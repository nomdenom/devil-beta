//----- (00478720) --------------------------------------------------------
void __cdecl InitQuests()
{
  int v0; // ebx
  signed int i; // [esp+Ch] [ebp-4h]
  unsigned int j; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 11; ++i )
    quests[i]._qactive = 0;
  Xmax_quests = 0;
  questlog = 0;
  ALLQUESTS = 1;
  WaterDone = 0;
  for ( j = 0; j < 11; ++j )
  {
    v0 = questlist[j]._qdrnd;
    if ( v0 >= random(0, 100) && ((signed int)gbMaxPlayers <= 1 || questlist[j]._qflags & 1) )
    {
      quests[Xmax_quests]._qtype = questlist[j]._qdtype;
      quests[Xmax_quests]._qlevel = questlist[j]._qdlvl
                                  + random(
                                      0,
                                      (unsigned __int8)questlist[j].X_qdlvl_max
                                    - (unsigned __int8)questlist[j]._qdlvl
                                    + 1);
      if ( (signed int)gbMaxPlayers <= 1 )
        quests[Xmax_quests]._qactive = 1;
      else
        quests[Xmax_quests]._qactive = 2;
      quests[Xmax_quests]._qslvl = questlist[j]._qslvl;
      quests[Xmax_quests]._qtx = 0;
      quests[Xmax_quests]._qty = 0;
      quests[Xmax_quests]._qidx = j;
      quests[Xmax_quests++]._qlvltype = questlist[j]._qlvlt;
    }
  }
  quests[7]._qvar1 = 19;
  quests[10]._qvar1 = 25;
}

//----- (00478908) --------------------------------------------------------
void __cdecl CheckQuests()
{
  int i; // [esp+Ch] [ebp-4h]

  if ( gbMaxPlayers == 1 )
  {
    if ( setlevel )
    {
      if ( quests[5]._qlevel == currlevel
        && quests[5]._qactive != 1
        && quests[5]._qlvltype == leveltype
        && !nummonsters
        && quests[5]._qactive != 3 )
      {
        quests[5]._qactive = 3;
        LoadPalette("Levels\\L3Data\\L3pwater.pal");
        WaterDone = 32;
      }
      if ( WaterDone > 0 )
      {
        palette_update_quest_palette(WaterDone);
        --WaterDone;
      }
    }
    else if ( !plr[myplr]._pmode )
    {
      for ( i = 0; i < Xmax_quests; ++i )
      {
        if ( quests[i]._qlevel == currlevel
          && quests[i]._qactive == 2
          && quests[i]._qslvl
          && quests[i]._qtx == plr[myplr].WorldX
          && quests[i]._qty == plr[myplr].WorldY )
        {
          if ( quests[i]._qlvltype != 255 )
            leveltype = quests[i]._qlvltype;
          StartNewLvl(myplr, 1029, quests[i]._qslvl);
        }
      }
    }
  }
}

//----- (00478B1D) --------------------------------------------------------
BOOL __cdecl ForceQuests()
{
  signed int j; // [esp+Ch] [ebp-14h]
  int v2; // [esp+10h] [ebp-10h]
  int v3; // [esp+14h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-4h]

  if ( gbMaxPlayers != 1 )
    return 0;
  for ( i = 0; Xmax_quests > i; ++i )
  {
    if ( quests[i]._qlevel == currlevel && quests[i]._qactive == 2 && quests[i]._qslvl )
    {
      v3 = quests[i]._qtx;
      v2 = quests[i]._qty;
      for ( j = 0; j < 7; ++j )
      {
        if ( v3 + questxoff[j] == cursmx && v2 + questyoff[j] == cursmy )
        {
          sprintf(infostr, "To %s", questlist[quests[i]._qidx]._qlstr);
          cursmx = v3;
          cursmy = v2;
          return 1;
        }
      }
    }
  }
  return 0;
}

//----- (00478C87) --------------------------------------------------------
void __fastcall QuestStatus(int i)
{
  if ( gbMaxPlayers == 1 )
  {
    if ( monster[i].MType->mtype == 50 )
    {
      quests[0]._qactive = 3;
      sfxdelay = 30;
      if ( plr[myplr]._pClass )
      {
        if ( plr[myplr]._pClass == 1 )
        {
          sfxdnum = 193;
        }
        else if ( plr[myplr]._pClass == 2 )
        {
          sfxdnum = 165;
        }
      }
      else
      {
        sfxdnum = 221;
      }
    }
    else if ( monster[i].MType->mtype == 51 )
    {
      quests[1]._qactive = 3;
      sfxdelay = 30;
      if ( plr[myplr]._pClass )
      {
        if ( plr[myplr]._pClass == 1 )
        {
          sfxdnum = 192;
        }
        else if ( plr[myplr]._pClass == 2 )
        {
          sfxdnum = 164;
        }
      }
      else
      {
        sfxdnum = 220;
      }
    }
    else if ( monster[i].mName == UniqMonst[0].mName )
    {
      quests[7]._qactive = 3;
      sfxdelay = 30;
      if ( plr[myplr]._pClass )
      {
        if ( plr[myplr]._pClass == 1 )
        {
          sfxdnum = 192;
        }
        else if ( plr[myplr]._pClass == 2 )
        {
          sfxdnum = 164;
        }
      }
      else
      {
        sfxdnum = 220;
      }
    }
    else if ( monster[i].mName == UniqMonst[2].mName )
    {
      quests[10]._qactive = 3;
      sfxdelay = 30;
      if ( plr[myplr]._pClass )
      {
        if ( plr[myplr]._pClass == 1 )
        {
          sfxdnum = 192;
        }
        else if ( plr[myplr]._pClass == 2 )
        {
          sfxdnum = 164;
        }
      }
      else
      {
        sfxdnum = 220;
      }
    }
  }
}

//----- (0047900F) --------------------------------------------------------
void __fastcall CheckQuestKill(int m, unsigned __int8 sendmsg)
{
  signed int i; // [esp+Ch] [ebp-8h]
  signed int j; // [esp+10h] [ebp-4h]

  for ( i = 0; i < 40; ++i )
  {
    for ( j = 0; j < 40; ++j )
      pdungeon[j][i] = dungeon[j][i];
  }
}

//----- (0047907E) --------------------------------------------------------
void __cdecl DrawButcher()
{
  quests[6]._qtx = 2 * setpc_x + 19;
  quests[6]._qty = 2 * setpc_y + 19;
  DRLG_RectTrans(2 * setpc_x + 19, 2 * setpc_y + 19, 2 * setpc_x + 26, 2 * setpc_y + 26);
}

//----- (004790E0) --------------------------------------------------------
void __fastcall DrawSkelKing(int quest_id, int xx, int yy)
{
  quests[quest_id]._qtx = 2 * xx + 28;
  quests[quest_id]._qty = 2 * yy + 23;
}

//----- (00479123) --------------------------------------------------------
void __fastcall DrawSChamber(int quest_id, int xx, int yy)
{
  unsigned __int8 v3; // dl
  int v4; // [esp+Ch] [ebp-28h]
  int v5; // [esp+10h] [ebp-24h]
  int sendmsg; // [esp+18h] [ebp-1Ch]
  int i; // [esp+1Ch] [ebp-18h]
  int v8; // [esp+20h] [ebp-14h]
  int v9; // [esp+24h] [ebp-10h]
  unsigned __int8 *ptr; // [esp+28h] [ebp-Ch]
  BYTE *v11; // [esp+30h] [ebp-4h]

  v4 = xx;
  v5 = quest_id;
  if ( quests[quest_id]._qactive == 2 )
    ptr = LoadFileInMem("Levels\\L2Data\\Bonestr2.DUN", 0, 279, "Quests.cpp");
  else
    ptr = LoadFileInMem("Levels\\L2Data\\Bonestr1.DUN", 0, 281, "Quests.cpp");
  v9 = *ptr;
  v8 = ptr[2];
  v11 = ptr + 4;
  setpc_w = *ptr;
  setpc_h = v8;
  setpc_x = v4;
  setpc_y = yy;
  for ( sendmsg = yy; yy + v8 > sendmsg; ++sendmsg )
  {
    for ( i = v4; v4 + v9 > i; ++i )
    {
      if ( *v11 )
      {
        v3 = sendmsg;
        dungeon[i][sendmsg] = *v11;
      }
      else
      {
        dungeon[i][sendmsg] = 3;
      }
      v11 += 2;
    }
  }
  quests[v5]._qtx = 2 * v4 + 22;
  quests[v5]._qty = 2 * yy + 23;
  CheckQuestKill(16 * v5, v3);
  mem_free_dbg(ptr, 307, "Quests.cpp");
}

//----- (0047929B) --------------------------------------------------------
void __fastcall DrawLTBanner(int xx, int yy)
{
  int v2; // [esp+Ch] [ebp-20h]
  int v3; // [esp+10h] [ebp-1Ch]
  int i; // [esp+14h] [ebp-18h]
  int j; // [esp+18h] [ebp-14h]
  int v6; // [esp+1Ch] [ebp-10h]
  int v7; // [esp+20h] [ebp-Ch]
  char *v8; // [esp+24h] [ebp-8h]
  unsigned __int8 *ptr; // [esp+28h] [ebp-4h]

  v2 = yy;
  v3 = xx;
  ptr = LoadFileInMem("Levels\\L1Data\\Hero1.DUN", 0, 319, "Quests.cpp");
  v7 = *ptr;
  v6 = ptr[2];
  v8 = (char *)(ptr + 4);
  for ( i = 0; i < v6; ++i )
  {
    for ( j = 0; v7 > j; ++j )
    {
      if ( *v8 )
        pdungeon[j + v3][i + v2] = *v8;
      v8 += 2;
    }
  }
  mem_free_dbg(ptr, 332, "Quests.cpp");
}

//----- (0047936F) --------------------------------------------------------
void __fastcall DrawBlind(int xx, int yy)
{
  int v2; // [esp+Ch] [ebp-20h]
  int v3; // [esp+10h] [ebp-1Ch]
  int i; // [esp+14h] [ebp-18h]
  int j; // [esp+18h] [ebp-14h]
  int v6; // [esp+1Ch] [ebp-10h]
  int v7; // [esp+20h] [ebp-Ch]
  char *v8; // [esp+24h] [ebp-8h]
  unsigned __int8 *pMap; // [esp+28h] [ebp-4h]

  v2 = yy;
  v3 = xx;
  pMap = LoadFileInMem("Levels\\L2Data\\Blind1.DUN", 0, 344, "Quests.cpp");
  SetMapMonsters((char *)pMap, 2 * v3, 2 * v2);
  v7 = *pMap;
  v6 = pMap[2];
  v8 = (char *)(pMap + 4);
  setpc_x = v3;
  setpc_y = v2;
  setpc_w = v7;
  setpc_h = v6;
  for ( i = 0; i < v6; ++i )
  {
    for ( j = 0; j < v7; ++j )
    {
      if ( *v8 )
        pdungeon[j + v3][i + v2] = *v8;
      v8 += 2;
    }
  }
  mem_free_dbg(pMap, 363, "Quests.cpp");
}

//----- (00479476) --------------------------------------------------------
void __fastcall DrawBlood(int xx, int yy)
{
  int v2; // [esp+Ch] [ebp-20h]
  int v3; // [esp+10h] [ebp-1Ch]
  int i; // [esp+14h] [ebp-18h]
  int j; // [esp+18h] [ebp-14h]
  int v6; // [esp+1Ch] [ebp-10h]
  int v7; // [esp+20h] [ebp-Ch]
  BYTE *v8; // [esp+24h] [ebp-8h]
  unsigned __int8 *ptr; // [esp+28h] [ebp-4h]

  v2 = yy;
  v3 = xx;
  ptr = LoadFileInMem("Levels\\L2Data\\Blood2.DUN", 0, 375, "Quests.cpp");
  v7 = *ptr;
  v6 = ptr[2];
  v8 = ptr + 4;
  setpc_x = v3;
  setpc_y = v2;
  setpc_w = v7;
  setpc_h = v6;
  for ( i = 0; i < v6; ++i )
  {
    for ( j = 0; j < v7; ++j )
    {
      if ( *v8 )
        dungeon[v3 + j][v2 + i] = *v8;
      v8 += 2;
    }
  }
  mem_free_dbg(ptr, 397, "Quests.cpp");
}

//----- (0047956A) --------------------------------------------------------
void __fastcall DRLG_CheckQuests(int xx, int yy)
{
  int quest_id; // [esp+18h] [ebp-4h]

  for ( quest_id = 0; quest_id < Xmax_quests; ++quest_id )
  {
    if ( quests[quest_id]._qlevel == currlevel )
    {
      switch ( quests[quest_id]._qtype )
      {
        case 0:
          DrawSkelKing(quest_id, xx, yy);
          break;
        case 1:
          DrawButcher();
          break;
        case 3:
          DrawSChamber(quest_id, xx, yy);
          break;
        case 4:
          DrawLTBanner(xx, yy);
          break;
        case 8:
          DrawBlind(xx, yy);
          break;
        case 9:
          DrawBlood(xx, yy);
          break;
        default:
          continue;
      }
    }
  }
}

//----- (0047967B) --------------------------------------------------------
void __cdecl SetReturnLvlPos()
{
  switch ( setlvlnum )
  {
    case 1:
      ReturnLvlX = quests[0]._qtx + 1;
      ReturnLvlY = quests[0]._qty;
      break;
    case 2:
      ReturnLvlX = quests[3]._qtx + 1;
      if ( quests[3]._qactive == 3 )
        ReturnLvlX += 4;
      ReturnLvlY = quests[3]._qty;
      break;
    case 4:
      ReturnLvlX = quests[5]._qtx + 1;
      ReturnLvlY = quests[5]._qty;
      leveltype = 1;
      break;
  }
}

//----- (00479731) --------------------------------------------------------
void __cdecl unused_sub_479731()
{
  ViewX = ReturnLvlX;
  ViewY = ReturnLvlY;
}

//----- (00479755) --------------------------------------------------------
void unused_sub_479755()
{
  signed int v0; // [esp+Ch] [ebp-Ch]
  int num; // [esp+10h] [ebp-8h]

  if ( quests[1]._qlevel == currlevel && quests[1]._qactive == 2 )
  {
    v0 = 0;
    for ( num = 0; !v0 && num < nummonsters; ++num )
    {
      if ( monster[monstactive[num]].MType->mtype == 51 )
        v0 = 1;
    }
    if ( !v0 )
      monster_402D39(monstactive[nummonsters]);
  }
}

//----- (00479818) --------------------------------------------------------
void __fastcall PrintQLString(int x, int y, unsigned __int8 cjustflag, char *str, int col)
{
  signed int v7; // [esp+14h] [ebp-20h]
  signed int v8; // [esp+1Ch] [ebp-18h]
  signed int i; // [esp+20h] [ebp-14h]
  signed int j; // [esp+20h] [ebp-14h]
  int v11; // [esp+24h] [ebp-10h]
  int No; // [esp+28h] [ebp-Ch]
  int v13; // [esp+2Ch] [ebp-8h]
  char v14; // [esp+30h] [ebp-4h]

  v13 = SStringY[y];
  No = x + screen_y_times_768[v13 + 204] + 96;
  v7 = strlen(str);
  v11 = 0;
  if ( cjustflag )
  {
    v8 = 0;
    for ( i = 0; i < v7; ++i )
      v8 += fontkern[fontframe[str[i] & 0x7F]] + 1;
    if ( v8 < 257 )
      v11 = (257 - v8) >> 1;
    No += v11;
  }
  if ( y == qline )
  {
    if ( cjustflag )
      CelDecodeOnly(x + v11 + 76, v13 + 205, pCelBuff, ALLQUESTS, 12);
    else
      CelDecodeOnly(x + 76, v13 + 205, pCelBuff, ALLQUESTS, 12);
  }
  for ( j = 0; j < v7; ++j )
  {
    v14 = fontframe[str[j] & 0x7F];
    v11 += fontkern[v14] + 1;
    if ( v14 )
    {
      if ( v11 <= 257 )
        CPrintString(No, v14, col);
    }
    No += fontkern[v14] + 1;
  }
  if ( y == qline )
  {
    if ( cjustflag )
      CelDecodeOnly(x + v11 + 100, v13 + 205, pCelBuff, ALLQUESTS, 12);
    else
      CelDecodeOnly(340 - x, v13 + 205, pCelBuff, ALLQUESTS, 12);
  }
}

//----- (00479A00) --------------------------------------------------------
void __cdecl DrawQuestLog()
{
  int y; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]

  PrintQLString(0, 2, 1u, "Quest Log", 3);
  CelDecodeOnly(64, 511, pQLogCel, 1, 320);
  y = 8;
  for ( i = 0; numqlines > i; ++i )
  {
    PrintQLString(0, y, 1u, questlist[qlist[i]]._qlstr, 0);
    y += 2;
  }
  PrintQLString(0, 22, 1u, "Close Quest Log", 0);
  ALLQUESTS = (ALLQUESTS & 7) + 1;
}

//----- (00479ABD) --------------------------------------------------------
void __cdecl StartQuestlog()
{
  unsigned int i; // [esp+Ch] [ebp-4h]

  qline = 8;
  numqlines = 0;
  if ( gbMaxPlayers == 1 )
  {
    for ( i = 0; i < 0xB; ++i )
    {
      if ( quests[i]._qactive == 2 )
        qlist[numqlines++] = i;
    }
  }
  if ( !numqlines )
    qline = 22;
  questlog = 1;
  ALLQUESTS = 1;
}

//----- (00479B6A) --------------------------------------------------------
void __cdecl QuestlogUp()
{
  if ( numqlines )
  {
    if ( qline == 8 )
    {
      qline = 22;
    }
    else if ( qline == 22 )
    {
      qline = 2 * numqlines - 2 + 8;
    }
    else
    {
      qline -= 2;
    }
    PlaySFX(41);
  }
}

//----- (00479BDA) --------------------------------------------------------
void __cdecl QuestlogDown()
{
  if ( numqlines )
  {
    if ( qline == 22 )
    {
      qline = 8;
    }
    else if ( 2 * numqlines - 2 + 8 == qline )
    {
      qline = 22;
    }
    else
    {
      qline += 2;
    }
    PlaySFX(41);
  }
}

//----- (00479C4E) --------------------------------------------------------
void __cdecl QuestlogEnter()
{
  if ( numqlines && qline != 22 )
  {
    PlaySFX(42);
    InitQTextMsg((unsigned __int8)quests[*(int *)((char *)qlist + 2 * ((qline - 8) & 0xFFFFFFFE))]._qvar1);
  }
  questlog = 0;
}

//----- (00479CBA) --------------------------------------------------------
void __cdecl QuestlogESC()
{
  int i; // [esp+Ch] [ebp-8h]
  int v1; // [esp+10h] [ebp-4h]

  v1 = (MouseY - 32) / 12;
  if ( numqlines )
  {
    for ( i = 0; numqlines > i; ++i )
    {
      if ( 2 * i + 8 == v1 )
      {
        qline = v1;
        QuestlogEnter();
      }
    }
  }
  if ( v1 == 22 )
  {
    qline = 22;
    QuestlogEnter();
  }
}

//----- (00479D47) --------------------------------------------------------
void __cdecl QuestlogOff()
{
  questlog = 0;
}

