#include <iostream>

#include "mem.h"

int main() {
    std::array<char, 15> data{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    char bytes[] {3, 0, 5};
    bool mask[] {true, false, true};
    auto *p{scan_codestyle(&data, 15, bytes, mask, 3)};
    auto *q{scan_idastyle(&data, 15, "03 ? 05")};
    std::cout << &data << std::endl;
    std::cout << p << std::endl;
    std::cout << q << std::endl;

    return 0;
}