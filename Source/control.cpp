//----- (00414980) --------------------------------------------------------
void __fastcall DrawSpellCel(int xp, int yp, char *Trans, int nCel, int w)
{
  char *v5; // ebx
  char *v6; // esi
  char *v7; // edi
  int v9; // edx
  unsigned int v10; // eax
  unsigned int v11; // ecx
  char v14; // cf
  unsigned int v15; // ecx
  int v18; // [esp+1Ch] [ebp-4h]

  v5 = &Trans[4 * nCel];
  v6 = &Trans[*(_DWORD *)v5];
  v7 = &gpBuffer[xp + screen_y_times_768[yp]];
  v18 = (int)&v6[*((_DWORD *)v5 + 1) - *(_DWORD *)v5];
  _EBX = Xspelltrans;
  do
  {
    v9 = w;
    do
    {
      while ( 1 )
      {
        v10 = (unsigned __int8)*v6++;
        if ( (v10 & 0x80u) == 0 )
          break;
        LOBYTE(v10) = -(char)v10;
        v7 += v10;
        v9 -= v10;
        if ( !v9 )
          goto LABEL_12;
      }
      v9 -= v10;
      v11 = v10 >> 1;
      if ( v10 & 1 )
      {
        _AL = *v6++;
        __asm { xlat }
        *v7++ = _AL;
        if ( !v11 )
          continue;
      }
      v14 = v11 & 1;
      v15 = v11 >> 1;
      if ( !v14 )
        goto LABEL_15;
      _AX = *(_WORD *)v6;
      v6 += 2;
      __asm { xlat }
      _AX = __ROR2__(_AX, 8);
      __asm { xlat }
      *(_WORD *)v7 = __ROR2__(_AX, 8);
      v7 += 2;
      if ( v15 )
      {
LABEL_15:
        do
        {
          _EAX = *(_DWORD *)v6;
          v6 += 4;
          __asm { xlat }
          _EAX = __ROR4__(_EAX, 8);
          __asm { xlat }
          _EAX = __ROR4__(_EAX, 8);
          __asm { xlat }
          _EAX = __ROR4__(_EAX, 8);
          __asm { xlat }
          *(_DWORD *)v7 = __ROR4__(_EAX, 8);
          v7 += 4;
          --v15;
        }
        while ( v15 );
      }
    }
    while ( v9 );
LABEL_12:
    v7 = &v7[-w - 768];
  }
  while ( v6 != (char *)v18 );
}

//----- (00414A54) --------------------------------------------------------
void __fastcall SetSpellTrans(char t)
{
  signed int i; // [esp+14h] [ebp-4h]
  signed int j; // [esp+14h] [ebp-4h]
  signed int k; // [esp+14h] [ebp-4h]
  signed int m; // [esp+14h] [ebp-4h]
  signed int l; // [esp+14h] [ebp-4h]
  signed int n; // [esp+14h] [ebp-4h]

  if ( !t )
  {
    for ( i = 0; i < 128; ++i )
      Xspelltrans[i] = i;
  }
  for ( j = 128; j < 256; ++j )
    Xspelltrans[j] = j;
  Xspelltrans[255] = 0;
  switch ( t )
  {
    case 1:
      Xspelltrans[144] = -79;
      Xspelltrans[145] = -77;
      Xspelltrans[146] = -75;
      for ( k = 176; k < 192; ++k )
      {
        Xspelltrans[k - 16] = k;
        Xspelltrans[k + 16] = k;
        Xspelltrans[k + 32] = k;
      }
      break;
    case 2:
      Xspelltrans[144] = -95;
      Xspelltrans[145] = -93;
      Xspelltrans[146] = -91;
      for ( l = 160; l < 176; ++l )
      {
        Xspelltrans[l + 32] = l;
        Xspelltrans[l + 48] = l;
      }
      break;
    case 3:
      Xspelltrans[144] = -47;
      Xspelltrans[145] = -45;
      Xspelltrans[146] = -43;
      for ( m = 208; m < 224; ++m )
      {
        Xspelltrans[m - 48] = m;
        Xspelltrans[m - 16] = m;
      }
      break;
    case 4:
      Xspelltrans[144] = -15;
      Xspelltrans[145] = -13;
      Xspelltrans[146] = -11;
      for ( n = 240; n < 255; ++n )
      {
        Xspelltrans[n - 80] = n;
        Xspelltrans[n - 48] = n;
        Xspelltrans[n - 32] = n;
      }
      Xspelltrans[175] = 0;
      Xspelltrans[207] = 0;
      Xspelltrans[223] = 0;
      break;
    default:
      return;
  }
}

//----- (00414C88) --------------------------------------------------------
void __cdecl DrawSpell()
{
  int v0; // [esp+Ch] [ebp-Ch]
  char st; // [esp+10h] [ebp-8h]
  char v2; // [esp+14h] [ebp-4h]

  st = plr[myplr]._pRSplType;
  v2 = plr[myplr]._pRSpell;
  v0 = plr[myplr]._pISplLvlAdd + plr[myplr]._pSplLvl[v2];
  if ( st == 1 && v2 != -1 )
  {
    if ( !CheckSpell(myplr, v2, st, 1) )
      st = 4;
    if ( v0 <= 0 )
      st = 4;
  }
  if ( !currlevel )
    st = 4;
  SetSpellTrans(st);
  if ( v2 == -1 )
    DrawSpellCel(629, 631, Trans, 27, 56);
  else
    DrawSpellCel(629, 631, Trans, SpellITbl[v2], 56);
}

//----- (00414DDC) --------------------------------------------------------
void __cdecl DrawSpellList()
{
  QWORD v0; // [esp+14h] [ebp-3Ch]
  signed __int64 v1; // [esp+1Ch] [ebp-34h]
  signed int i; // [esp+24h] [ebp-2Ch]
  int yp; // [esp+28h] [ebp-28h]
  signed int j; // [esp+2Ch] [ebp-24h]
  int xp; // [esp+30h] [ebp-20h]
  int nCel; // [esp+34h] [ebp-1Ch]
  int v7; // [esp+38h] [ebp-18h]
  int v8; // [esp+3Ch] [ebp-14h]
  int k; // [esp+40h] [ebp-10h]
  signed int l; // [esp+40h] [ebp-10h]
  int v11; // [esp+44h] [ebp-Ch]
  signed int m; // [esp+4Ch] [ebp-4h]

  xp = 636;
  yp = 495;
  pSpell = -1;
  infostr[0] = 0;
  for ( i = 0; i < 4; ++i )
  {
    switch ( i )
    {
      case 0:
        SetSpellTrans(0);
        v0 = plr[myplr]._pAblSpells;
        nCel = 46;
        break;
      case 1:
        v0 = plr[myplr]._pMemSpells;
        nCel = 47;
        break;
      case 2:
        SetSpellTrans(2);
        v0 = plr[myplr]._pScrlSpells;
        nCel = 44;
        break;
      case 3:
        SetSpellTrans(3);
        v0 = plr[myplr]._pISpells;
        nCel = 45;
        break;
      default:
        break;
    }
    v1 = 1i64;
    for ( j = 1; j < 37; ++j )
    {
      if ( v1 & v0 )
      {
        if ( i == 1 )
        {
          v7 = plr[myplr]._pISplLvlAdd + plr[myplr]._pSplLvl[j];
          if ( v7 < 0 )
            v7 = 0;
          if ( v7 <= 0 )
            SetSpellTrans(4);
          else
            SetSpellTrans(1);
        }
        DrawSpellCel(xp, yp, Trans, SpellITbl[j], 56);
        v8 = yp - 216;
        if ( MouseX >= xp - 64 && xp - 64 + 56 > MouseX && v8 <= MouseY && v8 + 56 > MouseY )
        {
          pSpell = j;
          pSplType = i;
          DrawSpellCel(xp, yp, Trans, nCel, 56);
          ClearPanel();
          switch ( i )
          {
            case 0:
              sprintf(infostr, "%s Skill", spelldata[pSpell].sSkillText);
              break;
            case 1:
              sprintf(infostr, "%s Spell", spelldata[pSpell].sNameText);
              if ( v7 )
                sprintf(tempstr, "Spell Level %i", v7);
              else
                sprintf(tempstr, "Spell Level 0 - Unusable");
              AddPanelString(tempstr, 1);
              break;
            case 2:
              sprintf(infostr, "Scroll of %s", spelldata[pSpell].sNameText);
              v11 = 0;
              for ( k = 0; plr[myplr]._pNumInv > k; ++k )
              {
                if ( plr[myplr].InvList[k]._itype != -1
                  && (plr[myplr].InvList[k]._iMiscId == 21 || plr[myplr].InvList[k]._iMiscId == 22)
                  && plr[myplr].InvList[k]._iSpell == pSpell )
                {
                  ++v11;
                }
              }
              for ( l = 0; l < 8; ++l )
              {
                if ( plr[myplr].SpdList[l]._itype != -1
                  && (plr[myplr].SpdList[l]._iMiscId == 21 || plr[myplr].SpdList[l]._iMiscId == 22)
                  && plr[myplr].SpdList[l]._iSpell == pSpell )
                {
                  ++v11;
                }
              }
              if ( v11 == 1 )
                strcpy(tempstr, "1 Scroll");
              else
                sprintf(tempstr, "%i Scrolls", v11);
              AddPanelString(tempstr, 1);
              break;
            case 3:
              sprintf(infostr, "Staff of %s", spelldata[pSpell].sNameText);
              if ( plr[myplr].InvBody[4]._iCharges == 1 )
                strcpy(tempstr, "1 Charge");
              else
                sprintf(tempstr, "%i Charges", plr[myplr].InvBody[4]._iCharges);
              AddPanelString(tempstr, 1);
              break;
            default:
              break;
          }
          for ( m = 0; m < 4; ++m )
          {
            if ( plr[myplr]._pSplHotKey[m] == pSpell && plr[myplr]._pSplTHotKey[m] == pSplType )
            {
              DrawSpellCel(xp, yp, Trans, m + 48, 56);
              sprintf(tempstr, "Spell Hot Key #F%i", m + 5);
              AddPanelString(tempstr, 1);
            }
          }
        }
        xp -= 56;
        if ( xp == 20 )
        {
          xp = 636;
          yp -= 56;
        }
      }
      v1 *= 2i64;
    }
    if ( v0 && xp != 636 )
      xp -= 56;
    if ( xp == 20 )
    {
      xp = 636;
      yp -= 56;
    }
  }
}

//----- (004155FB) --------------------------------------------------------
void __cdecl SetSpell()
{
  spselflag = 0;
  if ( pSpell != -1 )
  {
    plr[myplr]._pRSpell = pSpell;
    plr[myplr]._pRSplType = pSplType;
    DrawSpell();
    drawpanflag = 255;
  }
}

//----- (0041567B) --------------------------------------------------------
void __fastcall SetSpeedSpell(int slot)
{
  signed int i; // [esp+10h] [ebp-4h]

  if ( pSpell != -1 )
  {
    for ( i = 0; i < 4; ++i )
    {
      if ( plr[myplr]._pSplHotKey[i] == pSpell && plr[myplr]._pSplTHotKey[i] == pSplType )
        plr[myplr]._pSplHotKey[i] = -1;
    }
    plr[myplr]._pSplHotKey[slot] = pSpell;
    plr[myplr]._pSplTHotKey[slot] = pSplType;
  }
}

//----- (00415798) --------------------------------------------------------
void __fastcall ToggleSpell(int slot)
{
  __int64 v1; // rax
  int v2; // [esp+14h] [ebp-8h]
  int v3; // [esp+14h] [ebp-8h]
  int v4; // [esp+18h] [ebp-4h]

  if ( plr[myplr]._pSplHotKey[slot] != -1 )
  {
    switch ( plr[myplr]._pSplTHotKey[slot] )
    {
      case 0:
        v2 = plr[myplr]._pAblSpells;
        v4 = HIDWORD(plr[myplr]._pAblSpells);
        break;
      case 1:
        v2 = plr[myplr]._pMemSpells;
        v4 = HIDWORD(plr[myplr]._pMemSpells);
        break;
      case 2:
        v2 = plr[myplr]._pScrlSpells;
        v4 = HIDWORD(plr[myplr]._pScrlSpells);
        break;
      case 3:
        v2 = plr[myplr]._pISpells;
        v4 = HIDWORD(plr[myplr]._pISpells);
        break;
      default:
        break;
    }
    v1 = 1 << (LOBYTE(plr[myplr]._pSplHotKey[slot]) - 1);
    v3 = v1 & v2;
    if ( HIDWORD(v1) & v4 || v3 )
    {
      plr[myplr]._pRSpell = plr[myplr]._pSplHotKey[slot];
      plr[myplr]._pRSplType = plr[myplr]._pSplTHotKey[slot];
      DrawSpell();
      drawpanflag = 255;
    }
  }
}

//----- (004159E0) --------------------------------------------------------
void __fastcall CPrintString(int No, char frame, char Just)
{
  _DWORD *v3; // ebx
  BYTE *v4; // esi
  char *v5; // edi
  BYTE *v6; // ebx
  signed int v7; // edx
  unsigned int v8; // eax
  unsigned int v9; // ecx
  char v10; // cf
  unsigned int v11; // ecx
  signed int v12; // edx
  int v13; // eax
  int v14; // ecx
  BYTE v15; // al
  signed int v16; // edx
  int v17; // eax
  int v18; // ecx
  char v19; // al
  signed int v20; // edx
  int v21; // eax
  int v22; // ecx
  char v23; // al

  v3 = (char *)pPanelText + 4 * frame;
  v4 = (BYTE *)pPanelText + *v3;
  v5 = &gpBuffer[No];
  v6 = &v4[v3[1] - *v3];
  if ( Just )
  {
    if ( Just == 1 )
    {
      do
      {
        v12 = 13;
        do
        {
          while ( 1 )
          {
            v13 = *v4++;
            if ( (v13 & 0x80u) == 0 )
              break;
            LOBYTE(v13) = -(char)v13;
            v5 += v13;
            v12 -= v13;
            if ( !v12 )
              goto LABEL_28;
          }
          v12 -= v13;
          v14 = v13;
          do
          {
            v15 = *v4++;
            if ( v15 > 0xFDu )
            {
              v15 = -65;
            }
            else if ( v15 >= 0xF0u )
            {
              v15 -= 62;
            }
            *v5++ = v15;
            --v14;
          }
          while ( v14 );
        }
        while ( v12 );
LABEL_28:
        v5 -= 781;
      }
      while ( v6 != v4 );
    }
    else if ( Just == 2 )
    {
      do
      {
        v16 = 13;
        do
        {
          while ( 1 )
          {
            v17 = *v4++;
            if ( (v17 & 0x80u) == 0 )
              break;
            LOBYTE(v17) = -(char)v17;
            v5 += v17;
            v16 -= v17;
            if ( !v16 )
              goto LABEL_39;
          }
          v16 -= v17;
          v18 = v17;
          do
          {
            v19 = *v4++;
            if ( (unsigned __int8)v19 >= 0xF0u )
              v19 -= 16;
            *v5++ = v19;
            --v18;
          }
          while ( v18 );
        }
        while ( v16 );
LABEL_39:
        v5 -= 781;
      }
      while ( v6 != v4 );
    }
    else
    {
      do
      {
        v20 = 13;
        do
        {
          while ( 1 )
          {
            v21 = *v4++;
            if ( (v21 & 0x80u) == 0 )
              break;
            LOBYTE(v21) = -(char)v21;
            v5 += v21;
            v20 -= v21;
            if ( !v20 )
              goto LABEL_52;
          }
          v20 -= v21;
          v22 = v21;
          do
          {
            v23 = *v4++;
            if ( (unsigned __int8)v23 >= 0xF0u )
            {
              if ( (unsigned __int8)v23 >= 0xFEu )
                v23 = -49;
              else
                v23 -= 46;
            }
            *v5++ = v23;
            --v22;
          }
          while ( v22 );
        }
        while ( v20 );
LABEL_52:
        v5 -= 781;
      }
      while ( v6 != v4 );
    }
  }
  else
  {
    do
    {
      v7 = 13;
      do
      {
        while ( 1 )
        {
          v8 = *v4++;
          if ( (v8 & 0x80u) == 0 )
            break;
          LOBYTE(v8) = -(char)v8;
          v5 += v8;
          v7 -= v8;
          if ( !v7 )
            goto LABEL_15;
        }
        v7 -= v8;
        v9 = v8 >> 1;
        if ( v8 & 1 )
        {
          *v5++ = *v4++;
          if ( !v9 )
            continue;
        }
        v10 = v9 & 1;
        v11 = v8 >> 2;
        if ( v10 )
        {
          *(_WORD *)v5 = *(_WORD *)v4;
          v4 += 2;
          v5 += 2;
          if ( !v11 )
            continue;
        }
        qmemcpy(v5, v4, 4 * v11);
        v4 += 4 * v11;
        v5 += 4 * v11;
      }
      while ( v7 );
LABEL_15:
      v5 -= 781;
    }
    while ( v6 != v4 );
  }
}

//----- (00415BA4) --------------------------------------------------------
void __fastcall AddPanelString(char *str, int just)
{
  strcpy(panelstr[pnumlines], str);
  pstrjust[pnumlines] = just;
  if ( pnumlines < 4 )
    ++pnumlines;
}

//----- (00415BFA) --------------------------------------------------------
void __cdecl ClearPanel()
{
  pnumlines = 0;
  pinfoflag = 0;
}

//----- (00415C1E) --------------------------------------------------------
void __fastcall DrawPanelBox(int x, int y, WORD w, WORD h, int sx, int sy)
{
  char *v6; // esi
  char *v7; // edi
  int v8; // edx
  unsigned int v9; // ecx
  char v10; // cf
  unsigned int v11; // ecx

  v6 = &pBtmBuff[640 * y + x];
  v7 = &gpBuffer[768 * sy + sx];
  v8 = h;
  do
  {
    v9 = (unsigned int)w >> 1;
    if ( !(w & 1) || (*v7 = *v6, ++v6, ++v7, v9) )
    {
      v10 = v9 & 1;
      v11 = (unsigned int)w >> 2;
      if ( !v10 || (*(_WORD *)v7 = *(_WORD *)v6, v6 += 2, v7 += 2, v11) )
      {
        qmemcpy(v7, v6, 4 * v11);
        v6 += 4 * v11;
        v7 += 4 * v11;
      }
    }
    v6 = &v6[-w + 640];
    v7 = &v7[-w + 768];
    --v8;
  }
  while ( v8 );
}

//----- (00415CA7) --------------------------------------------------------
void j_ClearPanel()
{
  ClearPanel();
}

//----- (00415CBC) --------------------------------------------------------
void __fastcall SetFlaskHeight(char *buf, int min, int max, int c, int r)
{
  char *v5; // esi
  char *v6; // edi
  int v7; // edx

  v5 = &buf[88 * min];
  v6 = &gpBuffer[768 * r + c];
  v7 = max - min;
  do
  {
    qmemcpy(v6, v5, 88u);
    v5 += 88;
    v6 += 768;
    --v7;
  }
  while ( v7 );
}

//----- (00415D26) --------------------------------------------------------
void __fastcall DrawFlask(char *Xbuf, int a2, int Xbufof, char *Xgbuf, int Xgbufoffset, int a6)
{
  char *v6; // esi
  char *v7; // edi
  int v8; // edx
  signed int v9; // ecx
  char v10; // al

  v6 = &Xbuf[Xbufof];
  v7 = &Xgbuf[Xgbufoffset];
  v8 = a6;
  do
  {
    for (v9 = 59; v9; --v9)
    {
      v10 = *v6++;
      if ( v10 )
        *v7 = v10;
      ++v7;
    }
    v6 = &v6[a2 - 59];
    v7 += 709;
    --v8;
  }
  while ( v8 );
}

//----- (00415D76) --------------------------------------------------------
void __cdecl DrawLifeFlask()
{
  int a6; // [esp+Ch] [ebp-4h]
  int a6a; // [esp+Ch] [ebp-4h]

  a6 = 80 - plr[myplr]._pHPPer;
  if ( a6 > 11 )
    a6 = 11;
  a6a = a6 + 2;
  DrawFlask(pLifeBuff, 88, 277, gpBuffer, 383405, a6a);
  if ( a6a != 13 )
    DrawFlask(pBtmBuff, 640, 640 * a6a + 2029, gpBuffer, 768 * a6a + 383405, 13 - a6a);
}

//----- (00415E31) --------------------------------------------------------
void __cdecl UpdateLifeFlask()
{
  signed int h; // [esp+14h] [ebp-Ch]

  h = (signed __int64)((double)plr[myplr]._pHitPoints / (double)plr[myplr]._pMaxHP * 80.0);
  plr[myplr]._pHPPer = h;
  if ( h > 69 )
    h = 69;
  if ( h != 69 )
    SetFlaskHeight(pLifeBuff, 16, 85 - h, 160, 512);
  if ( h )
    DrawPanelBox(96, 85 - h, 88u, h, 160, 581 - h);
}

//----- (00415F34) --------------------------------------------------------
void __cdecl DrawManaFlask()
{
  int a6; // [esp+Ch] [ebp-4h]
  int a6a; // [esp+Ch] [ebp-4h]

  a6 = 80 - plr[myplr]._pManaPer;
  if ( a6 > 11 )
    a6 = 11;
  a6a = a6 + 2;
  DrawFlask(pManaBuff, 88, 277, gpBuffer, 383771, a6a);
  if ( a6a != 13 )
    DrawFlask(pBtmBuff, 640, 640 * a6a + 2395, gpBuffer, 768 * a6a + 383771, 13 - a6a);
}

//----- (00415FEF) --------------------------------------------------------
void __cdecl control_update_life_mana()
{
  int v0; // [esp+1Ch] [ebp-14h]
  int v1; // [esp+20h] [ebp-10h]
  int v2; // [esp+24h] [ebp-Ch]

  v2 = plr[myplr]._pMaxMana;
  v0 = plr[myplr]._pMana;
  if ( v2 < 0 )
    v2 = 0;
  if ( v0 < 0 )
    v0 = 0;
  if ( v2 )
    v1 = (signed __int64)((double)v0 / (double)v2 * 80.0);
  else
    v1 = 0;
  plr[myplr]._pManaPer = v1;
  plr[myplr]._pHPPer = (signed __int64)((double)plr[myplr]._pHitPoints / (double)plr[myplr]._pMaxHP * 80.0);
}

//----- (00416146) --------------------------------------------------------
void __cdecl UpdateManaFlask()
{
  int v0; // [esp+14h] [ebp-14h]
  signed int h; // [esp+18h] [ebp-10h]
  int v2; // [esp+1Ch] [ebp-Ch]

  v2 = plr[myplr]._pMaxMana;
  v0 = plr[myplr]._pMana;
  if ( v2 < 0 )
    v2 = 0;
  if ( v0 < 0 )
    v0 = 0;
  if ( v2 )
    h = (signed __int64)((double)v0 / (double)v2 * 80.0);
  else
    h = 0;
  plr[myplr]._pManaPer = h;
  if ( h > 69 )
    h = 69;
  if ( h != 69 )
    SetFlaskHeight(pManaBuff, 16, 85 - h, 528, 512);
  if ( h )
    DrawPanelBox(464, 85 - h, 0x58u, h, 528, 581 - h);
  DrawSpell();
}

//----- (00416292) --------------------------------------------------------
void __cdecl InitControlPan()
{
  signed int i; // [esp+Ch] [ebp-4h]
  signed int j; // [esp+Ch] [ebp-4h]
  signed int k; // [esp+Ch] [ebp-4h]

  if ( pBtmBuff )
    assertion_failed(1016, "C:\\Diablo\\Direct\\CONTROL.CPP");
  if ( gbMaxPlayers == 1 )
  {
    pBtmBuff = (char *)DiabloAllocPtr(0x16800, 1018, "C:\\Diablo\\Direct\\CONTROL.CPP");
    memset(pBtmBuff, 0, 0x16800u);
  }
  else
  {
    pBtmBuff = (char *)DiabloAllocPtr(0x2D000, 1021, "C:\\Diablo\\Direct\\CONTROL.CPP");
    memset(pBtmBuff, 0, 0x2D000u);
  }
  pManaBuff = (char *)DiabloAllocPtr(0x1E40, 1024, "C:\\Diablo\\Direct\\CONTROL.CPP");
  memset(pManaBuff, 0, 0x1E40u);
  pLifeBuff = (char *)DiabloAllocPtr(0x1E40, 1026, "C:\\Diablo\\Direct\\CONTROL.CPP");
  memset(pLifeBuff, 0, 0x1E40u);
  pPanelText = LoadFileInMem("CtrlPan\\SmalText.CEL", 0, 1028, "C:\\Diablo\\Direct\\CONTROL.CPP");
  pChrPanel = LoadFileInMem("Data\\Char.CEL", 0, 1029, "C:\\Diablo\\Direct\\CONTROL.CPP");
  Trans = (char *)LoadFileInMem("CtrlPan\\SpelIcon.CEL", 0, 1030, "C:\\Diablo\\Direct\\CONTROL.CPP");
  SetSpellTrans(0);
  pStatusPanel = (char *)LoadFileInMem("CtrlPan\\Panel8.CEL", 0, 1034, "C:\\Diablo\\Direct\\CONTROL.CPP");
  CelDecodeRect(pBtmBuff, 0, 143, 640, pStatusPanel, 1, 640);
  mem_free_dbg(pStatusPanel, 1036, "C:\\Diablo\\Direct\\CONTROL.CPP");
  pStatusPanel = (char *)LoadFileInMem("CtrlPan\\P8Bulbs.CEL", 0, 1037, "C:\\Diablo\\Direct\\CONTROL.CPP");
  CelDecodeRect(pLifeBuff, 0, 87, 88, pStatusPanel, 1, 88);
  CelDecodeRect(pManaBuff, 0, 87, 88, pStatusPanel, 2, 88);
  mem_free_dbg(pStatusPanel, 1040, "C:\\Diablo\\Direct\\CONTROL.CPP");
  if ( gbMaxPlayers != 1 )
  {
    pTalkPanel = (char *)LoadFileInMem("CtrlPan\\TalkPanl.CEL", 0, 1042, "C:\\Diablo\\Direct\\CONTROL.CPP");
    CelDecodeRect(pBtmBuff, 0, 287, 640, pTalkPanel, 1, 640);
    mem_free_dbg(pTalkPanel, 1044, "C:\\Diablo\\Direct\\CONTROL.CPP");
    pMultiBtns = LoadFileInMem("CtrlPan\\P8But2.CEL", 0, 1045, "C:\\Diablo\\Direct\\CONTROL.CPP");
    talkflag = 0;
    sgbPlrTalkTbl = 0;
    sgszTalkMsg[0] = 0;
    for ( i = 0; i < 4; ++i )
      talkbtndown[i] = 1;
  }
  panelflag = 0;
  lvlbtndown = 0;
  pPanelButtons = LoadFileInMem("CtrlPan\\Panel8bu.CEL", 0, 1055, "C:\\Diablo\\Direct\\CONTROL.CPP");
  for ( j = 0; j < 8; ++j )
    panbtn[j] = 0;
  panbtndown = 0;
  if ( gbMaxPlayers == 1 )
    numpanbtns = 6;
  else
    numpanbtns = 8;
  pChrButtons = LoadFileInMem("Data\\CharBut.CEL", 0, 1061, "C:\\Diablo\\Direct\\CONTROL.CPP");
  for ( k = 0; k < 4; ++k )
    chrbtn[k] = 0;
  chrbtnactive = 0;
  pDurIcons = LoadFileInMem("Items\\DurIcons.CEL", 0, 1065, "C:\\Diablo\\Direct\\CONTROL.CPP");
  strcpy(infostr, empty_string_0);
  j_ClearPanel();
  drawmanaflag = 1;
  drawhpflag = 1;
  chrflag = 0;
  spselflag = 0;
  pSpellBkCel = LoadFileInMem("Data\\SpellBk.CEL", 0, 1074, "C:\\Diablo\\Direct\\CONTROL.CPP");
  pSBkBtnCel = LoadFileInMem("Data\\SpellBkB.CEL", 0, 1075, "C:\\Diablo\\Direct\\CONTROL.CPP");
  pSBkIconCels = (char *)LoadFileInMem("Data\\SpellI2.CEL", 0, 1076, "C:\\Diablo\\Direct\\CONTROL.CPP");
  sbooktab = 0;
  sbookflag = 0;
  if ( plr[myplr]._pClass )
  {
    if ( plr[myplr]._pClass == 1 )
    {
      SpellPages[0][0] = 28;
    }
    else if ( plr[myplr]._pClass == 2 )
    {
      SpellPages[0][0] = 27;
    }
  }
  else
  {
    SpellPages[0][0] = 26;
  }
  pQLogCel = LoadFileInMem("Data\\Quest.CEL", 0, 1083, "C:\\Diablo\\Direct\\CONTROL.CPP");
  pGBoxBuff = LoadFileInMem("CtrlPan\\Golddrop.cel", 0, 1085, "C:\\Diablo\\Direct\\CONTROL.CPP");
  dropGoldFlag = 0;
  dropGoldValue = 0;
  initialDropGoldValue = 0;
  gold_index = 0;
  frame_gold = 1;
}

//----- (00416813) --------------------------------------------------------
void __cdecl control_416813()
{
  drawmanaflag = 1;
  drawhpflag = 1;
  drawbtnflag = 1;
}

//----- (00416841) --------------------------------------------------------
void __cdecl ClearCtrlPan()
{
  DrawPanelBox(0, sgbPlrTalkTbl + 16, 0x280u, 0x80u, 64, 512);
  if ( !talkflag )
  {
    DrawSpell();
    DrawInfoBox();
  }
}

//----- (00416889) --------------------------------------------------------
void __cdecl DrawCtrlPan()
{
  int v0; // [esp+Ch] [ebp-Ch]
  int v1; // [esp+Ch] [ebp-Ch]
  signed int j; // [esp+10h] [ebp-8h]
  signed int i; // [esp+10h] [ebp-8h]

  if ( talkflag )
  {
    v0 = 0;
    for ( i = 0; i < 4; ++i )
    {
      if ( myplr != i )
      {
        if ( talkbtndown[i] )
        {
          if ( panbtn[v0] )
            CelDecodeOnly(PanBtnPos[v0][0] + 64, PanBtnPos[v0][1] + 178, pPanelButtons, 7, 71);
          else
            DrawPanelBox(
              PanBtnPos[v0][0],
              sgbPlrTalkTbl + PanBtnPos[v0][1] - 336,
              0x47u,
              0x14u,
              PanBtnPos[v0][0] + 64,
              PanBtnPos[v0][1] + 160);
        }
        else if ( panbtn[v0] )
        {
          CelDecodeOnly(PanBtnPos[v0][0] + 64, PanBtnPos[v0][1] + 178, pPanelButtons, 9, 71);
        }
        else
        {
          CelDecodeOnly(PanBtnPos[v0][0] + 64, PanBtnPos[v0][1] + 178, pPanelButtons, 8, 71);
        }
        v1 = v0 + 1;
        if ( plr[i].plractive )
        {
          if ( talkbtndown[i] )
            ADD_PlrStringXY(
              PanBtnPos[v1][0] + 3,
              PanBtnPos[v1][1] + 15,
              PanBtnPos[v1][0] + PanBtnPos[v1][2] - 3,
              plr[i]._pName,
              1);
          else
            ADD_PlrStringXY(
              PanBtnPos[v1][0] + 3,
              PanBtnPos[v1][1] + 15,
              PanBtnPos[v1][0] + PanBtnPos[v1][2] - 3,
              plr[i]._pName,
              2);
        }
        v0 = v1 + 1;
      }
    }
  }
  else
  {
    for ( j = 0; j < 6; ++j )
    {
      if ( panbtn[j] )
        CelDecodeOnly(PanBtnPos[j][0] + 64, PanBtnPos[j][1] + 178, pPanelButtons, j + 1, 71);
      else
        DrawPanelBox(PanBtnPos[j][0], PanBtnPos[j][1] - 336, 0x47u, 0x14u, PanBtnPos[j][0] + 64, PanBtnPos[j][1] + 160);
    }
  }
  if ( numpanbtns == 8 )
  {
    CelDecodeOnly(151, 634, pMultiBtns, dword_5FDBA8 + 1, 33);
    if ( FriendlyMode )
      CelDecodeOnly(591, 634, pMultiBtns, dword_5FDBAC + 3, 33);
    else
      CelDecodeOnly(591, 634, pMultiBtns, dword_5FDBAC + 5, 33);
  }
}

//----- (00416BFC) --------------------------------------------------------
void __cdecl DoSpeedBook()
{
  QWORD v0; // [esp+10h] [ebp-28h]
  signed __int64 v1; // [esp+18h] [ebp-20h]
  int Y; // [esp+20h] [ebp-18h]
  signed int i; // [esp+24h] [ebp-14h]
  int X; // [esp+28h] [ebp-10h]
  signed int v5; // [esp+2Ch] [ebp-Ch]
  signed int j; // [esp+30h] [ebp-8h]
  signed int v7; // [esp+34h] [ebp-4h]

  spselflag = 1;
  v7 = 636;
  v5 = 495;
  X = 600;
  Y = 307;
  if ( plr[myplr]._pRSpell != -1 )
  {
    for ( i = 0; i < 4; ++i )
    {
      switch ( i )
      {
        case 0:
          v0 = plr[myplr]._pAblSpells;
          break;
        case 1:
          v0 = plr[myplr]._pMemSpells;
          break;
        case 2:
          v0 = plr[myplr]._pScrlSpells;
          break;
        case 3:
          v0 = plr[myplr]._pISpells;
          break;
        default:
          break;
      }
      v1 = 1i64;
      for ( j = 0; j < 37; ++j )
      {
        if ( v1 & v0 )
        {
          if ( plr[myplr]._pRSpell - 1 == j && (char)plr[myplr]._pRSplType == i )
          {
            X = v7 - 36;
            Y = v5 - 188;
          }
          v7 -= 56;
          if ( v7 == 20 )
          {
            v7 = 636;
            v5 -= 56;
          }
        }
        v1 *= 2i64;
      }
      if ( (unsigned __int8)v0 & (v7 != 636) )
        v7 -= 56;
      if ( v7 == 20 )
      {
        v7 = 636;
        v5 -= 56;
      }
    }
  }
  SetCursorPos(X, Y);
}

//----- (00416EA2) --------------------------------------------------------
void __cdecl DoPanBtn()
{
  int i; // [esp+10h] [ebp-8h]

  for ( i = 0; numpanbtns > i; ++i )
  {
    if ( (!talkflag || PanBtnPos[i][4])
      && PanBtnPos[i][0] <= MouseX
      && MouseX <= PanBtnPos[i][0] + PanBtnPos[i][2]
      && PanBtnPos[i][1] <= MouseY
      && PanBtnPos[i][3] + PanBtnPos[i][1] >= MouseY )
    {
      panbtn[i] = 1;
      drawbtnflag = 1;
      panbtndown = 1;
    }
  }
  if ( !spselflag && MouseX >= 565 && MouseX < 621 && MouseY >= 416 && MouseY < 472 )
    DoSpeedBook();
}

//----- (00416FFB) --------------------------------------------------------
void __fastcall control_set_button_down(int btn_id)
{
  panbtn[btn_id] = 1;
  drawbtnflag = 1;
  panbtndown = 1;
}

//----- (00417033) --------------------------------------------------------
void __cdecl control_check_btn_press()
{
  int btn_id; // [esp+10h] [ebp-8h]

  if ( talkflag )
  {
    for ( btn_id = 0; btn_id < numpanbtns; ++btn_id )
    {
      if ( (!talkflag || PanBtnPos[btn_id][4])
        && PanBtnPos[btn_id][0] <= MouseX
        && MouseX <= PanBtnPos[btn_id][0] + PanBtnPos[btn_id][2]
        && PanBtnPos[btn_id][1] <= MouseY
        && PanBtnPos[btn_id][3] + PanBtnPos[btn_id][1] >= MouseY )
      {
        control_set_button_down(btn_id);
      }
    }
  }
  else
  {
    if ( PanBtnPos[3][0] <= MouseX
      && MouseX <= PanBtnPos[3][2] + PanBtnPos[3][0]
      && PanBtnPos[3][1] <= MouseY
      && PanBtnPos[3][3] + PanBtnPos[3][1] >= MouseY )
    {
      control_set_button_down(3);
    }
    if ( PanBtnPos[6][0] <= MouseX
      && MouseX <= PanBtnPos[6][0] + PanBtnPos[6][2]
      && PanBtnPos[6][1] <= MouseY
      && PanBtnPos[6][3] + PanBtnPos[6][1] >= MouseY )
    {
      control_set_button_down(6);
    }
  }
}

//----- (004171FB) --------------------------------------------------------
void __cdecl CheckPanelInfo()
{
  int i; // [esp+14h] [ebp-18h]
  int v1; // [esp+1Ch] [ebp-10h]
  int v2; // [esp+20h] [ebp-Ch]
  int v3; // [esp+24h] [ebp-8h]
  int j; // [esp+28h] [ebp-4h]
  signed int k; // [esp+28h] [ebp-4h]

  panelflag = 0;
  if ( !talkflag )
  {
    for ( i = 0; numpanbtns > i; ++i )
    {
      if ( PanBtnPos[i][0] <= MouseX
        && MouseX <= PanBtnPos[i][0] + PanBtnPos[i][2]
        && PanBtnPos[i][1] <= MouseY
        && PanBtnPos[i][3] + PanBtnPos[i][1] >= MouseY
        && !talkflag )
      {
        if ( i == 7 )
        {
          if ( FriendlyMode )
            strcpy(infostr, "Player friendly");
          else
            strcpy(infostr, "Player attack");
        }
        else
        {
          strcpy(infostr, (&off_4C0638)[i]);
        }
        infoclr = 0;
        panelflag = 1;
        pinfoflag = 1;
      }
    }
  }
  if ( !spselflag && MouseX >= 565 && MouseX < 621 && MouseY >= 416 && MouseY < 472 )
  {
    strcpy(infostr, "Select current spell button");
    infoclr = 0;
    panelflag = 1;
    pinfoflag = 1;
    ClearPanel();
    v2 = plr[myplr]._pRSpell;
    if ( v2 != -1 )
    {
      switch ( plr[myplr]._pRSplType )
      {
        case 0u:
          sprintf(tempstr, "%s Skill", spelldata[v2].sSkillText);
          AddPanelString(tempstr, 1);
          break;
        case 1u:
          sprintf(tempstr, "%s Spell", spelldata[v2].sNameText);
          AddPanelString(tempstr, 1);
          v1 = plr[myplr]._pISplLvlAdd + plr[myplr]._pSplLvl[v2];
          if ( v1 < 0 )
            v1 = 0;
          if ( v1 )
            sprintf(tempstr, "Spell Level %i", v1);
          else
            sprintf(tempstr, "Spell Level 0 - Unusable");
          AddPanelString(tempstr, 1);
          break;
        case 2u:
          sprintf(tempstr, "Scroll of %s", spelldata[v2].sNameText);
          AddPanelString(tempstr, 1);
          v3 = 0;
          for ( j = 0; plr[myplr]._pNumInv > j; ++j )
          {
            if ( plr[myplr].InvList[j]._itype != -1
              && (plr[myplr].InvList[j]._iMiscId == 21 || plr[myplr].InvList[j]._iMiscId == 22)
              && plr[myplr].InvList[j]._iSpell == v2 )
            {
              ++v3;
            }
          }
          for ( k = 0; k < 8; ++k )
          {
            if ( plr[myplr].SpdList[k]._itype != -1
              && (plr[myplr].SpdList[k]._iMiscId == 21 || plr[myplr].SpdList[k]._iMiscId == 22)
              && plr[myplr].SpdList[k]._iSpell == v2 )
            {
              ++v3;
            }
          }
          if ( v3 == 1 )
            strcpy(tempstr, "1 Scroll");
          else
            sprintf(tempstr, "%i Scrolls", v3);
          AddPanelString(tempstr, 1);
          break;
        case 3u:
          sprintf(tempstr, "Staff of %s", spelldata[v2].sNameText);
          AddPanelString(tempstr, 1);
          if ( plr[myplr].InvBody[4]._iCharges == 1 )
            strcpy(tempstr, "1 Charge");
          else
            sprintf(tempstr, "%i Charges", plr[myplr].InvBody[4]._iCharges);
          AddPanelString(tempstr, 1);
          break;
        default:
          break;
      }
    }
  }
  if ( MouseX > 190 && MouseX < 437 && MouseY > 356 && MouseY < 385 )
    pcursinvitem = CheckInvHLight();
  if ( pcursinvitem == -1 && !panelflag )
    ClearPanel();
}

//----- (0041790D) --------------------------------------------------------
void __cdecl CheckBtnUp()
{
  char v0; // [esp+14h] [ebp-8h]
  signed int i; // [esp+18h] [ebp-4h]

  v0 = 1;
  drawbtnflag = 1;
  panbtndown = 0;
  for ( i = 0; i < 8; ++i )
  {
    if ( panbtn[i] )
    {
      panbtn[i] = 0;
      if ( PanBtnPos[i][0] <= MouseX
        && PanBtnPos[i][0] + PanBtnPos[i][2] >= MouseX
        && PanBtnPos[i][1] <= MouseY
        && PanBtnPos[i][3] + PanBtnPos[i][1] >= MouseY )
      {
        if ( talkflag )
        {
          switch ( i )
          {
            case 0:
            case 2:
            case 4:
              control_41AF7D((char *)(i >> 1));
              v0 = 0;
              break;
            case 6:
              if ( talkflag )
                control_reset_talk();
              else
                control_type_message();
              v0 = 0;
              break;
            case 7:
              FriendlyMode = FriendlyMode == 0;
              break;
            default:
              continue;
          }
        }
        else
        {
          switch ( i )
          {
            case 0:
              questlog = 0;
              chrflag = chrflag == 0;
              break;
            case 1:
              chrflag = 0;
              if ( questlog )
                questlog = 0;
              else
                StartQuestlog();
              break;
            case 2:
              if ( currlevel )
              {
                if ( automapflag )
                  automapflag = 0;
                else
                  StartAutomap();
              }
              else
              {
                InitDiabloMsg(1);
              }
              break;
            case 3:
              qtextflag = 0;
              gamemenu_handle_previous();
              v0 = 0;
              break;
            case 4:
              sbookflag = 0;
              invflag = invflag == 0;
              break;
            case 5:
              invflag = 0;
              sbookflag = sbookflag == 0;
              break;
            case 6:
              if ( talkflag )
                control_reset_talk();
              else
                control_type_message();
              v0 = 0;
              break;
            case 7:
              FriendlyMode = FriendlyMode == 0;
              break;
            default:
              continue;
          }
        }
      }
    }
  }
  if ( v0 )
    gamemenu_off();
}

//----- (00417C98) --------------------------------------------------------
void __cdecl FreeControlPan()
{
  mem_free_dbg(pBtmBuff, 1457, "C:\\Diablo\\Direct\\CONTROL.CPP");
  pBtmBuff = 0;
  mem_free_dbg(pManaBuff, 1459, "C:\\Diablo\\Direct\\CONTROL.CPP");
  pManaBuff = 0;
  mem_free_dbg(pLifeBuff, 1461, "C:\\Diablo\\Direct\\CONTROL.CPP");
  pLifeBuff = 0;
  mem_free_dbg(pPanelText, 1463, "C:\\Diablo\\Direct\\CONTROL.CPP");
  pPanelText = 0;
  mem_free_dbg(pChrPanel, 1465, "C:\\Diablo\\Direct\\CONTROL.CPP");
  pChrPanel = 0;
  mem_free_dbg(Trans, 1467, "C:\\Diablo\\Direct\\CONTROL.CPP");
  Trans = 0;
  mem_free_dbg(pPanelButtons, 1469, "C:\\Diablo\\Direct\\CONTROL.CPP");
  pPanelButtons = 0;
  mem_free_dbg(pMultiBtns, 1471, "C:\\Diablo\\Direct\\CONTROL.CPP");
  pMultiBtns = 0;
  mem_free_dbg(pChrButtons, 1473, "C:\\Diablo\\Direct\\CONTROL.CPP");
  pChrButtons = 0;
  mem_free_dbg(pDurIcons, 1475, "C:\\Diablo\\Direct\\CONTROL.CPP");
  pDurIcons = 0;
  mem_free_dbg(pQLogCel, 1477, "C:\\Diablo\\Direct\\CONTROL.CPP");
  pQLogCel = 0;
  mem_free_dbg(pSpellBkCel, 1479, "C:\\Diablo\\Direct\\CONTROL.CPP");
  pSpellBkCel = 0;
  mem_free_dbg(pSBkBtnCel, 1481, "C:\\Diablo\\Direct\\CONTROL.CPP");
  pSBkBtnCel = 0;
  mem_free_dbg(pSBkIconCels, 1483, "C:\\Diablo\\Direct\\CONTROL.CPP");
  pSBkIconCels = 0;
  mem_free_dbg(pGBoxBuff, 1485, "C:\\Diablo\\Direct\\CONTROL.CPP");
  pGBoxBuff = 0;
}

//----- (00417E79) --------------------------------------------------------
int __fastcall control_WriteStringToBuffer(char *str)
{
  char v1; // ST10_1
  char *v3; // [esp+Ch] [ebp-Ch]
  signed int v4; // [esp+14h] [ebp-4h]

  v3 = str;
  v4 = 0;
  while ( *v3 )
  {
    v1 = fontframe[*v3++ & 0x7F];
    v4 += fontkern[v1];
    if ( v4 >= 288 )
      return 0;
  }
  return 1;
}

//----- (00417EE5) --------------------------------------------------------
void __cdecl DrawInfoBox()
{
  DrawPanelBox(177, 62, 0x120u, 0x3Cu, 241, 558);
  if ( !panelflag && !trigflag && pcursinvitem == -1 && !spselflag )
  {
    infostr[0] = 0;
    infoclr = 0;
  }
  if ( spselflag )
  {
    infoclr = 0;
  }
  else if ( pcurs < 12 )
  {
    if ( pcursitem != -1 )
      GetItemStr(pcursitem);
    if ( pcursobj != -1 )
      GetObjectStr(pcursobj);
    if ( pcursmonst != -1 )
    {
      if ( leveltype )
      {
        infoclr = 0;
        strcpy(infostr, monster[pcursmonst].mName);
        ClearPanel();
        if ( monster[pcursmonst]._uniqtype )
          infoclr = 3;
        else
          PrintMonstHistory(monster[pcursmonst].MType->mtype);
      }
      else
      {
        strcpy(infostr, towner[pcursmonst]._tName);
      }
    }
    if ( pcursplr != -1 )
    {
      infoclr = 3;
      strcpy(infostr, plr[pcursplr]._pName);
    }
  }
  else if ( plr[myplr].HoldItem._itype == 11 )
  {
    sprintf(infostr, "%i Gold Pieces", plr[myplr].HoldItem._ivalue);
  }
  else
  {
    if ( plr[myplr].HoldItem._iIdentified )
      strcpy(infostr, plr[myplr].HoldItem._iIName);
    else
      strcpy(infostr, plr[myplr].HoldItem._iName);
    if ( plr[myplr].HoldItem._iMagical == 1 )
      infoclr = 1;
    if ( plr[myplr].HoldItem._iMagical == 2 )
      infoclr = 3;
  }
  if ( pinfoflag && pcursmonst == -1 && pcursinvitem == -1 && pcurs < 12 )
    ClearPanel();
  if ( infostr[0] || pnumlines )
    control_418275();
}

//----- (00418275) --------------------------------------------------------
void __cdecl control_418275()
{
  int i; // [esp+Ch] [ebp-Ch]
  signed int v1; // [esp+10h] [ebp-8h]
  signed int v2; // [esp+14h] [ebp-4h]

  v1 = 0;
  v2 = 1;
  if ( infostr[0] )
  {
    control_print_info_str(0, infostr, 1, pnumlines);
    v1 = 1;
    v2 = 0;
  }
  for ( i = 0; pnumlines > i; ++i )
    control_print_info_str(v1 + i, panelstr[i], pstrjust[i], pnumlines - v2);
}

//----- (00418315) --------------------------------------------------------
void __fastcall control_print_info_str(int y, char *str, bool center, int lines)
{
  char v4; // ST28_1
  char *v5; // [esp+Ch] [ebp-1Ch]
  signed int v6; // [esp+14h] [ebp-14h]
  char *v7; // [esp+18h] [ebp-10h]
  int v8; // [esp+1Ch] [ebp-Ch]
  int No; // [esp+20h] [ebp-8h]
  char v10; // [esp+24h] [ebp-4h]

  v5 = str;
  No = lineoffset[lines][y];
  v8 = 0;
  if ( center == 1 )
  {
    v6 = 0;
    v7 = str;
    while ( *v7 )
    {
      v4 = fontframe[*v7++ & 0x7F];
      v6 += fontkern[v4] + 2;
    }
    if ( v6 < 288 )
      v8 = (288 - v6) >> 1;
    No += v8;
  }
  while ( *v5 )
  {
    v10 = fontframe[*v5++ & 0x7F];
    v8 += fontkern[v10] + 2;
    if ( v10 )
    {
      if ( v8 < 288 )
        CPrintString(No, v10, infoclr);
    }
    No += fontkern[v10] + 2;
  }
}

//----- (00418432) --------------------------------------------------------
void __fastcall ADD_PlrStringXY(int x, int y, int width, char *pszStr, char Just)
{
  char v5; // ST28_1
  int v6; // [esp+14h] [ebp-18h]
  char *v7; // [esp+18h] [ebp-14h]
  int v8; // [esp+1Ch] [ebp-10h]
  int No; // [esp+20h] [ebp-Ch]
  char v10; // [esp+24h] [ebp-8h]
  int v11; // [esp+28h] [ebp-4h]

  v11 = width - x + 1;
  v8 = 0;
  v6 = 0;
  v7 = pszStr;
  while ( *v7 )
  {
    v5 = fontframe[*v7++ & 0x7F];
    v6 += fontkern[v5] + 1;
  }
  if ( v6 < v11 )
    v8 = (v11 - v6) >> 1;
  No = v8 + x + screen_y_times_768[y + 160] + 64;
  while ( *pszStr )
  {
    v10 = fontframe[*pszStr++ & 0x7F];
    v8 += fontkern[v10] + 1;
    if ( v10 )
    {
      if ( v8 < v11 )
        CPrintString(No, v10, Just);
    }
    No += fontkern[v10] + 1;
  }
}

//----- (00418540) --------------------------------------------------------
void __fastcall PrintGameStr(int x, int y, char *str, int color)
{
  char v4; // [esp+14h] [ebp-8h]
  int No; // [esp+18h] [ebp-4h]

  No = x + screen_y_times_768[y + 160] + 64;
  while ( *str )
  {
    v4 = fontframe[*str++ & 0x7F];
    if ( v4 )
      CPrintString(No, v4, color);
    No += fontkern[v4] + 1;
  }
}

//----- (004185C1) --------------------------------------------------------
void __cdecl DrawChr()
{
  int v0; // [esp+Ch] [ebp-54h]
  char a4; // [esp+18h] [ebp-48h]
  int v2; // [esp+58h] [ebp-8h]
  char Just; // [esp+5Ch] [ebp-4h]

  CelDecodeOnly(64, 511, pChrPanel, 1, 320);
  ADD_PlrStringXY(20, 32, 151, plr[myplr]._pName, 0);
  if ( !plr[myplr]._pClass )
    ADD_PlrStringXY(168, 32, 299, "Warrior", 0);
  if ( plr[myplr]._pClass == 1 )
    ADD_PlrStringXY(168, 32, 299, "Rogue", 0);
  if ( plr[myplr]._pClass == 2 )
    ADD_PlrStringXY(168, 32, 299, "Sorceror", 0);
  sprintf(&a4, "%i", plr[myplr]._pLevel);
  ADD_PlrStringXY(66, 69, 109, &a4, 0);
  sprintf(&a4, "%li", plr[myplr]._pExperience);
  ADD_PlrStringXY(216, 69, 300, &a4, 0);
  sprintf(&a4, "%li", plr[myplr]._pNextExper);
  ADD_PlrStringXY(216, 97, 300, &a4, 0);
  sprintf(&a4, "%i", plr[myplr]._pGold);
  ADD_PlrStringXY(216, 146, 300, &a4, 0);
  Just = 0;
  if ( plr[myplr]._pIBonusAC > 0 )
    Just = 1;
  if ( plr[myplr]._pIBonusAC < 0 )
    Just = 2;
  sprintf(&a4, "%i", plr[myplr]._pIAC + plr[myplr]._pIBonusAC + plr[myplr]._pArmorClass);
  ADD_PlrStringXY(258, 183, 301, &a4, Just);
  Just = 0;
  if ( plr[myplr]._pIBonusToHit > 0 )
    Just = 1;
  if ( plr[myplr]._pIBonusToHit < 0 )
    Just = 2;
  sprintf(&a4, "%i%%", plr[myplr]._pIBonusToHit + (plr[myplr]._pDexterity >> 2) + 50);
  ADD_PlrStringXY(258, 211, 301, &a4, Just);
  Just = 0;
  if ( plr[myplr]._pIBonusDam > 0 )
    Just = 1;
  if ( plr[myplr]._pIBonusDam < 0 )
    Just = 2;
  v2 = plr[myplr]._pIMinDam;
  v2 += v2 * plr[myplr]._pIBonusDam / 100;
  v2 += plr[myplr]._pDamageMod + plr[myplr]._pIBonusDamMod;
  sprintf(
    &a4,
    "%i-%i",
    v2,
    plr[myplr]._pDamageMod
  + plr[myplr]._pIBonusDamMod
  + plr[myplr]._pIMaxDam * plr[myplr]._pIBonusDam / 100
  + plr[myplr]._pIMaxDam);
  ADD_PlrStringXY(258, 239, 301, &a4, Just);
  Just = plr[myplr]._pMagResist != 0;
  sprintf(&a4, "%i%%", plr[myplr]._pMagResist);
  ADD_PlrStringXY(257, 276, 300, &a4, Just);
  Just = plr[myplr]._pFireResist != 0;
  sprintf(&a4, "%i%%", plr[myplr]._pFireResist);
  ADD_PlrStringXY(257, 304, 300, &a4, Just);
  Just = plr[myplr]._pLghtResist != 0;
  sprintf(&a4, "%i%%", plr[myplr]._pLghtResist);
  ADD_PlrStringXY(257, 332, 300, &a4, Just);
  sprintf(&a4, "%i", plr[myplr]._pBaseStr);
  ADD_PlrStringXY(95, 155, 126, &a4, 0);
  sprintf(&a4, "%i", plr[myplr]._pBaseMag);
  ADD_PlrStringXY(95, 183, 126, &a4, 0);
  sprintf(&a4, "%i", plr[myplr]._pBaseDex);
  ADD_PlrStringXY(95, 211, 126, &a4, 0);
  sprintf(&a4, "%i", plr[myplr]._pBaseVit);
  ADD_PlrStringXY(95, 239, 126, &a4, 0);
  Just = 0;
  if ( plr[myplr]._pStrength > plr[myplr]._pBaseStr )
    Just = 1;
  if ( plr[myplr]._pStrength < plr[myplr]._pBaseStr )
    Just = 2;
  sprintf(&a4, "%i", plr[myplr]._pStrength);
  ADD_PlrStringXY(143, 155, 173, &a4, Just);
  Just = 0;
  if ( plr[myplr]._pMagic > plr[myplr]._pBaseMag )
    Just = 1;
  if ( plr[myplr]._pMagic < plr[myplr]._pBaseMag )
    Just = 2;
  sprintf(&a4, "%i", plr[myplr]._pMagic);
  ADD_PlrStringXY(143, 183, 173, &a4, Just);
  Just = 0;
  if ( plr[myplr]._pDexterity > plr[myplr]._pBaseDex )
    Just = 1;
  if ( plr[myplr]._pDexterity < plr[myplr]._pBaseDex )
    Just = 2;
  sprintf(&a4, "%i", plr[myplr]._pDexterity);
  ADD_PlrStringXY(143, 211, 173, &a4, Just);
  Just = 0;
  if ( plr[myplr]._pVitality > plr[myplr]._pBaseVit )
    Just = 1;
  if ( plr[myplr]._pVitality < plr[myplr]._pBaseVit )
    Just = 2;
  sprintf(&a4, "%i", plr[myplr]._pVitality);
  ADD_PlrStringXY(143, 239, 173, &a4, Just);
  if ( plr[myplr]._pStatPts > 0 )
  {
    sprintf(&a4, "%i", plr[myplr]._pStatPts);
    ADD_PlrStringXY(95, 266, 126, &a4, 2);
    v0 = plr[myplr]._pClass;
    if ( plr[myplr]._pBaseStr < MaxStats[v0][0] )
      CelDecodeOnly(201, 319, pChrButtons, chrbtn[0] + 2, 41);
    if ( MaxStats[v0][1] > plr[myplr]._pBaseMag )
      CelDecodeOnly(201, 347, pChrButtons, chrbtn[1] + 4, 41);
    if ( plr[myplr]._pBaseDex < MaxStats[v0][2] )
      CelDecodeOnly(201, 376, pChrButtons, chrbtn[2] + 6, 41);
    if ( plr[myplr]._pBaseVit < MaxStats[v0][3] )
      CelDecodeOnly(201, 404, pChrButtons, chrbtn[3] + 8, 41);
  }
  Just = plr[myplr]._pMaxHPBase < plr[myplr]._pMaxHP;
  sprintf(&a4, "%i", plr[myplr]._pMaxHP >> 6);
  ADD_PlrStringXY(95, 304, 126, &a4, Just);
  if ( plr[myplr]._pMaxHP != plr[myplr]._pHitPoints )
    Just = 2;
  sprintf(&a4, "%i", plr[myplr]._pHitPoints >> 6);
  ADD_PlrStringXY(143, 304, 174, &a4, Just);
  Just = plr[myplr]._pMaxManaBase < plr[myplr]._pMaxMana;
  sprintf(&a4, "%i", plr[myplr]._pMaxMana >> 6);
  ADD_PlrStringXY(95, 332, 126, &a4, Just);
  if ( plr[myplr]._pMana != plr[myplr]._pMaxMana )
    Just = 2;
  sprintf(&a4, "%i", plr[myplr]._pMana >> 6);
  ADD_PlrStringXY(143, 332, 174, &a4, Just);
}

//----- (00419603) --------------------------------------------------------
void __cdecl CheckLvlBtn()
{
  if ( !lvlbtndown && MouseX >= 40 && MouseX <= 81 && MouseY >= 313 && MouseY <= 335 )
    lvlbtndown = 1;
}

//----- (00419669) --------------------------------------------------------
void __cdecl ReleaseLvlBtn()
{
  if ( MouseX >= 40 && MouseX <= 81 && MouseY >= 313 && MouseY <= 335 )
    chrflag = 1;
  lvlbtndown = 0;
}

//----- (004196C7) --------------------------------------------------------
void __cdecl DrawLevelUpIcon()
{
  int frame; // [esp+Ch] [ebp-4h]

  if ( !stextflag )
  {
    if ( lvlbtndown )
      frame = 3;
    else
      frame = 2;
    ADD_PlrStringXY(0, 303, 120, "Level Up", 0);
    CelDecodeOnly(104, 495, pChrButtons, frame, 41);
  }
}

//----- (0041973E) --------------------------------------------------------
void __cdecl CheckChrBtns()
{
  int v0; // [esp+18h] [ebp-8h]
  signed int i; // [esp+1Ch] [ebp-4h]

  if ( !chrbtnactive && plr[myplr]._pStatPts )
  {
    v0 = plr[myplr]._pClass;
    for ( i = 0; i < 4; ++i )
    {
      switch ( i )
      {
        case 0:
          if ( MaxStats[v0][i] > plr[myplr]._pBaseStr )
            goto LABEL_16;
          break;
        case 1:
          if ( MaxStats[v0][i] > plr[myplr]._pBaseMag )
            goto LABEL_16;
          break;
        case 2:
          if ( MaxStats[v0][i] > plr[myplr]._pBaseDex )
            goto LABEL_16;
          break;
        case 3:
          if ( MaxStats[v0][i] > plr[myplr]._pBaseVit )
          {
LABEL_16:
            if ( attribute_inc_rects[i][0] <= MouseX
              && MouseX <= attribute_inc_rects[i][0] + attribute_inc_rects[i][2]
              && attribute_inc_rects[i][1] <= MouseY
              && attribute_inc_rects[i][3] + attribute_inc_rects[i][1] >= MouseY )
            {
              chrbtn[i] = 1;
              chrbtnactive = 1;
            }
          }
          break;
        default:
          continue;
      }
    }
  }
}

//----- (004199A3) --------------------------------------------------------
void __cdecl ReleaseChrBtns()
{
  signed int i; // [esp+10h] [ebp-4h]

  chrbtnactive = 0;
  for ( i = 0; i < 4; ++i )
  {
    if ( chrbtn[i] )
    {
      chrbtn[i] = 0;
      if ( attribute_inc_rects[i][0] <= MouseX
        && attribute_inc_rects[i][0] + attribute_inc_rects[i][2] >= MouseX
        && attribute_inc_rects[i][1] <= MouseY
        && attribute_inc_rects[i][3] + attribute_inc_rects[i][1] >= MouseY )
      {
        switch ( i )
        {
          case 0:
            NetSendCmdParam1(1u, CMD_ADDSTR, 1u);
            --plr[myplr]._pStatPts;
            break;
          case 1:
            NetSendCmdParam1(1u, CMD_ADDMAG, 1u);
            --plr[myplr]._pStatPts;
            break;
          case 2:
            NetSendCmdParam1(1u, CMD_ADDDEX, 1u);
            --plr[myplr]._pStatPts;
            break;
          case 3:
            NetSendCmdParam1(1u, CMD_ADDVIT, 1u);
            --plr[myplr]._pStatPts;
            break;
          default:
            continue;
        }
      }
    }
  }
}

//----- (00419B96) --------------------------------------------------------
void __cdecl DrawDurIcon()
{
  PlayerStruct *v0; // ST14_4
  int v1; // eax
  int v2; // eax
  int v3; // eax
  signed int a2; // [esp+Ch] [ebp-8h]

  if ( !chrflag && !questlog || !invflag && !sbookflag )
  {
    a2 = 656;
    if ( invflag || sbookflag )
      a2 = 336;
    v0 = &plr[myplr];
    v1 = DrawDurIcon4Item(plr[myplr].InvBody, a2, 4);
    v2 = DrawDurIcon4Item(&v0->InvBody[6], v1, 3);
    v3 = DrawDurIcon4Item(&v0->InvBody[4], v2, 0);
    DrawDurIcon4Item(&v0->InvBody[5], v3, 0);
  }
}

//----- (00419C84) --------------------------------------------------------
int __fastcall DrawDurIcon4Item(ItemStruct *item, int x, int frame)
{
  if ( item->_itype == -1 )
    return x;
  if ( item->_iDurability > 5 )
    return x;
  if ( !frame )
  {
    if ( item->_iClass == 1 )
    {
      switch ( item->_itype )
      {
        case 1:
          frame = 2;
          break;
        case 2:
          frame = 6;
          break;
        case 3:
          frame = 7;
          break;
        case 4:
          frame = 5;
          break;
        case 0xA:
          frame = 8;
          break;
        default:
          break;
      }
    }
    else
    {
      frame = 1;
    }
  }
  if ( item->_iDurability > 2 )
    frame += 8;
  CelDecodeOnly(x, 495, pDurIcons, frame, 32);
  return x - 40;
}

//----- (00419DB8) --------------------------------------------------------
void __cdecl RedBack()
{
  char *v0; // edi
  signed int v2; // edx
  signed int v3; // ecx
  signed int v6; // [esp+Ch] [ebp-4h]

  if ( light4flag )
    v6 = 1536;
  else
    v6 = 4608;
  v0 = gpBuffer + 122944;
  _EBX = &pLightTbl[v6];
  v2 = 352;
  do
  {
    v3 = 640;
    do
    {
      _AL = *v0;
      __asm { xlat }
      *v0++ = _AL;
      --v3;
    }
    while ( v3 );
    v0 += 128;
    --v2;
  }
  while ( v2 );
}

//----- (00419E1D) --------------------------------------------------------
char __fastcall GetSBookTrans(int ii, unsigned __int8 townok)
{
  int townok_; // [esp+Ch] [ebp-10h]
  char result; // [esp+18h] [ebp-4h]

  townok_ = townok;
  result = 1;
  if ( (1 << (ii - 1)) & plr[myplr]._pISpells )
    result = 3;
  if ( (1 << (ii - 1)) & plr[myplr]._pAblSpells )
    result = 0;
  if ( result == 1 )
  {
    if ( !CheckSpell(myplr, ii, 1, 1) )
      result = 4;
    if ( (char)(plr[myplr]._pISplLvlAdd + plr[myplr]._pSplLvl[ii]) <= 0 )
      result = 4;
  }
  if ( townok_ && !currlevel )
    result = 4;
  return result;
}

//----- (00419F74) --------------------------------------------------------
void __cdecl DrawSpellBook()
{
  __int64 v0; // rax
  int v1; // eax
  int v2; // [esp+Ch] [ebp-24h]
  int v3; // [esp+10h] [ebp-20h]
  int v4; // [esp+14h] [ebp-1Ch]
  signed int i; // [esp+18h] [ebp-18h]
  int yp; // [esp+1Ch] [ebp-14h]
  char t; // [esp+24h] [ebp-Ch]
  int v8; // [esp+28h] [ebp-8h]
  int ii; // [esp+2Ch] [ebp-4h]

  CelDecodeOnly(384, 511, pSpellBkCel, 1, 320);
  CelDecodeOnly(51 * sbooktab + 391, 508, pSBkBtnCel, sbooktab + 1, 51);
  yp = 215;
  v3 = LODWORD(plr[myplr]._pAblSpells) | LODWORD(plr[myplr]._pMemSpells) | LODWORD(plr[myplr]._pISpells);
  v4 = HIDWORD(plr[myplr]._pAblSpells) | HIDWORD(plr[myplr]._pMemSpells) | HIDWORD(plr[myplr]._pISpells);
  for ( i = 1; i < 8; ++i )
  {
    ii = SpellPages[sbooktab - 1][i + 6];
    if ( ii != -1 )
    {
      v0 = 1 << (ii - 1);
      v1 = v3 & v0;
      if ( HIDWORD(v0) & v4 || v1 )
      {
        t = GetSBookTrans(ii, 1u);
        SetSpellTrans(t);
        DrawSpellCel(395, yp, pSBkIconCels, SpellITbl[ii], 37);
        if ( plr[myplr]._pRSpell == ii && (char)plr[myplr]._pRSplType == t )
          DrawSpellCel(395, yp, pSBkIconCels, 43, 37);
        PrintSBookStr(10, yp - 22, 0, spelldata[ii].sNameText, 0);
        v2 = GetSBookTrans(ii, 0);
        if ( v2 )
        {
          if ( v2 == 3 )
          {
            sprintf(tempstr, "Staff (%i charges)", plr[myplr].InvBody[4]._iCharges);
          }
          else
          {
            v8 = plr[myplr]._pISplLvlAdd + plr[myplr]._pSplLvl[ii];
            if ( v8 < 0 )
              v8 = 0;
            if ( v8 )
              sprintf(tempstr, "Spell Level %i", v8);
            else
              sprintf(tempstr, "Spell Level 0 - Unusable");
          }
        }
        else
        {
          strcpy(tempstr, "Skill");
        }
        PrintSBookStr(10, yp - 10, 0, tempstr, 0);
      }
    }
    yp += 43;
  }
}

//----- (0041A2C5) --------------------------------------------------------
void __fastcall PrintSBookStr(int x, int y, bool cjustflag, char *pszStr, int bright)
{
  char v5; // ST28_1
  signed int v6; // [esp+14h] [ebp-14h]
  char *v7; // [esp+18h] [ebp-10h]
  int v8; // [esp+1Ch] [ebp-Ch]
  int No; // [esp+20h] [ebp-8h]
  char v10; // [esp+24h] [ebp-4h]

  No = x + screen_y_times_768[y] + 440;
  v8 = 0;
  if ( cjustflag )
  {
    v6 = 0;
    v7 = pszStr;
    while ( *v7 )
    {
      v5 = fontframe[*v7++ & 0x7F];
      v6 += fontkern[v5] + 1;
    }
    if ( v6 < 222 )
      v8 = (222 - v6) >> 1;
    No += v8;
  }
  while ( *pszStr )
  {
    v10 = fontframe[*pszStr++ & 0x7F];
    v8 += fontkern[v10] + 1;
    if ( v10 )
    {
      if ( v8 <= 222 )
        CPrintString(No, v10, bright);
    }
    No += fontkern[v10] + 1;
  }
}

//----- (0041A3D9) --------------------------------------------------------
void __cdecl CheckSBook()
{
  __int64 v0; // rax
  int v1; // eax
  int v2; // [esp+14h] [ebp-8h]
  BYTE v3; // [esp+18h] [ebp-4h]

  if ( MouseX >= 331 && MouseX < 368 && MouseY >= 18 && MouseY < 314 )
  {
    v2 = SpellPages[sbooktab][(MouseY - 18) / 43];
    if ( v2 != -1 )
    {
      v0 = 1 << (v2 - 1);
      v1 = (LODWORD(plr[myplr]._pAblSpells) | LODWORD(plr[myplr]._pMemSpells) | LODWORD(plr[myplr]._pISpells)) & v0;
      if ( HIDWORD(v0) & (HIDWORD(plr[myplr]._pAblSpells) | HIDWORD(plr[myplr]._pMemSpells) | HIDWORD(plr[myplr]._pISpells))
        || v1 )
      {
        v3 = 1;
        if ( (1 << (v2 - 1)) & plr[myplr]._pISpells )
          v3 = 3;
        if ( (1 << (v2 - 1)) & plr[myplr]._pAblSpells )
          v3 = 0;
        plr[myplr]._pRSpell = v2;
        plr[myplr]._pRSplType = v3;
        DrawSpell();
        drawpanflag = 255;
      }
    }
  }
  if ( MouseX >= 327 && MouseX < 633 && MouseY >= 320 && MouseY < 349 )
    sbooktab = (MouseX - 327) / 51;
}

//----- (0041A64E) --------------------------------------------------------
int __cdecl control_41A64E()
{
  __int64 v1; // rax
  int v2; // eax
  int sn; // [esp+18h] [ebp-Ch]
  BOOL v4; // [esp+1Ch] [ebp-8h]
  char st; // [esp+20h] [ebp-4h]

  if ( !currlevel )
    return 0;
  if ( MouseX < 327 )
    return 0;
  if ( MouseX >= 368 )
    return 0;
  if ( MouseY < 29 )
    return 0;
  if ( MouseY >= 346 )
    return 0;
  sn = SpellPages[sbooktab][(MouseY - 29) / 46];
  if ( sn == -1 )
    return 0;
  v1 = 1 << (sn - 1);
  v2 = (LODWORD(plr[myplr]._pAblSpells) | LODWORD(plr[myplr]._pMemSpells) | LODWORD(plr[myplr]._pISpells)) & v1;
  if ( !(HIDWORD(v1) & (HIDWORD(plr[myplr]._pAblSpells) | HIDWORD(plr[myplr]._pMemSpells) | HIDWORD(plr[myplr]._pISpells)))
    && !v2 )
  {
    return 0;
  }
  st = 1;
  if ( (1 << (sn - 1)) & plr[myplr]._pISpells )
    st = 3;
  if ( (1 << (sn - 1)) & plr[myplr]._pAblSpells )
    st = 0;
  v4 = 0;
  if ( st >= 0 )
  {
    if ( st <= 1 )
    {
      v4 = CheckSpell(myplr, sn, st, 0);
    }
    else if ( st == 3 )
    {
      v4 = inv_456F00(sn);
    }
  }
  if ( !v4 )
    return 0;
  if ( spelldata[sn].sTargeted )
  {
    plr[myplr]._pTSpell = sn;
    plr[myplr]._pTSplType = st;
    j_SetCursor(9);
  }
  else
  {
    plr[myplr]._pSBkSpell = sn;
    plr[myplr]._pSBkSplType = st;
    NetSendCmdParam1(1u, 9u, plr[myplr]._pSBkSpell);
  }
  return 1;
}

//----- (0041A988) --------------------------------------------------------
void __fastcall DrawGoldSplit(int amount)
{
  int screen_x; // [esp+10h] [ebp-Ch]
  int screen_xa; // [esp+10h] [ebp-Ch]
  signed int i; // [esp+14h] [ebp-8h]

  screen_x = 0;
  CelDecodeOnly(415, 338, pGBoxBuff, 1, 261);
  sprintf(tempstr, "How much of %u", initialDropGoldValue);
  ADD_PlrStringXY(366, 87, 600, tempstr, 3);
  ADD_PlrStringXY(366, 103, 600, "gold pieces would you", 3);
  ADD_PlrStringXY(366, 121, 600, "like to remove?", 3);
  if ( amount > 0 )
  {
    sprintf(tempstr, "%u", amount);
    PrintGameStr(388, 140, tempstr, 0);
  }
  if ( amount <= 0 )
  {
    screen_xa = 450;
  }
  else
  {
    for ( i = 0; tempstr[i] > i; ++i )
      screen_x += fontkern[fontframe[tempstr[i] & 0x7F]] + 1;
    screen_xa = screen_x + 452;
  }
  CelDecodeOnly(screen_xa, 300, pCelBuff, frame_gold, 12);
  frame_gold = (frame_gold & 7) + 1;
}

//----- (0041AAF2) --------------------------------------------------------
void __cdecl control_drop_gold(int n)
{
  char v1; // cl MAPDST
  size_t v2; // ebx
  size_t v4; // [esp+14h] [ebp-Ch]
  char v5[8]; // [esp+18h] [ebp-8h]

  memset(v5, 0, 6u);
  _itoa(dropGoldValue, v5, 10);
  switch ( v1 )
  {
    case 13:
      if ( dropGoldValue > 0 )
        control_remove_gold(myplr, gold_index);
      dropGoldFlag = 0;
      break;
    case 27:
      dropGoldFlag = 0;
      dropGoldValue = 0;
      return;
    case 8:
      v4 = strlen(v5);
      v5[v4 - 1] = 0;
      dropGoldValue = atoi(v5);
      return;
    default:
      if ( v1 - 48 >= 0 && v1 - 48 <= 9 )
      {
        if ( dropGoldValue || atoi(v5) <= initialDropGoldValue )
        {
          v5[strlen(v5)] = v1;
          if ( atoi(v5) > initialDropGoldValue )
            return;
          v2 = strlen(v5);
          if ( v2 > strlen(v5) )
            return;
        }
        else
        {
          v5[0] = v1;
        }
        dropGoldValue = atoi(v5);
        return;
      }
      break;
  }
}

//----- (0041AC81) --------------------------------------------------------
void __fastcall control_remove_gold(int pnum, int gold_index)
{
  int i; // [esp+14h] [ebp-4h]
  int ia; // [esp+14h] [ebp-4h]

  if ( gold_index > 46 )
  {
    ia = gold_index - 47;
    plr[pnum].SpdList[gold_index - 47]._ivalue -= dropGoldValue;
    if ( plr[pnum].SpdList[gold_index - 47]._ivalue <= 0 )
      RemoveSpdBarItem(pnum, ia);
    else
      SetSpdbarGoldCurs(pnum, ia);
  }
  else
  {
    i = gold_index - 7;
    plr[pnum].InvList[gold_index - 7]._ivalue -= dropGoldValue;
    if ( plr[pnum].InvList[gold_index - 7]._ivalue <= 0 )
      RemoveInvItem(pnum, i);
    else
      SetGoldCurs(pnum, i);
  }
  SetPlrHandItem(&plr[pnum].HoldItem, 0);
  GetPlrHandSeed(&plr[pnum].HoldItem);
  plr[pnum].HoldItem._ivalue = dropGoldValue;
  plr[pnum].HoldItem._iStatFlag = 1;
  control_set_gold_curs(pnum);
  plr[pnum]._pGold = CalculateGold(pnum);
  dropGoldValue = 0;
}

//----- (0041AE87) --------------------------------------------------------
void __fastcall control_set_gold_curs(int pnum)
{
  if ( plr[pnum].HoldItem._ivalue < 2500 )
  {
    if ( plr[pnum].HoldItem._ivalue > 1000 )
      plr[pnum].HoldItem._iCurs = 5;
    else
      plr[pnum].HoldItem._iCurs = 4;
  }
  else
  {
    plr[pnum].HoldItem._iCurs = 6;
  }
  j_SetCursor(plr[pnum].HoldItem._iCurs + 12);
}

//----- (0041AF7D) --------------------------------------------------------
void __fastcall control_41AF7D(char *a1)
{
  char *v1; // [esp+Ch] [ebp-8h]
  signed int i; // [esp+10h] [ebp-4h]

  v1 = a1;
  for ( i = 0; i < 4 && v1 != (char *)-1; ++i )
  {
    if ( myplr != i )
    {
      if ( plr[i].plractive )
        --v1;
    }
  }
  if ( i < 4 )
  {
    if ( talkbtndown[i - 1] )
      talkbtndown[i - 1] = 0;
    else
      talkbtndown[i - 1] = 1;
  }
}

//----- (0041B030) --------------------------------------------------------
void __cdecl control_type_message()
{
  talkflag = 1;
  sgbPlrTalkTbl = 144;
  sgszTalkMsg[0] = 0;
  frame = 1;
  drawpanflag = 255;
}

//----- (0041B06F) --------------------------------------------------------
void __cdecl control_reset_talk_msg()
{
  int a1; // [esp+Ch] [ebp-8h]
  signed int i; // [esp+10h] [ebp-4h]

  if ( gbMaxPlayers != 1 )
  {
    if ( talkflag )
    {
      if ( sgszTalkMsg[0] )
      {
        a1 = 0;
        for ( i = 0; i < 4; ++i )
        {
          if ( talkbtndown[i] )
            a1 |= 1 << i;
        }
        NetSendCmdString(a1, sgszTalkMsg);
        sgszTalkMsg[0] = 0;
      }
      control_reset_talk();
      drawpanflag = 255;
    }
    else
    {
      control_type_message();
    }
  }
}

//----- (0041B123) --------------------------------------------------------
void __cdecl DrawTalkPan()
{
  int i; // [esp+Ch] [ebp-14h]
  signed int v1; // [esp+10h] [ebp-10h]
  signed int v2; // [esp+14h] [ebp-Ch]
  int No; // [esp+18h] [ebp-8h]
  char v4; // [esp+1Ch] [ebp-4h]

  if ( talkflag )
  {
    DrawPanelBox(200, sgbPlrTalkTbl + 37, 0x10Eu, 0x53u, 264, 533);
    v1 = 546;
    No = screen_y_times_768[546] + 264;
    v2 = 0;
    for ( i = 0; sgszTalkMsg[i]; ++i )
    {
      v4 = fontframe[sgszTalkMsg[i] & 0x7F];
      v2 += fontkern[v4] + 1;
      if ( v2 > 250 )
      {
        v1 += 13;
        No = screen_y_times_768[v1] + 264;
        v2 = 0;
      }
      if ( v4 )
        CPrintString(No, v4, 0);
      No += fontkern[v4] + 1;
    }
    CelDecDatOnly(&gpBuffer[No], pCelBuff, frame, 12);
    frame = (frame & 7) + 1;
  }
}

//----- (0041B256) --------------------------------------------------------
void __cdecl control_reset_talk()
{
  talkflag = 0;
  sgbPlrTalkTbl = 0;
  drawpanflag = 255;
}

//----- (0041B284) --------------------------------------------------------
bool __fastcall control_41B284_is_printable(char a1)
{
  bool result; // al

  if ( a1 >= 32 )
    result = a1 <= 128;
  else
    result = 0;
  return result;
}

//----- (0041B2C6) --------------------------------------------------------
int __fastcall control_talk_last_key(char a1)
{
  int result; // eax

  result = strlen(sgszTalkMsg);
  if ( result < 78 )
  {
    sgszTalkMsg[result] = a1;
    sgszTalkMsg[result + 1] = 0;
  }
  return result;
}

//----- (0041B30C) --------------------------------------------------------
int __fastcall control_presskeys(char a1)
{
  int result; // eax

  result = control_41B284_is_printable(a1);
  if ( (_BYTE)result )
    result = control_talk_last_key(a1);
  return result;
}

//----- (0041B33D) --------------------------------------------------------
void __fastcall control_press_enter(SHORT vkey)
{
  signed int v1; // [esp+10h] [ebp-4h]

  if ( vkey == 8 )
  {
    v1 = strlen(sgszTalkMsg);
    if ( v1 > 0 )
      sgszTalkMsg[v1 - 1] = 0;
  }
}

