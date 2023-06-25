#include <SFML/Graphics.hpp>
#include "BackGround.h"
#include "TetroMinos.h"

#ifndef TETRIS_TETRISSERVICE_H
#define TETRIS_TETRISSERVICE_H

/// Main class of the game - responsible for the game logic
class TeTris {

public:
    ///Structure to store position of the block
    struct Point {
        int x, y;
    };

    ///Constructor
    TeTris();

    ///Start game
    static void startTeTrisGame();

    /**Update all game elements
     *
     * @param window - window to draw
     */
    static void displayUpdate(sf::RenderWindow &window);

    /**Take signal from the button
     *
     * @param window - window to draw
     */
    static void takeButtonSignal(sf::RenderWindow &window);

    ///Delete lines full of blocks
    static void deleteFullLines();

    /**Check if game is end
     *
     * @param field - game board
     * @param window - window to draw
     */
    static void checkIfGameIsEnd(int field[ROWS][COLUMNS], sf::RenderWindow &window);

    ///Check if block is in game board
    static bool checkIfObjectIsInGameBoard();

    /**Move block in any direction that is demanded
     *
     * @param timer - timer to move block
     * @param tetroMinos - object of class TetroMinos - gives shape and color of the block
     */

    static void everyMoveOfBlock(float &timer, TetroMinos tetroMinos);

    /**Display every object of the game
     *
     * @param window - window to draw
     * @param tetroMinos - object of class TetroMinos - gives shape and color of the block
     */
    static void displayGame(sf::RenderWindow &window, TetroMinos tetroMinos);
};

#endif //TETRIS_TETRISSERVICE_H
