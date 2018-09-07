//----- (0041C0B0) --------------------------------------------------------
void __fastcall NetSendLoPri(unsigned __int8 *pbMsg, unsigned __int8 bLen)
{
  unsigned __int8 size; // [esp+Ch] [ebp-8h]
  unsigned __int8 *packet; // [esp+10h] [ebp-4h]

  size = bLen;
  packet = pbMsg;
  assert(sgbNetInited, "multi.cpp", 173);
  assert(bLen <= (unsigned int)(gdwNormalMsgSize - 8), "multi.cpp", 177);
  multi_copy_packet(packet_5FFCD8, pbMsg, bLen);
  multi_copy_packet(packet_5FF8D0, packet, size);
}

//----- (0041C136) --------------------------------------------------------
void __fastcall multi_copy_packet(void *a1, void *packet, BYTE size)
{
  BYTE *v3; // ST20_4

  if ( *(_DWORD *)a1 + (unsigned int)size + 2 > 0x400 )
    TermMsg("Msg buffer overrun");
  v3 = (BYTE *)a1 + *(_DWORD *)a1 + 4;
  *(_DWORD *)a1 += size + 1;
  *v3++ = size;
  memcpy(v3, packet, size);
  v3[size] = 0;
}

//----- (0041C1BE) --------------------------------------------------------
void __fastcall NetSendHiPri_1(void *packet, BYTE size)
{
  int v2; // eax
  TSyncHeader *v3; // eax
  char *v4; // eax
  char v7; // [esp+14h] [ebp-20Ch]
  char v8; // [esp+15h] [ebp-20Bh]
  char v9; // [esp+16h] [ebp-20Ah]
  char v10; // [esp+17h] [ebp-209h]
  __int16 v11; // [esp+18h] [ebp-208h]
  __int16 v12; // [esp+1Ah] [ebp-206h]
  char v13; // [esp+1Ch] [ebp-204h]
  int v14; // [esp+214h] [ebp-Ch]
  int v15; // [esp+218h] [ebp-8h]
  char *bLen; // [esp+21Ch] [ebp-4h]

  assert(sgbNetInited, "multi.cpp", 186);
  if ( packet )
  {
    assert(size <= (unsigned int)(gdwNormalMsgSize - 8), "multi.cpp", 189);
    multi_copy_packet(&pbMsg, packet, size);
    multi_copy_packet(packet_5FF8D0, packet, size);
  }
  if ( !dword_5FF8BC )
  {
    dword_5FF8BC = 1;
    assert((unsigned int)myplr < 4, "multi.cpp", 200);
    v11 = 26992;
    v7 = plr[myplr].WorldX;
    v8 = plr[myplr].WorldY;
    v9 = plr[myplr]._ptargx;
    v10 = plr[myplr]._ptargy;
    bLen = &v13;
    v15 = gdwNormalMsgSize - 8;
    NetSendHiPri((unsigned __int8 *)&pbMsg, (unsigned int)&v13);
    bLen = (char *)v2;
    NetSendHiPri((unsigned __int8 *)packet_5FFCD8, v2);
    bLen = (char *)v3;
    v15 = sync_all_monsters(v3, v15);
    v14 = gdwNormalMsgSize - v15;
    v12 = gdwNormalMsgSize - v15;
    if ( gdwNormalMsgSize - 8 != v15 && !SNetSendMessage(-1, &v7, v14, &v15, &v15) )
    {
      if ( GetLastError() != 553975813 )
      {
        v4 = GetLastErr();
        TermMsg("SNetSendMsg:\n%s", v4);
      }
      gbGameDestroyed = 1;
    }
  }
}

//----- (0041C3FD) --------------------------------------------------------
void __fastcall NetSendHiPri(unsigned __int8 *pbMsg, unsigned __int8 bLen)
{
  char *v2; // ST24_4
  void *v3; // [esp+Ch] [ebp-10h]
  unsigned __int8 *v4; // [esp+10h] [ebp-Ch]
  unsigned __int8 v5; // [esp+14h] [ebp-8h]
  unsigned __int8 *v6; // [esp+18h] [ebp-4h]
  _DWORD *v7; // [esp+24h] [ebp+8h]

  v3 = (void *)bLen;
  v4 = pbMsg;
  if ( *(_DWORD *)pbMsg )
  {
    v6 = pbMsg + 4;
    while ( 1 )
    {
      v5 = *v6;
      if ( !*v6 || (unsigned int)v5 > *v7 )
        break;
      v2 = (char *)(v6 + 1);
      memcpy(v3, v2, v5);
      v6 = (unsigned __int8 *)&v2[v5];
      v3 = (char *)v3 + v5;
      *v7 -= v5;
    }
    memcpy_0(v4 + 4, v6, *(_DWORD *)v4 - (v6 - (v4 + 4)) + 1);
    *(_DWORD *)v4 -= v6 - (v4 + 4);
  }
}

//----- (0041C4E2) --------------------------------------------------------
void __fastcall multi_recv_packet(void *packet, BYTE size, int *a3)
{
  assert(sgbNetInited, "multi.cpp", 235);
  if ( packet )
  {
    assert(size <= (unsigned int)(gdwNormalMsgSize - 8), "multi.cpp", 238);
    multi_copy_packet(packet_5FF8D0, packet, size);
  }
}

//----- (0041C561) --------------------------------------------------------
void __fastcall multi_send_msg_packet(int a1, unsigned __int8 *a2, unsigned __int8 len)
{
  char *v3; // eax
  int v4; // [esp+0h] [ebp-220h]
  int v5; // [esp+4h] [ebp-21Ch]
  unsigned __int8 *packet; // [esp+Ch] [ebp-214h]
  int v7; // [esp+10h] [ebp-210h]
  char v8; // [esp+14h] [ebp-20Ch]
  char v9; // [esp+15h] [ebp-20Bh]
  char v10; // [esp+16h] [ebp-20Ah]
  char v11; // [esp+17h] [ebp-209h]
  __int16 v12; // [esp+18h] [ebp-208h]
  __int16 v13; // [esp+1Ah] [ebp-206h]
  char v14; // [esp+1Ch] [ebp-204h]
  unsigned int v15; // [esp+214h] [ebp-Ch]
  int v16; // [esp+218h] [ebp-8h]
  unsigned int v17; // [esp+21Ch] [ebp-4h]

  packet = a2;
  v7 = a1;
  assert(sgbNetInited, "multi.cpp", 247);
  assert(a2, "multi.cpp", 248);
  assert(len, "multi.cpp", 249);
  if ( (1 << myplr) & a1 )
    multi_copy_packet(packet_5FF8D0, a2, len);
  v12 = 26992;
  v8 = plr[myplr].WorldX;
  v9 = plr[myplr].WorldY;
  v10 = plr[myplr]._ptargx;
  v11 = plr[myplr]._ptargy;
  v15 = len + 8;
  assert(gdwNormalMsgSize > v15, "multi.cpp", 265);
  v13 = v15;
  memcpy(&v14, packet, len);
  v16 = 1;
  v17 = 0;
  while ( v17 < 4 )
  {
    if ( v7 & v16 && myplr != v17 && !SNetSendMessage(v17, &v8, v15, v4, v5) )
    {
      if ( GetLastError() != 553975813 )
      {
        v3 = GetLastErr();
        TermMsg("SNetSendMsg:\n%s", v3);
      }
      gbGameDestroyed = 1;
      return;
    }
    ++v17;
    v16 *= 2;
  }
}

//----- (0041C7A7) --------------------------------------------------------
void __fastcall multi_msg_countdown()
{
  int pnum; // [esp+Ch] [ebp-4h]

  for ( pnum = 0; pnum < 4; ++pnum )
  {
    if ( plr[pnum].plractive )
    {
      if ( byte_5FF8B0[pnum] )
        multi_parse_turn(pnum);
    }
  }
}

//----- (0041C824) --------------------------------------------------------
void __fastcall multi_parse_turn(int pnum)
{
  RemovePlrFromMap(pnum);
  RemovePortalMissile(pnum);
  DeactivatePortal(pnum);
  EventPlrMsg("Player '%s' just left the game", plr[pnum]._pName);
  plr[pnum].plractive = 0;
  byte_5FF8B0[pnum] = 0;
  byte_5FF8C8[pnum] = 0;
  --gbActivePlayers;
}

//----- (0041C8BA) --------------------------------------------------------
void __fastcall multi_41C8BA(BOOL a1)
{
  int pnum; // [esp+14h] [ebp-4h]

  for ( pnum = 0; pnum < 4; ++pnum )
  {
    switch ( dword_5FE0D8[pnum] )
    {
      case 0:
        break;
      case 1:
        assert(dword_5FE120[pnum], "multi.cpp", 440);
        assert(dword_5FE0F0[pnum] == 4, "multi.cpp", 441);
        multi_41C9FB(pnum, *(_DWORD *)dword_5FE120[pnum]);
        break;
      case 2:
        TermMsg("SNET_PS_WAITING");
        return;
      case 3:
        TermMsg("SNET_PS_NOTRESPONDING");
        return;
      default:
        TermMsg("SNET_PS_UNKNOWN");
        return;
    }
    if ( a1 )
    {
      if ( byte_5FF8C8[pnum] )
      {
        byte_5FF8C8[pnum] = 0;
        DeltaExportData(pnum);
      }
    }
  }
}

//----- (0041C9FB) --------------------------------------------------------
void __fastcall multi_41C9FB(int pnum, int a2)
{
  int v2; // [esp+Ch] [ebp-8h]
  unsigned int v3; // [esp+Ch] [ebp-8h]

  v2 = a2;
  if ( a2 & 0x40000000 )
    multi_41CA8A(pnum);
  dword_5FE158 |= v2 & 0x80000000;
  v3 = v2 & 0x3FFFFFFF;
  if ( v3 + gdwTurnsInTransit > cur_turn )
  {
    if ( v3 >= 0x3FFFFFFF )
      v3 = (unsigned __int16)v3;
    cur_turn = v3 + gdwTurnsInTransit;
    dword_6000DC = 8 * v3 * byte_5FE0E8;
  }
}

//----- (0041CA8A) --------------------------------------------------------
void __fastcall multi_41CA8A(int pnum)
{
  signed int i; // [esp+10h] [ebp-4h]

  if ( myplr != pnum )
  {
    for ( i = 0; i < 4 && (i == pnum || !plr[i].plractive || myplr == i && !msg_5FF8B4_isprocessing); ++i )
      ;
    if ( myplr == i )
    {
      assert(!gbBufferMsgs, "multi.cpp", 353);
      byte_5FF8C8[pnum] = 1;
    }
  }
}

//----- (0041CB78) --------------------------------------------------------
int __fastcall multi_handle_delta()
{
  int result; // eax
  int a2; // [esp+Ch] [ebp-8h]
  int pfSendAsync; // [esp+10h] [ebp-4h]

  assert(sgbNetInited, "multi.cpp", 474);
  if ( gbGameDestroyed )
  {
    gbRunGame = 0;
    result = 0;
  }
  else
  {
    multi_msg_countdown();
    cur_turn = nthread_send_and_recv_turn(cur_turn, 1);
    if ( nthread_recv_turns(&pfSendAsync, &a2) )
    {
      if ( a2 )
        multi_41C8BA(1);
      sgbTimeout = 0;
      if ( pfSendAsync )
      {
        if ( dword_5FF8BC )
        {
          dword_5FF8BC = 0;
          if ( !multi_check_pkt_valid(&pbMsg) )
            NetSendHiPri_1(0, 0);
        }
        else
        {
          NetSendHiPri_1(0, 0);
          dword_5FF8BC = 0;
        }
      }
      multi_mon_seeds();
      result = 1;
    }
    else
    {
      if ( sgbTimeout )
      {
        sgbTimeout = 0;
        multi_begin_timeout();
      }
      result = 0;
    }
  }
  return result;
}

//----- (0041CC99) --------------------------------------------------------
int __fastcall multi_check_pkt_valid(char *a1)
{
  return *(_DWORD *)a1 == 0;
}

//----- (0041CCC7) --------------------------------------------------------
void __cdecl multi_mon_seeds()
{
  signed int i; // [esp+Ch] [ebp-8h]
  unsigned int v1; // [esp+10h] [ebp-4h]

  v1 = _rotr(++dword_6000DC, 8);
  for ( i = 0; i < 200; ++i )
    monster[i]._mAISeed = v1 + i;
}

//----- (0041CD2E) --------------------------------------------------------
void __cdecl multi_begin_timeout()
{
  signed int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 4; ++i )
  {
    if ( myplr != i && plr[i].plractive && dword_5FE0D8[i] == 3 )
      SNetDropPlayer(i);
  }
}

//----- (0041CDBE) --------------------------------------------------------
void __cdecl multi_process_network_packets()
{
  int v0; // ST28_4
  char *v1; // eax
  int *v2; // [esp-4h] [ebp-22Ch]
  int v3; // [esp+Ch] [ebp-21Ch]
  unsigned __int8 *v4; // [esp+14h] [ebp-214h]
  char bLen; // [esp+20h] [ebp-208h]
  unsigned int v6; // [esp+218h] [ebp-10h]
  int v7; // [esp+21Ch] [ebp-Ch]
  unsigned __int8 *v8; // [esp+220h] [ebp-8h]
  unsigned int pnum; // [esp+224h] [ebp-4h]

  v7 = 504;
  v2 = &v7;
  NetSendHiPri((unsigned __int8 *)packet_5FF8D0, (unsigned int)&bLen);
  multi_handle_all_packets(myplr, (int)&bLen, 504 - v7);
  assert(sgbNetInited, "multi.cpp", 554);
  while ( SNetReceiveMessage(&pnum, &v8, &v6, v2) )
  {
    v4 = v8;
    assert(v6 >= 8, "multi.cpp", 557);
    assert(pnum < 4, "multi.cpp", 558);
    assert(*((_WORD *)v8 + 2) == 26992, "multi.cpp", 559);
    assert(*((unsigned __int16 *)v8 + 3) == v6, "multi.cpp", 560);
    plr[pnum]._pownerx = *v8;
    plr[pnum]._pownery = v4[1];
    if ( pnum != myplr )
    {
      if ( pnum != myplr )
      {
        assert(gbBufferMsgs != 2, "multi.cpp", 573);
        if ( gbBufferMsgs != 1 && plr[pnum].plractive )
        {
          if ( plr[pnum].plrlevel != currlevel || plr[pnum]._pLvlChanging )
          {
            plr[pnum].WorldX = v4[2];
            plr[pnum].WorldY = v4[3];
            plr[pnum]._px = v4[2];
            plr[pnum]._py = v4[3];
            plr[pnum]._ptargx = v4[2];
            plr[pnum]._ptargy = v4[3];
          }
          else
          {
            v0 = abs(plr[pnum].WorldX - *v4);
            v3 = abs(plr[pnum].WorldY - v4[1]);
            if ( v0 > 3 || v3 > 3 )
            {
              RemovePlrFromMap(pnum);
              plr[pnum]._poldx = plr[pnum].WorldX;
              plr[pnum]._poldy = plr[pnum].WorldY;
              RemovePlrFromMap(pnum);
              plr[pnum].WorldX = *v4;
              plr[pnum].WorldY = v4[1];
              dPlayer[plr[pnum].WorldX][plr[pnum].WorldY] = pnum + 1;
            }
            MakePlrPath(pnum, v4[2], v4[3], 1u);
          }
        }
      }
      multi_handle_all_packets(pnum, (int)(v4 + 8), v6 - 8);
    }
  }
  if ( GetLastError() != 553975814 )
  {
    if ( GetLastError() != 553975813 )
    {
      v1 = GetLastErr();
      TermMsg("SNetReceiveMsg:\n%s", v1);
    }
    gbGameDestroyed = 1;
  }
}

//----- (0041D323) --------------------------------------------------------
void __fastcall multi_handle_all_packets(int a1, int a2, int a3)
{
  int v3; // ST14_4
  unsigned __int8 *a2a; // [esp+Ch] [ebp-Ch]
  int pnum; // [esp+10h] [ebp-8h]

  a2a = (unsigned __int8 *)a2;
  pnum = a1;
  while ( a3 )
  {
    v3 = ParseCmd(pnum, (char *)a2a);
    a2a += v3;
    a3 -= v3;
  }
}

//----- (0041D36B) --------------------------------------------------------
void __fastcall multi_41D36B(int pnum, char a2, PkPlayerStruct *a3, int a4)
{
  unsigned int v4; // eax
  unsigned __int16 v5; // cx
  char *v6; // eax
  int v7; // [esp+0h] [ebp-224h]
  int v8; // [esp+4h] [ebp-220h]
  char v11[512]; // [esp+14h] [ebp-210h]
  int v12; // [esp+214h] [ebp-10h]
  unsigned int v13; // [esp+218h] [ebp-Ch]
  char *v14; // [esp+21Ch] [ebp-8h]
  int v15; // [esp+220h] [ebp-4h]

  assert(myplr != pnum, "multi.cpp", 622);
  assert(a3, "multi.cpp", 625);
  assert((unsigned int)a4 <= 0xFFFF, "multi.cpp", 626);
  v15 = 0;
  while ( a4 )
  {
    *(_WORD *)&v11[4] = 26992;
    v11[0] = 0;
    v11[1] = 0;
    v11[2] = 0;
    v11[3] = 0;
    v14 = &v11[8];
    v11[8] = a2;
    *(_WORD *)&v11[9] = v15;
    v13 = gdwLargestMsgSize - 13;
    v4 = a4;
    if ( a4 >= (unsigned int)(gdwLargestMsgSize - 13) )
      v4 = gdwLargestMsgSize - 13;
    v13 = v4;
    assert(v4 <= 0xFFFF, "multi.cpp", 645);
    *(_WORD *)(v14 + 3) = v13;
    memcpy(&v11[13], a3, *(unsigned __int16 *)(v14 + 3));
    v12 = 13;
    v5 = *(_WORD *)(v14 + 3);
    v12 = v5 + 13;
    *(_WORD *)&v11[6] = v5 + 13;
    if ( !SNetSendMessage(pnum, v11, v12, v7, v8) )
    {
      if ( GetLastError() != 553975813 )
      {
        v6 = GetLastErr();
        TermMsg("SNetSendMsg2:\n%s", v6);
      }
      gbGameDestroyed = 1;
      return;
    }
    a3 = (PkPlayerStruct *)((char *)a3 + *(unsigned __int16 *)(v14 + 3));
    a4 -= *(unsigned __int16 *)(v14 + 3);
    v15 += *(unsigned __int16 *)(v14 + 3);
  }
}

//----- (0041D54D) --------------------------------------------------------
void __fastcall multi_41D54D(int pnum, char a2)
{
  PkPlayerStruct pPack; // [esp+14h] [ebp-3D8h]

  PackPlayer(&pPack, myplr);
  multi_41D36B(pnum, a2, &pPack, 982);
}

//----- (0041D59D) --------------------------------------------------------
void __cdecl NetClose()
{
  if ( sgbNetInited )
  {
    sgbNetInited = 0;
    nthread_cleanup();
    multi_event_handler(0);
    SNetLeaveGame();
    if ( (signed int)gbMaxPlayers > 1 )
      Sleep(0x3E8u);
    SNetDestroy();
  }
}

//----- (0041D5F5) --------------------------------------------------------
void __fastcall multi_event_handler(BOOL a1)
{
  char *v1; // eax
  BOOL v2; // [esp+Ch] [ebp-Ch]
  int (__stdcall *v3)(int, void (__stdcall *)(void *)); // [esp+10h] [ebp-8h]
  unsigned int i; // [esp+14h] [ebp-4h]

  v2 = a1;
  if ( a1 )
    v3 = (int (__stdcall *)(int, void (__stdcall *)(void *)))&SNetRegisterEventHandler;
  else
    v3 = (int (__stdcall *)(int, void (__stdcall *)(void *)))&SNetUnregisterEventHandler;
  for ( i = 0; i < 3; ++i )
  {
    if ( !v3(dword_4B4038[i], multi_handle_events) )
    {
      if ( v2 )
      {
        v1 = GetLastErr();
        TermMsg("SNetRegisterEventHandler:\n%s", v1);
      }
    }
  }
}

//----- (0041D67E) --------------------------------------------------------
void __stdcall multi_handle_events(void *a1)
{
  bool v1; // zf
  int v2; // [esp+Ch] [ebp-4h]

  v2 = *(_DWORD *)a1;
  if ( v2 == 1 )
  {
    assert(*((_DWORD *)a1 + 2), "multi.cpp", 772);
    assert(*((_DWORD *)a1 + 3) == 4, "multi.cpp", 773);
    s = **((_DWORD **)a1 + 2);
    msg_5FF8B4_isprocessing = 0;
  }
  else if ( v2 != 2 && v2 == 3 )
  {
    v1 = *((_DWORD *)a1 + 1) == 0;
    assert(*((_DWORD *)a1 + 1) < 4u, "multi.cpp", 785);
    byte_5FF8B0[*((_DWORD *)a1 + 1)] = 1;
  }
}

//----- (0041D768) --------------------------------------------------------
int __fastcall NetInit(int bSinglePlayer, int *pfExitProgram)
{
  int result; // eax
  char *v3; // eax
  char *v4; // eax
  char *v5; // eax
  bool v6; // cl
  int v7; // eax
  char v10; // [esp+14h] [ebp-198h]
  unsigned int v11; // [esp+18h] [ebp-194h]
  unsigned int v12; // [esp+1Ch] [ebp-190h]
  int v13; // [esp+20h] [ebp-18Ch]
  int v14; // [esp+24h] [ebp-188h]
  unsigned int v15; // [esp+28h] [ebp-184h]
  unsigned int v16; // [esp+2Ch] [ebp-180h]
  int v17; // [esp+30h] [ebp-17Ch]
  _uiheroinfo a2; // [esp+34h] [ebp-178h]
  int v19; // [esp+54h] [ebp-158h]
  char *v20; // [esp+58h] [ebp-154h]
  int *v21; // [esp+5Ch] [ebp-150h]
  int newseed; // [esp+60h] [ebp-14Ch]
  char v23[36]; // [esp+64h] [ebp-148h]
  char v24[36]; // [esp+88h] [ebp-124h]
  int v25; // [esp+ACh] [ebp-100h]

  LOBYTE(v25) = 0;
  if ( !bSinglePlayer )
  {
    myplr = 0;
    pfile_read_player_from_save();
    game_2_ui_player(plr, &a2);
    if ( !UiCreatePlayerDescription(&a2, (int)&v25) )
      return 0;
  }
  SetRndSeed(0);
  s = time(0);
  assert(pfExitProgram, "multi.cpp", 849);
  *pfExitProgram = 0;
  memset(v24, 0, 0x24u);
  *(_DWORD *)v24 = 36;
  *(_DWORD *)&v24[4] = "Diablo";
  *(_DWORD *)&v24[8] = "version unknown";
  *(_DWORD *)&v24[12] = 1145651522;
  *(_DWORD *)&v24[16] = 3;
  *(_DWORD *)&v24[24] = 4;
  *(_DWORD *)&v24[28] = &s;
  *(_DWORD *)&v24[32] = 4;
  v19 = 12;
  v20 = name;
  v21 = &v25;
  memset(v23, 0, 0x24u);
  *(_DWORD *)v23 = 36;
  *(_DWORD *)&v23[4] = SDrawGetFrameWindow(0);
  *(_DWORD *)&v23[8] = &UiArtCallback;
  *(_DWORD *)&v23[16] = &UiCreateGameCallback;
  *(_DWORD *)&v23[20] = &UiDrawDescCallback;
  *(_DWORD *)&v23[28] = &UiMessageBoxCallback;
  *(_DWORD *)&v23[32] = &UiSoundCallback;
  msg_5FF8B4_isprocessing = 1;
  gbGameDestroyed = 0;
  memset(byte_5FF8B0, 0, 4u);
  memset(byte_5FF8C8, 0, 4u);
  memset(plr, 0, 0x15260u);
  memset(sgwPackPlrOffsetTbl, 0, 8u);
  SNetSetBasePlayer(0);
  if ( bSinglePlayer )
  {
    if ( !SNetInitializeProvider(0, v24, &v19, v23, &fileinfo) )
    {
      v3 = GetLastErr();
      TermMsg("SNetInitializeProvider:\n%s", v3);
    }
    v17 = 0;
    if ( !SNetCreateGame("local", "local", "local", &s, 4, 1, "local", "local", &v17) )
    {
      v4 = GetLastErr();
      TermMsg("SNetCreateGame1:\n%s", v4);
    }
    assert(!v17, "multi.cpp", 906);
    myplr = 0;
    gbMaxPlayers = 1;
  }
  else
  {
    v14 = 1;
    while ( !UiSelectProvider(0, v24, &v19, v23, &fileinfo, &v10) )
    {
      if ( !v14 )
        return 0;
      if ( GetLastError() != 553975818 )
        return 0;
      if ( !multi_upgrade(pfExitProgram) )
        return 0;
      v14 = 0;
    }
    multi_event_handler(1);
    if ( !SNetSelectGame(1, v24, &v19, v23, &fileinfo, &v16) )
      return 0;
    assert(v16 < 4, "multi.cpp", 932);
    if ( !SNetGetNumPlayers(&v15, &v11, &v12) )
    {
      v5 = GetLastErr();
      TermMsg("SNetGetNumPlayers:\n%s", v5);
    }
    assert(v15 < 4, "multi.cpp", 937);
    assert(v11 < 4, "multi.cpp", 938);
    assert(!(!v12 || v12 > 4), "multi.cpp", 939);
    v13 = 0;
    while ( v11 >= v15 )
    {
      if ( SNetGetPlayerName(v15, plr[v15]._pName, 32) )
        ++v13;
      ++v15;
    }
    if ( v12 != v13 )
      TermMsg("Couldn't find all players");
    myplr = v16;
    gbMaxPlayers = 4;
  }
  sgbNetInited = 1;
  sgbTimeout = 0;
  delta_init();
  InitPlrMsg();
  multi_clear_pkt(&pbMsg);
  multi_clear_pkt(packet_5FFCD8);
  multi_clear_pkt(packet_5FF8D0);
  dword_5FF8BC = 0;
  sync_clear_pkt();
  nthread_start(v6);
  dword_6000DC = 0;
  cur_turn = nthread_send_and_recv_turn(0, 1);
  pfile_read_player_from_save();
  NetSendCmd(1u, 3u);
  SetupLocalCoords();
  multi_41D54D(-1, 57);
  plr[myplr].plractive = 1;
  gbActivePlayers = 1;
  if ( msg_5FF8B4_isprocessing || msg_wait_resync() )
  {
    SetRndSeed(s);
    for ( newseed = 0; newseed < 17; ++newseed )
    {
      glSeedTbl[newseed] = GetRndSeed();
      v7 = InitNewSeed(newseed);
      gnLevelTypeTbl[newseed] = v7;
    }
    result = 1;
  }
  else
  {
    NetClose();
    result = 0;
  }
  return result;
}

//----- (0041DDC2) --------------------------------------------------------
void __fastcall multi_clear_pkt(char *a1)
{
  *(_DWORD *)a1 = 0;
  a1[4] = 0;
}

//----- (0041DDE8) --------------------------------------------------------
int __fastcall InitNewSeed(int newseed)
{
  if ( !newseed )
    return 0;
  if ( newseed >= 1 && newseed <= 4 )
    return 1;
  if ( newseed >= 5 && newseed <= 8 )
    return 2;
  if ( newseed < 9 || newseed > 12 )
    return 4;
  return 3;
}

//----- (0041DE6E) --------------------------------------------------------
void __cdecl SetupLocalCoords()
{
  int v0; // ST10_4
  int v1; // ST0C_4

  if ( !leveldebug || (signed int)gbMaxPlayers > 1 )
  {
    currlevel = 0;
    leveltype = 0;
    setlevel = 0;
  }
  v0 = plrxoff[myplr] + 75;
  v1 = plryoff[myplr] + 68;
  plr[myplr].WorldX = v0;
  plr[myplr].WorldY = v1;
  plr[myplr]._px = v0;
  plr[myplr]._py = v1;
  plr[myplr]._ptargx = v0;
  plr[myplr]._ptargy = v1;
  plr[myplr].plrlevel = currlevel;
  plr[myplr].destAction = -1;
}

//----- (0041DFFB) --------------------------------------------------------
int __fastcall multi_upgrade(int *a1)
{
  unsigned int v3; // [esp+14h] [ebp-4h]

  SNetPerformUpgrade(&v3);
  if ( v3 > 2 )
  {
    if ( v3 == -1 )
      DrawDlg("Network upgrade failed");
  }
  else
  {
    switch ( v3 )
    {
      case 2u:
        *a1 = 1;
        break;
      case 0u:
        return 1;
      case 1u:
        return 1;
    }
  }
  return 0;
}

//----- (0041E098) --------------------------------------------------------
void __fastcall multi_player_joins(int pnum, TCmdPlrInfoHdr *cmd, int a3)
{
  if ( sgwPackPlrOffsetTbl[pnum] == cmd->wOffset || (sgwPackPlrOffsetTbl[pnum] = 0, !cmd->wOffset) )
  {
    memcpy(&netplr[982 * pnum + cmd->wOffset], &cmd[1], cmd->wBytes);
    sgwPackPlrOffsetTbl[pnum] += cmd->wBytes;
    if ( sgwPackPlrOffsetTbl[pnum] == 982 )
    {
      sgwPackPlrOffsetTbl[pnum] = 0;
      if ( pnum != myplr )
      {
        if ( plr[pnum].plractive )
        {
          assert(!strcmp(plr[pnum]._pName, &netplr[982 * pnum + 8]), "multi.cpp", 1032);
        }
        else
        {
          plr[pnum]._pGFXLoad = 0;
          UnPackPlayer((PkPlayerStruct *)&netplr[982 * pnum], pnum);
          plr[pnum].plractive = 1;
          ++gbActivePlayers;
          EventPlrMsg("Player '%s' just joined the game", plr[pnum]._pName);
        }
        if ( a3 )
        {
          LoadPlrGFX(pnum, 1);
          SyncInitPlrPos(pnum);
          if ( plr[pnum].plrlevel == currlevel )
            StartStand(pnum, 0);
        }
      }
    }
  }
}

