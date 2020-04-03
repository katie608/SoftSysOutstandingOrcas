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
#include <iostream>
#include <SFML/Audio.hpp>

sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML Game"); //width, height
sf::Event event;
sf::Music music;

void playSound(std::string filename)
{
  sf::SoundBuffer buffer;
  if (!buffer.loadFromFile(filename))
  {
        printf("Error. Sound file invalid.");
        return;
      }
  sf::Sound sound;
  sound.setBuffer(buffer);
  sound.play();
  sound.setLoop(true);
  while (sound.getStatus() == sf::Sound::Playing)
  {
    while (window.pollEvent(event)){ // listen for events
        if (event.type == sf::Event::MouseButtonPressed){
          // if mouse button is pressed
            if (event.mouseButton.button == sf::Mouse::Right){
              // if the mouse button was the left one
              // print out the x and y values of the mouse
              sound.stop();
              break;
            }
          }
          else{
    sf::sleep(sf::milliseconds(100));
  }
  }
}
}

void buttonPress()
{
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

//150, 450
        if(abs((x-200)-150)<200 && abs((y-100)-450) < 100){
          std::cout << "Snake was pressed" << std::endl;
          playSound("resources/snakeHiss.wav");
        }
//(400, 150)
        else if (abs((x-100)-400)<100 && abs((y-100)-150)<100) {
          std::cout << "Canary was pressed" << std::endl;
          playSound("resources/canary.wav");
        }
//750,300
        else if (abs((x-150)-750)<150 && abs((y-100)-300)<100) {
          std::cout << "Monkey was pressed" << std::endl;
          playSound("resources/monkey.wav");
  }
  //Need to fix radius, only works to the bottom and right of circle.
}
}
}

void playBackground()
  {
      music.openFromFile("resources/forest_ambience.wav");
      music.play();
      music.setLoop(true);
  }

int main()
{
  //backgroundMusic my_music;
  //my_music.playBackground();
  playBackground();

    sf::Texture shape1;
    shape1.loadFromFile("Images/snekpt2.png");
    sf:: Sprite snake;
    snake.setTexture(shape1);
    snake.setPosition(150, 450);
    snake.setScale(sf::Vector2f(0.4f, 0.4f));

    sf::Texture shape2;
    shape2.loadFromFile("Images/bordpt2.png");
    sf:: Sprite bird;
    bird.setTexture(shape2);
    bird.setPosition(400, 150);
    bird.setScale(sf::Vector2f(0.5f, 0.5f));

    sf::Texture shape3;
    shape3.loadFromFile("Images/monkeypt2.png");
    sf:: Sprite monkey;
    monkey.setTexture(shape3);
    monkey.setPosition(750,300);
    monkey.setScale(sf::Vector2f(0.2f, 0.2f));

    // sf::CircleShape shape4(25.f);//radius
    // shape4.setFillColor(sf::Color::Red);
    // shape4.setPosition(200, 500);
    //
    // sf::CircleShape shape5(25.f);//radius
    // shape5.setFillColor(sf::Color::Green);
    // shape5.setPosition(450, 200);
    //
    // sf::CircleShape shape6(25.f);//radius
    // shape6.setFillColor(sf::Color::Blue);
    // shape6.setPosition(775,350);

    sf:: Texture texture;
    texture.loadFromFile("Images/runforrestrun.png");
    sf:: Sprite sprite_back;
    sprite_back.setTexture(texture);
    sprite_back.setScale(sf::Vector2f(0.45f,0.45f));

    while (window.isOpen()){
        while (window.pollEvent(event)){ // listen for events
            if (event.type == sf::Event::Closed){
              // close window if window close (red x in corner of window) is pushed
                window.close();
            }
            buttonPress();
        }

        window.clear();
        window.draw(sprite_back);

        window.draw(snake);
        window.draw(bird);
        window.draw(monkey);
        // window.draw(shape4);
        // window.draw(shape5);
        // window.draw(shape6);
        window.display();
}
    return 0;
}
