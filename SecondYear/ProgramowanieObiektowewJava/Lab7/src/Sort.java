import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Sort {

    public static void wypisz(ArrayList<Integer> lista) {
        for (int i = 0; i < lista.size(); i++) {
            System.out.print(lista.get(i) + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Integer> numbers = new ArrayList<>();
        int sum = 0;
        long product = 1;

        while (true) {
            System.out.print("Podaj liczb: ");
            int n = scanner.nextInt();

            sum += n;
            product *= n;

            if (Math.abs(sum) > 250 || Math.abs(product) > 3000000) {
                break;
            }

            numbers.add(n);
        }

        int count = numbers.size();

        System.out.println("Liczb wprowadzono: " + count);
        System.out.println("Suma: " + sum);
        System.out.println("Iloczyn: " + product);

        System.out.println("Kolekcja przed:");
        wypisz(numbers);

        for (int i = 0; i < count - 1; i++)
        {
            for(int j = 0; j < count - i - 1; j++)
            {
                if(numbers.get(j) > numbers.get(j+1))
                {
                    int temp = numbers.get(j);
                    numbers.set(j, numbers.get(j+1));
                    numbers.set(j + 1, temp);
                }
            }
        }
        System.out.println("Kolekcja po:");
        wypisz(numbers);
    }
}
