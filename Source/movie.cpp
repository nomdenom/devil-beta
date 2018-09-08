//----- (00482290) --------------------------------------------------------
void __fastcall play_movie(char *pszMovie, bool user_can_close)
{
  char Msg; // [esp+10h] [ebp-24h]
  int v4; // [esp+14h] [ebp-20h]
  int v5; // [esp+2Ch] [ebp-8h]
  WNDPROC func; // [esp+30h] [ebp-4h]

  if ( gbActive )
  {
    assert(ghMainWnd, "movie.cpp", 69);
    func = SetWindowProc(MovieWndProc);
    InvalidateRect(ghMainWnd, 0, 0);
    UpdateWindow(ghMainWnd);
    ShowCursor(0);
    movie_playing = 1;
    dword_645124 = 0;
    if ( pszMovie )
    {
      SVidPlayBegin(pszMovie, 0, 0, 0, 268961800, &v5);
      if ( !v5 )
        movie_playing = 0;
    }
    do
    {
      if ( !movie_playing || !gbActive )
        break;
      while ( PeekMessageA((LPMSG)&Msg, 0, 0, 0, 1u) )
      {
        if ( v4 == 18 )
          exit(0);
        TranslateMessage((const MSG *)&Msg);
        DispatchMessageA((const MSG *)&Msg);
      }
    }
    while ( !pszMovie || SVidPlayContinue() );
    if ( v5 )
      SVidPlayEnd(v5);
    ShowCursor(1);
    func = SetWindowProc(func);
    assert(func == MovieWndProc, "movie.cpp", 100);
  }
}

//----- (00482419) --------------------------------------------------------
LRESULT __stdcall MovieWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  int v4; // ST20_4

  if ( Msg <= WM_KEYDOWN )
  {
    if ( Msg == WM_KEYDOWN )
    {
      movie_playing = 0;
    }
    else if ( Msg == WM_PAINT && dword_4DB908 )
    {
      dword_4DB908();
    }
    return MainWndProc(hWnd, Msg, wParam, lParam);
  }
  if ( Msg > WM_TIMER )
  {
    if ( Msg != WM_LBUTTONDOWN && Msg != WM_RBUTTONDOWN )
      return MainWndProc(hWnd, Msg, wParam, lParam);
LABEL_3:
    movie_playing = 0;
    return MainWndProc(hWnd, Msg, wParam, lParam);
  }
  if ( Msg != WM_TIMER )
  {
    if ( Msg != 258 )
      return MainWndProc(hWnd, Msg, wParam, lParam);
    goto LABEL_3;
  }
  if ( dword_645124 )
  {
    v4 = dword_645124--;
    if ( !v4 )
      movie_playing = 0;
  }
  return MainWndProc(hWnd, Msg, wParam, lParam);
}

//----- (0048251A) --------------------------------------------------------
void movie_unused_48251A()
{
  movie_unused_482539("Gendata\\Quotes.CEL", "Gendata\\Quotes.pal");
}

//----- (00482539) --------------------------------------------------------
void __fastcall movie_unused_482539(char *palette, char *a2)
{
  bool v2; // dl
  char *pszFileName; // [esp+Ch] [ebp-Ch]
  unsigned __int8 *pCelBuff; // [esp+14h] [ebp-4h]

  pszFileName = a2;
  if ( gbActive )
  {
    pCelBuff = LoadFileInMem(palette, 0, 122, "movie.cpp");
    if ( pCelBuff )
    {
      ClearScreenBuffer();
      CelDecodeOnly(64, 639, pCelBuff, 1, 640);
      drawpanflag = 255;
      scrollrt_draw_game_screen(1);
      LoadPalette(pszFileName);
      PaletteFadeIn(8);
      dword_645124 = 60;
      dword_4DB908 = (int (*)(void))movie_unused_482640_paint;
      play_movie(0, v2);
      dword_4DB908 = 0;
      PaletteFadeOut(8);
      ClearScreenBuffer();
      CelDecodeOnly(64, 639, pCelBuff, 1, 640);
      drawpanflag = 255;
      scrollrt_draw_game_screen(1);
      mem_free_dbg(pCelBuff, 146, "movie.cpp");
    }
  }
}

//----- (00482640) --------------------------------------------------------
BOOL movie_unused_482640_paint()
{
  const PAINTSTRUCT Paint; // [esp+Ch] [ebp-40h]

  assert(ghMainWnd, "movie.cpp", 108);
  BeginPaint(ghMainWnd, (LPPAINTSTRUCT)&Paint);
  drawpanflag = 255;
  scrollrt_draw_game_screen(1);
  return EndPaint(ghMainWnd, &Paint);
}

//----- (004826A8) --------------------------------------------------------
void movie_unused_4826A8()
{
  char v0; // [esp+Ch] [ebp-20Ch]
  char v1; // [esp+110h] [ebp-108h]
  int i; // [esp+214h] [ebp-4h]

  music_start(5);
  for ( i = 0; i < 5; ++i )
  {
    sprintf(&v0, "Gendata\\Screen0%d.CEL", i + 1);
    sprintf(&v1, "Gendata\\Screen0%d.PAL", i + 1);
    movie_unused_482539(&v0, &v1);
  }
  music_stop();
}

