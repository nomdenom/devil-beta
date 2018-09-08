#include "all.h"

//----- (0049AE30) --------------------------------------------------------
void __cdecl DRLG_Init_Globals()
{
  char v0; // [esp+Ch] [ebp-4h]

  memset(dFlags, 0, 0x3100u);
  memset(dPlayer, 0, 0x3100u);
  memset(dMonster, 0, 0xC400u);
  memset(dDead, 0, 0x3100u);
  memset(dObject, 0, 0x3100u);
  memset(dItem, 0, 0x3100u);
  memset(dMissile, 0, 0x3100u);
  memset(dArch, 0, 0x3100u);
  if ( lightflag )
  {
    v0 = 0;
  }
  else if ( light4flag )
  {
    v0 = 3;
  }
  else
  {
    v0 = 15;
  }
  memset(dTransVal, v0, 0x3100u);
}

//----- (0049AF2A) --------------------------------------------------------
void __fastcall LoadL1Dungeon(char *sFileName, int vx, int vy)
{
  char *pszName; // ST18_4
  int v4; // [esp+Ch] [ebp-20h]
  signed int i; // [esp+14h] [ebp-18h]
  int k; // [esp+14h] [ebp-18h]
  signed int j; // [esp+18h] [ebp-14h]
  int l; // [esp+18h] [ebp-14h]
  int v9; // [esp+1Ch] [ebp-10h]
  int v10; // [esp+20h] [ebp-Ch]
  unsigned __int8 *pMap; // [esp+24h] [ebp-8h]
  BYTE *v12; // [esp+28h] [ebp-4h]

  v4 = vx;
  pszName = sFileName;
  dminx = 16;
  dminy = 16;
  dmaxx = 96;
  dmaxy = 96;
  DRLG_InitTrans();
  pMap = LoadFileInMem(pszName, 0, 721, "DRLG_L1.CPP");
  for ( i = 0; i < 40; ++i )
  {
    for ( j = 0; j < 40; ++j )
    {
      dungeon[j][i] = 22;
      dflags[j][i] = 0;
    }
  }
  v10 = *pMap;
  v9 = pMap[2];
  v12 = pMap + 4;
  for ( k = 0; v9 > k; ++k )
  {
    for ( l = 0; v10 > l; ++l )
    {
      if ( *v12 )
      {
        dungeon[l][k] = *v12;
        dflags[l][k] |= 0x80u;
      }
      else
      {
        dungeon[l][k] = 13;
      }
      v12 += 2;
    }
  }
  DRLG_L1Floor();
  ViewX = v4;
  ViewY = vy;
  DRLG_L1Pass3();
  DRLG_InitL1Vals();
  SetMapMonsters((char *)pMap, 0, 0);
  SetMapObjects((char *)pMap, 0, 0);
  mem_free_dbg(pMap, 763, "DRLG_L1.CPP");
}

//----- (0049B0F5) --------------------------------------------------------
void __cdecl DRLG_L1Floor()
{
  signed int i; // [esp+Ch] [ebp-Ch]
  signed int j; // [esp+10h] [ebp-8h]
  int v2; // [esp+14h] [ebp-4h]

  for ( i = 0; i < 40; ++i )
  {
    for ( j = 0; j < 40; ++j )
    {
      if ( !dflags[j][i] && dungeon[j][i] == 13 )
      {
        v2 = random(0, 3);
        if ( v2 == 1 )
          dungeon[j][i] = -94;
        if ( v2 == 2 )
          dungeon[j][i] = -93;
      }
    }
  }
}

//----- (0049B1BE) --------------------------------------------------------
void __cdecl DRLG_L1Pass3()
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

  v0 = pMegaTiles[84] + 1;
  v16 = pMegaTiles[84] + 1;
  LOWORD(v0) = pMegaTiles[85];
  v15 = ++v0;
  LOWORD(v0) = pMegaTiles[86];
  v1 = v0 + 1;
  v14 = v1;
  LOWORD(v1) = pMegaTiles[87];
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

//----- (0049B3A2) --------------------------------------------------------
void __cdecl DRLG_InitL1Vals()
{
  int v0; // [esp+Ch] [ebp-Ch]
  char v1; // [esp+Ch] [ebp-Ch]
  signed int i; // [esp+10h] [ebp-8h]
  signed int v3; // [esp+14h] [ebp-4h]

  DRLG_Init_Globals();
  v3 = 0;
LABEL_2:
  if ( v3 < 112 )
  {
    for ( i = 0; ; ++i )
    {
      if ( i >= 112 )
      {
        ++v3;
        goto LABEL_2;
      }
      v0 = dPiece[i][v3];
      if ( v0 == 12 )
        break;
      switch ( v0 )
      {
        case 11:
          v1 = 2;
          goto LABEL_35;
        case 71:
          v1 = 1;
          goto LABEL_35;
        case 259:
          v1 = 5;
          goto LABEL_35;
        case 249:
          v1 = 2;
          goto LABEL_35;
        case 325:
          v1 = 2;
          goto LABEL_35;
        case 321:
          v1 = 1;
          goto LABEL_35;
        case 255:
          v1 = 4;
          goto LABEL_35;
        case 211:
          v1 = 1;
          goto LABEL_35;
        case 344:
          v1 = 2;
          goto LABEL_35;
        case 341:
          v1 = 1;
          goto LABEL_35;
        case 331:
          v1 = 2;
          goto LABEL_35;
        case 418:
          v1 = 1;
          goto LABEL_35;
        case 421:
          v1 = 2;
          goto LABEL_35;
      }
LABEL_4:
      ;
    }
    v1 = 1;
LABEL_35:
    dArch[i][v3] = v1;
    goto LABEL_4;
  }
}

//----- (0049B584) --------------------------------------------------------
void __fastcall LoadPreL1Dungeon(char *sFileName, int vx, int vy)
{
  signed int i; // [esp+14h] [ebp-18h]
  int k; // [esp+14h] [ebp-18h]
  signed int m; // [esp+14h] [ebp-18h]
  signed int j; // [esp+18h] [ebp-14h]
  int l; // [esp+18h] [ebp-14h]
  signed int n; // [esp+18h] [ebp-14h]
  int v9; // [esp+1Ch] [ebp-10h]
  int v10; // [esp+20h] [ebp-Ch]
  unsigned __int8 *ptr; // [esp+24h] [ebp-8h]
  BYTE *v12; // [esp+28h] [ebp-4h]

  dminx = 16;
  dminy = 16;
  dmaxx = 96;
  dmaxy = 96;
  ptr = LoadFileInMem(sFileName, 0, 780, "DRLG_L1.CPP");
  for ( i = 0; i < 40; ++i )
  {
    for ( j = 0; j < 40; ++j )
    {
      dungeon[j][i] = 22;
      dflags[j][i] = 0;
    }
  }
  v10 = *ptr;
  v9 = ptr[2];
  v12 = ptr + 4;
  for ( k = 0; v9 > k; ++k )
  {
    for ( l = 0; v10 > l; ++l )
    {
      if ( *v12 )
      {
        dungeon[l][k] = *v12;
        dflags[l][k] |= 0x80u;
      }
      else
      {
        dungeon[l][k] = 13;
      }
      v12 += 2;
    }
  }
  DRLG_L1Floor();
  for ( m = 0; m < 40; ++m )
  {
    for ( n = 0; n < 40; ++n )
      pdungeon[n][m] = dungeon[n][m];
  }
  mem_free_dbg(ptr, 814, "DRLG_L1.CPP");
}

//----- (0049B774) --------------------------------------------------------
void __fastcall CreateL5Dungeon(int rseed, int entry)
{
  SetRndSeed(rseed);
  dminx = 16;
  dminy = 16;
  dmaxx = 96;
  dmaxy = 96;
  DRLG_InitTrans();
  DRLG_LoadL1SP();
  DRLG_L5(entry);
  DRLG_L1Pass3();
  DRLG_FreeL1SP();
  DRLG_InitL1Vals();
  DRLG_SetPC();
}

//----- (0049B7E3) --------------------------------------------------------
void __cdecl DRLG_LoadL1SP()
{
  setloadflag = 0;
  if ( quests[1]._qlevel == currlevel )
  {
    pSetPiece = LoadFileInMem("Levels\\L1Data\\rnd6.DUN", 0, 626, "DRLG_L1.CPP");
    setloadflag = 1;
  }
  else if ( quests[0]._qlevel != currlevel || gbMaxPlayers != 1 )
  {
    if ( quests[4]._qlevel == currlevel )
    {
      pSetPiece = LoadFileInMem("Levels\\L1Data\\Hero2.DUN", 0, 637, "DRLG_L1.CPP");
      setloadflag = 1;
    }
  }
  else
  {
    if ( quests[0]._qactive == 2 )
      pSetPiece = LoadFileInMem("Levels\\L1Data\\SKngDO.DUN", 0, 631, "DRLG_L1.CPP");
    else
      pSetPiece = LoadFileInMem("Levels\\L1Data\\SKngDC.DUN", 0, 633, "DRLG_L1.CPP");
    setloadflag = 1;
  }
}

//----- (0049B8FB) --------------------------------------------------------
void __cdecl DRLG_FreeL1SP()
{
  mem_free_dbg(pSetPiece, 645, "DRLG_L1.CPP");
  pSetPiece = 0;
}

//----- (0049B92A) --------------------------------------------------------
void __fastcall DRLG_L5(int entry)
{
  signed int y; // [esp+18h] [ebp-18h]
  int ya; // [esp+18h] [ebp-18h]
  signed int yb; // [esp+18h] [ebp-18h]
  signed int x; // [esp+1Ch] [ebp-14h]
  int xa; // [esp+1Ch] [ebp-14h]
  signed int xb; // [esp+1Ch] [ebp-14h]
  signed int v8; // [esp+28h] [ebp-8h]
  int v9; // [esp+2Ch] [ebp-4h]

  v8 = 0;
  switch ( currlevel )
  {
    case 1u:
      v9 = 533;
      break;
    case 2u:
      v9 = 693;
      break;
    case 3u:
    case 4u:
      v9 = 761;
      break;
    default:
      break;
  }
  while ( !v8 )
  {
    DRLG_InitTrans();
    do
    {
      InitL5Dungeon();
      L5firstRoom();
    }
    while ( v9 > L5GetArea() );
    L5makeDungeon();
    L5makeDmt();
    L5FillChambers();
    L5tileFix();
    L5AddWall();
    L5ClearFlags();
    DRLG_L5FloodTVal();
    v8 = 1;
    if ( quests[5]._qlevel == currlevel )
    {
      if ( entry )
      {
        if ( DRLG_PlaceMiniSet(PWATERIN, 1, 1, 0, 0, 0, -1, 0) < 0 )
          v8 = 0;
        --ViewY;
      }
      else if ( DRLG_PlaceMiniSet(PWATERIN, 1, 1, 0, 0, 1, -1, 0) < 0 )
      {
        v8 = 0;
      }
    }
    if ( quests[4]._qlevel == currlevel )
    {
      if ( entry )
      {
        if ( DRLG_PlaceMiniSet(STAIRSUP, 1, 1, 0, 0, 0, -1, 0) < 0 )
          v8 = 0;
        --ViewY;
      }
      else if ( DRLG_PlaceMiniSet(STAIRSUP, 1, 1, 0, 0, 1, -1, 0) < 0 )
      {
        v8 = 0;
      }
    }
    else if ( entry )
    {
      if ( DRLG_PlaceMiniSet(L5STAIRSUP, 1, 1, 0, 0, 0, -1, 0) >= 0 )
      {
        if ( DRLG_PlaceMiniSet(STAIRSDOWN, 1, 1, 0, 0, 1, -1, 1) < 0 )
          v8 = 0;
      }
      else
      {
        v8 = 0;
      }
      --ViewY;
    }
    else if ( DRLG_PlaceMiniSet(L5STAIRSUP, 1, 1, 0, 0, 1, -1, 0) >= 0 )
    {
      if ( DRLG_PlaceMiniSet(STAIRSDOWN, 1, 1, 0, 0, 0, -1, 1) < 0 )
        v8 = 0;
    }
    else
    {
      v8 = 0;
    }
  }
  if ( quests[5]._qactive == 2 && quests[5]._qlevel == currlevel )
    dungeon[quests[5]._qtx][quests[5]._qty] = 2;
  for ( y = 0; y < 40; ++y )
  {
    for ( x = 0; x < 40; ++x )
    {
      if ( dungeon[x][y] == 64 )
      {
        DRLG_CopyTrans(2 * x + 16, 2 * y + 17, 2 * x + 16, 2 * y + 16);
        DRLG_CopyTrans(2 * x + 17, 2 * y + 17, 2 * x + 17, 2 * y + 16);
      }
    }
  }
  DRLG_L5TransFix();
  DRLG_L5DirtFix();
  for ( ya = 0; ya < 40; ++ya )
  {
    for ( xa = 0; xa < 40; ++xa )
    {
      if ( dflags[xa][ya] & 0x7F )
        DRLG_PlaceDoor(xa, ya);
    }
  }
  DRLG_L5Subs();
  DRLG_L1Shadows();
  DRLG_PlaceMiniSet(LAMPS, 5, 10, 0, 0, 0, -1, 4);
  DRLG_L1Floor();
  for ( yb = 0; yb < 40; ++yb )
  {
    for ( xb = 0; xb < 40; ++xb )
      pdungeon[xb][yb] = dungeon[xb][yb];
  }
  DRLG_CheckQuests(setpc_x, setpc_y);
}

//----- (0049BDA5) --------------------------------------------------------
void __fastcall DRLG_PlaceDoor(int x, int y)
{
  char v2; // [esp+14h] [ebp-8h]
  BYTE v3; // [esp+18h] [ebp-4h]

  if ( dflags[x][y] >= 0 )
  {
    v2 = dflags[x][y] & 0x7F;
    v3 = dungeon[x][y];
    if ( v2 == 1 )
    {
      if ( y != 1 && v3 == 2 )
        dungeon[x][y] = 26;
      if ( y != 1 && v3 == 7 )
        dungeon[x][y] = 31;
      if ( y != 1 && v3 == 14 )
        dungeon[x][y] = 42;
      if ( y != 1 && v3 == 4 )
        dungeon[x][y] = 43;
      if ( x != 1 && v3 == 1 )
        dungeon[x][y] = 25;
      if ( x != 1 && v3 == 10 )
        dungeon[x][y] = 40;
      if ( x != 1 && v3 == 6 )
        dungeon[x][y] = 30;
    }
    if ( v2 == 2 )
    {
      if ( x != 1 && v3 == 1 )
        dungeon[x][y] = 25;
      if ( x != 1 && v3 == 6 )
        dungeon[x][y] = 30;
      if ( x != 1 && v3 == 10 )
        dungeon[x][y] = 40;
      if ( x != 1 && v3 == 4 )
        dungeon[x][y] = 41;
      if ( y != 1 && v3 == 2 )
        dungeon[x][y] = 26;
      if ( y != 1 && v3 == 14 )
        dungeon[x][y] = 42;
      if ( y != 1 && v3 == 7 )
        dungeon[x][y] = 31;
    }
    if ( v2 == 3 )
    {
      if ( x != 1 && y != 1 && v3 == 4 )
        dungeon[x][y] = 28;
      if ( x != 1 && v3 == 10 )
        dungeon[x][y] = 40;
      if ( y != 1 && v3 == 14 )
        dungeon[x][y] = 42;
      if ( y != 1 && v3 == 2 )
        dungeon[x][y] = 26;
      if ( x != 1 && v3 == 1 )
        dungeon[x][y] = 25;
      if ( y != 1 && v3 == 7 )
        dungeon[x][y] = 31;
      if ( x != 1 && v3 == 6 )
        dungeon[x][y] = 30;
    }
  }
  dflags[x][y] = -128;
}

//----- (0049C1A6) --------------------------------------------------------
void __cdecl DRLG_L1Shadows()
{
  signed int i; // [esp+Ch] [ebp-18h]
  signed int l; // [esp+Ch] [ebp-18h]
  signed int k; // [esp+10h] [ebp-14h]
  signed int j; // [esp+14h] [ebp-10h]
  signed int m; // [esp+14h] [ebp-10h]
  signed int v5; // [esp+18h] [ebp-Ch]
  char v6; // [esp+1Ch] [ebp-8h]
  char v7; // [esp+1Dh] [ebp-7h]
  char v8; // [esp+1Eh] [ebp-6h]
  char v9; // [esp+1Fh] [ebp-5h]
  BYTE v10; // [esp+20h] [ebp-4h]
  BYTE v11; // [esp+20h] [ebp-4h]
  BYTE v12; // [esp+20h] [ebp-4h]

  for ( i = 1; i < 40; ++i )
  {
    for ( j = 1; j < 40; ++j )
    {
      v6 = BSTYPES[dungeon[j][i]];
      v8 = BSTYPES[dungeon[j - 1][i]];
      v7 = BSTYPES[dungeon[j][i - 1]];
      v9 = BSTYPES[dungeon[j][i - 2]];
      for ( k = 0; k < 37; ++k )
      {
        if ( SPATS[k][0] == v6 )
        {
          v5 = 1;
          if ( SPATS[k][1] && SPATS[k][1] != v9 )
            v5 = 0;
          if ( SPATS[k][2] && SPATS[k][2] != v7 )
            v5 = 0;
          if ( SPATS[k][3] && SPATS[k][3] != v8 )
            v5 = 0;
          if ( v5 == 1 )
          {
            if ( SPATS[k][4] && !dflags[j][i - 2] )
              dungeon[j][i - 2] = SPATS[k][4];
            if ( SPATS[k][5] && !dflags[j][i - 1] )
              dungeon[j][i - 1] = SPATS[k][5];
            if ( SPATS[k][6] )
            {
              if ( !dflags[j - 1][i] )
                dungeon[j - 1][i] = SPATS[k][6];
            }
          }
        }
      }
    }
  }
  for ( l = 1; l < 40; ++l )
  {
    for ( m = 1; m < 40; ++m )
    {
      if ( dungeon[m - 1][l] == 139 && !dflags[m - 1][l] )
      {
        v10 = -117;
        if ( dungeon[m][l] == 29 )
          v10 = -115;
        if ( dungeon[m][l] == 32 )
          v10 = -115;
        if ( dungeon[m][l] == 35 )
          v10 = -115;
        if ( dungeon[m][l] == 37 )
          v10 = -115;
        if ( dungeon[m][l] == 38 )
          v10 = -115;
        if ( dungeon[m][l] == 39 )
          v10 = -115;
        dungeon[m - 1][l] = v10;
      }
      if ( dungeon[m - 1][l] == 149 && !dflags[m - 1][l] )
      {
        v11 = -107;
        if ( dungeon[m][l] == 29 )
          v11 = -103;
        if ( dungeon[m][l] == 32 )
          v11 = -103;
        if ( dungeon[m][l] == 35 )
          v11 = -103;
        if ( dungeon[m][l] == 37 )
          v11 = -103;
        if ( dungeon[m][l] == 38 )
          v11 = -103;
        if ( dungeon[m][l] == 39 )
          v11 = -103;
        dungeon[m - 1][l] = v11;
      }
      if ( dungeon[m - 1][l] == 148 && !dflags[m - 1][l] )
      {
        v12 = -108;
        if ( dungeon[m][l] == 29 )
          v12 = -102;
        if ( dungeon[m][l] == 32 )
          v12 = -102;
        if ( dungeon[m][l] == 35 )
          v12 = -102;
        if ( dungeon[m][l] == 37 )
          v12 = -102;
        if ( dungeon[m][l] == 38 )
          v12 = -102;
        if ( dungeon[m][l] == 39 )
          v12 = -102;
        dungeon[m - 1][l] = v12;
      }
    }
  }
}

//----- (0049C7EC) --------------------------------------------------------
int __fastcall DRLG_PlaceMiniSet(unsigned __int8 *miniset, int tmin, int tmax, int cx, int cy, bool setview, int noquad, int ldir)
{
  int k; // [esp+18h] [ebp-2Ch]
  int m; // [esp+18h] [ebp-2Ch]
  signed int v12; // [esp+1Ch] [ebp-28h]
  int v13; // [esp+20h] [ebp-24h]
  int v14; // [esp+24h] [ebp-20h]
  int v15; // [esp+28h] [ebp-1Ch]
  int v16; // [esp+2Ch] [ebp-18h]
  int i; // [esp+30h] [ebp-14h]
  int v18; // [esp+34h] [ebp-10h]
  int v19; // [esp+38h] [ebp-Ch]
  int j; // [esp+3Ch] [ebp-8h]
  int l; // [esp+3Ch] [ebp-8h]
  signed int v22; // [esp+40h] [ebp-4h]
  int v23; // [esp+40h] [ebp-4h]

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
    v12 = 0;
    v19 = 0;
    while ( !v12 )
    {
      v12 = 1;
      if ( cx != -1 && cx - v16 <= v14 && cx + 12 >= v14 )
      {
        ++v14;
        v12 = 0;
      }
      if ( cy != -1 && cy - v15 <= v13 && cy + 12 >= v13 )
      {
        ++v13;
        v12 = 0;
      }
      switch ( noquad )
      {
        case 0:
          if ( v14 < cx && cy > v13 )
            v12 = 0;
          break;
        case 1:
          if ( v14 > cx && cy > v13 )
            v12 = 0;
          break;
        case 2:
          if ( v14 < cx && cy < v13 )
            v12 = 0;
          break;
        case 3:
          if ( v14 > cx && cy < v13 )
            v12 = 0;
          break;
        default:
          break;
      }
      v22 = 2;
      for ( j = 0; j < v15 && v12 == 1; ++j )
      {
        for ( k = 0; k < v16 && v12 == 1; ++k )
        {
          if ( miniset[v22] && dungeon[k + v14][v13 + j] != miniset[v22] )
            v12 = 0;
          if ( dflags[k + v14][v13 + j] )
            v12 = 0;
          ++v22;
        }
      }
      if ( !v12 )
      {
        if ( 40 - v16 == ++v14 )
        {
          v14 = 0;
          if ( 40 - v15 == ++v13 )
            v13 = 0;
        }
        if ( ++v19 > 4000 )
          return -1;
      }
    }
    v23 = v16 * v15 + 2;
    for ( l = 0; l < v15; ++l )
    {
      for ( m = 0; m < v16; ++m )
      {
        if ( miniset[v23] )
          dungeon[m + v14][v13 + l] = miniset[v23];
        ++v23;
      }
    }
  }
  if ( miniset == PWATERIN )
  {
    if ( quests[5]._qactive == 2 )
    {
      quests[5]._qtx = 2 * v14 + 19;
      quests[5]._qty = 2 * v13 + 19;
    }
    else
    {
      quests[5]._qtx = v14 + 1;
      quests[5]._qty = v13 + 1;
    }
  }
  if ( setview == 1 )
  {
    ViewX = 2 * v14 + 19;
    ViewY = 2 * v13 + 20;
  }
  if ( !ldir )
  {
    LvlViewX = 2 * v14 + 19;
    LvlViewY = 2 * v13 + 20;
  }
  if ( v14 < cx && cy > v13 )
    return 0;
  if ( v14 > cx && cy > v13 )
    return 1;
  if ( v14 >= cx || cy >= v13 )
    return 3;
  return 2;
}

//----- (0049CC83) --------------------------------------------------------
void __cdecl InitL5Dungeon()
{
  signed int i; // [esp+Ch] [ebp-8h]
  signed int j; // [esp+10h] [ebp-4h]

  for ( i = 0; i < 40; ++i )
  {
    for ( j = 0; j < 40; ++j )
    {
      dungeon[j][i] = 0;
      dflags[j][i] = 0;
    }
  }
}

//----- (0049CCF4) --------------------------------------------------------
void __cdecl L5ClearFlags()
{
  signed int i; // [esp+Ch] [ebp-8h]
  signed int j; // [esp+10h] [ebp-4h]

  for ( i = 0; i < 40; ++i )
  {
    for ( j = 0; j < 40; ++j )
      dflags[j][i] &= 0xBFu;
  }
}

//----- (0049CD68) --------------------------------------------------------
void __cdecl L5firstRoom()
{
  signed int v0; // [esp+Ch] [ebp-18h]
  signed int v1; // [esp+10h] [ebp-14h]
  signed int v2; // [esp+14h] [ebp-10h]
  signed int j; // [esp+18h] [ebp-Ch]
  signed int i; // [esp+1Ch] [ebp-8h]
  signed int v5; // [esp+20h] [ebp-4h]

  if ( random(0, 2) )
  {
    v2 = 1;
    v1 = 39;
    HR1 = random(0, 2);
    HR2 = random(0, 2);
    HR3 = random(0, 2);
    if ( HR1 + HR3 <= 1 )
      HR2 = 1;
    if ( HR1 )
      L5drawRoom(1, 15, 10, 10);
    else
      v2 = 18;
    if ( HR2 )
      L5drawRoom(15, 15, 10, 10);
    if ( HR3 )
      L5drawRoom(29, 15, 10, 10);
    else
      v1 = 22;
    for ( i = v2; i < v1; ++i )
    {
      dungeon[i][17] = 1;
      dungeon[i][18] = 1;
      dungeon[i][19] = 1;
      dungeon[i][20] = 1;
      dungeon[i][21] = 1;
      dungeon[i][22] = 1;
    }
    if ( HR1 )
      L5roomGen(1, 15, 10, 10, 1);
    if ( HR2 )
      L5roomGen(15, 15, 10, 10, 1);
    if ( HR3 )
      L5roomGen(29, 15, 10, 10, 1);
    VR3 = 0;
    VR2 = 0;
    VR1 = 0;
  }
  else
  {
    v0 = 1;
    v5 = 39;
    VR1 = random(0, 2);
    VR2 = random(0, 2);
    VR3 = random(0, 2);
    if ( VR1 + VR3 <= 1 )
      VR2 = 1;
    if ( VR1 )
      L5drawRoom(15, 1, 10, 10);
    else
      v0 = 18;
    if ( VR2 )
      L5drawRoom(15, 15, 10, 10);
    if ( VR3 )
      L5drawRoom(15, 29, 10, 10);
    else
      v5 = 22;
    for ( j = v0; j < v5; ++j )
    {
      dungeon[17][j] = 1;
      dungeon[18][j] = 1;
      dungeon[19][j] = 1;
      dungeon[20][j] = 1;
      dungeon[21][j] = 1;
      dungeon[22][j] = 1;
    }
    if ( VR1 )
      L5roomGen(15, 1, 10, 10, 0);
    if ( VR2 )
      L5roomGen(15, 15, 10, 10, 0);
    if ( VR3 )
      L5roomGen(15, 29, 10, 10, 0);
    HR3 = 0;
    HR2 = 0;
    HR1 = 0;
  }
}

//----- (0049D10C) --------------------------------------------------------
void __fastcall L5drawRoom(int x, int y, int w, int h)
{
  int i; // [esp+14h] [ebp-8h]
  int j; // [esp+18h] [ebp-4h]

  for ( i = 0; i < h; ++i )
  {
    for ( j = 0; j < w; ++j )
      dungeon[x + j][y + i] = 1;
  }
}

//----- (0049D17E) --------------------------------------------------------
void __fastcall L5roomGen(int x, int y, int w, int h, bool dir)
{
  signed int v7; // [esp+18h] [ebp-3Ch]
  int v8; // [esp+18h] [ebp-3Ch]
  signed int v9; // [esp+20h] [ebp-34h]
  signed int v10; // [esp+20h] [ebp-34h]
  int v11; // [esp+30h] [ebp-24h]
  int v12; // [esp+30h] [ebp-24h]
  int v13; // [esp+34h] [ebp-20h]
  int v14; // [esp+34h] [ebp-20h]
  int v15; // [esp+38h] [ebp-1Ch]
  BOOL v16; // [esp+3Ch] [ebp-18h]
  BOOL v17; // [esp+40h] [ebp-14h]
  BOOL v18; // [esp+40h] [ebp-14h]
  BOOL v19; // [esp+44h] [ebp-10h]
  BOOL v20; // [esp+44h] [ebp-10h]
  int v21; // [esp+48h] [ebp-Ch]
  int v22; // [esp+4Ch] [ebp-8h]
  signed int v23; // [esp+4Ch] [ebp-8h]
  int v24; // [esp+50h] [ebp-4h]

  v24 = random(0, 4);
  if ( dir == 1 )
    v16 = v24 != 0;
  else
    v16 = v24 == 0;
  if ( v16 )
  {
    if ( v16 == 1 )
    {
      v10 = 0;
      do
      {
        v23 = (random(0, 5) + 2) & 0xFFFFFFFE;
        v8 = (random(0, 5) + 2) & 0xFFFFFFFE;
        v14 = w / 2 + x - v23 / 2;
        v12 = y - v8;
        v20 = L5checkRoom(v14 - 1, y - v8 - 1, v23 + 2, v8 + 1);
        ++v10;
      }
      while ( !v20 && v10 < 20 );
      if ( v20 == 1 )
        L5drawRoom(v14, v12, v23, v8);
      v15 = h + y;
      v18 = L5checkRoom(v14 - 1, h + y, v23 + 2, v8 + 1);
      if ( v18 == 1 )
        L5drawRoom(v14, v15, v23, v8);
      if ( v20 == 1 )
        L5roomGen(v14, v12, v23, v8, 0);
      if ( v18 == 1 )
        L5roomGen(v14, v15, v23, v8, 0);
    }
  }
  else
  {
    v9 = 0;
    do
    {
      v22 = (random(0, 5) + 2) & 0xFFFFFFFE;
      v7 = (random(0, 5) + 2) & 0xFFFFFFFE;
      v11 = h / 2 + y - v7 / 2;
      v13 = x - v22;
      v19 = L5checkRoom(x - v22 - 1, v11 - 1, v7 + 2, v22 + 1);
      ++v9;
    }
    while ( !v19 && v9 < 20 );
    if ( v19 == 1 )
      L5drawRoom(v13, v11, v22, v7);
    v21 = x + w;
    v17 = L5checkRoom(x + w, v11 - 1, v22 + 1, v7 + 2);
    if ( v17 == 1 )
      L5drawRoom(v21, v11, v22, v7);
    if ( v19 == 1 )
      L5roomGen(v13, v11, v22, v7, 1);
    if ( v17 == 1 )
      L5roomGen(v21, v11, v22, v7, 1);
  }
}

//----- (0049D4D6) --------------------------------------------------------
BOOL __fastcall L5checkRoom(int x, int y, int width, int height)
{
  int i; // [esp+14h] [ebp-8h]
  int j; // [esp+18h] [ebp-4h]

  for ( i = 0; i < height; ++i )
  {
    for ( j = 0; width > j; ++j )
    {
      if ( j + x < 0 || j + x >= 40 || i + y < 0 || i + y >= 40 )
        return 0;
      if ( dungeon[j + x][i + y] )
        return 0;
    }
  }
  return 1;
}

//----- (0049D59A) --------------------------------------------------------
int __cdecl L5GetArea()
{
  signed int i; // [esp+Ch] [ebp-Ch]
  signed int j; // [esp+10h] [ebp-8h]
  int v3; // [esp+14h] [ebp-4h]

  v3 = 0;
  for ( i = 0; i < 40; ++i )
  {
    for ( j = 0; j < 40; ++j )
    {
      if ( dungeon[j][i] == 1 )
        ++v3;
    }
  }
  return v3;
}

//----- (0049D611) --------------------------------------------------------
void __cdecl L5makeDungeon()
{
  int v0; // ST10_4
  int v1; // ST0C_4
  signed int i; // [esp+14h] [ebp-8h]
  signed int j; // [esp+18h] [ebp-4h]

  for ( i = 0; i < 40; ++i )
  {
    for ( j = 0; j < 40; ++j )
    {
      v0 = 2 * j;
      v1 = 2 * i;
      L5Dungeon[2 * j][2 * i] = dungeon[j][i];
      L5Dungeon[v0][v1 + 1] = dungeon[j][i];
      L5Dungeon[v0 + 1][v1] = dungeon[j][i];
      L5Dungeon[0][16 * (10 * j + 5) + 1 + v1] = dungeon[j][i];
    }
  }
}

//----- (0049D6FE) --------------------------------------------------------
void __cdecl L5makeDmt()
{
  signed int i; // [esp+Ch] [ebp-18h]
  signed int k; // [esp+Ch] [ebp-18h]
  signed int j; // [esp+10h] [ebp-14h]
  signed int l; // [esp+10h] [ebp-14h]
  int v4; // [esp+14h] [ebp-10h]
  int v5; // [esp+18h] [ebp-Ch]

  for ( i = 0; i < 40; ++i )
  {
    for ( j = 0; j < 40; ++j )
      dungeon[j][i] = 22;
  }
  v4 = 0;
  for ( k = 1; k <= 77; k += 2 )
  {
    v5 = 0;
    for ( l = 1; l <= 77; l += 2 )
      dungeon[v5++][v4] = L5ConvTbl[8 * L5Dungeon[l + 1][k + 1]
                                  + 4 * L5Dungeon[l][k + 1]
                                  + 2 * L5Dungeon[l + 1][k]
                                  + L5Dungeon[l][k]];
    ++v4;
  }
}

//----- (0049D839) --------------------------------------------------------
void __cdecl L5AddWall()
{
  int j; // [esp+Ch] [ebp-10h]
  int i; // [esp+10h] [ebp-Ch]
  int dy; // [esp+14h] [ebp-8h]
  int dya; // [esp+14h] [ebp-8h]
  int dyb; // [esp+14h] [ebp-8h]
  int v5; // [esp+18h] [ebp-4h]
  int v6; // [esp+18h] [ebp-4h]
  int v7; // [esp+18h] [ebp-4h]

  for ( j = 0; j < 40; ++j )
  {
    for ( i = 0; i < 40; ++i )
    {
      if ( !dflags[i][j] )
      {
        if ( dungeon[i][j] == 3 && random(0, 100) < 100 )
        {
          v5 = L5HWallOk(i, j);
          if ( v5 != -1 )
            L5HorizWall(i, j, 2, v5);
        }
        if ( dungeon[i][j] == 3 && random(0, 100) < 100 )
        {
          dy = L5VWallOk(i, j);
          if ( dy != -1 )
            L5VertWall(i, j, 1, dy);
        }
        if ( dungeon[i][j] == 6 && random(0, 100) < 100 )
        {
          v6 = L5HWallOk(i, j);
          if ( v6 != -1 )
            L5HorizWall(i, j, 4, v6);
        }
        if ( dungeon[i][j] == 7 && random(0, 100) < 100 )
        {
          dya = L5VWallOk(i, j);
          if ( dya != -1 )
            L5VertWall(i, j, 4, dya);
        }
        if ( dungeon[i][j] == 2 && random(0, 100) < 100 )
        {
          v7 = L5HWallOk(i, j);
          if ( v7 != -1 )
            L5HorizWall(i, j, 2, v7);
        }
        if ( dungeon[i][j] == 1 && random(0, 100) < 100 )
        {
          dyb = L5VWallOk(i, j);
          if ( dyb != -1 )
            L5VertWall(i, j, 1, dyb);
        }
      }
    }
  }
}

//----- (0049DAB8) --------------------------------------------------------
int __fastcall L5HWallOk(int i, int j)
{
  int result; // eax
  signed int k; // [esp+14h] [ebp-8h]
  signed int v4; // [esp+18h] [ebp-4h]

  for ( k = 1;
        dungeon[i + k][j] == 13 && dungeon[i + k - 1][j + 39] == 13 && dungeon[i + k][j + 1] == 13 && !dflags[i + k][j];
        ++k )
  {
    ;
  }
  v4 = 0;
  if ( (signed int)dungeon[i + k][j] >= 3 && (signed int)dungeon[i + k][j] <= 7 )
    v4 = 1;
  if ( (signed int)dungeon[i + k][j] >= 16 && (signed int)dungeon[i + k][j] <= 24 )
    v4 = 1;
  if ( dungeon[i + k][j] == 22 )
    v4 = 0;
  if ( k == 1 )
    v4 = 0;
  if ( v4 )
    result = k;
  else
    result = -1;
  return result;
}

//----- (0049DC36) --------------------------------------------------------
int __fastcall L5VWallOk(int i, int j)
{
  int result; // eax
  signed int k; // [esp+14h] [ebp-8h]
  signed int v4; // [esp+18h] [ebp-4h]

  for ( k = 1;
        dungeon[i][j + k] == 13
     && dungeon[0][8 * (5 * i - 5) + j + k] == 13
     && dungeon[0][8 * (5 * i + 5) + j + k] == 13
     && !dflags[i][j + k];
        ++k )
  {
    ;
  }
  v4 = 0;
  if ( (signed int)dungeon[i][j + k] >= 3 && (signed int)dungeon[i][j + k] <= 7 )
    v4 = 1;
  if ( (signed int)dungeon[i][j + k] >= 16 && (signed int)dungeon[i][j + k] <= 24 )
    v4 = 1;
  if ( dungeon[i][j + k] == 22 )
    v4 = 0;
  if ( k == 1 )
    v4 = 0;
  if ( v4 )
    result = k;
  else
    result = -1;
  return result;
}

//----- (0049DDB6) --------------------------------------------------------
void __fastcall L5HorizWall(int i, int j, char p, int dx)
{
  int k; // [esp+18h] [ebp-Ch]
  int v7; // [esp+18h] [ebp-Ch]
  BYTE v8; // [esp+1Ch] [ebp-8h]
  BYTE v9; // [esp+20h] [ebp-4h]

  switch ( random(0, 4) )
  {
    case 0:
    case 1:
      v9 = 2;
      break;
    case 2:
      v9 = 12;
      if ( p == 2 )
        p = 12;
      if ( p == 4 )
        p = 10;
      break;
    case 3:
      v9 = 36;
      if ( p == 2 )
        p = 36;
      if ( p == 4 )
        p = 27;
      break;
    default:
      break;
  }
  if ( random(0, 6) == 5 )
    v8 = 12;
  else
    v8 = 26;
  if ( v9 == 12 )
    v8 = 12;
  dungeon[i][j] = p;
  for ( k = 1; k < dx; ++k )
    dungeon[i + k][j] = v9;
  v7 = random(0, dx - 1) + 1;
  if ( v8 == 12 )
  {
    dungeon[i + v7][j] = v8;
  }
  else
  {
    dungeon[i + v7][j] = 2;
    dflags[i + v7][j] |= 1u;
  }
}

//----- (0049DF5F) --------------------------------------------------------
void __fastcall L5VertWall(int i, int j, char p, int dy)
{
  BYTE v6; // [esp+18h] [ebp-Ch]
  BYTE v7; // [esp+1Ch] [ebp-8h]
  int k; // [esp+20h] [ebp-4h]
  int v9; // [esp+20h] [ebp-4h]

  switch ( random(0, 4) )
  {
    case 0:
    case 1:
      v7 = 1;
      break;
    case 2:
      v7 = 11;
      if ( p == 1 )
        p = 11;
      if ( p == 4 )
        p = 14;
      break;
    case 3:
      v7 = 35;
      if ( p == 1 )
        p = 35;
      if ( p == 4 )
        p = 37;
      break;
    default:
      break;
  }
  if ( random(0, 6) == 5 )
    v6 = 11;
  else
    v6 = 25;
  if ( v7 == 11 )
    v6 = 11;
  dungeon[i][j] = p;
  for ( k = 1; dy > k; ++k )
    dungeon[i][k + j] = v7;
  v9 = random(0, dy - 1) + 1;
  if ( v6 == 11 )
  {
    dungeon[i][v9 + j] = v6;
  }
  else
  {
    dungeon[i][v9 + j] = 1;
    dflags[i][v9 + j] |= 2u;
  }
}

//----- (0049E108) --------------------------------------------------------
void __cdecl L5tileFix()
{
  signed int i; // [esp+Ch] [ebp-8h]
  signed int k; // [esp+Ch] [ebp-8h]
  signed int m; // [esp+Ch] [ebp-8h]
  signed int j; // [esp+10h] [ebp-4h]
  signed int l; // [esp+10h] [ebp-4h]
  signed int n; // [esp+10h] [ebp-4h]

  for ( i = 0; i < 40; ++i )
  {
    for ( j = 0; j < 40; ++j )
    {
      if ( dungeon[j][i] == 2 && dungeon[j + 1][i] == 22 )
        dungeon[j + 1][i] = 23;
      if ( dungeon[j][i] == 13 && dungeon[j + 1][i] == 22 )
        dungeon[j + 1][i] = 18;
      if ( dungeon[j][i] == 13 && dungeon[j + 1][i] == 2 )
        dungeon[j + 1][i] = 7;
      if ( dungeon[j][i] == 6 && dungeon[j + 1][i] == 22 )
        dungeon[j + 1][i] = 24;
      if ( dungeon[j][i] == 1 && dungeon[j][i + 1] == 22 )
        dungeon[j][i + 1] = 24;
      if ( dungeon[j][i] == 13 && dungeon[j][i + 1] == 1 )
        dungeon[j][i + 1] = 6;
      if ( dungeon[j][i] == 13 && dungeon[j][i + 1] == 22 )
        dungeon[j][i + 1] = 19;
    }
  }
  for ( k = 0; k < 40; ++k )
  {
    for ( l = 0; l < 40; ++l )
    {
      if ( dungeon[l][k] == 13 && dungeon[l + 1][k] == 19 )
        dungeon[l + 1][k] = 21;
      if ( dungeon[l][k] == 13 && dungeon[l + 1][k] == 22 )
        dungeon[l + 1][k] = 20;
      if ( dungeon[l][k] == 7 && dungeon[l + 1][k] == 22 )
        dungeon[l + 1][k] = 23;
      if ( dungeon[l][k] == 13 && dungeon[l + 1][k] == 24 )
        dungeon[l + 1][k] = 21;
      if ( dungeon[l][k] == 19 && dungeon[l + 1][k] == 22 )
        dungeon[l + 1][k] = 20;
      if ( dungeon[l][k] == 2 && dungeon[l + 1][k] == 19 )
        dungeon[l + 1][k] = 21;
      if ( dungeon[l][k] == 19 && dungeon[l + 1][k] == 1 )
        dungeon[l + 1][k] = 6;
      if ( dungeon[l][k] == 7 && dungeon[l + 1][k] == 19 )
        dungeon[l + 1][k] = 21;
      if ( dungeon[l][k] == 2 && dungeon[l + 1][k] == 1 )
        dungeon[l + 1][k] = 6;
      if ( dungeon[l][k] == 3 && dungeon[l + 1][k] == 22 )
        dungeon[l + 1][k] = 24;
      if ( dungeon[l][k] == 21 && dungeon[l + 1][k] == 1 )
        dungeon[l + 1][k] = 6;
      if ( dungeon[l][k] == 7 && dungeon[l + 1][k] == 1 )
        dungeon[l + 1][k] = 6;
      if ( dungeon[l][k] == 7 && dungeon[l + 1][k] == 24 )
        dungeon[l + 1][k] = 21;
      if ( dungeon[l][k] == 4 && dungeon[l + 1][k] == 16 )
        dungeon[l + 1][k] = 17;
      if ( dungeon[l][k] == 7 && dungeon[l + 1][k] == 13 )
        dungeon[l + 1][k] = 17;
      if ( dungeon[l][k] == 2 && dungeon[l + 1][k] == 24 )
        dungeon[l + 1][k] = 21;
      if ( dungeon[l][k] == 2 && dungeon[l + 1][k] == 13 )
        dungeon[l + 1][k] = 17;
      if ( dungeon[l][k] == 23 && dungeon[l - 1][k] == 22 )
        dungeon[l - 1][k] = 19;
      if ( dungeon[l][k] == 19 && dungeon[l - 1][k] == 23 )
        dungeon[l - 1][k] = 21;
      if ( dungeon[l][k] == 6 && dungeon[l - 1][k] == 22 )
        dungeon[l - 1][k] = 24;
      if ( dungeon[l][k] == 6 && dungeon[l - 1][k] == 23 )
        dungeon[l - 1][k] = 21;
      if ( dungeon[l][k] == 1 && dungeon[l][k + 1] == 2 )
        dungeon[l][k + 1] = 7;
      if ( dungeon[l][k] == 6 && dungeon[l][k + 1] == 18 )
        dungeon[l][k + 1] = 21;
      if ( dungeon[l][k] == 18 && dungeon[l][k + 1] == 2 )
        dungeon[l][k + 1] = 7;
      if ( dungeon[l][k] == 6 && dungeon[l][k + 1] == 2 )
        dungeon[l][k + 1] = 7;
      if ( dungeon[l][k] == 21 && dungeon[l][k + 1] == 2 )
        dungeon[l][k + 1] = 7;
      if ( dungeon[l][k] == 6 && dungeon[l][k + 1] == 22 )
        dungeon[l][k + 1] = 24;
      if ( dungeon[l][k] == 6 && dungeon[l][k + 1] == 13 )
        dungeon[l][k + 1] = 16;
      if ( dungeon[l][k] == 1 && dungeon[l][k + 1] == 13 )
        dungeon[l][k + 1] = 16;
      if ( dungeon[l][k] == 13 && dungeon[l][k + 1] == 16 )
        dungeon[l][k + 1] = 17;
      if ( dungeon[l][k] == 6 && dungeon[l][k - 1] == 22 )
        dungeon[l][k - 1] = 7;
      if ( dungeon[l][k] == 6 && dungeon[l][k - 1] == 22 )
        dungeon[l][k - 1] = 24;
      if ( dungeon[l][k] == 7 && dungeon[l][k - 1] == 24 )
        dungeon[l][k - 1] = 21;
      if ( dungeon[l][k] == 18 && dungeon[l][k - 1] == 24 )
        dungeon[l][k - 1] = 21;
    }
  }
  for ( m = 0; m < 40; ++m )
  {
    for ( n = 0; n < 40; ++n )
    {
      if ( dungeon[n][m] == 4 && dungeon[n][m + 1] == 2 )
        dungeon[n][m + 1] = 7;
      if ( dungeon[n][m] == 2 && dungeon[n + 1][m] == 19 )
        dungeon[n + 1][m] = 21;
      if ( dungeon[n][m] == 18 && dungeon[n][m + 1] == 22 )
        dungeon[n][m + 1] = 20;
    }
  }
}

//----- (0049EE37) --------------------------------------------------------
void __cdecl DRLG_L5Subs()
{
  signed int i; // [esp+Ch] [ebp-14h]
  signed int v1; // [esp+10h] [ebp-10h]
  signed int j; // [esp+14h] [ebp-Ch]
  int v3; // [esp+18h] [ebp-8h]
  char v4; // [esp+1Ch] [ebp-4h]

  for ( i = 0; i < 40; ++i )
  {
    for ( j = 0; j < 40; ++j )
    {
      if ( !random(0, 4) )
      {
        v4 = L5BTYPES[dungeon[j][i]];
        if ( v4 )
        {
          if ( !dflags[j][i] )
          {
            v3 = random(0, 16);
            v1 = -1;
            while ( v3 >= 0 )
            {
              if ( ++v1 == 206 )
                v1 = 0;
              if ( L5BTYPES[v1] == v4 )
                --v3;
            }
            if ( v1 == 89 )
            {
              if ( L5BTYPES[dungeon[j][i - 1]] != 79 || dflags[j][i - 1] )
                v1 = 79;
              else
                dungeon[j][i - 1] = 90;
            }
            if ( v1 == 91 )
            {
              if ( L5BTYPES[dungeon[j + 1][i]] != 80 || dflags[j + 1][i] )
                LOBYTE(v1) = 80;
              else
                dungeon[j + 1][i] = 92;
            }
            dungeon[j][i] = v1;
          }
        }
      }
    }
  }
}

//----- (0049F028) --------------------------------------------------------
void __cdecl L5FillChambers()
{
  int v0; // [esp+14h] [ebp-4h]
  int v1; // [esp+14h] [ebp-4h]

  if ( HR1 )
    DRLG_L5GChamber(0, 14, 0, 0, 0, 1);
  if ( HR2 )
  {
    if ( HR1 && !HR3 )
      DRLG_L5GChamber(14, 14, 0, 0, 1, 0);
    if ( !HR1 && HR3 )
      DRLG_L5GChamber(14, 14, 0, 0, 0, 1);
    if ( HR1 && HR3 )
      DRLG_L5GChamber(14, 14, 0, 0, 1, 1);
    if ( !HR1 && !HR3 )
      DRLG_L5GChamber(14, 14, 0, 0, 0, 0);
  }
  if ( HR3 )
    DRLG_L5GChamber(28, 14, 0, 0, 1, 0);
  if ( HR1 && HR2 )
    DRLG_L5GHall(12, 18, 14, 18);
  if ( HR2 && HR3 )
    DRLG_L5GHall(26, 18, 28, 18);
  if ( HR1 && !HR2 && HR3 )
    DRLG_L5GHall(12, 18, 28, 18);
  if ( VR1 )
    DRLG_L5GChamber(14, 0, 0, 1, 0, 0);
  if ( VR2 )
  {
    if ( VR1 && !VR3 )
      DRLG_L5GChamber(14, 14, 1, 0, 0, 0);
    if ( !VR1 && VR3 )
      DRLG_L5GChamber(14, 14, 0, 1, 0, 0);
    if ( VR1 && VR3 )
      DRLG_L5GChamber(14, 14, 1, 1, 0, 0);
    if ( !VR1 && !VR3 )
      DRLG_L5GChamber(14, 14, 0, 0, 0, 0);
  }
  if ( VR3 )
    DRLG_L5GChamber(14, 28, 1, 0, 0, 0);
  if ( VR1 && VR2 )
    DRLG_L5GHall(18, 12, 18, 14);
  if ( VR2 && VR3 )
    DRLG_L5GHall(18, 26, 18, 28);
  if ( VR1 && !VR2 && VR3 )
    DRLG_L5GHall(18, 12, 18, 28);
  if ( setloadflag )
  {
    if ( VR1 || VR2 || VR3 )
    {
      v1 = 1;
      if ( !VR1 && VR2 && VR3 && random(0, 2) )
        v1 = 2;
      if ( VR1 && VR2 && !VR3 && random(0, 2) )
        v1 = 0;
      if ( VR1 && !VR2 && VR3 )
      {
        if ( random(0, 2) )
          v1 = 0;
        else
          v1 = 2;
      }
      if ( VR1 && VR2 && VR3 )
        v1 = random(0, 3);
      if ( v1 )
      {
        if ( v1 == 1 )
        {
          DRLG_L5SetRoom(16, 16);
        }
        else if ( v1 == 2 )
        {
          DRLG_L5SetRoom(16, 30);
        }
      }
      else
      {
        DRLG_L5SetRoom(16, 2);
      }
    }
    else
    {
      v0 = 1;
      if ( !HR1 && HR2 && HR3 && random(0, 2) )
        v0 = 2;
      if ( HR1 && HR2 && !HR3 && random(0, 2) )
        v0 = 0;
      if ( HR1 && !HR2 && HR3 )
      {
        if ( random(0, 2) )
          v0 = 0;
        else
          v0 = 2;
      }
      if ( HR1 && HR2 && HR3 )
        v0 = random(0, 3);
      if ( v0 )
      {
        if ( v0 == 1 )
        {
          DRLG_L5SetRoom(16, 16);
        }
        else if ( v0 == 2 )
        {
          DRLG_L5SetRoom(30, 16);
        }
      }
      else
      {
        DRLG_L5SetRoom(2, 16);
      }
    }
  }
}

//----- (0049F6C4) --------------------------------------------------------
void __fastcall DRLG_L5GChamber(int sx, int sy, bool topflag, bool bottomflag, bool leftflag, bool rightflag)
{
  int v7; // [esp+Ch] [ebp-10h]
  int v9; // [esp+10h] [ebp-Ch]
  signed int i; // [esp+14h] [ebp-8h]
  signed int j; // [esp+18h] [ebp-4h]

  if ( topflag == 1 )
  {
    dungeon[sx + 2][sy] = 12;
    dungeon[sx + 3][sy] = 12;
    dungeon[sx + 4][sy] = 3;
    dungeon[sx + 7][sy] = 9;
    dungeon[sx + 8][sy] = 12;
    dungeon[sx + 9][sy] = 2;
  }
  if ( bottomflag == 1 )
  {
    v7 = sy + 11;
    dungeon[sx + 2][v7] = 10;
    dungeon[sx + 3][v7] = 12;
    dungeon[sx + 4][v7] = 8;
    dungeon[sx + 7][v7] = 5;
    dungeon[sx + 8][v7] = 12;
    if ( dungeon[sx + 9][sy + 11] != 4 )
      dungeon[sx + 9][v7] = 21;
  }
  if ( leftflag == 1 )
  {
    dungeon[sx][sy + 2] = 11;
    dungeon[sx][sy + 3] = 11;
    dungeon[sx][sy + 4] = 3;
    dungeon[sx][sy + 7] = 8;
    dungeon[sx][sy + 8] = 11;
    dungeon[sx][sy + 9] = 1;
  }
  if ( rightflag == 1 )
  {
    v9 = sx + 11;
    dungeon[v9][sy + 2] = 14;
    dungeon[v9][sy + 3] = 11;
    dungeon[v9][sy + 4] = 9;
    dungeon[v9][sy + 7] = 5;
    dungeon[v9][sy + 8] = 11;
    if ( dungeon[sx + 11][sy + 9] != 4 )
      dungeon[v9][sy + 9] = 21;
  }
  for ( i = 1; i < 11; ++i )
  {
    for ( j = 1; j < 11; ++j )
    {
      dungeon[j + sx][i + sy] = 13;
      dflags[j + sx][i + sy] |= 0x40u;
    }
  }
  dungeon[sx + 4][sy + 4] = 15;
  dungeon[sx + 7][sy + 4] = 15;
  dungeon[sx + 4][sy + 7] = 15;
  dungeon[sx + 7][sy + 7] = 15;
}

//----- (0049F9BE) --------------------------------------------------------
void __fastcall DRLG_L5GHall(int x1, int y1, int x2, int y2)
{
  int i; // [esp+14h] [ebp-4h]
  int j; // [esp+14h] [ebp-4h]

  if ( y2 == y1 )
  {
    for ( i = x1; i < x2; ++i )
    {
      dungeon[i][y1] = 12;
      dungeon[i][y1 + 3] = 12;
    }
  }
  else
  {
    for ( j = y1; j < y2; ++j )
    {
      dungeon[x1][j] = 11;
      dungeon[x1 + 3][j] = 11;
    }
  }
}

//----- (0049FA6D) --------------------------------------------------------
void __fastcall DRLG_L5SetRoom(int rx1, int ry1)
{
  int i; // [esp+14h] [ebp-14h]
  int j; // [esp+18h] [ebp-10h]
  int v4; // [esp+1Ch] [ebp-Ch]
  int v5; // [esp+20h] [ebp-8h]
  BYTE *v6; // [esp+24h] [ebp-4h]

  v5 = *(unsigned __int8 *)pSetPiece;
  v4 = *((unsigned __int8 *)pSetPiece + 2);
  setpc_x = rx1;
  setpc_y = ry1;
  setpc_w = v5;
  setpc_h = v4;
  v6 = (BYTE *)pSetPiece + 4;
  for ( i = 0; i < v4; ++i )
  {
    for ( j = 0; j < v5; ++j )
    {
      dungeon[rx1 + j][ry1 + i] = *v6;
      dflags[rx1 + j][ry1 + i] |= 0x80u;
      v6 += 2;
    }
  }
}

//----- (0049FB65) --------------------------------------------------------
void __cdecl DRLG_L5FloodTVal()
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
      if ( dungeon[i][j] == 13 && !dung_map[x][y] )
      {
        DRLG_L5FTVR(i, j, x, y, 0);
        ++TransVal;
      }
      x += 2;
    }
    y += 2;
  }
}

//----- (0049FC20) --------------------------------------------------------
void __fastcall DRLG_L5FTVR(int i, int j, int x, int y, int d)
{
  if ( dung_map[x][y] || dungeon[i][j] != 13 )
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
    DRLG_L5FTVR(i + 1, j, x + 2, y, 1);
    DRLG_L5FTVR(i - 1, j, x - 2, y, 2);
    DRLG_L5FTVR(i, j + 1, x, y + 2, 3);
    DRLG_L5FTVR(i, j - 1, x, y - 2, 4);
    DRLG_L5FTVR(i - 1, j - 1, x - 2, y - 2, 5);
    DRLG_L5FTVR(i + 1, j - 1, x + 2, y - 2, 6);
    DRLG_L5FTVR(i - 1, j + 1, x - 2, y + 2, 7);
    DRLG_L5FTVR(i + 1, j + 1, x + 2, y + 2, 8);
  }
}

//----- (0049FF6B) --------------------------------------------------------
void __cdecl DRLG_L5TransFix()
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
      if ( dungeon[j][i] == 23 && dungeon[j][i - 1] == 18 )
      {
        dung_map[v0 + 1][v3] = dung_map[v0][v3];
        dung_map[v0 + 1][v3 + 1] = dung_map[v0][v3];
      }
      if ( dungeon[j][i] == 24 && dungeon[j + 1][i] == 19 )
      {
        dung_map[v0][v3 + 1] = dung_map[v0][v3];
        dung_map[v0 + 1][v3 + 1] = dung_map[v0][v3];
      }
      if ( dungeon[j][i] == 18 )
      {
        dung_map[v0 + 1][v3] = dung_map[v0][v3];
        dung_map[v0 + 1][v3 + 1] = dung_map[v0][v3];
      }
      if ( dungeon[j][i] == 19 )
      {
        dung_map[v0][v3 + 1] = dung_map[v0][v3];
        dung_map[v0 + 1][v3 + 1] = dung_map[v0][v3];
      }
      if ( dungeon[j][i] == 20 )
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

//----- (004A0290) --------------------------------------------------------
void __cdecl DRLG_L5DirtFix()
{
  signed int i; // [esp+Ch] [ebp-8h]
  signed int j; // [esp+10h] [ebp-4h]

  for ( i = 0; i < 40; ++i )
  {
    for ( j = 0; j < 40; ++j )
    {
      if ( dungeon[j][i] == 21 && dungeon[j + 1][i] != 19 )
        dungeon[j][i] = -54;
      if ( dungeon[j][i] == 19 && dungeon[j + 1][i] != 19 )
        dungeon[j][i] = -56;
      if ( dungeon[j][i] == 24 && dungeon[j + 1][i] != 19 )
        dungeon[j][i] = -51;
      if ( dungeon[j][i] == 18 && dungeon[j][i + 1] != 18 )
        dungeon[j][i] = -57;
      if ( dungeon[j][i] == 21 && dungeon[j][i + 1] != 18 )
        dungeon[j][i] = -54;
      if ( dungeon[j][i] == 23 && dungeon[j][i + 1] != 18 )
        dungeon[j][i] = -52;
    }
  }
}

