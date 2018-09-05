//----- (00437B50) --------------------------------------------------------
void __fastcall SetLightFX(int *x, int *y, __int16 *s_r, __int16 *s_g, int *s_b, int *d_r, int *d_g, int *d_b)
{
  int v8; // ST14_4
  int v9; // ST14_4

  *d_g = 0;
  *d_b = 0;
  v8 = *(_DWORD *)s_r;
  *(_DWORD *)s_r = 7 - *(_DWORD *)s_g;
  *(_DWORD *)s_g = v8;
  v9 = *s_b;
  *s_b = 7 - *d_r;
  *d_r = v9;
  *x = *(_DWORD *)s_r - *s_b;
  *y = *(_DWORD *)s_g - *d_r;
  if ( *x < 0 )
  {
    *x += 8;
    *d_g = 1;
  }
  if ( *y < 0 )
  {
    *y += 8;
    *d_b = 1;
  }
}

//----- (00437C0F) --------------------------------------------------------
void __fastcall DoLighting(int nXPos, int nYPos, int nRadius, int Lnum)
{
  int nx; // [esp+Ch] [ebp-54h]
  int ny; // [esp+10h] [ebp-50h]
  signed int v6; // [esp+18h] [ebp-48h]
  signed int v7; // [esp+18h] [ebp-48h]
  signed int v8; // [esp+18h] [ebp-48h]
  signed int v9; // [esp+18h] [ebp-48h]
  int v10; // [esp+1Ch] [ebp-44h]
  int v11; // [esp+20h] [ebp-40h]
  int i; // [esp+24h] [ebp-3Ch]
  int k; // [esp+24h] [ebp-3Ch]
  int m; // [esp+24h] [ebp-3Ch]
  int ii; // [esp+24h] [ebp-3Ch]
  signed int j; // [esp+28h] [ebp-38h]
  signed int l; // [esp+28h] [ebp-38h]
  signed int n; // [esp+28h] [ebp-38h]
  signed int jj; // [esp+28h] [ebp-38h]
  int v20; // [esp+2Ch] [ebp-34h]
  int s_g; // [esp+30h] [ebp-30h]
  int d_r; // [esp+34h] [ebp-2Ch]
  int s_b; // [esp+38h] [ebp-28h]
  int v24; // [esp+3Ch] [ebp-24h]
  int v25; // [esp+40h] [ebp-20h]
  int d_b; // [esp+44h] [ebp-1Ch]
  int d_g; // [esp+48h] [ebp-18h]
  int v28; // [esp+4Ch] [ebp-14h]
  int y; // [esp+50h] [ebp-10h]
  int s_r; // [esp+54h] [ebp-Ch]
  int x; // [esp+58h] [ebp-8h]
  int v32; // [esp+5Ch] [ebp-4h]

  nx = nYPos;
  ny = nXPos;
  x = 0;
  y = 0;
  s_b = 0;
  d_r = 0;
  d_g = 0;
  d_b = 0;
  if ( Lnum >= 0 )
  {
    x = LightList[Lnum]._xoff;
    y = LightList[Lnum]._yoff;
    if ( x < 0 )
    {
      x += 8;
      ny = nXPos - 1;
    }
    if ( y < 0 )
    {
      y += 8;
      nx = nYPos - 1;
    }
  }
  s_r = x;
  s_g = y;
  if ( ny - 15 >= 0 )
    v11 = 15;
  else
    v11 = ny + 1;
  if ( ny + 15 <= 112 )
    v20 = 15;
  else
    v20 = 112 - ny;
  if ( nx - 15 >= 0 )
    v24 = 15;
  else
    v24 = nx + 1;
  if ( nx + 15 <= 112 )
    v10 = 15;
  else
    v10 = 112 - nx;
  dTransVal[ny][nx] = 0;
  v32 = x + 8 * y;
  for ( i = 0; i < v24; ++i )
  {
    for ( j = 1; j < v20; ++j )
    {
      v25 = (unsigned __int8)dung_map_rgba[0][v32][i][j];
      if ( v25 < 128 )
      {
        v28 = nx + i;
        v6 = (unsigned __int8)dung_map_radius[nRadius][v25];
        if ( dTransVal[j + ny][nx + i] > v6 )
          dTransVal[j + ny][v28] = v6;
      }
    }
  }
  SetLightFX(&x, &y, (__int16 *)&s_r, (__int16 *)&s_g, &s_b, &d_r, &d_g, &d_b);
  v32 = x + 8 * y;
  for ( k = 0; k < v10; ++k )
  {
    for ( l = 1; l < v20; ++l )
    {
      v25 = (unsigned __int8)dung_map_rgba[0][v32][d_b + k][l + d_g];
      if ( v25 < 128 )
      {
        v28 = nx - l;
        v7 = (unsigned __int8)dung_map_radius[nRadius][v25];
        if ( dTransVal[k + ny][nx - l] > v7 )
          dTransVal[k + ny][v28] = v7;
      }
    }
  }
  SetLightFX(&x, &y, (__int16 *)&s_r, (__int16 *)&s_g, &s_b, &d_r, &d_g, &d_b);
  v32 = x + 8 * y;
  for ( m = 0; m < v10; ++m )
  {
    for ( n = 1; n < v11; ++n )
    {
      v25 = (unsigned __int8)dung_map_rgba[0][v32][d_b + m][n + d_g];
      if ( v25 < 128 )
      {
        v28 = nx - m;
        v8 = (unsigned __int8)dung_map_radius[nRadius][v25];
        if ( dTransVal[ny - n][nx - m] > v8 )
          dTransVal[ny - n][v28] = v8;
      }
    }
  }
  SetLightFX(&x, &y, (__int16 *)&s_r, (__int16 *)&s_g, &s_b, &d_r, &d_g, &d_b);
  v32 = x + 8 * y;
  for ( ii = 0; ii < v24; ++ii )
  {
    for ( jj = 1; jj < v11; ++jj )
    {
      v25 = (unsigned __int8)dung_map_rgba[0][v32][d_b + ii][jj + d_g];
      if ( v25 < 128 )
      {
        v28 = nx + jj;
        v9 = (unsigned __int8)dung_map_radius[nRadius][v25];
        if ( dTransVal[ny - ii][nx + jj] > v9 )
          dTransVal[ny - ii][v28] = v9;
      }
    }
  }
}

//----- (0043812B) --------------------------------------------------------
void __fastcall DoUnLight(int nXPos, int nYPos, int nRadius)
{
  int v3; // [esp+14h] [ebp-18h]
  int v4; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  int j; // [esp+20h] [ebp-Ch]
  int v7; // [esp+24h] [ebp-8h]
  int v8; // [esp+28h] [ebp-4h]
  int nRadiusa; // [esp+34h] [ebp+8h]

  nRadiusa = nRadius + 1;
  v4 = nYPos - nRadiusa;
  v3 = nRadiusa + nYPos;
  v8 = nXPos - nRadiusa;
  v7 = nRadiusa + nXPos;
  if ( nYPos - nRadiusa < 0 )
    v4 = 0;
  if ( v3 > 112 )
    v3 = 112;
  if ( v8 < 0 )
    v8 = 0;
  if ( v7 > 112 )
    v7 = 112;
  for ( i = v4; v3 > i; ++i )
  {
    for ( j = v8; v7 > j; ++j )
      dTransVal[j][i] = dTransVal2[j][i];
  }
}

//----- (0043821D) --------------------------------------------------------
void __fastcall DoUnVision(int nXPos, int nYPos, int nRadius)
{
  int v3; // [esp+14h] [ebp-18h]
  int v4; // [esp+18h] [ebp-14h]
  int j; // [esp+1Ch] [ebp-10h]
  int i; // [esp+20h] [ebp-Ch]
  int v7; // [esp+24h] [ebp-8h]
  int v8; // [esp+28h] [ebp-4h]
  int nRadiusa; // [esp+34h] [ebp+8h]

  nRadiusa = nRadius + 1;
  v4 = nYPos - nRadiusa;
  v3 = nYPos + nRadiusa;
  v8 = nXPos - nRadiusa;
  v7 = nXPos + nRadiusa;
  if ( nYPos - nRadiusa < 0 )
    v4 = 0;
  if ( v3 > 112 )
    v3 = 112;
  if ( v8 < 0 )
    v8 = 0;
  if ( v7 > 112 )
    v7 = 112;
  for ( i = v8; v7 > i; ++i )
  {
    for ( j = v4; v3 > j; ++j )
      dFlags[i][j] &= 0xBDu;
  }
}

//----- (00438312) --------------------------------------------------------
void __fastcall DoVision(int nXPos, int nYPos, int nRadius, unsigned __int8 doautomap, int visible)
{
  int v7; // [esp+18h] [ebp-30h]
  int v8; // [esp+1Ch] [ebp-2Ch]
  signed int i; // [esp+20h] [ebp-28h]
  signed int j; // [esp+24h] [ebp-24h]
  signed int v11; // [esp+28h] [ebp-20h]
  int k; // [esp+2Ch] [ebp-1Ch]
  signed int v13; // [esp+30h] [ebp-18h]
  int v14; // [esp+34h] [ebp-14h]
  signed int v15; // [esp+3Ch] [ebp-Ch]
  int y; // [esp+40h] [ebp-8h]
  signed int v17; // [esp+44h] [ebp-4h]

  if ( nXPos >= 0 && nXPos <= 112 && nYPos >= 0 && nYPos <= 112 )
  {
    if ( doautomap )
    {
      if ( dFlags[nXPos][nYPos] >= 0 )
        SetAutomapView(nXPos, nXPos);
      dFlags[nXPos][nYPos] |= 0x80u;
    }
    if ( visible )
      dFlags[nXPos][nYPos] |= 0x40u;
    dFlags[nXPos][nYPos] |= 2u;
  }
  for ( i = 0; i < 4; ++i )
  {
    for ( j = 0; j < 23; ++j )
    {
      v8 = 0;
      v14 = 2 * (nRadius - RadiusAdj[j]);
      for ( k = 0; k < v14 && !v8; k += 2 )
      {
        v13 = 0;
        v11 = 0;
        v17 = 0;
        v15 = 0;
        switch ( i )
        {
          case 0:
            v7 = nXPos + vCrawlTable[j][k];
            y = nYPos + vCrawlTable[j][k + 1];
            if ( (signed int)vCrawlTable[j][k] > 0 && (signed int)vCrawlTable[j][k + 1] > 0 )
            {
              v13 = -1;
              v15 = -1;
            }
            break;
          case 1:
            v7 = nXPos - vCrawlTable[j][k];
            y = nYPos - vCrawlTable[j][k + 1];
            if ( (signed int)vCrawlTable[j][k] > 0 && (signed int)vCrawlTable[j][k + 1] > 0 )
            {
              v17 = 1;
              v11 = 1;
            }
            break;
          case 2:
            v7 = nXPos + vCrawlTable[j][k];
            y = nYPos - vCrawlTable[j][k + 1];
            if ( (signed int)vCrawlTable[j][k] > 0 && (signed int)vCrawlTable[j][k + 1] > 0 )
            {
              v13 = -1;
              v15 = 1;
            }
            break;
          case 3:
            v7 = nXPos - vCrawlTable[j][k];
            y = nYPos + vCrawlTable[j][k + 1];
            if ( (signed int)vCrawlTable[j][k] > 0 && (signed int)vCrawlTable[j][k + 1] > 0 )
            {
              v17 = -1;
              v11 = 1;
            }
            break;
          default:
            break;
        }
        if ( v7 >= 0 && v7 <= 112 && y >= 0 && y <= 112 )
        {
          v8 = (unsigned __int8)nBlockTable[dPiece[v7][y]];
          if ( !nBlockTable[dPiece[v13 + v7][v17 + y]] || !nBlockTable[dPiece[v11 + v7][v15 + y]] )
          {
            if ( doautomap )
            {
              if ( dFlags[v7][y] >= 0 )
                SetAutomapView(v7, y);
              dFlags[v7][y] |= 0x80u;
            }
            if ( visible )
              dFlags[v7][y] |= 0x40u;
            dFlags[v7][y] |= 2u;
            if ( !v8 )
            {
              if ( dung_map[v7][y] )
                TransList[dung_map[v7][y]] = 1;
            }
          }
        }
      }
    }
  }
}

//----- (004388DD) --------------------------------------------------------
void __cdecl FreeLightTable()
{
  mem_free_dbg(pLightTbl, 583, "C:\\Diablo\\Direct\\LIGHTING.CPP");
  pLightTbl = 0;
}

//----- (0043890C) --------------------------------------------------------
void __cdecl MakeLightTable()
{
  _BYTE *v0; // ST7C_4
  double v1; // st7
  char v3; // c0
  signed int k; // [esp+44h] [ebp-48h]
  signed int m; // [esp+44h] [ebp-48h]
  signed int ii; // [esp+44h] [ebp-48h]
  signed int v7; // [esp+48h] [ebp-44h]
  signed int j; // [esp+4Ch] [ebp-40h]
  signed int l; // [esp+4Ch] [ebp-40h]
  signed int n; // [esp+4Ch] [ebp-40h]
  signed int jj; // [esp+4Ch] [ebp-40h]
  signed int kk; // [esp+4Ch] [ebp-40h]
  signed int ll; // [esp+4Ch] [ebp-40h]
  signed int mm; // [esp+4Ch] [ebp-40h]
  signed int i1; // [esp+4Ch] [ebp-40h]
  signed int i3; // [esp+4Ch] [ebp-40h]
  signed int i7; // [esp+4Ch] [ebp-40h]
  unsigned __int8 *ptr; // [esp+50h] [ebp-3Ch]
  unsigned __int8 *ptra; // [esp+50h] [ebp-3Ch]
  signed int i; // [esp+54h] [ebp-38h]
  signed int i2; // [esp+54h] [ebp-38h]
  int i6; // [esp+54h] [ebp-38h]
  signed int i8; // [esp+54h] [ebp-38h]
  BYTE v24; // [esp+58h] [ebp-34h]
  BYTE v25; // [esp+58h] [ebp-34h]
  BYTE v26; // [esp+58h] [ebp-34h]
  unsigned __int8 nn; // [esp+58h] [ebp-34h]
  char v28; // [esp+58h] [ebp-34h]
  unsigned __int8 i4; // [esp+58h] [ebp-34h]
  unsigned __int8 *v30; // [esp+5Ch] [ebp-30h]
  unsigned __int8 *v31; // [esp+5Ch] [ebp-30h]
  signed int i9; // [esp+60h] [ebp-2Ch]
  signed int i10; // [esp+64h] [ebp-28h]
  signed int i5; // [esp+68h] [ebp-24h]
  double v35; // [esp+6Ch] [ebp-20h]
  double v36; // [esp+6Ch] [ebp-20h]
  BYTE *pLightTbl_; // [esp+7Ch] [ebp-10h]
  int v38; // [esp+84h] [ebp-8h]
  unsigned __int8 v39; // [esp+88h] [ebp-4h]
  unsigned __int8 v40; // [esp+88h] [ebp-4h]
  unsigned __int8 v41; // [esp+88h] [ebp-4h]

  if ( pLightTbl )
    assertion_failed(603, "C:\\Diablo\\Direct\\LIGHTING.CPP");
  pLightTbl = (BYTE *)DiabloAllocPtr(6912, 604, "C:\\Diablo\\Direct\\LIGHTING.CPP");
  pLightTbl_ = pLightTbl;
  v38 = 0;
  if ( light4flag )
    v7 = 3;
  else
    v7 = 15;
  for ( i = 0; v7 > i; ++i )
  {
    *pLightTbl_++ = 0;
    for ( j = 0; j < 8; ++j )
    {
      v24 = v38 + 16 * j;
      v39 = 16 * j + 15;
      for ( k = 0; k < 16; ++k )
      {
        if ( k || j )
          *pLightTbl_++ = v24;
        if ( v24 >= (signed int)v39 )
        {
          v39 = 0;
          v24 = 0;
        }
        else
        {
          ++v24;
        }
      }
    }
    for ( l = 16; l < 20; ++l )
    {
      v25 = (v38 >> 1) + 8 * l;
      v40 = 8 * l + 7;
      for ( m = 0; m < 8; ++m )
      {
        *pLightTbl_++ = v25;
        if ( v25 >= (signed int)v40 )
        {
          v40 = 0;
          v25 = 0;
        }
        else
        {
          ++v25;
        }
      }
    }
    for ( n = 10; n < 16; ++n )
    {
      v26 = v38 + 16 * n;
      v41 = 16 * n + 15;
      for ( ii = 0; ii < 16; ++ii )
      {
        *pLightTbl_++ = v26;
        if ( v26 >= (signed int)v41 )
        {
          v41 = 0;
          v26 = 0;
        }
        else
        {
          ++v26;
        }
        if ( v26 == 255 )
        {
          v41 = 0;
          v26 = 0;
        }
      }
    }
    if ( light4flag )
      v38 += 5;
    else
      ++v38;
  }
  for ( jj = 0; jj < 256; ++jj )
    *pLightTbl_++ = 0;
  ptr = LoadFileInMem("PlrGFX\\Infra.TRN", 0, 647, "C:\\Diablo\\Direct\\LIGHTING.CPP");
  v30 = ptr;
  for ( kk = 0; kk < 256; ++kk )
    *pLightTbl_++ = *v30++;
  mem_free_dbg(ptr, 650, "C:\\Diablo\\Direct\\LIGHTING.CPP");
  ptra = LoadFileInMem("PlrGFX\\Stone.TRN", 0, 653, "C:\\Diablo\\Direct\\LIGHTING.CPP");
  v31 = ptra;
  for ( ll = 0; ll < 256; ++ll )
    *pLightTbl_++ = *v31++;
  mem_free_dbg(ptra, 656, "C:\\Diablo\\Direct\\LIGHTING.CPP");
  for ( mm = 0; mm < 8; ++mm )
  {
    for ( nn = -30; (signed int)nn < 239; ++nn )
    {
      if ( mm || nn != 226 )
        *pLightTbl_++ = nn;
      else
        *pLightTbl_++ = 0;
    }
    *pLightTbl_ = 0;
    v0 = pLightTbl_ + 1;
    *v0++ = 0;
    *v0 = 0;
    pLightTbl_ = v0 + 1;
  }
  for ( i1 = 0; i1 < 4; ++i1 )
  {
    v28 = -32;
    for ( i2 = 224; i2 < 239; i2 += 2 )
    {
      *pLightTbl_++ = v28;
      v28 += 2;
    }
  }
  for ( i3 = 0; i3 < 6; ++i3 )
  {
    for ( i4 = -32; (signed int)i4 < 239; ++i4 )
      *pLightTbl_++ = i4;
    *pLightTbl_++ = 0;
  }
  for ( i5 = 0; i5 < 16; ++i5 )
  {
    for ( i6 = 0; i6 < 128; ++i6 )
    {
      if ( 8 * i5 + 8 >= i6 )
        dung_map_radius[i5][i6] = (signed __int64)((double)i6 * 15.0 / ((double)(i5 + 1) * 8.0) + 0.5);
      else
        dung_map_radius[i5][i6] = 15;
    }
  }
  for ( i7 = 0; i7 < 8; ++i7 )
  {
    for ( i8 = 0; i8 < 8; ++i8 )
    {
      for ( i9 = 0; i9 < 16; ++i9 )
      {
        for ( i10 = 0; i10 < 16; ++i10 )
        {
          v1 = (double)((8 * i10 - i8) * (8 * i10 - i8) + (8 * i9 - i7) * (8 * i9 - i7));
          sub_4A7F40(v1);
          v35 = (double)(unsigned __int8)(signed __int64)v1;
          if ( v3 )
            v36 = v35 + -0.5;
          else
            v36 = v35 + 0.5;
          dung_map_rgba[0][i8 + 8 * i7][i9][i10] = (signed __int64)v36;
        }
      }
    }
  }
}

//----- (00438F77) --------------------------------------------------------
void unused_sub_438F77()
{
  signed int i; // [esp+Ch] [ebp-4h]

  if ( lightflag )
  {
    memset(dTransVal, 0, 0x3100u);
  }
  else
  {
    memset(dTransVal, lightmax, 0x3100u);
    for ( i = 0; i < 4; ++i )
    {
      if ( plr[i].plractive )
      {
        if ( plr[i].plrlevel == currlevel )
          DoLighting(plr[i].WorldX, plr[i].WorldY, plr[i]._pLightRad, -1);
      }
    }
  }
}

//----- (004390A4) --------------------------------------------------------
void unused_sub_4390A4()
{
  signed int i; // [esp+Ch] [ebp-4h]

  lightflag ^= 1u;
  if ( lightflag )
  {
    memset(dTransVal, 0, 0x3100u);
  }
  else
  {
    memcpy(dTransVal, dTransVal2, 0x3100u);
    for ( i = 0; i < 4; ++i )
    {
      if ( plr[i].plractive )
      {
        if ( plr[i].plrlevel == currlevel )
          DoLighting(plr[i].WorldX, plr[i].WorldY, plr[i]._pLightRad, -1);
      }
    }
  }
}

//----- (004391CE) --------------------------------------------------------
void __cdecl InitLightMax()
{
  if ( light4flag )
    lightmax = 3;
  else
    lightmax = 15;
}

//----- (004391FE) --------------------------------------------------------
void __cdecl InitLighting()
{
  signed int i; // [esp+Ch] [ebp-4h]

  numlights = 0;
  dolighting = 0;
  lightflag = 0;
  for ( i = 0; i < 32; ++i )
    lightactive[i] = i;
}

//----- (00439259) --------------------------------------------------------
int __fastcall AddLight(int x, int y, int r)
{
  int v4; // [esp+14h] [ebp-4h]

  if ( lightflag )
    return -1;
  v4 = -1;
  if ( numlights < 32 )
  {
    v4 = lightactive[numlights++];
    LightList[v4]._lx = x;
    LightList[v4]._ly = y;
    LightList[v4]._lradius = r;
    LightList[v4]._xoff = 0;
    LightList[v4]._yoff = 0;
    LightList[v4]._ldel = 0;
    LightList[v4]._lunflag = 0;
    dolighting = 1;
  }
  return v4;
}

//----- (00439359) --------------------------------------------------------
void __fastcall AddUnLight(int i)
{
  if ( !lightflag && i != -1 )
  {
    LightList[i]._ldel = 1;
    dolighting = 1;
  }
}

//----- (004393B0) --------------------------------------------------------
void __fastcall ChangeLightRadius(int i, int r)
{
  if ( !lightflag && i != -1 )
  {
    LightList[i]._lunflag = 1;
    LightList[i]._lunx = LightList[i]._lx;
    LightList[i]._luny = LightList[i]._ly;
    LightList[i]._lunr = LightList[i]._lradius;
    LightList[i]._lradius = r;
    dolighting = 1;
  }
}

//----- (0043948B) --------------------------------------------------------
void __fastcall ChangeLightXY(int i, int x, int y)
{
  if ( !lightflag && i != -1 )
  {
    LightList[i]._lunflag = 1;
    LightList[i]._lunx = LightList[i]._lx;
    LightList[i]._luny = LightList[i]._ly;
    LightList[i]._lunr = LightList[i]._lradius;
    LightList[i]._lx = x;
    LightList[i]._ly = y;
    dolighting = 1;
  }
}

//----- (0043957D) --------------------------------------------------------
void __fastcall ChangeLightOff(int i, int x, int y)
{
  if ( !lightflag && i != -1 )
  {
    LightList[i]._lunflag = 1;
    LightList[i]._lunx = LightList[i]._lx;
    LightList[i]._luny = LightList[i]._ly;
    LightList[i]._lunr = LightList[i]._lradius;
    LightList[i]._xoff = x;
    LightList[i]._yoff = y;
    dolighting = 1;
  }
}

//----- (0043966F) --------------------------------------------------------
void __fastcall ChangeLight(int i, int x, int y, int r)
{
  if ( !lightflag && i != -1 )
  {
    LightList[i]._lunflag = 1;
    LightList[i]._lunx = LightList[i]._lx;
    LightList[i]._luny = LightList[i]._ly;
    LightList[i]._lunr = LightList[i]._lradius;
    LightList[i]._lx = x;
    LightList[i]._ly = y;
    LightList[i]._lradius = r;
    dolighting = 1;
  }
}

//----- (00439776) --------------------------------------------------------
void __cdecl ProcessLightList()
{
  BYTE v0; // ST1C_1
  int i; // [esp+Ch] [ebp-Ch]
  int j; // [esp+Ch] [ebp-Ch]
  int v3; // [esp+Ch] [ebp-Ch]
  int Lnum; // [esp+10h] [ebp-8h]
  int Lnuma; // [esp+10h] [ebp-8h]

  if ( !lightflag )
  {
    if ( dolighting )
    {
      for ( i = 0; i < numlights; ++i )
      {
        Lnum = lightactive[i];
        if ( LightList[Lnum]._ldel )
          DoUnLight(LightList[Lnum]._lx, LightList[Lnum]._ly, LightList[Lnum]._lradius);
        if ( LightList[Lnum]._lunflag )
        {
          DoUnLight(LightList[Lnum]._lunx, LightList[Lnum]._luny, LightList[Lnum]._lunr);
          LightList[Lnum]._lunflag = 0;
        }
      }
      for ( j = 0; j < numlights; ++j )
      {
        Lnuma = lightactive[j];
        if ( !LightList[Lnuma]._ldel )
          DoLighting(LightList[Lnuma]._lx, LightList[Lnuma]._ly, LightList[Lnuma]._lradius, Lnuma);
      }
      v3 = 0;
      while ( v3 < numlights )
      {
        if ( LightList[lightactive[v3]]._ldel )
        {
          v0 = lightactive[--numlights];
          lightactive[numlights] = lightactive[v3];
          lightactive[v3] = v0;
        }
        else
        {
          ++v3;
        }
      }
    }
    dolighting = 0;
  }
}

//----- (004399A9) --------------------------------------------------------
void __cdecl SavePreLighting()
{
  memcpy(dTransVal2, dTransVal, 0x3100u);
}

//----- (004399D0) --------------------------------------------------------
void __cdecl InitVision()
{
  signed int i; // [esp+Ch] [ebp-4h]

  numvision = 0;
  dovision = 0;
  visionid = 1;
  for ( i = 0; TransVal > i; ++i )
    TransList[i] = 0;
}

//----- (00439A2F) --------------------------------------------------------
int __fastcall AddVision(int x, int y, int r, bool mine)
{
  int v5; // [esp+14h] [ebp-4h]

  if ( numvision < 32 )
  {
    VisionList[numvision]._lx = x;
    VisionList[numvision]._ly = y;
    VisionList[numvision]._lradius = r;
    v5 = visionid++;
    VisionList[numvision]._lid = v5;
    VisionList[numvision]._ldel = 0;
    VisionList[numvision]._lunflag = 0;
    VisionList[numvision++]._lflags = mine != 0;
    dovision = 1;
  }
  return v5;
}

//----- (00439BBA) --------------------------------------------------------
void __fastcall ChangeVisionRadius(int id, int r)
{
  int i; // [esp+14h] [ebp-4h]

  for ( i = 0; numvision > i; ++i )
  {
    if ( VisionList[i]._lid == id )
    {
      VisionList[i]._lunflag = 1;
      VisionList[i]._lunx = VisionList[i]._lx;
      VisionList[i]._luny = VisionList[i]._ly;
      VisionList[i]._lunr = VisionList[i]._lradius;
      VisionList[i]._lradius = r;
      dovision = 1;
    }
  }
}

//----- (00439CB2) --------------------------------------------------------
void __fastcall ChangeVisionXY(int id, int x, int y)
{
  int i; // [esp+14h] [ebp-4h]

  for ( i = 0; i < numvision; ++i )
  {
    if ( VisionList[i]._lid == id )
    {
      VisionList[i]._lunflag = 1;
      VisionList[i]._lunx = VisionList[i]._lx;
      VisionList[i]._luny = VisionList[i]._ly;
      VisionList[i]._lunr = VisionList[i]._lradius;
      VisionList[i]._lx = x;
      VisionList[i]._ly = y;
      dovision = 1;
    }
  }
}

//----- (00439EE4) --------------------------------------------------------
void __cdecl ProcessVisionList()
{
  int i; // [esp+Ch] [ebp-8h]
  signed int j; // [esp+Ch] [ebp-8h]
  int k; // [esp+Ch] [ebp-8h]
  int l; // [esp+Ch] [ebp-8h]
  signed int v4; // [esp+10h] [ebp-4h]

  if ( dovision )
  {
    for ( i = 0; i < numvision; ++i )
    {
      if ( VisionList[i]._ldel )
        DoUnVision(VisionList[i]._lx, VisionList[i]._ly, VisionList[i]._lradius);
      if ( VisionList[i]._lunflag )
      {
        DoUnVision(VisionList[i]._lunx, VisionList[i]._luny, VisionList[i]._lunr);
        VisionList[i]._lunflag = 0;
      }
    }
    for ( j = 0; TransVal > j; ++j )
      TransList[j] = 0;
    for ( k = 0; k < numvision; ++k )
    {
      if ( !VisionList[k]._ldel )
        DoVision(
          VisionList[k]._lx,
          VisionList[k]._ly,
          VisionList[k]._lradius,
          VisionList[k]._lflags & 1,
          VisionList[k]._lflags & 1);
    }
    do
    {
      v4 = 0;
      for ( l = 0; l < numvision; ++l )
      {
        if ( VisionList[l]._ldel )
        {
          if ( --numvision > 0 && l != numvision )
            qmemcpy(&VisionList[l], &VisionList[numvision], sizeof(LightListStruct));
          v4 = 1;
        }
      }
    }
    while ( v4 );
  }
  dovision = 0;
}

