cmake_minimum_required(VERSION 3.21)

add_library(
    gui

    "background.cpp"
    "background.hpp"

    "drawable_and_writable.cpp"
    "drawable_and_writable.hpp"

    "drawable.cpp"
    "drawable.hpp"

    "gui_output_base.cpp"
    "gui_output_base.hpp"

    "gui.cpp"
    "gui.hpp"

    "window.cpp"
    "window.hpp"

    "writable.cpp"
    "writable.hpp"
)

