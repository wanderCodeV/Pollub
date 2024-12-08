#include <SFML/Graphics.hpp>
#include <cmath>

int main() {
    const int width = 800;
    const int height = 600;
    sf::RenderWindow window(sf::VideoMode(width, height), "3D Spiral in SFML");

    const float radius = 100.f;
    const float heightStep = 5.f; // How much the height increases per angle step
    const float distanceFromCamera = 500.f; // Distance for perspective effect
    const int numPoints = 1000; // Number of points to draw in the spiral

    sf::VertexArray spiral(sf::LineStrip, numPoints);

    for (int i = 0; i < numPoints; ++i) {
        float theta = i * 0.1f; // Angle in radians
        float x = radius * cos(theta);
        float y = radius * sin(theta);
        float z = i * heightStep;

        // Apply perspective projection
        float x2D = width / 2 + x / (z / 100 + distanceFromCamera / 100);
        float y2D = height / 2 + y / (z / 100 + distanceFromCamera / 100);

        spiral[i].position = sf::Vector2f(x2D, y2D);
        spiral[i].color = sf::Color(255, 255 - i % 255, i % 255); // Gradient effect
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(spiral);
        window.display();
    }

    return 0;
}
