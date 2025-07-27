//
// Created by LSH on 2025. 7. 26..
//

#ifndef WXWIDGETS_CLION_PROJECT_GAMEBOARD_H
#define WXWIDGETS_CLION_PROJECT_GAMEBOARD_H

#include <vector>
#include "CellType.h"

class GameBoard {

public:

    GameBoard();

    ~GameBoard();

    void initWall();

    void setCell(int i, CellType type);

    std::vector<CellType> getCells() const;

    CellType getType(int i) const;

private:

    std::vector<CellType> cells;

};


#endif //WXWIDGETS_CLION_PROJECT_GAMEBOARD_H
