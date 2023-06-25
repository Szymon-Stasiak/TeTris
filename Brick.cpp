#include "Brick.h"
#include <SFML/Graphics.hpp>
#include "BackGround.h"


Brick::Brick() {
    shape.setSize(sf::Vector2f(CELL_SIZE * SCREEN_RESIZE, CELL_SIZE * SCREEN_RESIZE));
    shape.setFillColor(sf::Color(47, 50, 70));
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(1);
}


void Brick::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(shape, states);
}

void Brick::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

void Brick::setFillColor(sf::Color color) {
    shape.setFillColor(color);
}



