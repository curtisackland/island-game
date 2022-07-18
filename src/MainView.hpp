#pragma once
#include <SFML/Graphics.hpp>

class MainView : public sf::View{
    private:
        MainView();
        ~MainView();
        static MainView *self;
    public:
        static MainView& getInstance();
        static void destroy();
};