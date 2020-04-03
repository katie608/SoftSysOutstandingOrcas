#include <SFML/Audio.hpp>

int main()
{
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("sound.wav"))
        return -1;
    return 0;
    std::cin.get();
}

sf::Sound sound;
sound.setBuffer(buffer);
sound.play();
