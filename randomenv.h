// Copyright (c)  -    
// Copyright (c)  -2021 The CLBI Core developers
//      
//   

#ifndef CLBI_RANDOMENV_H
#define CLBI_RANDOMENV_H

#include "crypto/sha512.h"

/** Gather non-cryptographic environment data that changes over time. */
void RandAddDynamicEnv(CSHA512& hasher);

/** Gather non-cryptographic environment data that does not change over time. */
void RandAddStaticEnv(CSHA512& hasher);

#endif
