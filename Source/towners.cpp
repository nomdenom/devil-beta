//----- (004579F0) --------------------------------------------------------
int __fastcall GetActiveTowner(int t)
{
  int i; // [esp+10h] [ebp-4h]

  for ( i = 0; numtowners > i; ++i )
  {
    if ( towner[i]._ttype == t )
      return i;
  }
  return -1;
}

//----- (00457A53) --------------------------------------------------------
void __fastcall SetTownerGPtrs(void *pData, void **pAnim)
{
  signed int i; // [esp+14h] [ebp-8h]

  for ( i = 0; i < 8; ++i )
    pAnim[i] = (char *)pData + *((_DWORD *)pData + i);
}

//----- (00457AB0) --------------------------------------------------------
void __fastcall NewTownerAnim(int tnum, void *pAnim, int numFrames, int Delay)
{
  if ( !pAnim )
    assertion_failed(98, "C:\\Diablo\\Direct\\towners.cpp");
  towner[tnum]._tAnimData = pAnim;
  towner[tnum]._tAnimLen = numFrames;
  towner[tnum]._tAnimFrame = 1;
  towner[tnum]._tAnimCnt = 0;
  towner[tnum]._tAnimDelay = Delay;
}

//----- (00457B5E) --------------------------------------------------------
void __fastcall InitTownerInfo(int i, int w, bool sel, int t, int x, int y, int ao, int tp)
{
  memset(&towner[i], 0, 0xDCu);
  towner[i]._tSelFlag = sel;
  towner[i]._tAnimWidth = w;
  towner[i]._tAnimWidth2 = (w - 64) >> 1;
  towner[i]._tMsgSaid = 0;
  towner[i]._ttype = t;
  towner[i]._tx = x;
  towner[i]._ty = y;
  dMonster[x][y] = i + 1;
  towner[i]._tAnimOrder = ao;
  towner[i]._tTenPer = tp;
}

//----- (00457C8E) --------------------------------------------------------
void __cdecl InitSmith()
{
  InitTownerInfo(numtowners, 96, 1, 0, 62, 63, 0, 10);
  if ( towner[numtowners]._tNData )
    assertion_failed(128, "C:\\Diablo\\Direct\\towners.cpp");
  towner[numtowners]._tNData = LoadFileInMem("Towners\\Smith\\SmithN.CEL", 0, 129, "C:\\Diablo\\Direct\\towners.cpp");
  SetTownerGPtrs(towner[numtowners]._tNData, (void **)towner[numtowners]._tNAnim);
  towner[numtowners]._tNFrames = 16;
  NewTownerAnim(numtowners, towner[numtowners]._tNAnim[1], towner[numtowners]._tNFrames, 3);
  strcpy(towner[numtowners]._tName, "Griswold the Blacksmith");
  ++numtowners;
}

//----- (00457DCC) --------------------------------------------------------
void __cdecl InitBarOwner()
{
  InitTownerInfo(numtowners, 96, 1, 3, 55, 62, 3, 10);
  if ( towner[numtowners]._tNData )
    assertion_failed(142, "C:\\Diablo\\Direct\\towners.cpp");
  towner[numtowners]._tNData = LoadFileInMem("Towners\\TwnF\\TwnFN.CEL", 0, 143, "C:\\Diablo\\Direct\\towners.cpp");
  SetTownerGPtrs(towner[numtowners]._tNData, (void **)towner[numtowners]._tNAnim);
  towner[numtowners]._tNFrames = 16;
  NewTownerAnim(numtowners, towner[numtowners]._tNAnim[1], towner[numtowners]._tNFrames, 3);
  strcpy(towner[numtowners]._tName, "Ogden the Tavern owner");
  ++numtowners;
}

//----- (00457F0A) --------------------------------------------------------
void __cdecl InitTownDead()
{
  signed int i; // [esp+Ch] [ebp-4h]

  InitTownerInfo(numtowners, 96, 1, 2, 24, 32, -1, 10);
  if ( towner[numtowners]._tNData )
    assertion_failed(155, "C:\\Diablo\\Direct\\towners.cpp");
  towner[numtowners]._tNData = LoadFileInMem("Towners\\Butch\\Deadguy.CEL", 0, 156, "C:\\Diablo\\Direct\\towners.cpp");
  for ( i = 0; i < 8; ++i )
    towner[numtowners]._tNAnim[i] = towner[numtowners]._tNData;
  towner[numtowners]._tNFrames = 8;
  NewTownerAnim(numtowners, towner[numtowners]._tNAnim[4], towner[numtowners]._tNFrames, 6);
  strcpy(towner[numtowners]._tName, "Wounded Townsman");
  ++numtowners;
}

//----- (0045806A) --------------------------------------------------------
void __cdecl InitWitch()
{
  signed int i; // [esp+Ch] [ebp-4h]

  InitTownerInfo(numtowners, 96, 1, 7, 80, 20, 5, 10);
  if ( towner[numtowners]._tNData )
    assertion_failed(168, "C:\\Diablo\\Direct\\towners.cpp");
  towner[numtowners]._tNData = LoadFileInMem("Towners\\TownWmn1\\WmnN.CEL", 0, 169, "C:\\Diablo\\Direct\\towners.cpp");
  for ( i = 0; i < 8; ++i )
    towner[numtowners]._tNAnim[i] = towner[numtowners]._tNData;
  towner[numtowners]._tNFrames = 19;
  NewTownerAnim(numtowners, towner[numtowners]._tNAnim[0], towner[numtowners]._tNFrames, 6);
  strcpy(towner[numtowners]._tName, "The Witch");
  ++numtowners;
}

//----- (004581CA) --------------------------------------------------------
void __cdecl InitBoy()
{
  signed int i; // [esp+Ch] [ebp-4h]

  InitTownerInfo(numtowners, 96, 1, 6, 11, 53, -1, 10);
  if ( towner[numtowners]._tNData )
    assertion_failed(181, "C:\\Diablo\\Direct\\towners.cpp");
  towner[numtowners]._tNData = LoadFileInMem("Towners\\TownBoy\\PegKid1.CEL", 0, 182, "C:\\Diablo\\Direct\\towners.cpp");
  for ( i = 0; i < 8; ++i )
    towner[numtowners]._tNAnim[i] = towner[numtowners]._tNData;
  towner[numtowners]._tNFrames = 20;
  NewTownerAnim(numtowners, towner[numtowners]._tNAnim[0], towner[numtowners]._tNFrames, 6);
  strcpy(towner[numtowners]._tName, "Wirt the Peg-legged boy");
  ++numtowners;
}

//----- (0045832A) --------------------------------------------------------
void __cdecl InitHealer()
{
  signed int i; // [esp+Ch] [ebp-4h]

  InitTownerInfo(numtowners, 96, 1, 1, 55, 79, 1, 10);
  if ( towner[numtowners]._tNData )
    assertion_failed(194, "C:\\Diablo\\Direct\\towners.cpp");
  towner[numtowners]._tNData = LoadFileInMem("Towners\\Healer\\Healer.CEL", 0, 195, "C:\\Diablo\\Direct\\towners.cpp");
  for ( i = 0; i < 8; ++i )
    towner[numtowners]._tNAnim[i] = towner[numtowners]._tNData;
  towner[numtowners]._tNFrames = 20;
  NewTownerAnim(numtowners, towner[numtowners]._tNAnim[7], towner[numtowners]._tNFrames, 6);
  strcpy(towner[numtowners]._tName, "Pepin the Healer");
  ++numtowners;
}

//----- (0045848A) --------------------------------------------------------
void __cdecl InitTeller()
{
  signed int i; // [esp+Ch] [ebp-4h]

  InitTownerInfo(numtowners, 96, 1, 4, 62, 71, 2, 10);
  if ( towner[numtowners]._tNData )
    assertion_failed(208, "C:\\Diablo\\Direct\\towners.cpp");
  towner[numtowners]._tNData = LoadFileInMem(
                                 "Towners\\Strytell\\Strytell.CEL",
                                 0,
                                 209,
                                 "C:\\Diablo\\Direct\\towners.cpp");
  for ( i = 0; i < 8; ++i )
    towner[numtowners]._tNAnim[i] = towner[numtowners]._tNData;
  towner[numtowners]._tNFrames = 25;
  NewTownerAnim(numtowners, towner[numtowners]._tNAnim[0], towner[numtowners]._tNFrames, 3);
  strcpy(towner[numtowners]._tName, "Deckard Cain the elder");
  ++numtowners;
}

//----- (004585EA) --------------------------------------------------------
void __cdecl InitDrunk()
{
  signed int i; // [esp+Ch] [ebp-4h]

  InitTownerInfo(numtowners, 96, 1, 5, 71, 84, 4, 10);
  if ( towner[numtowners]._tNData )
    assertion_failed(221, "C:\\Diablo\\Direct\\towners.cpp");
  towner[numtowners]._tNData = LoadFileInMem("Towners\\Drunk\\TwnDrunk.CEL", 0, 222, "C:\\Diablo\\Direct\\towners.cpp");
  for ( i = 0; i < 8; ++i )
    towner[numtowners]._tNAnim[i] = towner[numtowners]._tNData;
  towner[numtowners]._tNFrames = 18;
  NewTownerAnim(numtowners, towner[numtowners]._tNAnim[0], towner[numtowners]._tNFrames, 3);
  strcpy(towner[numtowners]._tName, "Farnham the Drunk");
  ++numtowners;
}

//----- (0045874A) --------------------------------------------------------
void __cdecl InitCows()
{
  int v0; // ST38_4
  int v1; // [esp+Ch] [ebp-18h]
  signed int i; // [esp+10h] [ebp-14h]
  int y; // [esp+14h] [ebp-10h]
  int v4; // [esp+18h] [ebp-Ch]
  int x; // [esp+1Ch] [ebp-8h]

  if ( pCowCels )
    assertion_failed(236, "C:\\Diablo\\Direct\\towners.cpp");
  pCowCels = LoadFileInMem("Towners\\Animals\\Cow.CEL", 0, 237, "C:\\Diablo\\Direct\\towners.cpp");
  for ( i = 0; i < 3; ++i )
  {
    x = TownCowX[i];
    y = TownCowY[i];
    v0 = TownCowDir[i];
    InitTownerInfo(numtowners, 128, 0, 8, TownCowX[i], TownCowY[i], -1, 10);
    towner[numtowners]._tNData = pCowCels;
    SetTownerGPtrs(towner[numtowners]._tNData, (void **)towner[numtowners]._tNAnim);
    towner[numtowners]._tNFrames = 12;
    NewTownerAnim(numtowners, towner[numtowners]._tNAnim[v0], towner[numtowners]._tNFrames, 3);
    towner[numtowners]._tAnimFrame = random(0, 11) + 1;
    towner[numtowners]._tSelFlag = 0;
    v4 = x + cowoffx[v0];
    v1 = y + cowoffy[v0];
    if ( !dMonster[x][v1] )
      dMonster[x][v1] = -(numtowners + 1);
    if ( !dMonster[v4][y] )
      dMonster[v4][y] = -(numtowners + 1);
    if ( !dMonster[v4][v1] )
      dMonster[v4][v1] = -(numtowners + 1);
    ++numtowners;
  }
}

//----- (004589C1) --------------------------------------------------------
void __cdecl InitTowners()
{
  numtowners = 0;
  InitSmith();
  InitBarOwner();
  if ( gbMaxPlayers == 1 && quests[1]._qactive != 3 )
    InitTownDead();
  InitWitch();
  InitHealer();
  InitTeller();
  InitDrunk();
  if ( !random(0, 3) || gbMaxPlayers != 1 )
    InitBoy();
  InitCows();
}

//----- (00458A4C) --------------------------------------------------------
void __cdecl FreeTownerGFX()
{
  signed int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 16; ++i )
  {
    if ( towner[i]._tNData == pCowCels )
    {
      towner[i]._tNData = 0;
    }
    else if ( towner[i]._tNData )
    {
      mem_free_dbg(towner[i]._tNData, 293, "C:\\Diablo\\Direct\\towners.cpp");
      towner[i]._tNData = 0;
    }
  }
  mem_free_dbg(pCowCels, 299, "C:\\Diablo\\Direct\\towners.cpp");
  pCowCels = 0;
}

//----- (00458B2F) --------------------------------------------------------
void __fastcall TownCtrlMsg(int i)
{
  int v1; // ST1C_4
  int v2; // ST18_4
  int v4; // [esp+10h] [ebp-Ch]

  if ( towner[i]._tbtcnt )
  {
    v1 = towner[i]._tVar1;
    v2 = abs(towner[i]._tx - plr[v1].WorldX);
    v4 = abs(towner[i]._ty - plr[v1].WorldY);
    if ( v2 >= 2 || v4 >= 2 )
      towner[i]._tbtcnt = 0;
    if ( !towner[i]._tbtcnt )
    {
      qtextflag = 0;
      sfx_stop();
    }
  }
}

//----- (00458C47) --------------------------------------------------------
void __cdecl TownBlackSmith()
{
  int y; // [esp+Ch] [ebp-Ch]
  int x; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  i = GetActiveTowner(0);
  TownCtrlMsg(i);
  if ( !qtextflag && quests[2]._qactive == 3 )
  {
    x = towner[i]._tx;
    y = towner[i]._ty + 1;
    if ( dPlayer[x][y] > 0 )
      ++x;
    CreateItem(2, x, y);
    quests[2]._qactive = 0;
  }
}

//----- (00458CF3) --------------------------------------------------------
void __cdecl TownBarOwner()
{
  int i; // ST0C_4

  i = GetActiveTowner(3);
  TownCtrlMsg(i);
}

//----- (00458D1B) --------------------------------------------------------
void __cdecl TownDead()
{
  int i; // [esp+Ch] [ebp-4h]

  i = GetActiveTowner(2);
  TownCtrlMsg(i);
  if ( !qtextflag && quests[1]._qactive != 1 )
  {
    towner[i]._tAnimDelay = 1000;
    towner[i]._tAnimFrame = 1;
    strcpy(towner[i]._tName, "Slain Townsman");
  }
  if ( quests[1]._qactive != 1 )
    towner[i]._tAnimCnt = 0;
}

//----- (00458DDE) --------------------------------------------------------
void __cdecl ProcessTowners()
{
  int v0; // [esp+Ch] [ebp-Ch]
  int v1; // [esp+10h] [ebp-8h]
  signed int i; // [esp+14h] [ebp-4h]

  for ( i = 0; i < 16; ++i )
  {
    v0 = towner[i]._ttype;
    if ( v0 )
    {
      if ( v0 == 2 )
      {
        TownDead();
      }
      else if ( v0 == 3 )
      {
        TownBarOwner();
      }
    }
    else
    {
      TownBlackSmith();
    }
    if ( towner[i]._tAnimDelay <= ++towner[i]._tAnimCnt )
    {
      towner[i]._tAnimCnt = 0;
      if ( towner[i]._tAnimOrder < 0 )
      {
        if ( towner[i]._tAnimLen < ++towner[i]._tAnimFrame )
          towner[i]._tAnimFrame = 1;
      }
      else
      {
        v1 = towner[i]._tAnimOrder;
        if ( AnimOrder[v1][++towner[i]._tAnimFrameCnt] == -1 )
          towner[i]._tAnimFrameCnt = 0;
        towner[i]._tAnimFrame = AnimOrder[v1][towner[i]._tAnimFrameCnt];
      }
    }
  }
}

//----- (00458FFA) --------------------------------------------------------
void __fastcall towners_458FFA_sfx(int sfx1, int sfx2, int sfxlimit)
{
  int v3; // ST14_4
  int v4; // eax

  v3 = towner[numtowners]._tTenPer;
  if ( random(0, 100) <= v3 || sfx1 == -1 )
  {
    v4 = random(0, sfxlimit);
    PlaySFX(v4 + sfx2);
  }
  else
  {
    PlaySFX(sfx1);
  }
}

//----- (0045906E) --------------------------------------------------------
void __fastcall TalkToTowner(int p, int t)
{
  int v2; // ST1C_4
  int v5; // [esp+14h] [ebp-18h]
  int iv; // [esp+1Ch] [ebp-10h]

  random(6, 3);
  random(6, 4);
  random(6, 5);
  v2 = abs(plr[p].WorldX - towner[t]._tx);
  v5 = abs(plr[p].WorldY - towner[t]._ty);
  if ( v2 < 2 && v5 < 2 && !qtextflag )
  {
    if ( GetActiveTowner(3) == t )
    {
      if ( qtextflag || random(0, 100) <= 10 )
        PlaySFX(134);
      else
        PlaySFX(133);
      towner[t]._tbtcnt = 150;
      towner[t]._tVar1 = p;
      towner[t]._tMsgSaid = 1;
      if ( quests[1]._qactive == 3 )
      {
        switch ( quests[0]._qactive )
        {
          case 2:
            quests[0]._qvar1 = 1;
            towner[t]._tbtcnt = 150;
            towner[t]._tVar1 = p;
            InitQTextMsg(1);
            towner[t]._tMsgSaid = 1;
            break;
          case 3:
            quests[0]._qvar1 = 2;
            towner[t]._tbtcnt = 150;
            towner[t]._tVar1 = p;
            InitQTextMsg(2);
            towner[t]._tMsgSaid = 1;
            break;
          case 1:
            quests[0]._qactive = 2;
            quests[0]._qvar1 = 0;
            towner[t]._tbtcnt = 150;
            towner[t]._tVar1 = p;
            InitQTextMsg(0);
            towner[t]._tMsgSaid = 1;
            break;
        }
      }
      else
      {
        towner[t]._tbtcnt = 150;
        towner[t]._tVar1 = p;
        towner[t]._tMsgSaid = 1;
      }
    }
    else if ( GetActiveTowner(2) == t )
    {
      if ( quests[1]._qactive == 2 )
      {
        towner[t]._tbtcnt = 150;
        towner[t]._tVar1 = p;
        InitQTextMsg(4);
        towner[t]._tMsgSaid = 1;
      }
      else if ( quests[1]._qactive == 1 )
      {
        quests[1]._qactive = 2;
        quests[1]._qvar1 = 3;
        towner[t]._tbtcnt = 50;
        towner[t]._tVar1 = p;
        towner[t]._tVar2 = 3;
        PlaySFX(139);
        towner[t]._tMsgSaid = 1;
      }
    }
    if ( GetActiveTowner(0) == t )
    {
      if ( quests[2]._qactive != 1 || quests[0]._qactive != 3 )
      {
        if ( quests[2]._qactive == 2 )
        {
          for ( iv = 0; plr[p]._pNumInv > iv; ++iv )
          {
            if ( plr[p].InvList[iv]._iCurs == 76 )
            {
              quests[2]._qactive = 3;
              RemoveInvItem(p, iv);
              iv = plr[p]._pNumInv;
            }
          }
        }
        if ( quests[2]._qactive == 3 )
        {
          quests[2]._qvar1 = 8;
          towner[t]._tbtcnt = 150;
          towner[t]._tVar1 = p;
          InitQTextMsg(8);
          towner[t]._tMsgSaid = 1;
        }
      }
      else
      {
        quests[2]._qactive = 2;
        quests[2]._qvar1 = 6;
        towner[t]._tbtcnt = 150;
        towner[t]._tVar1 = p;
        InitQTextMsg(6);
        towner[t]._tMsgSaid = 1;
      }
      if ( !qtextflag )
      {
        towners_458FFA_sfx(115, 116, 3);
        StartStore(1);
      }
      towner[t]._tbtcnt = 150;
      towner[t]._tVar1 = p;
      towner[t]._tMsgSaid = 1;
    }
    else if ( GetActiveTowner(7) == t )
    {
      towners_458FFA_sfx(135, 136, 3);
      StartStore(5);
    }
    else if ( GetActiveTowner(5) == t )
    {
      towners_458FFA_sfx(-1, 120, 5);
    }
    else if ( GetActiveTowner(1) == t )
    {
      if ( !towner[t]._tMsgSaid )
      {
        if ( quests[5]._qactive == 2 )
        {
          quests[5]._qvar1 = 16;
          towner[t]._tbtcnt = 150;
          towner[t]._tVar1 = p;
          InitQTextMsg(16);
          towner[t]._tMsgSaid = 1;
        }
        else if ( quests[5]._qactive == 1 )
        {
          quests[5]._qactive = 2;
          quests[5]._qvar1 = 15;
          towner[t]._tbtcnt = 150;
          towner[t]._tVar1 = p;
          InitQTextMsg(15);
          towner[t]._tMsgSaid = 1;
        }
        else if ( quests[5]._qactive == 3 && quests[5]._qvar1 != 17 )
        {
          quests[5]._qvar1 = 17;
          towner[t]._tbtcnt = 150;
          towner[t]._tVar1 = p;
          InitQTextMsg(17);
          CreateItem(88, towner[t]._tx, towner[t]._ty + 1);
          towner[t]._tMsgSaid = 1;
        }
      }
      if ( !qtextflag )
      {
        towners_458FFA_sfx(125, 126, 2);
        StartStore(14);
      }
    }
    else if ( GetActiveTowner(6) == t )
    {
      if ( quests[6]._qactive == 1 )
      {
        quests[6]._qactive = 2;
        quests[6]._qvar1 = 18;
        towner[t]._tbtcnt = 150;
        towner[t]._tVar1 = p;
        InitQTextMsg(18);
        PlaySFX(129);
        towner[t]._tMsgSaid = 1;
      }
      towners_458FFA_sfx(128, 129, 2);
      StartStore(12);
    }
    else if ( GetActiveTowner(4) == t )
    {
      towners_458FFA_sfx(130, 131, 2);
      StartStore(15);
    }
  }
}

