#ifndef KUS_FILE_HPP
#define KUS_FILE_HPP

//--------------------------------------------------------------------------------

#include <array>
#include <string>
#include <vector>

//--------------------------------------------------------------------------------

namespace file
{

class File
{
private:
    static bool isSeparator(char c) noexcept;
    // static bool isSeparator(char c) noexcept;

public:
    static std::string getAllData(const std::string& aFileName,
                                  bool aIsCritical = false) noexcept;
    static std::vector<std::string> getLines(const std::string& aFileName,
                                             bool aIsCritical = false) noexcept;
    static std::vector<std::vector<std::string>> getWords(
        const std::string& aFileName,
        bool aIsCritical = false,
        decltype(&file::File::isSeparator) funk =
            &file::File::isSeparator) noexcept;

    static std::vector<std::array<std::string, 2>> getMap(
        const std::string& aFileName, bool aIsCritical = false) noexcept;

    // static std::string writeData(const std::string& aFolderName,
    //                              const std::string& aFileName,
    //                              const std::string& aData) noexcept;
};

} // namespace file

//--------------------------------------------------------------------------------

#endif // !KUS_FILE_HPP
