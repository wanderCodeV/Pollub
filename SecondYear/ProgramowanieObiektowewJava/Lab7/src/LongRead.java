import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class LongRead {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Integer> numbers = new ArrayList<>();

        while (true) {
            System.out.print("Podaj liczbę (0 kończy): ");
            int n = scanner.nextInt();

            if (n == 0) {
                break;
            }

            numbers.add(n);
        }

        int count = numbers.size();
        int sum = 0;
        long product = 1;

        for (int num : numbers) {
            sum += num;
            product *= num;
        }

        System.out.println("Liczb wprowadzono: " + count);
        System.out.println("Suma: " + sum);
        System.out.println("Iloczyn: " + product);
    }
}
