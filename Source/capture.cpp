//----- (00435DE0) --------------------------------------------------------
void __cdecl CaptureScreen()
{
  PALETTEENTRY pal; // [esp+Ch] [ebp-50Ch]
  HANDLE hObject; // [esp+40Ch] [ebp-10Ch]
  BOOL v2; // [esp+410h] [ebp-108h]
  char FileName[260]; // [esp+414h] [ebp-104h]

  hObject = CaptureFile(FileName);
  if ( hObject == (HANDLE)-1 )
  {
    MessageBeep(0);
  }
  else
  {
    assert(gpBuffer, "capture.cpp", 247);
    DrawAndBlit();
    lpDDPalette->lpVtbl->GetEntries(lpDDPalette, 0, 0, 256, (LPPALETTEENTRY)&pal);
    RedPalette(&pal);
    v2 = CaptureHdr(hObject, 640, 480);
    if ( v2 )
      v2 = CapturePix(hObject, 0x280u, 0x1E0u, 0x300u, (BYTE *)gpBuffer + 122944);
    if ( v2 )
      v2 = CapturePal(hObject, &pal);
    CloseHandle(hObject);
    if ( !v2 )
    {
      DeleteFileA(FileName);
      MessageBeep(0);
    }
    Sleep(0x12Cu);
    lpDDPalette->lpVtbl->SetEntries(lpDDPalette, 0, 0, 256, (LPPALETTEENTRY)&pal);
  }
}

//----- (00435F43) --------------------------------------------------------
BOOL __fastcall CaptureHdr(HANDLE hFile, __int16 width, __int16 height)
{
  __int16 v3; // ST20_2
  HANDLE v4; // ST24_4
  int NumberOfBytesWritten; // [esp+14h] [ebp-84h]
  char Buffer[128]; // [esp+18h] [ebp-80h]

  v3 = width;
  v4 = hFile;
  memset(Buffer, 0, 0x80u);
  Buffer[0] = 10;
  Buffer[1] = 5;
  Buffer[2] = 1;
  Buffer[3] = 8;
  *(_WORD *)&Buffer[8] = v3 - 1;
  *(_WORD *)&Buffer[10] = height - 1;
  *(_WORD *)&Buffer[12] = v3;
  *(_WORD *)&Buffer[14] = height;
  Buffer[65] = 1;
  *(_WORD *)&Buffer[66] = v3;
  return WriteFile(v4, Buffer, 0x80u, (LPDWORD)&NumberOfBytesWritten, 0) && NumberOfBytesWritten == 128;
}

//----- (0043600D) --------------------------------------------------------
BOOL __fastcall CapturePal(HANDLE hFile, PALETTEENTRY *palette)
{
  int NumberOfBytesWritten; // [esp+14h] [ebp-30Ch]
  int i; // [esp+18h] [ebp-308h]
  char Buffer; // [esp+1Ch] [ebp-304h]
  char v6[256][3]; // [esp+1Dh] [ebp-303h]

  Buffer = 12;
  for ( i = 0; i < 256; ++i )
  {
    v6[i][0] = palette[i].peRed;
    v6[i][1] = palette[i].peGreen;
    v6[i][2] = palette[i].peBlue;
  }
  return WriteFile(hFile, &Buffer, 0x301u, (LPDWORD)&NumberOfBytesWritten, 0) && NumberOfBytesWritten == 769;
}

//----- (00436105) --------------------------------------------------------
BOOL __fastcall CapturePix(HANDLE hFile, WORD width, WORD height, WORD stride, BYTE *pixels)
{
  WORD v5; // ST28_2
  WORD v7; // [esp+Ch] [ebp-1Ch]
  HANDLE hFilea; // [esp+10h] [ebp-18h]
  int NumberOfBytesWritten; // [esp+18h] [ebp-10h]
  int nNumberOfBytesToWrite; // [esp+1Ch] [ebp-Ch]
  BYTE *v11; // [esp+20h] [ebp-8h]
  BYTE *lpBuffer; // [esp+24h] [ebp-4h]

  v7 = width;
  hFilea = hFile;
  lpBuffer = (BYTE *)DiabloAllocPtr(2 * width, 169, "capture.cpp");
  while ( 1 )
  {
    v5 = height--;
    if ( !v5 )
      break;
    v11 = CaptureEnc(pixels, lpBuffer, v7);
    pixels += stride;
    nNumberOfBytesToWrite = v11 - lpBuffer;
    if ( !WriteFile(hFilea, lpBuffer, v11 - lpBuffer, (LPDWORD)&NumberOfBytesWritten, 0) )
      return 0;
    if ( NumberOfBytesWritten != nNumberOfBytesToWrite )
      return 0;
  }
  mem_free_dbg(lpBuffer, 179, "capture.cpp");
  return 1;
}

//----- (004361DC) --------------------------------------------------------
BYTE *__fastcall CaptureEnc(BYTE *src, BYTE *dst, int width)
{
  BYTE *v4; // [esp+Ch] [ebp-10h]
  BYTE *v5; // [esp+10h] [ebp-Ch]
  signed int v6; // [esp+14h] [ebp-8h]
  BYTE v7; // [esp+18h] [ebp-4h]

  v4 = dst;
  v5 = src;
  do
  {
    v7 = *v5++;
    v6 = 1;
    --width;
    while ( *v5 == v7 && v6 < 63 && width )
    {
      ++v6;
      --width;
      ++v5;
    }
    if ( v6 > 1 || (signed int)v7 > 191 )
      *v4++ = v6 | 0xC0;
    *v4++ = v7;
  }
  while ( width );
  return v4;
}

//----- (00436286) --------------------------------------------------------
HANDLE __fastcall CaptureFile(char *dst_path)
{
  int v2; // [esp-4h] [ebp-198h]
  char v4[100]; // [esp+10h] [ebp-184h]
  int i; // [esp+74h] [ebp-120h]
  int v6; // [esp+78h] [ebp-11Ch]
  struct _finddata_t v7; // [esp+7Ch] [ebp-118h]

  memset(v4, 0, 0x64u);
  v6 = _findfirst("screen??.PCX", &v7);
  if ( v6 != -1 )
  {
    do
    {
      if ( isdigit(v7.name[6]) )
      {
        if ( isdigit(v7.name[7]) )
        {
          i = 2 * (5 * v7.name[6] - 240);
          i += v7.name[7] - 48;
          v4[i] = 1;
        }
      }
    }
    while ( !_findnext(v6, &v7) );
  }
  for ( i = 0; i < 100; ++i )
  {
    if ( !v4[i] )
    {
      v2 = i;
      sprintf(dst_path, "screen%02d.PCX", i);
      return CreateFileA(dst_path, 0x40000000u, 0, 0, 2u, 0x80u, 0);
    }
  }
  return (HANDLE)-1;
}

//----- (004363EF) --------------------------------------------------------
void __fastcall RedPalette(PALETTEENTRY *pal)
{
  signed int i; // [esp+10h] [ebp-404h]
  PALETTEENTRY v2[256]; // [esp+14h] [ebp-400h]

  for ( i = 0; i < 256; ++i )
  {
    v2[i].peRed = pal[i].peRed;
    v2[i].peGreen = 0;
    v2[i].peBlue = 0;
    v2[i].peFlags = 0;
  }
  lpDDPalette->lpVtbl->SetEntries(lpDDPalette, 0, 0, 256, (LPPALETTEENTRY)v2);
}

