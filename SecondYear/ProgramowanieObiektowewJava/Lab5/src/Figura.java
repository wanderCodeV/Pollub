import java.awt.*;

public class Figura {

    protected double pole;
    protected double obwod;
    private Color kolor;

    public Figura()
    {
        this.pole = 0;
        this.obwod = 0;
        this.kolor = Color.BLACK;
    }
    public Figura (Color kolor, double pole, double obwod)
    {
        this.kolor = kolor;
        this.pole = pole;
        this.obwod = obwod;
    }
    protected void rysuj() {
        System.out.println("Rysuję figurę...");
    }

    protected void usun() {
        System.out.println("Usuwam figurę...");
    }

    protected void przesun() {
        System.out.println("Przesuwam figurę...");
    }

    protected String podajParametry() {
        return "Pole: " + pole + ", Obwód: " + obwod + ", Kolor: " + kolor;
    }
    public double getPole() {
        return pole;
    }
    public void setPole(double pole) {
        this.pole = pole;
    }
    public double getObwod() {
        return obwod;
    }

    public void setObwod(double obwod) {
        this.obwod = obwod;
    }

    public Color getKolor() {
        return kolor;
    }

    public void setKolor(Color kolor) {
        this.kolor = kolor;
    }
}
