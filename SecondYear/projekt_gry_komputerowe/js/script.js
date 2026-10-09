/* zLab6: Obsługa zdarzeń – rozwijane menu nawigacji mobilnej (addEventListener, DOM) */
/* zLab10: Współpracuje z układem navbar na wszystkich podstronach projektu */

const toggleButton = document.getElementById('navbarToggle');
const navbarMenu = document.getElementById('navbarMenu');

if (toggleButton && navbarMenu) {
    toggleButton.addEventListener('click', () => {
        navbarMenu.classList.toggle('active');
        toggleButton.classList.toggle('open');
        console.log('zLab6 – menu mobilne:', navbarMenu.classList.contains('active') ? 'otwarte' : 'zamknięte');
    });
}
