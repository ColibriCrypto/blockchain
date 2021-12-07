// Copyright (c) 2021     
//      
//   

#ifndef clbi_SPENDTYPE_H
#define clbi_SPENDTYPE_H

#include <cstdint>

namespace libzero  {
    enum SpendType : uint8_t {
        SPEND, // Used for a typical spend transaction, zclbi should be unusable after
        STAKE, // Used for a spend that occurs as a stake
        MN_COLLATERAL, // Used when proving ownership of zclbi that will be used for masternodes (future)
        SIGN_MESSAGE // Used to sign messages that do not belong above (future)
    };
}

#endif //clbi_SPENDTYPE_H
