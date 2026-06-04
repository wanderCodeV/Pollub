/* zLab1cz2: skrypt obsługujący formularz rekrutacji, walidację, zapis profilu i geolokalizację */
const formView = document.getElementById('formView');
const profileView = document.getElementById('profileView');
const form = document.getElementById('expeditionForm');

const nameInput = document.getElementById('userName');
const emailInput = document.getElementById('userEmail');
const websiteInput = document.getElementById('userWebsite');
const phoneInput = document.getElementById('userPhone');
const dateInput = document.getElementById('tripDate');
const expeditionTypeInput = document.getElementById('expeditionType');
const gameStyleInputs = document.querySelectorAll('input[name="gameStyle"]');
const termsAgreeInput = document.getElementById('termsAgree');
const lvlInput = document.getElementById('groupSize');
const errorDiv = document.getElementById('formError');

function checkGildiaStatus() {
    // zLab11cz1: sprawdzenie, czy formularz już był wcześniej zapisany w localStorage
    if (localStorage.getItem('savedName')) {
        renderProfile();
    } else {
        if (formView) formView.style.display = 'block';
        if (profileView) profileView.style.display = 'none';
    }
}

window.addEventListener('DOMContentLoaded', checkGildiaStatus);

function getSelectedGameStyle() {
    for (const radio of gameStyleInputs) {
        if (radio.checked) {
            return radio.value;
        }
    }
    return '';
}

function renderProfile() {
    if (!formView || !profileView) return;

    formView.style.display = 'none';
    profileView.style.display = 'block';

    const name = localStorage.getItem('savedName') || '';
    const email = localStorage.getItem('savedEmail') || '';
    const website = localStorage.getItem('savedWebsite') || '';
    const phone = localStorage.getItem('savedPhone') || '';
    const date = localStorage.getItem('savedDate') || '';
    const expeditionType = localStorage.getItem('savedExpeditionType') || '';
    const gameStyle = localStorage.getItem('savedGameStyle') || '';
    const lvl = localStorage.getItem('savedLvl') || '';

    profileView.innerHTML = `
        <h2>Twój Profil w Gildii</h2>
        <div class="profile-card">
            <p><strong>Kandydat:</strong> ${name}</p>
            <p><strong>E-mail:</strong> ${email}</p>
            <p><strong>Profil:</strong> ${website || 'Brak'}</p>
            <p><strong>Kontakt:</strong> ${phone}</p>
            <p><strong>Data pierwszej wyprawy:</strong> ${date}</p>
            <p><strong>Typ wyprawy:</strong> ${expeditionType}</p>
            <p><strong>Styl gry:</strong> ${gameStyle}</p>
            <p><strong>Poziom doświadczenia:</strong> <span class="rank-highlight">${lvl} / 10</span></p>
        </div>
        <div class="profile-actions">
            <button class="action-btn" onclick="editProfile()">Edytuj dane</button>
            <button class="submit-btn" style="margin-top: 10px;" onclick="deleteProfile()">Opuść Gildię (Usuń mnie)</button>
        </div>
    `;
}

if (form) {
    // zLab8: przechwycenie submit formularza i wykonanie walidacji JS przed zapisem
    form.addEventListener('submit', (e) => {
        e.preventDefault();

        const errors = [];
        errorDiv.style.display = 'none';
        errorDiv.innerText = '';

        const selectedDate = new Date(dateInput.value);
        const today = new Date();
        today.setHours(0, 0, 0, 0);

        if (!nameInput.value.trim()) {
            errors.push('Musisz podać swoje imię i nick.');
        }
        if (!emailInput.value.trim()) {
            errors.push('Musisz podać adres e-mail.');
        }
        if (!phoneInput.value.trim()) {
            errors.push('Musisz podać numer telefonu.');
        }
        if (!dateInput.value) {
            errors.push('Musisz wybrać datę wyprawy.');
        } else if (selectedDate < today) {
            errors.push('Data wyprawy nie może być z przeszłości!');
        }
        if (!expeditionTypeInput.value) {
            errors.push('Musisz wybrać typ wyprawy.');
        }
        if (!getSelectedGameStyle()) {
            errors.push('Musisz wybrać preferowany styl gry.');
        }
        if (!termsAgreeInput.checked) {
            errors.push('Musisz zaakceptować regulamin gildii.');
        }

        const phonePattern = /^[0-9]{9}$/;
        if (!phonePattern.test(phoneInput.value)) {
            errors.push('Numer telefonu musi składać się z dokładnie 9 cyfr.');
        }

        const lvlValue = parseInt(lvlInput.value, 10);
        if (Number.isNaN(lvlValue) || lvlValue < 1 || lvlValue > 10) {
            errors.push('Poziom doświadczenia postaci musi mieścić się w przedziale od 1 do 10!');
        }

        if (errors.length > 0) {
            errorDiv.innerText = errors.join(' ');
            errorDiv.style.display = 'block';
            return;
        }

        // zLab11cz1: zapis formularza do localStorage i serializacja danych
        localStorage.setItem('savedName', nameInput.value.trim());
        localStorage.setItem('savedEmail', emailInput.value.trim());
        localStorage.setItem('savedWebsite', websiteInput.value.trim());
        localStorage.setItem('savedPhone', phoneInput.value.trim());
        localStorage.setItem('savedDate', dateInput.value);
        localStorage.setItem('savedExpeditionType', expeditionTypeInput.value);
        localStorage.setItem('savedGameStyle', getSelectedGameStyle());
        localStorage.setItem('savedLvl', lvlInput.value);

        alert('Zgłoszenie wysłane! Zostałeś zarejestrowany w bazie Gildii.');
        renderProfile();
    });
}

window.editProfile = function() {
    formView.style.display = 'block';
    profileView.style.display = 'none';

    nameInput.value = localStorage.getItem('savedName') || '';
    emailInput.value = localStorage.getItem('savedEmail') || '';
    websiteInput.value = localStorage.getItem('savedWebsite') || '';
    phoneInput.value = localStorage.getItem('savedPhone') || '';
    dateInput.value = localStorage.getItem('savedDate') || '';
    expeditionTypeInput.value = localStorage.getItem('savedExpeditionType') || '';

    const savedStyle = localStorage.getItem('savedGameStyle');
    gameStyleInputs.forEach((radio) => {
        radio.checked = radio.value === savedStyle;
    });

    termsAgreeInput.checked = true;
    lvlInput.value = localStorage.getItem('savedLvl') || '1';
};

window.deleteProfile = function() {
    if (confirm('Czy na pewno chcesz usunąć swoje zgłoszenie i opuścić Gildię?')) {
        localStorage.removeItem('savedName');
        localStorage.removeItem('savedEmail');
        localStorage.removeItem('savedWebsite');
        localStorage.removeItem('savedPhone');
        localStorage.removeItem('savedDate');
        localStorage.removeItem('savedExpeditionType');
        localStorage.removeItem('savedGameStyle');
        localStorage.removeItem('savedLvl');

        form.reset();
        alert('Twoje dane zostały trwale usunięte z bazy danych przeglądarki.');
        checkGildiaStatus();
    }
};

const geoBtn = document.getElementById('geoBtn');
if (geoBtn) {
    // zLab11cz2: geolokalizacja wysyła współrzędne i oblicza dystans do Zakopanego
    geoBtn.addEventListener('click', () => {
        const resultText = document.getElementById('geoResult');
        if (!navigator.geolocation) {
            resultText.innerText = 'Geolokacja nie jest wspierana przez Twoją przeglądarkę.';
            return;
        }

        resultText.innerText = 'Pobieranie danych satelitarnych...';

        navigator.geolocation.getCurrentPosition((position) => {
            const userLat = position.coords.latitude;
            const userLon = position.coords.longitude;
            const tatryLat = 49.299181;
            const tatryLon = 19.949562;

            const R = 6371;
            const dLat = (tatryLat - userLat) * Math.PI / 180;
            const dLon = (tatryLon - userLon) * Math.PI / 180;
            const a = Math.sin(dLat / 2) * Math.sin(dLat / 2) +
                Math.cos(userLat * Math.PI / 180) * Math.cos(tatryLat * Math.PI / 180) *
                Math.sin(dLon / 2) * Math.sin(dLon / 2);
            const c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1 - a));
            const distance = Math.round(R * c);

            resultText.innerHTML = `Twoja pozycja: <b>${userLat.toFixed(4)}, ${userLon.toFixed(4)}</b>.<br>Znajdujesz się około <b>${distance} km</b> od kwatery głównej gildii w Zakopanem!`;
        }, () => {
            resultText.innerText = 'Brak dostępu do lokalizacji.';
        });
    });
}

// Removed jQuery-dependent UI effects (FAQ toggle / counters) to avoid requiring jQuery.

