//----- (00437B50) --------------------------------------------------------
// NOTE: Argument types differ from PSX
void __fastcall SetLightFX(int *x, int *y, int *s_r, int *s_g, int *s_b, int *d_r, int *d_g, int *d_b)
{
  int orig_r; // ST14_4
  int orig_b; // ST14_4

  *d_g = 0;
  *d_b = 0;
  orig_r = *s_r;
  *s_r = 7 - *s_g;
  *s_g = orig_r;
  orig_b = *s_b;
  *s_b = 7 - *d_r;
  *d_r = orig_b;
  *x = *s_r - *s_b;
  *y = *s_g - *d_r;
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
// Partial PSX
void __fastcall DoLighting(int nXPos, int nYPos, int nRadius, int Lnum)
{
  int y; // [esp+Ch] [ebp-54h]
  int x; // [esp+10h] [ebp-50h]
  int v6; // [esp+18h] [ebp-48h]
  int radius_block; // [esp+18h] [ebp-48h] MAPDST
  int max_x2; // [esp+1Ch] [ebp-44h]
  int max_y; // [esp+20h] [ebp-40h]
  int i; // [esp+24h] [ebp-3Ch]
  int k; // [esp+24h] [ebp-3Ch]
  int m; // [esp+24h] [ebp-3Ch]
  int ii; // [esp+24h] [ebp-3Ch]
  signed int j; // [esp+28h] [ebp-38h]
  signed int l; // [esp+28h] [ebp-38h]
  signed int n; // [esp+28h] [ebp-38h]
  signed int jj; // [esp+28h] [ebp-38h]
  int max_y2; // [esp+2Ch] [ebp-34h]
  int s_g; // [esp+30h] [ebp-30h]
  int d_r; // [esp+34h] [ebp-2Ch]
  int s_b; // [esp+38h] [ebp-28h]
  int max_x; // [esp+3Ch] [ebp-24h]
  int v; // [esp+40h] [ebp-20h]
  int d_b; // [esp+44h] [ebp-1Ch]
  int d_g; // [esp+48h] [ebp-18h]
  int temp_y; // [esp+4Ch] [ebp-14h]
  int yoff; // [esp+50h] [ebp-10h]
  int s_r; // [esp+54h] [ebp-Ch]
  int xoff; // [esp+58h] [ebp-8h]
  int xyoff; // [esp+5Ch] [ebp-4h]

  y = nYPos;
  x = nXPos;
  xoff = 0;
  yoff = 0;
  s_b = 0;
  d_r = 0;
  d_g = 0;
  d_b = 0;
  if ( Lnum >= 0 )
  {
    xoff = LightList[Lnum]._xoff;
    yoff = LightList[Lnum]._yoff;
    if ( xoff < 0 )
    {
      xoff += 8;
      x = nXPos - 1;
    }
    if ( yoff < 0 )
    {
      yoff += 8;
      y = nYPos - 1;
    }
  }
  s_r = xoff;
  s_g = yoff;
  if ( x - 15 >= 0 )
    max_y = 15;
  else
    max_y = x + 1;
  if ( x + 15 <= 112 )
    max_y2 = 15;
  else
    max_y2 = 112 - x;
  if ( y - 15 >= 0 )
    max_x = 15;
  else
    max_x = y + 1;
  if ( y + 15 <= 112 )
    max_x2 = 15;
  else
    max_x2 = 112 - y;
  dTransVal[x][y] = 0;
  xyoff = xoff + 8 * yoff;
  for ( i = 0; i < max_x; ++i )
  {
    for ( j = 1; j < max_y2; ++j )
    {
      v = dung_map_rgba[0][xyoff][i][j];
      if ( v < 128 )
      {
        temp_y = y + i;
        v6 = dung_map_radius[nRadius][v];
        if ( dTransVal[j + x][y + i] > v6 )
          dTransVal[j + x][temp_y] = v6;
      }
    }
  }
  SetLightFX(&xoff, &yoff, &s_r, &s_g, &s_b, &d_r, &d_g, &d_b);
  xyoff = xoff + 8 * yoff;
  for ( k = 0; k < max_x2; ++k )
  {
    for ( l = 1; l < max_y2; ++l )
    {
      v = dung_map_rgba[0][xyoff][d_b + k][l + d_g];
      if ( v < 128 )
      {
        temp_y = y - l;
        radius_block = dung_map_radius[nRadius][v];
        if ( dTransVal[k + x][y - l] > radius_block )
          dTransVal[k + x][temp_y] = radius_block;
      }
    }
  }
  SetLightFX(&xoff, &yoff, &s_r, &s_g, &s_b, &d_r, &d_g, &d_b);
  xyoff = xoff + 8 * yoff;
  for ( m = 0; m < max_x2; ++m )
  {
    for ( n = 1; n < max_y; ++n )
    {
      v = dung_map_rgba[0][xyoff][d_b + m][n + d_g];
      if ( v < 128 )
      {
        temp_y = y - m;
        radius_block = dung_map_radius[nRadius][v];
        if ( dTransVal[x - n][y - m] > radius_block )
          dTransVal[x - n][temp_y] = radius_block;
      }
    }
  }
  SetLightFX(&xoff, &yoff, &s_r, &s_g, &s_b, &d_r, &d_g, &d_b);
  xyoff = xoff + 8 * yoff;
  for ( ii = 0; ii < max_x; ++ii )
  {
    for ( jj = 1; jj < max_y; ++jj )
    {
      v = dung_map_rgba[0][xyoff][d_b + ii][jj + d_g];
      if ( v < 128 )
      {
        temp_y = y + jj;
        radius_block = dung_map_radius[nRadius][v];
        if ( dTransVal[x - ii][y + jj] > radius_block )
          dTransVal[x - ii][temp_y] = radius_block;
      }
    }
  }
}

//----- (0043812B) --------------------------------------------------------
// PSX
void __fastcall DoUnLight(int nXPos, int nYPos, int nRadius)
{
  int max_x; // [esp+14h] [ebp-18h]
  int x; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  int j; // [esp+20h] [ebp-Ch]
  int max_y; // [esp+24h] [ebp-8h]
  int y; // [esp+28h] [ebp-4h]
  int radius; // [esp+34h] [ebp+8h]

  radius = nRadius + 1;
  x = nYPos - radius;
  max_x = radius + nYPos;
  y = nXPos - radius;
  max_y = radius + nXPos;
  if ( nYPos - radius < 0 )
    x = 0;
  if ( max_x > 112 )
    max_x = 112;
  if ( y < 0 )
    y = 0;
  if ( max_y > 112 )
    max_y = 112;
  for ( i = x; max_x > i; ++i )
  {
    for ( j = y; max_y > j; ++j )
      dTransVal[j][i] = dTransVal2[j][i];
  }
}

//----- (0043821D) --------------------------------------------------------
// PSX
void __fastcall DoUnVision(int nXPos, int nYPos, int nRadius)
{
  int y2; // [esp+14h] [ebp-18h]
  int y1; // [esp+18h] [ebp-14h]
  int j; // [esp+1Ch] [ebp-10h]
  int i; // [esp+20h] [ebp-Ch]
  int x2; // [esp+24h] [ebp-8h]
  int x1; // [esp+28h] [ebp-4h]
  int radius; // [esp+34h] [ebp+8h]

  radius = nRadius + 1;
  y1 = nYPos - radius;
  y2 = nYPos + radius;
  x1 = nXPos - radius;
  x2 = nXPos + radius;
  if ( nYPos - radius < 0 )
    y1 = 0;
  if ( y2 > 112 )
    y2 = 112;
  if ( x1 < 0 )
    x1 = 0;
  if ( x2 > 112 )
    x2 = 112;
  for ( i = x1; x2 > i; ++i )
  {
    for ( j = y1; y2 > j; ++j )
      dFlags[i][j] &= 0xBDu;
  }
}

//----- (00438312) --------------------------------------------------------
// PSX
void __fastcall DoVision(int nXPos, int nYPos, int nRadius, unsigned __int8 doautomap, int visible)
{
  int nCrawlX; // [esp+18h] [ebp-30h]
  int nBlockerFlag; // [esp+1Ch] [ebp-2Ch]
  signed int v; // [esp+20h] [ebp-28h]
  signed int i; // [esp+24h] [ebp-24h]
  signed int x2adj; // [esp+28h] [ebp-20h]
  int j; // [esp+2Ch] [ebp-1Ch]
  signed int x1adj; // [esp+30h] [ebp-18h]
  int nLineLen; // [esp+34h] [ebp-14h]
  signed int y2adj; // [esp+3Ch] [ebp-Ch]
  int nCrawlY; // [esp+40h] [ebp-8h]
  signed int y1adj; // [esp+44h] [ebp-4h]

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
  for ( v = 0; v < 4; ++v )
  {
    for ( i = 0; i < 23; ++i )
    {
      nBlockerFlag = 0;
      nLineLen = 2 * (nRadius - RadiusAdj[i]);
      for ( j = 0; j < nLineLen && !nBlockerFlag; j += 2 )
      {
        x1adj = 0;
        x2adj = 0;
        y1adj = 0;
        y2adj = 0;
        switch ( v )
        {
          case 0:
            nCrawlX = nXPos + vCrawlTable[i][j];
            nCrawlY = nYPos + vCrawlTable[i][j + 1];
            if ( (signed int)vCrawlTable[i][j] > 0 && (signed int)vCrawlTable[i][j + 1] > 0 )
            {
              x1adj = -1;
              y2adj = -1;
            }
            break;
          case 1:
            nCrawlX = nXPos - vCrawlTable[i][j];
            nCrawlY = nYPos - vCrawlTable[i][j + 1];
            if ( (signed int)vCrawlTable[i][j] > 0 && (signed int)vCrawlTable[i][j + 1] > 0 )
            {
              y1adj = 1;
              x2adj = 1;
            }
            break;
          case 2:
            nCrawlX = nXPos + vCrawlTable[i][j];
            nCrawlY = nYPos - vCrawlTable[i][j + 1];
            if ( (signed int)vCrawlTable[i][j] > 0 && (signed int)vCrawlTable[i][j + 1] > 0 )
            {
              x1adj = -1;
              y2adj = 1;
            }
            break;
          case 3:
            nCrawlX = nXPos - vCrawlTable[i][j];
            nCrawlY = nYPos + vCrawlTable[i][j + 1];
            if ( (signed int)vCrawlTable[i][j] > 0 && (signed int)vCrawlTable[i][j + 1] > 0 )
            {
              y1adj = -1;
              x2adj = 1;
            }
            break;
          default:
            break;
        }
        if ( nCrawlX >= 0 && nCrawlX <= 112 && nCrawlY >= 0 && nCrawlY <= 112 )
        {
          nBlockerFlag = (unsigned __int8)nBlockTable[dPiece[nCrawlX][nCrawlY]];
          if ( !nBlockTable[dPiece[x1adj + nCrawlX][y1adj + nCrawlY]]
            || !nBlockTable[dPiece[x2adj + nCrawlX][y2adj + nCrawlY]] )
          {
            if ( doautomap )
            {
              if ( dFlags[nCrawlX][nCrawlY] >= 0 )
                SetAutomapView(nCrawlX, nCrawlY);
              dFlags[nCrawlX][nCrawlY] |= 0x80u;
            }
            if ( visible )
              dFlags[nCrawlX][nCrawlY] |= 0x40u;
            dFlags[nCrawlX][nCrawlY] |= 2u;
            if ( !nBlockerFlag )
            {
              if ( dung_map[nCrawlX][nCrawlY] )
                TransList[dung_map[nCrawlX][nCrawlY]] = 1;
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
  mem_free_dbg(pLightTbl, 583, "LIGHTING.CPP");
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

  assert(!pLightTbl, "LIGHTING.CPP", 603);
  pLightTbl = (BYTE *)DiabloAllocPtr(6912, 604, "LIGHTING.CPP");
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
  ptr = LoadFileInMem("PlrGFX\\Infra.TRN", 0, 647, "LIGHTING.CPP");
  v30 = ptr;
  for ( kk = 0; kk < 256; ++kk )
    *pLightTbl_++ = *v30++;
  mem_free_dbg(ptr, 650, "LIGHTING.CPP");
  ptra = LoadFileInMem("PlrGFX\\Stone.TRN", 0, 653, "LIGHTING.CPP");
  v31 = ptra;
  for ( ll = 0; ll < 256; ++ll )
    *pLightTbl_++ = *v31++;
  mem_free_dbg(ptra, 656, "LIGHTING.CPP");
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
// PSX
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
// PSX
int __fastcall AddLight(int x, int y, int r)
{
  int lid; // [esp+14h] [ebp-4h]

  if ( lightflag )
    return -1;
  lid = -1;
  if ( numlights < 32 )
  {
    lid = lightactive[numlights++];
    LightList[lid]._lx = x;
    LightList[lid]._ly = y;
    LightList[lid]._lradius = r;
    LightList[lid]._xoff = 0;
    LightList[lid]._yoff = 0;
    LightList[lid]._ldel = 0;
    LightList[lid]._lunflag = 0;
    dolighting = 1;
  }
  return lid;
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
// PSX
void __cdecl ProcessLightList()
{
  BYTE temp_; // ST1C_1
  int i; // [esp+Ch] [ebp-Ch] MAPDST
  int j; // [esp+Ch] [ebp-Ch]
  int temp; // [esp+10h] [ebp-8h] MAPDST

  if ( !lightflag )
  {
    if ( dolighting )
    {
      for ( i = 0; i < numlights; ++i )
      {
        temp = lightactive[i];
        if ( LightList[temp]._ldel )
          DoUnLight(LightList[temp]._lx, LightList[temp]._ly, LightList[temp]._lradius);
        if ( LightList[temp]._lunflag )
        {
          DoUnLight(LightList[temp]._lunx, LightList[temp]._luny, LightList[temp]._lunr);
          LightList[temp]._lunflag = 0;
        }
      }
      for ( i = 0; i < numlights; ++i )
      {
        temp = lightactive[i];
        if ( !LightList[temp]._ldel )
          DoLighting(LightList[temp]._lx, LightList[temp]._ly, LightList[temp]._lradius, temp);
      }
      j = 0;
      while ( j < numlights )
      {
        if ( LightList[lightactive[j]]._ldel )
        {
          temp_ = lightactive[--numlights];
          lightactive[numlights] = lightactive[j];
          lightactive[j] = temp_;
        }
        else
        {
          ++j;
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
// PSX
int __fastcall AddVision(int x, int y, int r, bool mine)
{
  int vid; // [esp+14h] [ebp-4h]

  if ( numvision < 32 )
  {
    VisionList[numvision]._lx = x;
    VisionList[numvision]._ly = y;
    VisionList[numvision]._lradius = r;
    vid = visionid++;
    VisionList[numvision]._lid = vid;
    VisionList[numvision]._ldel = 0;
    VisionList[numvision]._lunflag = 0;
    VisionList[numvision++]._lflags = mine != 0;
    dovision = 1;
  }
  return vid;
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
// PSX
void __cdecl ProcessVisionList()
{
  int i; // [esp+Ch] [ebp-8h] MAPDST
  signed int delflag; // [esp+10h] [ebp-4h]

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
    for ( i = 0; TransVal > i; ++i )
      TransList[i] = 0;
    for ( i = 0; i < numvision; ++i )
    {
      if ( !VisionList[i]._ldel )
        DoVision(
          VisionList[i]._lx,
          VisionList[i]._ly,
          VisionList[i]._lradius,
          VisionList[i]._lflags & 1,
          VisionList[i]._lflags & 1);
    }
    do
    {
      delflag = 0;
      for ( i = 0; i < numvision; ++i )
      {
        if ( VisionList[i]._ldel )
        {
          if ( --numvision > 0 && i != numvision )
            qmemcpy(&VisionList[i], &VisionList[numvision], sizeof(LightListStruct));
          delflag = 1;
        }
      }
    }
    while ( delflag );
  }
  dovision = 0;
}

