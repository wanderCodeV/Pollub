<?php
function walidacja()
{
    $args = [
        'nazw' => [
            'filter' => FILTER_VALIDATE_REGEXP,
            'options' => ['regexp' => '/^[A-ZŁŚŻŹĆŃ]{1}[a-ząęółśżźćń]{1,25}$/']
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
        return $dane;
    } else {
        echo "<br>Nie poprawnie dane: " . $errors;
        return false;
    }
}

function dodajdoBD($bd)
{
    $dane = walidacja();
    if ($dane !== false) {
        $nazwisko = $dane['nazw'];
        $wiek = $dane['wiek'];
        $panstwo = $dane['kraj'];
        $email = $dane['email'];
        $zamowienie = implode(",", $dane['jezyki']);
        $platnosc = $dane['zaplata'];

        $sql = "INSERT INTO klienci VALUES (NULL, '$nazwisko', '$wiek', '$panstwo', '$email', '$zamowienie', '$platnosc');";
        if ($bd->insert($sql)) {
            echo "<br>Dodano do bazy";
        } else {
            echo "<br>Błąd dodawania do bazy";
        }
    }
}
