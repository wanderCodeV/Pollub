const quizQuestions = [
    {
        game: "Wiedźmin 3: Dziki Gon",
        question: "Jak nazywa się potężna, górska twierdza wiedźminów z cechu wilka w Kaer Morhen?",
        answers: ["Kaer Trolde", "Kaer Morhen", "Oxenfurt", "Beauclair"],
        correct: 1
    },
    {
        game: "The Elder Scrolls V: Skyrim",
        question: "Ile legendarnych stopni prowadzi na szczyt Gardła Świata do klasztoru Wysoki Hrothgar?",
        answers: ["100 stopni", "5000 stopni", "7000 stopni", "10 000 stopni"],
        correct: 2
    },
    {
        game: "Celeste",
        question: "Jak ma na imię główna bohaterka gry, która zmaga się z własnymi słabościami podczas wspinaczki na górę Celeste?",
        answers: ["Madeleine", "Elena", "Lara", "Chell"],
        correct: 0
    },
    {
        game: "Wiedźmin 3: Dziki Gon",
        question: "Który wyspiarski, górzysty region w Wiedźminie 3 słynie z klanów celtyckich i lodowych gigantów?",
        answers: ["Velen", "Toussaint", "Biały Sad", "Skellige"],
        correct: 3
    },
    {
        game: "The Elder Scrolls V: Skyrim",
        question: "Jak nazywa się najwyższy szczyt w prowincji Skyrim, na którym rezyduje siwobrody Paarthurnax?",
        answers: ["Czerwona Góra", "Gardło Świata", "Samotnia", "Szczyt Solstheim"],
        correct: 1
    }
];

let currentQuestionIndex = 0;
let score = 0;

const quizContainer = document.getElementById('quiz-container');
const startBtn = document.getElementById('start-btn');

if (startBtn) {
    startBtn.addEventListener('click', startQuiz);
}

function startQuiz() {
    currentQuestionIndex = 0;
    score = 0;
    renderQuestion();
}

function renderQuestion() {
    const q = quizQuestions[currentQuestionIndex];

    quizContainer.innerHTML = `
        <div class="quiz-progress">Pytanie ${currentQuestionIndex + 1} z ${quizQuestions.length}</div>
        <div class="quiz-badge">${q.game}</div>
        <h2>${q.question}</h2>
        <div class="quiz-answers">
            ${q.answers.map((ans, index) => `<button class="answer-btn" onclick="checkAnswer(${index})">${ans}</button>`).join('')}
        </div>
    `;
}

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

function renderEndScreen() {
    let rank = "";

    if (score === quizQuestions.length) {
        rank = "Górski Bóg Gry";
    } else if (score >= 3) {
        rank = "Doświadczony Taternik";
    } else {
        rank = "Kanapowy Turysta";
    }

    quizContainer.innerHTML = `
        <div id="end-screen">
            <h2>Koniec Wyprawy!</h2>
            <p class="score-text">Twój wynik to: <strong>${score} / ${quizQuestions.length}</strong></p>
            <p class="rank-text">Twoja ranga: <span class="rank-highlight">${rank}</span></p>
            <button class="quiz-btn" onclick="startQuiz()">Spróbuj Ponownie</button>
        </div>
    `;
}
