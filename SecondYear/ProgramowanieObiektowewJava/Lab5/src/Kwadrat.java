public class Kwadrat extends Wielokat{
    private double side;

    public Kwadrat() {
        super();
        side = 0;
    }
    public Kwadrat(double side) {
        super();
        this.side = side;
    }

    @Override
    protected void rysuj() {
        System.out.println("Rysuje kwadrat...");
    }

    @Override
    protected void usun() {
        System.out.println("Usulam kwadrat...");
    }

    @Override
    protected void przesun() {
        System.out.println("Przesulam kwadrat...");
    }

    @Override
    protected String podajParametry() {
        return "Kwadrat: strona = " + side;
    }

    public void obliczObwod() {
        super.setObwod(4*side);
    }

    public void obliczPole() {
        super.setPole(side*side);
    }
}
