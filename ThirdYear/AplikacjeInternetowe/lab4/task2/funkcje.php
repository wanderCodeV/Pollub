<?php
function walidacja()
{
    $args = [
        'nazw' => [
            'filter' => FILTER_VALIDATE_REGEXP,
            'options' => ['regexp' => '/^[A-Z]{1}[a-ząęłńśćźżó-]{1,25}$/']
        ],
        'wiek' => [
            'filter' => FILTER_VALIDATE_INT,
            'options' => ['min_range' => 1, 'max_range' => 120]
        ],
        'kraj' => FILTER_SANITIZE_FULL_SPECIAL_CHARS,
        'email' => FILTER_VALIDATE_EMAIL,
        'jezyki' => [
            'filter' => FILTER_SANITIZE_FULL_SPECIAL_CHARS,
            'flags' => FILTER_REQUIRE_ARRAY
        ],
        'zaplata' => FILTER_SANITIZE_FULL_SPECIAL_CHARS
    ];

    $dane = filter_input_array(INPUT_POST, $args);

    var_dump($dane);

    $errors = "";
    foreach ($dane as $key => $val) {
        if ($val === false or $val === NULL) {
            $errors .= $key . " ";
        }
    }

    if ($errors === "") {
        dopliku("dane.txt", $dane);
    } else {
        echo "<br>Nie poprawne dane: " . $errors;
    }
}

function dopliku($nazwaPliku, $tablicaDanych)
{
    $dane = "";
    foreach ($tablicaDanych as $key => $val) {
        if (is_array($val)) {
            $dane .= implode(",", $val) . " ";
        } else {
            $dane .= $val . " ";
        }
    }
    $dane .= PHP_EOL;

    $fp = fopen($_SERVER['DOCUMENT_ROOT'] . "/" . $nazwaPliku, "a");
    fwrite($fp, $dane);
    fclose($fp);
    echo "<p>Zapisano:<br /> $dane</p>";
}

function dodaj()
{
    echo "<h3>Dodawanie do pliku:</h3>";
    walidacja();
}

function pokaz()
{
    $linie = file($_SERVER['DOCUMENT_ROOT'] . "/dane.txt");
    foreach ($linie as $linia) {
        echo htmlspecialchars($linia) . "<br />";
    }
}

function pokaz_zamowienie($tut)
{
    $linie = file($_SERVER['DOCUMENT_ROOT'] . "/dane.txt");
    foreach ($linie as $linia) {
        $tab = explode(" ", trim($linia));
        $jezyki = explode(",", $tab[4]);
        if (in_array($tut, $jezyki)) {
            echo htmlspecialchars($linia) . "<br />";
        }
    }
}

function statystyki()
{
    $linie = file($_SERVER['DOCUMENT_ROOT'] . "/dane.txt");
    $wszystkie = count($linie);
    $ponizej18 = 0;
    $powyzej49 = 0;

    foreach ($linie as $linia) {
        $tab = explode(" ", trim($linia));
        $wiek = (int)$tab[1];
        if ($wiek < 18) {
            $ponizej18++;
        }
        if ($wiek >= 50) {
            $powyzej49++;
        }
    }

    echo "<p>Liczba wszystkich zamówień: $wszystkie</p>";
    echo "<p>Liczba zamówień od osób w wieku < 18 lat: $ponizej18</p>";
    echo "<p>Liczba zamówień od osób w wieku >=50 lat: $powyzej49</p>";
}
