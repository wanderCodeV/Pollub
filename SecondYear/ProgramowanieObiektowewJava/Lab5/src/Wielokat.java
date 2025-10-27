public class Wielokat extends Figura {
    int cntPoints;
    int cntSides;
    double sumAngle;
    public Wielokat()
    {
        super();
        cntPoints = 0;
        cntSides = 0;
        sumAngle = 0;
    }
    public Wielokat(int cntPoints, int cntSides, double sumAngle)
    {
        super();
        this.cntPoints = cntPoints;
        this.cntSides = cntSides;
        this.sumAngle = sumAngle;
    }
}
