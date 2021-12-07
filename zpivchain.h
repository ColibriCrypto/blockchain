// Copyright (c)   2021     
//      
//   

#ifndef clbi_ZclbiCHAIN_H
#define clbi_ZclbiCHAIN_H

#include "chain.h"
#include "libzero / .h"
#include "libzero /Denominations.h"
#include "libzero / Spend.h"
#include <list>
#include <string>

class CBlock;
class CBlockIndex;
class CBigNum;
class CTransaction;
class CTxIn;
class CTxOut;
class CValidationState;
class uint256;

bool IsSerialInBlockchain(const CBigNum& bnSerial, int& nHeightTx);
libzero :: Spend TxInToZero Spend(const CTxIn& txin);
bool TxOutToPublic (const CTxOut& txout, libzero ::Public & pub , CValidationState& state);

#endif //clbi_ZclbiCHAIN_H
