public class Student {
    String name;
    String surname;
    int age;
    double avarage;

    Student()
    {
        name = "Adam";
        surname = "Nowak";
        age = 19;
        avarage = 3.8;
    }

    Student(String name, String surname, int age, double avarage)
    {
        this.name=name;
        this.surname=surname;
        this.age=age;
        this.avarage=avarage;
    }
}
