#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Bird.h"  
#include "BackGround.h"  


int main()
{
    sf::RenderWindow window(sf::VideoMode(360, 640), "Flappy Bird Clone");
    window.setFramerateLimit(60);

    Bird bird; 
    Background backGround;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                bird.jump();  

            }
        }

        bird.update();  
        window.clear();
        window.draw(backGround.getSprite());
        window.draw(bird.getSprite()); 
        window.display();
    }

    return 0;
}
