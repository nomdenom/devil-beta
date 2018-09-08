#include "all.h"

//----- (004880B0) --------------------------------------------------------
void __fastcall DrawMissile(int x, int y, int sx, int sy, int a5, int a6, int del_flag)
{
  int v9; // [esp+14h] [ebp-10h]
  int v10; // [esp+14h] [ebp-10h]
  int i; // [esp+18h] [ebp-Ch]
  int screen_y; // [esp+1Ch] [ebp-8h]
  int screen_ya; // [esp+1Ch] [ebp-8h]
  int screen_x; // [esp+20h] [ebp-4h]
  int screen_xa; // [esp+20h] [ebp-4h]

  if ( dMissile[x][y] == -1 )
  {
    for ( i = 0; i < nummissiles; ++i )
    {
      v10 = missileactive[i];
      if ( missile[v10]._mix == x && missile[v10]._miy == y && missile[v10]._miPreFlag == del_flag )
      {
        screen_xa = sx + missile[v10]._mixoff - missile[v10]._miAnimWidth2;
        screen_ya = sy + missile[v10]._miyoff;
        if ( missile[v10]._miUniqTrans )
        {
          CelDrawHdrLightRed(
            screen_xa,
            screen_ya,
            (char *)missile[v10]._miAnimData,
            missile[v10]._miAnimFrame,
            missile[v10]._miAnimWidth,
            a5,
            a6,
            missile[v10]._miUniqTrans + 3);
        }
        else if ( missile[v10]._miLightFlag )
        {
          CelDecodeHdrLightOnly(
            screen_xa,
            screen_ya,
            (char *)missile[v10]._miAnimData,
            missile[v10]._miAnimFrame,
            missile[v10]._miAnimWidth,
            a5,
            a6);
        }
        else
        {
          assert(missile[v10]._miAnimData, "SCROLLRT.CPP", 142);
          CelDrawHdrOnly(
            screen_xa,
            screen_ya,
            (char *)missile[v10]._miAnimData,
            missile[v10]._miAnimFrame,
            missile[v10]._miAnimWidth,
            a5,
            a6);
        }
      }
    }
  }
  else
  {
    v9 = dMissile[x][y] - 1;
    if ( missile[v9]._miPreFlag == del_flag )
    {
      screen_x = sx + missile[v9]._mixoff - missile[v9]._miAnimWidth2;
      screen_y = sy + missile[v9]._miyoff;
      if ( missile[v9]._miUniqTrans )
      {
        CelDrawHdrLightRed(
          screen_x,
          screen_y,
          (char *)missile[v9]._miAnimData,
          missile[v9]._miAnimFrame,
          missile[v9]._miAnimWidth,
          a5,
          a6,
          missile[v9]._miUniqTrans + 3);
      }
      else if ( missile[v9]._miLightFlag )
      {
        CelDecodeHdrLightOnly(
          screen_x,
          screen_y,
          (char *)missile[v9]._miAnimData,
          missile[v9]._miAnimFrame,
          missile[v9]._miAnimWidth,
          a5,
          a6);
      }
      else
      {
        assert(missile[v9]._miAnimData, "SCROLLRT.CPP", 121);
        CelDrawHdrOnly(
          screen_x,
          screen_y,
          (char *)missile[v9]._miAnimData,
          missile[v9]._miAnimFrame,
          missile[v9]._miAnimWidth,
          a5,
          a6);
      }
    }
  }
}

//----- (0048855E) --------------------------------------------------------
void __fastcall DrawClippedMissile(int x, int y, int sx, int sy, int a5, int a6, int a7)
{
  int v9; // [esp+14h] [ebp-10h]
  int v10; // [esp+14h] [ebp-10h]
  int i; // [esp+18h] [ebp-Ch]
  int screen_y; // [esp+1Ch] [ebp-8h]
  int screen_ya; // [esp+1Ch] [ebp-8h]
  int screen_x; // [esp+20h] [ebp-4h]
  int screen_xa; // [esp+20h] [ebp-4h]

  if ( dMissile[x][y] == -1 )
  {
    for ( i = 0; nummissiles > i; ++i )
    {
      v10 = missileactive[i];
      if ( missile[v10]._mix == x
        && missile[v10]._miy == y
        && missile[v10]._miPreFlag == a7
        && missile[v10]._miDrawFlag == 1 )
      {
        screen_xa = sx + missile[v10]._mixoff - missile[v10]._miAnimWidth2;
        screen_ya = sy + missile[v10]._miyoff;
        if ( missile[v10]._miUniqTrans )
        {
          Cel2DrawHdrLightRed(
            screen_xa,
            screen_ya,
            (char *)missile[v10]._miAnimData,
            missile[v10]._miAnimFrame,
            missile[v10]._miAnimWidth,
            a5,
            a6,
            missile[v10]._miUniqTrans + 3);
        }
        else if ( missile[v10]._miLightFlag )
        {
          Cel2DecodeHdrLight(
            screen_xa,
            screen_ya,
            (char *)missile[v10]._miAnimData,
            missile[v10]._miAnimFrame,
            missile[v10]._miAnimWidth,
            a5,
            a6);
        }
        else
        {
          Cel2DrawHdrOnly(
            screen_xa,
            screen_ya,
            (char *)missile[v10]._miAnimData,
            missile[v10]._miAnimFrame,
            missile[v10]._miAnimWidth,
            a5,
            a6);
        }
      }
    }
  }
  else
  {
    v9 = dMissile[x][y] - 1;
    if ( missile[v9]._miPreFlag == a7 )
    {
      screen_x = sx + missile[v9]._mixoff - missile[v9]._miAnimWidth2;
      screen_y = sy + missile[v9]._miyoff;
      if ( missile[v9]._miUniqTrans )
      {
        Cel2DrawHdrLightRed(
          screen_x,
          screen_y,
          (char *)missile[v9]._miAnimData,
          missile[v9]._miAnimFrame,
          missile[v9]._miAnimWidth,
          a5,
          a6,
          missile[v9]._miUniqTrans + 3);
      }
      else if ( missile[v9]._miLightFlag )
      {
        Cel2DecodeHdrLight(
          screen_x,
          screen_y,
          (char *)missile[v9]._miAnimData,
          missile[v9]._miAnimFrame,
          missile[v9]._miAnimWidth,
          a5,
          a6);
      }
      else
      {
        Cel2DrawHdrOnly(
          screen_x,
          screen_y,
          (char *)missile[v9]._miAnimData,
          missile[v9]._miAnimFrame,
          missile[v9]._miAnimWidth,
          a5,
          a6);
      }
    }
  }
}

//----- (004889C9) --------------------------------------------------------
void __fastcall DrawView(int StartX, int StartY)
{
  char *v2; // edi
  signed int v3; // edx
  int y; // [esp+Ch] [ebp-8h]

  y = StartY;
  if ( leveltype == 4 )
  {
    v2 = gpBuffer + 122944;
    for (v3 = 352; v3; --v3)
    {
      memset(v2, 0, 0x280u);
      v2 += 768;
    }
  }
  if ( zoomflag )
    DrawGame(StartX, y);
  else
    DrawZoom(StartX, y);
  if ( automapflag )
    DrawAutomap();
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
  if ( Xhelpflag_2 )
    helpmode_draw2();
  if ( dropGoldFlag )
    DrawGoldSplit(dropGoldValue);
  if ( helpflag )
    DrawHelp();
  if ( msgflag )
    DrawDiabloMsg();
  if ( deathflag )
  {
    RedBack();
  }
  else if ( PauseMode )
  {
    gmenu_draw_pause();
  }
  DrawPlrMsg();
  gmenu_draw();
  DrawInfoBox();
  DrawLifeFlask();
  DrawManaFlask();
}

//----- (00488BAF) --------------------------------------------------------
void __fastcall DrawGame(int x, int y)
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
  v10 = 8;
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
    case 1:
      goto LABEL_9;
    case 2:
      ++a5;
LABEL_9:
      sy = Scrollinfo._syoff + 143;
      --xa;
      --ya;
      v10 = 9;
      break;
    case 3:
      goto LABEL_11;
    case 4:
      v10 = 9;
LABEL_11:
      ++a5;
      break;
    case 5:
      v10 = 9;
      break;
    case 6:
      v10 = 9;
      goto LABEL_14;
    case 7:
LABEL_14:
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
      v10 = 9;
      break;
    default:
      break;
  }
  gpBufEnd = (unsigned __int8 *)&gpBuffer[screen_y_times_768[160]];
  for ( a6 = 0; a6 < 4; ++a6 )
  {
    scrollrt_draw_upper(xa, ya++, sx, sy, a5, a6, 0);
    v2 = sx - 32;
    v3 = sy + 16;
    scrollrt_draw_upper(xa++, ya, v2, v3, a5, a6, 1);
    sx = v2 + 32;
    sy = v3 + 16;
  }
  gpBufEnd = (unsigned __int8 *)&gpBuffer[screen_y_times_768[512]];
  for ( a6a = 0; v10 > a6a; ++a6a )
  {
    scrollrt_draw_lower(xa, ya++, sx, sy, a5, 0);
    v4 = sx - 32;
    v5 = sy + 16;
    scrollrt_draw_lower(xa++, ya, v4, v5, a5, 1);
    sx = v4 + 32;
    sy = v5 + 16;
  }
  arch_draw_type = 0;
  for ( a6b = 0; a6b < 4; ++a6b )
  {
    scrollrt_draw_lower_2(xa, ya++, sx, sy, a5, a6b, 0);
    v6 = sx - 32;
    v7 = sy + 16;
    scrollrt_draw_lower_2(xa++, ya, v6, v7, a5, a6b, 1);
    sx = v6 + 32;
    sy = v7 + 16;
  }
}

//----- (00488E82) --------------------------------------------------------
void __fastcall scrollrt_draw_lower(int x, int y, int sx, int sy, int a5, int some_flag)
{
  int v6; // ST24_4
  signed int ya; // [esp+Ch] [ebp-20h]
  signed int xa; // [esp+10h] [ebp-1Ch]
  unsigned __int8 *a1; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *a1a; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *a1b; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *a1c; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *a1d; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *a1e; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *a1f; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *a1g; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *a1h; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *a1i; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *a1j; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *a1k; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *a1l; // [esp+1Ch] [ebp-10h]
  int v22; // [esp+20h] [ebp-Ch]
  _WORD *v23; // [esp+24h] [ebp-8h]
  signed int i; // [esp+28h] [ebp-4h]

  ya = y;
  xa = x;
  v23 = (_WORD *)((char *)dpiece_defs_map_1 + 32 * gendung_get_dpiece_num_from_coord(x, y));
  if ( some_flag )
  {
    if ( (unsigned int)ya < 0x70 && (unsigned int)xa < 0x70 )
    {
      level_piece_id = dPiece[xa][ya];
      light_table_index = dTransVal[xa][ya];
      if ( level_piece_id )
      {
        a1 = (unsigned __int8 *)&gpBuffer[sx + 32 + screen_y_times_768[sy]];
        cel_transparency_active = (unsigned __int8)(nTransTable[level_piece_id] & TransList[dung_map[xa][ya]]);
        arch_draw_type = 2;
        LOWORD(level_cel_block) = v23[1];
        if ( (_WORD)level_cel_block )
          drawLowerScreen(a1);
        arch_draw_type = 0;
        a1a = a1 - 24576;
        LOWORD(level_cel_block) = v23[3];
        if ( (_WORD)level_cel_block )
          drawLowerScreen(a1a);
        a1b = a1a - 24576;
        LOWORD(level_cel_block) = v23[5];
        if ( (_WORD)level_cel_block )
          drawLowerScreen(a1b);
        a1c = a1b - 24576;
        LOWORD(level_cel_block) = v23[7];
        if ( (_WORD)level_cel_block )
          drawLowerScreen(a1c);
        a1d = a1c - 24576;
        LOWORD(level_cel_block) = v23[9];
        if ( (_WORD)level_cel_block )
          drawLowerScreen(a1d);
        a1e = a1d - 24576;
        LOWORD(level_cel_block) = v23[11];
        if ( (_WORD)level_cel_block && leveltype == 4 )
          drawLowerScreen(a1e);
        scrollrt_draw_clipped_dungeon(&gpBuffer[sx + screen_y_times_768[sy]], xa, ya, sx, sy, 0);
      }
      else
      {
        world_draw_black_tile(&gpBuffer[sx + screen_y_times_768[sy]]);
      }
    }
    ++xa;
    --ya;
    sx += 64;
    v23 += 16;
    --a5;
  }
  v22 = a5;
  while ( 1 )
  {
    v6 = v22--;
    if ( !v6 || ya < 0 || xa >= 112 )
      break;
    if ( ya < 112 && xa >= 0 )
    {
      level_piece_id = dPiece[xa][ya];
      light_table_index = dTransVal[xa][ya];
      if ( level_piece_id )
      {
        a1f = (unsigned __int8 *)&gpBuffer[sx + screen_y_times_768[sy]];
        cel_transparency_active = (unsigned __int8)(nTransTable[level_piece_id] & TransList[dung_map[xa][ya]]);
        arch_draw_type = 1;
        LOWORD(level_cel_block) = *v23;
        if ( (_WORD)level_cel_block )
          drawLowerScreen(a1f);
        arch_draw_type = 2;
        LOWORD(level_cel_block) = v23[1];
        if ( (_WORD)level_cel_block )
          drawLowerScreen(a1f + 32);
        arch_draw_type = 0;
        for ( i = 2; i < gendung_567144; i += 2 )
        {
          a1f -= 24576;
          LOWORD(level_cel_block) = v23[i];
          if ( (_WORD)level_cel_block )
            drawLowerScreen(a1f);
          LOWORD(level_cel_block) = v23[i + 1];
          if ( (_WORD)level_cel_block )
            drawLowerScreen(a1f + 32);
        }
        scrollrt_draw_clipped_dungeon(&gpBuffer[sx + screen_y_times_768[sy]], xa, ya, sx, sy, 0);
      }
      else
      {
        world_draw_black_tile(&gpBuffer[sx + screen_y_times_768[sy]]);
      }
    }
    ++xa;
    --ya;
    sx += 64;
    v23 += 16;
  }
  if ( some_flag && (unsigned int)ya < 0x70 && (unsigned int)xa < 0x70 )
  {
    level_piece_id = dPiece[xa][ya];
    light_table_index = dTransVal[xa][ya];
    if ( level_piece_id )
    {
      a1g = (unsigned __int8 *)&gpBuffer[sx + screen_y_times_768[sy]];
      cel_transparency_active = (unsigned __int8)(nTransTable[level_piece_id] & TransList[dung_map[xa][ya]]);
      arch_draw_type = 1;
      LOWORD(level_cel_block) = *v23;
      if ( (_WORD)level_cel_block )
        drawLowerScreen(a1g);
      arch_draw_type = 0;
      a1h = a1g - 24576;
      LOWORD(level_cel_block) = v23[2];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(a1h);
      a1i = a1h - 24576;
      LOWORD(level_cel_block) = v23[4];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(a1i);
      a1j = a1i - 24576;
      LOWORD(level_cel_block) = v23[6];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(a1j);
      a1k = a1j - 24576;
      LOWORD(level_cel_block) = v23[8];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(a1k);
      a1l = a1k - 24576;
      LOWORD(level_cel_block) = v23[10];
      if ( (_WORD)level_cel_block && leveltype == 4 )
        drawLowerScreen(a1l);
      scrollrt_draw_clipped_dungeon(&gpBuffer[sx + screen_y_times_768[sy]], xa, ya, sx, sy, 0);
    }
    else
    {
      world_draw_black_tile(&gpBuffer[sx + screen_y_times_768[sy]]);
    }
  }
}

//----- (00489531) --------------------------------------------------------
void __fastcall scrollrt_draw_clipped_dungeon(char *a1, int sx, int sy, int a4, int a5, int a6)
{
  ItemStruct *v8; // [esp+14h] [ebp-50h]
  MonsterStruct *v9; // [esp+18h] [ebp-4Ch]
  PlayerStruct *v10; // [esp+1Ch] [ebp-48h]
  MonsterStruct *v11; // [esp+20h] [ebp-44h]
  PlayerStruct *v12; // [esp+24h] [ebp-40h]
  ItemStruct *v13; // [esp+28h] [ebp-3Ch]
  DeadStruct *v14; // [esp+2Ch] [ebp-38h]
  char v15; // [esp+30h] [ebp-34h]
  int v16; // [esp+34h] [ebp-30h]
  int screen_x; // [esp+38h] [ebp-2Ch]
  int screen_xa; // [esp+38h] [ebp-2Ch]
  int screen_xb; // [esp+38h] [ebp-2Ch]
  int screen_xc; // [esp+38h] [ebp-2Ch]
  int screen_xd; // [esp+38h] [ebp-2Ch]
  char v22; // [esp+3Ch] [ebp-28h]
  char v23; // [esp+40h] [ebp-24h]
  char v24; // [esp+44h] [ebp-20h]
  char v25; // [esp+48h] [ebp-1Ch]
  int v26; // [esp+4Ch] [ebp-18h]
  char v27; // [esp+50h] [ebp-14h]
  char v28; // [esp+54h] [ebp-10h]
  char v29; // [esp+58h] [ebp-Ch]
  int py; // [esp+5Ch] [ebp-8h]
  int pya; // [esp+5Ch] [ebp-8h]
  char v32; // [esp+60h] [ebp-4h]

  v28 = dFlags[sx][sy];
  v25 = dDead[sx][sy];
  v29 = dObject[sx][sy];
  v32 = dItem[sx][sy];
  v27 = dPlayer[sx][sy];
  v23 = dArch[sx][sy];
  v22 = dung_map[sx][sy];
  v26 = dMonster[sx][sy];
  v24 = dPlayer[sx][sy - 1];
  v16 = dMonster[sx][sy - 1];
  if ( visiondebug && v28 & 0x40 )
    Cel2DecodeHdrOnly(a1, pSquareCel, 1, 64, 0, 8);
  if ( MissilePreFlag && v28 & 1 )
    DrawClippedMissile(sx, sy, a4, a5, 0, 8, 1);
  if ( lightmax > light_table_index )
  {
    if ( v25 )
    {
      v14 = &dead[(v25 & 0x1F) - 1];
      v15 = (unsigned __int8)(v25 & 0xE0) >> 5;
      screen_x = a4 - dead[(v25 & 0x1F) - 1]._deadWidth2;
      if ( dead[(v25 & 0x1F) - 1]._deadtrans )
        Cel2DrawHdrLightRed(
          screen_x,
          a5,
          (char *)v14->_deadData[v15],
          v14->_deadFrame,
          v14->_deadWidth,
          0,
          8,
          v14->_deadtrans);
      else
        Cel2DecodeHdrLight(screen_x, a5, (char *)v14->_deadData[v15], v14->_deadFrame, v14->_deadWidth, 0, 8);
    }
    if ( v29 )
      DrawClippedObject(sx, sy, a4, a5, 1, 0, 8);
  }
  if ( v32 )
  {
    v13 = &item[v32 - 1];
    if ( !v13->_iPostDraw )
    {
      screen_xa = a4 - v13->_iAnimWidth2;
      if ( v32 - 1 == pcursitem )
        CelDrawHdrClrHL(181, screen_xa, a5, (char *)v13->_iAnimData, v13->_iAnimFrame, v13->_iAnimWidth, 0, 8);
      Cel2DecodeHdrLight(screen_xa, a5, (char *)v13->_iAnimData, v13->_iAnimFrame, v13->_iAnimWidth, 0, 8);
    }
  }
  if ( v28 & 0x20 )
  {
    v12 = &plr[-(v24 + 1)];
    DrawClippedPlayer(
      -(v24 + 1),
      sx,
      sy - 1,
      a4 + plr[-v24 - 1]._pxoff - plr[-v24 - 1]._pAnimWidth2,
      a5 + plr[-v24 - 1]._pyoff,
      plr[-v24 - 1]._pAnimData,
      plr[-v24 - 1]._pAnimFrame,
      plr[-v24 - 1]._pAnimWidth,
      0,
      8);
    if ( a6 )
    {
      if ( v12->_peflag )
      {
        if ( v12->_peflag == 2 )
          scrollrt_draw_clipped_e_flag(a1 - 12384, sx - 2, sy + 1, a4 - 96, a5 - 16);
        scrollrt_draw_clipped_e_flag(a1 - 64, sx - 1, sy + 1, a4 - 64, a5);
      }
    }
  }
  if ( v28 & 0x10 && (v28 & 0x40 || plr[myplr]._pInfraFlag) )
  {
    mon_id = -(v16 + 1);
    v11 = &monster[-(v16 + 1)];
    if ( monster[-v16 - 1]._mFlags & 1 )
    {
      screen_xb = a4 + v11->_mxoff - v11->MType->flags_2;
      py = a5 + v11->_myoff;
      if ( mon_id == pcursmonst )
        CelDrawHdrClrHL(233, screen_xb, py, (char *)v11->_mAnimData, v11->_mAnimFrame, v11->MType->flags_1, 0, 8);
      DrawClippedMonster(sx, sy, screen_xb, py, mon_id, 0, 8);
      if ( a6 && v11->_meflag )
        scrollrt_draw_clipped_e_flag(a1 - 64, sx - 1, sy + 1, a4 - 64, a5);
    }
  }
  if ( v27 > 0 )
  {
    v10 = &plr[v27 - 1];
    DrawClippedPlayer(
      v27 - 1,
      sx,
      sy,
      a4 + plr[v27 - 1]._pxoff - plr[v27 - 1]._pAnimWidth2,
      a5 + plr[v27 - 1]._pyoff,
      plr[v27 - 1]._pAnimData,
      plr[v27 - 1]._pAnimFrame,
      plr[v27 - 1]._pAnimWidth,
      0,
      8);
    if ( a6 )
    {
      if ( v10->_peflag )
      {
        if ( v10->_peflag == 2 )
          scrollrt_draw_clipped_e_flag(a1 - 12384, sx - 2, sy + 1, a4 - 96, a5 - 16);
        scrollrt_draw_clipped_e_flag(a1 - 64, sx - 1, sy + 1, a4 - 64, a5);
      }
    }
  }
  if ( v26 > 0 && (v28 & 0x40 || plr[myplr]._pInfraFlag) )
  {
    mon_id = v26 - 1;
    v9 = &monster[v26 - 1];
    if ( monster[v26 - 1]._mFlags & 1 )
    {
      screen_xc = a4 + v9->_mxoff - v9->MType->flags_2;
      pya = a5 + v9->_myoff;
      if ( mon_id == pcursmonst )
        CelDrawHdrClrHL(233, screen_xc, pya, (char *)v9->_mAnimData, v9->_mAnimFrame, v9->MType->flags_1, 0, 8);
      DrawClippedMonster(sx, sy, screen_xc, pya, mon_id, 0, 8);
      if ( a6 && v9->_meflag )
        scrollrt_draw_clipped_e_flag(a1 - 64, sx - 1, sy + 1, a4 - 64, a5);
    }
  }
  if ( v28 & 1 )
    DrawClippedMissile(sx, sy, a4, a5, 0, 8, 0);
  if ( v29 && lightmax > light_table_index )
    DrawClippedObject(sx, sy, a4, a5, 0, 0, 8);
  if ( v32 )
  {
    v8 = &item[v32 - 1];
    if ( v8->_iPostDraw )
    {
      screen_xd = a4 - v8->_iAnimWidth2;
      if ( v32 - 1 == pcursitem )
        CelDrawHdrClrHL(181, screen_xd, a5, (char *)v8->_iAnimData, v8->_iAnimFrame, v8->_iAnimWidth, 0, 8);
      Cel2DecodeHdrLight(screen_xd, a5, (char *)v8->_iAnimData, v8->_iAnimFrame, v8->_iAnimWidth, 0, 8);
    }
  }
  if ( v23 )
  {
    cel_transparency_active = (unsigned __int8)TransList[v22];
    Cel2DecodeLightTrans(a1, level_special_cel, v23, 64, 0, 8);
  }
}

//----- (00489DBB) --------------------------------------------------------
void __fastcall DrawClippedMonster(int x, int y, int a3, int a4, int mon_id, int a6, int a7)
{
  char always_1; // [esp+14h] [ebp-4h]

  if ( dFlags[x][y] & 0x40 )
  {
    always_1 = 0;
    if ( monster[mon_id]._uniqtype )
      always_1 = monster[mon_id]._uniqtrans + 4;
    if ( monster[mon_id]._mmode == 15 )
      always_1 = 2;
    if ( plr[myplr]._pInfraFlag && light_table_index > 8 )
      always_1 = 1;
    if ( always_1 )
      Cel2DrawHdrLightRed(
        a3,
        a4,
        (char *)monster[mon_id]._mAnimData,
        monster[mon_id]._mAnimFrame,
        monster[mon_id].MType->flags_1,
        a6,
        a7,
        always_1);
    else
      Cel2DecodeHdrLight(
        a3,
        a4,
        (char *)monster[mon_id]._mAnimData,
        monster[mon_id]._mAnimFrame,
        monster[mon_id].MType->flags_1,
        a6,
        a7);
  }
  else
  {
    Cel2DrawHdrLightRed(
      a3,
      a4,
      (char *)monster[mon_id]._mAnimData,
      monster[mon_id]._mAnimFrame,
      monster[mon_id].MType->flags_1,
      a6,
      a7,
      1);
  }
}

//----- (00489FAE) --------------------------------------------------------
void __fastcall DrawClippedPlayer(int pnum, int x, int y, int px, int py, int animdata, int animframe, int animwidth, int a9, int a10)
{
  int v12; // [esp+14h] [ebp-4h]

  if ( dFlags[x][y] & 0x40 || plr[myplr]._pInfraFlag )
  {
    if ( pcursplr == pnum )
      CelDrawHdrClrHL(165, px, py, (char *)animdata, animframe, animwidth, a9, a10);
    if ( myplr == pnum )
    {
      Cel2DrawHdrOnly(px, py, (char *)animdata, animframe, animwidth, a9, a10);
    }
    else if ( dFlags[x][y] & 0x40 && (!plr[myplr]._pInfraFlag || light_table_index <= 8) )
    {
      v12 = light_table_index;
      if ( light_table_index < 5 )
        light_table_index = 0;
      else
        light_table_index -= 5;
      Cel2DecodeHdrLight(px, py, (char *)animdata, animframe, animwidth, a9, a10);
      light_table_index = v12;
    }
    else
    {
      Cel2DrawHdrLightRed(px, py, (char *)animdata, animframe, animwidth, a9, a10, 1);
    }
  }
}

//----- (0048A142) --------------------------------------------------------
void __fastcall DrawClippedObject(int x, int y, int a3, int a4, int pre_flag, int a6, int dir)
{
  int v7; // ST3C_4
  int v8; // ST38_4
  int screen_x; // [esp+14h] [ebp-14h]
  char v10; // [esp+18h] [ebp-10h]
  int screen_y; // [esp+1Ch] [ebp-Ch]

  if ( dObject[x][y] <= 0 )
  {
    v10 = -(char)(dObject[x][y] + 1);
    if ( object[v10]._oPreFlag != pre_flag )
      return;
    v7 = object[v10]._ox - x;
    v8 = object[v10]._oy - y;
    screen_x = 32 * v7 + a3 - object[v10]._oAnimWidth2 - 32 * v8;
    screen_y = a4 + 16 * v7 + 16 * v8;
    a6 = 0;
    dir = 8;
  }
  else
  {
    v10 = dObject[x][y] - 1;
    if ( object[v10]._oPreFlag != pre_flag )
      return;
    screen_x = a3 - object[v10]._oAnimWidth2;
    screen_y = a4;
  }
  if ( pcursobj == v10 )
    CelDrawHdrClrHL(
      194,
      screen_x,
      screen_y,
      (char *)object[v10]._oAnimData,
      object[v10]._oAnimFrame,
      object[v10]._oAnimWidth,
      a6,
      dir);
  if ( object[v10]._oLight )
    Cel2DecodeHdrLight(
      screen_x,
      screen_y,
      (char *)object[v10]._oAnimData,
      object[v10]._oAnimFrame,
      object[v10]._oAnimWidth,
      a6,
      dir);
  else
    Cel2DrawHdrOnly(
      screen_x,
      screen_y,
      (char *)object[v10]._oAnimData,
      object[v10]._oAnimFrame,
      object[v10]._oAnimWidth,
      a6,
      dir);
}

//----- (0048A39F) --------------------------------------------------------
void __fastcall scrollrt_draw_clipped_e_flag(char *buffer, int x, int y, int a4, int a5)
{
  int v7; // [esp+14h] [ebp-18h]
  _WORD *v8; // [esp+18h] [ebp-14h]
  unsigned __int8 *pbDst; // [esp+1Ch] [ebp-10h]
  int v10; // [esp+20h] [ebp-Ch]
  int v11; // [esp+24h] [ebp-8h]
  signed int i; // [esp+28h] [ebp-4h]

  v10 = light_table_index;
  v11 = cel_transparency_active;
  v7 = level_piece_id;
  level_piece_id = dPiece[x][y];
  light_table_index = dTransVal[x][y];
  cel_transparency_active = (unsigned __int8)(nTransTable[level_piece_id] & TransList[dung_map[x][y]]);
  v8 = (_WORD *)((char *)dpiece_defs_map_1 + 32 * gendung_get_dpiece_num_from_coord(x, y));
  arch_draw_type = 1;
  LOWORD(level_cel_block) = *v8;
  if ( (_WORD)level_cel_block )
    drawLowerScreen((unsigned __int8 *)buffer);
  arch_draw_type = 2;
  LOWORD(level_cel_block) = v8[1];
  if ( (_WORD)level_cel_block )
    drawLowerScreen((unsigned __int8 *)buffer + 32);
  arch_draw_type = 0;
  pbDst = (unsigned __int8 *)buffer;
  for ( i = 2; i < gendung_567144; i += 2 )
  {
    pbDst -= 24576;
    LOWORD(level_cel_block) = v8[i];
    if ( (_WORD)level_cel_block )
      drawLowerScreen(pbDst);
    LOWORD(level_cel_block) = v8[i + 1];
    if ( (_WORD)level_cel_block )
      drawLowerScreen(pbDst + 32);
  }
  scrollrt_draw_clipped_dungeon(buffer, x, y, a4, a5, 0);
  light_table_index = v10;
  cel_transparency_active = v11;
  level_piece_id = v7;
}

//----- (0048A56C) --------------------------------------------------------
void __fastcall scrollrt_draw_lower_2(int x, int y, int sx, int sy, int a5, int a6, int some_flag)
{
  int v7; // ST2C_4
  signed int ya; // [esp+Ch] [ebp-24h]
  signed int xa; // [esp+10h] [ebp-20h]
  unsigned __int8 *a1; // [esp+1Ch] [ebp-14h]
  unsigned __int8 *a1a; // [esp+1Ch] [ebp-14h]
  unsigned __int8 *a1b; // [esp+1Ch] [ebp-14h]
  int v13; // [esp+20h] [ebp-10h]
  int v14; // [esp+24h] [ebp-Ch]
  char *v15; // [esp+28h] [ebp-8h]
  int i; // [esp+2Ch] [ebp-4h]
  int v17; // [esp+2Ch] [ebp-4h]
  int j; // [esp+2Ch] [ebp-4h]

  ya = y;
  xa = x;
  v15 = (char *)dpiece_defs_map_1 + 32 * gendung_get_dpiece_num_from_coord(x, y);
  v13 = 2 * a6 + 2;
  if ( some_flag )
  {
    if ( ya >= 0 && ya < 112 && xa >= 0 && xa < 112 )
    {
      level_piece_id = dPiece[xa][ya];
      light_table_index = dTransVal[xa][ya];
      if ( level_piece_id )
      {
        a1 = (unsigned __int8 *)&gpBuffer[sx - 24544 + screen_y_times_768[sy]];
        cel_transparency_active = (unsigned __int8)(nTransTable[level_piece_id] & TransList[dung_map[xa][ya]]);
        for ( i = 0; (gendung_567144 >> 1) - 1 > i; ++i )
        {
          if ( i >= a6 )
          {
            LOWORD(level_cel_block) = *(_WORD *)&v15[4 * i + 6];
            if ( (_WORD)level_cel_block )
              drawLowerScreen(a1);
          }
          a1 -= 24576;
        }
        if ( v13 < 8 )
          scrollrt_draw_clipped_dungeon_2(
            &gpBuffer[sx + screen_y_times_768[sy] + -12288 * v13],
            xa,
            ya,
            a6,
            v13,
            sx,
            sy,
            0);
      }
    }
    ++xa;
    --ya;
    sx += 64;
    --a5;
    v15 += 32;
  }
  v14 = a5;
  while ( 1 )
  {
    v7 = v14--;
    if ( !v7 || xa >= 112 || ya < 0 )
      break;
    if ( ya < 112 && xa >= 0 )
    {
      level_piece_id = dPiece[xa][ya];
      light_table_index = dTransVal[xa][ya];
      if ( level_piece_id )
      {
        a1a = (unsigned __int8 *)&gpBuffer[sx - 24576 + screen_y_times_768[sy]];
        cel_transparency_active = (unsigned __int8)(nTransTable[level_piece_id] & TransList[dung_map[xa][ya]]);
        v17 = 0;
        while ( (gendung_567144 >> 1) - 2 > v17 )
        {
          if ( v17 >= a6 )
          {
            LOWORD(level_cel_block) = *(_WORD *)&v15[4 * v17 + 4];
            if ( (_WORD)level_cel_block )
              drawLowerScreen(a1a);
            LOWORD(level_cel_block) = *(_WORD *)&v15[4 * v17 + 6];
            if ( (_WORD)level_cel_block )
              drawLowerScreen(a1a + 32);
          }
          ++v17;
          a1a -= 24576;
        }
        if ( v13 < 8 )
          scrollrt_draw_clipped_dungeon_2(
            &gpBuffer[sx + screen_y_times_768[sy] + -24576 * (a6 + 1)],
            xa,
            ya,
            a6,
            v13,
            sx,
            sy,
            1);
      }
    }
    ++xa;
    --ya;
    sx += 64;
    v15 += 32;
  }
  if ( some_flag )
  {
    if ( (unsigned int)ya < 0x70 && (unsigned int)xa < 0x70 )
    {
      level_piece_id = dPiece[xa][ya];
      light_table_index = dTransVal[xa][ya];
      if ( level_piece_id )
      {
        a1b = (unsigned __int8 *)&gpBuffer[sx - 24576 + screen_y_times_768[sy]];
        cel_transparency_active = (unsigned __int8)(nTransTable[level_piece_id] & TransList[dung_map[xa][ya]]);
        for ( j = 0; (gendung_567144 >> 1) - 1 > j; ++j )
        {
          if ( j >= a6 )
          {
            LOWORD(level_cel_block) = *(_WORD *)&v15[4 * j + 4];
            if ( (_WORD)level_cel_block )
              drawLowerScreen(a1b);
          }
          a1b -= 24576;
        }
        if ( v13 < 8 )
          scrollrt_draw_clipped_dungeon_2(
            &gpBuffer[sx + screen_y_times_768[sy] + -12288 * v13],
            xa,
            ya,
            a6,
            v13,
            sx,
            sy,
            0);
      }
    }
  }
}

//----- (0048AA8C) --------------------------------------------------------
void __fastcall scrollrt_draw_clipped_dungeon_2(char *buffer, int x, int y, int a4, int a5, int sx, int sy, int me_flag)
{
  ItemStruct *v10; // [esp+14h] [ebp-50h]
  MonsterStruct *v11; // [esp+18h] [ebp-4Ch]
  PlayerStruct *v12; // [esp+1Ch] [ebp-48h]
  MonsterStruct *v13; // [esp+20h] [ebp-44h]
  PlayerStruct *v14; // [esp+24h] [ebp-40h]
  ItemStruct *v15; // [esp+28h] [ebp-3Ch]
  DeadStruct *v16; // [esp+2Ch] [ebp-38h]
  char v17; // [esp+30h] [ebp-34h]
  int v18; // [esp+34h] [ebp-30h]
  int screen_x; // [esp+38h] [ebp-2Ch]
  int screen_xa; // [esp+38h] [ebp-2Ch]
  int screen_xb; // [esp+38h] [ebp-2Ch]
  int screen_xc; // [esp+38h] [ebp-2Ch]
  int screen_xd; // [esp+38h] [ebp-2Ch]
  char v24; // [esp+3Ch] [ebp-28h]
  char v25; // [esp+40h] [ebp-24h]
  char v26; // [esp+44h] [ebp-20h]
  char v27; // [esp+48h] [ebp-1Ch]
  int v28; // [esp+4Ch] [ebp-18h]
  char v29; // [esp+50h] [ebp-14h]
  char v30; // [esp+54h] [ebp-10h]
  char v31; // [esp+58h] [ebp-Ch]
  int py; // [esp+5Ch] [ebp-8h]
  int pya; // [esp+5Ch] [ebp-8h]
  char v34; // [esp+60h] [ebp-4h]

  v30 = dFlags[x][y];
  v27 = dDead[x][y];
  v31 = dObject[x][y];
  v34 = dItem[x][y];
  v29 = dPlayer[x][y];
  v25 = dArch[x][y];
  v24 = dung_map[x][y];
  v28 = dMonster[x][y];
  v26 = dPlayer[x][y - 1];
  v18 = dMonster[x][y - 1];
  if ( visiondebug && v30 & 0x40 )
    Cel2DecodeHdrOnly(buffer, pSquareCel, 1, 64, a5, 8);
  if ( MissilePreFlag && v30 & 1 )
    DrawClippedMissile(x, y, sx, sy, a5, 8, 1);
  if ( lightmax > light_table_index )
  {
    if ( v27 )
    {
      v16 = &dead[(v27 & 0x1F) - 1];
      v17 = (unsigned __int8)(v27 & 0xE0) >> 5;
      screen_x = sx - dead[(v27 & 0x1F) - 1]._deadWidth2;
      if ( dead[(v27 & 0x1F) - 1]._deadtrans )
        Cel2DrawHdrLightRed(
          screen_x,
          sy,
          (char *)v16->_deadData[v17],
          v16->_deadFrame,
          v16->_deadWidth,
          a5,
          8,
          v16->_deadtrans);
      else
        Cel2DecodeHdrLight(screen_x, sy, (char *)v16->_deadData[v17], v16->_deadFrame, v16->_deadWidth, a5, 8);
    }
    if ( v31 )
      DrawClippedObject(x, y, sx, sy, 1, a5, 8);
  }
  if ( v34 )
  {
    v15 = &item[v34 - 1];
    if ( !v15->_iPostDraw )
    {
      screen_xa = sx - v15->_iAnimWidth2;
      if ( v34 - 1 == pcursitem )
        CelDrawHdrClrHL(181, screen_xa, sy, (char *)v15->_iAnimData, v15->_iAnimFrame, v15->_iAnimWidth, a5, 8);
      Cel2DecodeHdrLight(screen_xa, sy, (char *)v15->_iAnimData, v15->_iAnimFrame, v15->_iAnimWidth, a5, 8);
    }
  }
  if ( v30 & 0x20 )
  {
    v14 = &plr[-(v26 + 1)];
    DrawClippedPlayer(
      -(v26 + 1),
      x,
      y - 1,
      sx + plr[-v26 - 1]._pxoff - plr[-v26 - 1]._pAnimWidth2,
      sy + plr[-v26 - 1]._pyoff,
      plr[-v26 - 1]._pAnimData,
      plr[-v26 - 1]._pAnimFrame,
      plr[-v26 - 1]._pAnimWidth,
      a5,
      8);
    if ( me_flag )
    {
      if ( v14->_peflag )
      {
        if ( v14->_peflag == 2 )
          scrollrt_draw_clipped_e_flag_2(buffer - 12384, x - 2, y + 1, a4, a5, sx - 96, sy - 16);
        scrollrt_draw_clipped_e_flag_2(buffer - 64, x - 1, y + 1, a4, a5, sx - 64, sy);
      }
    }
  }
  if ( v30 & 0x10 && (v30 & 0x40 || plr[myplr]._pInfraFlag) )
  {
    mon_id = -(v18 + 1);
    v13 = &monster[-(v18 + 1)];
    if ( monster[-v18 - 1]._mFlags & 1 )
    {
      screen_xb = sx + v13->_mxoff - v13->MType->flags_2;
      py = sy + v13->_myoff;
      if ( mon_id == pcursmonst )
        CelDrawHdrClrHL(233, screen_xb, py, (char *)v13->_mAnimData, v13->_mAnimFrame, v13->MType->flags_1, a5, 8);
      DrawClippedMonster(x, y, screen_xb, py, mon_id, a5, 8);
      if ( me_flag && !v13->_meflag )
        scrollrt_draw_clipped_e_flag_2(buffer - 64, x - 1, y + 1, a4, a5, sx - 64, sy);
    }
  }
  if ( v29 > 0 )
  {
    v12 = &plr[v29 - 1];
    DrawClippedPlayer(
      v29 - 1,
      x,
      y,
      sx + plr[v29 - 1]._pxoff - plr[v29 - 1]._pAnimWidth2,
      sy + plr[v29 - 1]._pyoff,
      plr[v29 - 1]._pAnimData,
      plr[v29 - 1]._pAnimFrame,
      plr[v29 - 1]._pAnimWidth,
      a5,
      8);
    if ( me_flag )
    {
      if ( v12->_peflag )
      {
        if ( v12->_peflag == 2 )
          scrollrt_draw_clipped_e_flag_2(buffer - 12384, x - 2, y + 1, a4, a5, sx - 96, sy - 16);
        scrollrt_draw_clipped_e_flag_2(buffer - 64, x - 1, y + 1, a4, a5, sx - 64, sy);
      }
    }
  }
  if ( v28 > 0 && (v30 & 0x40 || plr[myplr]._pInfraFlag) )
  {
    mon_id = v28 - 1;
    v11 = &monster[v28 - 1];
    if ( monster[v28 - 1]._mFlags & 1 )
    {
      screen_xc = sx + v11->_mxoff - v11->MType->flags_2;
      pya = sy + v11->_myoff;
      if ( mon_id == pcursmonst )
        CelDrawHdrClrHL(233, screen_xc, pya, (char *)v11->_mAnimData, v11->_mAnimFrame, v11->MType->flags_1, a5, 8);
      DrawClippedMonster(x, y, screen_xc, pya, mon_id, a5, 8);
      if ( me_flag && !v11->_meflag )
        scrollrt_draw_clipped_e_flag_2(buffer - 64, x - 1, y + 1, a4, a5, sx - 64, sy);
    }
  }
  if ( v30 & 1 )
    DrawClippedMissile(x, y, sx, sy, a5, 8, 0);
  if ( v31 && lightmax > light_table_index )
    DrawClippedObject(x, y, sx, sy, 0, a5, 8);
  if ( v34 )
  {
    v10 = &item[v34 - 1];
    if ( v10->_iPostDraw )
    {
      screen_xd = sx - v10->_iAnimWidth2;
      if ( v34 - 1 == pcursitem )
        CelDrawHdrClrHL(181, screen_xd, sy, (char *)v10->_iAnimData, v10->_iAnimFrame, v10->_iAnimWidth, a5, 8);
      Cel2DecodeHdrLight(screen_xd, sy, (char *)v10->_iAnimData, v10->_iAnimFrame, v10->_iAnimWidth, a5, 8);
    }
  }
  if ( v25 )
  {
    cel_transparency_active = (unsigned __int8)TransList[v24];
    Cel2DecodeLightTrans(buffer, level_special_cel, v25, 64, a5, 8);
  }
}

//----- (0048B36A) --------------------------------------------------------
void __fastcall scrollrt_draw_clipped_e_flag_2(char *buffer, int x, int y, int a4, signed int a5, int sx, int sy)
{
  int v9; // [esp+18h] [ebp-14h]
  _WORD *v10; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *a1; // [esp+20h] [ebp-Ch]
  unsigned __int8 *a1a; // [esp+20h] [ebp-Ch]
  int v13; // [esp+24h] [ebp-8h]
  int v14; // [esp+28h] [ebp-4h]

  v13 = light_table_index;
  v14 = cel_transparency_active;
  v9 = level_piece_id;
  level_piece_id = dPiece[x][y];
  light_table_index = dTransVal[x][y];
  a1 = (unsigned __int8 *)&buffer[24576 * a4];
  cel_transparency_active = (unsigned __int8)(nTransTable[level_piece_id] & TransList[dung_map[x][y]]);
  v10 = (_WORD *)((char *)dpiece_defs_map_1 + 32 * gendung_get_dpiece_num_from_coord(x, y));
  switch ( a4 )
  {
    case 0:
      LOWORD(level_cel_block) = v10[2];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(a1);
      LOWORD(level_cel_block) = v10[3];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(a1 + 32);
      goto LABEL_6;
    case 1:
LABEL_6:
      a1 -= 24576;
      LOWORD(level_cel_block) = v10[4];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(a1);
      LOWORD(level_cel_block) = v10[5];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(a1 + 32);
      goto LABEL_10;
    case 2:
LABEL_10:
      a1 -= 24576;
      LOWORD(level_cel_block) = v10[6];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(a1);
      LOWORD(level_cel_block) = v10[7];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(a1 + 32);
      goto LABEL_14;
    case 3:
LABEL_14:
      a1a = a1 - 24576;
      LOWORD(level_cel_block) = v10[8];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(a1a);
      LOWORD(level_cel_block) = v10[9];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(a1a + 32);
      break;
    default:
      break;
  }
  if ( a5 < 8 )
    scrollrt_draw_clipped_dungeon_2(buffer, x, y, a4, a5, sx, sy, 0);
  light_table_index = v13;
  cel_transparency_active = v14;
  level_piece_id = v9;
}

//----- (0048B5F0) --------------------------------------------------------
void __fastcall scrollrt_draw_upper(int x, int y, int sx, int sy, int a5, int a6, int some_flag)
{
  signed int ya; // [esp+Ch] [ebp-20h]
  signed int xa; // [esp+10h] [ebp-1Ch]
  unsigned __int8 *a1; // [esp+18h] [ebp-14h]
  unsigned __int8 *a1a; // [esp+18h] [ebp-14h]
  unsigned __int8 *a1b; // [esp+18h] [ebp-14h]
  unsigned __int8 *a1c; // [esp+18h] [ebp-14h]
  unsigned __int8 *a1d; // [esp+18h] [ebp-14h]
  unsigned __int8 *a1e; // [esp+18h] [ebp-14h]
  unsigned __int8 *a1f; // [esp+18h] [ebp-14h]
  unsigned __int8 *a1g; // [esp+18h] [ebp-14h]
  unsigned __int8 *a1h; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  _WORD *v19; // [esp+20h] [ebp-Ch]
  int j; // [esp+24h] [ebp-8h]
  int v21; // [esp+28h] [ebp-4h]

  ya = y;
  xa = x;
  v19 = (_WORD *)((char *)dpiece_defs_map_1 + 32 * gendung_get_dpiece_num_from_coord(x, y));
  v21 = 2 * a6 + 2;
  if ( v21 > 8 )
    v21 = 8;
  if ( some_flag )
  {
    if ( ya >= 0 && ya < 112 && xa >= 0 && xa < 112 )
    {
      level_piece_id = dPiece[xa][ya];
      light_table_index = dTransVal[xa][ya];
      if ( level_piece_id )
      {
        a1 = (unsigned __int8 *)&gpBuffer[sx + 32 + screen_y_times_768[sy]];
        cel_transparency_active = (unsigned __int8)(nTransTable[level_piece_id] & TransList[dung_map[xa][ya]]);
        if ( a6 >= 0 )
        {
          LOWORD(level_cel_block) = v19[1];
          if ( (_WORD)level_cel_block )
          {
            arch_draw_type = 2;
            drawUpperScreen(a1);
            arch_draw_type = 0;
          }
        }
        a1a = a1 - 24576;
        if ( a6 >= 1 )
        {
          LOWORD(level_cel_block) = v19[3];
          if ( (_WORD)level_cel_block )
            drawUpperScreen(a1a);
        }
        a1b = a1a - 24576;
        if ( a6 >= 2 )
        {
          LOWORD(level_cel_block) = v19[5];
          if ( (_WORD)level_cel_block )
            drawUpperScreen(a1b);
        }
        a1c = a1b - 24576;
        if ( a6 >= 3 )
        {
          LOWORD(level_cel_block) = v19[7];
          if ( (_WORD)level_cel_block )
            drawUpperScreen(a1c);
        }
        scrollrt_draw_dungeon(&gpBuffer[sx + screen_y_times_768[sy]], xa, ya, a6, v21, sx, sy, 0);
      }
      else
      {
        world_draw_black_tile(&gpBuffer[sx + screen_y_times_768[sy]]);
      }
    }
    ++xa;
    --ya;
    sx += 64;
    --a5;
    v19 += 16;
  }
  for ( i = 0; a5 > i; ++i )
  {
    if ( ya >= 0 && ya < 112 && xa >= 0 && xa < 112 )
    {
      level_piece_id = dPiece[xa][ya];
      light_table_index = dTransVal[xa][ya];
      if ( level_piece_id )
      {
        a1d = (unsigned __int8 *)&gpBuffer[sx + screen_y_times_768[sy]];
        cel_transparency_active = (unsigned __int8)(nTransTable[level_piece_id] & TransList[dung_map[xa][ya]]);
        arch_draw_type = 1;
        LOWORD(level_cel_block) = *v19;
        if ( (_WORD)level_cel_block )
          drawUpperScreen(a1d);
        arch_draw_type = 2;
        LOWORD(level_cel_block) = v19[1];
        if ( (_WORD)level_cel_block )
          drawUpperScreen(a1d + 32);
        arch_draw_type = 0;
        for ( j = 1; (gendung_567144 >> 1) - 1 > j; ++j )
        {
          a1d -= 24576;
          if ( a6 >= j )
          {
            LOWORD(level_cel_block) = v19[2 * j];
            if ( (_WORD)level_cel_block )
              drawUpperScreen(a1d);
            LOWORD(level_cel_block) = v19[2 * j + 1];
            if ( (_WORD)level_cel_block )
              drawUpperScreen(a1d + 32);
          }
        }
        scrollrt_draw_dungeon(&gpBuffer[sx + screen_y_times_768[sy]], xa, ya, a6, v21, sx, sy, 1);
      }
      else
      {
        world_draw_black_tile(&gpBuffer[sx + screen_y_times_768[sy]]);
      }
    }
    ++xa;
    --ya;
    sx += 64;
    v19 += 16;
  }
  if ( some_flag && ya >= 0 && ya < 112 && xa >= 0 && xa < 112 )
  {
    level_piece_id = dPiece[xa][ya];
    light_table_index = dTransVal[xa][ya];
    if ( level_piece_id )
    {
      a1e = (unsigned __int8 *)&gpBuffer[sx + screen_y_times_768[sy]];
      cel_transparency_active = (unsigned __int8)(nTransTable[level_piece_id] & TransList[dung_map[xa][ya]]);
      arch_draw_type = 1;
      if ( a6 >= 0 )
      {
        LOWORD(level_cel_block) = *v19;
        if ( (_WORD)level_cel_block )
          drawUpperScreen(a1e);
      }
      arch_draw_type = 0;
      a1f = a1e - 24576;
      if ( a6 >= 1 )
      {
        LOWORD(level_cel_block) = v19[2];
        if ( (_WORD)level_cel_block )
          drawUpperScreen(a1f);
      }
      a1g = a1f - 24576;
      if ( a6 >= 2 )
      {
        LOWORD(level_cel_block) = v19[4];
        if ( (_WORD)level_cel_block )
          drawUpperScreen(a1g);
      }
      a1h = a1g - 24576;
      if ( a6 >= 3 )
      {
        LOWORD(level_cel_block) = v19[6];
        if ( (_WORD)level_cel_block )
          drawUpperScreen(a1h);
      }
      scrollrt_draw_dungeon(&gpBuffer[sx + screen_y_times_768[sy]], xa, ya, a6, v21, sx, sy, 0);
    }
    else
    {
      world_draw_black_tile(&gpBuffer[sx + screen_y_times_768[sy]]);
    }
  }
}

//----- (0048BC8A) --------------------------------------------------------
void __fastcall scrollrt_draw_dungeon(char *buffer, int x, int y, int a4, int a5, int sx, int sy, int me_flag)
{
  ItemStruct *v10; // [esp+14h] [ebp-50h]
  MonsterStruct *v11; // [esp+18h] [ebp-4Ch]
  PlayerStruct *v12; // [esp+1Ch] [ebp-48h]
  MonsterStruct *v13; // [esp+20h] [ebp-44h]
  PlayerStruct *v14; // [esp+24h] [ebp-40h]
  ItemStruct *v15; // [esp+28h] [ebp-3Ch]
  DeadStruct *v16; // [esp+2Ch] [ebp-38h]
  char v17; // [esp+30h] [ebp-34h]
  int v18; // [esp+34h] [ebp-30h]
  int screen_x; // [esp+38h] [ebp-2Ch]
  int screen_xa; // [esp+38h] [ebp-2Ch]
  int screen_xb; // [esp+38h] [ebp-2Ch]
  int screen_xc; // [esp+38h] [ebp-2Ch]
  int screen_xd; // [esp+38h] [ebp-2Ch]
  char v24; // [esp+3Ch] [ebp-28h]
  char v25; // [esp+40h] [ebp-24h]
  char v26; // [esp+44h] [ebp-20h]
  char v27; // [esp+48h] [ebp-1Ch]
  int v28; // [esp+4Ch] [ebp-18h]
  char v29; // [esp+50h] [ebp-14h]
  char v30; // [esp+54h] [ebp-10h]
  char v31; // [esp+58h] [ebp-Ch]
  int py; // [esp+5Ch] [ebp-8h]
  int pya; // [esp+5Ch] [ebp-8h]
  char v34; // [esp+60h] [ebp-4h]

  v30 = dFlags[x][y];
  v27 = dDead[x][y];
  v31 = dObject[x][y];
  v34 = dItem[x][y];
  v29 = dPlayer[x][y];
  v25 = dArch[x][y];
  v24 = dung_map[x][y];
  v28 = dMonster[x][y];
  v26 = dPlayer[x][y - 1];
  v18 = dMonster[x][y - 1];
  if ( visiondebug && v30 & 0x40 )
    CelDecodeHdrOnly(buffer, pSquareCel, 1, 64, 0, a5);
  if ( MissilePreFlag && v30 & 1 )
    DrawMissile(x, y, sx, sy, 0, a5, 1);
  if ( lightmax > light_table_index )
  {
    if ( v27 )
    {
      v16 = &dead[(v27 & 0x1F) - 1];
      v17 = (unsigned __int8)(v27 & 0xE0) >> 5;
      screen_x = sx - dead[(v27 & 0x1F) - 1]._deadWidth2;
      if ( dead[(v27 & 0x1F) - 1]._deadtrans )
        CelDrawHdrLightRed(
          screen_x,
          sy,
          (char *)v16->_deadData[v17],
          v16->_deadFrame,
          v16->_deadWidth,
          0,
          a5,
          v16->_deadtrans);
      else
        CelDecodeHdrLightOnly(screen_x, sy, (char *)v16->_deadData[v17], v16->_deadFrame, v16->_deadWidth, 0, a5);
    }
    if ( v31 )
      DrawObject(x, y, sx, sy, 1, 0, a5);
  }
  if ( v34 )
  {
    v15 = &item[v34 - 1];
    if ( !v15->_iPostDraw )
    {
      screen_xa = sx - v15->_iAnimWidth2;
      if ( v34 - 1 == pcursitem )
        CelDecodeClr(181, screen_xa, sy, (char *)v15->_iAnimData, v15->_iAnimFrame, v15->_iAnimWidth, 0, a5);
      CelDecodeHdrLightOnly(screen_xa, sy, (char *)v15->_iAnimData, v15->_iAnimFrame, v15->_iAnimWidth, 0, a5);
    }
  }
  if ( v30 & 0x20 )
  {
    v14 = &plr[-(v26 + 1)];
    DrawPlayer(
      -(v26 + 1),
      x,
      y - 1,
      sx + plr[-v26 - 1]._pxoff - plr[-v26 - 1]._pAnimWidth2,
      sy + plr[-v26 - 1]._pyoff,
      plr[-v26 - 1]._pAnimData,
      plr[-v26 - 1]._pAnimFrame,
      plr[-v26 - 1]._pAnimWidth,
      0,
      a5);
    if ( me_flag )
    {
      if ( v14->_peflag )
      {
        if ( v14->_peflag == 2 )
          scrollrt_draw_e_flag(buffer - 12384, x - 2, y + 1, a4, a5, sx - 96, sy - 16);
        scrollrt_draw_e_flag(buffer - 64, x - 1, y + 1, a4, a5, sx - 64, sy);
      }
    }
  }
  if ( v30 & 0x10 && (v30 & 0x40 || plr[myplr]._pInfraFlag) )
  {
    mon_id = -(v18 + 1);
    v13 = &monster[-(v18 + 1)];
    if ( monster[-v18 - 1]._mFlags & 1 )
    {
      screen_xb = sx + v13->_mxoff - v13->MType->flags_2;
      py = sy + v13->_myoff;
      if ( mon_id == pcursmonst )
        CelDecodeClr(233, screen_xb, py, (char *)v13->_mAnimData, v13->_mAnimFrame, v13->MType->flags_1, 0, a5);
      DrawMonster(x, y, screen_xb, py, mon_id, 0, a5);
      if ( me_flag && !v13->_meflag )
        scrollrt_draw_e_flag(buffer - 64, x - 1, y + 1, a4, a5, sx - 64, sy);
    }
  }
  if ( v29 > 0 )
  {
    v12 = &plr[v29 - 1];
    DrawPlayer(
      v29 - 1,
      x,
      y,
      sx + plr[v29 - 1]._pxoff - plr[v29 - 1]._pAnimWidth2,
      sy + plr[v29 - 1]._pyoff,
      plr[v29 - 1]._pAnimData,
      plr[v29 - 1]._pAnimFrame,
      plr[v29 - 1]._pAnimWidth,
      0,
      a5);
    if ( me_flag )
    {
      if ( v12->_peflag )
      {
        if ( v12->_peflag == 2 )
          scrollrt_draw_e_flag(buffer - 12384, x - 2, y + 1, a4, a5, sx - 96, sy - 16);
        scrollrt_draw_e_flag(buffer - 64, x - 1, y + 1, a4, a5, sx - 64, sy);
      }
    }
  }
  if ( v28 > 0 && (v30 & 0x40 || plr[myplr]._pInfraFlag) )
  {
    mon_id = v28 - 1;
    v11 = &monster[v28 - 1];
    if ( monster[v28 - 1]._mFlags & 1 )
    {
      screen_xc = sx + v11->_mxoff - v11->MType->flags_2;
      pya = sy + v11->_myoff;
      if ( mon_id == pcursmonst )
        CelDecodeClr(233, screen_xc, pya, (char *)v11->_mAnimData, v11->_mAnimFrame, v11->MType->flags_1, 0, a5);
      DrawMonster(x, y, screen_xc, pya, mon_id, 0, a5);
      if ( me_flag && !v11->_meflag )
        scrollrt_draw_e_flag(buffer - 64, x - 1, y + 1, a4, a5, sx - 64, sy);
    }
  }
  if ( v30 & 1 )
    DrawMissile(x, y, sx, sy, 0, a5, 0);
  if ( v31 && lightmax > light_table_index )
    DrawObject(x, y, sx, sy, 0, 0, a5);
  if ( v34 )
  {
    v10 = &item[v34 - 1];
    if ( v10->_iPostDraw )
    {
      screen_xd = sx - v10->_iAnimWidth2;
      if ( v34 - 1 == pcursitem )
        CelDecodeClr(181, screen_xd, sy, (char *)v10->_iAnimData, v10->_iAnimFrame, v10->_iAnimWidth, 0, a5);
      CelDecodeHdrLightOnly(screen_xd, sy, (char *)v10->_iAnimData, v10->_iAnimFrame, v10->_iAnimWidth, 0, a5);
    }
  }
  if ( v25 )
  {
    cel_transparency_active = (unsigned __int8)TransList[v24];
    CelDecodeHdrLightTrans(buffer, level_special_cel, v25, 64, 0, a5);
  }
}

//----- (0048C568) --------------------------------------------------------
void __fastcall DrawMonster(int x, int y, int a3, int a4, int mon_id, int a6, int a7)
{
  char always_1; // [esp+14h] [ebp-4h]

  if ( dFlags[x][y] & 0x40 )
  {
    always_1 = 0;
    if ( monster[mon_id]._uniqtype )
      always_1 = monster[mon_id]._uniqtrans + 4;
    if ( monster[mon_id]._mmode == 15 )
      always_1 = 2;
    if ( plr[myplr]._pInfraFlag && light_table_index > 8 )
      always_1 = 1;
    if ( always_1 )
      CelDrawHdrLightRed(
        a3,
        a4,
        (char *)monster[mon_id]._mAnimData,
        monster[mon_id]._mAnimFrame,
        monster[mon_id].MType->flags_1,
        a6,
        a7,
        always_1);
    else
      CelDecodeHdrLightOnly(
        a3,
        a4,
        (char *)monster[mon_id]._mAnimData,
        monster[mon_id]._mAnimFrame,
        monster[mon_id].MType->flags_1,
        a6,
        a7);
  }
  else
  {
    CelDrawHdrLightRed(
      a3,
      a4,
      (char *)monster[mon_id]._mAnimData,
      monster[mon_id]._mAnimFrame,
      monster[mon_id].MType->flags_1,
      a6,
      a7,
      1);
  }
}

//----- (0048C75B) --------------------------------------------------------
void __fastcall DrawPlayer(int pnum, int x, int y, int px, int py, int animdata, int animframe, int animwidth, int a9, int a10)
{
  int v12; // [esp+14h] [ebp-4h]

  if ( dFlags[x][y] & 0x40 || plr[myplr]._pInfraFlag )
  {
    if ( pcursplr == pnum )
      CelDecodeClr(165, px, py, (char *)animdata, animframe, animwidth, a9, a10);
    if ( myplr == pnum )
    {
      assert(animdata, "SCROLLRT.CPP", 246);
      CelDrawHdrOnly(px, py, (char *)animdata, animframe, animwidth, a9, a10);
    }
    else if ( dFlags[x][y] & 0x40 && (!plr[myplr]._pInfraFlag || light_table_index <= 8) )
    {
      v12 = light_table_index;
      if ( light_table_index < 5 )
        light_table_index = 0;
      else
        light_table_index -= 5;
      CelDecodeHdrLightOnly(px, py, (char *)animdata, animframe, animwidth, a9, a10);
      light_table_index = v12;
    }
    else
    {
      CelDrawHdrLightRed(px, py, (char *)animdata, animframe, animwidth, a9, a10, 1);
    }
  }
}

//----- (0048C90D) --------------------------------------------------------
void __fastcall DrawObject(int x, int y, int a3, int a4, int pre_flag, int a6, int dir)
{
  int v7; // ST3C_4
  int v8; // ST38_4
  int screen_x; // [esp+14h] [ebp-14h]
  char v10; // [esp+18h] [ebp-10h]
  int screen_y; // [esp+1Ch] [ebp-Ch]

  if ( dObject[x][y] <= 0 )
  {
    v10 = -(char)(dObject[x][y] + 1);
    if ( object[v10]._oPreFlag != pre_flag )
      return;
    v7 = object[v10]._ox - x;
    v8 = object[v10]._oy - y;
    screen_x = 32 * v7 + a3 - object[v10]._oAnimWidth2 - 32 * v8;
    screen_y = a4 + 16 * v8 + 16 * v7;
    a6 = 0;
    dir = 8;
  }
  else
  {
    v10 = dObject[x][y] - 1;
    if ( object[v10]._oPreFlag != pre_flag )
      return;
    screen_x = a3 - object[v10]._oAnimWidth2;
    screen_y = a4;
  }
  if ( v10 == pcursobj )
    CelDecodeClr(
      194,
      screen_x,
      screen_y,
      (char *)object[v10]._oAnimData,
      object[v10]._oAnimFrame,
      object[v10]._oAnimWidth,
      a6,
      dir);
  if ( object[v10]._oLight )
  {
    CelDecodeHdrLightOnly(
      screen_x,
      screen_y,
      (char *)object[v10]._oAnimData,
      object[v10]._oAnimFrame,
      object[v10]._oAnimWidth,
      a6,
      dir);
  }
  else
  {
    assert(object[v10]._oAnimData, "SCROLLRT.CPP", 327);
    CelDrawHdrOnly(
      screen_x,
      screen_y,
      (char *)object[v10]._oAnimData,
      object[v10]._oAnimFrame,
      object[v10]._oAnimWidth,
      a6,
      dir);
  }
}

//----- (0048CB96) --------------------------------------------------------
void __fastcall scrollrt_draw_e_flag(char *buffer, int x, int y, int a4, int a5, int sx, int sy)
{
  int v9; // [esp+14h] [ebp-18h]
  _WORD *v10; // [esp+18h] [ebp-14h]
  unsigned __int8 *a1; // [esp+1Ch] [ebp-10h]
  int v12; // [esp+20h] [ebp-Ch]
  int v13; // [esp+24h] [ebp-8h]
  int i; // [esp+28h] [ebp-4h]

  v12 = light_table_index;
  v13 = cel_transparency_active;
  v9 = level_piece_id;
  level_piece_id = dPiece[x][y];
  light_table_index = dTransVal[x][y];
  a1 = (unsigned __int8 *)buffer;
  cel_transparency_active = (unsigned __int8)(nTransTable[level_piece_id] & TransList[dung_map[x][y]]);
  v10 = (_WORD *)((char *)dpiece_defs_map_1 + 32 * gendung_get_dpiece_num_from_coord(x, y));
  arch_draw_type = 1;
  LOWORD(level_cel_block) = *v10;
  if ( (_WORD)level_cel_block )
    drawUpperScreen(a1);
  arch_draw_type = 2;
  LOWORD(level_cel_block) = v10[1];
  if ( (_WORD)level_cel_block )
    drawUpperScreen(a1 + 32);
  arch_draw_type = 0;
  for ( i = 1; (gendung_567144 >> 1) - 1 > i; ++i )
  {
    a1 -= 24576;
    if ( a4 >= i )
    {
      LOWORD(level_cel_block) = v10[2 * i];
      if ( (_WORD)level_cel_block )
        drawUpperScreen(a1);
      LOWORD(level_cel_block) = v10[2 * i + 1];
      if ( (_WORD)level_cel_block )
        drawUpperScreen(a1 + 32);
    }
  }
  scrollrt_draw_dungeon(buffer, x, y, a4, a5, sx, sy, 0);
  light_table_index = v12;
  cel_transparency_active = v13;
  level_piece_id = v9;
}

//----- (0048CD79) --------------------------------------------------------
void __fastcall DrawZoom(int x, int y)
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
  v17 = 3;
  switch ( Scrollinfo._sdir )
  {
    case 1:
      goto LABEL_3;
    case 2:
      a5 = 7;
LABEL_3:
      sy = Scrollinfo._syoff + 111;
      xa = x - 7;
      ya = y - 2;
      v17 = 4;
      break;
    case 3:
      goto LABEL_5;
    case 4:
      v17 = 4;
LABEL_5:
      a5 = 7;
      break;
    case 5:
      v17 = 4;
      break;
    case 6:
      v17 = 4;
      goto LABEL_8;
    case 7:
LABEL_8:
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
      v17 = 4;
      break;
    default:
      break;
  }
  gpBufEnd = (unsigned __int8 *)&gpBuffer[screen_y_times_768[143]];
  for ( a6 = 0; a6 < 4; ++a6 )
  {
    scrollrt_draw_upper(xa, ya++, sx, sy, a5, a6, 0);
    v2 = sx - 32;
    v3 = sy + 16;
    scrollrt_draw_upper(xa++, ya, v2, v3, a5, a6, 1);
    sx = v2 + 32;
    sy = v3 + 16;
  }
  gpBufEnd = (unsigned __int8 *)&gpBuffer[screen_y_times_768[320]];
  for ( a6a = 0; v17 > a6a; ++a6a )
  {
    scrollrt_draw_lower(xa, ya++, sx, sy, a5, 0);
    v4 = sx - 32;
    v5 = sy + 16;
    scrollrt_draw_lower(xa++, ya, v4, v5, a5, 1);
    sx = v4 + 32;
    sy = v5 + 16;
  }
  arch_draw_type = 0;
  for ( a6b = 0; a6b < 4; ++a6b )
  {
    scrollrt_draw_lower_2(xa, ya++, sx, sy, a5, a6b, 0);
    v6 = sx - 32;
    v7 = sy + 16;
    scrollrt_draw_lower_2(xa++, ya, v6, v7, a5, a6b, 1);
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
  for (v11 = 176; v11; --v11)
  {
    for (v12 = v22; v12; --v12)
    {
      LOBYTE(v13) = *v9++;
      HIBYTE(v13) = v13;
      *(_WORD *)v8 = v13;
      *(_WORD *)v10 = v13;
      v8 += 2;
      v10 += 2;
    }
    v9 += -v22 - 768;
    v14 = 2 * (v22 + 768);
    v10 -= v14;
    v8 -= v14;
  }
}

//----- (0048D0B8) --------------------------------------------------------
void __cdecl ClearScreenBuffer()
{
  char *v0; // edi
  signed int v1; // edx

  v0 = gpBuffer + 122944;
  for (v1 = 480; v1; --v1)
  {
    memset(v0, 0, 0x280u);
    v0 += 768;
  }
}

//----- (0048D386) --------------------------------------------------------
void __fastcall scrollrt_draw_game_screen(bool draw_cursor)
{
  if ( drawpanflag == 255 )
    DrawMain(480, 1, 0, 0, 0, 0, 0);
  else
    DrawMain(0, draw_cursor, 0, 0, 0, 0, 0);
  drawpanflag = 0;
}

//----- (0048D3E8) --------------------------------------------------------
void __fastcall DrawMain(int dwHgt, int draw_desc, int draw_hp, int draw_mana, int draw_sbar, int draw_btn, int drawbtnflag)
{
  char *v7; // esi
  char *v8; // edi
  int v9; // ebx
  int v10; // edx
  char *v11; // esi
  char *v12; // edi
  signed int v13; // edx
  char *v14; // esi
  char *v15; // edi
  unsigned int v16; // ebx
  int v17; // edx
  char *v18; // esi
  char *v19; // edi
  unsigned int v20; // ebx
  int v21; // edx
  char *v22; // esi
  char *v23; // edi
  signed int v24; // edx
  char *v25; // esi
  char *v26; // edi
  signed int v27; // edx
  char *v28; // esi
  char *v29; // edi
  signed int v30; // edx
  char *v31; // esi
  char *v32; // edi
  signed int v33; // edx
  char *v34; // esi
  char *v35; // edi
  signed int v36; // edx
  char *v37; // esi
  char *v38; // edi
  signed int v39; // edx
  char *v40; // esi
  char *v41; // edi
  signed int v42; // edx
  char *v43; // esi
  char *v44; // edi
  signed int v45; // edx
  int h_; // [esp+10h] [ebp-84h]
  signed int j; // [esp+14h] [ebp-80h]
  int v49; // [esp+18h] [ebp-7Ch]
  int error_code; // [esp+1Ch] [ebp-78h]
  int error_codea; // [esp+1Ch] [ebp-78h]
  signed int i; // [esp+20h] [ebp-74h]
  char *surface_; // [esp+24h] [ebp-70h]
  DDSURFACEDESC v54; // [esp+28h] [ebp-6Ch]

  h_ = dwHgt;
  if ( gbActive )
  {
    if ( lpDDSPrimary )
    {
      if ( lpDDSPrimary->lpVtbl->IsLost(lpDDSPrimary) != DDERR_SURFACELOST
        || (error_code = lpDDSPrimary->lpVtbl->Restore(lpDDSPrimary)) == 0 )
      {
        v54.dwSize = 108;
        for ( i = 0; i < 2; ++i )
        {
          error_code = lpDDSPrimary->lpVtbl->Lock(lpDDSPrimary, 0, &v54, 1, 0);
          if ( !error_code || i == 1 )
            break;
          if ( error_code == DDERR_GENERIC )
          {
            dx_reinit_42D562();
            h_ = 480;
          }
        }
        if ( error_code != DDERR_WASSTILLDRAWING && error_code != DDERR_SURFACEBUSY )
        {
          if ( error_code )
            DDErrDlg(error_code, 1940, "SCROLLRT.CPP");
          surface_ = (char *)v54.lpSurface;
          if ( v54.lPitch - 640 != scrollrt_4DC21C_soff || scrollrt_4DC21C_soff == -1 )
          {
            scrollrt_4DC21C_soff = v54.lPitch - 640;
            v49 = 0;
            for ( j = 0; j < 480; ++j )
            {
              scrollrt_648738_line_off[j] = v49;
              v49 += v54.lPitch;
            }
            scrollrt_648EDC_off1 = 398 * v54.lPitch + 177;
            scrollrt_648ED4_off2 = 352 * v54.lPitch + 96;
            scrollrt_648EC0_off3 = 352 * v54.lPitch + 461;
            scrollrt_648EB8_off4 = 416 * v54.lPitch + 565;
            scrollrt_648EEC_off5 = 357 * v54.lPitch + 205;
            scrollrt_648EE0_off6 = 357 * v54.lPitch + 11;
            scrollrt_647730_off7 = 357 * v54.lPitch + 558;
            scrollrt_648EC4_off8 = 443 * v54.lPitch + 87;
            scrollrt_648ECC_off9 = 443 * v54.lPitch + 527;
          }
          if ( h_ > 0 )
          {
            v7 = gpBuffer + 122944;
            v8 = surface_;
            v9 = scrollrt_4DC21C_soff;
            for (v10 = h_; v10; --v10)
            {
              qmemcpy(v8, v7, 0x280u);
              v7 += 768;
              v8 += v9 + 640;
            }
          }
          if ( h_ < 480 )
          {
            if ( draw_btn )
            {
              v11 = gpBuffer + 397325;
              v12 = &surface_[scrollrt_648EEC_off5];
              for (v13 = 28; v13; --v13)
              {
                qmemcpy(v12, v11, 0xE8u);
                v11 += 768;
                v12 += scrollrt_4DC21C_soff + 640;
              }
            }
            if ( draw_desc )
            {
              if ( dword_645760 > 0 && dword_645764 > 0 )
              {
                v14 = (char *)dword_645744;
                v15 = &surface_[dword_645740];
                v16 = dword_645760;
                for (v17 = dword_645764; v17; --v17)
                {
                  qmemcpy(v15, v14, v16);
                  v14 += 768;
                  v15 += scrollrt_4DC21C_soff + 640;
                }
              }
              if ( cursor_dword_645768_W > 0 && cursor_dword_64576C_H > 0 )
              {
                cursor_dword_645720 = sgdwCursX + scrollrt_648738_line_off[sgdwCursY];
                v18 = (char *)cursor_dword_645724_buf2;
                v19 = &surface_[cursor_dword_645720];
                v20 = cursor_dword_645768_W;
                for (v21 = cursor_dword_64576C_H; v21; --v21)
                {
                  qmemcpy(v19, v18, v20);
                  v18 += 768;
                  v19 += scrollrt_4DC21C_soff + 640;
                }
              }
              dword_645744 = cursor_dword_645724_buf2;
              dword_645740 = cursor_dword_645720;
              dword_645760 = cursor_dword_645768_W;
              dword_645764 = cursor_dword_64576C_H;
            }
            if ( draw_hp )
            {
              v22 = gpBuffer + 428785;
              v23 = &surface_[scrollrt_648EDC_off1];
              for (v24 = 60; v24; --v24)
              {
                qmemcpy(v23, v22, 0x120u);
                v22 += 768;
                v23 += scrollrt_4DC21C_soff + 640;
              }
            }
            if ( draw_sbar )
            {
              v25 = gpBuffer + 393741;
              v26 = &surface_[scrollrt_648EC0_off3];
              for (v27 = 72; v27; --v27)
              {
                qmemcpy(v26, v25, 0x58u);
                v25 += 768;
                v26 += scrollrt_4DC21C_soff + 640;
              }
              v28 = gpBuffer + 442997;
              v29 = &surface_[scrollrt_648EB8_off4];
              for (v30 = 56; v30; --v30)
              {
                qmemcpy(v29, v28, 0x38u);
                v28 += 768;
                v29 += scrollrt_4DC21C_soff + 640;
              }
            }
            if ( draw_mana )
            {
              v31 = gpBuffer + 393376;
              v32 = &surface_[scrollrt_648ED4_off2];
              for (v33 = 72; v33; --v33)
              {
                qmemcpy(v32, v31, 0x58u);
                v31 += 768;
                v32 += scrollrt_4DC21C_soff + 640;
              }
            }
            if ( drawbtnflag )
            {
              v34 = gpBuffer + 397131;
              v35 = &surface_[scrollrt_648EE0_off6];
              for (v36 = 119; v36; --v36)
              {
                qmemcpy(v35, v34, 0x48u);
                v34 += 768;
                v35 += scrollrt_4DC21C_soff + 640;
              }
              v37 = gpBuffer + 397678;
              v38 = &surface_[scrollrt_647730_off7];
              for (v39 = 42; v39; --v39)
              {
                qmemcpy(v38, v37, 0x48u);
                v37 += 768;
                v38 += scrollrt_4DC21C_soff + 640;
              }
              v40 = gpBuffer + 463255;
              v41 = &surface_[scrollrt_648EC4_off8];
              for (v42 = 32; v42; --v42)
              {
                qmemcpy(v41, v40, 0x24u);
                v40 += 768;
                v41 += scrollrt_4DC21C_soff + 640;
              }
              v43 = gpBuffer + 463695;
              v44 = &surface_[scrollrt_648ECC_off9];
              for (v45 = 32; v45; --v45)
              {
                qmemcpy(v44, v43, 0x24u);
                v43 += 768;
                v44 += scrollrt_4DC21C_soff + 640;
              }
            }
          }
          error_codea = lpDDSPrimary->lpVtbl->Unlock(lpDDSPrimary, 0);
          if ( error_codea )
            DDErrDlg(error_codea, 2184, "SCROLLRT.CPP");
          DrawFPS();
        }
      }
    }
  }
}

//----- (0048DA46) --------------------------------------------------------
void __cdecl DrawFPS()
{
  int v0; // eax
  HDC hdc; // [esp+Ch] [ebp-1Ch]
  HRESULT v2; // [esp+10h] [ebp-18h]
  char String[12]; // [esp+14h] [ebp-14h]
  DWORD v4; // [esp+20h] [ebp-8h]
  int v5; // [esp+24h] [ebp-4h]

  if ( frameflag && gbActive )
  {
    ++frameend;
    v4 = GetTickCount();
    if ( v4 - framestart >= 0x3E8 )
    {
      v5 = v4 - framestart;
      framestart = v4;
      framerate = 1000 * frameend / v5;
      frameend = 0;
    }
    if ( framerate > 99 )
      framerate = 99;
    wsprintfA(String, "%2d", framerate);
    v2 = lpDDSPrimary->lpVtbl->GetDC(lpDDSPrimary, &hdc);
    if ( !v2 )
    {
      v0 = strlen(String);
      TextOutA(hdc, 0, 400, String, v0);
      lpDDSPrimary->lpVtbl->ReleaseDC(lpDDSPrimary, hdc);
    }
  }
}

//----- (0048DB65) --------------------------------------------------------
void __cdecl DrawAndBlit()
{
  int draw_hp; // [esp+Ch] [ebp-Ch]
  signed int v1; // [esp+10h] [ebp-8h]
  int dwHgt; // [esp+14h] [ebp-4h]

  if ( drawpanflag == 255 )
  {
    drawmanaflag = 1;
    drawhpflag = 1;
    drawbtnflag = 1;
    draw_btn = 1;
    draw_hp = 0;
    v1 = 1;
    dwHgt = 480;
  }
  else
  {
    if ( drawpanflag != 1 )
      return;
    draw_hp = 1;
    v1 = 0;
    dwHgt = 352;
  }
  scrollrt_draw_cursor_back_buffer();
  if ( leveltype )
    DrawView(ViewX, ViewY);
  else
    T_DrawView(ViewX, ViewY);
  if ( v1 )
    ClearCtrlPan();
  if ( drawmanaflag )
    UpdateLifeFlask();
  if ( drawhpflag )
    UpdateManaFlask();
  if ( drawbtnflag )
    DrawCtrlPan();
  if ( draw_btn )
    DrawInvBelt();
  if ( talkflag )
  {
    DrawTalkPan();
    dwHgt = 480;
  }
  if ( !PauseMode )
    scrollrt_draw_cursor_item();
  DrawMain(dwHgt, 1, draw_hp, drawmanaflag, drawhpflag, draw_btn, drawbtnflag);
  drawpanflag = 0;
  drawmanaflag = 0;
  drawhpflag = 0;
  drawbtnflag = 0;
  draw_btn = 0;
}

