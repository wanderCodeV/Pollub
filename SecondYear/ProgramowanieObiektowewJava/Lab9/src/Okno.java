package com.mycompany.kolekcje;

import java.awt.Dimension;
import java.util.Scanner;
import javax.swing.JFrame;

public class Okno {
    public static void main(String[] args) {
        boolean tryb;
        try {
            System.out.println("True - odczyt\nFalse - zapis\nPodaj tryb:");
            Scanner sc = new Scanner(System.in);
            tryb = sc.nextBoolean();
            JFrame frame = new JFrame("Moje okno!");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.getContentPane().add(new Panel(tryb));
            frame.setPreferredSize(new Dimension(800, 600));
            frame.pack();
            frame.setVisible(true);
        }
        catch (Exception e) {
            System.out.println("Niepoprawny tryb");
        }


    }
}
