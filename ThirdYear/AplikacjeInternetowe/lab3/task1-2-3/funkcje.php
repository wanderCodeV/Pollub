<?php
function dodaj()
{
    $dane = "";
    if (isset($_REQUEST["nazw"])) {
        $dane .= htmlspecialchars($_REQUEST['nazw']) . " ";
    }
    if (isset($_REQUEST["wiek"])) {
        $dane .= htmlspecialchars($_REQUEST['wiek']) . " ";
    }
    if (isset($_REQUEST["kraj"])) {
        $dane .= htmlspecialchars($_REQUEST['kraj']) . " ";
    }
    if (isset($_REQUEST["email"])) {
        $dane .= htmlspecialchars($_REQUEST['email']) . " ";
    }
    if (isset($_REQUEST["jezyki"])) {
        $dane .= htmlspecialchars(join(",", $_REQUEST['jezyki'])) . " ";
    }
    if (isset($_REQUEST["zaplata"])) {
        $dane .= htmlspecialchars($_REQUEST['zaplata']);
    }
    $dane .= PHP_EOL;

    $fp = fopen($_SERVER['DOCUMENT_ROOT'] . "/dane.txt", "a");
    fwrite($fp, $dane);
    fclose($fp);
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
