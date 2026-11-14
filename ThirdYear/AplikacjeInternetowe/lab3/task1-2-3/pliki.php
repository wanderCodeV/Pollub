<!DOCTYPE html>
<html lang="pl">

<head>
    <title>Formularz zamówienia</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>

<body>
    <div>
        <h1>Formularz zamówienia</h1>
        <form method="post" action="pliki.php">
            <table>
                <tr>
                    <td>Nazwisko: </td>
                    <td><input name="nazw"> </td>
                </tr>
                <tr>
                    <td>Wiek:</td>
                    <td><input name="wiek"></td>
                </tr>
                <tr>
                    <td>Państwo:</td>
                    <td><select name="kraj" size="2">
                            <option selected>Polska</option>
                            <option>Wielka Brytania</option>
                            <option>Niemcy</option>
                            <option value="fr">Francja</option>
                            <option value="gr">Grecja</option>
                        </select>
                    </td>
                </tr>
                <tr>
                    <td>Adres e-mail: </td>
                    <td><input name="email"></td>
                </tr>
            </table>

            <h2>Zamawiam tutorial z języka:</h2>
            <p>
                <?php
                $jezyki = ["C", "CPP", "Java", "C#", "HTML", "CSS", "XML", "PHP", "JavaScript"];
                foreach ($jezyki as $value) {
                    echo "<input name='jezyki[]' value='$value' type='checkbox' >$value ";
                }
                ?>
            </p>
            <h2>Sposób zapłaty:</h2>
            <p><input name="zaplata" type="radio" value="euro" checked>eurocard
                <input name="zaplata" type="radio" value="visa">visa
                <input name="zaplata" type="radio" value="przelew">przelew bankowy
                <br>
                <input type="reset" value="Wyczyść">
                <input type="submit" name="submit" value="Zapisz">
                <input type="submit" name="submit" value="Pokaż">
                <input type="submit" name="submit" value="PHP">
                <input type="submit" name="submit" value="CPP">
                <input type="submit" name="submit" value="Java">
            </p>
        </form>
    </div>
    <?php
    include_once "funkcje.php";

    if (isset($_REQUEST["submit"])) {
        $akcja = $_REQUEST["submit"];
        switch ($akcja) {
            case "Zapisz":
                dodaj();
                break;
            case "Pokaż":
                pokaz();
                break;
            case "PHP":
                pokaz_zamowienie("PHP");
                break;
            case "CPP":
                pokaz_zamowienie("CPP");
                break;
            case "Java":
                pokaz_zamowienie("Java");
                break;
        }
    }

    echo "<br /><br />";
    foreach ($_SERVER as $key => $value) {
        if (is_array($value)) {
            echo "$key = " . implode(",", $value) . "<br />";
        } else {
            echo "$key = $value <br />";
        }
    }
    ?>
</body>

</html>