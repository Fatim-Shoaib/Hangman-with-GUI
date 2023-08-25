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

void exit(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 200 && x_pos > 108 && y_pos < 380 && y_pos > 334)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void restart(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 265 && x_pos > 103 && y_pos < 509 && y_pos > 460)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void back(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 229 && x_pos > 102 && y_pos < 636 && y_pos > 583)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

int main()
{
    system("CLS");
    int mouse_x_pos = 9999;
    int mouse_y_pos = 9999;
    int old_mouse_x_pos = 9999;
    int pointer_1_pos_1 = 523;
    int pointer_1_pos_2 = 9999;
    int pointer_2_pos_1 = 603;
    bool bool_mouse_pressed = false;
    bool bool_mouse_released = false;
    int effects_volume = 50;
    int music_volume = 25;
    bool bool_exit_small = false;
    bool bool_exit_large = false;
    bool bool_restart_small = false;
    bool bool_restart_large = false;
    bool bool_back_small = false;
    bool bool_back_large = false;
    sf::RenderWindow window(sf::VideoMode(1024, 786), "Volume Control");

    window.setFramerateLimit(60);

    sf::Sprite menu_screen_sprite;
    sf::Texture menu_screen_texture;
    sf::Sprite exit_small_sprite;
    sf::Texture exit_small_texture;
    sf::Sprite exit_large_sprite;
    sf::Texture exit_large_texture;
    sf::Sprite restart_small_sprite;
    sf::Texture restart_small_texture;
    sf::Sprite restart_large_sprite;
    sf::Texture restart_large_texture;
    sf::Sprite back_small_sprite;
    sf::Texture back_small_texture;
    sf::Sprite back_large_sprite;
    sf::Texture back_large_texture;

    if (!menu_screen_texture.loadFromFile("images/menu_screen.jpg"))
        cout << "Error could not load file";
    if (!exit_small_texture.loadFromFile("images/exit_small.png"))
        cout << "Error could not load file";
    if (!exit_large_texture.loadFromFile("images/exit_large.png"))
        cout << "Error could not load file";
    if (!restart_small_texture.loadFromFile("images/restart_small.png"))
        cout << "Error could not load file";
    if (!restart_large_texture.loadFromFile("images/restart_large.png"))
        cout << "Error could not load file";
    if (!back_small_texture.loadFromFile("images/back_small.png"))
        cout << "Error could not load file";
    if (!back_large_texture.loadFromFile("images/back_large.png"))
        cout << "Error could not load file";

    menu_screen_sprite.setTexture(menu_screen_texture);
    exit_small_sprite.setTexture(exit_small_texture);
    exit_large_sprite.setTexture(exit_large_texture);
    restart_small_sprite.setTexture(restart_small_texture);
    restart_large_sprite.setTexture(restart_large_texture);
    back_small_sprite.setTexture(back_small_texture);
    back_large_sprite.setTexture(back_large_texture);

    sf::CircleShape pointer_1;
    pointer_1.setRadius(13);
    pointer_1.setPointCount(3);
    pointer_1.setFillColor(sf::Color(92, 64, 51));
    pointer_1.setPosition(sf::Vector2f(523, 413));

    sf::CircleShape pointer_2;
    pointer_2.setRadius(13);
    pointer_2.setPointCount(3);
    pointer_2.setFillColor(sf::Color(92, 64, 51));
    pointer_2.setPosition(sf::Vector2f(603, 553));

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();

            if (event.type == sf::Event::MouseButtonReleased)
            {
                bool_mouse_released = true;
                bool_mouse_pressed = false;
            }
            if (bool_mouse_pressed == false)
            {
                if (event.type == sf::Event::MouseMoved)
                {
                    mouse_x_pos = sf::Mouse::getPosition(window).x;
                    mouse_y_pos = sf::Mouse::getPosition(window).y;
                }
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                mouse_x_pos = sf::Mouse::getPosition(window).x;
                mouse_y_pos = sf::Mouse::getPosition(window).y;
                cout << "Mouse coordinates: x: " << mouse_x_pos << ", y: " << mouse_y_pos << endl;
                bool_mouse_pressed = true;
                bool_mouse_released = false;
                break;
            }
        }

        exit(bool_exit_large, bool_exit_small, mouse_x_pos, mouse_y_pos);
        restart(bool_restart_large, bool_restart_small, mouse_x_pos, mouse_y_pos);
        back(bool_back_large, bool_back_small, mouse_x_pos, mouse_y_pos);

        if (bool_mouse_pressed == true && bool_mouse_released == false)
        {
            // MUSIC VOL
            if (mouse_x_pos > pointer_1_pos_1 && mouse_x_pos < pointer_1_pos_1 + 23 && mouse_y_pos > 411 and mouse_y_pos < 432)
            {
                old_mouse_x_pos = mouse_x_pos;
                mouse_x_pos = sf::Mouse::getPosition(window).x;

                pointer_1_pos_1 += mouse_x_pos - old_mouse_x_pos;
                if (pointer_1_pos_1 > 764)
                {
                    pointer_1_pos_1 = 764;
                }
                if (pointer_1_pos_1 < 443)
                {
                    pointer_1_pos_1 = 443;
                }
                pointer_1.setPosition(sf::Vector2f(pointer_1_pos_1, 413));

                music_volume = (764.0 - pointer_1_pos_1 * 1.0) / (764.0 - 443.0) * 100.0;
                music_volume = 100 - music_volume;
            }

            // EFFECTS VOL
            if (mouse_x_pos > pointer_2_pos_1 && mouse_x_pos < pointer_2_pos_1 + 23 && mouse_y_pos > 548 and mouse_y_pos < 573)
            {
                old_mouse_x_pos = mouse_x_pos;
                mouse_x_pos = sf::Mouse::getPosition(window).x;
                pointer_1.setPosition(sf::Vector2f(pointer_1_pos_1, 413));
                pointer_2_pos_1 += mouse_x_pos - old_mouse_x_pos;

                if (pointer_2_pos_1 > 764)
                {
                    pointer_2_pos_1 = 764;
                }
                if (pointer_2_pos_1 < 443)
                {
                    pointer_2_pos_1 = 443;
                }

                pointer_2.setPosition(sf::Vector2f(pointer_2_pos_1, 553));
                effects_volume = (764.0 - pointer_2_pos_1 * 1.0) / (764.0 - 443.0) * 100.0;
                effects_volume = 100 - effects_volume;
            }
        }

        window.clear();
        window.draw(menu_screen_sprite);
        if (bool_restart_small == true)
        {
            window.draw(restart_small_sprite);
        }
        else
        {
            window.draw(restart_large_sprite);
        }
        if (bool_exit_small == true)
        {
            window.draw(exit_small_sprite);
        }
        else
        {
            window.draw(exit_large_sprite);
        }
        if (bool_back_small == true)
        {
            window.draw(back_small_sprite);
        }
        else
        {
            window.draw(back_large_sprite);
        }
        window.draw(pointer_1);
        window.draw(pointer_2);
        window.display();
    }
}
