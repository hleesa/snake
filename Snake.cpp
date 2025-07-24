//
// Created by LSH on 2025. 7. 23..
//

#include <wx/wx.h>
#include "Snake.h"
#include "Direction.h"
#include "Config.h"

Snake::Snake() : body(std::deque<int>(1, 0)), direction(Direction::DOWN) {
}

Snake::~Snake() {
}

bool Snake::setDirection(Direction direction_) {
    direction = direction_;
    return true;
}

bool Snake::move(std::vector<CellType>& board) {
    const int dx[] = {0, 0, -1, 1};
    const int dy[] = {-1, 1, 0, 0};
    int x = body.front() % BOARD_WIDTH;
    int y = body.front() / BOARD_WIDTH;
    int nx = x + dx[static_cast<int>(direction)];
    int ny = y + dy[static_cast<int>(direction)];

    if (nx < 0 || nx + CELL_WIDTH >= BOARD_WIDTH || ny < 0 || ny + CELL_HEIGHT >= BOARD_HEIGHT) {
        return false;
    }

    board[ny * BOARD_WIDTH + nx] = CellType::SNAKE;
    return true;
}