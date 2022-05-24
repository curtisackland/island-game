#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdio.h>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "My window", sf::Style::Fullscreen);
    sf::CircleShape shape(200.f);

    sf::Texture spriteTexture;
    if (!spriteTexture.loadFromFile("test1.png"))
    {
        // error...
        printf("weird\n");
    }
    sf::Texture *texture = &spriteTexture;
    //texture->setSmooth(true);
    shape.setTexture(texture);

    sf::Image *image = new sf::Image();
    
    if(!image->loadFromFile("master.png")){
        printf("weird2\n");
    }
    texture->update(*image,  100, 100);
    // set the shape color to green
    shape.setFillColor(sf::Color(255, 255, 255));
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type){

                //window closed
                case sf::Event::Closed:
                    window.close();
                    break;
                
                // key pressed
                //case sf::Event::KeyPressed:

                default:
                    break;
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            // left key is pressed: move our character
            shape.setPosition(shape.getPosition().x - 10, shape.getPosition().y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            // left key is pressed: move our character
            shape.setPosition(shape.getPosition().x + 10, shape.getPosition().y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            // left key is pressed: move our character
            shape.setPosition(shape.getPosition().x, shape.getPosition().y - 10);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            // left key is pressed: move our character
            shape.setPosition(shape.getPosition().x, shape.getPosition().y + 10);
        }
        // draw everything here...
        // window.draw(...);

        
        /*
        sf::Texture spriteTexture;
        if (!spriteTexture.loadFromFile("test1.png"))
        {
            // error...
            printf("weird\n");
        }
        
        sf::Sprite sprite;
        sprite.setTexture(spriteTexture);
        */
        window.draw(shape);
        
        
        // end the current frame
        window.display();
    }

    return 0;
}
