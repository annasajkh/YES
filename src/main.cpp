#include <SFML/Graphics.hpp>
#include <Circle.h>
#include <pch.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 600), "Circle");

    sf::Vector2u size = window.getSize();
    
    sf::Clock deltaClock; 
    std::array<std::unique_ptr<Circle>,1000> circles;

    for (unsigned int i = 0; i < circles.size(); i++)
    {
        circles[i] = std::unique_ptr<Circle>(   new Circle(std::rand() % size.x,std::rand() % size.y,10, 
                                                new sf::Color(  std::rand() % 255,
                                                std::rand() % 255,
                                                std::rand() % 255,255)));
    }
    

    while (window.isOpen())
    {
        sf::Time deltaTime = deltaClock.restart();
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (std::unique_ptr<Circle>& circle : circles)
        {
            circle->update(window, deltaTime.asSeconds());
        }

        window.clear();

        for (std::unique_ptr<Circle>& circle : circles)
        {
            circle->draw(window);
        }
        
        window.display();
    }
}
