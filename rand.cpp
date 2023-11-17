#include "rand.h"

Rand::Rand(): rd(rand_dev()), distr(range_from, range_to){
    rd.seed(::time(NULL));
}

ld Rand::rng(){
    return distr(rd);
}