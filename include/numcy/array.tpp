#include <iostream>

namespace numcy {
    template <typename T>
    bool nested_type<T>::is_list() {
        return type == nested_type<T>::Type::LIST;
    }

    template <typename T>
    bool nested_type<T>::is_value() {
        return type == nested_type<T>::Type::VALUE;
    }

    template <typename T>
    nested_type<T>::List nested_type<T>::get_list() {
        if(type != nested_type<T>::Type::LIST) {
            std::cout << "Not a list" << std::endl;
            exit(EXIT_FAILURE);
        }

        return list;
    }

    template <typename T>
    T nested_type<T>::get_value() {
        if(type != nested_type<T>::Type::VALUE) {
            std::cout << "Not a single value" << std::endl;
            exit(EXIT_FAILURE);
        }

        return value;
    }
};