import java.util.Arrays;
import java.util.Comparator;

public class Task2 {
    public static void sortArray(Integer[] lista, Comparator<Integer> comparator) {
        Arrays.sort(lista, comparator);
    }
    public static void main(String[] args) {
        Integer[] lista = {1, 17, 18, 5, 76, 4, 933, 32};

        sortArray(lista, (o1, o2) -> o1 - o2);

        System.out.println("Sortowanie rosnące:");
        System.out.println(Arrays.toString(lista));

        sortArray(lista, (o1, o2) -> o2 - o1);

        System.out.println("Sortowanie malejące:");
        System.out.println(Arrays.toString(lista));
    }
}
