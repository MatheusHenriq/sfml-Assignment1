#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include "lib/shape_movement.h"
#include "lib/shape_movement_vector.h"

void LoadFont(sf::Font &font, std::string str)
{
    if (!font.openFromFile(str))
    {
        std::cerr << "ERROR: COULD NOT LOAD FILE::" << str << "!!!" << std::endl;
    }
}

std::tuple<int, int> readFromFile(const std::string &fileName)
{
    std::ifstream fin(fileName);
    std::string type;
    int width = 1280, height = 720;
    while (fin >> type)
    {
        if (type == "Window")
        {
            fin >> width >> height;
            std::cout << width << " " << height << std::endl;
        }
    }
    fin.close();

    return std::make_tuple(width, height);
}

int main()
{

    std::string inputFileName = "input_files/input_file.txt";
    std::string fontFileName = "Tech.ttf";

    auto [w, h] = readFromFile(inputFileName);
    sf::RenderWindow window(sf::VideoMode({(unsigned int)w, (unsigned int)h}), "Assignment 1!");
    window.clear();
    int frameRateLimit = 144;
    std::cout << window.getSize().x << " " << window.getSize().y << std::endl;
    window.setFramerateLimit(frameRateLimit);
    sf::CircleShape shape(100.f);
    ShapeMovimentVector shapes;
    sf::Font font;
    LoadFont(font, fontFileName);

    shapes.loadShapesFromFile(inputFileName, font);
    while (window.isOpen())
    {
        shapes.movementShapes(window.getSize().x, window.getSize().y);

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            else if (event->is<sf::Event::KeyPressed>())
            {
                if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::X)
                {
                    frameRateLimit *= 2;
                    window.setFramerateLimit(frameRateLimit);
                }
                else if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::C)
                {
                    frameRateLimit /= 2;
                    window.setFramerateLimit(frameRateLimit);
                }
            }
        }

        window.clear();
        for (const ShapeMoviment &s : shapes.getShapes())
        {
            window.draw(s.getShape());
            window.draw(s.getText());
        };
        window.display();
    }
}