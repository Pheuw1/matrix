#include "ft_mat.hpp"
#include "ft_vec.hpp"
#include <iostream>
using namespace ft;

int main() {
  ft::matrix<double> m({{1, 2, 3}, 
                      {0, 10, -100},
                      {0, 0, 1}
                      });
  ft::vector<double> v({10, -2, 0.5});


  std::cout << "m : "<< m << std::endl;
  std::cout << "v : "<< v << std::endl;
  std::cout << "m * v" << m * v << std::endl;
  {
    ft::matrix<int> a(2, 3);
    int i = 1;
    for (auto it = a.begin(); it != a.end(); ++it)
    {
        *it = i;
        i++;
    }
    ft::matrix<int> b({
        {10 ,11 },
        {20 , 21},
        { 30,31 }
    });

    std::cout << " A :" << std::endl << a <<      std::endl;
    std::cout << " B :" << std::endl << b <<      std::endl;
    std::cout << " * :" << "\n" <<  b * a << std::endl;
  }

  return 0;
}