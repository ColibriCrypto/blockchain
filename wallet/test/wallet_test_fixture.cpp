// Copyright (c)   2021 The CLBI Core developers
// Copyright (c)   2021     
//      
//   

#include "wallet/test/wallet_test_fixture.h"

#include "rpc/server.h"
#include "wallet/db.h"
#include "wallet/rpcwallet.h"
#include "wallet/wallet.h"

WalletTestingSetup::WalletTestingSetup(const std::string& chainName):
        SaplingTestingSetup(chainName), m_wallet("mock", WalletDatabase::CreateMock())
{
    bool fFirstRun;
    m_wallet.LoadWallet(fFirstRun);
    RegisterValidationInterface(&m_wallet);

    RegisterWalletRPCCommands(tableRPC);
}

WalletTestingSetup::~WalletTestingSetup()
{
    UnregisterValidationInterface(&m_wallet);
}
