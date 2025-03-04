
#ifndef SHAPEMOVIMENT_H
#define SHAPEMOVIMENT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

class ShapeMoviment
{
    std::string m_type;
    std::string m_shapeName;
    float m_initialXPosition;
    float m_initialYPosition;
    float m_xVelocity;
    float m_yVelocity;
    std::uint8_t m_R;
    std::uint8_t m_G;
    std::uint8_t m_B;
    float m_width;
    float m_height;
    std::shared_ptr<sf::Shape> m_shape;
    sf::Text m_text;

public:
    ShapeMoviment(std::string type, std::string name, float xInitialPosition, float yInitialPosition, float xVelocity, float yVelocity, std::uint8_t R, std::uint8_t G, std::uint8_t B, float width, float heigth, sf::Font &font, int fontSize, std::uint8_t font_r, std::uint8_t font_g, std::uint8_t font_b);

    const sf::Shape &getShape() const;
    const sf::Text &getText() const;
    void const print() const;
    void makeShapeMoviment(int wHeight, int wWidth);
};

#endif
