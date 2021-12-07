// Copyright (c)  -    
// Copyright (c)  -2021 The CLBI Core developers
// Copyright (c) 2021     
//      
//   

#include "util/validation.h"

#include "consensus/validation.h"
#include "tinyformat.h"

/** Convert CValidationState to a human-readable message for logging */
std::string FormatStateMessage(const CValidationState& state)
{
    if (state.IsValid()) {
        return "Valid";
    }

    const std::string& debug_message = state.GetDebugMessage();
    if (!debug_message.empty()) {
        return strprintf("%s, %s", state.GetRejectReason(), debug_message);
    }

    return state.GetRejectReason();
}

const std::string strMessageMagic = "DarkNet Signed Message:\n";
