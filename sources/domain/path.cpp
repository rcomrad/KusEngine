#include "path.hpp"

str_const_ref
dom::MainPath::getPath()
{
    static str_val path = getMainPath();
    return path;
}

str_val
dom::MainPath::getMainPath()
{
#if     defined(BILL_WINDOWS)
    CHAR buffer[MAX_PATH] = { 0 };
    uint_8 size = GetModuleFileNameA(NULL, buffer, MAX_PATH);
    for (int i = 0; i < 2; ++i) while (buffer[--size] != L'\\');
    buffer[size + 1] = 0;
    //return std::string(buffer).substr(0, size + 1);
    return getString(buffer);
#elif   defined(LINUS_LINUX)
    char buf[PATH_MAX + 1];
    if (readlink("/proc/self/exe", buf, sizeof(buf) - 1) == -1)
        throw std::string("readlink() failed");
    std::string str(buf);
    int i = str.size() - 1;
    for (int j = 0; j < 1; --i)
    {
        if (str[i] == '/') ++j;
    }
    return str.substr(0, i + 2);
    //return str.substr(0, str.rfind('/'));
#else
    return "";
#endif
}