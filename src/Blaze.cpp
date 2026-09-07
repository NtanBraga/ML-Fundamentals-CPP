#include <iostream>
#include <blaze/Math.h>

int main(){

    using namespace std;

    //Definidas em compilação

    typedef blaze::StaticMatrix<float, 3UL, 3UL, blaze::columnMajor> Matrix33f;
    typedef blaze::StaticVector<float, 3UL> Matrix3f;

    Matrix33f a;
    Matrix3f b;

    cout << "Matrix 3x3:\n" << a << endl;
    cout << "Vetor de 3:\n" << b << endl;

    //Definidas em runtime

    typedef blaze::DynamicMatrix<double> DynMatrix;
    typedef blaze::DynamicVector<double> DynVector;

    DynMatrix dm(4,5);
    DynVector dv(6);

    cout << "Matrix Dinamico:\n" << dm << endl;
    cout << "Vetor Dinamico:\n" << dv << endl;
    

    a = blaze::zero<float>(3UL,3UL);

    cout << "Matrix de zeros:\n " << a << endl;

    a = blaze::IdentityMatrix<float>(3UL);

    cout << "Matrix Identidade:\n " << a << endl;

    blaze::Rand<float> rand;

    auto vRand = blaze::generate(3UL, [&] (size_t) {return rand.generate();});

    cout << "Vetor randomico: \n" << vRand << endl;

    a = {{1,2,3},{4,5,6},{7,8,9}};

    cout << "Matriz A: \n" << a << endl; 

    a = blaze::uniform(3UL, 3UL, 3.0f);

    cout << "Matriz A uniforme: \n" << a << endl;

    a(0,0) = 1;

    cout << "Matriz A com valor modificado: \n" << a << endl;

    array<int, 4> data = {1,2,3,4};

    blaze::CustomVector<int,blaze::unaligned,blaze::unpadded,blaze::rowMajor> v2(data.data(), data.size());

    vector<float> mdata = {1,2,3,4,5,6,7,8,9};

    blaze::CustomMatrix<float,blaze::unaligned,blaze::unpadded, blaze::rowMajor> m2(mdata.data(), 3UL,3UL);


    cout << "Modificar vetor standard para vetor blaze: \n" << v2 << endl;
    cout << "Modificar vetor standard para matriz blaze: \n" << m2 << endl;


    blaze::StaticMatrix<float,2UL,2UL> mmat1 = {{1,2}, {3,4}};

    auto mmat2 = mmat1;

    blaze::StaticMatrix<float,2UL,2UL> result = mmat1 % mmat2;

    cout << "Matriz resultado %: \n" << result << endl;

    result = mmat1 + mmat2;

    cout << "Matriz resultado +: \n" << result << endl;

    mmat1 += mmat2;
    result = mmat1 * mmat2;

    cout << "Matriz resultado *: \n" << result << endl;

    blaze::StaticMatrix<float,4UL,4UL> mat4 = { { 1, 2, 3, 4},
                                                { 5, 6, 7, 8},
                                                { 9, 10, 11, 12},
                                                { 13, 14, 15, 16}};

    cout << "Matrix 4x4: \n" << mat4 << endl;


    auto mmat4 = blaze::submatrix<1UL,1UL,2UL,2UL>(mat4);

    cout << "Submatrix de matrix 4x4: \n" << mmat4 << endl;

    blaze::submatrix<1UL,1UL,2UL,2UL>(mat4) *= 0;

    cout << "Matrix 4x4 modificada: \n" << mat4 << endl;

    blaze::DynamicMatrix<float, blaze::rowVector> matex = blaze::uniform(4UL,4UL, 2);

    cout << "Matrix 4x4 uniforme: \n" << matex << endl;

    blaze::DynamicVector<float, blaze::rowVector> vecex = {1, 2, 3, 4};

    auto mat_vec_ex = blaze::expand(vecex, 4UL);

    cout << "Vetor transformado em Matrix: \n" << mat_vec_ex << endl;

    matex += mat_vec_ex;

    cout << "Vetor transformado em Matrix 2: \n" << matex << endl;

    return 0;
}