// Copyright (c) 2021 The CLBI Core developers
//      
//   

#ifndef CLBI_UTIL_STRING_H
#define CLBI_UTIL_STRING_H

#include "attributes.h"

#include <algorithm>
#include <array>
#include <cstring>
#include <functional>
#include <string>
#include <vector>

/**
 * Join a list of items
 *
 * @param list       The list to join
 * @param separator  The separator
 * @param unary_op   Apply this operator to each item in the list
 */
template <typename T, typename UnaryOp>
std::string Join(const std::vector<T>& list, const std::string& separator, UnaryOp unary_op)
{
    std::string ret;
    for (size_t i = 0; i < list.size(); ++i) {
        if (i > 0) ret += separator;
        ret += unary_op(list.at(i));
    }
    return ret;
}

inline std::string Join(const std::vector<std::string>& list, const std::string& separator)
{
    return Join(list, separator, [](const std::string& i) { return i; });
}

/**
 * Check if a string does not contain any embedded NUL (\0) characters
 */
inline bool ValidAsCString(const std::string& str) noexcept
{
    return str.size() == strlen(str.c_str());
}

/**
 * Check whether a container begins with the given prefix.
 */
template <typename T1, size_t PREFIX_LEN>
NODISCARD inline bool HasPrefix(const T1& obj,
                                const std::array<uint8_t, PREFIX_LEN>& prefix)
{
    return obj.size() >= PREFIX_LEN &&
           std::equal(std::begin(prefix), std::end(prefix), std::begin(obj));
}

#endif // CLBI_UTIL_STRENCODINGS_H
