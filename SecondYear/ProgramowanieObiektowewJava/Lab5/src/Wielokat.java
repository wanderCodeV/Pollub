class Wielokat extends Figura {
    int cntPoints;
    int cntSides;
    double sumAngle;

    public Wielokat() {
        super();
        cntPoints = 0;
        cntSides = 0;
        sumAngle = 0;
    }

    public Wielokat(int cntPoints, int cntSides, double sumAngle) {
        super();
        this.cntPoints = cntPoints;
        this.cntSides = cntSides;
        this.sumAngle = sumAngle;
    }

    public void setCntPoints(int cntPoints) {
        this.cntPoints = cntPoints;
    }

    public void setCntSides(int cntSides) {
        this.cntSides = cntSides;
    }

    public void setSumAngle(double sumAngle) {
        this.sumAngle = sumAngle;
    }

    public int getCntPoints() {
        return cntPoints;
    }

    public int getCntSides() {
        return cntSides;
    }

    public double getSumAngle() {
        return sumAngle;
    }

    @Override
    protected void rysuj() {
        System.out.println("Trwa rysowanie wielokata o " + cntPoints + " wierzcjolkach");
        super.rysuj();
    }

    @Override
    protected void usun() {
        System.out.println("Usuwanie wielokata...");
        super.usun();
    }

    @Override
    protected void przesun() {
        System.out.println("Przesuwanie wielokata...");
        super.przesun();
    }

    @Override
    protected String podajParametry() {
        return "Wielokat: cntPoints = " + cntPoints + ", cntSides = " + cntSides + ", sumAngle = " + sumAngle;
    }

    public void calculatesumAngle() {
        sumAngle = (cntPoints - 2) * 180;
    }
}
