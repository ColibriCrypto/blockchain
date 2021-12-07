/**
 * @file        Spend.cpp
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

#include " Spend.h"
#include <iostream>
#include <sstream>

namespace libzero 
{

const uint256  Spend::signatureHash() const
{
    CHashWriter h(0, 0);
    h << serialCommitmentTo Value << accCommitmentTo Value << commitmentPoK << accumulatorPoK << ptxHash
      <<  SerialNumber << accChecksum << denomination;

    if (version >= PUBKEY_VERSION)
        h << spendType;

    return h.GetHash();
}

std::string  Spend::ToString() const
{
    std::stringstream ss;
    ss << " Spend:\n version=" << (int)version << " signatureHash=" << signatureHash().GetHex() << " spendtype=" << spendType << "\n";
    return ss.str();
}

bool  Spend::HasValidSerial(Zero Params* params) const
{
    return IsValidSerial(params,  SerialNumber);
}

//Additional verification layer that requires the spend be signed by the private key associated with the serial
bool  Spend::HasValidSignature() const
{
    const int  Version = get Version();
    //No private key for V1
    if ( Version < PUBKEY_VERSION)
        return true;

    try {
        //V2 serial requires that the signature hash be signed by the public key associated with the serial
        arith_uint256 hashedPubkey = UintToArith256(Hash(pubkey.begin(), pubkey.end())) >> V2_BITSHIFT;
        if (hashedPubkey != GetAdjustedSerial( SerialNumber).getuint256()) {
            //cout << " Spend::HasValidSignature() hashedpubkey is not equal to the serial!\n";
            return false;
        }
    } catch (const std::range_error& e) {
        //std::cout << "HasValidSignature() error: " << e.what() << std::endl;
        throw InvalidSerialException("Serial longer than 256 bits");
    }

    return pubkey.Verify(signatureHash(), vchSig);
}

CBigNum  Spend::CalculateValidSerial(Zero Params* params)
{
    CBigNum bnSerial =  SerialNumber;
    bnSerial = bnSerial % params-> CommitmentGroup.groupOrder;
    return bnSerial;
}

std::vector<unsigned char>  Spend::ParseSerial(CDataStream& s) {
    unsigned int nSize = ReadCompactSize(s);
    s.movePos(nSize);
    nSize = ReadCompactSize(s);
    s.movePos(nSize);
    CBigNum  SerialNumber;
    s >>  SerialNumber;
    return  SerialNumber.getvch();
}

void  Spend::setPubKey(CPubKey pkey, bool fUpdateSerial) {
    this->pubkey = pkey;
    if (fUpdateSerial) {
        this-> SerialNumber = libzero ::ExtractSerialFromPubKey(this->pubkey);
    }
}

} /* namespace libzero  */
