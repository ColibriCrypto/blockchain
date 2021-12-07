// Copyright (c) 2021 The CLBI Core developers
//      
//   

#ifndef CLBI_OPTIONAL_H
#define CLBI_OPTIONAL_H

#include <boost/optional.hpp>

//! Substitute for C++17 std::optional
template <typename T>
using Optional = boost::optional<T>;

//! Substitute for C++17 std::nullopt
static auto& nullopt = boost::none;

#endif // CLBI_OPTIONAL_H
