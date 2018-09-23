#include "all.h"

//----- (00420580) --------------------------------------------------------
void __cdecl InitItemGFX()
{
  unsigned __int8 *v0; // eax
  char pszName; // [esp+Ch] [ebp-44h]
  int i; // [esp+4Ch] [ebp-4h]

  for ( i = 0; i < 31; ++i )
  {
    sprintf(&pszName, "Items\\%s.CEL", ItemDropStrs[i]);
    assert(!Item2Frm[i], "ITEMS.CPP", 399);
    v0 = LoadFileInMem(&pszName, 0, 400, "ITEMS.CPP");
    Item2Frm[i] = v0;
  }
  memset(UniqueItemFlag, 0, 0x200u);
}

//----- (00420624) --------------------------------------------------------
BOOL __fastcall ItemPlace(int x, int y)
{
  if ( dMonster[x][y] )
    return 0;
  if ( dPlayer[x][y] )
    return 0;
  if ( dItem[x][y] )
    return 0;
  if ( dObject[x][y] )
    return 0;
  if ( dFlags[x][y] & 8 )
    return 0;
  return nSolidTable[dPiece[x][y]] == 0;
}

//----- (00420731) --------------------------------------------------------
void __cdecl AddInitItems()
{
  BOOL k; // eax
  int x; // [esp+Ch] [ebp-14h]
  int y; // [esp+10h] [ebp-10h]
  int i; // [esp+14h] [ebp-Ch]
  int v4; // [esp+18h] [ebp-8h]
  int j; // [esp+1Ch] [ebp-4h]

  v4 = random(11, 3) + 3;
  for ( j = 0; j < v4; ++j )
  {
    i = itemavail[0];
    itemavail[0] = itemavail[127 - numitems - 1];
    itemactive[numitems] = i;
    x = random(12, 80) + 16;
    y = random(12, 80) + 16;
    for ( k = ItemPlace(x, y); !k; k = ItemPlace(x, y) )
    {
      x = random(12, 80) + 16;
      y = random(12, 80) + 16;
    }
    item[i]._ix = x;
    item[i]._iy = y;
    dItem[x][y] = i + 1;
    item[i]._iSeed = GetRndSeed();
    SetRndSeed(item[i]._iSeed);
    if ( random(12, 2) )
      GetItemAttrs(i, 11, currlevel);
    else
      GetItemAttrs(i, 12, currlevel);
    item[i]._iCreateInfo = currlevel + -32768;
    SetupItem(i);
    item[i]._iAnimFrame = item[i]._iAnimLen;
    item[i]._iAnimFlag = 0;
    item[i]._iSelFlag = 1;
    DeltaAddItem(i);
    ++numitems;
  }
}

//----- (00420961) --------------------------------------------------------
void __cdecl InitItems()
{
  signed int i; // [esp+Ch] [ebp-8h]
  int j; // [esp+Ch] [ebp-8h]

  GetItemAttrs(0, 0, 1);
  qmemcpy(&golditem, item, sizeof(golditem));
  golditem._iStatFlag = 1;
  numitems = 0;
  for ( i = 0; i < 127; ++i )
  {
    item[i]._itype = 0;
    item[i]._ix = 0;
    item[i]._iy = 0;
    item[i]._iAnimFlag = 0;
    item[i]._isin = 0;
    item[i]._iSelFlag = 0;
    item[i]._iIdentified = 0;
    item[i]._iPostDraw = 0;
  }
  for ( j = 0; j < 127; ++j )
  {
    itemavail[j] = j;
    itemactive[j] = 0;
  }
  GetRndSeed();
  if ( !setlevel && quests[2]._qlevel == currlevel && quests[2]._qactive == 2 )
    SpawnRock();
  if ( !setlevel && (signed int)currlevel > 0 )
    AddInitItems();
  uitemflag = 0;
}

//----- (00420B28) --------------------------------------------------------
void __fastcall CalcPlrItemVals(int p, BOOL Loadgfx)
{
  int v2; // eax
  __int64 v3; // rax
  int v4; // eax
  int v5; // ST40_4
  int bac; // [esp+1Ch] [ebp-7Ch]
  int fmin; // [esp+20h] [ebp-78h]
  int vadd; // [esp+24h] [ebp-74h]
  signed int mr; // [esp+28h] [ebp-70h]
  int v12; // [esp+2Ch] [ebp-6Ch]
  char splcost; // [esp+30h] [ebp-68h]
  int lmin; // [esp+34h] [ebp-64h]
  signed int i; // [esp+38h] [ebp-60h]
  int dmod; // [esp+3Ch] [ebp-5Ch]
  int ihp; // [esp+40h] [ebp-58h]
  int maxd; // [esp+44h] [ebp-54h]
  signed int lr; // [esp+48h] [ebp-50h]
  signed int g; // [esp+4Ch] [ebp-4Ch]
  int btohit; // [esp+50h] [ebp-48h]
  int madd; // [esp+54h] [ebp-44h]
  int tac; // [esp+58h] [ebp-40h]
  int fmax; // [esp+5Ch] [ebp-3Ch]
  int mind; // [esp+60h] [ebp-38h]
  int sadd; // [esp+64h] [ebp-34h]
  int dadd; // [esp+68h] [ebp-30h]
  int spldur; // [esp+6Ch] [ebp-2Ch]
  int v29; // [esp+70h] [ebp-28h]
  int imana; // [esp+74h] [ebp-24h]
  int imana_; // [esp+74h] [ebp-24h]
  int lmax; // [esp+78h] [ebp-20h]
  int ghit; // [esp+7Ch] [ebp-1Ch]
  signed int lrad; // [esp+80h] [ebp-18h]
  int bdam; // [esp+84h] [ebp-14h]
  int enac; // [esp+88h] [ebp-10h]
  int iflgs; // [esp+8Ch] [ebp-Ch]
  signed int fr; // [esp+90h] [ebp-8h]
  char spllvladd; // [esp+94h] [ebp-4h]

  mind = 0;
  maxd = 0;
  tac = 0;
  bdam = 0;
  btohit = 0;
  bac = 0;
  iflgs = 0;
  sadd = 0;
  madd = 0;
  dadd = 0;
  vadd = 0;
  v12 = 0;
  fr = 0;
  lr = 0;
  mr = 0;
  dmod = 0;
  ghit = 0;
  lrad = 10;
  ihp = 0;
  imana = 0;
  spllvladd = 0;
  splcost = 0;
  spldur = 0;
  enac = 0;
  fmin = 0;
  fmax = 0;
  lmin = 0;
  lmax = 0;
  for ( i = 0; i < 7; ++i )
  {
    if ( plr[p].InvBody[i]._itype != -1 && plr[p].InvBody[i]._iStatFlag )
    {
      mind += plr[p].InvBody[i]._iMinDam;
      maxd += plr[p].InvBody[i]._iMaxDam;
      tac += plr[p].InvBody[i]._iAC;
      if ( plr[p].InvBody[i]._iSpell )
        v12 |= 1 << (LOBYTE(plr[p].InvBody[i]._iSpell) - 1);
      if ( !plr[p].InvBody[i]._iMagical || plr[p].InvBody[i]._iIdentified )
      {
        bdam += plr[p].InvBody[i]._iPLDam;
        btohit += plr[p].InvBody[i]._iPLToHit;
        bac += plr[p].InvBody[i]._iPLAC * plr[p].InvBody[i]._iAC / 100;
        iflgs |= plr[p].InvBody[i]._iFlags;
        sadd += plr[p].InvBody[i]._iPLStr;
        madd += plr[p].InvBody[i]._iPLMag;
        dadd += plr[p].InvBody[i]._iPLDex;
        vadd += plr[p].InvBody[i]._iPLVit;
        fr += plr[p].InvBody[i]._iPLFR;
        lr += plr[p].InvBody[i]._iPLLR;
        mr += plr[p].InvBody[i]._iPLMR;
        dmod += plr[p].InvBody[i]._iPLDamMod;
        ghit += plr[p].InvBody[i]._iPLGetHit;
        lrad += plr[p].InvBody[i]._iPLLight;
        ihp += plr[p].InvBody[i]._iPLHP;
        imana += plr[p].InvBody[i]._iPLMana;
        spllvladd += plr[p].InvBody[i]._iSplLvlAdd;
        splcost += plr[p].InvBody[i]._pISplCost;
        spldur += plr[p].InvBody[i]._pISplDur;
        enac += plr[p].InvBody[i]._iPLEnAc;
        fmin += plr[p].InvBody[i]._iFMinDam;
        fmax += plr[p].InvBody[i]._iFMaxDam;
        lmin += plr[p].InvBody[i]._iLMinDam;
        lmax += plr[p].InvBody[i]._iLMaxDam;
      }
    }
  }
  if ( !mind && !maxd )
  {
    mind = 1;
    maxd = 1;
    if ( plr[p].InvBody[4]._itype == 5 && plr[p].InvBody[4]._iStatFlag )
      maxd = 3;
    if ( plr[p].InvBody[5]._itype == 5 && plr[p].InvBody[5]._iStatFlag )
      maxd = 3;
  }
  plr[p]._pIMinDam = mind;
  plr[p]._pIMaxDam = maxd;
  plr[p]._pIAC = tac;
  plr[p]._pIBonusDam = bdam;
  plr[p]._pIBonusToHit = btohit;
  plr[p]._pIBonusAC = bac;
  plr[p]._pIFlags = iflgs;
  plr[p]._pIBonusDamMod = dmod;
  plr[p]._pIGetHit = ghit;
  if ( lrad < 2 )
    lrad = 2;
  if ( lrad > 15 )
    lrad = 15;
  if ( plr[p]._pLightRad != lrad )
  {
    ChangeLightRadius(plr[p]._plid, lrad);
    if ( lrad >= 10 )
      ChangeVisionRadius(plr[p]._pvid, lrad);
    else
      ChangeVisionRadius(plr[p]._pvid, 10);
    plr[p]._pLightRad = lrad;
  }
  plr[p]._pStrength = sadd + plr[p]._pBaseStr;
  plr[p]._pMagic = madd + plr[p]._pBaseMag;
  plr[p]._pDexterity = dadd + plr[p]._pBaseDex;
  plr[p]._pVitality = vadd + plr[p]._pBaseVit;
  if ( plr[p]._pClass == 1 )
    v2 = plr[p]._pLevel * (plr[p]._pStrength + plr[p]._pDexterity) / 200;
  else
    v2 = plr[p]._pStrength * plr[p]._pLevel / 100;
  plr[p]._pDamageMod = v2;
  plr[p]._pISpells = v12;
  if ( plr[p]._pRSplType == 3 )
  {
    v3 = 1 << (plr[p]._pRSpell - 1);
    v4 = LODWORD(plr[p]._pISpells) & v3;
    if ( !(HIDWORD(v3) & HIDWORD(plr[p]._pISpells)) && !v4 )
    {
      plr[p]._pRSpell = -1;
      plr[p]._pRSplType = 4;
      drawpanflag = 255;
    }
  }
  plr[p]._pISplLvlAdd = spllvladd;
  plr[p]._pISplCost = splcost;                  // not in 1.09
  plr[p]._pISplDur = spldur;                    // not in 1.09
  plr[p]._pIEnAc = enac;
  if ( iflgs < 0 )
  {
    mr = 0;
    fr = 0;
    lr = 0;
  }
  if ( mr > 100 )
    LOBYTE(mr) = 100;
  plr[p]._pMagResist = mr;
  if ( fr > 100 )
    LOBYTE(fr) = 100;
  plr[p]._pFireResist = fr;
  if ( lr > 100 )
    LOBYTE(lr) = 100;
  plr[p]._pLghtResist = lr;
  v5 = (vadd << 6) + ihp;
  imana_ = (madd << 6) + imana;
  plr[p]._pHitPoints = v5 + plr[p]._pHPBase;
  plr[p]._pMaxHP = v5 + plr[p]._pMaxHPBase;
  if ( (signed int)(plr[p]._pHitPoints & 0xFFFFFFC0) <= 0 )
    SetPlayerHitPoints(p, 0);
  plr[p]._pMana = imana_ + plr[p]._pManaBase;
  plr[p]._pMaxMana = imana_ + plr[p]._pMaxManaBase;
  plr[p]._pIFMinDam = fmin;
  plr[p]._pIFMaxDam = fmax;
  plr[p]._pILMinDam = lmin;
  plr[p]._pILMaxDam = lmax;
  if ( iflgs & 1 )
    plr[p]._pInfraFlag = 1;
  else
    plr[p]._pInfraFlag = 0;
  plr[p]._pBlockFlag = 0;
  plr[p]._pwtype = 0;
  g = 0;
  if ( plr[p].InvBody[4]._itype != -1 && plr[p].InvBody[4]._iClass == 1 && plr[p].InvBody[4]._iStatFlag )
    g = plr[p].InvBody[4]._itype;
  if ( plr[p].InvBody[5]._itype != -1 && plr[p].InvBody[5]._iClass == 1 && plr[p].InvBody[5]._iStatFlag )
    g = plr[p].InvBody[5]._itype;
  switch ( g )
  {
    case 1:
      g = 2;
      break;
    case 2:
      g = 5;
      break;
    case 3:
      plr[p]._pwtype = 1;
      g = 4;
      break;
    case 4:
      g = 6;
      break;
    case 10:
      g = 8;
      break;
    default:
      break;
  }
  if ( plr[p].InvBody[4]._itype == 5 && plr[p].InvBody[4]._iStatFlag )
  {
    plr[p]._pBlockFlag = 1;
    ++g;
  }
  if ( plr[p].InvBody[5]._itype == 5 && plr[p].InvBody[5]._iStatFlag )
  {
    plr[p]._pBlockFlag = 1;
    ++g;
  }
  if ( plr[p].InvBody[6]._itype == 8 && plr[p].InvBody[6]._iStatFlag )
    g += 16;
  if ( plr[p].InvBody[6]._itype == 9 && plr[p].InvBody[6]._iStatFlag )
    g += 32;
  if ( plr[p]._pgfxnum != g && Loadgfx )
  {
    plr[p]._pgfxnum = g;
    plr[p]._pGFXLoad = 0;
    LoadPlrGFX(p, 1);
    SetPlrAnims(p);
    v29 = plr[p]._pdir;
    assert(plr[p]._pNAnim[v29], "ITEMS.CPP", 704);
    plr[p]._pAnimData = plr[p]._pNAnim[v29];
    plr[p]._pAnimLen = plr[p]._pNFrames;
    plr[p]._pAnimFrame = 1;
    plr[p]._pAnimCnt = 0;
    plr[p]._pAnimDelay = 3;
    plr[p]._pAnimWidth = plr[p]._pNWidth;
    plr[p]._pAnimWidth2 = (plr[p]._pNWidth - 64) >> 1;
  }
  else
  {
    plr[p]._pgfxnum = g;
  }
  drawmanaflag = 1;
  drawhpflag = 1;
}

//----- (00421E5E) --------------------------------------------------------
void __fastcall CalcPlrScrolls(int p)
{
  DWORD *v1; // eax
  int i; // [esp+10h] [ebp-Ch]
  signed int j; // [esp+10h] [ebp-Ch]

  v1 = (DWORD *)&plr[p]._pScrlSpells;
  *v1 = 0;
  v1[1] = 0;
  for ( i = 0; plr[p]._pNumInv > i; ++i )
  {
    if ( plr[p].InvList[i]._itype != -1 && (plr[p].InvList[i]._iMiscId == 21 || plr[p].InvList[i]._iMiscId == 22) )
    {
      if ( plr[p].InvList[i]._iStatFlag )
        plr[p]._pScrlSpells |= 1i64 << ((unsigned __int8)plr[p].InvList[i]._iSpell - 1);
    }
  }
  for ( j = 0; j < 8; ++j )
  {
    if ( plr[p].SpdList[j]._itype != -1
      && (plr[p].SpdList[j]._iMiscId == 21 || plr[p].SpdList[j]._iMiscId == 22)
      && plr[p].SpdList[j]._iStatFlag )
    {
      plr[p]._pScrlSpells |= 1i64 << ((unsigned __int8)plr[p].SpdList[j]._iSpell - 1);
    }
  }
}

//----- (0042217D) --------------------------------------------------------
void __fastcall CalcPlrStaff(int pnum)
{
  DWORD *v1; // eax

  v1 = (DWORD *)&plr[pnum]._pISpells;
  *v1 = 0;
  v1[1] = 0;
  if ( plr[pnum].InvBody[4]._itype != -1 && plr[pnum].InvBody[4]._iCharges > 0 )
    plr[pnum]._pISpells |= 1i64 << ((unsigned __int8)plr[pnum].InvBody[4]._iSpell - 1);
}

//----- (00422270) --------------------------------------------------------
BOOL __fastcall CalcSelfItems(int pnum)
{
  signed int v1; // ST18_4
  int v2; // ST14_4
  signed int v3; // ST10_4
  signed int v5; // [esp+1Ch] [ebp-14h]
  int v6; // [esp+1Ch] [ebp-14h]
  signed int v7; // [esp+1Ch] [ebp-14h]
  BOOL v8; // [esp+20h] [ebp-10h]
  int v9; // [esp+24h] [ebp-Ch]
  ItemStruct *a2; // [esp+28h] [ebp-8h]
  ItemStruct *a2a; // [esp+28h] [ebp-8h]
  ItemStruct *a2b; // [esp+28h] [ebp-8h]
  PlayerStruct *a1; // [esp+2Ch] [ebp-4h]

  v9 = 0;
  a1 = &plr[pnum];
  a2 = plr[pnum].InvBody;
  v5 = 7;
  while ( 1 )
  {
    v1 = v5--;
    if ( !v1 )
      break;
    if ( a2->_itype != -1 )
    {
      v8 = ItemMinStats(a1, a2);
      if ( a2->_iStatFlag != v8 )
        v9 |= 1u;
      a2->_iStatFlag = v8;
    }
    ++a2;
  }
  a2a = a1->InvList;
  v6 = a1->_pNumInv;
  while ( 1 )
  {
    v2 = v6--;
    if ( !v2 )
      break;
    a2a->_iStatFlag = ItemMinStats(a1, a2a);
    ++a2a;
  }
  a2b = a1->SpdList;
  v7 = 8;
  while ( 1 )
  {
    v3 = v7--;
    if ( !v3 )
      break;
    if ( a2b->_itype != -1 )
      a2b->_iStatFlag = ItemMinStats(a1, a2b);
    ++a2b;
  }
  return v9;
}

//----- (004223D8) --------------------------------------------------------
BOOL __fastcall ItemMinStats(PlayerStruct *a1, ItemStruct *a2)
{
  if ( (char)a2->_iMinMag > a1->_pMagic )
    return 0;
  if ( a2->_iMinStr <= a1->_pStrength )
    return a2->_iMinDex <= a1->_pDexterity;
  return 0;
}

//----- (00422456) --------------------------------------------------------
void __fastcall CalcPlrInv(int p, BOOL Loadgfx)
{
  CalcSelfItems(p);
  CalcPlrItemVals(p, Loadgfx);
  if ( CalcSelfItems(p) )
    CalcPlrItemVals(p, Loadgfx);
  if ( p == myplr )
  {
    CalcPlrScrolls(p);
    CalcPlrStaff(p);
  }
  if ( p == myplr && !currlevel )
    RecalcStoreStats();
}

//----- (004224DD) --------------------------------------------------------
void __fastcall SetPlrHandItem(ItemStruct *h, int idata)
{
  ItemDataStruct *v4; // [esp+14h] [ebp-4h]

  v4 = &AllItemsList[idata];
  memset(h, 0, 0x170u);
  h->_itype = v4->itype;
  h->_iCurs = v4->iCurs;
  strcpy(h->_iName, v4->iName);
  strcpy(h->_iIName, v4->iName);
  h->_iLoc = v4->iLoc;
  h->_iClass = v4->iClass;
  h->_iMinDam = v4->iMinDam;
  h->_iMaxDam = v4->iMaxDam;
  h->_iAC = v4->iMinAC;
  h->_iMiscId = v4->iMiscId;
  h->_iSpell = v4->iSpell;
  if ( v4->iMiscId == 23 )
    h->_iCharges = 8;
  h->_iMaxCharges = h->_iCharges;
  h->_iDurability = v4->iDurability;
  h->_iMaxDur = v4->iDurability;
  h->_iMinStr = v4->iMinStr;
  h->_iMinMag = v4->iMinMag;
  h->_iMinDex = v4->iMinDex;
  h->_ivalue = v4->iValue;
  h->_iIvalue = v4->iValue;
  h->_iPrePower = -1;
  h->_iSufPower = -1;
  h->IDidx = idata;
  h->_iMagical = 0;
}

//----- (0042268B) --------------------------------------------------------
void __fastcall GetPlrHandSeed(ItemStruct *h)
{
  h->_iSeed = GetRndSeed();
}

//----- (004226AB) --------------------------------------------------------
void __fastcall SetPlrHandSeed(ItemStruct *h, int iseed)
{
  h->_iSeed = iseed;
}

//----- (004226CC) --------------------------------------------------------
void __fastcall CreatePlrItems(int p)
{
  signed int v1; // ST28_4
  signed int v2; // ST24_4
  signed int v3; // ST20_4
  int v4; // [esp+Ch] [ebp-1Ch]
  signed int v6; // [esp+20h] [ebp-8h]
  signed int v7; // [esp+20h] [ebp-8h]
  signed int v8; // [esp+20h] [ebp-8h]
  ItemStruct *v9; // [esp+24h] [ebp-4h]
  ItemStruct *v10; // [esp+24h] [ebp-4h]
  ItemStruct *v11; // [esp+24h] [ebp-4h]

  v9 = plr[p].InvBody;
  v6 = 7;
  while ( 1 )
  {
    v1 = v6--;
    if ( !v1 )
      break;
    v9->_itype = -1;
    ++v9;
  }
  memset(plr[p].InvGrid, 0, 0x28u);
  v10 = plr[p].InvList;
  v7 = 40;
  while ( 1 )
  {
    v2 = v7--;
    if ( !v2 )
      break;
    v10->_itype = -1;
    ++v10;
  }
  plr[p]._pNumInv = 0;
  v11 = plr[p].SpdList;
  v8 = 8;
  while ( 1 )
  {
    v3 = v8--;
    if ( !v3 )
      break;
    v11->_itype = -1;
    ++v11;
  }
  v4 = plr[p]._pClass;
  if ( plr[p]._pClass )
  {
    if ( v4 == 1 )
    {
      SetPlrHandItem(&plr[p].InvBody[4], 4);
      GetPlrHandSeed(&plr[p].InvBody[4]);
      SetPlrHandItem(plr[p].SpdList, 11);
      GetPlrHandSeed(plr[p].SpdList);
      SetPlrHandItem(&plr[p].SpdList[1], 11);
      GetPlrHandSeed(&plr[p].SpdList[1]);
    }
    else if ( v4 == 2 )
    {
      SetPlrHandItem(&plr[p].InvBody[4], 5);
      GetPlrHandSeed(&plr[p].InvBody[4]);
      SetPlrHandItem(plr[p].SpdList, 12);
      GetPlrHandSeed(plr[p].SpdList);
      SetPlrHandItem(&plr[p].SpdList[1], 12);
      GetPlrHandSeed(&plr[p].SpdList[1]);
    }
  }
  else
  {
    SetPlrHandItem(&plr[p].InvBody[4], 1);
    GetPlrHandSeed(&plr[p].InvBody[4]);
    SetPlrHandItem(&plr[p].InvBody[5], 2);
    GetPlrHandSeed(&plr[p].InvBody[5]);
    SetPlrHandItem(&plr[p].HoldItem, 3);
    GetPlrHandSeed(&plr[p].HoldItem);
    AutoPlace(p, 0, 1, 3, 1);
    SetPlrHandItem(plr[p].SpdList, 11);
    GetPlrHandSeed(plr[p].SpdList);
    SetPlrHandItem(&plr[p].SpdList[1], 11);
    GetPlrHandSeed(&plr[p].SpdList[1]);
  }
  SetPlrHandItem(&plr[p].HoldItem, 0);
  GetPlrHandSeed(&plr[p].HoldItem);
  plr[p].HoldItem._ivalue = 100;
  plr[p].HoldItem._iCurs = 4;
  plr[p]._pGold = plr[p].HoldItem._ivalue;
  qmemcpy(&plr[p].InvList[plr[p]._pNumInv++], &plr[p].HoldItem, sizeof(plr[p].InvList[plr[p]._pNumInv++]));
  plr[p].InvGrid[30] = plr[p]._pNumInv;
  CalcPlrItemVals(p, 0);
}

//----- (00422D64) --------------------------------------------------------
BOOL __fastcall ItemSpaceOk(int i, int j)
{
  int v3; // [esp+14h] [ebp-8h]

  if ( i < 0 || i >= 112 || j < 0 || j >= 112 )
    return 0;
  if ( dMonster[i][j] )
    return 0;
  if ( dPlayer[i][j] )
    return 0;
  if ( dItem[i][j] )
    return 0;
  if ( dObject[i][j] )
  {
    v3 = dObject[i][j] <= 0 ? -(dObject[i][j] + 1) : dObject[i][j] - 1;
    if ( object[v3]._oSolidFlag )
      return 0;
  }
  if ( dObject[i + 1][j + 1] > 0 && object[dObject[i + 1][j + 1] - 1]._oSelFlag )
    return 0;
  if ( dObject[i + 1][j + 1] < 0 && object[-(dObject[i + 1][j + 1] + 1)]._oSelFlag )
    return 0;
  if ( dObject[i + 1][j] > 0
    && dObject[i][j + 1] > 0
    && object[dObject[i + 1][j] - 1]._oSelFlag
    && object[dObject[i][j + 1] - 1]._oSelFlag )
  {
    return 0;
  }
  return nSolidTable[dPiece[i][j]] == 0;
}

//----- (00423066) --------------------------------------------------------
BOOL __fastcall GetItemSpace(int x, int y, char inum)
{
  int v4; // ST14_4
  int v5; // ST24_4
  int v8; // [esp+14h] [ebp-18h]
  signed int l; // [esp+14h] [ebp-18h]
  int v10; // [esp+14h] [ebp-18h]
  int j; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  signed int v13; // [esp+20h] [ebp-Ch]
  int v14; // [esp+24h] [ebp-8h]
  signed int k; // [esp+24h] [ebp-8h]
  int v16; // [esp+24h] [ebp-8h]
  int v17; // [esp+28h] [ebp-4h]

  v14 = 0;
  for ( j = y - 1; y + 1 >= j; ++j )
  {
    v8 = 0;
    for ( i = x - 1; x + 1 >= i; ++i )
      itemhold[v8++][v14] = ItemSpaceOk(i, j);
    ++v14;
  }
  v13 = 0;
  for ( k = 0; k < 3; ++k )
  {
    for ( l = 0; l < 3; ++l )
    {
      if ( itemhold[l][k] )
        v13 = 1;
    }
  }
  v17 = random(13, 15) + 1;
  if ( !v13 )
    return 0;
  v10 = 0;
  v16 = 0;
  while ( v17 > 0 )
  {
    if ( itemhold[v10][v16] )
      --v17;
    if ( v17 > 0 && ++v10 == 3 )
    {
      v10 = 0;
      if ( ++v16 == 3 )
        v16 = 0;
    }
  }
  v4 = x - 1 + v10;
  v5 = y - 1 + v16;
  item[inum]._ix = v4;
  item[inum]._iy = v5;
  dItem[v4][v5] = inum + 1;
  return 1;
}

//----- (00423248) --------------------------------------------------------
void __fastcall GetSuperItemSpace(int x, int y, char inum)
{
  int m; // [esp+14h] [ebp-14h]
  int l; // [esp+18h] [ebp-10h]
  int i; // [esp+1Ch] [ebp-Ch]
  signed int k; // [esp+20h] [ebp-8h]
  int j; // [esp+24h] [ebp-4h]

  if ( !GetItemSpace(x, y, inum) )
  {
    for ( k = 2; k < 50; ++k )
    {
      for ( l = -k; l <= k; ++l )
      {
        j = y + l;
        for ( m = -k; k >= m; ++m )
        {
          i = m + x;
          if ( ItemSpaceOk(m + x, j) )
          {
            item[inum]._ix = i;
            item[inum]._iy = j;
            dItem[i][j] = inum + 1;
            return;
          }
        }
      }
    }
  }
}

//----- (0042335A) --------------------------------------------------------
void __fastcall CalcItemValue(int i)
{
  int v1; // [esp+10h] [ebp-4h]
  int v2; // [esp+10h] [ebp-4h]

  v1 = item[i]._iVMult1 + item[i]._iVMult2;
  if ( v1 > 0 )
    v1 *= item[i]._ivalue;
  if ( v1 < 0 )
    v1 = item[i]._ivalue / v1;
  v2 = item[i]._iVAdd1 + item[i]._iVAdd2 + v1;
  if ( v2 < 0 )
    v2 = 0;
  item[i]._iIvalue = v2;
}

//----- (00423434) --------------------------------------------------------
void __fastcall GetBookSpell(int i, int lvl)
{
  int v4; // [esp+14h] [ebp-Ch]
  signed int v5; // [esp+18h] [ebp-8h]
  int v6; // [esp+1Ch] [ebp-4h]

  if ( !lvl )
    lvl = 1;
  v4 = random(14, 37) + 1;
  v5 = 1;
  while ( v4 > 0 )
  {
    if ( spelldata[v5].sBookLvl != -1 && spelldata[v5].sBookLvl <= lvl )
    {
      --v4;
      v6 = v5;
    }
    ++v5;
    if ( gbMaxPlayers == 1 && v5 == 32 )
      v5 = 33;
    if ( gbMaxPlayers == 1 && v5 == 34 )
      v5 = 35;
    if ( v5 == 37 )
      v5 = 1;
  }
  strcat(item[i]._iName, spelldata[v6].sNameText);
  strcat(item[i]._iIName, spelldata[v6].sNameText);
  item[i]._iSpell = v6;
  item[i]._iMinMag = spelldata[v6].sTownSpell;
  item[i]._ivalue += 1000 * spelldata[v6].sBookLvl;
  item[i]._iIvalue += 1000 * spelldata[v6].sBookLvl;
}

//----- (004235F6) --------------------------------------------------------
void __fastcall GetStaffPower(int i, int lvl, int bs, unsigned __int8 onlygood)
{
  int v6[256]; // [esp+18h] [ebp-494h]
  int v; // [esp+418h] [ebp-94h]
  int j; // [esp+41Ch] [ebp-90h]
  int v9; // [esp+420h] [ebp-8Ch]
  char v10; // [esp+424h] [ebp-88h]
  int v11; // [esp+4A4h] [ebp-8h]
  int v12; // [esp+4A8h] [ebp-4h]

  v9 = -1;
  if ( !random(15, 10) || onlygood )
  {
    v = 0;
    for ( j = 0; PL_Prefix[j].PLPower != -1; ++j )
    {
      if ( PL_Prefix[j].PLIType & 0x100 && (char)PL_Prefix[j].PLMinLvl <= lvl )
      {
        v12 = 1;
        if ( onlygood && !PL_Prefix[j].PLOk )
          v12 = 0;
        if ( v12 )
        {
          v6[v++] = j;
          if ( PL_Prefix[j].PLDouble )
            v6[v++] = j;
        }
      }
    }
    if ( v )
    {
      v9 = v6[random(16, v)];
      sprintf(&v10, "%s %s", PL_Prefix[v9].PLName, item[i]._iIName);
      strcpy(item[i]._iIName, &v10);
      item[i]._iMagical = 1;
      SaveItemPower(
        i,
        PL_Prefix[v9].PLPower,
        PL_Prefix[v9].PLParam1,
        PL_Prefix[v9].PLParam2,
        PL_Prefix[v9].PLMinVal,
        PL_Prefix[v9].PLMaxVal,
        PL_Prefix[v9].PLMultVal);
      item[i]._iPrePower = PL_Prefix[v9].PLPower;
    }
  }
  if ( !control_WriteStringToBuffer(item[i]._iIName) )
  {
    v11 = item[i].IDidx;
    strcpy(item[i]._iIName, AllItemsList[v11].iSName);
    if ( v9 != -1 )
    {
      sprintf(&v10, "%s %s", PL_Prefix[v9].PLName, item[i]._iIName);
      strcpy(item[i]._iIName, &v10);
    }
    sprintf(&v10, "%s of %s", item[i]._iIName, spelldata[bs].sNameText);
    strcpy(item[i]._iIName, &v10);
    if ( !item[i]._iMagical )
      strcpy(item[i]._iName, item[i]._iIName);
  }
  CalcItemValue(i);
}

//----- (00423A3F) --------------------------------------------------------
void __fastcall GetStaffSpell(int i, int lvl, unsigned __int8 onlygood)
{
  int v3; // eax
  char v6; // [esp+14h] [ebp-50h]
  int v7; // [esp+54h] [ebp-10h]
  int v; // [esp+58h] [ebp-Ch]
  int v9; // [esp+5Ch] [ebp-8h]
  int bs; // [esp+60h] [ebp-4h]

  if ( random(17, 4) )
  {
    v7 = lvl >> 1;
    if ( !(lvl >> 1) )
      v7 = 1;
    v = random(18, 37) + 1;
    v9 = 1;
    while ( v > 0 )
    {
      if ( spelldata[v9].sStaffLvl != -1 && spelldata[v9].sStaffLvl <= v7 )
      {
        --v;
        bs = v9;
      }
      ++v9;
      if ( gbMaxPlayers == 1 && v9 == 32 )
        v9 = 33;
      if ( gbMaxPlayers == 1 && v9 == 34 )
        v9 = 35;
      if ( v9 == 37 )
        v9 = 1;
    }
    sprintf(&v6, "%s of %s", item[i]._iName, spelldata[bs].sNameText);
    strcpy(item[i]._iName, &v6);
    strcpy(item[i]._iIName, &v6);
    item[i]._iSpell = bs;
    v = 2 * abs(spelldata[bs].sStaffLvl - v7);
    if ( v < 3 )
      v = 3;
    v3 = random(19, v);
    item[i]._iCharges = v3 + v;
    item[i]._iMaxCharges = item[i]._iCharges;
    item[i]._iMinMag = spelldata[bs].sTownSpell;
    item[i]._ivalue += 500 * spelldata[bs].sStaffLvl;
    item[i]._iIvalue += 500 * spelldata[bs].sStaffLvl;
    GetStaffPower(i, lvl, bs, onlygood);
  }
  else
  {
    GetItemPower(i, lvl >> 1, lvl, 256, onlygood);
  }
}

//----- (00423CF6) --------------------------------------------------------
void __fastcall GetOilMagic(int i, int lvl)
{
  int v; // [esp+14h] [ebp-30h]
  signed int j; // [esp+1Ch] [ebp-28h]
  char v6[32]; // [esp+20h] [ebp-24h]
  int v7; // [esp+40h] [ebp-4h]

  if ( gbMaxPlayers == 1 )
  {
    if ( !lvl )
      lvl = 1;
    v = 0;
    for ( j = 0; j < 10; ++j )
    {
      if ( oil_4C3328[j] <= lvl )
        v6[v++] = j;
    }
    v7 = v6[random(165, v)];
  }
  else if ( random(165, 2) )
  {
    v7 = 6;
  }
  else
  {
    v7 = 5;
  }
  strcpy(item[i]._iName, Xoil_names[v7]);
  strcpy(item[i]._iIName, Xoil_names[v7]);
  item[i]._iMiscId = oil_4C3378_id[v7];
  item[i]._ivalue = oil_4C3350_ivalue[v7];
  item[i]._iIvalue = oil_4C3350_ivalue[v7];
}

//----- (00423E7C) --------------------------------------------------------
void __fastcall GetItemAttrs(int i, int idata, int lvl)
{
  int v5; // [esp+14h] [ebp-4h]

  item[i]._itype = AllItemsList[idata].itype;
  item[i]._iCurs = AllItemsList[idata].iCurs;
  strcpy(item[i]._iName, AllItemsList[idata].iName);
  strcpy(item[i]._iIName, AllItemsList[idata].iName);
  item[i]._iLoc = AllItemsList[idata].iLoc;
  item[i]._iClass = AllItemsList[idata].iClass;
  item[i]._iMinDam = AllItemsList[idata].iMinDam;
  item[i]._iMaxDam = AllItemsList[idata].iMaxDam;
  item[i]._iAC = random(20, AllItemsList[idata].iMaxAC - AllItemsList[idata].iMinAC + 1) + AllItemsList[idata].iMinAC;
  item[i]._iFlags = AllItemsList[idata].iFlags;
  item[i]._iMiscId = AllItemsList[idata].iMiscId;
  item[i]._iSpell = AllItemsList[idata].iSpell;
  item[i]._iMagical = 0;
  item[i]._ivalue = AllItemsList[idata].iValue;
  item[i]._iIvalue = AllItemsList[idata].iValue;
  item[i]._iVAdd1 = 0;
  item[i]._iVMult1 = 0;
  item[i]._iVAdd2 = 0;
  item[i]._iVMult2 = 0;
  item[i]._iPLDam = 0;
  item[i]._iPLToHit = 0;
  item[i]._iPLAC = 0;
  item[i]._iPLStr = 0;
  item[i]._iPLMag = 0;
  item[i]._iPLDex = 0;
  item[i]._iPLVit = 0;
  item[i]._iCharges = 0;
  item[i]._iMaxCharges = 0;
  item[i]._iDurability = AllItemsList[idata].iDurability;
  item[i]._iMaxDur = AllItemsList[idata].iDurability;
  item[i]._iMinStr = AllItemsList[idata].iMinStr;
  item[i]._iMinMag = AllItemsList[idata].iMinMag;
  item[i]._iMinDex = AllItemsList[idata].iMinDex;
  item[i]._iPLFR = 0;
  item[i]._iPLLR = 0;
  item[i]._iPLMR = 0;
  item[i].IDidx = idata;
  item[i]._iPLDamMod = 0;
  item[i]._iPLGetHit = 0;
  item[i]._iPLLight = 0;
  item[i]._iSplLvlAdd = 0;
  item[i]._pISplCost = 0;
  item[i]._pISplDur = 0;
  item[i]._iFMinDam = 0;
  item[i]._iFMaxDam = 0;
  item[i]._iLMinDam = 0;
  item[i]._iLMaxDam = 0;
  item[i]._iPLEnAc = 0;
  item[i]._iPLMana = 0;
  item[i]._iPLHP = 0;
  item[i]._iPrePower = -1;
  item[i]._iSufPower = -1;
  if ( item[i]._iMiscId == 24 )
    GetBookSpell(i, lvl);
  if ( item[i]._iMiscId == 30 )
    GetOilMagic(i, lvl);
  if ( item[i]._itype == 11 )
  {
    v5 = 5 * currlevel + random(21, 10 * currlevel);
    item[i]._ivalue = v5;
    if ( v5 < 2500 )
    {
      if ( v5 > 1000 )
        item[i]._iCurs = 5;
      else
        item[i]._iCurs = 4;
    }
    else
    {
      item[i]._iCurs = 6;
    }
  }
}

//----- (004245D4) --------------------------------------------------------
int __fastcall RndPL(int param1, int param2)
{
  return param1 + random(22, param2 - param1 + 1);
}

//----- (00424603) --------------------------------------------------------
int __fastcall PLVal(int pv, int p1, int p2, int minv, int maxv)
{
  if ( p2 == p1 )
    return minv;
  if ( minv == maxv )
    return minv;
  return minv + (maxv - minv) * (100 * (pv - p1) / (p2 - p1)) / 100;
}

//----- (00424672) --------------------------------------------------------
void __fastcall SaveItemPower(int i, int power, int param1, int param2, int minval, int maxval, int multval)
{
  int v7; // ST28_4
  int pv; // [esp+18h] [ebp-8h]
  int v11; // [esp+1Ch] [ebp-4h]

  pv = RndPL(param1, param2);
  switch ( power )
  {
    case 0:
      item[i]._iPLToHit += pv;
      break;
    case 1:
      item[i]._iPLToHit -= pv;
      break;
    case 2:
      item[i]._iPLDam += pv;
      break;
    case 3:
      item[i]._iPLDam -= pv;
      break;
    case 4:
      pv = RndPL(param1, param2);
      item[i]._iPLDam += pv;
      if ( param1 == 25 )
        v11 = RndPL(1, 5);
      if ( param1 == 50 )
        v11 = RndPL(6, 10);
      if ( param1 == 75 )
        v11 = RndPL(11, 15);
      if ( param1 == 100 )
        v11 = RndPL(16, 25);
      if ( param1 == 150 )
        v11 = RndPL(26, 40);
      if ( param1 == 200 )
        v11 = RndPL(41, 60);
      if ( param1 == 250 )
        v11 = RndPL(61, 100);
      item[i]._iPLToHit += v11;
      break;
    case 5:
      item[i]._iPLDam -= pv;
      if ( param1 == 25 )
        v11 = RndPL(1, 5);
      if ( param1 == 50 )
        v11 = RndPL(6, 10);
      item[i]._iPLToHit -= v11;
      break;
    case 6:
      item[i]._iPLAC += pv;
      break;
    case 7:
      item[i]._iPLAC -= pv;
      break;
    case 8:
      item[i]._iPLFR += pv;
      break;
    case 9:
      item[i]._iPLLR += pv;
      break;
    case 10:
      item[i]._iPLMR += pv;
      break;
    case 11:
      item[i]._iPLFR += pv;
      item[i]._iPLLR += pv;
      item[i]._iPLMR += pv;
      break;
    case 12:
      item[i]._pISplCost = pv;
      break;
    case 13:
      item[i]._pISplDur = pv;
      break;
    case 14:
      item[i]._iSplLvlAdd = pv;
      break;
    case 15:
      item[i]._iCharges *= param1;
      item[i]._iMaxCharges = item[i]._iCharges;
      break;
    case 16:
      item[i]._iFlags |= 0x10u;
      item[i]._iFMinDam = param1;
      item[i]._iFMaxDam = param2;
      break;
    case 17:
      item[i]._iFlags |= 0x20u;
      item[i]._iLMinDam = param1;
      item[i]._iLMaxDam = param2;
      break;
    case 19:
      item[i]._iPLStr += pv;
      break;
    case 20:
      item[i]._iPLStr -= pv;
      break;
    case 21:
      item[i]._iPLMag += pv;
      break;
    case 22:
      item[i]._iPLMag -= pv;
      break;
    case 23:
      item[i]._iPLDex += pv;
      break;
    case 24:
      item[i]._iPLDex -= pv;
      break;
    case 25:
      item[i]._iPLVit += pv;
      break;
    case 26:
      item[i]._iPLVit -= pv;
      break;
    case 27:
      item[i]._iPLStr += pv;
      item[i]._iPLMag += pv;
      item[i]._iPLDex += pv;
      item[i]._iPLVit += pv;
      break;
    case 28:
      item[i]._iPLStr -= pv;
      item[i]._iPLMag -= pv;
      item[i]._iPLDex -= pv;
      item[i]._iPLVit -= pv;
      break;
    case 29:
      item[i]._iPLGetHit += pv;
      break;
    case 30:
      item[i]._iPLGetHit -= pv;
      break;
    case 31:
      item[i]._iPLHP += pv << 6;
      break;
    case 32:
      item[i]._iPLHP -= pv << 6;
      break;
    case 33:
      item[i]._iPLMana += pv << 6;
      drawmanaflag = 1;
      break;
    case 34:
      item[i]._iPLMana -= pv << 6;
      drawmanaflag = 1;
      break;
    case 35:
      v7 = pv * item[i]._iMaxDur / 100;
      item[i]._iMaxDur += v7;
      item[i]._iDurability += v7;
      break;
    case 36:
      item[i]._iMaxDur -= pv * item[i]._iMaxDur / 100;
      if ( item[i]._iMaxDur < 1 )
        item[i]._iMaxDur = 1;
      item[i]._iDurability = item[i]._iMaxDur;
      break;
    case 37:
      item[i]._iDurability = 1000;
      item[i]._iMaxDur = 1000;
      break;
    case 38:
      item[i]._iPLLight += param1;
      break;
    case 39:
      item[i]._iPLLight -= param1;
      break;
    case 42:
      pv = RndPL(param1, param2);
      item[i]._iFlags |= 8u;
      item[i]._iFMaxDam += pv;
      break;
    case 43:
      pv = RndPL(param1, param2);
      item[i]._iFlags |= 0x2000000u;
      item[i]._iLMaxDam += pv;
      break;
    case 44:
      item[i]._iCurs = param1;
      break;
    case 45:
      item[i]._iFlags |= 0x4000000u;
      break;
    case 46:
      item[i]._iFlags |= 0x8000000u;
      drawmanaflag = 1;
      break;
    case 47:
      item[i]._iFlags |= 0x100u;
      break;
    case 52:
      item[i]._iFlags |= 0x10000000u;
      break;
    case 53:
      item[i]._iFlags |= 0x800u;
      break;
    case 54:
      item[i]._iFlags |= 0x1000u;
      break;
    case 55:
      if ( param1 == 5 )
        item[i]._iFlags |= 0x2000u;
      if ( param1 == 10 )
        item[i]._iFlags |= 0x4000u;
      drawmanaflag = 1;
      break;
    case 56:
      if ( param1 == 5 )
        item[i]._iFlags |= 0x8000u;
      if ( param1 == 10 )
        item[i]._iFlags |= 0x10000u;
      drawhpflag = 1;
      break;
    case 57:
      break;
    case 58:
      if ( param1 == 1 )
        item[i]._iFlags |= 0x20000u;
      if ( param1 == 2 )
        item[i]._iFlags |= 0x40000u;
      if ( param1 == 3 )
        item[i]._iFlags |= 0x80000u;
      if ( param1 == 4 )
        item[i]._iFlags |= 0x100000u;
      break;
    case 59:
      if ( param1 == 1 )
        item[i]._iFlags |= 0x200000u;
      if ( param1 == 2 )
        item[i]._iFlags |= 0x400000u;
      if ( param1 == 3 )
        item[i]._iFlags |= 0x800000u;
      break;
    case 60:
      item[i]._iFlags |= 0x1000000u;
      break;
    case 61:
      item[i]._iPLDamMod += pv;
      break;
    case 62:
      item[i]._iFlags |= 4u;
      break;
    case 63:
      item[i]._iMinDam = param1;
      item[i]._iMaxDam = param2;
      break;
    case 64:
      item[i]._iDurability = param1;
      item[i]._iMaxDur = param1;
      break;
    case 65:
      item[i]._iMinStr = 0;
      break;
    case 66:
      item[i]._iSpell = param1;
      item[i]._iCharges = param1;
      item[i]._iMaxCharges = param2;
      break;
    case 67:
      item[i]._iFlags |= 0x80000u;
      break;
    case 68:
      item[i]._iLoc = 1;
      break;
    case 69:
      item[i]._iFlags |= 0x40000000u;
      break;
    case 70:
      item[i]._iFlags |= 0x80000000;
      break;
    case 72:
      item[i]._iFlags |= 0x40u;
      break;
    case 73:
      item[i]._iFlags |= 2u;
      break;
    case 74:
      item[i]._iFlags |= 1u;
      break;
    case 75:
      item[i]._iAC = pv;
      break;
  }
  if ( item[i]._iVAdd1 || item[i]._iVMult1 )
  {
    item[i]._iVAdd2 = PLVal(pv, param1, param2, minval, maxval);
    item[i]._iVMult2 = multval;
  }
  else
  {
    item[i]._iVAdd1 = PLVal(pv, param1, param2, minval, maxval);
    item[i]._iVMult1 = multval;
  }
}

//----- (004255C2) --------------------------------------------------------
void __fastcall GetItemPower(int i, int minlvl, int maxlvl, int flgs, int onlygood)
{
  int v7; // [esp+14h] [ebp-4A0h]
  int v8[256]; // [esp+18h] [ebp-49Ch]
  int v; // [esp+418h] [ebp-9Ch]
  int j; // [esp+41Ch] [ebp-98h]
  int v11; // [esp+420h] [ebp-94h]
  int v12; // [esp+424h] [ebp-90h]
  unsigned __int8 v13; // [esp+428h] [ebp-8Ch]
  char v14; // [esp+42Ch] [ebp-88h]
  int v15; // [esp+4ACh] [ebp-8h]
  int v16; // [esp+4B0h] [ebp-4h]

  v7 = random(23, 4);
  v16 = random(23, 3);
  if ( v7 && !v16 )
  {
    if ( random(23, 2) )
      v16 = 1;
    else
      v7 = 0;
  }
  v11 = -1;
  v12 = -1;
  v13 = 0;
  if ( !onlygood && random(0, 3) )
    onlygood = 1;
  if ( !v7 )
  {
    v = 0;
    for ( j = 0; PL_Prefix[j].PLPower != -1; ++j )
    {
      if ( PL_Prefix[j].PLIType & flgs
        && (char)PL_Prefix[j].PLMinLvl >= minlvl
        && (char)PL_Prefix[j].PLMinLvl <= maxlvl
        && (!onlygood || PL_Prefix[j].PLOk) )
      {
        v8[v++] = j;
        if ( PL_Prefix[j].PLDouble )
          v8[v++] = j;
      }
    }
    if ( v )
    {
      v11 = v8[random(23, v)];
      sprintf(&v14, "%s %s", PL_Prefix[v11].PLName, item[i]._iIName);
      strcpy(item[i]._iIName, &v14);
      item[i]._iMagical = 1;
      SaveItemPower(
        i,
        PL_Prefix[v11].PLPower,
        PL_Prefix[v11].PLParam1,
        PL_Prefix[v11].PLParam2,
        PL_Prefix[v11].PLMinVal,
        PL_Prefix[v11].PLMaxVal,
        PL_Prefix[v11].PLMultVal);
      item[i]._iPrePower = PL_Prefix[v11].PLPower;
      v13 = PL_Prefix[v11].PLGOE;
    }
  }
  if ( v16 )
  {
    v = 0;
    for ( j = 0; PL_Suffix[j].PLPower != -1; ++j )
    {
      if ( PL_Suffix[j].PLIType & flgs
        && (char)PL_Suffix[j].PLMinLvl >= minlvl
        && (char)PL_Suffix[j].PLMinLvl <= maxlvl
        && (v13 | LOBYTE(PL_Suffix[j].PLGOE)) != 17
        && (!onlygood || PL_Suffix[j].PLOk) )
      {
        v8[v++] = j;
      }
    }
    if ( v )
    {
      v12 = v8[random(23, v)];
      sprintf(&v14, "%s of %s", item[i]._iIName, PL_Suffix[v12].PLName);
      strcpy(item[i]._iIName, &v14);
      item[i]._iMagical = 1;
      SaveItemPower(
        i,
        PL_Suffix[v12].PLPower,
        PL_Suffix[v12].PLParam1,
        PL_Suffix[v12].PLParam2,
        PL_Suffix[v12].PLMinVal,
        PL_Suffix[v12].PLMaxVal,
        PL_Suffix[v12].PLMultVal);
      item[i]._iSufPower = PL_Suffix[v12].PLPower;
    }
  }
  if ( !control_WriteStringToBuffer(item[i]._iIName) )
  {
    v15 = item[i].IDidx;
    strcpy(item[i]._iIName, AllItemsList[v15].iSName);
    if ( v11 != -1 )
    {
      sprintf(&v14, "%s %s", PL_Prefix[v11].PLName, item[i]._iIName);
      strcpy(item[i]._iIName, &v14);
    }
    if ( v12 != -1 )
    {
      sprintf(&v14, "%s of %s", item[i]._iIName, PL_Suffix[v12].PLName);
      strcpy(item[i]._iIName, &v14);
    }
  }
  CalcItemValue(i);
}

//----- (00425C9A) --------------------------------------------------------
void __fastcall GetItemBonus(int i, int idata, int minlvl, int maxlvl, int onlygood)
{
  if ( item[i]._iClass != 4 )
  {
    switch ( item[i]._itype )
    {
      case 1:
      case 2:
      case 4:
        GetItemPower(i, minlvl, maxlvl, 4096, onlygood);
        break;
      case 3:
        GetItemPower(i, minlvl, maxlvl, 16, onlygood);
        break;
      case 5:
        GetItemPower(i, minlvl, maxlvl, 0x10000, onlygood);
        break;
      case 6:
      case 7:
      case 8:
      case 9:
        GetItemPower(i, minlvl, maxlvl, 0x100000, onlygood);
        break;
      case 0xA:
        GetStaffSpell(i, maxlvl, onlygood);
        break;
      case 0xC:
      case 0xD:
        GetItemPower(i, minlvl, maxlvl, 1, onlygood);
        break;
      default:
        return;
    }
  }
}

//----- (00425DE4) --------------------------------------------------------
void __fastcall SetupItem(int i)
{
  int v1; // ST10_4

  v1 = ItemCAnimTbl[item[i]._iCurs];
  item[i]._iAnimData = (unsigned __int8 *)Item2Frm[v1];
  item[i]._iAnimLen = ItemAnimLs[v1];
  item[i]._iAnimFrame = 1;
  item[i]._iAnimFlag = 1;
  item[i]._isin = 0;
  item[i]._iAnimWidth = 96;
  item[i]._iAnimWidth2 = 16;
  item[i]._iSelFlag = 0;
  item[i]._iIdentified = 0;
  item[i]._iPostDraw = 0;
}

//----- (00425F13) --------------------------------------------------------
int __fastcall RndItem(int m)
{
  int v3[512]; // [esp+10h] [ebp-80Ch]
  int i; // [esp+810h] [ebp-Ch]
  int v; // [esp+814h] [ebp-8h]
  int v6; // [esp+818h] [ebp-4h]

  if ( ((monster[m].MData->mMagicRes2 >> 8) & 0x80u) != 0 )
    return -((monster[m].MData->mMagicRes2 & 0xFFF) + 1);
  if ( (monster[m].MData->mMagicRes2 >> 8) & 0x40 )
    return 0;
  v6 = random(24, 100);
  if ( v6 > 40 )
    return 0;
  if ( random(24, 100) > 25 )
    return 1;
  v = 0;
  for ( i = 0; AllItemsList[i].iLoc != -1; ++i )
  {
    if ( AllItemsList[i].iRnd == 2 && AllItemsList[i].iMinMLvl <= monster[m].mLevel )
      v3[v++] = i;
    if ( AllItemsList[i].iRnd && AllItemsList[i].iMinMLvl <= monster[m].mLevel )
      v3[v++] = i;
    if ( AllItemsList[i].iSpell == 32 && gbMaxPlayers == 1 )
      --v;
    if ( AllItemsList[i].iSpell == 34 && gbMaxPlayers == 1 )
      --v;
  }
  return v3[random(24, v)] + 1;
}

//----- (00426156) --------------------------------------------------------
int __fastcall RndUItem(int m)
{
  int v2[512]; // [esp+10h] [ebp-80Ch]
  int i; // [esp+810h] [ebp-Ch]
  int v; // [esp+814h] [ebp-8h]
  int v5; // [esp+818h] [ebp-4h]

  v = 0;
  for ( i = 0; AllItemsList[i].iLoc != -1; ++i )
  {
    v5 = 1;
    if ( !AllItemsList[i].iRnd )
      v5 = 0;
    if ( m == -1 )
    {
      if ( AllItemsList[i].iMinMLvl > 2 * currlevel )
        v5 = 0;
    }
    else if ( AllItemsList[i].iMinMLvl > monster[m].mLevel )
    {
      v5 = 0;
    }
    if ( !AllItemsList[i].itype )
      v5 = 0;
    if ( AllItemsList[i].itype == 11 )
      v5 = 0;
    if ( AllItemsList[i].itype == 14 )
      v5 = 0;
    if ( AllItemsList[i].iMiscId == 24 )
      v5 = 1;
    if ( AllItemsList[i].iSpell == 32 && gbMaxPlayers == 1 )
      v5 = 0;
    if ( AllItemsList[i].iSpell == 34 && gbMaxPlayers == 1 )
      v5 = 0;
    if ( v5 )
      v2[v++] = i;
  }
  return v2[random(25, v)];
}

//----- (0042635E) --------------------------------------------------------
int __cdecl RndAllItems()
{
  int v1[512]; // [esp+Ch] [ebp-80Ch]
  int i; // [esp+80Ch] [ebp-Ch]
  int v; // [esp+810h] [ebp-8h]

  if ( random(26, 100) > 25 )
    return 0;
  v = 0;
  for ( i = 0; AllItemsList[i].iLoc != -1; ++i )
  {
    if ( AllItemsList[i].iRnd && AllItemsList[i].iMinMLvl <= 2 * currlevel )
      v1[v++] = i;
    if ( AllItemsList[i].iSpell == 32 && gbMaxPlayers == 1 )
      --v;
    if ( AllItemsList[i].iSpell == 34 && gbMaxPlayers == 1 )
      --v;
  }
  return v1[random(26, v)];
}

//----- (0042648A) --------------------------------------------------------
int __fastcall RndTypeItems(int itype, int imid)
{
  int v3[512]; // [esp+14h] [ebp-80Ch]
  int i; // [esp+814h] [ebp-Ch]
  int v; // [esp+818h] [ebp-8h]
  int v6; // [esp+81Ch] [ebp-4h]

  v = 0;
  for ( i = 0; AllItemsList[i].iLoc != -1; ++i )
  {
    v6 = 1;
    if ( !AllItemsList[i].iRnd )
      v6 = 0;
    if ( AllItemsList[i].iMinMLvl > 2 * currlevel )
      v6 = 0;
    if ( AllItemsList[i].itype != itype )
      v6 = 0;
    if ( imid != -1 && AllItemsList[i].iMiscId != imid )
      v6 = 0;
    if ( v6 )
      v3[v++] = i;
  }
  return v3[random(27, v)];
}

//----- (004265BC) --------------------------------------------------------
int __fastcall CheckUnique(int i, int lvl, int uper, bool recreate)
{
  int j; // [esp+18h] [ebp-8Ch]
  int v8; // [esp+18h] [ebp-8Ch]
  int v9; // [esp+1Ch] [ebp-88h]
  char v10[128]; // [esp+20h] [ebp-84h]
  int v11; // [esp+A0h] [ebp-4h]

  if ( random(28, 100) > uper )
    return -1;
  v9 = 0;
  memset(v10, 0, 0x80u);
  for ( j = 0; UniqueItemList[j].UIItemId != -1; ++j )
  {
    if ( AllItemsList[item[i].IDidx].iItemId == UniqueItemList[j].UIItemId
      && UniqueItemList[j].UIMinLvl <= lvl
      && (recreate || !UniqueItemFlag[j] || gbMaxPlayers != 1) )
    {
      v10[j] = 1;
      ++v9;
    }
  }
  if ( !v9 )
    return -1;
  v11 = random(29, 10);
  v8 = 0;
  while ( v9 > 0 )
  {
    if ( v10[v8] )
      --v9;
    if ( v9 > 0 && ++v8 == 128 )
      v8 = 0;
  }
  return v8;
}

//----- (004267B4) --------------------------------------------------------
void __fastcall GetUniqueItem(int i, int uid)
{
  UniqueItemFlag[uid] = 1;
  SaveItemPower(i, UniqueItemList[uid].UIPower1, UniqueItemList[uid].UIParam1, UniqueItemList[uid].UIParam2, 0, 0, 1);
  if ( UniqueItemList[uid].UINumPL > 1 )
    SaveItemPower(i, UniqueItemList[uid].UIPower2, UniqueItemList[uid].UIParam3, UniqueItemList[uid].UIParam4, 0, 0, 1);
  if ( UniqueItemList[uid].UINumPL > 2 )
    SaveItemPower(i, UniqueItemList[uid].UIPower3, UniqueItemList[uid].UIParam5, UniqueItemList[uid].UIParam6, 0, 0, 1);
  if ( UniqueItemList[uid].UINumPL > 3 )
    SaveItemPower(i, UniqueItemList[uid].UIPower4, UniqueItemList[uid].UIParam7, UniqueItemList[uid].UIParam8, 0, 0, 1);
  if ( UniqueItemList[uid].UINumPL > 4 )
    SaveItemPower(i, UniqueItemList[uid].UIPower5, UniqueItemList[uid].UIParam9, UniqueItemList[uid].UIParam10, 0, 0, 1);
  if ( UniqueItemList[uid].UINumPL > 5 )
    SaveItemPower(
      i,
      UniqueItemList[uid].UIPower6,
      UniqueItemList[uid].UIParam11,
      UniqueItemList[uid].UIParam12,
      0,
      0,
      1);
  strcpy(item[i]._iIName, UniqueItemList[uid].UIName);
  item[i]._ivalue = UniqueItemList[uid].UIValue;
  item[i]._iIvalue = item[i]._ivalue;
  item[i]._iPrePower = uid;
  item[i]._iMagical = 2;
}

//----- (00426ABE) --------------------------------------------------------
void __fastcall SpawnUnique(int uid, int x, int y)
{
  int idata; // [esp+14h] [ebp-8h]
  int inum; // [esp+18h] [ebp-4h]

  if ( numitems < 127 )
  {
    inum = itemavail[0];
    GetSuperItemSpace(x, y, itemavail[0]);
    itemavail[0] = itemavail[127 - numitems - 1];
    itemactive[numitems] = inum;
    for ( idata = 0; UniqueItemList[uid].UIItemId != AllItemsList[idata].iItemId; ++idata )
      ;
    GetItemAttrs(inum, idata, currlevel);
    GetUniqueItem(inum, uid);
    SetupItem(inum);
    ++numitems;
  }
}

//----- (00426B8D) --------------------------------------------------------
void __fastcall ItemRndDur(int ii)
{
  if ( item[ii]._iDurability )
  {
    if ( item[ii]._iDurability != 1000 )
      item[ii]._iDurability = (item[ii]._iMaxDur >> 2) + random(0, item[ii]._iMaxDur >> 1) + 1;
  }
}

//----- (00426C33) --------------------------------------------------------
void __fastcall SetupAllItems(int ii, int idx, int iseed, int lvl, int uper, int onlygood, int recreate, int pregen)
{
  int maxlvl; // [esp+14h] [ebp-8h]
  int uid; // [esp+18h] [ebp-4h]

  item[ii]._iSeed = iseed;
  SetRndSeed(iseed);
  GetItemAttrs(ii, idx, lvl >> 1);
  item[ii]._iCreateInfo = lvl;
  if ( pregen )
    item[ii]._iCreateInfo |= 0x8000u;
  if ( onlygood )
    item[ii]._iCreateInfo |= 0x40u;
  if ( uper == 15 )
  {
    item[ii]._iCreateInfo |= 0x80u;
  }
  else if ( uper == 1 )
  {
    item[ii]._iCreateInfo |= 0x100u;
  }
  if ( item[ii]._iMiscId == 27 )
  {
    item[ii]._iIdentified = 1;
  }
  else
  {
    maxlvl = -1;
    if ( random(32, 100) > 10 )
    {
      if ( random(33, 100) <= lvl )
        maxlvl = lvl;
    }
    else
    {
      maxlvl = lvl;
    }
    if ( maxlvl == -1 && item[ii]._iMiscId == 23 )
      maxlvl = lvl;
    if ( maxlvl == -1 && item[ii]._iMiscId == 25 )
      maxlvl = lvl;
    if ( maxlvl == -1 && item[ii]._iMiscId == 26 )
      maxlvl = lvl;
    if ( onlygood )
      maxlvl = lvl;
    if ( uper == 15 )
      maxlvl = 2 * lvl;
    if ( maxlvl != -1 )
    {
      uid = CheckUnique(ii, maxlvl, uper, recreate);
      if ( uid == -1 )
      {
        GetItemBonus(ii, idx, maxlvl >> 1, maxlvl, onlygood);
      }
      else
      {
        GetUniqueItem(ii, uid);
        item[ii]._iCreateInfo |= 0x200u;
      }
    }
    if ( item[ii]._iMagical != 2 )
      ItemRndDur(ii);
  }
  SetupItem(ii);
}

//----- (00426F5E) --------------------------------------------------------
void __fastcall SpawnItem(int m, int x, int y, unsigned __int8 sendmsg)
{
  int v4; // ST04_4
  int v5; // eax
  int v6; // ST04_4
  int v7; // eax
  int onlygood; // [esp+14h] [ebp-Ch]
  int inum; // [esp+18h] [ebp-8h]
  int idx; // [esp+1Ch] [ebp-4h]
  int idxa; // [esp+1Ch] [ebp-4h]

  if ( monster[m]._uniqtype || ((monster[m].MData->mMagicRes2 >> 8) & 0x80u) != 0 && gbMaxPlayers != 1 )
  {
    idx = RndUItem(m);
    onlygood = 1;
  }
  else
  {
    idxa = RndItem(m);
    if ( !idxa )
      return;
    if ( idxa <= 0 )
    {
      SpawnUnique(-(idxa + 1), x, y);
      return;
    }
    idx = idxa - 1;
    onlygood = 0;
  }
  if ( numitems < 127 )
  {
    inum = itemavail[0];
    GetSuperItemSpace(x, y, itemavail[0]);
    itemavail[0] = itemavail[127 - numitems - 1];
    itemactive[numitems] = inum;
    if ( monster[m]._uniqtype )
    {
      v4 = monster[m].MData->mLevel;
      v5 = GetRndSeed();
      SetupAllItems(inum, idx, v5, v4, 15, onlygood, 0, 0);
    }
    else
    {
      v6 = monster[m].MData->mLevel;
      v7 = GetRndSeed();
      SetupAllItems(inum, idx, v7, v6, 1, onlygood, 0, 0);
    }
    ++numitems;
    if ( sendmsg )
      NetSendCmdDItem(0, inum);
  }
}

//----- (0042711D) --------------------------------------------------------
void __fastcall CreateItem(int uid, int x, int y)
{
  int i; // [esp+14h] [ebp-8h]
  int idata; // [esp+18h] [ebp-4h]

  if ( numitems < 127 )
  {
    i = itemavail[0];
    itemavail[0] = itemavail[127 - numitems - 1];
    itemactive[numitems] = i;
    item[i]._ix = x;
    item[i]._iy = y;
    dItem[x][y] = i + 1;
    for ( idata = 0; AllItemsList[idata].iItemId != UniqueItemList[uid].UIItemId; ++idata )
      ;
    GetItemAttrs(i, idata, currlevel);
    GetUniqueItem(i, uid);
    SetupItem(i);
    item[i]._iMagical = 2;
    ++numitems;
  }
}

//----- (0042723B) --------------------------------------------------------
void __fastcall CreateRndItem(int x, int y, unsigned __int8 onlygood, unsigned __int8 sendmsg, int delta)
{
  int v5; // ST04_4
  int v6; // eax
  int inum; // [esp+14h] [ebp-8h]
  int idx; // [esp+18h] [ebp-4h]

  if ( onlygood )
    idx = RndUItem(-1);
  else
    idx = RndAllItems();
  if ( numitems < 127 )
  {
    inum = itemavail[0];
    GetSuperItemSpace(x, y, itemavail[0]);
    itemavail[0] = itemavail[127 - numitems - 1];
    itemactive[numitems] = inum;
    v5 = 2 * currlevel;
    v6 = GetRndSeed();
    SetupAllItems(inum, idx, v6, v5, 1, onlygood, 0, delta);
    if ( sendmsg )
      NetSendCmdDItem(0, inum);
    if ( delta )
      DeltaAddItem(inum);
    ++numitems;
  }
}

//----- (00427318) --------------------------------------------------------
void __fastcall SetupAllUseful(int ii, int iseed, int lvl)
{
  int idata; // [esp+14h] [ebp-4h]

  item[ii]._iSeed = iseed;
  SetRndSeed(iseed);
  if ( random(34, 2) )
    idata = 11;
  else
    idata = 12;
  if ( lvl > 1 && !random(34, 3) )
    idata = 14;
  GetItemAttrs(ii, idata, lvl);
  item[ii]._iCreateInfo = lvl + 384;
  SetupItem(ii);
}

//----- (004273D8) --------------------------------------------------------
void __fastcall CreateRndUseful(int pnum, int x, int y, unsigned __int8 sendmsg)
{
  int v4; // ST00_4
  int v5; // eax
  int inum; // [esp+14h] [ebp-4h]

  if ( numitems < 127 )
  {
    inum = itemavail[0];
    GetSuperItemSpace(x, y, itemavail[0]);
    itemavail[0] = itemavail[127 - numitems - 1];
    itemactive[numitems] = inum;
    v4 = currlevel;
    v5 = GetRndSeed();
    SetupAllUseful(inum, v5, v4);
    if ( sendmsg )
      NetSendCmdDItem(0, inum);
    ++numitems;
  }
}

//----- (0042746F) --------------------------------------------------------
void __fastcall CreateTypeItem(int x, int y, unsigned __int8 onlygood, int itype, int imisc, int sendmsg, int delta)
{
  int v7; // ST04_4
  int v8; // eax
  int inum; // [esp+14h] [ebp-8h]
  int idx; // [esp+18h] [ebp-4h]

  if ( itype == 11 )
    idx = 0;
  else
    idx = RndTypeItems(itype, imisc);
  if ( numitems < 127 )
  {
    inum = itemavail[0];
    GetSuperItemSpace(x, y, itemavail[0]);
    itemavail[0] = itemavail[127 - numitems - 1];
    itemactive[numitems] = inum;
    v7 = 2 * currlevel;
    v8 = GetRndSeed();
    SetupAllItems(inum, idx, v8, v7, 1, onlygood, 0, delta);
    if ( sendmsg )
      NetSendCmdDItem(0, inum);
    if ( delta )
      DeltaAddItem(inum);
    ++numitems;
  }
}

//----- (0042754C) --------------------------------------------------------
void __fastcall RecreateItem(int ii, int idx, unsigned __int16 ic, int iseed, int ivalue)
{
  int onlygood; // [esp+14h] [ebp-10h]
  int recreate; // [esp+18h] [ebp-Ch]
  int uper; // [esp+1Ch] [ebp-8h]
  int pregen; // [esp+20h] [ebp-4h]

  if ( idx )
  {
    if ( ic )
    {
      if ( ic & 0x7C00 )
      {
        RecreateTownItem(ii, idx, ic, iseed, ivalue);
      }
      else if ( (ic & 0x180) == 384 )
      {
        SetupAllUseful(ii, iseed, ic & 0x3F);
      }
      else
      {
        uper = 0;
        onlygood = 0;
        recreate = 0;
        pregen = 0;
        if ( ic & 0x100 )
          uper = 1;
        if ( (ic & 0x80u) != 0 )
          uper = 15;
        if ( ic & 0x40 )
          onlygood = 1;
        if ( ic & 0x200 )
          recreate = 1;
        if ( (ic & 0x8000u) != 0 )
          pregen = 1;
        SetupAllItems(ii, idx, iseed, ic & 0x3F, uper, onlygood, recreate, pregen);
      }
    }
    else
    {
      SetPlrHandItem(&item[ii], idx);
      SetPlrHandSeed(&item[ii], iseed);
    }
  }
  else
  {
    SetPlrHandItem(&item[ii], 0);
    item[ii]._iSeed = iseed;
    item[ii]._iCreateInfo = ic;
    item[ii]._ivalue = ivalue;
    if ( item[ii]._ivalue < 2500 )
    {
      if ( ivalue > 1000 )
        item[ii]._iCurs = 5;
      else
        item[ii]._iCurs = 4;
    }
    else
    {
      item[ii]._iCurs = 6;
    }
  }
}

//----- (00427787) --------------------------------------------------------
void __cdecl SpawnRock()
{
  int i; // ST24_4
  int v1; // ST10_4
  int j; // [esp+10h] [ebp-14h]
  int v3; // [esp+14h] [ebp-10h]
  BOOL v4; // [esp+18h] [ebp-Ch]

  v4 = 0;
  for ( j = 0; j < nobjects && !v4; ++j )
  {
    v3 = objectactive[j];
    v4 = object[v3]._otype == 23;
  }
  if ( v4 )
  {
    i = itemavail[0];
    itemavail[0] = itemavail[127 - numitems - 1];
    itemactive[numitems] = i;
    item[i]._ix = object[v3]._ox;
    v1 = item[i]._ix;
    item[i]._iy = object[v3]._oy;
    dItem[v1][item[i]._iy] = i + 1;
    GetItemAttrs(i, 7, currlevel);
    SetupItem(i);
    item[i]._iSelFlag = 2;
    item[i]._iPostDraw = 1;
    item[i]._iAnimFrame = 11;
    ++numitems;
  }
}

//----- (00427936) --------------------------------------------------------
void __fastcall RespawnItem(int i, bool FlipFlag)
{
  int v2; // ST14_4

  v2 = ItemCAnimTbl[item[i]._iCurs];
  item[i]._iAnimData = (unsigned __int8 *)Item2Frm[v2];
  item[i]._iAnimLen = ItemAnimLs[v2];
  item[i]._isin = 0;
  item[i]._iAnimWidth = 96;
  item[i]._iAnimWidth2 = 16;
  item[i]._iPostDraw = 0;
  if ( FlipFlag )
  {
    item[i]._iAnimFrame = 1;
    item[i]._iAnimFlag = 1;
    item[i]._iSelFlag = 0;
  }
  else
  {
    item[i]._iAnimFrame = item[i]._iAnimLen;
    item[i]._iAnimFlag = 0;
    item[i]._iSelFlag = 1;
  }
  if ( item[i]._iCurs == 76 )
    item[i]._iSelFlag = 1;
}

//----- (00427AE4) --------------------------------------------------------
void __fastcall DeleteItem(int ii, int i)
{
  itemavail[127 - numitems--] = ii;
  if ( numitems > 0 && numitems != i )
    itemactive[i] = itemactive[numitems];
}

//----- (00427B4A) --------------------------------------------------------
void __cdecl ProcessItems()
{
  int i; // [esp+10h] [ebp-8h]
  int ia; // [esp+10h] [ebp-8h]
  int ii; // [esp+14h] [ebp-4h]
  int iia; // [esp+14h] [ebp-4h]

  for ( i = 0; numitems > i; ++i )
  {
    ii = itemactive[i];
    if ( item[ii]._iAnimFlag )
    {
      if ( item[ii]._iAnimLen >> 1 == item[ii]._iAnimFrame )
        PlaySfxLoc(ItemDropSnds[ItemCAnimTbl[item[ii]._iCurs]], item[ii]._ix, item[ii]._iy);
      ++item[ii]._iAnimFrame;
      if ( item[ii]._iCurs == 76 )
      {
        if ( item[ii]._iSelFlag == 1 && item[ii]._iAnimFrame == 11 )
          item[ii]._iAnimFrame = 1;
        if ( item[ii]._iSelFlag == 2 && item[ii]._iAnimFrame == 21 )
          item[ii]._iAnimFrame = 11;
      }
      else if ( item[ii]._iAnimLen <= item[ii]._iAnimFrame )
      {
        item[ii]._iAnimFrame = item[ii]._iAnimLen;
        item[ii]._iAnimFlag = 0;
        item[ii]._iSelFlag = 1;
      }
    }
  }
  ia = 0;
  while ( numitems > ia )
  {
    iia = itemactive[ia];
    if ( item[iia]._isin )
    {
      DeleteItem(iia, ia);
      ia = 0;
    }
    else
    {
      ++ia;
    }
  }
}

//----- (00427DE5) --------------------------------------------------------
void __cdecl FreeItemGFX()
{
  signed int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 31; ++i )
  {
    mem_free_dbg(Item2Frm[i], 2462, "ITEMS.CPP");
    Item2Frm[i] = 0;
  }
}

//----- (00427E90) --------------------------------------------------------
void __fastcall GetItemStr(int i)
{
  int v1; // ST20_4

  if ( item[i]._itype == 11 )
  {
    sprintf(infostr, "%i Gold Pieces", item[i]._ivalue);
  }
  else
  {
    v1 = item[i]._itype;
    if ( item[i]._iIdentified )
      strcpy(infostr, item[i]._iIName);
    else
      strcpy(infostr, item[i]._iName);
    if ( item[i]._iMagical == 1 )
      infoclr = 1;
    if ( item[i]._iMagical == 2 )
      infoclr = 3;
  }
}

//----- (00427FD2) --------------------------------------------------------
void __fastcall CheckIdentify(int pnum, int cii)
{
  ItemStruct *v2; // eax

  if ( cii >= 7 )
    v2 = &plr[pnum].InvList[cii - 7];
  else
    v2 = &plr[pnum].InvBody[cii];
  v2->_iIdentified = 1;
  CalcPlrInv(pnum, 1);
  if ( myplr == pnum )
    j_SetCursor(1);
}

//----- (00428099) --------------------------------------------------------
void __fastcall DoRepair(int pnum, int cii)
{
  ItemStruct *v2; // eax
  PlayerStruct *v5; // [esp+14h] [ebp-8h]

  v5 = &plr[pnum];
  PlaySfxLoc(68, plr[pnum].WorldX, plr[pnum].WorldY);
  if ( cii >= 7 )
    v2 = &v5->InvList[cii - 7];
  else
    v2 = &v5->InvBody[cii];
  RepairItem(v2, v5->_pLevel);
  CalcPlrInv(pnum, 1);
  if ( pnum == myplr )
    j_SetCursor(1);
}

//----- (00428168) --------------------------------------------------------
void __fastcall RepairItem(ItemStruct *i, int lvl)
{
  int v4; // [esp+14h] [ebp-8h]
  int v5; // [esp+18h] [ebp-4h]

  if ( i->_iMaxDur != i->_iDurability )
  {
    v5 = 0;
    do
    {
      v5 += random(37, lvl) + lvl;
      v4 = i->_iMaxDur / (lvl + 9);
      if ( v4 < 1 )
        v4 = 1;
      i->_iMaxDur -= v4;
      if ( !i->_iMaxDur )
      {
        i->_itype = -1;
        return;
      }
    }
    while ( v5 + i->_iDurability < i->_iMaxDur );
    i->_iDurability += v5;
    if ( i->_iMaxDur < i->_iDurability )
      i->_iDurability = i->_iMaxDur;
  }
}

//----- (00428260) --------------------------------------------------------
void __fastcall DoRecharge(int pnum, int cii)
{
  ItemStruct *v2; // eax
  ItemStruct *i; // ST20_4
  int v4; // eax
  PlayerStruct *v6; // [esp+1Ch] [ebp-8h]

  v6 = &plr[pnum];
  if ( cii >= 7 )
    v2 = &v6->InvList[cii - 7];
  else
    v2 = &v6->InvBody[cii];
  i = v2;
  v4 = random(38, v6->_pLevel / spelldata[v2->_iSpell].sBookLvl);
  RechargeItem(i, v4 + 1);
  CalcPlrInv(pnum, 1);
  if ( pnum == myplr )
    j_SetCursor(1);
}

//----- (0042834B) --------------------------------------------------------
void __fastcall RechargeItem(ItemStruct *i, int r)
{
  if ( i->_iCharges != i->_iMaxCharges )
  {
    do
    {
      if ( !--i->_iMaxCharges )
      {
        i->_itype = -1;
        return;
      }
      i->_iCharges += r;
    }
    while ( r + i->_iCharges < i->_iMaxCharges );
    if ( i->_iCharges > i->_iMaxCharges )
      i->_iCharges = i->_iMaxCharges;
  }
}

//----- (004283FA) --------------------------------------------------------
void __fastcall DoOil(int pnum, int i)
{
  int v2; // eax
  ItemStruct *a1; // [esp+18h] [ebp-8h]
  PlayerStruct *v5; // [esp+1Ch] [ebp-4h]

  v5 = &plr[pnum];
  if ( i >= 7 )
  {
    a1 = &v5->InvList[i - 7];
  }
  else
  {
    if ( i && (i < 4 || i > 6) )
      return;
    a1 = &v5->InvBody[i];
  }
  OilItem(a1, v5);
  if ( v2 )
  {
    CalcPlrInv(pnum, 1);
    if ( myplr == pnum )
      j_SetCursor(1);
  }
}

//----- (004284F1) --------------------------------------------------------
void __fastcall OilItem(ItemStruct *item, PlayerStruct *p)
{
  int v2; // eax
  char v4; // [esp+1Ch] [ebp-4h]

  if ( item->_iClass != 3 && item->_iClass != 4 && item->_iClass != 5 )
  {
    switch ( p->_pOilType )
    {
      case 0x1F:
      case 0x20:
      case 0x21:
        if ( item->_iClass != 2 )
          goto LABEL_31;
        break;
      case 0x22:
        if ( item->_iClass != 2 && item->_itype != 3 )
          goto LABEL_31;
        break;
      case 0x27:
      case 0x28:
        if ( item->_iClass != 1 )
          goto LABEL_31;
        break;
      default:
LABEL_31:
        switch ( p->_pOilType )
        {
          case 0x1F:
            item->_iPLToHit += random(68, 4) + 2;
            break;
          case 0x20:
            item->_iPLToHit += random(68, 10) + 6;
            break;
          case 0x21:
            ++item->_iMaxDam;
            break;
          case 0x22:
            item->_iMaxDam += random(68, 2) + 2;
            break;
          case 0x23:
            v4 = random(68, 6) + 5;
            item->_iMinStr -= v4;
            if ( item->_iMinStr < 0 )
              item->_iMinStr = 0;
            item->_iMinMag -= v4;
            if ( (item->_iMinMag & 0x80u) != 0 )
              item->_iMinMag = 0;
            item->_iMinDex -= v4;
            if ( item->_iMinDex < 0 )
              item->_iMinDex = 0;
            break;
          case 0x24:
            if ( item->_iMaxDur != 1000 )
            {
              item->_iDurability = 12 * item->_iDurability / 10;
              item->_iMaxDur = 12 * item->_iMaxDur / 10;
            }
            break;
          case 0x25:
            v2 = random(68, 41);
            item->_iMaxDur += v2 + 10;
            item->_iDurability += v2 + 10;
            break;
          case 0x26:
            item->_iDurability = 1000;
            item->_iMaxDur = 1000;
            break;
          case 0x27:
            item->_iAC += random(68, 3) + 1;
            break;
          case 0x28:
            item->_iAC += random(68, 5) + 4;
            break;
          default:
            return;
        }
        break;
    }
  }
}

//----- (0042887E) --------------------------------------------------------
void __fastcall PrintItemOil(char IDidx)
{
  switch ( IDidx )
  {
    case 2:
      strcpy(tempstr, "fully recover life");
      AddPanelString(tempstr, 1);
      break;
    case 3:
      strcpy(tempstr, "recover partial life");
      AddPanelString(tempstr, 1);
      break;
    case 4:
      strcpy(tempstr, "recover life");
      AddPanelString(tempstr, 1);
      break;
    case 5:
      strcpy(tempstr, "deadly heal");
      AddPanelString(tempstr, 1);
      break;
    case 6:
      strcpy(tempstr, "recover mana");
      AddPanelString(tempstr, 1);
      break;
    case 7:
      strcpy(tempstr, "fully recover mana");
      AddPanelString(tempstr, 1);
      break;
    case 8:
      strcpy(tempstr, "increase experience");
      AddPanelString(tempstr, 1);
      break;
    case 9:
      strcpy(tempstr, "decrease experience");
      AddPanelString(tempstr, 1);
      break;
    case 10:
      strcpy(tempstr, "increase strength");
      AddPanelString(tempstr, 1);
      break;
    case 11:
      strcpy(tempstr, "increase magic");
      AddPanelString(tempstr, 1);
      break;
    case 12:
      strcpy(tempstr, "increase dexterity");
      AddPanelString(tempstr, 1);
      break;
    case 13:
      strcpy(tempstr, "increase vitality");
      AddPanelString(tempstr, 1);
      break;
    case 14:
      strcpy(tempstr, "decrease strength");
      AddPanelString(tempstr, 1);
      break;
    case 15:
      strcpy(tempstr, "decrease strength");
      AddPanelString(tempstr, 1);
      break;
    case 16:
      strcpy(tempstr, "decrease dexterity");
      AddPanelString(tempstr, 1);
      break;
    case 17:
      strcpy(tempstr, "decrease vitality");
      AddPanelString(tempstr, 1);
      break;
    case 18:
      strcpy(tempstr, "recover life and mana");
      AddPanelString(tempstr, 1);
      break;
    case 19:
      strcpy(tempstr, "fully recover life and mana");
      AddPanelString(tempstr, 1);
      break;
    case 31:
      strcpy(tempstr, "increases a weapon's");
      AddPanelString(tempstr, 1);
      strcpy(tempstr, "chance to hit");
      AddPanelString(tempstr, 1);
      break;
    case 32:
      strcpy(tempstr, "greatly increases a");
      AddPanelString(tempstr, 1);
      strcpy(tempstr, "weapon's chance to hit");
      AddPanelString(tempstr, 1);
      break;
    case 33:
      strcpy(tempstr, "increases a weapon's damage");
      AddPanelString(tempstr, 1);
      strcpy(tempstr, "potential - not bows");
      AddPanelString(tempstr, 1);
      break;
    case 34:
      strcpy(tempstr, "greatly increases a weapon's");
      AddPanelString(tempstr, 1);
      strcpy(tempstr, "damage potential - not bows");
      AddPanelString(tempstr, 1);
      break;
    case 35:
      strcpy(tempstr, "reduces attributes needed");
      AddPanelString(tempstr, 1);
      strcpy(tempstr, "to use armor or weapons");
      AddPanelString(tempstr, 1);
      break;
    case 36:
      strcpy(tempstr, "adds 20% to an item's");
      AddPanelString(tempstr, 1);
      strcpy(tempstr, "current and max durability");
      AddPanelString(tempstr, 1);
      break;
    case 37:
      strcpy(tempstr, "increases an item's");
      AddPanelString(tempstr, 1);
      strcpy(tempstr, "current and max durability");
      AddPanelString(tempstr, 1);
      break;
    case 38:
      strcpy(tempstr, "makes an item indestructible");
      AddPanelString(tempstr, 1);
      break;
    case 39:
      strcpy(tempstr, "increases the armor class");
      AddPanelString(tempstr, 1);
      strcpy(tempstr, "of armor and shields");
      AddPanelString(tempstr, 1);
      break;
    case 40:
      strcpy(tempstr, "greatly increases the armor");
      AddPanelString(tempstr, 1);
      strcpy(tempstr, "class of armor and shields");
      AddPanelString(tempstr, 1);
      break;
    default:
      return;
  }
}

//----- (00428EAA) --------------------------------------------------------
void __fastcall PrintItemPower(char power, ItemStruct *item)
{
  switch ( power )
  {
    case 0:
    case 1:
      sprintf(tempstr, "chance to hit : %+i%%", item->_iPLToHit);
      break;
    case 2:
    case 3:
      sprintf(tempstr, "%+i%% damage", item->_iPLDam);
      break;
    case 4:
    case 5:
      sprintf(tempstr, "to hit: %+i%%, %+i%% damage", item->_iPLToHit, item->_iPLDam);
      break;
    case 6:
    case 7:
      sprintf(tempstr, "%+i%% armor class", item->_iPLAC);
      break;
    case 8:
      sprintf(tempstr, "Resist Fire : %+i%%", item->_iPLFR);
      break;
    case 9:
      sprintf(tempstr, "Resist Lightning : %+i%%", item->_iPLLR);
      break;
    case 10:
      sprintf(tempstr, "Resist General Magic : %+i%%", item->_iPLMR);
      break;
    case 11:
      sprintf(tempstr, "Resist All : %+i%%", item->_iPLFR);
      break;
    case 12:
      sprintf(tempstr, "spell cost -%i%% less mana", item->_pISplCost);
      break;
    case 13:
      sprintf(tempstr, "spell duration: +%i%%", item->_pISplDur);
      break;
    case 14:
      if ( item->_iSplLvlAdd == 1 )
        strcpy(tempstr, "spells are increased 1 level");
      if ( item->_iSplLvlAdd == 2 )
        strcpy(tempstr, "spells are increased 2 levels");
      if ( item->_iSplLvlAdd < 1 )
        strcpy(tempstr, "spells are decreased 1 level");
      break;
    case 15:
      strcpy(tempstr, "Extra charges");
      break;
    case 16:
      strcpy(tempstr, "Fire hit");
      break;
    case 17:
      strcpy(tempstr, "Lightning hit");
      break;
    case 19:
    case 20:
      sprintf(tempstr, "%+i to strength", item->_iPLStr);
      break;
    case 21:
    case 22:
      sprintf(tempstr, "%+i to magic", item->_iPLMag);
      break;
    case 23:
    case 24:
      sprintf(tempstr, "%+i to dexterity", item->_iPLDex);
      break;
    case 25:
    case 26:
      sprintf(tempstr, "%+i to vitality", item->_iPLVit);
      break;
    case 27:
    case 28:
      sprintf(tempstr, "%+i to all attributes", item->_iPLStr);
      break;
    case 29:
    case 30:
      sprintf(tempstr, "%+i damage from enemies", item->_iPLGetHit);
      break;
    case 31:
    case 32:
      sprintf(tempstr, "Hit Points : %+i", item->_iPLHP >> 6);
      break;
    case 33:
    case 34:
      sprintf(tempstr, "Mana : %+i", item->_iPLMana >> 6);
      break;
    case 35:
      strcpy(tempstr, "high durability");
      break;
    case 36:
      strcpy(tempstr, "decreased durability");
      break;
    case 37:
      strcpy(tempstr, "indestructible");
      break;
    case 38:
      sprintf(tempstr, "+%i%% light radius", 10 * item->_iPLLight);
      break;
    case 39:
      sprintf(tempstr, "-%i%% light radius", -10 * item->_iPLLight);
      break;
    case 42:
      strcpy(tempstr, "shoots fire arrows");
      break;
    case 43:
      strcpy(tempstr, "shoots lightning arrows");
      break;
    case 44:
      strcpy(tempstr, " ");
      break;
    case 45:
      strcpy(tempstr, "attacker takes damage");
      break;
    case 46:
      strcpy(tempstr, "user loses all mana");
      break;
    case 47:
      strcpy(tempstr, "you can't heal(NW)");
      break;
    case 52:
      strcpy(tempstr, "absorbs half of trap damage");
      break;
    case 53:
      strcpy(tempstr, "knocks target back");
      break;
    case 54:
      strcpy(tempstr, "hit monster doesn't heal");
      break;
    case 55:
      strcpy(tempstr, "hit steals mana");
      break;
    case 56:
      strcpy(tempstr, "hit steals life");
      break;
    case 57:
      strcpy(tempstr, "damages target's armor");
      break;
    case 58:
      if ( item->_iFlags & 0x20000 )
        strcpy(tempstr, "quick attack");
      if ( item->_iFlags & 0x40000 )
        strcpy(tempstr, "fast attack");
      if ( item->_iFlags & 0x80000 )
        strcpy(tempstr, "faster attack");
      if ( item->_iFlags & 0x100000 )
        strcpy(tempstr, "fastest attack");
      break;
    case 59:
      if ( item->_iFlags & 0x200000 )
        strcpy(tempstr, "fast hit recovery");
      if ( item->_iFlags & 0x400000 )
        strcpy(tempstr, "faster hit recovery");
      if ( (item->_iFlags & 0x800000) != 0 )
        strcpy(tempstr, "fastest hit recovery");
      break;
    case 60:
      strcpy(tempstr, "fast block");
      break;
    case 61:
      sprintf(tempstr, "adds %i points to damage", item->_iPLDamMod);
      break;
    case 62:
      strcpy(tempstr, "fires random speed arrows");
      break;
    case 63:
      sprintf(tempstr, "unusual item damage");
      break;
    case 64:
      strcpy(tempstr, "altered durability");
      break;
    case 65:
      strcpy(tempstr, "no strength requirement");
      break;
    case 66:
      strcpy(tempstr, "Increased charges");
      break;
    case 67:
      strcpy(tempstr, "Faster attack swing");
      break;
    case 68:
      strcpy(tempstr, "two handed item is one handed");
      break;
    case 69:
      strcpy(tempstr, "+200 damage vs. demons only");
      break;
    case 70:
      strcpy(tempstr, "All Resistance equals 0");
      break;
    case 72:
      strcpy(tempstr, "constantly lose hit points");
      break;
    case 73:
      strcpy(tempstr, "life stealing");
      break;
    case 74:
      strcpy(tempstr, "see with infravision");
      break;
    case 75:
      strcpy(tempstr, "increased armor class");
      break;
    default:
      strcpy(tempstr, "Another ability (NW)");
      break;
  }
}

//----- (00429759) --------------------------------------------------------
void __cdecl DrawUBack()
{
  BYTE *buf; // edi MAPDST
  signed int i; // edx MAPDST
  signed int j; // ecx MAPDST

  CelDecodeOnly(88, 487, pSTextBoxCels, 1, 271);
  buf = gpBuffer + 371803;
  for (i = 148; i; --i)
  {
    for (j = 132; j; --j)
    {
      *buf = 0;
      buf += 2;
    }
    *buf = 0;
    buf -= 1032;
    for (j = 132; j; --j)
    {
      *++buf = 0;
      ++buf;
    }
    buf -= 1032;
  }
  
  for (i = 132; i; --i)
  {
    *buf = 0;
    buf += 2;
  }
  *buf = 0;
}

//----- (004297C8) --------------------------------------------------------
void __fastcall PrintUString(int x, int y, int cjustflag, char *str, int col)
{
  signed int v5; // [esp+14h] [ebp-1Ch]
  signed int v6; // [esp+18h] [ebp-18h]
  signed int i; // [esp+1Ch] [ebp-14h]
  signed int j; // [esp+1Ch] [ebp-14h]
  int v9; // [esp+20h] [ebp-10h]
  int No; // [esp+24h] [ebp-Ch]
  char v11; // [esp+2Ch] [ebp-4h]

  No = x + screen_y_times_768[SStringY[y] + 204] + 96;
  v5 = strlen(str);
  v9 = 0;
  if ( cjustflag )
  {
    v6 = 0;
    for ( i = 0; i < v5; ++i )
      v6 += fontkern[fontframe[str[i] & 0x7F]] + 1;
    if ( v6 < 257 )
      v9 = (257 - v6) >> 1;
    No += v9;
  }
  for ( j = 0; j < v5; ++j )
  {
    v11 = fontframe[str[j] & 0x7F];
    v9 += fontkern[v11] + 1;
    if ( v11 )
    {
      if ( v9 <= 257 )
        CPrintString(No, v11, col);
    }
    No += fontkern[v11] + 1;
  }
}

//----- (0042990C) --------------------------------------------------------
void __fastcall DrawULine(int y)
{
  BYTE *v1; // esi
  BYTE *v2; // edi
  signed int v3; // edx
  _WORD *v4; // edi
  _WORD *v5; // esi

  v1 = gpBuffer + 142170;
  v2 = &gpBuffer[screen_y_times_768[SStringY[y] + 198] + 90];
  for (v3 = 3; v3; --v3)
  {
    qmemcpy(v2, v1, 0x108u);
    v5 = v1 + 264;
    v4 = v2 + 264;
    *v4 = *v5;
    v1 = (BYTE *)(v5 + 252);
    v2 = (BYTE *)(v4 + 252);
  }
}

//----- (00429968) --------------------------------------------------------
void __cdecl DrawUniqueInfo()
{
  int y; // [esp+Ch] [ebp-8h]
  int v1; // [esp+10h] [ebp-4h]

  if ( !chrflag && !questlog )
  {
    v1 = curruitem._iPrePower;
    DrawUBack();
    PrintUString(0, 2, 1, UniqueItemList[v1].UIName, 3);
    DrawULine(5);
    PrintItemPower(UniqueItemList[v1].UIPower1, &curruitem);
    y = 6 - UniqueItemList[v1].UINumPL + 8;
    PrintUString(0, y, 1, tempstr, 0);
    if ( UniqueItemList[v1].UINumPL > 1 )
    {
      PrintItemPower(UniqueItemList[v1].UIPower2, &curruitem);
      PrintUString(0, y + 2, 1, tempstr, 0);
    }
    if ( UniqueItemList[v1].UINumPL > 2 )
    {
      PrintItemPower(UniqueItemList[v1].UIPower3, &curruitem);
      PrintUString(0, y + 4, 1, tempstr, 0);
    }
    if ( UniqueItemList[v1].UINumPL > 3 )
    {
      PrintItemPower(UniqueItemList[v1].UIPower4, &curruitem);
      PrintUString(0, y + 6, 1, tempstr, 0);
    }
    if ( UniqueItemList[v1].UINumPL > 4 )
    {
      PrintItemPower(UniqueItemList[v1].UIPower5, &curruitem);
      PrintUString(0, y + 8, 1, tempstr, 0);
    }
    if ( UniqueItemList[v1].UINumPL > 5 )
    {
      PrintItemPower(UniqueItemList[v1].UIPower6, &curruitem);
      PrintUString(0, y + 10, 1, tempstr, 0);
    }
  }
}

//----- (00429BB7) --------------------------------------------------------
void __fastcall PrintItemMisc(ItemStruct *x)
{
  if ( x->_iMiscId >= 29 && x->_iMiscId <= 41 )
  {
    PrintItemOil(x->_iMiscId);
    strcpy(tempstr, "Right click to open, then");
    AddPanelString(tempstr, 1);
    strcpy(tempstr, "left-click to apply");
    AddPanelString(tempstr, 1);
  }
  if ( x->_iMiscId == 21 )
  {
    strcpy(tempstr, "Right-click to read");
    AddPanelString(tempstr, 1);
  }
  if ( x->_iMiscId == 22 )
  {
    strcpy(tempstr, "Right-click to read, then");
    AddPanelString(tempstr, 1);
    strcpy(tempstr, "left-click to target");
    AddPanelString(tempstr, 1);
  }
  if ( x->_iMiscId >= 1 && x->_iMiscId <= 20 )
  {
    PrintItemOil(x->_iMiscId);
    strcpy(tempstr, "Right click to use");
    AddPanelString(tempstr, 1);
  }
  if ( x->_iMiscId == 24 )
  {
    strcpy(tempstr, "Right click to read");
    AddPanelString(tempstr, 1);
  }
}

//----- (00429D40) --------------------------------------------------------
void __fastcall PrintItemDetails(ItemStruct *x)
{
  if ( x->_iClass == 1 )
  {
    if ( x->_iMaxDur == 1000 )
    {
      strcpy(tempstr, "Indestructible");
      sprintf(tempstr, "damage: %i-%i", x->_iMinDam, x->_iMaxDam);
    }
    else
    {
      sprintf(tempstr, "damage: %i-%i  Dur: %i/%i", x->_iMinDam, x->_iMaxDam, x->_iDurability, x->_iMaxDur);
    }
    AddPanelString(tempstr, 1);
  }
  if ( x->_iClass == 2 )
  {
    if ( x->_iMaxDur == 1000 )
    {
      strcpy(tempstr, "Indestructible");
      sprintf(tempstr, "armor: %i", x->_iAC);
    }
    else
    {
      sprintf(tempstr, "armor: %i  Dur: %i/%i", x->_iAC, x->_iDurability, x->_iMaxDur);
    }
    AddPanelString(tempstr, 1);
  }
  if ( x->_iMiscId == 23 && x->_iMaxCharges )
  {
    sprintf(tempstr, "dam: %i-%i  Dur: %i/%i", x->_iMinDam, x->_iMaxDam, x->_iDurability, x->_iMaxDur);
    sprintf(tempstr, "Charges: %i/%i", x->_iCharges, x->_iMaxCharges);
    AddPanelString(tempstr, 1);
  }
  if ( x->_iMagical != 2 && x->_iPrePower != -1 )
  {
    PrintItemPower(x->_iPrePower, x);
    AddPanelString(tempstr, 1);
  }
  if ( x->_iSufPower != -1 )
  {
    PrintItemPower(x->_iSufPower, x);
    AddPanelString(tempstr, 1);
  }
  if ( x->_iMagical == 2 )
  {
    AddPanelString("unique item", 1);
    uitemflag = 1;
    qmemcpy(&curruitem, x, sizeof(curruitem));
  }
  PrintItemMisc(x);
  if ( x->_iMinDex + (char)x->_iMinMag + x->_iMinStr )
  {
    strcpy(tempstr, "Required:");
    if ( x->_iMinStr )
      sprintf(tempstr, "%s %i Str", tempstr, x->_iMinStr);
    if ( x->_iMinMag )
      sprintf(tempstr, "%s %i Mag", tempstr, (char)x->_iMinMag);
    if ( x->_iMinDex )
      sprintf(tempstr, "%s %i Dex", tempstr, x->_iMinDex);
    AddPanelString(tempstr, 1);
  }
  pinfoflag = 1;
}

//----- (0042A0D2) --------------------------------------------------------
void __fastcall PrintItemDur(ItemStruct *x)
{
  if ( x->_iClass == 1 )
  {
    if ( x->_iMaxDur == 1000 )
    {
      strcpy(tempstr, "Indestructible");
      sprintf(tempstr, "damage: %i-%i", x->_iMinDam, x->_iMaxDam);
    }
    else
    {
      sprintf(tempstr, "damage: %i-%i  Dur: %i/%i", x->_iMinDam, x->_iMaxDam, x->_iDurability, x->_iMaxDur);
    }
    AddPanelString(tempstr, 1);
    if ( x->_iMiscId == 23 && x->_iMaxCharges )
    {
      sprintf(tempstr, "Charges: %i/%i", x->_iCharges, x->_iMaxCharges);
      AddPanelString(tempstr, 1);
    }
    if ( x->_iMagical )
      AddPanelString("Not Identified", 1);
  }
  if ( x->_iClass == 2 )
  {
    if ( x->_iMaxDur == 1000 )
    {
      strcpy(tempstr, "Indestructible");
      sprintf(tempstr, "armor: %i", x->_iAC);
    }
    else
    {
      sprintf(tempstr, "armor: %i  Dur: %i/%i", x->_iAC, x->_iDurability, x->_iMaxDur);
    }
    AddPanelString(tempstr, 1);
    if ( x->_iMagical )
      AddPanelString("Not Identified", 1);
    if ( x->_iMiscId == 23 && x->_iMaxCharges )
    {
      sprintf(tempstr, "Charges: %i/%i", x->_iCharges, x->_iMaxCharges);
      AddPanelString(tempstr, 1);
    }
  }
  if ( x->_itype == 12 || x->_itype == 13 )
    AddPanelString("Not Identified", 1);
  PrintItemMisc(x);
  if ( x->_iMinDex + (char)x->_iMinMag + x->_iMinStr )
  {
    strcpy(tempstr, "Required:");
    if ( x->_iMinStr )
      sprintf(tempstr, "%s %i Str", tempstr, x->_iMinStr);
    if ( x->_iMinMag )
      sprintf(tempstr, "%s %i Mag", tempstr, (char)x->_iMinMag);
    if ( x->_iMinDex )
      sprintf(tempstr, "%s %i Dex", tempstr, x->_iMinDex);
    AddPanelString(tempstr, 1);
  }
  pinfoflag = 1;
}

//----- (0042A432) --------------------------------------------------------
void __fastcall UseItem(int p, int Mid, int spl)
{
  int v3; // ST1C_4
  int v4; // ST1C_4
  char v5; // al
  char v6; // al
  char v7; // al
  char v8; // al
  char v9; // al
  char v10; // al
  char v11; // al
  char v12; // al
  int v13; // ST1C_4
  int v14; // ST1C_4
  int v; // [esp+18h] [ebp-10h]
  int va; // [esp+18h] [ebp-10h]
  int vb; // [esp+18h] [ebp-10h]
  int vc; // [esp+18h] [ebp-10h]

  switch ( Mid )
  {
    case 2:
      plr[p]._pHitPoints = plr[p]._pMaxHP;
      plr[p]._pHPBase = plr[p]._pMaxHPBase;
      drawhpflag = 1;
      break;
    case 3:
    case 28:
      v3 = plr[p]._pMaxHP >> 8;
      v = ((v3 >> 1) + random(39, v3)) << 6;
      if ( !plr[p]._pClass )
        v *= 2;
      if ( plr[p]._pClass == 1 )
        v += v >> 1;
      plr[p]._pHitPoints += v;
      if ( plr[p]._pHitPoints > plr[p]._pMaxHP )
        plr[p]._pHitPoints = plr[p]._pMaxHP;
      plr[p]._pHPBase += v;
      if ( plr[p]._pMaxHPBase < plr[p]._pHPBase )
        plr[p]._pHPBase = plr[p]._pMaxHPBase;
      drawhpflag = 1;
      break;
    case 6:
      v4 = plr[p]._pMaxMana >> 8;
      va = ((v4 >> 1) + random(40, v4)) << 6;
      if ( plr[p]._pClass == 2 )
        va *= 2;
      if ( plr[p]._pClass == 1 )
        va += va >> 1;
      if ( !(plr[p]._pIFlags & 0x8000000) )
      {
        plr[p]._pMana += va;
        if ( plr[p]._pMana > plr[p]._pMaxMana )
          plr[p]._pMana = plr[p]._pMaxMana;
        plr[p]._pManaBase += va;
        if ( plr[p]._pManaBase > plr[p]._pMaxManaBase )
          plr[p]._pManaBase = plr[p]._pMaxManaBase;
        drawmanaflag = 1;
      }
      break;
    case 7:
      if ( !(plr[p]._pIFlags & 0x8000000) )
      {
        plr[p]._pMana = plr[p]._pMaxMana;
        plr[p]._pManaBase = plr[p]._pMaxManaBase;
        drawmanaflag = 1;
      }
      break;
    case 8:
      AddPlrExperience(p, plr[p]._pLevel, plr[p]._pExperience >> 3);
      break;
    case 10:
      v5 = random(41, 3);
      plr[p]._pStrength += (char)(v5 + 1);
      plr[p]._pBaseStr += (char)(v5 + 1);
      break;
    case 11:
      v6 = random(42, 3);
      plr[p]._pMagic += (char)(v6 + 1);
      plr[p]._pBaseMag += (char)(v6 + 1);
      break;
    case 12:
      v7 = random(43, 3);
      plr[p]._pDexterity += (char)(v7 + 1);
      plr[p]._pBaseDex += (char)(v7 + 1);
      break;
    case 13:
      v8 = random(44, 3);
      plr[p]._pVitality += (char)(v8 + 1);
      plr[p]._pBaseVit += (char)(v8 + 1);
      break;
    case 14:
      v9 = random(45, 3);
      plr[p]._pStrength -= (char)(v9 + 1);
      plr[p]._pBaseStr -= (char)(v9 + 1);
      break;
    case 15:
      v10 = random(46, 3);
      plr[p]._pMagic -= (char)(v10 + 1);
      plr[p]._pBaseMag -= (char)(v10 + 1);
      break;
    case 16:
      v11 = random(47, 3);
      plr[p]._pDexterity -= (char)(v11 + 1);
      plr[p]._pBaseDex -= (char)(v11 + 1);
      break;
    case 17:
      v12 = random(48, 3);
      plr[p]._pVitality -= (char)(v12 + 1);
      plr[p]._pBaseVit -= (char)(v12 + 1);
      break;
    case 18:
      v13 = plr[p]._pMaxHP >> 8;
      vb = ((v13 >> 1) + random(39, v13)) << 6;
      if ( !plr[p]._pClass )
        vb *= 2;
      if ( plr[p]._pClass == 1 )
        vb += vb >> 1;
      plr[p]._pHitPoints += vb;
      if ( plr[p]._pHitPoints > plr[p]._pMaxHP )
        plr[p]._pHitPoints = plr[p]._pMaxHP;
      plr[p]._pHPBase += vb;
      if ( plr[p]._pMaxHPBase < plr[p]._pHPBase )
        plr[p]._pHPBase = plr[p]._pMaxHPBase;
      drawhpflag = 1;
      v14 = plr[p]._pMaxMana >> 8;
      vc = ((v14 >> 1) + random(40, v14)) << 6;
      if ( plr[p]._pClass == 2 )
        vc *= 2;
      if ( plr[p]._pClass == 1 )
        vc += vc >> 1;
      if ( !(plr[p]._pIFlags & 0x8000000) )
      {
        plr[p]._pMana += vc;
        if ( plr[p]._pMana > plr[p]._pMaxMana )
          plr[p]._pMana = plr[p]._pMaxMana;
        plr[p]._pManaBase += vc;
        if ( plr[p]._pManaBase > plr[p]._pMaxManaBase )
          plr[p]._pManaBase = plr[p]._pMaxManaBase;
        drawmanaflag = 1;
      }
      break;
    case 19:
      plr[p]._pHitPoints = plr[p]._pMaxHP;
      plr[p]._pHPBase = plr[p]._pMaxHPBase;
      drawhpflag = 1;
      if ( !(plr[p]._pIFlags & 0x8000000) )
      {
        plr[p]._pMana = plr[p]._pMaxMana;
        plr[p]._pManaBase = plr[p]._pMaxManaBase;
        drawmanaflag = 1;
      }
      break;
    case 21:
      if ( spelldata[spl].sTargeted )
      {
        plr[p]._pTSpell = spl;
        plr[p]._pTSplType = 2;
        if ( p == myplr )
          j_SetCursor(9);
      }
      else
      {
        ClrPlrPath(p);
        plr[p]._pSpell = spl;
        plr[p]._pSplType = 2;
        plr[p]._pSplFrom = 3;
        plr[p].destAction = 12;
        plr[p].destParam1 = cursmx;
        plr[p].destParam2 = cursmy;
      }
      break;
    case 22:
      if ( spelldata[spl].sTargeted )
      {
        plr[p]._pTSpell = spl;
        plr[p]._pTSplType = 2;
        if ( p == myplr )
          j_SetCursor(9);
      }
      else
      {
        ClrPlrPath(p);
        plr[p]._pSpell = spl;
        plr[p]._pSplType = 2;
        plr[p]._pSplFrom = 3;
        plr[p].destAction = 12;
        plr[p].destParam1 = cursmx;
        plr[p].destParam2 = cursmy;
      }
      break;
    case 24:
      plr[p]._pMemSpells |= 1i64 << ((unsigned __int8)spl - 1);
      ++plr[p]._pSplLvl[spl];
      plr[p]._pMana += spelldata[spl].sManaCost << 6;
      if ( plr[p]._pMana > plr[p]._pMaxMana )
        plr[p]._pMana = plr[p]._pMaxMana;
      plr[p]._pManaBase += spelldata[spl].sManaCost << 6;
      if ( plr[p]._pManaBase > plr[p]._pMaxManaBase )
        plr[p]._pManaBase = plr[p]._pMaxManaBase;
      drawmanaflag = 1;
      break;
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
      plr[p]._pOilType = Mid;
      if ( p == myplr )
      {
        if ( sbookflag )
          sbookflag = 0;
        if ( !invflag )
          invflag = 1;
        j_SetCursor(6);
      }
      break;
    default:
      return;
  }
}

//----- (0042B6E5) --------------------------------------------------------
BOOL __fastcall StoreStatOk(ItemStruct *h)
{
  BOOL v2; // [esp+10h] [ebp-4h]

  v2 = 1;
  if ( plr[myplr]._pStrength < h->_iMinStr )
    v2 = 0;
  if ( plr[myplr]._pMagic < (char)h->_iMinMag )
    v2 = 0;
  if ( plr[myplr]._pDexterity < h->_iMinDex )
    v2 = 0;
  return v2;
}

//----- (0042B7A7) --------------------------------------------------------
BOOL __fastcall SmithItemOk(int i)
{
  BOOL v2; // [esp+10h] [ebp-4h]

  v2 = 1;
  if ( AllItemsList[i].iMiscId == 30 )
    v2 = 1;
  if ( !AllItemsList[i].itype )
    v2 = 0;
  if ( AllItemsList[i].itype == 11 )
    v2 = 0;
  if ( AllItemsList[i].itype == 14 )
    v2 = 0;
  if ( AllItemsList[i].itype == 10 )
    v2 = 0;
  if ( AllItemsList[i].itype == 12 )
    v2 = 0;
  if ( AllItemsList[i].itype == 13 )
    v2 = 0;
  return v2;
}

//----- (0042B8B8) --------------------------------------------------------
int __fastcall RndSmithItem(int lvl)
{
  int v3[512]; // [esp+10h] [ebp-808h]
  int i; // [esp+810h] [ebp-8h]
  int v; // [esp+814h] [ebp-4h]

  v = 0;
  for ( i = 1; AllItemsList[i].iLoc != -1; ++i )
  {
    if ( AllItemsList[i].iRnd && SmithItemOk(i) && AllItemsList[i].iMinMLvl <= lvl )
    {
      v3[v++] = i;
      if ( AllItemsList[i].iRnd == 2 )
        v3[v++] = i;
    }
  }
  return v3[random(50, v)] + 1;
}

//----- (0042B9A1) --------------------------------------------------------
void __fastcall SpawnSmith(int lvl)
{
  int idata; // ST14_4
  int i; // [esp+14h] [ebp-8h]
  signed int j; // [esp+14h] [ebp-8h]
  int v5; // [esp+18h] [ebp-4h]

  v5 = random(50, 10) + 10;
  for ( i = 0; v5 > i; ++i )
  {
    item[0]._iSeed = GetRndSeed();
    SetRndSeed(item[0]._iSeed);
    idata = RndSmithItem(lvl) - 1;
    GetItemAttrs(0, idata, lvl);
    qmemcpy(&smithitem[i], item, sizeof(ItemStruct));
    smithitem[i]._iCreateInfo = lvl | 0x400;
    smithitem[i]._iIdentified = 1;
    smithitem[i]._iStatFlag = StoreStatOk(&smithitem[i]);
  }
  for ( j = v5; j < 20; ++j )
    smithitem[j]._itype = -1;
}

//----- (0042BAD2) --------------------------------------------------------
BOOL __fastcall PremiumItemOk(int i)
{
  BOOL v2; // [esp+10h] [ebp-4h]

  v2 = 1;
  if ( !AllItemsList[i].itype )
    v2 = 0;
  if ( AllItemsList[i].itype == 11 )
    v2 = 0;
  if ( AllItemsList[i].itype == 14 )
    v2 = 0;
  if ( AllItemsList[i].itype == 10 )
    v2 = 0;
  return v2;
}

//----- (0042BB7D) --------------------------------------------------------
int __fastcall RndPremiumItem(int minlvl, int maxlvl)
{
  int v5[512]; // [esp+14h] [ebp-808h]
  int i; // [esp+814h] [ebp-8h]
  int v; // [esp+818h] [ebp-4h]

  v = 0;
  for ( i = 1; AllItemsList[i].iLoc != -1; ++i )
  {
    if ( AllItemsList[i].iRnd
      && PremiumItemOk(i)
      && AllItemsList[i].iMinMLvl >= minlvl
      && AllItemsList[i].iMinMLvl <= maxlvl )
    {
      v5[v++] = i;
    }
  }
  return v5[random(50, v)] + 1;
}

//----- (0042BC62) --------------------------------------------------------
void __fastcall SpawnOnePremium(int i, int plvl)
{
  int idata; // ST20_4
  signed int maxlvl; // [esp+Ch] [ebp-Ch]

  maxlvl = plvl;
  if ( plvl > 30 )
    maxlvl = 30;
  item[0]._iSeed = GetRndSeed();
  SetRndSeed(item[0]._iSeed);
  idata = RndPremiumItem(maxlvl >> 2, maxlvl) - 1;
  GetItemAttrs(0, idata, maxlvl);
  GetItemBonus(0, idata, maxlvl >> 1, maxlvl, 1);
  qmemcpy(&premiumitem[i], item, sizeof(ItemStruct));
  premiumitem[i]._iCreateInfo = maxlvl | 0x800;
  premiumitem[i]._iIdentified = 1;
  premiumitem[i]._iStatFlag = StoreStatOk(&premiumitem[i]);
}

//----- (0042BD5B) --------------------------------------------------------
void __fastcall SpawnPremium(int lvl)
{
  int v1; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v1 = lvl;
  if ( numpremium < 6 )
  {
    for ( i = 0; i < 6; ++i )
    {
      if ( premiumitem[i]._itype == -1 )
        SpawnOnePremium(i, premiumlevel + premiumlvladd[i]);
    }
    numpremium = 6;
  }
  while ( premiumlevel != v1 )
  {
    ++premiumlevel;
    qmemcpy(premiumitem, &premiumitem[2], 0x170u);
    qmemcpy(&premiumitem[1], &premiumitem[3], sizeof(ItemStruct));
    qmemcpy(&premiumitem[2], &premiumitem[4], sizeof(ItemStruct));
    SpawnOnePremium(3, premiumlevel + premiumlvladd[3]);
    qmemcpy(&premiumitem[4], &premiumitem[5], sizeof(ItemStruct));
    SpawnOnePremium(5, premiumlevel + premiumlvladd[5]);
  }
}

//----- (0042BE6E) --------------------------------------------------------
BOOL __fastcall WitchItemOk(int i)
{
  BOOL v2; // [esp+10h] [ebp-4h]

  v2 = 0;
  if ( !AllItemsList[i].itype )
    v2 = 1;
  if ( AllItemsList[i].itype == 10 )
    v2 = 1;
  if ( AllItemsList[i].iMiscId == 3 )
    v2 = 0;
  if ( AllItemsList[i].iMiscId == 6 )
    v2 = 0;
  return v2;
}

//----- (0042BF13) --------------------------------------------------------
int __fastcall RndWitchItem(int lvl)
{
  int v3[512]; // [esp+10h] [ebp-808h]
  int i; // [esp+810h] [ebp-8h]
  int v; // [esp+814h] [ebp-4h]

  v = 0;
  for ( i = 1; AllItemsList[i].iLoc != -1; ++i )
  {
    if ( AllItemsList[i].iRnd && WitchItemOk(i) && AllItemsList[i].iMinMLvl <= lvl )
      v3[v++] = i;
  }
  return v3[random(51, v)] + 1;
}

//----- (0042BFD3) --------------------------------------------------------
void __fastcall SpawnWitch(int lvl)
{
  int maxlvl; // [esp+10h] [ebp-10h]
  int idata; // [esp+14h] [ebp-Ch]
  signed int i; // [esp+18h] [ebp-8h]
  signed int j; // [esp+18h] [ebp-8h]
  int v6; // [esp+1Ch] [ebp-4h]

  GetItemAttrs(0, 11, 1);
  qmemcpy(witchitem, item, 0x170u);
  witchitem[0]._iStatFlag = 1;
  GetItemAttrs(0, 12, 1);
  qmemcpy(&witchitem[1], item, sizeof(ItemStruct));
  witchitem[1]._iStatFlag = 1;
  v6 = random(51, 10) + 10;
  for ( i = 2; i < v6; ++i )
  {
    item[0]._iSeed = GetRndSeed();
    SetRndSeed(item[0]._iSeed);
    idata = RndWitchItem(lvl) - 1;
    GetItemAttrs(0, idata, lvl);
    maxlvl = -1;
    if ( random(51, 100) <= 5 )
      maxlvl = 2 * lvl;
    if ( maxlvl == -1 && item[0]._iMiscId == 23 )
      maxlvl = 2 * lvl;
    if ( maxlvl != -1 )
      GetItemBonus(0, idata, maxlvl >> 1, maxlvl, 1);
    qmemcpy(&witchitem[i], item, sizeof(ItemStruct));
    witchitem[i]._iCreateInfo = lvl | 0x2000;
    witchitem[i]._iIdentified = 1;
    witchitem[i]._iStatFlag = StoreStatOk(&witchitem[i]);
  }
  for ( j = v6; j < 20; ++j )
    witchitem[j]._itype = -1;
}

//----- (0042C1CF) --------------------------------------------------------
int __fastcall RndBoyItem(int lvl)
{
  int v2[512]; // [esp+10h] [ebp-808h]
  int i; // [esp+810h] [ebp-8h]
  int v; // [esp+814h] [ebp-4h]

  v = 0;
  for ( i = 1; AllItemsList[i].iLoc != -1; ++i )
  {
    if ( AllItemsList[i].iRnd )
    {
      if ( AllItemsList[i].iMinMLvl <= lvl )
        v2[v++] = i;
    }
  }
  return v2[random(49, v)] + 1;
}

//----- (0042C27F) --------------------------------------------------------
void __fastcall SpawnBoy(int lvl)
{
  int idata; // ST1C_4

  item[0]._iSeed = GetRndSeed();
  SetRndSeed(item[0]._iSeed);
  idata = RndBoyItem(lvl) - 1;
  GetItemAttrs(0, idata, lvl);
  GetItemBonus(0, idata, lvl, 2 * lvl, 1);
  qmemcpy(&boyitem, item, sizeof(boyitem));
  boyitem._iCreateInfo = lvl | 0x1000;
  boyitem._iIdentified = 1;
  boyitem._iStatFlag = StoreStatOk(&boyitem);
}

//----- (0042C312) --------------------------------------------------------
BOOL __fastcall HealerItemOk(int i)
{
  BOOL v2; // [esp+10h] [ebp-4h]

  v2 = 0;
  if ( AllItemsList[i].itype )
    return 0;
  if ( AllItemsList[i].iMiscId == 21 && AllItemsList[i].iSpell == 2 )
    v2 = 1;
  if ( AllItemsList[i].iMiscId == 22 && AllItemsList[i].iSpell == 32 && gbMaxPlayers != 1 )
    v2 = 1;
  if ( AllItemsList[i].iMiscId == 22 && AllItemsList[i].iSpell == 34 && gbMaxPlayers != 1 )
    v2 = 1;
  if ( AllItemsList[i].iMiscId == 10 )
    v2 = 1;
  if ( AllItemsList[i].iMiscId == 11 )
    v2 = 1;
  if ( AllItemsList[i].iMiscId == 12 )
    v2 = 1;
  if ( AllItemsList[i].iMiscId == 13 )
    v2 = 1;
  if ( AllItemsList[i].iMiscId == 3 )
    v2 = 1;
  if ( AllItemsList[i].iMiscId == 2 )
    v2 = 1;
  if ( AllItemsList[i].iMiscId == 6 )
    v2 = 1;
  if ( AllItemsList[i].iMiscId == 7 )
    v2 = 1;
  if ( AllItemsList[i].iMiscId == 18 )
    v2 = 1;
  if ( AllItemsList[i].iMiscId == 19 )
    v2 = 1;
  return v2;
}

//----- (0042C55F) --------------------------------------------------------
int __fastcall RndHealerItem(int lvl)
{
  int v3[512]; // [esp+10h] [ebp-808h]
  int i; // [esp+810h] [ebp-8h]
  int v; // [esp+814h] [ebp-4h]

  v = 0;
  for ( i = 1; AllItemsList[i].iLoc != -1; ++i )
  {
    if ( AllItemsList[i].iRnd && HealerItemOk(i) && AllItemsList[i].iMinMLvl <= lvl )
      v3[v++] = i;
  }
  return v3[random(50, v)] + 1;
}

//----- (0042C61F) --------------------------------------------------------
void __fastcall SpawnHealer(int lvl)
{
  int idata; // ST14_4
  int i; // [esp+14h] [ebp-8h]
  signed int j; // [esp+14h] [ebp-8h]
  int v5; // [esp+18h] [ebp-4h]

  v5 = random(50, 10) + 10;
  for ( i = 0; v5 > i; ++i )
  {
    item[0]._iSeed = GetRndSeed();
    SetRndSeed(item[0]._iSeed);
    idata = RndHealerItem(lvl) - 1;
    GetItemAttrs(0, idata, lvl);
    qmemcpy(&healitem[i], item, sizeof(ItemStruct));
    healitem[i]._iCreateInfo = lvl | 0x4000;
    healitem[i]._iStatFlag = StoreStatOk(&healitem[i]);
  }
  for ( j = v5; j < 20; ++j )
    healitem[j]._itype = -1;
}

//----- (0042C738) --------------------------------------------------------
void __cdecl SpawnStoreGold()
{
  GetItemAttrs(0, 0, 1);
  qmemcpy(&golditem, item, sizeof(golditem));
  golditem._iStatFlag = 1;
}

//----- (0042C76E) --------------------------------------------------------
void __fastcall RecreateSmithItem(int ii, int idx, int plvl, int iseed)
{
  int idata; // ST18_4

  SetRndSeed(iseed);
  idata = RndSmithItem(plvl) - 1;
  GetItemAttrs(ii, idata, plvl);
  item[ii]._iSeed = iseed;
  item[ii]._iCreateInfo = plvl | 0x400;
  item[ii]._iIdentified = 1;
}

//----- (0042C7F8) --------------------------------------------------------
void __fastcall RecreatePremiumItem(int ii, int idx, int lvl, int iseed)
{
  int idata; // ST20_4

  SetRndSeed(iseed);
  idata = RndPremiumItem(lvl >> 2, lvl) - 1;
  GetItemAttrs(ii, idata, lvl);
  GetItemBonus(ii, idata, lvl >> 1, lvl, 1);
  item[ii]._iSeed = iseed;
  item[ii]._iCreateInfo = lvl | 0x800;
  item[ii]._iIdentified = 1;
}

//----- (0042C8A1) --------------------------------------------------------
void __fastcall RecreateBoyItem(int ii, int idx, int lvl, int iseed)
{
  int idata; // ST20_4

  SetRndSeed(iseed);
  idata = RndBoyItem(lvl) - 1;
  GetItemAttrs(ii, idata, lvl);
  GetItemBonus(ii, idata, lvl, 2 * lvl, 1);
  item[ii]._iSeed = iseed;
  item[ii]._iCreateInfo = lvl | 0x1000;
  item[ii]._iIdentified = 1;
}

//----- (0042C942) --------------------------------------------------------
void __fastcall RecreateWitchItem(int ii, int idx, int lvl, int iseed)
{
  int maxlvl; // [esp+14h] [ebp-8h]
  int v6; // [esp+18h] [ebp-4h]

  if ( idx != 11 && idx != 12 )
  {
    SetRndSeed(iseed);
    v6 = RndWitchItem(lvl) - 1;
    GetItemAttrs(ii, v6, lvl);
    maxlvl = -1;
    if ( random(51, 100) <= 5 )
      maxlvl = 2 * lvl;
    if ( maxlvl == -1 && item[0]._iMiscId == 23 )
      maxlvl = 2 * lvl;
    if ( maxlvl != -1 )
      GetItemBonus(ii, v6, maxlvl >> 1, maxlvl, 1);
  }
  else
  {
    GetItemAttrs(ii, idx, lvl);
  }
  item[ii]._iSeed = iseed;
  item[ii]._iCreateInfo = lvl | 0x2000;
  item[ii]._iIdentified = 1;
}

//----- (0042CA5B) --------------------------------------------------------
void __fastcall RecreateHealerItem(int ii, int idx, int lvl, int iseed)
{
  int idata; // ST18_4

  SetRndSeed(iseed);
  idata = RndHealerItem(lvl) - 1;
  GetItemAttrs(ii, idata, lvl);
  item[ii]._iSeed = iseed;
  item[ii]._iCreateInfo = lvl | 0x4000;
}

//----- (0042CACD) --------------------------------------------------------
void __fastcall RecreateTownItem(int ii, int idx, unsigned __int16 icreateinfo, int iseed, int ivalue)
{
  if ( icreateinfo & 0x400 )
  {
    RecreateSmithItem(ii, idx, icreateinfo & 0x3F, iseed);
  }
  else if ( icreateinfo & 0x800 )
  {
    RecreatePremiumItem(ii, idx, icreateinfo & 0x3F, iseed);
  }
  else if ( icreateinfo & 0x1000 )
  {
    RecreateBoyItem(ii, idx, icreateinfo & 0x3F, iseed);
  }
  else if ( icreateinfo & 0x2000 )
  {
    RecreateWitchItem(ii, idx, icreateinfo & 0x3F, iseed);
  }
  else if ( icreateinfo & 0x4000 )
  {
    RecreateHealerItem(ii, idx, icreateinfo & 0x3F, iseed);
  }
}

//----- (0042CB9C) --------------------------------------------------------
void __cdecl unused_sub_42CB9C()
{
  int v0; // edx
  signed int i; // [esp+Ch] [ebp-8h]

  for ( i = 0; i < 40; ++i )
  {
    if ( !plr[myplr].InvGrid[i] )
    {
      v0 = plr[myplr]._pNumInv;
      qmemcpy(&plr[myplr].InvList[v0], &golditem, sizeof(plr[myplr].InvList[v0]));
      plr[myplr].InvList[v0]._ivalue = 5000;
      plr[myplr].InvList[v0]._iCurs = 6;
      plr[myplr]._pGold += 5000;
      ++plr[myplr]._pNumInv;
      plr[myplr].InvGrid[i] = plr[myplr]._pNumInv;
    }
  }
}

//----- (0042CD40) --------------------------------------------------------
void unused_sub_42CD40()
{
  signed int i; // [esp+Ch] [ebp-4h]

  numpremium = 0;
  for ( i = 0; i < 6; ++i )
    premiumitem[i]._itype = -1;
  SpawnPremium(30);
}

//----- (0042CD9D) --------------------------------------------------------
void __cdecl unused_sub_42CD9D()
{
  signed int i; // [esp+Ch] [ebp-8h]
  signed int j; // [esp+Ch] [ebp-8h]
  int iv; // [esp+10h] [ebp-4h]

  for ( i = 0; i < 40; ++i )
  {
    if ( plr[myplr].InvGrid[i] > 0 )
    {
      iv = plr[myplr].InvGrid[i] - 1;
      if ( plr[myplr].InvList[iv]._itype == 11 )
        RemoveInvItem(myplr, iv);
    }
  }
  for ( j = 0; j < 8; ++j )
  {
    if ( plr[myplr].SpdList[j]._itype == 11 )
      plr[myplr].SpdList[j]._itype = -1;
  }
  plr[myplr]._pGold = 0;
}

//----- (0042CFC5) --------------------------------------------------------
void __cdecl RecalcStoreStats()
{
  signed int i; // [esp+Ch] [ebp-4h]
  signed int j; // [esp+Ch] [ebp-4h]
  signed int k; // [esp+Ch] [ebp-4h]
  signed int l; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 20; ++i )
  {
    if ( smithitem[i]._itype != -1 )
      smithitem[i]._iStatFlag = StoreStatOk(&smithitem[i]);
  }
  for ( j = 0; j < 6; ++j )
  {
    if ( premiumitem[j]._itype != -1 )
      premiumitem[j]._iStatFlag = StoreStatOk(&premiumitem[j]);
  }
  for ( k = 0; k < 20; ++k )
  {
    if ( witchitem[k]._itype != -1 )
      witchitem[k]._iStatFlag = StoreStatOk(&witchitem[k]);
  }
  for ( l = 0; l < 20; ++l )
  {
    if ( healitem[l]._itype != -1 )
      healitem[l]._iStatFlag = StoreStatOk(&healitem[l]);
  }
  boyitem._iStatFlag = StoreStatOk(&boyitem);
}

