/* zLab7/zLab8/zLab11cz1: Rekrutacja – SPA (widok formularz/profil), walidacja JS, localStorage */
/* zLab1cz2/zLab4: Formularz HTML w rekrutacja.html – pola, typy HTML5, required, pattern */
let formView, profileView, form, nameInput, emailInput, websiteInput, phoneInput, dateInput, expeditionTypeInput, gameStyleInputs, termsAgreeInput, lvlInput, errorDiv;
let formSubmitHandler = null;

const STORAGE_KEYS = [
    'savedName', 'savedEmail', 'savedWebsite', 'savedPhone',
    'savedDate', 'savedType', 'savedStyle', 'savedLvl'
];

function initElements() {
    formView = document.getElementById('formView');
    profileView = document.getElementById('profileView');
    form = document.getElementById('expeditionForm');
    nameInput = document.getElementById('userName');
    emailInput = document.getElementById('userEmail');
    websiteInput = document.getElementById('userWebsite');
    phoneInput = document.getElementById('userPhone');
    dateInput = document.getElementById('tripDate');
    expeditionTypeInput = document.getElementById('expeditionType');
    gameStyleInputs = document.querySelectorAll('input[name="gameStyle"]');
    termsAgreeInput = document.getElementById('termsAgree');
    lvlInput = document.getElementById('groupSize');
    errorDiv = document.getElementById('formError');
}

function showError(message) {
    if (!errorDiv) return;
    errorDiv.textContent = message;
    errorDiv.style.display = 'block';
    errorDiv.scrollIntoView({ behavior: 'smooth', block: 'nearest' });
}

function clearError() {
    if (!errorDiv) return;
    errorDiv.textContent = '';
    errorDiv.style.display = 'none';
}

function escapeHtml(text) {
    const div = document.createElement('div');
    div.textContent = text;
    return div.innerHTML;
}

function hasSavedProfile() {
    try {
        return !!localStorage.getItem('savedName');
    } catch (_) {
        return false;
    }
}

function clearProfileStorage() {
    try {
        STORAGE_KEYS.forEach((key) => localStorage.removeItem(key));
    } catch (_) {
        /* localStorage niedostępny */
    }
}

function readStorageItem(key, fallback) {
    try {
        return localStorage.getItem(key) || fallback;
    } catch (_) {
        return fallback;
    }
}

function getProfileData() {
    const website = readStorageItem('savedWebsite', '');
    return {
        name: readStorageItem('savedName', ''),
        email: readStorageItem('savedEmail', ''),
        website: website === '—' ? '' : website,
        phone: readStorageItem('savedPhone', ''),
        date: readStorageItem('savedDate', ''),
        type: readStorageItem('savedType', 'Trekking'),
        style: readStorageItem('savedStyle', ''),
        lvl: readStorageItem('savedLvl', '1')
    };
}

function setFormMode(mode) {
    const titleEl = document.getElementById('formPanelTitle');
    const submitBtn = document.getElementById('submitExpeditionBtn');

    if (mode === 'edit') {
        if (titleEl) titleEl.textContent = 'Edycja danych';
        if (submitBtn) submitBtn.textContent = 'Zapisz zmiany';
    } else {
        if (titleEl) titleEl.textContent = 'Formularz rekrutacji';
        if (submitBtn) submitBtn.textContent = 'Wyślij formularz';
    }
}

function fillFormWithProfile(data) {
    if (!nameInput) return;

    nameInput.value = data.name;
    emailInput.value = data.email;
    websiteInput.value = data.website;
    phoneInput.value = data.phone;
    dateInput.value = data.date;
    expeditionTypeInput.value = data.type;
    lvlInput.value = data.lvl;

    gameStyleInputs.forEach((radio) => {
        radio.checked = radio.value === data.style;
    });

    if (termsAgreeInput) {
        termsAgreeInput.checked = true;
    }
}

function showFormView(options = {}) {
    const { reset = true, mode = 'new' } = options;

    if (formView) formView.style.display = 'block';
    if (profileView) {
        profileView.style.display = 'none';
        profileView.innerHTML = '';
    }

    if (reset && form) {
        form.reset();
        if (lvlInput) lvlInput.value = '1';
        gameStyleInputs.forEach((radio) => {
            radio.checked = false;
        });
        if (termsAgreeInput) termsAgreeInput.checked = false;
    }

    setFormMode(mode);
    clearError();
}

function showEditForm() {
    initElements();
    showFormView({ reset: false, mode: 'edit' });
    fillFormWithProfile(getProfileData());
}

function checkGildiaStatus() {
    initElements();
    setupFormListener();

    if (hasSavedProfile()) {
        renderProfile();
    } else {
        showFormView({ reset: true, mode: 'new' });
    }
}

function runWhenDomReady(callback) {
    if (document.readyState === 'loading') {
        document.addEventListener('DOMContentLoaded', callback);
    } else {
        callback();
    }
}

runWhenDomReady(checkGildiaStatus);

function getSelectedGameStyle() {
    for (const radio of gameStyleInputs) {
        if (radio.checked) {
            return radio.value;
        }
    }
    return '';
}

function getTodayDateString() {
    const today = new Date();
    const yyyy = today.getFullYear();
    let mm = today.getMonth() + 1;
    let dd = today.getDate();
    if (mm < 10) mm = '0' + mm;
    if (dd < 10) dd = '0' + dd;
    return `${yyyy}-${mm}-${dd}`;
}

function formatWebsiteDisplay(website) {
    if (!website || website === '—') {
        return '—';
    }
    return website;
}

function bindProfileActions() {
    const editBtn = document.getElementById('editProfileBtn');
    const deleteBtn = document.getElementById('deleteProfileBtn');

    if (editBtn) {
        editBtn.addEventListener('click', showEditForm);
    }

    if (deleteBtn) {
        deleteBtn.addEventListener('click', () => {
            if (confirm('Czy na pewno usunąć zapisane dane z przeglądarki?')) {
                clearProfileStorage();
                if (form) form.reset();
                clearError();
                checkGildiaStatus();
            }
        });
    }
}

function renderProfile() {
    if (formView) formView.style.display = 'none';
    if (profileView) profileView.style.display = 'block';

    const data = getProfileData();
    const websiteDisplay = formatWebsiteDisplay(readStorageItem('savedWebsite', '—'));

    profileView.innerHTML = `
        <section class="section-panel">
            <h2>Twoje dane</h2>
            <p><strong>Imię / Nick:</strong> ${escapeHtml(data.name)}</p>
            <p><strong>E-mail:</strong> ${escapeHtml(data.email)}</p>
            <p><strong>Strona WWW:</strong> ${escapeHtml(websiteDisplay)}</p>
            <p><strong>Telefon:</strong> ${escapeHtml(data.phone)}</p>
            <p><strong>Data dołączenia:</strong> ${escapeHtml(data.date)}</p>
            <p><strong>Typ ekspedycji:</strong> ${escapeHtml(data.type)}</p>
            <p><strong>Styl rozgrywki:</strong> ${escapeHtml(data.style)}</p>
            <p><strong>Poziom postaci:</strong> ${escapeHtml(data.lvl)} / 10</p>
            <div class="profile-actions">
                <button type="button" id="editProfileBtn" class="action-btn">Edytuj dane</button>
                <button type="button" id="deleteProfileBtn" class="submit-btn">Usuń dane</button>
            </div>
        </section>
    `;

    bindProfileActions();
}

function saveProfileData(data) {
    try {
        localStorage.setItem('savedName', data.name);
        localStorage.setItem('savedEmail', data.email);
        localStorage.setItem('savedWebsite', data.website);
        localStorage.setItem('savedPhone', data.phone);
        localStorage.setItem('savedDate', data.date);
        localStorage.setItem('savedType', data.type);
        localStorage.setItem('savedStyle', data.style);
        localStorage.setItem('savedLvl', data.lvl);
        return true;
    } catch (_) {
        showError('Nie udało się zapisać danych. Otwórz stronę przez serwer HTTP (np. Live Server), nie jako plik file://.');
        return false;
    }
}

function handleFormSubmit(event) {
    event.preventDefault();
    initElements();
    clearError();

    if (!form || !nameInput || !emailInput || !phoneInput || !dateInput) {
        showError('Błąd ładowania formularza. Odśwież stronę (Ctrl+F5).');
        return;
    }

    const nameVal = nameInput.value.trim();
    if (nameVal.length < 3) {
        showError('Imię lub Nick musi mieć co najmniej 3 znaki.');
        return;
    }

    const emailVal = emailInput.value.trim();
    const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    if (!emailRegex.test(emailVal)) {
        showError('Wprowadź poprawny adres e-mail.');
        return;
    }

    const websiteVal = websiteInput.value.trim();
    if (websiteVal.length > 0) {
        try {
            new URL(websiteVal);
        } catch (_) {
            showError('Wprowadź pełny i poprawny adres URL (np. https://mojastrona.pl).');
            return;
        }
    }

    const phoneVal = phoneInput.value.trim();
    const phoneRegex = /^[0-9]{9}$/;
    if (!phoneRegex.test(phoneVal)) {
        showError('Numer telefonu musi składać się z dokładnie 9 cyfr.');
        return;
    }

    const dateVal = dateInput.value;
    if (!dateVal) {
        showError('Wybierz planowaną datę dołączenia.');
        return;
    }
    const todayStr = getTodayDateString();
    if (dateVal < todayStr) {
        showError('Data dołączenia do wyprawy nie może być z przeszłości!');
        return;
    }

    const gameStyleVal = getSelectedGameStyle();
    if (!gameStyleVal) {
        showError('Proszę wybrać preferowany styl rozgrywki.');
        return;
    }

    if (!termsAgreeInput.checked) {
        showError('Musisz zaakceptować regulamin gildii, aby kontynuować.');
        return;
    }

    const lvlVal = Number(lvlInput.value);
    if (!Number.isInteger(lvlVal) || lvlVal < 1 || lvlVal > 10) {
        showError('Poziom postaci musi być liczbą całkowitą od 1 do 10.');
        return;
    }

    const saved = saveProfileData({
        name: nameVal,
        email: emailVal,
        website: websiteVal || '—',
        phone: phoneVal,
        date: dateVal,
        type: expeditionTypeInput.value,
        style: gameStyleVal,
        lvl: String(lvlVal)
    });

    if (saved) {
        clearError();
        renderProfile();
    }
}

function setupFormListener() {
    if (!form) return;

    if (formSubmitHandler) {
        form.removeEventListener('submit', formSubmitHandler);
    }

    formSubmitHandler = handleFormSubmit;
    form.addEventListener('submit', formSubmitHandler);
}
