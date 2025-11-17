import java.util.InputMismatchException;
import java.util.Scanner;

public class RealNumber {

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

    private static double divide(double a, double b) {
        if (b == 0) throw new ArithmeticException("Dzielenie przez zero.");
        return a / b;
    }

    public static void divideExMan() {
        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.print("Podaj liczbe zmiennoprzecinkowa: ");
            double a = getDouble(sc);
            double copya = a;
            int temp = 1;
            int cecha = (int) a;
            while(a != (int)a)
            {
                a *= 10;
                temp *= 10;
            }
            double mantysa = a - cecha*temp;

            System.out.println("Po rozdzieleniu: cecha = " + cecha + " mantyca = " + (int)mantysa);

            double wynik = divide(cecha , mantysa);
            System.out.println("Iloraz cechy i mantysy dla liczby " + copya + " = " + wynik);

        }
    }
}
