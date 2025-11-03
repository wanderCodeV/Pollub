class Elipsa extends Figura {
    private double smallRadius;
    private double bigRadius;
    private double F1x, F1y;
    private double F2x, F2y;
    private double lenCenter;

    public Elipsa()
    {
        super();
        smallRadius = 0;
        bigRadius = 0;
        F1x = F1y = F2x = F2y = 0;
        lenCenter = 0;
    }
    public Elipsa(double smallRadius, double bigRadius, double F1x, double F1y, double F2x, double F2y, double lenCenter) {
        super();
        this.smallRadius = smallRadius;
        this.bigRadius = bigRadius;
        this.F1x = F1x;
        this.F1y = F1y;
        this.F2x = F2x;
        this.F2y = F2y;
        this.lenCenter = lenCenter;
    }

    public double getSmallRadius() {
        return smallRadius;
    }

    public double getBigRadius() {
        return bigRadius;
    }

    public double getF1x() {
        return F1x;
    }

    public double getF1y() {
        return F1y;
    }

    public double getF2x() {
        return F2x;
    }

    public double getF2y() {
        return F2y;
    }

    public double getLenCenter() {
        return lenCenter;
    }

    public void setSmallRadius(double smallRadius) {
        this.smallRadius = smallRadius;
    }

    public void setBigRadius(double bigRadius) {
        this.bigRadius = bigRadius;
    }

    public void setF1x(double f1x) {
        this.F1x = f1x;
    }

    public void setF1y(double f1y) {
        this.F1y = f1y;
    }

    public void setF2x(double f2x) {
        this.F2x = f2x;
    }

    public void setF2y(double f2y) {
        this.F2y = f2y;
    }

    public void setLenCenter(double lenCenter) {
        this.lenCenter = lenCenter;
    }

    @Override
    protected void rysuj() {
        System.out.println("Trwa rysowanie elipsy o półosiach: smallRadius=" + smallRadius + ", bigRadius=" + bigRadius);
        super.rysuj();
    }

    @Override
    protected void usun() {
        System.out.println("Usuwanie elipsy...");
        super.usun();
    }

    @Override
    protected void przesun() {
        System.out.println("Przesuwanie elipsy...");
        super.przesun();
    }

    @Override
    protected String podajParametry() {
        return "Elipsa: smallRadius=" + smallRadius + ", bigRadius=" + bigRadius + ", ogniska=(" + F1x + "," + F1y + "),(" + F2x + "," + F2y + "), lenCenter=" + lenCenter + ", kolor=" + getKolor();
    }

    public void caluclateLenCenter() {
        lenCenter = Math.sqrt(smallRadius * smallRadius + bigRadius * bigRadius);
    }
}
