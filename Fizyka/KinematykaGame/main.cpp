#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#define G 9.8
#define PI 3.14159265

using namespace std;
using namespace sf;

const int r = 15;
const Vector2f screenSize(1500, 800);
int main()
{
    VertexArray trajektory_mandarynka(LineStrip);
    VertexArray trajektory_target(LineStrip);

    sf::CircleShape mandarynka(r);
    mandarynka.setFillColor(sf::Color(242, 133, 0));

    sf::CircleShape win(r);
    mandarynka.setFillColor(sf::Color::Red);

    sf::CircleShape target(r);
    target.setFillColor(sf::Color(0, 207, 217));

    sf::RectangleShape ground(sf::Vector2f(screenSize.x, 150));
    ground.setPosition(0, screenSize.y - 100);
    ground.setFillColor(sf::Color(119, 141, 69));

    sf::RectangleShape floor(sf::Vector2f(98, 98));
    Vector2f coord_floor(0, screenSize.y - 200);
    floor.setPosition(coord_floor.x, coord_floor.y);
    floor.setFillColor(sf::Color(188, 189, 207));
    floor.setOutlineThickness(2);
    floor.setOutlineColor(sf::Color::Black);

    float t = 0.0f;
    const float dt = 0.02f;

    // Input parameters
    float h, vec_speed, angle;
    cout << "Enter speed of tangerine: ";
    cin >> vec_speed;
    cout << "Enter floor of dormitory (place where we throw tangerine): ";
    cin >> h;
    while(h < 0 || h > 7)
    {
        cout << "\tError!\nEnter floor of dormitory (place where we throw tangerine): ";
        cin >> h;
    }
    cout << "Enter angle at which we throw tangerine: ";
    cin >> angle;
    while(angle < 0 || angle > 90)
    {
        cout << "\tError!\nEnter angle at which we throw tangerine: ";
        cin >> angle;
    }

    Vector2f coord_mandarynka, coord_target;
    Vector2f start_mandarynka(100, (h + 1) * 100);
    Vector2f start_target(800, 1000);

    sf::CircleShape triangle(r/1., 3);
    triangle.setFillColor(sf::Color::Red);
    triangle.setPosition(start_mandarynka.x , screenSize.y - start_mandarynka.y);

    Vector2f speed(vec_speed * cos(angle * PI / 180.0), vec_speed * sin(angle * PI / 180.0));

    // Create a render window with the custom size
    sf::RenderWindow window(sf::VideoMode(screenSize.x, screenSize.y), "SFML Vector Simulation");
    window.setFramerateLimit(100);

    bool flag = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

            if (coord_mandarynka.y < screenSize.y - 100 - 2*r || t == 0.0f)
            {
                coord_mandarynka.x = start_mandarynka.x + speed.x * t;
                coord_mandarynka.y = screenSize.y - (start_mandarynka.y + speed.y * t - G * t * t / 2);
            }
            else
            {
                coord_mandarynka.y =  screenSize.y - 100 - 2*r;
            }


            mandarynka.setPosition(coord_mandarynka.x, coord_mandarynka.y);

            if (coord_target.y < screenSize.y - 100 - 2*r || t == 0.0f)
            {
                coord_target.x = start_target.x;
                coord_target.y = screenSize.y - (start_target.y - G * t * t / 2);
            }
            else
                coord_target.y = screenSize.y - 100 - 2*r;

            target.setPosition(coord_target.x, coord_target.y);
            t += dt;

            trajektory_mandarynka.append(Vector2f(coord_mandarynka.x + r, coord_mandarynka.y + r));
            trajektory_target.append(Vector2f(coord_target.x + r, coord_target.y));

        window.clear(sf::Color::Blue);

        if (abs(coord_mandarynka.x - coord_target.x) < 0.1 && abs(coord_mandarynka.y - coord_target.y) < 0.1)
        {
            win.setPosition(coord_target);
            flag = true;
        }

        if(flag)
            window.draw(win);

        window.draw(trajektory_target);
        window.draw(trajektory_mandarynka);

        window.draw(target);
        window.draw(mandarynka);


        window.draw(ground);

        for (int i = 0; i < h; i++)
        {
            floor.setPosition(coord_floor.x, coord_floor.y - i * 100);
            window.draw(floor);
        }
        window.draw(triangle);
        window.display();
    }

    return 0;
}

/*
100
2
45
*/
