#include <iostream>
#include "numcy.hpp"

using namespace std;
using namespace numcy;

int main() {
    // Initialisation d'un tableau ndarray
    numcy::array<float> arr({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}, 
    });

    // afficher ndarray
    print("Voici le tableau ndarray: \n\n");
    print(arr);

    print("\nshape: ");
    print(arr.shape_);

    print("strides: ");
    print(arr.strides_);

    print("ndim: ", arr.ndim);
    print("size: ", arr.size);
    print("dtype: ", arr.dtype);

    //flatten
    std::vector<float> flattened = arr.flatten();
    cout << "\nFlattened: ";
    print(flattened);

    //indexing
    print("\nElement à l'index [0, 1]: " , arr(1, 1));

    print("\n===========================================================================\n");

    // maths
    print("\n");
    print("Puissance: \n");
    print(numcy::pow(arr, 3)); // puissance de 3
    print("\nRacine carrée: \n");
    print(numcy::sqrt(arr)); 
    print("\nCarrée: \n");
    print(numcy::square(arr));

    print("\n===========================================================================\n");
    print("\nTableau trigo: \n");

    numcy::array<float> arr_trigo({
        {1, 0.5},
        {0.25, 0.75} 
    });

    print(arr_trigo);
    
    // Trigo
    print("\nCosinus: \n");
    print(numcy::cos(arr_trigo)); 
    print("\nSinus: \n");
    print(numcy::sin(arr_trigo)); 
    print("\nTangente: \n");
    print(numcy::tan(arr_trigo)); 

    print("\n===========================================================================\n");
    print("Expo, log , Abs: \n");
    print("\nExponentiel: \n");
    print(numcy::exp(arr));
    print("\nLogarithme: \n");
    print(numcy::log(arr));
    print("\nVal Absolue: \n");
    print(numcy::abs(arr));
    
    print("\n===========================================================================\n");
    print("Round functions: \n");

    numcy::array<float> arr_round({
        {1.12, 2.56, 3.13},
        {4.45, 5.14, 6.89},
        {7.77, 8.20, 9.74}, 
    });

    print(arr_round);

    print("\nRound: \n");
    print(numcy::round(arr_round));
    print("\nFloor: \n");
    print(numcy::floor(arr_round));
    print("\nCeil: \n");
    print(numcy::ceil(arr_round));


    print("\n===========================================================================\n");
    print("Statistiques: \n");

    numcy::array<float> arr_stat({
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}, 
    });

    print(arr_stat);

    print("\nSum: ", numcy::sum(arr_stat));
    print("Mean: ", numcy::mean(arr_stat));
    print("Max: ", numcy::max(arr_stat));
    print("Min: ", numcy::min(arr_stat));
    print("Argmax: ", numcy::argmax(arr_stat));
    print("Argmin: ", numcy::argmin(arr_stat));
    print("Variance: ", numcy::var(arr_stat));
    print("Ecart-type: ", numcy::std(arr_stat), "\n");

    print("\n===========================================================================\n");
    print("Random: \n");
    std::vector<size_t> shape = {2, 3};
    print("\nInitialisation avec rand: \n");
    numcy::array<float> rand_arr = numcy::random::rand(shape);
    print(rand_arr);

    print("\nInitialisation avec randn: \n");
    numcy::array<float> randn_arr = numcy::random::randn(shape);
    print(randn_arr);

    print("\nInitialisation avec randint: \n");
    numcy::array<float> randint_arr = numcy::random::randint(45, 100, shape);
    print(randint_arr);

    return 0;
}

