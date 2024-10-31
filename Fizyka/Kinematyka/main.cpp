#include <SFML/Graphics.hpp>
#include <cmath>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Vector Simulation");
    window.setFramerateLimit(100);

    sf::CircleShape point1(5);
    sf::CircleShape point2(5);
    point1.setFillColor(sf::Color::Red);
    point2.setFillColor(sf::Color::Blue);

    float t = 0.0f;
    const float dt = 0.01f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float x1 = t * t;
        float y1 = 3 * t;
        float x2 = t * t;
        float y2 = 2;

        point1.setPosition(100 + x1 * 10, 500 - y1 * 10);
        point2.setPosition(100 + x2 * 10, 500 - y2 * 10);

        t += dt;

        window.clear();
        window.draw(point1);
        window.draw(point2);
        window.display();
    }

    return 0;
}
