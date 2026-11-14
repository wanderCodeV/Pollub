<!DOCTYPE html>
<html lang="pl">

<head>
    <meta charset="UTF-8">
    <title>Ankieta</title>
</head>

<body>
    <h3>Wybierz technologie, które znasz:</h3>
    <form action="ankieta.php" method="post">
        <?php
        $tech = ["C", "CPP", "Java", "C#", "Html", "CSS", "XML", "PHP", "JavaScript"];
        foreach ($tech as $item) {
            echo '<input type="checkbox" name="tech[]" value="' . $item . '" />' . $item . '<br />';
        }
        ?>
        <br />
        <input type="submit" name="submit" value="Wyślij" />
    </form>

    <?php
    if (filter_input(INPUT_POST, 'submit')) {
        $plik = "ankieta.txt";
        $glosy = [];
        foreach ($tech as $t) {
            $glosy[$t] = 0;
        }

        if (file_exists($plik)) {
            $linie = file($plik);
            foreach ($linie as $linia) {
                $para = explode(":", trim($linia));
                if (count($para) == 2) {
                    $glosy[$para[0]] = (int)$para[1];
                }
            }
        }

        $wybrane = filter_input(INPUT_POST, 'tech', FILTER_SANITIZE_FULL_SPECIAL_CHARS, FILTER_REQUIRE_ARRAY);
        if (is_array($wybrane)) {
            foreach ($wybrane as $zaznaczone) {
                if (isset($glosy[$zaznaczone])) {
                    $glosy[$zaznaczone]++;
                }
            }
        }

        $fp = fopen($plik, "w");
        foreach ($glosy as $technologia => $ilosc) {
            fwrite($fp, $technologia . ":" . $ilosc . PHP_EOL);
        }
        fclose($fp);

        echo "<br />";
        foreach ($glosy as $technologia => $ilosc) {
            echo htmlspecialchars($technologia) . ": " . $ilosc . "<br />";
        }
    }
    ?>
</body>

</html>