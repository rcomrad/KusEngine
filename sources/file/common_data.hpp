#ifndef COMMON_DATA_HPP
#define COMMON_DATA_HPP

#include <boost/optional.hpp>

#include <optional>
#include <string>
#include <unordered_map>

#include "variable.hpp"

namespace file
{

class CommonData
{
public:
    static const CommonData& getInstance() noexcept;

    boost::optional<const file::VariableArray&> getData(
        const std::string& aObjectLabel,
        const std::string& aObjectName) const noexcept;

    void addData(const std::string& aObjectLabel,
                 const std::string& aObjectName,
                 file::VariableArray& Variables) const noexcept;

private:
    CommonData() noexcept;

    std::unordered_map<std::string,
                       std::unordered_map<std::string, file::VariableArray>>
        mCommonStorage;
};

} // namespace file

#endif // !COMMON_DATA_HPP
