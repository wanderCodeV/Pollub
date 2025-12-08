import java.util.Arrays;
import java.util.Comparator;

public class Task3 {
    public static void sortArray(String[] lista, Comparator<String> comparator) {
        Arrays.sort(lista, comparator);
    }
    public static void main(String[] args) {
        String[] lista = {"AAA", "alaMa", "Kotek", "piesek", "bal"};

        sortArray(lista, (o1, o2) -> o1.length() - o2.length());

        System.out.println("Sortowanie według długości rosnąco:");
        System.out.println(Arrays.toString(lista));

        sortArray(lista, (o1, o2) -> o2.length() - o1.length());

        System.out.println("Sortowanie według długości malejąco:");
        System.out.println(Arrays.toString(lista));
    }
}
