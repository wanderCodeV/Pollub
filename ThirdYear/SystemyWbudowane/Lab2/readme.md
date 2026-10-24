## Zadanie 1

Napisz program odczytu klawiatury matrycowej dołączonej do portu A (zadanie 3 z CW2) oraz wyświetlania kodu (numeru) naciśniętego przycisku na wyświetlaczu LCD. 

Na wyświetlaczu pojawić się ma napis: 
* **Linia 1:** Nazwisko I. np. `Kowalski J.`
* **Linia 2:** Przycisk nr: `xx`, gdzie `xx` to `1` - `16`

> **Wskazówka:** W przypadku liczb jednocyfrowych do nr przycisku należy dodać wartość `0x30`, dla dwucyfrowych nr przycisku należy wyświetlić jako dwa znaki ASCII.

---

## Zadanie 2

Zdefiniuj trzy symbole, które następnie wprowadź do pamięci wyświetlacza LCD jako kolejne symbole `0`, `1` i `2`. 

Następnie napisz program animacji, w którym co `0,4 s` na tej samej pozycji kolejno wyświetlane są symbole w porządku `0`, `1`, `2`…