import javax.swing.*;
import java.awt.event.ActionListener;

public class calculator {

    private JButton plus;
    private JButton minus;
    private JButton mnozenie;
    private JButton dzielenie;
    private JButton potegowanie;
    private JButton pierwiastek;
    private JButton rownasie;
    private JButton clean;
    private JPanel panelСalculator;

    private JButton liczba1;
    private JButton liczba2;
    private JButton liczba3;
    private JButton liczba4;
    private JButton liczba5;
    private JButton liczba6;
    private JButton liczba7;
    private JButton liczba8;
    private JButton liczba9;
    private JButton liczba0;

    private JLabel ekran;

    private String wyrazenie = "";
    private double pierwszaLiczba = 0;
    private String aktualnaOperacja = "";
    private boolean pokazanyWynik = false;

    public calculator() {

        /* ===== PRZYCISKI LICZB ===== */
        ActionListener liczbyListener = e -> {
            if (pokazanyWynik) return;

            JButton b = (JButton) e.getSource();
            wyrazenie += b.getText();
            ekran.setText(wyrazenie);
        };

        liczba0.addActionListener(liczbyListener);
        liczba1.addActionListener(liczbyListener);
        liczba2.addActionListener(liczbyListener);
        liczba3.addActionListener(liczbyListener);
        liczba4.addActionListener(liczbyListener);
        liczba5.addActionListener(liczbyListener);
        liczba6.addActionListener(liczbyListener);
        liczba7.addActionListener(liczbyListener);
        liczba8.addActionListener(liczbyListener);
        liczba9.addActionListener(liczbyListener);

        /* ===== OPERATORY ===== */
        plus.addActionListener(e -> ustawOperacje("+"));
        minus.addActionListener(e -> ustawOperacje("-"));
        mnozenie.addActionListener(e -> ustawOperacje("*"));
        dzielenie.addActionListener(e -> ustawOperacje("/"));
        potegowanie.addActionListener(e -> ustawOperacje("^"));

        pierwiastek.addActionListener(e -> {
            try {
                if (pokazanyWynik) return;

                double a = Double.parseDouble(wyrazenie);
                if (a < 0)
                    throw new ArithmeticException("Pierwiastek z liczby ujemnej");

                double wynik = Math.sqrt(a);
                ekran.setText("√" + wyrazenie + "=" + wynik);
                wyrazenie = String.valueOf(wynik);
                pokazanyWynik = true;

            } catch (Exception ex) {
                pokazBlad(ex.getMessage());
            }
        });

        /* ===== = ===== */
        rownasie.addActionListener(e -> oblicz());

        /* ===== CLEAN ===== */
        clean.addActionListener(e -> {
            wyrazenie = "";
            pierwszaLiczba = 0;
            aktualnaOperacja = "";
            ekran.setText("");
            pokazanyWynik = false;
        });
    }

    private void ustawOperacje(String operacja) {
        try {
            if (wyrazenie.isEmpty()) return;

            if (pokazanyWynik) {
                pokazanyWynik = false;
            }

            pierwszaLiczba = Double.parseDouble(wyrazenie);
            aktualnaOperacja = operacja;
            wyrazenie += operacja;
            ekran.setText(wyrazenie);

        } catch (Exception e) {
            pokazBlad("Błędne dane");
        }
    }

    private void oblicz() {
        try {
            if (aktualnaOperacja.isEmpty()) return;

            String[] parts = wyrazenie.split("\\" + aktualnaOperacja);
            double drugaLiczba = Double.parseDouble(parts[1]);
            double wynik;

            switch (aktualnaOperacja) {
                case "+" -> wynik = pierwszaLiczba + drugaLiczba;
                case "-" -> wynik = pierwszaLiczba - drugaLiczba;
                case "*" -> wynik = pierwszaLiczba * drugaLiczba;
                case "/" -> {
                    if (drugaLiczba == 0)
                        throw new ArithmeticException("Dzielenie przez zero");
                    wynik = pierwszaLiczba / drugaLiczba;
                }
                case "^" -> wynik = Math.pow(pierwszaLiczba, drugaLiczba);
                default -> throw new IllegalStateException("Brak operacji");
            }

            ekran.setText(wyrazenie + "=" + wynik);
            wyrazenie = String.valueOf(wynik);
            pokazanyWynik = true;

        } catch (Exception e) {
            pokazBlad(e.getMessage());
        }
    }

    private void pokazBlad(String komunikat) {
        JOptionPane.showMessageDialog(panelСalculator, komunikat,
                "Błąd", JOptionPane.ERROR_MESSAGE);
        wyrazenie = "";
        ekran.setText("");
        pokazanyWynik = false;
    }

    public JPanel getPanelСalculator() {
        return panelСalculator;
    }
}
