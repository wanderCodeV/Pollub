<?php
include_once 'klasy/User.php';
include_once 'klasy/Baza.php';
include_once 'klasy/RegistrationForm.php';

$rf = new RegistrationForm();
$bd = new Baza("localhost", "root", "", "klienci");
if (filter_input(INPUT_POST, 'submit', FILTER_SANITIZE_FULL_SPECIAL_CHARS)) {
   $user = $rf->checkUser();
   if ($user === NULL) {
      echo "<p>Niepoprawne dane rejestracji</p>";
   } else {
      echo "<p>Poprawne dane rejestracji:</p>";
      $user->show();
      $user->saveDB($bd);
   }
}
echo "<h3>Wszyscy użytkownicy DB:</h3>";
User::getAllUsersFromDB($bd);
