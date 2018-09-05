//----- (0044A530) --------------------------------------------------------
void __fastcall town_clear_upper_buf(int a1)
{
  unsigned int v1; // edi
  signed int v2; // edx
  signed int v3; // ebx
  char *v4; // edi
  signed int v5; // edx
  signed int v6; // ebx
  char *v7; // edi

  v1 = a1;
  v2 = 30;
  v3 = 1;
  while ( v1 >= screen_buf_end )
  {
    v4 = (char *)(v2 + v1);
    memset(v4, 0, 4 * v3);
    v1 = (unsigned int)&v4[4 * v3 - 832 + v2];
    if ( !v2 )
    {
      v5 = 2;
      v6 = 15;
      do
      {
        if ( v1 < screen_buf_end )
          break;
        v7 = (char *)(v5 + v1);
        memset(v7, 0, 4 * v6);
        v1 = (unsigned int)&v7[4 * v6-- - 832 + v5];
        v5 += 2;
      }
      while ( v5 != 32 );
      return;
    }
    v2 -= 2;
    ++v3;
  }
}

//----- (0044A5B2) --------------------------------------------------------
void __fastcall town_clear_low_buf(int y_related)
{
  unsigned int v1; // edi
  signed int v2; // edx
  signed int i; // ebx
  int v4; // edi
  char *v5; // edi
  signed int v6; // edx
  signed int v7; // ebx
  int v8; // edi
  char *v9; // edi

  v1 = y_related;
  v2 = 30;
  for ( i = 1; ; ++i )
  {
    if ( v1 < screen_buf_end )
    {
      v5 = (char *)(v2 + v1);
      memset(v5, 0, 4 * i);
      v4 = (int)&v5[4 * i + v2];
    }
    else
    {
      v4 = v1 + 64;
    }
    v1 = v4 - 832;
    if ( !v2 )
      break;
    v2 -= 2;
  }
  v6 = 2;
  v7 = 15;
  do
  {
    if ( v1 < screen_buf_end )
    {
      v9 = (char *)(v6 + v1);
      memset(v9, 0, 4 * v7);
      v8 = (int)&v9[4 * v7 + v6];
    }
    else
    {
      v8 = v1 + 64;
    }
    v1 = v8 - 832;
    --v7;
    v6 += 2;
  }
  while ( v6 != 32 );
}

//----- (0044A643) --------------------------------------------------------
void __fastcall town_44A643(int a1, int a2)
{
  ;
}

//----- (0044A6F5) --------------------------------------------------------
void __fastcall town_44A6F5(int a1, int a2)
{
  ;
}

//----- (0044A79F) --------------------------------------------------------
void __fastcall town_draw_clipped_e_flag(void *buffer, int x, int y, int sx, int sy)
{
  char *v7; // [esp+14h] [ebp-Ch]
  char *a1; // [esp+18h] [ebp-8h]
  signed int i; // [esp+1Ch] [ebp-4h]

  a1 = (char *)buffer;
  v7 = (char *)dpiece_defs_map_1 + 32 * gendung_get_dpiece_num_from_coord(x, y);
  for ( i = 0; i < 12; i += 2 )
  {
    level_cel_block = *(_WORD *)&v7[2 * i];
    if ( level_cel_block )
      drawLowerScreen(a1);
    level_cel_block = *(_WORD *)&v7[2 * i + 2];
    if ( level_cel_block )
      drawLowerScreen(a1 + 32);
    a1 -= 24576;
  }
  town_draw_clipped_town(buffer, x, y, sx, sy, 0);
}

//----- (0044A869) --------------------------------------------------------
void __fastcall town_draw_clipped_town(void *unused, int x, int y, int sx, int sy, int some_flag)
{
  char *v7; // [esp+10h] [ebp-14h]
  int screen_x; // [esp+14h] [ebp-10h]
  int screen_xa; // [esp+14h] [ebp-10h]
  int screen_xb; // [esp+14h] [ebp-10h]
  int screen_xc; // [esp+14h] [ebp-10h]
  int screen_xd; // [esp+14h] [ebp-10h]
  int screen_y; // [esp+18h] [ebp-Ch]
  int screen_ya; // [esp+18h] [ebp-Ch]
  char v15; // [esp+1Ch] [ebp-8h]
  char v16; // [esp+1Ch] [ebp-8h]
  char v17; // [esp+1Ch] [ebp-8h]
  int v18; // [esp+20h] [ebp-4h]
  int v19; // [esp+20h] [ebp-4h]

  v7 = &gpBuffer[sx + screen_y_times_768[sy]];
  if ( dItem[x][y] )
  {
    v15 = dItem[x][y] - 1;
    screen_x = sx - item[v15]._iAnimWidth2;
    if ( pcursitem == v15 )
      CelDrawHdrClrHL(
        181,
        screen_x,
        sy,
        (char *)item[v15]._iAnimData,
        item[v15]._iAnimFrame,
        item[v15]._iAnimWidth,
        0,
        8);
    Cel2DrawHdrOnly(screen_x, sy, (char *)item[v15]._iAnimData, item[v15]._iAnimFrame, item[v15]._iAnimWidth, 0, 8);
  }
  if ( dFlags[x][y] & 0x10 )
  {
    v18 = -(dMonster[x][y - 1] + 1);
    screen_xa = sx - towner[-(dMonster[x][y - 1] + 1)]._tAnimWidth2;
    if ( pcursmonst == v18 )
      CelDrawHdrClrHL(
        166,
        screen_xa,
        sy,
        (char *)towner[-(dMonster[x][y - 1] + 1)]._tAnimData,
        towner[-(dMonster[x][y - 1] + 1)]._tAnimFrame,
        towner[-(dMonster[x][y - 1] + 1)]._tAnimWidth,
        0,
        8);
    Cel2DrawHdrOnly(
      screen_xa,
      sy,
      (char *)towner[v18]._tAnimData,
      towner[v18]._tAnimFrame,
      towner[v18]._tAnimWidth,
      0,
      8);
  }
  if ( dMonster[x][y] > 0 )
  {
    v19 = dMonster[x][y] - 1;
    screen_xb = sx - towner[v19]._tAnimWidth2;
    if ( pcursmonst == v19 )
      CelDrawHdrClrHL(
        166,
        screen_xb,
        sy,
        (char *)towner[v19]._tAnimData,
        towner[v19]._tAnimFrame,
        towner[v19]._tAnimWidth,
        0,
        8);
    Cel2DrawHdrOnly(
      screen_xb,
      sy,
      (char *)towner[v19]._tAnimData,
      towner[v19]._tAnimFrame,
      towner[v19]._tAnimWidth,
      0,
      8);
  }
  if ( dFlags[x][y] & 0x20 )
  {
    v16 = -(char)(dPlayer[x][y - 1] + 1);
    screen_xc = sx + plr[v16]._pxoff - plr[v16]._pAnimWidth2;
    screen_y = sy + plr[v16]._pyoff;
    if ( v16 == pcursplr )
      CelDrawHdrClrHL(
        165,
        screen_xc,
        screen_y,
        (char *)plr[v16]._pAnimData,
        plr[v16]._pAnimFrame,
        plr[v16]._pAnimWidth,
        0,
        8);
    Cel2DrawHdrOnly(screen_xc, screen_y, (char *)plr[v16]._pAnimData, plr[v16]._pAnimFrame, plr[v16]._pAnimWidth, 0, 8);
    if ( some_flag && plr[v16]._peflag )
      town_draw_clipped_e_flag(v7 - 64, x - 1, y + 1, sx - 64, sy);
  }
  if ( dPlayer[x][y] > 0 )
  {
    v17 = dPlayer[x][y] - 1;
    screen_xd = sx + plr[v17]._pxoff - plr[v17]._pAnimWidth2;
    screen_ya = sy + plr[v17]._pyoff;
    if ( v17 == pcursplr )
      CelDrawHdrClrHL(
        165,
        screen_xd,
        screen_ya,
        (char *)plr[v17]._pAnimData,
        plr[v17]._pAnimFrame,
        plr[v17]._pAnimWidth,
        0,
        8);
    Cel2DrawHdrOnly(screen_xd, screen_ya, (char *)plr[v17]._pAnimData, plr[v17]._pAnimFrame, plr[v17]._pAnimWidth, 0, 8);
    if ( some_flag && plr[v17]._peflag )
      town_draw_clipped_e_flag(v7 - 64, x - 1, y + 1, sx - 64, sy);
  }
  if ( dFlags[x][y] & 1 )
    DrawClippedMissile(x, y, sx, sy, 0, 8, 0);
  if ( dArch[x][y] )
    town_44A643((int)v7, dArch[x][y]);
}

//----- (0044B001) --------------------------------------------------------
void __fastcall town_draw_lower(int x, int y, int sx, int sy, int a5, int some_flag)
{
  signed int ya; // [esp+Ch] [ebp-18h]
  signed int xa; // [esp+10h] [ebp-14h]
  char *v8; // [esp+14h] [ebp-10h]
  char *v9; // [esp+14h] [ebp-10h]
  char *v10; // [esp+14h] [ebp-10h]
  char *a1; // [esp+18h] [ebp-Ch]
  char *a1a; // [esp+18h] [ebp-Ch]
  char *a1b; // [esp+18h] [ebp-Ch]
  int j; // [esp+1Ch] [ebp-8h]
  signed int i; // [esp+20h] [ebp-4h]
  signed int k; // [esp+20h] [ebp-4h]
  signed int l; // [esp+20h] [ebp-4h]
  int a5a; // [esp+34h] [ebp+10h]

  ya = y;
  xa = x;
  if ( some_flag )
  {
    if ( y < 0 || y >= 112 || x < 0 || x >= 112 )
    {
      town_clear_low_buf((int)&gpBuffer[sx + screen_y_times_768[sy]]);
    }
    else
    {
      level_cel_block = dPiece[x][y];
      if ( level_cel_block )
      {
        a1 = &gpBuffer[sx + 32 + screen_y_times_768[sy]];
        v8 = (char *)dpiece_defs_map_1 + 32 * gendung_get_dpiece_num_from_coord(x, y);
        for ( i = 1; i < 17; i += 2 )
        {
          level_cel_block = *(_WORD *)&v8[2 * i];
          if ( level_cel_block )
            drawLowerScreen(a1);
          a1 -= 24576;
        }
        town_draw_clipped_town(&gpBuffer[sx + screen_y_times_768[sy]], xa, ya, sx, sy, 0);
      }
      else
      {
        town_clear_low_buf((int)&gpBuffer[sx + screen_y_times_768[sy]]);
      }
    }
    ++xa;
    --ya;
    sx += 64;
  }
  a5a = a5 - some_flag;
  for ( j = 0; j < a5a; ++j )
  {
    if ( ya < 0 || ya >= 112 || xa < 0 || xa >= 112 )
    {
      town_clear_low_buf((int)&gpBuffer[sx + screen_y_times_768[sy]]);
    }
    else
    {
      level_cel_block = dPiece[xa][ya];
      if ( level_cel_block )
      {
        a1a = &gpBuffer[sx + screen_y_times_768[sy]];
        v9 = (char *)dpiece_defs_map_1 + 32 * gendung_get_dpiece_num_from_coord(xa, ya);
        for ( k = 0; k < 16; k += 2 )
        {
          level_cel_block = *(_WORD *)&v9[2 * k];
          if ( level_cel_block )
            drawLowerScreen(a1a);
          level_cel_block = *(_WORD *)&v9[2 * k + 2];
          if ( level_cel_block )
            drawLowerScreen(a1a + 32);
          a1a -= 24576;
        }
        town_draw_clipped_town(&gpBuffer[sx + screen_y_times_768[sy]], xa, ya, sx, sy, 1);
      }
      else
      {
        town_clear_low_buf((int)&gpBuffer[sx + screen_y_times_768[sy]]);
      }
    }
    ++xa;
    --ya;
    sx += 64;
  }
  if ( some_flag )
  {
    if ( ya < 0 || ya >= 112 || xa < 0 || xa >= 112 )
    {
      town_clear_low_buf((int)&gpBuffer[sx + screen_y_times_768[sy]]);
    }
    else
    {
      level_cel_block = dPiece[xa][ya];
      if ( level_cel_block )
      {
        a1b = &gpBuffer[sx + screen_y_times_768[sy]];
        v10 = (char *)dpiece_defs_map_1 + 32 * gendung_get_dpiece_num_from_coord(xa, ya);
        for ( l = 0; l < 16; l += 2 )
        {
          level_cel_block = *(_WORD *)&v10[2 * l];
          if ( level_cel_block )
            drawLowerScreen(a1b);
          a1b -= 24576;
        }
        town_draw_clipped_town(&gpBuffer[sx + screen_y_times_768[sy]], xa, ya, sx, sy, 0);
      }
      else
      {
        town_clear_low_buf((int)&gpBuffer[sx + screen_y_times_768[sy]]);
      }
    }
  }
}

//----- (0044B469) --------------------------------------------------------
void __fastcall town_draw_clipped_e_flag_2(void *buffer, int x, int y, int a4, int a5, int sx, int sy)
{
  int xa; // [esp+Ch] [ebp-14h]
  void *v8; // [esp+10h] [ebp-10h]
  char *v9; // [esp+14h] [ebp-Ch]
  char *a1; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  xa = x;
  v8 = buffer;
  if ( a4 )
    a1 = (char *)buffer + 24576 * a4;
  else
    a1 = (char *)buffer;
  v9 = (char *)dpiece_defs_map_1 + 32 * gendung_get_dpiece_num_from_coord(x, y);
  for ( i = 0; i < 6; ++i )
  {
    if ( i >= a4 )
    {
      level_cel_block = *(_WORD *)&v9[4 * i + 4];
      if ( level_cel_block )
        drawLowerScreen(a1);
      level_cel_block = *(_WORD *)&v9[4 * i + 6];
      if ( level_cel_block )
        drawLowerScreen(a1 + 32);
    }
    a1 -= 24576;
  }
  if ( a5 < 8 )
    town_draw_clipped_town_2((int)v8, xa, y, a4, a5, sx, sy, 0);
}

//----- (0044B56F) --------------------------------------------------------
void __fastcall town_draw_clipped_town_2(int x, int y, int a3, int a4, int a5, int sx, int sy, int some_flag)
{
  int screen_x; // [esp+14h] [ebp-10h]
  int screen_xa; // [esp+14h] [ebp-10h]
  int screen_xb; // [esp+14h] [ebp-10h]
  int screen_xc; // [esp+14h] [ebp-10h]
  int screen_xd; // [esp+14h] [ebp-10h]
  int screen_y; // [esp+18h] [ebp-Ch]
  int screen_ya; // [esp+18h] [ebp-Ch]
  char v17; // [esp+1Ch] [ebp-8h]
  char v18; // [esp+1Ch] [ebp-8h]
  char v19; // [esp+1Ch] [ebp-8h]
  int v20; // [esp+20h] [ebp-4h]
  int v21; // [esp+20h] [ebp-4h]

  if ( dItem[y][a3] )
  {
    v17 = dItem[y][a3] - 1;
    screen_x = sx - item[v17]._iAnimWidth2;
    if ( pcursitem == v17 )
      CelDrawHdrClrHL(
        181,
        screen_x,
        sy,
        (char *)item[v17]._iAnimData,
        item[v17]._iAnimFrame,
        item[v17]._iAnimWidth,
        a5,
        8);
    Cel2DrawHdrOnly(screen_x, sy, (char *)item[v17]._iAnimData, item[v17]._iAnimFrame, item[v17]._iAnimWidth, a5, 8);
  }
  if ( dFlags[y][a3] & 0x10 )
  {
    v20 = -(dMonster[y][a3 - 1] + 1);
    screen_xa = sx - towner[-(dMonster[y][a3 - 1] + 1)]._tAnimWidth2;
    if ( pcursmonst == v20 )
      CelDrawHdrClrHL(
        166,
        screen_xa,
        sy,
        (char *)towner[-(dMonster[y][a3 - 1] + 1)]._tAnimData,
        towner[-(dMonster[y][a3 - 1] + 1)]._tAnimFrame,
        towner[-(dMonster[y][a3 - 1] + 1)]._tAnimWidth,
        a5,
        8);
    Cel2DrawHdrOnly(
      screen_xa,
      sy,
      (char *)towner[v20]._tAnimData,
      towner[v20]._tAnimFrame,
      towner[v20]._tAnimWidth,
      a5,
      8);
  }
  if ( dMonster[y][a3] > 0 )
  {
    v21 = dMonster[y][a3] - 1;
    screen_xb = sx - towner[v21]._tAnimWidth2;
    if ( pcursmonst == v21 )
      CelDrawHdrClrHL(
        166,
        screen_xb,
        sy,
        (char *)towner[v21]._tAnimData,
        towner[v21]._tAnimFrame,
        towner[v21]._tAnimWidth,
        a5,
        8);
    Cel2DrawHdrOnly(
      screen_xb,
      sy,
      (char *)towner[v21]._tAnimData,
      towner[v21]._tAnimFrame,
      towner[v21]._tAnimWidth,
      a5,
      8);
  }
  if ( dFlags[y][a3] & 0x20 )
  {
    v18 = -(char)(dPlayer[y][a3 - 1] + 1);
    screen_xc = sx + plr[v18]._pxoff - plr[v18]._pAnimWidth2;
    screen_y = sy + plr[v18]._pyoff;
    if ( v18 == pcursplr )
      CelDrawHdrClrHL(
        165,
        screen_xc,
        screen_y,
        (char *)plr[v18]._pAnimData,
        plr[v18]._pAnimFrame,
        plr[v18]._pAnimWidth,
        a5,
        8);
    Cel2DrawHdrOnly(screen_xc, screen_y, (char *)plr[v18]._pAnimData, plr[v18]._pAnimFrame, plr[v18]._pAnimWidth, a5, 8);
    if ( some_flag && plr[v18]._peflag )
      town_draw_clipped_e_flag_2((void *)(x - 64), y - 1, a3 + 1, a4, a5, sx - 64, sy);
  }
  if ( dPlayer[y][a3] > 0 )
  {
    v19 = dPlayer[y][a3] - 1;
    screen_xd = sx + plr[v19]._pxoff - plr[v19]._pAnimWidth2;
    screen_ya = sy + plr[v19]._pyoff;
    if ( v19 == pcursplr )
      CelDrawHdrClrHL(
        165,
        screen_xd,
        screen_ya,
        (char *)plr[v19]._pAnimData,
        plr[v19]._pAnimFrame,
        plr[v19]._pAnimWidth,
        a5,
        8);
    Cel2DrawHdrOnly(
      screen_xd,
      screen_ya,
      (char *)plr[v19]._pAnimData,
      plr[v19]._pAnimFrame,
      plr[v19]._pAnimWidth,
      a5,
      8);
    if ( some_flag && plr[v19]._peflag )
      town_draw_clipped_e_flag_2((void *)(x - 64), y - 1, a3 + 1, a4, a5, sx - 64, sy);
  }
  if ( dFlags[y][a3] & 1 )
    DrawClippedMissile(y, a3, sx, sy, a5, 8, 0);
  if ( dArch[y][a3] )
    town_44A643(x + screen_y_times_768[16 * a5], dArch[y][a3]);
}

//----- (0044BD25) --------------------------------------------------------
void __fastcall town_draw_lower_2(int x, int y, int sx, int sy, int a5, int a6, int some_flag)
{
  signed int ya; // [esp+Ch] [ebp-1Ch]
  signed int xa; // [esp+10h] [ebp-18h]
  char *v9; // [esp+14h] [ebp-14h]
  char *v10; // [esp+14h] [ebp-14h]
  char *v11; // [esp+14h] [ebp-14h]
  char *a1; // [esp+18h] [ebp-10h]
  char *a1a; // [esp+18h] [ebp-10h]
  char *a1b; // [esp+18h] [ebp-10h]
  int v15; // [esp+1Ch] [ebp-Ch]
  int j; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]
  int k; // [esp+24h] [ebp-4h]
  int l; // [esp+24h] [ebp-4h]
  int a5a; // [esp+38h] [ebp+10h]

  ya = y;
  xa = x;
  v15 = 2 * a6 + 2;
  if ( some_flag )
  {
    if ( y < 0 || y >= 112 || x < 0 || x >= 112 )
    {
      town_clear_low_buf((int)&gpBuffer[sx + screen_y_times_768[sy]]);
    }
    else
    {
      level_cel_block = dPiece[x][y];
      if ( level_cel_block )
      {
        a1 = &gpBuffer[sx - 24544 + screen_y_times_768[sy]];
        v9 = (char *)dpiece_defs_map_1 + 32 * gendung_get_dpiece_num_from_coord(x, y);
        for ( i = 0; i < 7; ++i )
        {
          if ( i >= a6 )
          {
            level_cel_block = *(_WORD *)&v9[4 * i + 6];
            if ( level_cel_block )
              drawLowerScreen(a1);
          }
          a1 -= 24576;
        }
        if ( v15 < 8 )
          town_draw_clipped_town_2((int)&gpBuffer[sx + screen_y_times_768[sy]], xa, ya, a6, v15, sx, sy, 0);
      }
      else
      {
        town_clear_low_buf((int)&gpBuffer[sx + screen_y_times_768[sy]]);
      }
    }
    ++xa;
    --ya;
    sx += 64;
  }
  a5a = a5 - some_flag;
  for ( j = 0; j < a5a; ++j )
  {
    if ( ya < 0 || ya >= 112 || xa < 0 || xa >= 112 )
    {
      town_clear_low_buf((int)&gpBuffer[sx + screen_y_times_768[sy]]);
    }
    else
    {
      level_cel_block = dPiece[xa][ya];
      if ( level_cel_block )
      {
        a1a = &gpBuffer[sx - 24576 + screen_y_times_768[sy]];
        v10 = (char *)dpiece_defs_map_1 + 32 * gendung_get_dpiece_num_from_coord(xa, ya);
        for ( k = 0; k < 7; ++k )
        {
          if ( k >= a6 )
          {
            level_cel_block = *(_WORD *)&v10[4 * k + 4];
            if ( level_cel_block )
              drawLowerScreen(a1a);
            level_cel_block = *(_WORD *)&v10[4 * k + 6];
            if ( level_cel_block )
              drawLowerScreen(a1a + 32);
          }
          a1a -= 24576;
        }
        if ( v15 < 8 )
          town_draw_clipped_town_2(
            (int)&gpBuffer[sx + screen_y_times_768[sy] + -12288 * v15],
            xa,
            ya,
            a6,
            v15,
            sx,
            sy,
            1);
      }
      else
      {
        town_clear_low_buf((int)&gpBuffer[sx + screen_y_times_768[sy]]);
      }
    }
    ++xa;
    --ya;
    sx += 64;
  }
  if ( some_flag )
  {
    if ( ya < 0 || ya >= 112 || xa < 0 || xa >= 112 )
    {
      town_clear_low_buf((int)&gpBuffer[sx + screen_y_times_768[sy]]);
    }
    else
    {
      level_cel_block = dPiece[xa][ya];
      if ( level_cel_block )
      {
        a1b = &gpBuffer[sx - 24576 + screen_y_times_768[sy]];
        v11 = (char *)dpiece_defs_map_1 + 32 * gendung_get_dpiece_num_from_coord(xa, ya);
        for ( l = 0; l < 7; ++l )
        {
          if ( l >= a6 )
          {
            level_cel_block = *(_WORD *)&v11[4 * l + 4];
            if ( level_cel_block )
              drawLowerScreen(a1b);
          }
          a1b -= 24576;
        }
        if ( v15 < 8 )
          town_draw_clipped_town_2((int)&gpBuffer[sx + screen_y_times_768[sy]], xa, ya, a6, v15, sx, sy, 0);
      }
      else
      {
        town_clear_low_buf((int)&gpBuffer[sx + screen_y_times_768[sy]]);
      }
    }
  }
}

//----- (0044C20B) --------------------------------------------------------
void __fastcall town_draw_e_flag(void *buffer, int x, int y, int a4, int dir, int sx, int sy)
{
  char *v9; // [esp+14h] [ebp-Ch]
  char *a1; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  a1 = (char *)buffer;
  v9 = (char *)dpiece_defs_map_1 + 32 * gendung_get_dpiece_num_from_coord(x, y);
  for ( i = 0; i < 7; ++i )
  {
    if ( i <= a4 )
    {
      level_cel_block = *(_WORD *)&v9[4 * i];
      if ( level_cel_block )
        drawUpperScreen(a1);
      level_cel_block = *(_WORD *)&v9[4 * i + 2];
      if ( level_cel_block )
        drawUpperScreen(a1 + 32);
    }
    a1 -= 24576;
  }
  town_draw_town_all(buffer, x, y, a4, dir, sx, sy, 0);
}

//----- (0044C2E8) --------------------------------------------------------
void __fastcall town_draw_town_all(void *buffer, int x, int y, int a4, int dir, int sx, int sy, int some_flag)
{
  int screen_x; // [esp+14h] [ebp-10h]
  int screen_xa; // [esp+14h] [ebp-10h]
  int screen_xb; // [esp+14h] [ebp-10h]
  int screen_xc; // [esp+14h] [ebp-10h]
  int screen_xd; // [esp+14h] [ebp-10h]
  int screen_y; // [esp+18h] [ebp-Ch]
  int screen_ya; // [esp+18h] [ebp-Ch]
  char v17; // [esp+1Ch] [ebp-8h]
  char v18; // [esp+1Ch] [ebp-8h]
  char v19; // [esp+1Ch] [ebp-8h]
  int v20; // [esp+20h] [ebp-4h]
  int v21; // [esp+20h] [ebp-4h]

  if ( dItem[x][y] )
  {
    v17 = dItem[x][y] - 1;
    screen_x = sx - item[v17]._iAnimWidth2;
    if ( pcursitem == v17 )
      CelDecodeClr(
        181,
        screen_x,
        sy,
        (char *)item[v17]._iAnimData,
        item[v17]._iAnimFrame,
        item[v17]._iAnimWidth,
        0,
        dir);
    if ( !item[v17]._iAnimData )
      assertion_failed(663, "C:\\Diablo\\Direct\\TOWN.CPP");
    CelDrawHdrOnly(screen_x, sy, (char *)item[v17]._iAnimData, item[v17]._iAnimFrame, item[v17]._iAnimWidth, 0, dir);
  }
  if ( dFlags[x][y] & 0x10 )
  {
    v20 = -(dMonster[x][y - 1] + 1);
    screen_xa = sx - towner[-(dMonster[x][y - 1] + 1)]._tAnimWidth2;
    if ( pcursmonst == v20 )
      CelDecodeClr(
        166,
        screen_xa,
        sy,
        (char *)towner[-(dMonster[x][y - 1] + 1)]._tAnimData,
        towner[-(dMonster[x][y - 1] + 1)]._tAnimFrame,
        towner[-(dMonster[x][y - 1] + 1)]._tAnimWidth,
        0,
        dir);
    if ( !towner[v20]._tAnimData )
      assertion_failed(671, "C:\\Diablo\\Direct\\TOWN.CPP");
    CelDrawHdrOnly(
      screen_xa,
      sy,
      (char *)towner[v20]._tAnimData,
      towner[v20]._tAnimFrame,
      towner[v20]._tAnimWidth,
      0,
      dir);
  }
  if ( dMonster[x][y] > 0 )
  {
    v21 = dMonster[x][y] - 1;
    screen_xb = sx - towner[v21]._tAnimWidth2;
    if ( pcursmonst == v21 )
      CelDecodeClr(
        166,
        screen_xb,
        sy,
        (char *)towner[v21]._tAnimData,
        towner[v21]._tAnimFrame,
        towner[v21]._tAnimWidth,
        0,
        dir);
    if ( !towner[v21]._tAnimData )
      assertion_failed(679, "C:\\Diablo\\Direct\\TOWN.CPP");
    CelDrawHdrOnly(
      screen_xb,
      sy,
      (char *)towner[v21]._tAnimData,
      towner[v21]._tAnimFrame,
      towner[v21]._tAnimWidth,
      0,
      dir);
  }
  if ( dFlags[x][y] & 0x20 )
  {
    v18 = -(char)(dPlayer[x][y - 1] + 1);
    screen_xc = sx + plr[v18]._pxoff - plr[v18]._pAnimWidth2;
    screen_y = sy + plr[v18]._pyoff;
    if ( v18 == pcursplr )
      CelDecodeClr(
        165,
        screen_xc,
        screen_y,
        (char *)plr[v18]._pAnimData,
        plr[v18]._pAnimFrame,
        plr[v18]._pAnimWidth,
        0,
        dir);
    if ( !plr[v18]._pAnimData )
      assertion_failed(687, "C:\\Diablo\\Direct\\TOWN.CPP");
    CelDrawHdrOnly(screen_xc, screen_y, (char *)plr[v18]._pAnimData, plr[v18]._pAnimFrame, plr[v18]._pAnimWidth, 0, dir);
    if ( some_flag && plr[v18]._peflag )
      town_draw_e_flag((char *)buffer - 64, x - 1, y + 1, a4, dir, sx - 64, sy);
  }
  if ( dPlayer[x][y] > 0 )
  {
    v19 = dPlayer[x][y] - 1;
    screen_xd = sx + plr[v19]._pxoff - plr[v19]._pAnimWidth2;
    screen_ya = sy + plr[v19]._pyoff;
    if ( v19 == pcursplr )
      CelDecodeClr(
        165,
        screen_xd,
        screen_ya,
        (char *)plr[v19]._pAnimData,
        plr[v19]._pAnimFrame,
        plr[v19]._pAnimWidth,
        0,
        dir);
    if ( !plr[v19]._pAnimData )
      assertion_failed(700, "C:\\Diablo\\Direct\\TOWN.CPP");
    CelDrawHdrOnly(
      screen_xd,
      screen_ya,
      (char *)plr[v19]._pAnimData,
      plr[v19]._pAnimFrame,
      plr[v19]._pAnimWidth,
      0,
      dir);
    if ( some_flag && plr[v19]._peflag )
      town_draw_e_flag((char *)buffer - 64, x - 1, y + 1, a4, dir, sx - 64, sy);
  }
  if ( dFlags[x][y] & 1 )
    DrawMissile(x, y, sx, sy, 0, dir, 0);
  if ( dArch[x][y] )
    town_44A6F5((int)buffer, dArch[x][y]);
}

//----- (0044CB90) --------------------------------------------------------
void __fastcall town_draw_upper(int x, int y, int sx, int sy, int a5, int a6, int some_flag)
{
  signed int ya; // [esp+Ch] [ebp-1Ch]
  signed int xa; // [esp+10h] [ebp-18h]
  char *v9; // [esp+14h] [ebp-14h]
  char *v10; // [esp+14h] [ebp-14h]
  char *v11; // [esp+14h] [ebp-14h]
  char *a1; // [esp+18h] [ebp-10h]
  char *a1a; // [esp+18h] [ebp-10h]
  char *a1b; // [esp+18h] [ebp-10h]
  int j; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  int k; // [esp+20h] [ebp-8h]
  int l; // [esp+20h] [ebp-8h]
  int dir; // [esp+24h] [ebp-4h]
  int a5a; // [esp+38h] [ebp+10h]

  ya = y;
  xa = x;
  dir = 2 * a6 + 2;
  if ( dir > 8 )
    dir = 8;
  if ( some_flag )
  {
    if ( y < 0 || y >= 112 || x < 0 || x >= 112 )
    {
      town_clear_upper_buf((int)&gpBuffer[sx + screen_y_times_768[sy]]);
    }
    else
    {
      level_cel_block = dPiece[x][y];
      if ( level_cel_block )
      {
        a1 = &gpBuffer[sx + 32 + screen_y_times_768[sy]];
        v9 = (char *)dpiece_defs_map_1 + 32 * gendung_get_dpiece_num_from_coord(x, y);
        for ( i = 0; i < 7; ++i )
        {
          if ( a6 >= i )
          {
            level_cel_block = *(_WORD *)&v9[4 * i + 2];
            if ( level_cel_block )
              drawUpperScreen(a1);
          }
          a1 -= 24576;
        }
        town_draw_town_all(&gpBuffer[sx + screen_y_times_768[sy]], xa, ya, a6, dir, sx, sy, 0);
      }
      else
      {
        town_clear_upper_buf((int)&gpBuffer[sx + screen_y_times_768[sy]]);
      }
    }
    ++xa;
    --ya;
    sx += 64;
  }
  a5a = a5 - some_flag;
  for ( j = 0; j < a5a; ++j )
  {
    if ( ya < 0 || ya >= 112 || xa < 0 || xa >= 112 )
    {
      town_clear_upper_buf((int)&gpBuffer[sx + screen_y_times_768[sy]]);
    }
    else
    {
      level_cel_block = dPiece[xa][ya];
      if ( level_cel_block )
      {
        a1a = &gpBuffer[sx + screen_y_times_768[sy]];
        v10 = (char *)dpiece_defs_map_1 + 32 * gendung_get_dpiece_num_from_coord(xa, ya);
        for ( k = 0; k < 7; ++k )
        {
          if ( a6 >= k )
          {
            level_cel_block = *(_WORD *)&v10[4 * k];
            if ( level_cel_block )
              drawUpperScreen(a1a);
            level_cel_block = *(_WORD *)&v10[4 * k + 2];
            if ( level_cel_block )
              drawUpperScreen(a1a + 32);
          }
          a1a -= 24576;
        }
        town_draw_town_all(&gpBuffer[sx + screen_y_times_768[sy]], xa, ya, a6, dir, sx, sy, 1);
      }
      else
      {
        town_clear_upper_buf((int)&gpBuffer[sx + screen_y_times_768[sy]]);
      }
    }
    ++xa;
    --ya;
    sx += 64;
  }
  if ( some_flag )
  {
    if ( ya < 0 || ya >= 112 || xa < 0 || xa >= 112 )
    {
      town_clear_upper_buf((int)&gpBuffer[sx + screen_y_times_768[sy]]);
    }
    else
    {
      level_cel_block = dPiece[xa][ya];
      if ( level_cel_block )
      {
        a1b = &gpBuffer[sx + screen_y_times_768[sy]];
        v11 = (char *)dpiece_defs_map_1 + 32 * gendung_get_dpiece_num_from_coord(xa, ya);
        for ( l = 0; l < 7; ++l )
        {
          if ( a6 >= l )
          {
            level_cel_block = *(_WORD *)&v11[4 * l];
            if ( level_cel_block )
              drawUpperScreen(a1b);
          }
          a1b -= 24576;
        }
        town_draw_town_all(&gpBuffer[sx + screen_y_times_768[sy]], xa, ya, a6, dir, sx, sy, 0);
      }
      else
      {
        town_clear_upper_buf((int)&gpBuffer[sx + screen_y_times_768[sy]]);
      }
    }
  }
}

//----- (0044D050) --------------------------------------------------------
void __fastcall T_DrawGame(int x, int y)
{
  int v2; // ST38_4
  int v3; // ST34_4
  int v4; // ST38_4
  int v5; // ST34_4
  int v6; // ST38_4
  int v7; // ST34_4
  int ya; // [esp+10h] [ebp-1Ch]
  int xa; // [esp+14h] [ebp-18h]
  signed int v10; // [esp+18h] [ebp-14h]
  int a6; // [esp+1Ch] [ebp-10h]
  signed int a6a; // [esp+1Ch] [ebp-10h]
  int a6b; // [esp+1Ch] [ebp-10h]
  int sy; // [esp+20h] [ebp-Ch]
  int sx; // [esp+24h] [ebp-8h]
  int a5; // [esp+28h] [ebp-4h]

  scr_pix_width = 640;
  scr_pix_height = 352;
  gendung_5847D0_unused = 10;
  gendung_5847D4_unused = 11;
  sx = Scrollinfo._sxoff + 64;
  sy = Scrollinfo._syoff + 175;
  xa = x - 10;
  ya = y - 1;
  a5 = 10;
  v10 = 5;
  if ( chrflag || questlog )
  {
    xa += 2;
    ya = y - 3;
    sx = Scrollinfo._sxoff + 352;
    a5 = 6;
  }
  if ( invflag || sbookflag )
  {
    xa += 2;
    ya -= 2;
    sx -= 32;
    a5 = 6;
  }
  switch ( Scrollinfo._sdir )
  {
    case 0:
      break;
    case 1:
      sy = Scrollinfo._syoff + 143;
      --xa;
      --ya;
      v10 = 6;
      break;
    case 2:
      sy = Scrollinfo._syoff + 143;
      --xa;
      --ya;
      ++a5;
      v10 = 6;
      break;
    case 3:
      ++a5;
      break;
    case 4:
      ++a5;
      v10 = 6;
      break;
    case 5:
      v10 = 6;
      break;
    case 6:
      sx -= 64;
      --xa;
      ++ya;
      ++a5;
      v10 = 6;
      break;
    case 7:
      sx -= 64;
      --xa;
      ++ya;
      ++a5;
      break;
    case 8:
      sx -= 64;
      sy = Scrollinfo._syoff + 143;
      xa -= 2;
      ++a5;
      v10 = 6;
      break;
  }
  screen_buf_end = (int)&gpBuffer[screen_y_times_768[160]];
  for ( a6 = 0; a6 < 7; ++a6 )
  {
    town_draw_upper(xa, ya++, sx, sy, a5, a6, 0);
    v2 = sx - 32;
    v3 = sy + 16;
    town_draw_upper(xa++, ya, v2, v3, a5, a6, 1);
    sx = v2 + 32;
    sy = v3 + 16;
  }
  screen_buf_end = (int)&gpBuffer[screen_y_times_768[512]];
  for ( a6a = 0; v10 > a6a; ++a6a )
  {
    town_draw_lower(xa, ya++, sx, sy, a5, 0);
    v4 = sx - 32;
    v5 = sy + 16;
    town_draw_lower(xa++, ya, v4, v5, a5, 1);
    sx = v4 + 32;
    sy = v5 + 16;
  }
  for ( a6b = 0; a6b < 7; ++a6b )
  {
    town_draw_lower_2(xa, ya++, sx, sy, a5, a6b, 0);
    v6 = sx - 32;
    v7 = sy + 16;
    town_draw_lower_2(xa++, ya, v6, v7, a5, a6b, 1);
    sx = v6 + 32;
    sy = v7 + 16;
  }
}

//----- (0044D34E) --------------------------------------------------------
void __fastcall T_DrawZoom(int x, int y)
{
  int v2; // ST44_4
  int v3; // ST40_4
  int v4; // ST44_4
  int v5; // ST40_4
  int v6; // ST44_4
  int v7; // ST40_4
  char *v8; // edi
  char *v9; // esi
  char *v10; // ebx
  signed int v11; // edx
  signed int v12; // ecx
  __int16 v13; // ax
  int v14; // eax
  int ya; // [esp+10h] [ebp-28h]
  int xa; // [esp+14h] [ebp-24h]
  signed int v17; // [esp+18h] [ebp-20h]
  signed int v18; // [esp+1Ch] [ebp-1Ch]
  int a6; // [esp+20h] [ebp-18h]
  signed int a6a; // [esp+20h] [ebp-18h]
  int a6b; // [esp+20h] [ebp-18h]
  signed int v22; // [esp+24h] [ebp-14h]
  signed int v23; // [esp+28h] [ebp-10h]
  int sy; // [esp+2Ch] [ebp-Ch]
  int sx; // [esp+30h] [ebp-8h]
  int a5; // [esp+34h] [ebp-4h]

  scr_pix_width = 384;
  scr_pix_height = 192;
  gendung_5847D0_unused = 6;
  gendung_5847D4_unused = 6;
  sx = Scrollinfo._sxoff + 64;
  sy = Scrollinfo._syoff + 143;
  xa = x - 6;
  ya = y - 1;
  a5 = 6;
  v17 = 0;
  switch ( Scrollinfo._sdir )
  {
    case 0:
      break;
    case 1:
      sy = Scrollinfo._syoff + 111;
      xa = x - 7;
      ya = y - 2;
      v17 = 1;
      break;
    case 2:
      sy = Scrollinfo._syoff + 111;
      xa = x - 7;
      ya = y - 2;
      a5 = 7;
      v17 = 1;
      break;
    case 3:
      a5 = 7;
      break;
    case 4:
      a5 = 7;
      v17 = 1;
      break;
    case 5:
      v17 = 1;
      break;
    case 6:
      sx = Scrollinfo._sxoff;
      xa = x - 7;
      ya = y;
      a5 = 7;
      v17 = 1;
      break;
    case 7:
      sx = Scrollinfo._sxoff;
      xa = x - 7;
      ya = y;
      a5 = 7;
      break;
    case 8:
      sx = Scrollinfo._sxoff;
      sy = Scrollinfo._syoff + 111;
      xa = x - 8;
      a5 = 7;
      v17 = 1;
      break;
  }
  screen_buf_end = (int)&gpBuffer[screen_y_times_768[143]];
  for ( a6 = 0; a6 < 7; ++a6 )
  {
    town_draw_upper(xa, ya++, sx, sy, a5, a6, 0);
    v2 = sx - 32;
    v3 = sy + 16;
    town_draw_upper(xa++, ya, v2, v3, a5, a6, 1);
    sx = v2 + 32;
    sy = v3 + 16;
  }
  screen_buf_end = (int)&gpBuffer[screen_y_times_768[320]];
  for ( a6a = 0; v17 > a6a; ++a6a )
  {
    town_draw_lower(xa, ya++, sx, sy, a5, 0);
    v4 = sx - 32;
    v5 = sy + 16;
    town_draw_lower(xa++, ya, v4, v5, a5, 1);
    sx = v4 + 32;
    sy = v5 + 16;
  }
  for ( a6b = 0; a6b < 7; ++a6b )
  {
    town_draw_lower_2(xa, ya++, sx, sy, a5, a6b, 0);
    v6 = sx - 32;
    v7 = sy + 16;
    town_draw_lower_2(xa++, ya, v6, v7, a5, a6b, 1);
    sx = v6 + 32;
    sy = v7 + 16;
  }
  if ( chrflag || questlog )
  {
    v23 = 245168;
    v18 = 392064;
    v22 = 160;
  }
  else if ( invflag || sbookflag )
  {
    v23 = 245168;
    v18 = 391744;
    v22 = 160;
  }
  else
  {
    v23 = 245088;
    v18 = 391744;
    v22 = 320;
  }
  v8 = &gpBuffer[v18];
  v9 = &gpBuffer[v23];
  v10 = &gpBuffer[v18 + 768];
  v11 = 176;
  do
  {
    v12 = v22;
    do
    {
      LOBYTE(v13) = *v9++;
      HIBYTE(v13) = v13;
      *(_WORD *)v8 = v13;
      *(_WORD *)v10 = v13;
      v8 += 2;
      v10 += 2;
      --v12;
    }
    while ( v12 );
    v9 += -v22 - 768;
    v14 = 2 * (v22 + 768);
    v10 -= v14;
    v8 -= v14;
    --v11;
  }
  while ( v11 );
}

//----- (0044D6BD) --------------------------------------------------------
void __fastcall T_DrawView(int StartX, int StartY)
{
  light_table_index = 0;
  cel_transparency_active = 0;
  if ( zoomflag )
    T_DrawGame(StartX, StartY);
  else
    T_DrawZoom(StartX, StartY);
  if ( automapflag )
    DrawAutomap();
  if ( stextflag )
    DrawSText();
  if ( invflag )
  {
    DrawInv();
  }
  else if ( sbookflag )
  {
    DrawSpellBook();
  }
  DrawDurIcon();
  if ( chrflag )
  {
    DrawChr();
  }
  else if ( questlog )
  {
    DrawQuestLog();
  }
  else if ( plr[myplr]._pStatPts && !spselflag )
  {
    DrawLevelUpIcon();
  }
  if ( uitemflag )
    DrawUniqueInfo();
  if ( qtextflag )
    DrawQText();
  if ( spselflag )
    DrawSpellList();
  DrawPlrMsg();
  gmenu_draw();
  if ( dropGoldFlag )
    DrawGoldSplit(dropGoldValue);
  if ( Xhelpflag_2 )
    helpmode_draw2();
  if ( helpflag )
    DrawHelp();
  if ( msgflag )
    DrawDiabloMsg();
  if ( PauseMode )
    gmenu_draw_pause();
  DrawInfoBox();
  DrawLifeFlask();
  DrawManaFlask();
}

//----- (0044D87D) --------------------------------------------------------
void __cdecl town_init_dpiece_defs_map()
{
  __int16 v0; // cx
  unsigned __int16 v1; // cx
  int v2; // eax
  int v3; // eax
  int v4; // eax
  char *v5; // [esp+18h] [ebp-48h]
  unsigned __int16 *v6; // [esp+18h] [ebp-48h]
  int y; // [esp+1Ch] [ebp-44h]
  int ya; // [esp+1Ch] [ebp-44h]
  int v9; // [esp+20h] [ebp-40h]
  int x; // [esp+24h] [ebp-3Ch]
  int xa; // [esp+24h] [ebp-3Ch]
  int v12; // [esp+28h] [ebp-38h]
  int v13; // [esp+28h] [ebp-38h]
  int v14; // [esp+28h] [ebp-38h]
  int v15; // [esp+2Ch] [ebp-34h]
  int v16; // [esp+2Ch] [ebp-34h]
  int v17; // [esp+2Ch] [ebp-34h]
  int v18; // [esp+30h] [ebp-30h]
  int v19; // [esp+34h] [ebp-2Ch]
  int i; // [esp+50h] [ebp-10h]
  int j; // [esp+54h] [ebp-Ch]
  char *v22; // [esp+58h] [ebp-8h]
  int v23; // [esp+5Ch] [ebp-4h]

  for ( y = 0; y < 112; ++y )
  {
    for ( x = 0; x < 112; ++x )
    {
      v9 = dPiece[x][y];
      v5 = (char *)dpiece_defs_map_1 + 32 * gendung_get_dpiece_num_from_coord(x, y);
      if ( v9 )
      {
        v22 = (char *)pLevelPieces + 32 * (v9 - 1);
        for ( i = 0; i < 16; ++i )
          *(_WORD *)&v5[2 * i] = *(_WORD *)&v22[2 * ((i & 1) + 14 - (i & 0xE))];
      }
      else
      {
        for ( i = 0; i < 16; ++i )
          *(_WORD *)&v5[2 * i] = 0;
      }
    }
  }
  for ( ya = 0; ya < 112; ++ya )
  {
    for ( xa = 0; xa < 112; ++xa )
    {
      v6 = (unsigned __int16 *)((char *)dpiece_defs_map_1 + 32 * gendung_get_dpiece_num_from_coord(xa, ya));
      for ( i = 0; i < 16; ++i )
        *((_WORD *)&v18 + i) = 0;
      v0 = *v6;
      v23 = *v6;
      if ( (HIBYTE(v0) & 0x70) == 64 && v23 )
        LOWORD(v18) = 1;
      v1 = v6[1];
      v23 = v1;
      if ( (HIBYTE(v1) & 0x70) == 80 && v23 )
        HIWORD(v18) = 1;
      for ( i = 2; i < 16; ++i )
      {
        v23 = v6[i];
        if ( !(v23 & 0x7000) && v23 )
        {
          *((_WORD *)&v18 + i) = 1;
          v12 = xa;
          v15 = ya;
          for ( j = i - 2; j >= 0 && v12 > 0 && v15 > 0; j -= 2 )
          {
            v2 = gendung_get_dpiece_num_from_coord(--v12, --v15);
            dpiece_defs_map_1[0][0][16 * v2 + j] = 0;
          }
        }
      }
      for ( i = 0; i < 13; i += 2 )
      {
        if ( *(int *)((char *)&v18 + 2 * i) & 0xFFFF && *(int *)((char *)&v19 + 2 * i) & 0xFFFF )
        {
          v13 = xa - 1;
          v16 = ya;
          for ( j = i + 1; j >= 0 && v13 >= 0 && v16 >= 0; j -= 2 )
          {
            v3 = gendung_get_dpiece_num_from_coord(v13, v16);
            dpiece_defs_map_1[0][0][16 * v3 + j] = 0;
            --v13;
            --v16;
          }
        }
      }
      for ( i = 1; i < 14; i += 2 )
      {
        if ( *(int *)((char *)&v18 + 2 * i) & 0xFFFF && *(int *)((char *)&v19 + 2 * i) & 0xFFFF )
        {
          v14 = xa;
          v17 = ya - 1;
          for ( j = i + 1; j >= 0 && v14 >= 0 && v17 >= 0; j -= 2 )
          {
            v4 = gendung_get_dpiece_num_from_coord(v14, v17);
            dpiece_defs_map_1[0][0][16 * v4 + j] = 0;
            --v14;
            --v17;
          }
        }
      }
    }
  }
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

//----- (0044DCBF) --------------------------------------------------------
void __fastcall T_FillSector(WORD *P3Tiles, WORD *pSector, int xi, int yi, int w, int h)
{
  int v6; // eax
  WORD *v7; // esi
  WORD v8; // ax
  int v9; // eax
  int v10; // [esp+14h] [ebp-24h]
  int i; // [esp+18h] [ebp-20h]
  int j; // [esp+1Ch] [ebp-1Ch]
  int v13; // [esp+20h] [ebp-18h]
  int v14; // [esp+24h] [ebp-14h]
  signed int v15; // [esp+28h] [ebp-10h]
  int v16; // [esp+2Ch] [ebp-Ch]
  int v17; // [esp+30h] [ebp-8h]
  int v18; // [esp+34h] [ebp-4h]

  v15 = 2;
  v13 = yi;
  for ( i = 0; i < h; ++i )
  {
    v10 = xi;
    for ( j = 0; j < w; ++j )
    {
      v6 = pSector[v15];
      if ( (_WORD)v6 )
      {
        v7 = &P3Tiles[4 * (v6 - 1)];
        v8 = *v7;
        ++v7;
        v9 = v8 + 1;
        v18 = v9;
        LOWORD(v9) = *v7;
        ++v7;
        v17 = ++v9;
        LOWORD(v9) = *v7;
        v16 = ++v9;
        LOWORD(v9) = v7[1];
        v14 = v9 + 1;
      }
      else
      {
        v18 = 0;
        v17 = 0;
        v16 = 0;
        v14 = 0;
      }
      dPiece[v10][v13] = v18;
      dPiece[v10 + 1][v13] = v17;
      dPiece[v10][v13 + 1] = v16;
      dPiece[v10 + 1][v13 + 1] = v14;
      v10 += 2;
      ++v15;
    }
    v13 += 2;
  }
}

//----- (0044DDEC) --------------------------------------------------------
void __cdecl T_Pass3()
{
  unsigned __int8 *P3Tiles; // ST20_4
  unsigned __int8 *pSector; // ST28_4
  unsigned __int8 *v2; // ST28_4
  unsigned __int8 *v3; // ST28_4
  unsigned __int8 *v4; // ST28_4
  signed int j; // [esp+Ch] [ebp-10h]
  signed int i; // [esp+14h] [ebp-8h]

  for ( i = 0; i < 112; i += 2 )
  {
    for ( j = 0; j < 112; j += 2 )
    {
      dPiece[j][i] = 0;
      dPiece[j + 1][i] = 0;
      dPiece[j][i + 1] = 0;
      dPiece[j + 1][i + 1] = 0;
    }
  }
  P3Tiles = LoadFileInMem("Levels\\TownData\\Town.TIL", 0, 1344, "C:\\Diablo\\Direct\\TOWN.CPP");
  pSector = LoadFileInMem("Levels\\TownData\\Sector1s.DUN", 0, 1347, "C:\\Diablo\\Direct\\TOWN.CPP");
  T_FillSector((WORD *)P3Tiles, (WORD *)pSector, 46, 46, 25, 25);
  mem_free_dbg(pSector, 1349, "C:\\Diablo\\Direct\\TOWN.CPP");
  v2 = LoadFileInMem("Levels\\TownData\\Sector2s.DUN", 0, 1351, "C:\\Diablo\\Direct\\TOWN.CPP");
  T_FillSector((WORD *)P3Tiles, (WORD *)v2, 46, 0, 25, 23);
  mem_free_dbg(v2, 1353, "C:\\Diablo\\Direct\\TOWN.CPP");
  v3 = LoadFileInMem("Levels\\TownData\\Sector3s.DUN", 0, 1355, "C:\\Diablo\\Direct\\TOWN.CPP");
  T_FillSector((WORD *)P3Tiles, (WORD *)v3, 0, 46, 23, 25);
  mem_free_dbg(v3, 1357, "C:\\Diablo\\Direct\\TOWN.CPP");
  v4 = LoadFileInMem("Levels\\TownData\\Sector4s.DUN", 0, 1359, "C:\\Diablo\\Direct\\TOWN.CPP");
  T_FillSector((WORD *)P3Tiles, (WORD *)v4, 0, 0, 23, 23);
  mem_free_dbg(v4, 1361, "C:\\Diablo\\Direct\\TOWN.CPP");
  mem_free_dbg(P3Tiles, 1363, "C:\\Diablo\\Direct\\TOWN.CPP");
}

//----- (0044DFCE) --------------------------------------------------------
void __fastcall CreateTown(int entry)
{
  int v1; // [esp+10h] [ebp-Ch]
  signed int i; // [esp+14h] [ebp-8h]
  signed int j; // [esp+18h] [ebp-4h]

  dminx = 10;
  dminy = 10;
  dmaxx = 84;
  dmaxy = 84;
  if ( entry )
  {
    if ( entry == 1 )
    {
      ViewX = 25;
      ViewY = 31;
    }
    else if ( entry == 7 )
    {
      ViewX = 49;
      ViewY = 22;
    }
  }
  else
  {
    ViewX = 75;
    ViewY = 68;
  }
  T_Pass3();
  memset(dTransVal, 0, 0x3100u);
  memset(dFlags, 0, 0x3100u);
  memset(dPlayer, 0, 0x3100u);
  memset(dMonster, 0, 0xC400u);
  memset(dObject, 0, 0x3100u);
  memset(dItem, 0, 0x3100u);
  memset(dArch, 0, 0x3100u);
  for ( i = 0; i < 112; ++i )
  {
    for ( j = 0; j < 112; ++j )
    {
      v1 = dPiece[j][i];
      switch ( v1 )
      {
        case 360:
          dArch[j][i] = 1;
          break;
        case 358:
          dArch[j][i] = 2;
          break;
        case 129:
          dArch[j][i] = 6;
          break;
        case 130:
          dArch[j][i] = 7;
          break;
        case 128:
          dArch[j][i] = 8;
          break;
        case 117:
          dArch[j][i] = 9;
          break;
        case 157:
          dArch[j][i] = 10;
          break;
        case 158:
          dArch[j][i] = 11;
          break;
        case 156:
          dArch[j][i] = 12;
          break;
        case 162:
          dArch[j][i] = 13;
          break;
        case 160:
          dArch[j][i] = 14;
          break;
        case 214:
          dArch[j][i] = 15;
          break;
        case 212:
          dArch[j][i] = 16;
          break;
        case 217:
          dArch[j][i] = 17;
          break;
        case 216:
          dArch[j][i] = 18;
          break;
      }
    }
  }
  town_init_dpiece_defs_map();
}

