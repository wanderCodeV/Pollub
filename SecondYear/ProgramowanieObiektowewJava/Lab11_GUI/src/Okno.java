package com.mycompany.kolekcje;

import javax.swing.JFrame;
import javax.swing.SwingUtilities;

public class Okno {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Symulacja Kul - GUI");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

            frame.add(new Panel());

            frame.setSize(800, 600);
            frame.setLocationRelativeTo(null);
            frame.setVisible(true);
        });
    }
}