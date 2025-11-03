abstract class Czlowiek {
    String name;
    int years;

    public Czlowiek() {
        years = 0;
        name = "No name";
    }
    public Czlowiek(int years, String name) {
        this.years = years;
        this.name = name;
    }

    abstract void jedz();

    abstract void pij();

    public void ileLat() {
        System.out.println(name + " ma " + years + " lat");
    }

    public void cechy() {
        System.out.println("Czlowiek ma cechy ...");
    }
}
