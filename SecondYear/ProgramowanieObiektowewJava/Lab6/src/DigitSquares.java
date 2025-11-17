import java.util.Scanner;

public class DigitSquares {

    public static int getIntInRange(Scanner scanner) {
        while (true) {
            System.out.print("Podaj liczbę całkowitą z zakresu <99,999>: ");
            String input = scanner.nextLine();

            try {
                int number = Integer.parseInt(input);

                if (number < 99 || number > 999) {
                    System.out.println("Liczba poza zakresem! Spróbuj ponownie.");
                    continue;
                }

                return number;

            } catch (NumberFormatException e) {
                System.out.println("Błędne dane! Wprowadź liczbę całkowitą.");
            }
        }
    }

    public static int sumOfDigitSquares(int number) {
        int sum = 0;

        while (number > 0) {
            int digit = number % 10;
            sum += digit * digit;
            number /= 10;
        }

        return sum;
    }


    public static void calculateSum() {
        Scanner scanner = new Scanner(System.in);

        int number = getIntInRange(scanner);
        int sum = sumOfDigitSquares(number);

        System.out.println("Suma kwadratów cyfr: " + sum);
    }
}
