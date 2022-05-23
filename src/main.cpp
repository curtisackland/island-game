#include <SFML/Graphics.hpp>
#include <stdio.h>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(1600, 900), "My window");
    sf::CircleShape shape(50.f);

    // set the shape color to green
    shape.setFillColor(sf::Color(100, 250, 50));
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

/*
        sf::Texture spriteTexture;
        if (!spriteTexture.loadFromFile("test1.png"))
        {
            // error...
        }
        
        sf::Sprite sprite;
        sprite.setTexture(spriteTexture);

        window.draw(sprite);
*/