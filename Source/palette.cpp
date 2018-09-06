//----- (0048DD10) --------------------------------------------------------
void __cdecl SaveGamma()
{
  SRegSaveValue("Diablo", "Gamma Correction", 0, gamma_correction);
}

//----- (0048DD37) --------------------------------------------------------
void __cdecl palette_init()
{
  int error_code; // [esp+Ch] [ebp-4h]
  int error_codea; // [esp+Ch] [ebp-4h]

  LoadGamma();
  memcpy(system_palette, orig_palette, 0x400u);
  LoadSysPal();
  error_code = lpDD->lpVtbl->CreatePalette(lpDD, 4, (LPPALETTEENTRY)system_palette, &lpDDPalette, 0);
  if ( error_code )
    DDErrDlg(error_code, 119, "PALETTE.CPP");
  error_codea = lpDDSPrimary->lpVtbl->SetPalette(lpDDSPrimary, lpDDPalette);
  if ( error_codea )
    DDErrDlg(error_codea, 121, "PALETTE.CPP");
}

//----- (0048DDE7) --------------------------------------------------------
void __cdecl LoadGamma()
{
  int v0; // [esp+Ch] [ebp-4h]

  v0 = gamma_correction;
  if ( !SRegLoadValue("Diablo", "Gamma Correction", 0, &v0) )
    v0 = 100;
  gamma_correction = v0;
  if ( v0 >= 30 )
  {
    if ( gamma_correction > 100 )
      gamma_correction = 100;
  }
  else
  {
    gamma_correction = 30;
  }
  gamma_correction -= gamma_correction % 5;
}

//----- (0048DE7A) --------------------------------------------------------
void __cdecl LoadSysPal()
{
  signed int iStart; // [esp+Ch] [ebp-8h]
  signed int iStarta; // [esp+Ch] [ebp-8h]
  signed int iStartb; // [esp+Ch] [ebp-8h]
  HDC hdc; // [esp+10h] [ebp-4h]

  for ( iStart = 0; iStart < 256; ++iStart )
    system_palette[iStart].peFlags = 5;
  if ( !fullscreen )
  {
    hdc = GetDC(0);
    gdwPalEntries = GetDeviceCaps(hdc, 24) / 2;
    GetSystemPaletteEntries(hdc, 0, gdwPalEntries, (LPPALETTEENTRY)system_palette);
    for ( iStarta = 0; (signed int)gdwPalEntries > iStarta; ++iStarta )
      system_palette[iStarta].peFlags = 0;
    iStartb = 256 - gdwPalEntries;
    GetSystemPaletteEntries(
      hdc,
      256 - gdwPalEntries,
      gdwPalEntries,
      (LPPALETTEENTRY)&system_palette[256 - gdwPalEntries]);
    while ( iStartb < 256 )
      system_palette[iStartb++].peFlags = 0;
    ReleaseDC(0, hdc);
  }
}

//----- (0048DF8F) --------------------------------------------------------
void __fastcall LoadPalette(char *pszFileName)
{
  char v2; // [esp+10h] [ebp-308h]
  char v3; // [esp+11h] [ebp-307h]
  char v4[766]; // [esp+12h] [ebp-306h]
  int v5; // [esp+310h] [ebp-8h]
  int i; // [esp+314h] [ebp-4h]

  assert(pszFileName, 135, "PALETTE.CPP");
  if ( !SFileOpenFile(pszFileName, &v5) )
    TermMsg("Unable to open file %s", pszFileName);
  SFileReadFile(v5, (int)&v2, 768, 0, 0);
  SFileCloseFile(v5);
  for ( i = 0; i < 256; ++i )
  {
    orig_palette[i].peRed = *(&v2 + 3 * i);
    orig_palette[i].peGreen = *(&v3 + 3 * i);
    orig_palette[i].peBlue = v4[3 * i];
    orig_palette[i].peFlags = 0;
  }
}

//----- (0048E08B) --------------------------------------------------------
void __fastcall LoadRndLvlPal(int l)
{
  int v1; // eax
  char pszFileName[260]; // [esp+14h] [ebp-104h]

  if ( l )
  {
    v1 = random(0, 4);
    sprintf(pszFileName, "Levels\\L%iData\\L%i_%i.PAL", l, l, v1 + 1);
    LoadPalette(pszFileName);
  }
  else
  {
    LoadPalette("Levels\\TownData\\Town.pal");
  }
}

//----- (0048E157) --------------------------------------------------------
void __cdecl palette_update()
{
  DWORD v0; // [esp+Ch] [ebp-Ch]
  int error_code; // [esp+10h] [ebp-8h]
  DWORD v2; // [esp+14h] [ebp-4h]

  if ( lpDDPalette )
  {
    v0 = 0;
    v2 = 256;
    if ( !fullscreen )
    {
      v0 = gdwPalEntries;
      v2 = 256 - 2 * gdwPalEntries;
    }
    error_code = lpDDPalette->lpVtbl->SetEntries(lpDDPalette, 0, v0, v2, (LPPALETTEENTRY)&system_palette[v0]);
    if ( error_code )
      DDErrDlg(error_code, 45, "PALETTE.CPP");
  }
}

//----- (0048E1FA) --------------------------------------------------------
void __cdecl IncreaseGamma()
{
  if ( gamma_correction < 100 )
  {
    gamma_correction += 5;
    if ( gamma_correction > 100 )
      gamma_correction = 100;
    ApplyGamma(system_palette, logical_palette, 0);
    palette_update();
  }
}

//----- (0048E250) --------------------------------------------------------
void __fastcall ApplyGamma(PALETTEENTRY *dst, PALETTEENTRY *src, int n)
{
  PALETTEENTRY *v3; // [esp+38h] [ebp-14h]
  PALETTEENTRY *v4; // [esp+3Ch] [ebp-10h]
  double v5; // [esp+40h] [ebp-Ch]
  int v6; // [esp+48h] [ebp-4h]
  int v7; // [esp+58h] [ebp+Ch]

  v3 = src;
  v4 = dst;
  v5 = (double)gamma_correction / 100.0;
  v6 = n;
  while ( v7 > v6 )
  {
    v4->peRed = (signed __int64)(pow((double)v3->peRed / 256.0, v5) * 256.0);
    v4->peGreen = (signed __int64)(pow((double)v3->peGreen / 256.0, v5) * 256.0);
    v4->peBlue = (signed __int64)(pow((double)v3->peBlue / 256.0, v5) * 256.0);
    ++v6;
    ++v4;
    ++v3;
  }
}

//----- (0048E36A) --------------------------------------------------------
void __cdecl DecreaseGamma()
{
  if ( gamma_correction > 30 )
  {
    gamma_correction -= 5;
    if ( gamma_correction < 30 )
      gamma_correction = 30;
    ApplyGamma(system_palette, logical_palette, 0);
    palette_update();
  }
}

//----- (0048E3C0) --------------------------------------------------------
int __fastcall UpdateGamma(int gamma)
{
  if ( gamma )
  {
    gamma_correction = 100 - gamma + 30;
    ApplyGamma(system_palette, logical_palette, 0);
    palette_update();
  }
  return 100 - gamma_correction + 30;
}

//----- (0048E419) --------------------------------------------------------
void __fastcall PaletteFadeIn(int fr)
{
  int brightness; // [esp+10h] [ebp-4h]

  ApplyGamma(logical_palette, orig_palette, 0);
  for ( brightness = 0; brightness < 256; brightness += fr )
    SetFadeLevel(brightness);
  SetFadeLevel(256);
  memcpy(logical_palette, orig_palette, 0x400u);
}

//----- (0048E492) --------------------------------------------------------
void __fastcall SetFadeLevel(int brightness)
{
  signed int i; // [esp+14h] [ebp-4h]

  for ( i = 0; i < 256; ++i )
  {
    system_palette[i].peRed = (unsigned __int16)(brightness * logical_palette[i].peRed) >> 8;
    system_palette[i].peGreen = (unsigned __int16)(brightness * logical_palette[i].peGreen) >> 8;
    system_palette[i].peBlue = (unsigned __int16)(brightness * logical_palette[i].peBlue) >> 8;
  }
  Sleep(3u);
  lpDD->lpVtbl->WaitForVerticalBlank(lpDD, 1, 0);
  palette_update();
}

//----- (0048E54A) --------------------------------------------------------
void __fastcall PaletteFadeOut(int fr)
{
  int brightness; // [esp+10h] [ebp-4h]

  for ( brightness = 256; brightness > 0; brightness -= fr )
    SetFadeLevel(brightness);
  SetFadeLevel(0);
}

//----- (0048E594) --------------------------------------------------------
void __cdecl palette_update_caves()
{
  signed int i; // [esp+Ch] [ebp-8h]
  PALETTEENTRY v1; // [esp+10h] [ebp-4h]

  v1 = system_palette[1];
  for ( i = 1; i < 31; ++i )
  {
    system_palette[i].peRed = system_palette[i + 1].peRed;
    system_palette[i].peGreen = system_palette[i + 1].peGreen;
    system_palette[i].peBlue = system_palette[i + 1].peBlue;
  }
  system_palette[i].peRed = v1.peRed;
  system_palette[i].peGreen = v1.peGreen;
  system_palette[i].peBlue = v1.peBlue;
  palette_update();
}

//----- (0048E692) --------------------------------------------------------
void __fastcall palette_update_quest_palette(int n)
{
  int i; // [esp+10h] [ebp-4h]

  for ( i = 32 - n; i >= 0; --i )
    logical_palette[i] = orig_palette[i];
  ApplyGamma(system_palette, logical_palette, 0);
  palette_update();
}

