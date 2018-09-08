#include "all.h"

//----- (0048E700) --------------------------------------------------------
void __fastcall CelDrawDatOnly(char *pDecodeTo, char *pRLEBytes, int dwRLESize, int dwRLEWdt)
{
  char *src; // esi
  char *dst; // edi
  char *src_end; // ebx
  int v7; // edx
  unsigned int v8; // eax
  unsigned int v9; // ecx
  char v10; // cf
  unsigned int v11; // ecx

  assert(pDecodeTo, "ENGINE.CPP", 45);
  assert(pRLEBytes, "ENGINE.CPP", 46);
  src = pRLEBytes;
  dst = pDecodeTo;
  src_end = &pRLEBytes[dwRLESize];
  do
  {
    v7 = dwRLEWdt;
    do
    {
      while ( 1 )
      {
        v8 = (unsigned __int8)*src++;
        if ( (v8 & 0x80u) == 0 )
          break;
        LOBYTE(v8) = -(char)v8;
        dst += v8;
        v7 -= v8;
        if ( !v7 )
          goto LABEL_16;
      }
      v7 -= v8;
      v9 = v8 >> 1;
      if ( v8 & 1 )
      {
        *dst++ = *src++;
        if ( !v9 )
          continue;
      }
      v10 = v9 & 1;
      v11 = v8 >> 2;
      if ( v10 )
      {
        *(_WORD *)dst = *(_WORD *)src;
        src += 2;
        dst += 2;
        if ( !v11 )
          continue;
      }
      qmemcpy(dst, src, 4 * v11);
      src += 4 * v11;
      dst += 4 * v11;
    }
    while ( v7 );
LABEL_16:
    dst += -dwRLEWdt - 768;
  }
  while ( src_end != src );
}

//----- (0048E7BC) --------------------------------------------------------
void __fastcall CelDecodeOnly(int screen_x, int screen_y, void *pCelBuff, int frame, int frame_width)
{
  assert(pCelBuff, "ENGINE.CPP", 107);
  CelDrawDatOnly(
    &gpBuffer[screen_x + screen_y_times_768[screen_y]],
    (char *)pCelBuff + *((_DWORD *)pCelBuff + frame),
    *((_DWORD *)pCelBuff + frame + 1) - *((_DWORD *)pCelBuff + frame),
    frame_width);
}

//----- (0048E843) --------------------------------------------------------
void __fastcall CelDecDatOnly(char *pBuff, char *pCelBuff, int frame, int frame_width)
{
  assert(pCelBuff, "ENGINE.CPP", 128);
  assert(pBuff, "ENGINE.CPP", 129);
  CelDrawDatOnly(
    pBuff,
    &pCelBuff[*(_DWORD *)&pCelBuff[4 * frame]],
    *(_DWORD *)&pCelBuff[4 * frame + 4] - *(_DWORD *)&pCelBuff[4 * frame],
    frame_width);
}

//----- (0048E8D2) --------------------------------------------------------
void __fastcall CelDrawHdrOnly(int screen_x, int screen_y, char *pCelBuff, int frame, int frame_width, int always_0, int direction)
{
  unsigned __int16 v7; // dx
  char *pRLEBytes; // [esp+1Ch] [ebp-Ch]
  int dwRLESize; // [esp+20h] [ebp-8h]
  int v11; // [esp+24h] [ebp-4h]

  assert(pCelBuff, "ENGINE.CPP", 150);
  pRLEBytes = &pCelBuff[*(_DWORD *)&pCelBuff[4 * frame]];
  v7 = *(_WORD *)&pRLEBytes[always_0];
  if ( v7 )
  {
    if ( direction == 8 )
      v11 = 0;
    else
      v11 = *(unsigned __int16 *)&pRLEBytes[direction];
    if ( v11 )
      dwRLESize = v11 - v7;
    else
      dwRLESize = *(_DWORD *)&pCelBuff[4 * frame + 4] - *(_DWORD *)&pCelBuff[4 * frame] - v7;
    CelDrawDatOnly(
      &gpBuffer[screen_x + screen_y_times_768[screen_y - 16 * always_0]],
      &pRLEBytes[v7],
      dwRLESize,
      frame_width);
  }
}

//----- (0048E9CC) --------------------------------------------------------
void __fastcall CelDecodeHdrOnly(char *pBuff, char *pCelBuff, int frame, int frame_width, int always_0, int direction)
{
  unsigned __int16 v6; // dx
  char *pRLEBytes; // [esp+18h] [ebp-Ch]
  int dwRLESize; // [esp+1Ch] [ebp-8h]
  int v10; // [esp+20h] [ebp-4h]

  assert(pCelBuff, "ENGINE.CPP", 177);
  assert(pBuff, "ENGINE.CPP", 178);
  pRLEBytes = &pCelBuff[*(_DWORD *)&pCelBuff[4 * frame]];
  v6 = *(_WORD *)&pRLEBytes[always_0];
  if ( v6 )
  {
    if ( direction == 8 )
      v10 = 0;
    else
      v10 = *(unsigned __int16 *)&pRLEBytes[direction];
    if ( v10 )
      dwRLESize = v10 - v6;
    else
      dwRLESize = *(_DWORD *)&pCelBuff[4 * frame + 4] - *(_DWORD *)&pCelBuff[4 * frame] - v6;
    CelDrawDatOnly(pBuff, &pRLEBytes[v6], dwRLESize, frame_width);
  }
}

//----- (0048EAC6) --------------------------------------------------------
void __fastcall CelDecDatLightOnly(char *pDecodeTo, char *pRLEBytes, int frame_content_size, int frame_width)
{
  char *src; // esi
  char *dst; // edi
  char *src_end; // ebx
  int v7; // edx
  int v8; // eax
  int v9; // ST00_4

  assert(pDecodeTo, "ENGINE.CPP", 197);
  assert(pRLEBytes, "ENGINE.CPP", 198);
  src = pRLEBytes;
  dst = pDecodeTo;
  src_end = &pRLEBytes[frame_content_size];
  do
  {
    v7 = frame_width;
    do
    {
      while ( 1 )
      {
        v8 = (unsigned __int8)*src++;
        if ( (v8 & 0x80u) != 0 )
          break;
        v9 = v7 - v8;
        CelDecDatLightEntry(v8, (char *)(v7 - v8));
        v7 = v9;
        if ( !v9 )
          goto LABEL_11;
      }
      LOBYTE(v8) = -(char)v8;
      dst += v8;
      v7 -= v8;
    }
    while ( v7 );
LABEL_11:
    dst += -frame_width - 768;
  }
  while ( src_end != src );
}

//----- (0048EB7F) --------------------------------------------------------
void __fastcall CelDecDatLightEntry(int a1, char *a2)
{
  int v2; // ebx
  char *v3; // edi
  _BYTE *v4; // esi
  char v5; // cf
  unsigned __int8 v6; // cl
  char v7; // cl
  int v8; // eax
  char v9; // ch
  char v10; // ch
  char v11; // ch

  v5 = a1 & 1;
  v6 = (unsigned __int8)a1 >> 1;
  if ( v5 )
  {
    LOBYTE(a2) = *v4;
    *v3 = a2[v2];
    ++v4;
    ++v3;
  }
  v5 = v6 & 1;
  v7 = v6 >> 1;
  if ( v5 )
  {
    LOBYTE(a2) = *v4;
    *v3 = a2[v2];
    LOBYTE(a2) = v4[1];
    v3[1] = a2[v2];
    v4 += 2;
    v3 += 2;
  }
  for ( ; v7; --v7 )
  {
    v8 = *(_DWORD *)v4;
    v4 += 4;
    LOBYTE(a2) = v8;
    v9 = a2[v2];
    LOBYTE(a2) = BYTE1(v8);
    v8 = __ROR4__(v8, 16);
    *v3 = v9;
    v10 = a2[v2];
    LOBYTE(a2) = v8;
    v3[1] = v10;
    v11 = a2[v2];
    LOBYTE(a2) = BYTE1(v8);
    v3[2] = v11;
    v3[3] = a2[v2];
    v3 += 4;
  }
}

//----- (0048EBF9) --------------------------------------------------------
void __fastcall CelDecDatLightTrans(char *pDecodeTo, char *pRLEBytes, int frame_content_size, int frame_width)
{
  char *src; // esi
  char *dst; // edi
  char *src_end; // ebx
  int v7; // edx
  unsigned int v8; // eax
  unsigned int v10; // ecx
  char v11; // cf
  unsigned int v12; // ecx
  char *v13; // esi
  char *v14; // edi
  char *v18; // edi
  unsigned int v21; // ecx
  char *v25; // edi
  char *v26; // [esp-4h] [ebp-24h]
  int v27; // [esp+14h] [ebp-Ch]
  BYTE *v28; // [esp+18h] [ebp-8h]

  assert(pDecodeTo, "ENGINE.CPP", 320);
  assert(pRLEBytes, "ENGINE.CPP", 321);
  v28 = &pLightTbl[256 * light_table_index];
  src = pRLEBytes;
  dst = pDecodeTo;
  src_end = &pRLEBytes[frame_content_size];
  v27 = (unsigned __int8)pDecodeTo & 1;
  do
  {
    v7 = frame_width;
    do
    {
      while ( 1 )
      {
        v8 = (unsigned __int8)*src++;
        if ( (v8 & 0x80u) != 0 )
          break;
        v26 = src_end;
        _EBX = v28;
        v7 -= v8;
        if ( ((unsigned __int8)dst & 1) == v27 )
        {
          v10 = v8 >> 1;
          if ( !(v8 & 1) )
            goto LABEL_12;
          ++src;
          ++dst;
          if ( v10 )
          {
LABEL_19:
            v11 = v10 & 1;
            if ( !v11 )
              goto LABEL_28;
            _AL = *src;
            ASM_XLAT();
            *dst = _AL;
            src += 2;
            dst += 2;
            if ( v21 )
            {
LABEL_28:
              for (v21 = v10 >> 1; v21; --v21)
              {
                _EAX = *(_DWORD *)src;
                src += 4;
                ASM_XLAT();
                *dst = _EAX;
                v25 = dst + 2;
                _EAX = __ROR4__(_EAX, 16);
                ASM_XLAT();
                *v25 = _EAX;
                dst = v25 + 2;
              }
            }
            goto LABEL_22;
          }
        }
        else
        {
          v10 = v8 >> 1;
          if ( !(v8 & 1) )
            goto LABEL_19;
          _AL = *src++;
          ASM_XLAT();
          *dst++ = _AL;
          if ( v10 )
          {
LABEL_12:
            v11 = v10 & 1;
            if ( !v11 )
              goto LABEL_29;
            v13 = src + 1;
            v14 = dst + 1;
            _AL = *v13;
            src = v13 + 1;
            ASM_XLAT();
            *v14 = _AL;
            dst = v14 + 1;
            if ( v12 )
            {
LABEL_29:
              for (v12 = v10 >> 1; v12; --v12)
              {
                _EAX = *(_DWORD *)src;
                src += 4;
                v18 = dst + 1;
                _EAX = __ROR4__(_EAX, 8);
                ASM_XLAT();
                *v18 = _EAX;
                _EAX = __ROR4__(_EAX, 16);
                v18 += 2;
                ASM_XLAT();
                *v18 = _EAX;
                dst = v18 + 1;
              }
            }
            goto LABEL_22;
          }
        }
LABEL_22:
        src_end = v26;
        if ( !v7 )
          goto LABEL_25;
      }
      LOBYTE(v8) = -(char)v8;
      dst += v8;
      v7 -= v8;
    }
    while ( v7 );
LABEL_25:
    dst += -frame_width - 768;
    v27 = ((_BYTE)v27 + 1) & 1;
  }
  while ( src_end != src );
}

//----- (0048ED33) --------------------------------------------------------
void __fastcall CelDecodeLightOnly(int screen_x, int screen_y, char *pCelBuff, int frame, int frame_width)
{
  char *pDecodeTo; // [esp+14h] [ebp-Ch]
  char *pRLEBytes; // [esp+18h] [ebp-8h]
  int frame_content_size; // [esp+1Ch] [ebp-4h]

  assert(pCelBuff, "ENGINE.CPP", 444);
  frame_content_size = *(_DWORD *)&pCelBuff[4 * frame + 4] - *(_DWORD *)&pCelBuff[4 * frame];
  pRLEBytes = &pCelBuff[*(_DWORD *)&pCelBuff[4 * frame]];
  pDecodeTo = &gpBuffer[screen_x + screen_y_times_768[screen_y]];
  if ( light_table_index )
    CelDecDatLightOnly(pDecodeTo, pRLEBytes, frame_content_size, frame_width);
  else
    CelDrawDatOnly(pDecodeTo, pRLEBytes, frame_content_size, frame_width);
}

//----- (0048EDDF) --------------------------------------------------------
void __fastcall CelDecodeHdrLightOnly(int screen_x, int screen_y, char *pCelBuff, int frame, int frame_width, int always_0, int direction)
{
  unsigned __int16 v7; // dx
  char *pDecodeTo; // [esp+18h] [ebp-10h]
  char *pRLEBytes; // [esp+1Ch] [ebp-Ch]
  char *pRLEBytesa; // [esp+1Ch] [ebp-Ch]
  int frame_content_size; // [esp+20h] [ebp-8h]
  int v13; // [esp+24h] [ebp-4h]

  assert(pCelBuff, "ENGINE.CPP", 497);
  pRLEBytes = &pCelBuff[*(_DWORD *)&pCelBuff[4 * frame]];
  v7 = *(_WORD *)&pRLEBytes[always_0];
  if ( v7 )
  {
    if ( direction == 8 )
      v13 = 0;
    else
      v13 = *(unsigned __int16 *)&pRLEBytes[direction];
    if ( v13 )
      frame_content_size = v13 - v7;
    else
      frame_content_size = *(_DWORD *)&pCelBuff[4 * frame + 4] - *(_DWORD *)&pCelBuff[4 * frame] - v7;
    pRLEBytesa = &pRLEBytes[v7];
    pDecodeTo = &gpBuffer[screen_x + screen_y_times_768[screen_y - 16 * always_0]];
    if ( light_table_index )
      CelDecDatLightOnly(pDecodeTo, pRLEBytesa, frame_content_size, frame_width);
    else
      CelDrawDatOnly(pDecodeTo, pRLEBytesa, frame_content_size, frame_width);
  }
}

//----- (0048EEFE) --------------------------------------------------------
void __fastcall CelDecodeHdrLightTrans(char *pBuff, char *pCelBuff, int frame, int frame_width, int always_0, int direction)
{
  unsigned __int16 v6; // dx
  char *pRLEBytes; // [esp+18h] [ebp-Ch]
  char *pRLEBytesa; // [esp+18h] [ebp-Ch]
  int frame_content_size; // [esp+1Ch] [ebp-8h]
  int v11; // [esp+20h] [ebp-4h]

  assert(pCelBuff, "ENGINE.CPP", 560);
  assert(pBuff, "ENGINE.CPP", 561);
  pRLEBytes = &pCelBuff[*(_DWORD *)&pCelBuff[4 * frame]];
  v6 = *(_WORD *)&pRLEBytes[always_0];
  if ( v6 )
  {
    if ( direction == 8 )
      v11 = 0;
    else
      v11 = *(unsigned __int16 *)&pRLEBytes[direction];
    if ( v11 )
      frame_content_size = v11 - v6;
    else
      frame_content_size = *(_DWORD *)&pCelBuff[4 * frame + 4] - *(_DWORD *)&pCelBuff[4 * frame] - v6;
    pRLEBytesa = &pRLEBytes[v6];
    if ( cel_transparency_active )
    {
      CelDecDatLightTrans(pBuff, pRLEBytesa, frame_content_size, frame_width);
    }
    else if ( light_table_index )
    {
      CelDecDatLightOnly(pBuff, pRLEBytesa, frame_content_size, frame_width);
    }
    else
    {
      CelDrawDatOnly(pBuff, pRLEBytesa, frame_content_size, frame_width);
    }
  }
}

//----- (0048F042) --------------------------------------------------------
void __fastcall CelDrawHdrLightRed(int screen_x, int screen_y, char *pCelBuff, int frame, int frame_width, int always_0, int direction, char always_1)
{
  unsigned __int16 v8; // dx
  _BYTE *v9; // esi
  char *v10; // edi
  int v11; // edx
  int v12; // eax
  int v13; // ecx
  char *v15; // [esp+1Ch] [ebp-18h]
  int v16; // [esp+1Ch] [ebp-18h]
  BYTE *v17; // [esp+20h] [ebp-14h]
  signed int v18; // [esp+24h] [ebp-10h]
  int v19; // [esp+28h] [ebp-Ch]
  int v20; // [esp+2Ch] [ebp-8h]

  assert(pCelBuff, "ENGINE.CPP", 595);
  v15 = &pCelBuff[*(_DWORD *)&pCelBuff[4 * frame]];
  v8 = *(_WORD *)&v15[always_0];
  if ( v8 )
  {
    if ( direction == 8 )
      v20 = 0;
    else
      v20 = *(unsigned __int16 *)&v15[direction];
    if ( v20 )
      v19 = v20 - v8;
    else
      v19 = *(_DWORD *)&pCelBuff[4 * frame + 4] - *(_DWORD *)&pCelBuff[4 * frame] - v8;
    v16 = (int)&v15[v8];
    if ( light4flag )
      v18 = 1024;
    else
      v18 = 4096;
    if ( always_1 == 2 )
      v18 += 256;
    if ( always_1 >= 4 )
      v18 += ((always_1 - 4) << 8) + 768;
    v17 = &pLightTbl[v18];
    v9 = (_BYTE *)v16;
    v10 = &gpBuffer[screen_x + screen_y_times_768[screen_y - 16 * always_0]];
    do
    {
      v11 = frame_width;
      do
      {
        while ( 1 )
        {
          v12 = (unsigned __int8)*v9++;
          if ( (v12 & 0x80u) == 0 )
            break;
          LOBYTE(v12) = -(char)v12;
          v10 += v12;
          v11 -= v12;
          if ( !v11 )
            goto LABEL_25;
        }
        v11 -= v12;
        v13 = v12;
        do
        {
          LOBYTE(v12) = *v9++;
          *v10 = v17[v12];
          --v13;
          ++v10;
        }
        while ( v13 );
      }
      while ( v11 );
LABEL_25:
      v10 += -frame_width - 768;
    }
    while ( (_BYTE *)(v16 + v19) != v9 );
  }
}

//----- (0048F1EC) --------------------------------------------------------
void __fastcall Cel2DecDatOnly(char *pDecodeTo, char *pRLEBytes, int frame_content_size, int frame_width)
{
  char *src; // esi
  char *dst; // edi
  char *src_end; // ebx
  int v7; // edx
  unsigned int v8; // eax
  unsigned int v9; // ecx
  char v10; // cf
  unsigned int v11; // ecx

  assert(pDecodeTo, "ENGINE.CPP", 669);
  assert(pRLEBytes, "ENGINE.CPP", 670);
  src = pRLEBytes;
  dst = pDecodeTo;
  src_end = &pRLEBytes[frame_content_size];
  do
  {
    v7 = frame_width;
    do
    {
      while ( 1 )
      {
        v8 = (unsigned __int8)*src++;
        if ( (v8 & 0x80u) == 0 )
          break;
        LOBYTE(v8) = -(char)v8;
        dst += v8;
        v7 -= v8;
        if ( !v7 )
          goto LABEL_18;
      }
      v7 -= v8;
      if ( dst < (char *)gpBufEnd )
      {
        v9 = v8 >> 1;
        if ( !(v8 & 1) || (*dst = *src, ++src, ++dst, v9) )
        {
          v10 = v9 & 1;
          v11 = v8 >> 2;
          if ( !v10 || (*(_WORD *)dst = *(_WORD *)src, src += 2, dst += 2, v11) )
          {
            qmemcpy(dst, src, 4 * v11);
            src += 4 * v11;
            dst += 4 * v11;
          }
        }
      }
      else
      {
        src += v8;
        dst += v8;
      }
    }
    while ( v7 );
LABEL_18:
    dst += -frame_width - 768;
  }
  while ( src_end != src );
}

//----- (0048F2BD) --------------------------------------------------------
void __fastcall Cel2DrawHdrOnly(int screen_x, int screen_y, char *pCelBuff, int frame, int frame_width, int a6, int direction)
{
  unsigned __int16 v7; // dx
  int v8; // [esp+Ch] [ebp-1Ch]
  char *pRLEBytes; // [esp+1Ch] [ebp-Ch]
  int frame_content_size; // [esp+20h] [ebp-8h]
  int v11; // [esp+24h] [ebp-4h]

  v8 = screen_y;
  assert(pCelBuff, "ENGINE.CPP", 735);
  pRLEBytes = &pCelBuff[*(_DWORD *)&pCelBuff[4 * frame]];
  v7 = *(_WORD *)&pRLEBytes[a6];
  if ( v7 )
  {
    if ( direction == 8 )
      v11 = 0;
    else
      v11 = *(unsigned __int16 *)&pRLEBytes[direction];
    if ( v11 )
      frame_content_size = v11 - v7;
    else
      frame_content_size = *(_DWORD *)&pCelBuff[4 * frame + 4] - *(_DWORD *)&pCelBuff[4 * frame] - v7;
    Cel2DecDatOnly(
      &gpBuffer[screen_x + screen_y_times_768[v8 - 16 * a6]],
      &pRLEBytes[v7],
      frame_content_size,
      frame_width);
  }
}

//----- (0048F3B7) --------------------------------------------------------
void __fastcall Cel2DecodeHdrOnly(char *pBuff, char *pCelBuff, int frame, int frame_width, int a5, int direction)
{
  unsigned __int16 v6; // dx
  char *v7; // [esp+Ch] [ebp-18h]
  char *pRLEBytes; // [esp+18h] [ebp-Ch]
  int frame_content_size; // [esp+1Ch] [ebp-8h]
  int v10; // [esp+20h] [ebp-4h]

  v7 = pCelBuff;
  assert(pCelBuff, "ENGINE.CPP", 762);
  assert(pBuff, "ENGINE.CPP", 763);
  pRLEBytes = &pCelBuff[*(_DWORD *)&pCelBuff[4 * frame]];
  v6 = *(_WORD *)&pRLEBytes[a5];
  if ( v6 )
  {
    v10 = *(unsigned __int16 *)&pRLEBytes[direction];
    if ( direction == 8 )
      v10 = 0;
    if ( v10 )
      frame_content_size = v10 - v6;
    else
      frame_content_size = *(_DWORD *)&v7[4 * frame + 4] - *(_DWORD *)&v7[4 * frame] - v6;
    Cel2DecDatOnly(pBuff, &pRLEBytes[v6], frame_content_size, frame_width);
  }
}

//----- (0048F4AC) --------------------------------------------------------
void __fastcall Cel2DecDatLightOnly(char *pDecodeTo, char *pRLEBytes, int frame_content_size, int frame_width)
{
  char *v4; // esi
  char *v5; // edi
  char *v6; // ebx
  int v7; // edx
  int v8; // eax
  int v9; // ST00_4

  assert(pDecodeTo, "ENGINE.CPP", 783);
  assert(pRLEBytes, "ENGINE.CPP", 784);
  v4 = pRLEBytes;
  v5 = pDecodeTo;
  v6 = &pRLEBytes[frame_content_size];
  do
  {
    v7 = frame_width;
    do
    {
      while ( 1 )
      {
        v8 = (unsigned __int8)*v4++;
        if ( (v8 & 0x80u) == 0 )
          break;
        LOBYTE(v8) = -(char)v8;
        v5 += v8;
        v7 -= v8;
        if ( !v7 )
          goto LABEL_14;
      }
      v7 -= v8;
      if ( v5 < (char *)gpBufEnd )
      {
        v9 = v7;
        Cel2DecDatLightEntry(v8, v7);
        v7 = v9;
      }
      else
      {
        v4 += v8;
        v5 += v8;
      }
    }
    while ( v7 );
LABEL_14:
    v5 += -frame_width - 768;
  }
  while ( v6 != v4 );
}

//----- (0048F57A) --------------------------------------------------------
void __fastcall Cel2DecDatLightEntry(int a1, int a2)
{
  int v2; // ebx
  _BYTE *v3; // edi
  _BYTE *v4; // esi
  char v5; // cf
  unsigned __int8 v6; // cl
  char v7; // cl
  int v8; // eax
  char v9; // ch
  char v10; // ch
  char v11; // ch

  v5 = a1 & 1;
  v6 = (unsigned __int8)a1 >> 1;
  if ( v5 )
  {
    LOBYTE(a2) = *v4;
    *v3 = *(_BYTE *)(v2 + a2);
    ++v4;
    ++v3;
  }
  v5 = v6 & 1;
  v7 = v6 >> 1;
  if ( v5 )
  {
    LOBYTE(a2) = *v4;
    *v3 = *(_BYTE *)(v2 + a2);
    LOBYTE(a2) = v4[1];
    v3[1] = *(_BYTE *)(v2 + a2);
    v4 += 2;
    v3 += 2;
  }
  for ( ; v7; --v7 )
  {
    v8 = *(_DWORD *)v4;
    v4 += 4;
    LOBYTE(a2) = v8;
    v9 = *(_BYTE *)(v2 + a2);
    LOBYTE(a2) = BYTE1(v8);
    v8 = __ROR4__(v8, 16);
    *v3 = v9;
    v10 = *(_BYTE *)(v2 + a2);
    LOBYTE(a2) = v8;
    v3[1] = v10;
    v11 = *(_BYTE *)(v2 + a2);
    LOBYTE(a2) = BYTE1(v8);
    v3[2] = v11;
    v3[3] = *(_BYTE *)(v2 + a2);
    v3 += 4;
  }
}

//----- (0048F5F4) --------------------------------------------------------
void __fastcall Cel2DecDatLightTrans(char *pDecodeTo, char *pRLEBytes, int frame_content_size, int frame_width)
{
  char *v4; // esi
  unsigned int v5; // edi
  char *v6; // ebx
  int v7; // edx
  unsigned int v8; // eax
  unsigned int v10; // ecx
  char v11; // cf
  unsigned int v12; // ecx
  char *v13; // esi
  _BYTE *v14; // edi
  _BYTE *v18; // edi
  unsigned int v21; // ecx
  _BYTE *v25; // edi
  char *v26; // [esp-4h] [ebp-24h]
  int v27; // [esp+14h] [ebp-Ch]
  BYTE *v28; // [esp+18h] [ebp-8h]

  assert(pDecodeTo, "ENGINE.CPP", 912);
  assert(pRLEBytes, "ENGINE.CPP", 913);
  v28 = &pLightTbl[256 * light_table_index];
  v4 = pRLEBytes;
  v5 = (unsigned int)pDecodeTo;
  v6 = &pRLEBytes[frame_content_size];
  v27 = (unsigned __int8)pDecodeTo & 1;
  do
  {
    v7 = frame_width;
    do
    {
      while ( 1 )
      {
        v8 = (unsigned __int8)*v4++;
        if ( (v8 & 0x80u) != 0 )
          break;
        v26 = v6;
        _EBX = v28;
        v7 -= v8;
        if ( v5 < (unsigned int)gpBufEnd )
        {
          if ( (v5 & 1) == v27 )
          {
            v10 = v8 >> 1;
            if ( !(v8 & 1) )
              goto LABEL_14;
            ++v4;
            ++v5;
            if ( v10 )
            {
LABEL_21:
              v11 = v10 & 1;
              if ( !v11 )
                goto LABEL_30;
              _AL = *v4;
              ASM_XLAT();
              *(_BYTE *)v5 = _AL;
              v4 += 2;
              v5 += 2;
              if ( v21 )
              {
LABEL_30:
                for (v21 = v10 >> 1; v21; --v21)
                {
                  _EAX = *(_DWORD *)v4;
                  v4 += 4;
                  ASM_XLAT();
                  *(_BYTE *)v5 = _EAX;
                  v25 = (_BYTE *)(v5 + 2);
                  _EAX = __ROR4__(_EAX, 16);
                  ASM_XLAT();
                  *v25 = _EAX;
                  v5 = (unsigned int)(v25 + 2);
                }
              }
              goto LABEL_24;
            }
          }
          else
          {
            v10 = v8 >> 1;
            if ( !(v8 & 1) )
              goto LABEL_21;
            _AL = *v4++;
            ASM_XLAT();
            *(_BYTE *)v5++ = _AL;
            if ( v10 )
            {
LABEL_14:
              v11 = v10 & 1;
              if ( !v11 )
                goto LABEL_31;
              v13 = v4 + 1;
              v14 = (_BYTE *)(v5 + 1);
              _AL = *v13;
              v4 = v13 + 1;
              ASM_XLAT();
              *v14 = _AL;
              v5 = (unsigned int)(v14 + 1);
              if ( v12 )
              {
LABEL_31:
                for (v12 = v10 >> 1; v12; --v12)
                {
                  _EAX = *(_DWORD *)v4;
                  v4 += 4;
                  v18 = (_BYTE *)(v5 + 1);
                  _EAX = __ROR4__(_EAX, 8);
                  ASM_XLAT();
                  *v18 = _EAX;
                  _EAX = __ROR4__(_EAX, 16);
                  v18 += 2;
                  ASM_XLAT();
                  *v18 = _EAX;
                  v5 = (unsigned int)(v18 + 1);
                }
              }
              goto LABEL_24;
            }
          }
        }
        else
        {
          v4 += v8;
          v5 += v8;
        }
LABEL_24:
        v6 = v26;
        if ( !v7 )
          goto LABEL_27;
      }
      LOBYTE(v8) = -(char)v8;
      v5 += v8;
      v7 -= v8;
    }
    while ( v7 );
LABEL_27:
    v5 -= frame_width + 768;
    v27 = ((_BYTE)v27 + 1) & 1;
  }
  while ( v6 != v4 );
}

//----- (0048F743) --------------------------------------------------------
void __fastcall Cel2DecodeHdrLight(int screen_x, int screen_y, char *pCelBuff, int frame, int frame_width, int a6, int direction)
{
  unsigned __int16 v7; // dx
  char *pDecodeTo; // [esp+18h] [ebp-10h]
  char *pRLEBytes; // [esp+1Ch] [ebp-Ch]
  char *pRLEBytesa; // [esp+1Ch] [ebp-Ch]
  int frame_content_size; // [esp+20h] [ebp-8h]
  int v13; // [esp+24h] [ebp-4h]

  assert(pCelBuff, "ENGINE.CPP", 1042);
  pRLEBytes = &pCelBuff[*(_DWORD *)&pCelBuff[4 * frame]];
  v7 = *(_WORD *)&pRLEBytes[a6];
  if ( v7 )
  {
    v13 = *(unsigned __int16 *)&pRLEBytes[direction];
    if ( direction == 8 )
      v13 = 0;
    if ( v13 )
      frame_content_size = v13 - v7;
    else
      frame_content_size = *(_DWORD *)&pCelBuff[4 * frame + 4] - *(_DWORD *)&pCelBuff[4 * frame] - v7;
    pRLEBytesa = &pRLEBytes[v7];
    pDecodeTo = &gpBuffer[screen_x + screen_y_times_768[screen_y - 16 * a6]];
    if ( light_table_index )
      Cel2DecDatLightOnly(pDecodeTo, pRLEBytesa, frame_content_size, frame_width);
    else
      Cel2DecDatOnly(pDecodeTo, pRLEBytesa, frame_content_size, frame_width);
  }
}

//----- (0048F85D) --------------------------------------------------------
void __fastcall Cel2DecodeLightTrans(char *dst_buf, char *pCelBuff, int frame, int frame_width, int a5, int direction)
{
  unsigned __int16 v6; // dx
  char *pRLEBytes; // [esp+18h] [ebp-Ch]
  char *pRLEBytesa; // [esp+18h] [ebp-Ch]
  int frame_content_size; // [esp+1Ch] [ebp-8h]
  int v11; // [esp+20h] [ebp-4h]

  assert(pCelBuff, "ENGINE.CPP", 1108);
  pRLEBytes = &pCelBuff[*(_DWORD *)&pCelBuff[4 * frame]];
  v6 = *(_WORD *)&pRLEBytes[a5];
  if ( v6 )
  {
    v11 = *(unsigned __int16 *)&pRLEBytes[direction];
    if ( direction == 8 )
      v11 = 0;
    if ( v11 )
      frame_content_size = v11 - v6;
    else
      frame_content_size = *(_DWORD *)&pCelBuff[4 * frame + 4] - *(_DWORD *)&pCelBuff[4 * frame] - v6;
    pRLEBytesa = &pRLEBytes[v6];
    if ( cel_transparency_active )
    {
      Cel2DecDatLightTrans(dst_buf, pRLEBytesa, frame_content_size, frame_width);
    }
    else if ( light_table_index )
    {
      Cel2DecDatLightOnly(dst_buf, pRLEBytesa, frame_content_size, frame_width);
    }
    else
    {
      Cel2DecDatOnly(dst_buf, pRLEBytesa, frame_content_size, frame_width);
    }
  }
}

//----- (0048F97E) --------------------------------------------------------
void __fastcall Cel2DrawHdrLightRed(int screen_x, int screen_y, char *pCelBuff, int frame, int frame_width, int always_0, int direction, char always_1)
{
  unsigned __int16 v8; // dx
  _BYTE *v9; // esi
  char *v10; // edi
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // eax
  _BYTE *v15; // [esp-4h] [ebp-38h]
  char *v17; // [esp+1Ch] [ebp-18h]
  int v18; // [esp+1Ch] [ebp-18h]
  BYTE *v19; // [esp+20h] [ebp-14h]
  signed int v20; // [esp+24h] [ebp-10h]
  int v21; // [esp+28h] [ebp-Ch]
  int v22; // [esp+2Ch] [ebp-8h]

  assert(pCelBuff, "ENGINE.CPP", 1145);
  v17 = &pCelBuff[*(_DWORD *)&pCelBuff[4 * frame]];
  v8 = *(_WORD *)&v17[always_0];
  if ( v8 )
  {
    if ( direction == 8 )
      v22 = 0;
    else
      v22 = *(unsigned __int16 *)&v17[direction];
    if ( v22 )
      v21 = v22 - v8;
    else
      v21 = *(_DWORD *)&pCelBuff[4 * frame + 4] - *(_DWORD *)&pCelBuff[4 * frame] - v8;
    v18 = (int)&v17[v8];
    if ( light4flag )
      v20 = 1024;
    else
      v20 = 4096;
    if ( always_1 == 2 )
      v20 += 256;
    if ( always_1 >= 4 )
      v20 += ((always_1 - 4) << 8) + 768;
    v19 = &pLightTbl[v20];
    v9 = (_BYTE *)v18;
    v10 = &gpBuffer[screen_x + screen_y_times_768[screen_y - 16 * always_0]];
    v11 = v18 + v21;
    do
    {
      v15 = (_BYTE *)v11;
      v12 = frame_width;
      v13 = 0;
      do
      {
        while ( 1 )
        {
          v14 = (unsigned __int8)*v9++;
          if ( (v14 & 0x80u) == 0 )
            break;
          LOBYTE(v14) = -(char)v14;
          v10 += v14;
          v12 -= v14;
          if ( !v12 )
            goto LABEL_26;
        }
        v12 -= v14;
        if ( v10 < (char *)gpBufEnd )
        {
          do
          {
            LOBYTE(v13) = *v9++;
            *v10 = v19[v13];
            --v14;
            ++v10;
          }
          while ( v14 );
        }
        else
        {
          v9 += v14;
          v10 += v14;
        }
      }
      while ( v12 );
LABEL_26:
      v11 = (int)v15;
      v10 += -frame_width - 768;
    }
    while ( v15 != v9 );
  }
}

//----- (0048FB3E) --------------------------------------------------------
void __fastcall CelDecodeRect(char *pBuff, int always_0, int dst_height, int dst_width, char *pCelBuff, int frame, int frame_width)
{
  char *v7; // ebx
  char *v8; // esi
  char *v9; // edi
  int v10; // ebx
  int v11; // edx
  unsigned int v12; // eax
  unsigned int v13; // ecx
  char v14; // cf
  unsigned int v15; // ecx
  int dst_widtha; // [esp+2Ch] [ebp+Ch]

  assert(pCelBuff, "ENGINE.CPP", 1228);
  assert(pBuff, "ENGINE.CPP", 1229);
  v7 = &pCelBuff[4 * frame];
  v8 = &pCelBuff[*(_DWORD *)v7];
  v9 = &pBuff[always_0 + dst_height * dst_width];
  dst_widtha = frame_width + dst_width;
  v10 = (int)&v8[*((_DWORD *)v7 + 1) - *(_DWORD *)v7];
  do
  {
    v11 = frame_width;
    do
    {
      while ( 1 )
      {
        v12 = (unsigned __int8)*v8++;
        if ( (v12 & 0x80u) == 0 )
          break;
        LOBYTE(v12) = -(char)v12;
        v9 += v12;
        v11 -= v12;
        if ( !v11 )
          goto LABEL_16;
      }
      v11 -= v12;
      v13 = v12 >> 1;
      if ( v12 & 1 )
      {
        *v9++ = *v8++;
        if ( !v13 )
          continue;
      }
      v14 = v13 & 1;
      v15 = v12 >> 2;
      if ( v14 )
      {
        *(_WORD *)v9 = *(_WORD *)v8;
        v8 += 2;
        v9 += 2;
        if ( !v15 )
          continue;
      }
      qmemcpy(v9, v8, 4 * v15);
      v8 += 4 * v15;
      v9 += 4 * v15;
    }
    while ( v11 );
LABEL_16:
    v9 -= dst_widtha;
  }
  while ( (char *)v10 != v8 );
}

//----- (0048FC23) --------------------------------------------------------
void __fastcall CelDecodeClr(char colour, int screen_x, int screen_y, char *pCelBuff, int frame, int frame_width, int a7, int direction)
{
  char *v8; // ebx
  char *v9; // esi
  char *v10; // edi
  int v11; // edx
  int v12; // eax
  int v13; // ecx
  char v14; // al
  int v16; // [esp+14h] [ebp-18h]
  char *v17; // [esp+1Ch] [ebp-10h]
  int v18; // [esp+20h] [ebp-Ch]
  int v19; // [esp+24h] [ebp-8h]

  assert(pCelBuff, "ENGINE.CPP", 1305);
  v8 = &pCelBuff[4 * frame];
  v17 = &pCelBuff[*(_DWORD *)v8];
  v16 = *(unsigned __int16 *)&v17[a7];
  v19 = *(unsigned __int16 *)&v17[direction];
  if ( *(_WORD *)&v17[a7] )
  {
    if ( direction == 8 )
      v19 = 0;
    if ( v19 )
      v18 = v19 - v16;
    else
      v18 = *((_DWORD *)v8 + 1) - *(_DWORD *)v8 - v16;
    v9 = &v17[v16];
    v10 = &gpBuffer[screen_x + screen_y_times_768[screen_y - 16 * a7]];
    do
    {
      v11 = frame_width;
      do
      {
        while ( 1 )
        {
          v12 = (unsigned __int8)*v9++;
          if ( (v12 & 0x80u) == 0 )
            break;
          LOBYTE(v12) = -(char)v12;
          v10 += v12;
          v11 -= v12;
          if ( !v11 )
            goto LABEL_19;
        }
        v11 -= v12;
        for (v13 = v12; v13; --v13)
        {
          v14 = *v9++;
          if ( v14 )
          {
            *(v10 - 768) = colour;
            *(v10 - 1) = colour;
            v10[1] = colour;
            v10[768] = colour;
          }
          ++v10;
      }
      }
      while ( v11 );
LABEL_19:
      v10 += -frame_width - 768;
    }
    while ( &v17[v16 + v18] != v9 );
  }
}

//----- (0048FD5C) --------------------------------------------------------
void __fastcall CelDrawHdrClrHL(char colour, int screen_x, int screen_y, char *pCelBuff, int frame, int frame_width, int a7, int direction)
{
  char *v8; // ebx
  char *v9; // esi
  char *v10; // edi
  int v11; // edx
  int v12; // eax
  int v13; // ecx
  char v14; // al
  int v15; // ecx
  char v16; // al
  int v18; // [esp+14h] [ebp-18h]
  char *v19; // [esp+1Ch] [ebp-10h]
  int v20; // [esp+20h] [ebp-Ch]
  int v21; // [esp+24h] [ebp-8h]

  assert(pCelBuff, "ENGINE.CPP", 1395);
  v8 = &pCelBuff[4 * frame];
  v19 = &pCelBuff[*(_DWORD *)v8];
  v18 = *(unsigned __int16 *)&v19[a7];
  v21 = *(unsigned __int16 *)&v19[direction];
  if ( *(_WORD *)&v19[a7] )
  {
    if ( direction == 8 )
      v21 = 0;
    if ( v21 )
      v20 = v21 - v18;
    else
      v20 = *((_DWORD *)v8 + 1) - *(_DWORD *)v8 - v18;
    v9 = &v19[v18];
    v10 = &gpBuffer[screen_x + screen_y_times_768[screen_y - 16 * a7]];
    do
    {
      v11 = frame_width;
      do
      {
        while ( 1 )
        {
          v12 = (unsigned __int8)*v9++;
          if ( (v12 & 0x80u) == 0 )
            break;
          LOBYTE(v12) = -(char)v12;
          v10 += v12;
          v11 -= v12;
          if ( !v11 )
            goto LABEL_27;
        }
        v11 -= v12;
        if ( v10 < (char *)gpBufEnd )
        {
          if ( v10 >= (char *)gpBufEnd - 768 )
          {
            for (v15 = v12; v15; --v15)
            {
              v16 = *v9++;
              if ( v16 )
              {
                *(v10 - 768) = colour;
                *(v10 - 1) = colour;
                v10[1] = colour;
              }
              ++v10;
            }
          }
          else
          {
            for (v13 = v12; v13; --v13)
            {
              v14 = *v9++;
              if ( v14 )
              {
                *(v10 - 768) = colour;
                *(v10 - 1) = colour;
                v10[1] = colour;
                v10[768] = colour;
              }
              ++v10;
            }
          }
        }
        else
        {
          v9 += v12;
          v10 += v12;
        }
      }
      while ( v11 );
LABEL_27:
      v10 += -frame_width - 768;
    }
    while ( &v19[v18 + v20] != v9 );
  }
}

//----- (0048FEDC) --------------------------------------------------------
void __fastcall Cl2ApplyTrans(char *p, char *ttbl, int last_frame)
{
  char *v3; // ebx
  char *v4; // esi
  int v5; // edx
  char *v6; // edi
  int v8; // eax
  int v9; // ecx
  int i; // [esp+14h] [ebp-4h]

  assert(p, "ENGINE.CPP", 1495);
  assert(ttbl, "ENGINE.CPP", 1496);
  for ( i = 1; i <= last_frame; ++i )
  {
    v3 = &p[4 * i];
    v4 = &p[*(_DWORD *)v3 + 10];
    v5 = *((_DWORD *)v3 + 1) - *(_DWORD *)v3 - 10;
    v6 = &p[*(_DWORD *)v3 + 10];
    _EBX = ttbl;
    while ( 1 )
    {
      v8 = (unsigned __int8)*v4++;
      *v6++ = v8;
      if ( !--v5 )
        break;
      if ( (v8 & 0x80u) == 0 )
      {
        v5 -= v8;
        for (v9 = v8; v9; --v9)
        {
          _AL = *v4++;
          ASM_XLAT();
          *v6++ = _AL;
        }
        if ( !v5 )
          break;
      }
    }
  }
}

//----- (0048FF98) --------------------------------------------------------
void __fastcall ENG_set_pixel(int screen_x, int screen_y, char pixel)
{
  char *v3; // [esp+14h] [ebp-4h]

  if ( screen_y >= 0 && screen_y < 640 && screen_x >= 64 && screen_x < 704 )
  {
    v3 = &gpBuffer[screen_x + screen_y_times_768[screen_y]];
    if ( v3 < (char *)gpBufEnd )
      *v3 = pixel;
  }
}

//----- (00490016) --------------------------------------------------------
void __fastcall engine_draw_pixel(int x, int y)
{
  char *v2; // [esp+14h] [ebp-4h]

  if ( dword_649AFC )
  {
    if ( dword_649B0C && (x < 0 || x >= 640 || y < 64 || y >= 704) )
      return;
    v2 = &gpBuffer[y + screen_y_times_768[x]];
LABEL_18:
    if ( v2 < (char *)gpBufEnd )
      *v2 = byte_649AF8;
    return;
  }
  if ( !dword_649B0C || y >= 0 && y < 640 && x >= 64 && x < 704 )
  {
    v2 = &gpBuffer[x + screen_y_times_768[y]];
    goto LABEL_18;
  }
}

//----- (0049010D) --------------------------------------------------------
void __fastcall engine_draw_automap_pixels(int x1, int y1, int x2, int y2, char a5)
{
  int v5; // ST18_4
  int v6; // ST2C_4
  int v7; // ST20_4
  int v8; // [esp+Ch] [ebp-48h]
  int v9; // [esp+10h] [ebp-44h]
  int v10; // [esp+14h] [ebp-40h]
  int v11; // [esp+18h] [ebp-3Ch]
  signed int v12; // [esp+1Ch] [ebp-38h]
  int v13; // [esp+20h] [ebp-34h]
  int v14; // [esp+24h] [ebp-30h]
  int v15; // [esp+28h] [ebp-2Ch]
  int y; // [esp+2Ch] [ebp-28h]
  int ya; // [esp+2Ch] [ebp-28h]
  int yb; // [esp+2Ch] [ebp-28h]
  int yc; // [esp+2Ch] [ebp-28h]
  int j; // [esp+30h] [ebp-24h]
  int i; // [esp+30h] [ebp-24h]
  int x; // [esp+34h] [ebp-20h]
  int xa; // [esp+34h] [ebp-20h]
  int xb; // [esp+34h] [ebp-20h]
  int xc; // [esp+34h] [ebp-20h]
  int xd; // [esp+34h] [ebp-20h]
  int xe; // [esp+34h] [ebp-20h]
  int xf; // [esp+34h] [ebp-20h]
  int xg; // [esp+34h] [ebp-20h]
  int xh; // [esp+34h] [ebp-20h]
  int v31; // [esp+38h] [ebp-1Ch]
  int v32; // [esp+3Ch] [ebp-18h]
  int v33; // [esp+3Ch] [ebp-18h]
  int v34; // [esp+3Ch] [ebp-18h]
  signed int v35; // [esp+40h] [ebp-14h]
  signed int v36; // [esp+44h] [ebp-10h]
  int v37; // [esp+48h] [ebp-Ch]
  int v38; // [esp+48h] [ebp-Ch]
  int v39; // [esp+4Ch] [ebp-8h]
  int v40; // [esp+4Ch] [ebp-8h]
  int v41; // [esp+50h] [ebp-4h]
  int x2a; // [esp+5Ch] [ebp+8h]

  v8 = y1;
  v9 = x1;
  byte_649AF8 = a5;
  dword_649B0C = 0;
  if ( x1 < 64 || x1 >= 704 )
    dword_649B0C = 1;
  if ( x2 < 64 || x2 >= 704 )
    dword_649B0C = 1;
  if ( y1 < 160 || y1 >= 512 )
    dword_649B0C = 1;
  if ( y2 < 160 || y2 >= 512 )
    dword_649B0C = 1;
  if ( x2 - x1 < 0 )
    v36 = -1;
  else
    v36 = 1;
  v11 = v36 * (x2 - x1);
  if ( y2 - y1 < 0 )
    v35 = -1;
  else
    v35 = 1;
  v10 = v35 * (y2 - y1);
  if ( v35 == v36 )
    v12 = 1;
  else
    v12 = -1;
  if ( v11 >= v10 )
  {
    dword_649AFC = 0;
  }
  else
  {
    v8 = y1 ^ x1 ^ y1;
    v9 = v8 ^ y1 ^ x1;
    x2a = y2 ^ x2;
    y2 ^= x2a;
    x2 = y2 ^ x2a;
    v5 = v10 ^ v11;
    v10 ^= v5;
    v11 = v10 ^ v5;
    dword_649AFC = 1;
  }
  if ( x2 >= v9 )
  {
    x = v9;
    y = v8;
    v32 = x2;
    v13 = y2;
  }
  else
  {
    x = x2;
    y = y2;
    v32 = v9;
    v13 = v8;
  }
  v31 = (v11 - 1) / 4;
  v41 = (((v11 - 1) >> 31) ^ abs(v11 - 1) & 3) - ((v11 - 1) >> 31);
  engine_draw_pixel(x, y);
  engine_draw_pixel(v32, v13);
  v14 = 4 * v10 - 2 * v11;
  if ( v14 >= 0 )
  {
    v40 = 2 * (v10 - v11);
    v15 = 4 * (v10 - v11);
    v38 = v15 + v11;
    for ( i = 0; i < v31; ++i )
    {
      xe = x + 1;
      v34 = v32 - 1;
      if ( v38 <= 0 )
      {
        if ( v40 <= v38 )
        {
          y += v12;
          engine_draw_pixel(xe, y);
          x = xe + 1;
          engine_draw_pixel(x, y);
          v13 -= v12;
          engine_draw_pixel(v34, v13);
        }
        else
        {
          engine_draw_pixel(xe, y);
          y += v12;
          x = xe + 1;
          engine_draw_pixel(x, y);
          engine_draw_pixel(v34, v13);
          v13 -= v12;
        }
        v32 = v34 - 1;
        engine_draw_pixel(v32, v13);
        v38 += v14;
      }
      else
      {
        v6 = v12 + y;
        engine_draw_pixel(xe, v6);
        y = v12 + v6;
        x = xe + 1;
        engine_draw_pixel(x, y);
        v7 = v13 - v12;
        engine_draw_pixel(v34, v7);
        v13 = v7 - v12;
        v32 = v34 - 1;
        engine_draw_pixel(v32, v13);
        v38 += v15;
      }
    }
    if ( v41 )
    {
      if ( v38 <= 0 )
      {
        if ( v40 <= v38 )
        {
          yc = v12 + y;
          xh = x + 1;
          engine_draw_pixel(xh, yc);
          if ( v41 > 1 )
            engine_draw_pixel(xh + 1, yc);
          if ( v41 > 2 )
          {
            if ( v40 >= v38 )
              engine_draw_pixel(v32 - 1, v13);
            else
              engine_draw_pixel(v32 - 1, v13 - v12);
          }
        }
        else
        {
          xg = x + 1;
          engine_draw_pixel(xg, y);
          if ( v41 > 1 )
            engine_draw_pixel(xg + 1, v12 + y);
          if ( v41 > 2 )
            engine_draw_pixel(v32 - 1, v13);
        }
      }
      else
      {
        yb = v12 + y;
        xf = x + 1;
        engine_draw_pixel(xf, yb);
        if ( v41 > 1 )
          engine_draw_pixel(xf + 1, v12 + yb);
        if ( v41 > 2 )
          engine_draw_pixel(v32 - 1, v13 - v12);
      }
    }
  }
  else
  {
    v39 = 2 * v10;
    v37 = 4 * v10 - v11;
    for ( j = 0; j < v31; ++j )
    {
      xa = x + 1;
      v33 = v32 - 1;
      if ( v37 >= 0 )
      {
        if ( v39 <= v37 )
        {
          y += v12;
          engine_draw_pixel(xa, y);
          x = xa + 1;
          engine_draw_pixel(x, y);
          v13 -= v12;
          engine_draw_pixel(v33, v13);
        }
        else
        {
          engine_draw_pixel(xa, y);
          y += v12;
          x = xa + 1;
          engine_draw_pixel(x, y);
          engine_draw_pixel(v33, v13);
          v13 -= v12;
        }
        v32 = v33 - 1;
        engine_draw_pixel(v32, v13);
        v37 += v14;
      }
      else
      {
        engine_draw_pixel(xa, y);
        x = xa + 1;
        engine_draw_pixel(x, y);
        engine_draw_pixel(v33, v13);
        v32 = v33 - 1;
        engine_draw_pixel(v32, v13);
        v37 += 4 * v10;
      }
    }
    if ( v41 )
    {
      if ( v37 >= 0 )
      {
        if ( v39 <= v37 )
        {
          ya = v12 + y;
          xd = x + 1;
          engine_draw_pixel(xd, ya);
          if ( v41 > 1 )
            engine_draw_pixel(xd + 1, ya);
          if ( v41 > 2 )
            engine_draw_pixel(v32 - 1, v13 - v12);
        }
        else
        {
          xc = x + 1;
          engine_draw_pixel(xc, y);
          if ( v41 > 1 )
            engine_draw_pixel(xc + 1, v12 + y);
          if ( v41 > 2 )
            engine_draw_pixel(v32 - 1, v13);
        }
      }
      else
      {
        xb = x + 1;
        engine_draw_pixel(xb, y);
        if ( v41 > 1 )
          engine_draw_pixel(xb + 1, y);
        if ( v41 > 2 )
          engine_draw_pixel(v32 - 1, v13);
      }
    }
  }
}

//----- (004907BD) --------------------------------------------------------
int __fastcall GetDirection(int x1, int y1, int x2, int y2)
{
  int v5; // [esp+14h] [ebp-Ch]
  int v6; // [esp+18h] [ebp-8h]
  int v7; // [esp+1Ch] [ebp-4h]

  v7 = x2 - x1;
  v6 = y2 - y1;
  if ( x2 - x1 < 0 )
  {
    if ( v6 < 0 )
    {
      v5 = 4;
      if ( 2 * (x1 - x2) < y1 - y2 )
        v5 = 5;
      if ( 2 * (y1 - y2) < x1 - x2 )
        v5 = 3;
    }
    else
    {
      v5 = 2;
      if ( 2 * (x1 - x2) < v6 )
        v5 = 1;
      if ( 2 * v6 < x1 - x2 )
        v5 = 3;
    }
  }
  else if ( v6 < 0 )
  {
    v5 = 6;
    if ( 2 * v7 < y1 - y2 )
      v5 = 5;
    if ( 2 * (y1 - y2) < v7 )
      v5 = 7;
  }
  else
  {
    v5 = 0;
    if ( 2 * v7 < v6 )
      v5 = 1;
    if ( 2 * v6 < v7 )
      v5 = 7;
  }
  return v5;
}

//----- (004908FE) --------------------------------------------------------
void __fastcall SetRndSeed(int s)
{
  sglGameSeed = s;
  orgseed = s;
  SeedCount = 0;
}

//----- (0049092E) --------------------------------------------------------
int __cdecl GetRndSeed()
{
  ++SeedCount;
  sglGameSeed = 22695477 * sglGameSeed + 1;
  return abs(sglGameSeed);
}

//----- (00490963) --------------------------------------------------------
int __fastcall random(int idx, int v)
{
  if ( v <= 0 )
    return 0;
  if ( v >= 0xFFFF )
    return GetRndSeed() % v;
  return (GetRndSeed() >> 16) % v;
}

//----- (004909B8) --------------------------------------------------------
void *__fastcall DiabloAllocPtr(int dwBytes, int line, char *file)
{
  void *v4; // [esp+14h] [ebp-4h]

  v4 = (void *)SMemAlloc(dwBytes, file, line);
  if ( !v4 )
    TermMsg("Out of memory");
  return v4;
}

//----- (00490A01) --------------------------------------------------------
void __fastcall mem_free_dbg(void *ptr, int line, char *file)
{
  if ( ptr )
    SMemFree(ptr, file, line);
}

//----- (00490A37) --------------------------------------------------------
unsigned __int8 *__fastcall LoadFileInMem(char *pszName, int *pdwFileLen, int line, char *file)
{
  int *v5; // [esp+Ch] [ebp-18h]
  char *v6; // [esp+10h] [ebp-14h]
  int v7; // [esp+14h] [ebp-10h]
  int dwBytes; // [esp+18h] [ebp-Ch]
  unsigned __int8 *v9; // [esp+1Ch] [ebp-8h]
  int v10; // [esp+20h] [ebp-4h]

  v5 = pdwFileLen;
  v6 = pszName;
  assert(pszName, "ENGINE.CPP", 1873);
  if ( !SFileOpenFile(pszName, &v7) )
    TermMsg("Unable to open SFILE:\n%s", v6);
  dwBytes = SFileGetFileSize(v7, 0);
  if ( v5 )
    *v5 = dwBytes;
  v9 = (unsigned __int8 *)DiabloAllocPtr(dwBytes, line, file);
  v10 = SFileReadFile(v7, (int)v9, dwBytes, 0, 0);
  assert(v10, "ENGINE.CPP", 1887);
  v10 = SFileCloseFile(v7);
  assert(v10, "ENGINE.CPP", 1890);
  return v9;
}

//----- (00490B2B) --------------------------------------------------------
void __fastcall LoadFileWithMem(char *pszName, void *buf)
{
  int v4; // [esp+14h] [ebp-Ch]
  int v5; // [esp+18h] [ebp-8h]
  int v6; // [esp+1Ch] [ebp-4h]

  assert(buf, "ENGINE.CPP", 1900);
  assert(pszName, "ENGINE.CPP", 1901);
  if ( !SFileOpenFile(pszName, &v4) )
    TermMsg("Unable to open SFILE:\n%s", pszName);
  v5 = SFileGetFileSize(v4, 0);
  v6 = SFileReadFile(v4, (int)buf, v5, 0, 0);
  assert(v6, "ENGINE.CPP", 1907);
  v6 = SFileCloseFile(v4);
  assert(v6, "ENGINE.CPP", 1910);
}

