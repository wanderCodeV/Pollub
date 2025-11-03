class Okrag extends Elipsa {
    private double radius;

    public Okrag() {
        super();
        radius = 0;
    }

    public Okrag(double radius)
    {
        super();
        this.radius = radius;
    }

    @Override
    protected void rysuj() {
        System.out.println("Rysuje okrag...");
    }

    @Override
    protected void usun() {
        System.out.println("Usulam okrag...");
    }

    @Override
    protected void przesun() {
        System.out.println("Przesulam okrag...");
    }

    @Override
    protected String podajParametry() {
        return "Okrag: radius = " + radius;
    }

    public void obliczObwod() {
        super.setObwod(2*Math.PI*radius);
    }

    public void obliczPole() {
        super.setPole(Math.PI*radius);
    }
}
