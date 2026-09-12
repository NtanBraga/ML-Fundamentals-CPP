#include <iostream>
#include <blaze/Math.h>

int main(){

    typedef blaze::DynamicMatrix<float, blaze::columnMajor> Matrix;
    typedef blaze::DynamicVector<float, blaze::columnVector> Vector;

    int n = 10000;

    Matrix x(n, 2UL);
    Matrix y(n, 1UL);

    //X^T*X
    auto xtx = blaze::trans(x) * x;
    //inverse of X^T*X
    auto inv_xtx = blaze::inv(xtx);
    //calc X^T*y
    auto xty = blaze::trans(x) * y;
    //calc coefficient of linear regression
    Matrix beta = inv_xtx * xty;


    //coefficients for making predictions on data

    blaze::StaticMatrix<float,2UL,3UL> new_x = {{1,2,3}, {1,2,3}};

    auto line_coeffs = blaze::expand(blaze::row<0UL>(blaze::trans(beta)), new_x.rows());
    auto new_y = new_x % line_coeffs;


    return 0;
}