public interface IStudent {
    void zdajEgzamin(int nrEgzaminu, String przedmiot);
    Object[] pokazIndeks(int nrEgzaminu);
    double obliczSrednia();
    boolean czyStypendium();
}
