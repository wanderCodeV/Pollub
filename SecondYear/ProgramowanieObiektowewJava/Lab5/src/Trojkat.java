public class Trojkat extends Wielokat {
    private double height;
    private double side;

    public Trojkat() {
        super();
        height = 0;
        side = 0;
    }

    public Trojkat(double height, double side) {
        super();
        this.height = height;
        this.side = side;
    }

    @Override
    protected void rysuj() {
        System.out.println("Rysuje trojkat...");
    }

    @Override
    protected void usun() {
        System.out.println("Usulam trojkat...");
    }

    @Override
    protected void przesun() {
        System.out.println("Przesulam trojkat...");
    }

    @Override
    protected String podajParametry() {
        return "Trojkat: wysokosc = " + height + ", podstawa = " + side;
    }

    public void obliczObwod() {
        super.setObwod(3*side);
    }

    public void obliczPole() {
        super.setPole(side * height / 2);
    }
}
