#include "ft_mat.hpp"
#include "ft_vec.hpp"
#include <iostream>
using namespace ft;

int main() {
    vector<int>  v1({1, 2, 3});
    vector<int>  v2({4, 5, 6});

    std::cout << "v1 : "<< v1 << std::endl;
    std::cout << "v2 : "<< v2 << std::endl;
    std::cout << "v1 . v2 : " << dot(v1, v2) << std::endl;
}