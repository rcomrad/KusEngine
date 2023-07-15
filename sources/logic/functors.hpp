#ifndef FUNCTORS_HPP
#define FUNCTORS_HPP

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace lgc
{
class FinctorStorage
{
public:
    static FinctorStorage& getInstance() noexcept;

    int getClickID(const std::string& aStr) noexcept;
    int getGazeID(const std::string& aStr) noexcept;
    int getUpdateID(const std::string& aStr) noexcept;

    const std::function<void(std::string)>& getClickFinctor(
        int aID) const noexcept;
    const std::function<void(std::string)>& getGazeFinctor(
        int aID) const noexcept;
    const std::function<void(std::string)>& getUpdateFinctor(
        int aID) const noexcept;

private:
    FinctorStorage() noexcept;

    std::unordered_map<std::string, int> mClickIDs;
    std::unordered_map<std::string, int> mGazeIDs;
    std::unordered_map<std::string, int> mUpdateIDs;

    std::vector<std::function<void(std::string)>> mClickFinctors;
    std::vector<std::function<void(std::string)>> mGazeFinctors;
    std::vector<std::function<void(std::string)>> mUpdateFinctors;
};
} // namespace lgc

#endif // !FUNCTORS_HPP
