#include "TetroMinos.h"


sf::Color TetroMinos::getTetroColor(int random) {
    return colorOfMino[random];
}

int TetroMinos::getTetroShape(int random, int i) {
    return shapeOfMino[random][i];
}

