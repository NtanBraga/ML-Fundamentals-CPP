#include <iostream>
#include <vector>
#include <array>
#include <xtensor/containers/xarray.hpp>
#include <xtensor/containers/xtensor.hpp>
#include <xtensor/containers/xfixed.hpp>
#include <xtensor/io/xio.hpp>

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

    return 0;
}