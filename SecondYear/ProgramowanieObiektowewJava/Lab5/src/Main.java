import java.awt.Color;

public class Main {
    public static void main(String[] args) {

//        System.out.println("=== TEST ELIPSA ===");
//        Elipsa e = new Elipsa(6, 4, Color.RED);
//        e.obliczPole();
//        e.obliczObwod();
//        e.rysuj();
//        System.out.println(e.podajParametry());

        System.out.println("\n=== TEST OKRĄG ===");
        Okrag o = new Okrag(5);
        o.obliczPole();
        o.obliczObwod();
        o.rysuj();
        System.out.println("Pole okraga: " + o.getPole());
        System.out.println(o.podajParametry());

        System.out.println("\n=== TEST TRÓJKĄT ===");
        Trojkat t = new Trojkat(6, 4);
        t.obliczPole();
        t.obliczObwod();
        t.rysuj();
        System.out.println("Pole trojkata: " + t.getPole());
        System.out.println(t.podajParametry());

        System.out.println("\n=== TEST PROSTOKĄT ===");
        Prostokat p = new Prostokat(8, 3);
        p.obliczPole();
        p.obliczObwod();
        p.rysuj();
        System.out.println("Pole prostokata: " + p.getPole());
        System.out.println(p.podajParametry());

        System.out.println("\n=== TEST KWADRAT ===");
        Kwadrat k = new Kwadrat(5);
        k.obliczPole();
        k.obliczObwod();
        k.rysuj();
        System.out.println("Pole kwadrata: " + k.getPole());
        System.out.println(k.podajParametry());
    }
}
