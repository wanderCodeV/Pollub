<?php
class User
{
    const STATUS_USER = 1;
    const STATUS_ADMIN = 2;

    protected $userName;
    protected $passwd;
    protected $fullName;
    protected $email;
    protected $date;
    protected $status;

    function __construct($userName, $fullName, $email, $passwd)
    {
        $this->userName = $userName;
        $this->fullName = $fullName;
        $this->email = $email;
        $this->passwd = password_hash($passwd, PASSWORD_DEFAULT);
        $this->status = User::STATUS_USER;
        $this->date = (new DateTime())->format('Y-m-d');
    }

    public function show()
    {
        echo $this->userName . " " . $this->fullName . " " . $this->email . " status: " . $this->status . " " . $this->date . "<br/>";
    }

    public function setUserName($userName)
    {
        $this->userName = $userName;
    }

    public function getUserName()
    {
        return $this->userName;
    }

    public function setPasswd($passwd)
    {
        $this->passwd = $passwd;
    }

    public function getPasswd()
    {
        return $this->passwd;
    }

    public function setFullName($fullName)
    {
        $this->fullName = $fullName;
    }

    public function getFullName()
    {
        return $this->fullName;
    }

    public function setEmail($email)
    {
        $this->email = $email;
    }

    public function getEmail()
    {
        return $this->email;
    }

    public function setDate($date)
    {
        $this->date = $date;
    }

    public function getDate()
    {
        return $this->date;
    }

    public function setStatus($status)
    {
        $this->status = $status;
    }

    public function getStatus()
    {
        return $this->status;
    }

    static function getAllUsers($plik = "users.json")
    {
        $tab = json_decode(file_get_contents($plik));
        foreach ($tab as $val) {
            echo "<p>" . $val->userName . " " . $val->fullName . " " . $val->date . "</p>";
        }
    }

    function toArray()
    {
        $arr = [
            "userName" => $this->userName,
            "passwd" => $this->passwd,
            "fullName" => $this->fullName,
            "email" => $this->email,
            "date" => $this->date,
            "status" => $this->status
        ];
        return $arr;
    }

    function save($plik = "users.json")
    {
        $tab = json_decode(file_get_contents($plik), true);
        array_push($tab, $this->toArray());
        file_put_contents($plik, json_encode($tab));
    }

    function saveXML()
    {
        $xml = simplexml_load_file('users.xml');
        $xmlCopy = $xml->addChild("user");
        $xmlCopy->addChild("userName", $this->userName);
        $xmlCopy->addChild("passwd", $this->passwd);
        $xmlCopy->addChild("fullName", $this->fullName);
        $xmlCopy->addChild("email", $this->email);
        $xmlCopy->addChild("date", $this->date);
        $xmlCopy->addChild("status", $this->status);
        $xml->asXML('users.xml');
    }

    static function getAllUsersFromXML()
    {
        $allUsers = simplexml_load_file('users.xml');
        echo "<ul>";
        foreach ($allUsers as $user):
            $userName = $user->userName;
            $fullName = $user->fullName;
            $date = $user->date;
            echo "<li>$userName, $fullName, $date</li>";
        endforeach;
        echo "</ul>";
    }
}
