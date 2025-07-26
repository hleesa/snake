//
// Created by LSH on 2025. 7. 26..
//

#include "Apple.h"
#include "RandomGenerator.h"
#include "Config.h"

void Apple::init(std::vector<CellType>& board) {
    for (int i = 0; i < 10; ++i) {
        int boardIndex = -1;
        do {
            int y = RandomGenerator::getint(1, BOARD_WIDTH - 1);
            int x = RandomGenerator::getint(1, BOARD_HEIGHT - 1);
            boardIndex = y * BOARD_WIDTH + x;
        } while (board[boardIndex] != CellType::EMPTY);
        board[boardIndex] = CellType::APPLE;
    }
}