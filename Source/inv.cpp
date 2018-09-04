//----- (0044EF20) --------------------------------------------------------
void __cdecl FreeInvGFX()
{
  mem_free_dbg(pInvCels, 87, "C:\\Diablo\\Direct\\inv.cpp");
  pInvCels = 0;
}

//----- (0044EF4F) --------------------------------------------------------
void __cdecl InitInv()
{
  if ( pInvCels )
    assertion_failed(95, "C:\\Diablo\\Direct\\inv.cpp");
  if ( plr[myplr]._pClass )
  {
    if ( plr[myplr]._pClass == 1 )
    {
      pInvCels = LoadFileInMem("Data\\Inv\\Inv_rog.CEL", 0, 97, "C:\\Diablo\\Direct\\inv.cpp");
    }
    else if ( plr[myplr]._pClass == 2 )
    {
      pInvCels = LoadFileInMem("Data\\Inv\\Inv_Sor.CEL", 0, 98, "C:\\Diablo\\Direct\\inv.cpp");
    }
  }
  else
  {
    pInvCels = LoadFileInMem("Data\\Inv\\Inv.CEL", 0, 96, "C:\\Diablo\\Direct\\inv.cpp");
  }
  invflag = 0;
  draw_btn = 0;
}

//----- (0044F060) --------------------------------------------------------
void __fastcall InvDrawSlotBack(int X, int Y, int W, int H)
{
  char *v4; // edi
  int v5; // edx
  int v6; // ecx
  char v7; // al
  char v8; // al

  v4 = &gpBuffer[X + screen_y_times_768[Y]];
  v5 = (unsigned __int16)H;
  do
  {
    v6 = (unsigned __int16)W;
    do
    {
      v7 = *v4;
      if ( (unsigned __int8)*v4 < 0xB0u )
        goto LABEL_9;
      if ( (unsigned __int8)v7 > 0xBFu )
      {
        if ( (unsigned __int8)v7 < 0xF0u )
          goto LABEL_9;
        v8 = v7 - 80;
      }
      else
      {
        v8 = v7 - 16;
      }
      *v4 = v8;
LABEL_9:
      ++v4;
      --v6;
    }
    while ( v6 );
    v4 = &v4[-(unsigned __int16)W - 768];
    --v5;
  }
  while ( v5 );
}

//----- (0044F0D9) --------------------------------------------------------
void __cdecl DrawInv()
{
  int screen_x; // [esp+Ch] [ebp-C0h]
  int screen_xa; // [esp+Ch] [ebp-C0h]
  signed int i; // [esp+10h] [ebp-BCh]
  signed int j; // [esp+10h] [ebp-BCh]
  int v4[40]; // [esp+18h] [ebp-B4h]
  int frame_width; // [esp+B8h] [ebp-14h]
  int frame; // [esp+BCh] [ebp-10h]
  int colour; // [esp+C0h] [ebp-Ch]
  int screen_y; // [esp+C4h] [ebp-8h]
  int v9; // [esp+C8h] [ebp-4h]

  CelDecodeOnly(384, 511, pInvCels, 1, 320);
  if ( plr[myplr].InvBody[0]._itype != -1 )
  {
    InvDrawSlotBack(516, 219, 56, 56);
    frame = plr[myplr].InvBody[0]._iCurs + 12;
    frame_width = InvItemWidth[frame];
    if ( !pcursinvitem )
    {
      colour = 197;
      if ( plr[myplr].InvBody[0]._iMagical )
        colour = 181;
      if ( !plr[myplr].InvBody[0]._iStatFlag )
        colour = 229;
      CelDecodeClr(colour, 516, 219, pCursCels, frame, frame_width, 0, 8);
    }
    if ( plr[myplr].InvBody[0]._iStatFlag )
    {
      if ( !pCursCels )
        assertion_failed(166, "C:\\Diablo\\Direct\\inv.cpp");
      CelDrawHdrOnly(516, 219, pCursCels, frame, frame_width, 0, 8);
    }
    else
    {
      CelDrawHdrLightRed(516, 219, pCursCels, frame, frame_width, 0, 8, 1);
    }
  }
  if ( plr[myplr].InvBody[1]._itype != -1 )
  {
    InvDrawSlotBack(429, 365, 28, 28);
    frame = plr[myplr].InvBody[1]._iCurs + 12;
    frame_width = InvItemWidth[frame];
    if ( pcursinvitem == 1 )
    {
      colour = 197;
      if ( plr[myplr].InvBody[1]._iMagical )
        colour = 181;
      if ( !plr[myplr].InvBody[1]._iStatFlag )
        colour = 229;
      CelDecodeClr(colour, 429, 365, pCursCels, frame, frame_width, 0, 8);
    }
    if ( plr[myplr].InvBody[1]._iStatFlag )
    {
      if ( !pCursCels )
        assertion_failed(184, "C:\\Diablo\\Direct\\inv.cpp");
      CelDrawHdrOnly(429, 365, pCursCels, frame, frame_width, 0, 8);
    }
    else
    {
      CelDrawHdrLightRed(429, 365, pCursCels, frame, frame_width, 0, 8, 1);
    }
  }
  if ( plr[myplr].InvBody[2]._itype != -1 )
  {
    InvDrawSlotBack(631, 365, 28, 28);
    frame = plr[myplr].InvBody[2]._iCurs + 12;
    frame_width = InvItemWidth[frame];
    if ( pcursinvitem == 2 )
    {
      colour = 197;
      if ( plr[myplr].InvBody[2]._iMagical )
        colour = 181;
      if ( !plr[myplr].InvBody[2]._iStatFlag )
        colour = 229;
      CelDecodeClr(colour, 631, 365, pCursCels, frame, frame_width, 0, 8);
    }
    if ( plr[myplr].InvBody[2]._iStatFlag )
    {
      if ( !pCursCels )
        assertion_failed(202, "C:\\Diablo\\Direct\\inv.cpp");
      CelDrawHdrOnly(631, 365, pCursCels, frame, frame_width, 0, 8);
    }
    else
    {
      CelDrawHdrLightRed(631, 365, pCursCels, frame, frame_width, 0, 8, 1);
    }
  }
  if ( plr[myplr].InvBody[3]._itype != -1 )
  {
    InvDrawSlotBack(588, 220, 28, 28);
    frame = plr[myplr].InvBody[3]._iCurs + 12;
    frame_width = InvItemWidth[frame];
    if ( pcursinvitem == 3 )
    {
      colour = 197;
      if ( plr[myplr].InvBody[3]._iMagical )
        colour = 181;
      if ( !plr[myplr].InvBody[3]._iStatFlag )
        colour = 229;
      CelDecodeClr(colour, 588, 220, pCursCels, frame, frame_width, 0, 8);
    }
    if ( plr[myplr].InvBody[3]._iStatFlag )
    {
      if ( !pCursCels )
        assertion_failed(220, "C:\\Diablo\\Direct\\inv.cpp");
      CelDrawHdrOnly(588, 220, pCursCels, frame, frame_width, 0, 8);
    }
    else
    {
      CelDrawHdrLightRed(588, 220, pCursCels, frame, frame_width, 0, 8, 1);
    }
  }
  if ( plr[myplr].InvBody[4]._itype != -1 )
  {
    InvDrawSlotBack(401, 320, 56, 84);
    frame = plr[myplr].InvBody[4]._iCurs + 12;
    frame_width = InvItemWidth[frame];
    if ( frame_width == 28 )
      screen_x = 415;
    else
      screen_x = 401;
    if ( InvItemHeight[frame] == 84 )
      screen_y = 320;
    else
      screen_y = 306;
    if ( pcursinvitem == 4 )
    {
      colour = 197;
      if ( plr[myplr].InvBody[4]._iMagical )
        colour = 181;
      if ( !plr[myplr].InvBody[4]._iStatFlag )
        colour = 229;
      CelDecodeClr(colour, screen_x, screen_y, pCursCels, frame, frame_width, 0, 8);
    }
    if ( plr[myplr].InvBody[4]._iStatFlag )
    {
      if ( !pCursCels )
        assertion_failed(242, "C:\\Diablo\\Direct\\inv.cpp");
      CelDrawHdrOnly(screen_x, screen_y, pCursCels, frame, frame_width, 0, 8);
    }
    else
    {
      CelDrawHdrLightRed(screen_x, screen_y, pCursCels, frame, frame_width, 0, 8, 1);
    }
    if ( plr[myplr].InvBody[4]._iLoc == 2 )
    {
      InvDrawSlotBack(631, 320, 56, 84);
      light_table_index = 0;
      cel_transparency_active = 1;
      if ( frame_width == 28 )
        CelDecodeHdrLightTrans(gpBuffer + 246405, pCursCels, frame, 28, 0, 8);
      else
        CelDecodeHdrLightTrans(gpBuffer + 246391, pCursCels, frame, frame_width, 0, 8);
      cel_transparency_active = 0;
    }
  }
  if ( plr[myplr].InvBody[5]._itype != -1 )
  {
    InvDrawSlotBack(631, 320, 56, 84);
    frame = plr[myplr].InvBody[5]._iCurs + 12;
    frame_width = InvItemWidth[frame];
    if ( frame_width == 28 )
      screen_xa = 645;
    else
      screen_xa = 631;
    if ( InvItemHeight[frame] == 84 )
      screen_y = 320;
    else
      screen_y = 306;
    if ( pcursinvitem == 5 )
    {
      colour = 197;
      if ( plr[myplr].InvBody[5]._iMagical )
        colour = 181;
      if ( !plr[myplr].InvBody[5]._iStatFlag )
        colour = 229;
      CelDecodeClr(colour, screen_xa, screen_y, pCursCels, frame, frame_width, 0, 8);
    }
    if ( plr[myplr].InvBody[5]._iStatFlag )
    {
      if ( !pCursCels )
        assertion_failed(273, "C:\\Diablo\\Direct\\inv.cpp");
      CelDrawHdrOnly(screen_xa, screen_y, pCursCels, frame, frame_width, 0, 8);
    }
    else
    {
      CelDrawHdrLightRed(screen_xa, screen_y, pCursCels, frame, frame_width, 0, 8, 1);
    }
  }
  if ( plr[myplr].InvBody[6]._itype != -1 )
  {
    InvDrawSlotBack(516, 320, 56, 84);
    frame = plr[myplr].InvBody[6]._iCurs + 12;
    frame_width = InvItemWidth[frame];
    if ( pcursinvitem == 6 )
    {
      colour = 197;
      if ( plr[myplr].InvBody[6]._iMagical )
        colour = 181;
      if ( !plr[myplr].InvBody[6]._iStatFlag )
        colour = 229;
      CelDecodeClr(colour, 516, 320, pCursCels, frame, frame_width, 0, 8);
    }
    if ( plr[myplr].InvBody[6]._iStatFlag )
    {
      if ( !pCursCels )
        assertion_failed(291, "C:\\Diablo\\Direct\\inv.cpp");
      CelDrawHdrOnly(516, 320, pCursCels, frame, frame_width, 0, 8);
    }
    else
    {
      CelDrawHdrLightRed(516, 320, pCursCels, frame, frame_width, 0, 8, 1);
    }
  }
  for ( i = 0; i < 40; ++i )
  {
    v4[i] = 0;
    if ( plr[myplr].InvGrid[i] )
      InvDrawSlotBack(InvRect[i + 25].X + 64, InvRect[i + 25].Y + 159, 28, 28);
  }
  for ( j = 0; j < 40; ++j )
  {
    if ( plr[myplr].InvGrid[j] > 0 )
    {
      if ( v4[j] )
        assertion_failed(307, "C:\\Diablo\\Direct\\inv.cpp");
      v4[j] = 1;
      if ( plr[myplr].InvGrid[j] > plr[myplr]._pNumInv )
        assertion_failed(309, "C:\\Diablo\\Direct\\inv.cpp");
      v9 = plr[myplr].InvGrid[j] - 1;
      frame = plr[myplr].InvList[v9]._iCurs + 12;
      frame_width = InvItemWidth[frame];
      if ( pcursinvitem == v9 + 7 )
      {
        colour = 197;
        if ( plr[myplr].InvList[v9]._iMagical )
          colour = 181;
        if ( !plr[myplr].InvList[v9]._iStatFlag )
          colour = 229;
        CelDecodeClr(colour, InvRect[j + 25].X + 64, InvRect[j + 25].Y + 159, pCursCels, frame, frame_width, 0, 8);
      }
      if ( plr[myplr].InvList[v9]._iStatFlag )
      {
        if ( !pCursCels )
          assertion_failed(320, "C:\\Diablo\\Direct\\inv.cpp");
        CelDrawHdrOnly(InvRect[j + 25].X + 64, InvRect[j + 25].Y + 159, pCursCels, frame, frame_width, 0, 8);
      }
      else
      {
        CelDrawHdrLightRed(InvRect[j + 25].X + 64, InvRect[j + 25].Y + 159, pCursCels, frame, frame_width, 0, 8, 1);
      }
    }
  }
}

//----- (004500CF) --------------------------------------------------------
void __cdecl DrawInvBelt()
{
  signed int i; // [esp+14h] [ebp-14h]
  int frame_width; // [esp+18h] [ebp-10h]
  int frame; // [esp+1Ch] [ebp-Ch]
  char colour; // [esp+20h] [ebp-8h]

  if ( !talkflag )
  {
    DrawPanelBox(205, 21, 0xE8u, 0x1Cu, 269, 517);
    for ( i = 0; i < 8; ++i )
    {
      if ( plr[myplr].SpdList[i]._itype != -1 )
      {
        InvDrawSlotBack(InvRect[i + 65].X + 64, InvRect[i + 65].Y + 159, 28, 28);
        frame = plr[myplr].SpdList[i]._iCurs + 12;
        frame_width = InvItemWidth[frame];
        if ( pcursinvitem == i + 47 )
        {
          colour = -59;
          if ( plr[myplr].SpdList[i]._iMagical )
            colour = -75;
          if ( !plr[myplr].SpdList[i]._iStatFlag )
            colour = -27;
          CelDecodeClr(colour, InvRect[i + 65].X + 64, InvRect[i + 65].Y + 159, pCursCels, frame, frame_width, 0, 8);
        }
        if ( plr[myplr].SpdList[i]._iStatFlag )
        {
          if ( !pCursCels )
            assertion_failed(353, "C:\\Diablo\\Direct\\inv.cpp");
          CelDrawHdrOnly(InvRect[i + 65].X + 64, InvRect[i + 65].Y + 159, pCursCels, frame, frame_width, 0, 8);
        }
        else
        {
          CelDrawHdrLightRed(InvRect[i + 65].X + 64, InvRect[i + 65].Y + 159, pCursCels, frame, frame_width, 0, 8, 1);
        }
        if ( AllItemsList[plr[myplr].SpdList[i].IDidx].iUsable
          && plr[myplr].SpdList[i]._iStatFlag
          && plr[myplr].SpdList[i]._itype != 11 )
        {
          CPrintString(
            InvRect[i + 65].X + screen_y_times_768[InvRect[i + 65].Y + 159] + 92 - fontkern[byte_4C0471[i]],
            byte_4C0471[i],
            0);
        }
      }
    }
  }
}

//----- (0045046C) --------------------------------------------------------
int __fastcall AutoPlace(int pnum, int ii, int sx, int sy, int saveflag)
{
  int v6; // [esp+14h] [ebp-14h]
  int v7; // [esp+14h] [ebp-14h]
  int i; // [esp+18h] [ebp-10h]
  int k; // [esp+18h] [ebp-10h]
  int j; // [esp+1Ch] [ebp-Ch]
  int l; // [esp+1Ch] [ebp-Ch]
  int v12; // [esp+20h] [ebp-8h]
  int v13; // [esp+24h] [ebp-4h]
  int v14; // [esp+24h] [ebp-4h]

  v12 = 1;
  v13 = 10 * (ii / 10);
  if ( v13 < 0 )
    v13 = 0;
  for ( i = 0; i < sy && v12; ++i )
  {
    if ( v13 >= 40 )
      v12 = 0;
    v6 = ii % 10;
    if ( ii % 10 < 0 )
      v6 = 0;
    for ( j = 0; j < sx && v12; ++j )
    {
      if ( v6 < 10 )
        v12 = plr[pnum].InvGrid[v6 + v13] == 0;
      else
        v12 = 0;
      ++v6;
    }
    v13 += 10;
  }
  if ( v12 && saveflag )
  {
    qmemcpy(
      &plr[pnum].InvList[plr[pnum]._pNumInv++],
      &plr[pnum].HoldItem,
      sizeof(plr[pnum].InvList[plr[pnum]._pNumInv++]));
    v14 = 10 * (ii / 10);
    if ( v14 < 0 )
      v14 = 0;
    for ( k = 0; k < sy; ++k )
    {
      v7 = ii % 10;
      if ( ii % 10 < 0 )
        v7 = 0;
      for ( l = 0; l < sx; ++l )
      {
        if ( l || sy - 1 != k )
          plr[pnum].InvGrid[v7 + v14] = -LOBYTE(plr[pnum]._pNumInv);
        else
          plr[pnum].InvGrid[v7 + v14] = plr[pnum]._pNumInv;
        ++v7;
      }
      v14 += 10;
    }
    CalcPlrScrolls(pnum);
  }
  return v12;
}

//----- (00450767) --------------------------------------------------------
int __fastcall GoldAutoPlace(int pnum)
{
  int v1; // ST1C_4
  int i; // [esp+14h] [ebp-14h]
  int j; // [esp+14h] [ebp-14h]
  int v5; // [esp+14h] [ebp-14h]
  int v6; // [esp+18h] [ebp-10h]
  int v7; // [esp+1Ch] [ebp-Ch]
  int v8; // [esp+1Ch] [ebp-Ch]
  signed int k; // [esp+24h] [ebp-4h]

  v6 = 0;
  for ( i = 0; plr[pnum]._pNumInv > i && !v6; ++i )
  {
    if ( plr[pnum].InvList[i]._itype == 11 )
    {
      v7 = plr[pnum].HoldItem._ivalue + plr[pnum].InvList[i]._ivalue;
      if ( v7 <= 5000 )
      {
        plr[pnum].InvList[i]._ivalue += plr[pnum].HoldItem._ivalue;
        plr[pnum]._pGold += plr[pnum].HoldItem._ivalue;
        if ( v7 < 2500 )
        {
          if ( v7 > 1000 )
            plr[pnum].InvList[i]._iCurs = 5;
          else
            plr[pnum].InvList[i]._iCurs = 4;
        }
        else
        {
          plr[pnum].InvList[i]._iCurs = 6;
        }
        v6 = 1;
      }
    }
  }
  if ( !v6 )
  {
    for ( j = 0; plr[pnum]._pNumInv > j && !v6; ++j )
    {
      if ( plr[pnum].InvList[j]._itype == 11 && plr[pnum].InvList[j]._ivalue < 5000 )
      {
        v8 = plr[pnum].HoldItem._ivalue + plr[pnum].InvList[j]._ivalue;
        if ( v8 > 5000 )
        {
          v1 = 5000 - plr[pnum].InvList[j]._ivalue;
          plr[pnum]._pGold += v1;
          plr[pnum].HoldItem._ivalue -= v1;
          plr[pnum].InvList[j]._ivalue = 5000;
          plr[pnum].InvList[j]._iCurs = 6;
        }
        else
        {
          plr[pnum].InvList[j]._ivalue += plr[pnum].HoldItem._ivalue;
          plr[pnum]._pGold += plr[pnum].HoldItem._ivalue;
          if ( v8 < 2500 )
          {
            if ( v8 > 1000 )
              plr[pnum].InvList[j]._iCurs = 5;
            else
              plr[pnum].InvList[j]._iCurs = 4;
          }
          else
          {
            plr[pnum].InvList[j]._iCurs = 6;
          }
          v6 = 1;
        }
      }
    }
  }
  if ( !v6 )
  {
    for ( k = 39; k >= 0 && !v6; --k )
    {
      if ( !plr[pnum].InvGrid[10 * (k / 10) + k % 10] )
      {
        v5 = plr[pnum]._pNumInv;
        plr[pnum]._pGold += plr[pnum].HoldItem._ivalue;
        qmemcpy(&plr[pnum].InvList[v5], &plr[pnum].HoldItem, sizeof(plr[pnum].InvList[v5]));
        ++plr[pnum]._pNumInv;
        plr[pnum].InvGrid[10 * (k / 10) + k % 10] = plr[pnum]._pNumInv;
        if ( plr[pnum].HoldItem._ivalue < 2500 )
        {
          if ( plr[pnum].HoldItem._ivalue > 1000 )
            plr[pnum].InvList[v5]._iCurs = 5;
          else
            plr[pnum].InvList[v5]._iCurs = 4;
        }
        else
        {
          plr[pnum].InvList[v5]._iCurs = 6;
        }
        v6 = 1;
      }
    }
  }
  return v6;
}

//----- (00450F49) --------------------------------------------------------
int __fastcall WeaponAutoPlace(int pnum)
{
  int result; // eax

  if ( plr[pnum].HoldItem._iLoc == 2 )
  {
    if ( plr[pnum].InvBody[4]._itype == -1 && plr[pnum].InvBody[5]._itype == -1 )
    {
      NetSendCmdChItem(1u, 4u);
      qmemcpy(&plr[pnum].InvBody[4], &plr[pnum].HoldItem, sizeof(plr[pnum].InvBody[4]));
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    if ( plr[pnum].InvBody[4]._itype == -1 )
    {
      NetSendCmdChItem(1u, 4u);
      qmemcpy(&plr[pnum].InvBody[4], &plr[pnum].HoldItem, sizeof(plr[pnum].InvBody[4]));
    }
    else
    {
      NetSendCmdChItem(1u, 5u);
      qmemcpy(&plr[pnum].InvBody[5], &plr[pnum].HoldItem, sizeof(plr[pnum].InvBody[5]));
    }
    result = 1;
  }
  return result;
}

//----- (00451102) --------------------------------------------------------
int __fastcall SwapItem(ItemStruct *a, ItemStruct *b)
{
  char v3; // [esp+14h] [ebp-170h]
  int v4; // [esp+D4h] [ebp-B0h]

  qmemcpy(&v3, a, 0x170u);
  qmemcpy(a, b, sizeof(ItemStruct));
  qmemcpy(b, &v3, sizeof(ItemStruct));
  return v4 + 12;
}

//----- (00451166) --------------------------------------------------------
void __fastcall CheckInvPaste(int pnum, int mx, int my)
{
  int v4; // ST4C_4
  int v5; // ST4C_4
  int v7; // [esp+18h] [ebp-1B8h]
  int v8; // [esp+18h] [ebp-1B8h]
  int v9; // [esp+18h] [ebp-1B8h]
  int v10; // [esp+20h] [ebp-1B0h]
  int v11; // [esp+24h] [ebp-1ACh]
  int v12; // [esp+28h] [ebp-1A8h]
  int v13; // [esp+2Ch] [ebp-1A4h]
  int k; // [esp+30h] [ebp-1A0h]
  int l; // [esp+30h] [ebp-1A0h]
  int ii; // [esp+34h] [ebp-19Ch]
  int iia; // [esp+34h] [ebp-19Ch]
  int iib; // [esp+34h] [ebp-19Ch]
  signed int iic; // [esp+34h] [ebp-19Ch]
  int iid; // [esp+34h] [ebp-19Ch]
  signed int v21; // [esp+38h] [ebp-198h]
  signed int v22; // [esp+38h] [ebp-198h]
  signed int v23; // [esp+3Ch] [ebp-194h]
  int v24; // [esp+40h] [ebp-190h]
  int v25; // [esp+40h] [ebp-190h]
  char v26; // [esp+44h] [ebp-18Ch]
  int v27; // [esp+1B4h] [ebp-1Ch]
  int v28; // [esp+1B8h] [ebp-18h]
  int j; // [esp+1BCh] [ebp-14h]
  int v30; // [esp+1C0h] [ebp-10h]
  int v31; // [esp+1C4h] [ebp-Ch]
  int i; // [esp+1C8h] [ebp-8h]
  int v33; // [esp+1CCh] [ebp-4h]

  SetICursor(plr[pnum].HoldItem._iCurs + 12);
  v13 = mx + (icursW >> 1);
  v11 = my + (icursH >> 1);
  v12 = icursW28;
  v10 = icursH28;
  v21 = 0;
  for ( j = 0; (unsigned int)j < 0x49 && !v21; ++j )
  {
    if ( InvRect[j].X <= v13 && InvRect[j].X + 28 > v13 && InvRect[j].Y - 29 <= v11 && InvRect[j].Y > v11 )
    {
      v21 = 1;
      --j;
    }
    if ( j == 24 )
    {
      if ( !(icursW28 & 1) )
        v13 -= 14;
      if ( !(icursH28 & 1) )
        v11 -= 14;
    }
    if ( j == 64 && !(icursH28 & 1) )
      v11 += 14;
  }
  if ( v21 )
  {
    v23 = 7;
    if ( j >= 0 && j <= 3 )
      v23 = 4;
    if ( j >= 4 && j <= 5 )
      v23 = 5;
    if ( j == 6 )
      v23 = 6;
    if ( j >= 7 && j <= 18 )
      v23 = 1;
    if ( j >= 19 && j <= 24 )
      v23 = 3;
    if ( j >= 65 && j <= 72 )
      v23 = 8;
    v22 = 0;
    if ( plr[pnum].HoldItem._iLoc == v23 )
      v22 = 1;
    if ( v23 == 1 && plr[pnum].HoldItem._iLoc == 2 )
    {
      v23 = 2;
      v22 = 1;
    }
    if ( plr[pnum].HoldItem._iLoc == 7 && v23 == 8 && icursW28 == 1 && icursH28 == 1 )
      v22 = 1;
    if ( v23 == 7 )
    {
      v28 = j - 25;
      v33 = 0;
      v22 = 1;
      if ( plr[pnum].HoldItem._itype == 11 )
      {
        v27 = 10 * (v28 / 10);
        if ( plr[pnum].InvGrid[10 * (v28 / 10) + v28 % 10] )
        {
          v31 = plr[pnum].InvGrid[v28 % 10 + v27];
          if ( v31 <= 0 )
          {
            v33 = -v31;
          }
          else if ( plr[pnum].InvList[v31 - 1]._itype != 11 )
          {
            v33 = v31;
          }
        }
      }
      else
      {
        v27 = 10 * (v28 / 10 - ((icursH28 - 1) >> 1));
        if ( v27 < 0 )
          v27 = 0;
        for ( k = 0; k < icursH28 && v22; ++k )
        {
          if ( v27 >= 40 )
            v22 = 0;
          v7 = v28 % 10 - ((icursW28 - 1) >> 1);
          if ( v7 < 0 )
            v7 = 0;
          for ( ii = 0; ii < icursW28 && v22; ++ii )
          {
            if ( v7 < 10 )
            {
              if ( plr[pnum].InvGrid[v7 + v27] )
              {
                v31 = plr[pnum].InvGrid[v7 + v27];
                if ( v31 < 0 )
                  v31 = -v31;
                if ( v33 )
                {
                  if ( v31 != v33 )
                    v22 = 0;
                }
                else
                {
                  v33 = v31;
                }
              }
            }
            else
            {
              v22 = 0;
            }
            ++v7;
          }
          v27 += 10;
        }
      }
    }
    if ( v22 && v23 != 7 && v23 != 8 && !plr[pnum].HoldItem._iStatFlag )
    {
      v22 = 0;
      if ( !plr[pnum]._pClass )
        PlaySFX(196);
      if ( plr[pnum]._pClass == 1 )
        PlaySFX(168);
      if ( plr[pnum]._pClass == 2 )
        PlaySFX(140);
    }
    if ( v22 )
    {
      if ( myplr == pnum )
        PlaySFX(psfx[ItemCAnimTbl[plr[pnum].HoldItem._iCurs]]);
      i = 1;
      switch ( v23 )
      {
        case 1:
          if ( j <= 13 )
          {
            if ( plr[pnum].InvBody[4]._itype == -1 )
            {
              if ( plr[pnum].InvBody[5]._itype == -1 || plr[pnum].InvBody[5]._iClass != plr[pnum].HoldItem._iClass )
              {
                NetSendCmdChItem(0, 4u);
                qmemcpy(&plr[pnum].InvBody[4], &plr[pnum].HoldItem, sizeof(plr[pnum].InvBody[4]));
              }
              else
              {
                NetSendCmdChItem(0, 5u);
                i = SwapItem(&plr[pnum].InvBody[5], &plr[pnum].HoldItem);
              }
            }
            else if ( plr[pnum].InvBody[5]._itype == -1 || plr[pnum].InvBody[5]._iClass != plr[pnum].HoldItem._iClass )
            {
              NetSendCmdChItem(0, 4u);
              i = SwapItem(&plr[pnum].InvBody[4], &plr[pnum].HoldItem);
            }
            else
            {
              NetSendCmdChItem(0, 5u);
              i = SwapItem(&plr[pnum].InvBody[5], &plr[pnum].HoldItem);
            }
            break;
          }
          if ( plr[pnum].InvBody[5]._itype == -1 )
          {
            if ( plr[pnum].InvBody[4]._itype == -1 || plr[pnum].InvBody[4]._iLoc != 2 )
            {
              if ( plr[pnum].InvBody[4]._itype == -1 || plr[pnum].InvBody[4]._iClass != plr[pnum].HoldItem._iClass )
              {
                NetSendCmdChItem(0, 5u);
                qmemcpy(&plr[pnum].InvBody[5], &plr[pnum].HoldItem, sizeof(plr[pnum].InvBody[5]));
              }
              else
              {
                NetSendCmdChItem(0, 4u);
                i = SwapItem(&plr[pnum].InvBody[4], &plr[pnum].HoldItem);
              }
            }
            else
            {
              NetSendCmdChItem(0, 4u);
              SwapItem(&plr[pnum].InvBody[5], &plr[pnum].InvBody[4]);
              i = SwapItem(&plr[pnum].InvBody[5], &plr[pnum].HoldItem);
            }
            break;
          }
          if ( plr[pnum].InvBody[4]._itype != -1 && plr[pnum].InvBody[4]._iClass == plr[pnum].HoldItem._iClass )
          {
            NetSendCmdChItem(0, 4u);
            i = SwapItem(&plr[pnum].InvBody[4], &plr[pnum].HoldItem);
            break;
          }
          if ( plr[pnum].InvBody[5]._iClass == plr[pnum].HoldItem._iClass )
          {
            NetSendCmdChItem(0, 5u);
            i = SwapItem(&plr[pnum].InvBody[5], &plr[pnum].HoldItem);
            break;
          }
          return;
        case 2:
          NetSendCmdDelItem(0, 5u);
          if ( plr[pnum].InvBody[4]._itype == -1 || plr[pnum].InvBody[5]._itype == -1 )
            goto LABEL_159;
          qmemcpy(&v26, &plr[pnum].HoldItem, 0x170u);
          if ( plr[pnum].InvBody[5]._itype == 5 )
            qmemcpy(&plr[pnum].HoldItem, &plr[pnum].InvBody[5], sizeof(plr[pnum].HoldItem));
          else
            qmemcpy(&plr[pnum].HoldItem, &plr[pnum].InvBody[4], sizeof(plr[pnum].HoldItem));
          if ( myplr == pnum )
            SetCursor(plr[pnum].HoldItem._iCurs + 12);
          else
            SetICursor(plr[pnum].HoldItem._iCurs + 12);
          v30 = 0;
          for ( iia = 0; iia < 40 && !v30; ++iia )
            v30 = AutoPlace(pnum, iia, icursW28, icursH28, 1);
          qmemcpy(&plr[pnum].HoldItem, &v26, sizeof(plr[pnum].HoldItem));
          if ( myplr == pnum )
            SetCursor(plr[pnum].HoldItem._iCurs + 12);
          else
            SetICursor(plr[pnum].HoldItem._iCurs + 12);
          if ( v30 )
          {
            if ( plr[pnum].InvBody[5]._itype == 5 )
              plr[pnum].InvBody[5]._itype = -1;
            else
              plr[pnum].InvBody[4]._itype = -1;
LABEL_159:
            if ( plr[pnum].InvBody[4]._itype != -1 || plr[pnum].InvBody[5]._itype != -1 )
            {
              NetSendCmdChItem(0, 4u);
              if ( plr[pnum].InvBody[4]._itype == -1 )
                SwapItem(&plr[pnum].InvBody[4], &plr[pnum].InvBody[5]);
              i = SwapItem(&plr[pnum].InvBody[4], &plr[pnum].HoldItem);
            }
            else
            {
              NetSendCmdChItem(0, 4u);
              qmemcpy(&plr[pnum].InvBody[4], &plr[pnum].HoldItem, sizeof(plr[pnum].InvBody[4]));
            }
            if ( plr[pnum].InvBody[4]._itype == 10 && plr[pnum].InvBody[4]._iSpell && plr[pnum].InvBody[4]._iCharges > 0 )
            {
              plr[pnum]._pRSpell = plr[pnum].InvBody[4]._iSpell;
              plr[pnum]._pRSplType = 3;
              drawpanflag = 255;
            }
            break;
          }
          return;
        case 3:
          NetSendCmdChItem(0, 6u);
          if ( plr[pnum].InvBody[6]._itype == -1 )
            qmemcpy(&plr[pnum].InvBody[6], &plr[pnum].HoldItem, sizeof(plr[pnum].InvBody[6]));
          else
            i = SwapItem(&plr[pnum].InvBody[6], &plr[pnum].HoldItem);
          break;
        case 4:
          NetSendCmdChItem(0, 0);
          if ( plr[pnum].InvBody[0]._itype == -1 )
            qmemcpy(plr[pnum].InvBody, &plr[pnum].HoldItem, 0x170u);
          else
            i = SwapItem(plr[pnum].InvBody, &plr[pnum].HoldItem);
          break;
        case 5:
          if ( j == 4 )
          {
            NetSendCmdChItem(0, 1u);
            if ( plr[pnum].InvBody[1]._itype == -1 )
              qmemcpy(&plr[pnum].InvBody[1], &plr[pnum].HoldItem, sizeof(plr[pnum].InvBody[1]));
            else
              i = SwapItem(&plr[pnum].InvBody[1], &plr[pnum].HoldItem);
          }
          else
          {
            NetSendCmdChItem(0, 2u);
            if ( plr[pnum].InvBody[2]._itype == -1 )
              qmemcpy(&plr[pnum].InvBody[2], &plr[pnum].HoldItem, sizeof(plr[pnum].InvBody[2]));
            else
              i = SwapItem(&plr[pnum].InvBody[2], &plr[pnum].HoldItem);
          }
          break;
        case 6:
          NetSendCmdChItem(0, 3u);
          if ( plr[pnum].InvBody[3]._itype == -1 )
            qmemcpy(&plr[pnum].InvBody[3], &plr[pnum].HoldItem, sizeof(plr[pnum].InvBody[3]));
          else
            i = SwapItem(&plr[pnum].InvBody[3], &plr[pnum].HoldItem);
          break;
        case 7:
          if ( plr[pnum].HoldItem._itype != 11 || v33 )
          {
            if ( v33 )
            {
              v28 = v33 - 1;
              if ( plr[pnum].HoldItem._itype == 11 )
                plr[pnum]._pGold += plr[pnum].HoldItem._ivalue;
              i = SwapItem(&plr[pnum].InvList[v28], &plr[pnum].HoldItem);
              if ( plr[pnum].HoldItem._itype == 11 )
                plr[pnum]._pGold = CalculateGold(pnum);
              for ( iic = 0; iic < 40; ++iic )
              {
                if ( plr[pnum].InvGrid[iic] == v33 )
                  plr[pnum].InvGrid[iic] = 0;
                if ( plr[pnum].InvGrid[iic] == -v33 )
                  plr[pnum].InvGrid[iic] = 0;
              }
            }
            else
            {
              v28 = plr[pnum]._pNumInv;
              qmemcpy(&plr[pnum].InvList[v28], &plr[pnum].HoldItem, sizeof(plr[pnum].InvList[v28]));
              v33 = ++plr[pnum]._pNumInv;
            }
            v28 = j - 25;
            v27 = 10 * ((j - 25) / 10 - ((v10 - 1) >> 1));
            if ( v27 < 0 )
              v27 = 0;
            for ( l = 0; l < v10; ++l )
            {
              v9 = v28 % 10 - ((v12 - 1) >> 1);
              if ( v9 < 0 )
                v9 = 0;
              for ( iid = 0; iid < v12; ++iid )
              {
                if ( iid || v10 - 1 != l )
                  plr[pnum].InvGrid[v9 + v27] = -(char)v33;
                else
                  plr[pnum].InvGrid[v9 + v27] = v33;
                ++v9;
              }
              v27 += 10;
            }
          }
          else
          {
            v28 = j - 25;
            v27 = 10 * ((j - 25) / 10);
            v8 = (j - 25) % 10;
            if ( plr[pnum].InvGrid[10 * ((j - 25) / 10) + v8] <= 0 )
            {
              v28 = plr[pnum]._pNumInv;
              qmemcpy(&plr[pnum].InvList[v28], &plr[pnum].HoldItem, sizeof(plr[pnum].InvList[v28]));
              ++plr[pnum]._pNumInv;
              plr[pnum].InvGrid[v8 + v27] = plr[pnum]._pNumInv;
              plr[pnum]._pGold += plr[pnum].HoldItem._ivalue;
            }
            else
            {
              iib = plr[pnum].InvGrid[v8 + v27] - 1;
              v24 = plr[pnum].HoldItem._ivalue + plr[pnum].InvList[iib]._ivalue;
              if ( v24 > 5000 )
              {
                v4 = 5000 - plr[pnum].InvList[iib]._ivalue;
                plr[pnum]._pGold += v4;
                plr[pnum].HoldItem._ivalue -= v4;
                plr[pnum].InvList[iib]._ivalue = 5000;
                plr[pnum].InvList[iib]._iCurs = 6;
                if ( plr[pnum].HoldItem._ivalue < 2500 )
                {
                  if ( plr[pnum].HoldItem._ivalue > 1000 )
                    i = 17;
                  else
                    i = 16;
                }
                else
                {
                  i = 18;
                }
              }
              else
              {
                plr[pnum].InvList[iib]._ivalue += plr[pnum].HoldItem._ivalue;
                plr[pnum]._pGold += plr[pnum].HoldItem._ivalue;
                if ( v24 < 2500 )
                {
                  if ( v24 > 1000 )
                    plr[pnum].InvList[iib]._iCurs = 5;
                  else
                    plr[pnum].InvList[iib]._iCurs = 4;
                }
                else
                {
                  plr[pnum].InvList[iib]._iCurs = 6;
                }
              }
            }
          }
          break;
        case 8:
          v28 = j - 65;
          if ( plr[pnum].HoldItem._itype == 11 )
          {
            if ( plr[pnum].SpdList[v28]._itype == -1 )
            {
              qmemcpy(&plr[pnum].SpdList[v28], &plr[pnum].HoldItem, sizeof(plr[pnum].SpdList[v28]));
              plr[pnum]._pGold += plr[pnum].HoldItem._ivalue;
            }
            else if ( plr[pnum].SpdList[v28]._itype == 11 )
            {
              v25 = plr[pnum].HoldItem._ivalue + plr[pnum].SpdList[v28]._ivalue;
              if ( v25 > 5000 )
              {
                v5 = 5000 - plr[pnum].SpdList[v28]._ivalue;
                plr[pnum]._pGold += v5;
                plr[pnum].HoldItem._ivalue -= v5;
                plr[pnum].SpdList[v28]._ivalue = 5000;
                plr[pnum].SpdList[v28]._iCurs = 6;
                if ( plr[pnum].HoldItem._ivalue < 2500 )
                {
                  if ( plr[pnum].HoldItem._ivalue > 1000 )
                    i = 17;
                  else
                    i = 16;
                }
                else
                {
                  i = 18;
                }
              }
              else
              {
                plr[pnum].SpdList[v28]._ivalue += plr[pnum].HoldItem._ivalue;
                plr[pnum]._pGold += plr[pnum].HoldItem._ivalue;
                if ( v25 < 2500 )
                {
                  if ( v25 > 1000 )
                    plr[pnum].SpdList[v28]._iCurs = 5;
                  else
                    plr[pnum].SpdList[v28]._iCurs = 4;
                }
                else
                {
                  plr[pnum].SpdList[v28]._iCurs = 6;
                }
              }
            }
            else
            {
              plr[pnum]._pGold += plr[pnum].HoldItem._ivalue;
              i = SwapItem(&plr[pnum].SpdList[v28], &plr[pnum].HoldItem);
            }
          }
          else if ( plr[pnum].SpdList[v28]._itype == -1 )
          {
            qmemcpy(&plr[pnum].SpdList[v28], &plr[pnum].HoldItem, sizeof(plr[pnum].SpdList[v28]));
          }
          else
          {
            i = SwapItem(&plr[pnum].SpdList[v28], &plr[pnum].HoldItem);
            if ( plr[pnum].HoldItem._itype == 11 )
              plr[pnum]._pGold = CalculateGold(pnum);
          }
          draw_btn = 1;
          break;
        default:
          break;
      }
      CalcPlrInv(pnum, 1);
      if ( myplr == pnum )
      {
        scrollrt_draw_cursor_back_buffer();
        if ( i == 1 )
          SetCursorPos(MouseX + (cursW >> 1), MouseY + (cursH >> 1));
        SetCursor(i);
        scrollrt_draw_cursor_item();
      }
    }
  }
}

//----- (0045389E) --------------------------------------------------------
void __fastcall CheckInvSwap(int pnum, BYTE bLoc, int idx, int wCI, int seed, int bId)
{
  int ii; // ST20_4
  PlayerStruct *v9; // [esp+18h] [ebp-4h]

  ii = itemavail[0];
  RecreateItem(itemavail[0], idx, wCI, seed, 0);
  v9 = &plr[pnum];
  qmemcpy(&plr[pnum].HoldItem, &item[ii], sizeof(plr[pnum].HoldItem));
  if ( (signed int)bLoc < 7 )
  {
    qmemcpy(&v9->InvBody[bLoc], &v9->HoldItem, sizeof(v9->InvBody[bLoc]));
    if ( bLoc == 4 )
    {
      if ( v9->HoldItem._iLoc == 2 )
        v9->InvBody[5]._itype = -1;
    }
    else if ( bLoc == 5 && v9->HoldItem._iLoc == 2 )
    {
      v9->InvBody[4]._itype = -1;
    }
  }
  CalcPlrInv(pnum, 1);
}

//----- (004539BF) --------------------------------------------------------
void __fastcall CheckInvCut(int pnum, int mx, int my)
{
  signed int j; // [esp+14h] [ebp-14h]
  signed int k; // [esp+14h] [ebp-14h]
  signed int v7; // [esp+18h] [ebp-10h]
  int v8; // [esp+1Ch] [ebp-Ch]
  int v9; // [esp+1Ch] [ebp-Ch]
  signed int i; // [esp+20h] [ebp-8h]
  int v11; // [esp+24h] [ebp-4h]
  int v12; // [esp+24h] [ebp-4h]

  if ( plr[pnum]._pmode <= 3 )
  {
    v7 = 0;
    for ( i = 0; (unsigned int)i < 0x49 && !v7; ++i )
    {
      if ( InvRect[i].X <= mx && InvRect[i].X + 29 > mx && InvRect[i].Y - 29 <= my && InvRect[i].Y > my )
      {
        v7 = 1;
        --i;
      }
    }
    if ( v7 )
    {
      plr[pnum].HoldItem._itype = -1;
      if ( i >= 0 && i <= 3 && plr[pnum].InvBody[0]._itype != -1 )
      {
        NetSendCmdDelItem(0, 0);
        qmemcpy(&plr[pnum].HoldItem, plr[pnum].InvBody, sizeof(plr[pnum].HoldItem));
        plr[pnum].InvBody[0]._itype = -1;
      }
      if ( i == 4 && plr[pnum].InvBody[1]._itype != -1 )
      {
        NetSendCmdDelItem(0, 1u);
        qmemcpy(&plr[pnum].HoldItem, &plr[pnum].InvBody[1], sizeof(plr[pnum].HoldItem));
        plr[pnum].InvBody[1]._itype = -1;
      }
      if ( i == 5 && plr[pnum].InvBody[2]._itype != -1 )
      {
        NetSendCmdDelItem(0, 2u);
        qmemcpy(&plr[pnum].HoldItem, &plr[pnum].InvBody[2], sizeof(plr[pnum].HoldItem));
        plr[pnum].InvBody[2]._itype = -1;
      }
      if ( i == 6 && plr[pnum].InvBody[3]._itype != -1 )
      {
        NetSendCmdDelItem(0, 3u);
        qmemcpy(&plr[pnum].HoldItem, &plr[pnum].InvBody[3], sizeof(plr[pnum].HoldItem));
        plr[pnum].InvBody[3]._itype = -1;
      }
      if ( i >= 7 && i <= 12 && plr[pnum].InvBody[4]._itype != -1 )
      {
        NetSendCmdDelItem(0, 4u);
        qmemcpy(&plr[pnum].HoldItem, &plr[pnum].InvBody[4], sizeof(plr[pnum].HoldItem));
        plr[pnum].InvBody[4]._itype = -1;
      }
      if ( i >= 13 && i <= 18 && plr[pnum].InvBody[5]._itype != -1 )
      {
        NetSendCmdDelItem(0, 5u);
        qmemcpy(&plr[pnum].HoldItem, &plr[pnum].InvBody[5], sizeof(plr[pnum].HoldItem));
        plr[pnum].InvBody[5]._itype = -1;
      }
      if ( i >= 19 && i <= 24 && plr[pnum].InvBody[6]._itype != -1 )
      {
        NetSendCmdDelItem(0, 6u);
        qmemcpy(&plr[pnum].HoldItem, &plr[pnum].InvBody[6], sizeof(plr[pnum].HoldItem));
        plr[pnum].InvBody[6]._itype = -1;
      }
      if ( i >= 25 && i <= 64 )
      {
        v8 = i - 25;
        if ( *((_BYTE *)&plr[pnum].InvList[39]._iVAdd2 + i + 3) )
        {
          v11 = plr[pnum].InvGrid[v8] <= 0 ? -plr[pnum].InvGrid[v8] : plr[pnum].InvGrid[v8];
          for ( j = 0; j < 40; ++j )
          {
            if ( plr[pnum].InvGrid[j] == v11 || plr[pnum].InvGrid[j] == -v11 )
              plr[pnum].InvGrid[j] = 0;
          }
          v12 = v11 - 1;
          qmemcpy(&plr[pnum].HoldItem, &plr[pnum].InvList[v12], sizeof(plr[pnum].HoldItem));
          if ( --plr[pnum]._pNumInv > 0 && plr[pnum]._pNumInv != v12 )
          {
            qmemcpy(&plr[pnum].InvList[v12], &plr[pnum].InvList[plr[pnum]._pNumInv], sizeof(plr[pnum].InvList[v12]));
            for ( k = 0; k < 40; ++k )
            {
              if ( plr[pnum].InvGrid[k] == plr[pnum]._pNumInv + 1 )
                plr[pnum].InvGrid[k] = v12 + 1;
              if ( plr[pnum].InvGrid[k] == -(plr[pnum]._pNumInv + 1) )
                plr[pnum].InvGrid[k] = -(char)(v12 + 1);
            }
          }
        }
      }
      if ( i >= 65 )
      {
        v9 = i - 65;
        if ( plr[pnum].SpdList[i - 65]._itype != -1 )
        {
          qmemcpy(&plr[pnum].HoldItem, &plr[pnum].SpdList[v9], sizeof(plr[pnum].HoldItem));
          plr[pnum].SpdList[v9]._itype = -1;
          draw_btn = 1;
        }
      }
      if ( plr[pnum].HoldItem._itype != -1 )
      {
        if ( plr[pnum].HoldItem._itype == 11 )
          plr[pnum]._pGold = CalculateGold(pnum);
        CalcPlrInv(pnum, 1);
        if ( pnum == myplr )
        {
          PlaySFX(26);
          scrollrt_draw_cursor_back_buffer();
          SetCursor(plr[pnum].HoldItem._iCurs + 12);
          SetCursorPos(mx - (cursW >> 1), MouseY - (cursH >> 1));
          scrollrt_draw_cursor_item();
        }
      }
    }
  }
}

//----- (0045445D) --------------------------------------------------------
void __fastcall inv_update_rem_item(int pnum, int iv)
{
  if ( (signed int)(unsigned __int8)iv < 7 )
    plr[pnum].InvBody[(unsigned __int8)iv]._itype = -1;
  CalcPlrInv(pnum, 1);
}

//----- (004544C4) --------------------------------------------------------
void __fastcall RemoveInvItem(int pnum, int iv)
{
  __int64 v2; // rax
  int v3; // eax
  int v4; // [esp+Ch] [ebp-Ch]
  signed int i; // [esp+14h] [ebp-4h]
  signed int j; // [esp+14h] [ebp-4h]

  v4 = iv + 1;
  for ( i = 0; i < 40; ++i )
  {
    if ( plr[pnum].InvGrid[i] == v4 || plr[pnum].InvGrid[i] == -v4 )
      plr[pnum].InvGrid[i] = 0;
  }
  if ( --plr[pnum]._pNumInv > 0 && plr[pnum]._pNumInv != iv )
  {
    qmemcpy(&plr[pnum].InvList[iv], &plr[pnum].InvList[plr[pnum]._pNumInv], sizeof(plr[pnum].InvList[iv]));
    for ( j = 0; j < 40; ++j )
    {
      if ( plr[pnum].InvGrid[j] == plr[pnum]._pNumInv + 1 )
        plr[pnum].InvGrid[j] = iv + 1;
      if ( plr[pnum].InvGrid[j] == -(plr[pnum]._pNumInv + 1) )
        plr[pnum].InvGrid[j] = -(char)(iv + 1);
    }
  }
  CalcPlrScrolls(pnum);
  if ( plr[pnum]._pRSplType == 2 && plr[pnum]._pRSpell != -1 )
  {
    v2 = 1 << (plr[pnum]._pRSpell - 1);
    v3 = LODWORD(plr[pnum]._pScrlSpells) & v2;
    if ( !(HIDWORD(v2) & HIDWORD(plr[pnum]._pScrlSpells)) && !v3 )
      plr[pnum]._pRSpell = -1;
    drawpanflag = 255;
  }
}

//----- (00454830) --------------------------------------------------------
void __fastcall RemoveSpdBarItem(int pnum, int iv)
{
  __int64 v2; // rax
  int v3; // eax

  plr[pnum].SpdList[iv]._itype = -1;
  CalcPlrScrolls(pnum);
  if ( plr[pnum]._pRSplType == 2 && plr[pnum]._pRSpell != -1 )
  {
    v2 = 1 << (plr[pnum]._pRSpell - 1);
    v3 = LODWORD(plr[pnum]._pScrlSpells) & v2;
    if ( !(HIDWORD(v2) & HIDWORD(plr[pnum]._pScrlSpells)) && !v3 )
      plr[pnum]._pRSpell = -1;
  }
  drawpanflag = 255;
}

//----- (00454956) --------------------------------------------------------
void __cdecl CheckInvItem()
{
  if ( pcurs < 12 )
    CheckInvCut(myplr, MouseX, MouseY);
  else
    CheckInvPaste(myplr, MouseX, MouseY);
}

//----- (004549A6) --------------------------------------------------------
void __cdecl CheckInvScrn()
{
  if ( MouseX > 190 && MouseX < 437 && MouseY > 352 && MouseY < 385 )
    CheckInvItem();
}

//----- (004549FB) --------------------------------------------------------
void __fastcall CheckItemStats(int pnum)
{
  PlayerStruct *v1; // [esp+10h] [ebp-8h]

  v1 = &plr[pnum];
  plr[pnum].HoldItem._iStatFlag = 0;
  if ( plr[pnum].HoldItem._iMinStr <= v1->_pStrength
    && (char)plr[pnum].HoldItem._iMinMag <= v1->_pMagic
    && plr[pnum].HoldItem._iMinDex <= v1->_pDexterity )
  {
    plr[pnum].HoldItem._iStatFlag = 1;
  }
}

//----- (00454AB0) --------------------------------------------------------
void __fastcall InvGetItem(int pnum, int ii)
{
  if ( dItem[item[ii]._ix][item[ii]._iy] )
  {
    item[ii]._iCreateInfo &= 0x7FFFu;
    qmemcpy(&plr[pnum].HoldItem, &item[ii], sizeof(plr[pnum].HoldItem));
    CheckItemStats(pnum);
    item[ii]._isin = 1;
    dItem[item[ii]._ix][item[ii]._iy] = 0;
    pcursitem = -1;
    j_SetCursor(plr[pnum].HoldItem._iCurs + 12);
  }
}

//----- (00454C00) --------------------------------------------------------
void __fastcall AutoGetItem(int pnum, int ii)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  signed int iia; // [esp+14h] [ebp-18h]
  int iib; // [esp+14h] [ebp-18h]
  int iic; // [esp+14h] [ebp-18h]
  int iid; // [esp+14h] [ebp-18h]
  int iie; // [esp+14h] [ebp-18h]
  int iif; // [esp+14h] [ebp-18h]
  int iig; // [esp+14h] [ebp-18h]
  int iih; // [esp+14h] [ebp-18h]
  int iii; // [esp+14h] [ebp-18h]
  signed int iij; // [esp+14h] [ebp-18h]
  int iik; // [esp+14h] [ebp-18h]
  int iil; // [esp+14h] [ebp-18h]
  int iim; // [esp+14h] [ebp-18h]
  int iin; // [esp+14h] [ebp-18h]
  int iio; // [esp+14h] [ebp-18h]
  int sy; // [esp+18h] [ebp-14h]
  int v23; // [esp+1Ch] [ebp-10h]
  int sx; // [esp+20h] [ebp-Ch]
  int v25; // [esp+24h] [ebp-8h]

  if ( dItem[item[ii]._ix][item[ii]._iy] )
  {
    if ( item[ii].IDidx == 10 )
      quests[8]._qactive = 3;
    item[ii]._iCreateInfo &= 0x7FFFu;
    qmemcpy(&plr[pnum].HoldItem, &item[ii], sizeof(plr[pnum].HoldItem));
    CheckItemStats(pnum);
    SetICursor(plr[pnum].HoldItem._iCurs + 12);
    if ( plr[pnum].HoldItem._itype == 11 )
    {
      v25 = GoldAutoPlace(pnum);
    }
    else
    {
      v25 = 0;
      v23 = plr[pnum]._pgfxnum & 0xF;
      if ( (!v23 || v23 == 1) && plr[pnum]._pmode <= 3 )
      {
        if ( plr[pnum].HoldItem._iStatFlag )
        {
          if ( plr[pnum].HoldItem._iClass == 1 )
          {
            v25 = WeaponAutoPlace(pnum);
            if ( v25 )
              CalcPlrInv(pnum, 1);
          }
        }
      }
      if ( !v25 )
      {
        sx = icursW28;
        sy = icursH28;
        if ( icursW28 == 1 && icursH28 == 1 )
        {
          if ( plr[pnum].HoldItem._iStatFlag && AllItemsList[plr[pnum].HoldItem.IDidx].iUsable )
          {
            for ( iia = 0; iia < 8 && !v25; ++iia )
            {
              if ( plr[pnum].SpdList[iia]._itype == -1 )
              {
                qmemcpy(&plr[pnum].SpdList[iia], &plr[pnum].HoldItem, sizeof(plr[pnum].SpdList[iia]));
                CalcPlrScrolls(pnum);
                draw_btn = 1;
                v25 = 1;
              }
            }
          }
          for ( iib = 30; iib <= 39 && !v25; ++iib )
            v25 = AutoPlace(pnum, iib, sx, 1, 1);
          for ( iic = 20; iic <= 29 && !v25; ++iic )
            v25 = AutoPlace(pnum, iic, sx, 1, 1);
          for ( iid = 10; iid <= 19 && !v25; ++iid )
            v25 = AutoPlace(pnum, iid, sx, 1, 1);
          for ( iie = 0; iie <= 9 && !v25; ++iie )
            v25 = AutoPlace(pnum, iie, sx, 1, 1);
        }
        if ( sx == 1 && sy == 2 )
        {
          for ( iif = 29; iif >= 20 && !v25; --iif )
            v25 = AutoPlace(pnum, iif, 1, 2, 1);
          for ( iig = 9; iig >= 0 && !v25; --iig )
            v25 = AutoPlace(pnum, iig, 1, 2, 1);
          for ( iih = 19; iih >= 10 && !v25; --iih )
            v25 = AutoPlace(pnum, iih, 1, 2, 1);
        }
        if ( sx == 1 && sy == 3 )
        {
          for ( iii = 0; iii < 20 && !v25; ++iii )
            v25 = AutoPlace(pnum, iii, 1, 3, 1);
        }
        if ( sx == 2 && sy == 2 )
        {
          for ( iij = 0; iij < 10 && !v25; ++iij )
            v25 = AutoPlace(pnum, AP2x2Tbl[iij], 2, 2, 1);
          for ( iik = 21; iik < 29 && !v25; iik += 2 )
            v25 = AutoPlace(pnum, iik, 2, 2, 1);
          for ( iil = 1; iil < 9 && !v25; iil += 2 )
            v25 = AutoPlace(pnum, iil, 2, 2, 1);
          for ( iim = 10; iim < 19 && !v25; ++iim )
            v25 = AutoPlace(pnum, iim, 2, 2, 1);
        }
        if ( sx == 2 && sy == 3 )
        {
          for ( iin = 0; iin < 9 && !v25; ++iin )
            v25 = AutoPlace(pnum, iin, 2, 3, 1);
          for ( iio = 10; iio < 19 && !v25; ++iio )
            v25 = AutoPlace(pnum, iio, 2, 3, 1);
        }
      }
    }
    if ( v25 )
    {
      item[ii]._isin = 1;
      dItem[item[ii]._ix][item[ii]._iy] = 0;
    }
    else
    {
      if ( pnum == myplr )
      {
        if ( !plr[pnum]._pClass )
        {
          v2 = random(0, 3);
          PlaySFX(v2 + 197);
        }
        if ( plr[pnum]._pClass == 1 )
        {
          v3 = random(0, 3);
          PlaySFX(v3 + 169);
        }
        if ( plr[pnum]._pClass == 2 )
        {
          v4 = random(0, 3);
          PlaySFX(v4 + 141);
        }
      }
      qmemcpy(&plr[pnum].HoldItem, &item[ii], sizeof(plr[pnum].HoldItem));
      RespawnItem(ii, 1);
      NetSendCmdPItem(1u, 0xDu, item[ii]._ix, item[ii]._iy);
      plr[pnum].HoldItem._itype = -1;
    }
  }
}

//----- (00455514) --------------------------------------------------------
int __fastcall FindGetItem(int indx, unsigned __int16 ci, int iseed)
{
  int i; // [esp+14h] [ebp-8h]
  int v5; // [esp+18h] [ebp-4h]

  for ( i = 0; numitems > i; ++i )
  {
    v5 = itemactive[i];
    if ( item[v5].IDidx == indx && item[v5]._iSeed == iseed && item[v5]._iCreateInfo == ci )
      return itemactive[i];
  }
  return -1;
}

//----- (004555CE) --------------------------------------------------------
void __fastcall SyncGetItem(int x, int y, int idx, unsigned __int16 ci, int iseed)
{
  int v5; // [esp+14h] [ebp-4h]

  if ( dItem[x][y] )
  {
    v5 = dItem[x][y] - 1;
    if ( item[v5].IDidx != idx || item[v5]._iSeed != iseed || item[v5]._iCreateInfo != ci )
      v5 = FindGetItem(idx, ci, iseed);
  }
  else
  {
    v5 = FindGetItem(idx, ci, iseed);
  }
  if ( v5 == -1 )
    assertion_failed(1240, "C:\\Diablo\\Direct\\inv.cpp");
  item[v5]._isin = 1;
  dItem[item[v5]._ix][item[v5]._iy] = 0;
}

//----- (0045571F) --------------------------------------------------------
int __fastcall CanPut(int i, int j)
{
  int v3; // [esp+14h] [ebp-4h]

  if ( dItem[i][j] )
    return 0;
  if ( nSolidTable[dPiece[i][j]] )
    return 0;
  if ( dObject[i][j] )
  {
    v3 = dObject[i][j] <= 0 ? -(dObject[i][j] + 1) : dObject[i][j] - 1;
    if ( object[v3]._oSolidFlag )
      return 0;
  }
  if ( dObject[i + 1][j + 1] > 0 && object[dObject[i + 1][j + 1] - 1]._oSelFlag )
    return 0;
  if ( dObject[i + 1][j + 1] < 0 && object[-(dObject[i + 1][j + 1] + 1)]._oSelFlag )
    return 0;
  if ( dObject[i + 1][j] > 0
    && dObject[i][j + 1] > 0
    && object[dObject[i + 1][j] - 1]._oSelFlag
    && object[dObject[i][j + 1] - 1]._oSelFlag )
  {
    return 0;
  }
  return 1;
}

//----- (004559A0) --------------------------------------------------------
int __cdecl TryInvPut()
{
  int v0; // ST18_4
  int v1; // ST24_4
  int v3; // [esp+Ch] [ebp-14h]
  int j; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  int v6; // [esp+1Ch] [ebp-4h]
  int v7; // [esp+1Ch] [ebp-4h]

  v0 = abs(i - plr[myplr].WorldX);
  v3 = abs(j - plr[myplr].WorldY);
  if ( v0 > 1 || v3 > 1 )
  {
    v6 = GetDirection(plr[myplr].WorldX, plr[myplr].WorldY, cursmx, cursmy);
    i = offset_x[v6] + plr[myplr].WorldX;
    j = offset_y[v6] + plr[myplr].WorldY;
  }
  if ( !CanPut(i, j) )
  {
    v7 = ((_BYTE)v6 - 1) & 7;
    i = offset_x[v7] + plr[myplr].WorldX;
    j = offset_y[v7] + plr[myplr].WorldY;
    if ( !CanPut(i, j) )
    {
      v1 = ((_BYTE)v7 + 2) & 7;
      i = offset_x[v1] + plr[myplr].WorldX;
      j = offset_y[v1] + plr[myplr].WorldY;
      if ( !CanPut(i, j) )
        return 0;
    }
  }
  if ( numitems < 127 && CanPut(i, j) )
    return 1;
  return 0;
}

//----- (00455C02) --------------------------------------------------------
int __fastcall InvPutItem(int pnum, int x, int y)
{
  int v3; // ST30_4
  int v4; // ST38_4
  int v5; // ST40_4
  int x2; // [esp+Ch] [ebp-30h]
  int m; // [esp+14h] [ebp-28h]
  int l; // [esp+18h] [ebp-24h]
  signed int k; // [esp+1Ch] [ebp-20h]
  int v12; // [esp+20h] [ebp-1Ch]
  int i; // [esp+24h] [ebp-18h]
  signed int v14; // [esp+2Ch] [ebp-10h]
  int v15; // [esp+30h] [ebp-Ch]
  int v16; // [esp+30h] [ebp-Ch]
  int j; // [esp+34h] [ebp-8h]

  x2 = x;
  v3 = abs(x - plr[pnum].WorldX);
  v12 = abs(y - plr[pnum].WorldY);
  if ( v3 > 1 || v12 > 1 )
  {
    v15 = GetDirection(plr[pnum].WorldX, plr[pnum].WorldY, x2, y);
    x2 = offset_x[v15] + plr[pnum].WorldX;
    y = offset_y[v15] + plr[pnum].WorldY;
  }
  if ( !CanPut(x2, y) )
  {
    v16 = ((_BYTE)v15 - 1) & 7;
    x2 = offset_x[v16] + plr[pnum].WorldX;
    y = offset_y[v16] + plr[pnum].WorldY;
    if ( !CanPut(x2, y) )
    {
      v4 = ((_BYTE)v16 + 2) & 7;
      x2 = offset_x[v4] + plr[pnum].WorldX;
      y = offset_y[v4] + plr[pnum].WorldY;
      if ( !CanPut(x2, y) )
      {
        v14 = 0;
        for ( k = 1; k < 50 && !v14; ++k )
        {
          for ( l = -k; l <= k && !v14; ++l )
          {
            j = l + plr[pnum].WorldY;
            for ( m = -k; m <= k && !v14; ++m )
            {
              i = m + plr[pnum].WorldX;
              if ( CanPut(m + plr[pnum].WorldX, j) )
              {
                v14 = 1;
                x2 = i;
                y = j;
              }
            }
          }
        }
      }
    }
  }
  if ( numitems >= 127 || !CanPut(x2, y) )
    return -1;
  v5 = itemavail[0];
  dItem[x2][y] = LOBYTE(itemavail[0]) + 1;
  itemavail[0] = itemavail[127 - numitems - 1];
  itemactive[numitems] = v5;
  qmemcpy(&item[v5], &plr[pnum].HoldItem, sizeof(ItemStruct));
  item[v5]._ix = x2;
  item[v5]._iy = y;
  RespawnItem(v5, 1);
  ++numitems;
  j_SetCursor(1);
  return v5;
}

//----- (0045600E) --------------------------------------------------------
int __fastcall SyncPutItem(int pnum, int x, int y, int idx, int icreateinfo, int iseed, int Id, int dur, int mdur, int ch, int mch, int ivalue, unsigned int ibuff)
{
  int v13; // ST34_4
  int v14; // ST3C_4
  int x2; // [esp+Ch] [ebp-30h]
  int m; // [esp+14h] [ebp-28h]
  int l; // [esp+18h] [ebp-24h]
  signed int k; // [esp+1Ch] [ebp-20h]
  int v21; // [esp+20h] [ebp-1Ch]
  int i; // [esp+24h] [ebp-18h]
  signed int v23; // [esp+2Ch] [ebp-10h]
  int v24; // [esp+30h] [ebp-Ch]
  int v25; // [esp+30h] [ebp-Ch]
  int j; // [esp+34h] [ebp-8h]
  int ii; // [esp+38h] [ebp-4h]

  x2 = x;
  v13 = abs(x - plr[pnum].WorldX);
  v21 = abs(y - plr[pnum].WorldY);
  if ( v13 > 1 || v21 > 1 )
  {
    v24 = GetDirection(plr[pnum].WorldX, plr[pnum].WorldY, x2, y);
    x2 = offset_x[v24] + plr[pnum].WorldX;
    y = offset_y[v24] + plr[pnum].WorldY;
  }
  if ( !CanPut(x2, y) )
  {
    v25 = ((_BYTE)v24 - 1) & 7;
    x2 = offset_x[v25] + plr[pnum].WorldX;
    y = offset_y[v25] + plr[pnum].WorldY;
    if ( !CanPut(x2, y) )
    {
      v14 = ((_BYTE)v25 + 2) & 7;
      x2 = offset_x[v14] + plr[pnum].WorldX;
      y = offset_y[v14] + plr[pnum].WorldY;
      if ( !CanPut(x2, y) )
      {
        v23 = 0;
        for ( k = 1; k < 50 && !v23; ++k )
        {
          for ( l = -k; l <= k && !v23; ++l )
          {
            j = l + plr[pnum].WorldY;
            for ( m = -k; m <= k && !v23; ++m )
            {
              i = m + plr[pnum].WorldX;
              if ( CanPut(m + plr[pnum].WorldX, j) )
              {
                v23 = 1;
                x2 = i;
                y = j;
              }
            }
          }
        }
      }
    }
  }
  if ( numitems >= 127 || !CanPut(x2, y) )
    return -1;
  ii = itemavail[0];
  dItem[x2][y] = LOBYTE(itemavail[0]) + 1;
  itemavail[0] = itemavail[127 - numitems - 1];
  itemactive[numitems] = ii;
  RecreateItem(ii, idx, icreateinfo, iseed, ivalue);
  item[ii]._ix = x2;
  item[ii]._iy = y;
  if ( Id )
    item[ii]._iIdentified = 1;
  item[ii]._iDurability = dur;
  item[ii]._iMaxDur = mdur;
  item[ii]._iCharges = ch;
  item[ii]._iMaxCharges = mch;
  RespawnItem(ii, 1);
  ++numitems;
  return ii;
}

//----- (0045646D) --------------------------------------------------------
char __cdecl CheckInvHLight()
{
  int v1; // ST1C_4
  char v2; // [esp+Ch] [ebp-10h]
  signed int i; // [esp+10h] [ebp-Ch]
  int v4; // [esp+10h] [ebp-Ch]
  int v5; // [esp+10h] [ebp-Ch]
  ItemStruct *x; // [esp+14h] [ebp-8h]
  PlayerStruct *v7; // [esp+18h] [ebp-4h]

  for ( i = 0;
        (unsigned int)i < 0x49
     && (InvRect[i].X > MouseX || InvRect[i].X + 29 <= MouseX || InvRect[i].Y - 29 > MouseY || InvRect[i].Y <= MouseY);
        ++i )
  {
    ;
  }
  if ( (unsigned int)i >= 0x49 )
    return -1;
  v2 = -1;
  infoclr = 0;
  x = 0;
  v7 = &plr[myplr];
  ClearPanel();
  if ( i < 0 || i > 3 )
  {
    switch ( i )
    {
      case 4:
        v2 = 1;
        x = &v7->InvBody[1];
        break;
      case 5:
        v2 = 2;
        x = &v7->InvBody[2];
        break;
      case 6:
        v2 = 3;
        x = &v7->InvBody[3];
        break;
      default:
        if ( i < 7 || i > 12 )
        {
          if ( i < 13 || i > 18 )
          {
            if ( i < 19 || i > 24 )
            {
              if ( i < 25 || i > 64 )
              {
                if ( i >= 65 )
                {
                  v5 = i - 65;
                  x = &v7->SpdList[v5];
                  if ( v7->SpdList[v5]._itype == -1 )
                    return -1;
                  v2 = v5 + 47;
                  draw_btn = 1;
                }
              }
              else
              {
                v4 = abs(*((char *)&v7->InvList[39]._iVAdd2 + i + 3));
                if ( !v4 )
                  return -1;
                v1 = v4 - 1;
                v2 = v1 + 7;
                x = &v7->InvList[v1];
              }
            }
            else
            {
              v2 = 6;
              x = &v7->InvBody[6];
            }
          }
          else
          {
            x = &v7->InvBody[4];
            if ( v7->InvBody[4]._itype == -1 || v7->InvBody[4]._iLoc != 2 )
            {
              v2 = 5;
              x = &v7->InvBody[5];
            }
            else
            {
              v2 = 4;
            }
          }
        }
        else
        {
          v2 = 4;
          x = &v7->InvBody[4];
        }
        break;
    }
  }
  else
  {
    v2 = 0;
    x = v7->InvBody;
  }
  if ( !x )
    assertion_failed(1515, "C:\\Diablo\\Direct\\inv.cpp");
  if ( x->_itype == -1 )
    return -1;
  if ( x->_itype == 11 )
  {
    sprintf(infostr, "%i Gold Pieces", x->_ivalue);
  }
  else
  {
    if ( x->_iMagical == 1 )
    {
      infoclr = 1;
    }
    else if ( x->_iMagical == 2 )
    {
      infoclr = 3;
    }
    strcpy(infostr, x->_iName);
    if ( x->_iIdentified )
    {
      strcpy(infostr, x->_iIName);
      PrintItemDetails(x);
    }
    else
    {
      PrintItemDur(x);
    }
  }
  return v2;
}

//----- (00456814) --------------------------------------------------------
void __fastcall RemoveScroll(int pnum)
{
  int iv; // [esp+10h] [ebp-4h]
  int iva; // [esp+10h] [ebp-4h]

  for ( iv = 0; plr[pnum]._pNumInv > iv; ++iv )
  {
    if ( plr[pnum].InvList[iv]._itype != -1
      && (plr[pnum].InvList[iv]._iMiscId == 21 || plr[pnum].InvList[iv]._iMiscId == 22)
      && plr[pnum].InvList[iv]._iSpell == plr[pnum]._pRSpell )
    {
      RemoveInvItem(pnum, iv);
      CalcPlrScrolls(pnum);
      return;
    }
  }
  for ( iva = 0; iva < 8; ++iva )
  {
    if ( plr[pnum].SpdList[iva]._itype != -1
      && (plr[pnum].SpdList[iva]._iMiscId == 21 || plr[pnum].SpdList[iva]._iMiscId == 22)
      && plr[pnum].SpdList[iva]._iSpell == plr[pnum]._pRSpell )
    {
      RemoveSpdBarItem(pnum, iva);
      CalcPlrScrolls(pnum);
      return;
    }
  }
}

//----- (00456A8A) --------------------------------------------------------
BOOL __cdecl UseScroll()
{
  int i; // [esp+Ch] [ebp-4h]
  signed int j; // [esp+Ch] [ebp-4h]

  if ( pcurs != 1 )
    return 0;
  if ( !leveltype )
    return 0;
  for ( i = 0; plr[myplr]._pNumInv > i; ++i )
  {
    if ( plr[myplr].InvList[i]._itype != -1
      && (plr[myplr].InvList[i]._iMiscId == 21 || plr[myplr].InvList[i]._iMiscId == 22)
      && plr[myplr].InvList[i]._iSpell == plr[myplr]._pRSpell )
    {
      return 1;
    }
  }
  for ( j = 0; j < 8; ++j )
  {
    if ( plr[myplr].SpdList[j]._itype != -1
      && (plr[myplr].SpdList[j]._iMiscId == 21 || plr[myplr].SpdList[j]._iMiscId == 22)
      && plr[myplr].SpdList[j]._iSpell == plr[myplr]._pRSpell )
    {
      return 1;
    }
  }
  return 0;
}

//----- (00456D2D) --------------------------------------------------------
void __fastcall UseStaffCharge(int pnum)
{
  if ( plr[pnum].InvBody[4]._itype != -1
    && plr[pnum].InvBody[4]._iMiscId == 23
    && plr[pnum].InvBody[4]._iSpell == plr[pnum]._pRSpell
    && plr[pnum].InvBody[4]._iCharges > 0 )
  {
    --plr[pnum].InvBody[4]._iCharges;
    CalcPlrStaff(pnum);
  }
}

//----- (00456E19) --------------------------------------------------------
BOOL __cdecl UseStaff()
{
  if ( pcurs != 1 )
    return 0;
  if ( plr[myplr].InvBody[4]._itype == -1
    || plr[myplr].InvBody[4]._iMiscId != 23
    || plr[myplr].InvBody[4]._iSpell != plr[myplr]._pRSpell
    || plr[myplr].InvBody[4]._iCharges <= 0 )
  {
    return 0;
  }
  return 1;
}

//----- (00456F00) --------------------------------------------------------
BOOL __fastcall inv_456F00(int sn)
{
  if ( pcurs != 1 )
    return 0;
  if ( plr[myplr].InvBody[4]._itype == -1
    || plr[myplr].InvBody[4]._iMiscId != 23
    || plr[myplr].InvBody[4]._iSpell != sn
    || plr[myplr].InvBody[4]._iCharges <= 0 )
  {
    return 0;
  }
  return 1;
}

//----- (00456FD0) --------------------------------------------------------
int __fastcall UseInvItem(int pnum, int cii)
{
  int v3; // [esp+18h] [ebp-8h]

  v3 = 0;
  if ( cii <= 5 )
    return 0;
  if ( cii > 46 )
  {
    if ( plr[pnum].SpdList[cii - 47]._iStatFlag && AllItemsList[plr[pnum].SpdList[cii - 47].IDidx].iUsable )
      v3 = 1;
  }
  else if ( plr[pnum].InvList[cii - 7]._iStatFlag )
  {
    if ( AllItemsList[plr[pnum].InvList[cii - 7].IDidx].iUsable )
      v3 = 1;
  }
  return v3;
}

//----- (0045712E) --------------------------------------------------------
void __cdecl inv_45712E()
{
  gold_index = pcursinvitem;
  if ( pcursinvitem > 46 )
    initialDropGoldValue = plr[myplr].SpdList[pcursinvitem - 47]._ivalue;
  else
    initialDropGoldValue = plr[myplr].InvList[pcursinvitem - 7]._ivalue;
  dropGoldFlag = 1;
  dropGoldValue = 0;
  if ( talkflag )
    control_reset_talk();
}

//----- (004571FD) --------------------------------------------------------
void __fastcall inv_4571FD(int pnum, int ii)
{
  int iv; // [esp+1Ch] [ebp-4h]
  int iva; // [esp+1Ch] [ebp-4h]

  if ( ii > 5 )
  {
    if ( ii > 46 )
    {
      if ( !talkflag )
      {
        iva = ii - 47;
        if ( plr[pnum].SpdList[ii - 47]._iStatFlag )
        {
          if ( AllItemsList[plr[pnum].SpdList[ii - 47].IDidx].iUsable )
          {
            if ( plr[pnum].SpdList[iva]._iMiscId || plr[pnum].SpdList[iva]._itype != 11 )
            {
              if ( (plr[pnum].SpdList[iva]._iMiscId != 21 || currlevel)
                && (plr[pnum].SpdList[iva]._iMiscId != 22 || currlevel) )
              {
                if ( pnum == myplr )
                  PlaySFX(psfx[ItemCAnimTbl[plr[pnum].SpdList[iva]._iCurs]]);
                UseItem(pnum, plr[pnum].SpdList[iva]._iMiscId, plr[pnum].SpdList[iva]._iSpell);
                RemoveSpdBarItem(pnum, iva);
              }
            }
            else
            {
              inv_45712E();
            }
          }
        }
        else
        {
          if ( !plr[pnum]._pClass )
            PlaySFX(196);
          if ( plr[pnum]._pClass == 1 )
            PlaySFX(168);
          if ( plr[pnum]._pClass == 2 )
            PlaySFX(140);
        }
      }
    }
    else
    {
      iv = ii - 7;
      if ( plr[pnum].InvList[ii - 7]._iStatFlag )
      {
        if ( AllItemsList[plr[pnum].InvList[ii - 7].IDidx].iUsable )
        {
          if ( plr[pnum].InvList[iv]._iMiscId || plr[pnum].InvList[iv]._itype != 11 )
          {
            if ( (plr[pnum].InvList[iv]._iMiscId != 21 || currlevel)
              && (plr[pnum].InvList[iv]._iMiscId != 22 || currlevel) )
            {
              if ( pnum == myplr )
                PlaySFX(psfx[ItemCAnimTbl[plr[pnum].InvList[iv]._iCurs]]);
              UseItem(pnum, plr[pnum].InvList[iv]._iMiscId, plr[pnum].InvList[iv]._iSpell);
              RemoveInvItem(pnum, iv);
            }
          }
          else
          {
            inv_45712E();
          }
        }
      }
      else
      {
        if ( !plr[pnum]._pClass )
          PlaySFX(196);
        if ( plr[pnum]._pClass == 1 )
          PlaySFX(168);
        if ( plr[pnum]._pClass == 2 )
          PlaySFX(140);
      }
    }
  }
}

//----- (0045780A) --------------------------------------------------------
void __cdecl DoTelekinesis()
{
  if ( pcursobj != -1 )
    NetSendCmdParam1(1u, CMD_OPOBJT, pcursobj);
  if ( pcursitem != -1 )
    NetSendCmdGItem(1u, CMD_REQUESTAGITEM, myplr, myplr, pcursitem);
  if ( pcursmonst != -1 )
    NetSendCmdParam1(1u, CMD_KNOCKBACK, pcursmonst);
  j_SetCursor(1);
}

//----- (0045789F) --------------------------------------------------------
int __fastcall CalculateGold(int pnum)
{
  signed int i; // [esp+10h] [ebp-8h]
  int j; // [esp+10h] [ebp-8h]
  int v4; // [esp+14h] [ebp-4h]

  v4 = 0;
  for ( i = 0; i < 8; ++i )
  {
    if ( plr[pnum].SpdList[i]._itype == 11 )
    {
      v4 += plr[pnum].SpdList[i]._ivalue;
      drawpanflag = 255;
    }
  }
  for ( j = 0; plr[pnum]._pNumInv > j; ++j )
  {
    if ( plr[pnum].InvList[j]._itype == 11 )
      v4 += plr[pnum].InvList[j]._ivalue;
  }
  return v4;
}

