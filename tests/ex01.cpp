#include "ft_mat.hpp"
#include "ft_vec.hpp"
#include <iostream>
using namespace std;

int main() {
    // ft::vector<ft::vector<int>> v({{{1, 2, 3}, {4, 5, 6}}});
{
    ft::matrix<double> m({{1, 0, 0}, 
                        {0, 1, 0},
                        {0, 0, 1}
                        });
    ft::vector<double> v({10, -2, 0.5});
    cout << "m : \n"<< m << endl;
    cout << "v : "<< v << endl;
    cout << "linear combination of m and v : " << linear_combination(m.to_vecs(), v) << endl;
  }
    cout << "-----------------------------" << endl;
  {  
    ft::matrix<double> m({{1, 2, 3}, 
                        {0, 10, -100}
                        });
    ft::vector<double> v({10, -2});
    cout << "m : \n"<< m << endl;
    cout << "v : "<< v << endl;
    cout << "linear combination of m and v " << linear_combination(m.to_vecs(), v) << endl;
    return 0;
}
}