import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

class Nalesnik {
    private int id;
    private boolean usmazony = false;
    private boolean posmarowany = false;
    private boolean zwiniety = false;

    public Nalesnik(int id) { this.id = id; }

    public void smaz() { usmazony = true; }
    public void smaruj() { posmarowany = true; }
    public void zwijaj() { zwiniety = true; }

    @Override
    public String toString() {
        return "Naleśnik #" + id + " [Smażenie: " + usmazony +
                ", Dżem: " + posmarowany + ", Rulon: " + zwiniety + "]";
    }
}

public class Task3 {
    public static void main(String[] args) {
        BlockingQueue<Nalesnik> doSmarowania = new ArrayBlockingQueue<>(3);
        BlockingQueue<Nalesnik> doZwijania = new ArrayBlockingQueue<>(3);

        Thread smazenieThread = new Thread(() -> {
            try {
                for (int i = 1; i <= 5; i++) {
                    Nalesnik n = new Nalesnik(i);
                    Thread.sleep(800);
                    n.smaz();
                    System.out.println("1. Usmażono: " + n);
                    doSmarowania.put(n);
                }
            } catch (InterruptedException e) { Thread.currentThread().interrupt(); }
        });

        Thread smarowanieThread = new Thread(() -> {
            try {
                for (int i = 1; i <= 5; i++) {
                    Nalesnik n = doSmarowania.take();
                    Thread.sleep(500);
                    n.smaruj();
                    System.out.println("2. Posmarowano: " + n);
                    doZwijania.put(n);
                }
            } catch (InterruptedException e) { Thread.currentThread().interrupt(); }
        });

        Thread zwijanieThread = new Thread(() -> {
            try {
                for (int i = 1; i <= 5; i++) {
                    Nalesnik n = doZwijania.take();
                    Thread.sleep(300);
                    n.zwijaj();
                    System.out.println("3. Zwinięto: " + n + " -> GOTOWE!");
                }
            } catch (InterruptedException e) { Thread.currentThread().interrupt(); }
        });

        smazenieThread.start();
        smarowanieThread.start();
        zwijanieThread.start();
    }
}
