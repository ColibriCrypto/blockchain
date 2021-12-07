// Copyright (c) 2021     
// Distributed under the MIT/X11 software license, see the accompanying
//   

#ifndef  RANDOMNESSPROOF_H_
#define  RANDOMNESSPROOF_H_

#include "Params.h"
#include " .h"
#include "serialize.h"
#include "hash.h"

namespace libzero  {

/**A Schnorr Signature on the hash of metadata attesting that the signer knows the randomness v
 *  necessary to open a public   C (which is a pedersen commitment g^S h^v mod p) with
 * given serial number S.
 */
class  RandomnessSchnorrSignature {
public:
     RandomnessSchnorrSignature() {};
    template <typename Stream>  RandomnessSchnorrSignature(Stream& strm) {strm >> *this;}

    /** Creates a Schnorr signature object using the randomness of a public   as private key sk.
     *
     * @param zcparams zero  params (group modulus, order and generators)
     * @param randomness the   we are going to use for the signature (sk := randomness, pk := h^sk mod p).
     * @param msghash hash of meta data to create a signature on.
     */
     RandomnessSchnorrSignature(const Zero Params* zcparams, const CBigNum randomness, const uint256 msghash);

    /** Verifies the Schnorr signature on message msghash with public key pk = Cg^-S mod p
     *
     * @param zcparams zero  params (group modulus, order and generators)
     * @param S serial number of the   used for the signature
     * @param C value of the public   (commitment to serial S and randomness v) used for the signature.
     * @param msghash hash of meta data to verify the signature on.
     * @return
     */
    bool Verify(const Zero Params* zcparams, const CBigNum& S, const CBigNum& C, const uint256 msghash) const;

    SERIALIZE_METHODS( RandomnessSchnorrSignature, obj) { READWRITE(obj.alpha, obj.beta); }

private:
    // signature components
    CBigNum alpha, beta;
};

} /* namespace libzero  */
#endif /*  RANDOMNESSPROOF_H_ */
