/*
https://www.sfml-dev.org/tutorials/2.1/start-linux.php
https://www.gamefromscratch.com/page/SFML-CPP-Tutorial-Series.aspx

run:
g++ -c 3-24.cpp
g++ 3-24.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app
*/

/*
https://www.sfml-dev.org/tutorials/2.1/start-linux.php
*/

#include <SFML/Graphics.hpp>
#include  <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML Game"); //width, height
    sf::CircleShape shape1(25.f);//radius
    shape1.setFillColor(sf::Color::Red);
    shape1.setPosition(200, 300);

    sf::CircleShape shape2(25.f);//radius
    shape2.setFillColor(sf::Color::Green);
    shape2.setPosition(400, 300);

    sf::CircleShape shape3(25.f);//radius
    shape3.setFillColor(sf::Color::Blue);
    shape3.setPosition(600, 300);

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
                  int x = event.mouseButton.x;
                  int y = event.mouseButton.y;
                    // std::cout << "the left button was pressed" << std::endl;
                    // std::cout << "mouse x: " << x << std::endl;
                    // std::cout << "mouse y: " << y << std::endl;

                  if (abs((x-25)-200)<25 && abs((y-25)-300)<25){
                    std::cout << "Shape 1 was pressed" << std::endl;
                  } else if (abs((x-25)-400)<25 && abs((y-25)-300)<25) {
                    std::cout << "Shape 2 was pressed" << std::endl;
                  } else if (abs((x-25)-600)<25 && abs((y-25)-300)<25) {
                    std::cout << "Shape 3 was pressed" << std::endl;
                  }
                }
            }

        }

        window.clear();
        window.draw(shape1);
        window.draw(shape2);
        window.draw(shape3);
        window.display();
    }

    return 0;
}
