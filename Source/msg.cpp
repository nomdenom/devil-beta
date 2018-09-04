//----- (00494540) --------------------------------------------------------
int __cdecl msg_wait_resync()
{
  int v0; // ST20_4
  int result; // eax

  if ( !ghMainWnd )
    assertion_failed(294, "C:\\Diablo\\Direct\\msg.cpp");
  if ( sgpMegaPkt )
    assertion_failed(295, "C:\\Diablo\\Direct\\msg.cpp");
  if ( sgpCurrPkt )
    assertion_failed(296, "C:\\Diablo\\Direct\\msg.cpp");
  if ( dword_5FE158 < 0 )
    assertion_failed(297, "C:\\Diablo\\Direct\\msg.cpp");
  msg_get_next_packet();
  gbBufferMsgs = 1;
  sgbDeltaChunks = -1;
  sgnCurrMegaPlayer = -1;
  v0 = UiProgressDialog(ghMainWnd, "Waiting for game data...", 1, msg_wait_for_turns, 20);
  gbBufferMsgs = 0;
  if ( v0 )
  {
    if ( gbGameDestroyed )
    {
      DrawDlg("The game ended");
      msg_free_packets();
      result = 0;
    }
    else if ( sgbDeltaChunks == 19 )
    {
      result = 1;
    }
    else
    {
      DrawDlg("Unable to get level data");
      msg_free_packets();
      result = 0;
    }
  }
  else
  {
    msg_free_packets();
    result = 0;
  }
  return result;
}

//----- (0049468D) --------------------------------------------------------
TMegaPkt *__cdecl msg_get_next_packet()
{
  TMegaPkt *result; // eax
  TMegaPkt *i; // [esp+Ch] [ebp-4h]

  sgpCurrPkt = (TMegaPkt *)DiabloAllocPtr(32008, 162, "C:\\Diablo\\Direct\\msg.cpp");
  sgpCurrPkt->pNext = 0;
  sgpCurrPkt->dwSpaceLeft = 32000;
  for ( i = (TMegaPkt *)&sgpMegaPkt; i->pNext; i = i->pNext )
    ;
  result = sgpCurrPkt;
  i->pNext = sgpCurrPkt;
  return result;
}

//----- (004946FA) --------------------------------------------------------
void __cdecl msg_free_packets()
{
  while ( sgpMegaPkt )
  {
    sgpCurrPkt = sgpMegaPkt->pNext;
    mem_free_dbg(sgpMegaPkt, 177, "C:\\Diablo\\Direct\\msg.cpp");
    sgpMegaPkt = sgpCurrPkt;
  }
}

//----- (00494747) --------------------------------------------------------
int __cdecl msg_wait_for_turns()
{
  int a2; // [esp+Ch] [ebp-8h]
  char pfSendAsync; // [esp+10h] [ebp-4h]

  multi_process_network_packets();
  nthread_send_and_recv_turn(0, 0);
  nthread_recv_turns((int *)&pfSendAsync, &a2);
  if ( a2 )
    multi_41C8BA(1);
  multi_msg_countdown();
  if ( gbGameDestroyed )
    return 100;
  if ( sgbDeltaChunks == 255 )
  {
    if ( !a2 )
      return 0;
    if ( dword_5FE158 >= 0 )
    {
      sgbDeltaChunks = 19;
    }
    else
    {
      dword_5FE158 |= 0x40000000u;
      sgbDeltaChunks = 0;
    }
  }
  else if ( (unsigned int)dword_4DCFB0 < 4 && !dword_5FE0D8[dword_4DCFB0] )
  {
    sgbDeltaChunks = 0;
    return 19;
  }
  return 100 * sgbDeltaChunks / 19;
}

//----- (00494840) --------------------------------------------------------
void __cdecl msg_process_net_packets()
{
  if ( msg_5FF8B4_isprocessing )
  {
    if ( sgpMegaPkt )
      assertion_failed(345, "C:\\Diablo\\Direct\\msg.cpp");
  }
  else
  {
    if ( currlevel )
      assertion_failed(349, "C:\\Diablo\\Direct\\msg.cpp");
    if ( plr[myplr].plrlevel )
      assertion_failed(350, "C:\\Diablo\\Direct\\msg.cpp");
    gbBufferMsgs = 2;
    msg_pre_packet();
    gbBufferMsgs = 0;
    msg_free_packets();
    msg_5FF8B4_isprocessing = 1;
  }
}

//----- (00494901) --------------------------------------------------------
void __cdecl msg_pre_packet()
{
  char *v0; // ST14_4
  int v1; // ST10_4
  signed int v2; // [esp+18h] [ebp-10h]
  char *v3; // [esp+1Ch] [ebp-Ch]
  unsigned int pnum; // [esp+20h] [ebp-8h]
  TMegaPkt *i; // [esp+24h] [ebp-4h]

  pnum = -1;
  for ( i = sgpMegaPkt; i; i = i->pNext )
  {
    v3 = (char *)i->data;
    v2 = 32000;
    while ( i->dwSpaceLeft != v2 )
    {
      if ( *v3 == 87 )
      {
        v0 = v3;
        v3 += 2;
        v2 -= 2;
        pnum = (unsigned __int8)v0[1];
      }
      else
      {
        if ( pnum >= 4 )
          assertion_failed(200, "C:\\Diablo\\Direct\\msg.cpp");
        v1 = ParseCmd(pnum, v3);
        v3 += v1;
        v2 -= v1;
      }
    }
  }
}

//----- (004949D3) --------------------------------------------------------
void __fastcall DeltaExportData(int pnum)
{
  void *v1; // eax
  void *v2; // eax
  void *dst; // ST20_4
  int v4; // ST04_4
  char *v5; // ST20_4
  int v6; // ST04_4
  PkPlayerStruct *buffer; // [esp+14h] [ebp-Ch]
  signed int i; // [esp+1Ch] [ebp-4h]

  buffer = (PkPlayerStruct *)DiabloAllocPtr(5814, 512, "C:\\Diablo\\Direct\\msg.cpp");
  for ( i = 0; i < 17; ++i )
  {
    v1 = DeltaExportItem(&buffer->destParam1, &sgLevels[i]);
    v2 = DeltaExportObject(v1, sgLevels[i].object);
    dst = DeltaExportMonster(v2, sgLevels[i].monster);
    v4 = msg_comp_level(&buffer->destAction, (int)dst);
    multi_41D36B(pnum, i + 61, buffer, v4);
  }
  v5 = DeltaExportJunk(&buffer->destParam1);
  v6 = msg_comp_level(&buffer->destAction, (int)v5);
  multi_41D36B(pnum, 78, buffer, v6);
  multi_41D36B(pnum, 79, buffer, 1);
  mem_free_dbg(buffer, 535, "C:\\Diablo\\Direct\\msg.cpp");
}

//----- (00494B0F) --------------------------------------------------------
void *__fastcall DeltaExportItem(void *dst, void *src)
{
  unsigned __int8 *v3; // [esp+Ch] [ebp-Ch]
  _BYTE *v4; // [esp+10h] [ebp-8h]
  signed int v5; // [esp+14h] [ebp-4h]

  v3 = (unsigned __int8 *)src;
  v4 = dst;
  v5 = 0;
  while ( v5 < 127 )
  {
    if ( *v3 == 255 )
    {
      *v4++ = -1;
    }
    else
    {
      memcpy(v4, v3, 0x12u);
      v4 += 18;
    }
    ++v5;
    v3 += 18;
  }
  return v4;
}

//----- (00494B84) --------------------------------------------------------
void *__fastcall DeltaExportObject(void *dst, void *src)
{
  char *v2; // ST1C_4

  v2 = (char *)dst;
  memcpy(dst, src, 0x7Fu);
  return v2 + 127;
}

//----- (00494BB5) --------------------------------------------------------
void *__fastcall DeltaExportMonster(void *dst, void *src)
{
  unsigned __int8 *v3; // [esp+Ch] [ebp-Ch]
  _BYTE *v4; // [esp+10h] [ebp-8h]
  signed int v5; // [esp+14h] [ebp-4h]

  v3 = (unsigned __int8 *)src;
  v4 = dst;
  v5 = 0;
  while ( v5 < 200 )
  {
    if ( *v3 == 255 )
    {
      *v4++ = -1;
    }
    else
    {
      memcpy(v4, v3, 9u);
      v4 += 9;
    }
    ++v5;
    v3 += 9;
  }
  return v4;
}

//----- (00494C2D) --------------------------------------------------------
char *__fastcall DeltaExportJunk(char *a1)
{
  char *v2; // [esp+Ch] [ebp-8h]
  signed int i; // [esp+10h] [ebp-4h]

  v2 = a1;
  for ( i = 0; i < 4; ++i )
  {
    if ( sgJunk.portal[i].x == 255 )
    {
      *v2++ = -1;
    }
    else
    {
      memcpy(v2, &sgJunk.portal[i], 4u);
      v2 += 4;
    }
  }
  return v2;
}

//----- (00494CA7) --------------------------------------------------------
int __fastcall msg_comp_level(char *buffer, int size)
{
  int v2; // ST18_4
  int v5; // [esp+14h] [ebp-8h]

  v2 = size - (_DWORD)buffer - 1;
  v5 = encrypt_compress(buffer + 1, v2);
  *buffer = v5 != v2;
  return v5 + 1;
}

//----- (00494CFC) --------------------------------------------------------
void __cdecl delta_init()
{
  signed int i; // [esp+Ch] [ebp-4h]

  dword_5FE158 = 0;
  memset(&sgJunk, 255, 16u);
  memset(sgLevels, 255, 0x18205u);
  for ( i = 0; i < 17; ++i )
    memset(sgLevels[i].automap, 0, 0x640u);
  dword_4DCFB0 = -1;
  deltaload = 0;
}

//----- (00494DA7) --------------------------------------------------------
void __fastcall delta_kill_monster(int mi, unsigned __int8 x, unsigned __int8 y, unsigned __int8 bLevel)
{
  DMonsterStr *v4; // ST14_4

  dword_5FE158 |= 0x80000000;
  v4 = &sgLevels[bLevel].monster[mi];
  v4->_mx = x;
  v4->_my = y;
  v4->_mdir = monster[mi]._mdir;
  v4->_mhitpoints = 0;
}

//----- (00494E2F) --------------------------------------------------------
void __fastcall delta_monster_hp(int mi, int hp, unsigned __int8 bLevel)
{
  dword_5FE158 |= 0x80000000;
  if ( sgLevels[bLevel].monster[mi]._mhitpoints > hp )
    sgLevels[bLevel].monster[mi]._mhitpoints = hp;
}

//----- (00494E9A) --------------------------------------------------------
void __fastcall delta_sync_monster(TSyncMonster *p, BYTE level)
{
  int v2; // eax
  int v3; // ecx

  dword_5FE158 |= 0x80000000;
  v2 = p->_mndx;
  v3 = level;
  if ( sgLevels[v3].monster[v2]._mhitpoints )
  {
    sgLevels[v3].monster[v2]._mx = p->_mx;
    sgLevels[v3].monster[v2]._my = p->_my;
    sgLevels[v3].monster[v2]._mactive = -1;
    sgLevels[v3].monster[v2]._menemy = p->_menemy;
  }
}

//----- (00494F2B) --------------------------------------------------------
void __fastcall delta_leave_sync(unsigned __int8 bLevel)
{
  DMonsterStr *v1; // ST1C_4
  int v3; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  if ( !currlevel )
    glSeedTbl[0] = GetRndSeed();
  if ( (signed int)currlevel > 0 )
  {
    for ( i = 0; i < nummonsters; ++i )
    {
      v3 = monstactive[i];
      if ( monster[v3]._mhitpoints )
      {
        dword_5FE158 |= 0x80000000;
        v1 = &sgLevels[bLevel].monster[v3];
        v1->_mx = monster[v3]._mx;
        v1->_my = monster[v3]._my;
        v1->_mdir = monster[v3]._mdir;
        v1->_menemy = monster[v3]._menemy;
        v1->_mhitpoints = monster[v3]._mhitpoints;
        v1->_mactive = monster[v3]._msquelch;
      }
    }
    memcpy(sgLevels[bLevel].automap, automapview, 0x640u);
  }
}

//----- (004950C6) --------------------------------------------------------
BOOL __fastcall delta_portal_inited(int portal_num)
{
  return sgJunk.portal[portal_num].x == 255;
}

//----- (00495105) --------------------------------------------------------
void __fastcall DeltaAddItem(int ii)
{
  TCmdPItem *v1; // [esp+10h] [ebp-8h]
  TCmdPItem *v2; // [esp+10h] [ebp-8h]
  signed int v3; // [esp+14h] [ebp-4h]
  signed int v4; // [esp+14h] [ebp-4h]

  v1 = sgLevels[currlevel].item;
  v3 = 0;
  while ( v3 < 127 )
  {
    if ( (unsigned __int8)v1->bCmd != 255
      && item[ii].IDidx == v1->wIndx
      && item[ii]._iCreateInfo == v1->wCI
      && item[ii]._iSeed == v1->dwSeed
      && (v1->bCmd == 1 || !v1->bCmd) )
    {
      return;
    }
    ++v3;
    ++v1;
  }
  v2 = sgLevels[currlevel].item;
  v4 = 0;
  while ( v4 < 127 )
  {
    if ( (unsigned __int8)v2->bCmd == 255 )
    {
      dword_5FE158 |= 0x80000000;
      v2->bCmd = 0;
      v2->x = item[ii]._ix;
      v2->y = item[ii]._iy;
      v2->wIndx = item[ii].IDidx;
      v2->wCI = item[ii]._iCreateInfo;
      v2->dwSeed = item[ii]._iSeed;
      v2->bId = item[ii]._iIdentified;
      v2->bDur = item[ii]._iDurability;
      v2->bMDur = item[ii]._iMaxDur;
      v2->bCh = item[ii]._iCharges;
      v2->bMCh = item[ii]._iMaxCharges;
      v2->wValue = item[ii]._ivalue;
      return;
    }
    ++v4;
    ++v2;
  }
}

//----- (004953AF) --------------------------------------------------------
void __cdecl DeltaSaveLevel()
{
  signed int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 4; ++i )
  {
    if ( i != myplr )
      plr[i]._pGFXLoad = 0;
  }
  if ( currlevel >= 0x11u )
    assertion_failed(887, "C:\\Diablo\\Direct\\msg.cpp");
  plr[myplr]._pLvlVisited[currlevel] = 1;
  delta_leave_sync(currlevel);
}

//----- (00495467) --------------------------------------------------------
void __cdecl DeltaLoadLevel()
{
  int i; // [esp+14h] [ebp-8h]
  int ia; // [esp+14h] [ebp-8h]
  int ib; // [esp+14h] [ebp-8h]
  int ic; // [esp+14h] [ebp-8h]
  int ii; // [esp+18h] [ebp-4h]
  int iia; // [esp+18h] [ebp-4h]
  int iib; // [esp+18h] [ebp-4h]

  deltaload = 1;
  if ( currlevel )
  {
    for ( i = 0; i < 200; ++i )
    {
      if ( sgLevels[currlevel].monster[i]._mx != 255 )
      {
        M_ClearSquares(i);
        monster[i]._mx = sgLevels[currlevel].monster[i]._mx;
        monster[i]._my = sgLevels[currlevel].monster[i]._my;
        if ( sgLevels[currlevel].monster[i]._mhitpoints != -1 )
          monster[i]._mhitpoints = sgLevels[currlevel].monster[i]._mhitpoints;
        if ( sgLevels[currlevel].monster[i]._mhitpoints )
        {
          monster[i]._menemy = sgLevels[currlevel].monster[i]._menemy;
          dMonster[monster[i]._mx][monster[i]._my] = i + 1;
          M_StartStand(i, monster[i]._mdir);
          monster[i]._msquelch = sgLevels[currlevel].monster[i]._mactive;
        }
        else
        {
          monster[i]._moldx = sgLevels[currlevel].monster[i]._mx;
          monster[i]._moldy = sgLevels[currlevel].monster[i]._my;
          M_ClearSquares(i);
          if ( monster[i]._uniqtype )
            AddDead(monster[i]._mx, monster[i]._my, monster[i]._udeadval, monster[i]._mdir);
          else
            AddDead(monster[i]._mx, monster[i]._my, monster[i].MType->mdeadval, monster[i]._mdir);
          monster[i]._mDelFlag = 1;
          M_UpdateLeader(i);
        }
      }
    }
    memcpy(automapview, sgLevels[currlevel].automap, 0x640u);
  }
  for ( ia = 0; ia < 127; ++ia )
  {
    if ( (unsigned __int8)sgLevels[currlevel].item[ia].bCmd != 255 )
    {
      if ( sgLevels[currlevel].item[ia].bCmd == 1 )
      {
        ii = FindGetItem(
               sgLevels[currlevel].item[ia].wIndx,
               sgLevels[currlevel].item[ia].wCI,
               sgLevels[currlevel].item[ia].dwSeed);
        if ( ii == -1 )
          assertion_failed(945, "C:\\Diablo\\Direct\\msg.cpp");
        if ( dItem[item[ii]._ix][item[ii]._iy] == ii + 1 )
          dItem[item[ii]._ix][item[ii]._iy] = 0;
        DeleteItem(ii, ia);
      }
      if ( sgLevels[currlevel].item[ia].bCmd == 2 )
      {
        iia = itemavail[0];
        itemavail[0] = itemavail[127 - numitems - 1];
        itemactive[numitems] = iia;
        RecreateItem(
          iia,
          sgLevels[currlevel].item[ia].wIndx,
          sgLevels[currlevel].item[ia].wCI,
          sgLevels[currlevel].item[ia].dwSeed,
          sgLevels[currlevel].item[ia].wValue);
        item[iia]._ix = sgLevels[currlevel].item[ia].x;
        item[iia]._iy = sgLevels[currlevel].item[ia].y;
        dItem[item[iia]._ix][item[iia]._iy] = iia + 1;
        if ( sgLevels[currlevel].item[ia].bId )
          item[iia]._iIdentified = 1;
        item[iia]._iDurability = sgLevels[currlevel].item[ia].bDur;
        item[iia]._iMaxDur = sgLevels[currlevel].item[ia].bMDur;
        item[iia]._iCharges = sgLevels[currlevel].item[ia].bCh;
        item[iia]._iMaxCharges = sgLevels[currlevel].item[ia].bMCh;
        RespawnItem(iia, 0);
        ++numitems;
      }
    }
  }
  if ( currlevel )
  {
    for ( ib = 0; ib < 127; ++ib )
    {
      switch ( sgLevels[currlevel].object[ib].bCmd )
      {
        case CMD_OPENDOOR:
        case CMD_CLOSEDOOR:
        case CMD_OPERATEOBJ:
        case CMD_PLROPOBJ:
          SyncOpObject(-1, sgLevels[currlevel].object[ib].bCmd, ib);
          break;
        case CMD_BREAKOBJ:
          SyncBreakObj(-1, ib);
          break;
        case X_CMD_LAST:
          continue;
      }
    }
    for ( ic = 0; nobjects > ic; ++ic )
    {
      iib = objectactive[ic];
      if ( object[iib]._otype == 53 || object[iib]._otype == 54 )
        Obj_Trap(iib);
    }
  }
  deltaload = 0;
}

//----- (00495FC5) --------------------------------------------------------
void __fastcall NetSendCmd(unsigned __int8 bHiPri, unsigned __int8 bCmd)
{
  unsigned __int8 pbMsg; // [esp+14h] [ebp-4h]

  pbMsg = bCmd;
  if ( bHiPri )
    NetSendHiPri_1(&pbMsg, 1u);
  else
    NetSendLoPri(&pbMsg, 1u);
}

//----- (0049600D) --------------------------------------------------------
void __fastcall NetSendCmdLoc(unsigned __int8 bHiPri, unsigned __int8 bCmd, unsigned __int8 x, unsigned __int8 y)
{
  char pbMsg[3]; // [esp+14h] [ebp-4h]

  pbMsg[0] = bCmd;
  pbMsg[1] = x;
  pbMsg[2] = y;
  if ( bHiPri )
    NetSendHiPri_1(pbMsg, 3u);
  else
    NetSendLoPri((unsigned __int8 *)pbMsg, 3u);
}

//----- (00496063) --------------------------------------------------------
void __fastcall NetSendCmdLocParam1(unsigned __int8 bHiPri, unsigned __int8 bCmd, unsigned __int8 x, unsigned __int8 y, int wParam1)
{
  char pbMsg[5]; // [esp+14h] [ebp-8h]

  pbMsg[0] = bCmd;
  pbMsg[1] = x;
  pbMsg[2] = y;
  *(_WORD *)&pbMsg[3] = wParam1;
  if ( bHiPri )
    NetSendHiPri_1(pbMsg, 5u);
  else
    NetSendLoPri((unsigned __int8 *)pbMsg, 5u);
}

//----- (004960C1) --------------------------------------------------------
void __fastcall NetSendCmdLocParam2(unsigned __int8 bHiPri, unsigned __int8 bCmd, unsigned __int8 x, unsigned __int8 y, int wParam1, int wParam2)
{
  char pbMsg[7]; // [esp+14h] [ebp-8h]

  pbMsg[0] = bCmd;
  pbMsg[1] = x;
  pbMsg[2] = y;
  *(_WORD *)&pbMsg[3] = wParam1;
  *(_WORD *)&pbMsg[5] = wParam2;
  if ( bHiPri )
    NetSendHiPri_1(pbMsg, 7u);
  else
    NetSendLoPri((unsigned __int8 *)pbMsg, 7u);
}

//----- (00496127) --------------------------------------------------------
void __fastcall NetSendCmdParam1(unsigned __int8 bHiPri, BYTE bCmd, unsigned __int16 wParam1)
{
  char buf[3]; // [esp+14h] [ebp-4h]

  buf[0] = bCmd;
  *(_WORD *)&buf[1] = wParam1;
  if ( bHiPri )
    NetSendHiPri_1(buf, 3u);
  else
    NetSendLoPri((unsigned __int8 *)buf, 3u);
}

//----- (00496179) --------------------------------------------------------
void __fastcall NetSendCmdParam2(unsigned __int8 bHiPri, unsigned __int8 bCmd, unsigned __int16 wParam1, unsigned __int16 wParam2)
{
  char pbMsg[5]; // [esp+14h] [ebp-8h]

  pbMsg[0] = bCmd;
  *(_WORD *)&pbMsg[1] = wParam1;
  *(_WORD *)&pbMsg[3] = wParam2;
  if ( bHiPri )
    NetSendHiPri_1(pbMsg, 5u);
  else
    NetSendLoPri((unsigned __int8 *)pbMsg, 5u);
}

//----- (004961D3) --------------------------------------------------------
void __fastcall NetSendCmdGItem(unsigned __int8 bHiPri, unsigned __int8 bCmd, unsigned __int8 mast, unsigned __int8 pnum, BYTE ii)
{
  BYTE pbMsg[25]; // [esp+14h] [ebp-1Ch]

  pbMsg[0] = bCmd;
  pbMsg[2] = pnum;
  pbMsg[1] = mast;
  pbMsg[3] = ii;
  pbMsg[4] = item[ii]._ix;
  pbMsg[5] = item[ii]._iy;
  *(_WORD *)&pbMsg[6] = item[ii].IDidx;
  *(_WORD *)&pbMsg[8] = item[ii]._iCreateInfo;
  *(_DWORD *)&pbMsg[10] = item[ii]._iSeed;
  pbMsg[14] = item[ii]._iIdentified;
  pbMsg[15] = item[ii]._iDurability;
  pbMsg[16] = item[ii]._iMaxDur;
  pbMsg[17] = item[ii]._iCharges;
  pbMsg[18] = item[ii]._iMaxCharges;
  *(_WORD *)&pbMsg[19] = item[ii]._ivalue;
  if ( bHiPri )
    NetSendHiPri_1(pbMsg, 25u);
  else
    NetSendLoPri(pbMsg, 25u);
}

//----- (00496346) --------------------------------------------------------
void __fastcall NetSendCmdGItem2(unsigned __int8 usonly, unsigned __int8 bCmd, unsigned __int8 mast, unsigned __int8 pnum, struct TCmdGItem *p)
{
  int v6; // ST1C_4
  int *v7; // [esp+0h] [ebp-34h]
  DWORD v8; // [esp+14h] [ebp-20h]
  char packet[25]; // [esp+18h] [ebp-1Ch]

  v6 = usonly;
  memcpy(packet, p, 0x19u);
  packet[0] = bCmd;
  packet[2] = pnum;
  packet[1] = mast;
  if ( !v6 )
  {
    *(_DWORD *)&packet[21] = 0;
    NetSendHiPri_1(packet, 0x19u);
    return;
  }
  v8 = GetTickCount();
  if ( *(_DWORD *)&packet[21] )
  {
    if ( (signed int)(v8 - *(_DWORD *)&packet[21]) > 5000 )
      return;
  }
  else
  {
    *(_DWORD *)&packet[21] = v8;
  }
  multi_recv_packet(packet, 0x19u, v7);
}

//----- (004963E9) --------------------------------------------------------
void __fastcall NetSendCmdPItem(unsigned __int8 bHiPri, unsigned __int8 bCmd, unsigned __int8 x, unsigned __int8 y)
{
  char pbMsg[18]; // [esp+14h] [ebp-14h]

  pbMsg[0] = bCmd;
  pbMsg[1] = x;
  pbMsg[2] = y;
  *(_WORD *)&pbMsg[3] = plr[myplr].HoldItem.IDidx;
  *(_WORD *)&pbMsg[5] = plr[myplr].HoldItem._iCreateInfo;
  *(_DWORD *)&pbMsg[7] = plr[myplr].HoldItem._iSeed;
  pbMsg[11] = plr[myplr].HoldItem._iIdentified;
  pbMsg[12] = plr[myplr].HoldItem._iDurability;
  pbMsg[13] = plr[myplr].HoldItem._iMaxDur;
  pbMsg[14] = plr[myplr].HoldItem._iCharges;
  pbMsg[15] = plr[myplr].HoldItem._iMaxCharges;
  *(_WORD *)&pbMsg[16] = plr[myplr].HoldItem._ivalue;
  if ( bHiPri )
    NetSendHiPri_1(pbMsg, 0x12u);
  else
    NetSendLoPri((unsigned __int8 *)pbMsg, 0x12u);
}

//----- (00496575) --------------------------------------------------------
void __fastcall NetSendCmdChItem(unsigned __int8 bHiPri, unsigned __int8 bLoc)
{
  char pbMsg[10]; // [esp+14h] [ebp-Ch]

  pbMsg[0] = 51;
  pbMsg[1] = bLoc;
  *(_WORD *)&pbMsg[2] = plr[myplr].HoldItem.IDidx;
  *(_WORD *)&pbMsg[4] = plr[myplr].HoldItem._iCreateInfo;
  *(_DWORD *)&pbMsg[6] = plr[myplr].HoldItem._iSeed;
  if ( bHiPri )
    NetSendHiPri_1(pbMsg, 0xAu);
  else
    NetSendLoPri((unsigned __int8 *)pbMsg, 0xAu);
}

//----- (0049662A) --------------------------------------------------------
void __fastcall NetSendCmdDelItem(unsigned __int8 bHiPri, unsigned __int8 bLoc)
{
  char pbMsg[2]; // [esp+14h] [ebp-4h]

  pbMsg[0] = 52;
  pbMsg[1] = bLoc;
  if ( bHiPri )
    NetSendHiPri_1(pbMsg, 2u);
  else
    NetSendLoPri((unsigned __int8 *)pbMsg, 2u);
}

//----- (00496676) --------------------------------------------------------
void __fastcall NetSendCmdDItem(unsigned __int8 bHiPri, int ii)
{
  char pbMsg[18]; // [esp+14h] [ebp-14h]

  pbMsg[0] = 55;
  pbMsg[1] = item[ii]._ix;
  pbMsg[2] = item[ii]._iy;
  *(_WORD *)&pbMsg[3] = item[ii].IDidx;
  *(_WORD *)&pbMsg[5] = item[ii]._iCreateInfo;
  *(_DWORD *)&pbMsg[7] = item[ii]._iSeed;
  pbMsg[11] = item[ii]._iIdentified;
  pbMsg[12] = item[ii]._iDurability;
  pbMsg[13] = item[ii]._iMaxDur;
  pbMsg[14] = item[ii]._iCharges;
  pbMsg[15] = item[ii]._iMaxCharges;
  *(_WORD *)&pbMsg[16] = item[ii]._ivalue;
  if ( bHiPri )
    NetSendHiPri_1(pbMsg, 0x12u);
  else
    NetSendLoPri((unsigned __int8 *)pbMsg, 0x12u);
}

//----- (004967BD) --------------------------------------------------------
void __fastcall NetSendCmdDamage(unsigned __int8 bHiPri, unsigned __int8 bPlr, unsigned int dwDam)
{
  char pbMsg[6]; // [esp+14h] [ebp-8h]

  pbMsg[0] = 53;
  pbMsg[1] = bPlr;
  *(_DWORD *)&pbMsg[2] = dwDam;
  if ( bHiPri )
    NetSendHiPri_1(pbMsg, 6u);
  else
    NetSendLoPri((unsigned __int8 *)pbMsg, 6u);
}

//----- (00496811) --------------------------------------------------------
void __fastcall NetSendCmdString(int a1, const char *pszStr)
{
  char a2; // [esp+14h] [ebp-58h]
  char v5[81]; // [esp+15h] [ebp-57h]
  size_t v6; // [esp+68h] [ebp-4h]

  if ( !pszStr )
    assertion_failed(1278, "C:\\Diablo\\Direct\\msg.cpp");
  v6 = strlen(pszStr);
  if ( v6 >= 0x50 )
    assertion_failed(1282, "C:\\Diablo\\Direct\\msg.cpp");
  a2 = 81;
  strcpy(v5, pszStr);
  multi_send_msg_packet(a1, (unsigned __int8 *)&a2, v6 + 2);
}

//----- (0049689B) --------------------------------------------------------
int __fastcall ParseCmd(int pnum, char *pCmd)
{
  int v3; // eax
  int v4; // eax
  int v5; // STC8_4
  int v6; // eax
  char *v7; // eax
  unsigned int v8; // [esp+0h] [ebp-110h]
  int v9; // [esp+4h] [ebp-10Ch]
  int v10; // [esp+8h] [ebp-108h]
  int v13; // [esp+9Ch] [ebp-74h]
  int v14; // [esp+D0h] [ebp-40h]
  int v15; // [esp+DCh] [ebp-34h]
  int v16; // [esp+ECh] [ebp-24h]

  sbLastCmd = *pCmd;
  switch ( *pCmd )
  {
    case CMD_WALKXY:
      if ( gbBufferMsgs == 2 )
        assertion_failed(1356, "C:\\Diablo\\Direct\\msg.cpp");
      if ( gbBufferMsgs != 1 && plr[pnum].plrlevel == currlevel )
      {
        MakePlrPath(pnum, (unsigned __int8)pCmd[1], (unsigned __int8)pCmd[2], 1u);
        plr[pnum].destAction = -1;
      }
      return 3;
    case CMD_XXX_1:
      if ( pnum != myplr )
        multi_41D54D(pnum, 4);
      return 1;
    case CMD_XXX_2:
      if ( gbBufferMsgs == 1 )
        msg_send_packet(pnum, pCmd, *(unsigned __int16 *)(pCmd + 3) + 5);
      else
        multi_player_joins(pnum, (TCmdPlrInfoHdr *)pCmd, 1);
      return *(unsigned __int16 *)(pCmd + 3) + 5;
    case CMD_ADDSTR:
      if ( gbBufferMsgs == 1 )
        msg_send_packet(pnum, pCmd, 3);
      else
        ModifyPlrStr(pnum, *(unsigned __int16 *)(pCmd + 1));
      return 3;
    case CMD_ADDMAG:
      if ( gbBufferMsgs == 1 )
        msg_send_packet(pnum, pCmd, 3);
      else
        ModifyPlrMag(pnum, *(unsigned __int16 *)(pCmd + 1));
      return 3;
    case CMD_ADDDEX:
      if ( gbBufferMsgs == 1 )
        msg_send_packet(pnum, pCmd, 3);
      else
        ModifyPlrDex(pnum, *(unsigned __int16 *)(pCmd + 1));
      return 3;
    case CMD_ADDVIT:
      if ( gbBufferMsgs == 1 )
        msg_send_packet(pnum, pCmd, 3);
      else
        ModifyPlrVit(pnum, *(unsigned __int16 *)(pCmd + 1));
      return 3;
    case CMD_SBSPELL:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 3);
      }
      else
      {
        plr[pnum]._pSpell = *(unsigned __int16 *)(pCmd + 1);
        plr[pnum]._pSplType = plr[pnum]._pSBkSplType;
        plr[pnum]._pSplFrom = 1;
        plr[pnum].destAction = 12;
      }
      return 3;
    case CMD_GETITEM:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 25);
      }
      else if ( delta_get_item((TCmdGItem *)pCmd, plr[pnum].plrlevel) )
      {
        if ( plr[pnum].plrlevel == currlevel && (unsigned __int8)pCmd[1] != myplr )
        {
          if ( (unsigned __int8)pCmd[2] == myplr )
            InvGetItem(myplr, (unsigned __int8)pCmd[3]);
          else
            SyncGetItem(
              (unsigned __int8)pCmd[4],
              (unsigned __int8)pCmd[5],
              *((unsigned __int16 *)pCmd + 3),
              *((_WORD *)pCmd + 4),
              *(_DWORD *)(pCmd + 10));
        }
      }
      else
      {
        NetSendCmdGItem2(1u, 0xAu, pCmd[1], pCmd[2], (struct TCmdGItem *)pCmd);
      }
      return 25;
    case CMD_AGETITEM:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 25);
      }
      else if ( delta_get_item((TCmdGItem *)pCmd, plr[pnum].plrlevel) )
      {
        if ( plr[pnum].plrlevel == currlevel && (unsigned __int8)pCmd[1] != myplr )
        {
          if ( (unsigned __int8)pCmd[2] == myplr )
            AutoGetItem(myplr, (unsigned __int8)pCmd[3]);
          else
            SyncGetItem(
              (unsigned __int8)pCmd[4],
              (unsigned __int8)pCmd[5],
              *((unsigned __int16 *)pCmd + 3),
              *((_WORD *)pCmd + 4),
              *(_DWORD *)(pCmd + 10));
        }
      }
      else
      {
        NetSendCmdGItem2(1u, 0xBu, pCmd[1], pCmd[2], (struct TCmdGItem *)pCmd);
      }
      return 25;
    case CMD_PUTITEM:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 18);
      }
      else
      {
        if ( plr[pnum].plrlevel == currlevel )
        {
          if ( pnum == myplr )
          {
            v14 = InvPutItem(pnum, (unsigned __int8)pCmd[1], (unsigned __int8)pCmd[2]);
          }
          else
          {
            HIWORD(v3) = HIWORD(pCmd);
            LOWORD(v3) = *(_WORD *)(pCmd + 5);
            v14 = SyncPutItem(
                    pnum,
                    (unsigned __int8)pCmd[1],
                    (unsigned __int8)pCmd[2],
                    *(unsigned __int16 *)(pCmd + 3),
                    v3,
                    *(_DWORD *)(pCmd + 7),
                    (unsigned __int8)pCmd[11],
                    (unsigned __int8)pCmd[12],
                    (unsigned __int8)pCmd[13],
                    (unsigned __int8)pCmd[14],
                    (unsigned __int8)pCmd[15],
                    *((unsigned __int16 *)pCmd + 8),
                    v8);
          }
          if ( v14 != -1 )
          {
            delta_put_item((struct TCmdPItem *)pCmd, item[v14]._ix, item[v14]._iy, plr[pnum].plrlevel);
            return 18;
          }
        }
        delta_put_item((struct TCmdPItem *)pCmd, (unsigned __int8)pCmd[1], (unsigned __int8)pCmd[2], plr[pnum].plrlevel);
        check_update_plr(pnum);
      }
      return 18;
    case CMD_RESPAWNITEM:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 18);
      }
      else
      {
        if ( plr[pnum].plrlevel == currlevel && pnum != myplr )
        {
          HIWORD(v4) = HIWORD(pCmd);
          LOWORD(v4) = *(_WORD *)(pCmd + 5);
          SyncPutItem(
            pnum,
            (unsigned __int8)pCmd[1],
            (unsigned __int8)pCmd[2],
            *(unsigned __int16 *)(pCmd + 3),
            v4,
            *(_DWORD *)(pCmd + 7),
            (unsigned __int8)pCmd[11],
            (unsigned __int8)pCmd[12],
            (unsigned __int8)pCmd[13],
            (unsigned __int8)pCmd[14],
            (unsigned __int8)pCmd[15],
            *((unsigned __int16 *)pCmd + 8),
            v8);
        }
        delta_put_item((struct TCmdPItem *)pCmd, (unsigned __int8)pCmd[1], (unsigned __int8)pCmd[2], plr[pnum].plrlevel);
      }
      return 18;
    case CMD_ATTACKXY:
      if ( gbBufferMsgs == 2 )
        assertion_failed(1576, "C:\\Diablo\\Direct\\msg.cpp");
      if ( gbBufferMsgs != 1 && plr[pnum].plrlevel == currlevel )
      {
        MakePlrPath(pnum, (unsigned __int8)pCmd[1], (unsigned __int8)pCmd[2], 0);
        plr[pnum].destAction = 9;
        plr[pnum].destParam1 = (unsigned __int8)pCmd[1];
        plr[pnum].destParam2 = (unsigned __int8)pCmd[2];
      }
      return 3;
    case CMD_RATTACKXY:
      if ( gbBufferMsgs == 2 )
        assertion_failed(1604, "C:\\Diablo\\Direct\\msg.cpp");
      if ( gbBufferMsgs != 1 && plr[pnum].plrlevel == currlevel )
      {
        ClrPlrPath(pnum);
        plr[pnum].destAction = 10;
        plr[pnum].destParam1 = (unsigned __int8)pCmd[1];
        plr[pnum].destParam2 = (unsigned __int8)pCmd[2];
      }
      return 3;
    case CMD_SPELLXY:
      if ( gbBufferMsgs == 2 )
        assertion_failed(1618, "C:\\Diablo\\Direct\\msg.cpp");
      if ( gbBufferMsgs != 1 && plr[pnum].plrlevel == currlevel )
      {
        ClrPlrPath(pnum);
        plr[pnum].destAction = 12;
        plr[pnum].destParam1 = (unsigned __int8)pCmd[1];
        plr[pnum].destParam2 = (unsigned __int8)pCmd[2];
        plr[pnum]._pSpell = *(unsigned __int16 *)(pCmd + 3);
        plr[pnum]._pSplType = plr[pnum]._pRSplType;
        plr[pnum]._pSplFrom = 0;
      }
      return 5;
    case CMD_TSPELLXY:
      if ( gbBufferMsgs == 2 )
        assertion_failed(1635, "C:\\Diablo\\Direct\\msg.cpp");
      if ( gbBufferMsgs != 1 && plr[pnum].plrlevel == currlevel )
      {
        ClrPlrPath(pnum);
        plr[pnum].destAction = 12;
        plr[pnum].destParam1 = (unsigned __int8)pCmd[1];
        plr[pnum].destParam2 = (unsigned __int8)pCmd[2];
        plr[pnum]._pSpell = *(unsigned __int16 *)(pCmd + 3);
        plr[pnum]._pSplType = plr[pnum]._pTSplType;
        plr[pnum]._pSplFrom = 2;
      }
      return 5;
    case CMD_OPOBJXY:
      if ( gbBufferMsgs == 2 )
        assertion_failed(1652, "C:\\Diablo\\Direct\\msg.cpp");
      if ( gbBufferMsgs != 1 && plr[pnum].plrlevel == currlevel )
      {
        if ( object[*(unsigned __int16 *)(pCmd + 3)]._oSolidFlag || object[*(unsigned __int16 *)(pCmd + 3)]._oDoorFlag )
          MakePlrPath(pnum, (unsigned __int8)pCmd[1], (unsigned __int8)pCmd[2], 0);
        else
          MakePlrPath(pnum, (unsigned __int8)pCmd[1], (unsigned __int8)pCmd[2], 1u);
        plr[pnum].destAction = 13;
        plr[pnum].destParam1 = *(unsigned __int16 *)(pCmd + 3);
      }
      return 5;
    case CMD_DISARMXY:
      if ( gbBufferMsgs == 2 )
        assertion_failed(1668, "C:\\Diablo\\Direct\\msg.cpp");
      if ( gbBufferMsgs != 1 && plr[pnum].plrlevel == currlevel )
      {
        if ( object[*(unsigned __int16 *)(pCmd + 3)]._oSolidFlag || object[*(unsigned __int16 *)(pCmd + 3)]._oDoorFlag )
          MakePlrPath(pnum, (unsigned __int8)pCmd[1], (unsigned __int8)pCmd[2], 0);
        else
          MakePlrPath(pnum, (unsigned __int8)pCmd[1], (unsigned __int8)pCmd[2], 1u);
        plr[pnum].destAction = 14;
        plr[pnum].destParam1 = *(unsigned __int16 *)(pCmd + 3);
      }
      return 5;
    case CMD_ATTACKID:
      if ( gbBufferMsgs == 2 )
        assertion_failed(1696, "C:\\Diablo\\Direct\\msg.cpp");
      if ( gbBufferMsgs != 1 && plr[pnum].plrlevel == currlevel )
      {
        v5 = abs(plr[pnum].WorldX - monster[*(unsigned __int16 *)(pCmd + 1)]._mfutx);
        v13 = abs(plr[pnum].WorldY - monster[*(unsigned __int16 *)(pCmd + 1)]._mfuty);
        if ( v5 > 1 || v13 > 1 )
          MakePlrPath(
            pnum,
            monster[*(unsigned __int16 *)(pCmd + 1)]._mfutx,
            monster[*(unsigned __int16 *)(pCmd + 1)]._mfuty,
            0);
        plr[pnum].destAction = 20;
        plr[pnum].destParam1 = *(unsigned __int16 *)(pCmd + 1);
      }
      return 3;
    case CMD_ATTACKPID:
      if ( gbBufferMsgs == 2 )
        assertion_failed(1712, "C:\\Diablo\\Direct\\msg.cpp");
      if ( gbBufferMsgs != 1 && plr[pnum].plrlevel == currlevel )
      {
        MakePlrPath(pnum, plr[*(unsigned __int16 *)(pCmd + 1)]._px, plr[*(unsigned __int16 *)(pCmd + 1)]._py, 0);
        plr[pnum].destAction = 21;
        plr[pnum].destParam1 = *(unsigned __int16 *)(pCmd + 1);
      }
      return 3;
    case CMD_RATTACKID:
      if ( gbBufferMsgs == 2 )
        assertion_failed(1725, "C:\\Diablo\\Direct\\msg.cpp");
      if ( gbBufferMsgs != 1 && plr[pnum].plrlevel == currlevel )
      {
        ClrPlrPath(pnum);
        plr[pnum].destAction = 22;
        plr[pnum].destParam1 = *(unsigned __int16 *)(pCmd + 1);
      }
      return 3;
    case CMD_RATTACKPID:
      if ( gbBufferMsgs == 2 )
        assertion_failed(1738, "C:\\Diablo\\Direct\\msg.cpp");
      if ( gbBufferMsgs != 1 && plr[pnum].plrlevel == currlevel )
      {
        ClrPlrPath(pnum);
        plr[pnum].destAction = 23;
        plr[pnum].destParam1 = *(unsigned __int16 *)(pCmd + 1);
      }
      return 3;
    case CMD_SPELLID:
      if ( gbBufferMsgs == 2 )
        assertion_failed(1751, "C:\\Diablo\\Direct\\msg.cpp");
      if ( gbBufferMsgs != 1 && plr[pnum].plrlevel == currlevel )
      {
        ClrPlrPath(pnum);
        plr[pnum].destAction = 24;
        plr[pnum].destParam1 = *(unsigned __int16 *)(pCmd + 1);
        plr[pnum]._pSpell = *(unsigned __int16 *)(pCmd + 3);
        plr[pnum]._pSplType = plr[pnum]._pRSplType;
        plr[pnum]._pSplFrom = 0;
      }
      return 5;
    case CMD_SPELLPID:
      if ( gbBufferMsgs == 2 )
        assertion_failed(1767, "C:\\Diablo\\Direct\\msg.cpp");
      if ( gbBufferMsgs != 1 && plr[pnum].plrlevel == currlevel )
      {
        ClrPlrPath(pnum);
        plr[pnum].destAction = 25;
        plr[pnum].destParam1 = *(unsigned __int16 *)(pCmd + 1);
        plr[pnum]._pSpell = *(unsigned __int16 *)(pCmd + 3);
        plr[pnum]._pSplType = plr[pnum]._pRSplType;
        plr[pnum]._pSplFrom = 0;
      }
      return 5;
    case CMD_TSPELLID:
      if ( gbBufferMsgs == 2 )
        assertion_failed(1783, "C:\\Diablo\\Direct\\msg.cpp");
      if ( gbBufferMsgs != 1 && plr[pnum].plrlevel == currlevel )
      {
        ClrPlrPath(pnum);
        plr[pnum].destAction = 24;
        plr[pnum].destParam1 = *(unsigned __int16 *)(pCmd + 1);
        plr[pnum]._pSpell = *(unsigned __int16 *)(pCmd + 3);
        plr[pnum]._pSplType = plr[pnum]._pTSplType;
        plr[pnum]._pSplFrom = 2;
      }
      return 5;
    case CMD_TSPELLPID:
      if ( gbBufferMsgs == 2 )
        assertion_failed(1799, "C:\\Diablo\\Direct\\msg.cpp");
      if ( gbBufferMsgs != 1 && plr[pnum].plrlevel == currlevel )
      {
        ClrPlrPath(pnum);
        plr[pnum].destAction = 25;
        plr[pnum].destParam1 = *(unsigned __int16 *)(pCmd + 1);
        plr[pnum]._pSpell = *(unsigned __int16 *)(pCmd + 3);
        plr[pnum]._pSplType = plr[pnum]._pTSplType;
        plr[pnum]._pSplFrom = 2;
      }
      return 5;
    case CMD_RESURRECT:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 3);
      }
      else
      {
        DoResurrect(pnum, *(unsigned __int16 *)(pCmd + 1));
        check_update_plr(pnum);
      }
      return 3;
    case CMD_OPOBJT:
      if ( gbBufferMsgs == 2 )
        assertion_failed(1684, "C:\\Diablo\\Direct\\msg.cpp");
      if ( gbBufferMsgs != 1 && plr[pnum].plrlevel == currlevel )
      {
        plr[pnum].destAction = 18;
        plr[pnum].destParam1 = *(unsigned __int16 *)(pCmd + 1);
      }
      return 3;
    case CMD_KNOCKBACK:
      if ( gbBufferMsgs != 1 && plr[pnum].plrlevel == currlevel )
      {
        plr[pnum]._pIFlags |= 0x800u;
        M_StartHit(*(unsigned __int16 *)(pCmd + 1), pnum, 0);
        plr[pnum]._pIFlags &= 0xFFFFF7FF;
      }
      return 3;
    case CMD_TALKXY:
      if ( gbBufferMsgs == 2 )
        assertion_failed(1852, "C:\\Diablo\\Direct\\msg.cpp");
      if ( gbBufferMsgs != 1 && plr[pnum].plrlevel == currlevel )
      {
        MakePlrPath(pnum, (unsigned __int8)pCmd[1], (unsigned __int8)pCmd[2], 0);
        plr[pnum].destAction = 17;
        plr[pnum].destParam1 = *(unsigned __int16 *)(pCmd + 3);
      }
      return 5;
    case CMD_NEWLVL:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 5);
      }
      else if ( pnum != myplr )
      {
        StartNewLvl(pnum, *(unsigned __int16 *)(pCmd + 1), *(unsigned __int16 *)(pCmd + 3));
      }
      return 5;
    case CMD_WARP:
      if ( gbBufferMsgs == 1 )
        msg_send_packet(pnum, pCmd, 3);
      else
        StartWarpLvl(pnum, *(unsigned __int16 *)(pCmd + 1));
      return 3;
    case CMD_CHEAT_EXPERIENCE:
      if ( (signed int)gbMaxPlayers <= 1 )
      {
        if ( PauseMode )
          PauseMode = 0;
        else
          PauseMode = 2;
      }
      drawpanflag = 255;
      return 1;
    case CMD_CHEAT_SPELL_LEVEL:
      if ( gbBufferMsgs == 1 )
        msg_send_packet(pnum, pCmd, 1);
      else
        AddPlrExperience(pnum, plr[pnum]._pLevel, plr[pnum]._pNextExper - plr[pnum]._pExperience);
      return 1;
    case CMD_XXX_4:
      if ( gbBufferMsgs == 1 )
        msg_send_packet(pnum, pCmd, 1);
      else
        ++plr[pnum]._pSplLvl[plr[pnum]._pRSpell];
      return 1;
    case CMD_DEBUG:
      return 1;
    case CMD_SYNCDATA:
      return SyncData(pnum, (TSyncHeader *)pCmd);
    case CMD_MONSTDEATH:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 5);
      }
      else if ( pnum != myplr )
      {
        if ( plr[pnum].plrlevel == currlevel )
          M_SyncStartKill(*(unsigned __int16 *)(pCmd + 3), (unsigned __int8)pCmd[1], (unsigned __int8)pCmd[2], pnum);
        delta_kill_monster(*(unsigned __int16 *)(pCmd + 3), pCmd[1], pCmd[2], plr[pnum].plrlevel);
      }
      return 5;
    case CMD_MONSTDAMAGE:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 5);
      }
      else if ( pnum != myplr && plr[pnum].plrlevel == currlevel )
      {
        monster[*(unsigned __int16 *)(pCmd + 1)].mWhoHit |= 1 << pnum;
        if ( monster[*(unsigned __int16 *)(pCmd + 1)]._mhitpoints )
        {
          monster[*(unsigned __int16 *)(pCmd + 1)]._mhitpoints -= *(unsigned __int16 *)(pCmd + 3);
          if ( (signed int)(monster[*(unsigned __int16 *)(pCmd + 1)]._mhitpoints & 0xFFFFFFC0) < 64 )
            monster[*(unsigned __int16 *)(pCmd + 1)]._mhitpoints = 64;
          delta_monster_hp(
            *(unsigned __int16 *)(pCmd + 1),
            monster[*(unsigned __int16 *)(pCmd + 1)]._mhitpoints,
            plr[pnum].plrlevel);
        }
      }
      return 5;
    case CMD_PLRDEAD:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 1);
      }
      else if ( pnum == myplr )
      {
        check_update_plr(pnum);
      }
      else
      {
        RemovePlrMissiles(pnum);
      }
      return 1;
    case CMD_REQUESTGITEM:
      if ( gbBufferMsgs == 2 )
        assertion_failed(1434, "C:\\Diablo\\Direct\\msg.cpp");
      if ( gbBufferMsgs != 1 && msg_49AC05(plr[pnum].plrlevel) )
      {
        if ( plr[myplr].plrlevel != currlevel )
          assertion_failed(1441, "C:\\Diablo\\Direct\\msg.cpp");
        v16 = FindGetItem(*((unsigned __int16 *)pCmd + 3), *((_WORD *)pCmd + 4), *(_DWORD *)(pCmd + 10));
        if ( v16 != -1 && !item[v16]._isin )
        {
          NetSendCmdGItem2(0, 0xAu, myplr, pnum, (struct TCmdGItem *)pCmd);
          if ( pnum == myplr )
            InvGetItem(myplr, (unsigned __int8)pCmd[3]);
          else
            SyncGetItem(
              (unsigned __int8)pCmd[4],
              (unsigned __int8)pCmd[5],
              *((unsigned __int16 *)pCmd + 3),
              *((_WORD *)pCmd + 4),
              *(_DWORD *)(pCmd + 10));
        }
      }
      return 25;
    case CMD_REQUESTAGITEM:
      if ( gbBufferMsgs == 2 )
        assertion_failed(1493, "C:\\Diablo\\Direct\\msg.cpp");
      if ( gbBufferMsgs != 1 && msg_49AC05(plr[pnum].plrlevel) )
      {
        if ( plr[myplr].plrlevel != currlevel )
          assertion_failed(1500, "C:\\Diablo\\Direct\\msg.cpp");
        v15 = FindGetItem(*((unsigned __int16 *)pCmd + 3), *((_WORD *)pCmd + 4), *(_DWORD *)(pCmd + 10));
        if ( v15 != -1 && !item[v15]._isin )
        {
          NetSendCmdGItem2(0, 0xBu, myplr, pnum, (struct TCmdGItem *)pCmd);
          if ( pnum == myplr )
            AutoGetItem(myplr, (unsigned __int8)pCmd[3]);
          else
            SyncGetItem(
              (unsigned __int8)pCmd[4],
              (unsigned __int8)pCmd[5],
              *((unsigned __int16 *)pCmd + 3),
              *((_WORD *)pCmd + 4),
              *(_DWORD *)(pCmd + 10));
        }
      }
      return 25;
    case CMD_GOTOGETITEM:
      if ( gbBufferMsgs == 2 )
        assertion_failed(1421, "C:\\Diablo\\Direct\\msg.cpp");
      if ( gbBufferMsgs != 1 && plr[pnum].plrlevel == currlevel )
      {
        MakePlrPath(pnum, (unsigned __int8)pCmd[1], (unsigned __int8)pCmd[2], 0);
        plr[pnum].destAction = 15;
        plr[pnum].destParam1 = *(unsigned __int16 *)(pCmd + 3);
      }
      return 5;
    case CMD_GOTOAGETITEM:
      if ( gbBufferMsgs == 2 )
        assertion_failed(1480, "C:\\Diablo\\Direct\\msg.cpp");
      if ( gbBufferMsgs != 1 && plr[pnum].plrlevel == currlevel )
      {
        MakePlrPath(pnum, (unsigned __int8)pCmd[1], (unsigned __int8)pCmd[2], 0);
        plr[pnum].destAction = 16;
        plr[pnum].destParam1 = *(unsigned __int16 *)(pCmd + 3);
      }
      return 5;
    case CMD_OPENDOOR:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 3);
      }
      else
      {
        if ( plr[pnum].plrlevel == currlevel )
          SyncOpObject(pnum, 46, *(unsigned __int16 *)(pCmd + 1));
        delta_sync_object(*(unsigned __int16 *)(pCmd + 1), 46, plr[pnum].plrlevel);
      }
      return 3;
    case CMD_CLOSEDOOR:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 3);
      }
      else
      {
        if ( plr[pnum].plrlevel == currlevel )
          SyncOpObject(pnum, 47, *(unsigned __int16 *)(pCmd + 1));
        delta_sync_object(*(unsigned __int16 *)(pCmd + 1), 47, plr[pnum].plrlevel);
      }
      return 3;
    case CMD_OPERATEOBJ:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 3);
      }
      else
      {
        if ( plr[pnum].plrlevel == currlevel )
          SyncOpObject(pnum, 48, *(unsigned __int16 *)(pCmd + 1));
        delta_sync_object(*(unsigned __int16 *)(pCmd + 1), 48, plr[pnum].plrlevel);
      }
      return 3;
    case CMD_PLROPOBJ:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 5);
      }
      else
      {
        if ( plr[pnum].plrlevel == currlevel )
          SyncOpObject(*(unsigned __int16 *)(pCmd + 1), 49, *(unsigned __int16 *)(pCmd + 3));
        delta_sync_object(*(unsigned __int16 *)(pCmd + 3), 49, plr[pnum].plrlevel);
      }
      return 5;
    case CMD_BREAKOBJ:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 5);
      }
      else
      {
        if ( plr[pnum].plrlevel == currlevel )
          SyncBreakObj(*(unsigned __int16 *)(pCmd + 1), *(unsigned __int16 *)(pCmd + 3));
        delta_sync_object(*(unsigned __int16 *)(pCmd + 3), 50, plr[pnum].plrlevel);
      }
      return 5;
    case CMD_CHANGEPLRITEMS:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 10);
      }
      else if ( pnum != myplr )
      {
        HIWORD(v6) = HIWORD(pCmd);
        LOWORD(v6) = *((_WORD *)pCmd + 2);
        CheckInvSwap(pnum, pCmd[1], *((unsigned __int16 *)pCmd + 1), v6, *(_DWORD *)(pCmd + 6), v9);
      }
      return 10;
    case CMD_DELPLRITEMS:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 2);
      }
      else if ( pnum != myplr )
      {
        v7 = pCmd;
        LOBYTE(v7) = pCmd[1];
        inv_update_rem_item(pnum, (int)v7);
      }
      return 2;
    case CMD_PLRDAMAGE:
      if ( gbBufferMsgs == 2 )
        assertion_failed(1970, "C:\\Diablo\\Direct\\msg.cpp");
      if ( (unsigned __int8)pCmd[1] == myplr && gbBufferMsgs != 1 )
      {
        drawmanaflag = 1;
        plr[myplr]._pHitPoints -= *(_DWORD *)(pCmd + 2);
        plr[myplr]._pHPBase -= *(_DWORD *)(pCmd + 2);
        if ( plr[myplr]._pHitPoints > plr[myplr]._pMaxHP )
        {
          plr[myplr]._pHitPoints = plr[myplr]._pMaxHP;
          plr[myplr]._pHPBase = plr[myplr]._pMaxHPBase;
        }
        if ( (signed int)(plr[myplr]._pHitPoints & 0xFFFFFFC0) <= 0 )
        {
          plr[myplr]._pHitPoints = 0;
          SyncPlrKill(myplr);
        }
      }
      return 6;
    case CMD_PLRLEVEL:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 3);
      }
      else if ( pnum != myplr )
      {
        plr[pnum]._pLevel = pCmd[1];
      }
      return 3;
    case CMD_DROPITEM:
      if ( gbBufferMsgs == 1 )
        msg_send_packet(pnum, pCmd, 18);
      else
        delta_put_item((struct TCmdPItem *)pCmd, (unsigned __int8)pCmd[1], (unsigned __int8)pCmd[2], plr[pnum].plrlevel);
      return 18;
    case CMD_PLAYER_JOINLEVEL:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 5);
      }
      else
      {
        plr[pnum]._pLvlChanging = 0;
        if ( pnum != myplr )
        {
          plr[pnum].WorldX = (unsigned __int8)pCmd[1];
          plr[pnum].WorldY = (unsigned __int8)pCmd[2];
          plr[pnum].plrlevel = *(unsigned __int16 *)(pCmd + 3);
          plr[pnum]._pGFXLoad = 0;
          if ( plr[pnum].plrlevel == currlevel )
          {
            LoadPlrGFX(pnum, 1);
            SyncInitPlrPos(pnum);
            StartStand(pnum, 0);
            plr[pnum]._pvid = AddVision(plr[pnum].WorldX, plr[pnum].WorldY, plr[pnum]._pLightRad, pnum == myplr);
            plr[pnum]._plid = -1;
          }
        }
      }
      return 5;
    case CMD_SEND_PLRINFO:
      if ( gbBufferMsgs == 1 )
        msg_send_packet(pnum, pCmd, *(unsigned __int16 *)(pCmd + 3) + 5);
      else
        multi_player_joins(pnum, (TCmdPlrInfoHdr *)pCmd, 0);
      return *(unsigned __int16 *)(pCmd + 3) + 5;
    case CMD_SATTACKXY:
      if ( gbBufferMsgs == 2 )
        assertion_failed(1590, "C:\\Diablo\\Direct\\msg.cpp");
      if ( gbBufferMsgs != 1 && plr[pnum].plrlevel == currlevel )
      {
        ClrPlrPath(pnum);
        plr[pnum].destAction = 9;
        plr[pnum].destParam1 = (unsigned __int8)pCmd[1];
        plr[pnum].destParam2 = (unsigned __int8)pCmd[2];
      }
      return 3;
    case CMD_ACTIVATEPORTAL:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 7);
      }
      else
      {
        ActivatePortal(
          pnum,
          (unsigned __int8)pCmd[1],
          (unsigned __int8)pCmd[2],
          *(unsigned __int16 *)(pCmd + 3),
          *(unsigned __int16 *)(pCmd + 5),
          v10);
        if ( pnum != myplr && !currlevel )
          AddInTownPortal(pnum);
        delta_open_portal(pnum, pCmd[1], pCmd[2], *(_WORD *)(pCmd + 3), *(_WORD *)(pCmd + 5));
      }
      return 7;
    case CMD_DEACTIVATEPORTAL:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 1);
      }
      else
      {
        if ( PortalOnLevel(pnum) )
          RemovePortalMissile(pnum);
        DeactivatePortal(pnum);
        RemovePlrPortal(pnum);
      }
      return 1;
    case CMD_HEALOTHER:
      if ( gbBufferMsgs != 1 && plr[pnum].plrlevel == currlevel )
        DoHealOther(pnum, *(unsigned __int16 *)(pCmd + 1));
      return 3;
    case CMD_STRING:
      return On_STRING(pnum, pCmd);
    case CMD_SETSTR:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 3);
      }
      else if ( pnum != myplr )
      {
        SetPlrStr(pnum, *(unsigned __int16 *)(pCmd + 1));
      }
      return 3;
    case CMD_SETMAG:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 3);
      }
      else if ( pnum != myplr )
      {
        SetPlrMag(pnum, *(unsigned __int16 *)(pCmd + 1));
      }
      return 3;
    case CMD_SETDEX:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 3);
      }
      else if ( pnum != myplr )
      {
        SetPlrDex(pnum, *(unsigned __int16 *)(pCmd + 1));
      }
      return 3;
    case CMD_SETVIT:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 3);
      }
      else if ( pnum != myplr )
      {
        SetPlrVit(pnum, *(unsigned __int16 *)(pCmd + 1));
      }
      return 3;
    case CMD_RETOWN:
      if ( gbBufferMsgs == 1 )
      {
        msg_send_packet(pnum, pCmd, 1);
      }
      else
      {
        if ( pnum == myplr )
        {
          deathflag = 0;
          gamemenu_off();
        }
        RestartTownLvl(pnum);
      }
      return 1;
    default:
      if ( (unsigned __int8)*pCmd < (signed int)CMD_DLEVEL_0 || (unsigned __int8)*pCmd > (signed int)CMD_DLEVEL_END )
        TermMsg("Unknown PCMD %d (last cmd %d)\n", (unsigned __int8)*pCmd, (unsigned __int8)sbLastCmd);
      return msg_49A299_on_dlevel(pnum, pCmd);  // Inlined in 1.09
  }
}

//----- (0049A163) --------------------------------------------------------
void __fastcall msg_send_packet(int pnum, void *packet, int dwSize)
{
  char packeta; // [esp+14h] [ebp-4h]
  char v5; // [esp+15h] [ebp-3h]

  if ( (unsigned int)pnum >= 4 )
    assertion_failed(214, "C:\\Diablo\\Direct\\msg.cpp");
  if ( !packet )
    assertion_failed(215, "C:\\Diablo\\Direct\\msg.cpp");
  if ( dwSize > (unsigned int)gdwLargestMsgSize )
    assertion_failed(216, "C:\\Diablo\\Direct\\msg.cpp");
  if ( pnum != sgnCurrMegaPlayer )
  {
    sgnCurrMegaPlayer = pnum;
    packeta = 87;
    v5 = pnum;
    msg_send_packet(pnum, &packeta, 2);
  }
  if ( !sgpCurrPkt )
    assertion_failed(228, "C:\\Diablo\\Direct\\msg.cpp");
  if ( sgpCurrPkt->dwSpaceLeft < (unsigned int)dwSize )
    msg_get_next_packet();
  if ( sgpCurrPkt->dwSpaceLeft < (unsigned int)dwSize )
    assertion_failed(231, "C:\\Diablo\\Direct\\msg.cpp");
  memcpy((char *)&sgpCurrPkt[1] - sgpCurrPkt->dwSpaceLeft, packet, dwSize);
  sgpCurrPkt->dwSpaceLeft -= dwSize;
}

//----- (0049A299) --------------------------------------------------------
int __fastcall msg_49A299_on_dlevel(int pnum, char *pCmd)
{
  if ( myplr == pnum )
    assertion_failed(569, "C:\\Diablo\\Direct\\msg.cpp");
  if ( dword_4DCFB0 == -1 )
  {
    if ( *pCmd != 61 || *(_WORD *)(pCmd + 1) )
      return *(unsigned __int16 *)(pCmd + 3) + 5;
    if ( sgbDeltaChunks )
      assertion_failed(581, "C:\\Diablo\\Direct\\msg.cpp");
    dword_4DCFB0 = pnum;
    dword_649D20 = 0;
    byte_6635F0 = *pCmd;
  }
  else
  {
    if ( dword_4DCFB0 != pnum )
      return *(unsigned __int16 *)(pCmd + 3) + 5;
    if ( *pCmd != byte_6635F0 )
    {
      DeltaImportData(byte_6635F0, dword_649D20 + *(unsigned __int16 *)(pCmd + 3));
      if ( *pCmd == 79 )
      {
        dword_4DCFB0 = -1;
        ++sgbDeltaChunks;
        return *(unsigned __int16 *)(pCmd + 3) + 5;
      }
      dword_649D20 = 0;
      byte_6635F0 = *pCmd;
    }
  }
  if ( *(unsigned __int16 *)(pCmd + 1) != dword_649D20 )
    assertion_failed(612, "C:\\Diablo\\Direct\\msg.cpp");
  memcpy(&sgRecvBuf[*(unsigned __int16 *)(pCmd + 1)], pCmd + 5, *(unsigned __int16 *)(pCmd + 3));
  dword_649D20 += *(unsigned __int16 *)(pCmd + 3);
  return *(unsigned __int16 *)(pCmd + 3) + 5;
}

//----- (0049A462) --------------------------------------------------------
void __fastcall DeltaImportData(unsigned __int8 cmd, int recv_offset)
{
  void *v2; // eax
  void *v3; // eax
  char *a1; // [esp+18h] [ebp-4h]

  if ( sgRecvBuf[0] )
    encrypt_decompress(&sgRecvBuf[1], recv_offset, 5813);
  a1 = &sgRecvBuf[1];
  if ( cmd == CMD_DLEVEL_JUNK )
  {
    DeltaImportJunk((int)a1);
  }
  else
  {
    if ( cmd < (signed int)CMD_DLEVEL_0 || cmd > (signed int)CMD_DLEVEL_16 )
      TermMsg("msg:1");
    v2 = DeltaImportItem(a1, &sgLevels[(unsigned __int8)(cmd - CMD_DLEVEL_0)]);
    v3 = DeltaImportObject(v2, sgLevels[(unsigned __int8)(cmd - CMD_DLEVEL_0)].object);
    DeltaImportMonster(v3, sgLevels[(unsigned __int8)(cmd - CMD_DLEVEL_0)].monster);
  }
  dword_5FE158 |= 0x80000000;
  ++sgbDeltaChunks;
}

//----- (0049A582) --------------------------------------------------------
void *__fastcall DeltaImportItem(void *src, void *dst)
{
  signed int v5; // [esp+14h] [ebp-4h]

  v5 = 0;
  while ( v5 < 127 )
  {
    if ( *(unsigned __int8 *)src == 255 )
    {
      memset(dst, 255, 0x12u);
      src = (char *)src + 1;
    }
    else
    {
      memcpy(dst, src, 0x12u);
      src = (char *)src + 18;
    }
    ++v5;
    dst = (char *)dst + 18;
  }
  return src;
}

//----- (0049A604) --------------------------------------------------------
void *__fastcall DeltaImportObject(void *src, void *dst)
{
  memcpy(dst, src, 0x7Fu);
  return (char *)src + 127;
}

//----- (0049A635) --------------------------------------------------------
void *__fastcall DeltaImportMonster(void *src, void *dst)
{
  signed int v5; // [esp+14h] [ebp-4h]

  v5 = 0;
  while ( v5 < 200 )
  {
    if ( *(unsigned __int8 *)src == 255 )
    {
      memset(dst, 255, 9u);
      src = (char *)src + 1;
    }
    else
    {
      memcpy(dst, src, 9u);
      src = (char *)src + 9;
    }
    ++v5;
    dst = (char *)dst + 9;
  }
  return src;
}

//----- (0049A6BA) --------------------------------------------------------
char __fastcall DeltaImportJunk(int src)
{
  char result; // al
  int v2; // [esp+0h] [ebp-14h]
  int i; // [esp+10h] [ebp-4h]

  for ( i = 0; i < 4; ++i )
  {
    if ( *(unsigned __int8 *)src == 255 )
    {
      memset(&sgJunk.portal[i], 255, 4u);
      ++src;
      SetPortalStats(i, 0, 0, 0, 0, v2);
    }
    else
    {
      memcpy(&sgJunk.portal[i], (const void *)src, 4u);
      src += 4;
      SetPortalStats(i, 1, sgJunk.portal[i].x, sgJunk.portal[i].y, sgJunk.portal[i].level, v2);
    }
  }
  return result;
}

//----- (0049A784) --------------------------------------------------------
void __fastcall delta_sync_object(int a1, char a2, unsigned __int8 level)
{
  dword_5FE158 |= 0x80000000;
  sgLevels[level].object[a1].bCmd = a2;
}

//----- (0049A7DA) --------------------------------------------------------
BOOL __fastcall delta_get_item(TCmdGItem *pI, unsigned __int8 bLevel)
{
  BOOL result; // eax
  TCmdPItem *v3; // [esp+14h] [ebp-8h]
  TCmdPItem *v4; // [esp+14h] [ebp-8h]
  signed int v5; // [esp+18h] [ebp-4h]
  signed int v6; // [esp+18h] [ebp-4h]

  v3 = sgLevels[bLevel].item;
  v5 = 0;
  while ( v5 < 127 )
  {
    if ( (unsigned __int8)v3->bCmd != 255 && v3->wIndx == pI->wIndx && v3->wCI == pI->wCI && v3->dwSeed == pI->dwSeed )
    {
      if ( v3->bCmd == 1 )
        return 1;
      if ( v3->bCmd )
      {
        if ( v3->bCmd != 2 )
          TermMsg("delta:1");
        dword_5FE158 |= 0x80000000;
        v3->bCmd = -1;
        result = 1;
      }
      else
      {
        dword_5FE158 |= 0x80000000;
        v3->bCmd = 1;
        result = 1;
      }
      return result;
    }
    ++v5;
    ++v3;
  }
  if ( (((unsigned __int16)pI->wCI >> 8) & 0x80u) == 0 )
    return 0;
  if ( (signed int)bLevel <= 0 )
    assertion_failed(764, "C:\\Diablo\\Direct\\msg.cpp");
  v4 = sgLevels[bLevel].item;
  v6 = 0;
  while ( v6 < 127 )
  {
    if ( (unsigned __int8)v4->bCmd == 255 )
    {
      dword_5FE158 |= 0x80000000;
      v4->bCmd = 1;
      v4->x = pI->x;
      v4->y = pI->y;
      v4->wIndx = pI->wIndx;
      v4->wCI = pI->wCI;
      v4->dwSeed = pI->dwSeed;
      v4->bId = pI->bId;
      v4->bDur = pI->bDur;
      v4->bMDur = pI->bMDur;
      v4->bCh = pI->bCh;
      v4->bMCh = pI->bMCh;
      v4->wValue = pI->wValue;
      return 1;
    }
    ++v6;
    ++v4;
  }
  return 1;
}

//----- (0049AA6F) --------------------------------------------------------
void __fastcall delta_put_item(struct TCmdPItem *pI, int x, int y, unsigned __int8 bLevel)
{
  TCmdPItem *v5; // [esp+14h] [ebp-8h]
  DLevel *v6; // [esp+14h] [ebp-8h]
  signed int v7; // [esp+18h] [ebp-4h]
  signed int v8; // [esp+18h] [ebp-4h]

  bLevel = x;
  v5 = sgLevels[bLevel].item;
  v7 = 0;
  while ( v7 < 127 )
  {
    if ( v5->bCmd != 1
      && (unsigned __int8)v5->bCmd != 255
      && pI->wIndx == v5->wIndx
      && pI->wCI == v5->wCI
      && pI->dwSeed == v5->dwSeed )
    {
      if ( v5->bCmd != 2 )
        TermMsg("Trying to drop a floor item?");
      return;
    }
    ++v7;
    ++v5;
  }
  v6 = &sgLevels[bLevel];
  v8 = 0;
  while ( v8 < 127 )
  {
    if ( (unsigned __int8)v6->item[0].bCmd == 255 )
    {
      dword_5FE158 |= 0x80000000;
      memcpy(v6, pI, 0x12u);
      v6->item[0].bCmd = 2;
      v6->item[0].x = bLevel;
      v6->item[0].y = y;
      return;
    }
    ++v8;
    v6 = (DLevel *)((char *)v6 + 18);
  }
}

//----- (0049AC05) --------------------------------------------------------
BOOL __fastcall msg_49AC05(int level)
{
  signed int i; // [esp+10h] [ebp-4h]

  for ( i = 0;
        i < 4 && (!plr[i].plractive || plr[i]._pLvlChanging || plr[i].plrlevel != level || i == myplr && gbBufferMsgs);
        ++i )
  {
    ;
  }
  return i == myplr;
}

//----- (0049ACFD) --------------------------------------------------------
int __fastcall On_STRING(int pnum, const char *a2)
{
  size_t v5; // [esp+14h] [ebp-4h]

  v5 = strlen(a2 + 1);
  if ( !gbBufferMsgs )
    SendPlrMsg(pnum, a2 + 1);
  return v5 + 2;
}

//----- (0049AD47) --------------------------------------------------------
void __fastcall delta_open_portal(int a1, char x, char y, WORD level, WORD ltype)
{
  sgJunk.portal[a1].x = x;
  sgJunk.portal[a1].y = y;
  sgJunk.portal[a1].level = level;
  sgJunk.portal[a1].ltype = ltype;
  dword_5FE158 |= 0x80000000;
}

//----- (0049ADA0) --------------------------------------------------------
void __fastcall RemovePlrPortal(int pnum)
{
  memset(&sgJunk.portal[pnum], 255, 4u);
  dword_5FE158 |= 0x80000000;
}

//----- (0049ADDA) --------------------------------------------------------
void __fastcall check_update_plr(int pnum)
{
  if ( myplr == pnum && gbMaxPlayers != 1 )
    pfile_update(1);
}

