<?php
class Baza
{
    private ?mysqli $mysqli;

    public function __construct(string $serwer, string $user, string $pass, string $baza)
    {
        $this->mysqli = new mysqli($serwer, $user, $pass, $baza);
        if ($this->mysqli->connect_errno) {
            printf(
                "Nie udało sie połączenie z serwerem: %s\n",
                $this->mysqli->connect_error
            );
            exit();
        }
        if ($this->mysqli->set_charset("utf8")) {
        }
    }

    function __destruct()
    {
        $this->mysqli->close();
    }

    public function select(string $sql, array $pola)
    {
        $tresc = "";
        if ($result = $this->mysqli->query($sql)) {
            $ilepol = count($pola);
            $ile = $result->num_rows;
            $tresc .= "<table border='1'><tbody>";
            while ($row = $result->fetch_object()) {
                $tresc .= "<tr>";
                for ($i = 0; $i < $ilepol; $i++) {
                    $p = $pola[$i];
                    $tresc .= "<td>" . $row->$p . "</td>";
                }
                $tresc .= "</tr>";
            }
            $tresc .= "</tbody></table>";
            $result->close();
        }
        return $tresc;
    }

    public function insert(string $sql)
    {
        if ($this->mysqli->query($sql)) return true;
        else return false;
    }

    public function delete(string $sql)
    {
        if ($this->mysqli->query($sql)) return true;
        else return false;
    }

    public function getMysqli()
    {
        return $this->mysqli;
    }
}
