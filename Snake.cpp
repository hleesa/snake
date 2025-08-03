//
// Created by LSH on 2025. 7. 23..
//

#include "Snake.h"
#include "Direction.h"
#include "Config.h"
#include "RandomGenerator.h"
#include <deque>

Snake::Snake() : size(1) {
    int position[4] = {(BOARD_HEIGHT - 2) * BOARD_WIDTH + BOARD_WIDTH / 2, BOARD_WIDTH * 1 + BOARD_WIDTH / 2,
                       BOARD_HEIGHT / 2 * BOARD_WIDTH + BOARD_WIDTH - 2, BOARD_HEIGHT / 2 * BOARD_WIDTH + 1};

    int d = RandomGenerator::getint(0, 3);
    body = std::deque<int>(1, position[d]);
    direction = static_cast<Direction>(d);
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

void Snake::clear() {
    body.clear();
}

int Snake::getHead() const {
    return body.front();
}
int Snake::getTail() const {
    return body.back();
}

std::deque<int> Snake::getBody() const{
    return body;
}

int Snake::move(const std::vector<CellType>& board) {
    const int dx[] = {0, 0, -1, 1};
    const int dy[] = {-1, 1, 0, 0};
    int x = body.front() % BOARD_WIDTH;
    int y = body.front() / BOARD_WIDTH;
    int nx = x + dx[static_cast<int>(direction)];
    int ny = y + dy[static_cast<int>(direction)];
    int newSnakePosition = ny * BOARD_WIDTH + nx;

    if (nx < 0 || nx >= BOARD_WIDTH || ny < 0 || ny >= BOARD_HEIGHT) {
        return -1;
    }
    if (board[newSnakePosition] == CellType::SNAKE || board[newSnakePosition] == CellType::WALL) {
        return -1;
    }

    if (board[newSnakePosition] == CellType::APPLE) {
        eat();
    }
    else {
        body.pop_back();
    }
    body.push_front(newSnakePosition);

    return newSnakePosition;
}