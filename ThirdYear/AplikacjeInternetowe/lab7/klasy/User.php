<?php
class User
{
    const STATUS_USER = 1;
    const STATUS_ADMIN = 2;

    protected string $userName;
    protected string $passwd;
    protected string $fullName;
    protected string $email;
    protected string $date;
    protected int $status;

    function __construct(string $userName, string $fullName, string $email, string $passwd)
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

    public function setUserName(string $userName)
    {
        $this->userName = $userName;
    }

    public function getUserName()
    {
        return $this->userName;
    }

    public function setPasswd(string $passwd)
    {
        $this->passwd = $passwd;
    }

    public function getPasswd()
    {
        return $this->passwd;
    }

    public function setFullName(string $fullName)
    {
        $this->fullName = $fullName;
    }

    public function getFullName()
    {
        return $this->fullName;
    }

    public function setEmail(string $email)
    {
        $this->email = $email;
    }

    public function getEmail()
    {
        return $this->email;
    }

    public function setDate(string $date)
    {
        $this->date = $date;
    }

    public function getDate()
    {
        return $this->date;
    }

    public function setStatus(int $status)
    {
        $this->status = $status;
    }

    public function getStatus()
    {
        return $this->status;
    }

    public function saveDB($db)
    {
        $sql = "INSERT INTO users VALUES (NULL, '$this->userName', '$this->fullName', '$this->email', '$this->passwd', '$this->status', '$this->date')";
        return $db->insert($sql);
    }

    public static function getAllUsersFromDB($db)
    {
        $sql = "SELECT * FROM users";
        $result = $db->select($sql, ['id', 'userName', 'fullName', 'email', 'status', 'date']);
        echo $result;
    }
}
