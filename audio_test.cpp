#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <windows.h>
#include <cctype>
#include <SFML/Audio.hpp>

using namespace std;

int main()
{
    system("CLS");

    sf::RenderWindow window(sf::VideoMode(600, 600), "AUDIO TEST");

    sf::SoundBuffer buffer;
    sf::Sound sound;

    sf::Music music;
    if (!music.openFromFile("audios/audio_3.wav"))
        cout << "Error could not load file";

    if (!buffer.loadFromFile("audios/audio_1.wav"))
        cout << "Error could not load file";

    sound.setBuffer(buffer);

    // sound.play();
    music.play();

    music.

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();

                break;
            }
        }

        window.clear();

        window.display();
    }
}