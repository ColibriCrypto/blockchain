// Copyright (c)     
//      
//   

#include "evo/evonotificationinterface.h"

#include "evo/deterministicmns.h"
#include "validation.h"

void EvoNotificationInterface::InitializeCurrentBlockTip()
{
    LOCK(cs_main);
    UpdatedBlockTip(chainActive.Tip(), nullptr, IsInitialBlockDownload());
}

void EvoNotificationInterface::UpdatedBlockTip(const CBlockIndex *pindexNew, const CBlockIndex *pindexFork, bool fInitialDownload)
{
    deterministicMNManager->UpdatedBlockTip(pindexNew);
}

void EvoNotificationInterface::NotifyMasternodeListChanged(bool undo, const CDeterministicMNList& oldMNList, const CDeterministicMNListDiff& diff)
{
    // !TODO
}
