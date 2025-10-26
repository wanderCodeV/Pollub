import java.util.Random;

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
        int size = rand.nextInt(10) + 10;
        int[][] arr = new int[size][size];
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
                if (i != j)
                    arr[i][j] = rand.nextInt(40) - 20;
                else
                    arr[i][j] = rand.nextInt(2) - 1;
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
        int sumaOddColumn = 0;
        int sumaEvenRow = 0;
        for(int i = 0; i < arr.length; i++)
        {
            for(int j = 0; j < arr.length; j++)
            {
                if(i % 2 == 0)
                    sumaEvenRow += arr[i][j];
                if(j % 2 == 1)
                    sumaOddColumn += arr[i][j];
            }
        }
        if(sumaOddColumn == 0)
            return 0;
        return (double) sumaEvenRow / sumaOddColumn;
    }
    public static void main(String[] args) {
        printArray(createArray());
        print2DArray(create2DArray());
        System.out.println("Stosunek " +  calculateRatio(create2DArray()));
    }
}