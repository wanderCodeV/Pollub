import java.util.Scanner;

public class Main {
    public static int cntSymbolInString(String text, char ch) {
        int cnt = 0;
        for (int i = 0; i < text.length(); i++) {
            if (text.charAt(i) == ch)
                cnt++;
        }
        return cnt;
    }

    public static int sumASCII(String text) {
        int sum = 0;
        for (int i = 0; i < text.length(); i++) {
            sum += text.charAt(i);
        }
        return sum;
    }

    public static char characterFromASCII() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Zadanie 3: Podaj liczbe z zakresu <33, 126>: ");
        int n = sc.nextInt();
        while (n < 33 || n > 126) {
            System.out.print("Niepoprawna liczba. Podaj liczbe z zakresu <33, 126>: ");
            n = sc.nextInt();
        }
        return (char) n;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Podaj numer zadanie: ");
        int task = sc.nextInt();
        switch (task) {
            case 1:
                String text = "Ala ma kota";
                char ch = 'a';
                int result = cntSymbolInString(text, ch);
                System.out.println("Zadanie 1: Znak '" + ch + "' występuje " + result + " razy w tekście: \"" + text + "\"");
                break;
            case 2:
                String text2 = "Hello World";
                int sum = sumASCII(text2);
                System.out.println("Zadanie 2: Suma ASCII \"" + text2 + "\": " + sum);
                break;
            case 3:
                char ch2 = characterFromASCII();
                System.out.println("Symbol ASCII: " + ch2);
                break;
            case 4:
                CesarShift cesar = new CesarShift();
                System.out.print("Zadanie 4: Podaj tekst do szyfrowania: ");
                String text3 = cesar.shifting(cesar.readText());
                System.out.print("Zaszyfrowany tekst: \"" + text3 + "\"");
                text3 = cesar.unshifting(text3);
                System.out.println(" Dezaszyfrowany tekst: \"" + text3 + "\"");

                if (cesar.isPalindrome(text3))
                    System.out.println("\"" + text3 + "\" jest palindromem");
                else
                    System.out.println("\"" + text3 + "\" NIE jest palindromem");
                break;
            case 5:
                BinarySystem binarka = new BinarySystem();
                System.out.print("Zadanie 5: Podaj liczbe: ");
                int n = sc.nextInt();
                String text4 = binarka.toBinary(n);
                System.out.println("Binarna reprezyntacja " + n + ": " + text4);
                System.out.println("Maksymalna sekwencja zer ma dlugosc: " + binarka.maxSubStringZero(text4));
                break;
            default:
                System.out.println("Nie ma takiego zadania");
        }
    }
}