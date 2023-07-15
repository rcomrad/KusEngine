#include "functors.hpp"

lgc::FinctorStorage::FinctorStorage() noexcept
{
}

lgc::FinctorStorage&
lgc::FinctorStorage::getInstance() noexcept
{
    static FinctorStorage instance;
    return instance;
}

int
lgc::FinctorStorage::getClickID(const std::string& aStr) noexcept
{
    if (mClickIDs.find(aStr) == mClickIDs.end())
    {
        mClickIDs[aStr] = mClickFinctors.size();
    }
}

int
lgc::FinctorStorage::getGazeID(const std::string& aStr) noexcept
{
    if (mGazeIDs.find(aStr) == mGazeIDs.end())
    {
        mGazeIDs[aStr] = mGazeFinctors.size();
    }
}

int
lgc::FinctorStorage::getUpdateID(const std::string& aStr) noexcept
{
    if (mUpdateIDs.find(aStr) == mUpdateIDs.end())
    {
        mUpdateIDs[aStr] = mUpdateFinctors.size();
    }
}

const std::function<void(std::string)>&
lgc::FinctorStorage::getClickFinctor(int aID) const noexcept
{
    return mClickFinctors[aID];
}

const std::function<void(std::string)>&
lgc::FinctorStorage::getGazeFinctor(int aID) const noexcept
{
    return mGazeFinctors[aID];
}

const std::function<void(std::string)>&
lgc::FinctorStorage::getUpdateFinctor(int aID) const noexcept
{
    return mUpdateFinctors[aID];
}
