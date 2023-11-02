#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include <string.h>
using namespace std;

int main()
{
    // Load a music to play
    string name;
    getline(cin, name);


    sf::Music music;
    if (!music.openFromFile(name))
        return EXIT_FAILURE;

    // Play the music
    music.play();
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::CircleShape shape(400.f);
    shape.setFillColor(sf::Color::Green);

    bool isPaused = false;
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::P) {
                    isPaused = !isPaused;  // Toggle the playback state
                    if (isPaused) {
                        music.pause(); // Pause the music

                    }
                    else {
                        music.play();  // Resume the music

                    }
                }
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
