// Copyright (c)   2021     
//      
//   

#include "zclbichain.h"

#include "guiinterface.h"
#include "invalid.h"
#include "txdb.h"
#include "wallet/wallet.h"
#include "zclbi/zclbimodule.h"

// 6 comes from OPCODE (1) + vch.size() (1) + BIGNUM size (4)
#define SCRIPT_OFFSET 6

static bool IsTransactionInChain(const uint256& txId, int& nHeightTx, CTransactionRef& tx)
{
    uint256 hashBlock;
    if (!GetTransaction(txId, tx, hashBlock, true))
        return false;

    if (hashBlock.IsNull() || !mapBlockIndex.count(hashBlock)) {
        return false;
    }

    CBlockIndex* pindex = mapBlockIndex[hashBlock];
    if (!chainActive.Contains(pindex)) {
        return false;
    }

    nHeightTx = pindex->nHeight;
    return true;
}

static bool IsTransactionInChain(const uint256& txId, int& nHeightTx)
{
    CTransactionRef tx;
    return IsTransactionInChain(txId, nHeightTx, tx);
}

bool IsSerialInBlockchain(const CBigNum& bnSerial, int& nHeightTx)
{
    uint256 txHash;
    // if not in zero DB then its not in the blockchain
    if (!zero DB->Read Spend(bnSerial, txHash))
        return false;

    return IsTransactionInChain(txHash, nHeightTx);
}

libzero :: Spend TxInToZero Spend(const CTxIn& txin)
{
    CDataStream serialized Spend = ZclbiModule::ScriptSigToSerializedSpend(txin.scriptSig);
    return libzero :: Spend(serialized Spend);
}

bool TxOutToPublic (const CTxOut& txout, libzero ::Public & pub , CValidationState& state)
{
    CBigNum publicZero ;
    std::vector<unsigned char> vchZeroMint;
    vchZeroMint.insert(vchZeroMint.end(), txout.scriptPubKey.begin() + SCRIPT_OFFSET,
                       txout.scriptPubKey.begin() + txout.scriptPubKey.size());
    publicZero .setvch(vchZeroMint);

    libzero :: Denomination denomination = libzero ::AmountToZero Denomination(txout.nValue);
    LogPrint(BCLog::LEGACYZC, "%s : denomination %d for pub  %s\n", __func__, denomination, publicZero .GetHex());
    if (denomination == libzero ::ZQ_ERROR)
        return state.DoS(100, error("TxOutToPublic  : txout.nValue is not correct"));

    libzero ::Public  checkPub (Params().GetConsensus().Zero _Params(false), publicZero , denomination);
    pub  = checkPub ;

    return true;
}


