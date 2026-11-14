<?php
class RegistrationForm
{
    protected $user;

    function __construct()
    { ?>
        <h3>Formularz rejestracji</h3>
        <p>
        <form action="index.php" method="post">
            Nazwa użytkownika: <br /><input name="userName" /><br />
            Imię i nazwisko: <br /><input name="fullName" /><br />
            Hasło: <br /><input type="password" name="passwd" /><br />
            Email: <br /><input name="email" />
            <input type="submit" name="submit" value="Rejestruj" />
            <input type="reset" value="Anuluj" />
        </form>
        </p>
<?php
    }

    function checkUser()
    {
        $args = [
            'userName' => [
                'filter' => FILTER_VALIDATE_REGEXP,
                'options' => ['regexp' => '/^[0-9A-Za-ząęłńśćźżó_-]{2,25}$/']
            ],
            'fullName' => [
                'filter' => FILTER_VALIDATE_REGEXP,
                'options' => ['regexp' => '/^[A-ZĄĘŁŃŚĆŹŻÓ][a-ząęłńśćźżó]+\s[A-ZĄĘŁŃŚĆŹŻÓ][a-ząęłńśćźżó-]+$/']
            ],
            'passwd' => [
                'filter' => FILTER_VALIDATE_REGEXP,
                'options' => ['regexp' => '/^.{4,25}$/']
            ],
            'email' => FILTER_VALIDATE_EMAIL
        ];

        $dane = filter_input_array(INPUT_POST, $args);

        $errors = "";
        foreach ($dane as $key => $val) {
            if ($val === false or $val === NULL) {
                $errors .= $key . " ";
            }
        }

        if ($errors === "") {
            $this->user = new User($dane['userName'], $dane['fullName'], $dane['email'], $dane['passwd']);
        } else {
            $this->user = NULL;
        }

        return $this->user;
    }
}
?>