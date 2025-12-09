import java.util.Random;

public class Student extends Osoba implements IStudent{
    private int nrIndeksu;
    private Object[][] oceny;

    public Student(Plec in_plec) {
        super(in_plec);

        oceny = new Object[5][2];

        for(int i = 0; i < 5; i++){
            oceny[i][0] = null;
            oceny[i][1] = Ocena.NIEDOSTATECZNY;
        }
    }

    @Override
    public void zdajEgzamin(int nrEgzaminu, String przedmiot) {
        Random rand = new Random();
        Ocena[] all_values = Ocena.values();
        Ocena wylosowana = all_values[rand.nextInt(all_values.length)];

        oceny[nrEgzaminu][0] = przedmiot;
        oceny[nrEgzaminu][1] = wylosowana;
    }

    @Override
    public Object[] pokazIndeks(int nrEgzaminu) {
        if(oceny[nrEgzaminu][1] == null)
            return new Object[]{"Brak_przedmiotu", Ocena.NIEDOSTATECZNY};

        return oceny[nrEgzaminu];
    }

    @Override
    public double obliczSrednia() {
        double suma = 0;

        for (int i = 0; i < 5; i++) {
            if (oceny[i][0] == null) {
                throw new IllegalStateException("Nie wszystkie oceny są wystawione!");
            }

            Ocena o = (Ocena) oceny[i][1];

            switch (o) {
                case NIEDOSTATECZNY:
                    suma += 2;
                    break;
                case DOSTATECZNY:
                    suma += 3;
                    break;
                case DOSTATECZNY_PLUS:
                    suma += 3.5;
                    break;
                case DOBRY:
                    suma += 4;
                    break;
                case DOBRY_PLUS:
                    suma += 4.5;
                    break;
                case BARDZO_DOBRY:
                    suma += 5;
                    break;
            }
        }
        return suma / 5;
    }

    @Override
    public boolean czyStypendium() {
        try {
            return (obliczSrednia() > 4.75);
        } catch (IllegalStateException e) {
            return false;
        }

    }
}
