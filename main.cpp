#include<SFML/Graphics.hpp>
#include<iostream>

void check_controls(sf::Sprite *sprite, float *actual_sprite, sf::IntRect *rect);
const int movement = 4;
int main() {

    sf::RenderWindow window(sf::VideoMode(1920,1080), "walking_man");
    window.setFramerateLimit(60);

    sf::IntRect rect(0,0,96,160);
    sf::Texture texture;
    texture.loadFromFile("walking_man.png");
    sf::Sprite sprite(texture, rect);
    float actual_sprite = 0;


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

        check_controls(&sprite, &actual_sprite, &rect);
        
        window.clear(sf::Color::White);
        window.draw(sprite);
        window.display();
    }

    return 0;
}

void check_controls(sf::Sprite *sprite,float *actual_sprite, sf::IntRect *rect) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        sprite->move(0, -movement);
        *actual_sprite += 0.2;
        sprite->setTextureRect(sf::IntRect(0 + 96 *((int) *actual_sprite), 3 * 160,96,160));
        if(*actual_sprite >= 12) {
            *actual_sprite = 0;
            sprite->setTextureRect(sf::IntRect(0, 3 * 160,96,160));
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        sprite->move(-movement, 0);
        *actual_sprite += 0.2;
        sprite->setTextureRect(sf::IntRect(0 + 96 *((int) *actual_sprite),160,96,160));
        if(*actual_sprite >= 12) {
            *actual_sprite = 0;
            sprite->setTextureRect(sf::IntRect(0,0,96,160));
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        sprite->move(0, movement);
        *actual_sprite += 0.2;
        sprite->setTextureRect(sf::IntRect(0 + 96 *((int) *actual_sprite),0,96,160));
        if(*actual_sprite >= 12) {
            *actual_sprite = 0;
            sprite->setTextureRect(sf::IntRect(0,0,96,160));
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        sprite->move(movement, 0);
        *actual_sprite += 0.2;
        sprite->setTextureRect(sf::IntRect(0 + 96 *((int) *actual_sprite),2 * 160,93,160));
        if(*actual_sprite >= 12) {
            *actual_sprite = 0;
            sprite->setTextureRect(sf::IntRect(0,0,96,160));
        }
    }
}


//g++ -c main.cpp && g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio && ./sfml-app