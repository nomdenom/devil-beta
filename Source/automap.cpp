//----- (004599E0) --------------------------------------------------------
void __cdecl InitAutomapOnce()
{
  automapflag = 0;
  AutoMapScale = 50;
  AutoMapPosBits = 32;
  AutoMapXPos = 16;
  AutoMapYPos = 8;
  AMPlayerX = 4;
  AMPlayerY = 2;
}

//----- (00459A49) --------------------------------------------------------
void __cdecl InitAutomap()
{
  unsigned __int8 v0; // ST1C_1
  unsigned __int8 v1; // ST20_1
  unsigned int pdwFileLen; // [esp+18h] [ebp-20h]
  int k; // [esp+1Ch] [ebp-1Ch]
  int i; // [esp+20h] [ebp-18h]
  unsigned __int8 *v5; // [esp+24h] [ebp-14h]
  int v6; // [esp+28h] [ebp-10h]
  unsigned int j; // [esp+2Ch] [ebp-Ch]
  unsigned __int8 *ptr; // [esp+30h] [ebp-8h]
  int v9; // [esp+34h] [ebp-4h]

  v9 = 50;
  for ( i = 0; i < 31; ++i )
  {
    v6 = (v9 << 6) / 100;
    automap_628B48_xoff[i] = 2 * (320 / v6) + 1;
    if ( 320 % v6 )
      ++automap_628B48_xoff[i];
    if ( 32 * v9 / 100 <= 320 % v6 )
      ++automap_628B48_xoff[i];
    v9 += 5;
  }
  memset(automaptype, 0, 0x400u);
  switch ( leveltype )
  {
    case 1:
      ptr = LoadFileInMem("Levels\\L1Data\\L1.AMP", (int *)&pdwFileLen, 109, "automap.cpp");
      pdwFileLen >>= 1;
      break;
    case 2:
      ptr = LoadFileInMem("Levels\\L2Data\\L2.AMP", (int *)&pdwFileLen, 114, "automap.cpp");
      pdwFileLen >>= 1;
      break;
    case 3:
      ptr = LoadFileInMem("Levels\\L3Data\\L3.AMP", (int *)&pdwFileLen, 119, "automap.cpp");
      pdwFileLen >>= 1;
      break;
    default:
      return;
  }
  v5 = ptr;
  for ( j = 1; j <= pdwFileLen; ++j )
  {
    v0 = *v5++;
    v1 = *v5++;
    automaptype[j] = v0 + (v1 << 8);
  }
  mem_free_dbg(ptr, 135, "automap.cpp");
  memset(automapview, 0, 1600u);
  for ( k = 0; k < 112; ++k )
  {
    for ( i = 0; i < 112; ++i )
      dFlags[i][k] &= 0x7Fu;
  }
}

//----- (00459C85) --------------------------------------------------------
void __cdecl StartAutomap()
{
  AutoMapXOfs = 0;
  AutoMapYOfs = 0;
  automapflag = 1;
}

//----- (00459CB3) --------------------------------------------------------
void __cdecl AutomapUp()
{
  --AutoMapXOfs;
  --AutoMapYOfs;
}

//----- (00459CCF) --------------------------------------------------------
void __cdecl AutomapDown()
{
  ++AutoMapXOfs;
  ++AutoMapYOfs;
}

//----- (00459CEB) --------------------------------------------------------
void __cdecl AutomapLeft()
{
  --AutoMapXOfs;
  ++AutoMapYOfs;
}

//----- (00459D07) --------------------------------------------------------
void __cdecl AutomapRight()
{
  ++AutoMapXOfs;
  --AutoMapYOfs;
}

//----- (00459D23) --------------------------------------------------------
void __cdecl AutomapZoomIn()
{
  if ( AutoMapScale < 200 )
  {
    AutoMapScale += 5;
    AutoMapPosBits = (AutoMapScale << 6) / 100;
    AutoMapXPos = (AutoMapScale << 6) / 100 >> 1;
    AutoMapYPos = (AutoMapScale << 6) / 100 >> 2;
    AMPlayerX = (AutoMapScale << 6) / 100 >> 3;
    AMPlayerY = (AutoMapScale << 6) / 100 >> 4;
  }
}

//----- (00459D8F) --------------------------------------------------------
void __cdecl AutomapZoomOut()
{
  if ( AutoMapScale > 50 )
  {
    AutoMapScale -= 5;
    AutoMapPosBits = (AutoMapScale << 6) / 100;
    AutoMapXPos = (AutoMapScale << 6) / 100 >> 1;
    AutoMapYPos = (AutoMapScale << 6) / 100 >> 2;
    AMPlayerX = (AutoMapScale << 6) / 100 >> 3;
    AMPlayerY = (AutoMapScale << 6) / 100 >> 4;
  }
}

//----- (00459E9F) --------------------------------------------------------
void __fastcall DrawAutomapType(int screen_x, int screen_y, __int16 automap_type)
{
  int x2; // ST34_4
  int y1; // ST28_4
  int x1; // ST30_4
  int y2; // ST24_4
  int v7; // ST34_4
  int v8; // ST30_4
  int v9; // ST28_4
  int v10; // ST24_4
  int v11; // ST34_4
  int v12; // ST28_4
  int v13; // ST30_4
  int v14; // ST24_4
  int v15; // ST34_4
  int v16; // ST30_4
  int v17; // ST28_4
  int v18; // ST24_4
  int v19; // ST34_4
  int v20; // ST28_4
  int v21; // ST30_4
  int v22; // ST24_4
  signed int v25; // [esp+20h] [ebp-14h]
  char v26; // [esp+2Ch] [ebp-8h]
  signed int v27; // [esp+30h] [ebp-4h]

  v26 = HIBYTE(automap_type);
  if ( automap_type & 0x4000 )
  {
    ENG_set_pixel(screen_x, screen_y, 200);
    ENG_set_pixel(screen_x - AMPlayerX, screen_y - AMPlayerY, 200);
    ENG_set_pixel(screen_x - AMPlayerX, screen_y + AMPlayerY, 200);
    ENG_set_pixel(screen_x + AMPlayerX, screen_y - AMPlayerY, 200);
    ENG_set_pixel(screen_x + AMPlayerX, screen_y + AMPlayerY, 200);
    ENG_set_pixel(screen_x - AutoMapYPos, screen_y, 200);
    ENG_set_pixel(screen_x + AutoMapYPos, screen_y, 200);
    ENG_set_pixel(screen_x, screen_y - AMPlayerX, 200);
    ENG_set_pixel(screen_x, screen_y + AMPlayerX, 200);
    ENG_set_pixel(AMPlayerX + screen_x - AutoMapXPos, screen_y + AMPlayerY, 200);
    ENG_set_pixel(screen_x + AutoMapXPos - AMPlayerX, screen_y + AMPlayerY, 200);
    ENG_set_pixel(screen_x - AutoMapYPos, screen_y + AMPlayerX, 200);
    ENG_set_pixel(screen_x + AutoMapYPos, screen_y + AMPlayerX, 200);
    ENG_set_pixel(screen_x - AMPlayerX, screen_y + AutoMapYPos - AMPlayerY, 200);
    ENG_set_pixel(screen_x + AMPlayerX, screen_y + AutoMapYPos - AMPlayerY, 200);
    ENG_set_pixel(screen_x, screen_y + AutoMapYPos, 200);
  }
  if ( automap_type < 0 )
  {
    engine_draw_automap_pixels(
      screen_x - AMPlayerX,
      screen_y - AMPlayerX - AMPlayerY,
      screen_x + AutoMapYPos + AMPlayerX,
      screen_y + AMPlayerY,
      144);
    engine_draw_automap_pixels(
      screen_x - AutoMapYPos,
      screen_y - AMPlayerX,
      screen_x + AutoMapYPos,
      screen_y + AMPlayerX,
      144);
    engine_draw_automap_pixels(
      screen_x - AutoMapYPos - AMPlayerX,
      screen_y - AMPlayerY,
      screen_x + AMPlayerX,
      screen_y + AMPlayerX + AMPlayerY,
      144);
    engine_draw_automap_pixels(screen_x - AutoMapXPos, screen_y, screen_x, screen_y + AutoMapYPos, 144);
  }
  v25 = 0;
  v27 = 0;
  switch ( automap_type & 0xF )
  {
    case 1:
      x2 = screen_x - AutoMapYPos;
      y1 = screen_y - AutoMapYPos;
      x1 = AutoMapXPos + screen_x - AutoMapYPos;
      y2 = screen_y - AMPlayerX;
      engine_draw_automap_pixels(screen_x, screen_y - AutoMapYPos, screen_x - AutoMapYPos, screen_y - AMPlayerX, 200);
      engine_draw_automap_pixels(screen_x, y1, x1, y2, 200);
      engine_draw_automap_pixels(screen_x, screen_y, x2, y2, 200);
      engine_draw_automap_pixels(screen_x, screen_y, x1, y2, 200);
      break;
    case 2:
    case 5:
      v25 = 1;
      break;
    case 3:
    case 6:
      v27 = 1;
      break;
    case 4:
      v25 = 1;
      v27 = 1;
      break;
    default:
      break;
  }
  if ( v25 )
  {
    if ( automap_type & 0x100 )
    {
      v7 = screen_x - AutoMapXPos;
      v8 = screen_x - AutoMapYPos;
      v9 = screen_y - AutoMapYPos;
      v10 = screen_y - AMPlayerX;
      engine_draw_automap_pixels(
        screen_x,
        screen_y - AutoMapYPos,
        screen_x - AMPlayerX,
        AMPlayerY + screen_y - AutoMapYPos,
        200);
      engine_draw_automap_pixels(v7, screen_y, AMPlayerX + v7, screen_y - AMPlayerY, 200);
      engine_draw_automap_pixels(v8, v9, v7, v10, 144);
      engine_draw_automap_pixels(v8, v9, screen_x, v10, 144);
      engine_draw_automap_pixels(v8, screen_y, v7, v10, 144);
      engine_draw_automap_pixels(v8, screen_y, screen_x, v10, 144);
    }
    if ( automap_type & 0x1000 )
    {
      engine_draw_automap_pixels(screen_x - AutoMapYPos, screen_y - AMPlayerX, screen_x - AutoMapXPos, screen_y, 200);
      v26 = HIBYTE(automap_type) | 4;
    }
    if ( v26 & 4 )
    {
      v11 = screen_x - AutoMapYPos;
      v12 = screen_y - AutoMapYPos;
      v13 = AutoMapXPos + screen_x - AutoMapYPos;
      v14 = screen_y - AMPlayerX;
      engine_draw_automap_pixels(screen_x, screen_y - AutoMapYPos, screen_x - AutoMapYPos, screen_y - AMPlayerX, 200);
      engine_draw_automap_pixels(screen_x, v12, v13, v14, 200);
      engine_draw_automap_pixels(screen_x, screen_y, v11, v14, 200);
      engine_draw_automap_pixels(screen_x, screen_y, v13, v14, 200);
    }
    if ( !(v26 & 0x15) )
      engine_draw_automap_pixels(screen_x, screen_y - AutoMapYPos, screen_x - AutoMapXPos, screen_y, 200);
  }
  if ( v27 )
  {
    if ( v26 & 2 )
    {
      v15 = screen_x + AutoMapYPos;
      v16 = screen_x + AutoMapXPos;
      v17 = screen_y - AutoMapYPos;
      v18 = screen_y - AMPlayerX;
      engine_draw_automap_pixels(
        screen_x,
        screen_y - AutoMapYPos,
        screen_x + AMPlayerX,
        AMPlayerY + screen_y - AutoMapYPos,
        200);
      engine_draw_automap_pixels(v16, screen_y, v16 - AMPlayerX, screen_y - AMPlayerY, 200);
      engine_draw_automap_pixels(v15, v17, screen_x, v18, 144);
      engine_draw_automap_pixels(v15, v17, v16, v18, 144);
      engine_draw_automap_pixels(v15, screen_y, screen_x, v18, 144);
      engine_draw_automap_pixels(v15, screen_y, v16, v18, 144);
    }
    if ( v26 & 0x20 )
    {
      engine_draw_automap_pixels(screen_x + AutoMapYPos, screen_y - AMPlayerX, screen_x + AutoMapXPos, screen_y, 200);
      v26 |= 8u;
    }
    if ( v26 & 8 )
    {
      v19 = screen_x - AutoMapYPos;
      v20 = screen_y - AutoMapYPos;
      v21 = AutoMapXPos + screen_x - AutoMapYPos;
      v22 = screen_y - AMPlayerX;
      engine_draw_automap_pixels(screen_x, screen_y - AutoMapYPos, screen_x - AutoMapYPos, screen_y - AMPlayerX, 200);
      engine_draw_automap_pixels(screen_x, v20, v21, v22, 200);
      engine_draw_automap_pixels(screen_x, screen_y, v19, v22, 200);
      engine_draw_automap_pixels(screen_x, screen_y, v21, v22, 200);
    }
    if ( !(v26 & 0x2A) )
      engine_draw_automap_pixels(screen_x, screen_y - AutoMapYPos, screen_x + AutoMapXPos, screen_y, 200);
  }
}

//----- (0045A677) --------------------------------------------------------
void __cdecl DrawAutomapPlr()
{
  int v0; // [esp+10h] [ebp-18h]
  int y1; // [esp+1Ch] [ebp-Ch]
  int x1; // [esp+20h] [ebp-8h]
  int v3; // [esp+24h] [ebp-4h]

  if ( plr[myplr]._pmode == 3 )
  {
    v0 = plr[myplr]._px;
    v3 = plr[myplr]._py;
    if ( plr[myplr]._pdir == 2 )
      ++v0;
    else
      ++v3;
  }
  else
  {
    v0 = plr[myplr].WorldX;
    v3 = plr[myplr].WorldY;
  }
  x1 = (Scrollinfo._sxoff * AutoMapScale / 100 >> 1)
     + (AutoMapScale * plr[myplr]._pxoff / 100 >> 1)
     + AutoMapYPos * (v0 - ViewX - 2 * AutoMapXOfs)
     + 384
     - AutoMapYPos * (v3 - ViewY - 2 * AutoMapYOfs);
  if ( invflag || sbookflag )
    x1 -= 160;
  if ( chrflag || questlog )
    x1 += 160;
  y1 = (AutoMapScale * Scrollinfo._syoff / 100 >> 1)
     + (AutoMapScale * plr[myplr]._pyoff / 100 >> 1)
     + (v3 - ViewY - 2 * AutoMapYOfs) * AMPlayerX
     + (v0 - ViewX - 2 * AutoMapXOfs) * AMPlayerX
     + 336
     - AMPlayerX;
  switch ( plr[myplr]._pdir )
  {
    case 0:
      engine_draw_automap_pixels(x1, y1, x1, AutoMapYPos + y1, 153);
      engine_draw_automap_pixels(x1, AutoMapYPos + y1, x1 + AMPlayerY, AMPlayerX + y1, 153);
      engine_draw_automap_pixels(x1, AutoMapYPos + y1, x1 - AMPlayerY, AMPlayerX + y1, 153);
      break;
    case 1:
      engine_draw_automap_pixels(
        x1,
        (AutoMapScale * Scrollinfo._syoff / 100 >> 1)
      + (AutoMapScale * plr[myplr]._pyoff / 100 >> 1)
      + (v3 - ViewY - 2 * AutoMapYOfs) * AMPlayerX
      + (v0 - ViewX - 2 * AutoMapXOfs) * AMPlayerX
      + 336
      - AMPlayerX,
        x1 - AutoMapYPos,
        (AutoMapScale * Scrollinfo._syoff / 100 >> 1)
      + (AutoMapScale * plr[myplr]._pyoff / 100 >> 1)
      + (v3 - ViewY - 2 * AutoMapYOfs) * AMPlayerX
      + (v0 - ViewX - 2 * AutoMapXOfs) * AMPlayerX
      + 336,
        153);
      engine_draw_automap_pixels(x1 - AutoMapYPos, AMPlayerX + y1, x1 - AMPlayerX - AMPlayerY, y1, 153);
      engine_draw_automap_pixels(x1 - AutoMapYPos, AMPlayerX + y1, x1 - AMPlayerX, AMPlayerX + y1, 153);
      break;
    case 2:
      engine_draw_automap_pixels(x1, y1, x1 - AutoMapYPos, y1, 153);
      engine_draw_automap_pixels(x1 - AutoMapYPos, y1, x1 - AMPlayerX, y1 - AMPlayerY, 153);
      engine_draw_automap_pixels(x1 - AutoMapYPos, y1, x1 - AMPlayerX, AMPlayerY + y1, 153);
      break;
    case 3:
      engine_draw_automap_pixels(x1, y1, x1 - AutoMapYPos, y1 - AMPlayerX, 153);
      engine_draw_automap_pixels(x1 - AutoMapYPos, y1 - AMPlayerX, x1 - AMPlayerX, y1 - AMPlayerX, 153);
      engine_draw_automap_pixels(x1 - AutoMapYPos, y1 - AMPlayerX, x1 - AMPlayerX - AMPlayerY, y1, 153);
      break;
    case 4:
      engine_draw_automap_pixels(x1, y1, x1, y1 - AutoMapYPos, 153);
      engine_draw_automap_pixels(x1, y1 - AutoMapYPos, x1 - AMPlayerY, y1 - AMPlayerX, 153);
      engine_draw_automap_pixels(x1, y1 - AutoMapYPos, x1 + AMPlayerY, y1 - AMPlayerX, 153);
      break;
    case 5:
      engine_draw_automap_pixels(x1, y1, AutoMapYPos + x1, y1 - AMPlayerX, 153);
      engine_draw_automap_pixels(AutoMapYPos + x1, y1 - AMPlayerX, AMPlayerX + x1, y1 - AMPlayerX, 153);
      engine_draw_automap_pixels(AutoMapYPos + x1, y1 - AMPlayerX, AMPlayerX + x1 + AMPlayerY, y1, 153);
      break;
    case 6:
      engine_draw_automap_pixels(x1, y1, AutoMapYPos + x1, y1, 153);
      engine_draw_automap_pixels(AutoMapYPos + x1, y1, AMPlayerX + x1, y1 - AMPlayerY, 153);
      engine_draw_automap_pixels(AutoMapYPos + x1, y1, AMPlayerX + x1, AMPlayerY + y1, 153);
      break;
    case 7:
      engine_draw_automap_pixels(
        x1,
        (AutoMapScale * Scrollinfo._syoff / 100 >> 1)
      + (AutoMapScale * plr[myplr]._pyoff / 100 >> 1)
      + (v3 - ViewY - 2 * AutoMapYOfs) * AMPlayerX
      + (v0 - ViewX - 2 * AutoMapXOfs) * AMPlayerX
      + 336
      - AMPlayerX,
        AutoMapYPos + x1,
        (AutoMapScale * Scrollinfo._syoff / 100 >> 1)
      + (AutoMapScale * plr[myplr]._pyoff / 100 >> 1)
      + (v3 - ViewY - 2 * AutoMapYOfs) * AMPlayerX
      + (v0 - ViewX - 2 * AutoMapXOfs) * AMPlayerX
      + 336,
        153);
      engine_draw_automap_pixels(AutoMapYPos + x1, AMPlayerX + y1, AMPlayerX + x1 + AMPlayerY, y1, 153);
      engine_draw_automap_pixels(AutoMapYPos + x1, AMPlayerX + y1, AMPlayerX + x1, AMPlayerX + y1, 153);
      break;
    default:
      return;
  }
}

//----- (0045AD38) --------------------------------------------------------
__int16 __fastcall GetAutomapType(int tx, int ty, bool view)
{
  __int16 result; // ax
  __int16 v6; // [esp+14h] [ebp-8h]

  if ( view && tx == -1 && ty >= 0 && ty < 40 && automapview[0][ty] )
  {
    if ( ((unsigned __int16)GetAutomapType(0, ty, 0) >> 8) & 0x40 )
      result = 0;
    else
      result = 0x4000;
  }
  else if ( view && ty == -1 && tx >= 0 && tx < 40 && automapview[tx][0] )
  {
    if ( ((unsigned __int16)GetAutomapType(tx, 0, 0) >> 8) & 0x40 )
      result = 0;
    else
      result = 0x4000;
  }
  else if ( tx >= 0 && tx < 40 )
  {
    if ( ty >= 0 && ty < 40 )
    {
      if ( automapview[tx][ty] || !view )
      {
        v6 = automaptype[dungeon[tx][ty]];
        if ( v6 == 7
          && ((unsigned __int16)GetAutomapType(tx - 1, ty, 0) >> 8) & 8
          && ((unsigned __int16)GetAutomapType(tx, ty - 1, 0) >> 8) & 4 )
        {
          v6 = 1;
        }
        result = v6;
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0045AF08) --------------------------------------------------------
void __cdecl DrawAutomap()
{
  int v0; // [esp+Ch] [ebp-28h]
  int v1; // [esp+Ch] [ebp-28h]
  int v2; // [esp+10h] [ebp-24h]
  int i; // [esp+14h] [ebp-20h]
  int v4; // [esp+18h] [ebp-1Ch]
  int v5; // [esp+18h] [ebp-1Ch]
  int j; // [esp+1Ch] [ebp-18h]
  int k; // [esp+1Ch] [ebp-18h]
  int screen_y; // [esp+20h] [ebp-14h]
  int screen_x; // [esp+24h] [ebp-10h]
  int screen_xa; // [esp+24h] [ebp-10h]
  int v11; // [esp+28h] [ebp-Ch]
  __int16 automap_type; // [esp+2Ch] [ebp-8h]
  __int16 automap_typea; // [esp+2Ch] [ebp-8h]
  int v14; // [esp+30h] [ebp-4h]

  if ( leveltype == 1 || leveltype == 2 || leveltype == 3 )
  {
    screen_buf_end = (int)(gpBuffer + 393216);
    automap_628B38_x = (ViewX - 16) >> 1;
    while ( automap_628B38_x + AutoMapXOfs < 0 )
      ++AutoMapXOfs;
    while ( automap_628B38_x + AutoMapXOfs >= 40 )
      --AutoMapXOfs;
    automap_628B38_x += AutoMapXOfs;
    automap_628B3C_y = (ViewY - 16) >> 1;
    while ( automap_628B3C_y + AutoMapYOfs < 0 )
      ++AutoMapYOfs;
    while ( automap_628B3C_y + AutoMapYOfs >= 40 )
      --AutoMapYOfs;
    automap_628B3C_y += AutoMapYOfs;
    v2 = automap_628B48_xoff[(AutoMapScale - 50) / 5];
    if ( Scrollinfo._sxoff + Scrollinfo._syoff )
      ++v2;
    v14 = automap_628B38_x - v2;
    v11 = automap_628B3C_y - 1;
    if ( v2 & 1 )
    {
      v4 = 384 - AutoMapPosBits * ((v2 - 1) >> 1);
      v0 = 336 - AutoMapXPos * ((v2 + 1) >> 1);
    }
    else
    {
      v4 = AutoMapXPos + 384 - AutoMapPosBits * (v2 >> 1);
      v0 = 336 - AutoMapXPos * (v2 >> 1) - AutoMapYPos;
    }
    if ( ViewX & 1 )
    {
      v4 -= AutoMapYPos;
      v0 -= AMPlayerX;
    }
    if ( ViewY & 1 )
    {
      v4 += AutoMapYPos;
      v0 -= AMPlayerX;
    }
    v5 = (Scrollinfo._sxoff * AutoMapScale / 100 >> 1) + v4;
    v1 = (AutoMapScale * Scrollinfo._syoff / 100 >> 1) + v0;
    if ( invflag || sbookflag )
      v5 -= 160;
    if ( chrflag || questlog )
      v5 += 160;
    for ( i = 0; v2 + 1 >= i; ++i )
    {
      screen_x = v5;
      for ( j = 0; v2 > j; ++j )
      {
        automap_type = GetAutomapType(j + v14, v11 - j, 1);
        if ( automap_type )
          DrawAutomapType(screen_x, v1, automap_type);
        screen_x += AutoMapPosBits;
      }
      ++v11;
      screen_xa = v5 - AutoMapXPos;
      screen_y = v1 + AutoMapYPos;
      for ( k = 0; v2 >= k; ++k )
      {
        automap_typea = GetAutomapType(k + v14, v11 - k, 1);
        if ( automap_typea )
          DrawAutomapType(screen_xa, screen_y, automap_typea);
        screen_xa += AutoMapPosBits;
      }
      ++v14;
      v1 += AutoMapXPos;
    }
    DrawAutomapPlr();
  }
}

//----- (0045B28E) --------------------------------------------------------
void __fastcall SetAutomapView(int x, int y)
{
  __int16 v2; // ax
  signed int tx; // [esp+18h] [ebp-10h]
  signed int ty; // [esp+1Ch] [ebp-Ch]

  tx = (x - 16) >> 1;
  ty = (y - 16) >> 1;
  if ( tx >= 0 && tx < 40 && ty >= 0 && ty < 40 )
  {
    automapview[tx][ty] = 1;
    v2 = GetAutomapType(tx, ty, 0);
    switch ( v2 & 0xF )
    {
      case 2:
        if ( v2 & 0x4000 )
        {
          if ( GetAutomapType(tx, ty + 1, 0) == 16391 )
            automapview[tx][ty + 1] = 1;
        }
        else if ( ((unsigned __int16)GetAutomapType(tx - 1, ty, 0) >> 8) & 0x40 )
        {
          automapview[0][8 * (5 * tx - 5) + ty] = 1;
        }
        break;
      case 3:
        if ( v2 & 0x4000 )
        {
          if ( GetAutomapType(tx + 1, ty, 0) == 16391 )
            automapview[0][8 * (5 * tx + 5) + ty] = 1;
        }
        else if ( ((unsigned __int16)GetAutomapType(tx, ty - 1, 0) >> 8) & 0x40 )
        {
          automapview[tx - 1][ty + 39] = 1;
        }
        break;
      case 4:
        if ( v2 & 0x4000 )
        {
          if ( GetAutomapType(tx, ty + 1, 0) == 16391 )
            automapview[tx][ty + 1] = 1;
          if ( GetAutomapType(tx + 1, ty, 0) == 16391 )
            automapview[0][8 * (5 * tx + 5) + ty] = 1;
        }
        else
        {
          if ( ((unsigned __int16)GetAutomapType(tx - 1, ty, 0) >> 8) & 0x40 )
            automapview[0][8 * (5 * tx - 5) + ty] = 1;
          if ( ((unsigned __int16)GetAutomapType(tx, ty - 1, 0) >> 8) & 0x40 )
            automapview[tx - 1][ty + 39] = 1;
          if ( ((unsigned __int16)GetAutomapType(tx - 1, ty - 1, 0) >> 8) & 0x40 )
            automapview[-1][8 * (5 * tx - 5) + 39 + ty] = 1;
        }
        break;
      case 5:
        if ( v2 & 0x4000 )
        {
          if ( ((unsigned __int16)GetAutomapType(tx, ty - 1, 0) >> 8) & 0x40 )
            automapview[tx - 1][ty + 39] = 1;
          if ( GetAutomapType(tx, ty + 1, 0) == 16391 )
            automapview[tx][ty + 1] = 1;
        }
        else if ( ((unsigned __int16)GetAutomapType(tx - 1, ty, 0) >> 8) & 0x40 )
        {
          automapview[0][8 * (5 * tx - 5) + ty] = 1;
        }
        break;
      case 6:
        if ( v2 & 0x4000 )
        {
          if ( ((unsigned __int16)GetAutomapType(tx - 1, ty, 0) >> 8) & 0x40 )
            automapview[0][8 * (5 * tx - 5) + ty] = 1;
          if ( GetAutomapType(tx + 1, ty, 0) == 16391 )
            automapview[0][8 * (5 * tx + 5) + ty] = 1;
        }
        else if ( ((unsigned __int16)GetAutomapType(tx, ty - 1, 0) >> 8) & 0x40 )
        {
          automapview[tx - 1][ty + 39] = 1;
        }
        break;
      default:
        return;
    }
  }
}

