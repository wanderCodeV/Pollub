<!DOCTYPE html>
<html lang="pl">

<head>
    <meta charset="UTF-8">
    <title>BD</title>
</head>

<body>
    <h2>Formularz zamówienia</h2>
    <form action="index.php" method="post">
        <table>
            <tr>
                <td>Nazwisko:</td>
                <td><input type="text" name="nazw"></td>
            </tr>
            <tr>
                <td>Wiek:</td>
                <td><input type="text" name="wiek"></td>
            </tr>
            <tr>
                <td>Państwo:</td>
                <td>
                    <select name="kraj">
                        <option value="Polska">Polska</option>
                        <option value="Niemcy">Niemcy</option>
                        <option value="Wielka Brytania">Wielka Brytania</option>
                        <option value="Czechy">Czechy</option>
                    </select>
                </td>
            </tr>
            <tr>
                <td>Adres e-mail:</td>
                <td><input type="email" name="email"></td>
            </tr>
        </table>

        <h4>Zamawiam tutorial z języka:</h4>
        <input type="checkbox" name="jezyki[]" value="Java">Java
        <input type="checkbox" name="jezyki[]" value="PHP">PHP
        <input type="checkbox" name="jezyki[]" value="CPP">CPP

        <h4>Sposób zapłaty:</h4>
        <input type="radio" name="zaplata" value="Master Card" checked>Master Card
        <input type="radio" name="zaplata" value="Visa">Visa
        <input type="radio" name="zaplata" value="Przelew">Przelew
        <br><br>

        <input type="reset" value="Wyczyść">
        <input type="submit" name="submit" value="Dodaj">
        <input type="submit" name="submit" value="Pokaż">
        <input type="submit" name="submit" value="PHP">
        <input type="submit" name="submit" value="CPP">
        <input type="submit" name="submit" value="Java">
        <input type="submit" name="submit" value="Usuń">
    </form>

    <?php
    include_once("funkcje.php");
    include_once "klasy/BazaPDO.php";

    $bd = new BazaPDO("mysql:host=localhost;dbname=klienci", "root", "");

    if (filter_input(INPUT_POST, "submit")) {
        $akcja = filter_input(INPUT_POST, "submit");
        switch ($akcja) {
            case "Dodaj":
                dodajdoBD($bd);
                break;
            case "Pokaż":
                echo $bd->select("select Nazwisko,Zamowienie from klienci", ["Nazwisko", "Zamowienie"]);
                break;
            case "PHP":
                echo $bd->select("SELECT Nazwisko, Zamowienie FROM klienci WHERE Zamowienie REGEXP 'PHP'", ["Nazwisko", "Zamowienie"]);
                break;
            case "CPP":
                echo $bd->select("SELECT Nazwisko, Zamowienie FROM klienci WHERE Zamowienie REGEXP 'CPP'", ["Nazwisko", "Zamowienie"]);
                break;
            case "Java":
                echo $bd->select("SELECT Nazwisko, Zamowienie FROM klienci WHERE Zamowienie REGEXP 'Java'", ["Nazwisko", "Zamowienie"]);
                break;
            case "Usuń":
                $nazw = filter_input(INPUT_POST, 'nazw', FILTER_SANITIZE_FULL_SPECIAL_CHARS);
                if ($nazw) {
                    $bd->delete("DELETE FROM klienci WHERE Nazwisko='$nazw'");
                }
                break;
        }
    }
    ?>
</body>

</html>