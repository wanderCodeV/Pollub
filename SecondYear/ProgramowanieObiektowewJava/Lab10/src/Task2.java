class Buffer {
    private int data;
    private boolean hasData = false;

    public synchronized void produce(int value) throws InterruptedException {
        while (hasData) {
            wait();
        }

        data = value;
        hasData = true;
        System.out.println("Wyprodukowano: " + data);

        notifyAll();
    }

    public synchronized int consume() throws InterruptedException {
        while (!hasData) {
            wait();
        }

        hasData = false;
        System.out.println("Skońsumowano: " + data);

        notifyAll();
        return data;
    }
}

class Producer implements Runnable {
    private Buffer buffer;

    public Producer(Buffer buffer) {
        this.buffer = buffer;
    }

    @Override
    public void run() {
        try {
            for (int i = 1; i <= 10; i++) {
                buffer.produce(i);
                Thread.sleep((long) (Math.random() * 500)); // Symulacja pracy
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

class Consumer implements Runnable {
    private Buffer buffer;

    public Consumer(Buffer buffer) {
        this.buffer = buffer;
    }

    @Override
    public void run() {
        try {
            for (int i = 1; i <= 10; i++) {
                buffer.consume();
                Thread.sleep((long) (Math.random() * 1000)); // Symulacja pracy
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

public class Task2 {
    public static void main(String[] args) {
        Buffer buffer = new Buffer();

        new Thread(new Producer(buffer)).start();
        new Thread(new Consumer(buffer)).start();
    }
}