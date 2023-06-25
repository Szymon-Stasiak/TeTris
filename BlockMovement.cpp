#include "BlockMovement.h"
#include "TetroMinos.h"
#include "TeTris.h"
#include <iostream>

BlockMovement::BlockMovement() {
}

void
BlockMovement::spawnNewBlockOnTheBoard(TetroMinos tetroMinos, int &chooseBrick, int &nextBrick, bool &spawnNewBlock,
                                       TeTris::Point currentPosition[4]) {
    if (spawnNewBlock) {
        chooseBrick = nextBrick;
        for (int i = 0; i < 4; i++) {
            currentPosition[i].x = tetroMinos.getTetroShape(chooseBrick, i) % 2 + 4;//plus 4 to spawn in the middle
            currentPosition[i].y = tetroMinos.getTetroShape(chooseBrick, i) / 2 - 1;
        }
        nextBrick = rand() % 7 + 1;
        spawnNewBlock = false;
    }

}

void BlockMovement::moveBlock(int &shiftToSide, TeTris::Point currentPosition[4], TeTris::Point lastPosition[4]) {
    for (int i = 0; i < 4; i++) {
        lastPosition[i] = currentPosition[i];
        currentPosition[i].x += shiftToSide;
    }
    if (!TeTris::checkIfObjectIsInGameBoard()) {
        for (int i = 0; i < 4; i++) {
            currentPosition[i] = lastPosition[i];
        }
    }
}

void BlockMovement::rotateBlock(bool &rotate, TeTris::Point currentPosition[4], TeTris::Point lastPosition[4]) {
    if (rotate) {
        TeTris::Point centerOfRotation = currentPosition[1];
        for (int i = 0; i < 4; i++) {
            int x = currentPosition[i].y - centerOfRotation.y;
            int y = currentPosition[i].x - centerOfRotation.x;
            currentPosition[i].x = centerOfRotation.x - x;
            currentPosition[i].y = centerOfRotation.y + y;
        }
        if (!TeTris::checkIfObjectIsInGameBoard()) {
            for (int i = 0; i < 4; i++) {
                currentPosition[i] = lastPosition[i];
            }
        }
    }
}

void BlockMovement::fallingOfTheBlock(float &timer, float &delay, TeTris::Point currentPosition[4],
                                      TeTris::Point lastPosition[4], int &chooseBrick, bool &spawnNewBlock,
                                      int field[20][10]) {
    if (timer > delay) {
        for (int i = 0; i < 4; i++) {
            lastPosition[i] = currentPosition[i];
            currentPosition[i].y += 1;
        }
        if (!TeTris::checkIfObjectIsInGameBoard()) {
            for (int i = 0; i < 4; i++) {
                field[lastPosition[i].y][lastPosition[i].x] = chooseBrick;
            }
            spawnNewBlock = true;
        }
        timer = 0;
    }
}
