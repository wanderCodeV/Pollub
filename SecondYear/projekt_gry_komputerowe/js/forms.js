
/* zLab12: klasa przechowująca odpowiedzi z ankiety oraz konwersję do/z JSON */
class SurveyResponse {
    constructor(gameType, favPlatform, hypeLevel, userMessage) {
        this.gameType = gameType;
        this.favPlatform = favPlatform;
        this.hypeLevel = hypeLevel;
        this.userMessage = userMessage;
        this.submittedAt = new Date().toISOString();
    }

    toJSON() {
        return {
            gameType: this.gameType,
            favPlatform: this.favPlatform,
            hypeLevel: this.hypeLevel,
            userMessage: this.userMessage,
            submittedAt: this.submittedAt,
        };
    }

    static fromJSON(data) {
        const result = new SurveyResponse(data.gameType, data.favPlatform, data.hypeLevel, data.userMessage);
        result.submittedAt = data.submittedAt;
        return result;
    }
}

const preferencesForm = document.getElementById('preferencesForm');
const surveyStatus = document.getElementById('surveyStatus');

if (preferencesForm) {
    preferencesForm.addEventListener('submit', function (event) {
        event.preventDefault();

        const selectedType = document.querySelector('input[name="gameType"]:checked').value;
        const selectedPlatform = document.getElementById('favPlatform').value;
        const hypeValue = document.getElementById('hypeRange').value;
        const messageValue = document.getElementById('userMessage').value.trim();

        const response = new SurveyResponse(selectedType, selectedPlatform, hypeValue, messageValue);
        localStorage.setItem('surveyResponse', JSON.stringify(response.toJSON()));

        if (surveyStatus) {
            surveyStatus.innerHTML = `
                <div class="card mt-3">
                    <div class="card-body">
                        <h3 class="card-title">Zapisano ankietę!</h3>
                        <p>Typ gry: <strong>${response.gameType}</strong></p>
                        <p>Platforma: <strong>${response.favPlatform}</strong></p>
                        <p>Poziom ekscytacji: <strong>${response.hypeLevel}/100</strong></p>
                        <p>Twoja wiadomość: <strong>${response.userMessage || 'Brak dodatkowej wiadomości'}</strong></p>
                        <p class="text-muted">Zapisano: ${new Date(response.submittedAt).toLocaleString()}</p>
                    </div>
                </div>`;
        }
    });

    const savedResponse = localStorage.getItem('surveyResponse');
    if (savedResponse && surveyStatus) {
        const parsed = JSON.parse(savedResponse);
        const response = SurveyResponse.fromJSON(parsed);
        surveyStatus.innerHTML = `
            <div class="card mt-3">
                <div class="card-body">
                    <h3 class="card-title">Ostatnia zapisana ankieta</h3>
                    <p>Typ gry: <strong>${response.gameType}</strong></p>
                    <p>Platforma: <strong>${response.favPlatform}</strong></p>
                    <p>Poziom ekscytacji: <strong>${response.hypeLevel}/100</strong></p>
                    <p>Twoja wiadomość: <strong>${response.userMessage || 'Brak dodatkowej wiadomości'}</strong></p>
                    <p class="text-muted">Zapisano: ${new Date(response.submittedAt).toLocaleString()}</p>
                </div>
            </div>`;
    }
}


