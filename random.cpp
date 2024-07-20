#include "random.h"

Random::generate(int min, int max)
{
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen_);
}
