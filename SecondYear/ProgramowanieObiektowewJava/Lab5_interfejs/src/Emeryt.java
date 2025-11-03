class Emeryt extends Dorosly implements Podstawowy, Emerytura {
    public Emeryt(int years, String name) {
        super(years, name);
    }

    public void jedz() { System.out.println(name + " je zupę jarzynową."); }
    public void pij() { System.out.println(name + " pije herbatę."); }

    public void zabawa() { System.out.println(name + " gra w szachy."); }
    public void obowiazki() { System.out.println(name + " odbiera wnuki."); }

    public void spij() { System.out.println(name + " śpi po południu."); }
    public void wstan() { System.out.println(name + " wstaje rano."); }

    public void odbierzEmeryture() { System.out.println(name + " odbiera emeryturę."); }
    public void idzDoLekarza() { System.out.println(name + " idzie do lekarza."); }
    public void opiekujSieWnukami() { System.out.println(name + " opiekuje się wnukami."); }
    public void spacerujPoParku() { System.out.println(name + " spaceruje po parku."); }
}
