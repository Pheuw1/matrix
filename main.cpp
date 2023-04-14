#include "ft_mat.hpp"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ft::Matrix<int> a(5, 4);
    int i = 0;
    for (ft::Matrix<int>::iterator it = a.begin(); it != a.end(); ++it) {
        *it = i;
        i++;
    }
    cout << a << endl;
    return 0;
}

// In the main file of the Matrix class, add the following lines:
// #include <bits/stdc++.h>
// using namespace std;
// 
// //Create tests for the Matrix class and compare output with math library
// 
// int main()
// {
//     ft::Matrix<int> a(5, 4);
//     int i = 0;
//     for (ft::Matrix<int>::iterator it = a.begin(); it != a.end(); ++it)
//     {
//         *it = i;
//         i++;
//     }
//     for (ft::Matrix<int>::iterator it = a.begin(); it != a.end(); ++it)
//     {
//         cout << *it << endl;
//     }
//     return 0;
// }

// In the main file of the Matrix class, add the following lines:
#include <bits/stdc++.h>
using namespace std;

//Create tests for the Matrix class and compare output with math library
