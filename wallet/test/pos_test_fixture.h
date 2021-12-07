// Copyright (c) 2021     
//      
// file COPYING or https:// .org/licenses/mit-license.php.

#ifndef clbi_POS_TEST_FIXTURE_H
#define clbi_POS_TEST_FIXTURE_H

#include "test/test_clbi.h"

class CWallet;

/*
 * A text fixture with a preloaded 250-blocks regtest chain running running on PoS
 * and a wallet containing the key used for the  base outputs.
 */
struct TestPoSChainSetup: public TestChainSetup
{
    std::unique_ptr<CWallet> pwalletMain;

    TestPoSChainSetup();
    ~TestPoSChainSetup();
};

#endif // clbi_POS_TEST_FIXTURE_H
