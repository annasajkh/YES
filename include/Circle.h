#pragma once
#include <SFML/Graphics.hpp>

class Circle
{
    public:
        Circle(float x, float y, float radius, sf::Color* color);
        ~Circle();

        sf::Vector2f* position;
        sf::Vector2f* velocity;
        sf::Color* m_color; 

        void draw(sf::RenderWindow& renderWindow);
        void update(const sf::RenderWindow& renderWindow, float delta);
        
    private:
        sf::CircleShape* m_circle;
};