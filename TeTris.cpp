#include "TeTris.h"
#include "Brick.h"
#include "BackGround.h"
#include <iostream>
#include "TetroMinos.h"
#include "BlockMovement.h"
#include "DrawingGame.h"

bool
        rotate = false, ///<if block should rotate
spawnNewBlock = true, ///<if block should be spawn
endGame = false;
int
        field[ROWS][COLUMNS] = {0},
        shiftToSide = 0,
        chooseBrick,
        nextBrick = rand() % 7 + 1;
float
        delay = 0.3,
        speedDelay = 0.005,
        comeBackToDelay = 0.3,
        scaleOfChangeSpeed = 0.9;
int
        score = 0,
        changeSpeedStep = 5,
        deletedLines = 0;
TeTris::Point
        currentPosition[4],
        lastPosition[4];

TeTris::TeTris() = default;

void TeTris::startTeTrisGame() {

    sf::RenderWindow window(sf::VideoMode(2 * CELL_SIZE * COLUMNS * SCREEN_RESIZE, CELL_SIZE * ROWS * SCREEN_RESIZE),
                            "Tetris", sf::Style::Close);
    //synchronize the frame rate with the monitor's refresh rate
    window.setVerticalSyncEnabled(true);
    //set the window position in the middle of the  and the top of y
    window.setPosition(
            sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - CELL_SIZE * COLUMNS * SCREEN_RESIZE, 0));
    displayUpdate(window);
}

void TeTris::displayUpdate(sf::RenderWindow &window) {
    sf::Clock clock;
    float timer = 0;
    TetroMinos tetroMinos;//import of blocks

    while (window.isOpen()) {
        timer += clock.getElapsedTime().asSeconds();
        clock.restart();

        takeButtonSignal(window);

        everyMoveOfBlock(timer, tetroMinos);

        deleteFullLines();

        checkIfGameIsEnd(field, window);

        displayGame(window, tetroMinos);

        checkIfGameIsEnd(field, window);
        window.display();
        window.clear();
        shiftToSide = 0;
        rotate = false;
        delay = comeBackToDelay;
    }
}


void TeTris::takeButtonSignal(sf::RenderWindow &window) {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Space ||
                event.key.code == sf::Keyboard::W) {
                rotate = true;
            } else if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A) {
                shiftToSide = -1;
            } else if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D) {
                shiftToSide = 1;
            } else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S) {
                delay = speedDelay;
            } else if (event.key.code == sf::Keyboard::R) {
                endGame = false;
                score = 0;
                deletedLines = 0;
                delay = 0.3;
                speedDelay = 0.005;
                comeBackToDelay = 0.3;
                spawnNewBlock = true;
                for (int i = 0; i < ROWS; i++) {
                    for (int j = 0; j < COLUMNS; j++) {
                        field[i][j] = 0;
                    }
                }
            }
        }

    }
}

void TeTris::everyMoveOfBlock(float &timer, TetroMinos tetroMinos) {

    BlockMovement::spawnNewBlockOnTheBoard(tetroMinos, chooseBrick, nextBrick, spawnNewBlock, currentPosition);

    BlockMovement::moveBlock(shiftToSide, currentPosition, lastPosition);

    BlockMovement::rotateBlock(rotate, currentPosition, lastPosition);

    BlockMovement::fallingOfTheBlock(timer, delay, currentPosition, lastPosition, chooseBrick, spawnNewBlock, field);
}

void TeTris::displayGame(sf::RenderWindow &window, TetroMinos tetroMinos) {

    DrawingGame::drawBackGround(window, field);

    DrawingGame::drawNextBlock(window, nextBrick);

    DrawingGame::drawScore(window, score, 12, 9);

    DrawingGame::drawSpeed(window, comeBackToDelay);

    DrawingGame::drawRestart(window, 12, 16);

    DrawingGame::drawCurrentBlock(window, tetroMinos, chooseBrick, currentPosition);

}

void TeTris::deleteFullLines() {

    int lineToReplace = ROWS - 1;
    for (int i = ROWS - 1; i > 0; i--) {
        int count = 0;
        for (int j = 0; j < COLUMNS; j++) {
            if (field[i][j]) {
                count++;
            }
            field[lineToReplace][j] = field[i][j];

        }
        if (count < COLUMNS) {
            lineToReplace--;
        } else {
            score += 1;
            deletedLines++;
            if (deletedLines == changeSpeedStep) {
                comeBackToDelay = comeBackToDelay * scaleOfChangeSpeed;
                deletedLines = 0;
            }
        }
    }
}

void TeTris::checkIfGameIsEnd(int (*field)[10], sf::RenderWindow &window) {
    for (int i = 0; i < COLUMNS; i++) {
        if (field[0][i]) {
            endGame = true;
        }
    }
    if (endGame) {
        DrawingGame::drawEnd(window, score);
    }
}

bool TeTris::checkIfObjectIsInGameBoard() {
    for (auto &i: currentPosition) {
        if (i.x < 0 || i.x >= COLUMNS || i.y >= ROWS) {
            return false;
        } else if (field[i.y][i.x]) {
            return false;
        }
    }
    return true;
}



