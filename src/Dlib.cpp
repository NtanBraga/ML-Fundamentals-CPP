#include <iostream>
#include <dlib/array.h>
#include <dlib/matrix.h>

int main(){

    using namespace std;

    //Matrix feita em compilação
    dlib::matrix<float, 3, 1> a;
    //Matrix feita em runtime
    dlib::matrix<double> b(2, 2);
    
    b.set_size(3,3);

    b = 5.1, 6.6, 1.2,
        1.0, 2.0, 3.0,
        0.2, 0.4, 0.9; 

    cout << "Matriz inicializada: \n" << b << endl;

    double data[] = {1,2,3,4,5,6,7,8,9};

    auto c = dlib::mat(data, 3, 3);

    cout << "Matrix std em dlib: \n" << c << endl;

    b(1,1) = 10;

    cout << "mudança de valor em matrix runtime: \n" << b << endl;

    auto d = dlib::identity_matrix<double>(3);

    cout << "Matrix identidade: \n" << d << endl;

    auto e = dlib::ones_matrix<float>(3,4);

    cout << "Matrix de 1s: \n" << e << endl;

    dlib::matrix<double> f = dlib::matrix_cast<double>(dlib::randm(4,4));

    cout << "Matrix de randomica: \n" << f << endl;

    auto result1 = c + d;

    cout << "Matrix somada: \n" << result1 << endl;

    auto result2 = c * d;

    cout << "Matrix multiplicação: \n" << result2 << endl;

    auto result3 = dlib::pointwise_multiply(c,d);

    cout << "Matrix multiplicação(pointwise): \n" << result3 << endl;

    f += 5;

    dlib::matrix<double> result4 = dlib::trans(f);

    cout << "Matrix transposta da randomica: \n" << result4 << endl;

    auto rmat = dlib::rowm(result4, 0);

    cout << "1 linha de uma matrix: \n" << rmat << endl;

    auto cmat = dlib::colm(result4, 0);

    cout << "1 coluna de uma matrix: \n" << cmat << endl;

    dlib::matrix<double> smat = dlib::subm(result4, dlib::range(1,2),dlib::range(1,2));

    cout << "submatrix da transposta: \n" << smat << endl;

    dlib::set_subm(result4, dlib::range(0,1), dlib::range(0,1)) = 7;

    cout << "inicializar parte da matrix: \n" << result4 << endl;

    dlib::set_subm(result4, dlib::range(0,1), dlib::range(0,1)) += 7;

    cout << "incrementar parte da matrix: \n" << result4 << endl;

    int num1 = 1;
    int num2 = 2;

    int num3 = num1 + num2;

    cout << num3;

    return 0;
}