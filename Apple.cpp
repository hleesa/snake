//
// Created by LSH on 2025. 7. 26..
//

#include "Apple.h"
#include "RandomGenerator.h"
#include "Config.h"

Apple::Apple() {
}

Apple::~Apple() {
}

std::set<int> Apple::getPositions() const {
    return positions;
}

void Apple::init(const std::vector<CellType>& board) {
    for (int i = 0; i < 10; ++i) {
        int boardIndex = -1;
        do {
            int y = RandomGenerator::getint(1, BOARD_WIDTH - 1);
            int x = RandomGenerator::getint(1, BOARD_HEIGHT - 1);
            boardIndex = y * BOARD_WIDTH + x;
        } while (board[boardIndex] != CellType::EMPTY);
        positions.insert(boardIndex);

    }
}