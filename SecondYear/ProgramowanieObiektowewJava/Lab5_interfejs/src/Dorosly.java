abstract class Dorosly extends Czlowiek {
    public Dorosly(int years, String name) {
        super(years, name);
    }

    abstract void zabawa();
    abstract void obowiazki();

    public void odpoczywaj() {
        System.out.println(name + " odpoczywa po pracy.");
    }

    public void gotuj() {
        System.out.println(name + " gotuje obiad.");
    }
}
