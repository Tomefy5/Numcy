#include <iostream>
#include "numcy.hpp"

using namespace std;

int main() {
    numcy::nested_type<float> nt({1, 2, 3, 2, 3, 1, 4});
    std::cout << nt.is_list() << std::endl;
    std::cout << nt.is_value() << std::endl;

    if(nt.is_value()) {
        std::cout << "Value: " << nt.get_value() << std::endl;
    }

    numcy::array<float> ar({{1, 2, 3}, {1, 2, 3}});
    ar.determinate_shape(2.3312321);
    for(auto i = 0; i < ar.shape_.size(); i++) {
        cout << "Shape[" << i << "] = " << ar.shape_[i] << endl; 
    }
   cout << ar << endl;

    return 0;
}
