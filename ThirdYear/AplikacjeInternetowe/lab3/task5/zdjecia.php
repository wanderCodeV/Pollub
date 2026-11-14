<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8">
    <title>Miniaturki</title>
</head>

<body>
    <?php
    if (isset($_POST['zapisz']) && $_POST['zapisz'] == 'Zapisz' && !isset($_GET['pic'])) {
        if (is_uploaded_file($_FILES['zdjecie']['tmp_name'])) {
            $typ = $_FILES['zdjecie']['type'];
            if ($typ === 'image/jpeg') {
                move_uploaded_file($_FILES['zdjecie']['tmp_name'], './zdjecia/' . $_FILES['zdjecie']['name']);
                $link = $_FILES['zdjecie']['name'];
                $random = uniqid('img_');
                $zdj = $random . '.jpg';
                copy('./zdjecia/' . $link, './' . $zdj);

                list($width, $height) = getimagesize($zdj);
                $wys = $_POST['wys'];
                $szer = $_POST['szer'];

                $skalaWys = 1;
                $skalaSzer = 1;
                $skala = 1;

                if ($width > $szer) {
                    $skalaSzer = $szer / $width;
                }
                if ($height > $wys) {
                    $skalaWys = $wys / $height;
                }
                if ($skalaWys <= $skalaSzer) {
                    $skala = $skalaWys;
                } else {
                    $skala = $skalaSzer;
                }

                $newH = $height * $skala;
                $newW = $width * $skala;

                header('Content-Type: image/jpeg');
                $nowe = imagecreatetruecolor($newW, $newH);
                $obraz = imagecreatefromjpeg($zdj);
                imagecopyresampled($nowe, $obraz, 0, 0, 0, 0, $newW, $newH, $width, $height);
                imagejpeg($nowe, './miniatury/mini-' . $link, 100);
                echo "nowe=/miniatury/mini-$link <br>";
                unset($nowe);
                unset($obraz);
                unlink($zdj);

                $dlugosc = strlen($link);
                $dlugosc -= 4;
                $link = substr($link, 0, $dlugosc);
                echo "link=$link <br/>";
                header('location:zdjecia.php?pic=' . $link);
            } else {
                header('location:zdjecia.html');
            }
        }
    }

    echo "<h2>Galeria zdjęć</h2>";
    $katalog = opendir('./miniatury/');
    $licznik = 0;
    while ($plik = readdir($katalog)) {
        if ($plik != "." && $plik != "..") {
            $oryginal = substr($plik, 5);
            echo "<a href='zdjecia/$oryginal'><img src='miniatury/$plik' alt='$oryginal'></a> ";
            $licznik++;
        }
    }
    closedir($katalog);

    echo "<p>W galerii jest aktualnie $licznik zdjęć</p>";
    echo '<a href="zdjecia.html">Powrót do formularza dodawania zdjęć</a>';
    ?>
</body>

</html>