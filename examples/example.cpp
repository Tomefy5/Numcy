#include <iostream>
#include "numcy.hpp"
#include <vector>

using namespace std;

int main() {
    numcy::array<float> arr({{-1, 0.5}, {0.25, -2}});
    print(arr);
    // cout << arr(0) << endl;

    auto result = numcy::exp(arr);
    print(result);
    return 0;
}
