#ifndef SHAPEMOVIMENVECTOR_H
#define SHAPEMOVIMENVECTOR_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "shape_movement.h"
#include <memory>

class ShapeMovimentVector
{
    std::vector<ShapeMoviment> m_shapes;

public:
    ShapeMovimentVector();
    const std::vector<ShapeMoviment> &getShapes() const;
    void movementShapes(int wWidth, int wHeight);
    void addShape(const ShapeMoviment &shape);

    void loadShapesFromFile(const std::string &fileName, sf::Font &font);
};

#endif
