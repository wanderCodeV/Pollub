<?php
include_once 'klasy/User.php';
session_start();

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
$_SESSION = [];
if (isset($_COOKIE[session_name()])) {
    setcookie(session_name(), '', time() - 42000, '/');
}
session_destroy();
echo '<hr><a href="test1.php">Przejdź do strony 1</a>';
