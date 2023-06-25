//
// Created by stszy on 08.03.2023.
//

#ifndef TETRIS_DRAWINGGAME_H
#define TETRIS_DRAWINGGAME_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "TetroMinos.h"
#include "TeTris.h"


///Class responsible for drawing/displaying game
class DrawingGame {

public:
    /**Draw current block
     *
     * @param window - window to draw
     * @param tetroMinos - object of class TetroMinos - gives shape and color of the block
     * @param chooseBrick - number of the block
     * @param currentPosition - current position of the block
     */
    static void
    drawCurrentBlock(sf::RenderWindow &window, TetroMinos tetroMinos, int chooseBrick, TeTris::Point *currentPosition);

    /**Draw BackGround
     *
     * @param window - window to draw
     * @param tab - game board
     */
    static void drawBackGround(sf::RenderWindow &window, int tab[ROWS][COLUMNS]);

    /**Draw next block
     *
     * @param window - window to draw
     * @param nextBrick - number of the next block
     */
    static void drawNextBlock(sf::RenderWindow &window, int nextBrick);

    /**Draw score
     *
     * @param window - window to draw
     * @param score - current score
     * @param x - x position of the score counter
     * @param y - y position of the score counter
     */
    static void drawScore(sf::RenderWindow &window, int score, float x, float y);

    /**Draw speed
     *
     * @param window - window to draw
     * @param comeBackToDelay - speed of the block
     */
    static void drawSpeed(sf::RenderWindow &window, float comeBackToDelay);

    /**Draw restart
     *
     * @param window - window to draw
     * @param x - x position of the restart inscription
     * @param y - y position of the restart inscription
     */
    static void drawRestart(sf::RenderWindow &window, float x, float y);

    /**Draw endgame screen
     *
     * @param window - window to draw
     * @param score - current score
     */
    static void drawEnd(sf::RenderWindow &window, int score);
};


#endif //TETRIS_DRAWINGGAME_H
