#include <SFML/Graphics.hpp>
#include <cmath>
#include <memory>
#include <functional>

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
    void SetOutline(sf::Color color)
    {
        shape.setOutlineColor(color);
    }
    void SetThikness(float thick)
    {
        shape.setOutlineThickness(thick);
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

using Button = class Button 
{
    std::unique_ptr<RoundedRectangle> ptr;
    public:
    Button(sf::Vector2f pos,sf::Color col,sf::Color oco,float thi = 1.f,sf::Vector2f siz)
    {
        ptr = std :: make_unique<RoundedRectangle> (siz,20.f);
        ptr.get()->setPosition(pos);
        ptr.get()->setFillColor(col);
        ptr.get()->SetOutline(oco);
        ptr.get()->SetThikness(thi);
    }
    bool IsClicked(sf::RenderWindow win)
    {
        std :: optional event = win.pollEvent();
        if (const auto* mouse = event->getIf<sf::Event::MouseButtonPressed>())
        {
            sf::Vector2i pos = mouse->position;
            if(pos.x)
        }
    }
};