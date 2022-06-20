//
// Created by Kevin on 12/17/2018.
//

#ifndef PATTERNSCAN_MEM_H
#define PATTERNSCAN_MEM_H

#include <iostream>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <vector>

void* scan_codestyle(
        void* start,
        uintptr_t length,
        uint8_t const *bytes,
        bool const *mask,
        std::size_t pat_len);

void* scan_idastyle(void* start, uintptr_t length, std::string const& pattern);

#endif //PATTERNSCAN_MEM_H
