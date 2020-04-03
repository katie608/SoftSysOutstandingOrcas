/*
https://www.sfml-dev.org/tutorials/2.1/start-linux.php
https://www.gamefromscratch.com/page/SFML-CPP-Tutorial-Series.aspx

run:
g++ -c 3-10.cpp
g++ 3-10.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app
*/

/*
https://www.sfml-dev.org/tutorials/2.1/start-linux.php
*/

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    sf::Event event;
    // while there are pending events...
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::MouseButtonPressed){
        if (event.mouseButton.button == sf::Mouse::Right){
            std::cout << "the right button was pressed" << std::endl;
            std::cout << "mouse x: " << event.mouseButton.x << std::endl;
            std::cout << "mouse y: " << event.mouseButton.y << std::endl;
        }
      }
    }



    return 0;
}
