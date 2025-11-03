abstract class Dziecko extends Czlowiek {
    public Dziecko(int years, String name)  {
        super(years, name);
    }

    abstract void zabawa();
    abstract void obowiazki();

    public void rysuj() {
        System.out.println(name + " rysuje kredkami.");
    }

    public void placz() {
        System.out.println(name + " płacze, bo zgubił zabawkę.");
    }
}
