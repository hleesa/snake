//
// Created by LSH on 2025. 7. 26..
//

#ifndef WXWIDGETS_CLION_PROJECT_APPLE_H
#define WXWIDGETS_CLION_PROJECT_APPLE_H

#include "CellType.h"
#include <vector>
#include "RandomGenerator.h"
#include "set"

class Apple {

public:
    Apple();

    ~Apple();

    void init(const std::vector<CellType>& board);

    std::set<int> getPositions() const;

    int create(const std::vector<CellType>& board);

    void erase(int apple);

private:

    std::set<int> positions;

};


#endif //WXWIDGETS_CLION_PROJECT_APPLE_H
