import java.util.ArrayList;

public class Task1 {
    public static void printLista(ArrayList<String> lista, Printer printer) {
        for (String s : lista) {
            printer.metoda_abstrakcyjna(s);
        }
    }
    public static void main(String[] args) {
        ArrayList<String> lista_przedmiotow = new ArrayList<>();
        lista_przedmiotow.add("Matematyka");
        lista_przedmiotow.add("Fizyka");
        lista_przedmiotow.add("Programowanie");
        lista_przedmiotow.add("Sieci komputerowe");

        printLista(lista_przedmiotow, s -> System.out.println(s));
    }
}