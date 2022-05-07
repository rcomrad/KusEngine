cmake_minimum_required(VERSION 3.21)

add_library(
    core

    "core.hpp"
    "core.cpp"

    "domain.hpp"
    "domain.cpp"

    "my_time.hpp"
    "my_time.cpp"

    "program_state.hpp"
    "program_state.cpp"
)