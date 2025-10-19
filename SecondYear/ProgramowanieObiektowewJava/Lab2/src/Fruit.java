import java.awt.*;

public class Fruit {

    String name;
    double weight;
    String countryOfOrigin;

    Fruit(){

    }
    Fruit(String name, String countryOfOrigin){
        this.name = name;
        this.countryOfOrigin = countryOfOrigin;
    }

    public void enterWeight (double weightMeasured){
        this.weight = weightMeasured;
    }

    public void showWeight (){
        System.out.println(name + " " + weight);
    }

    public void showCountryOfOrigin(){
        System.out.println(name + " " + countryOfOrigin);
    }
}
