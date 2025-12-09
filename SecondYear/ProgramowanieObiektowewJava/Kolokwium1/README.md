# **KOLOKWIUM 1**
1. Utwórz typ wyliczeniowy (`enum`) **Plec**, zawierający wartości:
   - `KOBIETA`
   - `MEZCZYZNA`
2. Utworz klase **Osoba** zawierajaca skladowe:
   - prywatne pola:
     - imie,nazwisko
     - wiek
     - plec - typu `Plec` (typ wyliczeniowy utworzony w zadaniu 1.)
   - konstruktor z parametrem typu Plec ustawiajacy to pole w klasie.
   - publiczne metody dostepowe:
     - `zapytajOimie()`, `zapytajOnazwisko()`, `zapytajOwiek()` - metody maja zwrocic wartosc odpowiedniego pola
     - `wprowadzImie()`, `wprowadzNazwisko()`, `wprowadzWiek()` - metody maja zapytac uzytkownika o wartosc i ustawic je jako pole danego obiektu. Wprowadzenie wartosci jest mozliwe wylacznie w sytuacji, kiedy pole nie posiada warotsci(null lub 0) 
3. Utworz typ wyliczeniowy Ocena zawierajacy spis ocen w skali akademickiej tj:
    `NIEDOSTATECZNY, DOSTATECZNY, DOSTATECZNY_PLUS, DOBRY, DOBRY_PLUS, BARDZO_DOBRY`.
4. Utwórz klasę **Student** dziedziczącą po klasie **Osoba**. Zdefiniuj składniki klasy:
   - `nrIndeksu` - `int`
   - `oceny` - `Object[][]`
   - Konstruktor wykorzystujący klasę **Osoba**, który inicjalizuje (tylko) tablicę ocen o rozmiarze 5x2. Tablica po inicjalizacji ma zawierać wartości domyślne `null` oraz `NIEDOSTATECZNY`. Przyszłe wykorzystanie tablicy zostało pokazane w tabeli 1:

| Matematyka     | Elektrotechnika | Metrologia  | Algorytmy | Programowanie |
|----------------|-----------------|-------------|-----------|---------------|
| NIEDOSTATECZNY | DOSTATECZNY     | DOSTATECZNY | DOBRY     | DOBRY_PLUS    |

przykladowo: odwolanie `oceny[2][0]` zwroci lancuch znakow `Metrologia`, a `oceny[0][1]` zwroci wartosc wyliczeniowa `NIEDOSTATECZNY`
5. Utworz interfejs **IStudent** zawierajacy metody:
   - `zdajEgzamin(int nrEgzaminu, String przedmiot)` - metoda nic nie zwraca
   - `pokazIndeks(int NrEgzaminu)` - *metoda domyslna*,zwraca tablice klasy Object.
   - `obliczSrednia()` - metoda zwraca wartosc zmiennoprzecinkowa
   - `czyStypendium()` - metoda zwraca prawde lub falsz
6. Zaimplementuj interfejs **IStudent** w klasie Student:
   - `zdajEgzamin(int nrEgzaminu, String przedmiot)` - metoda ma wylosowac jedna z ocen(typ wyliczeniowy, zad 3) i ustawic ja dla danego przedmiotu, nrEgzaminu oznacza kolumne z Tabeli 1. Przykładowo ponizsze polecenie powinno uzupelnic pierwsza kolumne o losowa ocene z przedmiotu Matematyka: studentX.zdajEgzamin(0, "Matematyka");
   - `pokazIndeks(int nrEgzaminu)` - metoda ma zwrocic tablice zawierajaca nazwe przedmiotu i ocene z egzaminu (kolumna z tabeli 1). w przypadku gdy ocena nie jest wstawiona(null) metoda ma zwrocic tablice: `["Brak_przedmiotu", NIEDOSTATECZNY]`.
   - `obliczSrednia()` - metoda zwraca srednia arytmetyczna z ocen o ile wszystkie są wystawione. Jesli nie wszystkie oceny sa wystawione metoda ma rzucic wyjątek klasy IllegalStateException. Pamiętaj:
     - o odpowiednim wywolaniu metody
     - ze oceny są typem wyliczeniowym. Wykorzystaj `switch-case` do zmapowania na wartosci liczbowe
   - `czyStypendium()` - metoda ma zwrocic prawde, jesli wszystkie oceny są wystawione i srednia ocen jest wieksza niz `4,75`. w przeciwnym wypadku metoda zwraca false. wykorzystaj metode `obliczSrednia()`.
7. Utworz metode main() w klasie Main(psvm + Tab) zawierajaca:
   - Liste obiektow klasy Osoba - `oLista`.
   - Uzupelnienie wartosci(imie,nazwisko,wiek) i wyswietlenie listy osob (min. 4 obiekty), wykorzystaj kontruktor, metody dostepowe oraz petle.
   - Liste obiektow klasy Student - `sLista`.
   - Analogiczne uzupelnienie wartosci dla listy sLista (konstuktor, petla, `zdajEgzamin()`), min. 4 obiekty. Dodatkowo wypisane maja byc wszystkie dane studentow ktorzy otrzymają stypendium - metoda `czyStypendium()` zwroci prawde.
   - usuniecie z kazdej listy jednego obiektu o:
     - najnizszym wieku - `oLista`.
     - najnizszej sredniej - `sLista`.