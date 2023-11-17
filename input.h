#ifndef __INPUT
#define __INPUT

#include "def.h"
#include "misc.h"

class Input{
public:
    // comes prepared to be feedef to the network
    static vec<vec<ld>> X; 
    static vec<vec<ld>> Y_hot;
    static vec<ld> Y;
    static ld lr;
    static size_t classes;

    void input_X(const vec<vec<ld>>&);
    void one_hot_Y(const vec<ld>&);
    void normalizeX();

    void readCSV(const std::string&, const size_t );


    void printX(size_t = 0); // 0 for all else the provided no. of samples
    void printY(size_t = 0); // 0 for all else the provided no. of samples

};

#endif
