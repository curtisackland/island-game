#include "MainWindow.hpp"

MainWindow* MainWindow::self = nullptr;

MainWindow::MainWindow(sf::VideoMode mode, std::string title) : sf::RenderWindow(mode, title){
    
}

MainWindow::~MainWindow(){}

MainWindow& MainWindow::getInstance() {
    if (self == nullptr) {
        self = new MainWindow(sf::VideoMode(1600, 900), "Island Game");
    }
    return *self;
}

void MainWindow::destroy() {
    delete MainWindow::self;
    MainWindow::self = nullptr;
}