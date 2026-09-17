#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(){
    //Matrix de ponto flutuante
    typedef Eigen::Matrix<float, 3, 3> Matrix33f;
    //Coluna de vetores
    typedef Eigen::Matrix<float, 3, 1> Matrix3f;

    //Matrix com inicialização definidas em entrada
    typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> MatrixDynamic;


    Matrix33f a;
    Matrix3f b;
    MatrixDynamic c(6,13);
    Matrix33f d;

    //Adicionar valores em objetos
    a = Matrix33f::Identity();
    b = Matrix3f::Zero();
    c = MatrixDynamic::Random(6,13);
    d << 1, 2, 3,
         4, 5, 6,
         7, 8 ,9;

    a(0,0) = 3;

    cout << "Matrix A:\n" << a << endl;
    cout << "Matrix B:\n" << b << endl;
    cout << "Matrix C:\n" << c << endl;
    cout << "Matrix D:\n" << d << endl;


    auto u = Matrix2d::Random();
    auto v = Matrix2d::Random();

    cout << "Matriz U:\n" << u << endl;
    cout << "Matriz V:\n" << v << endl;

    auto result = u + v;
    cout << "Matrix Result soma:\n" << result << endl;

    auto result2 = u.array() * v.array();
    cout << "Matrix Result multiplicação:\n" << result2 << endl;

    auto result3 = u.array() / v.array();
    cout << "Matrix Result divisão:\n" << result3 << endl;




    return 0;
}