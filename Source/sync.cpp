//----- (00484BF0) --------------------------------------------------------
int __fastcall sync_all_monsters(TSyncHeader *packet, int size)
{
  unsigned int v3; // [esp+Ch] [ebp-14h]
  TSyncMonster *packeta; // [esp+10h] [ebp-10h]
  int v5; // [esp+14h] [ebp-Ch]
  TSyncHeader *pItem; // [esp+18h] [ebp-8h]
  signed int i; // [esp+1Ch] [ebp-4h]

  if ( nummonsters < 1 )
    return size;
  if ( (unsigned int)size < 0x26 )
    return size;
  pItem = packet;
  packeta = (TSyncMonster *)&packet->bPInvId;
  v3 = size - 33;
  packet->bCmd = 38;
  packet->bLevel = currlevel;
  packet->wLen = 0;
  SyncPlrInv(packet);
  if ( v3 > 0xFFFF )
    assertion_failed(207, "C:\\Diablo\\Direct\\sync.cpp");
  sync_one_monster();
  for ( i = 0; i < nummonsters && v3 >= 5; ++i )
  {
    v5 = 0;
    if ( i < 2 )
      v5 = sync_monster_active2(packeta);
    if ( !v5 )
      v5 = sync_monster_active(packeta);
    if ( !v5 )
      break;
    ++packeta;
    pItem->wLen += 5;
    v3 -= 5;
  }
  return v3;
}

//----- (00484D15) --------------------------------------------------------
void __cdecl sync_one_monster()
{
  __int16 v0; // bx
  int v1; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  for ( i = 0; nummonsters > i; ++i )
  {
    v1 = monstactive[i];
    v0 = abs(plr[myplr].WorldX - monster[v1]._mx);
    sync_word_6453F8[v1] = abs(plr[myplr].WorldY - monster[v1]._my) + v0;
    if ( monster[v1]._msquelch )
    {
      if ( sync_word_645590[v1] )
        --sync_word_645590[v1];
    }
    else
    {
      sync_word_6453F8[v1] += 4096;
    }
  }
}

//----- (00484E40) --------------------------------------------------------
int __fastcall sync_monster_active(TSyncMonster *packet)
{
  int v2; // [esp+10h] [ebp-10h]
  int i; // [esp+14h] [ebp-Ch]
  int mon_id; // [esp+18h] [ebp-8h]
  unsigned int v5; // [esp+1Ch] [ebp-4h]

  mon_id = -1;
  v5 = -1;
  for ( i = 0; nummonsters > i; ++i )
  {
    v2 = monstactive[i];
    if ( sync_word_6453F8[v2] < v5 && (signed int)sync_word_645590[v2] < 65534 )
    {
      v5 = sync_word_6453F8[v2];
      mon_id = monstactive[i];
    }
  }
  if ( mon_id == -1 )
    return 0;
  sync_monster_pos(packet, mon_id);
  return 1;
}

//----- (00484F04) --------------------------------------------------------
void __fastcall sync_monster_pos(TSyncMonster *packet, int mon_id)
{
  WORD v2; // cx

  packet->_mndx = mon_id;
  packet->_mx = monster[mon_id]._mx;
  packet->_my = monster[mon_id]._my;
  packet->_menemy = monster[mon_id]._menemy;
  v2 = sync_word_6453F8[mon_id];
  if ( (signed int)v2 >= 255 )
    LOBYTE(v2) = -1;
  packet->_mdelta = v2;
  sync_word_6453F8[mon_id] = -1;
  if ( monster[mon_id]._msquelch )
    sync_word_645590[mon_id] = -2;
  else
    sync_word_645590[mon_id] = -1;
}

//----- (00484FE1) --------------------------------------------------------
int __fastcall sync_monster_active2(TSyncMonster *packet)
{
  int v2; // [esp+10h] [ebp-10h]
  int v3; // [esp+14h] [ebp-Ch]
  int mon_id; // [esp+18h] [ebp-8h]
  unsigned int v5; // [esp+1Ch] [ebp-4h]

  mon_id = -1;
  v5 = 65534;
  v3 = 0;
  while ( nummonsters > v3 )
  {
    if ( nummonsters <= sync_dword_645588 )
      sync_dword_645588 = 0;
    v2 = monstactive[sync_dword_645588];
    if ( sync_word_645590[v2] < v5 )
    {
      v5 = sync_word_645590[v2];
      mon_id = monstactive[sync_dword_645588];
    }
    ++v3;
    ++sync_dword_645588;
  }
  if ( mon_id == -1 )
    return 0;
  sync_monster_pos(packet, mon_id);
  return 1;
}

//----- (004850AA) --------------------------------------------------------
void __fastcall SyncPlrInv(TSyncHeader *pItem)
{
  ItemStruct *v1; // [esp+10h] [ebp-8h]
  int v2; // [esp+14h] [ebp-4h]

  if ( numitems <= 0 )
  {
    pItem->bItemI = -1;
  }
  else
  {
    if ( sync_dword_4DBB1C >= numitems )
      sync_dword_4DBB1C = 0;
    v2 = itemactive[sync_dword_4DBB1C++];
    pItem->bItemI = v2;
    pItem->bItemX = item[v2]._ix;
    pItem->bItemY = item[v2]._iy;
    pItem->wItemIndx = item[v2].IDidx;
    pItem->wItemCI = item[v2]._iCreateInfo;
    pItem->seed = item[v2]._iSeed;
    pItem->bItemId = item[v2]._iIdentified;
    pItem->bItemDur = item[v2]._iDurability;
    pItem->bItemMDur = item[v2]._iMaxDur;
    pItem->bItemCh = item[v2]._iCharges;
    pItem->bItemMCh = item[v2]._iMaxCharges;
    if ( !item[v2].IDidx )
      pItem->wItemVal = item[v2]._ivalue;
  }
  if ( (unsigned int)sgnSyncPInv >= 7 )
    assertion_failed(167, "C:\\Diablo\\Direct\\sync.cpp");
  v1 = &plr[myplr].InvBody[sgnSyncPInv];
  if ( plr[myplr].InvBody[sgnSyncPInv]._itype == -1 )
  {
    pItem->dwItemBuff = -1;
  }
  else
  {
    pItem->dwItemBuff = sgnSyncPInv;
    pItem->wPInvIndx = v1->IDidx;
    pItem->wPInvCI = v1->_iCreateInfo;
    pItem->dwPInvSeed = v1->_iSeed;
  }
  if ( ++sgnSyncPInv >= 7 )
    sgnSyncPInv = 0;
}

//----- (00485315) --------------------------------------------------------
int __fastcall SyncData(int pnum, TSyncHeader *packet)
{
  TSyncMonster *packeta; // [esp+Ch] [ebp-10h]
  unsigned __int16 i; // [esp+18h] [ebp-4h]

  packeta = (TSyncMonster *)&packet->bPInvId;
  if ( packet->bCmd != 38 )
    TermMsg("bad sync command");
  if ( gbBufferMsgs == 2 )
    assertion_failed(343, "C:\\Diablo\\Direct\\sync.cpp");
  if ( gbBufferMsgs == 1 )
    return packet->wLen + 33;
  if ( myplr == pnum )
    return packet->wLen + 33;
  for ( i = packet->wLen; i >= 5u; i -= 5 )
  {
    if ( packet->bLevel == currlevel )
      sync_monster_data(pnum, packeta);
    delta_sync_monster(packeta, packet->bLevel);
    ++packeta;
  }
  if ( i )
    assertion_failed(363, "C:\\Diablo\\Direct\\sync.cpp");
  return packet->wLen + 33;
}

//----- (0048544D) --------------------------------------------------------
void __fastcall sync_monster_data(int pnum, TSyncMonster *packet)
{
  int v2; // ebx
  int v3; // ST30_4
  int v4; // eax
  int mdir; // [esp+14h] [ebp-18h]
  unsigned int v8; // [esp+18h] [ebp-14h]
  int j; // [esp+1Ch] [ebp-10h]
  int i; // [esp+20h] [ebp-Ch]
  int v11; // [esp+24h] [ebp-8h]

  i = packet->_mndx;
  if ( monster[i]._mhitpoints )
  {
    for ( j = 0; nummonsters > j && monstactive[j] != i; ++j )
      ;
    if ( nummonsters <= j )
      assertion_failed(240, "C:\\Diablo\\Direct\\sync.cpp");
    v2 = abs(plr[myplr].WorldY - monster[i]._my);
    v8 = abs(plr[myplr].WorldX - monster[i]._mx) + v2;
    if ( v8 > 0xFF )
      v8 = 255;
    if ( packet->_mdelta <= v8
      && (packet->_mdelta != v8 || pnum <= myplr)
      && (monster[i]._mfutx != packet->_mx || monster[i]._mfuty != packet->_my) )
    {
      v3 = abs(monster[i]._mx - packet->_mx);
      v11 = abs(monster[i]._my - packet->_my);
      if ( v3 <= 2 && v11 <= 2 )
      {
        mdir = GetDirection(monster[i]._moldx, monster[i]._moldy, packet->_mx, packet->_my);
        if ( (monster[i]._mmode < 1 || monster[i]._mmode > 3) && DirOK(i, mdir) )
        {
          M_ClearSquares(i);
          dMonster[monster[i]._moldx][monster[i]._moldy] = i + 1;
          monster[i]._mx = monster[i]._moldx;
          monster[i]._my = monster[i]._moldy;
          M_WalkDir(i, mdir);
          monster[i]._msquelch = -1;
        }
      }
      else if ( !dMonster[packet->_mx][packet->_my] )
      {
        M_ClearSquares(i);
        dMonster[packet->_mx][packet->_my] = i + 1;
        monster[i]._mx = packet->_mx;
        monster[i]._my = packet->_my;
        if ( monster[i]._mFlags & 0x10 )
          v4 = GetDirection(packet->_mx, packet->_my, monster[packet->_menemy]._mx, monster[packet->_menemy]._my);
        else
          v4 = GetDirection(packet->_mx, packet->_my, plr[packet->_menemy].WorldX, plr[packet->_menemy].WorldY);
        M_StartStand(i, v4);
        monster[i]._msquelch = -1;
      }
      monster[i]._menemy = packet->_menemy;
    }
  }
}

//----- (0048594F) --------------------------------------------------------
void __cdecl sync_clear_pkt()
{
  sync_dword_645588 = 16 * myplr;
  memset(sync_word_645590, 255, 0x190u);
}

