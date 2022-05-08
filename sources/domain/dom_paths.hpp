#ifndef DOM_PATHS_HPP
#define DOM_PATHS_HPP

#include <fstream>

#include "domain/dom_flags.hpp"
#include "domain/dom_type.hpp"
#include "domain/dom_string.hpp"

#if     defined(BILL_WINDOWS)
    #include <windows.h>
#elif   defined(LINUS_LINUX)
    #include <unistd.h>
    #include <limits.h>
#endif

#if     defined(BILL_WINDOWS)
    #define MAIN_PATH       dom::MainPath::getPath()
    #define RESOURCES       MAIN_PATH   + "resources\\"s
    #define OUTPUT_PATH     RESOURCES   + "output\\"s
    #define LOGS_PATH       RESOURCES   + "logs\\"s
    #define ERRORS_PATH     RESOURCES   + "errors\\"s
// !BILL_WINDOWS
#elif   defined(LINUS_LINUX)
    #define MAIN_PATH       dom::MainPath::getPath()
    #define RESOURCES       MAIN_PATH   + "resources/"s
    #define OUTPUT_PATH     RESOURCES   + "output/"s
    #define LOGS_PATH       RESOURCES   + "logs/"s
    #define ERRORS_PATH     WORK_DIR    + "errors/"s
// !LINUS_LINUX
#else   // NUN
    #define MAIN_PATH       ""s
    #define RESOURCES       ""s
    #define OUTPUT_PATH     ""s
    #define LOGS_PATH       ""s
    #define LOGS_PATH       ""s
// !NUN
#endif

namespace dom
{
    class MainPath
    {
    public:
        static str_const_ref getPath();
    private:
        static str_val getMainPath();
    };
}




#endif // !DOM_PATHS_HPP