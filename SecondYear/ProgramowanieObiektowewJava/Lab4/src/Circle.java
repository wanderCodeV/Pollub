import java.util.Random;

public class Circle {
    int x;
    int y;
    int radius;
    public Circle() {
        Random rand = new Random();
        x = rand.nextInt(91) + 5;
        y = rand.nextInt(91) + 5;
        radius = rand.nextInt(5) + 1;
    }
}
