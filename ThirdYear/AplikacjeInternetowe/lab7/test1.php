<?php
include_once 'klasy/User.php';
session_start();

$user = new User('kubus', 'Kubus Puchatek', 'kubus@stumilowylas.pl', 'haslo');
$_SESSION['user'] = serialize($user);

echo "<h3>Id sesji: " . session_id() . "</h3>";
// foreach ($_SESSION as $key => $val) {
//     echo "$key: $val <br>";
// }
if (isset($_SESSION['user'])) {
    $user = unserialize($_SESSION['user']);
    $user->show();
}
echo "<hr><b>Ciasteczka:</b><br>";
foreach ($_COOKIE as $key => $val) {
    echo "$key=$val <br>";
}
echo '<hr><a href="test2.php">Przejdź do strony 2</a>';
