#include "ft_mat.hpp"
#include "ft_vec.hpp"

using namespace ft;
int main() {
    //take the cross product of two vectors
    vector<int>  v1({1, 2, 3});
    vector<int>  v2({4, 5, 6});
    std::cout << "v1 : " << v1 << std::endl;
    std::cout << "v2 : " << v2 << std::endl;
    std::cout << "v1 x v2" << cross(v1, v2) << std::endl;
    return 0;
}