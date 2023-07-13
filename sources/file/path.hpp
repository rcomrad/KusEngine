#ifndef KUS_PATHS_HPP
#define KUS_PATHS_HPP

//--------------------------------------------------------------------------------

#include <filesystem>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

namespace file
{
class Path
{
public:
    static Path& getInstance() noexcept;

    std::optional<std::string> getPath(const std::string& aName) noexcept;
    void setPath(const std::string& aName, const std::string& aPath) noexcept;
    void setDefault(const std::string& aPath) noexcept;

    static std::vector<std::string> getAllContentPaths(
        const std::string& aPath) noexcept;
    static std::unordered_map<std::string, std::string> getAllContentPathsMap(
        const std::string& aPath) noexcept;

    // std::string getMainPath() noexcept;
    // std::string getExecutablePath() noexcept;

private:
    Path() noexcept;

    void reset() noexcept;

    std::string getMainPathOnce() noexcept;
    std::string getExecutablePathOnce() noexcept;

    std::unordered_map<std::string, std::string> mPaths;
};
} // namespace file

//--------------------------------------------------------------------------------

#endif // !KUS_PATHS_HPP
