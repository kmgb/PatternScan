#include <iostream>

#include "mem.h"

int main() {
    // The data we are scanning
    uint8_t data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    uint8_t bytes[] = {3, 0, 5};
    bool mask[] = {true, false, true};
    void *a = scan_codestyle(&data, sizeof(data), bytes, mask, sizeof(bytes));

    char *ida_pattern = "03 ?  05 ?? 07 08 ? ? ? ? 0d 0E";
    void *b = scan_idastyle(&data, sizeof(data), ida_pattern);

    std::cout << "Data base address: " << &data << std::endl;
    std::cout << "Found A at: " << a << std::endl;
    std::cout << "Found B at: " << b << std::endl;

    return 0;
}
