//----- (00485990) --------------------------------------------------------
void __cdecl InitCursor()
{
  assert(!pCursCels, "CURSOR.CPP", 121);
  pCursCels = (char *)LoadFileInMem("Data\\Inv\\Objcurs.CEL", 0, 122, "CURSOR.CPP");
  cursor_dword_647724_buf1 = 0;
}

//----- (004859E3) --------------------------------------------------------
void __cdecl FreeCursor()
{
  mem_free_dbg(pCursCels, 130, "CURSOR.CPP");
  pCursCels = 0;
  cursor_dword_647724_buf1 = 0;
}

//----- (00485A1C) --------------------------------------------------------
void __fastcall SetICursor(int i)
{
  icursW = InvItemWidth[i];
  icursH = InvItemHeight[i];
  icursW28 = icursW / 28;
  icursH28 = icursH / 28;
}

//----- (00485A74) --------------------------------------------------------
void __fastcall SetCursor(int i)
{
  pcurs = i;
  cursW = InvItemWidth[i];
  cursH = InvItemHeight[i];
  SetICursor(i);
}

//----- (00485ABC) --------------------------------------------------------
void __fastcall j_SetCursor(int hCursor)
{
  scrollrt_draw_cursor_back_buffer();
  SetCursor(hCursor);
  scrollrt_draw_cursor_item();
}

//----- (00485AE4) --------------------------------------------------------
void __cdecl InitLevelCursor()
{
  SetCursor(1);
  cursmx = ViewX;
  cursmy = ViewY;
  cursor_647720_last_pcursmont = -1;
  pcursmonst = -1;
  pcursobj = -1;
  pcursitem = -1;
  pcursplr = -1;
  cursor_dword_645724_buf2 = 0;
  cursor_dword_645720 = 0;
  cursor_dword_645768_W = 0;
  cursor_dword_64576C_H = 0;
  dword_645744 = 0;
  dword_645740 = 0;
  dword_645760 = 0;
  dword_645764 = 0;
  memset(sgSaveBack, 0, 8096u);
}

//----- (00485BA5) --------------------------------------------------------
void __cdecl CheckTown()
{
  int v0; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  for ( i = 0; nummissiles > i; ++i )
  {
    v0 = missileactive[i];
    if ( missile[v0]._mitype == 10
      && (missile[v0]._mix - 1 == cursmx && missile[v0]._miy == cursmy
       || missile[v0]._mix == cursmx && missile[v0]._miy - 1 == cursmy
       || missile[v0]._mix - 1 == cursmx && missile[v0]._miy - 1 == cursmy
       || missile[v0]._mix - 2 == cursmx && missile[v0]._miy - 1 == cursmy
       || missile[v0]._mix - 2 == cursmx && missile[v0]._miy - 2 == cursmy
       || missile[v0]._mix - 1 == cursmx && missile[v0]._miy - 2 == cursmy
       || missile[v0]._mix == cursmx && missile[v0]._miy == cursmy) )
    {
      trigflag = 1;
      ClearPanel();
      strcpy(infostr, "Town Portal");
      sprintf(tempstr, "from %s", plr[missile[v0]._misource]._pName);
      AddPanelString(tempstr, 1);
      cursmx = missile[v0]._mix;
      cursmy = missile[v0]._miy;
    }
  }
}

//----- (00485E8F) --------------------------------------------------------
void __cdecl CheckCursMove()
{
  int v0; // [esp+Ch] [ebp-44h]
  int v1; // [esp+Ch] [ebp-44h]
  int v2; // [esp+Ch] [ebp-44h]
  int v3; // [esp+Ch] [ebp-44h]
  int v4; // [esp+Ch] [ebp-44h]
  int v5; // [esp+Ch] [ebp-44h]
  int v6; // [esp+Ch] [ebp-44h]
  int v7; // [esp+Ch] [ebp-44h]
  int v8; // [esp+Ch] [ebp-44h]
  int v9; // [esp+Ch] [ebp-44h]
  int v10; // [esp+Ch] [ebp-44h]
  int v11; // [esp+Ch] [ebp-44h]
  int v12; // [esp+Ch] [ebp-44h]
  int v13; // [esp+Ch] [ebp-44h]
  int Xonmapx; // [esp+18h] [ebp-38h]
  int Xtileoffy_1; // [esp+1Ch] [ebp-34h]
  int Xtileoffy; // [esp+1Ch] [ebp-34h]
  char v17; // [esp+20h] [ebp-30h]
  char v18; // [esp+20h] [ebp-30h]
  char v19; // [esp+20h] [ebp-30h]
  char v20; // [esp+20h] [ebp-30h]
  BOOL v21; // [esp+24h] [ebp-2Ch]
  BOOL v22; // [esp+28h] [ebp-28h]
  int Xtileoffx; // [esp+2Ch] [ebp-24h]
  BOOL v24; // [esp+30h] [ebp-20h]
  int Xdungy; // [esp+34h] [ebp-1Ch]
  int Xdungx; // [esp+38h] [ebp-18h]
  char v27; // [esp+40h] [ebp-10h]
  char v28; // [esp+40h] [ebp-10h]
  char v29; // [esp+40h] [ebp-10h]
  char v30; // [esp+40h] [ebp-10h]
  char v31; // [esp+48h] [ebp-8h]
  char v32; // [esp+48h] [ebp-8h]
  char v33; // [esp+48h] [ebp-8h]
  char v34; // [esp+48h] [ebp-8h]
  signed int v35; // [esp+4Ch] [ebp-4h]

  if ( chrflag || questlog )
  {
    if ( MouseX < 160 )
      Xonmapx = 0;
    else
      Xonmapx = MouseX - 160;
  }
  else if ( invflag || sbookflag )
  {
    if ( MouseX > 320 )
      Xonmapx = 0;
    else
      Xonmapx = MouseX + 160;
  }
  else
  {
    Xonmapx = MouseX;
  }
  if ( zoomflag )
  {
    Xtileoffx = Xonmapx & 63;
    Xtileoffy_1 = MouseY & 31;
    Xdungx = ViewX + (Xonmapx >> 6) + (MouseY >> 5) - 10;
    Xdungy = ViewY + (MouseY >> 5) - (Xonmapx >> 6);
    v21 = Xtileoffx >> 1 > Xtileoffy_1;
    if ( Xtileoffx >> 1 > Xtileoffy_1 )
      --Xdungy;
    v24 = 32 - (Xtileoffx >> 1) <= Xtileoffy_1;
    if ( 32 - (Xtileoffx >> 1) <= Xtileoffy_1 )
      ++Xdungx;
    v35 = 32;
  }
  else
  {
    Xtileoffx = Xonmapx & 127;
    Xtileoffy = MouseY & 63;
    Xdungx = ViewX + (Xonmapx >> 7) + (MouseY >> 6) - 5;
    Xdungy = ViewY + (MouseY >> 6) - (Xonmapx >> 7);
    v21 = Xtileoffx >> 1 > Xtileoffy;
    if ( Xtileoffx >> 1 > Xtileoffy )
      --Xdungy;
    v24 = 64 - (Xtileoffx >> 1) <= Xtileoffy;
    if ( 64 - (Xtileoffx >> 1) <= Xtileoffy )
      ++Xdungx;
    v35 = 64;
  }
  if ( Xdungx < 0 )
    Xdungx = 0;
  if ( Xdungx >= 112 )
    Xdungx = 111;
  if ( Xdungy < 0 )
    Xdungy = 0;
  if ( Xdungy >= 112 )
    Xdungy = 111;
  v22 = v21 && v24 || (v21 || v24) && v35 > Xtileoffx;
  cursor_647720_last_pcursmont = pcursmonst;
  pcursmonst = -1;
  pcursobj = -1;
  pcursitem = -1;
  pcursinvitem = -1;
  pcursplr = -1;
  uitemflag = 0;
  panelflag = 0;
  if ( !plr[myplr]._pInvincible )
  {
    if ( pcurs >= 12 || spselflag )
    {
      cursmx = Xdungx;
      cursmy = Xdungy;
      return;
    }
    if ( MouseY > 352 )
    {
      CheckPanelInfo();
      return;
    }
    if ( invflag && MouseX > 320 )
    {
      pcursinvitem = CheckInvHLight();
      return;
    }
    if ( !chrflag && !questlog || MouseX >= 320 )
    {
      if ( !leveltype )
      {
        if ( !v22 && dMonster[Xdungx + 1][Xdungy] > 0 )
        {
          pcursmonst = dMonster[Xdungx + 1][Xdungy] - 1;
          cursmx = Xdungx + 1;
          cursmy = Xdungy;
        }
        if ( v22 && dMonster[Xdungx][Xdungy + 1] > 0 )
        {
          pcursmonst = dMonster[Xdungx][Xdungy + 1] - 1;
          cursmx = Xdungx;
          cursmy = Xdungy + 1;
        }
        if ( dMonster[Xdungx][Xdungy] > 0 )
        {
          pcursmonst = dMonster[Xdungx][Xdungy] - 1;
          cursmx = Xdungx;
          cursmy = Xdungy;
        }
        if ( dMonster[Xdungx + 1][Xdungy + 1] > 0 )
        {
          pcursmonst = dMonster[Xdungx + 1][Xdungy + 1] - 1;
          cursmx = Xdungx + 1;
          cursmy = Xdungy + 1;
        }
        if ( !towner[pcursmonst]._tSelFlag )
          pcursmonst = -1;
        goto LABEL_207;
      }
      if ( cursor_647720_last_pcursmont == -1 )
        goto LABEL_293;
      if ( !v22 && dMonster[Xdungx + 2][Xdungy + 1] && dFlags[Xdungx + 2][Xdungy + 1] & 0x40 )
      {
        v0 = dMonster[Xdungx + 2][Xdungy + 1] <= 0 ? -(dMonster[Xdungx + 2][Xdungy + 1] + 1) : dMonster[Xdungx + 2][Xdungy + 1]
                                                                                             - 1;
        if ( v0 == cursor_647720_last_pcursmont
          && (signed int)(monster[v0]._mhitpoints & 0xFFFFFFC0) > 0
          && monster[v0].MData->mSelFlag & 4 )
        {
          cursmx = Xdungx + 1;
          cursmy = Xdungy + 2;
          pcursmonst = v0;
        }
      }
      if ( v22 && dMonster[Xdungx + 1][Xdungy + 2] && dFlags[Xdungx + 1][Xdungy + 2] & 0x40 )
      {
        v1 = dMonster[Xdungx + 1][Xdungy + 2] <= 0 ? -(dMonster[Xdungx + 1][Xdungy + 2] + 1) : dMonster[Xdungx + 1][Xdungy + 2]
                                                                                             - 1;
        if ( v1 == cursor_647720_last_pcursmont
          && (signed int)(monster[v1]._mhitpoints & 0xFFFFFFC0) > 0
          && monster[v1].MData->mSelFlag & 4 )
        {
          cursmx = Xdungx + 1;
          cursmy = Xdungy + 2;
          pcursmonst = v1;
        }
      }
      if ( dMonster[Xdungx + 2][Xdungy + 2] && dFlags[Xdungx + 2][Xdungy + 2] & 0x40 )
      {
        v2 = dMonster[Xdungx + 2][Xdungy + 2] <= 0 ? -(dMonster[Xdungx + 2][Xdungy + 2] + 1) : dMonster[Xdungx + 2][Xdungy + 2]
                                                                                             - 1;
        if ( v2 == cursor_647720_last_pcursmont
          && (signed int)(monster[v2]._mhitpoints & 0xFFFFFFC0) > 0
          && monster[v2].MData->mSelFlag & 4 )
        {
          cursmx = Xdungx + 2;
          cursmy = Xdungy + 2;
          pcursmonst = v2;
        }
      }
      if ( !v22 && dMonster[Xdungx + 1][Xdungy] && dFlags[Xdungx + 1][Xdungy] & 0x40 )
      {
        v3 = dMonster[Xdungx + 1][Xdungy] <= 0 ? -(dMonster[Xdungx + 1][Xdungy] + 1) : dMonster[Xdungx + 1][Xdungy] - 1;
        if ( v3 == cursor_647720_last_pcursmont
          && (signed int)(monster[v3]._mhitpoints & 0xFFFFFFC0) > 0
          && monster[v3].MData->mSelFlag & 2 )
        {
          cursmx = Xdungx + 1;
          cursmy = Xdungy;
          pcursmonst = v3;
        }
      }
      if ( v22 && dMonster[Xdungx][Xdungy + 1] && dFlags[Xdungx][Xdungy + 1] & 0x40 )
      {
        v4 = dMonster[Xdungx][Xdungy + 1] <= 0 ? -(dMonster[Xdungx][Xdungy + 1] + 1) : dMonster[Xdungx][Xdungy + 1] - 1;
        if ( v4 == cursor_647720_last_pcursmont
          && (signed int)(monster[v4]._mhitpoints & 0xFFFFFFC0) > 0
          && monster[v4].MData->mSelFlag & 2 )
        {
          cursmx = Xdungx;
          cursmy = Xdungy + 1;
          pcursmonst = v4;
        }
      }
      if ( dMonster[Xdungx][Xdungy] && dFlags[Xdungx][Xdungy] & 0x40 )
      {
        v5 = dMonster[Xdungx][Xdungy] <= 0 ? -(dMonster[Xdungx][Xdungy] + 1) : dMonster[Xdungx][Xdungy] - 1;
        if ( v5 == cursor_647720_last_pcursmont
          && (signed int)(monster[v5]._mhitpoints & 0xFFFFFFC0) > 0
          && monster[v5].MData->mSelFlag & 1 )
        {
          cursmx = Xdungx;
          cursmy = Xdungy;
          pcursmonst = v5;
        }
      }
      if ( dMonster[Xdungx + 1][Xdungy + 1] && dFlags[Xdungx + 1][Xdungy + 1] & 0x40 )
      {
        v6 = dMonster[Xdungx + 1][Xdungy + 1] <= 0 ? -(dMonster[Xdungx + 1][Xdungy + 1] + 1) : dMonster[Xdungx + 1][Xdungy + 1]
                                                                                             - 1;
        if ( v6 == cursor_647720_last_pcursmont
          && (signed int)(monster[v6]._mhitpoints & 0xFFFFFFC0) > 0
          && monster[v6].MData->mSelFlag & 2 )
        {
          cursmx = Xdungx + 1;
          cursmy = Xdungy + 1;
          pcursmonst = v6;
        }
      }
      if ( pcursmonst != -1 && !(monster[pcursmonst]._mFlags & 1) )
      {
        pcursmonst = -1;
        cursmx = Xdungx;
        cursmy = Xdungy;
      }
      if ( pcursmonst != -1 && monster[pcursmonst]._mFlags & 0x20 )
        pcursmonst = -1;
      if ( pcursmonst == -1 )
      {
LABEL_293:
        if ( !v22 && dMonster[Xdungx + 2][Xdungy + 1] && dFlags[Xdungx + 2][Xdungy + 1] & 0x40 )
        {
          v7 = dMonster[Xdungx + 2][Xdungy + 1] <= 0 ? -(dMonster[Xdungx + 2][Xdungy + 1] + 1) : dMonster[Xdungx + 2][Xdungy + 1]
                                                                                               - 1;
          if ( (signed int)(monster[v7]._mhitpoints & 0xFFFFFFC0) > 0 && monster[v7].MData->mSelFlag & 4 )
          {
            cursmx = Xdungx + 2;
            cursmy = Xdungy + 1;
            pcursmonst = v7;
          }
        }
        if ( v22 && dMonster[Xdungx + 1][Xdungy + 2] && dFlags[Xdungx + 1][Xdungy + 2] & 0x40 )
        {
          v8 = dMonster[Xdungx + 1][Xdungy + 2] <= 0 ? -(dMonster[Xdungx + 1][Xdungy + 2] + 1) : dMonster[Xdungx + 1][Xdungy + 2]
                                                                                               - 1;
          if ( (signed int)(monster[v8]._mhitpoints & 0xFFFFFFC0) > 0 && monster[v8].MData->mSelFlag & 4 )
          {
            cursmx = Xdungx + 1;
            cursmy = Xdungy + 2;
            pcursmonst = v8;
          }
        }
        if ( dMonster[Xdungx + 2][Xdungy + 2] && dFlags[Xdungx + 2][Xdungy + 2] & 0x40 )
        {
          v9 = dMonster[Xdungx + 2][Xdungy + 2] <= 0 ? -(dMonster[Xdungx + 2][Xdungy + 2] + 1) : dMonster[Xdungx + 2][Xdungy + 2]
                                                                                               - 1;
          if ( (signed int)(monster[v9]._mhitpoints & 0xFFFFFFC0) > 0 && monster[v9].MData->mSelFlag & 4 )
          {
            cursmx = Xdungx + 2;
            cursmy = Xdungy + 2;
            pcursmonst = v9;
          }
        }
        if ( !v22 && dMonster[Xdungx + 1][Xdungy] && dFlags[Xdungx + 1][Xdungy] & 0x40 )
        {
          v10 = dMonster[Xdungx + 1][Xdungy] <= 0 ? -(dMonster[Xdungx + 1][Xdungy] + 1) : dMonster[Xdungx + 1][Xdungy]
                                                                                        - 1;
          if ( (signed int)(monster[v10]._mhitpoints & 0xFFFFFFC0) > 0 && monster[v10].MData->mSelFlag & 2 )
          {
            cursmx = Xdungx + 1;
            cursmy = Xdungy;
            pcursmonst = v10;
          }
        }
        if ( v22 && dMonster[Xdungx][Xdungy + 1] && dFlags[Xdungx][Xdungy + 1] & 0x40 )
        {
          v11 = dMonster[Xdungx][Xdungy + 1] <= 0 ? -(dMonster[Xdungx][Xdungy + 1] + 1) : dMonster[Xdungx][Xdungy + 1]
                                                                                        - 1;
          if ( (signed int)(monster[v11]._mhitpoints & 0xFFFFFFC0) > 0 && monster[v11].MData->mSelFlag & 2 )
          {
            cursmx = Xdungx;
            cursmy = Xdungy + 1;
            pcursmonst = v11;
          }
        }
        if ( dMonster[Xdungx][Xdungy] && dFlags[Xdungx][Xdungy] & 0x40 )
        {
          v12 = dMonster[Xdungx][Xdungy] <= 0 ? -(dMonster[Xdungx][Xdungy] + 1) : dMonster[Xdungx][Xdungy] - 1;
          if ( (signed int)(monster[v12]._mhitpoints & 0xFFFFFFC0) > 0 && monster[v12].MData->mSelFlag & 1 )
          {
            cursmx = Xdungx;
            cursmy = Xdungy;
            pcursmonst = v12;
          }
        }
        if ( dMonster[Xdungx + 1][Xdungy + 1] && dFlags[Xdungx + 1][Xdungy + 1] & 0x40 )
        {
          v13 = dMonster[Xdungx + 1][Xdungy + 1] <= 0 ? -(dMonster[Xdungx + 1][Xdungy + 1] + 1) : dMonster[Xdungx + 1][Xdungy + 1]
                                                                                                - 1;
          if ( (signed int)(monster[v13]._mhitpoints & 0xFFFFFFC0) > 0 && monster[v13].MData->mSelFlag & 2 )
          {
            cursmx = Xdungx + 1;
            cursmy = Xdungy + 1;
            pcursmonst = v13;
          }
        }
        if ( pcursmonst != -1 && !(monster[pcursmonst]._mFlags & 1) )
        {
          pcursmonst = -1;
          cursmx = Xdungx;
          cursmy = Xdungy;
        }
        if ( pcursmonst != -1 && monster[pcursmonst]._mFlags & 0x20 )
          pcursmonst = -1;
LABEL_207:
        if ( pcursmonst == -1 )
        {
          if ( !v22 && dPlayer[Xdungx + 1][Xdungy] )
          {
            v27 = dPlayer[Xdungx + 1][Xdungy] <= 0 ? -(char)(dPlayer[Xdungx + 1][Xdungy] + 1) : dPlayer[Xdungx + 1][Xdungy]
                                                                                              - 1;
            if ( v27 != myplr && plr[v27]._pHitPoints )
            {
              cursmx = Xdungx + 1;
              cursmy = Xdungy;
              pcursplr = v27;
            }
          }
          if ( v22 && dPlayer[Xdungx][Xdungy + 1] )
          {
            v28 = dPlayer[Xdungx][Xdungy + 1] <= 0 ? -(char)(dPlayer[Xdungx][Xdungy + 1] + 1) : dPlayer[Xdungx][Xdungy + 1]
                                                                                              - 1;
            if ( v28 != myplr && plr[v28]._pHitPoints )
            {
              cursmx = Xdungx;
              cursmy = Xdungy + 1;
              pcursplr = v28;
            }
          }
          if ( dPlayer[Xdungx][Xdungy] )
          {
            v29 = dPlayer[Xdungx][Xdungy] <= 0 ? -(char)(dPlayer[Xdungx][Xdungy] + 1) : dPlayer[Xdungx][Xdungy] - 1;
            if ( v29 != myplr )
            {
              cursmx = Xdungx;
              cursmy = Xdungy;
              pcursplr = v29;
            }
          }
          if ( dPlayer[Xdungx + 1][Xdungy + 1] )
          {
            v30 = dPlayer[Xdungx + 1][Xdungy + 1] <= 0 ? -(char)(dPlayer[Xdungx + 1][Xdungy + 1] + 1) : dPlayer[Xdungx + 1][Xdungy + 1] - 1;
            if ( v30 != myplr && plr[v30]._pHitPoints )
            {
              cursmx = Xdungx + 1;
              cursmy = Xdungy + 1;
              pcursplr = v30;
            }
          }
        }
        if ( pcursmonst == -1 && pcursplr == -1 )
        {
          if ( !v22 && dObject[Xdungx + 1][Xdungy] )
          {
            v31 = dObject[Xdungx + 1][Xdungy] <= 0 ? -(char)(dObject[Xdungx + 1][Xdungy] + 1) : dObject[Xdungx + 1][Xdungy]
                                                                                              - 1;
            if ( object[v31]._oSelFlag >= 2 )
            {
              cursmx = Xdungx + 1;
              cursmy = Xdungy;
              pcursobj = v31;
            }
          }
          if ( v22 && dObject[Xdungx][Xdungy + 1] )
          {
            v32 = dObject[Xdungx][Xdungy + 1] <= 0 ? -(char)(dObject[Xdungx][Xdungy + 1] + 1) : dObject[Xdungx][Xdungy + 1]
                                                                                              - 1;
            if ( object[v32]._oSelFlag >= 2 )
            {
              cursmx = Xdungx;
              cursmy = Xdungy + 1;
              pcursobj = v32;
            }
          }
          if ( dObject[Xdungx][Xdungy] )
          {
            v33 = dObject[Xdungx][Xdungy] <= 0 ? -(char)(dObject[Xdungx][Xdungy] + 1) : dObject[Xdungx][Xdungy] - 1;
            if ( object[v33]._oSelFlag == 1 || object[v33]._oSelFlag == 3 )
            {
              cursmx = Xdungx;
              cursmy = Xdungy;
              pcursobj = v33;
            }
          }
          if ( dObject[Xdungx + 1][Xdungy + 1] )
          {
            v34 = dObject[Xdungx + 1][Xdungy + 1] <= 0 ? -(char)(dObject[Xdungx + 1][Xdungy + 1] + 1) : dObject[Xdungx + 1][Xdungy + 1] - 1;
            if ( object[v34]._oSelFlag >= 2 )
            {
              cursmx = Xdungx + 1;
              cursmy = Xdungy + 1;
              pcursobj = v34;
            }
          }
        }
        if ( pcursplr == -1 && pcursobj == -1 && pcursmonst == -1 )
        {
          if ( !v22 && dItem[Xdungx + 1][Xdungy] > 0 )
          {
            v17 = dItem[Xdungx + 1][Xdungy] - 1;
            if ( item[v17]._iSelFlag >= 2 )
            {
              cursmx = Xdungx + 1;
              cursmy = Xdungy;
              pcursitem = v17;
            }
          }
          if ( v22 )
          {
            if ( dItem[Xdungx][Xdungy + 1] > 0 )
            {
              v18 = dItem[Xdungx][Xdungy + 1] - 1;
              if ( item[v18]._iSelFlag >= 2 )
              {
                cursmx = Xdungx;
                cursmy = Xdungy + 1;
                pcursitem = v18;
              }
            }
          }
          if ( dItem[Xdungx][Xdungy] > 0 )
          {
            v19 = dItem[Xdungx][Xdungy] - 1;
            if ( item[v19]._iSelFlag == 1 || item[v19]._iSelFlag == 3 )
            {
              cursmx = Xdungx;
              cursmy = Xdungy;
              pcursitem = v19;
            }
          }
          if ( dItem[Xdungx + 1][Xdungy + 1] > 0 )
          {
            v20 = dItem[Xdungx + 1][Xdungy + 1] - 1;
            if ( item[v20]._iSelFlag >= 2 )
            {
              cursmx = Xdungx + 1;
              cursmy = Xdungy + 1;
              pcursitem = v20;
            }
          }
          if ( pcursitem == -1 )
          {
            cursmx = Xdungx;
            cursmy = Xdungy;
            CheckTrigForce();
            CheckTown();
          }
        }
        if ( pcurs == 2 )
        {
          pcursobj = -1;
          pcursmonst = -1;
          pcursitem = -1;
          cursmx = Xdungx;
          cursmy = Xdungy;
        }
        if ( pcursmonst != -1 )
        {
          if ( monster[pcursmonst]._mFlags & 0x20 )
            pcursmonst = -1;
        }
        return;
      }
    }
  }
}

//----- (00487CAA) --------------------------------------------------------
void __cdecl scrollrt_draw_cursor_back_buffer()
{
  char *v0; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  unsigned __int8 *v2; // [esp+14h] [ebp-4h]

  if ( cursor_dword_647724_buf1 )
  {
    v2 = (unsigned __int8 *)cursor_dword_647724_buf1;
    v0 = sgSaveBack;
    gpBufEnd = (unsigned __int8 *)&gpBuffer[screen_y_times_768[640] - 2 - cursW];
    for ( i = 0; cursH + 2 > i && gpBufEnd > (unsigned __int8 *)v0 && gpBufEnd > v2; ++i )
    {
      memcpy(v2, v0, cursW + 2);
      v0 += cursW + 2;
      v2 += 768;
    }
    cursor_dword_647724_buf1 = 0;
  }
}

//----- (00487D71) --------------------------------------------------------
void __cdecl scrollrt_draw_cursor_item()
{
  char *v0; // [esp+Ch] [ebp-20h]
  int i; // [esp+10h] [ebp-1Ch]
  int v2; // [esp+14h] [ebp-18h]
  signed int colour; // [esp+18h] [ebp-14h]
  int v4; // [esp+1Ch] [ebp-10h]
  char *v5; // [esp+20h] [ebp-Ch]
  int v6; // [esp+24h] [ebp-8h]
  int v7; // [esp+28h] [ebp-4h]

  v4 = cursW + 2;
  v2 = cursH + 2;
  sgdwCursX = MouseX - 1;
  if ( MouseX - 1 < 0 )
    sgdwCursX = 0;
  sgdwCursY = MouseY - 1;
  if ( MouseY - 1 < 0 )
    sgdwCursY = 0;
  cursor_dword_645768_W = 639 - sgdwCursX;
  if ( 639 - sgdwCursX <= v4 )
  {
    if ( cursor_dword_645768_W < 0 )
      cursor_dword_645768_W = 0;
  }
  else
  {
    cursor_dword_645768_W = cursW + 2;
  }
  cursor_dword_64576C_H = 479 - sgdwCursY;
  if ( 479 - sgdwCursY <= v2 )
  {
    if ( cursor_dword_64576C_H < 0 )
      cursor_dword_64576C_H = 0;
  }
  else
  {
    cursor_dword_64576C_H = cursH + 2;
  }
  cursor_dword_647724_buf1 = (int)&gpBuffer[768 * (sgdwCursY + 160) + 64 + sgdwCursX];
  cursor_dword_645724_buf2 = (int)&gpBuffer[768 * (sgdwCursY + 160) + 64 + sgdwCursX];
  v0 = &gpBuffer[768 * (sgdwCursY + 160) + 64 + sgdwCursX];
  v5 = sgSaveBack;
  gpBufEnd = (unsigned __int8 *)&gpBuffer[screen_y_times_768[640] - v4];
  for ( i = 0; v2 > i && v0 < (char *)gpBufEnd; ++i )
  {
    memcpy(v5, v0, v4);
    v5 += v4;
    v0 += 768;
  }
  v7 = sgdwCursX + 1;
  v6 = sgdwCursY + 1;
  if ( pcurs < 12 )
  {
    Cel2DrawHdrOnly(sgdwCursX + 65, cursH + v6 + 159, pCursCels, pcurs, cursW, 0, 8);
  }
  else
  {
    colour = 197;
    if ( plr[myplr].HoldItem._iMagical )
      colour = 181;
    if ( !plr[myplr].HoldItem._iStatFlag )
      colour = 229;
    CelDrawHdrClrHL(colour, sgdwCursX + 65, v6 + cursH + 159, pCursCels, pcurs, cursW, 0, 8);
    if ( colour == 229 )
      Cel2DrawHdrLightRed(v7 + 64, cursH + v6 + 159, pCursCels, pcurs, cursW, 0, 8, 1);
    else
      Cel2DrawHdrOnly(v7 + 64, cursH + v6 + 159, pCursCels, pcurs, cursW, 0, 8);
    ClearPanel();
    if ( !plr[myplr].HoldItem._iStatFlag )
      AddPanelString("Requirements not met", 1);
    pinfoflag = 1;
  }
}

