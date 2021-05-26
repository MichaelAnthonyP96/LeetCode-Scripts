//
// Created by Michael Anthony Pope on 4/24/21.
//

#include <string>

namespace predicates
{
    /**
     * \brief Lambda function which compares size() values for classes which satisfy that API
     */
    auto less_by_size = [](const auto& a, const auto& b) {
        return a.size() < b.size();
    };

    /**
     * \brief Lambda function which determines equality for classes which satisfy a size() API
     * (most of the STL)
     */
    auto equal_by_size = [](auto size) {
        return [size](const auto& v) {
            return size == v.size();
        };
    };

    /**
     * \brief String based lambda function which compares strings case insensitively
     */
    auto equal_case_insensitive=[](const std::string& needle){
        return [&needle](const std::string& s){
            if(needle.size() != s.size())
                return false;
            auto eq_lower = [](char a, char b){
                return std::tolower(a)==std::tolower(b);
            };
            return std::equal(s.begin(), s.end(), needle.begin(), eq_lower);
        };
    };

}