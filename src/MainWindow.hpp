#pragma once
#include <SFML/Graphics.hpp>

class MainWindow : public sf::RenderWindow{
    private:
        MainWindow(sf::VideoMode, std::string);
        ~MainWindow();
        static MainWindow *self;
    public:
        static MainWindow& getInstance();
        static void destroy();
};