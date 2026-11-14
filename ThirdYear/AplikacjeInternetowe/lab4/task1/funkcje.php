<?php
function walidacja()
{
    $args = [
        'nazw' => [
            'filter' => FILTER_VALIDATE_REGEXP,
            'options' => ['regexp' => '/^[A-ZĄĆĘŁŃÓŚŹŻ]{1}[a-ząćęłńóśźż]{1,25}$/']
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
}

function dodaj()
{
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
