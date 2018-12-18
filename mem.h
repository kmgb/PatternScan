//
// Created by Kevin on 12/17/2018.
//

#ifndef PATTERNSCAN_MEM_H
#define PATTERNSCAN_MEM_H

#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <list>
#include <memory>
#include <stdexcept>

void* scan_codestyle(
        void* start,
        uintptr_t length,
        char const *bytes,
        bool const *mask,
        std::size_t pat_len);

void* scan_idastyle(void* start, uintptr_t length, std::string const& pattern);

#endif //PATTERNSCAN_MEM_H
