#include <iostream>
#include <arrayfire.h>
#include <vector>

int main(){

    using namespace std;

    //Usar CPU ao inves de drivers de video
        // AF_BUILD_CPU
        // AF_BUILD_CUDA
        // AF_BUILD_OPENCL
        // AF_BUILD_ONEAPI
    af::setBackend(AF_BACKEND_CPU);

    //floating vectors
    af::array m(3, 3, af::dtype::f32);
    af::array v(3, af::dtype::f64);

    m = af::constant(0, 3, 3);
    af::print("Matriz constante '0': \n", m);

    m = af::constant(1, 3, 3);
    af::print("Matriz constante '1': \n", m);

    m = af::identity(3,3);
    af::print("Matriz identidade: \n", m);

    v = af::randu(3);
    af::print("Vetor randomico: \n", v);

    m = af::array(af::dim4(3, 3), {1.0f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f,8.0f,9.0f});
    af::print("Matriz dinamica: \n", m);

    m(0,0) = 3;
    af::print("Matriz l0c0 modificada: \n", m);
    

    //diferente de outras bibliotecas, o arrayfire
    //copia o vetor standard ao inves de pegar o ponteiro
    vector<float> std_v = {1,2,3,4,5,6,7,8,9};
    m = af::array(3,3, std_v.data());
    
    af::print("matriz arrayfire de vetor standard: \n", m);
    cout << "Ponteiro de std_v: " << &std_v << endl;
    cout << "Ponteiro de matriz arrayfire:" << &m << endl;

    //aritmetica

    auto a = af::array(af::dim4(2,2), {1,2,3,4});
    a = a.as(af::dtype::f32);
    auto b = a.copy();

    af::print("Matriz A: \n", a);
    af::print("Matriz B: \n", b);

    auto result = a * b;
    af::print("Matriz result( a * b): \n", result);

    a = b * 4;
    af::print("Matriz A(b * 4): \n", a);

    result = a + b;
    a += b;
    af::print("Matriz result(a + b): \n", result);
    af::print("Matriz A(a+=b): \n", a);

    result = af::matmul(a, b);
    af::print("Matriz result(matmul(a,b)): \n", result);


    // seq - representing a linear sequence
    // end - representing the last element of a dimension
    // span - representing the entire dimension

    auto mat1 = af::iota(af::dim4(4,4));
    auto center = mat1(af::seq(1,2), af::seq(1,2));
    center *= 2;

    af::print("Matriz1: \n", mat1);
    af::print("Matriz center: \n", center);

    //rows and cols para trabalhar com mais de uma linha ou colunas

    m.row(1) +=3;
    m.col(2) /=4;

    af::print("Matriz1: \n", mat1);

    //broadcasting

    auto bmat = af::constant(2,4,4);
    auto bvec = af::array(4, {1, 2, 3, 4});
    bmat = af::batchFunc(bvec, bmat, [](const auto& a, const auto& b){return a + b;});

    af::print("Matriz distribuida: \n", bmat);

    return 0;
}