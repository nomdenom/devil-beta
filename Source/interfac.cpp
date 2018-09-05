//----- (0041E310) --------------------------------------------------------
BOOL __cdecl IncProgress()
{
  sgdwProgress += 15;
  if ( (unsigned int)sgdwProgress > 0x216 )
    sgdwProgress = 534;
  if ( sgpBackCel )
    DrawCutscene();
  return (unsigned int)sgdwProgress >= 0x216;
}

//----- (0041E36F) --------------------------------------------------------
void __cdecl DrawCutscene()
{
  unsigned int i; // [esp+Ch] [ebp-4h]

  if ( !sgpBackCel )
    assertion_failed(208, "C:\\Diablo\\Direct\\Interfac.cpp");
  CelDecodeOnly(64, 639, sgpBackCel, 1, 640);
  for ( i = 0; i < sgdwProgress; ++i )
    DrawProgress(
      i + progress_bar_screen_pos[progress_id][0] + 64,
      progress_bar_screen_pos[progress_id][1] + 160,
      progress_id);
  drawpanflag = 255;
  scrollrt_draw_game_screen(1);
}

//----- (0041E426) --------------------------------------------------------
void __fastcall DrawProgress(int screen_x, int screen_y, int progress_id)
{
  char *v3; // [esp+14h] [ebp-8h]
  signed int i; // [esp+18h] [ebp-4h]

  if ( !gpBuffer )
    assertion_failed(192, "C:\\Diablo\\Direct\\Interfac.cpp");
  v3 = &gpBuffer[screen_x + screen_y_times_768[screen_y]];
  for ( i = 0; i < 22; ++i )
  {
    *v3 = progress_bar_colours[progress_id];
    v3 += 768;
  }
}

//----- (0041E4AB) --------------------------------------------------------
void __fastcall ShowProgress(int uMsg)
{
  WNDPROC func; // [esp+14h] [ebp-4h]

  if ( !ghMainWnd )
    assertion_failed(256, "C:\\Diablo\\Direct\\Interfac.cpp");
  func = SetWindowProc(interfac_41F03E_wndproc);
  ClearScreenBuffer();
  scrollrt_draw_game_screen(1);
  InitCutscene(uMsg);
  DrawCutscene();
  PaletteFadeIn(8);
  IncProgress();
  effects_467FE5();
  IncProgress();
  switch ( uMsg )
  {
    case 0x402:
      IncProgress();
      if ( gbMaxPlayers == 1 )
        SaveLevel();
      else
        DeltaSaveLevel();
      FreeGameMem();
      leveltype = gnLevelTypeTbl[++currlevel];
      if ( plr[myplr].plrlevel != currlevel )
        assertion_failed(293, "C:\\Diablo\\Direct\\Interfac.cpp");
      IncProgress();
      LoadGameLevel(0, 0);
      IncProgress();
      break;
    case 0x403:
      IncProgress();
      if ( gbMaxPlayers == 1 )
        SaveLevel();
      else
        DeltaSaveLevel();
      IncProgress();
      FreeGameMem();
      leveltype = gnLevelTypeTbl[--currlevel];
      if ( plr[myplr].plrlevel != currlevel )
        assertion_failed(308, "C:\\Diablo\\Direct\\Interfac.cpp");
      IncProgress();
      LoadGameLevel(0, 1);
      IncProgress();
      control_416813();
      break;
    case 0x404:
      if ( gbMaxPlayers == 1 )
        SaveLevel();
      else
        DeltaSaveLevel();
      setlevel = 0;
      FreeGameMem();
      IncProgress();
      LoadGameLevel(0, 3);
      IncProgress();
      control_416813();
      break;
    case 0x405:
      if ( gbMaxPlayers == 1 )
        SaveLevel();
      else
        DeltaSaveLevel();
      setlevel = 1;
      FreeGameMem();
      IncProgress();
      LoadGameLevel(0, 2);
      IncProgress();
      control_416813();
      break;
    case 0x406:
      IncProgress();
      if ( gbMaxPlayers == 1 )
        SaveLevel();
      else
        DeltaSaveLevel();
      FreeGameMem();
      GetPortalLevel();
      IncProgress();
      LoadGameLevel(0, 5);
      IncProgress();
      control_416813();
      break;
    case 0x407:
      IncProgress();
      if ( gbMaxPlayers == 1 )
        SaveLevel();
      else
        DeltaSaveLevel();
      FreeGameMem();
      currlevel = plr[myplr].plrlevel;
      leveltype = gnLevelTypeTbl[currlevel];
      if ( plr[myplr].plrlevel != currlevel )
        assertion_failed(358, "C:\\Diablo\\Direct\\Interfac.cpp");
      IncProgress();
      LoadGameLevel(0, 6);
      IncProgress();
      break;
    case 0x408:
      IncProgress();
      if ( gbMaxPlayers == 1 )
        SaveLevel();
      else
        DeltaSaveLevel();
      FreeGameMem();
      currlevel = plr[myplr].plrlevel;
      leveltype = gnLevelTypeTbl[currlevel];
      if ( plr[myplr].plrlevel != currlevel )
        assertion_failed(372, "C:\\Diablo\\Direct\\Interfac.cpp");
      IncProgress();
      LoadGameLevel(0, 7);
      IncProgress();
      break;
    case 0x409:
      IncProgress();
      if ( gbMaxPlayers == 1 )
        SaveLevel();
      else
        DeltaSaveLevel();
      FreeGameMem();
      currlevel = plr[myplr].plrlevel;
      leveltype = gnLevelTypeTbl[currlevel];
      if ( plr[myplr].plrlevel != currlevel )
        assertion_failed(386, "C:\\Diablo\\Direct\\Interfac.cpp");
      IncProgress();
      LoadGameLevel(0, 0);
      IncProgress();
      break;
    case 0x40A:
      IncProgress();
      FreeGameMem();
      IncProgress();
      LoadGameLevel(1, 0);
      IncProgress();
      break;
    case 0x40B:
      IncProgress();
      LoadGame(1);
      IncProgress();
      break;
    default:
      break;
  }
  if ( !ghMainWnd )
    assertion_failed(395, "C:\\Diablo\\Direct\\Interfac.cpp");
  PaletteFadeOut(8);
  FreeInterface();
  if ( SetWindowProc(func) != interfac_41F03E_wndproc )
    assertion_failed(401, "C:\\Diablo\\Direct\\Interfac.cpp");
  NetSendCmdLocParam1(1u, 0x38u, plr[myplr].WorldX, plr[myplr].WorldY, plr[myplr].plrlevel);
}

//----- (0041EAD8) --------------------------------------------------------
void __cdecl FreeInterface()
{
  mem_free_dbg(sgpBackCel, 50, "C:\\Diablo\\Direct\\Interfac.cpp");
  sgpBackCel = 0;
}

//----- (0041EB07) --------------------------------------------------------
void __fastcall InitCutscene(int interface_mode)
{
  if ( sgpBackCel )
    assertion_failed(58, "C:\\Diablo\\Direct\\Interfac.cpp");
  switch ( interface_mode )
  {
    case 1026:
      switch ( gnLevelTypeTbl[currlevel] )
      {
        case 0:
          sgpBackCel = LoadFileInMem("Gendata\\Cuttt.CEL", 0, 63, "C:\\Diablo\\Direct\\Interfac.cpp");
          LoadPalette("Gendata\\Cuttt.pal");
          progress_id = 1;
          break;
        case 1:
          sgpBackCel = LoadFileInMem("Gendata\\Cutl1d.CEL", 0, 68, "C:\\Diablo\\Direct\\Interfac.cpp");
          LoadPalette("Gendata\\Cutl1d.pal");
          progress_id = 0;
          break;
        case 2:
          sgpBackCel = LoadFileInMem("Gendata\\Cut2.CEL", 0, 73, "C:\\Diablo\\Direct\\Interfac.cpp");
          LoadPalette("Gendata\\Cut2.pal");
          progress_id = 2;
          break;
        case 3:
          sgpBackCel = LoadFileInMem("Gendata\\Cut3.CEL", 0, 78, "C:\\Diablo\\Direct\\Interfac.cpp");
          LoadPalette("Gendata\\Cut3.pal");
          progress_id = 1;
          break;
        case 4:
          sgpBackCel = LoadFileInMem("Gendata\\Cut4.CEL", 0, 83, "C:\\Diablo\\Direct\\Interfac.cpp");
          LoadPalette("Gendata\\Cut4.pal");
          progress_id = 1;
          break;
        default:
          sgpBackCel = LoadFileInMem("Gendata\\Cutl1d.CEL", 0, 88, "C:\\Diablo\\Direct\\Interfac.cpp");
          LoadPalette("Gendata\\Cutl1d.pal");
          progress_id = 0;
          break;
      }
      break;
    case 1027:
      if ( gnLevelTypeTbl[currlevel - 1] )
      {
        switch ( gnLevelTypeTbl[currlevel] )
        {
          case 0:
            sgpBackCel = LoadFileInMem("Gendata\\Cuttt.CEL", 0, 103, "C:\\Diablo\\Direct\\Interfac.cpp");
            LoadPalette("Gendata\\Cuttt.pal");
            progress_id = 1;
            break;
          case 1:
            sgpBackCel = LoadFileInMem("Gendata\\Cutl1d.CEL", 0, 108, "C:\\Diablo\\Direct\\Interfac.cpp");
            LoadPalette("Gendata\\Cutl1d.pal");
            progress_id = 0;
            break;
          case 2:
            sgpBackCel = LoadFileInMem("Gendata\\Cut2.CEL", 0, 113, "C:\\Diablo\\Direct\\Interfac.cpp");
            LoadPalette("Gendata\\Cut2.pal");
            progress_id = 2;
            break;
          case 3:
            sgpBackCel = LoadFileInMem("Gendata\\Cut3.CEL", 0, 118, "C:\\Diablo\\Direct\\Interfac.cpp");
            LoadPalette("Gendata\\Cut3.pal");
            progress_id = 1;
            break;
          case 4:
            sgpBackCel = LoadFileInMem("Gendata\\Cut4.CEL", 0, 123, "C:\\Diablo\\Direct\\Interfac.cpp");
            LoadPalette("Gendata\\Cut4.pal");
            progress_id = 1;
            break;
          default:
            sgpBackCel = LoadFileInMem("Gendata\\Cutl1d.CEL", 0, 128, "C:\\Diablo\\Direct\\Interfac.cpp");
            LoadPalette("Gendata\\Cutl1d.pal");
            progress_id = 0;
            break;
        }
      }
      else
      {
        sgpBackCel = LoadFileInMem("Gendata\\Cuttt.CEL", 0, 97, "C:\\Diablo\\Direct\\Interfac.cpp");
        LoadPalette("Gendata\\Cuttt.pal");
        progress_id = 1;
      }
      break;
    case 1028:
      sgpBackCel = LoadFileInMem("Gendata\\Cutl1d.CEL", 0, 143, "C:\\Diablo\\Direct\\Interfac.cpp");
      LoadPalette("Gendata\\Cutl1d.pal");
      progress_id = 0;
      break;
    case 1029:
      sgpBackCel = LoadFileInMem("Gendata\\Cutl1d.CEL", 0, 137, "C:\\Diablo\\Direct\\Interfac.cpp");
      LoadPalette("Gendata\\Cutl1d.pal");
      progress_id = 0;
      break;
    case 1030:
      sgpBackCel = LoadFileInMem("Gendata\\Cutportl.CEL", 0, 149, "C:\\Diablo\\Direct\\Interfac.cpp");
      LoadPalette("Gendata\\Cutportl.pal");
      progress_id = 1;
      break;
    case 1031:
    case 1032:
      sgpBackCel = LoadFileInMem("Gendata\\Cut2.CEL", 0, 168, "C:\\Diablo\\Direct\\Interfac.cpp");
      LoadPalette("Gendata\\Cut2.pal");
      progress_id = 2;
      break;
    case 1033:
      sgpBackCel = LoadFileInMem("Gendata\\Cuttt.CEL", 0, 174, "C:\\Diablo\\Direct\\Interfac.cpp");
      LoadPalette("Gendata\\Cuttt.pal");
      progress_id = 1;
      break;
    case 1034:
      sgpBackCel = LoadFileInMem("Gendata\\Cutstart.CEL", 0, 161, "C:\\Diablo\\Direct\\Interfac.cpp");
      LoadPalette("Gendata\\Cutstart.pal");
      progress_id = 1;
      break;
    case 1035:
      sgpBackCel = LoadFileInMem("Gendata\\Cutstart.CEL", 0, 155, "C:\\Diablo\\Direct\\Interfac.cpp");
      LoadPalette("Gendata\\Cutstart.pal");
      progress_id = 1;
      break;
    default:
      TermMsg("Unknown progress mode");
      return;
  }
  sgdwProgress = 0;
}

//----- (0041F03E) --------------------------------------------------------
LRESULT __stdcall interfac_41F03E_wndproc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  if ( Msg != WM_SYSCOMMAND || wParam != SC_CLOSE )
    return init_palette(hWnd, Msg, wParam, lParam);
  gbRunGame = 0;
  gbRunGameResult = 0;
  return 0;
}

//----- (0041F1A8) --------------------------------------------------------
BOOL __cdecl mpqapi_write_header()
{
  TMPQHeader_buffer Buffer; // [esp+Ch] [ebp-64h]
  int NumberOfBytesWritten; // [esp+6Ch] [ebp-4h]

  memset(&Buffer, 0, 0x60u);
  Buffer.header.dwID = '\x1AQPM';
  Buffer.header.dwHeaderSize = 32;
  Buffer.header.dwArchiveSize = GetFileSize(hFile, 0);
  Buffer.header.wFormatVersion = 0;
  Buffer.header.wSectorSize = 3;
  Buffer.header.dwHashTablePos = 32864;
  Buffer.header.dwBlockTablePos = 96;
  Buffer.header.dwHashTableSize = 2048;
  Buffer.header.dwBlockTableSize = 2048;
  if ( SetFilePointer(hFile, 0, 0, 0) == -1 )
    return 0;
  if ( WriteFile(hFile, &Buffer, 0x60u, (LPDWORD)&NumberOfBytesWritten, 0) )
    return NumberOfBytesWritten == 96;
  return 0;
}

//----- (0041F271) --------------------------------------------------------
BOOL __cdecl mpqapi_write_block_table()
{
  int v0; // eax
  int NumberOfBytesWritten; // [esp+Ch] [ebp-4h]

  v0 = encrypt_hash("(block table)", 3);
  encrypt_encrypt_block(sgpBlockTbl, 0x8000, v0);
  if ( SetFilePointer(hFile, 96, 0, 0) == -1 )
    return 0;
  if ( WriteFile(hFile, sgpBlockTbl, 0x8000u, (LPDWORD)&NumberOfBytesWritten, 0) )
    return NumberOfBytesWritten == 0x8000;
  return 0;
}

//----- (0041F30B) --------------------------------------------------------
BOOL __cdecl mpqapi_write_hash_table()
{
  int v0; // eax
  int NumberOfBytesWritten; // [esp+Ch] [ebp-4h]

  v0 = encrypt_hash("(hash table)", 3);
  encrypt_encrypt_block(sgpHashTbl, 0x8000, v0);
  if ( SetFilePointer(hFile, 32864, 0, 0) == -1 )
    return 0;
  if ( WriteFile(hFile, sgpHashTbl, 0x8000u, (LPDWORD)&NumberOfBytesWritten, 0) )
    return NumberOfBytesWritten == 0x8000;
  return 0;
}

//----- (0041F3A8) --------------------------------------------------------
BOOL __cdecl mpqapi_can_seek()
{
  BOOL result; // eax

  if ( SetFilePointer(hFile, lDistanceToMove, 0, 0) == -1 )
    result = 0;
  else
    result = SetEndOfFile(hFile);
  return result;
}

//----- (0041F3EA) --------------------------------------------------------
void __fastcall mpqapi_close_archive(char *pszArchive, bool bFree, int dwChar)
{
  if ( sgpBlockTbl )
  {
    mem_free_dbg(sgpBlockTbl, 314, "C:\\Diablo\\Direct\\mpqapi.cpp");
    sgpBlockTbl = 0;
  }
  if ( sgpHashTbl )
  {
    mem_free_dbg(sgpHashTbl, 318, "C:\\Diablo\\Direct\\mpqapi.cpp");
    sgpHashTbl = 0;
  }
  CloseHandle(hFile);
  hFile = (HANDLE)-1;
}

//----- (0041F468) --------------------------------------------------------
BOOL __fastcall mpqapi_open_archive(char *pszArchive, BOOL hidden)
{
  bool v3; // dl
  char *v4; // ecx
  int v5; // eax
  int v6; // eax
  int v7; // [esp+0h] [ebp-38h]
  TMPQHeader a1; // [esp+14h] [ebp-24h]
  int NumberOfBytesRead; // [esp+34h] [ebp-4h]

  if ( !pszArchive )
    assertion_failed(382, "C:\\Diablo\\Direct\\mpqapi.cpp");
  encrypt_init_lookup_table();
  hFile = CreateFileA(pszArchive, 0xC0000000, 0, 0, 3u, 0, 0);
  if ( hFile == (HANDLE)-1 )
  {
    if ( !hidden )
      return 0;
    hFile = CreateFileA(pszArchive, 0xC0000000, 0, 0, 2u, 0, 0);
    if ( hFile == (HANDLE)-1 )
      return 0;
  }
  memset(&a1, 0, 0x20u);
  if ( !mpqapi_parse_archive_header(&a1, &lDistanceToMove) )
    goto LABEL_30;
  sgpBlockTbl = (_BLOCKENTRY *)DiabloAllocPtr(0x8000, 417, "C:\\Diablo\\Direct\\mpqapi.cpp");
  memset(sgpBlockTbl, 0, 0x8000u);
  if ( a1.dwBlockTableSize )
  {
    if ( a1.dwBlockTableSize != 2048 )
      assertion_failed(422, "C:\\Diablo\\Direct\\mpqapi.cpp");
    if ( a1.dwBlockTablePos != 96 )
      assertion_failed(423, "C:\\Diablo\\Direct\\mpqapi.cpp");
    if ( SetFilePointer(hFile, 96, 0, 0) == -1 || !ReadFile(hFile, sgpBlockTbl, 0x8000u, (LPDWORD)&NumberOfBytesRead, 0) )
      goto LABEL_30;
    if ( NumberOfBytesRead != 0x8000 )
      assertion_failed(428, "C:\\Diablo\\Direct\\mpqapi.cpp");
    v5 = encrypt_hash("(block table)", 3);
    encrypt_decrypt_block(sgpBlockTbl, 0x8000, v5);
  }
  sgpHashTbl = (_HASHENTRY *)DiabloAllocPtr(0x8000, 438, "C:\\Diablo\\Direct\\mpqapi.cpp");
  memset(sgpHashTbl, 255, 0x8000u);
  if ( !a1.dwHashTableSize )
    return 1;
  if ( a1.dwHashTableSize != 2048 )
    assertion_failed(443, "C:\\Diablo\\Direct\\mpqapi.cpp");
  if ( a1.dwHashTablePos != 32864 )
    assertion_failed(444, "C:\\Diablo\\Direct\\mpqapi.cpp");
  if ( SetFilePointer(hFile, 32864, 0, 0) != -1 && ReadFile(hFile, sgpHashTbl, 0x8000u, (LPDWORD)&NumberOfBytesRead, 0) )
  {
    if ( NumberOfBytesRead != 0x8000 )
      assertion_failed(449, "C:\\Diablo\\Direct\\mpqapi.cpp");
    v6 = encrypt_hash("(hash table)", 3);
    encrypt_decrypt_block(sgpHashTbl, 0x8000, v6);
    return 1;
  }
LABEL_30:
  mpqapi_close_archive(v4, v3, v7);
  return 0;
}

//----- (0041F78C) --------------------------------------------------------
BOOL __fastcall mpqapi_parse_archive_header(TMPQHeader *pHdr, int *pdwNextFileStart)
{
  int NumberOfBytesRead; // [esp+14h] [ebp-Ch]
  int v6; // [esp+18h] [ebp-8h]
  unsigned int v7; // [esp+1Ch] [ebp-4h]

  if ( !pHdr )
    assertion_failed(330, "C:\\Diablo\\Direct\\mpqapi.cpp");
  v6 = 0;
  v7 = GetFileSize(hFile, 0);
  *pdwNextFileStart = v7;
  if ( v7 != -1 && v7 )
  {
    if ( v7 >= 0x20 )
    {
      if ( ReadFile(hFile, pHdr, 0x20u, (LPDWORD)&NumberOfBytesRead, 0) )
      {
        if ( NumberOfBytesRead != 32 )
          assertion_failed(345, "C:\\Diablo\\Direct\\mpqapi.cpp");
      }
      else
      {
        v6 = 1;
      }
    }
    else
    {
      v6 = 1;
    }
  }
  else
  {
    v6 = 1;
  }
  if ( !v6 )
  {
    if ( pHdr->dwID == 441536589 )
    {
      if ( pHdr->dwHeaderSize == 32 )
      {
        if ( (signed int)(unsigned __int16)pHdr->wFormatVersion <= 0 )
        {
          if ( pHdr->wSectorSize == 3 )
          {
            if ( pHdr->dwArchiveSize != v7 )
              v6 = 1;
          }
          else
          {
            v6 = 1;
          }
        }
        else
        {
          v6 = 1;
        }
      }
      else
      {
        v6 = 1;
      }
    }
    else
    {
      v6 = 1;
    }
  }
  if ( v6 )
  {
    if ( SetFilePointer(hFile, 0, 0, 0) == -1 )
      return 0;
    if ( !SetEndOfFile(hFile) )
      return 0;
    memset(pHdr, 0, 0x20u);
    pHdr->dwID = 441536589;
    pHdr->dwHeaderSize = 32;
    pHdr->wSectorSize = 3;
    pHdr->wFormatVersion = 0;
    *pdwNextFileStart = 65632;
  }
  return 1;
}

