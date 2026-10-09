/* zLab7: Baza pytań quizu w formie tablicy obiektów dla aplikacji SPA */
const quizQuestions = [
    {
        game: "Wiedźmin 3: Dziki Gon",
        question: "W jakim górzystym regionie Północy znajduje się twierdza Kaer Morhen, gdzie szkoli się wiedźminów?",
        answers: ["Velen", "Kaedwen (Góry Błękitnych Kamieni)", "Toussaint", "Novigrad"],
        correct: 1
    },
    {
        game: "The Elder Scrolls V: Skyrim",
        question: "Ile stopni prowadzi święta Droga Do Gardła Świata na szczyt, gdzie mieszkają Szare Brody?",
        answers: ["700 stopni", "7000 stopni", "70 stopni", "777 stopni"],
        correct: 1
    },
    {
        game: "Celeste",
        question: "Jak nazywa się szczyt w Kanadzie, który zainspirował twórców do nazwania góry w grze?",
        answers: ["Mount Everest", "Mount Celeste", "Mont Blanc", "Mount Logan"],
        correct: 1
    },
    {
        game: "The Elder Scrolls V: Skyrim",
        question: "Jak nazywa się najwyższy szczyt Skyrim, na którym spotykasz smoków i Szarych Brodów?",
        answers: ["Czerwona Góra", "Gardło Świata", "Samotnia", "Morrowind"],
        correct: 1
    },
    {
        game: "Wiedźmin 3: Dziki Gon",
        question: "Który archipelag na Północy słynie z surowych klifów, fiordów i wojowniczych klanów żyjących między morzem a górami?",
        answers: ["Velen", "Toussaint", "Skellige", "Novigrad"],
        correct: 2
    },
    {
        game: "Celeste",
        question: "Czego metaforą jest wspinaczka Madeline na szczyt góry Celeste w fabule gry?",
        answers: [
            "Zdobycia najwyższego rekordu speedrunu",
            "Walki z lękiem i depresją",
            "Odnalezienia skarbu na szczycie",
            "Ucieczki przed smokiem"
        ],
        correct: 1
    }
];

let currentQuestionIndex = 0;
let score = 0;

const quizContainer = document.getElementById('quiz-container');
const startBtn = document.getElementById('start-btn');

/* zLab6: Event listener dla przycisku start quizu */
if (startBtn) {
    startBtn.addEventListener('click', startQuiz);
}

/* zLab7: Funkcja rozpoczynająca quiz – resetowanie zmiennych */
function startQuiz() {
    currentQuestionIndex = 0;
    score = 0;
    renderQuestion();
}

/* zLab7: Funkcja renderująca pytanie i odpowiedzi w kontenerze SPA */
function renderQuestion() {
    const q = quizQuestions[currentQuestionIndex];

    quizContainer.innerHTML = `
        <div class="quiz-progress">Pytanie ${currentQuestionIndex + 1} z ${quizQuestions.length}</div>
        <div class="quiz-badge">${q.game}</div>
        <h2>${q.question}</h2>
        <div class="quiz-answers">
            ${q.answers.map((ans, index) => `<button type="button" class="answer-btn" onclick="checkAnswer(${index})">${ans}</button>`).join('')}
        </div>
    `;
}

/* zLab7: Funkcja sprawdzająca odpowiedź i przechodząca do kolejnego pytania */
function checkAnswer(selectedIndex) {
    const q = quizQuestions[currentQuestionIndex];

    if (selectedIndex === q.correct) {
        score++;
    }

    currentQuestionIndex++;

    if (currentQuestionIndex < quizQuestions.length) {
        renderQuestion();
    } else {
        renderEndScreen();
    }
}

/* zLab7: Funkcja renderująca ekran końcowy z wynikiem i oceną */
function renderEndScreen() {
    let rank = "";

    if (score === quizQuestions.length) {
        rank = "Wynik bardzo dobry";
    } else if (score >= 4) {
        rank = "Wynik dobry";
    } else if (score >= 2) {
        rank = "Wynik średni";
    } else {
        rank = "Warto powtórzyć materiał";
    }

    quizContainer.innerHTML = `
        <div id="end-screen">
            <h2>Koniec quizu</h2>
            <p class="score-text">Poprawne odpowiedzi: <strong>${score} / ${quizQuestions.length}</strong></p>
            <p class="rank-text">Ocena: <span class="rank-highlight">${rank}</span></p>
            <button type="button" class="quiz-btn" onclick="startQuiz()">Zagraj jeszcze raz</button>
        </div>
    `;
}

/* zLab6: Eksport funkcji do globalnego scope dla onclick w HTML */
window.startQuiz = startQuiz;
window.checkAnswer = checkAnswer;
