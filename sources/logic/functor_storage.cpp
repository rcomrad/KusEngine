#include "functor_storage.hpp"

#include "core/program_state.hpp"

// lgc::FunctorStorage::Functor::Functor(const std::function<void(int)>& aFunc,
//                                       int aID) noexcept
//     : func(aFunc), id(aID)
// {
// }

// void
// lgc::FunctorStorage::Functor::operator()() noexcept
// {
//     func(id);
// }

lgc::FunctorStorage::FunctorStorage() noexcept
{
}

lgc::FunctorStorage&
lgc::FunctorStorage::getInstance() noexcept
{
    static FunctorStorage instance;
    return instance;
}

int
lgc::FunctorStorage::getFunctorID(const std::string& aStr) noexcept
{
    auto it = mFinctorIDs.find(aStr);
    if (it == mFinctorIDs.end())
    {
        // mFinctorIDs[aStr] = mFinctors.size();
        it = mFinctorIDs.insert({aStr, int(mFinctors.size())}).first;
        createFunctor(aStr);
    }
    return it->second;
}

// lgc::FunctorStorage::Functor
// lgc::FunctorStorage::getFunctor(int aID) const noexcept
// {
//     return {mFinctors[aID], aID};
// }

void
lgc::FunctorStorage::executeFunctor(int aID) const noexcept
{
    return mFinctors[aID](aID);
}

void
lgc::FunctorStorage::createFunctor(const std::string& aStr) noexcept
{
    static auto& programState = core::ProgramState::getInstance();

    if (aStr.front() == '~')
    {
        mStringStorage[mFinctors.size()] = aStr.substr(1, aStr.size());
        mFinctors.emplace_back([&](int aID)
                               { programState.reset(mStringStorage[aID]); });
    }
}

// int
// lgc::FinctorStorage::getClickID(const std::string& aStr) noexcept
// {
//     if (mClickIDs.find(aStr) == mClickIDs.end())
//     {
//         mClickIDs[aStr] = mClickFinctors.size();
//     }
//     return mClickIDs[aStr];
// }

// int
// lgc::FinctorStorage::getGazeID(const std::string& aStr) noexcept
// {
//     if (mGazeIDs.find(aStr) == mGazeIDs.end())
//     {
//         mGazeIDs[aStr] = mGazeFinctors.size();
//     }
//     return mGazeIDs[aStr];
// }

// int
// lgc::FinctorStorage::getUpdateID(const std::string& aStr) noexcept
// {
//     if (mUpdateIDs.find(aStr) == mUpdateIDs.end())
//     {
//         mUpdateIDs[aStr] = mUpdateFinctors.size();
//     }
//     return mUpdateIDs[aStr];
// }

// const std::function<void(std::string)>&
// lgc::FinctorStorage::getClickFinctor(int aID) const noexcept
// {
//     return mClickFinctors[aID];
// }

// const std::function<void(std::string)>&
// lgc::FinctorStorage::getGazeFinctor(int aID) const noexcept
// {
//     return mGazeFinctors[aID];
// }

// const std::function<void(std::string)>&
// lgc::FinctorStorage::getUpdateFinctor(int aID) const noexcept
// {
//     return mUpdateFinctors[aID];
// }
