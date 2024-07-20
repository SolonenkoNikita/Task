#ifndef RANDOM_H
#define RANDOM_H

#include <random>

class Random
{
public:
    Random() : gen_(rd_()) {}

    int generate(int, int);

private:
    std::random_device rd_;

    std::mt19937 gen_;
};

#endif
