#include <iostream>
#include "numcy.hpp"


using namespace std;

int main() {
    numcy::nested_type<float> nt(23);
    cout << nt.is_list() << endl;
    cout << nt.is_value() << endl;

    if(nt.is_value()) {
        cout << "Value: " << nt.get_value() << endl;
    }
    return 0;
}