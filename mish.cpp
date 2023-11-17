#include "misc.h"

void printArr(const vec<ld> &x){
    for(auto &i : x){
        std::cout<<i<<", ";
    }std::cout<<"\n";
}
void printArr(const vec<vec<ld>>& x){
    for(auto &i : x){
        for(auto &j : i){
            std::cout<<j<<", ";
        }std::cout<<"\n";
    }std::cout<<"\n";
}

void shape(std::string s, const vec<vec<ld>>&x){
    std::cout<<s<<" ( "<<x.size()<<", "<<x[0].size()<<" )\n";
}
