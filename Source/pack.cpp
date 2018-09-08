#include "all.h"

//----- (00468420) --------------------------------------------------------
void __fastcall PackPlayer(PkPlayerStruct *pPack, int pnum)
{
  int v2; // eax
  int *v3; // edx
  signed int v4; // ST24_4
  signed int v5; // ST20_4
  signed int v6; // ST1C_4
  PlayerStruct *v8; // [esp+20h] [ebp-10h]
  signed int i; // [esp+24h] [ebp-Ch]
  signed int v10; // [esp+24h] [ebp-Ch]
  signed int v11; // [esp+24h] [ebp-Ch]
  signed int j; // [esp+24h] [ebp-Ch]
  signed int v13; // [esp+24h] [ebp-Ch]
  PkItemStruct *id; // [esp+28h] [ebp-8h]
  PkItemStruct *ida; // [esp+28h] [ebp-8h]
  PkItemStruct *idb; // [esp+28h] [ebp-8h]
  ItemStruct *is; // [esp+2Ch] [ebp-4h]
  ItemStruct *isa; // [esp+2Ch] [ebp-4h]
  ItemStruct *isb; // [esp+2Ch] [ebp-4h]

  v8 = &plr[pnum];
  pPack->destAction = plr[pnum].destAction;
  pPack->destParam1 = v8->destParam1;
  pPack->destParam2 = v8->destParam2;
  pPack->plrlevel = v8->plrlevel;
  pPack->px = v8->WorldX;
  pPack->py = v8->WorldY;
  pPack->targx = v8->_ptargx;
  pPack->targy = v8->_ptargy;
  strcpy(pPack->pName, v8->_pName);
  pPack->pClass = v8->_pClass;
  pPack->pBaseStr = v8->_pBaseStr;
  pPack->pBaseMag = v8->_pBaseMag;
  pPack->pBaseDex = v8->_pBaseDex;
  pPack->pBaseVit = v8->_pBaseVit;
  pPack->pLevel = v8->_pLevel;
  pPack->pStatPts = v8->_pStatPts;
  pPack->pExperience = v8->_pExperience;
  pPack->pGold = v8->_pGold;
  pPack->pHPBase = v8->_pHPBase;
  pPack->pMaxHPBase = v8->_pMaxHPBase;
  pPack->pManaBase = v8->_pManaBase;
  pPack->pMaxManaBase = v8->_pMaxManaBase;
  v2 = HIDWORD(v8->_pMemSpells);
  v3 = &pPack->pMemSpells;
  *v3 = v8->_pMemSpells;
  v3[1] = v2;
  for ( i = 0; i < 37; ++i )
    pPack->pSplLvl[i] = v8->_pSplLvl[i];
  id = pPack->InvBody;
  is = v8->InvBody;
  v10 = 7;
  while ( 1 )
  {
    v4 = v10--;
    if ( !v4 )
      break;
    PackItem(id, is);
    ++id;
    ++is;
  }
  ida = pPack->InvList;
  isa = v8->InvList;
  v11 = 40;
  while ( 1 )
  {
    v5 = v11--;
    if ( !v5 )
      break;
    PackItem(ida, isa);
    ++ida;
    ++isa;
  }
  for ( j = 0; j < 40; ++j )
    pPack->InvGrid[j] = v8->InvGrid[j];
  pPack->_pNumInv = v8->_pNumInv;
  idb = pPack->SpdList;
  isb = v8->SpdList;
  v13 = 8;
  while ( 1 )
  {
    v6 = v13--;
    if ( !v6 )
      break;
    PackItem(idb, isb);
    ++idb;
    ++isb;
  }
}

//----- (00468718) --------------------------------------------------------
void __fastcall PackItem(PkItemStruct *id, ItemStruct *is)
{
  if ( is->_itype == -1 )
  {
    id->idx = -1;
  }
  else
  {
    id->iSeed = is->_iSeed;
    id->iCreateInfo = is->_iCreateInfo;
    id->idx = is->IDidx;
    id->bId = LOBYTE(is->_iIdentified) + 2 * is->_iMagical;
    id->bDur = is->_iDurability;
    id->bMDur = is->_iMaxDur;
    id->bCh = is->_iCharges;
    id->bMCh = is->_iMaxCharges;
    if ( !is->IDidx )
      id->wValue = is->_ivalue;
  }
}

//----- (004687E5) --------------------------------------------------------
void __fastcall UnPackPlayer(PkPlayerStruct *pPack, int pnum)
{
  int v2; // eax
  _DWORD *v3; // edx
  signed int v4; // ST24_4
  signed int v5; // ST20_4
  signed int v6; // ST1C_4
  PlayerStruct *plr_; // [esp+20h] [ebp-10h]
  signed int i; // [esp+24h] [ebp-Ch]
  signed int v11; // [esp+24h] [ebp-Ch]
  signed int v12; // [esp+24h] [ebp-Ch]
  signed int j; // [esp+24h] [ebp-Ch]
  signed int v14; // [esp+24h] [ebp-Ch]
  PkItemStruct *a1; // [esp+28h] [ebp-8h]
  PkItemStruct *a1a; // [esp+28h] [ebp-8h]
  PkItemStruct *a1b; // [esp+28h] [ebp-8h]
  ItemStruct *a2; // [esp+2Ch] [ebp-4h]
  ItemStruct *a2a; // [esp+2Ch] [ebp-4h]
  ItemStruct *a2b; // [esp+2Ch] [ebp-4h]

  plr_ = &plr[pnum];
  plr[pnum].WorldX = (unsigned __int8)pPack->px;
  plr_->WorldY = (unsigned __int8)pPack->py;
  plr_->_px = (unsigned __int8)pPack->px;
  plr_->_py = (unsigned __int8)pPack->py;
  plr_->_ptargx = (unsigned __int8)pPack->targx;
  plr_->_ptargy = (unsigned __int8)pPack->targy;
  plr_->plrlevel = (unsigned __int8)pPack->plrlevel;
  ClrPlrPath(pnum);
  plr_->destAction = -1;
  strcpy(plr_->_pName, pPack->pName);
  plr_->_pClass = pPack->pClass;
  InitPlayer(pnum, 1);
  plr_->_pBaseStr = (unsigned __int8)pPack->pBaseStr;
  plr_->_pStrength = (unsigned __int8)pPack->pBaseStr;
  plr_->_pBaseMag = (unsigned __int8)pPack->pBaseMag;
  plr_->_pMagic = (unsigned __int8)pPack->pBaseMag;
  plr_->_pBaseDex = (unsigned __int8)pPack->pBaseDex;
  plr_->_pDexterity = (unsigned __int8)pPack->pBaseDex;
  plr_->_pBaseVit = (unsigned __int8)pPack->pBaseVit;
  plr_->_pVitality = (unsigned __int8)pPack->pBaseVit;
  plr_->_pLevel = pPack->pLevel;
  plr_->_pStatPts = (unsigned __int8)pPack->pStatPts;
  plr_->_pExperience = pPack->pExperience;
  plr_->_pGold = pPack->pGold;
  plr_->_pMaxHPBase = pPack->pMaxHPBase;
  plr_->_pHPBase = pPack->pHPBase;
  if ( (signed int)(plr_->_pHPBase & 0xFFFFFFC0) < 64 )
    plr_->_pHPBase = 64;
  plr_->_pMaxManaBase = pPack->pMaxManaBase;
  plr_->_pManaBase = pPack->pManaBase;
  v2 = pPack->pMemSpells2;
  v3 = &plr_->_pMemSpells;
  *v3 = pPack->pMemSpells;
  v3[1] = v2;
  for ( i = 0; i < 37; ++i )
    plr_->_pSplLvl[i] = pPack->pSplLvl[i];
  a1 = pPack->InvBody;
  a2 = plr_->InvBody;
  v11 = 7;
  while ( 1 )
  {
    v4 = v11--;
    if ( !v4 )
      break;
    UnPackItem(a1, a2);
    ++a1;
    ++a2;
  }
  a1a = pPack->InvList;
  a2a = plr_->InvList;
  v12 = 40;
  while ( 1 )
  {
    v5 = v12--;
    if ( !v5 )
      break;
    UnPackItem(a1a, a2a);
    ++a1a;
    ++a2a;
  }
  for ( j = 0; j < 40; ++j )
    plr_->InvGrid[j] = pPack->InvGrid[j];
  plr_->_pNumInv = (unsigned __int8)pPack->_pNumInv;
  a1b = pPack->SpdList;
  a2b = plr_->SpdList;
  v14 = 8;
  while ( 1 )
  {
    v6 = v14--;
    if ( !v6 )
      break;
    UnPackItem(a1b, a2b);
    ++a1b;
    ++a2b;
  }
  CalcPlrInv(pnum, 0);
  CalcPlrScrolls(pnum);
  CalcPlrStaff(pnum);
}

//----- (00468B93) --------------------------------------------------------
void __fastcall UnPackItem(PkItemStruct *is, ItemStruct *id)
{
  int ii; // ST20_4

  if ( (unsigned __int16)is->idx == 0xFFFF )
  {
    id->_itype = -1;
  }
  else
  {
    ii = itemavail[0];
    RecreateItem(itemavail[0], (unsigned __int16)is->idx, is->iCreateInfo, is->iSeed, (unsigned __int16)is->wValue);
    item[ii]._iMagical = (signed int)(unsigned __int8)is->bId >> 1;
    item[ii]._iIdentified = is->bId & 1;
    item[ii]._iDurability = (unsigned __int8)is->bDur;
    item[ii]._iMaxDur = (unsigned __int8)is->bMDur;
    item[ii]._iCharges = (unsigned __int8)is->bCh;
    item[ii]._iMaxCharges = (unsigned __int8)is->bMCh;
    qmemcpy(id, &item[ii], sizeof(ItemStruct));
  }
}

