//----- (00482730) --------------------------------------------------------
BOOL __cdecl TFit_Barrel()
{
  return 1;
}

//----- (00482804) --------------------------------------------------------
BOOL __fastcall TFit_Shrine(int i)
{
  signed int v2; // [esp+10h] [ebp-Ch]
  int v3; // [esp+14h] [ebp-8h]
  int v4; // [esp+18h] [ebp-4h]

  v4 = 0;
  v3 = 0;
  v2 = 0;
  while ( !v2 )
  {
    if ( dung_map[v4][v3] == themes[i].ttval )
    {
      if ( nTrapTable[dPiece[v4][v3 - 1]]
        && !nSolidTable[dPiece[v4 - 1][v3]]
        && !nSolidTable[dPiece[v4 + 1][v3]]
        && dung_map[v4 - 1][v3] == themes[i].ttval
        && dung_map[v4 + 1][v3] == themes[i].ttval
        && !dObject[v4 - 1 - 1][v3 + 111]
        && !dObject[v4 + 1 - 1][v3 + 111] )
      {
        v2 = 1;
      }
      if ( !v2
        && nTrapTable[dPiece[v4 - 1][v3]]
        && !nSolidTable[dPiece[v4][v3 - 1]]
        && !nSolidTable[dPiece[v4][v3 + 1]]
        && dung_map[v4][v3 - 1] == themes[i].ttval
        && dung_map[v4][v3 + 1] == themes[i].ttval
        && !dObject[v4 - 1 - 1][v3 + 111]
        && !dObject[v4 - 1][v3 + 1] )
      {
        v2 = 2;
      }
    }
    if ( !v2 && ++v4 == 112 )
    {
      v4 = 0;
      if ( ++v3 == 112 )
        return 0;
    }
  }
  themex = v4;
  themey = v3;
  themeVar1 = v2;
  return 1;
}

//----- (00482AE0) --------------------------------------------------------
BOOL __fastcall TFit_Obj5(int t)
{
  int v1; // eax
  signed int v4; // [esp+10h] [ebp-18h]
  int v5; // [esp+14h] [ebp-14h]
  signed int i; // [esp+18h] [ebp-10h]
  int v7; // [esp+1Ch] [ebp-Ch]
  int v8; // [esp+20h] [ebp-8h]

  v7 = 0;
  v5 = 0;
  v1 = random(0, 5);
  v8 = v1 + 1;
  while ( v8 > 0 )
  {
    v4 = 0;
    if ( dung_map[v7][v5] == themes[t].ttval && !nSolidTable[dPiece[v7][v5]] )
    {
      v4 = 1;
      for ( i = 0; v4 && i < 25; ++i )
      {
        if ( nSolidTable[dPiece[v7 + trm5x[i]][v5 + trm5y[i]]] )
          v4 = 0;
        if ( dung_map[v7 + trm5x[i]][v5 + trm5y[i]] != themes[t].ttval )
          v4 = 0;
      }
    }
    if ( v4 )
    {
      --v8;
    }
    else if ( ++v7 == 112 )
    {
      v7 = 0;
      if ( ++v5 == 112 )
      {
        if ( v1 + 1 == v8 )
          return 0;
        v5 = 0;
      }
    }
  }
  themex = v7;
  themey = v5;
  return 1;
}

//----- (00482C9A) --------------------------------------------------------
BOOL __fastcall TFit_SkelRoom(int t)
{
  int i; // [esp+10h] [ebp-4h]

  for ( i = 0; i < nummtypes; ++i )
  {
    if ( IsSkel(Monsters[i].mtype) )
    {
      themeVar1 = i;
      return TFit_Obj5(t);
    }
  }
  return 0;
}

//----- (00482D0C) --------------------------------------------------------
BOOL __fastcall SpecialThemeFit(int i, int t)
{
  BOOL v3; // [esp+18h] [ebp-4h]

  v3 = 1;
  switch ( t )
  {
    case 0:
      v3 = TFit_Barrel();
      break;
    case 1:
    case 5:
      v3 = TFit_Shrine(i);
      break;
    case 3:
      v3 = TFit_SkelRoom(i);
      break;
    case 7:
      v3 = TFit_Obj5(i);
      break;
    case 9:
      v3 = leveltype == 2;
      break;
    default:
      return v3;
  }
  return v3;
}

//----- (00482DE3) --------------------------------------------------------
BOOL __fastcall CheckThemeRoom(int tv)
{
  signed int v2; // [esp+10h] [ebp-Ch]
  signed int i; // [esp+14h] [ebp-8h]
  signed int k; // [esp+14h] [ebp-8h]
  signed int j; // [esp+18h] [ebp-4h]
  signed int l; // [esp+18h] [ebp-4h]

  if ( dung_map[ViewX][ViewY] == tv )
    return 0;
  v2 = 0;
  for ( i = 0; i < 112; ++i )
  {
    for ( j = 0; j < 112; ++j )
    {
      if ( dung_map[j][i] == tv )
      {
        if ( dFlags[j][i] & 8 )
          return 0;
        ++v2;
      }
    }
  }
  if ( leveltype == 1 && (v2 < 9 || v2 > 100) )
    return 0;
  if ( leveltype == 2 && (v2 < 9 || v2 > 144) )
    return 0;
  for ( k = 0; k < 112; ++k )
  {
    for ( l = 0; l < 112; ++l )
    {
      if ( dung_map[l][k] == tv && !nSolidTable[dPiece[l][k]] )
      {
        if ( dung_map[l - 1][k] != tv && !nSolidTable[dPiece[l - 1][k]] )
          return 0;
        if ( dung_map[l + 1][k] != tv && !nSolidTable[dPiece[l + 1][k]] )
          return 0;
        if ( dung_map[l][k - 1] != tv && !nSolidTable[dPiece[l][k - 1]] )
          return 0;
        if ( dung_map[l][k + 1] != tv && !nSolidTable[dPiece[l][k + 1]] )
          return 0;
      }
    }
  }
  return 1;
}

//----- (004830D6) --------------------------------------------------------
void __cdecl InitThemes()
{
  BOOL i; // eax
  signed int tv; // [esp+Ch] [ebp-8h]
  int tva; // [esp+Ch] [ebp-8h]
  int tvb; // [esp+Ch] [ebp-8h]
  int t; // [esp+10h] [ebp-4h]

  numthemes = 0;
  if ( leveltype == 1 || leveltype == 2 )
  {
    for ( tv = 0; tv < 3; ++tv )
      ThemeGoodIn[tv] = 0;
    for ( tva = 0; tva < 256 && numthemes < 50; ++tva )
    {
      if ( CheckThemeRoom(tva) )
      {
        themes[numthemes].ttval = tva;
        t = ThemeGood[random(0, 3)];
        for ( i = SpecialThemeFit(numthemes, t); !i; i = SpecialThemeFit(numthemes, t) )
          t = random(0, 10);
        themes[numthemes++].ttype = t;
      }
    }
  }
  if ( leveltype == 2 )
  {
    for ( tvb = 0; tvb < themeCount; ++tvb )
    {
      themes[tvb].ttval = themeLoc[tvb].ttval;
      themes[tvb].ttype = 9;
    }
    numthemes += themeCount;
  }
}

//----- (00483242) --------------------------------------------------------
void __cdecl HoldThemeRooms()
{
  int v0; // ST0C_4
  int v1; // ST20_4
  char v2; // [esp+10h] [ebp-14h]
  int i; // [esp+14h] [ebp-10h]
  int l; // [esp+14h] [ebp-10h]
  signed int j; // [esp+18h] [ebp-Ch]
  int m; // [esp+18h] [ebp-Ch]
  signed int k; // [esp+1Ch] [ebp-8h]
  int n; // [esp+1Ch] [ebp-8h]

  for ( i = 0; i < numthemes; ++i )
  {
    v2 = themes[i].ttval;
    for ( j = 0; j < 112; ++j )
    {
      for ( k = 0; k < 112; ++k )
      {
        if ( dung_map[k][j] == v2 )
          dFlags[k][j] |= 8u;
      }
    }
  }
  if ( leveltype == 2 && themeCount > 0 )       // This is extracted to DRLG_HoldThemeRooms in 1.09
  {
    for ( l = 0; l < themeCount; ++l )
    {
      for ( m = themeLoc[l].y; themeLoc[l].height + themeLoc[l].y >= m; ++m )
      {
        for ( n = themeLoc[l].x; themeLoc[l].x + themeLoc[l].width >= n; ++n )
        {
          v0 = 2 * n + 16;
          v1 = 2 * m + 16;
          dFlags[v0][v1] |= 8u;
          dFlags[v0 + 1][v1] |= 8u;
          dFlags[v0][v1 + 1] |= 8u;
          dFlags[2 * n + 17][v1 + 1] |= 8u;
        }
      }
    }
  }
}

//----- (004834B2) --------------------------------------------------------
BOOL __fastcall CheckThemeObj3(int xp, int yp, int t, int f)
{
  signed int i; // [esp+14h] [ebp-4h]

  for ( i = 0; i < 9; ++i )
  {
    if ( xp + trm3x[i] < 0 || yp + trm3y[i] < 0 )
      return 0;
    if ( nSolidTable[dPiece[xp + trm3x[i]][yp + trm3y[i]]] )
      return 0;
    if ( dung_map[xp + trm3x[i]][yp + trm3y[i]] != themes[t].ttval )
      return 0;
    if ( dObject[xp + trm3x[i]][yp + trm3y[i]] )
      return 0;
    if ( f != -1 && !random(0, f) )
      return 0;
  }
  return 1;
}

//----- (00483600) --------------------------------------------------------
void __fastcall PlaceThemeMonsts(int t, int f)
{
  int v2; // eax
  int mtype; // [esp+14h] [ebp-1CCh]
  int y; // [esp+18h] [ebp-1C8h]
  int i; // [esp+1Ch] [ebp-1C4h]
  int x; // [esp+20h] [ebp-1C0h]
  int v9[110]; // [esp+24h] [ebp-1BCh]
  int v; // [esp+1DCh] [ebp-4h]

  v = 0;
  for ( i = 0; nummtypes > i; ++i )
  {
    if ( Monsters[i].mPlaceFlags & 1 )
      v9[v++] = i;
  }
  mtype = v9[random(0, v)];
  for ( y = 0; y < 112; ++y )
  {
    for ( x = 0; x < 112; ++x )
    {
      if ( dung_map[x][y] == themes[t].ttval
        && !nSolidTable[dPiece[x][y]]
        && !dItem[x][y]
        && !dObject[x][y]
        && !random(0, f) )
      {
        v2 = random(0, 8);
        AddMonster(x, y, v2, mtype, 1);
      }
    }
  }
}

//----- (004837D5) --------------------------------------------------------
void __fastcall Theme_Barrel(int t)
{
  int oy; // [esp+10h] [ebp-Ch]
  int ox; // [esp+14h] [ebp-8h]
  _object_id ot; // [esp+18h] [ebp-4h]

  for ( oy = 0; oy < 112; ++oy )
  {
    for ( ox = 0; ox < 112; ++ox )
    {
      if ( dung_map[ox][oy] == themes[t].ttval && !nSolidTable[dPiece[ox][oy]] && random(0, 3) )
      {
        if ( random(0, 3) )
          ot = OBJ_BARREL;
        else
          ot = OBJ_BARRELEX;
        AddObject(ot, ox, oy);
      }
    }
  }
}

//----- (004838C0) --------------------------------------------------------
void __fastcall Theme_Shrine(int t)
{
  TFit_Shrine(t);
  if ( themeVar1 == 1 )
  {
    AddObject(OBJ_CANDLE2, themex - 1, themey);
    AddObject(OBJ_SHRINER, themex, themey);
    AddObject(OBJ_CANDLE2, themex + 1, themey);
  }
  else
  {
    AddObject(OBJ_CANDLE2, themex, themey - 1);
    AddObject(OBJ_SHRINEL, themex, themey);
    AddObject(OBJ_CANDLE2, themex, themey + 1);
  }
  PlaceThemeMonsts(t, 5);
}

//----- (00483985) --------------------------------------------------------
void __fastcall Theme_MonstPit(int t)
{
  int v1; // ST24_4
  int y; // [esp+10h] [ebp-Ch]
  int x; // [esp+14h] [ebp-8h]
  int v5; // [esp+18h] [ebp-4h]

  v5 = random(0, 100);
  x = 0;
  y = 0;
  while ( v5 > 0 )
  {
    if ( dung_map[x][y] == themes[t].ttval && !nSolidTable[dPiece[x][y]] )
      --v5;
    if ( v5 > 0 && ++x == 112 )
    {
      x = 0;
      if ( ++y == 112 )
        y = 0;
    }
  }
  CreateRndItem(x, y, 1u, 0, 1);
  v1 = itemactive[numitems - 1];
  item[v1]._iAnimFrame = item[v1]._iAnimLen;
  item[v1]._iAnimFlag = 0;
  item[v1]._iSelFlag = 1;
  PlaceThemeMonsts(t, 2);
}

//----- (00483ACD) --------------------------------------------------------
void __fastcall Theme_SkelRoom(int t)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int ii; // ST20_4
  int v5; // ST20_4
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int oy; // [esp+14h] [ebp-Ch]
  int ox; // [esp+18h] [ebp-8h]

  TFit_SkelRoom(t);
  ox = themex;
  oy = themey;
  AddObject(OBJ_SKFIRE, themex, themey);
  if ( random(0, 4) )
  {
    v1 = PreSpawnSkeleton();
    SpawnSkeleton(v1, ox - 1, oy - 1);
  }
  else
  {
    AddObject(OBJ_BANNERL, ox - 1, oy - 1);
  }
  v2 = PreSpawnSkeleton();
  SpawnSkeleton(v2, ox, oy - 1);
  if ( random(0, 4) )
  {
    v3 = PreSpawnSkeleton();
    SpawnSkeleton(v3, ox + 1, oy - 1);
  }
  else
  {
    AddObject(OBJ_BANNERR, ox + 1, oy - 1);
  }
  if ( random(0, 4) )
  {
    ii = PreSpawnSkeleton();
    SpawnSkeleton(ii, ox - 1, oy);
  }
  else
  {
    AddObject(OBJ_BANNERM, ox - 1, oy);
  }
  if ( random(0, 4) )
  {
    v5 = PreSpawnSkeleton();
    SpawnSkeleton(v5, ox + 1, oy);
  }
  else
  {
    AddObject(OBJ_BANNERM, ox + 1, oy);
  }
  if ( random(0, 4) )
  {
    v6 = PreSpawnSkeleton();
    SpawnSkeleton(v6, ox - 1, oy + 1);
  }
  else
  {
    AddObject(OBJ_BANNERR, ox - 1, oy + 1);
  }
  v7 = PreSpawnSkeleton();
  SpawnSkeleton(v7, ox, oy + 1);
  if ( random(0, 4) )
  {
    v8 = PreSpawnSkeleton();
    SpawnSkeleton(v8, ox + 1, oy + 1);
  }
  else
  {
    AddObject(OBJ_BANNERL, ox + 1, oy + 1);
  }
  if ( !dungeon[39][112 * ox + 37 + oy] )
    AddObject(OBJ_SKELBOOK, ox, oy - 2);
  if ( !dObject[ox][oy + 3] )
    AddObject(OBJ_SKELBOOK, ox, oy + 2);
}

//----- (00483D46) --------------------------------------------------------
void __fastcall Theme_Treasure(int t)
{
  int v1; // edx
  int y; // [esp+10h] [ebp-10h]
  int x; // [esp+18h] [ebp-8h]

  GetRndSeed();
  for ( y = 0; y < 112; ++y )
  {
    for ( x = 0; x < 112; ++x )
    {
      if ( dung_map[x][y] == themes[t].ttval && !nSolidTable[dPiece[x][y]] )
      {
        if ( random(0, 4) )
          CreateTypeItem(x, y, 0, 11, 0, 0, 1);
        else
          CreateRndItem(x, y, 0, 0, 1);
        v1 = itemactive[numitems - 1];
        item[v1]._iAnimFrame = item[v1]._iAnimLen;
        item[v1]._iAnimFlag = 0;
        item[v1]._iSelFlag = 1;
      }
    }
  }
  PlaceThemeMonsts(t, 0);
}

//----- (00483E9C) --------------------------------------------------------
void __fastcall Theme_Library(int t)
{
  int v1; // ST1C_4
  int yp; // [esp+10h] [ebp-Ch]
  int xp; // [esp+18h] [ebp-4h]

  TFit_Shrine(t);
  if ( themeVar1 == 1 )
  {
    AddObject(OBJ_BOOKCANDLE, themex - 1, themey);
    AddObject(OBJ_BOOKCASER, themex, themey);
    AddObject(OBJ_BOOKCANDLE, themex + 1, themey);
  }
  else
  {
    AddObject(OBJ_BOOKCANDLE, themex, themey - 1);
    AddObject(OBJ_BOOKCASEL, themex, themey);
    AddObject(OBJ_BOOKCANDLE, themex, themey + 1);
  }
  for ( yp = 1; yp < 111; ++yp )
  {
    for ( xp = 1; xp < 111; ++xp )
    {
      if ( CheckThemeObj3(xp, yp, t, -1) )
      {
        AddObject(OBJ_BOOKSTAND, xp, yp);
        if ( random(0, 2) )
        {
          v1 = dObject[xp][yp] - 1;
          object[v1]._oSelFlag = 0;
          object[v1]._oAnimFrame += 2;
        }
      }
    }
  }
  PlaceThemeMonsts(t, 6);
}

//----- (00484019) --------------------------------------------------------
void __fastcall Theme_Torture(int t)
{
  int v1; // eax
  int yp; // [esp+10h] [ebp-Ch]
  int xp; // [esp+14h] [ebp-8h]
  int v5; // [esp+18h] [ebp-4h]

  v5 = 0;
  while ( !v5 )
  {
    for ( yp = 1; yp < 111; ++yp )
    {
      for ( xp = 1; xp < 111; ++xp )
      {
        if ( CheckThemeObj3(xp, yp, t, 5) )
        {
          v1 = random(0, 6);
          AddObject((_object_id)(v1 + OBJ_TNUDEM2), xp, yp);
          ++v5;
        }
      }
    }
  }
  PlaceThemeMonsts(t, 6);
}

//----- (004840C5) --------------------------------------------------------
void __fastcall Theme_BloodFountain(int t)
{
  TFit_Obj5(t);
  AddObject(OBJ_BLOODFTN, themex, themey);
  PlaceThemeMonsts(t, 8);
}

//----- (00484106) --------------------------------------------------------
void __fastcall Theme_Decap(int t)
{
  int yp; // [esp+10h] [ebp-Ch]
  int xp; // [esp+14h] [ebp-8h]
  int v4; // [esp+18h] [ebp-4h]

  v4 = 0;
  while ( !v4 )
  {
    for ( yp = 1; yp < 111; ++yp )
    {
      for ( xp = 1; xp < 111; ++xp )
      {
        if ( CheckThemeObj3(xp, yp, t, 5) )
        {
          AddObject(OBJ_DECAP, xp, yp);
          ++v4;
        }
      }
    }
  }
  PlaceThemeMonsts(t, 6);
}

//----- (004841A8) --------------------------------------------------------
void __fastcall Theme_PurifyingFountain(int t)
{
  int v1; // edx
  int v2; // [esp+Ch] [ebp-1Ch]
  int oy; // [esp+14h] [ebp-14h]
  int oya; // [esp+14h] [ebp-14h]
  int ox; // [esp+1Ch] [ebp-Ch]
  int oxa; // [esp+1Ch] [ebp-Ch]
  int v8; // [esp+20h] [ebp-8h]
  int v9; // [esp+24h] [ebp-4h]

  ox = 2 * themeLoc[t].x + 17;
  oy = 2 * themeLoc[t].y + 17;
  v9 = 2 * (themeLoc[t].width + themeLoc[t].x) - 2 + 17;
  v8 = 2 * (themeLoc[t].height + themeLoc[t].y) - 2 + 15;
  v2 = random(t, 3);
  if ( v2 )
  {
    if ( v2 == 1 )
    {
      if ( random(t, 2) )
      {
        AddObject(OBJ_L3LDOOR, ox, (v8 - oy) / 2 + oy - 1);
        AddObject(OBJ_ARMORSTANDN, ox, (v8 - oy) / 2 + oy);
        AddObject(OBJ_L3LDOOR, ox, (v8 - oy) / 2 + oy + 1);
      }
      else
      {
        AddObject(OBJ_L3LDOOR, ox + (v9 - ox) / 2 - 1, oy);
        AddObject(OBJ_ARMORSTAND, (v9 - ox) / 2 + ox, oy);
        AddObject(OBJ_L3LDOOR, ox + (v9 - ox) / 2 + 1, oy);
      }
      PlaceThemeMonsts(t, 6);
    }
    else if ( v2 == 2 )
    {
      PlaceThemeMonsts(t, 6);
      for ( oya = 0; oya < 112; ++oya )
      {
        for ( oxa = 0; oxa < 112; ++oxa )
        {
          if ( dung_map[oxa][oya] == themes[t].ttval && !nSolidTable[dPiece[oxa][oya]] )
          {
            if ( random(0, 4) )
              CreateTypeItem(oxa, oya, 0, 11, 0, 0, 1);
            else
              CreateRndItem(oxa, oya, 0, 0, 1);
            v1 = itemactive[numitems - 1];
            item[v1]._iAnimFrame = item[v1]._iAnimLen;
            item[v1]._iAnimFlag = 0;
            item[v1]._iSelFlag = 1;
          }
        }
      }
    }
  }
  else
  {
    if ( random(t, 2) )
    {
      AddObject(OBJ_L3LDOOR, ox, (v8 - oy) / 2 + oy - 1);
      AddObject(OBJ_PURIFYINGFTN, ox, (v8 - oy) / 2 + oy);
      AddObject(OBJ_L3LDOOR, ox, (v8 - oy) / 2 + oy + 1);
    }
    else
    {
      AddObject(OBJ_L3LDOOR, ox + (v9 - ox) / 2 - 1, oy);
      AddObject(OBJ_L3RDOOR, (v9 - ox) / 2 + ox, oy);
      AddObject(OBJ_L3LDOOR, ox + (v9 - ox) / 2 + 1, oy);
    }
    PlaceThemeMonsts(t, 6);
  }
}

//----- (0048457F) --------------------------------------------------------
void __cdecl CreateThemeRooms()
{
  int t; // [esp+10h] [ebp-4h]

  InitObjFlag = 1;
  for ( t = 0; numthemes > t; ++t )
  {
    switch ( themes[t].ttype )
    {
      case 0:
        Theme_Barrel(t);
        break;
      case 1:
        Theme_Shrine(t);
        break;
      case 2:
        Theme_MonstPit(t);
        break;
      case 3:
        Theme_SkelRoom(t);
        break;
      case 4:
        Theme_Treasure(t);
        break;
      case 5:
        Theme_Library(t);
        break;
      case 6:
        Theme_Torture(t);
        break;
      case 7:
        Theme_BloodFountain(t);
        break;
      case 8:
        Theme_Decap(t);
        break;
      case 9:
        Theme_PurifyingFountain(t);
        break;
      default:
        continue;
    }
  }
  InitObjFlag = 0;
}

