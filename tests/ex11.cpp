#include "ft_mat.hpp"
#include <iostream>
#include "ft_vec.hpp"

int main() {
    ft::matrix<double> m1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    ft::matrix<double> m2({{2,0,0},{0,2,0},{0,0,2}});
    
    std::cout<< "m1 = "<< std::endl  << m1 << std::endl;
    std::cout<< "m2 = "<< std::endl  << m2 << std::endl;
    std::cout << "det(m1) = " << m1.det() << std::endl;
    std::cout << "det(m2) = " << m2.det() << std::endl;
    return 0;
}