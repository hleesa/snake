//
// Created by LSH on 2025. 7. 23..
//

#include <wx/wx.h>
#include "Snake.h"
#include "Direction.h"
#include "Config.h"

Snake::Snake() : body(std::deque<int>(1, BOARD_WIDTH + 1)), direction(Direction::DOWN), size(1) {
}

Snake::~Snake() {
}

bool Snake::setDirection(Direction direction_) {
    direction = direction_;
    return true;
}

void Snake::eat() {
    ++size;
}

bool Snake::move(std::vector<CellType>& board) {
    const int dx[] = {0, 0, -1, 1};
    const int dy[] = {-1, 1, 0, 0};
    int x = body.front() % BOARD_WIDTH;
    int y = body.front() / BOARD_WIDTH;
    int nx = x + dx[static_cast<int>(direction)];
    int ny = y + dy[static_cast<int>(direction)];

    if (nx < 0 || nx >= BOARD_WIDTH || ny < 0 || ny >= BOARD_HEIGHT) {
        return false;
    }
    int newBoardIndex = ny * BOARD_WIDTH + nx;
    if (board[newBoardIndex] == CellType::SNAKE || board[newBoardIndex] == CellType::WALL) {
        return false;
    }
    else if (board[newBoardIndex] == CellType::APPLE) {
        eat();
    }
    body.push_front(ny * BOARD_WIDTH + nx);
    board[ny * BOARD_WIDTH + nx] = CellType::SNAKE;
    if (body.size() > size) {
        board[body.back()] = CellType::EMPTY;
        body.pop_back();
    }

    return true;
}