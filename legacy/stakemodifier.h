// Copyright (c)        The PP  developers
// Copyright (c)  - 2021 The Nova  Developers
// Copyright (c)    2021 The Black  Developers
// Copyright (c)   2021     
// Distributed under the MIT/X11 software license, see the accompanying
//   

#ifndef clbi_LEGACY_MODIFIER_H
#define clbi_LEGACY_MODIFIER_H

#include "chain.h"
#include "stakeinput.h"

// Old Modifier - Only for IBD
bool GetOldStakeModifier(CStakeInput* stake, uint64_t& nStakeModifier);
bool ComputeNextStakeModifier(const CBlockIndex* pindexPrev, uint64_t& nStakeModifier, bool& fGeneratedStakeModifier);

#endif // clbi_LEGACY_MODIFIER_H
