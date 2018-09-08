//----- (004119D0) --------------------------------------------------------
void __cdecl FillSolidBlockTbls()
{
  char v0; // [esp+10h] [ebp-14h]
  unsigned int pdwFileLen; // [esp+14h] [ebp-10h]
  unsigned __int8 *ptr; // [esp+18h] [ebp-Ch]
  unsigned __int8 *v3; // [esp+1Ch] [ebp-8h]
  unsigned int i; // [esp+20h] [ebp-4h]

  memset(nBlockTable, 0, 0x801u);
  memset(nSolidTable, 0, 0x801u);
  memset(nTransTable, 0, 0x801u);
  memset(nMissileTable, 0, 0x801u);
  memset(nTrapTable, 0, 0x801u);
  switch ( leveltype )
  {
    case 0:
      ptr = LoadFileInMem("Levels\\TownData\\Town.SOL", (int *)&pdwFileLen, 119, "GENDUNG.CPP");
      break;
    case 1:
      ptr = LoadFileInMem("Levels\\L1Data\\L1.SOL", (int *)&pdwFileLen, 122, "GENDUNG.CPP");
      break;
    case 2:
      ptr = LoadFileInMem("Levels\\L2Data\\L2.SOL", (int *)&pdwFileLen, 125, "GENDUNG.CPP");
      break;
    case 3:
      ptr = LoadFileInMem("Levels\\L3Data\\L3.SOL", (int *)&pdwFileLen, 128, "GENDUNG.CPP");
      break;
    case 4:
      ptr = LoadFileInMem("Levels\\L4Data\\L4.SOL", (int *)&pdwFileLen, 131, "GENDUNG.CPP");
      break;
    default:
      TermMsg("FillSolidBlockTbls");
      return;
  }
  v3 = ptr;
  for ( i = 1; pdwFileLen >= i; ++i )
  {
    v0 = *v3++;
    if ( v0 & 1 )
      nSolidTable[i] = 1;
    if ( v0 & 2 )
      nBlockTable[i] = 1;
    if ( v0 & 4 )
      nMissileTable[i] = 1;
    if ( v0 & 8 )
      nTransTable[i] = 1;
    if ( v0 < 0 )
      nTrapTable[i] = 1;
    block_lvid[i] = (unsigned __int8)(v0 & 0x70) >> 4;
  }
  mem_free_dbg(ptr, 149, "GENDUNG.CPP");
}

//----- (00411BF1) --------------------------------------------------------
void __cdecl gendung_418D91()
{
  char *v0; // esi
  char *v1; // edi
  int kk; // ecx
  char *v6; // esi
  char *v7; // edi
  int v9; // ecx
  signed int v10; // edx
  int v11; // eax
  int v12; // ecx
  int v15; // [esp-4h] [ebp-40h]
  char *v16; // [esp+Ch] [ebp-30h]
  unsigned __int16 i1; // [esp+10h] [ebp-2Ch]
  int v18; // [esp+14h] [ebp-28h]
  int v19; // [esp+14h] [ebp-28h]
  signed int v20; // [esp+18h] [ebp-24h]
  signed int j; // [esp+1Ch] [ebp-20h]
  int n; // [esp+1Ch] [ebp-20h]
  signed int ll; // [esp+1Ch] [ebp-20h]
  int i; // [esp+20h] [ebp-1Ch]
  signed int k; // [esp+20h] [ebp-1Ch]
  int m; // [esp+20h] [ebp-1Ch]
  signed int jj; // [esp+20h] [ebp-1Ch]
  signed int ii; // [esp+20h] [ebp-1Ch]
  signed int mm; // [esp+20h] [ebp-1Ch]
  signed int v30; // [esp+28h] [ebp-14h]
  int v31; // [esp+28h] [ebp-14h]
  signed int l; // [esp+2Ch] [ebp-10h]
  signed int nn; // [esp+2Ch] [ebp-10h]
  int v34; // [esp+30h] [ebp-Ch]
  signed int v35; // [esp+34h] [ebp-8h]
  WORD v36; // [esp+38h] [ebp-4h]
  int v37; // [esp+38h] [ebp-4h]

  for ( i = 0; i < 2048; ++i )
  {
    gendung_576C90[i] = i;
    gendung_57D6B8[i] = 0;
  }
  if ( leveltype == 4 )
    v20 = 12;
  else
    v20 = 10;
  for ( j = 0; j < 112; ++j )
  {
    for ( k = 0; k < 112; ++k )
    {
      for ( l = 0; v20 > l; ++l )
      {
        v36 = dpiece_defs_map_2[0][16 * k][16 * j + l];
        if ( v36 )
        {
          ++gendung_57D6B8[v36 & 0xFFF];
          gendung_4ED5B0[v36 & 0xFFF] = v36 & 0x7000;
        }
      }
    }
  }
  dword_4FE8FC = (unsigned __int16)*(_DWORD *)pDungeonCels;
  for ( m = 0; dword_4FE8FC > m; ++m )
    gendung_58E2F0[m] = (unsigned __int16)(*((_WORD *)pDungeonCels + 2 * m + 2) - *((_WORD *)pDungeonCels + 2 * m));
  gendung_58E2F0[0] = 0;
  gendung_4191BF(2047);
  v30 = 0;
  v18 = 0;
  if ( light4flag )
  {
    while ( v30 < 0x100000 )
      v30 += 2 * gendung_58E2F0[v18++];
  }
  else
  {
    while ( v30 < 0x100000 )
      v30 += 14 * gendung_58E2F0[v18++];
  }
  v19 = v18 - 1;
  if ( v19 > 128 )
    v19 = 128;
  v31 = 0;
  if ( light4flag )
    v35 = 3;
  else
    v35 = 15;
  for ( n = 0; v19 > n; ++n )
  {
    v37 = gendung_576C90[n];
    speed_cel_frame_num_from_light_index_frame_num[0][16 * n] = v37;
    if ( gendung_4ED5B0[n] == 4096 )
    {
      for ( ii = 1; v35 > ii; ++ii )
      {
        speed_cel_frame_num_from_light_index_frame_num[0][16 * n + ii] = v31;
        v6 = (char *)pDungeonCels + *((_DWORD *)pDungeonCels + v37);
        v7 = (char *)pSpeedCels + v31;
        _EBX = &pLightTbl[256 * ii];
        v9 = 32;
        do
        {
          v15 = v9;
          v10 = 32;
          do
          {
            while ( 1 )
            {
              v11 = (unsigned __int8)*v6++;
              *v7++ = v11;
              if ( (v11 & 0x80u) == 0 )
                break;
              LOBYTE(v11) = -(char)v11;
              v10 -= v11;
              if ( !v10 )
                goto LABEL_51;
            }
            v10 -= v11;
            for (v12 = v11; v12; --v12)
            {
              _AL = *v6++;
              ASM_XLAT();
              *v7++ = _AL;
          }
          }
          while ( v10 );
LABEL_51:
          v9 = v15 - 1;
        }
        while ( v15 != 1 );
        v31 += gendung_58E2F0[n];
      }
    }
    else
    {
      v34 = gendung_58E2F0[n];
      for ( jj = 1; v35 > jj; ++jj )
      {
        speed_cel_frame_num_from_light_index_frame_num[0][16 * n + jj] = v31;
        v0 = (char *)pDungeonCels + *((_DWORD *)pDungeonCels + v37);
        v1 = (char *)pSpeedCels + v31;
        _EBX = &pLightTbl[256 * jj];
        for ( kk = v34; kk; --kk )
        {
          _AL = *v0++;
          ASM_XLAT();
          *v1++ = _AL;
        }
        v31 += v34;
      }
    }
  }
  for ( ll = 0; ll < 112; ++ll )
  {
    for ( mm = 0; mm < 112; ++mm )
    {
      if ( dPiece[mm][ll] )
      {
        v16 = (char *)dpiece_defs_map_2 + 3584 * mm + 32 * ll;
        for ( nn = 0; v20 > nn; ++nn )
        {
          if ( *(_WORD *)&v16[2 * nn] )
          {
            for ( i1 = 0; i1 < v19; ++i1 )
            {
              if ( (*(_WORD *)&v16[2 * nn] & 0xFFF) == gendung_576C90[i1] )
              {
                *(_WORD *)&v16[2 * nn] = i1 + gendung_4ED5B0[i1] + -32768;
                i1 = v19;
              }
            }
          }
        }
      }
    }
  }
}

//----- (004120F4) --------------------------------------------------------
void __fastcall gendung_4191BF(int frames)
{
  int v1; // [esp+10h] [ebp-Ch]
  int a1; // [esp+14h] [ebp-8h]
  signed int v3; // [esp+18h] [ebp-4h]

  v1 = frames;
  v3 = 0;
  while ( v1 > 0 && !v3 )
  {
    v3 = 1;
    for ( a1 = 0; v1 > a1; ++a1 )
    {
      if ( gendung_57D6B8[a1 + 1] > gendung_57D6B8[a1] )
      {
        gendung_4191FB(a1, a1 + 1);
        v3 = 0;
      }
    }
    --v1;
  }
}

//----- (00412187) --------------------------------------------------------
void __fastcall gendung_4191FB(int a1, int a2)
{
  int v2; // ST14_4
  int v3; // ST14_4
  int v4; // ST14_4

  v2 = gendung_57D6B8[a1];
  gendung_57D6B8[a1] = gendung_57D6B8[a2];
  gendung_57D6B8[a2] = v2;
  v3 = gendung_576C90[a1];
  gendung_576C90[a1] = gendung_576C90[a2];
  gendung_576C90[a2] = v3;
  LOWORD(v3) = gendung_4ED5B0[a1];
  gendung_4ED5B0[a1] = gendung_4ED5B0[a2];
  gendung_4ED5B0[a2] = v3;
  v4 = gendung_58E2F0[a1];
  gendung_58E2F0[a1] = gendung_58E2F0[a2];
  gendung_58E2F0[a2] = v4;
}

//----- (0041225E) --------------------------------------------------------
int __fastcall gendung_get_dpiece_num_from_coord(int x, int y)
{
  int v3; // [esp+14h] [ebp-4h]

  if ( 112 - y <= x )
    v3 = 12544
       - ((112 - y - 1 + (112 - y - 1) * (112 - y - 1) + (112 - x - 1) * (112 - x - 1 + 2 * (112 - y - 1) + 3)) / 2
        + 1);
  else
    v3 = (y + y * y + x * (x + 2 * y + 3)) / 2;
  return v3;
}

//----- (004122F6) --------------------------------------------------------
void __cdecl gendung_4192C2()
{
  int y; // [esp+10h] [ebp-8h]
  int x; // [esp+14h] [ebp-4h]

  for ( x = 0; x < 112; ++x )
  {
    for ( y = 0; y < 112; ++y )
      qmemcpy(
        (char *)dpiece_defs_map_1 + 32 * gendung_get_dpiece_num_from_coord(x, y),
        (char *)dpiece_defs_map_2 + 3584 * x + 32 * y,
        0x20u);
  }
}

//----- (00412380) --------------------------------------------------------
void __cdecl SetDungeonMicros()
{
  WORD *v0; // [esp+Ch] [ebp-1Ch]
  signed int v1; // [esp+10h] [ebp-18h]
  signed int i; // [esp+14h] [ebp-14h]
  int v3; // [esp+18h] [ebp-10h]
  int v4; // [esp+18h] [ebp-10h]
  signed int j; // [esp+1Ch] [ebp-Ch]
  signed int k; // [esp+20h] [ebp-8h]
  signed int l; // [esp+20h] [ebp-8h]
  char *v8; // [esp+24h] [ebp-4h]

  if ( leveltype == 4 )
  {
    gendung_567144 = 12;
    v1 = 16;
  }
  else
  {
    gendung_567144 = 10;
    v1 = 10;
  }
  for ( i = 0; i < 112; ++i )
  {
    for ( j = 0; j < 112; ++j )
    {
      v3 = dPiece[j][i];
      v0 = (WORD *)((char *)dpiece_defs_map_2 + 3584 * j + 32 * i);
      if ( v3 )
      {
        v4 = v3 - 1;
        if ( leveltype == 4 )
          v8 = (char *)pLevelPieces + 32 * v4;
        else
          v8 = (char *)pLevelPieces + 20 * v4;
        for ( k = 0; v1 > k; ++k )
          v0[k] = *(_WORD *)&v8[2 * ((k & 1) + v1 - 2 - (k & 0xE))];
      }
      else
      {
        for ( l = 0; v1 > l; ++l )
          v0[l] = 0;
      }
    }
  }
  gendung_418D91();
  gendung_4192C2();
  if ( zoomflag )
  {
    scr_pix_width = 640;
    scr_pix_height = 352;
    gendung_5847D0_unused = 10;
    gendung_5847D4_unused = 11;
  }
  else
  {
    scr_pix_width = 384;
    scr_pix_height = 224;
    gendung_5847D0_unused = 6;
    gendung_5847D4_unused = 7;
  }
}

//----- (00412564) --------------------------------------------------------
void __cdecl DRLG_InitTrans()
{
  memset(dung_map, 0, 0x3100u);
  memset(TransList, 0, 0x100u);
  TransVal = 1;
}

//----- (004125A3) --------------------------------------------------------
void __fastcall DRLG_MRectTrans(int x1, int y1, int x2, int y2)
{
  int i; // [esp+14h] [ebp-8h]
  int j; // [esp+18h] [ebp-4h]
  int x2a; // [esp+24h] [ebp+8h]
  int y2a; // [esp+28h] [ebp+Ch]

  x2a = 2 * x2 + 16;
  y2a = 2 * y2 + 16;
  for ( i = 2 * y1 + 17; i <= y2a; ++i )
  {
    for ( j = 2 * x1 + 17; j <= x2a; ++j )
      dung_map[j][i] = TransVal;
  }
  ++TransVal;
}

//----- (0041273D) --------------------------------------------------------
void __fastcall DRLG_RectTrans(int x1, int y1, int x2, int y2)
{
  int i; // [esp+14h] [ebp-8h]
  int j; // [esp+18h] [ebp-4h]

  for ( i = y1; i <= y2; ++i )
  {
    for ( j = x1; x2 >= j; ++j )
      dung_map[j][i] = TransVal;
  }
  ++TransVal;
}

//----- (004127B8) --------------------------------------------------------
void __fastcall DRLG_CopyTrans(int sx, int sy, int dx, int dy)
{
  dung_map[dx][dy] = dung_map[sx][sy];
}

//----- (00412801) --------------------------------------------------------
void __fastcall DRLG_ListTrans(int num, unsigned __int8 *List)
{
  unsigned __int8 x1; // ST2C_1
  unsigned __int8 *v3; // ST14_4
  unsigned __int8 v4; // ST20_1
  unsigned __int8 v5; // ST28_1
  unsigned __int8 v6; // ST1C_1
  unsigned __int8 *v7; // [esp+Ch] [ebp-1Ch]
  int i; // [esp+1Ch] [ebp-Ch]

  v7 = List;
  for ( i = 0; num > i; ++i )
  {
    x1 = *v7;
    v3 = v7 + 1;
    v4 = *v3++;
    v5 = *v3++;
    v6 = *v3;
    v7 = v3 + 1;
    DRLG_RectTrans(x1, v4, v5, v6);
  }
}

//----- (00412883) --------------------------------------------------------
void __fastcall DRLG_AreaTrans(int num, unsigned __int8 *List)
{
  unsigned __int8 x1; // ST2C_1
  unsigned __int8 *v3; // ST14_4
  unsigned __int8 y1; // ST20_1
  unsigned __int8 x2; // ST28_1
  unsigned __int8 y2; // ST1C_1
  unsigned __int8 *p; // [esp+Ch] [ebp-1Ch]
  int i; // [esp+1Ch] [ebp-Ch]

  p = List;
  for ( i = 0; i < num; ++i )
  {
    x1 = *p;
    v3 = p + 1;
    y1 = *v3++;
    x2 = *v3++;
    y2 = *v3;
    p = v3 + 1;
    DRLG_RectTrans(x1, y1, x2, y2);
    --TransVal;
  }
  ++TransVal;
}

//----- (00412911) --------------------------------------------------------
void __cdecl DRLG_SetPC()
{
  int i; // [esp+Ch] [ebp-18h]
  int j; // [esp+10h] [ebp-14h]
  int v2; // [esp+14h] [ebp-10h]
  int v3; // [esp+18h] [ebp-Ch]
  int v4; // [esp+1Ch] [ebp-8h]
  int v5; // [esp+20h] [ebp-4h]

  v5 = 2 * setpc_w;
  v4 = 2 * setpc_h;
  v3 = 2 * setpc_x + 16;
  v2 = 2 * setpc_y + 16;
  for ( i = 0; v4 > i; ++i )
  {
    for ( j = 0; v5 > j; ++j )
      dFlags[j + v3][i + v2] |= 8u;
  }
}

