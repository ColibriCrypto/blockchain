// Copyright (c)  -    
// Copyright (c)  -2021 The CLBI Core developers
// Copyright (c) 2021     
//      
//   

#ifndef clbi_WALLET_FEES_H
#define clbi_WALLET_FEES_H

#include "amount.h"

class CTxMemPool;

/**
 * Return the minimum required fee taking into account the
 * floating relay fee and user set minimum transaction fee
 */
CAmount GetRequiredFee(unsigned int nTxBytes);

/**
 * Estimate the minimum fee considering user set parameters
 * and the required fee
 */
CAmount GetMinimumFee(unsigned int nTxBytes, unsigned int nConfirmTarget, const CTxMemPool& pool);


#endif // clbi_WALLET_FEES_H
