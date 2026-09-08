#include <SFML/Graphics.hpp>
#include <memory>
#include "UI.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({800.f,600.f}),"Call Of Truth : Air War");
    window.setPosition({200.f,200.f});
    while(window.isOpen())
    {
        while(const std :: optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()){window.close();}
            if (const auto* text = event->getIf<sf::Event::TextEntered>())
            {
                auto character = text->unicode;
            }
        }
        window.clear(sf::Color(220, 240, 255));

        window.display();
    }
}