#include "ft_mat.hpp"
#include <iostream>

using namespace std;


int main() {
    ft::matrix<int> m1({{5,5,6},
                        {5,5,7},
                        {5,5,8}});
    ft::matrix<int> m2({{5,5,8},
                        {5,5,7},
                        {5,5,6}});
    
    cout <<"m1 : \n" << m1 << endl;
    cout <<"m2 : \n" << m2 << endl;
    cout << "trace of m1 :"<< m1.trace() << endl;
    cout << "trace of m2 :"<< m2.trace() << endl;
    return 0;
}