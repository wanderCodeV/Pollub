<?php
include_once 'klasy/User.php';
include_once 'klasy/RegistrationForm.php';

$rf = new RegistrationForm();

if (filter_input(INPUT_POST, 'submit', FILTER_SANITIZE_FULL_SPECIAL_CHARS)) {
   $user = $rf->checkUser();
   if ($user === NULL) {
      echo "<p>Niepoprawne dane rejestracji</p>";
   } else {
      echo "<p>Poprawne dane rejestracji:</p>";
      $user->show();
      $user->save();
      $user->saveXML();
   }
}
echo "<h3>Wszyscy użytkownicy json:</h3>";
User::getAllUsers();
echo "<h3>Wszyscy użytkownicy xml:</h3>";
User::getAllUsersFromXML();
