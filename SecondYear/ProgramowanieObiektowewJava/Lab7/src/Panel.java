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

public class Panel extends JPanel {

    private ArrayList<Kula> listaKul;
    private ArrayList<Kula> snieg = new ArrayList<>();
    private boolean snowing = false;
    private int size = 20;
    private Timer timer;
    private final int DELAY = 16; //dla 30fps -> 1s/30 = 0,033s

    public Panel() {
        listaKul = new ArrayList<>();
        setBackground(Color.BLACK);

        addMouseListener(new Event());
        addMouseWheelListener(new Event());

        timer = new Timer(DELAY, new Event());
        timer.start();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

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

    private class Event implements MouseListener, ActionListener, MouseWheelListener {

        @Override
        public void mouseClicked(MouseEvent e) {
            if (e.getButton() == MouseEvent.BUTTON1 && e.getClickCount() == 2) {
                snowing = !snowing;
            }
        }

        @Override
        public void mousePressed(MouseEvent e) {
            listaKul.add(new Kula(e.getX(), e.getY(), size));
            repaint();
        }

        @Override
        public void mouseReleased(MouseEvent e) {}

        @Override
        public void mouseEntered(MouseEvent e) {
            timer.start();
        }

        @Override
        public void mouseExited(MouseEvent e) {
            timer.stop();
            snieg.clear();
            snowing = false;
            repaint();
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            for (Kula k : listaKul) k.update();
            checkCollisions();

            if (snowing) {
                int x = (int)(Math.random() * getWidth());
                int size = 5 + (int)(Math.random() * 8);
                Kula flake = new Kula(x, 0, size);
                flake.color = new Color(1f, 1f, 1f, (float)(0.6 + Math.random() * 0.4));
                flake.xspeed = 0;
                flake.yspeed = 1 + (int)(Math.random() * 3);
                snieg.add(flake);
            }

            for (Kula f : snieg) f.update();

            repaint();
        }

        @Override
        public void mouseWheelMoved(MouseWheelEvent e) {
            size += e.getWheelRotation() * 2;
            if (size < 5) size = 5;
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

                    double p = 2 * (a.xspeed * nx + a.yspeed * ny - b.xspeed * nx - b.yspeed * ny) / 2;

                    a.xspeed -= p * nx;
                    a.yspeed -= p * ny;
                    b.xspeed += p * nx;
                    b.yspeed += p * ny;
                }
            }
        }
    }

    private class Kula {
        public int x, y, size, xspeed, yspeed;
        public Color color;
        private final int MAX_SPEED = 5;

        public Kula(int x, int y, int size) {
            this.x = x;
            this.y = y;
            this.size = size;

            color = new Color((float) Math.random(), (float) Math.random(), (float) Math.random());

            do {
                xspeed = (int)(Math.random() * MAX_SPEED * 2 - MAX_SPEED);
                yspeed = (int)(Math.random() * MAX_SPEED * 2 - MAX_SPEED);
            }
            while (xspeed == 0 && yspeed == 0);
        }

        public void update() {
            x += xspeed;
            y += yspeed;

            if (x <= 0 || x >= getWidth() - size)
                xspeed = -xspeed;
            if (y <= 0 || y >= getHeight() - size)
                yspeed = -yspeed;
        }
    }
}
