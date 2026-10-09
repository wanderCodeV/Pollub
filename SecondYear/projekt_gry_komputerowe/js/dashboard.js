/* zLab11cz1: Dashboard sesji – localStorage, JSON i edycja zapisanych wyników */
(function () {
    const form = document.getElementById('sessionForm');
    const gameSelect = document.getElementById('gameSelect');
    const gameOther = document.getElementById('gameOther');
    const hoursInput = document.getElementById('hours');
    const dateInput = document.getElementById('sessionDate');
    const notesInput = document.getElementById('notes');
    const tableBody = document.querySelector('#sessionsTable tbody');
    const tableWrapper = document.getElementById('tableWrapper');
    const sessionsEmpty = document.getElementById('sessionsEmpty');
    const totalsDiv = document.getElementById('totals');
    const clearAllBtn = document.getElementById('clearAll');
    const submitBtn = document.getElementById('sessionSubmitBtn');
    const cancelEditBtn = document.getElementById('cancelEdit');
    const formTitle = document.getElementById('sessionFormTitle');

    let editingIndex = null;

    function loadSessions() {
        try {
            const raw = localStorage.getItem('gameSessions');
            return raw ? JSON.parse(raw) : [];
        } catch (_) {
            return [];
        }
    }

    function saveSessions(sessions) {
        localStorage.setItem('gameSessions', JSON.stringify(sessions));
    }

    function escapeHtml(str) {
        return String(str).replace(/[&<>"']/g, (s) => ({
            '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;', "'": '&#39;'
        })[s]);
    }

    function showOtherField(show) {
        if (!gameOther) return;
        gameOther.classList.toggle('is-hidden', !show);
        if (!show) gameOther.value = '';
    }

    function setFormModeNew() {
        editingIndex = null;
        try {
            sessionStorage.removeItem('editingSessionIdx');
        } catch (_) { /* ignore */ }
        if (submitBtn) submitBtn.textContent = 'Zapisz sesję';
        if (cancelEditBtn) cancelEditBtn.classList.add('is-hidden');
        if (formTitle) formTitle.textContent = 'Dodaj sesję';
    }

    function setFormModeEdit(index) {
        editingIndex = index;
        try {
            sessionStorage.setItem('editingSessionIdx', String(index));
        } catch (_) { /* ignore */ }
        if (submitBtn) submitBtn.textContent = 'Zapisz zmiany';
        if (cancelEditBtn) cancelEditBtn.classList.remove('is-hidden');
        if (formTitle) formTitle.textContent = 'Edycja sesji';
    }

    function fillFormFromSession(session) {
        const known = ['Wiedźmin 3', 'Skyrim', 'Celeste'];
        if (known.includes(session.name)) {
            gameSelect.value = session.name;
            showOtherField(false);
        } else {
            gameSelect.value = '__other__';
            showOtherField(true);
            gameOther.value = session.name;
        }
        hoursInput.value = session.hours;
        dateInput.value = session.date;
        notesInput.value = session.notes || '';
    }

    function updateEmptyState(hasSessions) {
        if (sessionsEmpty) {
            sessionsEmpty.classList.toggle('is-hidden', hasSessions);
        }
        if (tableWrapper) {
            tableWrapper.classList.toggle('is-hidden', !hasSessions);
        }
    }

    function renderTable() {
        const sessions = loadSessions();
        tableBody.innerHTML = '';
        updateEmptyState(sessions.length > 0);

        sessions.forEach((s, idx) => {
            const tr = document.createElement('tr');
            tr.innerHTML = `
                <td>${escapeHtml(s.date)}</td>
                <td>${escapeHtml(s.name)}</td>
                <td>${s.hours}</td>
                <td>${escapeHtml(s.notes || '—')}</td>
                <td class="table-actions">
                    <button type="button" data-edit="${idx}" class="action-btn table-btn">Edytuj</button>
                    <button type="button" data-idx="${idx}" class="submit-btn table-btn">Usuń</button>
                </td>
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

        const baseGames = ['Wiedźmin 3', 'Skyrim', 'Celeste'];
        baseGames.forEach(game => {
            if (!(game in grouped)) {
                grouped[game] = 0;
            }
        });

        totalsDiv.innerHTML = '';
        const keys = Object.keys(grouped);

        keys.forEach((key) => {
            const card = document.createElement('div');
            card.className = 'summary-card';
            card.innerHTML = `
                <span class="summary-card--name">${escapeHtml(key)}</span>
                <span class="summary-card--hours">${grouped[key]} godz.</span>
            `;
            totalsDiv.appendChild(card);
        });
    }

    document.addEventListener('click', (e) => {
        const editBtn = e.target.closest('button[data-edit]');
        if (editBtn) {
            const idx = Number(editBtn.getAttribute('data-edit'));
            const sessions = loadSessions();
            if (!sessions[idx]) return;
            fillFormFromSession(sessions[idx]);
            setFormModeEdit(idx);
            form.closest('.section-panel').scrollIntoView({ behavior: 'smooth', block: 'start' });
            return;
        }

        const del = e.target.closest('button[data-idx]');
        if (del) {
            const idx = Number(del.getAttribute('data-idx'));
            const sessions = loadSessions();
            sessions.splice(idx, 1);
            saveSessions(sessions);
            if (editingIndex === idx) {
                form.reset();
                showOtherField(false);
                setFormModeNew();
            } else if (editingIndex !== null && idx < editingIndex) {
                editingIndex -= 1;
                try {
                    sessionStorage.setItem('editingSessionIdx', String(editingIndex));
                } catch (_) { /* ignore */ }
            }
            renderTable();
        }
    });

    if (clearAllBtn) {
        clearAllBtn.addEventListener('click', () => {
            if (!confirm('Usunąć wszystkie zapisane sesje?')) return;
            localStorage.removeItem('gameSessions');
            form.reset();
            showOtherField(false);
            setFormModeNew();
            renderTable();
        });
    }

    if (cancelEditBtn) {
        cancelEditBtn.addEventListener('click', () => {
            form.reset();
            showOtherField(false);
            setFormModeNew();
        });
    }

    gameSelect.addEventListener('change', () => {
        showOtherField(gameSelect.value === '__other__');
    });

    form.addEventListener('submit', (e) => {
        e.preventDefault();

        const name = gameSelect.value === '__other__'
            ? (gameOther.value.trim() || 'Inne')
            : gameSelect.value;
        const hours = Number(hoursInput.value) || 0;
        const date = dateInput.value || new Date().toISOString().slice(0, 10);
        const notes = notesInput.value.trim();

        // zLab8: Walidacja - data nie może być z przyszłości
        const today = new Date().toISOString().slice(0, 10);
        if (date > today) {
            alert('Data nie może być z przyszłości!');
            return;
        }

        // zLab8: Walidacja - liczba godzin musi być dodatnia
        if (hours <= 0 || hours > 24) {
            alert('Liczba godzin musi być większa od 0 i nie większa niż 24!');
            return;
        }

        const entry = { name, hours, date, notes };
        const sessions = loadSessions();

        if (editingIndex !== null) {
            sessions[editingIndex] = entry;
        } else {
            sessions.push(entry);
        }

        saveSessions(sessions);
        form.reset();
        showOtherField(false);
        setFormModeNew();
        renderTable();
    });

    try {
        const savedEdit = sessionStorage.getItem('editingSessionIdx');
        if (savedEdit !== null && savedEdit !== '') {
            const idx = Number(savedEdit);
            const sessions = loadSessions();
            if (sessions[idx]) {
                fillFormFromSession(sessions[idx]);
                setFormModeEdit(idx);
            }
        }
    } catch (_) { /* ignore */ }

    renderTable();
})();
