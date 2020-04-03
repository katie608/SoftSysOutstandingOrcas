/*
https://www.sfml-dev.org/tutorials/2.1/start-linux.php
https://www.gamefromscratch.com/page/SFML-CPP-Tutorial-Series.aspx

run:
g++ -c one.cpp
g++ one.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app
*/

#include <SFML/Graphics.hpp>
#include <iostream>

// int main(int argc, char ** argv) {
//   sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "SFML Demo");
//
//   sf::Event event;
//
//   // A Clock starts counting as soon as it's created
//   sf::Clock clock;
//
//   while(renderWindow.isOpen()){
//     // Check for all the events that occured since the last frame.
//     while (renderWindow.pollEvent(event)){
//       //Handle events here
//       if (event.type == sf::Event::Closed)
//         renderWindow.close();
//     }
//
//     // A microsecond is 1/1,000,000th of a second, 1000 microseconds == 1 millisecond
//     std::cout << "Elapsed time since previous frame(microseconds): " << clock.getElapsedTime().asMicroseconds() << std::endl;
//     // Start the countdown over.  Think of laps on a stop watch.
//     clock.restart();
//
//
//     renderWindow.clear();
//     renderWindow.display();
//   }
//
// }

int main(int argc, char ** argv){
  sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Demo Game");

  sf::Event event;
  sf::Texture texture;
  texture.loadFromFile("images/orca.jpg");

  sf::IntRect rectSourceSprite(300, 0, 300, 400);
  sf::Sprite sprite(texture,rectSourceSprite);
  sf::Clock clock;

  while (renderWindow.isOpen()){
    while (renderWindow.pollEvent(event)){
      if (event.type == sf::Event::Closed)
        renderWindow.close();
    }

    if (clock.getElapsedTime().asSeconds() > 1.0f){
      if (rectSourceSprite.left == 600)
        rectSourceSprite.left = 0;
      else
        rectSourceSprite.left += 300;

      sprite.setTextureRect(rectSourceSprite);
      clock.restart();
    }


    renderWindow.clear();
    renderWindow.draw(sprite);
    renderWindow.display();
  }
}
