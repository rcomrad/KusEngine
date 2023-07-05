#include <iostream>

#include "core.hpp"

//--------------------------------------------------------------------------------

int
main(int argc, char* argv[])
{
    std::cout << "LAMPA\n";

    core::Core app;
    app.run();

    return 0;
}

//--------------------------------------------------------------------------------
