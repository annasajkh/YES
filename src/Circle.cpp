#include <Circle.h>
#include <math.h>


Circle::Circle(float x, float y, float radius, sf::Color* color)
    : position(new sf::Vector2f(x, y)), m_color(color)
{
    m_circle = new sf::CircleShape(radius);

    sf::Vector2f dir(1,0);
    float randomAngle  = static_cast<float> (std::rand() / static_cast<float> (RAND_MAX)) * M_PI * 2;

    float velX = std::cos(randomAngle) * 100;
    float velY = std::sin(randomAngle) * 100;

    velocity = new sf::Vector2f(velX, velY);
}

void Circle::update(const sf::RenderWindow& renderWindow, float delta)
{
    
    sf::Vector2u size = renderWindow.getSize();

    if(position->x < m_circle->getRadius())
    {
        velocity->x *= -1;
    }
    else if(position->x > size.x - m_circle->getRadius())
    {
        velocity->x *= -1;
    }
    else if(position->y < m_circle->getRadius())
    {
        velocity->y *= -1;
    }
    else if(position->y > size.y - m_circle->getRadius())
    {
        velocity->y *= -1;
    }

    position->x += velocity->x * delta;
    position->y += velocity->y * delta;
}

void Circle::draw(sf::RenderWindow& renderWindow)
{
    m_circle->setFillColor(*m_color);
    m_circle->setPosition(position->x,position->y);
    
    renderWindow.draw(*m_circle);
}

Circle:: ~Circle()
{
    delete m_circle;
    delete m_color;
    delete position;
    delete velocity;
}