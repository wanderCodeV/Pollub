//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void printSet()
    {
        for(int i=0;i<=54;i++)
            System.out.println(i);
    }
    public static void show_for(){
        for(int i=5;i<=80;i++)
            if((i-5)%15 == 0)
                System.out.print("i = " + i + " ");
        System.out.println();
    }
    public static void show_while(){
        int i = 5;
        while(i<=80)
        {
            if((i-5)%15 == 0)
                System.out.print("i = " + i + " ");
            i++;
        }
        System.out.println();
    }
    public static void check_triangle(int a, int b, int c)
    {
        if(a+b > c && a+c > b && b+c > a)
        {
            System.out.println("Can build triangle");
            if(a==b && b==c)
                System.out.println("Equilateral triangle");
            else if (a==b || b == c || c == a)
                System.out.println("Isosceles triangle");
            else
                System.out.println("Scalene triangle");
        }
        else
            System.out.println("Can't build triangle");
    }
    public static void show_aliquot_13()
    {
        for(int i=11;i<=111;i++)
            if(i%13 == 0)
                System.out.print("i = " + i + " ");
        System.out.println();
    }
    public static void showFibonacci(int n) {
        int a = 0, b = 1;

        for (int i = 0; i < n; i++) {
            int next = a + b;
            a = b;
            b = next;
            System.out.print(a + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        //task1
        EmptyClass current = new EmptyClass();
        System.out.println("current.cnt = " + current.cnt);
        System.out.println("current.symbol = " + current.symbol);
        System.out.println("current.name = " + current.name);
        //task2
        printSet();
        //task3
        Student ex1 = new Student();
        Student ex2 = new Student("Agnieszka", "Golab", 21, 4.3);
        System.out.println(ex1.name + " " + ex1.surname + " " + ex1.age + " " + ex1.avarage);
        System.out.println(ex2.name + " " + ex2.surname + " " + ex2.age + " " + ex2.avarage);
        //task4
        Fruit fruit1 = new Fruit("banan", "Colombia");
        fruit1.enterWeight(2.8);
        Fruit fruit2 = new Fruit("apple", "Chili");
        fruit2.enterWeight(128.3);
        fruit1.showCountryOfOrigin();
        fruit2.showWeight();
        //task5
        show_for();
        show_while();
        //task6
        check_triangle(3, 4, 5);
        check_triangle(3, 4, 18);
        //task7
        show_aliquot_13();
        //task8
        showFibonacci(15);
    }
}