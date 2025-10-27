import java.util.Random;
import java.util.Scanner;

public class Main {
    public static int[] createArray() {
        int[] arr = new int[100];
        for (int i = 0; i < 100; i++)
            arr[i] = i;
        return arr;
    }
    public static void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++)
        {
            if(arr[i] < 10)
                System.out.print("0" + arr[i] + ", ");
            else
                System.out.print(arr[i] + ", ");

            if(i % 10 == 9)
                System.out.println();
        }
        for (int i = 0; i < 10; i++)
        {
            int avg = 0;
            for(int j = i; j < arr.length; j+= 10)
                avg += arr[j];
            System.out.print(avg / 10 + ", ");
        }
    }
    public static int[][] create2DArray() {
        Random rand = new Random();
        int size = rand.nextInt(11) + 10;
        int[][] arr = new int[size][size];
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
                if (i != j)
                    arr[i][j] = rand.nextInt(41) - 20;
                else
                    arr[i][j] = rand.nextBoolean() ? 1 : -1;
        }
        return arr;
    }
    public static void print2DArray(int[][] arr) {
        System.out.println("\nTablica kwadratowa");
        for(int i = 0; i < arr.length; i++)
        {
            for(int j = 0; j < arr.length; j++)
                System.out.print(arr[i][j] + " ");
            System.out.println();
        }
    }
    public static double calculateRatio(int [][]arr) {
        int sumaEvenRow = 0;
        int sumaOddColumn = 0;

        for(int i = 0; i < arr.length; i++) {
            for(int j = 0; j < arr.length; j++) {
                if(i % 2 == 0)
                    sumaEvenRow += arr[i][j];
                if(j % 2 == 1)
                    sumaOddColumn += arr[i][j];
            }
        }

        if (sumaOddColumn == 0) {
            System.out.println("\nBrak możliwości dzielenia – suma w kolumnach nieparzystych = 0.");
            return 0;
        }

        return (double)sumaEvenRow / sumaOddColumn;
    }
    public static Circle[] createCircleArray(int n) {
        Circle [] arr = new Circle[n];
        for(int i = 0; i < n; i++)
            arr[i] = new Circle();
        return arr;
    }
    public static void printRatioCircles(Circle o1, Circle o2) {
        double dist = Math.sqrt(Math.pow(o1.x - o2.x, 2) + Math.pow(o1.y - o2.y, 2));

        if (dist == 0 && o1.radius == o2.radius)
            System.out.println("Pokrywają się");
        else if (dist == o1.radius + o2.radius)
            System.out.println("Styczne zewnętrznie");
        else if (dist == Math.abs(o1.radius - o2.radius))
            System.out.println("Styczne wewnętrznie");
        else if (dist > o1.radius + o2.radius)
            System.out.println("Rozłączne");
        else
            System.out.println("Przecinają się");
    }
    public static void printAreaCircle(Circle [] arr) {
        for (Circle ob : arr)
        {
            System.out.println("x = " + ob.x + ", y = " + ob.y + ", r = " + ob.radius);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Podaj numer zadanie: ");
        int task = sc.nextInt();
        switch (task) {
            case 1:
                System.out.println("Zadanie 1");
                printArray(createArray());
                break;
            case 2:
                System.out.println("Zadanie 2");
                int[][] tab1 = create2DArray();
                print2DArray(tab1);
                System.out.println("Stosunek " +  calculateRatio(tab1));
                break;
            case 3:
                Circle[] tab = createCircleArray(100);
                printAreaCircle(tab);

                Random rand = new Random();
                for(int i = 0; i < 10; i++)
                {
                    int x1 = rand.nextInt(100);
                    int x2 = rand.nextInt(100);
                    System.out.println("\nPołożenie " + x1 + " i " + x2 + " okręgu:");
                    printRatioCircles(tab[x1], tab[x2]);
                }

                break;
            default:
                System.out.println("Nie ma takiego zadania");
        }
    }
}