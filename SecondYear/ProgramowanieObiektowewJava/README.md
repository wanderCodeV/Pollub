# Programowanie obiektowe w Java
## Lab2. Składnia języka, instrukcje sterujące, typy danych, klasy, metody, obiekty.
### Zadanie 2.1. Inicjalizacja
Stwórz klasę składającą się z niezainicjalizowanych pól typu int, char, String. Stwórz obiekt klasy, a następnie wypisz wartości pól. Jakie wartości zostały nadane?
### Zadanie 2.2. Metoda statyczna
Standardowe metody są powiązane z obiektami (aby wywołać metodę niezbędny jest obiekt). Wykorzystując słowo kluczowe static napisz metodę wypisującą wartości 0 – 54 (każda wartość w nowym wierszu). Wywołaj metodę nie używając obiektu.
### Zadanie 2.3 Klasa Uczen
Stwórz nową klasę – **Uczen**, zadeklaruj niezainicjalizowane pola:
- klasy `String` – imie i nazwisko
- typu `int` – wiek
- typu `double` – srednia
Dodaj konstruktor bezparametrowy i parametrowy ustawiający wszystkie pola klasy. W metodzie main stwórz kilka obiektów używając obu konstruktorów. Wyświetl dane obiektów (nazwisko, imie, wiek, srednia) każdy obiekt w jednym wierszu.
### Zadanie 2.4 Klasa Owoc
Bazując na klasie przedstawionej w Laboratorium 2 napisz własną klasę Owoc. Dodaj kilka metod zwracających wartość (np. nazwę i masę) i wykorzystaj je do wypisania wartości
pól konkretnych obiektów.
### Zadanie 2.5 Odliczanie w pętli
Napisz kilka wariantów metody odliczającej w pętli od 5 do 80 co 15 wypisując te  wartości w jednym wierszu (oddziel wartości spacją). Wykorzystaj wszystkie rodzaje pętli.
### Zadanie 2.6 Trójkąt
Napisz metodę przyjmującą trzy parametry całkowite i sprawdzającą czy możliwe jest zbudowanie trójkąta o danych bokach. Sprawdź dodatkowo czy będzie to trójkąt równoboczny, równoramienny czy różnoboczny.
### Zadanie 2.7. Liczby całkowite
Napisz metodę która wyświetli wszystkie liczby całkowite z zakresu <11,111> podzielne bez reszty przez 13.
### Zadanie 2.8. Ciąg Fibonacciego
Napisz metodę przyjmującą jeden parametr całkowity dodatni – n. Metoda ma wyświetlać n – elementów z ciągu Fibonacciego (w jednym wierszu, każdy element
oddzielony spacją).
## Lab3. Tworzenie aplikacji obiektowych do przetwarzania tekstu.
### Zadanie 3.1. Obecność w łańcuchu
Napisz metodę przyjmującą jako parametr znak `char` i łańcuch znaków. Metoda ma sprawdzać czy i ile razy w podanym łańcuchu występuje dany znak.
## Lab4. Tworzenie aplikacji obiektowych wykorzystujących funkcje matematyczne.


## Lab5. Programowanie obiektowe z wykorzystaniem dziedziczenia i interfejsów.
### Zadanie 5.1. Dziedziczenie
Utwórz nową klasę – Figura. Zdefiniuj w klasie pola:
- protected:
  - int pole,
  - int obwód,
- private:
  - Color kolor (klasa importowana) .
Zdefiniuj w klasie metody chronione (protected):
- void rysuj(),
- void usuń() ,
- void przesuń(),
- String podajParametry(),
Dodaj konstruktor parametrowy oraz metody typu get i set (ALT+Insert → getter and setter dla pól klasy). Utwórz nowe klasy dziedziczące po klasie Figura <- Elipsa, Figura <-Wielokąt. Wróć do klasy figura i zdefiniuj tam konstruktor bezparametrowy. Usuń modyfikator dostępu klasy Elipsa i Wielokąt. 
Zdefiniuj w klasach odpowiednio pola prywatne:
- W klasie Elipsa:
  - półoś wielka (a), półoś mała (b), pozycje x,y dla dwóch ognisk (F1x, F1y, F2x, F2y) oraz odległość ognisk od środka elipsy (c).
- W klasie Wielokąt:
  - liczba wierzchołków, liczba boków, suma kątów wewnętrznych.
Dodaj konstruktory, gettery i settery dla każdej z klas – zauważ, że klasa dziedzicząca może wykorzystać konstruktor klasy nadrzędnej. Zwróć uwagę na słowo super – do czego się odnosi? Sprawdź czy masz dostęp do pól klasy bazowej. Dodaj/nadpisz dla każdej klasy metody z klasy bazowej (Alt+Insert → Override Methods). Zwróć uwagę na adnotację oznaczoną symbolem @ oraz ponownie słowo super. Metody mogą zawierać wypisanie informacji np.: ```System.out.println("Trwa rysowanie wielokąta o " + wierzcholki + "wierzchołkach");```

Dodaj metody obliczające:
- W klasie Elipsa: odległość ognisk od środka elipsy (c):
  `𝑐 = sqrt(𝑎^2 − 𝑏^2)`
- W klasie Wielokąt: sumę kątów wewnętrznych:
    𝑠𝑢𝑚𝑎𝐾𝑎𝑡𝑜𝑤 = (𝑛 − 2) ∙ 180°, gdzie n jest liczbą boków wielokąta.
Utwórz nowe klasy dziedziczące:
    Elipsa <- Okrąg
    Wielokąt <- Trójkąt
    Wielokąt <- Prostokąt
    Prostokąt <-> Kwadrat
Dodaj odpowiednie pola np. w klasie Trójkąt wysokość (h) oraz podstawa (a). Dla pozostałych klas analogicznie. W każdej z klas utwórz odpowiednie konstruktory ustawiające pola klas nadrzędnych. Nadpisz również metody – mogą zawierać sam komunikat. Dodaj również metody obliczające pole i obwód i ustawiające odpowiednie pola np. : po wywołaniu metody obliczObwód () dla obiektu klasy Okrąg ma zostać ustawione pole klasy (obwód) z klasy Figura.
W jaki sposób wywołać na obiekcie klasy podrzędnej oryginalną metodę klasy nadrzędnej? Utwórz nowy pakiet (drzewo projektowe → katalog src → New → package). Stwórz nową klasę (nazwa dowolna). Sprawdź widoczność/dostępność wszystkich stworzonych wcześniej klas. Co trzeba zmienić?

## Lab6. Obsługa wyjątków.
### Zadanie 6.1. Kalkulator
Napisz prosty program konsolowy realizujący funkcjonalności kalkulatora:
- Wykonywanie podstawowych działań (dodawanie, odejmowanie, mnożenie, dzielenie, pierwiastkowanie, potęgowanie) i wyświetlanie wyniku.
Zadbaj o odpowiednią obsługę wyjątków. Załóż, że użytkownik może wprowadzić dowolny znak (w przypadku wprowadzenia błędnych danych wyświetl komunikat i ponów prośbę o podanie danych).
### Zadanie 6.2. Pobieranie liczby rzeczywistej
Napisz metodę pobierającą od użytkownika liczbę zmiennoprzecinkową, rozdzielającą liczbę na cechę oraz mantysę, a następnie zwracającą iloraz cechy i mantysy. W przypadku, gdy nie jest to możliwe wypisz komunikat i ponów pobieranie liczby. Załóż, że użytkownik może wprowadzić dowolny znak.
### Zadanie 6.3. Pobieranie liczby całkowitej
Napisz metodę pobierającą o użytkownika liczbę całkowitą z zakresu <99,999>. Zwróć sumę kwadratów jej cyfr. Załóż, że użytkownik może wprowadzić dowolny znak.
## Lab7. Wykorzystanie kolekcji.
### Zadanie 7.1. Zmodyfikuj kod zgodnie z podpunktami
Nowo powstałe kule mają prędkość wylosowaną z zakresu `<–MAX_SPEED, MAX_SPEED>`, dla stałej MAX_SPEED = 5 oznacza to zakres <-5,5>. 
Istnieje możliwość wylosowania prędkości 0 (w osi x, y lub obu).
- Zmodyfikuj kod aby wyeliminować możliwość utworzenia kuli o składowej prędkości równej 0.
Kule odbijają się od granicy okna i przenikają się wzajemnie.
- Zmodyfikuj kod dodając kolizję między kulami (można wzorować się na zderzeniach sprężystych niecentralnych).
Kule mają stały rozmiar.
- Dodaj możliwość zmiany rozmiaru kolejnych kul przy pomocy rolki myszy (kule dodane przed obrotem rolki zachowują rozmiar).
- Sprawdź działanie aplikacji dla innych wartości stałej `DELAY`, np. 16, 42, 100 (odpowiednio dla 60, 24 i 10 fps).
- Dodaj kilka zdarzeń w zależności od działania myszki np. wejście/wyjście kursora w obszar okna aplikacji – włączenie/wyłączenie ruchu kul.
## Lab8. Wyrażenia lambda w języku Java.
### Zadanie 1.1. Wypisanie listy
Napisz interfejs zawierający jedną metodę abstrakcyjną przyjmującą jako parametr łańcuch znaków. Stwórz listę (np. `ArrayList`) zawierającą spis przedmiotów do zaliczenia (klasa `String`). Napisz metodę przyjmującą jako parametry: listę  łańcuchów znaków oraz stworzony interfejs – metoda ma wypisać wszystkie elementy listy. Użyj wyrażenia lambda przy wywołaniu metody.
### Zadanie 1.2. Sortowanie tablicy
Wykorzystując interfejs funkcyjny `Comparator<T>` napisz metodę sortującą tablicę liczb całkowitych. Metoda compare(T o1,T o2) zwraca liczbę całkowitą zgodnie z funkcją signum (ujemną, zero lub dodatnią) jeśli pierwszy argument jest odpowiednio (mniejszy, równy, większy) od drugiego. Użyj wyrażenia lambda.
### Zadanie 1.3. Sortowanie listy
Wykorzystując interfejs funkcyjny `Comparator<T>` napisz metodę sortującą listę łańcuchów znaków w zależności od długości. Metoda compare(T o1,T o2) zwraca liczbę całkowitą zgodnie z funkcją signum (ujemną, zero lub dodatnią) jeśli pierwszy argument jest odpowiednio (mniejszy, równy, większy) od drugiego. Użyj wyrażenia lambda.
## Lab9. Operacje wejścia – wyjścia, obsługa plików.
### Zadanie 9.1. Zapis kolizji
Wróć do zadania 7.1 dotyczącego zderzenia kul. Zmodyfikuj/dodaj kod tak aby każda kolizja została zapisywana do pliku – niezbędne informacje to współrzędne kul w momencie zderzenia oraz rozmiar (przy dużej liczbie kul rozważ buforowanie i zapis np. co 30 wykrytych kolizji).
### Zadanie 9.2. Odczyt kolizji
Wykorzystaj kod z zadania 7.1 oraz 9.1 – odczytaj plik z zarejestrowanymi kolizjami. Stwórz okno analogiczne do zadania 7.1 ale bez animacji. Użyj odczytanych danych do zaznaczenia miejsc kolizji (użyj metody rysującej `drawOval()`).
## Lab10 Współbieżność w języku Java.

## Lab11. Tworzenie aplikacji z graficznym interfejsem użytkownika z obsługą zdarzeń.

## Lab12. Tworzenie aplikacji do komunikacji sieciowej.

## Lab13. Tworzenie aplikacji do obsługi bazy danych.