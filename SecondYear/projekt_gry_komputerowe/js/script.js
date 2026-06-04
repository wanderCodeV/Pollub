
/* zLab10: prosty skrypt do obsługi rozwijanego menu nawigacji mobilnej */

const toggleButton = document.getElementById('navbarToggle');
const navbarMenu = document.getElementById('navbarMenu');

if (toggleButton && navbarMenu) {
    toggleButton.addEventListener('click', () => {
        navbarMenu.classList.toggle('active');
        toggleButton.classList.toggle('open');
    });
}

