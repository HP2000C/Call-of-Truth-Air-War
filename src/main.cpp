#include <SFML/Graphics.hpp>
#include <cmath>

class RoundedRectangle : public sf::Drawable
{
private:
    sf::ConvexShape shape;

public:
    RoundedRectangle(
        sf::Vector2f size,
        float radius,
        unsigned int cornerPoints = 8
    )
    {
        const unsigned int pointCount = cornerPoints * 4;
        shape.setPointCount(pointCount);

        const float pi = 3.14159265f;

        for (unsigned int corner = 0; corner < 4; ++corner)
        {
            float cx;
            float cy;

            if (corner == 0)
            {
                cx = radius;
                cy = radius;
            }
            else if (corner == 1)
            {
                cx = size.x - radius;
                cy = radius;
            }
            else if (corner == 2)
            {
                cx = size.x - radius;
                cy = size.y - radius;
            }
            else
            {
                cx = radius;
                cy = size.y - radius;
            }

            float startAngle = 0.f;

            if (corner == 0)
                startAngle = 180.f;
            else if (corner == 1)
                startAngle = 270.f;
            else if (corner == 2)
                startAngle = 0.f;
            else
                startAngle = 90.f;

            for (unsigned int i = 0; i < cornerPoints; ++i)
            {
                float angle =
                    (startAngle + i * 90.f / (cornerPoints - 1))
                    * pi / 180.f;

                shape.setPoint(
                    corner * cornerPoints + i,
                    {
                        cx + radius * std::cos(angle),
                        cy + radius * std::sin(angle)
                    }
                );
            }
        }
    }

    void setFillColor(sf::Color color)
    {
        shape.setFillColor(color);
    }

    void setPosition(sf::Vector2f position)
    {
        shape.setPosition(position);
    }

private:
    void draw(
        sf::RenderTarget& target,
        sf::RenderStates states
    ) const override
    {
        target.draw(shape, states);
    }
};
int main()
{
    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "My SFML App"
    );
    RoundedRectangle button({300.f, 80.f},20.f);

    button.setPosition({100.f, 100.f});
    button.setFillColor(sf::Color(220, 240, 255));
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color(230,248,255));

        window.draw(button);

        window.display();
    }
}