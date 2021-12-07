// Copyright (c) 2021 The CLBI Core developers
//      
//   

#ifndef CLBI_WALLET_UTIL_H
#define CLBI_WALLET_UTIL_H

#include "fs.h"
#include "operationresult.h"

//! Get the path of the wallet directory.
fs::path GetWalletDir();
//! Verify the wallet db's path
OperationResult VerifyWalletPath(const std::string& walletFile);

#endif // CLBI_WALLET_UTIL_H
