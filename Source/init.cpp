//----- (0042D180) --------------------------------------------------------
BOOL requires_pentium()
{
  char v0; // fl
  BOOL v2; // [esp+Ch] [ebp-28h]
  SYSTEM_INFO SystemInfo; // [esp+10h] [ebp-24h]

  v2 = 0;
  GetSystemInfo(&SystemInfo);
  if ( !SystemInfo.anonymous_0.anonymous_0.wProcessorArchitecture )
  {
    if ( SystemInfo.dwProcessorType >= 0x24A )
    {
      v2 = 1;
    }
    else if ( init_42D223(v0) )
    {
      v2 = 1;
    }
  }
  if ( !v2 )
    v2 = MessageBoxA(0, "Diablo requires at least a Pentium", "Diablo", 0x131u) == 1;
  return v2;
}

//----- (0042D223) --------------------------------------------------------
BOOL __usercall init_42D223@<eax>(char a1@<efl>)
{
  return a1 == 2;
}

//----- (0042D257) --------------------------------------------------------
void __cdecl dx_cleanup_42D257()
{
  if ( lpDDSPrimary )
  {
    lpDDSPrimary->lpVtbl->Release(lpDDSPrimary);
    lpDDSPrimary = 0;
  }
  if ( lpDDPalette )
  {
    lpDDPalette->lpVtbl->Release(lpDDPalette);
    lpDDPalette = 0;
  }
  if ( lpDD )
  {
    assert(ghMainWnd, 371, "init.cpp");
    lpDD->lpVtbl->SetCooperativeLevel(lpDD, ghMainWnd, 8);
    lpDD->lpVtbl->Release(lpDD);
    lpDD = 0;
  }
}

//----- (0042D315) --------------------------------------------------------
void __fastcall dx_init_42D315(HWND hwnd)
{
  DWORD v1; // ST18_4
  DWORD v2; // eax
  char rc; // [esp+10h] [ebp-84h]
  int error_code; // [esp+20h] [ebp-74h]
  int v6; // [esp+24h] [ebp-70h]
  DDSURFACEDESC v7; // [esp+28h] [ebp-6Ch]

  SetFocus(hwnd);
  error_code = DirectDrawCreate(0, &lpDD, 0);
  if ( error_code )
    DDErrDlg(error_code, 386, "init.cpp");
  if ( fullscreen )
  {
    error_code = lpDD->lpVtbl->SetCooperativeLevel(lpDD, hwnd, 17);
    if ( error_code )
      DDErrDlg(error_code, 406, "init.cpp");
    error_code = lpDD->lpVtbl->SetDisplayMode(lpDD, 640, 480, 8);
    if ( error_code )
      DDErrDlg(error_code, 410, "init.cpp");
  }
  else
  {
    error_code = lpDD->lpVtbl->SetCooperativeLevel(lpDD, hwnd, 8);
    if ( error_code )
      DDErrDlg(error_code, 395, "init.cpp");
    SetRect((LPRECT)&rc, 0, 0, 640, 480);
    v1 = GetWindowLongA(hwnd, -20);
    v2 = GetWindowLongA(hwnd, -16);
    AdjustWindowRectEx((LPRECT)&rc, v2, 0, v1);
  }
  memset(&v7, 0, 0x6Cu);
  v7.dwSize = 108;
  v7.dwFlags = 1;
  v7.ddsCaps.dwCaps = 512;
  error_code = lpDD->lpVtbl->CreateSurface(lpDD, &v7, &lpDDSPrimary, 0);
  if ( error_code )
    DDErrDlg(error_code, 422, "init.cpp");
  palette_init();
  v6 = SDrawManualInitialize(hwnd, lpDD, lpDDSPrimary, 0, 0, lpDDPalette, 0);
  assert(v6, 428, "init.cpp");
  GdiSetBatchLimit(1u);
  if ( !gpBuffer )
    gpBuffer = (char *)DiabloAllocPtr(503808, 434, "init.cpp");
}

//----- (0042D562) --------------------------------------------------------
void __cdecl dx_reinit_42D562()
{
  scrollrt_draw_cursor_back_buffer();
  assert(ghMainWnd, 442, "init.cpp");
  dx_cleanup_42D257();
  drawpanflag = 255;
  dx_init_42D315(ghMainWnd);
}

//----- (0042D5B2) --------------------------------------------------------
void __fastcall init_cleanup()
{
  init_disable_screensaver(0);
  init_42DA06_caps_lock(0);
  init_run_office_from_start_menu();
  if ( diabdat_mpq )
  {
    SFileCloseArchive(diabdat_mpq);
    diabdat_mpq = 0;
  }
  if ( patch_rt_mpq )
  {
    SFileCloseArchive(patch_rt_mpq);
    patch_rt_mpq = 0;
  }
  if ( gpBuffer )
  {
    mem_free_dbg(gpBuffer, 465, "init.cpp");
    gpBuffer = 0;
  }
  SFileDdaDestroy();
  SVidDestroy();
  UiDestroy();
  effects_cleanup_sfx();
  sound_cleanup();
  NetClose();
  StormDestroy();
  dx_cleanup_42D257();
}

//----- (0042D66D) --------------------------------------------------------
void __cdecl init_run_office_from_start_menu()
{
  HWND v0; // eax
  const ITEMIDLIST *ppidl; // [esp+Ch] [ebp-104h]
  char pszPath; // [esp+10h] [ebp-100h]
  char v3[252]; // [esp+11h] [ebp-FFh]
  __int16 v4; // [esp+10Dh] [ebp-3h]
  char v5; // [esp+10Fh] [ebp-1h]

  if ( killed_mom_parent )
  {
    killed_mom_parent = 0;
    pszPath = empty_string_1;
    memset(v3, 0, sizeof(v3));
    v4 = 0;
    v5 = 0;
    ppidl = 0;
    v0 = GetDesktopWindow();
    if ( !SHGetSpecialFolderLocation(v0, 11, (LPITEMIDLIST *)&ppidl) )
    {
      SHGetPathFromIDListA(ppidl, &pszPath);
      init_run_office(&pszPath);
    }
  }
}

//----- (0042D703) --------------------------------------------------------
void __fastcall init_run_office(char *dir)
{
  HWND v1; // eax
  char dira; // [esp+10h] [ebp-34Ch]
  char v4[256]; // [esp+11h] [ebp-34Bh]
  __int16 v5; // [esp+111h] [ebp-24Bh]
  char v6; // [esp+113h] [ebp-249h]
  char FileName; // [esp+114h] [ebp-248h]
  HANDLE hFindFile; // [esp+218h] [ebp-144h]
  char FindFileData; // [esp+21Ch] [ebp-140h]
  CHAR File; // [esp+248h] [ebp-114h]

  strcpy(&FileName, dir);
  if ( FileName && *(&v6 + strlen(&FileName)) == 92 )
    strcat(&FileName, "*");
  else
    strcat(&FileName, "\\*");
  hFindFile = FindFirstFileA(&FileName, (LPWIN32_FIND_DATAA)&FindFileData);
  if ( hFindFile != (HANDLE)-1 )
  {
    do
    {
      if ( FindFileData & 0x10 )
      {
        if ( strcmp(&File, ".") && strcmp(&File, "..") )
        {
          dira = empty_string_2;
          memset(v4, 0, sizeof(v4));
          v5 = 0;
          v6 = 0;
          if ( *dir && dir[strlen(dir) - 1] == 92 )
            sprintf(&dira, "%s%s\\", dir, &File);
          else
            sprintf(&dira, "%s\\%s\\", dir, &File);
          init_run_office(&dira);
        }
      }
      else if ( !_strcmpi(&File, "Microsoft Office Shortcut Bar.lnk") )
      {
        v1 = GetDesktopWindow();
        ShellExecuteA(v1, "open", &File, Parameters, dir, 1);
      }
    }
    while ( FindNextFileA(hFindFile, (LPWIN32_FIND_DATAA)&FindFileData) );
    FindClose(hFindFile);
  }
}

//----- (0042D913) --------------------------------------------------------
void __fastcall init_disable_screensaver(bool disable)
{
  int cbData; // [esp+10h] [ebp-24h]
  char Type; // [esp+14h] [ebp-20h]
  LONG v4; // [esp+18h] [ebp-1Ch]
  HKEY phkResult; // [esp+1Ch] [ebp-18h]
  char v6; // [esp+20h] [ebp-14h]
  char Data[16]; // [esp+24h] [ebp-10h]

  v4 = RegOpenKeyExA(HKEY_CURRENT_USER, "Control Panel\\Desktop", 0, 0x2001Fu, &phkResult);
  if ( !v4 )
  {
    if ( disable )
    {
      cbData = 16;
      v4 = RegQueryValueExA(phkResult, "ScreenSaveActive", 0, (LPDWORD)&Type, (LPBYTE)Data, (LPDWORD)&cbData);
      if ( !v4 )
        byte_4C56B8 = Data[0] != 48;
      v6 = 0;
    }
    else
    {
      v6 = byte_4C56B8;
    }
    if ( v6 )
      Data[0] = 49;
    else
      Data[0] = 48;
    Data[1] = 0;
    RegSetValueExA(phkResult, "ScreenSaveActive", 0, 1u, (const BYTE *)Data, 2u);
    RegCloseKey(phkResult);
  }
}

//----- (0042DA06) --------------------------------------------------------
void __fastcall init_42DA06_caps_lock(BOOL a1)
{
  char KeyState; // [esp+10h] [ebp-100h]
  char v3; // [esp+24h] [ebp-ECh]

  GetKeyboardState((PBYTE)&KeyState);
  if ( a1 )
  {
    dword_60D1DC = v3 & 1;
    if ( v3 & 1 )
      init_42DAAC_press_key(VK_CAPITAL);
  }
  else if ( dword_60D1DC && !(v3 & 1) || !dword_60D1DC && v3 & 1 )
  {
    init_42DAAC_press_key(VK_CAPITAL);
  }
}

//----- (0042DAAC) --------------------------------------------------------
void __fastcall init_42DAAC_press_key(BYTE key)
{
  keybd_event(key, 0x45u, KEYEVENTF_EXTENDEDKEY, 0);
  keybd_event(VK_CAPITAL, 0x45u, KEYEVENTF_KEYUP|KEYEVENTF_EXTENDEDKEY, 0);
}

//----- (0042DAE0) --------------------------------------------------------
void __fastcall init_create_window(int nCmdShow)
{
  WNDCLASSA WndClass; // [esp+10h] [ebp-2Ch]
  HWND hWnd; // [esp+38h] [ebp-4h]

  memset(&WndClass, 0, 0x28u);
  WndClass.style = 3;
  WndClass.lpfnWndProc = init_redraw_window;
  WndClass.hInstance = ghInst;
  WndClass.hIcon = LoadIconA(ghInst, (LPCSTR)0x7F00);
  WndClass.hCursor = LoadCursorA(0, (LPCSTR)0x7F00);
  WndClass.hbrBackground = 0;
  WndClass.lpszMenuName = "Diablo";
  WndClass.lpszClassName = "Diablo";
  if ( !RegisterClassA(&WndClass) )
    TermMsg("Unable to register window class");
  hWnd = CreateWindowExA(0, "Diablo", "Diablo", 0x80000008, 0, 0, 640, 480, 0, 0, ghInst, 0);
  if ( !hWnd )
    TermMsg("Unable to create main window");
  ShowWindow(hWnd, nCmdShow);
  UpdateWindow(hWnd);
  dx_init_42D315(hWnd);
  snd_init(hWnd);
  init_archives();
  init_disable_screensaver(1);
  init_42DA06_caps_lock(1);
  init_find_mom_parent();
  pfile_436980_init_savename();
}

//----- (0042DC0D) --------------------------------------------------------
HWND __cdecl init_find_mom_parent()
{
  HWND result; // eax
  HWND hHandle; // [esp+Ch] [ebp-110h]
  HWND v2; // [esp+10h] [ebp-10Ch]
  char ClassName[256]; // [esp+14h] [ebp-108h]
  DWORD dwProcessId; // [esp+114h] [ebp-8h]
  HWND hWnd; // [esp+118h] [ebp-4h]

  dwProcessId = 0;
  result = GetForegroundWindow();
  for ( hWnd = result; hWnd; hWnd = v2 )
  {
    v2 = GetWindow(hWnd, 2u);
    GetClassNameA(hWnd, ClassName, 255);
    if ( !_strcmpi(ClassName, "MOM Parent") )
    {
      GetWindowThreadProcessId(hWnd, &dwProcessId);
      PostMessageA(hWnd, 0x10u, 0, 0);
      killed_mom_parent = 1;
    }
    result = v2;
  }
  if ( dwProcessId )
  {
    result = (HWND)OpenProcess(0x1F0FFFu, 0, dwProcessId);
    hHandle = result;
    if ( result )
    {
      WaitForSingleObject(result, 0x3E8u);
      result = (HWND)CloseHandle(hHandle);
    }
  }
  return result;
}

//----- (0042DD04) --------------------------------------------------------
void __cdecl init_archives()
{
  int v0; // [esp+Ch] [ebp-4h]

  fileinfo.size = 20;
  fileinfo.versionstring = "version unknown";
  fileinfo.executablefile = diablo_exe_path;
  fileinfo.originalarchivefile = diabdat_mpq_path;
  fileinfo.patcharchivefile = patch_rt_mpq_path;
  init_get_file_info();
  diabdat_mpq = (int)init_test_access(diabdat_mpq_path, "\\diabdat.mpq", "DiabloCD", 1000, 1);
  if ( !diabdat_mpq )
    TermMsg("Unable to open program data file");
  if ( !SFileOpenFile("ui_art\\title.pcx", &v0) )
    TermMsg("Unable to open program data file");
  SFileCloseFile(v0);
  patch_rt_mpq = (int)init_test_access(patch_rt_mpq_path, "\\patch.mpq", 0, 2000, 0);
}

//----- (0042DDE2) --------------------------------------------------------
void *__fastcall init_test_access(char *mpq_path, char *mpq_name, char *reg_loc, int flags, bool on_cd)
{
  char path[260]; // [esp+14h] [ebp-314h]
  char *v9; // [esp+118h] [ebp-210h]
  char Filename[260]; // [esp+11Ch] [ebp-20Ch]
  char Buffer[260]; // [esp+220h] [ebp-108h]
  void *v12; // [esp+324h] [ebp-4h]

  if ( !GetCurrentDirectoryA(0x104u, Buffer) )
    TermMsg("Can't get program path");
  init_strip_trailing_slash(Buffer);
  if ( !GetModuleFileNameA(ghInst, Filename, 0x104u) )
    TermMsg("Can't get program name");
  v9 = strrchr(Filename, '\\');
  if ( v9 )
    *v9 = 0;
  init_strip_trailing_slash(Filename);
  path[0] = 0;
  if ( reg_loc )
  {
    if ( SRegLoadString("Archives", reg_loc, 0, path, 260) )
    {
      init_strip_trailing_slash(path);
      strcpy(mpq_path, path);
      strcat(mpq_path, mpq_name);
      if ( SFileOpenArchive(mpq_path, flags, on_cd, &v12) )
        return v12;
    }
  }
  if ( strcmp(Buffer, path) )
  {
    strcpy(mpq_path, Buffer);
    strcat(mpq_path, mpq_name);
    if ( SFileOpenArchive(mpq_path, flags, on_cd, &v12) )
      return v12;
  }
  if ( !strcmp(Filename, Buffer) )
    return 0;
  if ( !strcmp(Filename, path) )
    return 0;
  strcpy(mpq_path, Filename);
  strcat(mpq_path, mpq_name);
  if ( !SFileOpenArchive(mpq_path, flags, on_cd, &v12) )
    return 0;
  return v12;
}

//----- (0042E035) --------------------------------------------------------
char *__fastcall init_strip_trailing_slash(char *path)
{
  char *result; // eax
  char *v2; // [esp+10h] [ebp-4h]

  result = strrchr(path, '\\');
  v2 = result;
  if ( result )
  {
    result = (char *)result[1];
    if ( !v2[1] )
    {
      result = v2;
      *v2 = 0;
    }
  }
  return result;
}

//----- (0042E07B) --------------------------------------------------------
void __cdecl init_get_file_info()
{
  unsigned int puLen; // [esp+Ch] [ebp-14h]
  void *lpData; // [esp+10h] [ebp-10h]
  DWORD dwLen; // [esp+14h] [ebp-Ch]
  int lpBuffer; // [esp+18h] [ebp-8h]
  char dwHandle; // [esp+1Ch] [ebp-4h]

  if ( GetModuleFileNameA(ghInst, diablo_exe_path, 0x104u) )
  {
    dwLen = GetFileVersionInfoSizeA(diablo_exe_path, (LPDWORD)&dwHandle);
    if ( dwLen )
    {
      lpData = DiabloAllocPtr(dwLen, 565, "init.cpp");
      if ( GetFileVersionInfoA(diablo_exe_path, 0, dwLen, lpData)
        && VerQueryValueA(lpData, "\\", (LPVOID *)&lpBuffer, &puLen) )
      {
        assert(puLen >= 0x34, 573, "init.cpp");
        sprintf(
          "version unknown",
          "Version %d.%d.%d.%d",
          *(_DWORD *)(lpBuffer + 16) >> 16,
          *(_DWORD *)(lpBuffer + 16) & 0xFFFF,
          *(_DWORD *)(lpBuffer + 20) >> 16,
          *(_DWORD *)(lpBuffer + 20) & 0xFFFF);
      }
      mem_free_dbg(lpData, 585, "init.cpp");
    }
  }
}

//----- (0042E1AC) --------------------------------------------------------
LRESULT __stdcall init_palette(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  if ( Msg > WM_ACTIVATEAPP )
  {
    if ( Msg == WM_SYSKEYUP && wParam == VK_RETURN )
    {
      fullscreen = fullscreen == 0;
      dx_reinit_42D562();
      return 0;
    }
  }
  else
  {
    switch ( Msg )
    {
      case WM_ACTIVATEAPP:
        window_activated = wParam;
        if ( wParam )
          drawpanflag = 255;
        break;
      case WM_CREATE:
        ghMainWnd = hWnd;
        break;
      case WM_DESTROY:
        init_cleanup();
        ghMainWnd = 0;
        PostQuitMessage(0);
        break;
    }
  }
  return DefWindowProcA(hWnd, Msg, wParam, lParam);
}

//----- (0042E2B0) --------------------------------------------------------
LRESULT __stdcall init_redraw_window(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  LRESULT result; // eax

  if ( CurrentProc )
    result = CurrentProc(hWnd, Msg, wParam, lParam);
  else
    result = init_palette(hWnd, Msg, wParam, lParam);
  return result;
}

//----- (0042E2FF) --------------------------------------------------------
WNDPROC __fastcall SetWindowProc(WNDPROC func)
{
  WNDPROC v1; // ST10_4

  v1 = CurrentProc;
  CurrentProc = func;
  return v1;
}

