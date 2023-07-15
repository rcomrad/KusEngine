#ifndef FUNCTOR_STORAGE_HPP
#define FUNCTOR_STORAGE_HPP

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace lgc
{
class FunctorStorage
{
private:
    // class Functor
    // {
    // public:
    //     Functor(const std::function<void(int)>& aFunc, int aID) noexcept;

    //     void operator()() noexcept;

    // private:
    //     const std::function<void(int)>& func;
    //     int id;
    // };

public:
    static FunctorStorage& getInstance() noexcept;

    int getFunctorID(const std::string& aStr) noexcept;
    // Functor getFunctor(int aID) const noexcept;
    void executeFunctor(int aID) const noexcept;

    // int getClickID(const std::string& aStr) noexcept;
    // int getGazeID(const std::string& aStr) noexcept;
    // int getUpdateID(const std::string& aStr) noexcept;

    // const std::function<void(std::string)>& getClickFinctor(
    //     int aID) const noexcept;
    // const std::function<void(std::string)>& getGazeFinctor(
    //     int aID) const noexcept;
    // const std::function<void(std::string)>& getUpdateFinctor(
    //     int aID) const noexcept;

private:
    FunctorStorage() noexcept;

    std::unordered_map<std::string, int> mFinctorIDs;
    std::vector<std::function<void(int)>> mFinctors;

    std::unordered_map<int, std::string> mStringStorage;

    void createFunctor(const std::string& aStr) noexcept;

    // std::unordered_map<std::string, int> mClickIDs;
    // std::unordered_map<std::string, int> mGazeIDs;
    // std::unordered_map<std::string, int> mUpdateIDs;

    // std::vector<std::function<void(std::string)>> mClickFinctors;
    // std::vector<std::function<void(std::string)>> mGazeFinctors;
    // std::vector<std::function<void(std::string)>> mUpdateFinctors;
};
} // namespace lgc

#endif // !FUNCTOR_STORAGE_HPP
