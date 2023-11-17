#include "act.h"

vec<vec<ld>> act::relu(const vec<vec<ld>>&V){
    vec<vec<ld>>res(V.size(), vec<ld>(V[0].size()));
    for(size_t i = 0; i < V.size(); i++){
        for(size_t j = 0; j < V[0].size(); j++){
            res[i][j] = std::max(0.0L, V[i][j]);
        }
    }
    return res;
}

vec<vec<ld>> act::softmax(const vec<vec<ld>>&V){
    vec<vec<ld>>res(V.size(), vec<ld>(V[0].size()));
    for(size_t i = 0; i < V[0].size(); i++){
        
        ld expsum = 0.0L;
        for(size_t j = 0; j < V.size(); j++){
            expsum += std::exp(V[j][i]);
        }
        for(size_t j = 0; j < V.size(); j++){
            res[j][i] = std::exp(V[j][i])/expsum;
        }
    }
    return res;
}

vec<vec<ld>> act::d_relu(const vec<vec<ld>>&A){
    vec<vec<ld>>res(A.size(), vec<ld>(A[0].size()));
    for(size_t i = 0; i < A.size(); i++){            
        for(size_t j = 0; j < A[0].size(); j++){
            res[i][j] = (A[i][j] > 0.0)?1.0L:0.0L;
        }
    }
    return res;
}


vec<ld> mod::get_predictions(vec<vec<ld>> LA){
    size_t c = LA[0].size(), r = LA.size();
    vec<ld>R(c);
    for(size_t i = 0; i < c; i++){
        size_t mx = 0;
        for(size_t j = 1; j < r; j++){
            mx = (LA[mx][i] < LA[j][i])?j:mx;
        }
        R[i] = mx;
    }
    return R;
}
ld mod::get_accuracy(vec<ld> Pred_Y, vec<ld>Y){
    size_t n = Y.size();
    assert(Pred_Y.size() == n);

    size_t c = 0;
    for(int i = 0; i < n; i++){
        if(Pred_Y[i] == Y[i]) c++;
    }
    return ((ld)c/(ld)n);
}
