import javax.swing.*;
import java.awt.Dimension;

public class Main {
    public static void main(String[] args) {
        calculator okienko = new calculator();

        JFrame frame = new JFrame("Kalkulator!");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().add(okienko.getPanelСalculator());
        frame.setPreferredSize(new Dimension(800, 600));
        frame.pack();
        frame.setVisible(true);
    }
}