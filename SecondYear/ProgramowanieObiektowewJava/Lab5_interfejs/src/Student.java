class Student extends Dorosly implements Podstawowy, Studia, Praca {
    public Student(int years, String name) {
        super(years, name);
    }

    public void jedz() {
        System.out.println(name + " je makaron instant.");
    }

    public void pij() {
        System.out.println(name + " pije kawę.");
    }

    public void zabawa() {
        System.out.println(name + " imprezuje.");
    }

    public void obowiazki() {
        System.out.println(name + " zdaje egzaminy.");
    }

    public void spij() {
        System.out.println(name + " śpi po zajęciach.");
    }

    public void wstan() {
        System.out.println(name + " wstaje na uczelnię.");
    }

    public void studiuj() {
        System.out.println(name + " studiuje informatykę.");
    }

    public void nieIdzNaZajecia() {
        System.out.println(name + " nie poszedł na wykład.");
    }

    public void napiszEgzamin() {
        System.out.println(name + " pisze egzamin.");
    }

    public void idzNaImpreze() {
        System.out.println(name + " idzie na imprezę.");
    }

    public void pracuj() {
        System.out.println(name + " pracuje w IT.");
    }

    public void placPodatki() {
        System.out.println(name + " płaci podatki.");
    }

    public void awansuj() {
        System.out.println(name + " awansował.");
    }

    public void idzNaUrlop() {
        System.out.println(name + " idzie na urlop.");
    }
}
