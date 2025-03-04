#include <memory>
#include "shape_movement_vector.h"
#include "shape_movement.h"
#include <iostream>
#include <fstream>

ShapeMovimentVector::ShapeMovimentVector() {};
void ShapeMovimentVector::addShape(const ShapeMoviment &shape)
{
    m_shapes.push_back(shape);
}
const std::vector<ShapeMoviment> &ShapeMovimentVector::getShapes() const
{
    return m_shapes;
}
void ShapeMovimentVector::movementShapes(int wWidth, int wHeight)
{
    for (ShapeMoviment &s : m_shapes)
    {
        s.makeShapeMoviment(wWidth, wHeight);
    }
}
void ShapeMovimentVector::loadShapesFromFile(const std::string &fileName, sf::Font &font)
{
    std::ifstream fin(fileName);
    std::string type, name, fontName;
    float initXPos;
    float initYPos;
    float xVel;
    float yVel;
    int r;
    int g;
    int b;
    float width;
    float height;
    int fontSize = 18;
    int font_r;
    int font_g;
    int font_b;

    while (fin >> type)
    {
        if (type == "Font")

        {
            fin >> fontName >> fontSize >> font_r >> font_g >> font_b;

            if (!font.openFromFile(fontName))
            {
                std::cerr << "ERROR: COULD NOT LOAD FILE::" << fontName << "!!!" << std::endl;
            }
        }

        else if (type == "Circle")
        {
            fin >> name >> initXPos >> initYPos >> xVel >> yVel >> r >> g >> b >> width;
            height = 0;
            addShape(ShapeMoviment(type, name, initXPos, initYPos, xVel, yVel, r, g, b, width, height, font, fontSize, font_r, font_g, font_b));
        }
        else if (type == "Rectangle")
        {
            fin >> name >> initXPos >> initYPos >> xVel >> yVel >> r >> g >> b >> width >> height;
            addShape(ShapeMoviment(type, name, initXPos, initYPos, xVel, yVel, r, g, b, width, height, font, fontSize, font_r, font_g, font_b));
        }

        if (!fin)
        {
            std::cerr << "Erro ao ler dados do arquivo para a forma " << name << std::endl;
            break;
        }
    }
    fin.close();
}
