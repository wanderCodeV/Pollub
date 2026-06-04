// dashboard.js - manage sessions stored in localStorage
(function(){
    const form = document.getElementById('sessionForm');
    const gameSelect = document.getElementById('gameSelect');
    const gameOther = document.getElementById('gameOther');
    const hoursInput = document.getElementById('hours');
    const dateInput = document.getElementById('sessionDate');
    const notesInput = document.getElementById('notes');
    const tableBody = document.querySelector('#sessionsTable tbody');
    const totalsDiv = document.getElementById('totals');
    const clearAllBtn = document.getElementById('clearAll');

    function loadSessions() {
        const raw = localStorage.getItem('gameSessions');
        return raw ? JSON.parse(raw) : [];
    }

    function saveSessions(sessions) {
        localStorage.setItem('gameSessions', JSON.stringify(sessions));
    }

    function renderTable() {
        const sessions = loadSessions();
        tableBody.innerHTML = '';
        sessions.forEach((s, idx) => {
            const tr = document.createElement('tr');
            tr.innerHTML = `
                <td>${s.date}</td>
                <td>${escapeHtml(s.name)}</td>
                <td>${s.hours}</td>
                <td>${escapeHtml(s.notes || '')}</td>
                <td><button data-idx="${idx}" class="action-btn">Usuń</button></td>
            `;
            tableBody.appendChild(tr);
        });
        renderTotals();
    }

    function renderTotals() {
        const sessions = loadSessions();
        const grouped = sessions.reduce((acc, s) => {
            acc[s.name] = (acc[s.name] || 0) + Number(s.hours || 0);
            return acc;
        }, {});
        totalsDiv.innerHTML = '';
        const ul = document.createElement('ul');
        for (const key of Object.keys(grouped)) {
            const li = document.createElement('li');
            li.textContent = `${key}: ${grouped[key]} godzin`;
            ul.appendChild(li);
        }
        if (Object.keys(grouped).length === 0) totalsDiv.textContent = 'Brak zapisanych sesji.';
        else totalsDiv.appendChild(ul);
    }

    function escapeHtml(str){
        return String(str).replace(/[&<>"']/g, function(s){
            return ({'&':'&amp;','<':'&lt;','>':'&gt;','"':'&quot;',"'":'&#39;'})[s];
        });
    }

    document.addEventListener('click', (e) => {
        const del = e.target.closest('button[data-idx]');
        if (del) {
            const idx = Number(del.getAttribute('data-idx'));
            const sessions = loadSessions();
            sessions.splice(idx,1);
            saveSessions(sessions);
            renderTable();
        }
    });

    clearAllBtn.addEventListener('click', () => {
        if (!confirm('Na pewno usunąć wszystkie sesje?')) return;
        localStorage.removeItem('gameSessions');
        renderTable();
    });

    gameSelect.addEventListener('change', () => {
        if (gameSelect.value === '__other__') gameOther.style.display = 'block';
        else { gameOther.style.display = 'none'; gameOther.value = ''; }
    });

    form.addEventListener('submit', (e) => {
        e.preventDefault();
        const name = gameSelect.value === '__other__' ? (gameOther.value.trim() || 'Inne') : gameSelect.value;
        const hours = Number(hoursInput.value) || 0;
        const date = dateInput.value || new Date().toISOString().slice(0,10);
        const notes = notesInput.value.trim();

        const sessions = loadSessions();
        sessions.push({ name, hours, date, notes });
        saveSessions(sessions);
        form.reset();
        gameOther.style.display = 'none';
        renderTable();
    });

    // initial render
    renderTable();

})();
