package com.mycompany.kolekcje;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;
import java.util.ArrayList;
import javax.swing.JPanel;
import javax.swing.Timer;
import java.io.FileWriter;
import java.io.IOException;
import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileNotFoundException;

public class Panel extends JPanel {
    private static final int BUFFER_LIMIT = 30;
    private final int DELAY = 16;
    private final ArrayList<String> collisionBuffer = new ArrayList<>();
    private final ArrayList<Kula> listaKul;
    private final ArrayList<Kula> snieg = new ArrayList<>();
    private int size = 20;
    private final Timer timer;
    private final ArrayList<int[]> punktyKolizji = new ArrayList<>();
    private final boolean trybOdczytu;

    public Panel(boolean trybOdczytuIN) {
        listaKul = new ArrayList<>();
        setBackground(Color.BLACK);
        addMouseListener(new Event());
        addMouseWheelListener(new Event());
        timer = new Timer(DELAY, new Event());
        trybOdczytu = trybOdczytuIN;
        if (!trybOdczytu){
            File file = new File("kolizje.txt");
            try (FileWriter writer = new FileWriter(file, false)) {}
            catch (IOException e) {
                e.printStackTrace();
            }
            timer.start();
        }
        else
        {
            prostyOdczyt();
            repaint();
        }
    }

    public static void prostyZapis(double x, double y) {
        File file = new File("kolizje.txt");
        try {
            FileWriter fileWriter = new FileWriter(file, true);
            fileWriter.append(x + ";" + y + "\n");
            fileWriter.close();
        } catch (IOException ex) {
            System.err.println(ex.getMessage());
        }
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        if (trybOdczytu) {
            g.setColor(Color.YELLOW);
            for (int[] p : punktyKolizji)
            {
                g.fillOval(p[0] - 3, p[1] - 3, 6, 6);
            }
        } else {
            for (Kula k : listaKul) {
                g.setColor(k.color);
                g.drawOval(k.x, k.y, k.size, k.size);
            }
            g.setColor(Color.YELLOW);
            g.drawString(Integer.toString(listaKul.size()), 40, 40);
            for (Kula f : snieg) {
                g.setColor(f.color);
                g.fillOval(f.x, f.y, f.size, f.size);
            }
        }
    }

    public void prostyOdczyt() {
        try {
            BufferedReader bufferedReader = new BufferedReader(new FileReader(new File("kolizje.txt")));
            String linia;
            while ((linia = bufferedReader.readLine()) != null) {
                String[] dane = linia.split(";");
                int x = (int) Double.parseDouble(dane[0]);
                int y = (int) Double.parseDouble(dane[1]);
                punktyKolizji.add(new int[]{x, y});
            }
            bufferedReader.close();
        } catch (FileNotFoundException ex) {
            System.out.println("Pliku nie odnaleziono!");
        } catch (IOException ex) {
            System.out.println("Błąd odczytu pliku");
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
                    double nx = dx / dist;
                    double ny = dy / dist;
                    double contactX = a.x + nx * (a.size / 2.0);
                    double contactY = a.y + ny * (a.size / 2.0);
                    prostyZapis(contactX, contactY);
                    double overlap = minDist - dist;
                    a.x -= (int) ((overlap / 2) * nx);
                    a.y -= (int) ((overlap / 2) * ny);
                    b.x += (int) ((overlap / 2) * nx);
                    b.y += (int) ((overlap / 2) * ny);
                    double p = (a.xspeed * nx + a.yspeed * ny - b.xspeed * nx - b.yspeed * ny);
                    a.xspeed -= p * nx;
                    a.yspeed -= p * ny;
                    b.xspeed += p * nx;
                    b.yspeed += p * ny;
                    a.collisionCount++;
                    b.collisionCount++;
                }
            }
        }
        listaKul.removeIf(k -> k.collisionCount >= 5);
    }

    private class Event implements MouseListener, ActionListener, MouseWheelListener {
        @Override
        public void mouseClicked(MouseEvent e) {
        }

        @Override
        public void mousePressed(MouseEvent e) {
            if (!trybOdczytu) {
                listaKul.add(new Kula(e.getX(), e.getY(), size));
                repaint();
            }
        }

        @Override
        public void mouseReleased(MouseEvent e) {
        }

        @Override
        public void mouseEntered(MouseEvent e) {
            if (!trybOdczytu) timer.start();
        }

        @Override
        public void mouseExited(MouseEvent e) {
            if (!trybOdczytu) {
                timer.stop();
                snieg.clear();
                repaint();
            }
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            if (!trybOdczytu) {
                for (Kula k : listaKul) k.update();
                checkCollisions();
                for (Kula f : snieg) f.update();
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
        private final int MAX_SPEED = 5;
        public int x, y, size, xspeed, yspeed, collisionCount = 0;
        public Color color;

        public Kula(int x, int y, int size) {
            this.x = x;
            this.y = y;
            this.size = size;
            color = new Color((float) Math.random(), (float) Math.random(), (float) Math.random());
            do {
                xspeed = (int) (Math.random() * MAX_SPEED * 2 - MAX_SPEED);
                yspeed = (int) (Math.random() * MAX_SPEED * 2 - MAX_SPEED);
            } while (xspeed == 0 && yspeed == 0);
        }

        public void update() {
            x += xspeed;
            y += yspeed;
            if (x <= 0 || x >= getWidth() - size) xspeed = -xspeed;
            if (y <= 0 || y >= getHeight() - size) yspeed = -yspeed;
        }
    }
}
