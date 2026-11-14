<!DOCTYPE html>
<html lang="pl">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Odebrane 2</title>
</head>

<body>
    <div>
        <?php
        echo "<h3>GET:</h3>";
        foreach ($_GET as $key => $value) {
            if (is_array($value)) {
                echo "$key = " . implode(",", $value) . "<br />";
            } else {
                echo "$key = $value <br />";
            }
        }

        echo "<h3>POST:</h3>";
        foreach ($_POST as $key => $value) {
            if (is_array($value)) {
                echo "$key = " . implode(",", $value) . "<br />";
            } else {
                echo "$key = $value <br />";
            }
        }

        echo "<h3>REQUEST:</h3>";
        foreach ($_REQUEST as $key => $value) {
            if (is_array($value)) {
                echo "$key = " . implode(",", $value) . "<br />";
            } else {
                echo "$key = $value <br />";
            }
        }

        echo "<br />";
        var_dump($_GET);
        echo "<br />";
        var_dump($_POST);
        echo "<br />";
        var_dump($_REQUEST);
        ?>
    </div>
</body>

</html>