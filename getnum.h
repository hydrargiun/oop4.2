

#ifndef MAIN_CPP_GETNUM_H
#define MAIN_CPP_GETNUM_H
#include <iostream>

namespace oop4 {
    template<typename T>
    T getNum() {
        T num = 0;
        while (!(std::cin >> num)) {
            std::cout << "Try again: ";
            if (std::cin.eof()) {
                break;
            }
            std::cin.clear();
            std::cin.ignore();
        }
        return num;
    }
}
#endif //MAIN_CPP_GETNUM_H
