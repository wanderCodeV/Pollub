package com.mycompany.kolekcje;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.ArrayList;

public class Panel extends JPanel {
    private final int DELAY = 16;
    private final ArrayList<Kula> listaKul = new ArrayList<>();
    private final ArrayList<int[]> punktyKolizji = new ArrayList<>();
    private int size = 20;
    private final Timer timer;
    private boolean trybOdczytu = false;

    private final JButton btnStartStop = new JButton("Zatrzymaj");
    private final JButton btnWyczysc = new JButton("Wyczyść");
    private final JButton btnTryb = new JButton("Przełącz na Odczyt");

    public Panel() {
        setLayout(new BorderLayout());
        setBackground(Color.BLACK);

        JPanel sterowanie = new JPanel();
        sterowanie.setBackground(Color.DARK_GRAY);

        setupButtons();
        sterowanie.add(btnStartStop);
        sterowanie.add(btnWyczysc);
        sterowanie.add(btnTryb);
        add(sterowanie, BorderLayout.NORTH);

        Event eventHandler = new Event();
        addMouseListener(eventHandler);
        addMouseWheelListener(eventHandler);
        timer = new Timer(DELAY, eventHandler);

        resetFile();
        timer.start();
    }

    private void setupButtons() {
        btnStartStop.addActionListener(e -> {
            if (timer.isRunning()) {
                timer.stop();
                btnStartStop.setText("Wznów");
            } else {
                timer.start();
                btnStartStop.setText("Zatrzymaj");
            }
        });

        btnWyczysc.addActionListener(e -> {
            listaKul.clear();
            punktyKolizji.clear();
            resetFile();
            repaint();
        });

        btnTryb.addActionListener(e -> {
            trybOdczytu = !trybOdczytu;
            if (trybOdczytu) {
                timer.stop();
                prostyOdczyt();
                btnTryb.setText("Przełącz na Zapis");
                btnStartStop.setEnabled(false);
            } else {
                punktyKolizji.clear();
                btnTryb.setText("Przełącz na Odczyt");
                btnStartStop.setEnabled(true);
                btnStartStop.setText("Zatrzymaj");
                timer.start();
            }
            repaint();
        });
    }

    private void resetFile() {
        try (FileWriter writer = new FileWriter("kolizje.txt", false)) {
            // Czyści plik
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        if (trybOdczytu) {
            g.setColor(Color.YELLOW);
            for (int[] p : punktyKolizji) {
                g.fillOval(p[0] - 3, p[1] - 3, 6, 6);
            }
            g.drawString("TRYB ODCZYTU (Statyczny)", 10, 60);
        } else {
            for (Kula k : listaKul) {
                g.setColor(k.color);
                g.drawOval(k.x, k.y, k.size, k.size);
            }
            g.setColor(Color.YELLOW);
            g.drawString("Liczba kul: " + listaKul.size(), 10, 60);
        }
    }

    public void prostyZapis(double x, double y) {
        try (FileWriter fileWriter = new FileWriter("kolizje.txt", true)) {
            fileWriter.append(String.valueOf(x)).append(";").append(String.valueOf(y)).append("\n");
        } catch (IOException ex) {
            System.err.println(ex.getMessage());
        }
    }

    public void prostyOdczyt() {
        punktyKolizji.clear();
        try (BufferedReader br = new BufferedReader(new FileReader("kolizje.txt"))) {
            String linia;
            while ((linia = br.readLine()) != null) {
                String[] dane = linia.split(";");
                int x = (int) Double.parseDouble(dane[0]);
                int y = (int) Double.parseDouble(dane[1]);
                punktyKolizji.add(new int[]{x, y});
            }
        } catch (Exception ex) {
            System.out.println("Błąd pliku: " + ex.getMessage());
        }
    }

    private void checkCollisions() {
        for (int i = 0; i < listaKul.size(); i++) {
            for (int j = i + 1; j < listaKul.size(); j++) {
                Kula a = listaKul.get(i);
                Kula b = listaKul.get(j);
                double dx = b.x - a.x;
                double dy = b.y - a.y;
                double dist = Math.sqrt(dx * dx + dy * dy);
                double minDist = (a.size + b.size) / 2.0;
                if (dist < minDist && dist > 0) {
                    prostyZapis(a.x + (dx/2), a.y + (dy/2));
                    a.xspeed = -a.xspeed;
                    a.yspeed = -a.yspeed;
                    b.xspeed = -b.xspeed;
                    b.yspeed = -b.yspeed;
                    a.collisionCount++;
                    b.collisionCount++;
                }
            }
        }
        listaKul.removeIf(k -> k.collisionCount >= 5);
    }

    private class Event extends MouseAdapter implements ActionListener {
        @Override
        public void mousePressed(MouseEvent e) {
            if (!trybOdczytu) {
                listaKul.add(new Kula(e.getX(), e.getY(), size));
                repaint();
            }
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            if (!trybOdczytu && timer.isRunning()) {
                for (Kula k : listaKul) k.update();
                checkCollisions();
            }
            repaint();
        }

        @Override
        public void mouseWheelMoved(MouseWheelEvent e) {
            size += e.getWheelRotation() * 2;
            if (size < 5) size = 5;
        }
    }

    private class Kula {
        public int x, y, size, xspeed, yspeed, collisionCount = 0;
        public Color color;
        public Kula(int x, int y, int size) {
            this.x = x; this.y = y; this.size = size;
            this.color = new Color((float)Math.random(), (float)Math.random(), (float)Math.random());
            this.xspeed = (int)(Math.random()*10 - 5);
            this.yspeed = (int)(Math.random()*10 - 5);
        }
        public void update() {
            x += xspeed;
            y += yspeed;

            int topMargin = 40;

            if (x <= 0 || x >= getWidth() - size) xspeed = -xspeed;


            if (y <= topMargin) {
                y = topMargin;
                yspeed = -yspeed;
            }

            if (y >= getHeight() - size) {
                y = getHeight() - size;
                yspeed = -yspeed;
            }
        }
    }
}