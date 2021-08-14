#include<SFML/Graphics.hpp>
#include<iostream>

int main() {

    sf::RenderWindow window(sf::VideoMode(500,500), "walking_man");

    sf::IntRect rect(0,0,96,160);
    sf::Texture texture;
    texture.loadFromFile("walking_man.png");
    sf::Sprite sprite(texture, rect);

    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        window.clear(sf::Color::White);
        window.draw(sprite);
        window.display();
    }

    return 0;
}


//g++ -c main.cpp && g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio && ./sfml-app