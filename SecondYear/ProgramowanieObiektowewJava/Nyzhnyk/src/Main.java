import java.security.spec.RSAOtherPrimeInfo;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        ArrayList<Osoba> oLista = new ArrayList<Osoba>();

        oLista.add(new Osoba(Plec.MEZCZYZNA));
        oLista.add(new Osoba(Plec.MEZCZYZNA));
        oLista.add(new Osoba(Plec.KOBIETA));
        oLista.add(new Osoba(Plec.KOBIETA));

        for(Osoba osoba : oLista){
            osoba.wprowadzImie();
            osoba.wprowadzNazwisko();
            osoba.wprowadzWiek();
        }

        System.out.println(" == Lista osob == ");
        for(Osoba osoba : oLista) {
            System.out.println(osoba.zapytajOimie() + " " + osoba.zapytajOnazwisko() + " " + osoba.zapytajOwiek());
        }

        ArrayList<Student> sLista = new ArrayList<Student>();

        sLista.add(new Student(Plec.MEZCZYZNA));
        sLista.add(new Student(Plec.MEZCZYZNA));
        sLista.add(new Student(Plec.KOBIETA));
        sLista.add(new Student(Plec.KOBIETA));

        for(Student student : sLista){
            student.wprowadzImie();
            student.wprowadzNazwisko();
            student.wprowadzWiek();

            student.zdajEgzamin(0, "Matematyka");
            student.zdajEgzamin(1, "Elektrotechnika");
            student.zdajEgzamin(2, "Metrologia");
            student.zdajEgzamin(3, "Algorytmy");
            student.zdajEgzamin(4, "Programowanie");
        }

        System.out.println(" == Lista studentow == ");
        for(Student student : sLista){
            System.out.println(student.zapytajOimie() + " " + student.zapytajOnazwisko() + " " + student.zapytajOwiek() + " " + student.obliczSrednia());
        }


        System.out.println(" == Lista studentow, ktorzy otrzymuja stypendium == ");
        for(Student student : sLista)
        {
            if(student.czyStypendium())
                System.out.println(student.zapytajOimie() + " " + student.zapytajOnazwisko() + " " + student.zapytajOwiek());
        }

        Osoba min_wiek = oLista.get(0);
        for(Osoba osoba : oLista)
        {
            if(min_wiek.zapytajOwiek() > osoba.zapytajOwiek())
                min_wiek = osoba;
        }
        oLista.remove(min_wiek);

        System.out.println(" == Lista osob po usunieciu== ");
        for(Osoba osoba : oLista) {
            System.out.println(osoba.zapytajOimie() + " " + osoba.zapytajOnazwisko() + " " + osoba.zapytajOwiek());
        }

        Student min_srednia = sLista.get(0);
        for(Student student : sLista)
        {
            if(min_srednia.obliczSrednia() > student.obliczSrednia())
                min_srednia = student;
        }
        sLista.remove(min_srednia);

        System.out.println(" == Lista studentow po usunieciu== ");
        for(Student student : sLista){
            System.out.println(student.zapytajOimie() + " " + student.zapytajOnazwisko() + " " + student.zapytajOwiek());
        }
    }
}
