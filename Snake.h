//
// Created by LSH on 2025. 7. 23..
//

#ifndef WXWIDGETS_CLION_PROJECT_SNAKE_H
#define WXWIDGETS_CLION_PROJECT_SNAKE_H

#include <deque>
#include "Direction.h"
#include "CellType.h"

class Snake {
public:
    Snake();
    ~Snake();

    bool setDirection(Direction direction_);

    int move(const std::vector<CellType>& board);

    int getHead() const;
    int getTail() const;


private:
    std::deque<int> body;
    Direction direction;
    int size;
    void eat();
    void die();
};


#endif //WXWIDGETS_CLION_PROJECT_SNAKE_H
