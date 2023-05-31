#include "ft_mat.hpp"
#include <iostream>
using namespace std;

int main()
{
    int i = 0;
{   
    ft::matrix<int> a(2, 4);
    ft::matrix<int> b(2, 4);
    ft::vector<int> c;
    ft::vector<int> d;
    for (auto it = a.begin(); it != a.end(); ++it)
    {
        *it = i;
        i++;
    }
    for (auto it = b.rbegin(); it != b.rend(); ++it)
    {
        *it = i;
        i++;
    }
    cout << " A :" << endl << a << endl;
    cout << " B :" << endl << b << endl;
    cout << " + :" << "\n" << a + b << endl;
    cout << " - :" << "\n" << a - b << endl;
    cout << " * :" << "\n" << a * 2 << endl;
    c = a[1];
    d = b[0];
    cout << " C :" << endl << c << endl;
    cout << " D :" << endl << d << endl;
    cout << " + :" << "\n" << (c += d) << endl;
    cout << " - :" << "\n" << (c -= d) << endl;
    cout << " * :" << "\n" << (c * 2) << endl;
}
cout << "-----------------------------" << endl;

}
