import java.util.Scanner;

public class Osoba {
    private String imie;
    private String nazwisko;
    private int wiek;
    private Plec plec;

    public Osoba(Plec in_plec)
    {
        plec = in_plec;
    }

    public String zapytajOimie()
    {
        return imie;
    }

    public String zapytajOnazwisko()
    {
        return nazwisko;
    }

    public int zapytajOwiek()
    {
        return wiek;
    }

    public void wprowadzImie()
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Podaj imie: ");
        imie = sc.nextLine();

        while(imie == null || imie.isEmpty())
        {
            System.out.print("Wprowadzono niepoprawne imie. Podaj imie: ");
            imie = sc.nextLine();
        }
    }

    public void wprowadzNazwisko()
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Podaj nazwisko: ");
        nazwisko = sc.nextLine();

        while(nazwisko == null || nazwisko.isEmpty())
        {
            System.out.print("Wprowadzono niepoprawne nazwisko. Podaj nazwisko: ");
            nazwisko = sc.nextLine();
        }
    }

    public void wprowadzWiek()
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Podaj wiek: ");
        wiek = sc.nextInt();

        while(wiek <= 0 || wiek > 123)
        {
            System.out.print("Wprowadzono niepoprawny wiek. Podaj wiek: ");
            wiek = sc.nextInt();
        }
    }

}
