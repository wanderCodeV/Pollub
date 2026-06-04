import java.util.*;

import java.io.*;


public class Fib {
    public static final String PATH = "fib.txt"; // 1a. Ścieżka do pliku
    // 1b. Zwykłe listy (bez synchronizedList)
    public static List<Integer> readedFib = new ArrayList<>();
    public static List<Integer> generatedFib = new ArrayList<>();

    public static void main(String[] args) {
        // 2a. Wątek czytający (wyrażenie lambda)
        Thread readFib = new Thread(() -> {
            try (Scanner scanner = new Scanner(new File(PATH))) {
                while (scanner.hasNextInt()) {
                    int value = scanner.nextInt();
                    // 2d. Synchronizacja dostępu do współdzielonego zasobu
                    synchronized (readedFib) {
                        readedFib.add(value);
                    }
                }
            } catch (FileNotFoundException e) {
                System.err.println("Błąd: Nie znaleziono pliku " + PATH);
            }
        });

        // 2a. Wątek generujący (wyrażenie lambda)
        Thread genFib = new Thread(() -> {
            try {
                // Musimy poczekać, aż readFib skończy czytać, żeby znać rozmiar listy
                readFib.join();
                int targetSize;
                synchronized (readedFib) {
                    targetSize = readedFib.size();
                }
                for (int i = 0; i < targetSize; i++) {
                    int nextVal;
                    if (i == 0) nextVal = 0;
                    else if (i == 1) nextVal = 1;
                    else {
                        // Pobieramy dwa poprzednie elementy do obliczeń
                        synchronized (generatedFib) {
                            nextVal = generatedFib.get(i - 1) + generatedFib.get(i - 2);
                        }
                    }
                    // Dodajemy nową liczbę do listy
                    synchronized (generatedFib) {
                        generatedFib.add(nextVal);
                    }
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        });
        // Uruchomienie wątków
        readFib.start();
        genFib.start();
        try {
            // 3. Oczekiwanie na zakończenie obu wątków przed porównaniem
            readFib.join();
            genFib.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        // 3. Porównanie i wypisanie w konsoli
        System.out.println("Porównanie ciągów:");
        for (int i = 0; i < generatedFib.size(); i++) {
            int r = readedFib.get(i);
            int g = generatedFib.get(i);
            String status = (r == g) ? "OK" : "BŁĄD";
            System.out.printf("Indeks %d: Odczytano: %d | Wygenerowano: %d -> %s%n", i, r, g, status);
        }
        // 4. Zapis błędów do pliku wyniki.txt
        saveErrors(readedFib, generatedFib);
    }

    private static void saveErrors(List<Integer> readed, List<Integer> generated) {
        try (PrintWriter writer = new PrintWriter(new FileWriter("wyniki.txt"))) {
            writer.print("Ciag poprawny:    ");
            for (int i = 0; i < readed.size(); i++) {
                writer.print(readed.get(i) + " ");
            }
            writer.println();
            writer.print("Ciag niepoprawny: ");
            for (int i = 0; i < generated.size(); i++) {
                writer.print(generated.get(i) + " ");
            }
            writer.println();
            for (int i = 0; i < readed.size(); i++) {
                if (!readed.get(i).equals(generated.get(i))) {
                    writer.println(i + ": " + readed.get(i));
                }
            }
            System.out.println("\nZapisano błędy do pliku wyniki.txt");
        } catch (IOException e) {
            System.err.println("Błąd zapisu do pliku.");
        }
    }
}