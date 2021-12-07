/**
* @file       Zero .h
*
* @brief      Exceptions and constants for Zero 
*
* @author       
* @date       June  
*
* @copyright  Copyright     
* @license    This project is released under the MIT license.
**/
// Copyright (c) 2021     

#ifndef ZERO _DEFINES_H_
#define ZERO _DEFINES_H_

#include <stdexcept>

#define ZERO _DEFAULT_SECURITYLEVEL      80
#define ZERO _MIN_SECURITY_LEVEL         80
#define ZERO _MAX_SECURITY_LEVEL         80
#define ACCPROOF_KPRIME                     160
#define ACCPROOF_KDPRIME                    128
#define MAX_ MINT_ATTEMPTS               10000
#define ZERO _MINT_PRIME_PARAM			20
#define ZERO _VERSION_STRING             "0.11"
#define ZERO _VERSION_INT				11
#define ZERO _PROTOCOL_VERSION           "1"
#define HASH_OUTPUT_BITS                    256
#define ZERO _COMMITMENT_EQUALITY_PROOF  "COMMITMENT_EQUALITY_PROOF"
#define ZERO _ACCUMULATOR_PROOF          "ACCUMULATOR_PROOF"
#define ZERO _SERIALNUMBER_PROOF         "SERIALNUMBER_PROOF"

// Activate multithreaded mode for proof verification
#define ZERO _THREADING 1

// Uses a fast technique for   generation. Could be more vulnerable
// to timing attacks. Turn off if an attacker can measure   minting time.
#define	ZERO _FAST_MINT 1

#endif /* ZERO _H_ */
