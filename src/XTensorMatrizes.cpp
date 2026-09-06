#include <iostream>
#include <vector>
#include <array>
#include <xtensor/containers/xarray.hpp>
#include <xtensor/containers/xtensor.hpp>
#include <xtensor/containers/xfixed.hpp>
#include <xtensor/containers/xadapt.hpp>
#include <xtensor/generators/xrandom.hpp>
#include <xtensor/io/xio.hpp>
#include <xtensor-blas/xlinalg.hpp>

int main(){

    using namespace std;

    vector<size_t> shape1 = { 2, 3, 4};
    array<size_t, 3> shape2 = { 2, 3, 4};

    xt::xarray<double, xt::layout_type::row_major> a(shape1);
    xt::xtensor<double, 3> b(shape2);

    xt::xtensor_fixed<double, xt::xshape<3,2,4>> c;

    cout << "Matriz dinamica em compilação: \n" << a << endl;
    cout << "Matriz tem colunas fixas em compilação: \n" << b << endl;
    cout << "Matriz ao toda é fixa em compilação: \n" << c << endl;


    xt::xarray<double> mat1{{1.0,2.0,3.0},
                            {4.0,5.0,6.0},
                            {7.0,8.0,9.0}};

    cout << "Matriz 3x3 inicializada: \n" << mat1 << endl;

    vector<uint64_t> shape3 = {2, 2};

    auto x = xt::ones<int>(shape3);
    auto y = xt::zeros<int>(shape3);
    auto z = xt::eye<int>(shape3);

    cout << "Matriz preenchida com 1s: \n" << x << endl;
    cout << "Matriz preenchida com 0s: \n" << y << endl;
    cout << "Matriz 2x2 com 1s em diagonal: \n" << z << endl;

    //adaptar arrays em matrizes xtensor

    vector<float> data{1,2,3,4};
    vector<size_t> shape4{2,2};
    auto data_x = xt::adapt(data,shape4);
    
    cout << "Matriz adaptada: \n" << data_x << endl;

    //acesso direto aos containers

    vector<size_t> shape5 = {3,2,4};
    xt::xarray<float> alt = xt::ones<float>(shape5);
    alt(2,1,3) = 3.14f;

    cout << "Acesso direto a matriz: \n" << alt << endl;

    //operações aritmeticas

    xt::xarray<double> num1 = xt::random::rand<double>({2,2});
    xt::xarray<double> num2 = xt::random::rand<double>({2,2});
    xt::xarray<double> num3 = num1 + num2;

    cout << "Soma das matrizes: \n" << num3 << endl;

    num1 -= num2;

    cout << "Subtração das matrizes: \n" << num1 << endl;

    num3 = xt::linalg::dot(num1,num2);
    
    cout << "Matriz com linalg produto: \n" << num3 << endl;
    
    num3 = num1 + 5;

    cout << "Matriz com linalg produto mais 5: \n" << num3 << endl;

//View

    xt::xarray<int> view_a = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    auto view_m = xt::view(view_a, xt::range(1,3), xt::range(1,3));

    cout << "View matriz: \n" << view_m << endl;


    auto q = xt::random::rand<double>({2,2});
    auto p = xt::random::rand<double>({2,1});

    cout << "Matriz irregular 1: \n" << q << endl;
    cout << "Matriz irregular 2: \n" << p << endl;

    auto r = q + p;

    cout << "Matrizes irregulares em uma matrix: \n" << r << endl;

    return 0;
}