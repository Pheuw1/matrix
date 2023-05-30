#include "ft_mat.hpp"
#include <iostream>
#include "ft_vec.hpp"

int main() {
    ft::matrix<double> m1(3, 3);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m1[i][j] = i + j;
        }
    }
    std::cout  << "m = "<< std::endl  << m1 << std::endl;
    std::cout << "row_echanlon = " << std::endl << m1.row_echelon() << std::endl; 
    std::cout << "reduced row_echanlon = " << std::endl << m1.r_row_echelon() << std::endl; 
    return 0;
}