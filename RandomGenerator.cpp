//
// Created by LSH on 2025. 7. 26..
//

#include "RandomGenerator.h"

std::random_device RandomGenerator::rd;
std::mt19937 RandomGenerator::engine(RandomGenerator::rd());

int RandomGenerator::getint(int min, int max) {
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(engine);
}