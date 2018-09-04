//----- (0047B694) --------------------------------------------------------
void __cdecl InitTownTriggers()
{
  trigs[0]._tx = 25;
  trigs[0]._ty = 29;
  trigs[0]._tmsg = 1026;
  numtrigs = 1;
  if ( gbMaxPlayers == 4 )
  {
    trigs[1]._tx = 49;
    trigs[1]._ty = 21;
    trigs[1]._tmsg = 1031;
    trigs[1]._tlvl = 5;
    ++numtrigs;
  }
  trigflag = 0;
}

//----- (0047B714) --------------------------------------------------------
void __cdecl InitL1Triggers()
{
  int i; // [esp+Ch] [ebp-8h]
  int j; // [esp+10h] [ebp-4h]

  numtrigs = 0;
  for ( i = 0; i < 112; ++i )
  {
    for ( j = 0; j < 112; ++j )
    {
      if ( dPiece[j][i] == 129 )
      {
        trigs[numtrigs]._tx = j;
        trigs[numtrigs]._ty = i;
        trigs[numtrigs++]._tmsg = 1027;
      }
      if ( dPiece[j][i] == 115 )
      {
        trigs[numtrigs]._tx = j;
        trigs[numtrigs]._ty = i;
        trigs[numtrigs++]._tmsg = 1026;
      }
    }
  }
  trigflag = 0;
}

//----- (0047B82E) --------------------------------------------------------
void __cdecl InitL2Triggers()
{
  int i; // [esp+Ch] [ebp-8h]
  int j; // [esp+10h] [ebp-4h]

  numtrigs = 0;
  for ( i = 0; i < 112; ++i )
  {
    for ( j = 0; j < 112; ++j )
    {
      if ( dPiece[j][i] == 267 && (quests[3]._qtx != j || quests[3]._qty != i) )
      {
        trigs[numtrigs]._tx = j;
        trigs[numtrigs]._ty = i;
        trigs[numtrigs++]._tmsg = 1027;
      }
      if ( dPiece[j][i] == 559 )
      {
        trigs[numtrigs]._tx = j;
        trigs[numtrigs]._ty = i;
        trigs[numtrigs]._tmsg = 1032;
        trigs[numtrigs++]._tlvl = 0;
      }
      if ( dPiece[j][i] == 271 )
      {
        trigs[numtrigs]._tx = j;
        trigs[numtrigs]._ty = i;
        trigs[numtrigs++]._tmsg = 1026;
      }
    }
  }
  trigflag = 0;
}

//----- (0047BC12) --------------------------------------------------------
void __cdecl InitSKingTriggers()
{
  numtrigs = 1;
  trigs[0]._tx = 18;
  trigs[0]._ty = 49;
  trigs[0]._tmsg = 1028;
  trigflag = 0;
}

//----- (0047BC54) --------------------------------------------------------
void __cdecl InitSChambTriggers()
{
  numtrigs = 1;
  trigs[0]._tx = 70;
  trigs[0]._ty = 39;
  trigs[0]._tmsg = 1028;
  trigflag = 0;
}

//----- (0047BC96) --------------------------------------------------------
void __cdecl InitPWaterTriggers()
{
  numtrigs = 1;
  trigs[0]._tx = 30;
  trigs[0]._ty = 83;
  trigs[0]._tmsg = 1028;
  trigflag = 0;
}

//----- (0047BCD8) --------------------------------------------------------
BOOL __cdecl ForceTownTrig()
{
  int i; // [esp+Ch] [ebp-4h]
  int j; // [esp+Ch] [ebp-4h]

  for ( i = 0; TownDownList[i] != -1; ++i )
  {
    if ( dPiece[cursmx][cursmy] == TownDownList[i] )
    {
      strcpy(infostr, "Down to dungeon");
      cursmx = 25;
      cursmy = 29;
      return 1;
    }
  }
  for ( j = 0; TownWarp1List[j] != -1; ++j )
  {
    if ( dPiece[cursmx][cursmy] == TownWarp1List[j] )
    {
      strcpy(infostr, "Down to catacombs");
      cursmx = 49;
      cursmy = 21;
      return 1;
    }
  }
  return 0;
}

//----- (0047BDEF) --------------------------------------------------------
BOOL __cdecl ForceL1Trig()
{
  int j; // [esp+Ch] [ebp-8h]
  int l; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]
  int k; // [esp+10h] [ebp-4h]

  for ( i = 0; L1UpList[i] != -1; ++i )
  {
    if ( dPiece[cursmx][cursmy] == L1UpList[i] )
    {
      if ( (signed int)currlevel <= 1 )
        strcpy(infostr, "Up to town");
      else
        sprintf(infostr, "Up to level %i", currlevel - 1);
      for ( j = 0; numtrigs > j; ++j )
      {
        if ( trigs[j]._tmsg == 1027 )
        {
          cursmx = trigs[j]._tx;
          cursmy = trigs[j]._ty;
          return 1;
        }
      }
    }
  }
  for ( k = 0; L1DownList[k] != -1; ++k )
  {
    if ( dPiece[cursmx][cursmy] == L1DownList[k] )
    {
      sprintf(infostr, "Down to level %i", currlevel + 1);
      for ( l = 0; numtrigs > l; ++l )
      {
        if ( trigs[l]._tmsg == 1026 )
        {
          cursmx = trigs[l]._tx;
          cursmy = trigs[l]._ty;
          return 1;
        }
      }
    }
  }
  return 0;
}

//----- (0047BFCD) --------------------------------------------------------
BOOL __cdecl ForceL2Trig()
{
  int v0; // ST1C_4
  int v2; // ST1C_4
  int v3; // [esp+Ch] [ebp-10h]
  int v4; // [esp+Ch] [ebp-10h]
  int j; // [esp+14h] [ebp-8h]
  int l; // [esp+14h] [ebp-8h]
  int n; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]
  int k; // [esp+18h] [ebp-4h]
  int m; // [esp+18h] [ebp-4h]

  for ( i = 0; L2UpList[i] != -1; ++i )
  {
    if ( dPiece[cursmx][cursmy] == L2UpList[i] )
    {
      for ( j = 0; j < numtrigs; ++j )
      {
        if ( trigs[j]._tmsg == 1027 )
        {
          v0 = abs(trigs[j]._tx - cursmx);
          v3 = abs(trigs[j]._ty - cursmy);
          if ( v0 < 4 && v3 < 4 )
          {
            sprintf(infostr, "Up to level %i", currlevel - 1);
            cursmx = trigs[j]._tx;
            cursmy = trigs[j]._ty;
            return 1;
          }
        }
      }
    }
  }
  for ( k = 0; L2DownList[k] != -1; ++k )
  {
    if ( dPiece[cursmx][cursmy] == L2DownList[k] )
    {
      sprintf(infostr, "Down to level %i", currlevel + 1);
      for ( l = 0; l < numtrigs; ++l )
      {
        if ( trigs[l]._tmsg == 1026 )
        {
          cursmx = trigs[l]._tx;
          cursmy = trigs[l]._ty;
          return 1;
        }
      }
    }
  }
  if ( currlevel == 5 )
  {
    for ( m = 0; L2TWarpUpList[m] != -1; ++m )
    {
      if ( dPiece[cursmx][cursmy] == L2TWarpUpList[m] )
      {
        for ( n = 0; n < numtrigs; ++n )
        {
          if ( trigs[n]._tmsg == 1032 )
          {
            v2 = abs(trigs[n]._tx - cursmx);
            v4 = abs(trigs[n]._ty - cursmy);
            if ( v2 < 4 && v4 < 4 )
            {
              strcpy(infostr, "Up to town");
              cursmx = trigs[n]._tx;
              cursmy = trigs[n]._ty;
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}

//----- (0047C2F9) --------------------------------------------------------
BOOL __cdecl ForceL3Trig()
{
  int j; // [esp+Ch] [ebp-8h]
  int l; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]
  int k; // [esp+10h] [ebp-4h]

  for ( i = 0; L3UpList[i] != -1; ++i )
  {
    if ( dPiece[cursmx][cursmy] == L3UpList[i] )
    {
      sprintf(infostr, "Up to level %i", currlevel - 1);
      for ( j = 0; numtrigs > j; ++j )
      {
        if ( trigs[j]._tmsg == 1027 )
        {
          cursmx = trigs[j]._tx;
          cursmy = trigs[j]._ty;
          return 1;
        }
      }
    }
  }
  for ( k = 0; L3DownList[k] != -1; ++k )
  {
    if ( dPiece[cursmx][cursmy] == L3DownList[k] )
    {
      sprintf(infostr, "Down to level %i", currlevel + 1);
      for ( l = 0; numtrigs > l; ++l )
      {
        if ( trigs[l]._tmsg == 1026 )
        {
          cursmx = trigs[l]._tx;
          cursmy = trigs[l]._ty;
          return 1;
        }
      }
    }
  }
  return 0;
}

//----- (0047C4B0) --------------------------------------------------------
void __cdecl CheckTrigForce()
{
  if ( setlevel || MouseY > 351 )
  {
    trigflag = 0;
  }
  else
  {
    switch ( leveltype )
    {
      case 0:
        trigflag = ForceTownTrig();
        break;
      case 1:
        trigflag = ForceL1Trig();
        break;
      case 2:
        trigflag = ForceL2Trig();
        break;
      case 3:
        trigflag = ForceL3Trig();
        break;
      case 4:
        trigflag = ForceL2Trig();
        break;
      default:
        break;
    }
    if ( leveltype )
    {
      if ( !trigflag )
        trigflag = ForceQuests();
    }
  }
}

//----- (0047C59E) --------------------------------------------------------
void __cdecl CheckTriggers()
{
  int i; // [esp+10h] [ebp-4h]

  if ( !plr[myplr]._pmode )
  {
    for ( i = 0; numtrigs > i; ++i )
    {
      if ( plr[myplr].WorldX == trigs[i]._tx && plr[myplr].WorldY == trigs[i]._ty )
      {
        switch ( trigs[i]._tmsg )
        {
          case 0x402:
            StartNewLvl(myplr, trigs[i]._tmsg, currlevel + 1);
            break;
          case 0x403:
            StartNewLvl(myplr, trigs[i]._tmsg, currlevel - 1);
            break;
          case 0x404:
            if ( gbMaxPlayers != 1 )
              assertion_failed(443, "C:\\Diablo\\Direct\\TRIGS.CPP");
            SetReturnLvlPos();
            StartNewLvl(myplr, trigs[i]._tmsg, 0);
            break;
          case 0x407:
          case 0x408:
            StartNewLvl(myplr, trigs[i]._tmsg, trigs[i]._tlvl);
            break;
          default:
            TermMsg("Unknown trigger msg");
            return;
        }
      }
    }
  }
}

