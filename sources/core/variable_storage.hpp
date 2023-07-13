#ifndef VARIABLE_STORAGE_HPP
#define VARIABLE_STORAGE_HPP

//--------------------------------------------------------------------------------

#include <mutex>
#include <queue>
#include <string>
#include <unordered_map>

//--------------------------------------------------------------------------------

namespace core
{
class VariableStorage
{
public:
    static VariableStorage& getInstance();

    bool checkFlag(const std::string& aName,
                   bool aDefault = false) const noexcept;
    int getInt(const std::string& aName, int aDefault = 0) const noexcept;
    std::string getWord(const std::string& aName,
                        std::string aDefault = "") const noexcept;

private:
    VariableStorage();
    void reloadSettings() noexcept;

    // int valueSetter(const std::string& s) noexcept;
    std::unordered_map<std::string, int> mInts;

    // bool turnOnOff(const std::string& s) noexcept;
    std::unordered_map<std::string, bool> mFlags;

    std::unordered_map<std::string, std::string> mWords;
};
} // namespace core

//--------------------------------------------------------------------------------

#endif // !VARIABLE_STORAGE_HPP
