#include "input.h"

vec<vec<ld>> Input::X = vec<vec<ld>>();
vec<vec<ld>> Input::Y_hot = vec<vec<ld>>();
vec<ld> Input::Y = vec<ld>();

ld Input::lr = 0.01; // default learning rate;
size_t Input::classes = 1;


void Input::one_hot_Y(const vec<ld>& Y_data){
    size_t sz = Y_data.size();

    vec<vec<ld>> hot(Input::classes, vec<ld>(sz, 0.0L));
    for(size_t i = 0; i < sz; i++){
        hot[(size_t)Y_data[i]][i] = 1.0L;
    }
    Input::Y_hot = hot;
}

void Input::input_X(const vec<vec<ld>>& X_data){
    size_t r = X_data.size(), c =X_data[0].size();

    vec<vec<ld>>Xr(c, vec<ld>(r));
    for(size_t i = 0; i < r; i++){
        for(size_t j = 0; j < c; j++){
            Xr[j][i] = X_data[i][j];
        }
    }
    Input::X = Xr;
}


void Input::printX(size_t num){
    assert(num >= 0 && num < Input::X.size());
    size_t no_of_samples = (num == 0)?Input::X.size():num;
    std::cout<<"\nPrinting "<<no_of_samples<<" samples of X :\nRows = Input feature, Cols = Samples\n\n";
    for(size_t i = 0; i < Input::X.size(); i++){
        for(size_t j = 0; j < no_of_samples; j++){
            std::cout<<Input::X[i][j]<<"\t";
        }std::cout<<"\n";
    }std::cout<<"\n";
}

void Input::printY(size_t num){
    assert(num >= 0 && num < Input::Y.size());
    size_t no_of_samples = (num == 0)?Input::Y.size():num;
    std::cout<<"\nPrinting "<<no_of_samples<<" samples of Y :\nRows = Input feature, Cols = Samples\n\n";
    for(size_t i = 0; i < Input::Y.size(); i++){
        for(size_t j = 0; j < no_of_samples; j++){
            std::cout<<Input::Y_hot[i][j]<<"\t";
        }std::cout<<"\n";
    }std::cout<<"\n";    
}

void Input::normalizeX(){
    size_t r = Input::X.size(), c =Input::X[0].size();
    for(size_t i = 0; i < r; i++){
        for(size_t j = 0; j < c; j++){
            X[i][j] /= 255.0L;
        }
    } 
}

void Input::readCSV(const std::string& filename, const size_t label){
    std::vector<std::vector<ld>> data; // Store CSV data

    // Open the CSV file
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        // return data; // Return an empty vector in case of an error
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::vector<ld> row;
        std::stringstream lineStream(line);
        std::string cell;


        while(std::getline(lineStream, cell, ',')) {
            row.push_back(std::stof(cell));

            // std::cout<<cell<<", ";
        }
        data.push_back(row);
    }

    file.close();
    // preprocessing data;

    data = [&](){
        size_t r = data.size(), c = data[0].size();
        vec<vec<ld>> R(c, vec<ld>(r));

        for(size_t i = 0 ; i < r; i++){
            for(size_t j = 0; j < c; j++){
                R[j][i] = data[i][j];
            }
        }
        return R;
    }();
    this->Y = vec<ld>(data[0].begin(), data[0].end());
    this->one_hot_Y(this->Y);
    data.erase(data.begin());
    this->X = data;
    // return data;
}