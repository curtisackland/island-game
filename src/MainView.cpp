#include "MainView.hpp"

MainView* MainView::self = nullptr;

MainView::MainView() : sf::View(){
    
}

MainView::~MainView(){}

MainView& MainView::getInstance() {
    if (self == nullptr) {
        self = new MainView();
    }
    return *self;
}