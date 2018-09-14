#include "all.h"

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

  assert(sgpBackCel, "Interfac.cpp", 208);
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
  BYTE *v3; // [esp+14h] [ebp-8h]
  signed int i; // [esp+18h] [ebp-4h]

  assert(gpBuffer, "Interfac.cpp", 192);
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

  assert(ghMainWnd, "Interfac.cpp", 256);
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
      assert(plr[myplr].plrlevel == currlevel, "Interfac.cpp", 293);
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
      assert(plr[myplr].plrlevel == currlevel, "Interfac.cpp", 308);
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
      assert(plr[myplr].plrlevel == currlevel, "Interfac.cpp", 358);
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
      assert(plr[myplr].plrlevel == currlevel, "Interfac.cpp", 372);
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
      assert(plr[myplr].plrlevel == currlevel, "Interfac.cpp", 386);
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
  assert(ghMainWnd, "Interfac.cpp", 395);
  PaletteFadeOut(8);
  FreeInterface();
  assert(SetWindowProc(func) == interfac_41F03E_wndproc, "Interfac.cpp", 401);
  NetSendCmdLocParam1(1u, 0x38u, plr[myplr].WorldX, plr[myplr].WorldY, plr[myplr].plrlevel);
}

//----- (0041EAD8) --------------------------------------------------------
void __cdecl FreeInterface()
{
  mem_free_dbg(sgpBackCel, 50, "Interfac.cpp");
  sgpBackCel = 0;
}

//----- (0041EB07) --------------------------------------------------------
void __fastcall InitCutscene(int interface_mode)
{
  assert(!sgpBackCel, "Interfac.cpp", 58);
  switch ( interface_mode )
  {
    case 1026:
      switch ( gnLevelTypeTbl[currlevel] )
      {
        case 0:
          sgpBackCel = LoadFileInMem("Gendata\\Cuttt.CEL", 0, 63, "Interfac.cpp");
          LoadPalette("Gendata\\Cuttt.pal");
          progress_id = 1;
          break;
        case 1:
          sgpBackCel = LoadFileInMem("Gendata\\Cutl1d.CEL", 0, 68, "Interfac.cpp");
          LoadPalette("Gendata\\Cutl1d.pal");
          progress_id = 0;
          break;
        case 2:
          sgpBackCel = LoadFileInMem("Gendata\\Cut2.CEL", 0, 73, "Interfac.cpp");
          LoadPalette("Gendata\\Cut2.pal");
          progress_id = 2;
          break;
        case 3:
          sgpBackCel = LoadFileInMem("Gendata\\Cut3.CEL", 0, 78, "Interfac.cpp");
          LoadPalette("Gendata\\Cut3.pal");
          progress_id = 1;
          break;
        case 4:
          sgpBackCel = LoadFileInMem("Gendata\\Cut4.CEL", 0, 83, "Interfac.cpp");
          LoadPalette("Gendata\\Cut4.pal");
          progress_id = 1;
          break;
        default:
          sgpBackCel = LoadFileInMem("Gendata\\Cutl1d.CEL", 0, 88, "Interfac.cpp");
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
            sgpBackCel = LoadFileInMem("Gendata\\Cuttt.CEL", 0, 103, "Interfac.cpp");
            LoadPalette("Gendata\\Cuttt.pal");
            progress_id = 1;
            break;
          case 1:
            sgpBackCel = LoadFileInMem("Gendata\\Cutl1d.CEL", 0, 108, "Interfac.cpp");
            LoadPalette("Gendata\\Cutl1d.pal");
            progress_id = 0;
            break;
          case 2:
            sgpBackCel = LoadFileInMem("Gendata\\Cut2.CEL", 0, 113, "Interfac.cpp");
            LoadPalette("Gendata\\Cut2.pal");
            progress_id = 2;
            break;
          case 3:
            sgpBackCel = LoadFileInMem("Gendata\\Cut3.CEL", 0, 118, "Interfac.cpp");
            LoadPalette("Gendata\\Cut3.pal");
            progress_id = 1;
            break;
          case 4:
            sgpBackCel = LoadFileInMem("Gendata\\Cut4.CEL", 0, 123, "Interfac.cpp");
            LoadPalette("Gendata\\Cut4.pal");
            progress_id = 1;
            break;
          default:
            sgpBackCel = LoadFileInMem("Gendata\\Cutl1d.CEL", 0, 128, "Interfac.cpp");
            LoadPalette("Gendata\\Cutl1d.pal");
            progress_id = 0;
            break;
        }
      }
      else
      {
        sgpBackCel = LoadFileInMem("Gendata\\Cuttt.CEL", 0, 97, "Interfac.cpp");
        LoadPalette("Gendata\\Cuttt.pal");
        progress_id = 1;
      }
      break;
    case 1028:
      sgpBackCel = LoadFileInMem("Gendata\\Cutl1d.CEL", 0, 143, "Interfac.cpp");
      LoadPalette("Gendata\\Cutl1d.pal");
      progress_id = 0;
      break;
    case 1029:
      sgpBackCel = LoadFileInMem("Gendata\\Cutl1d.CEL", 0, 137, "Interfac.cpp");
      LoadPalette("Gendata\\Cutl1d.pal");
      progress_id = 0;
      break;
    case 1030:
      sgpBackCel = LoadFileInMem("Gendata\\Cutportl.CEL", 0, 149, "Interfac.cpp");
      LoadPalette("Gendata\\Cutportl.pal");
      progress_id = 1;
      break;
    case 1031:
    case 1032:
      sgpBackCel = LoadFileInMem("Gendata\\Cut2.CEL", 0, 168, "Interfac.cpp");
      LoadPalette("Gendata\\Cut2.pal");
      progress_id = 2;
      break;
    case 1033:
      sgpBackCel = LoadFileInMem("Gendata\\Cuttt.CEL", 0, 174, "Interfac.cpp");
      LoadPalette("Gendata\\Cuttt.pal");
      progress_id = 1;
      break;
    case 1034:
      sgpBackCel = LoadFileInMem("Gendata\\Cutstart.CEL", 0, 161, "Interfac.cpp");
      LoadPalette("Gendata\\Cutstart.pal");
      progress_id = 1;
      break;
    case 1035:
      sgpBackCel = LoadFileInMem("Gendata\\Cutstart.CEL", 0, 155, "Interfac.cpp");
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
    return MainWndProc(hWnd, Msg, wParam, lParam);
  gbRunGame = 0;
  gbRunGameResult = 0;
  return 0;
}

