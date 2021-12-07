/**
 * @file        Spend.h
 *
 * @brief       Spend class for the Zero  library.
 *
 * @author       
 * @date       June  
 *
 * @copyright  Copyright     
 * @license    This project is released under the MIT license.
 **/
// Copyright (c)   2021     

#ifndef  SPEND_H_
#define  SPEND_H_

#include <streams.h>
#include <utilstrencodings.h>
#include " .h"
#include "Commitment.h"
#include "Params.h"
#include "SpendType.h"

#include "bignum.h"
#include "pubkey.h"
#include "serialize.h"

namespace libzero 
{
// Lagacy zclbi - Only for serialization
// Proof that a value inside a commitment C is accumulated in accumulator A
class AccumulatorProofOfKnowledge {
public:
    AccumulatorProofOfKnowledge() {};
    SERIALIZE_METHODS(AccumulatorProofOfKnowledge, obj) {
        READWRITE(obj.C_e, obj.C_u, obj.C_r, obj.st_1, obj.st_2, obj.st_3);
        READWRITE(obj.t_1, obj.t_2, obj.t_3, obj.t_4, obj.s_alpha, obj.s_beta);
        READWRITE(obj.s_zeta, obj.s_sigma, obj.s_eta, obj.s_epsilon);
        READWRITE(obj.s_delta, obj.s_xi, obj.s_phi, obj.s_gamma, obj.s_psi);
    }
private:
    CBigNum C_e, C_u, C_r;
    CBigNum st_1, st_2, st_3;
    CBigNum t_1, t_2, t_3, t_4;
    CBigNum s_alpha, s_beta, s_zeta, s_sigma, s_eta, s_epsilon, s_delta;
    CBigNum s_xi, s_phi, s_gamma, s_psi;
};

// Lagacy zclbi - Only for serialization
// Signature of knowledge attesting that the signer knows the values to
// open a commitment to a   with given serial number
class SerialNumberSignatureOfKnowledge {
public:
    SerialNumberSignatureOfKnowledge(){};
    SERIALIZE_METHODS(SerialNumberSignatureOfKnowledge, obj) { READWRITE(obj.s_notprime, obj.sprime, obj.hash); }
private:
    uint256 hash;
    std::vector<CBigNum> s_notprime;
    std::vector<CBigNum> sprime;
};

// Lagacy zclbi - Only for serialization
// Proof that two commitments open to the same value (BROKEN)
class CommitmentProofOfKnowledge {
public:
    CommitmentProofOfKnowledge() {};
    SERIALIZE_METHODS(CommitmentProofOfKnowledge, obj) { READWRITE(obj.S1,obj.S2, obj.S3, obj.challenge); }
private:
    CBigNum S1, S2, S3, challenge;
};


// Lagacy zclbi - Only for serialization
/** The complete proof needed to spend a zero .
 * Composes together a proof that a   is accumulated
 * and that it has a given serial number.
 */
class  Spend
{
public:

     Spend() {};
     Spend(CDataStream& strm) { strm >> *this; }
    virtual ~ Spend(){};

    const CBigNum& get SerialNumber() const { return this-> SerialNumber; }
     Denomination getDenomination() const { return this->denomination; }
    uint32_t getAccumulatorChecksum() const { return this->accChecksum; }
    uint256 getTxOutHash() const { return ptxHash; }
    CBigNum getAccCommitment() const { return accCommitmentTo Value; }
    CBigNum getSerialComm() const { return serialCommitmentTo Value; }
    uint8_t getVersion() const { return version; }
    int get Version() const { return libzero ::ExtractVersionFromSerial( SerialNumber); }
    CPubKey getPubKey() const { return pubkey; }
    SpendType getSpendType() const { return spendType; }
    std::vector<unsigned char> getSignature() const { return vchSig; }

    static std::vector<unsigned char> ParseSerial(CDataStream& s);

    virtual const uint256 signatureHash() const;
    bool HasValidSerial(Zero Params* params) const;
    bool HasValidSignature() const;
    void setTxOutHash(uint256 txOutHash) { this->ptxHash = txOutHash; };
    void setDenom(libzero :: Denomination denom) { this->denomination = denom; }
    void setPubKey(CPubKey pkey, bool fUpdateSerial = false);

    CBigNum CalculateValidSerial(Zero Params* params);
    std::string ToString() const;

    SERIALIZE_METHODS( Spend, obj)
    {
        READWRITE(obj.denomination, obj.ptxHash, obj.accChecksum, obj.accCommitmentTo Value);
        READWRITE(obj.serialCommitmentTo Value, obj. SerialNumber, obj.accumulatorPoK);
        READWRITE(obj.serialNumberSoK, obj.commitmentPoK);
        try {
            READWRITE(obj.version, obj.pubkey, obj.vchSig, obj.spendType);
        } catch (...) {
            SER_READ(obj, obj.version = 1);
        }
    }

protected:
     Denomination denomination{ZQ_ERROR};
    CBigNum  SerialNumber{};
    uint8_t version{0};
    //As of version 2
    CPubKey pubkey;
    std::vector<unsigned char> vchSig;
    SpendType spendType{SPEND};
    uint256 ptxHash{UINT256_ZERO};

private:
    uint32_t accChecksum{0};
    CBigNum accCommitmentTo Value;
    CBigNum serialCommitmentTo Value;
    AccumulatorProofOfKnowledge accumulatorPoK;
    SerialNumberSignatureOfKnowledge serialNumberSoK;
    CommitmentProofOfKnowledge commitmentPoK;

};

} /* namespace libzero  */
#endif /*  SPEND_H_ */
