//----- (004129D0) --------------------------------------------------------
void __cdecl j_minitext_4129E5_init_qtexts()
{
  minitext_4129E5_init_qtexts();
}

//----- (004129E5) --------------------------------------------------------
void __cdecl minitext_4129E5_init_qtexts()
{
  Xqtexts[0] = off_4BB308[0];
  Xqtexts[1] = off_4BB328[0];
  Xqtexts[2] = off_4BB338[0];
  Xqtexts[3] = off_4BB340[0];
  Xqtexts[4] = off_4BB34C[0];
  Xqtexts[5] = off_4BB350;
  Xqtexts[6] = off_4BB358[0];
  Xqtexts[7] = off_4BB370[0];
  Xqtexts[8] = off_4BB380[0];
  Xqtexts[9] = off_4BB390[0];
  Xqtexts[10] = off_4BB3A0;
  Xqtexts[11] = off_4BB3A8[0];
  Xqtexts[12] = off_4BB3B0[0];
  Xqtexts[13] = off_4BB3D8[0];
  Xqtexts[14] = off_4BB3E8[0];
  Xqtexts[15] = off_4BB3F0[0];
  Xqtexts[16] = off_4BB3F8[0];
  Xqtexts[17] = off_4BB400[0];
  Xqtexts[18] = off_4BB408[0];
  Xqtexts[19] = off_4BB410[0];
  Xqtexts[20] = off_4BB414[0];
  Xqtexts[21] = off_4BB418[0];
  Xqtexts[22] = off_4BB41C[0];
  Xqtexts[23] = off_4BB420[0];
  Xqtexts[24] = off_4BB430[0];
  Xqtexts[25] = off_4BB438[0];
  Xqtexts[26] = off_4BB448[0];
}

//----- (00412B03) --------------------------------------------------------
void __cdecl FreeQuestText()
{
  mem_free_dbg(pMedTextCels, 681, "C:\\Diablo\\Direct\\minitext.cpp");
  pMedTextCels = 0;
  mem_free_dbg(pTextBoxCels, 683, "C:\\Diablo\\Direct\\minitext.cpp");
  pTextBoxCels = 0;
}

//----- (00412B51) --------------------------------------------------------
void __cdecl InitQuestText()
{
  if ( pMedTextCels )
    assertion_failed(691, "C:\\Diablo\\Direct\\minitext.cpp");
  pMedTextCels = LoadFileInMem("Data\\MedTextS.CEL", 0, 692, "C:\\Diablo\\Direct\\minitext.cpp");
  pTextBoxCels = LoadFileInMem("Data\\TextBox.CEL", 0, 693, "C:\\Diablo\\Direct\\minitext.cpp");
  qtextflag = 0;
}

//----- (00412BC2) --------------------------------------------------------
void __fastcall InitQTextMsg(int m)
{
  questlog = 0;
  qtextflag = 1;
  qtextptr = Xqtexts[m];
  qtexty = 500;
  minitext_5F5C44 = 0;
  sgLastScroll = qscroll_spd_tbl[m];
}

//----- (00412C1E) --------------------------------------------------------
void __cdecl DrawQTextBack()
{
  char *v0; // edi
  signed int v1; // edx
  signed int v2; // ecx
  int v3; // edi
  signed int v4; // ecx
  _BYTE *v5; // edi
  signed int v6; // ecx

  CelDecodeOnly(88, 487, pTextBoxCels, 1, 591);
  v0 = gpBuffer + 371803;
  v1 = 148;
  do
  {
    v2 = 292;
    do
    {
      *v0 = 0;
      v0 += 2;
      --v2;
    }
    while ( v2 );
    *v0 = 0;
    v3 = (int)(v0 - 1352);
    v4 = 292;
    do
    {
      v5 = (_BYTE *)(v3 + 1);
      *v5 = 0;
      v3 = (int)(v5 + 1);
      --v4;
    }
    while ( v4 );
    v0 = (char *)(v3 - 1352);
    --v1;
  }
  while ( v1 );
  v6 = 292;
  do
  {
    *v0 = 0;
    v0 += 2;
    --v6;
  }
  while ( v6 );
  *v0 = 0;
}

//----- (00412C8D) --------------------------------------------------------
void __fastcall PrintQTextChr(int screen_x, int screen_y, char *cel_buf, int frame)
{
  char *v4; // ebx
  char *v5; // esi
  char *v6; // edi
  int v7; // ebx
  signed int v8; // edx
  unsigned int v9; // eax
  unsigned int v10; // ecx
  char v11; // cf
  unsigned int v12; // ecx
  char *v13; // [esp+1Ch] [ebp-8h]
  char *v14; // [esp+20h] [ebp-4h]

  v14 = &gpBuffer[screen_y_times_768[209]];
  v13 = &gpBuffer[screen_y_times_768[469]];
  v4 = &cel_buf[4 * frame];
  v5 = &cel_buf[*(_DWORD *)v4];
  v6 = &gpBuffer[screen_x + screen_y_times_768[screen_y]];
  v7 = (int)&v5[*((_DWORD *)v4 + 1) - *(_DWORD *)v4];
  do
  {
    v8 = 22;
    do
    {
      while ( 1 )
      {
        v9 = (unsigned __int8)*v5++;
        if ( (v9 & 0x80u) == 0 )
          break;
        LOBYTE(v9) = -(char)v9;
        v6 += v9;
        v8 -= v9;
        if ( !v8 )
          goto LABEL_15;
      }
      v8 -= v9;
      if ( v6 < v14 || v6 > v13 )
      {
        v5 += v9;
        v6 += v9;
      }
      else
      {
        v10 = v9 >> 1;
        if ( !(v9 & 1) || (*v6 = *v5, ++v5, ++v6, v10) )
        {
          v11 = v10 & 1;
          v12 = v9 >> 2;
          if ( !v11 || (*(_WORD *)v6 = *(_WORD *)v5, v5 += 2, v6 += 2, v12) )
          {
            qmemcpy(v6, v5, 4 * v12);
            v5 += 4 * v12;
            v6 += 4 * v12;
          }
        }
      }
    }
    while ( v8 );
LABEL_15:
    v6 -= 790;
  }
  while ( (char *)v7 != v5 );
}

//----- (00412D69) --------------------------------------------------------
void __cdecl DrawQText()
{
  int screen_x; // [esp+Ch] [ebp-A4h]
  signed int v1; // [esp+10h] [ebp-A0h]
  char *v2; // [esp+14h] [ebp-9Ch]
  int v3; // [esp+18h] [ebp-98h]
  int i; // [esp+18h] [ebp-98h]
  char *v5; // [esp+1Ch] [ebp-94h]
  char qstr[128]; // [esp+20h] [ebp-90h]
  char v7; // [esp+A0h] [ebp-10h]
  int v8; // [esp+A4h] [ebp-Ch]
  char *v9; // [esp+A8h] [ebp-8h]
  int screen_y; // [esp+ACh] [ebp-4h]

  DrawQTextBack();
  v9 = qtextptr;
  v5 = 0;
  screen_x = 112;
  screen_y = qtexty;
  v8 = 0;
  while ( !v8 )
  {
    v1 = 0;
    v2 = v9;
    v3 = 0;
    while ( *v2 != 124 && v1 < 543 )
    {
      v7 = *v2++;
      if ( v7 )
      {
        qstr[v3] = v7;
        v7 = mfontframe[v7];
        v1 += mfontkern[v7] + 2;
      }
      else
      {
        --v3;
      }
      ++v3;
    }
    qstr[v3] = 0;
    if ( *v2 == 124 )
    {
      qstr[v3] = 0;
      v8 = 1;
    }
    else
    {
      while ( qstr[v3] != 32 && v3 > 0 )
        qstr[v3--] = 0;
    }
    for ( i = 0; qstr[i]; ++i )
    {
      v7 = mfontframe[qstr[i]];
      while ( !*v9 )
        ++v9;
      ++v9;
      if ( v7 )
        PrintQTextChr(screen_x, screen_y, (char *)pMedTextCels, v7);
      screen_x += mfontkern[v7] + 2;
    }
    if ( !v5 )
      v5 = v9;
    screen_x = 112;
    screen_y += 38;
    if ( screen_y > 501 )
      v8 = 1;
  }
  --qtexty;
  if ( sgLastScroll )
  {
    minitext_5F5C44 = ((_BYTE)minitext_5F5C44 - 1) & 1;
    if ( !minitext_5F5C44 )
      --qtexty;
  }
  if ( qtexty <= 209 )
  {
    qtexty += 38;
    qtextptr = v5;
    if ( *v5 == 124 )
      qtextflag = 0;
  }
}

