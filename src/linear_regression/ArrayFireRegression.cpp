#include <iostream>
#include <arrayfire.h>

int main(){

    using namespace std;

    //lambda to calculate predictions
    auto predict = [](auto& v, auto& w) {
        return af::batchFunc(v, w, [] (const auto& a, const auto& b){
            return af::sum(a*b, /*dim*/ 1);
        });
    };

    //assuming we have the training data in x and y variables
    //define train_weights

    af::array x(3, 3, af::dtype::f32);
    af::array y(3, 3, af::dtype::f32);

    //the first column is for the bias form
    af::dim4 weights_dim(1, 2);
    auto train_weights = af::constant(0.f, weights_dim, af::dtype::f32);


    //cost value and gradient
    af::array d, dj;
    //learning rate
    float lr = 0.1f;
    int n_iter = 300;
    for (int i = 0; i < n_iter; ++i){
        cout << "iteration " << i << ":\n";

        //captura as linhas da matriz(dados de amostra)
        int n = x.dims(0);

        //get cost
        auto h = predict(x, train_weights);
        auto diff = (y- h);
        auto j = af::sum(diff * diff) / n;
        af_print(j);

        //find gradient cost
        auto dm = (-2.f / n) * af::sum(x.col(1) * diff);
        auto dc = (-2.f / n) * af::sum(diff);
        auto dj = af::join(1, dc, dm);

        //update via gradient descent
        train_weights = train_weights - lr * dj;
    }

    //most import part of the loop is to calc the predict error
        // auto h = predict(x, train_weights);
        // auto diff = (y- h);

    //then join the values into one vector to make single expression
    //for upgrating the training parameters
        // auto dj = af::join(1, dc, dm);
        // train_weights = train_weights - lr * dj;
    

    //the cost function is calculated this way
        // auto j = af::sum(diff * diff) / i;

    return 0;
}