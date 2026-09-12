#include <iostream>
#include <Eigen/Dense>
#include <Eigen/IterativeLinearSolvers>

int main(){

    //Ax = b

    typedef float DType;
    using Matrix = Eigen::Matrix<DType, Eigen::Dynamic, Eigen::Dynamic>;

    int n = 100000;

    //Dados carregados em matrizes x e y
    Matrix x(n,2);
    Matrix y(n,1);

    //Metodo que utiliza algoritmo GD

    Eigen::LeastSquaresConjugateGradient<Matrix> gd;


    gd.setMaxIterations(1000); // Iterações maximas
    gd.setTolerance(0.001); // Parada
    gd.compute(x); 
    auto b_gd = gd.solve(y); // retorna o valor do peso beta

    //Metodo que utiliza da inversão de matriz (O(p^3))

    Eigen::MatrixXf new_x(5,2);
    new_x << 1, 1, 1, 2, 1, 3, 1, 4, 1, 5;

    auto b = (x.transpose() * x).ldlt().solve(x.transpose() * y);
    Eigen::VectorXf b_vec = b;
    auto new_y = new_x.array().rowwise() * b_vec.transpose().array();


    return 0;
}