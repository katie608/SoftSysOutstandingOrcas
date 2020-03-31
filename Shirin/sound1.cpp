#include <SFML/Audio.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>

void play_sound()
{
  sf::SoundBuffer buffer;
  if (!buffer.loadFromFile("sound.wav"))
    return;
  sf::Sound sound;
  sound.setBuffer(buffer);
  sound.play();
  while (sound.getStatus() == sf::Sound::Playing)
  {
    sf::sleep(sf::milliseconds(100));
  }
}

int main()
{
  sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("sound.wav"))
      return -1;
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    while (sound.getStatus() == sf::Sound::Playing)
    {
      sf::sleep(sf::milliseconds(100));
    }
    window.clear();
    window.display();
}
return 0;
}
