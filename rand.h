#ifndef __RAND
#define __RAND

#include <cstddef>
#include <random>
#include <time.h>
#include "def.h"

class Rand{
public:
    const ld range_from = -.5L;
    const ld range_to = .5L;

    std::random_device rand_dev;
    typedef std::mt19937_64 generator;
    generator  rd;
    std::uniform_real_distribution<ld> distr;

    Rand();
    ld rng();
    // std::cout<<distr(generator)<<std::endl;
    
};

#endif