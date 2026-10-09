/* zLab11cz2: Geolocation API – pobieranie współrzędnych i obliczanie odległości do bazy gildii */

const BAZA = { lat: 49.2992, lon: 19.9496, name: 'Zakopane' };

function toRad(deg) {
    return (deg * Math.PI) / 180;
}

function obliczOdlegloscKm(lat1, lon1, lat2, lon2) {
    const R = 6371;
    const dLat = toRad(lat2 - lat1);
    const dLon = toRad(lon2 - lon1);
    const a =
        Math.sin(dLat / 2) * Math.sin(dLat / 2) +
        Math.cos(toRad(lat1)) * Math.cos(toRad(lat2)) *
        Math.sin(dLon / 2) * Math.sin(dLon / 2);
    const c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1 - a));
    return R * c;
}

function wyswietlWynikGeo(tekst) {
    const result = document.getElementById('geoResult');
    if (result) {
        result.innerHTML = tekst;
    }
    try {
        /* zLab11cz1: sessionStorage – tymczasowy zapis ostatniego pomiaru w tej sesji */
        sessionStorage.setItem('ostatniPomiarGeo', tekst);
    } catch (_) {
        console.warn('sessionStorage niedostępny');
    }
}

function przywrocOstatniPomiar() {
    try {
        const zapis = sessionStorage.getItem('ostatniPomiarGeo');
        if (zapis) {
            wyswietlWynikGeo(zapis);
        }
    } catch (_) {
        /* brak dostępu do sessionStorage */
    }
}

const geoBtn = document.getElementById('geoBtn');

if (geoBtn) {
    geoBtn.addEventListener('click', () => {
        if (!navigator.geolocation) {
            wyswietlWynikGeo('Twoja przeglądarka nie obsługuje geolokalizacji.');
            return;
        }

        wyswietlWynikGeo('Trwa odczyt lokalizacji...');

        navigator.geolocation.getCurrentPosition(
            (position) => {
                const userLat = position.coords.latitude;
                const userLon = position.coords.longitude;
                const km = obliczOdlegloscKm(userLat, userLon, BAZA.lat, BAZA.lon);

                const tekst =
                    `<strong>📍 Twoja lokalizacja:</strong> ${userLat.toFixed(4)}°N, ${userLon.toFixed(4)}°E<br>` +
                    `<strong>🏔️ Odległość do ${BAZA.name}:</strong> <span style="color: var(--red); font-size: 1.2em; font-weight: bold;">${km.toFixed(1)} km</span>`;

                console.log('zLab11cz2 – współrzędne użytkownika:', userLat, userLon);
                wyswietlWynikGeo(tekst);
            },
            (error) => {
                let komunikat = 'Nie udało się ustalić lokalizacji.';
                if (error.code === 1) komunikat = 'Brak zgody na udostępnienie lokalizacji.';
                if (error.code === 2) komunikat = 'Lokalizacja jest chwilowo niedostępna.';
                if (error.code === 3) komunikat = 'Przekroczono czas oczekiwania na GPS.';
                wyswietlWynikGeo(komunikat);
            },
            { enableHighAccuracy: true, timeout: 10000, maximumAge: 0 }
        );
    });

    przywrocOstatniPomiar();
}
