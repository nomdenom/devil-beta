#include "all.h"

//----- (0044A530) --------------------------------------------------------
void __fastcall town_clear_upper_buf(BYTE *dst)
{
  BYTE *buf; // edi
  signed int off; // edx
  signed int i; // ebx
  BYTE *buftmp; // edi MAPDST
  signed int off2; // edx
  signed int j; // ebx

  buf = dst;
  off = 30;
  i = 1;
  while ( buf >= gpBufEnd )
  {
    buftmp = &buf[off];
    memset(buftmp, 0, 4 * i);
    buf = &buftmp[4 * i - 832 + off];
    if ( !off )
    {
      j = 15;
      for (off2 = 2; off2 != 32; off2 += 2)
      {
        if ( buf < gpBufEnd )
          break;
        buftmp = &buf[off2];
        memset(buftmp, 0, 4 * j);
        buf = &buftmp[4 * j-- - 832 + off2];
      }
      return;
    }
    off -= 2;
    ++i;
  }
}

//----- (0044A5B2) --------------------------------------------------------
void __fastcall town_clear_low_buf(BYTE *dst)
{
  BYTE *buf; // edi MAPDST
  signed int off; // edx
  signed int i; // ebx
  BYTE *buftmp; // edi MAPDST
  signed int off2; // edx
  signed int j; // ebx

  buf = dst;
  off = 30;
  for ( i = 1; ; ++i )
  {
    if ( buf < gpBufEnd )
    {
      buftmp = &buf[off];
      memset(buftmp, 0, 4 * i);
      buf = &buftmp[4 * i + off];
    }
    else
    {
      buf += 64;
    }
    buf -= 832;
    if ( !off )
      break;
    off -= 2;
  }
  j = 15;
  for (off2 = 2; off2 != 32; off2 += 2)
  {
    if ( buf < gpBufEnd )
    {
      buftmp = &buf[off2];
      memset(buftmp, 0, 4 * j);
      buf = &buftmp[4 * j + off2];
    }
    else
    {
      buf += 64;
    }
    buf -= 832;
    --j;
  }
}

//----- (0044A643) --------------------------------------------------------
void __fastcall town_44A643_empty(BYTE *a1, int a2)
{
  ;
}

//----- (0044A6F5) --------------------------------------------------------
void __fastcall town_44A6F5_empty(int a1, int a2)
{
  ;
}

//----- (0044A79F) --------------------------------------------------------
void __fastcall town_draw_clipped_e_flag(BYTE *buffer, int x, int y, int sx, int sy)
{
  SHORT *defs; // [esp+14h] [ebp-Ch]
  BYTE *buf; // [esp+18h] [ebp-8h]
  signed int i; // [esp+1Ch] [ebp-4h]

  buf = buffer;
  defs = dpiece_defs_map_1[gendung_get_dpiece_num_from_coord(x, y)];
  for ( i = 0; i < 12; i += 2 )
  {
    LOWORD(level_cel_block) = defs[i];
    if ( (_WORD)level_cel_block )
      drawLowerScreen(buf);
    LOWORD(level_cel_block) = defs[i + 1];
    if ( (_WORD)level_cel_block )
      drawLowerScreen(buf + 32);
    buf -= 24576;
  }
  town_draw_clipped_town(buffer, x, y, sx, sy, 0);
}

//----- (0044A869) --------------------------------------------------------
void __fastcall town_draw_clipped_town(BYTE *buffer_unused, int x, int y, int sx, int sy, int some_flag)
{
  BYTE *buf; // [esp+10h] [ebp-14h]
  int screen_x; // [esp+14h] [ebp-10h]
  int screen_xa; // [esp+14h] [ebp-10h]
  int screen_xb; // [esp+14h] [ebp-10h]
  int screen_xc; // [esp+14h] [ebp-10h]
  int screen_xd; // [esp+14h] [ebp-10h]
  int screen_y; // [esp+18h] [ebp-Ch]
  int screen_ya; // [esp+18h] [ebp-Ch]
  char item_at; // [esp+1Ch] [ebp-8h]
  char player_at; // [esp+1Ch] [ebp-8h] MAPDST
  int monster_at; // [esp+20h] [ebp-4h] MAPDST

  buf = &gpBuffer[sx + screen_y_times_768[sy]];
  if ( dItem[x][y] )
  {
    item_at = dItem[x][y] - 1;
    screen_x = sx - item[item_at]._iAnimWidth2;
    if ( pcursitem == item_at )
      CelDrawHdrClrHL(
        181,
        screen_x,
        sy,
        item[item_at]._iAnimData,
        item[item_at]._iAnimFrame,
        item[item_at]._iAnimWidth,
        0,
        8);
    Cel2DrawHdrOnly(screen_x, sy, item[item_at]._iAnimData, item[item_at]._iAnimFrame, item[item_at]._iAnimWidth, 0, 8);
  }
  if ( dFlags[x][y] & 0x10 )
  {
    monster_at = -(dMonster[x][y - 1] + 1);
    screen_xa = sx - towner[-(dMonster[x][y - 1] + 1)]._tAnimWidth2;
    if ( pcursmonst == monster_at )
      CelDrawHdrClrHL(
        166,
        screen_xa,
        sy,
        (BYTE *)towner[-(dMonster[x][y - 1] + 1)]._tAnimData,
        towner[-(dMonster[x][y - 1] + 1)]._tAnimFrame,
        towner[-(dMonster[x][y - 1] + 1)]._tAnimWidth,
        0,
        8);
    Cel2DrawHdrOnly(
      screen_xa,
      sy,
      (BYTE *)towner[monster_at]._tAnimData,
      towner[monster_at]._tAnimFrame,
      towner[monster_at]._tAnimWidth,
      0,
      8);
  }
  if ( dMonster[x][y] > 0 )
  {
    monster_at = dMonster[x][y] - 1;
    screen_xb = sx - towner[monster_at]._tAnimWidth2;
    if ( pcursmonst == monster_at )
      CelDrawHdrClrHL(
        166,
        screen_xb,
        sy,
        (BYTE *)towner[monster_at]._tAnimData,
        towner[monster_at]._tAnimFrame,
        towner[monster_at]._tAnimWidth,
        0,
        8);
    Cel2DrawHdrOnly(
      screen_xb,
      sy,
      (BYTE *)towner[monster_at]._tAnimData,
      towner[monster_at]._tAnimFrame,
      towner[monster_at]._tAnimWidth,
      0,
      8);
  }
  if ( dFlags[x][y] & 0x20 )
  {
    player_at = -(char)(dPlayer[x][y - 1] + 1);
    screen_xc = sx + plr[player_at]._pxoff - plr[player_at]._pAnimWidth2;
    screen_y = sy + plr[player_at]._pyoff;
    if ( player_at == pcursplr )
      CelDrawHdrClrHL(
        165,
        screen_xc,
        screen_y,
        (BYTE *)plr[player_at]._pAnimData,
        plr[player_at]._pAnimFrame,
        plr[player_at]._pAnimWidth,
        0,
        8);
    Cel2DrawHdrOnly(
      screen_xc,
      screen_y,
      (BYTE *)plr[player_at]._pAnimData,
      plr[player_at]._pAnimFrame,
      plr[player_at]._pAnimWidth,
      0,
      8);
    if ( some_flag && plr[player_at]._peflag )
      town_draw_clipped_e_flag(buf - 64, x - 1, y + 1, sx - 64, sy);
  }
  if ( dPlayer[x][y] > 0 )
  {
    player_at = dPlayer[x][y] - 1;
    screen_xd = sx + plr[player_at]._pxoff - plr[player_at]._pAnimWidth2;
    screen_ya = sy + plr[player_at]._pyoff;
    if ( player_at == pcursplr )
      CelDrawHdrClrHL(
        165,
        screen_xd,
        screen_ya,
        (BYTE *)plr[player_at]._pAnimData,
        plr[player_at]._pAnimFrame,
        plr[player_at]._pAnimWidth,
        0,
        8);
    Cel2DrawHdrOnly(
      screen_xd,
      screen_ya,
      (BYTE *)plr[player_at]._pAnimData,
      plr[player_at]._pAnimFrame,
      plr[player_at]._pAnimWidth,
      0,
      8);
    if ( some_flag && plr[player_at]._peflag )
      town_draw_clipped_e_flag(buf - 64, x - 1, y + 1, sx - 64, sy);
  }
  if ( dFlags[x][y] & 1 )
    DrawClippedMissile(x, y, sx, sy, 0, 8, 0);
  if ( dArch[x][y] )
    town_44A643_empty(buf, dArch[x][y]);
}

//----- (0044B001) --------------------------------------------------------
void __fastcall town_draw_lower(int x, int y, int sx, int sy, int a5, int some_flag)
{
  signed int ya; // [esp+Ch] [ebp-18h]
  signed int xa; // [esp+10h] [ebp-14h]
  SHORT *defs; // [esp+14h] [ebp-10h] MAPDST
  BYTE *buf; // [esp+18h] [ebp-Ch] MAPDST
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
      town_clear_low_buf(&gpBuffer[sx + screen_y_times_768[sy]]);
    }
    else
    {
      LOWORD(level_cel_block) = dPiece[x][y];
      if ( (_WORD)level_cel_block )
      {
        buf = &gpBuffer[sx + 32 + screen_y_times_768[sy]];
        defs = dpiece_defs_map_1[gendung_get_dpiece_num_from_coord(x, y)];
        for ( i = 1; i < 17; i += 2 )
        {
          LOWORD(level_cel_block) = defs[i];
          if ( (_WORD)level_cel_block )
            drawLowerScreen(buf);
          buf -= 24576;
        }
        town_draw_clipped_town(&gpBuffer[sx + screen_y_times_768[sy]], xa, ya, sx, sy, 0);
      }
      else
      {
        town_clear_low_buf(&gpBuffer[sx + screen_y_times_768[sy]]);
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
      town_clear_low_buf(&gpBuffer[sx + screen_y_times_768[sy]]);
    }
    else
    {
      LOWORD(level_cel_block) = dPiece[xa][ya];
      if ( (_WORD)level_cel_block )
      {
        buf = &gpBuffer[sx + screen_y_times_768[sy]];
        defs = dpiece_defs_map_1[gendung_get_dpiece_num_from_coord(xa, ya)];
        for ( k = 0; k < 16; k += 2 )
        {
          LOWORD(level_cel_block) = defs[k];
          if ( (_WORD)level_cel_block )
            drawLowerScreen(buf);
          LOWORD(level_cel_block) = defs[k + 1];
          if ( (_WORD)level_cel_block )
            drawLowerScreen(buf + 32);
          buf -= 24576;
        }
        town_draw_clipped_town(&gpBuffer[sx + screen_y_times_768[sy]], xa, ya, sx, sy, 1);
      }
      else
      {
        town_clear_low_buf(&gpBuffer[sx + screen_y_times_768[sy]]);
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
      town_clear_low_buf(&gpBuffer[sx + screen_y_times_768[sy]]);
    }
    else
    {
      LOWORD(level_cel_block) = dPiece[xa][ya];
      if ( (_WORD)level_cel_block )
      {
        buf = &gpBuffer[sx + screen_y_times_768[sy]];
        defs = dpiece_defs_map_1[gendung_get_dpiece_num_from_coord(xa, ya)];
        for ( l = 0; l < 16; l += 2 )
        {
          LOWORD(level_cel_block) = defs[l];
          if ( (_WORD)level_cel_block )
            drawLowerScreen(buf);
          buf -= 24576;
        }
        town_draw_clipped_town(&gpBuffer[sx + screen_y_times_768[sy]], xa, ya, sx, sy, 0);
      }
      else
      {
        town_clear_low_buf(&gpBuffer[sx + screen_y_times_768[sy]]);
      }
    }
  }
}

//----- (0044B469) --------------------------------------------------------
void __fastcall town_draw_clipped_e_flag_2(BYTE *buffer, int x, int y, int a4, int a5, int sx, int sy)
{
  SHORT *defs; // [esp+14h] [ebp-Ch]
  BYTE *buf; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  if ( a4 )
    buf = &buffer[24576 * a4];
  else
    buf = buffer;
  defs = dpiece_defs_map_1[gendung_get_dpiece_num_from_coord(x, y)];
  for ( i = 0; i < 6; ++i )
  {
    if ( i >= a4 )
    {
      LOWORD(level_cel_block) = defs[2 * i + 2];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(buf);
      LOWORD(level_cel_block) = defs[2 * i + 3];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(buf + 32);
    }
    buf -= 24576;
  }
  if ( a5 < 8 )
    town_draw_clipped_town_2(buffer, x, y, a4, a5, sx, sy, 0);
}

//----- (0044B56F) --------------------------------------------------------
void __fastcall town_draw_clipped_town_2(BYTE *buffer, int x, int y, int a4, int a5, int sx, int sy, int some_flag)
{
  int screen_x; // [esp+14h] [ebp-10h]
  int screen_xa; // [esp+14h] [ebp-10h]
  int screen_xb; // [esp+14h] [ebp-10h]
  int screen_xc; // [esp+14h] [ebp-10h]
  int screen_xd; // [esp+14h] [ebp-10h]
  int screen_y; // [esp+18h] [ebp-Ch]
  int screen_ya; // [esp+18h] [ebp-Ch]
  char item_at; // [esp+1Ch] [ebp-8h]
  char player_at; // [esp+1Ch] [ebp-8h] MAPDST
  int monster_at; // [esp+20h] [ebp-4h] MAPDST

  if ( dItem[x][y] )
  {
    item_at = dItem[x][y] - 1;
    screen_x = sx - item[item_at]._iAnimWidth2;
    if ( pcursitem == item_at )
      CelDrawHdrClrHL(
        181,
        screen_x,
        sy,
        item[item_at]._iAnimData,
        item[item_at]._iAnimFrame,
        item[item_at]._iAnimWidth,
        a5,
        8);
    Cel2DrawHdrOnly(screen_x, sy, item[item_at]._iAnimData, item[item_at]._iAnimFrame, item[item_at]._iAnimWidth, a5, 8);
  }
  if ( dFlags[x][y] & 0x10 )
  {
    monster_at = -(dMonster[x][y - 1] + 1);
    screen_xa = sx - towner[-(dMonster[x][y - 1] + 1)]._tAnimWidth2;
    if ( pcursmonst == monster_at )
      CelDrawHdrClrHL(
        166,
        screen_xa,
        sy,
        (BYTE *)towner[-(dMonster[x][y - 1] + 1)]._tAnimData,
        towner[-(dMonster[x][y - 1] + 1)]._tAnimFrame,
        towner[-(dMonster[x][y - 1] + 1)]._tAnimWidth,
        a5,
        8);
    Cel2DrawHdrOnly(
      screen_xa,
      sy,
      (BYTE *)towner[monster_at]._tAnimData,
      towner[monster_at]._tAnimFrame,
      towner[monster_at]._tAnimWidth,
      a5,
      8);
  }
  if ( dMonster[x][y] > 0 )
  {
    monster_at = dMonster[x][y] - 1;
    screen_xb = sx - towner[monster_at]._tAnimWidth2;
    if ( pcursmonst == monster_at )
      CelDrawHdrClrHL(
        166,
        screen_xb,
        sy,
        (BYTE *)towner[monster_at]._tAnimData,
        towner[monster_at]._tAnimFrame,
        towner[monster_at]._tAnimWidth,
        a5,
        8);
    Cel2DrawHdrOnly(
      screen_xb,
      sy,
      (BYTE *)towner[monster_at]._tAnimData,
      towner[monster_at]._tAnimFrame,
      towner[monster_at]._tAnimWidth,
      a5,
      8);
  }
  if ( dFlags[x][y] & 0x20 )
  {
    player_at = -(char)(dPlayer[x][y - 1] + 1);
    screen_xc = sx + plr[player_at]._pxoff - plr[player_at]._pAnimWidth2;
    screen_y = sy + plr[player_at]._pyoff;
    if ( player_at == pcursplr )
      CelDrawHdrClrHL(
        165,
        screen_xc,
        screen_y,
        (BYTE *)plr[player_at]._pAnimData,
        plr[player_at]._pAnimFrame,
        plr[player_at]._pAnimWidth,
        a5,
        8);
    Cel2DrawHdrOnly(
      screen_xc,
      screen_y,
      (BYTE *)plr[player_at]._pAnimData,
      plr[player_at]._pAnimFrame,
      plr[player_at]._pAnimWidth,
      a5,
      8);
    if ( some_flag && plr[player_at]._peflag )
      town_draw_clipped_e_flag_2(buffer - 64, x - 1, y + 1, a4, a5, sx - 64, sy);
  }
  if ( dPlayer[x][y] > 0 )
  {
    player_at = dPlayer[x][y] - 1;
    screen_xd = sx + plr[player_at]._pxoff - plr[player_at]._pAnimWidth2;
    screen_ya = sy + plr[player_at]._pyoff;
    if ( player_at == pcursplr )
      CelDrawHdrClrHL(
        165,
        screen_xd,
        screen_ya,
        (BYTE *)plr[player_at]._pAnimData,
        plr[player_at]._pAnimFrame,
        plr[player_at]._pAnimWidth,
        a5,
        8);
    Cel2DrawHdrOnly(
      screen_xd,
      screen_ya,
      (BYTE *)plr[player_at]._pAnimData,
      plr[player_at]._pAnimFrame,
      plr[player_at]._pAnimWidth,
      a5,
      8);
    if ( some_flag && plr[player_at]._peflag )
      town_draw_clipped_e_flag_2(buffer - 64, x - 1, y + 1, a4, a5, sx - 64, sy);
  }
  if ( dFlags[x][y] & 1 )
    DrawClippedMissile(x, y, sx, sy, a5, 8, 0);
  if ( dArch[x][y] )
    town_44A643_empty(&buffer[screen_y_times_768[16 * a5]], dArch[x][y]);
}

//----- (0044BD25) --------------------------------------------------------
void __fastcall town_draw_lower_2(int x, int y, int sx, int sy, int a5, int a6, int some_flag)
{
  signed int ya; // [esp+Ch] [ebp-1Ch]
  signed int xa; // [esp+10h] [ebp-18h]
  SHORT *defs; // [esp+14h] [ebp-14h] MAPDST
  BYTE *buf; // [esp+18h] [ebp-10h] MAPDST
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
      town_clear_low_buf(&gpBuffer[sx + screen_y_times_768[sy]]);
    }
    else
    {
      LOWORD(level_cel_block) = dPiece[x][y];
      if ( (_WORD)level_cel_block )
      {
        buf = &gpBuffer[sx - 24544 + screen_y_times_768[sy]];
        defs = dpiece_defs_map_1[gendung_get_dpiece_num_from_coord(x, y)];
        for ( i = 0; i < 7; ++i )
        {
          if ( i >= a6 )
          {
            LOWORD(level_cel_block) = defs[2 * i + 3];
            if ( (_WORD)level_cel_block )
              drawLowerScreen(buf);
          }
          buf -= 24576;
        }
        if ( v15 < 8 )
          town_draw_clipped_town_2(&gpBuffer[sx + screen_y_times_768[sy]], xa, ya, a6, v15, sx, sy, 0);
      }
      else
      {
        town_clear_low_buf(&gpBuffer[sx + screen_y_times_768[sy]]);
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
      town_clear_low_buf(&gpBuffer[sx + screen_y_times_768[sy]]);
    }
    else
    {
      LOWORD(level_cel_block) = dPiece[xa][ya];
      if ( (_WORD)level_cel_block )
      {
        buf = &gpBuffer[sx - 24576 + screen_y_times_768[sy]];
        defs = dpiece_defs_map_1[gendung_get_dpiece_num_from_coord(xa, ya)];
        for ( k = 0; k < 7; ++k )
        {
          if ( k >= a6 )
          {
            LOWORD(level_cel_block) = defs[2 * k + 2];
            if ( (_WORD)level_cel_block )
              drawLowerScreen(buf);
            LOWORD(level_cel_block) = defs[2 * k + 3];
            if ( (_WORD)level_cel_block )
              drawLowerScreen(buf + 32);
          }
          buf -= 24576;
        }
        if ( v15 < 8 )
          town_draw_clipped_town_2(&gpBuffer[sx + screen_y_times_768[sy] + -12288 * v15], xa, ya, a6, v15, sx, sy, 1);
      }
      else
      {
        town_clear_low_buf(&gpBuffer[sx + screen_y_times_768[sy]]);
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
      town_clear_low_buf(&gpBuffer[sx + screen_y_times_768[sy]]);
    }
    else
    {
      LOWORD(level_cel_block) = dPiece[xa][ya];
      if ( (_WORD)level_cel_block )
      {
        buf = &gpBuffer[sx - 24576 + screen_y_times_768[sy]];
        defs = dpiece_defs_map_1[gendung_get_dpiece_num_from_coord(xa, ya)];
        for ( l = 0; l < 7; ++l )
        {
          if ( l >= a6 )
          {
            LOWORD(level_cel_block) = defs[2 * l + 2];
            if ( (_WORD)level_cel_block )
              drawLowerScreen(buf);
          }
          buf -= 24576;
        }
        if ( v15 < 8 )
          town_draw_clipped_town_2(&gpBuffer[sx + screen_y_times_768[sy]], xa, ya, a6, v15, sx, sy, 0);
      }
      else
      {
        town_clear_low_buf(&gpBuffer[sx + screen_y_times_768[sy]]);
      }
    }
  }
}

//----- (0044C20B) --------------------------------------------------------
void __fastcall town_draw_e_flag(BYTE *buffer, int x, int y, int a4, int dir, int sx, int sy)
{
  SHORT *defs; // [esp+14h] [ebp-Ch]
  BYTE *buf; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  buf = buffer;
  defs = dpiece_defs_map_1[gendung_get_dpiece_num_from_coord(x, y)];
  for ( i = 0; i < 7; ++i )
  {
    if ( i <= a4 )
    {
      LOWORD(level_cel_block) = defs[2 * i];
      if ( (_WORD)level_cel_block )
        drawUpperScreen(buf);
      LOWORD(level_cel_block) = defs[2 * i + 1];
      if ( (_WORD)level_cel_block )
        drawUpperScreen(buf + 32);
    }
    buf -= 24576;
  }
  town_draw_town_all(buffer, x, y, a4, dir, sx, sy, 0);
}

//----- (0044C2E8) --------------------------------------------------------
void __fastcall town_draw_town_all(BYTE *buffer, int x, int y, int a4, int dir, int sx, int sy, int some_flag)
{
  int screen_x; // [esp+14h] [ebp-10h]
  int screen_xa; // [esp+14h] [ebp-10h]
  int screen_xb; // [esp+14h] [ebp-10h]
  int screen_xc; // [esp+14h] [ebp-10h]
  int screen_xd; // [esp+14h] [ebp-10h]
  int screen_y; // [esp+18h] [ebp-Ch]
  int screen_ya; // [esp+18h] [ebp-Ch]
  char item_at; // [esp+1Ch] [ebp-8h]
  char player_at; // [esp+1Ch] [ebp-8h] MAPDST
  int monster_at; // [esp+20h] [ebp-4h] MAPDST

  if ( dItem[x][y] )
  {
    item_at = dItem[x][y] - 1;
    screen_x = sx - item[item_at]._iAnimWidth2;
    if ( pcursitem == item_at )
      CelDecodeClr(
        181,
        screen_x,
        sy,
        item[item_at]._iAnimData,
        item[item_at]._iAnimFrame,
        item[item_at]._iAnimWidth,
        0,
        dir);
    assert(item[item_at]._iAnimData, "TOWN.CPP", 663);
    CelDrawHdrOnly(screen_x, sy, item[item_at]._iAnimData, item[item_at]._iAnimFrame, item[item_at]._iAnimWidth, 0, dir);
  }
  if ( dFlags[x][y] & 0x10 )
  {
    monster_at = -(dMonster[x][y - 1] + 1);
    screen_xa = sx - towner[-(dMonster[x][y - 1] + 1)]._tAnimWidth2;
    if ( pcursmonst == monster_at )
      CelDecodeClr(
        166,
        screen_xa,
        sy,
        (BYTE *)towner[-(dMonster[x][y - 1] + 1)]._tAnimData,
        towner[-(dMonster[x][y - 1] + 1)]._tAnimFrame,
        towner[-(dMonster[x][y - 1] + 1)]._tAnimWidth,
        0,
        dir);
    assert(towner[monster_at]._tAnimData, "TOWN.CPP", 671);
    CelDrawHdrOnly(
      screen_xa,
      sy,
      (BYTE *)towner[monster_at]._tAnimData,
      towner[monster_at]._tAnimFrame,
      towner[monster_at]._tAnimWidth,
      0,
      dir);
  }
  if ( dMonster[x][y] > 0 )
  {
    monster_at = dMonster[x][y] - 1;
    screen_xb = sx - towner[monster_at]._tAnimWidth2;
    if ( pcursmonst == monster_at )
      CelDecodeClr(
        166,
        screen_xb,
        sy,
        (BYTE *)towner[monster_at]._tAnimData,
        towner[monster_at]._tAnimFrame,
        towner[monster_at]._tAnimWidth,
        0,
        dir);
    assert(towner[monster_at]._tAnimData, "TOWN.CPP", 679);
    CelDrawHdrOnly(
      screen_xb,
      sy,
      (BYTE *)towner[monster_at]._tAnimData,
      towner[monster_at]._tAnimFrame,
      towner[monster_at]._tAnimWidth,
      0,
      dir);
  }
  if ( dFlags[x][y] & 0x20 )
  {
    player_at = -(char)(dPlayer[x][y - 1] + 1);
    screen_xc = sx + plr[player_at]._pxoff - plr[player_at]._pAnimWidth2;
    screen_y = sy + plr[player_at]._pyoff;
    if ( player_at == pcursplr )
      CelDecodeClr(
        165,
        screen_xc,
        screen_y,
        (BYTE *)plr[player_at]._pAnimData,
        plr[player_at]._pAnimFrame,
        plr[player_at]._pAnimWidth,
        0,
        dir);
    assert(plr[player_at]._pAnimData, "TOWN.CPP", 687);
    CelDrawHdrOnly(
      screen_xc,
      screen_y,
      (BYTE *)plr[player_at]._pAnimData,
      plr[player_at]._pAnimFrame,
      plr[player_at]._pAnimWidth,
      0,
      dir);
    if ( some_flag && plr[player_at]._peflag )
      town_draw_e_flag(buffer - 64, x - 1, y + 1, a4, dir, sx - 64, sy);
  }
  if ( dPlayer[x][y] > 0 )
  {
    player_at = dPlayer[x][y] - 1;
    screen_xd = sx + plr[player_at]._pxoff - plr[player_at]._pAnimWidth2;
    screen_ya = sy + plr[player_at]._pyoff;
    if ( player_at == pcursplr )
      CelDecodeClr(
        165,
        screen_xd,
        screen_ya,
        (BYTE *)plr[player_at]._pAnimData,
        plr[player_at]._pAnimFrame,
        plr[player_at]._pAnimWidth,
        0,
        dir);
    assert(plr[player_at]._pAnimData, "TOWN.CPP", 700);
    CelDrawHdrOnly(
      screen_xd,
      screen_ya,
      (BYTE *)plr[player_at]._pAnimData,
      plr[player_at]._pAnimFrame,
      plr[player_at]._pAnimWidth,
      0,
      dir);
    if ( some_flag && plr[player_at]._peflag )
      town_draw_e_flag(buffer - 64, x - 1, y + 1, a4, dir, sx - 64, sy);
  }
  if ( dFlags[x][y] & 1 )
    DrawMissile(x, y, sx, sy, 0, dir, 0);
  if ( dArch[x][y] )
    town_44A6F5_empty((int)buffer, dArch[x][y]);
}

//----- (0044CB90) --------------------------------------------------------
void __fastcall town_draw_upper(int x, int y, int sx, int sy, int a5, int a6, int some_flag)
{
  signed int ya; // [esp+Ch] [ebp-1Ch]
  signed int xa; // [esp+10h] [ebp-18h]
  SHORT *defs; // [esp+14h] [ebp-14h] MAPDST
  BYTE *buf; // [esp+18h] [ebp-10h] MAPDST
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
      town_clear_upper_buf(&gpBuffer[sx + screen_y_times_768[sy]]);
    }
    else
    {
      LOWORD(level_cel_block) = dPiece[x][y];
      if ( (_WORD)level_cel_block )
      {
        buf = &gpBuffer[sx + 32 + screen_y_times_768[sy]];
        defs = dpiece_defs_map_1[gendung_get_dpiece_num_from_coord(x, y)];
        for ( i = 0; i < 7; ++i )
        {
          if ( a6 >= i )
          {
            LOWORD(level_cel_block) = defs[2 * i + 1];
            if ( (_WORD)level_cel_block )
              drawUpperScreen(buf);
          }
          buf -= 24576;
        }
        town_draw_town_all(&gpBuffer[sx + screen_y_times_768[sy]], xa, ya, a6, dir, sx, sy, 0);
      }
      else
      {
        town_clear_upper_buf(&gpBuffer[sx + screen_y_times_768[sy]]);
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
      town_clear_upper_buf(&gpBuffer[sx + screen_y_times_768[sy]]);
    }
    else
    {
      LOWORD(level_cel_block) = dPiece[xa][ya];
      if ( (_WORD)level_cel_block )
      {
        buf = &gpBuffer[sx + screen_y_times_768[sy]];
        defs = dpiece_defs_map_1[gendung_get_dpiece_num_from_coord(xa, ya)];
        for ( k = 0; k < 7; ++k )
        {
          if ( a6 >= k )
          {
            LOWORD(level_cel_block) = defs[2 * k];
            if ( (_WORD)level_cel_block )
              drawUpperScreen(buf);
            LOWORD(level_cel_block) = defs[2 * k + 1];
            if ( (_WORD)level_cel_block )
              drawUpperScreen(buf + 32);
          }
          buf -= 24576;
        }
        town_draw_town_all(&gpBuffer[sx + screen_y_times_768[sy]], xa, ya, a6, dir, sx, sy, 1);
      }
      else
      {
        town_clear_upper_buf(&gpBuffer[sx + screen_y_times_768[sy]]);
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
      town_clear_upper_buf(&gpBuffer[sx + screen_y_times_768[sy]]);
    }
    else
    {
      LOWORD(level_cel_block) = dPiece[xa][ya];
      if ( (_WORD)level_cel_block )
      {
        buf = &gpBuffer[sx + screen_y_times_768[sy]];
        defs = dpiece_defs_map_1[gendung_get_dpiece_num_from_coord(xa, ya)];
        for ( l = 0; l < 7; ++l )
        {
          if ( a6 >= l )
          {
            LOWORD(level_cel_block) = defs[2 * l];
            if ( (_WORD)level_cel_block )
              drawUpperScreen(buf);
          }
          buf -= 24576;
        }
        town_draw_town_all(&gpBuffer[sx + screen_y_times_768[sy]], xa, ya, a6, dir, sx, sy, 0);
      }
      else
      {
        town_clear_upper_buf(&gpBuffer[sx + screen_y_times_768[sy]]);
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
  gpBufEnd = &gpBuffer[screen_y_times_768[160]];
  for ( a6 = 0; a6 < 7; ++a6 )
  {
    town_draw_upper(xa, ya++, sx, sy, a5, a6, 0);
    v2 = sx - 32;
    v3 = sy + 16;
    town_draw_upper(xa++, ya, v2, v3, a5, a6, 1);
    sx = v2 + 32;
    sy = v3 + 16;
  }
  gpBufEnd = &gpBuffer[screen_y_times_768[512]];
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
  BYTE *dst; // edi
  BYTE *src; // esi
  BYTE *dst_row2; // ebx
  signed int i; // edx
  signed int j; // ecx
  __int16 v13; // ax
  int v14; // eax
  int ya; // [esp+10h] [ebp-28h]
  int xa; // [esp+14h] [ebp-24h]
  signed int v17; // [esp+18h] [ebp-20h]
  signed int dst_off; // [esp+1Ch] [ebp-1Ch]
  int a6; // [esp+20h] [ebp-18h]
  signed int a6a; // [esp+20h] [ebp-18h]
  int a6b; // [esp+20h] [ebp-18h]
  signed int w; // [esp+24h] [ebp-14h]
  signed int src_off; // [esp+28h] [ebp-10h]
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
  gpBufEnd = &gpBuffer[screen_y_times_768[143]];
  for ( a6 = 0; a6 < 7; ++a6 )
  {
    town_draw_upper(xa, ya++, sx, sy, a5, a6, 0);
    v2 = sx - 32;
    v3 = sy + 16;
    town_draw_upper(xa++, ya, v2, v3, a5, a6, 1);
    sx = v2 + 32;
    sy = v3 + 16;
  }
  gpBufEnd = &gpBuffer[screen_y_times_768[320]];
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
    src_off = 245168;
    dst_off = 392064;
    w = 160;
  }
  else if ( invflag || sbookflag )
  {
    src_off = 245168;
    dst_off = 391744;
    w = 160;
  }
  else
  {
    src_off = 245088;
    dst_off = 391744;
    w = 320;
  }
  dst = &gpBuffer[dst_off];
  src = &gpBuffer[src_off];
  dst_row2 = &gpBuffer[dst_off + 768];
  for (i = 176; i; --i)
  {
    for (j = w; j; --j)
    {
      LOBYTE(v13) = *src++;
      HIBYTE(v13) = v13;
      *(_WORD *)dst = v13;
      *(_WORD *)dst_row2 = v13;
      dst += 2;
      dst_row2 += 2;
    }
    src += -w - 768;
    v14 = 2 * (w + 768);
    dst_row2 -= v14;
    dst -= v14;
  }
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
  SHORT v0; // cx
  unsigned __int16 v1; // cx
  int c; // eax MAPDST
  SHORT *defs; // [esp+18h] [ebp-48h] MAPDST
  int y; // [esp+1Ch] [ebp-44h]
  int ya; // [esp+1Ch] [ebp-44h]
  int piece; // [esp+20h] [ebp-40h]
  int x; // [esp+24h] [ebp-3Ch]
  int xa; // [esp+24h] [ebp-3Ch]
  int x2; // [esp+28h] [ebp-38h]
  int x2a; // [esp+28h] [ebp-38h] MAPDST
  int y2; // [esp+2Ch] [ebp-34h]
  int y2a; // [esp+2Ch] [ebp-34h] MAPDST
  __int16 tmpflag[16]; // [esp+30h] [ebp-30h]
  int i; // [esp+50h] [ebp-10h]
  int j; // [esp+54h] [ebp-Ch]
  char *lvlpieces; // [esp+58h] [ebp-8h]
  int def; // [esp+5Ch] [ebp-4h]

  for ( y = 0; y < 112; ++y )
  {
    for ( x = 0; x < 112; ++x )
    {
      piece = dPiece[x][y];
      defs = dpiece_defs_map_1[gendung_get_dpiece_num_from_coord(x, y)];
      if ( piece )
      {
        lvlpieces = (char *)pLevelPieces + 32 * (piece - 1);
        for ( i = 0; i < 16; ++i )
          defs[i] = *(_WORD *)&lvlpieces[2 * ((i & 1) + 14 - (i & 0xE))];
      }
      else
      {
        for ( i = 0; i < 16; ++i )
          defs[i] = 0;
      }
    }
  }
  for ( ya = 0; ya < 112; ++ya )
  {
    for ( xa = 0; xa < 112; ++xa )
    {
      defs = dpiece_defs_map_1[gendung_get_dpiece_num_from_coord(xa, ya)];
      for ( i = 0; i < 16; ++i )
        tmpflag[i] = 0;
      v0 = *defs;
      def = (unsigned __int16)*defs;
      if ( (HIBYTE(v0) & 0x70) == 64 && def )
        tmpflag[0] = 1;
      v1 = defs[1];
      def = v1;
      if ( (HIBYTE(v1) & 0x70) == 80 && def )
        tmpflag[1] = 1;
      for ( i = 2; i < 16; ++i )
      {
        def = (unsigned __int16)defs[i];
        if ( !(def & 0x7000) && def )
        {
          tmpflag[i] = 1;
          x2 = xa;
          y2 = ya;
          for ( j = i - 2; j >= 0 && x2 > 0 && y2 > 0; j -= 2 )
          {
            c = gendung_get_dpiece_num_from_coord(--x2, --y2);
            dpiece_defs_map_1[c][j] = 0;
          }
        }
      }
      for ( i = 0; i < 13; i += 2 )
      {
        if ( *(_DWORD *)&tmpflag[i] & 0xFFFF && *(_DWORD *)&tmpflag[i + 2] & 0xFFFF )
        {
          x2a = xa - 1;
          y2a = ya;
          for ( j = i + 1; j >= 0 && x2a >= 0 && y2a >= 0; j -= 2 )
          {
            c = gendung_get_dpiece_num_from_coord(x2a, y2a);
            dpiece_defs_map_1[c][j] = 0;
            --x2a;
            --y2a;
          }
        }
      }
      for ( i = 1; i < 14; i += 2 )
      {
        if ( *(_DWORD *)&tmpflag[i] & 0xFFFF && *(_DWORD *)&tmpflag[i + 2] & 0xFFFF )
        {
          x2a = xa;
          y2a = ya - 1;
          for ( j = i + 1; j >= 0 && x2a >= 0 && y2a >= 0; j -= 2 )
          {
            c = gendung_get_dpiece_num_from_coord(x2a, y2a);
            dpiece_defs_map_1[c][j] = 0;
            --x2a;
            --y2a;
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
  int xx; // [esp+14h] [ebp-24h]
  int i; // [esp+18h] [ebp-20h]
  int j; // [esp+1Ch] [ebp-1Ch]
  int yy; // [esp+20h] [ebp-18h]
  int v14; // [esp+24h] [ebp-14h]
  signed int ii; // [esp+28h] [ebp-10h]
  int v16; // [esp+2Ch] [ebp-Ch]
  int v17; // [esp+30h] [ebp-8h]
  int v18; // [esp+34h] [ebp-4h]

  ii = 2;
  yy = yi;
  for ( i = 0; i < h; ++i )
  {
    xx = xi;
    for ( j = 0; j < w; ++j )
    {
      v6 = pSector[ii];
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
      dPiece[xx][yy] = v18;
      dPiece[xx + 1][yy] = v17;
      dPiece[xx][yy + 1] = v16;
      dPiece[xx + 1][yy + 1] = v14;
      xx += 2;
      ++ii;
    }
    yy += 2;
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
  P3Tiles = LoadFileInMem("Levels\\TownData\\Town.TIL", 0, 1344, "TOWN.CPP");
  pSector = LoadFileInMem("Levels\\TownData\\Sector1s.DUN", 0, 1347, "TOWN.CPP");
  T_FillSector((WORD *)P3Tiles, (WORD *)pSector, 46, 46, 25, 25);
  mem_free_dbg(pSector, 1349, "TOWN.CPP");
  v2 = LoadFileInMem("Levels\\TownData\\Sector2s.DUN", 0, 1351, "TOWN.CPP");
  T_FillSector((WORD *)P3Tiles, (WORD *)v2, 46, 0, 25, 23);
  mem_free_dbg(v2, 1353, "TOWN.CPP");
  v3 = LoadFileInMem("Levels\\TownData\\Sector3s.DUN", 0, 1355, "TOWN.CPP");
  T_FillSector((WORD *)P3Tiles, (WORD *)v3, 0, 46, 23, 25);
  mem_free_dbg(v3, 1357, "TOWN.CPP");
  v4 = LoadFileInMem("Levels\\TownData\\Sector4s.DUN", 0, 1359, "TOWN.CPP");
  T_FillSector((WORD *)P3Tiles, (WORD *)v4, 0, 0, 23, 23);
  mem_free_dbg(v4, 1361, "TOWN.CPP");
  mem_free_dbg(P3Tiles, 1363, "TOWN.CPP");
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

