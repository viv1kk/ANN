#include "layer.h"
#include <chrono>
#include <omp.h>


vec<vec<ld>> Layer::dot(const vec<vec<ld>>&A, const vec<vec<ld>>&B){
    // auto start = std::chrono::high_resolution_clock::now();
    
    size_t Ar = A.size(), Ac = A[0].size(), Br = B.size(), Bc = B[0].size();
    assert(Ac == Br);
    vec<vec<ld>>res(Ar, vec<ld>(Bc));
 
    #pragma omp parallel for

    for(size_t i = 0; i < Ar; i++){
        for(size_t k = 0; k < Bc; k++){
            ld sum = 0.0L;
            for(size_t j = 0; j < Ac; j++){
                sum += A[i][j] * B[j][k];
            }
            res[i][k] = sum;
        }
    }
    // auto stop = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
 
    // std::cout << "\nTime taken by Dot : "
    //      << (float)duration.count()/1000.0f << " ms";
 

    return res;
}

vec<vec<ld>> Layer::mul(const ld &A, const vec<vec<ld>>&B){

    // auto start = std::chrono::high_resolution_clock::now();

    size_t Br = B.size(), Bc = B[0].size();
    vec<vec<ld>>R(Br, vec<ld>(Bc));


    for(size_t i = 0; i < Br; i++){
        for(size_t j = 0; j < Bc; j++){
            R[i][j] = A * B[i][j];
        }
    }

    //     auto stop = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
 
    // std::cout << "\nTime taken by mul1 : "
    //      << (float)duration.count()/1000.0f << " ms";
    return R;
}
vec<vec<ld>> Layer::mul(const vec<vec<ld>>& A, const vec<vec<ld>>& B){

        // auto start = std::chrono::high_resolution_clock::now();
    size_t Ar = A.size(), Ac = A[0].size(), Br = B.size(), Bc = B[0].size();
    // shape("A->",A);
    // shape("B->",B);
    assert(Ar == Br && Ac == Bc);
    vec<vec<ld>>R(Ar, vec<ld>(Ac));

    for(size_t i = 0; i < Ar; i++){
        for(size_t j = 0; j < Ac; j++){ 
            R[i][j] = A[i][j] * B[i][j];
        }
    }
    // auto stop = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
 
    // std::cout << "\nTime taken by mul2 : "
    //      << (float)duration.count()/1000.0f << " ms";

    return R;
}

vec<vec<ld>> Layer::add(const vec<vec<ld>>&A, const vec<ld>&B){
    // auto start = std::chrono::high_resolution_clock::now();

    size_t Ar = A.size(), Ac = A[0].size(), Bc = B.size();
    assert(Ar == Bc);
    vec<vec<ld>> R(Ar, vec<ld>(Ac));
    for(size_t i = 0; i < Ar; i++){
        for(size_t j = 0; j < Ac; j++){
            R[i][j] = A[i][j] + B[i]; 
        }
    }
    // auto stop = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
 
    // std::cout << "\nTime taken by Add : "
    //      << (float)duration.count()/1000.0f << " ms";

    return R;
}
vec<vec<ld>> Layer::sub(const vec<vec<ld>>&A, const vec<vec<ld>>&B){
        // auto start = std::chrono::high_resolution_clock::now();

    size_t Ar = A.size(), Ac = A[0].size(), Br = B.size(), Bc = B[0].size();
    assert(Ar == Br && Ac == Bc);
    vec<vec<ld>> R(Ar, vec<ld>(Ac));
    for(size_t i = 0; i < Ar; i++){
        for(size_t j = 0; j < Ac; j++){
            R[i][j] = A[i][j] - B[i][j]; 
        }
    }

    // auto stop = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
 
    // std::cout << "\nTime taken by Sub1 : "
    //      << (float)duration.count()/1000.0f << " ms";


    return R;
}

vec<vec<ld>> Layer::sub(const vec<vec<ld>>&A, const ld &B){

        // auto start = std::chrono::high_resolution_clock::now();


    size_t r = A.size(), c = A[0].size();
    vec<vec<ld>> R(r, vec<ld>(c));
    for(size_t i = 0; i < r; i++){
        for(size_t j = 0; j < c; j++){
            R[i][j] = A[i][j] - B;
        }
    }
    //         auto stop = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
 
    // std::cout << "\nTime taken by Sub2 : "
    //      << (float)duration.count()/1000.0f << " ms";


    return R;
}

vec<vec<ld>> Layer::sub(const vec<vec<ld>>&A, const vec<ld>&B){

        // auto start = std::chrono::high_resolution_clock::now();

    size_t r = A.size(), c = A[0].size();
    vec<vec<ld>> R(r, vec<ld>(c));
    for(size_t i = 0; i < r; i++){
        for(size_t j = 0; j < c; j++){
            R[i][j] = A[i][j] - B[i];
        }
    }
    //         auto stop = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
 
    // std::cout << "\nTime taken by Sub3 : "
    //      << (float)duration.count()/1000.0f << " ms";


    return R;
}

vec<ld> Layer::sub(const vec<ld>&A, const ld &B){

        // auto start = std::chrono::high_resolution_clock::now();

    vec<ld> R(A.size());
    for(size_t i = 0; i < A.size(); i++){
        R[i] = A[i] - B;
    }
    //         auto stop = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
 
    // std::cout << "\nTime taken by Sub4 : "
    //      << (float)duration.count()/1000.0f << " ms";


    return R;
}

vec<vec<ld>> Layer::T(const vec<vec<ld>>& A){

        // auto start = std::chrono::high_resolution_clock::now();

    size_t r = A.size(), c = A[0].size();
    vec<vec<ld>> R(c, vec<ld>(r));
    // #pragma omp parallel for

    for(size_t i = 0 ; i < r; i++){
        for(size_t j = 0; j < c; j++){
            R[j][i] = A[i][j];
        }
    }
    //         auto stop = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
 
    // std::cout << "\nTime taken by Trans : "
    //      << (float)duration.count()/1000.0f << " ms";


    return R;
}

ld Layer::sum(const vec<vec<ld>>&A){

        // auto start = std::chrono::high_resolution_clock::now();

    ld sum = 0.0L;
    size_t r = A.size(), c = A[0].size();

    for(size_t i = 0; i < r; i++){
        for(size_t j = 0; j < c; j++){
            sum += A[i][j];
        }
    }
    //         auto stop = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
 
    // std::cout << "\nTime taken by Sum2 : "
    //      << (float)duration.count()/1000.0f << " ms";


    return sum;
}
void Layer::grad(){
    auto start = std::chrono::high_resolution_clock::now();

    {
        this->dZ = this->sub(this->A, Input::Y_hot);
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "\nTime taken by Grad : " << (float)duration.count()/1000.0f << " ms";
}

void Layer::backProp(Layer& L){
    auto start = std::chrono::high_resolution_clock::now();

    {

        ld m = 1.0L/(ld)Input::Y.size();
        // #pragma omp parallel

        this->dW = this->mul(m, this->dot(this->dZ, L.T(L.A)));
        this->dB = m * this->sum(this->dZ);
    
        L.dZ = this->mul(this->dot(this->T(this->W), this->dZ), act::d_relu(L.Z));
    }
    
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "\nTime taken by BackProp : " << (float)duration.count()/1000.0f << " ms";
}

void Layer::update_param(){
    auto start = std::chrono::high_resolution_clock::now();
    {
        this->W = this->sub(this->W, this->mul(Input::lr, this->dW));
        this->B = this->sub(this->B, (Input::lr * this->dB));
    }
 
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "\nTime taken by Update Param : "
         << (float)duration.count()/1000.0f << " ms";
}

void Layer::forwardProp(Layer &P){
    auto start = std::chrono::high_resolution_clock::now();

    {
        // Calculate Z
        // #pragma omp parallel
        this->Z = this->add(this->dot(this->W, P.A) , this->B);
        this->A = this->activation(this->Z);
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
 
    std::cout << "\nTime taken by Forward Prop : "
         << (float)duration.count()/1000.0f << " ms";
}

Layer::Layer(size_t numN):numN(numN),W_size(Input::X[0].size()), A(Input::X), W(Input::X), Z(Input::X), B(vec<ld>(numN)){
    // Initialize Bias
    [&](){
        Rand r;
        for(auto &i : B){
            i = r.rng();
        }
    }();
    }

Layer::Layer(size_t numN, f_ptr activation,Layer& prev):numN(numN), W_size(prev.numN), activation(activation), W(vec<vec<ld>>(numN, vec<ld>(prev.numN))),  B(vec<ld>(numN)){
    // init Weights
    [&](){
        Rand r;
        for(auto &tmp : W){
            for(auto &i : tmp) i = r.rng();
        }
    }();
    // Init Bias
        [&](){
        Rand r;
        for(auto &i : this->B){
            i = r.rng();
        }
    }();
}

void Layer::printLayer()const{
    std::cout<<"**************************************************************************";
    std::cout<<"\n";
    std::cout<<"Number of Neurons : "<<this->numN<<std::endl;
    std::cout<<"Size of weight Vector : "<<this->W_size<<std::endl;
    std::cout<<"Printing Weights & Bias for each Neuron : "<<std::endl;
    for(size_t i = 0; i < this->numN; i++){
        std::cout<<"Node "<<i<<"-> Weights [ ";
        for(size_t j = 0; j < this->W_size; j++){
            std::cout<<W[i][j];
            if(j != this->W_size-1)std::cout<<", ";
        }
        std::cout<<" ] - Bias : "<<this->B[i]
        <<"\n";
    }
    std::cout<<"\n";
    
    if(Z.size() > 0){
        std::cout<<"Printing Before Activation Z for each Neuron : "<<std::endl;
        for(size_t i = 0; i < Z.size(); i++){
            std::cout<<"Node "<<i<<"-> Weights [ ";
            for(size_t j = 0; j < Z[0].size(); j++){
                std::cout<<Z[i][j];
                if(j != Z[0].size()-1)std::cout<<", ";
            }std::cout<<" ]\n";
        }
        std::cout<<"\n";
    }
    if(A.size() > 0){
        std::cout<<"Printing After Activation A for each Neuron : "<<std::endl;
        for(size_t i = 0; i < A.size(); i++){
            std::cout<<"Node "<<i<<"-> Weights [ ";
            for(size_t j = 0; j < A[0].size(); j++){
                std::cout<<A[i][j];
                if(j != A[0].size()-1)std::cout<<", ";
            }std::cout<<" ]\n";
        }
    }
    std::cout<<"\n";
    std::cout<<"**************************************************************************\n";
}
