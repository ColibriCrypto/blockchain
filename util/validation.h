// Copyright (c)  -    
// Copyright (c)  -2021 The CLBI Core developers
// Copyright (c) 2021     
//      
//   

#ifndef clbi_UTIL_VALIDATION_H
#define clbi_UTIL_VALIDATION_H

#include <string>

class CValidationState;

/** Convert CValidationState to a human-readable message for logging */
std::string FormatStateMessage(const CValidationState& state);

extern const std::string strMessageMagic;

#endif // clbi_UTIL_VALIDATION_H
