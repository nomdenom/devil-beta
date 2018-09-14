#include "all.h"

//----- (0043A370) --------------------------------------------------------
void __fastcall LoadL3Dungeon(char *sFileName, int vx, int vy)
{
  int nYPos; // [esp+14h] [ebp-18h]
  signed int nYPosa; // [esp+14h] [ebp-18h]
  int nYPosb; // [esp+14h] [ebp-18h]
  int nXPos; // [esp+18h] [ebp-14h]
  signed int nXPosa; // [esp+18h] [ebp-14h]
  int nXPosb; // [esp+18h] [ebp-14h]
  int v10; // [esp+1Ch] [ebp-10h]
  int v11; // [esp+20h] [ebp-Ch]
  unsigned __int8 *pMap; // [esp+24h] [ebp-8h]
  BYTE *v13; // [esp+28h] [ebp-4h]

  InitL3Dungeon();
  dminx = 16;
  dminy = 16;
  dmaxx = 96;
  dmaxy = 96;
  DRLG_InitTrans();
  pMap = LoadFileInMem(sFileName, 0, 1520, "DRLG_L3.CPP");
  v11 = *pMap;
  v10 = pMap[2];
  v13 = pMap + 4;
  for ( nYPos = 0; v10 > nYPos; ++nYPos )
  {
    for ( nXPos = 0; v11 > nXPos; ++nXPos )
    {
      if ( *v13 )
        dungeon[nXPos][nYPos] = *v13;
      else
        dungeon[nXPos][nYPos] = 7;
      v13 += 2;
    }
  }
  for ( nYPosa = 0; nYPosa < 40; ++nYPosa )
  {
    for ( nXPosa = 0; nXPosa < 40; ++nXPosa )
    {
      if ( !dungeon[nXPosa][nYPosa] )
        dungeon[nXPosa][nYPosa] = 8;
    }
  }
  abyssx = 112;
  DRLG_L3Pass3();
  DRLG_Init_Globals();
  ViewX = 31;
  ViewY = 83;
  SetMapMonsters((char *)pMap, 0, 0);
  SetMapObjects(pMap, 0, 0);
  for ( nYPosb = 0; nYPosb < 112; ++nYPosb )
  {
    for ( nXPosb = 0; nXPosb < 112; ++nXPosb )
    {
      if ( dPiece[nXPosb][nYPosb] < 56 || dPiece[nXPosb][nYPosb] > 147 )
      {
        if ( dPiece[nXPosb][nYPosb] < 154 || dPiece[nXPosb][nYPosb] > 161 )
        {
          if ( dPiece[nXPosb][nYPosb] == 150 )
          {
            DoLighting(nXPosb, nYPosb, 7, -1);
          }
          else if ( dPiece[nXPosb][nYPosb] == 152 )
          {
            DoLighting(nXPosb, nYPosb, 7, -1);
          }
        }
        else
        {
          DoLighting(nXPosb, nYPosb, 7, -1);
        }
      }
      else
      {
        DoLighting(nXPosb, nYPosb, 7, -1);
      }
    }
  }
  mem_free_dbg(pMap, 1563, "DRLG_L3.CPP");
}

//----- (0043A677) --------------------------------------------------------
void __cdecl InitL3Dungeon()
{
  memset(dungeon, 0, 0x640u);
}

//----- (0043A69B) --------------------------------------------------------
void __cdecl DRLG_L3Pass3()
{
  int v0; // eax
  int v1; // eax
  int v2; // eax
  int v3; // eax
  WORD *v4; // esi
  WORD v5; // ax
  int v6; // eax
  int j; // [esp+Ch] [ebp-24h]
  signed int l; // [esp+Ch] [ebp-24h]
  signed int v9; // [esp+Ch] [ebp-24h]
  int v10; // [esp+10h] [ebp-20h]
  signed int m; // [esp+14h] [ebp-1Ch]
  signed int n; // [esp+18h] [ebp-18h]
  signed int i; // [esp+1Ch] [ebp-14h]
  signed int k; // [esp+1Ch] [ebp-14h]
  signed int v15; // [esp+1Ch] [ebp-14h]
  int v16; // [esp+20h] [ebp-10h]
  int v17; // [esp+24h] [ebp-Ch]
  int v18; // [esp+24h] [ebp-Ch]
  int v19; // [esp+24h] [ebp-Ch]
  int v20; // [esp+28h] [ebp-8h]
  int v21; // [esp+28h] [ebp-8h]
  int v22; // [esp+28h] [ebp-8h]
  int v23; // [esp+2Ch] [ebp-4h]
  int v24; // [esp+2Ch] [ebp-4h]
  int v25; // [esp+2Ch] [ebp-4h]

  v0 = pMegaTiles[28] + 1;
  v23 = pMegaTiles[28] + 1;
  LOWORD(v0) = pMegaTiles[29];
  v20 = ++v0;
  LOWORD(v0) = pMegaTiles[30];
  v1 = v0 + 1;
  v17 = v1;
  LOWORD(v1) = pMegaTiles[31];
  for ( i = 0; i < 112; i += 2 )
  {
    for ( j = 0; j < abyssx; j += 2 )
    {
      dPiece[j][i] = v23;
      dPiece[j + 1][i] = v20;
      dPiece[j][i + 1] = v17;
      dPiece[j + 1][i + 1] = v1 + 1;
    }
  }
  v2 = pMegaTiles[472] + 1;
  v24 = pMegaTiles[472] + 1;
  LOWORD(v2) = pMegaTiles[473];
  v21 = ++v2;
  LOWORD(v2) = pMegaTiles[474];
  v3 = v2 + 1;
  v18 = v3;
  LOWORD(v3) = pMegaTiles[475];
  for ( k = 0; k < 112; k += 2 )
  {
    for ( l = abyssx; l < 112; l += 2 )
    {
      dPiece[l][k] = v24;
      dPiece[l + 1][k] = v21;
      dPiece[l][k + 1] = v18;
      dPiece[l + 1][k + 1] = v3 + 1;
    }
  }
  v15 = 16;
  for ( m = 0; m < 40; ++m )
  {
    v9 = 16;
    for ( n = 0; n < 40; ++n )
    {
      v10 = dungeon[n][m] - 1;
      if ( v10 < 0 )
      {
        v25 = 0;
        v22 = 0;
        v19 = 0;
        v16 = 0;
      }
      else
      {
        v4 = &pMegaTiles[4 * v10];
        v5 = *v4;
        ++v4;
        v6 = v5 + 1;
        v25 = v6;
        LOWORD(v6) = *v4;
        ++v4;
        v22 = ++v6;
        LOWORD(v6) = *v4;
        v19 = ++v6;
        LOWORD(v6) = v4[1];
        v16 = v6 + 1;
      }
      dPiece[v9][v15] = v25;
      dPiece[v9 + 1][v15] = v22;
      dPiece[v9][v15 + 1] = v19;
      dPiece[v9 + 1][v15 + 1] = v16;
      v9 += 2;
    }
    v15 += 2;
  }
}

//----- (0043A986) --------------------------------------------------------
void __fastcall LoadPreL3Dungeon(char *sFileName, int vx, int vy)
{
  int i; // [esp+14h] [ebp-18h]
  signed int k; // [esp+14h] [ebp-18h]
  int j; // [esp+18h] [ebp-14h]
  signed int l; // [esp+18h] [ebp-14h]
  int v8; // [esp+1Ch] [ebp-10h]
  int v9; // [esp+20h] [ebp-Ch]
  unsigned __int8 *ptr; // [esp+24h] [ebp-8h]
  BYTE *v11; // [esp+28h] [ebp-4h]

  InitL3Dungeon();
  DRLG_InitTrans();
  ptr = LoadFileInMem(sFileName, 0, 1577, "DRLG_L3.CPP");
  v9 = *ptr;
  v8 = ptr[2];
  v11 = ptr + 4;
  for ( i = 0; v8 > i; ++i )
  {
    for ( j = 0; v9 > j; ++j )
    {
      if ( *v11 )
        dungeon[j][i] = *v11;
      else
        dungeon[j][i] = 7;
      v11 += 2;
    }
  }
  for ( k = 0; k < 40; ++k )
  {
    for ( l = 0; l < 40; ++l )
    {
      if ( !dungeon[l][k] )
        dungeon[l][k] = 8;
    }
  }
  memcpy(pdungeon, dungeon, 0x640u);
  mem_free_dbg(ptr, 1600, "DRLG_L3.CPP");
}

