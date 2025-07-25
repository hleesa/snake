//
// Created by LSH on 2025. 7. 25..
//

#ifndef WXWIDGETS_CLION_PROJECT_WALL_H
#define WXWIDGETS_CLION_PROJECT_WALL_H

#include <vector>
#include "CellType.h"

class Wall {

public:
    Wall();

    ~Wall();

    static void initWall(std::vector<CellType>& board);

private:


};


#endif //WXWIDGETS_CLION_PROJECT_WALL_H
