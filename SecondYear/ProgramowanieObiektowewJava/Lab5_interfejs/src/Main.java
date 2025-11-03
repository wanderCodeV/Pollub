public class Main {
    public static void main(String[] args) {
        Uczen u = new Uczen(10, "Kasia");
        Student s = new Student(21, "Marek");
        Emeryt e = new Emeryt( 68, "Jan");

        System.out.println("--- UCZEŃ ---");
        u.ileLat();
        u.uczSie();
        u.zabawa();

        System.out.println("\n--- STUDENT ---");
        s.ileLat();
        s.studiuj();
        s.pracuj();

        System.out.println("\n--- EMERYT ---");
        e.ileLat();
        e.odbierzEmeryture();
        e.spacerujPoParku();
    }
}
