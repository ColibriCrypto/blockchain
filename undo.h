// Copyright (c)  -    
// Copyright (c)  -      
// Copyright (c)   2021     
//      
//   

#ifndef CLBI_UNDO_H
#define CLBI_UNDO_H

#include "chain.h"
#include "compressor.h"
#include "consensus/consensus.h"
#include "primitives/transaction.h"
#include "serialize.h"
#include "version.h"

/** Formatter for undo information for a CTxIn
 *
 *  Contains the prevout's CTxOut being spent, and its metadata as well
 *  ( base/ stake or not, height). The serialization contains a
 *  dummy value of zero. This is be compatible with older versions which
 *  expect to see the transaction version there.
 */
struct TxInUndoFormatter
{
    template<typename Stream>
    void Ser(Stream &s, const  & txout) {
        ::Serialize(s, VARINT(txout.nHeight * 4 + (txout.f Base ? 2u : 0u) + (txout.f Stake ? 1u : 0u)));
        if (txout.nHeight > 0) {
            // Required to maintain compatibility with older undo format.
            ::Serialize(s, (unsigned char)0);
        }
        ::Serialize(s, Using<TxOutCompression>(txout.out));
    }

    template<typename Stream>
    void Unser(Stream &s,  & txout) {
        unsigned int nCode = 0;
        ::Unserialize(s, VARINT(nCode));
        txout.nHeight = nCode >> 2;
        txout.f Base = nCode & 2;
        txout.f Stake = nCode & 1;
        if (txout.nHeight > 0) {
            // Old versions stored the version number for the last spend of
            // a transaction's outputs. Non-final spends were indicated with
            // height = 0.
            unsigned int nVersionDummy;
            ::Unserialize(s, VARINT(nVersionDummy));
        }
        ::Unserialize(s, Using<TxOutCompression>(txout.out));
    }
};

/** Undo information for a CTransaction */
class CTxUndo
{
public:
    // undo information for all txins
    std::vector< > vprevout;

    SERIALIZE_METHODS(CTxUndo, obj) { READWRITE(Using<VectorFormatter<TxInUndoFormatter>>(obj.vprevout)); }
};

/** Undo information for a CBlock */
class CBlockUndo
{
public:
    std::vector<CTxUndo> vtxundo; // for all but the  base

    SERIALIZE_METHODS(CBlockUndo, obj) { READWRITE(obj.vtxundo); }
};

#endif // CLBI_UNDO_H
