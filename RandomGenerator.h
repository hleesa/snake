//
// Created by LSH on 2025. 7. 26..
//

#ifndef WXWIDGETS_CLION_PROJECT_RANDOMGENERATOR_H
#define WXWIDGETS_CLION_PROJECT_RANDOMGENERATOR_H

#include <random>

class RandomGenerator {

public:

    static int getint(int min, int max);

private:

    RandomGenerator();

    ~RandomGenerator();

    static std::random_device rd;
    static std::mt19937 engine;
};


#endif //WXWIDGETS_CLION_PROJECT_RANDOMGENERATOR_H
