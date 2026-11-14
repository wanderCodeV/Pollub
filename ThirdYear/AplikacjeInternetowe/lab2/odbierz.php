<!DOCTYPE html>
<html lang="pl">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Odebrane</title>
</head>

<body>
    <div>
        <h2>Dane odebrane z formularza</h2>
        <?php
        if (isset($_REQUEST['nazw']) && $_REQUEST['nazw'] != "") {
            $nazwisko = htmlspecialchars(trim($_REQUEST['nazw']));
            echo "Nazwisko: $nazwisko <br />";
        } else {
            echo "Nie wpisano nazwiska <br />";
        }

        if (isset($_REQUEST['wiek']) && $_REQUEST['wiek'] != "") {
            $wiek = htmlspecialchars(trim($_REQUEST['wiek']));
            echo "Wiek: $wiek <br />";
        } else {
            echo "Nie wpisano wieku <br />";
        }

        if (isset($_REQUEST['kraj']) && $_REQUEST['kraj'] != "") {
            $kraj = htmlspecialchars(trim($_REQUEST['kraj']));
            echo "Kraj: $kraj <br />";
        } else {
            echo "Nie wybrano kraju <br />";
        }

        if (isset($_REQUEST['email']) && $_REQUEST['email'] != "") {
            $email = htmlspecialchars(trim($_REQUEST['email']));
            echo "Email: $email <br />";
        } else {
            echo "Nie wpisano adresu e-mail <br />";
        }

        if (isset($_REQUEST['jezyki'])) {
            echo "Wybrano tutoriale: ";
            foreach ($_REQUEST['jezyki'] as $jezyk) {
                echo htmlspecialchars($jezyk) . " ";
            }
            echo "<br />";
        } else {
            echo "Nie wybrano tutoriali <br />";
        }

        if (isset($_REQUEST['zaplata'])) {
            $zaplata = htmlspecialchars($_REQUEST['zaplata']);
            echo "Sposób zapłaty: $zaplata <br />";
        } else {
            echo "Nie wybrano sposobu zapłaty <br />";
        }
        ?>
        <a href="formularz.html">Powrót do formularza</a>
    </div>
</body>

</html>