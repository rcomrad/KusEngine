#ifndef FILES_MANAGER_HPP
#define FILES_MANAGER_HPP

#include <fstream>
#include <vector>

#include "domain/dom_flags.hpp"

#include "domain/dom_type.hpp"
#include "domain/dom_string.hpp"
#include "domain/dom_error_message.hpp"

namespace dom
{
    void copyFile(str_const_ref aFromFileName, str_const_ref aToFileName);

    class File
    {
    public:
        File(str_const_ref aFileName);
        ~File();

        void write(const std::vector<std::string>& aMessage);
        template<typename... Args>
        void write(Args... args)
        {
            (void) std::initializer_list<bool>
            {
                static_cast<bool>(mOut << args << mDelimiter)...
            };
            mOut << '\n';
        }

        void setDelimiter(str_const_ref aDelimiter);
        void writeEndl();

        void close();

    private:
        std::ofstream mOut;
        str_val mDelimiter;
    };
} // namespace dom

#endif // !FILES_MANAGER_HPP