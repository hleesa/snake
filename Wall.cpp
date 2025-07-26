//
// Created by LSH on 2025. 7. 25..
//

#include "Config.h"
#include "Wall.h"
#include "CellType.h"

void Wall::init(std::vector<CellType>& board) {
    for (int x = 0; x < BOARD_WIDTH; ++x) {
        board[x] = CellType::WALL;
        board[BOARD_WIDTH * (BOARD_HEIGHT - 1) + x] = CellType::WALL;
    }
    for(int y = 0 ;y < BOARD_HEIGHT; ++y){
        board[y * BOARD_WIDTH] = CellType::WALL;
        board[y * BOARD_WIDTH + BOARD_WIDTH - 1] = CellType::WALL;
    }
}
