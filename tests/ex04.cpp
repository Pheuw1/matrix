// let u = Vector::from([0., 0., 0.]);
// println!("{}, {}, {}, {}", u.norm_1(), u.norm(), u.norm_inf());
// // 0.0, 0.0, 0.0
// let u = Vector::from([1., 2., 3.]);
// println!("{}, {}, {}, {}", u.norm_1(), u.norm(), u.norm_inf());
// // 6.0, 3.74165738, 3.0
// let u = Vector::from([-1., -2.]);
// println!("{}, {}, {}, {}", u.norm_1(), u.norm(), u.norm_inf());
// // 3.0, 2.236067977, 2.0

#include "ft_mat.hpp"
#include "ft_vec.hpp"
#include <iostream>

using namespace ft;
int main() {
    ft::vector<double> v({0,0,0});
    ft::vector<double>  v1({1, 2, 3});
    ft::vector<double>  v2({-1, -2});

    std::cout << "v : " << v <<      std::endl;
    std::cout << "v1 : " << v1 <<      std::endl;
    std::cout << "v2 : " << v2 <<      std::endl;
    
    std::cout << "norm(v) | norm_1(v) | norm_inf(v)" << std::endl;
    std::cout << norm(v) << "|" << norm_1(v) << "|" << norm_inf(v) << std::endl;
    std::cout << norm(v1)<< "|" << norm_1(v1) << "|" << norm_inf(v1) << std::endl;
    std::cout << norm(v2)<< "|" << norm_1(v2) << "|" << norm_inf(v2) << std::endl;
    return 0;
}