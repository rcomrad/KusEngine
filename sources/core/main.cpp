﻿#include <iostream>

#include "core.hpp"

//--------------------------------------------------------------------------------

#include <SFML/Graphics.hpp>

#include <string>

int
main(int argc, char* argv[])
{
    // sf::Texture Texture;
    // std::cout << "Texture: " << sizeof(Texture) << "\n";

    // sf::Sprite Sprite;
    // std::cout << "Sprite: " << sizeof(Sprite) << "\n";

    // sf::Font Font;
    // std::cout << "Font: " << sizeof(Font) << "\n";

    // sf::Text Text;
    // std::cout << "Text: " << sizeof(Text) << "\n";
    // std::cout << "--------------------------\n";

    // Texture.loadFromFile(
    //     "D:/projects/VSCode/KusEngine0/resources/texture/background.png");
    // std::cout << "Texture: " << sizeof(Texture) << "\n";

    // Sprite.setTexture(Texture);
    // std::cout << "Sprite: " << sizeof(Sprite) << "\n";

    // Font.loadFromFile("D:/projects/VSCode/KusEngine0/resources/font/font.ttf");
    // std::cout << "Font: " << sizeof(Font) << "\n";

    // Text.setFont(Font);
    // std::cout << "Text: " << sizeof(Text) << "\n";
    // std::cout << "--------------------------\n";

    // std::unique_ptr<std::string> tttt4;
    // std::cout << "std::unique_ptr<std::string>: " << sizeof(tttt4) << "\n";

    // //-----------------------------------------------------

    // sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);

    // sf::Texture t1;
    // sf::Texture t2;

    // while (window.isOpen())
    // {
    //     sf::Sprite s;
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed) window.close();
    //     }

    //     window.clear();
    //     s.setTexture();
    //     window.draw(shape);
    //     window.display();
    // }

    // return 0;

    std::cout << "LAMPA\n";

    core::Core app;
    app.run();

    std::cout << "91\n";

    return 0;
}

//--------------------------------------------------------------------------------
