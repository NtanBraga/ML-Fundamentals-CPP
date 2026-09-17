#include <iostream>
#include <dlib/array.h>
#include <dlib/matrix.h>
#include <dlib/svm.h>
#include <vector>

int main(){

    using namespace dlib;

    typedef matrix<double, 0, 1> sample_type;
    typedef linear_kernel<sample_type> KernelType;

    std::vector<matrix<double>> x;
    std::vector<float> y;

    krr_trainer<KernelType> trainer;
    trainer.set_kernel(KernelType());
    decision_function<KernelType> df = trainer.train(x, y);

    //for new x input, we can predict new y values
    std::vector<matrix<double>> new_x;
    for(auto& v : new_x){
        auto prediction = df(v);
        std::cout << "prediction: " << prediction << std::endl;
    }  

    return 0;
}