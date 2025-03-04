#include <memory>
#include "shape_movement.h"
#include <iostream>

ShapeMoviment::ShapeMoviment(std::string type, std::string name, float xInitialPosition, float yInitialPosition, float xVelocity, float yVelocity, std::uint8_t R, std::uint8_t G, std::uint8_t B, float width, float heigth, sf::Font &font, int fontSize, std::uint8_t font_r, std::uint8_t font_g, std::uint8_t font_b) : m_type(type),
                                                                                                                                                                                                                                                                                                                             m_shapeName(name),
                                                                                                                                                                                                                                                                                                                             m_initialXPosition(xInitialPosition),
                                                                                                                                                                                                                                                                                                                             m_initialYPosition(yInitialPosition),
                                                                                                                                                                                                                                                                                                                             m_xVelocity(xVelocity),
                                                                                                                                                                                                                                                                                                                             m_yVelocity(yVelocity),
                                                                                                                                                                                                                                                                                                                             m_R(R),
                                                                                                                                                                                                                                                                                                                             m_G(G),
                                                                                                                                                                                                                                                                                                                             m_B(B),
                                                                                                                                                                                                                                                                                                                             m_width(width),
                                                                                                                                                                                                                                                                                                                             m_height(heigth),
                                                                                                                                                                                                                                                                                                                             m_text(font, name, fontSize)

{
    m_text.setFillColor(sf::Color(font_r, font_g, font_b));
    if (m_type == "Circle")
    {
        m_height = m_width;
        m_shape = std::make_shared<sf::CircleShape>(m_width);
    }
    else
    {
        m_shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(m_width, m_height));
    }
    m_shape->setFillColor(sf::Color(m_R, m_G, m_B));
    m_shape->setPosition(sf::Vector2f(m_initialXPosition + m_width, m_initialYPosition + m_height));
};

const sf::Shape &ShapeMoviment::getShape() const
{
    return *m_shape;
}
const sf::Text &ShapeMoviment::getText() const
{
    return m_text;
}
void const ShapeMoviment::print() const
{
    std::cout << "Type " << m_type << std::endl;
    std::cout << "Name " << m_shapeName << std::endl;
    std::cout << "RGB " << m_R << m_G << m_B << std::endl;
    std::cout << "Height " << m_height << std::endl;
    std::cout << "Width " << m_width << std::endl;
    std::cout << "xVelocity " << m_xVelocity << std::endl;
    std::cout << "yVelocity " << m_yVelocity << std::endl;
    std::cout << "xInitPost " << m_initialXPosition << std::endl;
    std::cout << "yInitPost " << m_initialYPosition << std::endl;
    std::cout << "\n";
}
void ShapeMoviment::makeShapeMoviment(int wWidth, int wHeight)
{

    bool circleGoesDown = m_yVelocity > 0;
    bool circleGoesRight = m_xVelocity > 0;
    float shapeWidth = m_width;
    float shapeHeigth = m_height;
    sf::FloatRect x = m_shape->getLocalBounds();
    sf::FloatRect textLocalBounds = m_text.getLocalBounds();
    float getTextSize = (float)m_text.getCharacterSize();
    if (m_type == "Circle")
    {

        shapeWidth *= 2;
        shapeHeigth = shapeWidth;
        m_text.setPosition(sf::Vector2f(m_shape->getPosition().x + m_width - textLocalBounds.size.x / 2, m_shape->getPosition().y + m_width - getTextSize / 2));
    }
    else if (m_type == "Rectangle")
    {
        m_text.setPosition(sf::Vector2f(m_shape->getPosition().x + m_width / 2 - textLocalBounds.size.x / 2, m_shape->getPosition().y + m_height / 2 - getTextSize / 2));
    }
    if (circleGoesRight)
    {
        if (m_shape->getPosition().x + shapeWidth < wWidth)
        {
            m_shape->setPosition(m_shape->getPosition() + sf::Vector2f(m_xVelocity, m_yVelocity));
            circleGoesRight = true;
        }
        else
        {
            m_xVelocity *= -1;
            circleGoesRight = false;
        }
    }
    else if (!circleGoesRight)
    {

        if (m_shape->getPosition().x > 0)
        {
            m_shape->setPosition(m_shape->getPosition() + sf::Vector2f(m_xVelocity, m_yVelocity));
            circleGoesRight = true;
        }
        else
        {
            m_xVelocity *= -1;
            circleGoesRight = false;
        }
    }
    if (circleGoesDown)
    {
        if (m_shape->getPosition().y + shapeHeigth < wHeight)
        {
            m_shape->setPosition(m_shape->getPosition() + sf::Vector2f(m_xVelocity, m_yVelocity));
            circleGoesDown = true;
        }
        else
        {
            m_yVelocity *= -1;
            circleGoesDown = false;
        }
    }
    if (!circleGoesDown)
    {
        if (m_shape->getPosition().y > 0)
        {
            m_shape->setPosition(m_shape->getPosition() + sf::Vector2f(m_xVelocity, m_yVelocity));
            circleGoesDown = false;
        }
        else
        {
            m_yVelocity *= -1;
            circleGoesDown = true;
        }
    }
};
