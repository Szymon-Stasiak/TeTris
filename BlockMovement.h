#ifndef TETRIS_BLOCKMOVEMENT_H
#define TETRIS_BLOCKMOVEMENT_H


#include "TetroMinos.h"
#include "TeTris.h"


///Class to move block
class BlockMovement {
public:

    ///Constructor
    BlockMovement();

    /** Spawn new block on the board
    *
     * @param tetroMinos - object of class TetroMinos - gives shape and color of the block
     * @param chooseBrick - number of the block
     * @param nextBrick - number of the next block
     * @param spawnNewBlock - boolean variable to spawn new block
     * @param currentPosition - current position of the spawning block
     *
      */

    static void spawnNewBlockOnTheBoard(TetroMinos tetroMinos, int &chooseBrick, int &nextBrick, bool &spawnNewBlock,
                                        TeTris::Point *currentPosition);

    /** Move block to chosen side
     *
     * @param shiftToSide - side to move block
     * @param currentPosition - current position of the block
     * @param lastPosition - last position of the block
     */
    static void moveBlock(int &shiftToSide, TeTris::Point *currentPosition, TeTris::Point *lastPosition);

    /** Rotate block
     *
     * @param rotate - boolean variable to rotate block
     * @param currentPosition - current position of the block
     * @param lastPosition - last position of the block
     */
    static void rotateBlock(bool &rotate, TeTris::Point *currentPosition, TeTris::Point *lastPosition);

    /** Falling of the block - move block down
     *
     * @param timer - time from that depends if block should fall down
     * @param delay - delay of the block falling down , from that depend speed of block
     * @param currentPosition - current position of the block
     * @param lastPosition - last position of the block
     * @param chooseBrick - number of the block
     * @param spawnNewBlock - boolean variable to spawn new block
     * @param field - game board
     */
    static void
    fallingOfTheBlock(float &timer, float &delay, TeTris::Point *currentPosition, TeTris::Point *lastPosition,
                      int &chooseBrick, bool &spawnNewBlock, int field[20][10]);
};


#endif //TETRIS_BLOCKMOVEMENT_H
