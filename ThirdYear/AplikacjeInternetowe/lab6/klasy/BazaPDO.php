<?php
class BazaPDO
{
    private ?PDO $dbh;

    public function __construct(string $serwer, string $user, string $pass)
    {
        try {
            $this->dbh = new PDO($serwer, $user, $pass, [PDO::MYSQL_ATTR_INIT_COMMAND => "SET NAMES utf8"]);
        } catch (PDOException $e) {
            print "Error!: " . $e->getMessage() . "<br/>";
            die();
        }
    }

    function __destruct()
    {
        $this->dbh = null;
    }

    public function select(string $sql, array $pola)
    {
        $tresc = "";
        if ($result = $this->dbh->query($sql)) {
            $ilepol = count($pola);
            $tresc .= "<table><tbody>";
            while ($row = $result->fetch(PDO::FETCH_OBJ)) {
                $tresc .= "<tr>";
                for ($i = 0; $i < $ilepol; $i++) {
                    $p = $pola[$i];
                    $tresc .= "<td>" . $row->$p . "</td>";
                }
                $tresc .= "</tr>";
            }
            $tresc .= "</tbody></table>";
        }
        return $tresc;
    }

    public function delete(string $sql)
    {
        if ($this->dbh->exec($sql)) return true;
        else return false;
    }

    public function insert(string $sql)
    {
        if ($this->dbh->exec($sql)) return true;
        else return false;
    }
}
