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

using namespace std;
using namespace sf;

int main()
{
    system("CLS");

    sf::RenderWindow window(sf::VideoMode(1024, 786), "Hang Man");
    window.setFramerateLimit(60);

    Font font;
    if (!font.loadFromFile("BerlinSansFBRegular.ttf"))
        throw("COULD NOT LOAD FONT!");

    Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(Color(68, 3, 3));
    // text.setColor(Color(68, 3, 3));
    text.setPosition(600, 350);
    text.setString("Fatim");

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        // Draw
        window.clear();
        window.draw(text);
        window.display();
    }
}