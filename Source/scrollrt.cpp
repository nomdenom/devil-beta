#include "all.h"

//----- (004880B0) --------------------------------------------------------
void __fastcall DrawMissile(int x, int y, int sx, int sy, int a5, int a6, int del_flag)
{
  int mi; // [esp+14h] [ebp-10h] MAPDST
  int i; // [esp+18h] [ebp-Ch]
  int screen_y; // [esp+1Ch] [ebp-8h]
  int screen_ya; // [esp+1Ch] [ebp-8h]
  int screen_x; // [esp+20h] [ebp-4h]
  int screen_xa; // [esp+20h] [ebp-4h]

  if ( dMissile[x][y] == -1 )
  {
    for ( i = 0; i < nummissiles; ++i )
    {
      mi = missileactive[i];
      if ( missile[mi]._mix == x && missile[mi]._miy == y && missile[mi]._miPreFlag == del_flag )
      {
        screen_xa = sx + missile[mi]._mixoff - missile[mi]._miAnimWidth2;
        screen_ya = sy + missile[mi]._miyoff;
        if ( missile[mi]._miUniqTrans )
        {
          CelDrawHdrLightRed(
            screen_xa,
            screen_ya,
            (char *)missile[mi]._miAnimData,
            missile[mi]._miAnimFrame,
            missile[mi]._miAnimWidth,
            a5,
            a6,
            missile[mi]._miUniqTrans + 3);
        }
        else if ( missile[mi]._miLightFlag )
        {
          CelDecodeHdrLightOnly(
            screen_xa,
            screen_ya,
            (char *)missile[mi]._miAnimData,
            missile[mi]._miAnimFrame,
            missile[mi]._miAnimWidth,
            a5,
            a6);
        }
        else
        {
          assert(missile[mi]._miAnimData, "SCROLLRT.CPP", 142);
          CelDrawHdrOnly(
            screen_xa,
            screen_ya,
            missile[mi]._miAnimData,
            missile[mi]._miAnimFrame,
            missile[mi]._miAnimWidth,
            a5,
            a6);
        }
      }
    }
  }
  else
  {
    mi = dMissile[x][y] - 1;
    if ( missile[mi]._miPreFlag == del_flag )
    {
      screen_x = sx + missile[mi]._mixoff - missile[mi]._miAnimWidth2;
      screen_y = sy + missile[mi]._miyoff;
      if ( missile[mi]._miUniqTrans )
      {
        CelDrawHdrLightRed(
          screen_x,
          screen_y,
          (char *)missile[mi]._miAnimData,
          missile[mi]._miAnimFrame,
          missile[mi]._miAnimWidth,
          a5,
          a6,
          missile[mi]._miUniqTrans + 3);
      }
      else if ( missile[mi]._miLightFlag )
      {
        CelDecodeHdrLightOnly(
          screen_x,
          screen_y,
          (char *)missile[mi]._miAnimData,
          missile[mi]._miAnimFrame,
          missile[mi]._miAnimWidth,
          a5,
          a6);
      }
      else
      {
        assert(missile[mi]._miAnimData, "SCROLLRT.CPP", 121);
        CelDrawHdrOnly(
          screen_x,
          screen_y,
          missile[mi]._miAnimData,
          missile[mi]._miAnimFrame,
          missile[mi]._miAnimWidth,
          a5,
          a6);
      }
    }
  }
}

//----- (0048855E) --------------------------------------------------------
void __fastcall DrawClippedMissile(int x, int y, int sx, int sy, int a5, int a6, int a7)
{
  int mi; // [esp+14h] [ebp-10h] MAPDST
  int i; // [esp+18h] [ebp-Ch]
  int screen_y; // [esp+1Ch] [ebp-8h]
  int screen_ya; // [esp+1Ch] [ebp-8h]
  int screen_x; // [esp+20h] [ebp-4h]
  int screen_xa; // [esp+20h] [ebp-4h]

  if ( dMissile[x][y] == -1 )
  {
    for ( i = 0; nummissiles > i; ++i )
    {
      mi = missileactive[i];
      if ( missile[mi]._mix == x
        && missile[mi]._miy == y
        && missile[mi]._miPreFlag == a7
        && missile[mi]._miDrawFlag == 1 )
      {
        screen_xa = sx + missile[mi]._mixoff - missile[mi]._miAnimWidth2;
        screen_ya = sy + missile[mi]._miyoff;
        if ( missile[mi]._miUniqTrans )
        {
          Cel2DrawHdrLightRed(
            screen_xa,
            screen_ya,
            missile[mi]._miAnimData,
            missile[mi]._miAnimFrame,
            missile[mi]._miAnimWidth,
            a5,
            a6,
            missile[mi]._miUniqTrans + 3);
        }
        else if ( missile[mi]._miLightFlag )
        {
          Cel2DecodeHdrLight(
            screen_xa,
            screen_ya,
            missile[mi]._miAnimData,
            missile[mi]._miAnimFrame,
            missile[mi]._miAnimWidth,
            a5,
            a6);
        }
        else
        {
          Cel2DrawHdrOnly(
            screen_xa,
            screen_ya,
            missile[mi]._miAnimData,
            missile[mi]._miAnimFrame,
            missile[mi]._miAnimWidth,
            a5,
            a6);
        }
      }
    }
  }
  else
  {
    mi = dMissile[x][y] - 1;
    if ( missile[mi]._miPreFlag == a7 )
    {
      screen_x = sx + missile[mi]._mixoff - missile[mi]._miAnimWidth2;
      screen_y = sy + missile[mi]._miyoff;
      if ( missile[mi]._miUniqTrans )
      {
        Cel2DrawHdrLightRed(
          screen_x,
          screen_y,
          missile[mi]._miAnimData,
          missile[mi]._miAnimFrame,
          missile[mi]._miAnimWidth,
          a5,
          a6,
          missile[mi]._miUniqTrans + 3);
      }
      else if ( missile[mi]._miLightFlag )
      {
        Cel2DecodeHdrLight(
          screen_x,
          screen_y,
          missile[mi]._miAnimData,
          missile[mi]._miAnimFrame,
          missile[mi]._miAnimWidth,
          a5,
          a6);
      }
      else
      {
        Cel2DrawHdrOnly(
          screen_x,
          screen_y,
          missile[mi]._miAnimData,
          missile[mi]._miAnimFrame,
          missile[mi]._miAnimWidth,
          a5,
          a6);
      }
    }
  }
}

//----- (004889C9) --------------------------------------------------------
void __fastcall DrawView(int StartX, int StartY)
{
  BYTE *buf; // edi
  signed int i; // edx
  int y; // [esp+Ch] [ebp-8h]

  y = StartY;
  if ( leveltype == 4 )
  {
    buf = gpBuffer + 122944;
    for (i = 352; i; --i)
    {
      memset(buf, 0, 0x280u);
      buf += 768;
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
  gpBufEnd = &gpBuffer[screen_y_times_768[160]];
  for ( a6 = 0; a6 < 4; ++a6 )
  {
    scrollrt_draw_upper(xa, ya++, sx, sy, a5, a6, 0);
    v2 = sx - 32;
    v3 = sy + 16;
    scrollrt_draw_upper(xa++, ya, v2, v3, a5, a6, 1);
    sx = v2 + 32;
    sy = v3 + 16;
  }
  gpBufEnd = &gpBuffer[screen_y_times_768[512]];
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
  BYTE *buf; // [esp+1Ch] [ebp-10h] MAPDST
  int v22; // [esp+20h] [ebp-Ch]
  SHORT *defs; // [esp+24h] [ebp-8h]
  signed int i; // [esp+28h] [ebp-4h]

  ya = y;
  xa = x;
  defs = dpiece_defs_map_1[gendung_get_dpiece_num_from_coord(x, y)];
  if ( some_flag )
  {
    if ( (unsigned int)ya < 0x70 && (unsigned int)xa < 0x70 )
    {
      level_piece_id = dPiece[xa][ya];
      light_table_index = dTransVal[xa][ya];
      if ( level_piece_id )
      {
        buf = &gpBuffer[sx + 32 + screen_y_times_768[sy]];
        cel_transparency_active = (unsigned __int8)(nTransTable[level_piece_id] & TransList[dung_map[xa][ya]]);
        arch_draw_type = 2;
        LOWORD(level_cel_block) = defs[1];
        if ( (_WORD)level_cel_block )
          drawLowerScreen(buf);
        arch_draw_type = 0;
        buf -= 24576;
        LOWORD(level_cel_block) = defs[3];
        if ( (_WORD)level_cel_block )
          drawLowerScreen(buf);
        buf -= 24576;
        LOWORD(level_cel_block) = defs[5];
        if ( (_WORD)level_cel_block )
          drawLowerScreen(buf);
        buf -= 24576;
        LOWORD(level_cel_block) = defs[7];
        if ( (_WORD)level_cel_block )
          drawLowerScreen(buf);
        buf -= 24576;
        LOWORD(level_cel_block) = defs[9];
        if ( (_WORD)level_cel_block )
          drawLowerScreen(buf);
        buf -= 24576;
        LOWORD(level_cel_block) = defs[11];
        if ( (_WORD)level_cel_block && leveltype == 4 )
          drawLowerScreen(buf);
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
    defs += 16;
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
        buf = &gpBuffer[sx + screen_y_times_768[sy]];
        cel_transparency_active = (unsigned __int8)(nTransTable[level_piece_id] & TransList[dung_map[xa][ya]]);
        arch_draw_type = 1;
        LOWORD(level_cel_block) = *defs;
        if ( (_WORD)level_cel_block )
          drawLowerScreen(buf);
        arch_draw_type = 2;
        LOWORD(level_cel_block) = defs[1];
        if ( (_WORD)level_cel_block )
          drawLowerScreen(buf + 32);
        arch_draw_type = 0;
        for ( i = 2; i < gendung_567144; i += 2 )
        {
          buf -= 24576;
          LOWORD(level_cel_block) = defs[i];
          if ( (_WORD)level_cel_block )
            drawLowerScreen(buf);
          LOWORD(level_cel_block) = defs[i + 1];
          if ( (_WORD)level_cel_block )
            drawLowerScreen(buf + 32);
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
    defs += 16;
  }
  if ( some_flag && (unsigned int)ya < 0x70 && (unsigned int)xa < 0x70 )
  {
    level_piece_id = dPiece[xa][ya];
    light_table_index = dTransVal[xa][ya];
    if ( level_piece_id )
    {
      buf = &gpBuffer[sx + screen_y_times_768[sy]];
      cel_transparency_active = (unsigned __int8)(nTransTable[level_piece_id] & TransList[dung_map[xa][ya]]);
      arch_draw_type = 1;
      LOWORD(level_cel_block) = *defs;
      if ( (_WORD)level_cel_block )
        drawLowerScreen(buf);
      arch_draw_type = 0;
      buf -= 24576;
      LOWORD(level_cel_block) = defs[2];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(buf);
      buf -= 24576;
      LOWORD(level_cel_block) = defs[4];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(buf);
      buf -= 24576;
      LOWORD(level_cel_block) = defs[6];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(buf);
      buf -= 24576;
      LOWORD(level_cel_block) = defs[8];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(buf);
      buf -= 24576;
      LOWORD(level_cel_block) = defs[10];
      if ( (_WORD)level_cel_block && leveltype == 4 )
        drawLowerScreen(buf);
      scrollrt_draw_clipped_dungeon(&gpBuffer[sx + screen_y_times_768[sy]], xa, ya, sx, sy, 0);
    }
    else
    {
      world_draw_black_tile(&gpBuffer[sx + screen_y_times_768[sy]]);
    }
  }
}

//----- (00489531) --------------------------------------------------------
void __fastcall scrollrt_draw_clipped_dungeon(BYTE *a1, int sx, int sy, int a4, int a5, int a6)
{
  PlayerStruct *pd; // [esp+1Ch] [ebp-48h] MAPDST
  MonsterStruct *md; // [esp+20h] [ebp-44h] MAPDST
  ItemStruct *it; // [esp+28h] [ebp-3Ch] MAPDST
  DeadStruct *dd; // [esp+2Ch] [ebp-38h]
  char v15; // [esp+30h] [ebp-34h]
  int monster_up; // [esp+34h] [ebp-30h]
  int screen_x; // [esp+38h] [ebp-2Ch]
  int screen_xa; // [esp+38h] [ebp-2Ch]
  int screen_xb; // [esp+38h] [ebp-2Ch]
  int screen_xc; // [esp+38h] [ebp-2Ch]
  int screen_xd; // [esp+38h] [ebp-2Ch]
  char map_at; // [esp+3Ch] [ebp-28h]
  char arch_at; // [esp+40h] [ebp-24h]
  char player_up; // [esp+44h] [ebp-20h]
  char dead_at; // [esp+48h] [ebp-1Ch]
  int monster_at; // [esp+4Ch] [ebp-18h]
  char player_at; // [esp+50h] [ebp-14h]
  char flags_at; // [esp+54h] [ebp-10h]
  char object_at; // [esp+58h] [ebp-Ch]
  int py; // [esp+5Ch] [ebp-8h]
  int pya; // [esp+5Ch] [ebp-8h]
  char item_at; // [esp+60h] [ebp-4h]

  flags_at = dFlags[sx][sy];
  dead_at = dDead[sx][sy];
  object_at = dObject[sx][sy];
  item_at = dItem[sx][sy];
  player_at = dPlayer[sx][sy];
  arch_at = dArch[sx][sy];
  map_at = dung_map[sx][sy];
  monster_at = dMonster[sx][sy];
  player_up = dPlayer[sx][sy - 1];
  monster_up = dMonster[sx][sy - 1];
  if ( visiondebug && flags_at & 0x40 )
    Cel2DecodeHdrOnly(a1, pSquareCel, 1, 64, 0, 8);
  if ( MissilePreFlag && flags_at & 1 )
    DrawClippedMissile(sx, sy, a4, a5, 0, 8, 1);
  if ( lightmax > light_table_index )
  {
    if ( dead_at )
    {
      dd = &dead[(dead_at & 0x1F) - 1];
      v15 = (unsigned __int8)(dead_at & 0xE0) >> 5;
      screen_x = a4 - dead[(dead_at & 0x1F) - 1]._deadWidth2;
      if ( dead[(dead_at & 0x1F) - 1]._deadtrans )
        Cel2DrawHdrLightRed(screen_x, a5, dd->_deadData[v15], dd->_deadFrame, dd->_deadWidth, 0, 8, dd->_deadtrans);
      else
        Cel2DecodeHdrLight(screen_x, a5, dd->_deadData[v15], dd->_deadFrame, dd->_deadWidth, 0, 8);
    }
    if ( object_at )
      DrawClippedObject(sx, sy, a4, a5, 1, 0, 8);
  }
  if ( item_at )
  {
    it = &item[item_at - 1];
    if ( !it->_iPostDraw )
    {
      screen_xa = a4 - it->_iAnimWidth2;
      if ( item_at - 1 == pcursitem )
        CelDrawHdrClrHL(181, screen_xa, a5, it->_iAnimData, it->_iAnimFrame, it->_iAnimWidth, 0, 8);
      Cel2DecodeHdrLight(screen_xa, a5, it->_iAnimData, it->_iAnimFrame, it->_iAnimWidth, 0, 8);
    }
  }
  if ( flags_at & 0x20 )
  {
    pd = &plr[-(player_up + 1)];
    DrawClippedPlayer(
      -(player_up + 1),
      sx,
      sy - 1,
      a4 + plr[-player_up - 1]._pxoff - plr[-player_up - 1]._pAnimWidth2,
      a5 + plr[-player_up - 1]._pyoff,
      plr[-player_up - 1]._pAnimData,
      plr[-player_up - 1]._pAnimFrame,
      plr[-player_up - 1]._pAnimWidth,
      0,
      8);
    if ( a6 )
    {
      if ( pd->_peflag )
      {
        if ( pd->_peflag == 2 )
          scrollrt_draw_clipped_e_flag(a1 - 12384, sx - 2, sy + 1, a4 - 96, a5 - 16);
        scrollrt_draw_clipped_e_flag(a1 - 64, sx - 1, sy + 1, a4 - 64, a5);
      }
    }
  }
  if ( flags_at & 0x10 && (flags_at & 0x40 || plr[myplr]._pInfraFlag) )
  {
    mon_id = -(monster_up + 1);
    md = &monster[-(monster_up + 1)];
    if ( monster[-monster_up - 1]._mFlags & 1 )
    {
      screen_xb = a4 + md->_mxoff - md->MType->flags_2;
      py = a5 + md->_myoff;
      if ( mon_id == pcursmonst )
        CelDrawHdrClrHL(233, screen_xb, py, md->_mAnimData, md->_mAnimFrame, md->MType->flags_1, 0, 8);
      DrawClippedMonster(sx, sy, screen_xb, py, mon_id, 0, 8);
      if ( a6 && md->_meflag )
        scrollrt_draw_clipped_e_flag(a1 - 64, sx - 1, sy + 1, a4 - 64, a5);
    }
  }
  if ( player_at > 0 )
  {
    pd = &plr[player_at - 1];
    DrawClippedPlayer(
      player_at - 1,
      sx,
      sy,
      a4 + plr[player_at - 1]._pxoff - plr[player_at - 1]._pAnimWidth2,
      a5 + plr[player_at - 1]._pyoff,
      plr[player_at - 1]._pAnimData,
      plr[player_at - 1]._pAnimFrame,
      plr[player_at - 1]._pAnimWidth,
      0,
      8);
    if ( a6 )
    {
      if ( pd->_peflag )
      {
        if ( pd->_peflag == 2 )
          scrollrt_draw_clipped_e_flag(a1 - 12384, sx - 2, sy + 1, a4 - 96, a5 - 16);
        scrollrt_draw_clipped_e_flag(a1 - 64, sx - 1, sy + 1, a4 - 64, a5);
      }
    }
  }
  if ( monster_at > 0 && (flags_at & 0x40 || plr[myplr]._pInfraFlag) )
  {
    mon_id = monster_at - 1;
    md = &monster[monster_at - 1];
    if ( monster[monster_at - 1]._mFlags & 1 )
    {
      screen_xc = a4 + md->_mxoff - md->MType->flags_2;
      pya = a5 + md->_myoff;
      if ( mon_id == pcursmonst )
        CelDrawHdrClrHL(233, screen_xc, pya, md->_mAnimData, md->_mAnimFrame, md->MType->flags_1, 0, 8);
      DrawClippedMonster(sx, sy, screen_xc, pya, mon_id, 0, 8);
      if ( a6 && md->_meflag )
        scrollrt_draw_clipped_e_flag(a1 - 64, sx - 1, sy + 1, a4 - 64, a5);
    }
  }
  if ( flags_at & 1 )
    DrawClippedMissile(sx, sy, a4, a5, 0, 8, 0);
  if ( object_at && lightmax > light_table_index )
    DrawClippedObject(sx, sy, a4, a5, 0, 0, 8);
  if ( item_at )
  {
    it = &item[item_at - 1];
    if ( it->_iPostDraw )
    {
      screen_xd = a4 - it->_iAnimWidth2;
      if ( item_at - 1 == pcursitem )
        CelDrawHdrClrHL(181, screen_xd, a5, it->_iAnimData, it->_iAnimFrame, it->_iAnimWidth, 0, 8);
      Cel2DecodeHdrLight(screen_xd, a5, it->_iAnimData, it->_iAnimFrame, it->_iAnimWidth, 0, 8);
    }
  }
  if ( arch_at )
  {
    cel_transparency_active = TransList[map_at];
    Cel2DecodeLightTrans(a1, level_special_cel, arch_at, 64, 0, 8);
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
        monster[mon_id]._mAnimData,
        monster[mon_id]._mAnimFrame,
        monster[mon_id].MType->flags_1,
        a6,
        a7,
        always_1);
    else
      Cel2DecodeHdrLight(
        a3,
        a4,
        monster[mon_id]._mAnimData,
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
      monster[mon_id]._mAnimData,
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
      CelDrawHdrClrHL(165, px, py, (BYTE *)animdata, animframe, animwidth, a9, a10);
    if ( myplr == pnum )
    {
      Cel2DrawHdrOnly(px, py, (BYTE *)animdata, animframe, animwidth, a9, a10);
    }
    else if ( dFlags[x][y] & 0x40 && (!plr[myplr]._pInfraFlag || light_table_index <= 8) )
    {
      v12 = light_table_index;
      if ( light_table_index < 5 )
        light_table_index = 0;
      else
        light_table_index -= 5;
      Cel2DecodeHdrLight(px, py, (BYTE *)animdata, animframe, animwidth, a9, a10);
      light_table_index = v12;
    }
    else
    {
      Cel2DrawHdrLightRed(px, py, (BYTE *)animdata, animframe, animwidth, a9, a10, 1);
    }
  }
}

//----- (0048A142) --------------------------------------------------------
void __fastcall DrawClippedObject(int x, int y, int a3, int a4, int pre_flag, int a6, int dir)
{
  int d_x; // ST3C_4
  int d_y; // ST38_4
  int screen_x; // [esp+14h] [ebp-14h]
  char object_at; // [esp+18h] [ebp-10h]
  int screen_y; // [esp+1Ch] [ebp-Ch]

  if ( dObject[x][y] <= 0 )
  {
    object_at = -(char)(dObject[x][y] + 1);
    if ( object[object_at]._oPreFlag != pre_flag )
      return;
    d_x = object[object_at]._ox - x;
    d_y = object[object_at]._oy - y;
    screen_x = 32 * d_x + a3 - object[object_at]._oAnimWidth2 - 32 * d_y;
    screen_y = a4 + 16 * d_x + 16 * d_y;
    a6 = 0;
    dir = 8;
  }
  else
  {
    object_at = dObject[x][y] - 1;
    if ( object[object_at]._oPreFlag != pre_flag )
      return;
    screen_x = a3 - object[object_at]._oAnimWidth2;
    screen_y = a4;
  }
  if ( pcursobj == object_at )
    CelDrawHdrClrHL(
      194,
      screen_x,
      screen_y,
      (BYTE *)object[object_at]._oAnimData,
      object[object_at]._oAnimFrame,
      object[object_at]._oAnimWidth,
      a6,
      dir);
  if ( object[object_at]._oLight )
    Cel2DecodeHdrLight(
      screen_x,
      screen_y,
      (BYTE *)object[object_at]._oAnimData,
      object[object_at]._oAnimFrame,
      object[object_at]._oAnimWidth,
      a6,
      dir);
  else
    Cel2DrawHdrOnly(
      screen_x,
      screen_y,
      (BYTE *)object[object_at]._oAnimData,
      object[object_at]._oAnimFrame,
      object[object_at]._oAnimWidth,
      a6,
      dir);
}

//----- (0048A39F) --------------------------------------------------------
void __fastcall scrollrt_draw_clipped_e_flag(BYTE *buffer, int x, int y, int a4, int a5)
{
  int old_lpi; // [esp+14h] [ebp-18h]
  SHORT *defs; // [esp+18h] [ebp-14h]
  unsigned __int8 *pbDst; // [esp+1Ch] [ebp-10h]
  int old_lti; // [esp+20h] [ebp-Ch]
  int old_cta; // [esp+24h] [ebp-8h]
  signed int i; // [esp+28h] [ebp-4h]

  old_lti = light_table_index;
  old_cta = cel_transparency_active;
  old_lpi = level_piece_id;
  level_piece_id = dPiece[x][y];
  light_table_index = dTransVal[x][y];
  cel_transparency_active = (unsigned __int8)(nTransTable[level_piece_id] & TransList[dung_map[x][y]]);
  defs = dpiece_defs_map_1[gendung_get_dpiece_num_from_coord(x, y)];
  arch_draw_type = 1;
  LOWORD(level_cel_block) = *defs;
  if ( (_WORD)level_cel_block )
    drawLowerScreen(buffer);
  arch_draw_type = 2;
  LOWORD(level_cel_block) = defs[1];
  if ( (_WORD)level_cel_block )
    drawLowerScreen(buffer + 32);
  arch_draw_type = 0;
  pbDst = buffer;
  for ( i = 2; i < gendung_567144; i += 2 )
  {
    pbDst -= 24576;
    LOWORD(level_cel_block) = defs[i];
    if ( (_WORD)level_cel_block )
      drawLowerScreen(pbDst);
    LOWORD(level_cel_block) = defs[i + 1];
    if ( (_WORD)level_cel_block )
      drawLowerScreen(pbDst + 32);
  }
  scrollrt_draw_clipped_dungeon(buffer, x, y, a4, a5, 0);
  light_table_index = old_lti;
  cel_transparency_active = old_cta;
  level_piece_id = old_lpi;
}

//----- (0048A56C) --------------------------------------------------------
void __fastcall scrollrt_draw_lower_2(int x, int y, int sx, int sy, int a5, int a6, int some_flag)
{
  int v7; // ST2C_4
  signed int ya; // [esp+Ch] [ebp-24h]
  signed int xa; // [esp+10h] [ebp-20h]
  BYTE *buf; // [esp+1Ch] [ebp-14h] MAPDST
  int v13; // [esp+20h] [ebp-10h]
  int v14; // [esp+24h] [ebp-Ch]
  SHORT *defs; // [esp+28h] [ebp-8h]
  int i; // [esp+2Ch] [ebp-4h]
  int v17; // [esp+2Ch] [ebp-4h]
  int j; // [esp+2Ch] [ebp-4h]

  ya = y;
  xa = x;
  defs = dpiece_defs_map_1[gendung_get_dpiece_num_from_coord(x, y)];
  v13 = 2 * a6 + 2;
  if ( some_flag )
  {
    if ( ya >= 0 && ya < 112 && xa >= 0 && xa < 112 )
    {
      level_piece_id = dPiece[xa][ya];
      light_table_index = dTransVal[xa][ya];
      if ( level_piece_id )
      {
        buf = &gpBuffer[sx - 24544 + screen_y_times_768[sy]];
        cel_transparency_active = (unsigned __int8)(nTransTable[level_piece_id] & TransList[dung_map[xa][ya]]);
        for ( i = 0; (gendung_567144 >> 1) - 1 > i; ++i )
        {
          if ( i >= a6 )
          {
            LOWORD(level_cel_block) = defs[2 * i + 3];
            if ( (_WORD)level_cel_block )
              drawLowerScreen(buf);
          }
          buf -= 24576;
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
    defs += 16;
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
        buf = &gpBuffer[sx - 24576 + screen_y_times_768[sy]];
        cel_transparency_active = (unsigned __int8)(nTransTable[level_piece_id] & TransList[dung_map[xa][ya]]);
        v17 = 0;
        while ( (gendung_567144 >> 1) - 2 > v17 )
        {
          if ( v17 >= a6 )
          {
            LOWORD(level_cel_block) = defs[2 * v17 + 2];
            if ( (_WORD)level_cel_block )
              drawLowerScreen(buf);
            LOWORD(level_cel_block) = defs[2 * v17 + 3];
            if ( (_WORD)level_cel_block )
              drawLowerScreen(buf + 32);
          }
          ++v17;
          buf -= 24576;
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
    defs += 16;
  }
  if ( some_flag )
  {
    if ( (unsigned int)ya < 0x70 && (unsigned int)xa < 0x70 )
    {
      level_piece_id = dPiece[xa][ya];
      light_table_index = dTransVal[xa][ya];
      if ( level_piece_id )
      {
        buf = &gpBuffer[sx - 24576 + screen_y_times_768[sy]];
        cel_transparency_active = (unsigned __int8)(nTransTable[level_piece_id] & TransList[dung_map[xa][ya]]);
        for ( j = 0; (gendung_567144 >> 1) - 1 > j; ++j )
        {
          if ( j >= a6 )
          {
            LOWORD(level_cel_block) = defs[2 * j + 2];
            if ( (_WORD)level_cel_block )
              drawLowerScreen(buf);
          }
          buf -= 24576;
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
void __fastcall scrollrt_draw_clipped_dungeon_2(BYTE *buffer, int x, int y, int a4, int a5, int sx, int sy, int me_flag)
{
  MonsterStruct *md; // [esp+20h] [ebp-44h] MAPDST
  PlayerStruct *pd; // [esp+24h] [ebp-40h] MAPDST
  ItemStruct *it; // [esp+28h] [ebp-3Ch] MAPDST
  DeadStruct *dd; // [esp+2Ch] [ebp-38h]
  char v17; // [esp+30h] [ebp-34h]
  int monster_up; // [esp+34h] [ebp-30h]
  int screen_x; // [esp+38h] [ebp-2Ch]
  int screen_xa; // [esp+38h] [ebp-2Ch]
  int screen_xb; // [esp+38h] [ebp-2Ch]
  int screen_xc; // [esp+38h] [ebp-2Ch]
  int screen_xd; // [esp+38h] [ebp-2Ch]
  char map_at; // [esp+3Ch] [ebp-28h]
  char arch_at; // [esp+40h] [ebp-24h]
  char player_up; // [esp+44h] [ebp-20h]
  char dead_at; // [esp+48h] [ebp-1Ch]
  int monster_at; // [esp+4Ch] [ebp-18h]
  char player_at; // [esp+50h] [ebp-14h]
  char flags_at; // [esp+54h] [ebp-10h]
  char object_at; // [esp+58h] [ebp-Ch]
  int py; // [esp+5Ch] [ebp-8h]
  int pya; // [esp+5Ch] [ebp-8h]
  char item_at; // [esp+60h] [ebp-4h]

  flags_at = dFlags[x][y];
  dead_at = dDead[x][y];
  object_at = dObject[x][y];
  item_at = dItem[x][y];
  player_at = dPlayer[x][y];
  arch_at = dArch[x][y];
  map_at = dung_map[x][y];
  monster_at = dMonster[x][y];
  player_up = dPlayer[x][y - 1];
  monster_up = dMonster[x][y - 1];
  if ( visiondebug && flags_at & 0x40 )
    Cel2DecodeHdrOnly(buffer, pSquareCel, 1, 64, a5, 8);
  if ( MissilePreFlag && flags_at & 1 )
    DrawClippedMissile(x, y, sx, sy, a5, 8, 1);
  if ( lightmax > light_table_index )
  {
    if ( dead_at )
    {
      dd = &dead[(dead_at & 0x1F) - 1];
      v17 = (unsigned __int8)(dead_at & 0xE0) >> 5;
      screen_x = sx - dead[(dead_at & 0x1F) - 1]._deadWidth2;
      if ( dead[(dead_at & 0x1F) - 1]._deadtrans )
        Cel2DrawHdrLightRed(screen_x, sy, dd->_deadData[v17], dd->_deadFrame, dd->_deadWidth, a5, 8, dd->_deadtrans);
      else
        Cel2DecodeHdrLight(screen_x, sy, dd->_deadData[v17], dd->_deadFrame, dd->_deadWidth, a5, 8);
    }
    if ( object_at )
      DrawClippedObject(x, y, sx, sy, 1, a5, 8);
  }
  if ( item_at )
  {
    it = &item[item_at - 1];
    if ( !it->_iPostDraw )
    {
      screen_xa = sx - it->_iAnimWidth2;
      if ( item_at - 1 == pcursitem )
        CelDrawHdrClrHL(181, screen_xa, sy, it->_iAnimData, it->_iAnimFrame, it->_iAnimWidth, a5, 8);
      Cel2DecodeHdrLight(screen_xa, sy, it->_iAnimData, it->_iAnimFrame, it->_iAnimWidth, a5, 8);
    }
  }
  if ( flags_at & 0x20 )
  {
    pd = &plr[-(player_up + 1)];
    DrawClippedPlayer(
      -(player_up + 1),
      x,
      y - 1,
      sx + plr[-player_up - 1]._pxoff - plr[-player_up - 1]._pAnimWidth2,
      sy + plr[-player_up - 1]._pyoff,
      plr[-player_up - 1]._pAnimData,
      plr[-player_up - 1]._pAnimFrame,
      plr[-player_up - 1]._pAnimWidth,
      a5,
      8);
    if ( me_flag )
    {
      if ( pd->_peflag )
      {
        if ( pd->_peflag == 2 )
          scrollrt_draw_clipped_e_flag_2(buffer - 12384, x - 2, y + 1, a4, a5, sx - 96, sy - 16);
        scrollrt_draw_clipped_e_flag_2(buffer - 64, x - 1, y + 1, a4, a5, sx - 64, sy);
      }
    }
  }
  if ( flags_at & 0x10 && (flags_at & 0x40 || plr[myplr]._pInfraFlag) )
  {
    mon_id = -(monster_up + 1);
    md = &monster[-(monster_up + 1)];
    if ( monster[-monster_up - 1]._mFlags & 1 )
    {
      screen_xb = sx + md->_mxoff - md->MType->flags_2;
      py = sy + md->_myoff;
      if ( mon_id == pcursmonst )
        CelDrawHdrClrHL(233, screen_xb, py, md->_mAnimData, md->_mAnimFrame, md->MType->flags_1, a5, 8);
      DrawClippedMonster(x, y, screen_xb, py, mon_id, a5, 8);
      if ( me_flag && !md->_meflag )
        scrollrt_draw_clipped_e_flag_2(buffer - 64, x - 1, y + 1, a4, a5, sx - 64, sy);
    }
  }
  if ( player_at > 0 )
  {
    pd = &plr[player_at - 1];
    DrawClippedPlayer(
      player_at - 1,
      x,
      y,
      sx + plr[player_at - 1]._pxoff - plr[player_at - 1]._pAnimWidth2,
      sy + plr[player_at - 1]._pyoff,
      plr[player_at - 1]._pAnimData,
      plr[player_at - 1]._pAnimFrame,
      plr[player_at - 1]._pAnimWidth,
      a5,
      8);
    if ( me_flag )
    {
      if ( pd->_peflag )
      {
        if ( pd->_peflag == 2 )
          scrollrt_draw_clipped_e_flag_2(buffer - 12384, x - 2, y + 1, a4, a5, sx - 96, sy - 16);
        scrollrt_draw_clipped_e_flag_2(buffer - 64, x - 1, y + 1, a4, a5, sx - 64, sy);
      }
    }
  }
  if ( monster_at > 0 && (flags_at & 0x40 || plr[myplr]._pInfraFlag) )
  {
    mon_id = monster_at - 1;
    md = &monster[monster_at - 1];
    if ( monster[monster_at - 1]._mFlags & 1 )
    {
      screen_xc = sx + md->_mxoff - md->MType->flags_2;
      pya = sy + md->_myoff;
      if ( mon_id == pcursmonst )
        CelDrawHdrClrHL(233, screen_xc, pya, md->_mAnimData, md->_mAnimFrame, md->MType->flags_1, a5, 8);
      DrawClippedMonster(x, y, screen_xc, pya, mon_id, a5, 8);
      if ( me_flag && !md->_meflag )
        scrollrt_draw_clipped_e_flag_2(buffer - 64, x - 1, y + 1, a4, a5, sx - 64, sy);
    }
  }
  if ( flags_at & 1 )
    DrawClippedMissile(x, y, sx, sy, a5, 8, 0);
  if ( object_at && lightmax > light_table_index )
    DrawClippedObject(x, y, sx, sy, 0, a5, 8);
  if ( item_at )
  {
    it = &item[item_at - 1];
    if ( it->_iPostDraw )
    {
      screen_xd = sx - it->_iAnimWidth2;
      if ( item_at - 1 == pcursitem )
        CelDrawHdrClrHL(181, screen_xd, sy, it->_iAnimData, it->_iAnimFrame, it->_iAnimWidth, a5, 8);
      Cel2DecodeHdrLight(screen_xd, sy, it->_iAnimData, it->_iAnimFrame, it->_iAnimWidth, a5, 8);
    }
  }
  if ( arch_at )
  {
    cel_transparency_active = TransList[map_at];
    Cel2DecodeLightTrans(buffer, level_special_cel, arch_at, 64, a5, 8);
  }
}

//----- (0048B36A) --------------------------------------------------------
void __fastcall scrollrt_draw_clipped_e_flag_2(BYTE *buffer, int x, int y, int a4, signed int a5, int sx, int sy)
{
  int old_lpi; // [esp+18h] [ebp-14h]
  SHORT *defs; // [esp+1Ch] [ebp-10h]
  BYTE *buf; // [esp+20h] [ebp-Ch]
  BYTE *a1a; // [esp+20h] [ebp-Ch]
  int old_lti; // [esp+24h] [ebp-8h]
  int old_cta; // [esp+28h] [ebp-4h]

  old_lti = light_table_index;
  old_cta = cel_transparency_active;
  old_lpi = level_piece_id;
  level_piece_id = dPiece[x][y];
  light_table_index = dTransVal[x][y];
  buf = &buffer[24576 * a4];
  cel_transparency_active = (unsigned __int8)(nTransTable[level_piece_id] & TransList[dung_map[x][y]]);
  defs = dpiece_defs_map_1[gendung_get_dpiece_num_from_coord(x, y)];
  switch ( a4 )
  {
    case 0:
      LOWORD(level_cel_block) = defs[2];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(buf);
      LOWORD(level_cel_block) = defs[3];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(buf + 32);
      goto LABEL_6;
    case 1:
LABEL_6:
      buf -= 24576;
      LOWORD(level_cel_block) = defs[4];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(buf);
      LOWORD(level_cel_block) = defs[5];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(buf + 32);
      goto LABEL_10;
    case 2:
LABEL_10:
      buf -= 24576;
      LOWORD(level_cel_block) = defs[6];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(buf);
      LOWORD(level_cel_block) = defs[7];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(buf + 32);
      goto LABEL_14;
    case 3:
LABEL_14:
      a1a = buf - 24576;
      LOWORD(level_cel_block) = defs[8];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(a1a);
      LOWORD(level_cel_block) = defs[9];
      if ( (_WORD)level_cel_block )
        drawLowerScreen(a1a + 32);
      break;
    default:
      break;
  }
  if ( a5 < 8 )
    scrollrt_draw_clipped_dungeon_2(buffer, x, y, a4, a5, sx, sy, 0);
  light_table_index = old_lti;
  cel_transparency_active = old_cta;
  level_piece_id = old_lpi;
}

//----- (0048B5F0) --------------------------------------------------------
void __fastcall scrollrt_draw_upper(int x, int y, int sx, int sy, int a5, int a6, int some_flag)
{
  signed int ya; // [esp+Ch] [ebp-20h]
  signed int xa; // [esp+10h] [ebp-1Ch]
  BYTE *a1a; // [esp+18h] [ebp-14h]
  BYTE *a1b; // [esp+18h] [ebp-14h]
  BYTE *a1c; // [esp+18h] [ebp-14h]
  BYTE *buf; // [esp+18h] [ebp-14h] MAPDST
  BYTE *a1f; // [esp+18h] [ebp-14h]
  BYTE *a1g; // [esp+18h] [ebp-14h]
  BYTE *a1h; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  SHORT *defs; // [esp+20h] [ebp-Ch]
  int j; // [esp+24h] [ebp-8h]
  int v21; // [esp+28h] [ebp-4h]

  ya = y;
  xa = x;
  defs = dpiece_defs_map_1[gendung_get_dpiece_num_from_coord(x, y)];
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
        buf = &gpBuffer[sx + 32 + screen_y_times_768[sy]];
        cel_transparency_active = (unsigned __int8)(nTransTable[level_piece_id] & TransList[dung_map[xa][ya]]);
        if ( a6 >= 0 )
        {
          LOWORD(level_cel_block) = defs[1];
          if ( (_WORD)level_cel_block )
          {
            arch_draw_type = 2;
            drawUpperScreen(buf);
            arch_draw_type = 0;
          }
        }
        a1a = buf - 24576;
        if ( a6 >= 1 )
        {
          LOWORD(level_cel_block) = defs[3];
          if ( (_WORD)level_cel_block )
            drawUpperScreen(a1a);
        }
        a1b = a1a - 24576;
        if ( a6 >= 2 )
        {
          LOWORD(level_cel_block) = defs[5];
          if ( (_WORD)level_cel_block )
            drawUpperScreen(a1b);
        }
        a1c = a1b - 24576;
        if ( a6 >= 3 )
        {
          LOWORD(level_cel_block) = defs[7];
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
    defs += 16;
  }
  for ( i = 0; a5 > i; ++i )
  {
    if ( ya >= 0 && ya < 112 && xa >= 0 && xa < 112 )
    {
      level_piece_id = dPiece[xa][ya];
      light_table_index = dTransVal[xa][ya];
      if ( level_piece_id )
      {
        buf = &gpBuffer[sx + screen_y_times_768[sy]];
        cel_transparency_active = (unsigned __int8)(nTransTable[level_piece_id] & TransList[dung_map[xa][ya]]);
        arch_draw_type = 1;
        LOWORD(level_cel_block) = *defs;
        if ( (_WORD)level_cel_block )
          drawUpperScreen(buf);
        arch_draw_type = 2;
        LOWORD(level_cel_block) = defs[1];
        if ( (_WORD)level_cel_block )
          drawUpperScreen(buf + 32);
        arch_draw_type = 0;
        for ( j = 1; (gendung_567144 >> 1) - 1 > j; ++j )
        {
          buf -= 24576;
          if ( a6 >= j )
          {
            LOWORD(level_cel_block) = defs[2 * j];
            if ( (_WORD)level_cel_block )
              drawUpperScreen(buf);
            LOWORD(level_cel_block) = defs[2 * j + 1];
            if ( (_WORD)level_cel_block )
              drawUpperScreen(buf + 32);
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
    defs += 16;
  }
  if ( some_flag && ya >= 0 && ya < 112 && xa >= 0 && xa < 112 )
  {
    level_piece_id = dPiece[xa][ya];
    light_table_index = dTransVal[xa][ya];
    if ( level_piece_id )
    {
      buf = &gpBuffer[sx + screen_y_times_768[sy]];
      cel_transparency_active = (unsigned __int8)(nTransTable[level_piece_id] & TransList[dung_map[xa][ya]]);
      arch_draw_type = 1;
      if ( a6 >= 0 )
      {
        LOWORD(level_cel_block) = *defs;
        if ( (_WORD)level_cel_block )
          drawUpperScreen(buf);
      }
      arch_draw_type = 0;
      a1f = buf - 24576;
      if ( a6 >= 1 )
      {
        LOWORD(level_cel_block) = defs[2];
        if ( (_WORD)level_cel_block )
          drawUpperScreen(a1f);
      }
      a1g = a1f - 24576;
      if ( a6 >= 2 )
      {
        LOWORD(level_cel_block) = defs[4];
        if ( (_WORD)level_cel_block )
          drawUpperScreen(a1g);
      }
      a1h = a1g - 24576;
      if ( a6 >= 3 )
      {
        LOWORD(level_cel_block) = defs[6];
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
void __fastcall scrollrt_draw_dungeon(BYTE *buffer, int x, int y, int a4, int a5, int sx, int sy, int me_flag)
{
  MonsterStruct *md; // [esp+20h] [ebp-44h] MAPDST
  PlayerStruct *pd; // [esp+24h] [ebp-40h] MAPDST
  ItemStruct *it; // [esp+28h] [ebp-3Ch] MAPDST
  DeadStruct *dd; // [esp+2Ch] [ebp-38h]
  char v17; // [esp+30h] [ebp-34h]
  int monster_up; // [esp+34h] [ebp-30h]
  int screen_x; // [esp+38h] [ebp-2Ch]
  int screen_xa; // [esp+38h] [ebp-2Ch]
  int screen_xb; // [esp+38h] [ebp-2Ch]
  int screen_xc; // [esp+38h] [ebp-2Ch]
  int screen_xd; // [esp+38h] [ebp-2Ch]
  char map_at; // [esp+3Ch] [ebp-28h]
  char arch_at; // [esp+40h] [ebp-24h]
  char player_up; // [esp+44h] [ebp-20h]
  char dead_at; // [esp+48h] [ebp-1Ch]
  int monster_at; // [esp+4Ch] [ebp-18h]
  char player_at; // [esp+50h] [ebp-14h]
  char flags_at; // [esp+54h] [ebp-10h]
  char object_at; // [esp+58h] [ebp-Ch]
  int py; // [esp+5Ch] [ebp-8h]
  int pya; // [esp+5Ch] [ebp-8h]
  char item_at; // [esp+60h] [ebp-4h]

  flags_at = dFlags[x][y];
  dead_at = dDead[x][y];
  object_at = dObject[x][y];
  item_at = dItem[x][y];
  player_at = dPlayer[x][y];
  arch_at = dArch[x][y];
  map_at = dung_map[x][y];
  monster_at = dMonster[x][y];
  player_up = dPlayer[x][y - 1];
  monster_up = dMonster[x][y - 1];
  if ( visiondebug && flags_at & 0x40 )
    CelDecodeHdrOnly(buffer, pSquareCel, 1, 64, 0, a5);
  if ( MissilePreFlag && flags_at & 1 )
    DrawMissile(x, y, sx, sy, 0, a5, 1);
  if ( lightmax > light_table_index )
  {
    if ( dead_at )
    {
      dd = &dead[(dead_at & 0x1F) - 1];
      v17 = (unsigned __int8)(dead_at & 0xE0) >> 5;
      screen_x = sx - dead[(dead_at & 0x1F) - 1]._deadWidth2;
      if ( dead[(dead_at & 0x1F) - 1]._deadtrans )
        CelDrawHdrLightRed(
          screen_x,
          sy,
          (char *)dd->_deadData[v17],
          dd->_deadFrame,
          dd->_deadWidth,
          0,
          a5,
          dd->_deadtrans);
      else
        CelDecodeHdrLightOnly(screen_x, sy, (char *)dd->_deadData[v17], dd->_deadFrame, dd->_deadWidth, 0, a5);
    }
    if ( object_at )
      DrawObject(x, y, sx, sy, 1, 0, a5);
  }
  if ( item_at )
  {
    it = &item[item_at - 1];
    if ( !it->_iPostDraw )
    {
      screen_xa = sx - it->_iAnimWidth2;
      if ( item_at - 1 == pcursitem )
        CelDecodeClr(181, screen_xa, sy, it->_iAnimData, it->_iAnimFrame, it->_iAnimWidth, 0, a5);
      CelDecodeHdrLightOnly(screen_xa, sy, (char *)it->_iAnimData, it->_iAnimFrame, it->_iAnimWidth, 0, a5);
    }
  }
  if ( flags_at & 0x20 )
  {
    pd = &plr[-(player_up + 1)];
    DrawPlayer(
      -(player_up + 1),
      x,
      y - 1,
      sx + plr[-player_up - 1]._pxoff - plr[-player_up - 1]._pAnimWidth2,
      sy + plr[-player_up - 1]._pyoff,
      plr[-player_up - 1]._pAnimData,
      plr[-player_up - 1]._pAnimFrame,
      plr[-player_up - 1]._pAnimWidth,
      0,
      a5);
    if ( me_flag )
    {
      if ( pd->_peflag )
      {
        if ( pd->_peflag == 2 )
          scrollrt_draw_e_flag(buffer - 12384, x - 2, y + 1, a4, a5, sx - 96, sy - 16);
        scrollrt_draw_e_flag(buffer - 64, x - 1, y + 1, a4, a5, sx - 64, sy);
      }
    }
  }
  if ( flags_at & 0x10 && (flags_at & 0x40 || plr[myplr]._pInfraFlag) )
  {
    mon_id = -(monster_up + 1);
    md = &monster[-(monster_up + 1)];
    if ( monster[-monster_up - 1]._mFlags & 1 )
    {
      screen_xb = sx + md->_mxoff - md->MType->flags_2;
      py = sy + md->_myoff;
      if ( mon_id == pcursmonst )
        CelDecodeClr(233, screen_xb, py, md->_mAnimData, md->_mAnimFrame, md->MType->flags_1, 0, a5);
      DrawMonster(x, y, screen_xb, py, mon_id, 0, a5);
      if ( me_flag && !md->_meflag )
        scrollrt_draw_e_flag(buffer - 64, x - 1, y + 1, a4, a5, sx - 64, sy);
    }
  }
  if ( player_at > 0 )
  {
    pd = &plr[player_at - 1];
    DrawPlayer(
      player_at - 1,
      x,
      y,
      sx + plr[player_at - 1]._pxoff - plr[player_at - 1]._pAnimWidth2,
      sy + plr[player_at - 1]._pyoff,
      plr[player_at - 1]._pAnimData,
      plr[player_at - 1]._pAnimFrame,
      plr[player_at - 1]._pAnimWidth,
      0,
      a5);
    if ( me_flag )
    {
      if ( pd->_peflag )
      {
        if ( pd->_peflag == 2 )
          scrollrt_draw_e_flag(buffer - 12384, x - 2, y + 1, a4, a5, sx - 96, sy - 16);
        scrollrt_draw_e_flag(buffer - 64, x - 1, y + 1, a4, a5, sx - 64, sy);
      }
    }
  }
  if ( monster_at > 0 && (flags_at & 0x40 || plr[myplr]._pInfraFlag) )
  {
    mon_id = monster_at - 1;
    md = &monster[monster_at - 1];
    if ( monster[monster_at - 1]._mFlags & 1 )
    {
      screen_xc = sx + md->_mxoff - md->MType->flags_2;
      pya = sy + md->_myoff;
      if ( mon_id == pcursmonst )
        CelDecodeClr(233, screen_xc, pya, md->_mAnimData, md->_mAnimFrame, md->MType->flags_1, 0, a5);
      DrawMonster(x, y, screen_xc, pya, mon_id, 0, a5);
      if ( me_flag && !md->_meflag )
        scrollrt_draw_e_flag(buffer - 64, x - 1, y + 1, a4, a5, sx - 64, sy);
    }
  }
  if ( flags_at & 1 )
    DrawMissile(x, y, sx, sy, 0, a5, 0);
  if ( object_at && lightmax > light_table_index )
    DrawObject(x, y, sx, sy, 0, 0, a5);
  if ( item_at )
  {
    it = &item[item_at - 1];
    if ( it->_iPostDraw )
    {
      screen_xd = sx - it->_iAnimWidth2;
      if ( item_at - 1 == pcursitem )
        CelDecodeClr(181, screen_xd, sy, it->_iAnimData, it->_iAnimFrame, it->_iAnimWidth, 0, a5);
      CelDecodeHdrLightOnly(screen_xd, sy, (char *)it->_iAnimData, it->_iAnimFrame, it->_iAnimWidth, 0, a5);
    }
  }
  if ( arch_at )
  {
    cel_transparency_active = TransList[map_at];
    CelDecodeHdrLightTrans(buffer, level_special_cel, arch_at, 64, 0, a5);
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
  int old_lti; // [esp+14h] [ebp-4h]

  if ( dFlags[x][y] & 0x40 || plr[myplr]._pInfraFlag )
  {
    if ( pcursplr == pnum )
      CelDecodeClr(165, px, py, (BYTE *)animdata, animframe, animwidth, a9, a10);
    if ( myplr == pnum )
    {
      assert(animdata, "SCROLLRT.CPP", 246);
      CelDrawHdrOnly(px, py, (BYTE *)animdata, animframe, animwidth, a9, a10);
    }
    else if ( dFlags[x][y] & 0x40 && (!plr[myplr]._pInfraFlag || light_table_index <= 8) )
    {
      old_lti = light_table_index;
      if ( light_table_index < 5 )
        light_table_index = 0;
      else
        light_table_index -= 5;
      CelDecodeHdrLightOnly(px, py, (char *)animdata, animframe, animwidth, a9, a10);
      light_table_index = old_lti;
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
  int d_x; // ST3C_4
  int d_y; // ST38_4
  int screen_x; // [esp+14h] [ebp-14h]
  char object_at; // [esp+18h] [ebp-10h]
  int screen_y; // [esp+1Ch] [ebp-Ch]

  if ( dObject[x][y] <= 0 )
  {
    object_at = -(char)(dObject[x][y] + 1);
    if ( object[object_at]._oPreFlag != pre_flag )
      return;
    d_x = object[object_at]._ox - x;
    d_y = object[object_at]._oy - y;
    screen_x = 32 * d_x + a3 - object[object_at]._oAnimWidth2 - 32 * d_y;
    screen_y = a4 + 16 * d_y + 16 * d_x;
    a6 = 0;
    dir = 8;
  }
  else
  {
    object_at = dObject[x][y] - 1;
    if ( object[object_at]._oPreFlag != pre_flag )
      return;
    screen_x = a3 - object[object_at]._oAnimWidth2;
    screen_y = a4;
  }
  if ( object_at == pcursobj )
    CelDecodeClr(
      194,
      screen_x,
      screen_y,
      (BYTE *)object[object_at]._oAnimData,
      object[object_at]._oAnimFrame,
      object[object_at]._oAnimWidth,
      a6,
      dir);
  if ( object[object_at]._oLight )
  {
    CelDecodeHdrLightOnly(
      screen_x,
      screen_y,
      (char *)object[object_at]._oAnimData,
      object[object_at]._oAnimFrame,
      object[object_at]._oAnimWidth,
      a6,
      dir);
  }
  else
  {
    assert(object[object_at]._oAnimData, "SCROLLRT.CPP", 327);
    CelDrawHdrOnly(
      screen_x,
      screen_y,
      (BYTE *)object[object_at]._oAnimData,
      object[object_at]._oAnimFrame,
      object[object_at]._oAnimWidth,
      a6,
      dir);
  }
}

//----- (0048CB96) --------------------------------------------------------
void __fastcall scrollrt_draw_e_flag(BYTE *buffer, int x, int y, int a4, int a5, int sx, int sy)
{
  int old_lpi; // [esp+14h] [ebp-18h]
  SHORT *piece_defs; // [esp+18h] [ebp-14h]
  BYTE *buf; // [esp+1Ch] [ebp-10h]
  int old_lti; // [esp+20h] [ebp-Ch]
  int old_cta; // [esp+24h] [ebp-8h]
  int i; // [esp+28h] [ebp-4h]

  old_lti = light_table_index;
  old_cta = cel_transparency_active;
  old_lpi = level_piece_id;
  level_piece_id = dPiece[x][y];
  light_table_index = dTransVal[x][y];
  buf = buffer;
  cel_transparency_active = (unsigned __int8)(nTransTable[level_piece_id] & TransList[dung_map[x][y]]);
  piece_defs = dpiece_defs_map_1[gendung_get_dpiece_num_from_coord(x, y)];
  arch_draw_type = 1;
  LOWORD(level_cel_block) = *piece_defs;
  if ( (_WORD)level_cel_block )
    drawUpperScreen(buf);
  arch_draw_type = 2;
  LOWORD(level_cel_block) = piece_defs[1];
  if ( (_WORD)level_cel_block )
    drawUpperScreen(buf + 32);
  arch_draw_type = 0;
  for ( i = 1; (gendung_567144 >> 1) - 1 > i; ++i )
  {
    buf -= 24576;
    if ( a4 >= i )
    {
      LOWORD(level_cel_block) = piece_defs[2 * i];
      if ( (_WORD)level_cel_block )
        drawUpperScreen(buf);
      LOWORD(level_cel_block) = piece_defs[2 * i + 1];
      if ( (_WORD)level_cel_block )
        drawUpperScreen(buf + 32);
    }
  }
  scrollrt_draw_dungeon(buffer, x, y, a4, a5, sx, sy, 0);
  light_table_index = old_lti;
  cel_transparency_active = old_cta;
  level_piece_id = old_lpi;
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
  BYTE *dst_buf; // edi
  BYTE *src_buf; // esi
  BYTE *dst_buf_row2; // ebx
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
  signed int width; // [esp+24h] [ebp-14h]
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
  gpBufEnd = &gpBuffer[screen_y_times_768[143]];
  for ( a6 = 0; a6 < 4; ++a6 )
  {
    scrollrt_draw_upper(xa, ya++, sx, sy, a5, a6, 0);
    v2 = sx - 32;
    v3 = sy + 16;
    scrollrt_draw_upper(xa++, ya, v2, v3, a5, a6, 1);
    sx = v2 + 32;
    sy = v3 + 16;
  }
  gpBufEnd = &gpBuffer[screen_y_times_768[320]];
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
    src_off = 245168;
    dst_off = 392064;
    width = 160;
  }
  else if ( invflag || sbookflag )
  {
    src_off = 245168;
    dst_off = 391744;
    width = 160;
  }
  else
  {
    src_off = 245088;
    dst_off = 391744;
    width = 320;
  }
  dst_buf = &gpBuffer[dst_off];
  src_buf = &gpBuffer[src_off];
  dst_buf_row2 = &gpBuffer[dst_off + 768];
  for (i = 176; i; --i)
  {
    for (j = width; j; --j)
    {
      LOBYTE(v13) = *src_buf++;
      HIBYTE(v13) = v13;
      *(_WORD *)dst_buf = v13;
      *(_WORD *)dst_buf_row2 = v13;
      dst_buf += 2;
      dst_buf_row2 += 2;
    }
    src_buf += -width - 768;
    v14 = 2 * (width + 768);
    dst_buf_row2 -= v14;
    dst_buf -= v14;
  }
}

//----- (0048D0B8) --------------------------------------------------------
void __cdecl ClearScreenBuffer()
{
  BYTE *buf; // edi
  signed int i; // edx

  buf = gpBuffer + 122944;
  for (i = 480; i; --i)
  {
    memset(buf, 0, 0x280u);
    buf += 768;
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
  BYTE *buf; // esi MAPDST
  char *v8; // edi
  int v9; // ebx
  int v10; // edx
  char *v12; // edi
  signed int v13; // edx
  char *v14; // esi
  char *v15; // edi
  unsigned int v16; // ebx
  int v17; // edx
  BYTE *v18; // esi
  char *v19; // edi
  unsigned int v20; // ebx
  int v21; // edx
  char *v23; // edi
  signed int v24; // edx
  char *v26; // edi
  signed int v27; // edx
  char *v29; // edi
  signed int v30; // edx
  char *v32; // edi
  signed int v33; // edx
  char *v35; // edi
  signed int v36; // edx
  char *v38; // edi
  signed int v39; // edx
  char *v41; // edi
  signed int v42; // edx
  char *v44; // edi
  signed int v45; // edx
  int h_; // [esp+10h] [ebp-84h]
  signed int j; // [esp+14h] [ebp-80h]
  int v49; // [esp+18h] [ebp-7Ch]
  int error_code; // [esp+1Ch] [ebp-78h]
  int error_codea; // [esp+1Ch] [ebp-78h]
  signed int i; // [esp+20h] [ebp-74h]
  char *surface_; // [esp+24h] [ebp-70h]
  DDSURFACEDESC desc; // [esp+28h] [ebp-6Ch]

  h_ = dwHgt;
  if ( gbActive )
  {
    if ( lpDDSPrimary )
    {
      if ( lpDDSPrimary->lpVtbl->IsLost(lpDDSPrimary) != DDERR_SURFACELOST
        || (error_code = lpDDSPrimary->lpVtbl->Restore(lpDDSPrimary)) == 0 )
      {
        desc.dwSize = 108;
        for ( i = 0; i < 2; ++i )
        {
          error_code = lpDDSPrimary->lpVtbl->Lock(lpDDSPrimary, 0, &desc, 1, 0);
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
          surface_ = (char *)desc.lpSurface;
          if ( desc.lPitch - 640 != scrollrt_4DC21C_soff || scrollrt_4DC21C_soff == -1 )
          {
            scrollrt_4DC21C_soff = desc.lPitch - 640;
            v49 = 0;
            for ( j = 0; j < 480; ++j )
            {
              scrollrt_648738_line_off[j] = v49;
              v49 += desc.lPitch;
            }
            scrollrt_648EDC_off1 = 398 * desc.lPitch + 177;
            scrollrt_648ED4_off2 = 352 * desc.lPitch + 96;
            scrollrt_648EC0_off3 = 352 * desc.lPitch + 461;
            scrollrt_648EB8_off4 = 416 * desc.lPitch + 565;
            scrollrt_648EEC_off5 = 357 * desc.lPitch + 205;
            scrollrt_648EE0_off6 = 357 * desc.lPitch + 11;
            scrollrt_647730_off7 = 357 * desc.lPitch + 558;
            scrollrt_648EC4_off8 = 443 * desc.lPitch + 87;
            scrollrt_648ECC_off9 = 443 * desc.lPitch + 527;
          }
          if ( h_ > 0 )
          {
            buf = gpBuffer + 122944;
            v8 = surface_;
            v9 = scrollrt_4DC21C_soff;
            for (v10 = h_; v10; --v10)
            {
              qmemcpy(v8, buf, 0x280u);
              buf += 768;
              v8 += v9 + 640;
            }
          }
          if ( h_ < 480 )
          {
            if ( draw_btn )
            {
              buf = gpBuffer + 397325;
              v12 = &surface_[scrollrt_648EEC_off5];
              for (v13 = 28; v13; --v13)
              {
                qmemcpy(v12, buf, 0xE8u);
                buf += 768;
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
                v18 = cursor_dword_645724_buf2;
                v19 = &surface_[cursor_dword_645720];
                v20 = cursor_dword_645768_W;
                for (v21 = cursor_dword_64576C_H; v21; --v21)
                {
                  qmemcpy(v19, v18, v20);
                  v18 += 768;
                  v19 += scrollrt_4DC21C_soff + 640;
                }
              }
              dword_645744 = (int)cursor_dword_645724_buf2;
              dword_645740 = cursor_dword_645720;
              dword_645760 = cursor_dword_645768_W;
              dword_645764 = cursor_dword_64576C_H;
            }
            if ( draw_hp )
            {
              buf = gpBuffer + 428785;
              v23 = &surface_[scrollrt_648EDC_off1];
              for (v24 = 60; v24; --v24)
              {
                qmemcpy(v23, buf, 0x120u);
                buf += 768;
                v23 += scrollrt_4DC21C_soff + 640;
              }
            }
            if ( draw_sbar )
            {
              buf = gpBuffer + 393741;
              v26 = &surface_[scrollrt_648EC0_off3];
              for (v27 = 72; v27; --v27)
              {
                qmemcpy(v26, buf, 0x58u);
                buf += 768;
                v26 += scrollrt_4DC21C_soff + 640;
              }
              buf = gpBuffer + 442997;
              v29 = &surface_[scrollrt_648EB8_off4];
              for (v30 = 56; v30; --v30)
              {
                qmemcpy(v29, buf, 0x38u);
                buf += 768;
                v29 += scrollrt_4DC21C_soff + 640;
              }
            }
            if ( draw_mana )
            {
              buf = gpBuffer + 393376;
              v32 = &surface_[scrollrt_648ED4_off2];
              for (v33 = 72; v33; --v33)
              {
                qmemcpy(v32, buf, 0x58u);
                buf += 768;
                v32 += scrollrt_4DC21C_soff + 640;
              }
            }
            if ( drawbtnflag )
            {
              buf = gpBuffer + 397131;
              v35 = &surface_[scrollrt_648EE0_off6];
              for (v36 = 119; v36; --v36)
              {
                qmemcpy(v35, buf, 0x48u);
                buf += 768;
                v35 += scrollrt_4DC21C_soff + 640;
              }
              buf = gpBuffer + 397678;
              v38 = &surface_[scrollrt_647730_off7];
              for (v39 = 42; v39; --v39)
              {
                qmemcpy(v38, buf, 0x48u);
                buf += 768;
                v38 += scrollrt_4DC21C_soff + 640;
              }
              buf = gpBuffer + 463255;
              v41 = &surface_[scrollrt_648EC4_off8];
              for (v42 = 32; v42; --v42)
              {
                qmemcpy(v41, buf, 0x24u);
                buf += 768;
                v41 += scrollrt_4DC21C_soff + 640;
              }
              buf = gpBuffer + 463695;
              v44 = &surface_[scrollrt_648ECC_off9];
              for (v45 = 32; v45; --v45)
              {
                qmemcpy(v44, buf, 0x24u);
                buf += 768;
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
  signed int clearpan; // [esp+10h] [ebp-8h]
  int dwHgt; // [esp+14h] [ebp-4h]

  if ( drawpanflag == 255 )
  {
    drawhpflag = 1;
    drawmanaflag = 1;
    drawbtnflag = 1;
    draw_btn = 1;
    draw_hp = 0;
    clearpan = 1;
    dwHgt = 480;
  }
  else
  {
    if ( drawpanflag != 1 )
      return;
    draw_hp = 1;
    clearpan = 0;
    dwHgt = 352;
  }
  scrollrt_draw_cursor_back_buffer();
  if ( leveltype )
    DrawView(ViewX, ViewY);
  else
    T_DrawView(ViewX, ViewY);
  if ( clearpan )
    ClearCtrlPan();
  if ( drawhpflag )
    UpdateLifeFlask();
  if ( drawmanaflag )
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
  DrawMain(dwHgt, 1, draw_hp, drawhpflag, drawmanaflag, draw_btn, drawbtnflag);
  drawpanflag = 0;
  drawhpflag = 0;
  drawmanaflag = 0;
  drawbtnflag = 0;
  draw_btn = 0;
}

