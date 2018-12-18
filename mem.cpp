//
// Created by Kevin on 12/18/2018.
//

#include "mem.h"

// Return first instance of the pattern found in the memory range [start, start + length]
void* scan_codestyle(void* start, uintptr_t length, char const *bytes, bool const *mask, std::size_t pat_len) {
    auto u_start{(uintptr_t)start};

    for (uintptr_t addr = u_start;
         addr + pat_len < u_start + length;
         addr++) {
        // Go through the pattern if it continues matching
        for (int i = 0; i <= pat_len; i++) {
            if (i == pat_len)
                return (void*)addr;

            if (mask[i] && *(char*)(addr + i) != bytes[i])
                break;
        }
    }

    return nullptr;
}

void* scan_idastyle(void* start, uintptr_t length, std::string const& pattern) {
    std::istringstream iss{pattern};
    std::string s;
    std::list<std::string> list;
    while (std::getline(iss, s, ' ')) {
        list.push_back(s);
    }

    auto bytes  = std::make_unique<char[]>(list.size());
    auto mask   = std::make_unique<bool[]>(list.size());

    int i{};
    for (auto const &l : list) {
        if (l == "?") {
            // bytes doesn't matter if mask is false
            mask[i] = false;
        }
        else if (l.length() == 2) {
            auto char1 = toupper(l[0]),
                char2 = toupper(l[1]);

            // Todo: Make this into a function
            int nibble_a = (char1 >= '0' && char1 <= '9') ? char1 - '0'
                    : (char1 >= 'A' && char1 <= 'F') ? 0xA + (char1 - 'A')
                    : 1337;
            int nibble_b = (char2 >= '0' && char2 <= '9') ? char2 - '0'
                    : (char2 >= 'A' && char2 <= 'F') ? 0xA + (char2 - 'A')
                    : 1337;

            if (nibble_a == 1337 || nibble_b == 1337)
                throw std::invalid_argument("Invalid IDA pattern");

            char byte = ((char)nibble_a << 4) | (char)nibble_b;

            bytes[i] = byte;
            mask[i] = true;
        }
        else {
            throw std::invalid_argument("Invalid IDA pattern");
        }

        i++;
    }

    return scan_codestyle(start, length, bytes.get(), mask.get(), list.size());
}