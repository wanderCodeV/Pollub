<!DOCTYPE html>
<html lang="pl">

<head>
    <meta charset="UTF-8">
    <title>Typy w PHP</title>
</head>

<body>
    <?php
    $z1 = 1234;
    $z2 = 567.789;
    $z3 = 1;
    $z4 = 0;
    $z5 = true;
    $z6 = "0";
    $z7 = "Typy w PHP";
    $z8 = [1, 2, 3, 4];
    $z9 = [];
    $z10 = ["zielony", "czerwony", "niebieski"];
    $z11 = ["Agata", "Agatowska", 4.67, true];
    $z12 = new DateTime();

    $zmienne = [
        '$z1'  => $z1,
        '$z2'  => $z2,
        '$z3'  => $z3,
        '$z4'  => $z4,
        '$z5'  => $z5,
        '$z6'  => $z6,
        '$z7'  => $z7,
        '$z8'  => $z8,
        '$z9'  => $z9,
        '$z10' => $z10,
        '$z11' => $z11,
        '$z12' => $z12
    ];

    foreach ($zmienne as $nazwa => $wartosc) {
        echo "$nazwa = ";
        if (is_bool($wartosc)) {
            echo $wartosc ? 'true' : 'false';
        } elseif (is_array($wartosc)) {
            echo implode(", ", $wartosc) . " (count: " . count($wartosc) . ")";
        } elseif ($wartosc instanceof DateTime) {
            echo $wartosc->format('Y-m-d H:i:s');
        } else {
            echo $wartosc;
        }
        echo "<br>";
    }

    echo "<br>";

    foreach ($zmienne as $nazwa => $val) {
        echo "$nazwa: ";
        echo "is_bool=" . (is_bool($val) ? 'true' : 'false') . ", ";
        echo "is_int=" . (is_int($val) ? 'true' : 'false') . ", ";
        echo "is_numeric=" . (is_numeric($val) ? 'true' : 'false') . ", ";
        echo "is_string=" . (is_string($val) ? 'true' : 'false') . ", ";
        echo "is_array=" . (is_array($val) ? 'true' : 'false') . ", ";
        echo "is_object=" . (is_object($val) ? 'true' : 'false') . "<br>";
    }

    echo "<br>";

    echo '1 == true: ' . (($z3 == $z5) ? 'true' : 'false') . '<br>';
    echo '1 === true: ' . (($z3 === $z5) ? 'true' : 'false') . '<br>';
    echo '0 == "0": ' . (($z4 == $z6) ? 'true' : 'false') . '<br>';
    echo '0 === "0": ' . (($z4 === $z6) ? 'true' : 'false') . '<br>';

    echo "<br>";

    var_dump($z11);
    echo "<br>";
    print_r($z10);
    ?>
</body>

</html>