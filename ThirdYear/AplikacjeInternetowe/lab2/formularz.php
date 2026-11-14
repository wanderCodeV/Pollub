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
        <form method="post" action="odbierz3.php">
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
                <input type="submit" value=" Wyślij ">
                <input type="reset" value=" Anuluj ">
            </p>
        </form>
    </div>

</body>

</html>