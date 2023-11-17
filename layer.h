#ifndef __LAYERS
#define __LAYERS

#include "misc.h"
#include "rand.h"
#include "input.h"
#include "act.h"


class Layer{
public:
    size_t numN {}; // number of neurons
    size_t W_size {}; // size of weight vector
    f_ptr activation; // activation function used buy layer

    vec<vec<ld>>W;
    vec<ld>B;

    vec<vec<ld>>Z;
    vec<vec<ld>>A;

    vec<vec<ld>>dZ;
    vec<vec<ld>>dW;
    ld dB;

    // operations
    vec<vec<ld>> dot(const vec<vec<ld>>&, const vec<vec<ld>>&);
    vec<vec<ld>> mul(const ld&, const vec<vec<ld>>&);
    vec<vec<ld>> mul(const vec<vec<ld>>&, const vec<vec<ld>>&);
    vec<vec<ld>> add(const vec<vec<ld>>&, const vec<vec<ld>>&);
    vec<vec<ld>> add(const vec<vec<ld>>&, const vec<ld>&);

    vec<vec<ld>> sub(const vec<vec<ld>>&, const vec<vec<ld>>&);
    vec<vec<ld>> sub(const vec<vec<ld>>&, const ld&);
    vec<vec<ld>> sub(const vec<vec<ld>>&, const vec<ld>&);
    vec<ld> sub(const vec<ld>&, const ld&);

    ld sum(const vec<vec<ld>>&);
    vec<vec<ld>> T(const vec<vec<ld>>& );

    // Input Layer
    Layer(size_t );
    Layer(size_t, f_ptr, Layer&);

    // Forward Prop
    void forwardProp(Layer& );
    void printLayer()const;
    void grad();
    //Back Prop
    // void backPropOut(Layer&); // output layer
    void backProp(Layer&);

    // update_param
    void update_param();
};

#endif