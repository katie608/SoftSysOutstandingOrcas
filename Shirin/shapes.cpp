#include <SFML/Graphics.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
  sf::CircleShape shape(50.f);

  //set color to green
  shape.setFillColor(sf::Color(100,250,50));
  //set a 10-pixel wide orange outline
  shape.setOutlineThickness(10.f);
  shape.setOutlineColor(sf::Color(250,150,100));
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

  return 0;
}
