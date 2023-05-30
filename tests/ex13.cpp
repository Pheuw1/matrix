#include "ft_mat.hpp"
#include <iostream>
#include "ft_vec.hpp"

int main() {
    ft::matrix<double> m1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    ft::matrix<double> m2({{2,0,0,1}, {0,2,0,1}});
    ft::matrix<int> i(4);
    
    std::cout<< "m1 = "<< std::endl  << m1 << std::endl;
    std::cout<< "m2 = "<< std::endl  << m2 << std::endl;
    std::cout<< "i = "<< std::endl  << i << std::endl;
    std::cout << "rank of m1 = " << m1.rank() << std::endl;
    std::cout << "rank of m2 = " << m2.rank() << std::endl;
    std::cout << "rank of i = " << i.rank() << std::endl;
    return 0;
}   