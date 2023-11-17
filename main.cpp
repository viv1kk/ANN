#include "layer.h"
#include "act.h"

int main(){
    {
        Input::classes = 10;
        Input::lr = .1;
        Input i;
        i.readCSV("./train.csv", 0);
        i.normalizeX();
    }

    std::cout<<"Building Layers\n";

    Layer l[3]= {
        Layer(Input::X.size()),
        Layer(32, act::relu, l[0]),
        Layer(Input::classes, act::softmax, l[1])
    };
        

    // forward prop is done
    std::cout<<"Layer Built\n";
    size_t layer_size = sizeof(l)/sizeof(l[0]);

    size_t iter = 500;
    for(size_t i = 1; i <= iter; i++){
        for(size_t j = 1; j < layer_size; j++){
            l[j].forwardProp(l[j-1]);
        }

        l[layer_size-1].grad();

        // back Prop
        // std::cout<<"\nBACKPROP \n\n";

        for(size_t j = layer_size-1; j > 0; j--){
            l[j].backProp(l[j-1]);
        }

        // l[1].backProp(l[0]);

        for(size_t j = 1; j < layer_size; j++){
            l[j].update_param();
        }

        // Input::lr = Input::lr * exp(0.1 * (10 - 11));
        std::cout<<"\nLearning Rate : "<<Input::lr<<std::endl;

        std::cout<<"iter : "<<i<<"\t";
        std::cout<<"Accuracy : " << mod::get_accuracy(mod::get_predictions(l[layer_size-1].A), Input::Y)<<std::endl;
    }

    //printing layers
    // l[0].printLayer();
    // l[1].printLayer();
    // l[2].printLayer();
    return 0;
}