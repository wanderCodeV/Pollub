import java.util.Scanner;

public class Main {
    public static int cntSymbolInString(String text, char ch) {
        int cnt = 0;
        for(int i = 0; i < text.length(); i++)
        {
            if(text.charAt(i) == ch)
                cnt++;
        }
        return cnt;
    }
    public static int sumASCII(String text)
    {
        int sum = 0;
        for(int i = 0; i < text.length(); i++)
        {
            sum += text.charAt(i);
        }
        return sum;
    }
    public static char characterFromASCII()
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Podaj liczbe z zakresu <33, 126>: ");
        int n = sc.nextInt();
        while(n < 33 || n > 126)
        {
            System.out.print("Niepoprawna liczba. Podaj liczbe z zakresu <33, 126>: ");
            n = sc.nextInt();
        }
        return (char)n;
    }
    public static void main(String[] args) {
        //task 1
        String text = "Ala ma kota";
        char ch = 'a';
        int result = cntSymbolInString(text, ch);
        System.out.println("Zadanie 1: Znak '" + ch + "' występuje " + result + " razy w tekście: \"" + text + "\"");

        //task 2
        String text2 = "Hello World";
        int sum = sumASCII(text2);
        System.out.println("Zadanie 2: Suma ASCII \"" + text2 +"\": " + sum);

        //task 3
        char ch2 = characterFromASCII();
        System.out.println("Zadanie 3: Symbol ASCII: " + ch2);
    }
}