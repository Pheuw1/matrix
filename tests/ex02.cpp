#include "ft_mat.hpp"
#include "ft_vec.hpp"
#include <iostream>

template <class T>
T linear_interpolation(T lhs, T rhs, double t) {
      return lhs + (rhs - lhs) * t;
}

int main() {
  {
    ft::matrix<double> m({{1, 0, 0}, 
                        {0, 1, 0},
                        {0, 0, 1}
                        });

    ft::matrix<double> n({{1, 2, 3}, 
                        {0, 10, -100},
                        {0, 0, 1}
                        });
    
    std::cout << "m : \n"<< m << std::endl;
    std::cout << "n : \n"<< n << std::endl;
    for (double t = 0; t <= 1; t += 0.2) {
        auto tmp = linear_interpolation(m, n, t);
        std::cout << "t = " << t << std::endl;
        std::cout << tmp << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
}
  {  
    ft::vector<double> v({1, -2, 15});
    ft::vector<double> w({10, -2, 0.5});
      std::cout << "v : "<< v << std::endl;
    std::cout << "w : "<< w << std::endl;
      for (double t = 0; t <= 1; t += 0.2) {
        auto tmp = linear_interpolation(v, w, t);
        std::cout << "t = " << t << std::endl;
        std::cout << tmp << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
  
  }
}