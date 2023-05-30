#include "ft_mat.hpp"
#include "ft_vec.hpp"
#include <iostream>

using namespace ft;
int main() {
    {
        vector<double>  v1({1, 0});
        vector<double>  v2({0.5, 0.5});
        std::cout << "v1 : "<< v1 << std::endl;
        std::cout << "v2 : "<< v2 << std::endl;
        std::cout << "cosing of angle between v1 and v2 :" << angle_cos(v1, v2) << std::endl;
        
    }
    {
        vector<double>  v1({1, 2, 3});
        vector<double>  v2({4, 5, 6});
        std::cout << "v1 : "<< v1 << std::endl;
        std::cout << "v2 : "<< v2 << std::endl;
        std::cout << "cosing of angle between v1 and v2 :" << angle_cos(v1, v2) << std::endl;
    }
    return 0;
}