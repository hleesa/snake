//
// Created by LSH on 2025. 7. 26..
//

#include "GameBoard.h"
#include "Config.h"

GameBoard::GameBoard() : cells(std::vector<CellType>(BOARD_WIDTH * BOARD_HEIGHT, CellType::EMPTY)) {
}

void GameBoard::initWall() {
    for (int x = 0; x < BOARD_WIDTH; ++x) {
        cells[x] = CellType::WALL;
        cells[BOARD_WIDTH * (BOARD_HEIGHT - 1) + x] = CellType::WALL;
    }
    for(int y = 0 ;y < BOARD_HEIGHT; ++y){
        cells[y * BOARD_WIDTH] = CellType::WALL;
        cells[y * BOARD_WIDTH + BOARD_WIDTH - 1] = CellType::WALL;
    }
}

void GameBoard::setCell(int i, CellType type) {
    cells[i] = type;
}