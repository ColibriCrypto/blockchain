// Copyright (c)   2021 The CLBI Core developers
// Copyright (c)   2021     
//      
//   

#ifndef clbi_WALLET_TEST_FIXTURE_H
#define clbi_WALLET_TEST_FIXTURE_H

#include "test/librust/sapling_test_fixture.h"
#include "wallet/wallet.h"


/** Testing setup and teardown for wallet.
 */
struct WalletTestingSetup : public SaplingTestingSetup
{
    WalletTestingSetup(const std::string& chainName = CBaseChainParams::MAIN);
    ~WalletTestingSetup();

    CWallet m_wallet;
};

struct WalletRegTestingSetup : public WalletTestingSetup
{
    WalletRegTestingSetup() : WalletTestingSetup(CBaseChainParams::REGTEST) {}
};

#endif // clbi_WALLET_TEST_FIXTURE_H

