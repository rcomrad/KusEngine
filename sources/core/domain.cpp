// #include "core/domain.hpp"

// // #ifdef BILL_WINDOWS
// // #include <windows.h>
// // #endif

// // std::string 
// // getMainPath() {
// // #ifdef BILL_WINDOWS
// //     CHAR buffer[MAX_PATH] = { 0 };
// //     uint_8 size = GetModuleFileNameA(NULL, buffer, MAX_PATH);
// //     for (int i = 0; i < 2; ++i) while (buffer[--size] != L'\\');
// //     return std::string(buffer).substr(0, size + 1);
// // #endif
// // #ifdef LINUS_LINUX
// //     char buf[PATH_MAX + 1];
// //     if (readlink("/proc/self/exe", buf, sizeof(buf) - 1) == -1)
// //         throw std::string("readlink() failed");
// //     std::string str(buf);
// //     int i = str.size() - 1;
// //     for(int j = 0; j < 2; --i)
// //     {
// //         if (str[i] == '/') ++j;
// //     }
// //     return str.substr(0, i + 2);
// //     //return str.substr(0, str.rfind('/'));
// // #endif
// // }

// double
// sr::cos(double aParametr)
// {
//     return std::cos(aParametr * PI / 180.);
// }

// double
// sr::sin(double aParametr)
// {
//     return std::sin(aParametr * PI / 180.);
// }