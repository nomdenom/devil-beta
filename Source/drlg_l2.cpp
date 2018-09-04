//----- (0047C790) --------------------------------------------------------
BOOL __fastcall DRLG_L2PlaceMiniSet(unsigned __int8 *miniset, int tmin, int tmax, int cx, int cy, bool setview, int ldir)
{
  int l; // [esp+14h] [ebp-2Ch]
  int n; // [esp+14h] [ebp-2Ch]
  signed int v11; // [esp+18h] [ebp-28h]
  signed int j; // [esp+1Ch] [ebp-24h]
  int v13; // [esp+20h] [ebp-20h]
  int v14; // [esp+24h] [ebp-1Ch]
  int v15; // [esp+28h] [ebp-18h]
  int v16; // [esp+2Ch] [ebp-14h]
  int i; // [esp+30h] [ebp-10h]
  int v18; // [esp+34h] [ebp-Ch]
  int k; // [esp+38h] [ebp-8h]
  int m; // [esp+38h] [ebp-8h]
  signed int v21; // [esp+3Ch] [ebp-4h]
  int v22; // [esp+3Ch] [ebp-4h]

  v16 = *miniset;
  v15 = miniset[1];
  if ( tmax == tmin )
    v18 = 1;
  else
    v18 = random(0, tmax - tmin) + tmin;
  for ( i = 0; v18 > i; ++i )
  {
    v14 = random(0, 40 - v16);
    v13 = random(0, 40 - v15);
    v11 = 0;
    for ( j = 0; !v11 && j < 200; ++j )
    {
      v11 = 1;
      if ( nSx1 <= v14 && nSx2 >= v14 && nSy1 <= v13 && nSy2 >= v13 )
        v11 = 0;
      if ( cx != -1 && cx - v16 <= v14 && cx + 12 >= v14 )
      {
        v14 = random(0, 40 - v16);
        v13 = random(0, 40 - v15);
        v11 = 0;
      }
      if ( cy != -1 && cy - v15 <= v13 && cy + 12 >= v13 )
      {
        v14 = random(0, 40 - v16);
        v13 = random(0, 40 - v15);
        v11 = 0;
      }
      v21 = 2;
      for ( k = 0; k < v15 && v11 == 1; ++k )
      {
        for ( l = 0; l < v16 && v11 == 1; ++l )
        {
          if ( miniset[v21] && dungeon[v14 + l][v13 + k] != miniset[v21] )
            v11 = 0;
          if ( Xdflags_2[v14 + l][v13 + k] )
            v11 = 0;
          ++v21;
        }
      }
      if ( !v11 && 40 - v16 == ++v14 )
      {
        v14 = 0;
        if ( 40 - v15 == ++v13 )
          v13 = 0;
      }
    }
    if ( j >= 200 )
      return 0;
    v22 = v16 * v15 + 2;
    for ( m = 0; m < v15; ++m )
    {
      for ( n = 0; n < v16; ++n )
      {
        if ( miniset[v22] )
          dungeon[v14 + n][v13 + m] = miniset[v22];
        ++v22;
      }
    }
  }
  if ( setview == 1 )
  {
    ViewX = 2 * v14 + 21;
    ViewY = 2 * v13 + 22;
  }
  if ( !ldir )
  {
    LvlViewX = 2 * v14 + 21;
    LvlViewY = 2 * v13 + 22;
  }
  if ( ldir == 6 )
  {
    LvlViewX = 2 * v14 + 21;
    LvlViewY = 2 * v13 + 22;
  }
  return 1;
}

//----- (0047CB6D) --------------------------------------------------------
void __fastcall DRLG_L2PlaceRndSet(unsigned __int8 *miniset, int rndper)
{
  int l; // [esp+14h] [ebp-28h]
  int jj; // [esp+14h] [ebp-28h]
  int v6; // [esp+18h] [ebp-24h]
  signed int v7; // [esp+1Ch] [ebp-20h]
  int i; // [esp+20h] [ebp-1Ch]
  int j; // [esp+24h] [ebp-18h]
  int v10; // [esp+28h] [ebp-14h]
  int n; // [esp+30h] [ebp-Ch]
  int k; // [esp+34h] [ebp-8h]
  int ii; // [esp+34h] [ebp-8h]
  signed int v15; // [esp+38h] [ebp-4h]
  int m; // [esp+38h] [ebp-4h]

  rndper = *miniset;
  v10 = miniset[1];
  for ( i = 0; 40 - v10 > i; ++i )
  {
    for ( j = 0; 40 - rndper > j; ++j )
    {
      v7 = 1;
      v15 = 2;
      if ( j >= nSx1 && j <= nSx2 && i >= nSy1 && i <= nSy2 )
        v7 = 0;
      for ( k = 0; k < v10 && v7 == 1; ++k )
      {
        for ( l = 0; l < rndper && v7 == 1; ++l )
        {
          if ( miniset[v15] && dungeon[l + j][k + i] != miniset[v15] )
            v7 = 0;
          if ( Xdflags_2[l + j][k + i] )
            v7 = 0;
          ++v15;
        }
      }
      v6 = rndper * v10 + 2;
      if ( v7 == 1 )
      {
        for ( m = i - v10; i + 2 * v10 > m && v7 == 1; ++m )
        {
          for ( n = j - rndper; j + 2 * rndper > n; ++n )
          {
            if ( dungeon[n][m] == miniset[v6] )
              v7 = 0;
          }
        }
      }
      if ( v7 == 1 && random(0, 100) < rndper )
      {
        for ( ii = 0; ii < v10; ++ii )
        {
          for ( jj = 0; jj < rndper; ++jj )
          {
            if ( miniset[v6] )
              dungeon[jj + j][ii + i] = miniset[v6];
            ++v6;
          }
        }
      }
    }
  }
}

//----- (0047CE24) --------------------------------------------------------
void __cdecl DRLG_L2Subs()
{
  int l; // [esp+Ch] [ebp-1Ch]
  int k; // [esp+10h] [ebp-18h]
  signed int i; // [esp+14h] [ebp-14h]
  signed int v3; // [esp+18h] [ebp-10h]
  signed int j; // [esp+1Ch] [ebp-Ch]
  int v5; // [esp+20h] [ebp-8h]
  char v6; // [esp+24h] [ebp-4h]

  for ( i = 0; i < 40; ++i )
  {
    for ( j = 0; j < 40; ++j )
    {
      if ( (nSx1 > j || nSx2 < j) && (nSy1 > i || nSy2 < i) && !random(0, 4) )
      {
        v6 = BTYPESL2[dungeon[j][i]];
        if ( v6 )
        {
          v5 = random(0, 16);
          v3 = -1;
          while ( v5 >= 0 )
          {
            if ( ++v3 == 161 )
              v3 = 0;
            if ( BTYPESL2[v3] == v6 )
              --v5;
          }
          for ( k = i - 2; i + 2 > k; ++k )
          {
            for ( l = j - 2; j + 2 > l; ++l )
            {
              if ( dungeon[l][k] == v3 )
              {
                k = i + 3;
                l = j + 2;
              }
            }
          }
          if ( i + 3 > k )
            dungeon[j][i] = v3;
        }
      }
    }
  }
}

//----- (0047CFE6) --------------------------------------------------------
void __cdecl DRLG_L2Shadows()
{
  signed int i; // [esp+Ch] [ebp-14h]
  signed int k; // [esp+10h] [ebp-10h]
  signed int j; // [esp+14h] [ebp-Ch]
  signed int v3; // [esp+18h] [ebp-8h]
  char v4; // [esp+1Ch] [ebp-4h]
  char v5; // [esp+1Dh] [ebp-3h]
  char v6; // [esp+1Eh] [ebp-2h]
  char v7; // [esp+1Fh] [ebp-1h]

  for ( i = 1; i < 40; ++i )
  {
    for ( j = 1; j < 40; ++j )
    {
      v4 = BSTYPESL2[dungeon[j][i]];
      v6 = BSTYPESL2[dungeon[j - 1][i]];
      v5 = BSTYPESL2[dungeon[j - 1][i + 39]];
      v7 = BSTYPESL2[dungeon[j][i - 2]];
      for ( k = 0; k < 2; ++k )
      {
        if ( SPATSL2[k][0] == v4 )
        {
          v3 = 1;
          if ( SPATSL2[k][1] && SPATSL2[k][1] != v7 )
            v3 = 0;
          if ( SPATSL2[k][2] && SPATSL2[k][2] != v5 )
            v3 = 0;
          if ( SPATSL2[k][3] && SPATSL2[k][3] != v6 )
            v3 = 0;
          if ( v3 == 1 )
          {
            if ( SPATSL2[k][4] )
              dungeon[j][i - 2] = SPATSL2[k][4];
            if ( SPATSL2[k][5] )
              dungeon[j - 1][i + 39] = SPATSL2[k][5];
            if ( SPATSL2[k][6] )
              dungeon[j - 1][i] = SPATSL2[k][6];
          }
        }
      }
    }
  }
}

//----- (0047D27C) --------------------------------------------------------
void __cdecl InitDungeon()
{
  signed int j; // [esp+Ch] [ebp-8h]
  signed int i; // [esp+10h] [ebp-4h]

  for ( i = 0; i < 40; ++i )
  {
    for ( j = 0; j < 40; ++j )
    {
      predungeon[j][i] = 32;
      Xdflags_2[j][i] = 0;
    }
  }
}

//----- (0047D2ED) --------------------------------------------------------
void __cdecl DRLG_LoadL2SP()
{
  setloadflag_2 = 0;
  if ( quests[8]._qlevel == currlevel )
  {
    pSetPiece_2 = LoadFileInMem("Levels\\L2Data\\Blind2.DUN", 0, 1417, "C:\\Diablo\\Direct\\DRLG_L2.CPP");
    setloadflag_2 = 1;
  }
  else if ( quests[9]._qlevel == currlevel )
  {
    pSetPiece_2 = LoadFileInMem("Levels\\L2Data\\Blood1.DUN", 0, 1421, "C:\\Diablo\\Direct\\DRLG_L2.CPP");
    setloadflag_2 = 1;
  }
}

//----- (0047D384) --------------------------------------------------------
void __cdecl DRLG_FreeL2SP()
{
  mem_free_dbg(pSetPiece_2, 1429, "C:\\Diablo\\Direct\\DRLG_L2.CPP");
  pSetPiece_2 = 0;
}

//----- (0047D3B3) --------------------------------------------------------
void __fastcall DRLG_L2SetRoom(int rx1, int ry1)
{
  int i; // [esp+14h] [ebp-14h]
  int j; // [esp+18h] [ebp-10h]
  int v4; // [esp+1Ch] [ebp-Ch]
  int v5; // [esp+20h] [ebp-8h]
  BYTE *v6; // [esp+24h] [ebp-4h]

  v5 = *(unsigned __int8 *)pSetPiece_2;
  v4 = *((unsigned __int8 *)pSetPiece_2 + 2);
  setpc_x = rx1;
  setpc_y = ry1;
  setpc_w = v5;
  setpc_h = v4;
  v6 = (BYTE *)pSetPiece_2 + 4;
  for ( i = 0; i < v4; ++i )
  {
    for ( j = 0; j < v5; ++j )
    {
      if ( *v6 )
      {
        dungeon[j + rx1][ry1 + i] = *v6;
        Xdflags_2[j + rx1][ry1 + i] |= 0x80u;
      }
      else
      {
        dungeon[j + rx1][ry1 + i] = 3;
      }
      v6 += 2;
    }
  }
}

//----- (0047D4D6) --------------------------------------------------------
void __fastcall DefineRoom(int nX1, int nY1, int nX2, int nY2, int ForceHW)
{
  int l; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  int j; // [esp+18h] [ebp-8h]
  int k; // [esp+18h] [ebp-8h]
  int nY2a; // [esp+2Ch] [ebp+Ch]

  predungeon[nX1][nY1] = 67;
  predungeon[nX1][nY2] = 69;
  predungeon[nX2][nY1] = 66;
  predungeon[nX2][nY2] = 65;
  RoomList[++nRoomCnt].nRoomx1 = nX1;
  RoomList[nRoomCnt].nRoomx2 = nX2;
  RoomList[nRoomCnt].nRoomy1 = nY1;
  RoomList[nRoomCnt].nRoomy2 = nY2;
  if ( ForceHW == 1 )
  {
    for ( i = nX1; i < nX2; ++i )
    {
      while ( i < nY2 )
        Xdflags_2[i++][nY1] |= 0x80u;
    }
  }
  for ( j = nX1 + 1; nX2 - 1 >= j; ++j )
  {
    predungeon[j][nY1] = 35;
    predungeon[j][nY2] = 35;
  }
  nY2a = nY2 - 1;
  for ( k = nY1 + 1; k <= nY2a; ++k )
  {
    predungeon[nX1][k] = 35;
    predungeon[nX2][k] = 35;
    for ( l = nX1 + 1; l < nX2; ++l )
      predungeon[l][k] = 46;
  }
}

//----- (0047D6B0) --------------------------------------------------------
void __fastcall CreateDoorType(int nX, int nY)
{
  signed int v2; // [esp+18h] [ebp-4h]

  v2 = 0;
  if ( predungeon[nX - 1][nY] == 68 )// IDX
    v2 = 1;
  if ( predungeon[nX + 1][nY] == 68 )// IDX
    v2 = 1;
  if ( predungeon[nX - 1][nY + 39] == 68 )
    v2 = 1;
  if ( predungeon[nX][nY + 1] == 68 )
    v2 = 1;
  if ( predungeon[nX][nY] == 66 || predungeon[nX][nY] == 67 || predungeon[nX][nY] == 65 || predungeon[nX][nY] == 69 )
    v2 = 1;
  if ( !v2 )
    predungeon[nX][nY] = 68;
}

//----- (0047D7FC) --------------------------------------------------------
void __fastcall PlaceHallExt(int nX, int nY)
{
  if ( predungeon[nX][nY] == 32 )
    predungeon[nX][nY] = 44;
}

//----- (0047D841) --------------------------------------------------------
void __fastcall AddHall(int nX1, int nY1, int nX2, int nY2, int nHd)
{
  HALLNODE *v7; // [esp+14h] [ebp-8h]
  HALLNODE *i; // [esp+18h] [ebp-4h]

  if ( pHallList )
  {
    v7 = (HALLNODE *)DiabloAllocPtr(24, 1571, "C:\\Diablo\\Direct\\DRLG_L2.CPP");
    v7->nHallx1 = nX1;
    v7->nHally1 = nY1;
    v7->nHallx2 = nX2;
    v7->nHally2 = nY2;
    v7->nHalldir = nHd;
    v7->pNext = 0;
    for ( i = pHallList; i->pNext; i = i->pNext )
      ;
    i->pNext = v7;
  }
  else
  {
    pHallList = (HALLNODE *)DiabloAllocPtr(24, 1562, "C:\\Diablo\\Direct\\DRLG_L2.CPP");
    pHallList->nHallx1 = nX1;
    pHallList->nHally1 = nY1;
    pHallList->nHallx2 = nX2;
    pHallList->nHally2 = nY2;
    pHallList->nHalldir = nHd;
    pHallList->pNext = 0;
  }
}

//----- (0047D947) --------------------------------------------------------
void __fastcall CreateRoom(int nX1, int nY1, int nX2, int nY2, int nRDest, int nHDir, int ForceHW, int nH, int nW)
{
  int v; // [esp+14h] [ebp-34h]
  int v12; // [esp+18h] [ebp-30h]
  int v13; // [esp+1Ch] [ebp-2Ch]
  int v14; // [esp+20h] [ebp-28h]
  int v15; // [esp+24h] [ebp-24h]
  int v16; // [esp+28h] [ebp-20h]
  int nY1a; // [esp+2Ch] [ebp-1Ch]
  int v18; // [esp+30h] [ebp-18h]
  int v19; // [esp+34h] [ebp-14h]
  int v20; // [esp+38h] [ebp-10h]
  int nX1a; // [esp+3Ch] [ebp-Ch]
  int v22; // [esp+40h] [ebp-8h]
  int v23; // [esp+44h] [ebp-4h]

  if ( nRoomCnt < 80 )
  {
    v20 = nX2 - nX1;
    v18 = nY2 - nY1;
    if ( nX2 - nX1 >= Area_Min && v18 >= Area_Min )
    {
      if ( v20 <= Room_Max )
      {
        if ( v20 <= Room_Min )
          v14 = nX2 - nX1;
        else
          v14 = random(0, v20 - Room_Min) + Room_Min;
      }
      else
      {
        v14 = random(0, Room_Max - Room_Min) + Room_Min;
      }
      if ( v18 <= Room_Max )
      {
        if ( v18 <= Room_Min )
          v13 = v18;
        else
          v13 = random(0, v18 - Room_Min) + Room_Min;
      }
      else
      {
        v13 = random(0, Room_Max - Room_Min) + Room_Min;
      }
      if ( ForceHW == 1 )
      {
        v14 = nW;
        v13 = nH;
      }
      nX1a = random(0, nX2 - nX1) + nX1;
      nY1a = random(0, nY2 - nY1) + nY1;
      v19 = v14 + nX1a;
      v16 = v13 + nY1a;
      if ( nX2 < v14 + nX1a )
      {
        v19 = nX2;
        nX1a = nX2 - v14;
      }
      if ( nY2 < v16 )
      {
        v16 = nY2;
        nY1a = nY2 - v13;
      }
      if ( nX1a >= 38 )
        nX1a = 38;
      if ( nY1a >= 38 )
        nY1a = 38;
      if ( nX1a <= 1 )
        nX1a = 1;
      if ( nY1a <= 1 )
        nY1a = 1;
      if ( v19 >= 38 )
        v19 = 38;
      if ( v16 >= 38 )
        v16 = 38;
      if ( v19 <= 1 )
        v19 = 1;
      if ( v16 <= 1 )
        v16 = 1;
      DefineRoom(nX1a, nY1a, v19, v16, ForceHW);
      if ( ForceHW == 1 )
      {
        nSx1 = nX1a + 2;
        nSy1 = nY1a + 2;
        nSx2 = v19;
        nSy2 = v16;
      }
      v15 = nRoomCnt;
      RoomList[nRoomCnt].nRoomDest = nRDest;
      if ( nRDest )
      {
        if ( nHDir == 1 )
        {
          v12 = random(0, v19 - nX1a - 2) + nX1a + 1;
          v23 = nY1a;
          v = random(0, RoomList[nRDest].nRoomx2 - RoomList[nRDest].nRoomx1 - 2) + RoomList[nRDest].nRoomx1 + 1;
          v22 = RoomList[nRDest].nRoomy2;
        }
        if ( nHDir == 3 )
        {
          v12 = random(0, v19 - nX1a - 2) + nX1a + 1;
          v23 = v16;
          v = random(0, RoomList[nRDest].nRoomx2 - RoomList[nRDest].nRoomx1 - 2) + RoomList[nRDest].nRoomx1 + 1;
          v22 = RoomList[nRDest].nRoomy1;
        }
        if ( nHDir == 2 )
        {
          v12 = v19;
          v23 = random(0, v16 - nY1a - 2) + nY1a + 1;
          v = RoomList[nRDest].nRoomx1;
          v22 = random(0, RoomList[nRDest].nRoomy2 - RoomList[nRDest].nRoomy1 - 2) + RoomList[nRDest].nRoomy1 + 1;
        }
        if ( nHDir == 4 )
        {
          v12 = nX1a;
          v23 = random(0, v16 - nY1a - 2) + nY1a + 1;
          v = RoomList[nRDest].nRoomx2;
          v22 = random(0, RoomList[nRDest].nRoomy2 - RoomList[nRDest].nRoomy1 - 2) + RoomList[nRDest].nRoomy1 + 1;
        }
        AddHall(v12, v23, v, v22, nHDir);
      }
      if ( v13 <= v14 )
      {
        CreateRoom(nX1 + 2, nY1 + 2, v19 - 2, nY1a - 2, v15, 3, 0, 0, 0);
        CreateRoom(nX1a + 2, v16 + 2, nX2 - 2, nY2 - 2, v15, 1, 0, 0, 0);
        CreateRoom(nX1 + 2, nY1a + 2, nX1a - 2, nY2 - 2, v15, 2, 0, 0, 0);
        CreateRoom(v19 + 2, nY1 + 2, nX2 - 2, v16 - 2, v15, 4, 0, 0, 0);
      }
      else
      {
        CreateRoom(nX1 + 2, nY1 + 2, nX1a - 2, v16 - 2, v15, 2, 0, 0, 0);
        CreateRoom(v19 + 2, nY1a + 2, nX2 - 2, nY2 - 2, v15, 4, 0, 0, 0);
        CreateRoom(nX1 + 2, v16 + 2, v19 - 2, nY2 - 2, v15, 1, 0, 0, 0);
        CreateRoom(nX1a + 2, nY1 + 2, nX2 - 2, nY1a - 2, v15, 3, 0, 0, 0);
      }
    }
  }
}

//----- (0047DF47) --------------------------------------------------------
void __fastcall GetHall(int *nX1, int *nY1, int *nX2, int *nY2, int *nHd)
{
  HALLNODE *v5; // ST18_4

  v5 = pHallList->pNext;
  *nX1 = pHallList->nHallx1;
  *nY1 = pHallList->nHally1;
  *nX2 = pHallList->nHallx2;
  *nY2 = pHallList->nHally2;
  *nHd = pHallList->nHalldir;
  mem_free_dbg(pHallList, 1720, "C:\\Diablo\\Direct\\DRLG_L2.CPP");
  pHallList = v5;
}

//----- (0047DFCA) --------------------------------------------------------
void __fastcall ConnectHall(int nX1, int nY1, int nX2, int nY2, int nHd)
{
  signed int nY; // [esp+Ch] [ebp-30h] MAPDST
  signed int nX; // [esp+10h] [ebp-2Ch] MAPDST
  signed int v8; // [esp+18h] [ebp-24h]
  int v9; // [esp+1Ch] [ebp-20h]
  int v10; // [esp+20h] [ebp-1Ch]
  int v11; // [esp+24h] [ebp-18h]
  int v12; // [esp+28h] [ebp-14h]
  int v13; // [esp+28h] [ebp-14h]
  signed int v15; // [esp+30h] [ebp-Ch]
  int v16; // [esp+34h] [ebp-8h]
  int v17; // [esp+38h] [ebp-4h]
  int nX2a; // [esp+44h] [ebp+8h]
  int nY2a; // [esp+48h] [ebp+Ch]

  nY = nY1;
  nX = nX1;
  v15 = 0;
  v10 = random(0, 100);
  v9 = random(0, 100);
  CreateDoorType(nX, nY);
  CreateDoorType(nX2, nY2);
  abs(nX2 - nX);
  abs(nY2 - nY);
  v16 = nHd;
  nX2a = nX2 - Dir_Xadd[nHd];
  nY2a = nY2 - Dir_Yadd[nHd];
  predungeon[nX2a][nY2a] = 44;
  v8 = 0;
  while ( !v15 )
  {
    if ( nX >= 38 && v16 == 2 )
      v16 = 4;
    if ( nY >= 38 && v16 == 3 )
      v16 = 1;
    if ( nX <= 1 && v16 == 4 )
      v16 = 2;
    if ( nY <= 1 && v16 == 1 )
      v16 = 3;
    if ( predungeon[nX][nY] == 67 && (v16 == 1 || v16 == 4) )
      v16 = 2;
    if ( predungeon[nX][nY] == 66 && (v16 == 1 || v16 == 2) )
      v16 = 3;
    if ( predungeon[nX][nY] == 69 && (v16 == 4 || v16 == 3) )
      v16 = 1;
    if ( predungeon[nX][nY] == 65 && (v16 == 2 || v16 == 3) )
      v16 = 4;
    nX += Dir_Xadd[v16];
    nY += Dir_Yadd[v16];
    if ( predungeon[nX][nY] == 32 )
    {
      if ( v8 )
      {
        CreateDoorType(nX - Dir_Xadd[v16], nY - Dir_Yadd[v16]);
      }
      else
      {
        if ( v10 < 50 )
        {
          if ( v16 != 1 && v16 != 3 )
            PlaceHallExt(nX, nY - 1);
          else
            PlaceHallExt(nX - 1, nY);
        }
        if ( v9 < 50 )
        {
          if ( v16 != 1 && v16 != 3 )
            PlaceHallExt(nX, nY + 1);
          else
            PlaceHallExt(nX + 1, nY);
        }
      }
      predungeon[nX][nY] = 44;
      v8 = 0;
    }
    else
    {
      if ( !v8 && predungeon[nX][nY] == 35 )
        CreateDoorType(nX, nY);
      if ( predungeon[nX][nY] != 44 )
        v8 = 1;
    }
    v17 = abs(nX2a - nX);
    v11 = abs(nY2a - nY);
    if ( v11 >= v17 )
    {
      v13 = 5 * v11;
      if ( 5 * v11 > 80 )
        v13 = 80;
      if ( random(0, 100) < v13 )
      {
        if ( nY2a <= nY || nY >= 40 )
          v16 = 1;
        else
          v16 = 3;
      }
    }
    else
    {
      v12 = 2 * v17;
      if ( 2 * v17 > 30 )
        v12 = 30;
      if ( random(0, 100) < v12 )
      {
        if ( nX2a <= nX || nX >= 40 )
          v16 = 4;
        else
          v16 = 2;
      }
    }
    if ( v11 < 10 && nX2a == nX && (v16 == 2 || v16 == 4) )
    {
      if ( nY2a <= nY || nY >= 40 )
        v16 = 1;
      else
        v16 = 3;
    }
    if ( v17 < 10 && nY2a == nY && (v16 == 1 || v16 == 3) )
    {
      if ( nX2a <= nX || nX >= 40 )
        v16 = 4;
      else
        v16 = 2;
    }
    if ( v11 == 1 && v17 > 1 && (v16 == 1 || v16 == 3) )
    {
      if ( nX2a <= nX || nX >= 40 )
        v16 = 4;
      else
        v16 = 2;
    }
    if ( v17 == 1 && v11 > 1 && (v16 == 2 || v16 == 4) )
    {
      if ( nY2a <= nY || nX >= 40 )
        v16 = 1;
      else
        v16 = 3;
    }
    if ( !v17 && predungeon[nX][nY] != 32 && (v16 == 2 || v16 == 4) )
    {
      if ( nX2a <= nX || nX >= 40 )
        v16 = 1;
      else
        v16 = 3;
    }
    if ( !v11 && predungeon[nX][nY] != 32 && (v16 == 1 || v16 == 3) )
    {
      if ( nY2a <= nY || nY >= 40 )
        v16 = 4;
      else
        v16 = 2;
    }
    if ( nX2a == nX && nY2a == nY )
      v15 = 1;
  }
}

//----- (0047E63C) --------------------------------------------------------
void __fastcall DoPatternCheck(int i, int j)
{
  signed int v2; // [esp+18h] [ebp-14h]
  signed int l; // [esp+1Ch] [ebp-10h]
  int k; // [esp+20h] [ebp-Ch]
  int v5; // [esp+24h] [ebp-8h]
  int v6; // [esp+28h] [ebp-4h]

  for ( k = 0; Patterns[k][4] != 255; ++k )
  {
    v6 = i - 1;
    v5 = j - 1;
    v2 = 254;
    for ( l = 0; l < 9 && v2 == 254; ++l )
    {
      v2 = 255;
      if ( l == 3 || l == 6 )
      {
        ++v5;
        v6 = i - 1;
      }
      if ( v6 >= 0 && v6 < 40 && v5 >= 0 && v5 < 40 )
      {
        switch ( Patterns[k][l] )
        {
          case 0:
            v2 = 254;
            break;
          case 1:
            if ( predungeon[v6][v5] == 35 )
              v2 = 254;
            break;
          case 2:
            if ( predungeon[v6][v5] == 46 )
              v2 = 254;
            break;
          case 3:
            if ( predungeon[v6][v5] == 68 )
              v2 = 254;
            break;
          case 4:
            if ( predungeon[v6][v5] == 32 )
              v2 = 254;
            break;
          case 5:
            if ( predungeon[v6][v5] == 68 || predungeon[v6][v5] == 46 )
              v2 = 254;
            break;
          case 6:
            if ( predungeon[v6][v5] == 68 || predungeon[v6][v5] == 35 )
              v2 = 254;
            break;
          case 7:
            if ( predungeon[v6][v5] == 32 || predungeon[v6][v5] == 46 )
              v2 = 254;
            break;
          case 8:
            if ( predungeon[v6][v5] == 68 || predungeon[v6][v5] == 35 || predungeon[v6][v5] == 46 )
              v2 = 254;
            break;
          default:
            break;
        }
      }
      else
      {
        v2 = 254;
      }
      ++v6;
    }
    if ( v2 == 254 )
      dungeon[i][j] = Patterns[k][9];
  }
}

//----- (0047E975) --------------------------------------------------------
void __cdecl L2TileFix()
{
  signed int i; // [esp+Ch] [ebp-8h]
  signed int j; // [esp+10h] [ebp-4h]

  for ( i = 0; i < 40; ++i )
  {
    for ( j = 0; j < 40; ++j )
    {
      if ( dungeon[j][i] == 1 && dungeon[j][i + 1] == 3 )
        dungeon[j][i + 1] = 1;
      if ( dungeon[j][i] == 3 && dungeon[j][i + 1] == 1 )
        dungeon[j][i + 1] = 3;
      if ( dungeon[j][i] == 3 && dungeon[j + 1][i] == 7 )
        dungeon[j + 1][i] = 3;
      if ( dungeon[j][i] == 2 && dungeon[j + 1][i] == 3 )
        dungeon[j + 1][i] = 2;
      if ( dungeon[j][i] == 11 && dungeon[j + 1][i] == 14 )
        dungeon[j + 1][i] = 16;
    }
  }
}

//----- (0047EB2D) --------------------------------------------------------
BOOL __fastcall DL2_Cont(bool x1f, bool y1f, bool x2f, bool y2f)
{
  if ( x1f && x2f && y1f && y2f )
    return 0;
  if ( x1f && x2f && (y1f || y2f) )
    return 1;
  if ( y1f && y2f && (x1f || x2f) )
    return 1;
  return 0;
}

//----- (0047EBDD) --------------------------------------------------------
int __cdecl DL2_NumNoChar()
{
  signed int i; // [esp+Ch] [ebp-Ch]
  int v2; // [esp+10h] [ebp-8h]
  signed int j; // [esp+14h] [ebp-4h]

  v2 = 0;
  for ( i = 0; i < 40; ++i )
  {
    for ( j = 0; j < 40; ++j )
    {
      if ( predungeon[j][i] == 32 )
        ++v2;
    }
  }
  return v2;
}

//----- (0047EC54) --------------------------------------------------------
void __fastcall DL2_DrawRoom(int x1, int y1, int x2, int y2)
{
  int i; // [esp+14h] [ebp-8h]
  int k; // [esp+14h] [ebp-8h]
  int j; // [esp+18h] [ebp-4h]
  int l; // [esp+18h] [ebp-4h]

  for ( i = y1; i <= y2; ++i )
  {
    for ( j = x1; j <= x2; ++j )
      predungeon[j][i] = 46;
  }
  for ( k = y1; k <= y2; ++k )
  {
    predungeon[x1][k] = 35;
    predungeon[x2][k] = 35;
  }
  for ( l = x1; l <= x2; ++l )
  {
    predungeon[l][y1] = 35;
    predungeon[l][y2] = 35;
  }
}

//----- (0047ED40) --------------------------------------------------------
void __fastcall DL2_KnockWalls(int x1, int y1, int x2, int y2)
{
  int j; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  for ( i = x1 + 1; i < x2; ++i )
  {
    if ( predungeon[i - 1][y1 + 39] == 46 && predungeon[i][y1 + 1] == 46 )
      predungeon[i][y1] = 46;
    if ( predungeon[i - 1][y2 + 39] == 46 && predungeon[i][y2 + 1] == 46 )
      predungeon[i][y2] = 46;
    if ( predungeon[i - 1][y1 + 39] == 68 )
      predungeon[i - 1][y1 + 39] = 35;
    if ( predungeon[i][y2 + 1] == 68 )
      predungeon[i][y2 + 1] = 35;
  }
  for ( j = y1 + 1; j < y2; ++j )
  {
    if ( predungeon[x1 - 1][j] == 46 && predungeon[x1 + 1][j] == 46 )
      predungeon[x1][j] = 46;
    if ( predungeon[x2 - 1][j] == 46 && predungeon[x2 + 1][j] == 46 )
      predungeon[x2][j] = 46;
    if ( predungeon[x1 - 1][j] == 68 )
      predungeon[x1 - 1][j] = 35;
    if ( predungeon[x2 + 1][j] == 68 )
      predungeon[x2 + 1][j] = 35;
  }
}

//----- (0047EF6F) --------------------------------------------------------
BOOL __cdecl DL2_FillVoids()
{
  int v0; // eax
  int v2; // [esp+Ch] [ebp-34h]
  int y2; // [esp+10h] [ebp-30h]
  int y2a; // [esp+10h] [ebp-30h]
  int y2b; // [esp+10h] [ebp-30h]
  int y2c; // [esp+10h] [ebp-30h]
  int y1; // [esp+14h] [ebp-2Ch]
  int y1a; // [esp+14h] [ebp-2Ch]
  int y1b; // [esp+14h] [ebp-2Ch]
  int y1c; // [esp+14h] [ebp-2Ch]
  BOOL y2f; // [esp+18h] [ebp-28h]
  BOOL x2f; // [esp+1Ch] [ebp-24h]
  BOOL y1f; // [esp+20h] [ebp-20h]
  int x2; // [esp+24h] [ebp-1Ch]
  int x2a; // [esp+24h] [ebp-1Ch]
  int x2b; // [esp+24h] [ebp-1Ch]
  int x2c; // [esp+24h] [ebp-1Ch]
  BOOL x1f; // [esp+28h] [ebp-18h]
  int l; // [esp+2Ch] [ebp-14h]
  int k; // [esp+2Ch] [ebp-14h]
  int x1; // [esp+30h] [ebp-10h]
  int x1a; // [esp+30h] [ebp-10h]
  int x1b; // [esp+30h] [ebp-10h]
  int x1c; // [esp+30h] [ebp-10h]
  signed int v25; // [esp+34h] [ebp-Ch]
  int v26; // [esp+38h] [ebp-8h]
  int j; // [esp+3Ch] [ebp-4h]
  int i; // [esp+3Ch] [ebp-4h]

  v25 = 0;
  while ( DL2_NumNoChar() > 700 && v25 < 100 )
  {
    v2 = random(0, 38) + 1;
    v0 = random(0, 38);
    v26 = v0 + 1;
    if ( predungeon[v2][v0 + 1] == 35 )
    {
      y2f = 0;
      y1f = 0;
      x2f = 0;
      x1f = 0;
      if ( predungeon[v2 - 1][v26] != 32 || predungeon[v2 + 1][v26] != 46 )
      {
        if ( predungeon[v2 + 1][v26] != 32 || predungeon[v2 - 1][v26] != 46 )
        {
          if ( predungeon[v2][v0] != 32 || predungeon[v2][v26 + 1] != 46 )
          {
            if ( predungeon[v2][v26 + 1] == 32
              && predungeon[v2][v0] == 46
              && predungeon[v2 - 1][v0] == 46
              && predungeon[v2 + 1][v0] == 46
              && predungeon[v2 - 1][v26 + 1] == 32
              && predungeon[v2 + 1][v26 + 1] == 32 )
            {
              x2f = 1;
              x1f = 1;
              y2f = 1;
            }
          }
          else if ( predungeon[v2 - 1][v26 + 1] == 46
                 && predungeon[v2 + 1][v26 + 1] == 46
                 && predungeon[v2 - 1][v0] == 32
                 && predungeon[v2 + 1][v0] == 32 )
          {
            x2f = 1;
            x1f = 1;
            y1f = 1;
          }
        }
        else if ( predungeon[v2 - 1][v0] == 46
               && predungeon[v2 - 1][v26 + 1] == 46
               && predungeon[v2 + 1][v0] == 32
               && predungeon[v2 + 1][v26 + 1] == 32 )
        {
          y2f = 1;
          y1f = 1;
          x2f = 1;
        }
      }
      else if ( predungeon[v2 + 1][v0] == 46
             && predungeon[v2 + 1][v26 + 1] == 46
             && predungeon[v2 - 1][v0] == 32
             && predungeon[v2 - 1][v26 + 1] == 32 )
      {
        y2f = 1;
        y1f = 1;
        x1f = 1;
      }
      if ( DL2_Cont(x1f, y1f, x2f, y2f) )
      {
        if ( x1f )
          x1 = v2 - 1;
        else
          x1 = v2;
        if ( x2f )
          x2 = v2 + 1;
        else
          x2 = v2;
        if ( y1f )
          y1 = v26 - 1;
        else
          y1 = v26;
        if ( y2f )
          y2 = v26 + 1;
        else
          y2 = v26;
        if ( x1f )
        {
          if ( x2f )
          {
            if ( y1f )
            {
              if ( !y2f )
              {
                while ( x1f || x2f )
                {
                  if ( !x1 )
                    x1f = 0;
                  if ( x2 == 39 )
                    x2f = 0;
                  if ( x2 - x1 >= 14 )
                  {
                    x1f = 0;
                    x2f = 0;
                  }
                  if ( x1f )
                    --x1;
                  if ( x2f )
                    ++x2;
                  if ( predungeon[x1][y1] != 32 )
                    x1f = 0;
                  if ( predungeon[x2][y1] != 32 )
                    x2f = 0;
                }
                x1c = x1 + 2;
                x2c = x2 - 2;
                if ( x2c - x1c > 5 )
                {
                  while ( y1f )
                  {
                    if ( !y1 )
                      y1f = 0;
                    if ( y2 - y1 >= 12 )
                      y1f = 0;
                    for ( i = x1c; i <= x2c; ++i )
                    {
                      if ( predungeon[i][y1] != 32 )
                        y1f = 0;
                    }
                    if ( y1f )
                      --y1;
                  }
                  y1c = y1 + 2;
                  if ( y2 - y1c > 5 )
                  {
                    DL2_DrawRoom(x1c, y1c, x2c, y2);
                    DL2_KnockWalls(x1c, y1c, x2c, y2);
                  }
                }
              }
            }
            else
            {
              while ( x1f || x2f )
              {
                if ( !x1 )
                  x1f = 0;
                if ( x2 == 39 )
                  x2f = 0;
                if ( x2 - x1 >= 14 )
                {
                  x1f = 0;
                  x2f = 0;
                }
                if ( x1f )
                  --x1;
                if ( x2f )
                  ++x2;
                if ( predungeon[x1][y2] != 32 )
                  x1f = 0;
                if ( predungeon[x2][y2] != 32 )
                  x2f = 0;
              }
              x1b = x1 + 2;
              x2b = x2 - 2;
              if ( x2b - x1b > 5 )
              {
                while ( y2f )
                {
                  if ( y2 == 39 )
                    y2f = 0;
                  if ( y2 - y1 >= 12 )
                    y2f = 0;
                  for ( j = x1b; j <= x2b; ++j )
                  {
                    if ( predungeon[j][y2] != 32 )
                      y2f = 0;
                  }
                  if ( y2f )
                    ++y2;
                }
                y2c = y2 - 2;
                if ( y2c - y1 > 5 )
                {
                  DL2_DrawRoom(x1b, y1, x2b, y2c);
                  DL2_KnockWalls(x1b, y1, x2b, y2c);
                }
              }
            }
          }
          else
          {
            while ( y1f || y2f )
            {
              if ( !y1 )
                y1f = 0;
              if ( y2 == 39 )
                y2f = 0;
              if ( y2 - y1 >= 14 )
              {
                y1f = 0;
                y2f = 0;
              }
              if ( y1f )
                --y1;
              if ( y2f )
                ++y2;
              if ( predungeon[x1][y1] != 32 )
                y1f = 0;
              if ( predungeon[x1][y2] != 32 )
                y2f = 0;
            }
            y1b = y1 + 2;
            y2b = y2 - 2;
            if ( y2b - y1b > 5 )
            {
              while ( x1f )
              {
                if ( !x1 )
                  x1f = 0;
                if ( x2 - x1 >= 12 )
                  x1f = 0;
                for ( k = y1b; k <= y2b; ++k )
                {
                  if ( predungeon[x1][k] != 32 )
                    x1f = 0;
                }
                if ( x1f )
                  --x1;
              }
              x1a = x1 + 2;
              if ( x2 - x1a > 5 )
              {
                DL2_DrawRoom(x1a, y1b, x2, y2b);
                DL2_KnockWalls(x1a, y1b, x2, y2b);
              }
            }
          }
        }
        else
        {
          while ( y1f || y2f )
          {
            if ( !y1 )
              y1f = 0;
            if ( y2 == 39 )
              y2f = 0;
            if ( y2 - y1 >= 14 )
            {
              y1f = 0;
              y2f = 0;
            }
            if ( y1f )
              --y1;
            if ( y2f )
              ++y2;
            if ( predungeon[x2][y1] != 32 )
              y1f = 0;
            if ( predungeon[x2][y2] != 32 )
              y2f = 0;
          }
          y1a = y1 + 2;
          y2a = y2 - 2;
          if ( y2a - y1a > 5 )
          {
            while ( x2f )
            {
              if ( x2 == 39 )
                x2f = 0;
              if ( x2 - x1 >= 12 )
                x2f = 0;
              for ( l = y1a; l <= y2a; ++l )
              {
                if ( predungeon[x2][l] != 32 )
                  x2f = 0;
              }
              if ( x2f )
                ++x2;
            }
            x2a = x2 - 2;
            if ( x2a - x1 > 5 )
            {
              DL2_DrawRoom(x1, y1a, x2a, y2a);
              DL2_KnockWalls(x1, y1a, x2a, y2a);
            }
          }
        }
      }
      ++v25;
    }
  }
  return DL2_NumNoChar() <= 700;
}

//----- (0047F9FC) --------------------------------------------------------
BOOL __cdecl CreateDungeon()
{
  int nW; // [esp+10h] [ebp-28h]
  int nH; // [esp+14h] [ebp-24h]
  int nX2; // [esp+18h] [ebp-20h]
  int nX1; // [esp+1Ch] [ebp-1Ch]
  int nHd; // [esp+20h] [ebp-18h]
  int j; // [esp+24h] [ebp-14h]
  int i; // [esp+28h] [ebp-10h]
  int ForceHW; // [esp+2Ch] [ebp-Ch]
  int nY2; // [esp+30h] [ebp-8h]
  int nY1; // [esp+34h] [ebp-4h]

  nW = 0;
  nH = 0;
  ForceHW = 0;
  switch ( currlevel )
  {
    case 5u:
      if ( quests[9]._qactive )
      {
        ForceHW = 1;
        nH = 20;
        nW = 14;
      }
      break;
    case 6u:
      if ( quests[3]._qactive )
      {
        ForceHW = 1;
        nW = 9;
        nH = 9;
      }
      break;
    case 7u:
      if ( quests[8]._qactive )
      {
        ForceHW = 1;
        nW = 15;
        nH = 15;
      }
      break;
    case 8u:
      break;
  }
  CreateRoom(2, 2, 39, 39, 0, 0, ForceHW, nH, nW);
  while ( pHallList )
  {
    GetHall(&nX1, &nY1, &nX2, &nY2, &nHd);
    ConnectHall(nX1, nY1, nX2, nY2, nHd);
  }
  for ( j = 0; j <= 40; ++j )
  {
    for ( i = 0; i <= 40; ++i )
    {
      if ( predungeon[i][j] == 67 )
        predungeon[i][j] = 35;
      if ( predungeon[i][j] == 66 )
        predungeon[i][j] = 35;
      if ( predungeon[i][j] == 69 )
        predungeon[i][j] = 35;
      if ( predungeon[i][j] == 65 )
        predungeon[i][j] = 35;
      if ( predungeon[i][j] == 44 )
      {
        predungeon[i][j] = 46;
        if ( predungeon[i][j - 2] == 32 )
          predungeon[i][j - 2] = 35;
        if ( predungeon[i - 1][j] == 32 )
          predungeon[i - 1][j] = 35;
        if ( predungeon[i - 1][j + 1] == 32 )
          predungeon[i - 1][j + 1] = 35;
        if ( predungeon[i + 2][j - 2] == 32 )
          predungeon[i + 2][j - 2] = 35;
        if ( predungeon[i + 1][j] == 32 )
          predungeon[i + 1][j] = 35;
        if ( predungeon[i + 1][j + 1] == 32 )
          predungeon[i + 1][j + 1] = 35;
        if ( predungeon[i - 1][j + 39] == 32 )
          predungeon[i - 1][j + 39] = 35;
        if ( predungeon[i][j + 1] == 32 )
          predungeon[i][j + 1] = 35;
      }
    }
  }
  if ( !DL2_FillVoids() )
    return 0;
  for ( j = 0; j < 40; ++j )
  {
    for ( i = 0; i < 40; ++i )
      DoPatternCheck(i, j);
  }
  return 1;
}

//----- (0047FE23) --------------------------------------------------------
void __cdecl DRLG_L2Pass3()
{
  int v0; // eax
  int v1; // eax
  WORD *v2; // esi
  WORD v3; // ax
  int v4; // eax
  int v5; // ST2C_4
  int v6; // ST28_4
  int v7; // ST24_4
  signed int j; // [esp+Ch] [ebp-24h]
  signed int v9; // [esp+Ch] [ebp-24h]
  signed int k; // [esp+14h] [ebp-1Ch]
  signed int l; // [esp+18h] [ebp-18h]
  signed int i; // [esp+1Ch] [ebp-14h]
  signed int v13; // [esp+1Ch] [ebp-14h]
  int v14; // [esp+24h] [ebp-Ch]
  int v15; // [esp+28h] [ebp-8h]
  int v16; // [esp+2Ch] [ebp-4h]

  v0 = pMegaTiles[44] + 1;
  v16 = pMegaTiles[44] + 1;
  LOWORD(v0) = pMegaTiles[45];
  v15 = ++v0;
  LOWORD(v0) = pMegaTiles[46];
  v1 = v0 + 1;
  v14 = v1;
  LOWORD(v1) = pMegaTiles[47];
  for ( i = 0; i < 112; i += 2 )
  {
    for ( j = 0; j < 112; j += 2 )
    {
      dPiece[j][i] = v16;
      dPiece[j + 1][i] = v15;
      dPiece[j][i + 1] = v14;
      dPiece[j + 1][i + 1] = v1 + 1;
    }
  }
  v13 = 16;
  for ( k = 0; k < 40; ++k )
  {
    v9 = 16;
    for ( l = 0; l < 40; ++l )
    {
      v2 = &pMegaTiles[4 * (dungeon[l][k] - 1)];
      v3 = *v2;
      ++v2;
      v4 = v3 + 1;
      v5 = v4;
      LOWORD(v4) = *v2;
      ++v2;
      v6 = ++v4;
      LOWORD(v4) = *v2;
      v7 = ++v4;
      LOWORD(v4) = v2[1];
      dPiece[v9][v13] = v5;
      dPiece[v9 + 1][v13] = v6;
      dPiece[v9][v13 + 1] = v7;
      dPiece[v9 + 1][v13 + 1] = v4 + 1;
      v9 += 2;
    }
    v13 += 2;
  }
}

//----- (00480007) --------------------------------------------------------
void __fastcall DRLG_L2FTVR(int i, int j, int x, int y, int d)
{
  if ( dung_map[x][y] || dungeon[i][j] != 3 )
  {
    if ( d == 1 )
    {
      dung_map[x][y] = TransVal;
      dung_map[x][y + 1] = TransVal;
    }
    if ( d == 2 )
    {
      dung_map[x + 1][y] = TransVal;
      dung_map[x + 1][y + 1] = TransVal;
    }
    if ( d == 3 )
    {
      dung_map[x][y] = TransVal;
      dung_map[x + 1][y] = TransVal;
    }
    if ( d == 4 )
    {
      dung_map[x][y + 1] = TransVal;
      dung_map[x + 1][y + 1] = TransVal;
    }
    if ( d == 5 )
      dung_map[x + 1][y + 1] = TransVal;
    if ( d == 6 )
      dung_map[x][y + 1] = TransVal;
    if ( d == 7 )
      dung_map[x + 1][y] = TransVal;
    if ( d == 8 )
      dung_map[x][y] = TransVal;
  }
  else
  {
    dung_map[x][y] = TransVal;
    dung_map[x + 1][y] = TransVal;
    dung_map[x][y + 1] = TransVal;
    dung_map[x + 1][y + 1] = TransVal;
    DRLG_L2FTVR(i + 1, j, x + 2, y, 1);
    DRLG_L2FTVR(i - 1, j, x - 2, y, 2);
    DRLG_L2FTVR(i, j + 1, x, y + 2, 3);
    DRLG_L2FTVR(i, j - 1, x, y - 2, 4);
    DRLG_L2FTVR(i - 1, j - 1, x - 2, y - 2, 5);
    DRLG_L2FTVR(i + 1, j - 1, x + 2, y - 2, 6);
    DRLG_L2FTVR(i - 1, j + 1, x - 2, y + 2, 7);
    DRLG_L2FTVR(i + 1, j + 1, x + 2, y + 2, 8);
  }
}

//----- (00480352) --------------------------------------------------------
void __cdecl DRLG_L2FloodTVal()
{
  int x; // [esp+Ch] [ebp-10h]
  int j; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]
  int y; // [esp+18h] [ebp-4h]

  y = 16;
  for ( j = 0; j < 40; ++j )
  {
    x = 16;
    for ( i = 0; i < 40; ++i )
    {
      if ( dungeon[i][j] == 3 && !dung_map[x][y] )
      {
        DRLG_L2FTVR(i, j, x, y, 0);
        ++TransVal;
      }
      x += 2;
    }
    y += 2;
  }
}

//----- (0048040D) --------------------------------------------------------
void __cdecl DRLG_L2TransFix()
{
  signed int v0; // [esp+Ch] [ebp-10h]
  signed int i; // [esp+10h] [ebp-Ch]
  signed int j; // [esp+14h] [ebp-8h]
  signed int v3; // [esp+18h] [ebp-4h]

  v3 = 16;
  for ( i = 0; i < 40; ++i )
  {
    v0 = 16;
    for ( j = 0; j < 40; ++j )
    {
      if ( dungeon[j][i] == 14 && dungeon[j - 1][i + 39] == 10 )
      {
        dung_map[v0 + 1][v3] = dung_map[v0][v3];
        dung_map[v0 + 1][v3 + 1] = dung_map[v0][v3];
      }
      if ( dungeon[j][i] == 15 && dungeon[j + 1][i] == 11 )
      {
        dung_map[v0][v3 + 1] = dung_map[v0][v3];
        dung_map[v0 + 1][v3 + 1] = dung_map[v0][v3];
      }
      if ( dungeon[j][i] == 10 )
      {
        dung_map[v0 + 1][v3] = dung_map[v0][v3];
        dung_map[v0 + 1][v3 + 1] = dung_map[v0][v3];
      }
      if ( dungeon[j][i] == 11 )
      {
        dung_map[v0][v3 + 1] = dung_map[v0][v3];
        dung_map[v0 + 1][v3 + 1] = dung_map[v0][v3];
      }
      if ( dungeon[j][i] == 16 )
      {
        dung_map[v0 + 1][v3] = dung_map[v0][v3];
        dung_map[v0][v3 + 1] = dung_map[v0][v3];
        dung_map[v0 + 1][v3 + 1] = dung_map[v0][v3];
      }
      v0 += 2;
    }
    v3 += 2;
  }
}

//----- (00480732) --------------------------------------------------------
void __cdecl L2DirtFix()
{
  signed int i; // [esp+Ch] [ebp-8h]
  signed int j; // [esp+10h] [ebp-4h]

  for ( i = 0; i < 40; ++i )
  {
    for ( j = 0; j < 40; ++j )
    {
      if ( dungeon[j][i] == 13 && dungeon[j + 1][i] != 11 )
        dungeon[j][i] = -110;
      if ( dungeon[j][i] == 11 && dungeon[j + 1][i] != 11 )
        dungeon[j][i] = -112;
      if ( dungeon[j][i] == 15 && dungeon[j + 1][i] != 11 )
        dungeon[j][i] = -108;
      if ( dungeon[j][i] == 10 && dungeon[j][i + 1] != 10 )
        dungeon[j][i] = -113;
      if ( dungeon[j][i] == 13 && dungeon[j][i + 1] != 10 )
        dungeon[j][i] = -110;
      if ( dungeon[j][i] == 14 && dungeon[j][i + 1] != 15 )
        dungeon[j][i] = -109;
    }
  }
}

//----- (0048092E) --------------------------------------------------------
BOOL __fastcall DRLG_WillThemeRoomFit(int x, int y, int minSize, int maxSize, int *width, int *height)
{
  int j; // [esp+14h] [ebp-C4h]
  int v10; // [esp+18h] [ebp-C0h]
  signed int v11; // [esp+1Ch] [ebp-BCh]
  int v12; // [esp+20h] [ebp-B8h]
  int v13; // [esp+24h] [ebp-B4h]
  int v14; // [esp+28h] [ebp-B0h]
  int k; // [esp+2Ch] [ebp-ACh]
  int i; // [esp+30h] [ebp-A8h]
  int l; // [esp+30h] [ebp-A8h]
  int m; // [esp+30h] [ebp-A8h]
  signed int v19; // [esp+34h] [ebp-A4h]
  int v20[20]; // [esp+38h] [ebp-A0h]
  int v21[20]; // [esp+88h] [ebp-50h]

  v13 = 0;
  v10 = 0;
  v19 = 1;
  v11 = 1;
  if ( 40 - maxSize < x && 40 - maxSize < y )
    return 0;
  memset(v20, 0, 0x50u);
  memset(v21, 0, 0x50u);
  for ( i = 0; i < maxSize; ++i )
  {
    if ( v11 )
    {
      for ( j = x; x + maxSize > j; ++j )
      {
        if ( dungeon[j][y + i] == 3 )
        {
          ++v13;
        }
        else
        {
          if ( j >= minSize )
            break;
          v11 = 0;
        }
      }
      if ( v11 )
      {
        v20[i] = v13;
        v13 = 0;
      }
    }
    if ( v19 )
    {
      for ( k = y; y + maxSize > k; ++k )
      {
        if ( dungeon[x + i][k] == 3 )
        {
          ++v10;
        }
        else
        {
          if ( k >= minSize )
            break;
          v19 = 0;
        }
      }
      if ( v19 )
      {
        v21[i] = v10;
        v10 = 0;
      }
    }
  }
  for ( l = 0; l < minSize; ++l )
  {
    if ( v20[l] < minSize || v21[l] < minSize )
      return 0;
  }
  v14 = v20[0];
  v12 = v21[0];
  for ( m = 0; m < maxSize && v20[m] >= minSize && v21[m] >= minSize; ++m )
  {
    if ( v20[m] < v14 )
      v14 = v20[m];
    if ( v21[m] < v12 )
      v12 = v21[m];
  }
  *width = v14 - 2;
  *height = v12 - 2;
  return 1;
}

//----- (00480CA9) --------------------------------------------------------
void __fastcall DRLG_CreateThemeRoom(int themeIndex, int width, int height)
{
  int v3; // [esp+Ch] [ebp-14h]
  int j; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  for ( i = themeLoc[themeIndex].y; height + themeLoc[themeIndex].y > i; ++i )
  {
    for ( j = themeLoc[themeIndex].x; width + themeLoc[themeIndex].x > j; ++j )
    {
      if ( (themeLoc[themeIndex].y != i || themeLoc[themeIndex].x > j || width + themeLoc[themeIndex].x < j)
        && (height - 1 + themeLoc[themeIndex].y != i || themeLoc[themeIndex].x > j || width + themeLoc[themeIndex].x < j) )
      {
        if ( (themeLoc[themeIndex].x != j || themeLoc[themeIndex].y > i || height + themeLoc[themeIndex].y < i)
          && (width - 1 + themeLoc[themeIndex].x != j
           || themeLoc[themeIndex].y > i
           || height + themeLoc[themeIndex].y < i) )
        {
          dungeon[j][i] = 3;
        }
        else
        {
          dungeon[j][i] = 1;
        }
      }
      else
      {
        dungeon[j][i] = 2;
      }
    }
  }
  dungeon[themeLoc[themeIndex].x][themeLoc[themeIndex].y] = 8;
  dungeon[width - 1 + themeLoc[themeIndex].x][themeLoc[themeIndex].y] = 7;
  dungeon[themeLoc[themeIndex].x][height - 1 + themeLoc[themeIndex].y] = 9;
  dungeon[width - 1 + themeLoc[themeIndex].x][height - 1 + themeLoc[themeIndex].y] = 6;
  v3 = random(0, 2);
  if ( v3 )
  {
    if ( v3 == 1 )
      dungeon[width / 2 + themeLoc[themeIndex].x][height - 1 + themeLoc[themeIndex].y] = 5;
  }
  else
  {
    dungeon[width - 1 + themeLoc[themeIndex].x][height / 2 + themeLoc[themeIndex].y] = 4;
  }
}

//----- (00480FDF) --------------------------------------------------------
void __cdecl DRLG_PlaceThemeRooms()
{
  signed int x; // [esp+Ch] [ebp-10h]
  signed int floor; // [esp+10h] [ebp-Ch]
  int height; // [esp+14h] [ebp-8h]
  int width; // [esp+18h] [ebp-4h]

  themeCount = 0;
  for ( x = 0; x < 40; ++x )
  {
    for ( floor = 0; floor < 40; ++floor )
    {
      if ( dungeon[floor][x] == 3 && !random(0, 10) )
      {
        if ( DRLG_WillThemeRoomFit(floor, x, 6, 10, &width, &height) )
        {
          themeLoc[themeCount].x = floor + 1;
          themeLoc[themeCount].y = x + 1;
          themeLoc[themeCount].width = width;
          themeLoc[themeCount].height = height;
          DRLG_MRectTrans(floor + 1, x + 1, floor + width - 1, x + height - 1);
          themeLoc[themeCount].ttval = TransVal - 1;
          DRLG_CreateThemeRoom(themeCount, width, height);
          ++themeCount;
        }
      }
    }
  }
}

//----- (00481121) --------------------------------------------------------
void __fastcall DRLG_L2(int entry)
{
  signed int i; // [esp+10h] [ebp-Ch]
  signed int j; // [esp+14h] [ebp-8h]
  BOOL v4; // [esp+18h] [ebp-4h]

  v4 = 0;
  while ( !v4 )
  {
    nRoomCnt = 0;
    InitDungeon();
    DRLG_InitTrans();
    if ( CreateDungeon() )
    {
      L2TileFix();
      if ( setloadflag_2 )
        DRLG_L2SetRoom(nSx1, nSy1);
      DRLG_L2FloodTVal();
      DRLG_L2TransFix();
      if ( entry )
      {
        if ( entry == 1 )
        {
          v4 = DRLG_L2PlaceMiniSet(&USTAIRS, 1, 1, -1, -1, 0, 0);
          if ( v4 && currlevel == 5 )
            v4 = DRLG_L2PlaceMiniSet(&WARPSTAIRS, 1, 1, -1, -1, 0, 6);
          ++ViewY;
        }
        else
        {
          v4 = DRLG_L2PlaceMiniSet(&USTAIRS, 1, 1, -1, -1, 0, 0);
          if ( v4 && currlevel == 5 )
            v4 = DRLG_L2PlaceMiniSet(&WARPSTAIRS, 1, 1, -1, -1, 1, 6);
          ++ViewX;
        }
      }
      else
      {
        v4 = DRLG_L2PlaceMiniSet(&USTAIRS, 1, 1, -1, -1, 1, 0);
        if ( v4 )
        {
          if ( currlevel == 5 )
            v4 = DRLG_L2PlaceMiniSet(&WARPSTAIRS, 1, 1, -1, -1, 0, 6);
        }
        ++ViewX;
      }
    }
  }
  L2DirtFix();
  if ( v4 )
    DRLG_PlaceThemeRooms();
  DRLG_L2PlaceRndSet(&byte_4DA730, 100);
  DRLG_L2PlaceRndSet(&byte_4DA748, 100);
  DRLG_L2PlaceRndSet(&byte_4DA760, 100);
  DRLG_L2PlaceRndSet(&byte_4DA778, 100);
  DRLG_L2PlaceRndSet(&byte_4DA790, 100);
  DRLG_L2PlaceRndSet(&byte_4DA7A8, 100);
  DRLG_L2PlaceRndSet(&byte_4DA7C0, 100);
  DRLG_L2PlaceRndSet(CTRDOOR8, 100);
  DRLG_L2PlaceRndSet(&byte_4DA288, 100);
  DRLG_L2PlaceRndSet(&byte_4DA2A0, 100);
  DRLG_L2PlaceRndSet(&byte_4DA2B8, 100);
  DRLG_L2PlaceRndSet(&byte_4DA2D0, 100);
  DRLG_L2PlaceRndSet(&byte_4DA2E8, 100);
  DRLG_L2PlaceRndSet(&byte_4DA300, 100);
  DRLG_L2PlaceRndSet(&byte_4DA318, 100);
  DRLG_L2PlaceRndSet(&byte_4DA330, 100);
  DRLG_L2PlaceRndSet(&byte_4D9FC8, 100);
  DRLG_L2PlaceRndSet(&byte_4D9FE0, 100);
  DRLG_L2PlaceRndSet(&byte_4D9FF8, 100);
  DRLG_L2PlaceRndSet(&byte_4DA010, 100);
  DRLG_L2PlaceRndSet(&byte_4DA028, 100);
  DRLG_L2PlaceRndSet(&byte_4DA040, 100);
  DRLG_L2PlaceRndSet(&byte_4DA058, 100);
  DRLG_L2PlaceRndSet(&byte_4DA070, 100);
  DRLG_L2PlaceRndSet(&byte_4DA088, 100);
  DRLG_L2PlaceRndSet(&byte_4DA0A0, 100);
  DRLG_L2PlaceRndSet(&byte_4DA0B8, 100);
  DRLG_L2PlaceRndSet(&byte_4DA0D0, 100);
  DRLG_L2PlaceRndSet(&byte_4DA0E8, 100);
  DRLG_L2PlaceRndSet(&byte_4DA100, 100);
  DRLG_L2PlaceRndSet(&byte_4DA118, 100);
  DRLG_L2PlaceRndSet(&byte_4DA130, 100);
  DRLG_L2PlaceRndSet(&byte_4DA148, 100);
  DRLG_L2PlaceRndSet(&byte_4DA158, 100);
  DRLG_L2PlaceRndSet(&byte_4DA168, 100);
  DRLG_L2PlaceRndSet(&byte_4DA178, 100);
  DRLG_L2PlaceRndSet(&byte_4DA188, 100);
  DRLG_L2PlaceRndSet(&byte_4DA198, 100);
  DRLG_L2PlaceRndSet(&byte_4DA1A8, 100);
  DRLG_L2PlaceRndSet(&byte_4DA1B8, 100);
  DRLG_L2PlaceRndSet(&byte_4DA1C8, 100);
  DRLG_L2PlaceRndSet(&byte_4DA1E0, 100);
  DRLG_L2PlaceRndSet(&byte_4DA1F8, 100);
  DRLG_L2PlaceRndSet(&byte_4DA210, 100);
  DRLG_L2PlaceRndSet(&byte_4DA228, 100);
  DRLG_L2PlaceRndSet(&byte_4DA240, 100);
  DRLG_L2PlaceRndSet(&byte_4DA258, 100);
  DRLG_L2PlaceRndSet(&byte_4DA270, 100);
  DRLG_L2PlaceRndSet(&byte_4DA348, 100);
  DRLG_L2PlaceRndSet(&byte_4DA358, 100);
  DRLG_L2PlaceRndSet(&byte_4DA368, 100);
  DRLG_L2PlaceRndSet(&byte_4DA378, 100);
  DRLG_L2PlaceRndSet(&byte_4DA388, 100);
  DRLG_L2PlaceRndSet(&byte_4DA398, 100);
  DRLG_L2PlaceRndSet(&byte_4DA3A8, 100);
  DRLG_L2PlaceRndSet(&byte_4DA3B8, 100);
  DRLG_L2PlaceRndSet(&byte_4DA3C8, 100);
  DRLG_L2PlaceRndSet(&byte_4DA3D8, 100);
  DRLG_L2PlaceRndSet(&byte_4DA3E8, 100);
  DRLG_L2PlaceRndSet(&byte_4DA3F8, 100);
  DRLG_L2PlaceRndSet(&byte_4DA408, 100);
  DRLG_L2PlaceRndSet(&byte_4DA418, 100);
  DRLG_L2PlaceRndSet(&byte_4DA428, 100);
  DRLG_L2PlaceRndSet(&byte_4DA438, 100);
  DRLG_L2PlaceRndSet(&byte_4DA448, 100);
  DRLG_L2PlaceRndSet(&byte_4DA458, 100);
  DRLG_L2PlaceRndSet(&byte_4DA468, 100);
  DRLG_L2PlaceRndSet(&byte_4DA478, 100);
  DRLG_L2PlaceRndSet(&byte_4DA488, 100);
  DRLG_L2PlaceRndSet(&byte_4DA498, 100);
  DRLG_L2PlaceRndSet(&byte_4DA4A8, 100);
  DRLG_L2PlaceRndSet(&byte_4DA4B8, 100);
  DRLG_L2PlaceRndSet(&byte_4DA4C8, 100);
  DRLG_L2PlaceRndSet(&byte_4DA4D8, 100);
  DRLG_L2PlaceRndSet(&byte_4DA4E8, 100);
  DRLG_L2PlaceRndSet(&byte_4DA4F8, 100);
  DRLG_L2PlaceRndSet(&byte_4DA508, 100);
  DRLG_L2PlaceRndSet(&byte_4DA518, 100);
  DRLG_L2PlaceRndSet(&byte_4DA528, 100);
  DRLG_L2PlaceRndSet(&byte_4DA538, 100);
  DRLG_L2PlaceRndSet(&byte_4DA548, 100);
  DRLG_L2PlaceRndSet(&byte_4DA558, 100);
  DRLG_L2PlaceRndSet(&byte_4DA568, 100);
  DRLG_L2PlaceRndSet(&byte_4DA578, 100);
  DRLG_L2PlaceRndSet(&byte_4DA588, 100);
  DRLG_L2PlaceRndSet(&byte_4DA598, 100);
  DRLG_L2PlaceRndSet(&byte_4DA5A8, 100);
  DRLG_L2PlaceRndSet(&byte_4DA5B8, 100);
  DRLG_L2PlaceRndSet(&CRUSHCOL, 99);
  DRLG_L2PlaceRndSet(&byte_4DA6D4, 10);
  DRLG_L2PlaceRndSet(&byte_4DA6D8, 10);
  DRLG_L2PlaceRndSet(&byte_4DA6DC, 10);
  DRLG_L2PlaceRndSet(&byte_4DA6E0, 10);
  DRLG_L2PlaceRndSet(&byte_4DA6E4, 10);
  DRLG_L2PlaceRndSet(&byte_4DA6E8, 10);
  DRLG_L2PlaceRndSet(&byte_4DA6EC, 50);
  DRLG_L2PlaceRndSet(&byte_4DA6F0, 1);
  DRLG_L2PlaceRndSet(&byte_4DA710, 1);
  DRLG_L2PlaceRndSet(&byte_4DA658, 3);
  DRLG_L2PlaceRndSet(&byte_4DA668, 3);
  DRLG_L2PlaceRndSet(&byte_4DA678, 3);
  DRLG_L2PlaceRndSet(&byte_4DA680, 3);
  DRLG_L2PlaceRndSet(&byte_4DA688, 3);
  DRLG_L2PlaceRndSet(&byte_4DA698, 20);
  DRLG_L2PlaceRndSet(&byte_4DA6A0, 20);
  DRLG_L2PlaceRndSet(&byte_4DA6A8, 3);
  DRLG_L2PlaceRndSet(&byte_4DA6B8, 20);
  DRLG_L2PlaceRndSet(&BIG10, 20);
  DRLG_L2Subs();
  DRLG_L2Shadows();
  for ( i = 0; i < 40; ++i )
  {
    for ( j = 0; j < 40; ++j )
      pdungeon[j][i] = dungeon[j][i];
  }
  DRLG_CheckQuests(nSx1, nSy1);
}

//----- (004819A0) --------------------------------------------------------
void __cdecl DRLG_InitL2Vals()
{
  int v0; // [esp+Ch] [ebp-Ch]
  char v1; // [esp+Ch] [ebp-Ch]
  signed int v2; // [esp+10h] [ebp-8h]
  signed int j; // [esp+10h] [ebp-8h]
  signed int i; // [esp+14h] [ebp-4h]
  signed int k; // [esp+14h] [ebp-4h]

  DRLG_Init_Globals();
  v2 = 0;
LABEL_2:
  if ( v2 < 112 )
  {
    for ( i = 0; ; ++i )
    {
      if ( i >= 112 )
      {
        ++v2;
        goto LABEL_2;
      }
      v0 = dPiece[i][v2];
      if ( v0 == 541 )
        break;
      switch ( v0 )
      {
        case 178:
          v1 = 5;
          goto LABEL_21;
        case 551:
          v1 = 5;
          goto LABEL_21;
        case 542:
          v1 = 6;
          goto LABEL_21;
        case 553:
          v1 = 6;
          goto LABEL_21;
        case 13:
          v1 = 5;
          goto LABEL_21;
        case 17:
          v1 = 6;
          goto LABEL_21;
      }
LABEL_4:
      ;
    }
    v1 = 5;
LABEL_21:
    dArch[i][v2] = v1;
    goto LABEL_4;
  }
  for ( j = 0; j < 112; ++j )
  {
    for ( k = 0; k < 112; ++k )
    {
      if ( dPiece[k][j] == 132 )
      {
        dArch[k][j + 1] = 2;
        dArch[k][j + 2] = 1;
      }
      else if ( dPiece[k][j] == 135 || dPiece[k][j] == 139 )
      {
        dArch[k + 1][j] = 3;
        dArch[k + 2][j] = 4;
      }
    }
  }
}

//----- (00481BDE) --------------------------------------------------------
void __fastcall LoadL2Dungeon(char *sFileName, int vx, int vy)
{
  char *pszName; // ST18_4
  int v4; // [esp+Ch] [ebp-24h]
  int v5; // [esp+14h] [ebp-1Ch]
  int i; // [esp+18h] [ebp-18h]
  signed int k; // [esp+18h] [ebp-18h]
  signed int m; // [esp+18h] [ebp-18h]
  signed int ii; // [esp+18h] [ebp-18h]
  int j; // [esp+1Ch] [ebp-14h]
  signed int l; // [esp+1Ch] [ebp-14h]
  signed int n; // [esp+1Ch] [ebp-14h]
  signed int jj; // [esp+1Ch] [ebp-14h]
  int v14; // [esp+20h] [ebp-10h]
  int v15; // [esp+24h] [ebp-Ch]
  unsigned __int8 *pMap; // [esp+28h] [ebp-8h]
  BYTE *v17; // [esp+2Ch] [ebp-4h]

  v4 = vx;
  pszName = sFileName;
  InitDungeon();
  DRLG_InitTrans();
  pMap = LoadFileInMem(pszName, 0, 2960, "C:\\Diablo\\Direct\\DRLG_L2.CPP");
  v15 = *pMap;
  v14 = pMap[2];
  v17 = pMap + 4;
  for ( i = 0; v14 > i; ++i )
  {
    for ( j = 0; v15 > j; ++j )
    {
      if ( *v17 )
      {
        dungeon[j][i] = *v17;
        Xdflags_2[j][i] |= 0x80u;
      }
      else
      {
        dungeon[j][i] = 3;
      }
      v17 += 2;
    }
  }
  for ( k = 0; k < 40; ++k )
  {
    for ( l = 0; l < 40; ++l )
    {
      if ( !dungeon[l][k] )
        dungeon[l][k] = 12;
    }
  }
  DRLG_L2Pass3();
  DRLG_Init_Globals();
  for ( m = 0; m < 112; ++m )
  {
    for ( n = 0; n < 112; ++n )
    {
      v5 = dPiece[n][m];
      if ( v5 == 541 )
        v5 = 5;
      if ( v5 == 178 )
        v5 = 5;
      if ( v5 == 551 )
        v5 = 5;
      if ( v5 == 542 )
        v5 = 6;
      if ( v5 == 553 )
        v5 = 6;
      if ( v5 == 13 )
        v5 = 5;
      if ( v5 == 17 )
        dArch[n][m] = 6;
    }
  }
  for ( ii = 0; ii < 112; ++ii )
  {
    for ( jj = 0; jj < 112; ++jj )
    {
      if ( dPiece[jj][ii] == 132 )
      {
        dArch[jj][ii + 1] = 2;
        dArch[jj][ii + 2] = 1;
      }
      else if ( dPiece[jj][ii] == 135 || dPiece[jj][ii] == 139 )
      {
        dArch[jj + 1][ii] = 3;
        dArch[jj + 2][ii] = 4;
      }
    }
  }
  ViewX = v4;
  ViewY = vy;
  SetMapMonsters((char *)pMap, 0, 0);
  SetMapObjects((char *)pMap, 0, 0);
  mem_free_dbg(pMap, 3025, "C:\\Diablo\\Direct\\DRLG_L2.CPP");
}

//----- (00481F92) --------------------------------------------------------
void __fastcall LoadPreL2Dungeon(char *sFileName, int vx, int vy)
{
  char *pszName; // ST18_4
  int i; // [esp+14h] [ebp-18h]
  signed int k; // [esp+14h] [ebp-18h]
  signed int m; // [esp+14h] [ebp-18h]
  int j; // [esp+18h] [ebp-14h]
  signed int l; // [esp+18h] [ebp-14h]
  signed int n; // [esp+18h] [ebp-14h]
  int v10; // [esp+1Ch] [ebp-10h]
  int v11; // [esp+20h] [ebp-Ch]
  unsigned __int8 *ptr; // [esp+24h] [ebp-8h]
  BYTE *v13; // [esp+28h] [ebp-4h]

  pszName = sFileName;
  InitDungeon();
  DRLG_InitTrans();
  ptr = LoadFileInMem(pszName, 0, 3039, "C:\\Diablo\\Direct\\DRLG_L2.CPP");
  v11 = *ptr;
  v10 = ptr[2];
  v13 = ptr + 4;
  for ( i = 0; i < v10; ++i )
  {
    for ( j = 0; v11 > j; ++j )
    {
      if ( *v13 )
      {
        dungeon[j][i] = *v13;
        Xdflags_2[j][i] |= 0x80u;
      }
      else
      {
        dungeon[j][i] = 3;
      }
      v13 += 2;
    }
  }
  for ( k = 0; k < 40; ++k )
  {
    for ( l = 0; l < 40; ++l )
    {
      if ( !dungeon[l][k] )
        dungeon[l][k] = 12;
    }
  }
  for ( m = 0; m < 40; ++m )
  {
    for ( n = 0; n < 40; ++n )
      pdungeon[n][m] = dungeon[n][m];
  }
  mem_free_dbg(ptr, 3065, "C:\\Diablo\\Direct\\DRLG_L2.CPP");
}

//----- (0048221F) --------------------------------------------------------
void __fastcall CreateL2Dungeon(int rseed, int entry)
{
  SetRndSeed(rseed);
  dminx = 16;
  dminy = 16;
  dmaxx = 96;
  dmaxy = 96;
  DRLG_InitTrans();
  DRLG_LoadL2SP();
  DRLG_L2(entry);
  DRLG_L2Pass3();
  DRLG_FreeL2SP();
  DRLG_InitL2Vals();
  DRLG_SetPC();
}

