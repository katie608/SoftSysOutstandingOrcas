/*
https://www.sfml-dev.org/tutorials/2.1/start-linux.php
https://www.gamefromscratch.com/page/SFML-CPP-Tutorial-Series.aspx

run:
g++ -c 3-22.cpp
g++ 3-22.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app
*/

/*
https://www.sfml-dev.org/tutorials/2.1/start-linux.php
*/

#include <SFML/Graphics.hpp>
#include  <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML Game"); //width, height
    sf::CircleShape shape(25.f);//radius
    shape.setFillColor(sf::Color::Blue);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){ // listen for events
            if (event.type == sf::Event::Closed){
              // close window if window close (red x in corner of window) is pushed
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed){
              // if mouse button is pressed
                if (event.mouseButton.button == sf::Mouse::Left){
                  // if the mouse button was the left one
                  // print out the x and y values of the mouse
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                    shape.setPosition(event.mouseButton.x-25, event.mouseButton.y-25);
                }
            }

            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Up){
                  shape.setPosition(shape.getPosition().x, shape.getPosition().y-25);
                }
                if (event.key.code == sf::Keyboard::Down){
                  shape.setPosition(shape.getPosition().x, shape.getPosition().y+25);
                }
                if (event.key.code == sf::Keyboard::Left){
                  shape.setPosition(shape.getPosition().x-25, shape.getPosition().y);
                }
                if (event.key.code == sf::Keyboard::Right){
                  shape.setPosition(shape.getPosition().x+25, shape.getPosition().y);
                }
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
