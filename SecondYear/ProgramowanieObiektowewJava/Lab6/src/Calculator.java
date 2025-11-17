import java.util.InputMismatchException;
import java.util.Scanner;

public class Calculator {

    private static int readInt(Scanner scanner) {
        while (true) {
            try {
                return scanner.nextInt();
            } catch (InputMismatchException e) {
                System.out.print("Błąd! Podaj poprawną liczbę całkowitą: ");
                scanner.nextLine();
            }
        }
    }

    private static double getDouble(Scanner scanner) {
        while (true) {
            try {
                return scanner.nextDouble();
            } catch (InputMismatchException e) {
                System.out.print("Błędne dane! Podaj liczbę: ");
                scanner.nextLine();
            }
        }
    }

    private static double divide(Scanner scanner, double a) {
        double b;
        while (true) {
            System.out.print("Podaj drugą liczbę (różną od 0): ");
            b = getDouble(scanner);
            if (b != 0) break;
            System.out.println("Nie można dzielić przez zero!");
        }
        return a / b;
    }

    private static double pow(Scanner scanner, double a) {
        double b;
        while (true) {
            System.out.print("Podaj wykładnik: ");
            b = getDouble(scanner);
            if (a != 0 || b != 0) break;
            System.out.println("0 do potęgi 0 jest nieokreślone. Podaj inną wartość.");
        }
        return Math.pow(a, b);
    }

    private static double sqrt(Scanner scanner) {
        double x;
        while (true) {
            System.out.print("Podaj liczbę do pierwiastkowania: ");
            x = getDouble(scanner);
            if (x >= 0) break;
            System.out.println("Nie można pierwiastkować liczby ujemnej!");
        }
        return Math.sqrt(x);
    }

    public static void runCalculator() {
        System.out.println("\n=== KALKULATOR ===");
        System.out.println("1. Dodawanie");
        System.out.println("2. Odejmowanie");
        System.out.println("3. Mnożenie");
        System.out.println("4. Dzielenie");
        System.out.println("5. Pierwiastkowanie");
        System.out.println("6. Potęgowanie");
        System.out.print("Wybierz działanie: ");

        Scanner sc = new Scanner(System.in);
        int choice = readInt(sc);

        double a = 0, wynik;

        try {
            if (choice != 5) {
                System.out.print("Podaj pierwszą liczbę: ");
                a = getDouble(sc);
            }

            switch (choice) {
                case 1 -> {
                    System.out.print("Podaj drugą liczbę: ");
                    double b = getDouble(sc);
                    wynik = a + b;
                }
                case 2 -> {
                    System.out.print("Podaj drugą liczbę: ");
                    double b = getDouble(sc);
                    wynik = a - b;
                }
                case 3 -> {
                    System.out.print("Podaj drugą liczbę: ");
                    double b = getDouble(sc);
                    wynik = a * b;
                }
                case 4 -> wynik = divide(sc, a);
                case 5 -> wynik = sqrt(sc);
                case 6 -> wynik = pow(sc, a);
                default -> throw new IllegalArgumentException("Nieprawidłowa operacja.");
            }

            System.out.println("Wynik: " + wynik);

        } catch (Exception e) {
            System.out.println("Błąd: " + e.getMessage());
        }
    }

}
