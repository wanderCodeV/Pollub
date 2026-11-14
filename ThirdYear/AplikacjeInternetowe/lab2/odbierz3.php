<!DOCTYPE html>
<html lang="pl">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Odebrane 3</title>
</head>

<body>
    <div>
        <?php
        if (isset($_REQUEST['jezyki'])) {
            foreach ($_REQUEST['jezyki'] as $jezyk) {
                echo htmlspecialchars($jezyk) . " ";
            }
            echo "<br />";
            echo join(",", $_REQUEST['jezyki']) . "<br />";
        }

        echo "<br />";
        var_dump($_REQUEST);
        echo "<br /><br />";

        foreach ($_REQUEST as $key => $value) {
            if (is_array($value)) {
                echo "$key = " . join(",", $value) . "<br />";
            } else {
                echo "$key = $value <br />";
            }
        }
        ?>
    </div>
</body>

</html>