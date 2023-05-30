#include "ft_mat.hpp"
#include <iostream>
#include <complex>

using namespace std;


int main() {
    ft::matrix<int> m1({{1,1,6},
                        {1,1,7},
                        {1,1,8}});
    ft::matrix<int> m2({{1,1,8},
                        {1,1,7},
                        {1,1,6}});
    
    ft::matrix<complex<int>> m3({{15. + 6i, -1. + 2i,8. - 3i},
                                 { 1. + 2i,  1. + 3i,1. - 4i},
                                 { 1. + 3i,  1. + 4i,1. - 5i}});
    cout <<"m1 :\n"<< m1 << endl;
    std::cout << "^^^^^^^^^^^^^^^^" << std::endl;
    cout <<"m1 transposed :\n" <<m1.transposed() << endl;
    std::cout << "----------------" << std::endl;
    cout <<"m2 :\n" <<m2 << endl;
    std::cout << "^^^^^^^^^^^^^^^^" << std::endl;
    cout  <<"m2 transposed :\n" << m2.transposed() << endl;
    std::cout << "----------------" << std::endl;
    cout << "m3 :\n"<< m3 << endl;
    std::cout << "^^^^^^^^^^^^^^^^" << std::endl;
    cout << "m3 transposed :\n"<< m3.transposed() << endl;
    return 0;
}