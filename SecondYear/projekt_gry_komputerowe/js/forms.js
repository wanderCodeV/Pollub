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

function renderSurveyStatus(response, title) {
    if (!surveyStatus) return;

    surveyStatus.innerHTML = `
        <div class="survey-result">
            <h3>${title}</h3>
            <p><strong>Gra:</strong> ${response.gameType}</p>
            <p><strong>Platforma:</strong> ${response.favPlatform}</p>
            <p><strong>Ocena:</strong> ${response.hypeLevel}/100</p>
            <p><strong>Wiadomość:</strong> ${response.userMessage || '—'}</p>
            <p class="survey-date">Zapisano: ${new Date(response.submittedAt).toLocaleString('pl-PL')}</p>
        </div>
    `;
}

if (preferencesForm) {
    preferencesForm.addEventListener('submit', function (event) {
        event.preventDefault();

        const selectedType = document.querySelector('input[name="gameType"]:checked');
        if (!selectedType) return;

        const selectedPlatform = document.getElementById('favPlatform').value;
        const hypeValue = document.getElementById('hypeRange').value;
        const messageValue = document.getElementById('userMessage').value.trim();

        const response = new SurveyResponse(selectedType.value, selectedPlatform, hypeValue, messageValue);

        /* zLab11cz1: sessionStorage + JSON.stringify do zapisu ankiety w sesji */
        sessionStorage.setItem('surveyResponse', JSON.stringify(response.toJSON()));

        renderSurveyStatus(response, 'Zapisano');
    });

    const savedResponse = sessionStorage.getItem('surveyResponse');
    if (savedResponse) {
        const parsed = JSON.parse(savedResponse);
        const response = SurveyResponse.fromJSON(parsed);
        renderSurveyStatus(response, 'Ostatnia odpowiedź');
    }
}
