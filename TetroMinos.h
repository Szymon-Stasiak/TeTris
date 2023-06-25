#include "Brick.h"
#include <SFML/Graphics.hpp>

#ifndef TETRIS_TETROMINOS_H
#define TETRIS_TETROMINOS_H

///Class responsible for giving shape and color of the block
class TetroMinos {

public:

    /**Get color of the block
     *
     * @param random - number of randomly generated block
    *
     */
    sf::Color getTetroColor(int random);

    /**Get shape of the block
     *
     * @param random - number of randomly generated block
     * @param i - number of the brick
     */

    int getTetroShape(int random, int i);


private:

    ///Array of shapes of the blocks
    int shapeOfMino[8][4] = {
            0, 0, 0, 0,//empty
            1, 3, 5, 7, // I
            2, 4, 5, 7, // Z
            3, 5, 4, 6, // S
            3, 5, 4, 7, // T
            2, 3, 5, 7, // L
            3, 5, 7, 6, // J
            2, 3, 4, 5, // O
    };
    ///Array of colors of the blocks
    sf::Color colorOfMino[8] = {
            sf::Color(47, 50, 70),//color of the background brick
            sf::Color(12, 177, 202),
            sf::Color(192, 4, 4),
            sf::Color(14, 178, 25),
            sf::Color(146, 0, 182),
            sf::Color(6, 18, 185),
            sf::Color(233, 97, 0),
            sf::Color(235, 219, 0)
    };
    ///Object of class Brick
    Brick brick = Brick();
};


#endif //TETRIS_TETROMINOS_H
