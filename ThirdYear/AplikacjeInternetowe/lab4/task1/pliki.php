<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8">
    <title>Formularz zamówienia</title>
</head>

<body>
    <h3>Formularz zamówienia</h3>
    <form action="pliki.php" method="post">
        <table>
            <tr>
                <td>Nazwisko:</td>
                <td><input type="text" name="nazw" /></td>
            </tr>
            <tr>
                <td>Wiek:</td>
                <td><input type="text" name="wiek" /></td>
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
                <td><input type="text" name="email" /></td>
            </tr>
        </table>
        <h4>Zamawiam tutorial z języka:</h4>
        <?php
        $jezyki = ["C", "CPP", "Java", "C#", "HTML", "CSS", "XML", "PHP", "JavaScript"];
        foreach ($jezyki as $jezyk) {
            echo '<input type="checkbox" name="jezyki[]" value="' . $jezyk . '" />' . $jezyk . ' ';
        }
        ?>
        <h4>Sposób zapłaty:</h4>
        <input type="radio" name="zaplata" value="eurocard" />eurocard
        <input type="radio" name="zaplata" value="visa" />visa
        <input type="radio" name="zaplata" value="przelew" />przelew bankowy
        <br /><br />
        <input type="submit" name="submit" value="Wyczyść" />
        <input type="submit" name="submit" value="Zapisz" />
        <input type="submit" name="submit" value="Pokaż" />
        <input type="submit" name="submit" value="PHP" />
        <input type="submit" name="submit" value="CPP" />
        <input type="submit" name="submit" value="Java" />
    </form>
    <?php
    include_once "funkcje.php";
    if (filter_input(INPUT_POST, "submit")) {
        $akcja = filter_input(INPUT_POST, "submit");
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
    ?>
</body>

</html>