//
// Created by stszy on 08.03.2023.
//

#include <iostream>
#include "DrawingGame.h"
#include "TeTris.h"

void DrawingGame::drawCurrentBlock(sf::RenderWindow &window, TetroMinos tetroMinos, int chooseBrick,
                                   TeTris::Point currentPosition[4]) {
    for (int i = 0; i < 4; i++) {
        Brick brick;
        brick.setFillColor(tetroMinos.getTetroColor(chooseBrick));
        brick.setPosition(currentPosition[i].x * CELL_SIZE * SCREEN_RESIZE,
                          currentPosition[i].y * CELL_SIZE * SCREEN_RESIZE);
        window.draw(brick);
    }
}


void DrawingGame::drawBackGround(sf::RenderWindow &window, int tab[ROWS][COLUMNS]) {
    TetroMinos tetroMinos = TetroMinos();
    for (int i = 0; i < COLUMNS; i++) {
        for (int j = 0; j < ROWS; j++) {
            Brick brick = Brick();
            brick.setFillColor(tetroMinos.getTetroColor(tab[j][i]));
            brick.setPosition(i * CELL_SIZE * SCREEN_RESIZE, j * CELL_SIZE * SCREEN_RESIZE);
            window.draw(brick);
        }
    }
}

void DrawingGame::drawNextBlock(sf::RenderWindow &window, int nextBrick) {
    sf::Font font;
    TetroMinos tetroMinos = TetroMinos();
    int tab[4][4] = {0};
    struct Point {
        int x, y;
    } toDisplay[4];
    for (int i = 0; i < 4; i++) {
        toDisplay[i].x = tetroMinos.getTetroShape(nextBrick, i) % 2 + 1;
        toDisplay[i].y = tetroMinos.getTetroShape(nextBrick, i) / 2;
    }
    for (auto &i: toDisplay) {
        tab[i.y][i.x] = nextBrick;
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            Brick brick = Brick();
            brick.setFillColor(tetroMinos.getTetroColor(tab[j][i]));
            brick.setPosition((i + 13) * CELL_SIZE * SCREEN_RESIZE, (j + 3) * CELL_SIZE * SCREEN_RESIZE);
            window.draw(brick);
        }
    }
    if (!font.loadFromFile("../Font.ttf")) {
        std::cout << "Error loading font" << std::endl;
        system("pause");
    }
    sf::Text text;
    text.setFont(font);

    text.setString("Next brick  :");
    text.setCharacterSize(30 * SCREEN_RESIZE / 1.75);
    text.setFillColor(sf::Color::White);
    text.setPosition(CELL_SIZE * 13 * SCREEN_RESIZE, 1 * CELL_SIZE * SCREEN_RESIZE);
    window.draw(text);
}

void DrawingGame::drawScore(sf::RenderWindow &window, int score, float x, float y) {
    sf::Font font;
    if (!font.loadFromFile("../Font.ttf")) {
        std::cout << "Error loading font" << std::endl;
        system("pause");
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Score  :  " + std::to_string(score));
    text.setCharacterSize(30 * SCREEN_RESIZE / 1.75);
    text.setFillColor(sf::Color::White);
    text.setPosition(CELL_SIZE * x * SCREEN_RESIZE, CELL_SIZE * SCREEN_RESIZE * y);
    window.draw(text);
}


void DrawingGame::drawSpeed(sf::RenderWindow &window, float comeBackToDelay) {
    sf::Font font;
    if (!font.loadFromFile("../Font.ttf")) {
        std::cout << "Error loading font" << std::endl;
        system("pause");
    }
    sf::Text text;
    text.setFont(font);
    comeBackToDelay = 0.3 / comeBackToDelay;
    std::string number = std::to_string(comeBackToDelay);
    number = number.substr(0, 4);
    text.setString("Speed  :  " + number + "x");
    text.setCharacterSize(30 * SCREEN_RESIZE / 1.75);
    text.setFillColor(sf::Color::White);
    text.setPosition(CELL_SIZE * 12 * SCREEN_RESIZE, CELL_SIZE * SCREEN_RESIZE * 10);
    window.draw(text);
}

void DrawingGame::drawRestart(sf::RenderWindow &window, float x, float y) {
    sf::Font font;
    if (!font.loadFromFile("../Font.ttf")) {
        std::cout << "Error loading font" << std::endl;
        system("pause");
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Press \"R\" to restart");
    text.setCharacterSize(30 * SCREEN_RESIZE / 1.75);
    text.setFillColor(sf::Color::White);
    text.setPosition(CELL_SIZE * x * SCREEN_RESIZE, CELL_SIZE * SCREEN_RESIZE * y);
    window.draw(text);

}

void DrawingGame::drawEnd(sf::RenderWindow &window, int score) {
    window.clear();
    Brick back;
    Brick red;
    red.setFillColor(sf::Color::Red);
    for (int j = 0; j < ROWS; j++) {
        for (int i = 0; i < COLUMNS * 2; i++) {

            red.setPosition(i * CELL_SIZE * SCREEN_RESIZE, j * CELL_SIZE * SCREEN_RESIZE);
            back.setPosition(i * CELL_SIZE * SCREEN_RESIZE, j * CELL_SIZE * SCREEN_RESIZE);
            if (j == 7) {
                if (i == 4 || i == 5 || i == 6 || i == 8 || i == 11 || i == 13 || i == 14) {
                    window.draw(red);
                } else {
                    window.draw(back);
                }
            } else if (j == 8) {
                if (i == 4 || i == 8 || i == 9 || i == 11 || i == 13 || i == 15) {
                    window.draw(red);
                } else {
                    window.draw(back);
                }
            } else if (j == 9) {
                if (i == 4 || i == 5 || i == 6 || i == 8 || i == 10 || i == 11 || i == 13 || i == 15) {
                    window.draw(red);
                } else {
                    window.draw(back);
                }
            } else if (j == 10) {
                if (i == 4 || i == 8 || i == 11 || i == 13 || i == 15) {
                    window.draw(red);
                } else {
                    window.draw(back);
                }
            } else if (j == 11) {
                if (i == 4 || i == 5 || i == 6 || i == 8 || i == 11 || i == 13 || i == 14) {
                    window.draw(red);
                } else {
                    window.draw(back);
                }
            } else if (j == 13 || j == 14) {
                if (i > 5 && i < 14) {
                    continue;
                } else {
                    window.draw(back);
                }
            } else {
                window.draw(back);
            }
        }
    }
    drawScore(window, score, 8.5, 13);
    drawRestart(window, 7, 14);
}