class Uczen extends Dziecko implements Podstawowy, Szkola {
    public Uczen(int years, String name) {
        super(years, name);
    }

    public void jedz() {
        System.out.println(name + " je kanapkę.");
    }

    public void pij() {
        System.out.println(name + " pije sok.");
    }

    public void zabawa() {
        System.out.println(name + " bawi się na placu zabaw.");
    }

    public void obowiazki() {
        System.out.println(name + " odrabia lekcje.");
    }

    public void spij() {
        System.out.println(name + " śpi po szkole.");
    }

    public void wstan() {
        System.out.println(name + " wstaje rano.");
    }

    public void uczSie() {
        System.out.println(name + " uczy się matematyki.");
    }

    public void odrobLekcje() {
        System.out.println(name + " odrabia zadania.");
    }

    public void idzDoSzkoly() {
        System.out.println(name + " idzie do szkoły.");
    }

    public void grajNaPrzerwie() {
        System.out.println(name + " gra w piłkę.");
    }
}
