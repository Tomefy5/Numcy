#include <iostream>
#include "numcy.hpp"
#include <vector>

using namespace std;

template <typename... Args>
void test(Args... args) {
    vector<int> vec;
    (vec.push_back(args), ...);
    for(auto el : vec) {
        cout << "El: " << el << endl;
    }
} 

int main() {
    numcy::nested_type<float> nt({1, 2, 3, 2, 3, 1, 4});
    std::cout << nt.is_list() << std::endl;
    std::cout << nt.is_value() << std::endl;

    if(nt.is_value()) {
        std::cout << "Value: " << nt.get_value() << std::endl;
    }

    numcy::array<float> ar({
        {2,7}, 
        {9,0}});
    ar.determinate_shape(2.3312321);
    for(auto i = 0; i < ar.shape_.size(); i++) {
        cout << "Shape[" << i << "] = " << ar.shape_[i] << endl; 
    }

    print(ar);
    cout << "Dim: " << ar.ndim << endl;
    cout << "Size: " << ar.size << endl;

    test(2,3,4);

    for(auto el: ar.strides_) {
        cout << "Pas: " << el << endl;
    }

    cout << ar(0,1) << endl;

    std::vector<size_t> shape = {1, 2};
    numcy::array<double> tab = numcy::fill_with_number<double>({3, 3}, 2);

    print(tab);

    numcy::array<float> tab_zero = numcy::zeros({3, 3});
    print(tab_zero);

    numcy::array<float> tab_one = numcy::ones({3, 3});
    print(tab_one);

    cout << "Sum: " << numcy::sum(tab) << endl;

    return 0;
}
