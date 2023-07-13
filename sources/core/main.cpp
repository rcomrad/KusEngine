#include <iostream>

#include "core.hpp"

//--------------------------------------------------------------------------------

#include <SFML/Graphics.hpp>

#include <string>

int
main(int argc, char* argv[])
{
    // sf::Sprite tttt1;
    // std::cout << "Sprite: " << sizeof(tttt1) << "\n";

    // sf::Texture tttt2;
    // std::cout << "Texture: " << sizeof(tttt2) << "\n";

    // sf::Text tttt3;
    // std::cout << "Text: " << sizeof(tttt3) << "\n";

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

    return 0;
}

//--------------------------------------------------------------------------------
