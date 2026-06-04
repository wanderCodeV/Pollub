import java.util.Random;

class RandomNumberGenerator implements Runnable {
    private final Random random = new Random();

    @Override
    public void run() {
        Random fixedRandom = new Random(12345);
        int number = random.nextInt(101);
        String threadName = Thread.currentThread().getName();
        System.out.println(threadName + " wylosowal: " + number);
    }
}

public class Task1 {
    public static void main(String[] args) {
        RandomNumberGenerator task = new RandomNumberGenerator();

        for (int i = 1; i <= 5; i++) {
            Thread thread = new Thread(task, "Watek-" + i);
            thread.start();
        }
    }
}