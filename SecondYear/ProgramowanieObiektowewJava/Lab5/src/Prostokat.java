public class Prostokat extends Wielokat{
    private double side1, side2;

    public Prostokat() {
        super();
        side1 = 0;
        side2 = 0;
    }

    public Prostokat(double side1, double side2) {
        super();
        this.side1 = side1;
        this.side2 = side2;
    }

    @Override
    protected void rysuj() {
        System.out.println("Rysuje prostokat...");
    }

    @Override
    protected void usun() {
        System.out.println("Usulam prostokat...");
    }

    @Override
    protected void przesun() {
        System.out.println("Przesulam prostokat...");
    }

    @Override
    protected String podajParametry() {
        return "Prostokat: strona a = " + side1 + ", strona b = " + side2;
    }

    public void obliczObwod() {
        super.setObwod(2*(side1+side2));
    }

    public void obliczPole() {
        super.setPole(side1*side2);
    }
}
