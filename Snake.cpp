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

int Snake::getTail() const {
    return body.back();
}

int Snake::move(const std::vector<CellType>& board) {
    const int dx[] = {0, 0, -1, 1};
    const int dy[] = {-1, 1, 0, 0};
    int x = body.front() % BOARD_WIDTH;
    int y = body.front() / BOARD_WIDTH;
    int nx = x + dx[static_cast<int>(direction)];
    int ny = y + dy[static_cast<int>(direction)];

    if (nx < 0 || nx >= BOARD_WIDTH || ny < 0 || ny >= BOARD_HEIGHT) {
        return -1;
    }
    int newSnakePosition = ny * BOARD_WIDTH + nx;
    if (board[newSnakePosition] == CellType::SNAKE || board[newSnakePosition] == CellType::WALL) {
        return -1;
    }
    else if (board[newSnakePosition] == CellType::APPLE) {
        eat();
    }

    body.push_front(ny * BOARD_WIDTH + nx);
    if (body.size() > size) {
        body.pop_back();
    }

    return newSnakePosition;
}