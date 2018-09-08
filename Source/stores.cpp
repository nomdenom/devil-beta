//----- (0042E330) --------------------------------------------------------
void __cdecl InitStores()
{
  signed int i; // [esp+Ch] [ebp-4h]

  assert(!pSTextBoxCels, "stores.cpp", 87);
  pSTextBoxCels = LoadFileInMem("Data\\TextBox2.CEL", 0, 88, "stores.cpp");
  pCelBuff = (char *)LoadFileInMem("Data\\PentSpn2.CEL", 0, 89, "stores.cpp");
  pSTextSlidCels = LoadFileInMem("Data\\TextSlid.CEL", 0, 90, "stores.cpp");
  ClearSText(0, 24);
  stextflag = 0;
  InStoreFlag = 1;
  stextsize = 0;
  stextscrl = 0;
  numpremium = 0;
  premiumlevel = 1;
  for ( i = 0; i < 6; ++i )
    premiumitem[i]._itype = -1;
}

//----- (0042E424) --------------------------------------------------------
void __cdecl SetupTownStores()
{
  int lvl; // [esp+Ch] [ebp-8h]
  int lvla; // [esp+Ch] [ebp-8h]
  signed int i; // [esp+10h] [ebp-4h]

  if ( gbMaxPlayers == 1 )
  {
    lvl = 0;
    for ( i = 0; i < 17; ++i )
    {
      if ( plr[myplr]._pLvlVisited[i] )
        lvl = i;
    }
  }
  else
  {
    lvl = plr[myplr]._pLevel >> 1;
  }
  lvla = lvl + 2;
  if ( lvla < 6 )
    lvla = 6;
  if ( lvla > 16 )
    lvla = 16;
  SpawnStoreGold();
  SpawnSmith(lvla);
  SpawnPremium(plr[myplr]._pLevel);
  SpawnWitch(lvla);
  SpawnBoy(2 * lvla);
  SpawnHealer(lvla);
}

//----- (0042E53B) --------------------------------------------------------
void __cdecl FreeStoreMem()
{
  mem_free_dbg(pSTextBoxCels, 139, "stores.cpp");
  pSTextBoxCels = 0;
  mem_free_dbg(pCelBuff, 141, "stores.cpp");
  pCelBuff = 0;
  mem_free_dbg(pSTextSlidCels, 143, "stores.cpp");
  pSTextSlidCels = 0;
}

//----- (0042E5A8) --------------------------------------------------------
void __cdecl DrawSTextBack()
{
  char *v0; // edi
  signed int v1; // edx
  signed int v2; // ecx
  int v3; // edi
  signed int v4; // ecx
  _BYTE *v5; // edi
  signed int v6; // ecx

  CelDecodeOnly(408, 487, pSTextBoxCels, 1, 271);
  v0 = gpBuffer + 372123;
  for (v1 = 148; v1; --v1)
  {
    for (v2 = 132; v2; --v2)
    {
      *v0 = 0;
      v0 += 2;
    }
    *v0 = 0;
    v3 = (int)(v0 - 1032);
    for (v4 = 132; v4; --v4)
    {
      v5 = (_BYTE *)(v3 + 1);
      *v5 = 0;
      v3 = (int)(v5 + 1);
    }
    v0 = (char *)(v3 - 1032);
  }
  
  for (v6 = 132; v6; --v6)
  {
    *v0 = 0;
    v0 += 2;
  }
  *v0 = 0;
}

//----- (0042E617) --------------------------------------------------------
void __fastcall PrintSString(int x, int y, unsigned __int8 cjustflag, char *str, char col, int val)
{
  signed int v8; // [esp+14h] [ebp-48h]
  int v9; // [esp+1Ch] [ebp-40h]
  signed int i; // [esp+20h] [ebp-3Ch]
  signed int j; // [esp+20h] [ebp-3Ch]
  signed int k; // [esp+20h] [ebp-3Ch]
  signed int v13; // [esp+24h] [ebp-38h]
  int v14; // [esp+28h] [ebp-34h]
  int No; // [esp+2Ch] [ebp-30h]
  int Noa; // [esp+2Ch] [ebp-30h]
  int v17; // [esp+30h] [ebp-2Ch]
  char v18; // [esp+34h] [ebp-28h]
  char v19; // [esp+34h] [ebp-28h]
  int v20; // [esp+38h] [ebp-24h]
  char v21[32]; // [esp+3Ch] [ebp-20h]

  v17 = SStringY[y] + stext[y]._syoff;
  if ( stextsize )
    v13 = 96;
  else
    v13 = 416;
  No = v13 + x + screen_y_times_768[v17 + 204];
  v8 = strlen(str);
  if ( stextsize )
    v20 = 577;
  else
    v20 = 257;
  v14 = 0;
  if ( cjustflag )
  {
    v9 = 0;
    for ( i = 0; i < v8; ++i )
      v9 += fontkern[fontframe[str[i] & 0x7F]] + 1;
    if ( v20 > v9 )
      v14 = (v20 - v9) >> 1;
    No += v14;
  }
  if ( stextsel == y )
  {
    if ( cjustflag )
      CelDecodeOnly(v13 + x + v14 - 20, v17 + 205, pCelBuff, InStoreFlag, 12);
    else
      CelDecodeOnly(v13 + x - 20, v17 + 205, pCelBuff, InStoreFlag, 12);
  }
  for ( j = 0; j < v8; ++j )
  {
    v18 = fontframe[str[j] & 0x7F];
    v14 += fontkern[v18] + 1;
    if ( v18 )
    {
      if ( v20 >= v14 )
        CPrintString(No, v18, col);
    }
    No += fontkern[v18] + 1;
  }
  if ( !cjustflag && val >= 0 )
  {
    sprintf(v21, "%i", val);
    Noa = screen_y_times_768[v17 + 204] + 656 - x;
    for ( k = strlen(v21) - 1; k >= 0; --k )
    {
      v19 = fontframe[v21[k] & 0x7F];
      Noa -= fontkern[v19] + 1;
      if ( v19 )
        CPrintString(Noa, v19, col);
    }
  }
  if ( stextsel == y )
  {
    if ( cjustflag )
      CelDecodeOnly(v13 + x + v14 + 4, v17 + 205, pCelBuff, InStoreFlag, 12);
    else
      CelDecodeOnly(660 - x, v17 + 205, pCelBuff, InStoreFlag, 12);
  }
}

//----- (0042E90E) --------------------------------------------------------
void __fastcall DrawSLine(int y)
{
  char *v1; // esi
  char *v2; // edi
  signed int v3; // edx
  char *v4; // edi
  char *v5; // esi
  signed int v6; // [esp+10h] [ebp-14h]
  int v7; // [esp+14h] [ebp-10h]
  signed int v8; // [esp+18h] [ebp-Ch]
  int v9; // [esp+1Ch] [ebp-8h]
  signed int v10; // [esp+20h] [ebp-4h]

  v9 = SStringY[y];
  if ( stextsize == 1 )
  {
    v8 = 142170;
    v7 = screen_y_times_768[v9 + 198] + 90;
    v10 = 146;
    v6 = 182;
  }
  else
  {
    v8 = 142490;
    v7 = screen_y_times_768[v9 + 198] + 410;
    v10 = 66;
    v6 = 502;
  }
  v1 = &gpBuffer[v8];
  v2 = &gpBuffer[v7];
  for (v3 = 3; v3; --v3)
  {
    qmemcpy(v2, v1, 4 * v10);
    v5 = &v1[4 * v10];
    v4 = &v2[4 * v10];
    *(_WORD *)v4 = *(_WORD *)v5;
    v1 = &v5[v6 + 2];
    v2 = &v4[v6 + 2];
  }
}

//----- (0042E9BA) --------------------------------------------------------
void __fastcall DrawSArrows(int y1, int y2)
{
  int i; // [esp+14h] [ebp-14h]
  int v5; // [esp+18h] [ebp-10h]
  int screen_y; // [esp+1Ch] [ebp-Ch]
  int v7; // [esp+20h] [ebp-8h]
  int v8; // [esp+24h] [ebp-4h]

  screen_y = SStringY[y1] + 204;
  v5 = SStringY[y2] + 204;
  if ( stextscrlubtn == -1 )
    CelDecodeOnly(665, screen_y, pSTextSlidCels, 10, 12);
  else
    CelDecodeOnly(665, screen_y, pSTextSlidCels, 12, 12);
  if ( stextscrldbtn == -1 )
    CelDecodeOnly(665, v5, pSTextSlidCels, 9, 12);
  else
    CelDecodeOnly(665, v5, pSTextSlidCels, 11, 12);
  for ( i = screen_y + 12; v5 > i; i += 12 )
    CelDecodeOnly(665, i, pSTextSlidCels, 14, 12);
  if ( stextsel == 22 )
    v8 = stextlhold;
  else
    v8 = stextsel;
  if ( storenumh <= 1 )
    v7 = 0;
  else
    v7 = 1000 * (stextsval + ((v8 - stextup) >> 2)) / (storenumh - 1) * (SStringY[y2] - SStringY[y1] - 24) / 1000;
  CelDecodeOnly(665, SStringY[y1 + 1] + 204 + v7, pSTextSlidCels, 13, 12);
}

//----- (0042EB9F) --------------------------------------------------------
void __cdecl DrawSTextHelp()
{
  stextsize = 1;
  stextsel = -1;
}

//----- (0042EBC0) --------------------------------------------------------
void __fastcall ClearSText(int s, int e)
{
  int i; // [esp+14h] [ebp-4h]

  for ( i = s; i < e; ++i )
  {
    stext[i]._sx = 0;
    stext[i]._syoff = 0;
    stext[i]._sstr[0] = 0;
    stext[i]._sjust = 0;
    stext[i]._sclr = 0;
    stext[i]._sline = 0;
    stext[i]._ssel = 0;
    stext[i]._sval = -1;
  }
}

//----- (0042ECB2) --------------------------------------------------------
void __fastcall AddSLine(int y)
{
  stext[y]._sx = 0;
  stext[y]._syoff = 0;
  stext[y]._sstr[0] = 0;
  stext[y]._sline = 1;
}

//----- (0042ED25) --------------------------------------------------------
void __fastcall AddSTextVal(int y, int val)
{
  stext[y]._sval = val;
}

//----- (0042ED55) --------------------------------------------------------
void __fastcall OffsetSTextY(int y, int yo)
{
  stext[y]._syoff = yo;
}

//----- (0042ED85) --------------------------------------------------------
void __fastcall AddSText(int x, int y, unsigned __int8 j, char *str, int clr, int sel)
{
  stext[y]._sx = x;
  stext[y]._syoff = 0;
  strcpy(stext[y]._sstr, str);
  stext[y]._sjust = j;
  stext[y]._sclr = clr;
  stext[y]._sline = 0;
  stext[y]._ssel = sel;
}

//----- (0042EE50) --------------------------------------------------------
void __cdecl S_StartSmith()
{
  stextsize = 0;
  stextscrl = 0;
  AddSText(0, 1, 1u, "Welcome to the", 3, 0);
  AddSText(0, 3, 1u, "Blacksmith's shop", 3, 0);
  AddSText(0, 9, 1u, "Would you like to:", 3, 0);
  AddSText(0, 12, 1u, "Buy basic items", 0, 1);
  AddSText(0, 14, 1u, "Buy premium items", 0, 1);
  AddSText(0, 16, 1u, "Sell items", 0, 1);
  AddSText(0, 18, 1u, "Repair items", 0, 1);
  AddSText(0, 20, 1u, "Leave the shop", 0, 1);
  AddSLine(5);
  storenumh = 20;
}

//----- (0042EF3D) --------------------------------------------------------
void __fastcall S_ScrollSBuy(int idx)
{
  int clr; // [esp+10h] [ebp-Ch]
  int y; // [esp+14h] [ebp-8h]

  ClearSText(5, 21);
  stextup = 5;
  for ( y = 5; y < 20; y += 4 )
  {
    if ( smithitem[idx]._itype != -1 )
    {
      LOBYTE(clr) = 0;
      if ( smithitem[idx]._iMagical )
        LOBYTE(clr) = 1;
      if ( !smithitem[idx]._iStatFlag )
        LOBYTE(clr) = 2;
      if ( smithitem[idx]._iMagical )
        AddSText(20, y, 0, smithitem[idx]._iIName, clr, 1);
      else
        AddSText(20, y, 0, smithitem[idx]._iName, clr, 1);
      AddSTextVal(y, smithitem[idx]._iIvalue);
      PrintStoreItem(&smithitem[idx], y + 1, clr);
      stextdown = y;
      ++idx;
    }
  }
  if ( !stext[stextsel]._ssel && stextsel != 22 )
    stextsel = stextdown;
}

//----- (0042F0E8) --------------------------------------------------------
void __fastcall PrintStoreItem(ItemStruct *x, int l, char iclr)
{
  char str; // [esp+14h] [ebp-80h]

  str = 0;
  if ( x->_iMagical != 2 && x->_iPrePower != -1 && x->_iIdentified )
  {
    PrintItemPower(x->_iPrePower, x);
    strcat(&str, tempstr);
  }
  if ( x->_iSufPower != -1 && x->_iIdentified )
  {
    PrintItemPower(x->_iSufPower, x);
    if ( str )
      strcat(&str, ",  ");
    strcat(&str, tempstr);
  }
  if ( x->_iMiscId == 23 && x->_iMaxCharges )
  {
    sprintf(tempstr, "Charges: %i/%i", x->_iCharges, x->_iMaxCharges);
    if ( str )
      strcat(&str, ",  ");
    strcat(&str, tempstr);
  }
  if ( str )
    AddSText(40, l++, 0, &str, iclr, 0);
  str = 0;
  if ( x->_iClass == 1 )
    sprintf(&str, "Damage: %i-%i  ", x->_iMinDam, x->_iMaxDam);
  if ( x->_iClass == 2 )
    sprintf(&str, "Armor: %i  ", x->_iAC);
  if ( x->_iMaxDur != 1000 && x->_iMaxDur )
  {
    sprintf(tempstr, "Dur: %i/%i,  ", x->_iDurability, x->_iMaxDur);
    strcat(&str, tempstr);
  }
  else
  {
    strcat(&str, "Indestructible,  ");
  }
  if ( !x->_itype )
    str = 0;
  if ( x->_iMinDex + (char)x->_iMinMag + x->_iMinStr )
  {
    strcpy(tempstr, "Required:");
    if ( x->_iMinStr )
      sprintf(tempstr, "%s %i Str", tempstr, x->_iMinStr);
    if ( x->_iMinMag )
      sprintf(tempstr, "%s %i Mag", tempstr, (char)x->_iMinMag);
    if ( x->_iMinDex )
      sprintf(tempstr, "%s %i Dex", tempstr, x->_iMinDex);
    strcat(&str, tempstr);
  }
  else
  {
    strcat(&str, "No required attributes");
  }
  AddSText(40, l, 0, &str, iclr, 0);
}

//----- (0042F4CB) --------------------------------------------------------
void __cdecl S_StartSBuy()
{
  int i; // [esp+Ch] [ebp-4h]

  stextsize = 1;
  stextscrl = 1;
  stextsval = 0;
  sprintf(tempstr, "I have these items for sale :           Your gold : %i", plr[myplr]._pGold);
  AddSText(0, 1, 1u, tempstr, 3, 0);
  AddSLine(3);
  AddSLine(21);
  S_ScrollSBuy(stextsval);
  AddSText(0, 22, 1u, "Back", 0, 0);
  OffsetSTextY(22, 6);
  storenumh = 0;
  for ( i = 0; smithitem[i]._itype != -1; ++i )
    ++storenumh;
  stextsmax = storenumh - 4;
  if ( storenumh - 4 < 0 )
    stextsmax = 0;
  if ( !storenumh )
    StartStore(1);
}

//----- (0042F601) --------------------------------------------------------
void __fastcall S_ScrollSPBuy(int idx)
{
  int v1; // [esp+Ch] [ebp-10h]
  int clr; // [esp+10h] [ebp-Ch]
  int y; // [esp+14h] [ebp-8h]

  v1 = idx;
  ClearSText(5, 21);
  stextup = 5;
  for ( y = 5; y < 20 && v1 < 6; y += 4 )
  {
    if ( premiumitem[v1]._itype == -1 )
    {
      if ( v1 < 6 )
        y -= 4;
    }
    else
    {
      LOBYTE(clr) = 0;
      if ( premiumitem[v1]._iMagical )
        LOBYTE(clr) = 1;
      if ( !premiumitem[v1]._iStatFlag )
        LOBYTE(clr) = 2;
      AddSText(20, y, 0, premiumitem[v1]._iIName, clr, 1);
      AddSTextVal(y, premiumitem[v1]._iIvalue);
      PrintStoreItem(&premiumitem[v1], y + 1, clr);
      stextdown = y;
    }
    ++v1;
  }
  if ( !stext[stextsel]._ssel && stextsel != 22 )
    stextsel = stextdown;
}

//----- (0042F77A) --------------------------------------------------------
void __cdecl S_StartSPBuy()
{
  signed int i; // [esp+Ch] [ebp-4h]

  stextsize = 1;
  stextscrl = 1;
  stextsval = 0;
  sprintf(tempstr, "I have these premium items for sale :   Your gold : %i", plr[myplr]._pGold);
  AddSText(0, 1, 1u, tempstr, 3, 0);
  AddSLine(3);
  AddSLine(21);
  AddSText(0, 22, 1u, "Back", 0, 0);
  OffsetSTextY(22, 6);
  storenumh = 0;
  for ( i = 0; i < 6; ++i )
  {
    if ( premiumitem[i]._itype != -1 )
      ++storenumh;
  }
  stextsmax = storenumh - 4;
  if ( storenumh - 4 < 0 )
    stextsmax = 0;
  S_ScrollSBuy(stextsval);
  if ( !storenumh )
    StartStore(1);
}

//----- (0042F8BA) --------------------------------------------------------
BOOL __fastcall SmithSellOk(int i)
{
  switch ( plr[myplr].InvList[i]._itype )
  {
    case (int)0xFFFFFFFF:
      return 0;
    case 0:
      return 0;
    case 0xB:
      return 0;
    case 0xE:
      return 0;
    case 0xA:
      return 0;
  }
  if ( plr[myplr].InvList[i]._iMagical && plr[myplr].InvList[i]._iIdentified && !plr[myplr].InvList[i]._iIvalue )
    return 0;
  return 1;
}

//----- (0042FAB9) --------------------------------------------------------
void __fastcall S_ScrollSSell(int idx)
{
  int v1; // [esp+Ch] [ebp-18h]
  int clr; // [esp+10h] [ebp-14h]
  int y; // [esp+14h] [ebp-10h]

  v1 = idx;
  ClearSText(5, 21);
  stextup = 5;
  for ( y = 5; y < 20; y += 4 )
  {
    if ( storehold[v1]._itype != -1 )
    {
      LOBYTE(clr) = 0;
      if ( storehold[v1]._iMagical )
        LOBYTE(clr) = 1;
      if ( !storehold[v1]._iStatFlag )
        LOBYTE(clr) = 2;
      if ( storehold[v1]._iMagical && storehold[v1]._iIdentified )
      {
        AddSText(20, y, 0, storehold[v1]._iIName, clr, 1);
        AddSTextVal(y, storehold[v1]._iIvalue);
      }
      else
      {
        AddSText(20, y, 0, storehold[v1]._iName, clr, 1);
        AddSTextVal(y, storehold[v1]._ivalue);
      }
      PrintStoreItem(&storehold[v1], y + 1, clr);
      stextdown = y;
    }
    if ( storenumh > v1 )
      ++v1;
  }
  stextsmax = storenumh - 4;
  if ( storenumh - 4 < 0 )
    stextsmax = 0;
}

//----- (0042FCA1) --------------------------------------------------------
void __cdecl S_StartSSell()
{
  signed int i; // [esp+Ch] [ebp-8h]
  int ia; // [esp+Ch] [ebp-8h]
  signed int v2; // [esp+10h] [ebp-4h]

  stextsize = 1;
  v2 = 0;
  storenumh = 0;
  for ( i = 0; i < 40; ++i )
    storehold[i]._itype = -1;
  for ( ia = 0; plr[myplr]._pNumInv > ia; ++ia )
  {
    if ( SmithSellOk(ia) )
    {
      v2 = 1;
      qmemcpy(&storehold[storenumh], &plr[myplr].InvList[ia], sizeof(ItemStruct));
      if ( storehold[storenumh]._iMagical )
      {
        if ( storehold[storenumh]._iIdentified )
          storehold[storenumh]._ivalue = storehold[storenumh]._iIvalue;
      }
      storehold[storenumh]._ivalue >>= 2;
      storehold[storenumh]._iIvalue = storehold[storenumh]._ivalue;
      storehidx[storenumh++] = ia;
    }
  }
  if ( v2 )
  {
    stextscrl = 1;
    stextsval = 0;
    stextsmax = plr[myplr]._pNumInv;
    sprintf(tempstr, "Which item is for sale?            Your gold : %i", plr[myplr]._pGold);
    AddSText(0, 1, 1u, tempstr, 3, 0);
    AddSLine(3);
    AddSLine(21);
    S_ScrollSSell(stextsval);
    AddSText(0, 22, 1u, "Back", 0, 1);
  }
  else
  {
    stextscrl = 0;
    sprintf(tempstr, "You have nothing I want.            Your gold : %i", plr[myplr]._pGold);
    AddSText(0, 1, 1u, tempstr, 3, 0);
    AddSLine(3);
    AddSLine(21);
    AddSText(0, 22, 1u, "Back", 0, 1);
  }
  OffsetSTextY(22, 6);
}

//----- (0042FFC7) --------------------------------------------------------
BOOL __fastcall SmithRepairOk(int i)
{
  switch ( plr[myplr].InvList[i]._itype )
  {
    case (int)0xFFFFFFFF:
      return 0;
    case 0:
      return 0;
    case 0xB:
      return 0;
    case 0xE:
      return 0;
  }
  return plr[myplr].InvList[i]._iMaxDur != plr[myplr].InvList[i]._iDurability;
}

//----- (00430147) --------------------------------------------------------
void __cdecl S_StartSRepair()
{
  signed int v0; // [esp+Ch] [ebp-8h]
  signed int i; // [esp+10h] [ebp-4h]
  int ia; // [esp+10h] [ebp-4h]

  stextsize = 1;
  v0 = 0;
  storenumh = 0;
  for ( i = 0; i < 40; ++i )
    storehold[i]._itype = -1;
  if ( plr[myplr].InvBody[0]._itype != -1 && plr[myplr].InvBody[0]._iMaxDur != plr[myplr].InvBody[0]._iDurability )
  {
    v0 = 1;
    AddStoreHoldRepair(plr[myplr].InvBody, -1);
  }
  if ( plr[myplr].InvBody[6]._itype != -1 && plr[myplr].InvBody[6]._iMaxDur != plr[myplr].InvBody[6]._iDurability )
  {
    v0 = 1;
    AddStoreHoldRepair(&plr[myplr].InvBody[6], -2);
  }
  if ( plr[myplr].InvBody[4]._itype != -1 && plr[myplr].InvBody[4]._iMaxDur != plr[myplr].InvBody[4]._iDurability )
  {
    v0 = 1;
    AddStoreHoldRepair(&plr[myplr].InvBody[4], -3);
  }
  if ( plr[myplr].InvBody[5]._itype != -1 && plr[myplr].InvBody[5]._iMaxDur != plr[myplr].InvBody[5]._iDurability )
  {
    v0 = 1;
    AddStoreHoldRepair(&plr[myplr].InvBody[5], -4);
  }
  for ( ia = 0; plr[myplr]._pNumInv > ia; ++ia )
  {
    if ( SmithRepairOk(ia) )
    {
      v0 = 1;
      AddStoreHoldRepair(&plr[myplr].InvList[ia], ia);
    }
  }
  if ( v0 )
  {
    stextscrl = 1;
    stextsval = 0;
    stextsmax = plr[myplr]._pNumInv;
    sprintf(tempstr, "Repair which item?            Your gold : %i", plr[myplr]._pGold);
    AddSText(0, 1, 1u, tempstr, 3, 0);
    AddSLine(3);
    AddSLine(21);
    S_ScrollSSell(stextsval);
    AddSText(0, 22, 1u, "Back", 0, 1);
  }
  else
  {
    stextscrl = 0;
    sprintf(tempstr, "You have nothing to repair.            Your gold : %i", plr[myplr]._pGold);
    AddSText(0, 1, 1u, tempstr, 3, 0);
    AddSLine(3);
    AddSLine(21);
    AddSText(0, 22, 1u, "Back", 0, 1);
  }
  OffsetSTextY(22, 6);
}

//----- (00430601) --------------------------------------------------------
void __fastcall AddStoreHoldRepair(ItemStruct *itm, int i)
{
  signed int v2; // [esp+14h] [ebp-4h]

  qmemcpy(&storehold[storenumh], itm, sizeof(ItemStruct));
  if ( storehold[storenumh]._iMagical && storehold[storenumh]._iIdentified )
    storehold[storenumh]._ivalue = storehold[storenumh]._iIvalue >> 1;
  v2 = 100
     * (storehold[storenumh]._iMaxDur - storehold[storenumh]._iDurability)
     / storehold[storenumh]._iMaxDur
     * storehold[storenumh]._ivalue
     / 100;
  if ( !v2 )
  {
    if ( storehold[storenumh]._iMagical && storehold[storenumh]._iIdentified )
      return;
    v2 = 1;
  }
  if ( v2 > 1 )
    v2 >>= 1;
  storehold[storenumh]._ivalue = v2;
  storehold[storenumh]._iIvalue = v2;
  storehidx[storenumh++] = i;
}

//----- (004307C8) --------------------------------------------------------
void __cdecl S_StartWitch()
{
  stextsize = 0;
  stextscrl = 0;
  AddSText(0, 2, 1u, "Witch's shack", 3, 0);
  AddSText(0, 9, 1u, "Would you like to:", 3, 0);
  AddSText(0, 12, 1u, "Buy items", 0, 1);
  AddSText(0, 14, 1u, "Sell items", 0, 1);
  AddSText(0, 16, 1u, "Recharge staves", 0, 1);
  AddSText(0, 18, 1u, "Leave the shack", 0, 1);
  AddSLine(5);
  storenumh = 20;
}

//----- (00430887) --------------------------------------------------------
void __fastcall S_ScrollWBuy(int idx)
{
  int v1; // [esp+Ch] [ebp-14h]
  int clr; // [esp+10h] [ebp-10h]
  int y; // [esp+14h] [ebp-Ch]

  v1 = idx;
  ClearSText(5, 21);
  stextup = 5;
  for ( y = 5; y < 20; y += 4 )
  {
    if ( witchitem[v1]._itype != -1 )
    {
      LOBYTE(clr) = 0;
      if ( witchitem[v1]._iMagical )
        LOBYTE(clr) = 1;
      if ( !witchitem[v1]._iStatFlag )
        LOBYTE(clr) = 2;
      if ( witchitem[v1]._iMagical )
        AddSText(20, y, 0, witchitem[v1]._iIName, clr, 1);
      else
        AddSText(20, y, 0, witchitem[v1]._iName, clr, 1);
      AddSTextVal(y, witchitem[v1]._iIvalue);
      PrintStoreItem(&witchitem[v1], y + 1, clr);
      stextdown = y;
      ++v1;
    }
  }
  if ( !stext[stextsel]._ssel && stextsel != 22 )
    stextsel = stextdown;
}

//----- (00430A38) --------------------------------------------------------
void __cdecl S_StartWBuy()
{
  int i; // [esp+Ch] [ebp-4h]

  stextsize = 1;
  stextscrl = 1;
  stextsval = 0;
  stextsmax = 20;
  sprintf(tempstr, "I have these items for sale :           Your gold : %i", plr[myplr]._pGold);
  AddSText(0, 1, 1u, tempstr, 3, 0);
  AddSLine(3);
  AddSLine(21);
  S_ScrollWBuy(stextsval);
  AddSText(0, 22, 1u, "Back", 0, 0);
  OffsetSTextY(22, 6);
  storenumh = 0;
  for ( i = 0; witchitem[i]._itype != -1; ++i )
    ++storenumh;
  stextsmax = storenumh - 4;
  if ( storenumh - 4 < 0 )
    stextsmax = 0;
}

//----- (00430B61) --------------------------------------------------------
BOOL __fastcall WitchSellOk(int i)
{
  BOOL v2; // [esp+10h] [ebp-4h]

  v2 = 0;
  if ( !plr[myplr].InvList[i]._itype )
    v2 = 1;
  if ( plr[myplr].InvList[i]._itype == 10 )
    v2 = 1;
  if ( plr[myplr].InvList[i]._iMagical && plr[myplr].InvList[i]._iIdentified && !plr[myplr].InvList[i]._iIvalue )
    v2 = 0;
  return v2;
}

//----- (00430CAB) --------------------------------------------------------
void __cdecl S_StartWSell()
{
  signed int i; // [esp+Ch] [ebp-8h]
  int ia; // [esp+Ch] [ebp-8h]
  signed int v2; // [esp+10h] [ebp-4h]

  stextsize = 1;
  v2 = 0;
  storenumh = 0;
  for ( i = 0; i < 40; ++i )
    storehold[i]._itype = -1;
  for ( ia = 0; plr[myplr]._pNumInv > ia; ++ia )
  {
    if ( WitchSellOk(ia) )
    {
      v2 = 1;
      qmemcpy(&storehold[storenumh], &plr[myplr].InvList[ia], sizeof(ItemStruct));
      if ( storehold[storenumh]._iMagical )
      {
        if ( storehold[storenumh]._iIdentified )
          storehold[storenumh]._ivalue = storehold[storenumh]._iIvalue;
      }
      storehold[storenumh]._ivalue >>= 2;
      storehold[storenumh]._iIvalue = storehold[storenumh]._ivalue;
      storehidx[storenumh++] = ia;
    }
  }
  if ( v2 )
  {
    stextscrl = 1;
    stextsval = 0;
    stextsmax = plr[myplr]._pNumInv;
    sprintf(tempstr, "Which item is for sale?            Your gold : %i", plr[myplr]._pGold);
    AddSText(0, 1, 1u, tempstr, 3, 0);
    AddSLine(3);
    AddSLine(21);
    S_ScrollSSell(stextsval);
    AddSText(0, 22, 1u, "Back", 0, 1);
  }
  else
  {
    stextscrl = 0;
    sprintf(tempstr, "You have nothing I want.            Your gold : %i", plr[myplr]._pGold);
    AddSText(0, 1, 1u, tempstr, 3, 0);
    AddSLine(3);
    AddSLine(21);
    AddSText(0, 22, 1u, "Back", 0, 1);
  }
  OffsetSTextY(22, 6);
}

//----- (00430FD1) --------------------------------------------------------
BOOL __fastcall WitchRechargeOk(int i)
{
  BOOL v2; // [esp+10h] [ebp-4h]

  v2 = 0;
  if ( plr[myplr].InvList[i]._itype == 10 && plr[myplr].InvList[i]._iCharges != plr[myplr].InvList[i]._iMaxCharges )
    v2 = 1;
  return v2;
}

//----- (00431093) --------------------------------------------------------
void __fastcall AddStoreHoldRecharge(ItemStruct itm, int i, int pnum)
{
  qmemcpy(&storehold[storenumh], &itm, sizeof(ItemStruct));
  if ( storehold[storenumh]._iMagical && storehold[storenumh]._iIdentified )
    storehold[storenumh]._ivalue = storehold[storenumh]._iIvalue;
  storehold[storenumh]._ivalue = 100
                               * (storehold[storenumh]._iMaxCharges - storehold[storenumh]._iCharges)
                               / storehold[storenumh]._iMaxCharges
                               * storehold[storenumh]._ivalue
                               / 100 >> 1;
  storehold[storenumh]._iIvalue = storehold[storenumh]._ivalue;
  storehidx[storenumh++] = i;
}

//----- (00431202) --------------------------------------------------------
void __cdecl S_StartWRecharge()
{
  ItemStruct v0; // [esp-170h] [ebp-184h]
  int i; // [esp+Ch] [ebp-8h]
  int v2; // [esp+10h] [ebp-4h]

  stextsize = 1;
  v2 = 0;
  storenumh = 0;
  for ( i = 0; i < 40; ++i )
    storehold[i]._itype = -1;
  if ( plr[myplr].InvBody[4]._itype != -1 && plr[myplr].InvBody[4]._iCharges != plr[myplr].InvBody[4]._iMaxCharges )
  {
    v2 = 1;
    qmemcpy(&v0, &plr[myplr].InvBody[4], sizeof(v0));
    AddStoreHoldRecharge(v0, -1, myplr);
  }
  for ( i = 0; plr[myplr]._pNumInv > i; ++i )
  {
    if ( WitchRechargeOk(i) )
    {
      v2 = 1;
      qmemcpy(&v0, &plr[myplr].InvList[i], sizeof(v0));
      AddStoreHoldRecharge(v0, i, myplr);
    }
  }
  if ( v2 )
  {
    stextscrl = 1;
    stextsval = 0;
    stextsmax = plr[myplr]._pNumInv;
    v0.Xgold_unused = plr[myplr]._pGold;
    sprintf(tempstr, "Recharge which item?            Your gold : %i", v0.Xgold_unused);
    AddSText(0, 1, 1u, tempstr, 3, 0);
    AddSLine(3);
    AddSLine(21);
    S_ScrollSSell(stextsval);
    AddSText(0, 22, 1u, "Back", 0, 1);
  }
  else
  {
    stextscrl = 0;
    v0.Xgold_unused = plr[myplr]._pGold;
    sprintf(tempstr, "You have nothing to recharge.            Your gold : %i", v0.Xgold_unused);
    AddSText(0, 1, 1u, tempstr, 3, 0);
    AddSLine(3);
    AddSLine(21);
    AddSText(0, 22, 1u, "Back", 0, 1);
  }
  OffsetSTextY(22, 6);
}

//----- (00431509) --------------------------------------------------------
void __cdecl S_StartNoMoney()
{
  StartStore(stextshold);
  stextsize = 1;
  stextscrl = 0;
  ClearSText(5, 23);
  AddSText(0, 14, 1u, "You do not have enough gold", 0, 1);
}

//----- (0043155B) --------------------------------------------------------
void __cdecl S_StartNoRoom()
{
  StartStore(stextshold);
  stextscrl = 0;
  ClearSText(5, 23);
  AddSText(0, 14, 1u, "You do not have enough room in inventory", 0, 1);
}

//----- (004315A6) --------------------------------------------------------
void __cdecl S_StartConfirm()
{
  BOOL v0; // [esp+10h] [ebp-8h]
  int clr; // [esp+14h] [ebp-4h]

  StartStore(stextshold);
  stextscrl = 0;
  ClearSText(5, 23);
  LOBYTE(clr) = 0;
  if ( plr[myplr].HoldItem._iMagical )
    LOBYTE(clr) = 1;
  if ( !plr[myplr].HoldItem._iStatFlag )
    LOBYTE(clr) = 2;
  v0 = plr[myplr].HoldItem._iMagical != 0;
  if ( stextshold == 17 )
    v0 = 0;
  if ( plr[myplr].HoldItem._iMagical && !plr[myplr].HoldItem._iIdentified )
  {
    if ( stextshold == 3 )
      v0 = 0;
    if ( stextshold == 7 )
      v0 = 0;
    if ( stextshold == 4 )
      v0 = 0;
    if ( stextshold == 8 )
      v0 = 0;
  }
  if ( v0 )
    AddSText(20, 8, 0, plr[myplr].HoldItem._iIName, clr, 0);
  else
    AddSText(20, 8, 0, plr[myplr].HoldItem._iName, clr, 0);
  AddSTextVal(8, plr[myplr].HoldItem._iIvalue);
  PrintStoreItem(&plr[myplr].HoldItem, 9, clr);
  switch ( stextshold )
  {
    case 2:
    case 6:
    case 16:
    case 18:
      strcpy(tempstr, "Are you sure you want to buy this item?");
      break;
    case 3:
    case 7:
      strcpy(tempstr, "Are you sure you want to sell this item?");
      break;
    case 4:
      strcpy(tempstr, "Are you sure you want to repair this item?");
      break;
    case 8:
      strcpy(tempstr, "Are you sure you want to recharge this item?");
      break;
    case 13:
      strcpy(tempstr, "Do we have a deal?");
      break;
    case 17:
      strcpy(tempstr, "Are you sure you want to identify this item?");
      break;
    default:
      break;
  }
  AddSText(0, 15, 1u, tempstr, 0, 0);
  AddSText(0, 18, 1u, "Yes", 0, 1);
  AddSText(0, 20, 1u, "No", 0, 1);
}

//----- (0043193F) --------------------------------------------------------
void __cdecl S_StartBoy()
{
  stextsize = 0;
  stextscrl = 0;
  AddSText(0, 2, 1u, "Pegged leg boy", 3, 0);
  AddSLine(5);
  if ( boyitem._itype == -1 )
  {
    AddSText(0, 12, 1u, "I have nothing for you.", 3, 0);
    AddSText(0, 16, 1u, "Leave", 0, 1);
  }
  else
  {
    AddSText(0, 8, 1u, "Pssst. Over here.", 3, 0);
    AddSText(0, 10, 1u, "I have something for sale.", 3, 0);
    AddSText(0, 12, 1u, "It will cost 50 gold", 3, 0);
    AddSText(0, 14, 1u, "just to start looking. ", 3, 0);
    AddSText(0, 18, 1u, "Yes, I would like to look", 0, 1);
    AddSText(0, 20, 1u, "No, I'll pass", 0, 1);
  }
}

//----- (00431A4B) --------------------------------------------------------
void __cdecl S_StartBBoy()
{
  signed int clr; // [esp+Ch] [ebp-4h]

  stextsize = 1;
  stextscrl = 0;
  sprintf(tempstr, "I have this item for sale :           Your gold : %i", plr[myplr]._pGold);
  AddSText(0, 1, 1u, tempstr, 3, 0);
  AddSLine(3);
  AddSLine(21);
  clr = 0;
  if ( boyitem._iMagical )
    clr = 1;
  if ( !boyitem._iStatFlag )
    clr = 2;
  if ( boyitem._iMagical )
    AddSText(20, 10, 0, boyitem._iIName, clr, 1);
  else
    AddSText(20, 10, 0, boyitem._iName, clr, 1);
  AddSTextVal(10, boyitem._iIvalue + (boyitem._iIvalue >> 1));
  PrintStoreItem(&boyitem, 11, clr);
  AddSText(0, 22, 1u, "Leave", 0, 1);
  OffsetSTextY(22, 6);
}

//----- (00431BA3) --------------------------------------------------------
void __cdecl S_StartHealer()
{
  stextsize = 0;
  stextscrl = 0;
  AddSText(0, 1, 1u, "Welcome to the", 3, 0);
  AddSText(0, 3, 1u, "Healer's temple", 3, 0);
  AddSText(0, 9, 1u, "Would you like to:", 3, 0);
  AddSText(0, 12, 1u, "Heal Yourself", 0, 1);
  AddSText(0, 14, 1u, "Buy items", 0, 1);
  AddSText(0, 18, 1u, "Leave the shop", 0, 1);
  AddSLine(5);
  storenumh = 20;
}

//----- (00431C62) --------------------------------------------------------
void __fastcall S_ScrollHBuy(int idx)
{
  int v1; // [esp+Ch] [ebp-10h]
  int clr; // [esp+10h] [ebp-Ch]
  int y; // [esp+14h] [ebp-8h]

  v1 = idx;
  ClearSText(5, 21);
  stextup = 5;
  for ( y = 5; y < 20; y += 4 )
  {
    if ( healitem[v1]._itype != -1 )
    {
      LOBYTE(clr) = 0;
      if ( !healitem[v1]._iStatFlag )
        LOBYTE(clr) = 2;
      AddSText(20, y, 0, healitem[v1]._iName, clr, 1);
      AddSTextVal(y, healitem[v1]._iIvalue);
      PrintStoreItem(&healitem[v1], y + 1, clr);
      stextdown = y;
      ++v1;
    }
  }
  if ( !stext[stextsel]._ssel && stextsel != 22 )
    stextsel = stextdown;
}

//----- (00431D9D) --------------------------------------------------------
void __cdecl S_StartHBuy()
{
  int i; // [esp+Ch] [ebp-4h]

  stextsize = 1;
  stextscrl = 1;
  stextsval = 0;
  sprintf(tempstr, "I have these items for sale :           Your gold : %i", plr[myplr]._pGold);
  AddSText(0, 1, 1u, tempstr, 3, 0);
  AddSLine(3);
  AddSLine(21);
  S_ScrollHBuy(stextsval);
  AddSText(0, 22, 1u, "Back", 0, 0);
  OffsetSTextY(22, 6);
  storenumh = 0;
  for ( i = 0; healitem[i]._itype != -1; ++i )
    ++storenumh;
  stextsmax = storenumh - 4;
  if ( storenumh - 4 < 0 )
    stextsmax = 0;
}

//----- (00431EBC) --------------------------------------------------------
void __cdecl S_StartStory()
{
  stextsize = 0;
  stextscrl = 0;
  AddSText(0, 2, 1u, "Town Elder", 3, 0);
  AddSText(0, 9, 1u, "Would you like to:", 3, 0);
  AddSText(0, 12, 1u, "Identify an item", 0, 1);
  AddSText(0, 18, 1u, "Talk to me later", 0, 1);
  AddSLine(5);
}

//----- (00431F43) --------------------------------------------------------
BOOL __fastcall IdItemOk(ItemStruct *i)
{
  if ( i->_itype == -1 )
    return 0;
  if ( i->_iMagical )
    return i->_iIdentified == 0;
  return 0;
}

//----- (00431F9C) --------------------------------------------------------
void __fastcall AddStoreHoldId(ItemStruct itm, int i)
{
  qmemcpy(&storehold[storenumh], &itm, sizeof(ItemStruct));
  storehold[storenumh]._ivalue = 100;
  storehold[storenumh]._iIvalue = 100;
  storehidx[storenumh++] = i;
}

//----- (0043201D) --------------------------------------------------------
void __cdecl S_StartSIdentify()
{
  ItemStruct v0; // [esp-170h] [ebp-184h]
  int v1; // [esp-4h] [ebp-18h]
  int i; // [esp+Ch] [ebp-8h]
  int v3; // [esp+10h] [ebp-4h]

  stextsize = 1;
  v3 = 0;
  storenumh = 0;
  for ( i = 0; i < 40; ++i )
    storehold[i]._itype = -1;
  if ( IdItemOk(plr[myplr].InvBody) )
  {
    v3 = 1;
    qmemcpy(&v0, plr[myplr].InvBody, sizeof(v0));
    AddStoreHoldId(v0, -1);
  }
  if ( IdItemOk(&plr[myplr].InvBody[6]) )
  {
    v3 = 1;
    qmemcpy(&v0, &plr[myplr].InvBody[6], sizeof(v0));
    AddStoreHoldId(v0, -2);
  }
  if ( IdItemOk(&plr[myplr].InvBody[4]) )
  {
    v3 = 1;
    qmemcpy(&v0, &plr[myplr].InvBody[4], sizeof(v0));
    AddStoreHoldId(v0, -3);
  }
  if ( IdItemOk(&plr[myplr].InvBody[5]) )
  {
    v3 = 1;
    qmemcpy(&v0, &plr[myplr].InvBody[5], sizeof(v0));
    AddStoreHoldId(v0, -4);
  }
  if ( IdItemOk(&plr[myplr].InvBody[1]) )
  {
    v3 = 1;
    qmemcpy(&v0, &plr[myplr].InvBody[1], sizeof(v0));
    AddStoreHoldId(v0, -5);
  }
  if ( IdItemOk(&plr[myplr].InvBody[2]) )
  {
    v3 = 1;
    qmemcpy(&v0, &plr[myplr].InvBody[2], sizeof(v0));
    AddStoreHoldId(v0, -6);
  }
  if ( IdItemOk(&plr[myplr].InvBody[3]) )
  {
    v3 = 1;
    qmemcpy(&v0, &plr[myplr].InvBody[3], sizeof(v0));
    AddStoreHoldId(v0, -7);
  }
  for ( i = 0; plr[myplr]._pNumInv > i; ++i )
  {
    if ( IdItemOk(&plr[myplr].InvList[i]) )
    {
      v3 = 1;
      qmemcpy(&v0, &plr[myplr].InvList[i], sizeof(v0));
      AddStoreHoldId(v0, i);
    }
  }
  if ( v3 )
  {
    stextscrl = 1;
    stextsval = 0;
    stextsmax = plr[myplr]._pNumInv;
    v1 = plr[myplr]._pGold;
    sprintf(tempstr, "Identify which item?            Your gold : %i", v1);
    AddSText(0, 1, 1u, tempstr, 3, 0);
    AddSLine(3);
    AddSLine(21);
    S_ScrollSSell(stextsval);
    AddSText(0, 22, 1u, "Back", 0, 1);
  }
  else
  {
    stextscrl = 0;
    v1 = plr[myplr]._pGold;
    sprintf(tempstr, "You have nothing to identify.            Your gold : %i", v1);
    AddSText(0, 1, 1u, tempstr, 3, 0);
    AddSLine(3);
    AddSLine(21);
    AddSText(0, 22, 1u, "Back", 0, 1);
  }
  OffsetSTextY(22, 6);
}

//----- (00432594) --------------------------------------------------------
void __fastcall StartStore(char s)
{
  signed int i; // [esp+14h] [ebp-4h]

  sbookflag = 0;
  invflag = 0;
  chrflag = 0;
  questlog = 0;
  dropGoldFlag = 0;
  ClearSText(0, 24);
  ReleaseStoreBtn();
  switch ( s )
  {
    case 1:
      S_StartSmith();
      break;
    case 2:
      if ( storenumh > 0 )
        S_StartSBuy();
      break;
    case 3:
      S_StartSSell();
      break;
    case 4:
      S_StartSRepair();
      break;
    case 5:
      S_StartWitch();
      break;
    case 6:
      if ( storenumh > 0 )
        S_StartWBuy();
      break;
    case 7:
      S_StartWSell();
      break;
    case 8:
      S_StartWRecharge();
      break;
    case 9:
      S_StartNoMoney();
      break;
    case 10:
      S_StartNoRoom();
      break;
    case 11:
      S_StartConfirm();
      break;
    case 12:
      S_StartBoy();
      break;
    case 13:
      S_StartBBoy();
      break;
    case 14:
      S_StartHealer();
      break;
    case 15:
      S_StartStory();
      break;
    case 16:
      if ( storenumh > 0 )
        S_StartHBuy();
      break;
    case 17:
      S_StartSIdentify();
      break;
    case 18:
      if ( storenumh > 0 )
        S_StartSPBuy();
      break;
    default:
      break;
  }
  for ( i = 0; i < 24 && !stext[i]._ssel; ++i )
    ;
  if ( i == 24 )
    stextsel = -1;
  else
    stextsel = i;
  stextflag = s;
}

//----- (004327A7) --------------------------------------------------------
void __cdecl DrawSText()
{
  int y; // [esp+10h] [ebp-4h]

  if ( stextsize )
    DrawQTextBack();
  else
    DrawSTextBack();
  if ( stextscrl )
  {
    switch ( stextflag )
    {
      case 2:
        S_ScrollSBuy(stextsval);
        break;
      case 3:
      case 4:
      case 7:
      case 8:
      case 17:
        S_ScrollSSell(stextsval);
        break;
      case 6:
        S_ScrollWBuy(stextsval);
        break;
      case 16:
        S_ScrollHBuy(stextsval);
        break;
      case 18:
        S_ScrollSPBuy(stextsval);
        break;
      default:
        break;
    }
  }
  for ( y = 0; y < 24; ++y )
  {
    if ( stext[y]._sline )
      DrawSLine(y);
    if ( stext[y]._sstr[0] )
      PrintSString(stext[y]._sx, y, stext[y]._sjust, stext[y]._sstr, stext[y]._sclr, stext[y]._sval);
  }
  if ( stextscrl )
    DrawSArrows(4, 20);
  InStoreFlag = (InStoreFlag & 7) + 1;
}

//----- (00432995) --------------------------------------------------------
void __cdecl STextESC()
{
  switch ( stextflag )
  {
    case 1:
    case 5:
    case 12:
    case 13:
    case 14:
    case 15:
      stextflag = 0;
      break;
    case 2:
      StartStore(1);
      stextsel = 12;
      break;
    case 3:
      StartStore(1);
      stextsel = 16;
      break;
    case 4:
      StartStore(1);
      stextsel = 18;
      break;
    case 6:
      StartStore(5);
      stextsel = 12;
      break;
    case 7:
      StartStore(5);
      stextsel = 14;
      break;
    case 8:
      StartStore(5);
      stextsel = 16;
      break;
    case 9:
    case 10:
    case 11:
      StartStore(stextshold);
      stextsel = stextlhold;
      stextsval = stextvhold;
      break;
    case 16:
      StartStore(14);
      stextsel = 14;
      break;
    case 17:
      StartStore(15);
      stextsel = 12;
      break;
    case 18:
      StartStore(1);
      stextsel = 14;
      break;
    default:
      return;
  }
}

//----- (00432B2C) --------------------------------------------------------
void __cdecl STextUp()
{
  PlaySFX(41);
  if ( stextsel != -1 )
  {
    if ( stextscrl )
    {
      if ( stextup == stextsel )
      {
        if ( stextsval )
          --stextsval;
      }
      else
      {
        --stextsel;
        while ( !stext[stextsel]._ssel )
        {
          if ( stextsel )
            --stextsel;
          else
            stextsel = 23;
        }
      }
    }
    else
    {
      if ( stextsel )
        --stextsel;
      else
        stextsel = 23;
      while ( !stext[stextsel]._ssel )
      {
        if ( stextsel )
          --stextsel;
        else
          stextsel = 23;
      }
    }
  }
}

//----- (00432C3E) --------------------------------------------------------
void __cdecl STextDown()
{
  PlaySFX(41);
  if ( stextsel != -1 )
  {
    if ( stextscrl )
    {
      if ( stextdown == stextsel )
      {
        if ( stextsmax > stextsval )
          ++stextsval;
      }
      else
      {
        ++stextsel;
        while ( !stext[stextsel]._ssel )
        {
          if ( stextsel == 23 )
            stextsel = 0;
          else
            ++stextsel;
        }
      }
    }
    else
    {
      if ( stextsel == 23 )
        stextsel = 0;
      else
        ++stextsel;
      while ( !stext[stextsel]._ssel )
      {
        if ( stextsel == 23 )
          stextsel = 0;
        else
          ++stextsel;
      }
    }
  }
}

//----- (00432D54) --------------------------------------------------------
void __cdecl S_SmithEnter()
{
  switch ( stextsel )
  {
    case 12:
      StartStore(2);
      break;
    case 14:
      StartStore(18);
      break;
    case 16:
      StartStore(3);
      break;
    case 18:
      StartStore(4);
      break;
    case 20:
      stextflag = 0;
      break;
    default:
      return;
  }
}

//----- (00432DFD) --------------------------------------------------------
void __fastcall SetGoldCurs(int pnum, int i)
{
  if ( plr[pnum].InvList[i]._ivalue < 2500 )
  {
    if ( plr[pnum].InvList[i]._ivalue > 1000 )
      plr[pnum].InvList[i]._iCurs = 5;
    else
      plr[pnum].InvList[i]._iCurs = 4;
  }
  else
  {
    plr[pnum].InvList[i]._iCurs = 6;
  }
}

//----- (00432F21) --------------------------------------------------------
void __fastcall SetSpdbarGoldCurs(int pnum, int i)
{
  if ( plr[pnum].SpdList[i]._ivalue < 2500 )
  {
    if ( plr[pnum].SpdList[i]._ivalue > 1000 )
      plr[pnum].SpdList[i]._iCurs = 5;
    else
      plr[pnum].SpdList[i]._iCurs = 4;
  }
  else
  {
    plr[pnum].SpdList[i]._iCurs = 6;
  }
}

//----- (00433045) --------------------------------------------------------
void __fastcall TakePlrsMoney(int cost)
{
  int v1; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]
  int ia; // [esp+10h] [ebp-4h]
  int ib; // [esp+10h] [ebp-4h]
  int ic; // [esp+10h] [ebp-4h]

  v1 = cost;
  plr[myplr]._pGold = CalculateGold(myplr) - cost;
  for ( i = 0; i < 8 && v1 > 0; ++i )
  {
    if ( plr[myplr].SpdList[i]._itype == 11 && plr[myplr].SpdList[i]._ivalue != 5000 )
    {
      if ( plr[myplr].SpdList[i]._ivalue <= v1 )
      {
        v1 -= plr[myplr].SpdList[i]._ivalue;
        RemoveSpdBarItem(myplr, i);
        i = -1;
      }
      else
      {
        plr[myplr].SpdList[i]._ivalue -= v1;
        SetSpdbarGoldCurs(myplr, i);
        v1 = 0;
      }
    }
  }
  if ( v1 > 0 )
  {
    for ( ia = 0; ia < 8 && v1 > 0; ++ia )
    {
      if ( plr[myplr].SpdList[ia]._itype == 11 )
      {
        if ( plr[myplr].SpdList[ia]._ivalue <= v1 )
        {
          v1 -= plr[myplr].SpdList[ia]._ivalue;
          RemoveSpdBarItem(myplr, ia);
          ia = -1;
        }
        else
        {
          plr[myplr].SpdList[ia]._ivalue -= v1;
          SetSpdbarGoldCurs(myplr, ia);
          v1 = 0;
        }
      }
    }
  }
  drawpanflag = 255;
  if ( v1 > 0 )
  {
    for ( ib = 0; plr[myplr]._pNumInv > ib && v1 > 0; ++ib )
    {
      if ( plr[myplr].InvList[ib]._itype == 11 && plr[myplr].InvList[ib]._ivalue != 5000 )
      {
        if ( plr[myplr].InvList[ib]._ivalue <= v1 )
        {
          v1 -= plr[myplr].InvList[ib]._ivalue;
          RemoveInvItem(myplr, ib);
          ib = -1;
        }
        else
        {
          plr[myplr].InvList[ib]._ivalue -= v1;
          SetGoldCurs(myplr, ib);
          v1 = 0;
        }
      }
    }
    if ( v1 > 0 )
    {
      for ( ic = 0; plr[myplr]._pNumInv > ic && v1 > 0; ++ic )
      {
        if ( plr[myplr].InvList[ic]._itype == 11 )
        {
          if ( plr[myplr].InvList[ic]._ivalue <= v1 )
          {
            v1 -= plr[myplr].InvList[ic]._ivalue;
            RemoveInvItem(myplr, ic);
            ic = -1;
          }
          else
          {
            plr[myplr].InvList[ic]._ivalue -= v1;
            SetGoldCurs(myplr, ic);
            v1 = 0;
          }
        }
      }
    }
  }
}

//----- (00433635) --------------------------------------------------------
void __cdecl SmithBuyItem()
{
  int ii; // [esp+Ch] [ebp-Ch]
  int v1; // [esp+10h] [ebp-8h]
  int v2; // [esp+14h] [ebp-4h]

  TakePlrsMoney(plr[myplr].HoldItem._iIvalue);
  SetCursor(plr[myplr].HoldItem._iCurs + 12);
  if ( !plr[myplr].HoldItem._iMagical )
    plr[myplr].HoldItem._iIdentified = 0;
  v1 = 0;
  for ( ii = 0; ii < 40 && !v1; ++ii )
    v1 = AutoPlace(myplr, ii, cursW / 28, cursH / 28, 1);
  SetCursor(1);
  v2 = stextvhold + ((stextlhold - stextup) >> 2);
  if ( v2 == 19 )
  {
    smithitem[19]._itype = -1;
  }
  else
  {
    while ( smithitem[v2 + 1]._itype != -1 )
    {
      qmemcpy(&smithitem[v2], &smithitem[v2 + 1], sizeof(ItemStruct));
      ++v2;
    }
    smithitem[v2]._itype = -1;
  }
}

//----- (004337F0) --------------------------------------------------------
void __cdecl S_SBuyEnter()
{
  int ii; // [esp+Ch] [ebp-Ch]
  int v1; // [esp+10h] [ebp-8h]

  if ( stextsel == 22 )
  {
    StartStore(1);
    stextsel = 12;
  }
  else
  {
    stextshold = 2;
    stextlhold = stextsel;
    stextvhold = stextsval;
    if ( smithitem[stextsval + ((stextsel - stextup) >> 2)]._iIvalue <= plr[myplr]._pGold )
    {
      qmemcpy(&plr[myplr].HoldItem, &smithitem[stextsval + ((stextsel - stextup) >> 2)], sizeof(plr[myplr].HoldItem));
      SetCursor(plr[myplr].HoldItem._iCurs + 12);
      v1 = 0;
      for ( ii = 0; ii < 40 && !v1; ++ii )
        v1 = AutoPlace(myplr, ii, cursW / 28, cursH / 28, 0);
      if ( v1 )
        StartStore(11);
      else
        StartStore(10);
      SetCursor(1);
    }
    else
    {
      StartStore(9);
    }
  }
}

//----- (00433994) --------------------------------------------------------
void __cdecl SmithBuyPItem()
{
  int v0; // [esp+Ch] [ebp-10h]
  int ii; // [esp+10h] [ebp-Ch]
  int iia; // [esp+10h] [ebp-Ch]
  int v3; // [esp+14h] [ebp-8h]
  int v4; // [esp+18h] [ebp-4h]

  TakePlrsMoney(plr[myplr].HoldItem._iIvalue);
  SetCursor(plr[myplr].HoldItem._iCurs + 12);
  if ( !plr[myplr].HoldItem._iMagical )
    plr[myplr].HoldItem._iIdentified = 0;
  v3 = 0;
  for ( ii = 0; ii < 40 && !v3; ++ii )
    v3 = AutoPlace(myplr, ii, cursW / 28, cursH / 28, 1);
  SetCursor(1);
  v0 = stextvhold + ((stextlhold - stextup) >> 2);
  v4 = 0;
  iia = 0;
  while ( v0 >= 0 )
  {
    if ( premiumitem[iia]._itype != -1 )
    {
      --v0;
      v4 = iia;
    }
    ++iia;
  }
  premiumitem[v4]._itype = -1;
}

//----- (00433B1D) --------------------------------------------------------
void __cdecl S_SPBuyEnter()
{
  int v0; // [esp+Ch] [ebp-10h]
  int ii; // [esp+10h] [ebp-Ch]
  int iia; // [esp+10h] [ebp-Ch]
  int v3; // [esp+14h] [ebp-8h]
  int v4; // [esp+18h] [ebp-4h]

  if ( stextsel == 22 )
  {
    StartStore(1);
    stextsel = 12;
  }
  else
  {
    stextshold = 18;
    stextlhold = stextsel;
    stextvhold = stextsval;
    v0 = stextsval + ((stextsel - stextup) >> 2);
    v4 = 0;
    ii = 0;
    while ( v0 >= 0 )
    {
      if ( premiumitem[ii]._itype != -1 )
      {
        --v0;
        v4 = ii;
      }
      ++ii;
    }
    if ( premiumitem[v4]._iIvalue <= plr[myplr]._pGold )
    {
      qmemcpy(&plr[myplr].HoldItem, &premiumitem[v4], sizeof(plr[myplr].HoldItem));
      SetCursor(plr[myplr].HoldItem._iCurs + 12);
      v3 = 0;
      for ( iia = 0; iia < 40 && !v3; ++iia )
        v3 = AutoPlace(myplr, iia, cursW / 28, cursH / 28, 0);
      if ( v3 )
        StartStore(11);
      else
        StartStore(10);
      SetCursor(1);
    }
    else
    {
      StartStore(9);
    }
  }
}

//----- (00433D0A) --------------------------------------------------------
BOOL __fastcall StoreGoldFit(int idx)
{
  int v2; // [esp+10h] [ebp-10h]
  signed int i; // [esp+14h] [ebp-Ch]
  int j; // [esp+14h] [ebp-Ch]
  int v5; // [esp+18h] [ebp-8h]
  int v6; // [esp+1Ch] [ebp-4h]
  int v7; // [esp+1Ch] [ebp-4h]

  v5 = storehold[idx]._iIvalue;
  v6 = v5 / 5000;
  if ( v5 % 5000 )
    ++v6;
  SetCursor(storehold[idx]._iCurs + 12);
  v2 = cursW / 28 * (cursH / 28);
  SetCursor(1);
  if ( v6 <= v2 )
    return 1;
  for ( i = 0; i < 40; ++i )
  {
    if ( !plr[myplr].InvGrid[i] )
      ++v2;
  }
  for ( j = 0; plr[myplr]._pNumInv > j; ++j )
  {
    if ( plr[myplr].InvList[j]._itype == 11 && plr[myplr].InvList[j]._ivalue != 5000 )
    {
      if ( v5 + plr[myplr].InvList[j]._ivalue > 5000 )
        v5 -= 5000 - plr[myplr].InvList[j]._ivalue;
      else
        v5 = 0;
    }
  }
  v7 = v5 / 5000;
  if ( v5 % 5000 )
    ++v7;
  return v7 <= v2;
}

//----- (00433F7C) --------------------------------------------------------
void __fastcall PlaceStoreGold(int v)
{
  int i; // ST14_4
  signed int v3; // [esp+18h] [ebp-Ch]
  signed int j; // [esp+20h] [ebp-4h]

  v3 = 0;
  for ( j = 0; j < 40 && !v3; ++j )
  {
    if ( !plr[myplr].InvGrid[10 * (j / 10) + j % 10] )
    {
      i = plr[myplr]._pNumInv;
      qmemcpy(&plr[myplr].InvList[i], &golditem, sizeof(plr[myplr].InvList[i]));
      ++plr[myplr]._pNumInv;
      plr[myplr].InvGrid[10 * (j / 10) + j % 10] = plr[myplr]._pNumInv;
      plr[myplr].InvList[i]._ivalue = v;
      SetGoldCurs(myplr, i);
      v3 = 1;
    }
  }
}

//----- (0043411B) --------------------------------------------------------
void __cdecl StoreSellItem()
{
  int i; // [esp+Ch] [ebp-Ch]
  signed int v; // [esp+10h] [ebp-8h]
  int v2; // [esp+14h] [ebp-4h]

  v2 = stextvhold + ((stextlhold - stextup) >> 2);
  RemoveInvItem(myplr, storehidx[v2]);
  v = storehold[v2]._iIvalue;
  if ( --storenumh != v2 )
  {
    while ( storenumh > v2 )
    {
      qmemcpy(&storehold[v2], &storehold[v2 + 1], sizeof(ItemStruct));
      storehidx[v2] = storehidx[v2 + 1];
      ++v2;
    }
  }
  plr[myplr]._pGold += v;
  for ( i = 0; plr[myplr]._pNumInv > i && v > 0; ++i )
  {
    if ( plr[myplr].InvList[i]._itype == 11 && plr[myplr].InvList[i]._ivalue != 5000 )
    {
      if ( v + plr[myplr].InvList[i]._ivalue > 5000 )
      {
        v -= 5000 - plr[myplr].InvList[i]._ivalue;
        plr[myplr].InvList[i]._ivalue = 5000;
        SetGoldCurs(myplr, i);
      }
      else
      {
        plr[myplr].InvList[i]._ivalue += v;
        SetGoldCurs(myplr, i);
        v = 0;
      }
    }
  }
  if ( v > 0 )
  {
    while ( v > 5000 )
    {
      PlaceStoreGold(5000);
      v -= 5000;
    }
    PlaceStoreGold(v);
  }
}

//----- (004343F9) --------------------------------------------------------
void __cdecl S_SSellEnter()
{
  int idx; // ST0C_4

  if ( stextsel == 22 )
  {
    StartStore(1);
    stextsel = 14;
  }
  else
  {
    stextshold = 3;
    stextlhold = stextsel;
    stextvhold = stextsval;
    idx = stextsval + ((stextsel - stextup) >> 2);
    qmemcpy(&plr[myplr].HoldItem, &storehold[stextsval + ((stextsel - stextup) >> 2)], sizeof(plr[myplr].HoldItem));
    if ( StoreGoldFit(idx) )
      StartStore(11);
    else
      StartStore(10);
  }
}

//----- (004344CB) --------------------------------------------------------
void __cdecl SmithRepairItem()
{
  int v0; // ST10_4
  int v1; // [esp+Ch] [ebp-8h]

  TakePlrsMoney(plr[myplr].HoldItem._iIvalue);
  v0 = stextvhold + ((stextlhold - stextup) >> 2);
  storehold[stextvhold + ((stextlhold - stextup) >> 2)]._iDurability = storehold[stextvhold
                                                                               + ((stextlhold - stextup) >> 2)]._iMaxDur;
  v1 = storehidx[v0];
  if ( v1 >= 0 )
  {
    plr[myplr].InvList[v1]._iDurability = plr[myplr].InvList[v1]._iMaxDur;
  }
  else
  {
    if ( v1 == -1 )
      plr[myplr].InvBody[0]._iDurability = plr[myplr].InvBody[0]._iMaxDur;
    if ( v1 == -2 )
      plr[myplr].InvBody[6]._iDurability = plr[myplr].InvBody[6]._iMaxDur;
    if ( v1 == -3 )
      plr[myplr].InvBody[4]._iDurability = plr[myplr].InvBody[4]._iMaxDur;
    if ( v1 == -4 )
      plr[myplr].InvBody[5]._iDurability = plr[myplr].InvBody[5]._iMaxDur;
  }
}

//----- (004346E0) --------------------------------------------------------
void __cdecl S_SRepairEnter()
{
  int v0; // ST0C_4

  if ( stextsel == 22 )
  {
    StartStore(1);
    stextsel = 16;
  }
  else
  {
    stextshold = 4;
    stextlhold = stextsel;
    stextvhold = stextsval;
    v0 = stextsval + ((stextsel - stextup) >> 2);
    qmemcpy(&plr[myplr].HoldItem, &storehold[stextsval + ((stextsel - stextup) >> 2)], sizeof(plr[myplr].HoldItem));
    if ( storehold[v0]._iIvalue <= plr[myplr]._pGold )
      StartStore(11);
    else
      StartStore(9);
  }
}

//----- (004347DC) --------------------------------------------------------
void __cdecl S_WitchEnter()
{
  switch ( stextsel )
  {
    case 12:
      StartStore(6);
      break;
    case 14:
      StartStore(7);
      break;
    case 16:
      StartStore(8);
      break;
    case 18:
      stextflag = 0;
      break;
    default:
      return;
  }
}

//----- (0043486E) --------------------------------------------------------
void __cdecl WitchBuyItem()
{
  int ii; // [esp+Ch] [ebp-Ch]
  int v1; // [esp+10h] [ebp-8h]
  int v2; // [esp+14h] [ebp-4h]

  v2 = stextvhold + ((stextlhold - stextup) >> 2);
  if ( v2 < 2 )
    plr[myplr].HoldItem._iSeed = GetRndSeed();
  TakePlrsMoney(plr[myplr].HoldItem._iIvalue);
  SetCursor(plr[myplr].HoldItem._iCurs + 12);
  v1 = 0;
  for ( ii = 0; ii < 40 && !v1; ++ii )
    v1 = AutoPlace(myplr, ii, cursW / 28, cursH / 28, 1);
  SetCursor(1);
  if ( v2 >= 2 )
  {
    if ( v2 == 19 )
    {
      witchitem[19]._itype = -1;
    }
    else
    {
      while ( witchitem[v2 + 1]._itype != -1 )
      {
        qmemcpy(&witchitem[v2], &witchitem[v2 + 1], sizeof(ItemStruct));
        ++v2;
      }
      witchitem[v2]._itype = -1;
    }
  }
}

//----- (00434A1C) --------------------------------------------------------
void __cdecl S_WBuyEnter()
{
  int ii; // [esp+Ch] [ebp-Ch]
  int v1; // [esp+10h] [ebp-8h]

  if ( stextsel == 22 )
  {
    StartStore(5);
    stextsel = 12;
  }
  else
  {
    stextshold = 6;
    stextlhold = stextsel;
    stextvhold = stextsval;
    if ( witchitem[stextsval + ((stextsel - stextup) >> 2)]._iIvalue <= plr[myplr]._pGold )
    {
      qmemcpy(&plr[myplr].HoldItem, &witchitem[stextsval + ((stextsel - stextup) >> 2)], sizeof(plr[myplr].HoldItem));
      SetCursor(plr[myplr].HoldItem._iCurs + 12);
      v1 = 0;
      for ( ii = 0; ii < 40 && !v1; ++ii )
        v1 = AutoPlace(myplr, ii, cursW / 28, cursH / 28, 0);
      if ( v1 )
        StartStore(11);
      else
        StartStore(10);
      SetCursor(1);
    }
    else
    {
      StartStore(9);
    }
  }
}

//----- (00434BC0) --------------------------------------------------------
void __cdecl S_WSellEnter()
{
  int idx; // ST0C_4

  if ( stextsel == 22 )
  {
    StartStore(5);
    stextsel = 14;
  }
  else
  {
    stextshold = 7;
    stextlhold = stextsel;
    stextvhold = stextsval;
    idx = stextsval + ((stextsel - stextup) >> 2);
    qmemcpy(&plr[myplr].HoldItem, &storehold[stextsval + ((stextsel - stextup) >> 2)], sizeof(plr[myplr].HoldItem));
    if ( StoreGoldFit(idx) )
      StartStore(11);
    else
      StartStore(10);
  }
}

//----- (00434C92) --------------------------------------------------------
void __cdecl WitchRechargeItem()
{
  int v0; // ST10_4
  int v1; // [esp+Ch] [ebp-8h]

  TakePlrsMoney(plr[myplr].HoldItem._iIvalue);
  v0 = stextvhold + ((stextlhold - stextup) >> 2);
  storehold[stextvhold + ((stextlhold - stextup) >> 2)]._iCharges = storehold[stextvhold + ((stextlhold - stextup) >> 2)]._iMaxCharges;
  v1 = storehidx[v0];
  if ( v1 >= 0 )
    plr[myplr].InvList[v1]._iCharges = plr[myplr].InvList[v1]._iMaxCharges;
  else
    plr[myplr].InvBody[4]._iCharges = plr[myplr].InvBody[4]._iMaxCharges;
}

//----- (00434DC3) --------------------------------------------------------
void __cdecl S_WRechargeEnter()
{
  int v0; // ST0C_4

  if ( stextsel == 22 )
  {
    StartStore(5);
    stextsel = 16;
  }
  else
  {
    stextshold = 8;
    stextlhold = stextsel;
    stextvhold = stextsval;
    v0 = stextsval + ((stextsel - stextup) >> 2);
    qmemcpy(&plr[myplr].HoldItem, &storehold[stextsval + ((stextsel - stextup) >> 2)], sizeof(plr[myplr].HoldItem));
    if ( storehold[v0]._iIvalue <= plr[myplr]._pGold )
      StartStore(11);
    else
      StartStore(9);
  }
}

//----- (00434EBF) --------------------------------------------------------
void __cdecl S_BoyEnter()
{
  if ( stextsel == 18 )
  {
    if ( plr[myplr]._pGold >= 50 )
    {
      TakePlrsMoney(50);
      StartStore(13);
    }
    else
    {
      stextshold = 12;
      stextlhold = stextsel;
      stextvhold = stextsval;
      StartStore(9);
    }
  }
  else
  {
    stextflag = 0;
  }
}

//----- (00434F4F) --------------------------------------------------------
void __cdecl BoyBuyItem()
{
  int ii; // [esp+Ch] [ebp-8h]
  int v1; // [esp+10h] [ebp-4h]

  TakePlrsMoney(plr[myplr].HoldItem._iIvalue);
  SetCursor(plr[myplr].HoldItem._iCurs + 12);
  v1 = 0;
  for ( ii = 0; ii < 40 && !v1; ++ii )
    v1 = AutoPlace(myplr, ii, cursW / 28, cursH / 28, 1);
  SetCursor(1);
  boyitem._itype = -1;
  stextshold = 12;
}

//----- (00435029) --------------------------------------------------------
void __cdecl HealerBuyItem()
{
  int ii; // [esp+Ch] [ebp-Ch]
  int v1; // [esp+10h] [ebp-8h]
  int v2; // [esp+14h] [ebp-4h]

  TakePlrsMoney(plr[myplr].HoldItem._iIvalue);
  SetCursor(plr[myplr].HoldItem._iCurs + 12);
  if ( !plr[myplr].HoldItem._iMagical )
    plr[myplr].HoldItem._iIdentified = 0;
  v1 = 0;
  for ( ii = 0; ii < 40 && !v1; ++ii )
    v1 = AutoPlace(myplr, ii, cursW / 28, cursH / 28, 1);
  SetCursor(1);
  v2 = stextvhold + ((stextlhold - stextup) >> 2);
  if ( v2 == 19 )
  {
    healitem[19]._itype = -1;
  }
  else
  {
    while ( healitem[v2 + 1]._itype != -1 )
    {
      qmemcpy(&healitem[v2], &healitem[v2 + 1], sizeof(ItemStruct));
      ++v2;
    }
    healitem[v2]._itype = -1;
  }
}

//----- (004351E4) --------------------------------------------------------
void __cdecl S_BBuyEnter()
{
  int ii; // [esp+Ch] [ebp-8h]
  int v1; // [esp+10h] [ebp-4h]

  if ( stextsel == 10 )
  {
    stextshold = 13;
    stextlhold = stextsel;
    stextvhold = stextsval;
    if ( plr[myplr]._pGold >= boyitem._iIvalue )
    {
      qmemcpy(&plr[myplr].HoldItem, &boyitem, sizeof(plr[myplr].HoldItem));
      plr[myplr].HoldItem._iIvalue += plr[myplr].HoldItem._iIvalue >> 1;
      SetCursor(plr[myplr].HoldItem._iCurs + 12);
      v1 = 0;
      for ( ii = 0; ii < 40 && !v1; ++ii )
        v1 = AutoPlace(myplr, ii, cursW / 28, cursH / 28, 0);
      if ( v1 )
        StartStore(11);
      else
        StartStore(10);
      SetCursor(1);
    }
    else
    {
      StartStore(9);
    }
  }
  else
  {
    stextflag = 0;
  }
}

//----- (00435386) --------------------------------------------------------
void __cdecl StoryIdItem()
{
  int v0; // [esp+Ch] [ebp-8h]

  TakePlrsMoney(plr[myplr].HoldItem._iIvalue);
  v0 = storehidx[stextvhold + ((stextlhold - stextup) >> 2)];
  if ( v0 >= 0 )
  {
    plr[myplr].InvList[v0]._iIdentified = 1;
  }
  else
  {
    if ( v0 == -1 )
      plr[myplr].InvBody[0]._iIdentified = 1;
    if ( v0 == -2 )
      plr[myplr].InvBody[6]._iIdentified = 1;
    if ( v0 == -3 )
      plr[myplr].InvBody[4]._iIdentified = 1;
    if ( v0 == -4 )
      plr[myplr].InvBody[5]._iIdentified = 1;
    if ( v0 == -5 )
      plr[myplr].InvBody[1]._iIdentified = 1;
    if ( v0 == -6 )
      plr[myplr].InvBody[2]._iIdentified = 1;
    if ( v0 == -7 )
      plr[myplr].InvBody[3]._iIdentified = 1;
  }
}

//----- (0043555F) --------------------------------------------------------
void __cdecl S_ConfirmEnter()
{
  if ( stextsel == 18 )
  {
    switch ( stextshold )
    {
      case 2:
        SmithBuyItem();
        break;
      case 3:
      case 7:
        StoreSellItem();
        break;
      case 4:
        SmithRepairItem();
        break;
      case 6:
        WitchBuyItem();
        break;
      case 8:
        WitchRechargeItem();
        break;
      case 13:
        BoyBuyItem();
        break;
      case 16:
        HealerBuyItem();
        break;
      case 17:
        StoryIdItem();
        break;
      case 18:
        SmithBuyPItem();
        break;
      default:
        break;
    }
    StartStore(stextshold);
  }
  else
  {
    StartStore(stextshold);
    stextsel = stextlhold;
    stextsval = stextvhold;
  }
}

//----- (00435677) --------------------------------------------------------
void __cdecl S_HealerEnter()
{
  switch ( stextsel )
  {
    case 12:
      plr[myplr]._pHitPoints = plr[myplr]._pMaxHP;
      plr[myplr]._pHPBase = plr[myplr]._pMaxHPBase;
      drawmanaflag = 1;
      break;
    case 14:
      StartStore(16);
      break;
    case 18:
      stextflag = 0;
      break;
  }
}

//----- (00435767) --------------------------------------------------------
void __cdecl S_HBuyEnter()
{
  int ii; // [esp+Ch] [ebp-Ch]
  int v1; // [esp+10h] [ebp-8h]

  if ( stextsel == 22 )
  {
    StartStore(14);
    stextsel = 12;
  }
  else
  {
    stextshold = 16;
    stextlhold = stextsel;
    stextvhold = stextsval;
    if ( healitem[stextsval + ((stextsel - stextup) >> 2)]._iIvalue <= plr[myplr]._pGold )
    {
      qmemcpy(&plr[myplr].HoldItem, &healitem[stextsval + ((stextsel - stextup) >> 2)], sizeof(plr[myplr].HoldItem));
      SetCursor(plr[myplr].HoldItem._iCurs + 12);
      v1 = 0;
      for ( ii = 0; ii < 40 && !v1; ++ii )
        v1 = AutoPlace(myplr, ii, cursW / 28, cursH / 28, 0);
      if ( v1 )
        StartStore(11);
      else
        StartStore(10);
      SetCursor(1);
    }
    else
    {
      StartStore(9);
    }
  }
}

//----- (0043590B) --------------------------------------------------------
void __cdecl S_StoryEnter()
{
  if ( stextsel == 12 )
  {
    StartStore(17);
  }
  else if ( stextsel == 18 )
  {
    stextflag = 0;
  }
}

//----- (00435964) --------------------------------------------------------
void __cdecl S_SIDEnter()
{
  int v0; // ST0C_4

  if ( stextsel == 22 )
  {
    StartStore(15);
    stextsel = 12;
  }
  else
  {
    stextshold = 17;
    stextlhold = stextsel;
    stextvhold = stextsval;
    v0 = stextsval + ((stextsel - stextup) >> 2);
    qmemcpy(&plr[myplr].HoldItem, &storehold[stextsval + ((stextsel - stextup) >> 2)], sizeof(plr[myplr].HoldItem));
    if ( storehold[v0]._iIvalue <= plr[myplr]._pGold )
      StartStore(11);
    else
      StartStore(9);
  }
}

//----- (00435A60) --------------------------------------------------------
void __cdecl STextEnter()
{
  PlaySFX(42);
  switch ( stextflag )
  {
    case 1:
      S_SmithEnter();
      break;
    case 2:
      S_SBuyEnter();
      break;
    case 3:
      S_SSellEnter();
      break;
    case 4:
      S_SRepairEnter();
      break;
    case 5:
      S_WitchEnter();
      break;
    case 6:
      S_WBuyEnter();
      break;
    case 7:
      S_WSellEnter();
      break;
    case 8:
      S_WRechargeEnter();
      break;
    case 9:
    case 10:
      StartStore(stextshold);
      stextsel = stextlhold;
      stextsval = stextvhold;
      break;
    case 11:
      S_ConfirmEnter();
      break;
    case 12:
      S_BoyEnter();
      break;
    case 13:
      S_BBuyEnter();
      break;
    case 14:
      S_HealerEnter();
      break;
    case 15:
      S_StoryEnter();
      break;
    case 16:
      S_HBuyEnter();
      break;
    case 17:
      S_SIDEnter();
      break;
    case 18:
      S_SPBuyEnter();
      break;
    default:
      return;
  }
}

//----- (00435BB4) --------------------------------------------------------
void __cdecl CheckStoreBtn()
{
  int v0; // [esp+Ch] [ebp-4h]

  if ( stextsel != -1 && MouseY >= 32 && MouseY <= 320 )
  {
    if ( stextsize )
    {
      if ( MouseX < 24 || MouseX > 616 )
        return;
    }
    else if ( MouseX < 344 || MouseX > 616 )
    {
      return;
    }
    v0 = (MouseY - 32) / 12;
    if ( stextscrl && MouseX > 600 )
    {
      if ( v0 == 4 )
      {
        if ( stextscrlubtn > 0 )
        {
          --stextscrlubtn;
        }
        else
        {
          STextUp();
          stextscrlubtn = 10;
        }
      }
      if ( v0 == 20 )
      {
        if ( stextscrldbtn > 0 )
        {
          --stextscrldbtn;
        }
        else
        {
          STextDown();
          stextscrldbtn = 10;
        }
      }
    }
    else
    {
      if ( v0 == 23 )
        v0 = 22;
      if ( stextscrl && v0 < 21 && !stext[v0]._ssel )
      {
        if ( stext[v0 - 2]._ssel )
        {
          v0 -= 2;
        }
        else if ( stext[v0 - 1]._ssel )
        {
          --v0;
        }
      }
      if ( stext[v0]._ssel || stextscrl && v0 == 22 )
      {
        stextsel = v0;
        STextEnter();
      }
    }
  }
}

//----- (00435DB3) --------------------------------------------------------
void __cdecl ReleaseStoreBtn()
{
  stextscrlubtn = -1;
  stextscrldbtn = -1;
}

