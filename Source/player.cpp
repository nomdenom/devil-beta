#include "all.h"

//----- (00468CD0) --------------------------------------------------------
void __fastcall SetPlayerGPtrs(DWORD *pData, DWORD *pAnim)
{
  signed int i; // [esp+14h] [ebp-8h]

  for ( i = 0; i < 8; ++i )
    pAnim[i] = (DWORD)pData + pData[i];
}

//----- (00468D2D) --------------------------------------------------------
void __fastcall player_468D2D(int a1)
{
  if ( leveltype )
  {
    SetPlayerGPtrs((DWORD *)plr[a1]._pNData, (DWORD *)plr[a1]._pNAnim);
    SetPlayerGPtrs((DWORD *)plr[a1]._pWData, (DWORD *)plr[a1]._pWAnim);
    SetPlayerGPtrs((DWORD *)plr[a1]._pAData, (DWORD *)plr[a1]._pAAnim);
    SetPlayerGPtrs((DWORD *)plr[a1]._pHData, (DWORD *)plr[a1]._pHAnim);
    SetPlayerGPtrs((DWORD *)plr[a1]._pLData, (DWORD *)plr[a1]._pLAnim);
    SetPlayerGPtrs((DWORD *)plr[a1]._pFData, (DWORD *)plr[a1]._pFAnim);
    SetPlayerGPtrs((DWORD *)plr[a1]._pTData, (DWORD *)plr[a1]._pTAnim);
    SetPlayerGPtrs((DWORD *)plr[a1]._pDData, (DWORD *)plr[a1]._pDAnim);
    if ( plr[a1]._pBlockFlag )
      SetPlayerGPtrs((DWORD *)plr[a1]._pBData, (DWORD *)plr[a1]._pBAnim);
  }
  else
  {
    SetPlayerGPtrs((DWORD *)plr[a1]._pNData, (DWORD *)plr[a1]._pNAnim);
    SetPlayerGPtrs((DWORD *)plr[a1]._pWData, (DWORD *)plr[a1]._pWAnim);
  }
}

//----- (00469033) --------------------------------------------------------
void __fastcall LoadPlrGFX(int pnum, int gfxflag)
{
  int v2; // [esp+10h] [ebp-B8h]
  char v5[16]; // [esp+1Ch] [ebp-ACh]
  char pszName[128]; // [esp+2Ch] [ebp-9Ch]
  char v7[16]; // [esp+ACh] [ebp-1Ch]
  char v8; // [esp+BCh] [ebp-Ch]
  char v9; // [esp+C0h] [ebp-8h]
  char v10; // [esp+C4h] [ebp-4h]

  v2 = plr[pnum]._pClass;
  if ( plr[pnum]._pClass )
  {
    if ( v2 == 1 )
    {
      strcpy(v5, "Rogue");
      v8 = 82;
    }
    else if ( v2 == 2 )
    {
      strcpy(v5, "Sorceror");
      v8 = 83;
    }
  }
  else
  {
    strcpy(v5, "Warrior");
    v8 = 87;
  }
  v9 = *((_BYTE *)&plryoff2[9] + (plr[pnum]._pgfxnum >> 4));
  v10 = WepChar[plr[pnum]._pgfxnum & 0xF];
  sprintf(v7, "%c%c%c", v8, v9, v10);
  if ( leveltype )
  {
    if ( gfxflag > 8 )
    {
      switch ( gfxflag )
      {
        case 16:
          sprintf(pszName, "PlrGFX\\%s\\%s\\%sLM.CEL", v5, v7, v7);
          LoadFileWithMem(pszName, plr[pnum]._pLData);
          SetPlayerGPtrs((DWORD *)plr[pnum]._pLData, (DWORD *)plr[pnum]._pLAnim);
          break;
        case 32:
          sprintf(pszName, "PlrGFX\\%s\\%s\\%sFM.CEL", v5, v7, v7);
          LoadFileWithMem(pszName, plr[pnum]._pFData);
          SetPlayerGPtrs((DWORD *)plr[pnum]._pFData, (DWORD *)plr[pnum]._pFAnim);
          break;
        case 64:
          sprintf(pszName, "PlrGFX\\%s\\%s\\%sQM.CEL", v5, v7, v7);
          LoadFileWithMem(pszName, plr[pnum]._pTData);
          SetPlayerGPtrs((DWORD *)plr[pnum]._pTData, (DWORD *)plr[pnum]._pTAnim);
          break;
        case 128:
          sprintf(pszName, "PlrGFX\\%s\\%s\\%sDT.CEL", v5, v7, v7);
          LoadFileWithMem(pszName, plr[pnum]._pDData);
          SetPlayerGPtrs((DWORD *)plr[pnum]._pDData, (DWORD *)plr[pnum]._pDAnim);
          break;
        case 256:
          sprintf(pszName, "PlrGFX\\%s\\%s\\%sBL.CEL", v5, v7, v7);
          LoadFileWithMem(pszName, plr[pnum]._pBData);
          SetPlayerGPtrs((DWORD *)plr[pnum]._pBData, (DWORD *)plr[pnum]._pBAnim);
          break;
        default:
          break;
      }
    }
    else
    {
      switch ( gfxflag )
      {
        case 8:
          sprintf(pszName, "PlrGFX\\%s\\%s\\%sHT.CEL", v5, v7, v7);
          LoadFileWithMem(pszName, plr[pnum]._pHData);
          SetPlayerGPtrs((DWORD *)plr[pnum]._pHData, (DWORD *)plr[pnum]._pHAnim);
          break;
        case 1:
          sprintf(pszName, "PlrGFX\\%s\\%s\\%sAS.CEL", v5, v7, v7);
          LoadFileWithMem(pszName, plr[pnum]._pNData);
          SetPlayerGPtrs((DWORD *)plr[pnum]._pNData, (DWORD *)plr[pnum]._pNAnim);
          break;
        case 2:
          sprintf(pszName, "PlrGFX\\%s\\%s\\%sAW.CEL", v5, v7, v7);
          LoadFileWithMem(pszName, plr[pnum]._pWData);
          SetPlayerGPtrs((DWORD *)plr[pnum]._pWData, (DWORD *)plr[pnum]._pWAnim);
          break;
        case 4:
          sprintf(pszName, "PlrGFX\\%s\\%s\\%sAT.CEL", v5, v7, v7);
          LoadFileWithMem(pszName, plr[pnum]._pAData);
          SetPlayerGPtrs((DWORD *)plr[pnum]._pAData, (DWORD *)plr[pnum]._pAAnim);
          break;
      }
    }
  }
  else if ( gfxflag == 1 )
  {
    sprintf(pszName, "PlrGFX\\%s\\%s\\%sST.CEL", v5, v7, v7);
    LoadFileWithMem(pszName, plr[pnum]._pNData);
    SetPlayerGPtrs((DWORD *)plr[pnum]._pNData, (DWORD *)plr[pnum]._pNAnim);
  }
  else
  {
    sprintf(pszName, "PlrGFX\\%s\\%s\\%sWL.CEL", v5, v7, v7);
    LoadFileWithMem(pszName, plr[pnum]._pWData);
    SetPlayerGPtrs((DWORD *)plr[pnum]._pWData, (DWORD *)plr[pnum]._pWAnim);
  }
  plr[pnum]._pGFXLoad |= gfxflag;
}

//----- (004699D5) --------------------------------------------------------
void __fastcall InitPlayerGFX(int pnum)
{
  int v1; // [esp+Ch] [ebp-134h]
  char v3[16]; // [esp+14h] [ebp-12Ch]
  char pszName[256]; // [esp+24h] [ebp-11Ch]
  char v5[16]; // [esp+124h] [ebp-1Ch]
  char v6; // [esp+134h] [ebp-Ch]
  char v7; // [esp+138h] [ebp-8h]
  char v8; // [esp+13Ch] [ebp-4h]

  v1 = plr[pnum]._pClass;
  if ( plr[pnum]._pClass )
  {
    if ( v1 == 1 )
    {
      strcpy(v3, "Rogue");
      v6 = 82;
    }
    else if ( v1 == 2 )
    {
      strcpy(v3, "Sorceror");
      v6 = 83;
    }
  }
  else
  {
    strcpy(v3, "Warrior");
    v6 = 87;
  }
  v7 = *((_BYTE *)&plryoff2[9] + (plr[pnum]._pgfxnum >> 4));
  v8 = WepChar[plr[pnum]._pgfxnum & 0xF];
  sprintf(v5, "%c%c%c", v6, v7, v8);
  if ( leveltype )
  {
    sprintf(pszName, "PlrGFX\\%s\\%s\\%sAS.CEL", v3, v5, v5);
    LoadFileWithMem(pszName, plr[pnum]._pNData);
    sprintf(pszName, "PlrGFX\\%s\\%s\\%sAW.CEL", v3, v5, v5);
    LoadFileWithMem(pszName, plr[pnum]._pWData);
    sprintf(pszName, "PlrGFX\\%s\\%s\\%sAT.CEL", v3, v5, v5);
    LoadFileWithMem(pszName, plr[pnum]._pAData);
    sprintf(pszName, "PlrGFX\\%s\\%s\\%sHT.CEL", v3, v5, v5);
    LoadFileWithMem(pszName, plr[pnum]._pHData);
    sprintf(pszName, "PlrGFX\\%s\\%s\\%sLM.CEL", v3, v5, v5);
    LoadFileWithMem(pszName, plr[pnum]._pLData);
    sprintf(pszName, "PlrGFX\\%s\\%s\\%sFM.CEL", v3, v5, v5);
    LoadFileWithMem(pszName, plr[pnum]._pFData);
    sprintf(pszName, "PlrGFX\\%s\\%s\\%sQM.CEL", v3, v5, v5);
    LoadFileWithMem(pszName, plr[pnum]._pTData);
    if ( plr[pnum]._pBlockFlag )
    {
      sprintf(pszName, "PlrGFX\\%s\\%s\\%sBL.CEL", v3, v5, v5);
      LoadFileWithMem(pszName, plr[pnum]._pBData);
    }
  }
  else
  {
    sprintf(pszName, "PlrGFX\\%s\\%s\\%sST.CEL", v3, v5, v5);
    LoadFileWithMem(pszName, plr[pnum]._pNData);
    sprintf(pszName, "PlrGFX\\%s\\%s\\%sWL.CEL", v3, v5, v5);
    LoadFileWithMem(pszName, plr[pnum]._pWData);
  }
  player_468D2D(pnum);
  plr[pnum]._pGFXLoad = 383;
}

//----- (00469E96) --------------------------------------------------------
void __fastcall InitPlrGFXMem(int pnum)
{
  int v1; // [esp+Ch] [ebp-4h]

  v1 = pnum;
  assert(!plr[pnum]._pNData, "PLAYER.CPP", 407);
  plr[pnum]._pNData = DiabloAllocPtr(284672, 408, "PLAYER.CPP");
  plr[v1]._pWData = DiabloAllocPtr(118784, 409, "PLAYER.CPP");
  plr[v1]._pAData = DiabloAllocPtr(356352, 410, "PLAYER.CPP");
  plr[v1]._pHData = DiabloAllocPtr(105472, 411, "PLAYER.CPP");
  plr[v1]._pLData = DiabloAllocPtr(368640, 412, "PLAYER.CPP");
  plr[v1]._pFData = DiabloAllocPtr(493568, 413, "PLAYER.CPP");
  plr[v1]._pTData = DiabloAllocPtr(595968, 414, "PLAYER.CPP");
  plr[v1]._pDData = DiabloAllocPtr(269312, 415, "PLAYER.CPP");
  plr[v1]._pBData = DiabloAllocPtr(78848, 416, "PLAYER.CPP");
  plr[v1]._pGFXLoad = 0;
}

//----- (0046A0BE) --------------------------------------------------------
void __fastcall FreePlayerGFX(int pnum)
{
  int v1; // ST10_4

  v1 = pnum;
  mem_free_dbg(plr[pnum]._pNData, 424, "PLAYER.CPP");
  plr[v1]._pNData = 0;
  mem_free_dbg(plr[v1]._pWData, 426, "PLAYER.CPP");
  plr[v1]._pWData = 0;
  mem_free_dbg(plr[v1]._pAData, 428, "PLAYER.CPP");
  plr[v1]._pAData = 0;
  mem_free_dbg(plr[v1]._pHData, 430, "PLAYER.CPP");
  plr[v1]._pHData = 0;
  mem_free_dbg(plr[v1]._pLData, 432, "PLAYER.CPP");
  plr[v1]._pLData = 0;
  mem_free_dbg(plr[v1]._pFData, 434, "PLAYER.CPP");
  plr[v1]._pFData = 0;
  mem_free_dbg(plr[v1]._pTData, 436, "PLAYER.CPP");
  plr[v1]._pTData = 0;
  mem_free_dbg(plr[v1]._pDData, 438, "PLAYER.CPP");
  plr[v1]._pDData = 0;
  mem_free_dbg(plr[v1]._pBData, 440, "PLAYER.CPP");
  plr[v1]._pBData = 0;
  plr[v1]._pGFXLoad = 0;
}

//----- (0046A3AA) --------------------------------------------------------
void __fastcall NewPlrAnim(int pnum, int Peq, int numFrames, int Delay, int width)
{
  plr[pnum]._pAnimData = Peq;
  plr[pnum]._pAnimLen = numFrames;
  plr[pnum]._pAnimFrame = 1;
  plr[pnum]._pAnimCnt = 0;
  plr[pnum]._pAnimDelay = Delay;
  plr[pnum]._pAnimWidth = width;
  plr[pnum]._pAnimWidth2 = (width - 64) >> 1;
}

//----- (0046A4AC) --------------------------------------------------------
void __fastcall ClearPlrPVars(int pnum)
{
  plr[pnum]._pVar1 = 0;
  plr[pnum]._pVar2 = 0;
  plr[pnum]._pVar3 = 0;
  plr[pnum]._pVar4 = 0;
  plr[pnum]._pVar5 = 0;
  plr[pnum]._pVar6 = 0;
  plr[pnum]._pVar7 = 0;
  plr[pnum]._pVar8 = 0;
}

//----- (0046A5CA) --------------------------------------------------------
void __fastcall SetPlrAnims(int pnum)
{
  int v1; // [esp+10h] [ebp-8h]
  int v2; // [esp+14h] [ebp-4h]

  plr[pnum]._pNWidth = 96;
  plr[pnum]._pWWidth = 96;
  plr[pnum]._pAWidth = 128;
  plr[pnum]._pHWidth = 96;
  plr[pnum]._pSWidth = 96;
  plr[pnum]._pDWidth = 128;
  plr[pnum]._pBWidth = 96;
  v1 = plr[pnum]._pClass;
  if ( leveltype )
  {
    plr[pnum]._pNFrames = PlrGFXAnimLens[v1][0];
    plr[pnum]._pWFrames = PlrGFXAnimLens[v1][2];
    plr[pnum]._pAFrames = PlrGFXAnimLens[v1][1];
    plr[pnum]._pHFrames = PlrGFXAnimLens[v1][6];
    plr[pnum]._pSFrames = PlrGFXAnimLens[v1][5];
    plr[pnum]._pDFrames = PlrGFXAnimLens[v1][4];
    plr[pnum]._pBFrames = PlrGFXAnimLens[v1][3];
    plr[pnum]._pAFNum = PlrGFXAnimLens[v1][9];
    plr[pnum]._pSFNum = PlrGFXAnimLens[v1][10];
  }
  else
  {
    plr[pnum]._pNFrames = PlrGFXAnimLens[v1][7];
    plr[pnum]._pWFrames = PlrGFXAnimLens[v1][8];
  }
  v2 = plr[pnum]._pgfxnum & 0xF;
  if ( v1 )
  {
    if ( v1 == 1 )
    {
      switch ( v2 )
      {
        case 5:
          plr[pnum]._pAFrames = 22;
          plr[pnum]._pAFNum = 13;
          break;
        case 4:
          plr[pnum]._pAFrames = 12;
          plr[pnum]._pAFNum = 7;
          plr[pnum]._pDFrames = 21;
          break;
        case 8:
          plr[pnum]._pAFrames = 16;
          plr[pnum]._pAFNum = 11;
          break;
      }
    }
    else if ( v1 == 2 )
    {
      plr[pnum]._pSWidth = 128;
      if ( v2 )
      {
        switch ( v2 )
        {
          case 1:
            plr[pnum]._pAFNum = 9;
            break;
          case 4:
            plr[pnum]._pAFrames = 20;
            plr[pnum]._pAFNum = 16;
            break;
          case 5:
            plr[pnum]._pAFrames = 24;
            plr[pnum]._pAFNum = 16;
            break;
        }
      }
      else
      {
        plr[pnum]._pAFrames = 20;
      }
    }
  }
  else if ( v2 == 3 )
  {
    plr[pnum]._pDFrames = 21;
  }
  else if ( v2 )
  {
    switch ( v2 )
    {
      case 1:
        plr[pnum]._pDFrames = 20;
        if ( plr[pnum]._pgfxnum == 33 )
          plr[pnum]._pDFrames = 15;
        break;
      case 2:
        plr[pnum]._pDFrames = 21;
        if ( plr[pnum]._pgfxnum == 34 )
          plr[pnum]._pDFrames = 15;
        break;
      case 4:
        if ( leveltype )
          plr[pnum]._pNFrames = 8;
        plr[pnum]._pAWidth = 96;
        plr[pnum]._pAFNum = 12;
        break;
      case 5:
        plr[pnum]._pAFrames = 20;
        plr[pnum]._pAFNum = 10;
        break;
      case 6:
        plr[pnum]._pDFrames = 16;
        break;
      case 7:
        if ( plr[pnum]._pgfxnum != 39 )
          plr[pnum]._pDFrames = 16;
        break;
      case 8:
        plr[pnum]._pAFrames = 16;
        plr[pnum]._pAFNum = 11;
        plr[pnum]._pDFrames = 20;
        break;
    }
  }
  else
  {
    plr[pnum]._pDFrames = 20;
    if ( plr[pnum]._pgfxnum == 16 )
      plr[pnum]._pDFrames = 15;
  }
}

//----- (0046AEB5) --------------------------------------------------------
void __fastcall CreatePlayer(int pnum, char c)
{
  int v2; // eax
  int v3; // eax
  QWORD *v4; // eax
  QWORD *v5; // eax
  QWORD *v6; // eax
  QWORD *v7; // eax
  signed int i; // [esp+14h] [ebp-8h]
  signed int j; // [esp+14h] [ebp-8h]
  signed int k; // [esp+14h] [ebp-8h]
  signed int l; // [esp+14h] [ebp-8h]
  char v14; // [esp+18h] [ebp-4h]
  char v15; // [esp+18h] [ebp-4h]
  char v16; // [esp+18h] [ebp-4h]
  char v17; // [esp+18h] [ebp-4h]

  v2 = time(0);
  SetRndSeed(v2);
  plr[pnum]._pClass = c;
  v14 = StrengthTbl[c];
  if ( v14 < 0 )
    v14 = 0;
  plr[pnum]._pStrength = v14;
  plr[pnum]._pBaseStr = v14;
  v15 = MagicTbl[c];
  if ( v15 < 0 )
    v15 = 0;
  plr[pnum]._pMagic = v15;
  plr[pnum]._pBaseMag = v15;
  v16 = DexterityTbl[c];
  if ( v16 < 0 )
    v16 = 0;
  plr[pnum]._pDexterity = v16;
  plr[pnum]._pBaseDex = v16;
  v17 = VitalityTbl[c];
  if ( v17 < 0 )
    v17 = 0;
  plr[pnum]._pVitality = v17;
  plr[pnum]._pBaseVit = v17;
  plr[pnum]._pStatPts = 0;
  if ( plr[pnum]._pClass == 1 )
    v3 = plr[pnum]._pLevel * (plr[pnum]._pStrength + plr[pnum]._pDexterity) / 200;
  else
    v3 = plr[pnum]._pStrength * plr[pnum]._pLevel / 100;
  plr[pnum]._pDamageMod = v3;
  plr[pnum]._pBaseToBlk = ToBlkTbl[c];
  plr[pnum]._pHitPoints = plr[pnum]._pVitality << 6;
  if ( !plr[pnum]._pClass )
    plr[pnum]._pHitPoints *= 2;
  if ( plr[pnum]._pClass == 1 )
    plr[pnum]._pHitPoints += plr[pnum]._pHitPoints >> 1;
  plr[pnum]._pMaxHP = plr[pnum]._pHitPoints;
  plr[pnum]._pHPBase = plr[pnum]._pHitPoints;
  plr[pnum]._pMaxHPBase = plr[pnum]._pHitPoints;
  plr[pnum]._pMana = plr[pnum]._pMagic << 6;
  if ( plr[pnum]._pClass == 2 )
    plr[pnum]._pMana *= 2;
  if ( plr[pnum]._pClass == 1 )
    plr[pnum]._pMana += plr[pnum]._pMana >> 1;
  plr[pnum]._pMaxMana = plr[pnum]._pMana;
  plr[pnum]._pManaBase = plr[pnum]._pMana;
  plr[pnum]._pMaxManaBase = plr[pnum]._pMana;
  plr[pnum]._pLevel = 1;
  plr[pnum]._pMaxLvl = plr[pnum]._pLevel;
  plr[pnum]._pExperience = 0;
  plr[pnum]._pMaxExp = plr[pnum]._pExperience;
  plr[pnum]._pNextExper = ExpLvlsTbl[1];
  plr[pnum]._pArmorClass = 0;
  plr[pnum]._pMagResist = 0;
  plr[pnum]._pFireResist = 0;
  plr[pnum]._pLghtResist = 0;
  plr[pnum]._pLightRad = 10;
  plr[pnum]._pInfraFlag = 0;
  if ( !c )
  {
    v4 = &plr[pnum]._pAblSpells;
    *(_DWORD *)v4 = 0x2000000;
    *((_DWORD *)v4 + 1) = 0;
  }
  if ( c == 1 )
  {
    v5 = &plr[pnum]._pAblSpells;
    *(_DWORD *)v5 = 0x8000000;
    *((_DWORD *)v5 + 1) = 0;
  }
  if ( c == 2 )
  {
    v6 = &plr[pnum]._pAblSpells;
    *(_DWORD *)v6 = 0x4000000;
    *((_DWORD *)v6 + 1) = 0;
  }
  if ( c == 2 )
  {
    v7 = &plr[pnum]._pMemSpells;
    *(_DWORD *)v7 = 1;
  }
  else
  {
    v7 = &plr[pnum]._pMemSpells;
    *(_DWORD *)v7 = 0;
  }
  *((_DWORD *)v7 + 1) = 0;
  for ( i = 0; i < 64; ++i )
    plr[pnum]._pSplLvl[i] = 0;
  plr[pnum]._pSpellFlags = 0;
  if ( plr[pnum]._pClass == 2 )
    plr[pnum]._pSplLvl[1] = 2;
  for ( j = 0; j < 3; ++j )
    plr[pnum]._pSplHotKey[j] = -1;
  if ( c )
  {
    if ( c == 1 )
    {
      plr[pnum]._pgfxnum = 4;
    }
    else if ( c == 2 )
    {
      plr[pnum]._pgfxnum = 8;
    }
  }
  else
  {
    plr[pnum]._pgfxnum = 3;
  }
  for ( k = 0; k < 17; ++k )
    plr[pnum]._pLvlVisited[k] = 0;
  for ( l = 0; l < 10; ++l )
    plr[pnum]._pSLvlVisited[l] = 0;
  plr[pnum]._pLvlChanging = 0;
  CreatePlrItems(pnum);
  SetRndSeed(0);
}

//----- (0046B9CC) --------------------------------------------------------
void __fastcall NextPlrLevel(int pnum)
{
  int v2; // [esp+10h] [ebp-4h]
  int v3; // [esp+10h] [ebp-4h]

  ++plr[pnum]._pLevel;
  ++plr[pnum]._pMaxLvl;
  plr[pnum]._pStatPts += 5;
  plr[pnum]._pNextExper = ExpLvlsTbl[plr[pnum]._pLevel];
  v2 = plr[pnum]._pBaseVit / 10 << 6;
  if ( !plr[pnum]._pClass )
    v2 = plr[pnum]._pBaseVit / 10 << 7;
  if ( plr[pnum]._pClass == 1 )
    v2 += v2 >> 1;
  plr[pnum]._pMaxHP += v2;
  plr[pnum]._pHitPoints = plr[pnum]._pMaxHP;
  plr[pnum]._pMaxHPBase += v2;
  plr[pnum]._pHPBase = plr[pnum]._pMaxHPBase;
  if ( myplr == pnum )
    drawhpflag = 1;
  v3 = plr[pnum]._pBaseMag / 10 << 6;
  if ( plr[pnum]._pClass == 2 )
    v3 = plr[pnum]._pBaseMag / 10 << 7;
  if ( plr[pnum]._pClass == 1 )
    v3 += v3 >> 1;
  plr[pnum]._pMaxMana += v3;
  plr[pnum]._pMaxManaBase += v3;
  if ( !(plr[pnum]._pIFlags & 0x8000000) )
  {
    plr[pnum]._pMana = plr[pnum]._pMaxMana;
    plr[pnum]._pManaBase = plr[pnum]._pMaxManaBase;
  }
  if ( myplr == pnum )
    drawmanaflag = 1;
}

//----- (0046BD41) --------------------------------------------------------
void __fastcall AddPlrExperience(int pnum, int lvl, int exp)
{
  int i; // [esp+20h] [ebp-14h]
  int j; // [esp+24h] [ebp-10h]
  int v6; // [esp+30h] [ebp-4h]

  if ( pnum == myplr )
  {
    v6 = (signed __int64)((((double)lvl - (double)plr[pnum]._pLevel) * 0.1 + 1.0) * (double)exp);
    if ( v6 < 0 )
      v6 = 0;
    plr[pnum]._pExperience += v6;
    if ( plr[pnum]._pExperience < ExpLvlsTbl[50] )
    {
      for ( i = 0; plr[pnum]._pExperience >= ExpLvlsTbl[i]; ++i )
        ;
      if ( plr[pnum]._pLevel != i )
      {
        for ( j = 0; i - plr[pnum]._pLevel >= j; ++j )
          NextPlrLevel(pnum);
      }
      NetSendCmdParam1(0, 0x36u, plr[myplr]._pLevel);
    }
    else
    {
      plr[pnum]._pLevel = 51;
    }
  }
}

//----- (0046BF1B) --------------------------------------------------------
void __fastcall AddPlrMonstExper(int lvl, int exp, char pmask)
{
  signed int i; // [esp+18h] [ebp-8h]
  int v4; // [esp+1Ch] [ebp-4h]

  v4 = 0;
  for ( i = 0; i < 4; ++i )
  {
    if ( pmask & (1 << i) )
      ++v4;
  }
  if ( pmask && pmask & (1 << myplr) )
    AddPlrExperience(myplr, lvl, exp / v4);
}

//----- (0046BFB5) --------------------------------------------------------
void __fastcall InitPlayer(int pnum, BOOL FirstTime)
{
  QWORD *v2; // eax
  QWORD *v3; // eax
  QWORD *v4; // eax
  QWORD *v5; // eax
  unsigned int i; // [esp+14h] [ebp-4h]

  if ( FirstTime )
  {
    if ( plr[pnum]._pClass )
    {
      if ( plr[pnum]._pClass == 1 )
      {
        plr[pnum]._pRSpell = 28;
        plr[pnum]._pRSplType = 0;
      }
      else if ( plr[pnum]._pClass == 2 )
      {
        plr[pnum]._pRSpell = 1;
        plr[pnum]._pRSplType = 1;
      }
    }
    else
    {
      plr[pnum]._pRSpell = 26;
      plr[pnum]._pRSplType = 0;
    }
    v2 = &plr[pnum]._pScrlSpells;
    *(_DWORD *)v2 = 0;
    *((_DWORD *)v2 + 1) = 0;
    plr[pnum]._pSBkSpell = -1;
    plr[pnum]._pSpell = plr[pnum]._pRSpell;
    plr[pnum]._pSplType = plr[pnum]._pRSplType;
    plr[pnum]._pwtype = (plr[pnum]._pgfxnum & 0xF) == 4;
  }
  if ( plr[pnum].plrlevel == currlevel || leveldebug )
  {
    SetPlrAnims(pnum);
    plr[pnum]._pxoff = 0;
    plr[pnum]._pyoff = 0;
    plr[pnum]._pxvel = 0;
    plr[pnum]._pyvel = 0;
    ClearPlrPVars(pnum);
    if ( (signed int)(plr[pnum]._pHitPoints & 0xFFFFFFC0) <= 0 )
    {
      plr[pnum]._pmode = 8;
      NewPlrAnim(pnum, plr[pnum]._pDAnim[0], plr[pnum]._pDFrames, 1, plr[pnum]._pDWidth);
    }
    else
    {
      plr[pnum]._pmode = 0;
      NewPlrAnim(pnum, plr[pnum]._pNAnim[0], plr[pnum]._pNFrames, 3, plr[pnum]._pNWidth);
      plr[pnum]._pAnimFrame = random(2, plr[pnum]._pNFrames - 1) + 1;
      plr[pnum]._pAnimCnt = random(2, 3);
    }
    plr[pnum]._pdir = 0;
    plr[pnum]._peflag = 0;
    if ( pnum == myplr )
    {
      if ( !FirstTime || currlevel )
      {
        plr[pnum].WorldX = ViewX;
        plr[pnum].WorldY = ViewY;
      }
      plr[pnum]._ptargx = plr[pnum].WorldX;
      plr[pnum]._ptargy = plr[pnum].WorldY;
    }
    else
    {
      plr[pnum]._ptargx = plr[pnum].WorldX;
      plr[pnum]._ptargy = plr[pnum].WorldY;
      for ( i = 0; i < 8 && !PosOkPlayer(pnum, plrxoff2[i] + plr[pnum].WorldX, plryoff2[i] + plr[pnum].WorldY); ++i )
        ;
      plr[pnum].WorldX += plrxoff2[i];
      plr[pnum].WorldY += plryoff2[i];
    }
    plr[pnum]._px = plr[pnum].WorldX;
    plr[pnum]._py = plr[pnum].WorldY;
    plr[pnum].walkpath[0] = -1;
    plr[pnum].destAction = -1;
    if ( pnum == myplr )
      plr[pnum]._plid = AddLight(plr[pnum].WorldX, plr[pnum].WorldY, plr[pnum]._pLightRad);
    else
      plr[pnum]._plid = -1;
    plr[pnum]._pvid = AddVision(plr[pnum].WorldX, plr[pnum].WorldY, plr[pnum]._pLightRad, pnum == myplr);
  }
  if ( plr[pnum]._pClass )
  {
    if ( plr[pnum]._pClass == 1 )
    {
      v4 = &plr[pnum]._pAblSpells;
      *(_DWORD *)v4 = 0x8000000;
      *((_DWORD *)v4 + 1) = 0;
    }
    else if ( plr[pnum]._pClass == 2 )
    {
      v5 = &plr[pnum]._pAblSpells;
      *(_DWORD *)v5 = 0x4000000;
      *((_DWORD *)v5 + 1) = 0;
    }
  }
  else
  {
    v3 = &plr[pnum]._pAblSpells;
    *(_DWORD *)v3 = 0x2000000;
    *((_DWORD *)v3 + 1) = 0;
  }
  plr[pnum]._pNextExper = ExpLvlsTbl[plr[pnum]._pLevel];
  plr[pnum]._pInvincible = 0;
  if ( pnum == myplr )
  {
    deathdelay = 0;
    deathflag = 0;
    ScrollInfo._sxoff = 0;
    ScrollInfo._syoff = 0;
    ScrollInfo._sdir = 0;
    if ( currlevel == 1 && !plr[pnum]._pLvlVisited[1] && gbMaxPlayers == 1 )
    {
      sfxdelay = 40;
      if ( plr[pnum]._pClass )
      {
        if ( plr[pnum]._pClass == 1 )
        {
          sfxdnum = 194;
        }
        else if ( plr[pnum]._pClass == 2 )
        {
          sfxdnum = 166;
        }
      }
      else
      {
        sfxdnum = 222;
      }
    }
  }
}

//----- (0046CBAC) --------------------------------------------------------
void __cdecl InitMultiView()
{
  ViewX = plr[myplr].WorldX;
  ViewY = plr[myplr].WorldY;
}

//----- (0046CC04) --------------------------------------------------------
void __fastcall InitPlayerLoc(int pnum, BOOL flag)
{
  int x; // [esp+14h] [ebp-14h]
  int xa; // [esp+14h] [ebp-14h]
  int xb; // [esp+14h] [ebp-14h]
  SHORT *v7; // [esp+18h] [ebp-10h]
  SHORT *v8; // [esp+18h] [ebp-10h]
  SHORT *v9; // [esp+18h] [ebp-10h]
  int v10; // [esp+1Ch] [ebp-Ch]
  int v11; // [esp+1Ch] [ebp-Ch]
  int v12; // [esp+1Ch] [ebp-Ch]
  signed int i; // [esp+20h] [ebp-8h]
  signed int j; // [esp+20h] [ebp-8h]
  signed int k; // [esp+20h] [ebp-8h]
  int y; // [esp+24h] [ebp-4h]
  int ya; // [esp+24h] [ebp-4h]
  int yb; // [esp+24h] [ebp-4h]

  x = plr[pnum].WorldX - 1;
  y = plr[pnum].WorldY + 1;
  v10 = 0;
  v7 = dpiece_defs_map_1[gendung_get_dpiece_num_from_coord(x, y)];
  for ( i = 2; i < 10; ++i )
    v10 |= (unsigned __int16)v7[i];
  if ( (unsigned __int8)nSolidTable[dPiece[x][y]] | dArch[x][y] | v10 )
    plr[pnum]._peflag = 1;
  else
    plr[pnum]._peflag = 0;
  if ( flag == 1 && plr[pnum]._peflag == 1 )
  {
    xa = plr[pnum].WorldX;
    ya = plr[pnum].WorldY + 2;
    v11 = 0;
    v8 = dpiece_defs_map_1[gendung_get_dpiece_num_from_coord(plr[pnum].WorldX, ya)];
    for ( j = 2; j < 10; ++j )
      v11 |= (unsigned __int16)v8[j];
    if ( !(dArch[xa][ya] | v11) )
    {
      xb = plr[pnum].WorldX - 2;
      yb = plr[pnum].WorldY + 1;
      v12 = 0;
      v9 = dpiece_defs_map_1[gendung_get_dpiece_num_from_coord(xb, yb)];
      for ( k = 2; k < 10; ++k )
        v12 |= (unsigned __int16)v9[k];
      if ( dArch[xb][yb] | v12 )
        plr[pnum]._peflag = 2;
    }
  }
}

//----- (0046CEDF) --------------------------------------------------------
int __fastcall unused_sub_46CEDF(int pnum, int mi)
{
  return GetDirection(plr[pnum].WorldX, plr[pnum].WorldY, monster[mi]._mx, monster[mi]._my);
}

//----- (0046CF61) --------------------------------------------------------
int __fastcall unused_sub_46CF61(int pnum, int x, int y)
{
  int v6; // [esp+14h] [ebp-4h]

  v6 = GetDirection(plr[pnum].WorldX, plr[pnum].WorldY, x, y);
  if ( plr[pnum].WorldX == x && plr[pnum].WorldY == y )
    v6 = plr[pnum]._pdir;
  return v6;
}

//----- (0046D035) --------------------------------------------------------
BOOL __fastcall SolidLoc(int x, int y)
{
  return (unsigned __int8)nSolidTable[dPiece[x][y]];
}

//----- (0046D06F) --------------------------------------------------------
BOOL __fastcall PlrDirOK(int pnum, int dir)
{
  int py; // [esp+14h] [ebp-Ch]
  BOOL v5; // [esp+18h] [ebp-8h]
  int px; // [esp+1Ch] [ebp-4h]

  px = offset_x[dir] + plr[pnum].WorldX;
  py = offset_y[dir] + plr[pnum].WorldY;
  if ( px < 0 )
    return 0;
  if ( !dPiece[px][py] )
    return 0;
  if ( !PosOkPlayer(pnum, px, py) )
    return 0;
  v5 = 1;
  if ( dir == 6 )
    v5 = !SolidLoc(px, py + 1) && !(dFlags[px][py + 1] & 0x20);
  if ( v5 && dir == 2 )
    v5 = !SolidLoc(px + 1, py) && !(dFlags[px + 1][py] & 0x20);
  return v5;
}

//----- (0046D1F1) --------------------------------------------------------
void __fastcall PlrClrTrans(int x, int y)
{
  int i; // [esp+14h] [ebp-Ch]
  int j; // [esp+18h] [ebp-8h]

  for ( i = y - 1; y + 1 >= i; ++i )
  {
    for ( j = x - 1; x + 1 >= j; ++j )
      TransList[dung_map[j][i]] = 0;
  }
}

//----- (0046D271) --------------------------------------------------------
void __fastcall PlrDoTrans(int x, int y)
{
  int i; // [esp+14h] [ebp-Ch]
  int j; // [esp+18h] [ebp-8h]
  char v4; // [esp+1Ch] [ebp-4h]

  if ( leveltype != 1 && leveltype != 2 )
  {
    TransList[1] = 1;
  }
  else
  {
    for ( i = y - 1; y + 1 >= i; ++i )
    {
      for ( j = x - 1; x + 1 >= j; ++j )
      {
        if ( !nSolidTable[dPiece[j][i]] )
        {
          v4 = dung_map[j][i];
          if ( v4 )
            TransList[v4] = 1;
        }
      }
    }
  }
}

//----- (0046D350) --------------------------------------------------------
void __fastcall SetPlayerOld(int pnum)
{
  plr[pnum]._poldx = plr[pnum].WorldX;
  plr[pnum]._poldy = plr[pnum].WorldY;
}

//----- (0046D3DA) --------------------------------------------------------
void __fastcall FixPlayerLocation(int pnum, int dir)
{
  plr[pnum]._px = plr[pnum].WorldX;
  plr[pnum]._py = plr[pnum].WorldY;
  plr[pnum]._ptargx = plr[pnum].WorldX;
  plr[pnum]._ptargy = plr[pnum].WorldY;
  plr[pnum]._pxoff = 0;
  plr[pnum]._pyoff = 0;
  InitPlayerLoc(pnum, 0);
  plr[pnum]._pdir = dir;
  if ( pnum == myplr )
  {
    ScrollInfo._sxoff = 0;
    ScrollInfo._syoff = 0;
    ScrollInfo._sdir = 0;
    ViewX = plr[pnum].WorldX;
    ViewY = plr[pnum].WorldY;
  }
}

//----- (0046D5B7) --------------------------------------------------------
void __fastcall StartStand(int pnum, int dir)
{
  if ( !plr[pnum]._pInvincible || plr[pnum]._pHitPoints )
  {
    if ( !(plr[pnum]._pGFXLoad & 1) )
      LoadPlrGFX(pnum, 1);
    NewPlrAnim(pnum, plr[pnum]._pNAnim[dir], plr[pnum]._pNFrames, 3, plr[pnum]._pNWidth);
    plr[pnum]._pmode = 0;
    FixPlayerLocation(pnum, dir);
    FixPlrWalkTags(pnum);
    dPlayer[plr[pnum].WorldX][plr[pnum].WorldY] = pnum + 1;
    SetPlayerOld(pnum);
  }
  else
  {
    SyncPlrKill(pnum);
  }
}

//----- (0046D74E) --------------------------------------------------------
void __fastcall StartWalkStand(int pnum)
{
  plr[pnum]._pmode = 0;
  plr[pnum]._px = plr[pnum].WorldX;
  plr[pnum]._py = plr[pnum].WorldY;
  plr[pnum]._pxoff = 0;
  plr[pnum]._pyoff = 0;
  InitPlayerLoc(pnum, 0);
  if ( myplr == pnum )
  {
    ScrollInfo._sxoff = 0;
    ScrollInfo._syoff = 0;
    ScrollInfo._sdir = 0;
    ViewX = plr[pnum].WorldX;
    ViewY = plr[pnum].WorldY;
  }
}

//----- (0046D8B6) --------------------------------------------------------
void __fastcall PM_ChangeLightOff(int pnum)
{
  int y; // [esp+10h] [ebp-24h]
  int ya; // [esp+10h] [ebp-24h]
  int x; // [esp+14h] [ebp-20h]
  int xa; // [esp+14h] [ebp-20h]
  signed int v6; // [esp+18h] [ebp-1Ch]
  signed int v7; // [esp+1Ch] [ebp-18h]
  int v8; // [esp+24h] [ebp-10h]
  int v9; // [esp+28h] [ebp-Ch]
  LightListStruct *v10; // [esp+2Ch] [ebp-8h]

  v10 = &LightList[plr[pnum]._plid];
  x = plr[pnum]._pxoff + 2 * plr[pnum]._pyoff;
  y = 2 * plr[pnum]._pyoff - plr[pnum]._pxoff;
  if ( x >= 0 )
  {
    v7 = 1;
  }
  else
  {
    v7 = -1;
    x = -x;
  }
  if ( y >= 0 )
  {
    v6 = 1;
  }
  else
  {
    v6 = -1;
    y = plr[pnum]._pxoff - 2 * plr[pnum]._pyoff;
  }
  xa = (x >> 3) * v7;
  ya = (y >> 3) * v6;
  v8 = ya + 8 * v10->_ly;
  v9 = v10->_yoff + 8 * v10->_ly;
  if ( abs(xa + 8 * v10->_lx - (v10->_xoff + 8 * v10->_lx)) >= 3 || abs(v8 - v9) >= 3 )
    ChangeLightOff(plr[pnum]._plid, xa, ya);
}

//----- (0046DA78) --------------------------------------------------------
void __fastcall PM_ChangeOffset(int pnum)
{
  int v2; // ST14_4
  int v3; // ST10_4
  int v4; // [esp+10h] [ebp-8h]
  int v5; // [esp+14h] [ebp-4h]

  ++plr[pnum]._pVar8;
  v2 = plr[pnum]._pVar6 >> 8;
  v3 = plr[pnum]._pVar7 >> 8;
  plr[pnum]._pVar6 += plr[pnum]._pxvel;
  plr[pnum]._pVar7 += plr[pnum]._pyvel;
  plr[pnum]._pxoff = plr[pnum]._pVar6 >> 8;
  plr[pnum]._pyoff = plr[pnum]._pVar7 >> 8;
  v5 = v2 - (plr[pnum]._pVar6 >> 8);
  v4 = v3 - (plr[pnum]._pVar7 >> 8);
  if ( pnum == myplr && ScrollInfo._sdir )
  {
    ScrollInfo._sxoff += v5;
    ScrollInfo._syoff += v4;
  }
  PM_ChangeLightOff(pnum);
}

//----- (0046DC66) --------------------------------------------------------
void __fastcall StartWalk(int pnum, int xvel, int yvel, int xadd, int yadd, int EndDir, int sdir)
{
  int y; // [esp+14h] [ebp-8h]
  int x; // [esp+18h] [ebp-4h]

  if ( !plr[pnum]._pInvincible || plr[pnum]._pHitPoints )
  {
    SetPlayerOld(pnum);
    x = xadd + plr[pnum].WorldX;
    y = yadd + plr[pnum].WorldY;
    if ( PlrDirOK(pnum, EndDir) )
    {
      plr[pnum]._px = x;
      plr[pnum]._py = y;
      if ( myplr == pnum )
      {
        ScrollInfo._sdx = plr[pnum].WorldX - ViewX;
        ScrollInfo._sdy = plr[pnum].WorldY - ViewY;
      }
      dPlayer[x][y] = -1 - pnum;
      plr[pnum]._pmode = 1;
      plr[pnum]._pxvel = xvel;
      plr[pnum]._pyvel = yvel;
      plr[pnum]._pxoff = 0;
      plr[pnum]._pyoff = 0;
      plr[pnum]._pVar1 = xadd;
      plr[pnum]._pVar2 = yadd;
      plr[pnum]._pVar3 = EndDir;
      if ( !(plr[pnum]._pGFXLoad & 2) )
        LoadPlrGFX(pnum, 2);
      NewPlrAnim(pnum, plr[pnum]._pWAnim[EndDir], plr[pnum]._pWFrames, 0, plr[pnum]._pWWidth);
      plr[pnum]._pdir = EndDir;
      plr[pnum]._pVar6 = 0;
      plr[pnum]._pVar7 = 0;
      plr[pnum]._pVar8 = 0;
      InitPlayerLoc(pnum, 0);
      if ( myplr == pnum )
      {
        if ( zoomflag )
        {
          if ( abs(ScrollInfo._sdx) >= 3 || abs(ScrollInfo._sdy) >= 3 )
            ScrollInfo._sdir = 0;
          else
            ScrollInfo._sdir = sdir;
        }
        else if ( abs(ScrollInfo._sdx) >= 2 || abs(ScrollInfo._sdy) >= 2 )
        {
          ScrollInfo._sdir = 0;
        }
        else
        {
          ScrollInfo._sdir = sdir;
        }
      }
    }
  }
  else
  {
    SyncPlrKill(pnum);
  }
}

//----- (0046E0D0) --------------------------------------------------------
void __fastcall StartWalk2(int pnum, int xvel, int yvel, int xoff, int yoff, int xadd, int yadd, int EndDir, int sdir)
{
  int v11; // [esp+14h] [ebp-8h]
  int v12; // [esp+18h] [ebp-4h]

  if ( !plr[pnum]._pInvincible || plr[pnum]._pHitPoints )
  {
    SetPlayerOld(pnum);
    v12 = xadd + plr[pnum].WorldX;
    v11 = yadd + plr[pnum].WorldY;
    if ( PlrDirOK(pnum, EndDir) )
    {
      plr[pnum]._px = v12;
      plr[pnum]._py = v11;
      if ( myplr == pnum )
      {
        ScrollInfo._sdx = plr[pnum].WorldX - ViewX;
        ScrollInfo._sdy = plr[pnum].WorldY - ViewY;
      }
      dPlayer[plr[pnum].WorldX][plr[pnum].WorldY] = -1 - pnum;
      plr[pnum]._pVar1 = plr[pnum].WorldX;
      plr[pnum]._pVar2 = plr[pnum].WorldY;
      plr[pnum].WorldX = v12;
      plr[pnum].WorldY = v11;
      dPlayer[plr[pnum].WorldX][plr[pnum].WorldY] = pnum + 1;
      plr[pnum]._pxoff = xoff;
      plr[pnum]._pyoff = yoff;
      ChangeLightXY(plr[pnum]._plid, plr[pnum].WorldX, plr[pnum].WorldY);
      PM_ChangeLightOff(pnum);
      plr[pnum]._pmode = 2;
      plr[pnum]._pxvel = xvel;
      plr[pnum]._pyvel = yvel;
      plr[pnum]._pVar6 = xoff << 8;
      plr[pnum]._pVar7 = yoff << 8;
      plr[pnum]._pVar3 = EndDir;
      if ( !(plr[pnum]._pGFXLoad & 2) )
        LoadPlrGFX(pnum, 2);
      NewPlrAnim(pnum, plr[pnum]._pWAnim[EndDir], plr[pnum]._pWFrames, 0, plr[pnum]._pWWidth);
      plr[pnum]._pdir = EndDir;
      plr[pnum]._pVar8 = 0;
      if ( EndDir == 7 )
        InitPlayerLoc(pnum, 1);
      else
        InitPlayerLoc(pnum, 0);
      if ( myplr == pnum )
      {
        if ( zoomflag )
        {
          if ( abs(ScrollInfo._sdx) >= 3 || abs(ScrollInfo._sdy) >= 3 )
            ScrollInfo._sdir = 0;
          else
            ScrollInfo._sdir = sdir;
        }
        else if ( abs(ScrollInfo._sdx) >= 2 || abs(ScrollInfo._sdy) >= 2 )
        {
          ScrollInfo._sdir = 0;
        }
        else
        {
          ScrollInfo._sdir = sdir;
        }
      }
    }
  }
  else
  {
    SyncPlrKill(pnum);
  }
}

//----- (0046E6B5) --------------------------------------------------------
void __fastcall StartWalk3(int pnum, int xvel, int yvel, int xoff, int yoff, int xadd, int yadd, int mapx, int mapy, int EndDir, int sdir)
{
  int x; // [esp+14h] [ebp-10h]
  int v14; // [esp+18h] [ebp-Ch]
  int v15; // [esp+1Ch] [ebp-8h]
  int y; // [esp+20h] [ebp-4h]

  if ( !plr[pnum]._pInvincible || plr[pnum]._pHitPoints )
  {
    SetPlayerOld(pnum);
    v15 = xadd + plr[pnum].WorldX;
    v14 = yadd + plr[pnum].WorldY;
    x = mapx + plr[pnum].WorldX;
    y = mapy + plr[pnum].WorldY;
    if ( PlrDirOK(pnum, EndDir) )
    {
      plr[pnum]._px = v15;
      plr[pnum]._py = v14;
      if ( myplr == pnum )
      {
        ScrollInfo._sdx = plr[pnum].WorldX - ViewX;
        ScrollInfo._sdy = plr[pnum].WorldY - ViewY;
      }
      dPlayer[plr[pnum].WorldX][plr[pnum].WorldY] = -1 - pnum;
      dPlayer[v15][v14] = -1 - pnum;
      plr[pnum]._pVar4 = x;
      plr[pnum]._pVar5 = y;
      dFlags[x][y] |= 0x20u;
      plr[pnum]._pxoff = xoff;
      plr[pnum]._pyoff = yoff;
      if ( leveltype )
      {
        ChangeLightXY(plr[pnum]._plid, x, y);
        PM_ChangeLightOff(pnum);
      }
      plr[pnum]._pmode = 3;
      plr[pnum]._pxvel = xvel;
      plr[pnum]._pyvel = yvel;
      plr[pnum]._pVar1 = v15;
      plr[pnum]._pVar2 = v14;
      plr[pnum]._pVar6 = xoff << 8;
      plr[pnum]._pVar7 = yoff << 8;
      plr[pnum]._pVar3 = EndDir;
      if ( !(plr[pnum]._pGFXLoad & 2) )
        LoadPlrGFX(pnum, 2);
      NewPlrAnim(pnum, plr[pnum]._pWAnim[EndDir], plr[pnum]._pWFrames, 0, plr[pnum]._pWWidth);
      plr[pnum]._pdir = EndDir;
      plr[pnum]._pVar8 = 0;
      InitPlayerLoc(pnum, 0);
      if ( myplr == pnum )
      {
        if ( zoomflag )
        {
          if ( abs(ScrollInfo._sdx) >= 3 || abs(ScrollInfo._sdy) >= 3 )
            ScrollInfo._sdir = 0;
          else
            ScrollInfo._sdir = sdir;
        }
        else if ( abs(ScrollInfo._sdx) >= 2 || abs(ScrollInfo._sdy) >= 2 )
        {
          ScrollInfo._sdir = 0;
        }
        else
        {
          ScrollInfo._sdir = sdir;
        }
      }
    }
  }
  else
  {
    SyncPlrKill(pnum);
  }
}

//----- (0046EC6E) --------------------------------------------------------
void __fastcall StartAttack(int pnum, int d)
{
  if ( !plr[pnum]._pInvincible || plr[pnum]._pHitPoints )
  {
    if ( !(plr[pnum]._pGFXLoad & 4) )
      LoadPlrGFX(pnum, 4);
    NewPlrAnim(pnum, plr[pnum]._pAAnim[d], plr[pnum]._pAFrames, 0, plr[pnum]._pAWidth);
    plr[pnum]._pmode = 4;
    FixPlayerLocation(pnum, d);
    SetPlayerOld(pnum);
  }
  else
  {
    SyncPlrKill(pnum);
  }
}

//----- (0046EDAD) --------------------------------------------------------
void __fastcall StartRangeAttack(int pnum, int d, int cx, int cy)
{
  if ( !plr[pnum]._pInvincible || plr[pnum]._pHitPoints )
  {
    if ( !(plr[pnum]._pGFXLoad & 4) )
      LoadPlrGFX(pnum, 4);
    NewPlrAnim(pnum, plr[pnum]._pAAnim[d], plr[pnum]._pAFrames, 0, plr[pnum]._pAWidth);
    plr[pnum]._pmode = 5;
    FixPlayerLocation(pnum, d);
    SetPlayerOld(pnum);
    plr[pnum]._pVar1 = cx;
    plr[pnum]._pVar2 = cy;
  }
  else
  {
    SyncPlrKill(pnum);
  }
}

//----- (0046EF2E) --------------------------------------------------------
void __fastcall StartPlrBlock(int pnum, int dir)
{
  if ( !plr[pnum]._pInvincible || plr[pnum]._pHitPoints )
  {
    PlaySfxLoc(34, plr[pnum].WorldX, plr[pnum].WorldY);
    if ( !(plr[pnum]._pGFXLoad & 0x100) )
      LoadPlrGFX(pnum, 256);
    NewPlrAnim(pnum, plr[pnum]._pBAnim[dir], plr[pnum]._pBFrames, 2, plr[pnum]._pBWidth);
    plr[pnum]._pmode = 6;
    FixPlayerLocation(pnum, dir);
    SetPlayerOld(pnum);
  }
  else
  {
    SyncPlrKill(pnum);
  }
}

//----- (0046F0B2) --------------------------------------------------------
void __fastcall StartSpell(int pnum, int d, int cx, int cy)
{
  int v4; // [esp+Ch] [ebp-Ch]

  if ( !plr[pnum]._pInvincible || plr[pnum]._pHitPoints )
  {
    v4 = spelldata[plr[pnum]._pSpell].sType;
    if ( spelldata[plr[pnum]._pSpell].sType )
    {
      if ( v4 == 1 )
      {
        if ( !(plr[pnum]._pGFXLoad & 0x10) )
          LoadPlrGFX(pnum, 16);
        NewPlrAnim(pnum, plr[pnum]._pLAnim[d], plr[pnum]._pSFrames, 0, plr[pnum]._pSWidth);
      }
      else if ( v4 == 2 )
      {
        if ( !(plr[pnum]._pGFXLoad & 0x40) )
          LoadPlrGFX(pnum, 64);
        NewPlrAnim(pnum, plr[pnum]._pTAnim[d], plr[pnum]._pSFrames, 0, plr[pnum]._pSWidth);
      }
    }
    else
    {
      if ( !(plr[pnum]._pGFXLoad & 0x20) )
        LoadPlrGFX(pnum, 32);
      NewPlrAnim(pnum, plr[pnum]._pFAnim[d], plr[pnum]._pSFrames, 0, plr[pnum]._pSWidth);
    }
    PlaySfxLoc((unsigned __int8)spelldata[plr[pnum]._pSpell]._sSFX, plr[pnum].WorldX, plr[pnum].WorldY);
    plr[pnum]._pmode = 9;
    FixPlayerLocation(pnum, d);
    SetPlayerOld(pnum);
    plr[pnum]._pVar1 = cx;
    plr[pnum]._pVar2 = cy;
    plr[pnum]._pVar8 = 0;
  }
  else
  {
    SyncPlrKill(pnum);
  }
}

//----- (0046F45B) --------------------------------------------------------
void __fastcall FixPlrWalkTags(int pnum)
{
  int j; // [esp+10h] [ebp-18h]
  int ox; // [esp+14h] [ebp-14h]
  int i; // [esp+18h] [ebp-10h]
  int oy; // [esp+24h] [ebp-4h]

  ox = plr[pnum]._poldx;
  oy = plr[pnum]._poldy;
  for ( i = oy - 1; oy + 1 >= i; ++i )
  {
    for ( j = ox - 1; ox + 1 >= j; ++j )
    {
      if ( j >= 0 && j < 112 && i >= 0 && i < 112 && (dPlayer[j][i] == pnum + 1 || dPlayer[j][i] == -1 - pnum) )
        dPlayer[j][i] = 0;
    }
  }
  if ( ox >= 0 && ox < 111 && oy >= 0 && oy < 111 )
  {
    dFlags[ox + 1][oy] &= 0xDFu;
    dFlags[ox][oy + 1] &= 0xDFu;
  }
}

//----- (0046F627) --------------------------------------------------------
void __fastcall StartPlrHit(int pnum, int dam)
{
  int dir; // [esp+14h] [ebp-4h]

  if ( !plr[pnum]._pInvincible || plr[pnum]._pHitPoints )
  {
    PlaySfxLoc(48, plr[pnum].WorldX, plr[pnum].WorldY);
    drawhpflag = 1;
    if ( plr[pnum]._pLevel <= dam >> 6 )
    {
      dir = plr[pnum]._pdir;
      if ( !(plr[pnum]._pGFXLoad & 8) )
        LoadPlrGFX(pnum, 8);
      NewPlrAnim(pnum, plr[pnum]._pHAnim[dir], plr[pnum]._pHFrames, 0, plr[pnum]._pHWidth);
      plr[pnum]._pmode = 7;
      FixPlayerLocation(pnum, dir);
      plr[pnum]._pVar8 = 1;
      FixPlrWalkTags(pnum);
      dPlayer[plr[pnum].WorldX][plr[pnum].WorldY] = pnum + 1;
      SetPlayerOld(pnum);
    }
  }
  else
  {
    SyncPlrKill(pnum);
  }
}

//----- (0046F87F) --------------------------------------------------------
void __fastcall RespawnDeadItem(ItemStruct *itm, int x, int y)
{
  int i; // ST14_4

  if ( numitems < 127 )
  {
    i = itemavail[0];
    dItem[x][y] = LOBYTE(itemavail[0]) + 1;
    itemavail[0] = itemavail[127 - numitems - 1];
    itemactive[numitems] = i;
    qmemcpy(&item[i], itm, sizeof(ItemStruct));
    item[i]._ix = x;
    item[i]._iy = y;
    RespawnItem(i, 1);
    ++numitems;
    itm->_itype = -1;
  }
}

//----- (0046F95A) --------------------------------------------------------
void __fastcall StartPlayerKill(int pnum)
{
  signed int v1; // ST20_4
  signed int v2; // ST1C_4
  int v3; // ST24_4
  signed int v5; // [esp+1Ch] [ebp-Ch]
  signed int v6; // [esp+1Ch] [ebp-Ch]
  ItemStruct *itm; // [esp+20h] [ebp-8h]
  ItemStruct *itma; // [esp+20h] [ebp-8h]
  PlayerStruct *v9; // [esp+24h] [ebp-4h]

  v9 = &plr[pnum];
  PlaySfxLoc(45, plr[pnum].WorldX, plr[pnum].WorldY);
  if ( v9->_pgfxnum )
  {
    v9->_pgfxnum = 0;
    v9->_pGFXLoad = 0;
    SetPlrAnims(pnum);
  }
  if ( SLOBYTE(v9->_pGFXLoad) >= 0 )
    LoadPlrGFX(pnum, 128);
  NewPlrAnim(pnum, v9->_pDAnim[v9->_pdir], v9->_pDFrames, 1, v9->_pDWidth);
  v9->_pmode = 8;
  v9->_pBlockFlag = 0;
  v9->_pInvincible = 1;
  SetPlayerHitPoints(pnum, 0);
  v9->_pVar8 = 1;
  if ( myplr != pnum )
  {
    itm = v9->InvBody;
    v5 = 7;
    while ( 1 )
    {
      v1 = v5--;
      if ( !v1 )
        break;
      itm->_itype = -1;
      ++itm;
    }
    CalcPlrInv(pnum, 0);
  }
  if ( plr[pnum].plrlevel == currlevel )
  {
    FixPlayerLocation(pnum, v9->_pdir);
    FixPlrWalkTags(pnum);
    dPlayer[v9->WorldX][v9->WorldY] = pnum + 1;
    SetPlayerOld(pnum);
    if ( myplr == pnum )
    {
      itma = v9->InvBody;
      v6 = 7;
      while ( 1 )
      {
        v2 = v6--;
        if ( !v2 )
          break;
        v3 = ((_BYTE)v6 + (unsigned __int8)v9->_pdir) & 7;
        PlrDeadItem(pnum, itma, offset_x[v3], offset_y[v3]);
        ++itma;
      }
      DropHalfPlayersGold(pnum);
      CalcPlrInv(pnum, 0);
      drawhpflag = 1;
      deathdelay = 30;
    }
  }
}

//----- (0046FBBB) --------------------------------------------------------
void __fastcall PlrDeadItem(int pnum, struct ItemStruct *itm, int xx, int yy)
{
  int m; // [esp+14h] [ebp-14h]
  int l; // [esp+18h] [ebp-10h]
  signed int k; // [esp+1Ch] [ebp-Ch]
  int j; // [esp+20h] [ebp-8h]
  int ja; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]
  int ia; // [esp+24h] [ebp-4h]

  if ( itm->_itype != -1 )
  {
    i = xx + plr[pnum].WorldX;
    j = yy + plr[pnum].WorldY;
    if ( ItemSpaceOk(xx + plr[pnum].WorldX, yy + plr[pnum].WorldY) )
    {
      RespawnDeadItem(itm, i, j);
      qmemcpy(&plr[pnum].HoldItem, itm, sizeof(plr[pnum].HoldItem));
      NetSendCmdPItem(0, 0xDu, i, j);
    }
    else
    {
      for ( k = 1; k < 50; ++k )
      {
        for ( l = -k; k >= l; ++l )
        {
          ja = l + plr[pnum].WorldY;
          for ( m = -k; k >= m; ++m )
          {
            ia = m + plr[pnum].WorldX;
            if ( ItemSpaceOk(m + plr[pnum].WorldX, ja) )
            {
              RespawnDeadItem(itm, ia, ja);
              qmemcpy(&plr[pnum].HoldItem, itm, sizeof(plr[pnum].HoldItem));
              NetSendCmdPItem(0, 0xDu, ia, ja);
              return;
            }
          }
        }
      }
    }
  }
}

//----- (0046FD9D) --------------------------------------------------------
void __fastcall DropHalfPlayersGold(int pnum)
{
  int i; // [esp+10h] [ebp-8h]
  int ia; // [esp+10h] [ebp-8h]
  int ib; // [esp+10h] [ebp-8h]
  int ic; // [esp+10h] [ebp-8h]
  int v6; // [esp+14h] [ebp-4h]

  v6 = plr[pnum]._pGold >> 1;
  for ( i = 0; i < 8 && v6 > 0; ++i )
  {
    if ( plr[pnum].SpdList[i]._itype == 11 && plr[pnum].SpdList[i]._ivalue != 5000 )
    {
      if ( plr[pnum].SpdList[i]._ivalue <= v6 )
      {
        v6 -= plr[pnum].SpdList[i]._ivalue;
        RemoveSpdBarItem(pnum, i);
        SetPlrHandItem(&plr[pnum].HoldItem, 0);
        GetPlrHandSeed(&plr[pnum].HoldItem);
        plr[pnum].HoldItem._ivalue = plr[pnum].SpdList[i]._ivalue;
        PlrDeadItem(pnum, &plr[pnum].HoldItem, plr[pnum].WorldX, plr[pnum].WorldY);
        i = -1;
      }
      else
      {
        plr[pnum].SpdList[i]._ivalue -= v6;
        SetSpdbarGoldCurs(pnum, i);
        SetPlrHandItem(&plr[pnum].HoldItem, 0);
        GetPlrHandSeed(&plr[pnum].HoldItem);
        plr[pnum].HoldItem._ivalue = v6;
        PlrDeadItem(pnum, &plr[pnum].HoldItem, plr[pnum].WorldX, plr[pnum].WorldY);
        v6 = 0;
      }
    }
  }
  if ( v6 > 0 )
  {
    for ( ia = 0; ia < 8 && v6 > 0; ++ia )
    {
      if ( plr[pnum].SpdList[ia]._itype == 11 )
      {
        if ( plr[pnum].SpdList[ia]._ivalue <= v6 )
        {
          v6 -= plr[pnum].SpdList[ia]._ivalue;
          RemoveSpdBarItem(pnum, ia);
          SetPlrHandItem(&plr[pnum].HoldItem, 0);
          GetPlrHandSeed(&plr[pnum].HoldItem);
          plr[pnum].HoldItem._ivalue = plr[pnum].SpdList[ia]._ivalue;
          PlrDeadItem(pnum, &plr[pnum].HoldItem, plr[pnum].WorldX, plr[pnum].WorldY);
          ia = -1;
        }
        else
        {
          plr[pnum].SpdList[ia]._ivalue -= v6;
          SetSpdbarGoldCurs(pnum, ia);
          SetPlrHandItem(&plr[pnum].HoldItem, 0);
          GetPlrHandSeed(&plr[pnum].HoldItem);
          plr[pnum].HoldItem._ivalue = v6;
          PlrDeadItem(pnum, &plr[pnum].HoldItem, plr[pnum].WorldX, plr[pnum].WorldY);
          v6 = 0;
        }
      }
    }
  }
  drawpanflag = 255;
  if ( v6 > 0 )
  {
    for ( ib = 0; plr[pnum]._pNumInv > ib && v6 > 0; ++ib )
    {
      if ( plr[pnum].InvList[ib]._itype == 11 && plr[pnum].InvList[ib]._ivalue != 5000 )
      {
        if ( plr[pnum].InvList[ib]._ivalue <= v6 )
        {
          v6 -= plr[pnum].InvList[ib]._ivalue;
          RemoveInvItem(pnum, ib);
          SetPlrHandItem(&plr[pnum].HoldItem, 0);
          GetPlrHandSeed(&plr[pnum].HoldItem);
          plr[pnum].HoldItem._ivalue = plr[pnum].InvList[ib]._ivalue;
          PlrDeadItem(pnum, &plr[pnum].HoldItem, plr[pnum].WorldX, plr[pnum].WorldY);
          ib = -1;
        }
        else
        {
          plr[pnum].InvList[ib]._ivalue -= v6;
          SetGoldCurs(pnum, ib);
          SetPlrHandItem(&plr[pnum].HoldItem, 0);
          GetPlrHandSeed(&plr[pnum].HoldItem);
          plr[pnum].HoldItem._ivalue = v6;
          PlrDeadItem(pnum, &plr[pnum].HoldItem, plr[pnum].WorldX, plr[pnum].WorldY);
          v6 = 0;
        }
      }
    }
    if ( v6 > 0 )
    {
      for ( ic = 0; plr[pnum]._pNumInv > ic && v6 > 0; ++ic )
      {
        if ( plr[pnum].InvList[ic]._itype == 11 )
        {
          if ( plr[pnum].InvList[ic]._ivalue <= v6 )
          {
            v6 -= plr[pnum].InvList[ic]._ivalue;
            RemoveInvItem(pnum, ic);
            SetPlrHandItem(&plr[pnum].HoldItem, 0);
            GetPlrHandSeed(&plr[pnum].HoldItem);
            plr[pnum].HoldItem._ivalue = plr[pnum].InvList[ic]._ivalue;
            PlrDeadItem(pnum, &plr[pnum].HoldItem, plr[pnum].WorldX, plr[pnum].WorldY);
            ic = -1;
          }
          else
          {
            plr[pnum].InvList[ic]._ivalue -= v6;
            SetGoldCurs(pnum, ic);
            SetPlrHandItem(&plr[pnum].HoldItem, 0);
            GetPlrHandSeed(&plr[pnum].HoldItem);
            plr[pnum].HoldItem._ivalue = v6;
            PlrDeadItem(pnum, &plr[pnum].HoldItem, plr[pnum].WorldX, plr[pnum].WorldY);
            v6 = 0;
          }
        }
      }
    }
  }
  plr[pnum]._pGold = CalculateGold(pnum);
}

//----- (00470A34) --------------------------------------------------------
void __fastcall SyncPlrKill(int pnum)
{
  if ( myplr == pnum )
    NetSendCmd(1u, 0x29u);
  StartPlayerKill(pnum);
}

//----- (00470A70) --------------------------------------------------------
void __fastcall RemovePlrMissiles(int pnum)
{
  StartPlayerKill(pnum);
}

//----- (00470A8E) --------------------------------------------------------
void __fastcall InitLevelChange(int pnum)
{
  FixPlrWalkTags(pnum);
  SetPlayerOld(pnum);
  FixPlrWalkTags(pnum);
  if ( pnum == myplr )
    dPlayer[plr[myplr].WorldX][plr[myplr].WorldY] = myplr + 1;
  else
    plr[pnum]._pLvlVisited[plr[pnum].plrlevel] = 1;
  plr[pnum]._pLvlChanging = 1;
}

//----- (00470B7F) --------------------------------------------------------
void __fastcall StartNewLvl(int pnum, int fom, int lvl)
{
  InitLevelChange(pnum);
  switch ( fom )
  {
    case 1026:
    case 1027:
    case 1031:
    case 1032:
      assert(plr[pnum].plrlevel != lvl, "PLAYER.CPP", 1840);
      plr[pnum].plrlevel = lvl;
      break;
    case 1028:
      assert(gbMaxPlayers == 1, "PLAYER.CPP", 1851);
      return;
    case 1029:
      setlvlnum = lvl;
      assert(gbMaxPlayers == 1, "PLAYER.CPP", 1856);
      return;
    case 1033:
      break;
    default:
      TermMsg("StartNewLvl");
      return;
  }
  if ( myplr == pnum )
  {
    plr[pnum]._pmode = 10;
    plr[pnum]._pInvincible = 1;
    PostMessageA(ghMainWnd, fom, 0, 0);
    if ( (signed int)gbMaxPlayers > 1 )
      NetSendCmdParam2(1u, 0x20u, fom, lvl);
  }
}

//----- (00470D46) --------------------------------------------------------
void __fastcall RestartTownLvl(int pnum)
{
  InitLevelChange(pnum);
  assert(plr[pnum].plrlevel, "PLAYER.CPP", 1878);
  plr[pnum].plrlevel = 0;
  plr[pnum]._pInvincible = 0;
  SetPlayerHitPoints(pnum, 64);
  plr[pnum]._pMana = 0;
  plr[pnum]._pManaBase = plr[pnum]._pMana - (plr[pnum]._pMaxMana - plr[pnum]._pMaxManaBase);
  CalcPlrInv(pnum, 0);
  if ( myplr == pnum )
  {
    plr[pnum]._pmode = 10;
    plr[pnum]._pInvincible = 1;
    PostMessageA(ghMainWnd, 0x409u, 0, 0);
  }
}

//----- (00470EEC) --------------------------------------------------------
void __fastcall StartWarpLvl(int pnum, int pidx)
{
  InitLevelChange(pnum);
  if ( pnum == myplr )
  {
    SetCurrentPortal(pidx);
    plr[pnum]._pmode = 10;
    plr[pnum]._pInvincible = 1;
    PostMessageA(ghMainWnd, 0x406u, 0, 0);
  }
}

//----- (00470F77) --------------------------------------------------------
int __fastcall PM_DoStand()
{
  return 0;
}

//----- (00470F8F) --------------------------------------------------------
int __fastcall PM_DoWalk(int pnum)
{
  int v3; // [esp+10h] [ebp-8h]
  int v4; // [esp+14h] [ebp-4h]

  if ( plr[pnum]._pAnimFrame == 2
    || plr[pnum]._pWFrames == 8 && plr[pnum]._pAnimFrame == 6
    || plr[pnum]._pWFrames != 8 && plr[pnum]._pAnimFrame == 4 )
  {
    PlaySfxLoc(52, plr[pnum].WorldX, plr[pnum].WorldY);
  }
  v3 = 8;
  if ( currlevel )
    v3 = PWVel[3][plr[pnum]._pClass + 1];
  if ( plr[pnum]._pVar8 == v3 )
  {
    dPlayer[plr[pnum].WorldX][plr[pnum].WorldY] = 0;
    plr[pnum].WorldX += plr[pnum]._pVar1;
    plr[pnum].WorldY += plr[pnum]._pVar2;
    dPlayer[plr[pnum].WorldX][plr[pnum].WorldY] = pnum + 1;
    if ( leveltype )
    {
      ChangeLightXY(plr[pnum]._plid, plr[pnum].WorldX, plr[pnum].WorldY);
      ChangeVisionXY(plr[pnum]._pvid, plr[pnum].WorldX, plr[pnum].WorldY);
    }
    if ( myplr == pnum && ScrollInfo._sdir )
    {
      ViewX = plr[pnum].WorldX - ScrollInfo._sdx;
      ViewY = plr[pnum].WorldY - ScrollInfo._sdy;
    }
    if ( plr[pnum].walkpath[0] == -1 )
      StartStand(pnum, plr[pnum]._pVar3);
    else
      StartWalkStand(pnum);
    ClearPlrPVars(pnum);
    if ( leveltype )
      ChangeLightOff(plr[pnum]._plid, 0, 0);
    v4 = 1;
  }
  else
  {
    PM_ChangeOffset(pnum);
    v4 = 0;
  }
  return v4;
}

//----- (004713FB) --------------------------------------------------------
int __fastcall PM_DoWalk2(int pnum)
{
  int v3; // [esp+10h] [ebp-8h]
  int v4; // [esp+14h] [ebp-4h]

  if ( plr[pnum]._pAnimFrame == 2
    || plr[pnum]._pWFrames == 8 && plr[pnum]._pAnimFrame == 6
    || plr[pnum]._pWFrames != 8 && plr[pnum]._pAnimFrame == 4 )
  {
    PlaySfxLoc(52, plr[pnum].WorldX, plr[pnum].WorldY);
  }
  v3 = 8;
  if ( currlevel )
    v3 = PWVel[3][plr[pnum]._pClass + 1];
  if ( plr[pnum]._pVar8 == v3 )
  {
    dPlayer[plr[pnum]._pVar1][plr[pnum]._pVar2] = 0;
    if ( leveltype )
    {
      ChangeLightXY(plr[pnum]._plid, plr[pnum].WorldX, plr[pnum].WorldY);
      ChangeVisionXY(plr[pnum]._pvid, plr[pnum].WorldX, plr[pnum].WorldY);
    }
    if ( myplr == pnum && ScrollInfo._sdir )
    {
      ViewX = plr[pnum].WorldX - ScrollInfo._sdx;
      ViewY = plr[pnum].WorldY - ScrollInfo._sdy;
    }
    if ( plr[pnum].walkpath[0] == -1 )
      StartStand(pnum, plr[pnum]._pVar3);
    else
      StartWalkStand(pnum);
    ClearPlrPVars(pnum);
    if ( leveltype )
      ChangeLightOff(plr[pnum]._plid, 0, 0);
    v4 = 1;
  }
  else
  {
    PM_ChangeOffset(pnum);
    v4 = 0;
  }
  return v4;
}

//----- (004717A3) --------------------------------------------------------
int __fastcall PM_DoWalk3(int pnum)
{
  int v3; // [esp+10h] [ebp-8h]
  int v4; // [esp+14h] [ebp-4h]

  if ( plr[pnum]._pAnimFrame == 2
    || plr[pnum]._pWFrames == 8 && plr[pnum]._pAnimFrame == 6
    || plr[pnum]._pWFrames != 8 && plr[pnum]._pAnimFrame == 4 )
  {
    PlaySfxLoc(52, plr[pnum].WorldX, plr[pnum].WorldY);
  }
  v3 = 8;
  if ( currlevel )
    v3 = PWVel[3][plr[pnum]._pClass + 1];
  if ( plr[pnum]._pVar8 == v3 )
  {
    dPlayer[plr[pnum].WorldX][plr[pnum].WorldY] = 0;
    dFlags[plr[pnum]._pVar4][plr[pnum]._pVar5] &= 0xDFu;
    plr[pnum].WorldX = plr[pnum]._pVar1;
    plr[pnum].WorldY = plr[pnum]._pVar2;
    dPlayer[plr[pnum].WorldX][plr[pnum].WorldY] = pnum + 1;
    if ( leveltype )
    {
      ChangeLightXY(plr[pnum]._plid, plr[pnum].WorldX, plr[pnum].WorldY);
      ChangeVisionXY(plr[pnum]._pvid, plr[pnum].WorldX, plr[pnum].WorldY);
    }
    if ( myplr == pnum && ScrollInfo._sdir )
    {
      ViewX = plr[pnum].WorldX - ScrollInfo._sdx;
      ViewY = plr[pnum].WorldY - ScrollInfo._sdy;
    }
    if ( plr[pnum].walkpath[0] == -1 )
      StartStand(pnum, plr[pnum]._pVar3);
    else
      StartWalkStand(pnum);
    ClearPlrPVars(pnum);
    if ( leveltype )
      ChangeLightOff(plr[pnum]._plid, 0, 0);
    v4 = 1;
  }
  else
  {
    PM_ChangeOffset(pnum);
    v4 = 0;
  }
  return v4;
}

//----- (00471CA8) --------------------------------------------------------
void __fastcall WeaponDur(int pnum, int durrnd)
{
  if ( myplr == pnum && !random(3, durrnd) )
  {
    if ( plr[pnum].InvBody[4]._itype != -1 && plr[pnum].InvBody[4]._iClass == 1 )
    {
      if ( plr[pnum].InvBody[4]._iDurability == 1000 )
        return;
      if ( !--plr[pnum].InvBody[4]._iDurability )
      {
        plr[pnum].InvBody[4]._itype = -1;
        CalcPlrInv(pnum, 1);
      }
    }
    if ( plr[pnum].InvBody[5]._itype != -1 && plr[pnum].InvBody[5]._iClass == 1 )
    {
      if ( plr[pnum].InvBody[5]._iDurability == 1000 )
        return;
      if ( !--plr[pnum].InvBody[5]._iDurability )
      {
        plr[pnum].InvBody[5]._itype = -1;
        CalcPlrInv(pnum, 1);
      }
    }
    if ( plr[pnum].InvBody[4]._itype == -1 && plr[pnum].InvBody[5]._itype == 5 )
    {
      if ( plr[pnum].InvBody[5]._iDurability == 1000 )
        return;
      if ( !--plr[pnum].InvBody[5]._iDurability )
      {
        plr[pnum].InvBody[5]._itype = -1;
        CalcPlrInv(pnum, 1);
      }
    }
    if ( plr[pnum].InvBody[5]._itype == -1
      && plr[pnum].InvBody[4]._itype == 5
      && plr[pnum].InvBody[4]._iDurability != 1000
      && !--plr[pnum].InvBody[4]._iDurability )
    {
      plr[pnum].InvBody[4]._itype = -1;
      CalcPlrInv(pnum, 1);
    }
  }
}

//----- (0047207C) --------------------------------------------------------
BOOL __fastcall PlrHitMonst(int pnum, int m)
{
  BOOL result; // eax
  int v3; // ST3C_4
  int v4; // eax
  int v5; // ST38_4
  int v8; // [esp+18h] [ebp-2Ch]
  int dam; // [esp+20h] [ebp-24h]
  int dama; // [esp+20h] [ebp-24h]
  signed int v11; // [esp+24h] [ebp-20h]
  int v12; // [esp+28h] [ebp-1Ch]
  int v13; // [esp+28h] [ebp-1Ch]
  BOOL v14; // [esp+34h] [ebp-10h]
  int v15; // [esp+3Ch] [ebp-8h]

  v14 = 0;
  if ( (signed int)(monster[m]._mhitpoints & 0xFFFFFFC0) <= 0 )
    return 0;
  if ( monster[m].MType->mtype == 32 && monster[m]._mgoal == 2 )
    return 0;
  v15 = random(4, 100);
  if ( monster[m]._mmode == 15 )
    v15 = 0;
  v12 = (plr[pnum]._pDexterity >> 2) + plr[pnum]._pLevel + 50 - (monster[m].mArmorClass - plr[pnum]._pIEnAc);
  if ( !plr[pnum]._pClass )
    v12 += 20;
  v13 = plr[pnum]._pIBonusToHit + v12;
  if ( v13 < 5 )
    v13 = 5;
  if ( v13 > 95 )
    v13 = 95;
  if ( monster[m]._mFlags & 4 )
  {
    monster[m]._mFlags &= 0xFFFFFFFB;
    monster[m]._mmode = 7;
    result = 1;
  }
  else
  {
    if ( v13 > v15 )
    {
      v3 = plr[pnum]._pIMinDam;
      v4 = random(5, plr[pnum]._pIMaxDam - v3 + 1);
      dam = plr[pnum]._pDamageMod + plr[pnum]._pIBonusDamMod + (v4 + v3) * plr[pnum]._pIBonusDam / 100 + v4 + v3;
      if ( !plr[pnum]._pClass )
      {
        v5 = (plr[pnum]._pDexterity + plr[pnum]._pLevel) >> 3;
        if ( v5 > random(6, 100) )
          dam *= 2;
      }
      v11 = -1;
      if ( plr[pnum].InvBody[4]._itype == 1 || plr[pnum].InvBody[5]._itype == 1 )
        v11 = 1;
      if ( plr[pnum].InvBody[4]._itype == 4 || plr[pnum].InvBody[5]._itype == 4 )
        v11 = 4;
      if ( monster[m].MData->mMonstClass )
      {
        if ( monster[m].MData->mMonstClass == 2 )
        {
          if ( v11 == 4 )
            dam -= dam >> 1;
          if ( v11 == 1 )
            dam += dam >> 1;
        }
      }
      else
      {
        if ( v11 == 1 )
          dam -= dam >> 1;
        if ( v11 == 4 )
          dam += dam >> 1;
      }
      if ( plr[pnum]._pIFlags & 0x40000000 && monster[m].MData->mMonstClass == 1 )
        dam *= 3;
      dama = dam << 6;
      if ( myplr == pnum )
        monster[m]._mhitpoints -= dama;
      if ( plr[pnum]._pIFlags & 2 )
      {
        v8 = random(7, dama >> 2);
        plr[pnum]._pHitPoints += v8;
        if ( plr[pnum]._pHitPoints > plr[pnum]._pMaxHP )
          plr[pnum]._pHitPoints = plr[pnum]._pMaxHP;
        plr[pnum]._pHPBase += v8;
        if ( plr[pnum]._pMaxHPBase < plr[pnum]._pHPBase )
          plr[pnum]._pHPBase = plr[pnum]._pMaxHPBase;
        drawhpflag = 1;
      }
      if ( plr[pnum]._pIFlags & 0x6000 && !(plr[pnum]._pIFlags & 0x8000000) )
      {
        if ( plr[pnum]._pIFlags & 0x2000 )
          v8 = dama / 10;
        if ( plr[pnum]._pIFlags & 0x4000 )
          v8 = dama / 5;
        plr[pnum]._pMana += v8;
        if ( plr[pnum]._pMana > plr[pnum]._pMaxMana )
          plr[pnum]._pMana = plr[pnum]._pMaxMana;
        plr[pnum]._pManaBase += v8;
        if ( plr[pnum]._pManaBase > plr[pnum]._pMaxManaBase )
          plr[pnum]._pManaBase = plr[pnum]._pMaxManaBase;
        drawmanaflag = 1;
      }
      if ( plr[pnum]._pIFlags & 0x18000 )
      {
        if ( (plr[pnum]._pIFlags & 0x8000) != 0 )
          v8 = dama / 10;
        if ( plr[pnum]._pIFlags & 0x10000 )
          v8 = dama / 5;
        plr[pnum]._pHitPoints += v8;
        if ( plr[pnum]._pHitPoints > plr[pnum]._pMaxHP )
          plr[pnum]._pHitPoints = plr[pnum]._pMaxHP;
        plr[pnum]._pHPBase += v8;
        if ( plr[pnum]._pMaxHPBase < plr[pnum]._pHPBase )
          plr[pnum]._pHPBase = plr[pnum]._pMaxHPBase;
        drawhpflag = 1;
      }
      if ( plr[pnum]._pIFlags & 0x100 )
        monster[m]._mFlags |= 8u;
      if ( myplr == pnum && monster[m]._mmode == 15 )
        monster[m]._mhitpoints = 0;
      if ( (signed int)(monster[m]._mhitpoints & 0xFFFFFFC0) > 0 )
      {
        M_StartHit(m, pnum, dama);
        missiles_43AFC2(monster[m]._mx, monster[m]._my, 18, dama >> 6, monster[m]._mmaxhp >> 6);
      }
      else if ( monster[m]._mmode == 15 )
      {
        M_StartKill(m, pnum);
        monster[m]._mmode = 15;
      }
      else
      {
        M_StartKill(m, pnum);
      }
      v14 = 1;
    }
    result = v14;
  }
  return result;
}

//----- (00472C1B) --------------------------------------------------------
BOOL __fastcall PlrHitPlr(int pnum, char p)
{
  int dir; // ST20_4
  int v4; // ST3C_4
  int v5; // eax
  int v6; // ST34_4
  int v9; // [esp+14h] [ebp-34h]
  int dwDam; // [esp+20h] [ebp-28h]
  signed int dwDama; // [esp+20h] [ebp-28h]
  int v12; // [esp+24h] [ebp-24h]
  int v13; // [esp+28h] [ebp-20h]
  int v14; // [esp+28h] [ebp-20h]
  BOOL v15; // [esp+38h] [ebp-10h]
  int v16; // [esp+40h] [ebp-8h]
  int v17; // [esp+44h] [ebp-4h]

  v15 = 0;
  if ( plr[p]._pInvincible )
    return 0;
  if ( plr[pnum]._pSpellFlags & 1 )
    return 0;
  v17 = random(4, 100);
  v13 = (plr[pnum]._pDexterity >> 2) + plr[pnum]._pLevel + 50 - (plr[p]._pIAC + plr[p]._pIBonusAC + plr[p]._pArmorClass);
  if ( !plr[pnum]._pClass )
    v13 += 20;
  v14 = plr[pnum]._pIBonusToHit + v13;
  if ( v14 < 5 )
    v14 = 5;
  if ( v14 > 95 )
    v14 = 95;
  if ( plr[p]._pmode && plr[p]._pmode != 4 || !plr[p]._pBlockFlag )
    v16 = 100;
  else
    v16 = random(5, 100);
  v12 = plr[p]._pBaseToBlk + plr[p]._pDexterity - 2 * (plr[pnum]._pLevel - plr[p]._pLevel);
  if ( v12 < 0 )
    v12 = 0;
  if ( v12 > 100 )
    v12 = 100;
  if ( v14 > v17 )
  {
    if ( v12 <= v16 )
    {
      v4 = plr[pnum]._pIMinDam;
      v5 = random(5, plr[pnum]._pIMaxDam - v4 + 1);
      dwDam = plr[pnum]._pDamageMod + plr[pnum]._pIBonusDamMod + (v5 + v4) * plr[pnum]._pIBonusDam / 100 + v5 + v4;
      if ( !plr[pnum]._pClass )
      {
        v6 = (plr[pnum]._pDexterity + plr[pnum]._pLevel) >> 3;
        if ( v6 > random(6, 100) )
          dwDam *= 2;
      }
      dwDama = dwDam << 6;
      if ( plr[pnum]._pIFlags & 2 )
      {
        v9 = random(7, dwDama >> 2);
        plr[pnum]._pHitPoints += v9;
        if ( plr[pnum]._pHitPoints > plr[pnum]._pMaxHP )
          plr[pnum]._pHitPoints = plr[pnum]._pMaxHP;
        plr[pnum]._pHPBase += v9;
        if ( plr[pnum]._pMaxHPBase < plr[pnum]._pHPBase )
          plr[pnum]._pHPBase = plr[pnum]._pMaxHPBase;
        drawhpflag = 1;
      }
      if ( pnum == myplr )
        NetSendCmdDamage(1u, p, dwDama);
      StartPlrHit(p, dwDama);
    }
    else
    {
      dir = GetDirection(plr[p].WorldX, plr[p].WorldY, plr[pnum].WorldX, plr[pnum].WorldY);
      StartPlrBlock(p, dir);
    }
    v15 = 1;
  }
  return v15;
}

//----- (00473297) --------------------------------------------------------
BOOL __fastcall PlrHitObj(int pnum, int mx, int my)
{
  int oi; // [esp+14h] [ebp-4h]

  if ( dObject[mx][my] <= 0 )
    oi = -(dObject[mx][my] + 1);
  else
    oi = dObject[mx][my] - 1;
  if ( object[oi]._oBreak != 1 )
    return 0;
  BreakObject(pnum, oi);
  return 1;
}

//----- (00473347) --------------------------------------------------------
int __fastcall PM_DoAttack(int pnum)
{
  int v1; // eax
  int v2; // eax
  int v3; // ST38_4
  int sy; // [esp+10h] [ebp-18h]
  int sx; // [esp+14h] [ebp-14h]
  int v8; // [esp+20h] [ebp-8h]

  v8 = plr[pnum]._pAnimFrame;
  if ( plr[pnum]._pIFlags & 0x20000 && v8 == 1 )
    ++plr[pnum]._pAnimFrame;
  if ( plr[pnum]._pIFlags & 0x40000 && (v8 == 1 || v8 == 3) )
    ++plr[pnum]._pAnimFrame;
  if ( plr[pnum]._pIFlags & 0x80000 && (v8 == 1 || v8 == 3 || v8 == 5) )
    ++plr[pnum]._pAnimFrame;
  if ( plr[pnum]._pIFlags & 0x100000 && (v8 == 1 || v8 == 4) )
    plr[pnum]._pAnimFrame += 2;
  if ( plr[pnum]._pAFNum - 1 == plr[pnum]._pAnimFrame )
    PlaySfxLoc(50, plr[pnum].WorldX, plr[pnum].WorldY);
  if ( plr[pnum]._pAFNum == plr[pnum]._pAnimFrame )
  {
    sx = plr[pnum].WorldX + offset_x[plr[pnum]._pdir];
    sy = plr[pnum].WorldY + offset_y[plr[pnum]._pdir];
    if ( plr[pnum]._pIFlags & 0x10 )
      AddMissile(sx, sy, 1, 0, 0, 64, 0, pnum, 0);
    if ( plr[pnum]._pIFlags & 0x20 )
      AddMissile(sx, sy, 2, 0, 0, 64, 0, pnum, 0);
    if ( dMonster[sx][sy] )
    {
      if ( dMonster[sx][sy] <= 0 )
        v1 = PlrHitMonst(pnum, -(dMonster[sx][sy] + 1));
      else
        v1 = PlrHitMonst(pnum, dMonster[sx][sy] - 1);
      plr[pnum]._pVar1 = v1;
    }
    else if ( dPlayer[sx][sy] )
    {
      if ( dPlayer[sx][sy] <= 0 )
        v2 = PlrHitPlr(pnum, -(char)(dPlayer[sx][sy] + 1));
      else
        v2 = PlrHitPlr(pnum, dPlayer[sx][sy] - 1);
      plr[pnum]._pVar1 = v2;
    }
    else if ( dObject[sx][sy] > 0 )
    {
      plr[pnum]._pVar1 = PlrHitObj(pnum, sx, sy);
    }
  }
  if ( plr[pnum]._pAnimFrame != plr[pnum]._pAFrames )
    return 0;
  v3 = plr[pnum]._pVar1;
  StartStand(pnum, plr[pnum]._pdir);
  ClearPlrPVars(pnum);
  if ( v3 )
    WeaponDur(pnum, 4);
  return 1;
}

//----- (004738F1) --------------------------------------------------------
int __fastcall PM_DoRangeAttack(int pnum)
{
  int mitype; // [esp+10h] [ebp-4h]

  if ( plr[pnum]._pAFNum == plr[pnum]._pAnimFrame )
  {
    mitype = 0;
    if ( plr[pnum]._pIFlags & 8 )
      mitype = 27;
    if ( plr[pnum]._pIFlags & 0x2000000 )
      mitype = 56;
    AddMissile(
      plr[pnum].WorldX,
      plr[pnum].WorldY,
      plr[pnum]._pVar1,
      plr[pnum]._pVar2,
      plr[pnum]._pdir,
      mitype,
      0,
      pnum,
      4);
    PlaySfxLoc(44, plr[pnum].WorldX, plr[pnum].WorldY);
  }
  if ( plr[pnum]._pAFrames > plr[pnum]._pAnimFrame )
    return 0;
  StartStand(pnum, plr[pnum]._pdir);
  ClearPlrPVars(pnum);
  WeaponDur(pnum, 4);
  return 1;
}

//----- (00473B19) --------------------------------------------------------
void __fastcall ShieldDur(int pnum)
{
  if ( pnum == myplr )
  {
    if ( plr[pnum].InvBody[4]._itype == 5 )
    {
      if ( plr[pnum].InvBody[4]._iDurability == 1000 )
        return;
      if ( !--plr[pnum].InvBody[4]._iDurability )
      {
        plr[pnum].InvBody[4]._itype = -1;
        CalcPlrInv(pnum, 1);
      }
    }
    if ( plr[pnum].InvBody[5]._itype == 5
      && plr[pnum].InvBody[5]._iDurability != 1000
      && !--plr[pnum].InvBody[5]._iDurability )
    {
      plr[pnum].InvBody[5]._itype = -1;
      CalcPlrInv(pnum, 1);
    }
  }
}

//----- (00473CC0) --------------------------------------------------------
int __fastcall PM_DoBlock(int pnum)
{
  if ( plr[pnum]._pIFlags & 0x1000000 && plr[pnum]._pAnimFrame != 1 )
    plr[pnum]._pAnimFrame = plr[pnum]._pBFrames;
  if ( plr[pnum]._pBFrames > plr[pnum]._pAnimFrame )
    return 0;
  StartStand(pnum, plr[pnum]._pdir);
  ClearPlrPVars(pnum);
  if ( random(3, 4) )
    ShieldDur(pnum);
  return 1;
}

//----- (00473DF5) --------------------------------------------------------
int __fastcall PM_DoSpell(int pnum)
{
  __int64 v1; // rax
  int v2; // eax
  __int64 v3; // rax
  int v4; // eax

  if ( plr[pnum]._pSFNum == plr[pnum]._pAnimFrame )
  {
    CastSpell(pnum, plr[pnum]._pSpell, plr[pnum].WorldX, plr[pnum].WorldY, plr[pnum]._pVar1, plr[pnum]._pVar2, 0);
    if ( !plr[pnum]._pSplFrom )
    {
      if ( plr[pnum]._pRSplType == 2 )
      {
        v1 = 1 << (plr[pnum]._pRSpell - 1);
        v2 = LODWORD(plr[pnum]._pScrlSpells) & v1;
        if ( !(HIDWORD(v1) & HIDWORD(plr[pnum]._pScrlSpells)) && !v2 )
        {
          plr[pnum]._pRSpell = -1;
          plr[pnum]._pRSplType = 4;
          drawpanflag = 255;
        }
      }
      if ( plr[pnum]._pRSplType == 3 )
      {
        v3 = 1 << (plr[pnum]._pRSpell - 1);
        v4 = LODWORD(plr[pnum]._pISpells) & v3;
        if ( !(HIDWORD(v3) & HIDWORD(plr[pnum]._pISpells)) && !v4 )
        {
          plr[pnum]._pRSpell = -1;
          plr[pnum]._pRSplType = 4;
          drawpanflag = 255;
        }
      }
    }
  }
  if ( plr[pnum]._pAnimFrame != plr[pnum]._pSFrames )
    return 0;
  StartStand(pnum, plr[pnum]._pdir);
  ClearPlrPVars(pnum);
  return 1;
}

//----- (00474128) --------------------------------------------------------
int __fastcall PM_DoGotHit(int pnum)
{
  int v3; // [esp+10h] [ebp-4h]

  if ( plr[pnum]._pHFrames == plr[pnum]._pVar8 )
  {
    StartStand(pnum, plr[pnum]._pdir);
    ClearPlrPVars(pnum);
    if ( random(3, 4) )
      ArmorDur(pnum);
    v3 = 1;
  }
  else
  {
    ++plr[pnum]._pVar8;
    v3 = 0;
  }
  return v3;
}

//----- (004741FD) --------------------------------------------------------
void __fastcall ArmorDur(int pnum)
{
  int v2; // [esp+10h] [ebp-Ch]
  PlayerStruct *v3; // [esp+14h] [ebp-8h]
  ItemStruct *v4; // [esp+18h] [ebp-4h]

  if ( pnum == myplr )
  {
    v3 = &plr[pnum];
    if ( plr[pnum].InvBody[6]._itype != -1 || v3->InvBody[0]._itype != -1 )
    {
      v2 = random(8, 3);
      if ( v3->InvBody[6]._itype != -1 && v3->InvBody[0]._itype == -1 )
        v2 = 1;
      if ( v3->InvBody[6]._itype == -1 && v3->InvBody[0]._itype != -1 )
        v2 = 0;
      if ( v2 )
        v4 = &v3->InvBody[6];
      else
        v4 = v3->InvBody;
      if ( v4->_iDurability != 1000 && !--v4->_iDurability )
      {
        v4->_itype = -1;
        CalcPlrInv(pnum, 1);
      }
    }
  }
}

//----- (00474338) --------------------------------------------------------
int __fastcall PM_DoDeath(int pnum)
{
  if ( 2 * plr[pnum]._pDFrames <= plr[pnum]._pVar8 )
  {
    if ( deathdelay > 1 && pnum == myplr && --deathdelay == 1 )
    {
      deathflag = 1;
      if ( gbMaxPlayers == 1 )
        gamemenu_previous();
    }
    plr[pnum]._pAnimDelay = 10000;
    plr[pnum]._pAnimFrame = plr[pnum]._pAnimLen;
  }
  if ( plr[pnum]._pVar8 < 100 )
    ++plr[pnum]._pVar8;
  return 0;
}

//----- (00474483) --------------------------------------------------------
int __fastcall PM_DoNewLvl(int pnum)
{
  return 0;
}

//----- (0047449B) --------------------------------------------------------
void __fastcall CheckNewPath(int pnum)
{
  int v1; // ST4C_4
  int v2; // ST40_4
  int v3; // ST40_4
  int v4; // ST4C_4
  int v5; // ST4C_4
  int v6; // ST48_4
  int v7; // ST4C_4
  int v8; // ST4C_4
  int v9; // ST48_4
  int v10; // ST4C_4
  int v11; // ST48_4
  int v12; // ST4C_4
  int v13; // ST4C_4
  int v14; // ST4C_4
  int v15; // ST40_4
  int v16; // ST40_4
  int v17; // ST4C_4
  int v18; // ST40_4
  int v19; // ST4C_4
  int v20; // ST40_4
  int v21; // ST4C_4
  int v22; // ST4C_4
  int v23; // ST4C_4
  int v24; // ST48_4
  int v25; // ST4C_4
  int v26; // ST48_4
  int v27; // ST4C_4
  int v28; // ST4C_4
  int v29; // ST48_4
  int v30; // ST4C_4
  int v31; // ST48_4
  int v32; // ST4C_4
  int v34; // [esp+18h] [ebp-20h]
  int v35; // [esp+18h] [ebp-20h]
  int v36; // [esp+18h] [ebp-20h]
  int v37; // [esp+18h] [ebp-20h]
  int v38; // [esp+18h] [ebp-20h]
  int v39; // [esp+18h] [ebp-20h]
  int v40; // [esp+18h] [ebp-20h]
  int v41; // [esp+18h] [ebp-20h]
  int v42; // [esp+18h] [ebp-20h]
  int v43; // [esp+18h] [ebp-20h]
  int v44; // [esp+1Ch] [ebp-1Ch]
  int v45; // [esp+1Ch] [ebp-1Ch]
  int v46; // [esp+1Ch] [ebp-1Ch]
  int v47; // [esp+1Ch] [ebp-1Ch]
  int v48; // [esp+20h] [ebp-18h]
  int v49; // [esp+20h] [ebp-18h]
  int v50; // [esp+20h] [ebp-18h]
  int v51; // [esp+20h] [ebp-18h]
  int i; // [esp+24h] [ebp-14h]
  signed int ia; // [esp+24h] [ebp-14h]
  int ib; // [esp+24h] [ebp-14h]
  int ic; // [esp+24h] [ebp-14h]
  int id; // [esp+24h] [ebp-14h]
  int ie; // [esp+24h] [ebp-14h]
  int ig; // [esp+24h] [ebp-14h]
  int ih; // [esp+24h] [ebp-14h]
  int ii; // [esp+24h] [ebp-14h]
  int d; // [esp+28h] [ebp-10h]
  int da; // [esp+28h] [ebp-10h]
  int db; // [esp+28h] [ebp-10h]
  int yvel; // [esp+2Ch] [ebp-Ch]
  int xvel; // [esp+30h] [ebp-8h]
  int v66; // [esp+34h] [ebp-4h]

  if ( plr[pnum].destAction == 20 )
    MakePlrPath(pnum, monster[plr[pnum].destParam1]._mfutx, monster[plr[pnum].destParam1]._mfuty, 0);
  if ( plr[pnum].destAction == 21 )
    MakePlrPath(pnum, plr[plr[pnum].destParam1]._px, plr[plr[pnum].destParam1]._py, 0);
  if ( plr[pnum].walkpath[0] == -1 )
  {
    if ( plr[pnum].destAction != -1 )
    {
      if ( plr[pnum]._pmode )
      {
        if ( plr[pnum]._pmode == 4 && plr[myplr]._pAFNum < plr[pnum]._pAnimFrame )
        {
          switch ( plr[pnum].destAction )
          {
            case 9:
              v17 = GetDirection(plr[pnum]._px, plr[pnum]._py, plr[pnum].destParam1, plr[pnum].destParam2);
              StartAttack(pnum, v17);
              plr[pnum].destAction = -1;
              break;
            case 0x14:
              ih = plr[pnum].destParam1;
              v18 = abs(plr[pnum].WorldX - monster[ih]._mfutx);
              v41 = abs(plr[pnum].WorldY - monster[ih]._mfuty);
              if ( v18 <= 1 && v41 <= 1 )
              {
                v19 = GetDirection(plr[pnum]._px, plr[pnum]._py, monster[ih]._mfutx, monster[ih]._mfuty);
                StartAttack(pnum, v19);
              }
              plr[pnum].destAction = -1;
              break;
            case 0x15:
              ii = plr[pnum].destParam1;
              v20 = abs(plr[pnum].WorldX - plr[ii]._px);
              v42 = abs(plr[pnum].WorldY - plr[ii]._py);
              if ( v20 <= 1 && v42 <= 1 )
              {
                v21 = GetDirection(plr[pnum]._px, plr[pnum]._py, plr[ii]._px, plr[ii]._py);
                StartAttack(pnum, v21);
              }
              plr[pnum].destAction = -1;
              break;
            case 0xD:
              v51 = plr[pnum].destParam1;
              v47 = abs(plr[pnum].WorldX - object[v51]._ox);
              v43 = abs(plr[pnum].WorldY - object[v51]._oy);
              if ( v43 > 1 && dObject[object[v51]._ox - 1][object[v51]._oy + 111] == -1 - v51 )
                v43 = abs(plr[pnum].WorldY - object[v51]._oy + 1);
              if ( v47 <= 1 && v43 <= 1 )
              {
                if ( object[v51]._oBreak == 1 )
                {
                  v22 = GetDirection(plr[pnum].WorldX, plr[pnum].WorldY, object[v51]._ox, object[v51]._oy);
                  StartAttack(pnum, v22);
                }
                else
                {
                  OperateObject(pnum, v51, 0);
                }
              }
              break;
          }
        }
        if ( plr[pnum]._pmode == 5 && plr[myplr]._pAFNum < plr[pnum]._pAnimFrame )
        {
          switch ( plr[pnum].destAction )
          {
            case 0xA:
              v23 = GetDirection(plr[pnum].WorldX, plr[pnum].WorldY, plr[pnum].destParam1, plr[pnum].destParam2);
              StartRangeAttack(pnum, v23, plr[pnum].destParam1, plr[pnum].destParam2);
              plr[pnum].destAction = -1;
              break;
            case 0x16:
              v24 = plr[pnum].destParam1;
              v25 = GetDirection(plr[pnum].WorldX, plr[pnum].WorldY, monster[v24]._mfutx, monster[v24]._mfuty);
              StartRangeAttack(pnum, v25, monster[v24]._mfutx, monster[v24]._mfuty);
              plr[pnum].destAction = -1;
              break;
            case 0x17:
              v26 = plr[pnum].destParam1;
              v27 = GetDirection(plr[pnum].WorldX, plr[pnum].WorldY, plr[v26]._px, plr[v26]._py);
              StartRangeAttack(pnum, v27, plr[v26]._px, plr[v26]._py);
              plr[pnum].destAction = -1;
              break;
          }
        }
        if ( plr[pnum]._pmode == 9 && plr[pnum]._pSFNum < plr[pnum]._pAnimFrame )
        {
          switch ( plr[pnum].destAction )
          {
            case 0xC:
              v28 = GetDirection(plr[pnum].WorldX, plr[pnum].WorldY, plr[pnum].destParam1, plr[pnum].destParam2);
              StartSpell(pnum, v28, plr[pnum].destParam1, plr[pnum].destParam2);
              plr[pnum].destAction = -1;
              break;
            case 0x18:
              v29 = plr[pnum].destParam1;
              v30 = GetDirection(plr[pnum].WorldX, plr[pnum].WorldY, monster[v29]._mfutx, monster[v29]._mfuty);
              StartSpell(pnum, v30, monster[v29]._mfutx, monster[v29]._mfuty);
              plr[pnum].destAction = -1;
              break;
            case 0x19:
              v31 = plr[pnum].destParam1;
              v32 = GetDirection(plr[pnum].WorldX, plr[pnum].WorldY, plr[v31]._px, plr[v31]._py);
              StartSpell(pnum, v32, plr[v31]._px, plr[v31]._py);
              plr[pnum].destAction = -1;
              break;
          }
        }
      }
      else
      {
        switch ( plr[pnum].destAction )
        {
          case 9:
            v1 = GetDirection(plr[pnum].WorldX, plr[pnum].WorldY, plr[pnum].destParam1, plr[pnum].destParam2);
            StartAttack(pnum, v1);
            break;
          case 0xA:
            v5 = GetDirection(plr[pnum].WorldX, plr[pnum].WorldY, plr[pnum].destParam1, plr[pnum].destParam2);
            StartRangeAttack(pnum, v5, plr[pnum].destParam1, plr[pnum].destParam2);
            break;
          case 0xC:
            v8 = GetDirection(plr[pnum].WorldX, plr[pnum].WorldY, plr[pnum].destParam1, plr[pnum].destParam2);
            StartSpell(pnum, v8, plr[pnum].destParam1, plr[pnum].destParam2);
            break;
          case 0xD:
            v48 = plr[pnum].destParam1;
            v45 = abs(plr[pnum].WorldX - object[v48]._ox);
            v37 = abs(plr[pnum].WorldY - object[v48]._oy);
            if ( v37 > 1 && dObject[object[v48]._ox - 1][object[v48]._oy + 111] == -1 - v48 )
              v37 = abs(plr[pnum].WorldY - object[v48]._oy + 1);
            if ( v45 <= 1 && v37 <= 1 )
            {
              if ( object[v48]._oBreak == 1 )
              {
                v13 = GetDirection(plr[pnum].WorldX, plr[pnum].WorldY, object[v48]._ox, object[v48]._oy);
                StartAttack(pnum, v13);
              }
              else
              {
                OperateObject(pnum, v48, 0);
              }
            }
            break;
          case 0xE:
            v49 = plr[pnum].destParam1;
            v46 = abs(plr[pnum].WorldX - object[v49]._ox);
            v38 = abs(plr[pnum].WorldY - object[v49]._oy);
            if ( v38 > 1 && dObject[object[v49]._ox - 1][object[v49]._oy + 111] == -1 - v49 )
              v38 = abs(plr[pnum].WorldY - object[v49]._oy + 1);
            if ( v46 <= 1 && v38 <= 1 )
            {
              if ( object[v49]._oBreak == 1 )
              {
                v14 = GetDirection(plr[pnum].WorldX, plr[pnum].WorldY, object[v49]._ox, object[v49]._oy);
                StartAttack(pnum, v14);
              }
              else
              {
                TryDisarm(pnum, v49);
                OperateObject(pnum, v49, 0);
              }
            }
            break;
          case 0xF:
            if ( myplr == pnum )
            {
              ie = plr[pnum].destParam1;
              v15 = abs(plr[pnum].WorldX - item[ie]._ix);
              v39 = abs(plr[pnum].WorldY - item[ie]._iy);
              if ( v15 <= 1 && v39 <= 1 && pcurs == 1 )
                NetSendCmdGItem(1u, 0x2Au, myplr, myplr, ie);
            }
            break;
          case 0x10:
            if ( myplr == pnum )
            {
              ig = plr[pnum].destParam1;
              v16 = abs(plr[pnum].WorldX - item[ig]._ix);
              v40 = abs(plr[pnum].WorldY - item[ig]._iy);
              if ( v16 <= 1 && v40 <= 1 && pcurs == 1 )
                NetSendCmdGItem(1u, 0x2Bu, myplr, myplr, ig);
            }
            break;
          case 0x11:
            if ( myplr == pnum )
              TalkToTowner(pnum, plr[pnum].destParam1);
            break;
          case 0x12:
            v50 = plr[pnum].destParam1;
            if ( object[v50]._oBreak != 1 )
              OperateObject(pnum, v50, 1u);
            break;
          case 0x14:
            ib = plr[pnum].destParam1;
            v2 = abs(plr[pnum].WorldX - monster[ib]._mfutx);
            v35 = abs(plr[pnum].WorldY - monster[ib]._mfuty);
            if ( v2 <= 1 && v35 <= 1 )
            {
              da = GetDirection(plr[pnum]._px, plr[pnum]._py, monster[ib]._mfutx, monster[ib]._mfuty);
              if ( monster[ib].mtalkmsg )
                TalktoMonster(ib);
              else
                StartAttack(pnum, da);
            }
            break;
          case 0x15:
            ic = plr[pnum].destParam1;
            v3 = abs(plr[pnum].WorldX - plr[ic]._px);
            v36 = abs(plr[pnum].WorldY - plr[ic]._py);
            if ( v3 <= 1 && v36 <= 1 )
            {
              v4 = GetDirection(plr[pnum]._px, plr[pnum]._py, plr[ic]._px, plr[ic]._py);
              StartAttack(pnum, v4);
            }
            break;
          case 0x16:
            id = plr[pnum].destParam1;
            db = GetDirection(plr[pnum]._px, plr[pnum]._py, monster[id]._mfutx, monster[id]._mfuty);
            if ( monster[id].mtalkmsg )
              TalktoMonster(id);
            else
              StartRangeAttack(pnum, db, monster[id]._mfutx, monster[id]._mfuty);
            break;
          case 0x17:
            v6 = plr[pnum].destParam1;
            v7 = GetDirection(plr[pnum]._px, plr[pnum]._py, plr[v6]._px, plr[v6]._py);
            StartRangeAttack(pnum, v7, plr[v6]._px, plr[v6]._py);
            break;
          case 0x18:
            v9 = plr[pnum].destParam1;
            v10 = GetDirection(plr[pnum].WorldX, plr[pnum].WorldY, monster[v9]._mfutx, monster[v9]._mfuty);
            StartSpell(pnum, v10, monster[v9]._mfutx, monster[v9]._mfuty);
            break;
          case 0x19:
            v11 = plr[pnum].destParam1;
            v12 = GetDirection(plr[pnum].WorldX, plr[pnum].WorldY, plr[v11]._px, plr[v11]._py);
            StartSpell(pnum, v12, plr[v11]._px, plr[v11]._py);
            break;
          default:
            break;
        }
        plr[pnum].destAction = -1;
      }
    }
  }
  else if ( !plr[pnum]._pmode )
  {
    if ( plr[pnum].destAction == 20 || plr[pnum].destAction == 21 )
    {
      i = plr[pnum].destParam1;
      if ( plr[pnum].destAction == 20 )
      {
        v44 = abs(plr[pnum]._px - monster[i]._mfutx);
        v34 = abs(plr[pnum]._py - monster[i]._mfuty);
        d = GetDirection(plr[pnum]._px, plr[pnum]._py, monster[i]._mfutx, monster[i]._mfuty);
      }
      else
      {
        v44 = abs(plr[pnum]._px - plr[i]._px);
        v34 = abs(plr[pnum]._py - plr[i]._py);
        d = GetDirection(plr[pnum]._px, plr[pnum]._py, plr[i]._px, plr[i]._py);
      }
      if ( v44 < 2 && v34 < 2 )
      {
        ClrPlrPath(pnum);
        if ( monster[i].mtalkmsg )
          TalktoMonster(i);
        else
          StartAttack(pnum, d);
        plr[pnum].destAction = -1;
      }
    }
    if ( currlevel )
    {
      v66 = PWVel[plr[pnum]._pClass][0];
      xvel = PWVel[plr[pnum]._pClass][1];
      yvel = PWVel[plr[pnum]._pClass][2];
    }
    else
    {
      v66 = 2048;
      xvel = 1024;
      yvel = 512;
    }
    switch ( plr[pnum].walkpath[0] )
    {
      case 1:
        StartWalk(pnum, xvel, -yvel, 0, -1, 5, 2);
        break;
      case 2:
        StartWalk(pnum, -xvel, -yvel, -1, 0, 3, 8);
        break;
      case 3:
        StartWalk2(pnum, xvel, yvel, -32, -16, 1, 0, 7, 4);
        break;
      case 4:
        StartWalk2(pnum, -xvel, yvel, 32, -16, 0, 1, 1, 6);
        break;
      case 5:
        StartWalk(pnum, 0, -xvel, -1, -1, 4, 1);
        break;
      case 6:
        StartWalk3(pnum, v66, 0, -32, -16, 1, -1, 1, 0, 6, 3);
        break;
      case 7:
        StartWalk2(pnum, 0, xvel, 0, -32, 1, 1, 0, 5);
        break;
      case 8:
        StartWalk3(pnum, -v66, 0, 32, -16, -1, 1, 0, 1, 2, 7);
        break;
      default:
        break;
    }
    for ( ia = 1; ia < 25; ++ia )
      plr[pnum].walkpath[ia - 1] = plr[pnum].walkpath[ia];
    plr[pnum].walkpath[24] = -1;
    if ( !plr[pnum]._pmode )
    {
      StartStand(pnum, plr[pnum]._pdir);
      plr[pnum].destAction = -1;
    }
  }
}

//----- (004768A6) --------------------------------------------------------
BOOL __fastcall PlrDeathModeOK(int pnum)
{
  if ( plr[pnum]._pmode == 8 )
    return 1;
  if ( plr[pnum]._pmode == 11 )
    return 1;
  return plr[pnum]._pmode == 10;
}

//----- (00476948) --------------------------------------------------------
void __cdecl ProcessPlayers()
{
  int v0; // [esp+10h] [ebp-Ch]
  signed int i; // [esp+14h] [ebp-8h]
  int pnum; // [esp+18h] [ebp-4h]

  for ( i = 0; i < 40; ++i )
  {
    assert(!(plr[myplr].InvGrid[i] > 0 && plr[myplr].InvGrid[i] > plr[myplr]._pNumInv), "PLAYER.CPP", 2837);
  }
  if ( sfxdelay > 0 && !--sfxdelay )
    PlaySFX(sfxdnum);
  for ( pnum = 0; pnum < 4; ++pnum )
  {
    if ( plr[pnum].plractive && plr[pnum].plrlevel == currlevel && (myplr == pnum || !plr[pnum]._pLvlChanging) )
    {
      if ( !PlrDeathModeOK(pnum) && (signed int)(plr[pnum]._pHitPoints & 0xFFFFFFC0) <= 0 )
      {
        SetPlayerHitPoints(pnum, 0);
        SyncPlrKill(pnum);
      }
      if ( myplr == pnum )
      {
        if ( plr[pnum]._pIFlags & 0x40 )
        {
          --plr[pnum]._pHitPoints;
          --plr[pnum]._pHPBase;
          if ( (signed int)(plr[pnum]._pHitPoints & 0xFFFFFFC0) <= 0 )
          {
            SetPlayerHitPoints(pnum, 0);
            SyncPlrKill(pnum);
          }
          drawhpflag = 1;
        }
        if ( plr[pnum]._pIFlags & 0x8000000 && plr[pnum]._pManaBase > 0 )
        {
          plr[pnum]._pManaBase -= plr[pnum]._pMana;
          plr[pnum]._pMana = 0;
          drawmanaflag = 1;
        }
      }
      v0 = 0;
      do
      {
        switch ( plr[pnum]._pmode )
        {
          case PM_STAND:
            v0 = PM_DoStand();
            break;
          case PM_WALK:
            v0 = PM_DoWalk(pnum);
            break;
          case PM_WALK2:
            v0 = PM_DoWalk2(pnum);
            break;
          case PM_WALK3:
            v0 = PM_DoWalk3(pnum);
            break;
          case PM_ATTACK:
            v0 = PM_DoAttack(pnum);
            break;
          case PM_RATTACK:
            v0 = PM_DoRangeAttack(pnum);
            break;
          case PM_BLOCK:
            v0 = PM_DoBlock(pnum);
            break;
          case PM_GOTHIT:
            v0 = PM_DoGotHit(pnum);
            break;
          case PM_DEATH:
            v0 = PM_DoDeath(pnum);
            break;
          case PM_SPELL:
            v0 = PM_DoSpell(pnum);
            break;
          case PM_NEWLVL:
            v0 = PM_DoNewLvl(pnum);             // NOTE: Merged with PM_DoStand in 1.09 due to duplicate function removal
            break;
          default:
            break;
        }
        CheckNewPath(pnum);
      }
      while ( v0 );
      if ( plr[pnum]._pAnimDelay < ++plr[pnum]._pAnimCnt )
      {
        plr[pnum]._pAnimCnt = 0;
        if ( plr[pnum]._pAnimLen < ++plr[pnum]._pAnimFrame )
          plr[pnum]._pAnimFrame = 1;
      }
    }
  }
}

//----- (00476EBF) --------------------------------------------------------
void __fastcall ClrPlrPath(int pnum)
{
  memset(plr[pnum].walkpath, -1, 0x19u);
}

//----- (00476F02) --------------------------------------------------------
BOOL __fastcall PosOkPlayer(int pnum, int px, int py)
{
  BOOL result; // eax
  char v6; // [esp+14h] [ebp-Ch]
  int v7; // [esp+1Ch] [ebp-4h]

  if ( !dPiece[px][py] )
    return 0;
  if ( SolidLoc(px, py) )
    return 0;
  if ( dPlayer[px][py] )
  {
    v7 = dPlayer[px][py] <= 0 ? -(dPlayer[px][py] + 1) : dPlayer[px][py] - 1;
    if ( pnum != v7 && plr[v7]._pHitPoints )
      return 0;
  }
  if ( dMonster[px][py] )
  {
    if ( !currlevel )
      return 0;
    if ( dMonster[px][py] <= 0 )
      return 0;
    if ( (signed int)(monster[dMonster[px][py] - 1]._mhitpoints & 0xFFFFFFC0) > 0 )
      return 0;
  }
  result = 1;
  if ( dObject[px][py] )
  {
    v6 = dObject[px][py] <= 0 ? -(char)(dObject[px][py] + 1) : dObject[px][py] - 1;
    if ( object[v6]._oSolidFlag )
      result = 0;
  }
  return result;
}

//----- (00477159) --------------------------------------------------------
void __fastcall MakePlrPath(int pnum, int xx, int yy, unsigned __int8 endspace)
{
  int sy; // [esp+10h] [ebp-Ch]
  int v6; // [esp+18h] [ebp-4h]

  sy = xx;
  plr[pnum]._ptargx = xx;
  plr[pnum]._ptargy = yy;
  if ( plr[pnum]._px != xx || plr[pnum]._py != yy )
  {
    v6 = FindPath(pnum, plr[pnum]._px, plr[pnum]._py, xx, yy, plr[pnum].walkpath);
    if ( v6 )
    {
      if ( !endspace )
      {
        switch ( plr[pnum].walkpath[--v6] )
        {
          case 1:
            ++yy;
            break;
          case 2:
            ++sy;
            break;
          case 3:
            --sy;
            break;
          case 4:
            --yy;
            break;
          case 5:
            ++sy;
            ++yy;
            break;
          case 6:
            --sy;
            ++yy;
            break;
          case 7:
            --sy;
            --yy;
            break;
          case 8:
            ++sy;
            --yy;
            break;
          default:
            break;
        }
        plr[pnum]._ptargx = sy;
        plr[pnum]._ptargy = yy;
      }
      plr[pnum].walkpath[v6] = -1;
    }
  }
}

//----- (0047739D) --------------------------------------------------------
void __fastcall CheckPlrSpell()
{
  int v0; // [esp+10h] [ebp-8h]
  BOOL v1; // [esp+14h] [ebp-4h]

  v1 = 0;
  v0 = plr[myplr]._pRSpell;
  if ( leveltype
    && pcurs == 1
    && (MouseY < 352 && (!chrflag || MouseX >= 320) && (!invflag || MouseX <= 320)
     || v0 == 2
     || v0 == 5
     || v0 == 26
     || v0 == 9
     || v0 == 27) )
  {
    switch ( plr[myplr]._pRSplType )
    {
      case 0u:
      case 1u:
        v1 = CheckSpell(myplr, plr[myplr]._pRSpell, plr[myplr]._pRSplType, 0);
        break;
      case 2u:
        v1 = UseScroll();
        break;
      case 3u:
        v1 = UseStaff();
        break;
      default:
        break;
    }
    if ( v1 )
    {
      if ( pcursmonst == -1 )
      {
        if ( pcursplr == -1 )
          NetSendCmdLocParam1(1u, 0x10u, cursmx, cursmy, plr[myplr]._pRSpell);
        else
          NetSendCmdParam2(1u, 0x19u, pcursplr, plr[myplr]._pRSpell);
      }
      else
      {
        NetSendCmdParam2(1u, 0x18u, pcursmonst, plr[myplr]._pRSpell);
      }
    }
  }
}

//----- (00477618) --------------------------------------------------------
void __fastcall SyncPlrAnim(int pnum)
{
  int v1; // [esp+14h] [ebp-8h]
  int v2; // [esp+18h] [ebp-4h]

  v1 = plr[pnum]._pdir;
  switch ( plr[pnum]._pmode )
  {
    case 0:
      plr[pnum]._pAnimData = plr[pnum]._pNAnim[v1];
      break;
    case 1:
      plr[pnum]._pAnimData = plr[pnum]._pWAnim[v1];
      break;
    case 2:
      plr[pnum]._pAnimData = plr[pnum]._pWAnim[v1];
      break;
    case 3:
      plr[pnum]._pAnimData = plr[pnum]._pWAnim[v1];
      break;
    case 4:
      plr[pnum]._pAnimData = plr[pnum]._pAAnim[v1];
      break;
    case 5:
      plr[pnum]._pAnimData = plr[pnum]._pAAnim[v1];
      break;
    case 6:
      plr[pnum]._pAnimData = plr[pnum]._pBAnim[v1];
      break;
    case 7:
      plr[pnum]._pAnimData = plr[pnum]._pHAnim[v1];
      break;
    case 8:
      plr[pnum]._pAnimData = plr[pnum]._pDAnim[v1];
      break;
    case 9:
      if ( myplr == pnum )
        v2 = spelldata[plr[pnum]._pSpell].sType;
      if ( !v2 )
        plr[pnum]._pAnimData = plr[pnum]._pFAnim[v1];
      if ( v2 == 1 )
        plr[pnum]._pAnimData = plr[pnum]._pLAnim[v1];
      if ( v2 == 2 )
        plr[pnum]._pAnimData = plr[pnum]._pTAnim[v1];
      break;
    case 0xA:
    case 0xB:
      plr[pnum]._pAnimData = plr[pnum]._pNAnim[v1];
      break;
    default:
      TermMsg("SyncPlrAnim");
      return;
  }
  assert(plr[pnum]._pAnimData, "PLAYER.CPP", 3116);
}

//----- (00477AEA) --------------------------------------------------------
void __fastcall SyncInitPlrPos(int pnum)
{
  unsigned int i; // [esp+10h] [ebp-4h]

  SetPlrAnims(pnum);
  plr[pnum]._ptargx = plr[pnum].WorldX;
  plr[pnum]._ptargy = plr[pnum].WorldY;
  if ( plr[pnum].plrlevel == currlevel )
  {
    for ( i = 0; i < 8 && !PosOkPlayer(pnum, plrxoff2[i] + plr[pnum].WorldX, plryoff2[i] + plr[pnum].WorldY); ++i )
      ;
    plr[pnum].WorldX += plrxoff2[i];
    plr[pnum].WorldY += plryoff2[i];
    dPlayer[plr[pnum].WorldX][plr[pnum].WorldY] = pnum + 1;
  }
}

//----- (00477CC8) --------------------------------------------------------
void __fastcall ModifyPlrStr(int pnum, int l)
{
  int v2; // eax

  plr[pnum]._pStrength += l;
  plr[pnum]._pBaseStr += l;
  if ( plr[pnum]._pClass == 1 )
    v2 = plr[pnum]._pLevel * (plr[pnum]._pStrength + plr[pnum]._pDexterity) / 200;
  else
    v2 = plr[pnum]._pStrength * plr[pnum]._pLevel / 100;
  plr[pnum]._pDamageMod = v2;
  CalcPlrInv(pnum, 1);
  if ( pnum == myplr )
    NetSendCmdParam1(0, 0x52u, plr[pnum]._pBaseStr);
}

//----- (00477E73) --------------------------------------------------------
void __fastcall ModifyPlrMag(int pnum, int l)
{
  int v2; // [esp+Ch] [ebp-8h]

  plr[pnum]._pMagic += l;
  plr[pnum]._pBaseMag += l;
  v2 = l << 6;
  if ( plr[pnum]._pClass == 2 )
    v2 = l << 7;
  plr[pnum]._pMaxManaBase += v2;
  plr[pnum]._pMaxMana += v2;
  if ( !(plr[pnum]._pIFlags & 0x8000000) )
  {
    plr[pnum]._pManaBase += v2;
    plr[pnum]._pMana += v2;
  }
  CalcPlrInv(pnum, 1);
  if ( pnum == myplr )
    NetSendCmdParam1(0, 0x53u, plr[pnum]._pBaseMag);
}

//----- (00477FE3) --------------------------------------------------------
void __fastcall ModifyPlrDex(int pnum, int l)
{
  plr[pnum]._pDexterity += l;
  plr[pnum]._pBaseDex += l;
  CalcPlrInv(pnum, 1);
  if ( plr[pnum]._pClass == 1 )
    plr[pnum]._pDamageMod = plr[pnum]._pLevel * (plr[pnum]._pStrength + plr[pnum]._pDexterity) / 200;
  if ( myplr == pnum )
    NetSendCmdParam1(0, CMD_SETDEX, plr[pnum]._pBaseDex);
}

//----- (00478129) --------------------------------------------------------
void __fastcall ModifyPlrVit(int pnum, int l)
{
  int v2; // [esp+Ch] [ebp-8h]

  plr[pnum]._pVitality += l;
  plr[pnum]._pBaseVit += l;
  v2 = l << 6;
  if ( !plr[pnum]._pClass )
    v2 = l << 7;
  plr[pnum]._pHPBase += v2;
  plr[pnum]._pMaxHPBase += v2;
  plr[pnum]._pHitPoints += v2;
  plr[pnum]._pMaxHP += v2;
  CalcPlrInv(pnum, 1);
  if ( pnum == myplr )
    NetSendCmdParam1(0, CMD_SETVIT, plr[pnum]._pBaseVit);
}

//----- (00478274) --------------------------------------------------------
void __fastcall SetPlayerHitPoints(int pnum, int newhp)
{
  plr[pnum]._pHitPoints = newhp;
  plr[pnum]._pHPBase = newhp - (plr[pnum]._pMaxHP - plr[pnum]._pMaxHPBase);
}

//----- (00478309) --------------------------------------------------------
void __fastcall SetPlrStr(int pnum, int v)
{
  int v2; // eax

  plr[pnum]._pBaseStr = v;
  CalcPlrInv(pnum, 1);
  if ( plr[pnum]._pClass == 1 )
    v2 = plr[pnum]._pLevel * (plr[pnum]._pStrength + plr[pnum]._pDexterity) / 200;
  else
    v2 = plr[pnum]._pStrength * plr[pnum]._pLevel / 100;
  plr[pnum]._pDamageMod = v2;
}

//----- (0047845C) --------------------------------------------------------
void __fastcall SetPlrMag(int pnum, int v)
{
  int v2; // [esp+Ch] [ebp-8h]

  plr[pnum]._pBaseMag = v;
  v2 = v << 6;
  if ( plr[pnum]._pClass == 2 )
    v2 = v << 7;
  plr[pnum]._pMaxManaBase = v2;
  plr[pnum]._pMaxMana = v2;
  CalcPlrInv(pnum, 1);
}

//----- (00478510) --------------------------------------------------------
void __fastcall SetPlrDex(int pnum, int v)
{
  int v2; // eax

  plr[pnum]._pBaseDex = v;
  CalcPlrInv(pnum, 1);
  if ( plr[pnum]._pClass == 1 )
    v2 = plr[pnum]._pLevel * (plr[pnum]._pStrength + plr[pnum]._pDexterity) / 200;
  else
    v2 = plr[pnum]._pStrength * plr[pnum]._pLevel / 100;
  plr[pnum]._pDamageMod = v2;
}

//----- (00478663) --------------------------------------------------------
void __fastcall SetPlrVit(int pnum, int v)
{
  int v2; // [esp+Ch] [ebp-8h]

  plr[pnum]._pBaseVit = v;
  v2 = v << 6;
  if ( !plr[pnum]._pClass )
    v2 = v << 7;
  plr[pnum]._pHPBase = v2;
  plr[pnum]._pMaxHPBase = v2;
  CalcPlrInv(pnum, 1);
}

