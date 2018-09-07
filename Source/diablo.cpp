//----- (00490C20) --------------------------------------------------------
void __cdecl FreeGameMem()
{
  music_stop();
  mem_free_dbg(pDungeonCels, 320, "DIABLO.CPP");
  pDungeonCels = 0;
  mem_free_dbg(pMegaTiles, 322, "DIABLO.CPP");
  pMegaTiles = 0;
  mem_free_dbg(pLevelPieces, 324, "DIABLO.CPP");
  pLevelPieces = 0;
  mem_free_dbg(level_special_cel, 326, "DIABLO.CPP");
  level_special_cel = 0;
  mem_free_dbg(pSpeedCels, 328, "DIABLO.CPP");
  pSpeedCels = 0;
  FreeMissiles();
  FreeMonsters();
  FreeObjectGFX();
  FreeEffects();
  FreeTownerGFX();
}

//----- (00490CE9) --------------------------------------------------------
void __fastcall run_game_loop(int uMsg)
{
  const MSG Msg; // [esp+10h] [ebp-20h]
  WNDPROC func; // [esp+2Ch] [ebp-4h]

  nthread_ignore_mutex(1);
  start_game(uMsg);
  assert(ghMainWnd, "DIABLO.CPP", 380);
  func = SetWindowProc(GM_Game);
  drawpanflag = 255;
  control_update_life_mana();
  DrawAndBlit();
  PaletteFadeIn(8);
  nthread_ignore_mutex(0);
  msg_process_net_packets();
  gbRunGame = 1;
  gbRunGameResult = 1;
  while ( gbRunGame )
  {
    if ( PeekMessageA((LPMSG)&Msg, 0, 0, 0, 0) )
    {
      if ( !GetMessageA((LPMSG)&Msg, 0, 0, 0) )
      {
        gbRunGame = 0;
        gbRunGameResult = 0;
      }
      TranslateMessage(&Msg);
      DispatchMessageA(&Msg);
    }
    else
    {
      diablo_493BDD();                          // This is inlined in 1.09
    }
  }
  if ( (signed int)gbMaxPlayers > 1 )
    pfile_write_hero();
  PaletteFadeOut(8);
  ClearScreenBuffer();
  drawpanflag = 255;
  scrollrt_draw_game_screen(1);
  func = SetWindowProc(func);
  assert(func == GM_Game, "DIABLO.CPP", 419);
  free_game();
}

//----- (00490E61) --------------------------------------------------------
void __fastcall start_game(int uMsg)
{
  zoomflag = 1;
  ShowCursor(0);
  InitCursor();
  MakeLightTable();
  LoadDebugGFX();
  assert(ghMainWnd, "DIABLO.CPP", 348);
  music_stop();
  ShowProgress(uMsg);
  gmenu_init_menu();
  InitLevelCursor();
  sgnTimeoutCurs = 0;
  sgbMouseDown = 0;
  track_repeat_walk(0);
}

//----- (00490EEE) --------------------------------------------------------
void __cdecl free_game()
{
  int pnum; // [esp+Ch] [ebp-4h]

  FreeControlPan();
  FreeInvGFX();
  FreeGMenu();
  FreeQuestText();
  FreeStoreMem();
  for ( pnum = 0; pnum < 4; ++pnum )
    FreePlayerGFX(pnum);
  FreeItemGFX();
  FreeCursor();
  FreeLightTable();
  FreeDebugGFX();
  FreeGameMem();
  ShowCursor(1);
}

//----- (00490F61) --------------------------------------------------------
int __fastcall diablo_init_menu(int a1, int bSinglePlayer)
{
  int v3; // eax
  int v5; // [esp+18h] [ebp-8h]
  int pfExitProgram; // [esp+1Ch] [ebp-4h]

  if ( !NetInit(bSinglePlayer, &pfExitProgram) )
    return pfExitProgram == 0;
  music_stop();
  sound_414561();
  if ( !a1 && dword_6180EC )
  {
    run_game_loop(1035);
  }
  else
  {
    InitQuests();
    InitPortals();
    run_game_loop(1034);
  }
  v5 = v3;
  NetClose();
  if ( v5 )
    mainmenu_refresh_music();
  return v5;
}

//----- (00491008) --------------------------------------------------------
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
  bool v5; // dl
  int v6; // ecx

  ghInst = hInstance;
  if ( !requires_pentium() )
    return 0;
  diablo_init_screen();
  init_create_window(nShowCmd);
  UiInitialize();
  if ( Xshow_intro )
    play_movie("gendata\\logo.smk", v5);
  if ( Xshow_intro )
    play_movie("gendata\\diablo.smk", v5);
  if ( Xshow_intro )
    UiTitleDialog(5);
  if ( Xshow_intro )
    UiBetaDisclaimer(5);
  mainmenu_action(v6);
  UiDestroy();
  SaveGamma();
  if ( ghMainWnd )
    DestroyWindow(ghMainWnd);
  return 0;
}

//----- (004910C8) --------------------------------------------------------
void __cdecl diablo_init_screen()
{
  signed int i; // [esp+Ch] [ebp-4h]

  MouseX = 320;
  MouseY = 240;
  Scrollinfo._sdx = 0;
  Scrollinfo._sdy = 0;
  Scrollinfo._sxoff = 0;
  Scrollinfo._syoff = 0;
  Scrollinfo._sdir = 0;
  for ( i = 0; i < 1024; ++i )
    screen_y_times_768[i] = 768 * i;
  ClrDiabloMsg();
}

//----- (0049115A) --------------------------------------------------------
int __stdcall GM_Game(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  int result; // eax

  if ( uMsg <= WM_SYSCOMMAND )
  {
    if ( uMsg != WM_SYSCOMMAND )
    {
      switch ( uMsg )
      {
        case WM_KEYDOWN:
          if ( !sgbMouseDown )
            PressKey(wParam);
          result = 0;
          break;
        case WM_KEYUP:
          if ( !sgbMouseDown )
            ReleaseKey(wParam);
          result = 0;
          break;
        case WM_CHAR:
          if ( !sgbMouseDown )
            PressChar(wParam);
          result = 0;
          break;
        case WM_SYSKEYDOWN:
          if ( sgbMouseDown || !PressSysKey(wParam) )
            return init_palette(hWnd, uMsg, wParam, lParam);
          result = 0;
          break;
        default:
          return init_palette(hWnd, uMsg, wParam, lParam);
      }
      return result;
    }
    if ( wParam == SC_CLOSE )
    {
      gbRunGame = 0;
      gbRunGameResult = 0;
      return 0;
    }
    return init_palette(hWnd, uMsg, wParam, lParam);
  }
  if ( uMsg > 0x409 )
    return init_palette(hWnd, uMsg, wParam, lParam);
  if ( uMsg >= 0x402 )
  {
    if ( (signed int)gbMaxPlayers > 1 )
      pfile_write_hero();
    nthread_ignore_mutex(1);
    PaletteFadeOut(8);
    effects_467E16();
    music_stop();
    ShowProgress(uMsg);
    drawpanflag = 255;
    DrawAndBlit();
    PaletteFadeIn(8);
    nthread_ignore_mutex(0);
    result = 0;
  }
  else
  {
    switch ( uMsg )
    {
      case WM_MOUSEMOVE:
        MouseX = (unsigned __int16)lParam;
        MouseY = (unsigned int)lParam >> 16;
        diablo_49200C();
        result = 0;
        break;
      case WM_LBUTTONDOWN:
        MouseX = (unsigned __int16)lParam;
        MouseY = (unsigned int)lParam >> 16;
        if ( !sgbMouseDown )
        {
          sgbMouseDown = 1;
          LeftMouseDown(wParam);
        }
        result = 0;
        break;
      case WM_LBUTTONUP:
        MouseX = (unsigned __int16)lParam;
        MouseY = (unsigned int)lParam >> 16;
        if ( sgbMouseDown == 1 )
        {
          sgbMouseDown = 0;
          LeftMouseUp();
        }
        result = 0;
        break;
      case WM_RBUTTONDOWN:
        MouseX = (unsigned __int16)lParam;
        MouseY = (unsigned int)lParam >> 16;
        if ( !sgbMouseDown )
        {
          sgbMouseDown = 2;
          RightMouseDown();
        }
        result = 0;
        break;
      case WM_RBUTTONUP:
        MouseX = (unsigned __int16)lParam;
        MouseY = (unsigned int)lParam >> 16;
        if ( sgbMouseDown == 2 )
          sgbMouseDown = 0;
        result = 0;
        break;
      default:
        return init_palette(hWnd, uMsg, wParam, lParam);
    }
  }
  return result;
}

//----- (00491497) --------------------------------------------------------
bool __fastcall LeftMouseDown(int wParam)
{
  int v1; // eax

  track_repeat_walk(0);
  v1 = gmenu_left_mouse(1);
  if ( !v1 && !sgnTimeoutCurs )
  {
    LOBYTE(v1) = 38 * myplr;
    if ( plr[myplr]._pInvincible && deathflag )
    {
      control_check_btn_press();
    }
    else if ( PauseMode != 2 )
    {
      if ( spselflag )
      {
        SetSpell();
      }
      else if ( stextflag )
      {
        CheckStoreBtn();
      }
      else if ( MouseY >= 352 )
      {
        if ( !talkflag && !dropGoldFlag )
          CheckInvScrn();
        DoPanBtn();
        if ( pcurs > 1 && pcurs < 12 )
          j_SetCursor(1);
      }
      else
      {
        v1 = TryIconCurs();
        if ( !v1 )
        {
          if ( questlog && MouseX > 32 && MouseX < 288 && MouseY > 32 && MouseY < 308 )
          {
            QuestlogESC();
          }
          else if ( chrflag && MouseX < 320 )
          {
            CheckChrBtns();
          }
          else if ( invflag && MouseX > 320 )
          {
            if ( !dropGoldFlag )
              CheckInvItem();
          }
          else if ( sbookflag && MouseX > 320 )
          {
            CheckSBook();
          }
          else if ( pcurs < 12 )
          {
            LOBYTE(v1) = 38 * myplr;
            if ( plr[myplr]._pStatPts && !spselflag )
              CheckLvlBtn();
            if ( !lvlbtndown )
              diablo_491753(wParam == (MK_SHIFT|MK_LBUTTON));// This function is inlined in 1.09
          }
          else
          {
            v1 = TryInvPut();
            if ( v1 )
            {
              NetSendCmdPItem(1u, 0xCu, cursmx, cursmy);
              j_SetCursor(1);
            }
          }
        }
      }
    }
  }
  return v1;
}

//----- (00491753) --------------------------------------------------------
void __fastcall diablo_491753(BOOL shift)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax
  BOOL v5; // [esp+10h] [ebp-4h]

  assert(MouseY < 352, "DIABLO.CPP", 528);
  if ( leveltype )
  {
    v5 = abs(plr[myplr].WorldX - cursmx) < 2 && abs(plr[myplr].WorldY - cursmy) < 2;
    v2 = pcursitem;
    if ( pcursitem == -1 || pcurs != 1 || shift )
    {
      v3 = pcursobj;
      if ( pcursobj == -1 || shift && (!v5 || (v3 = object[pcursobj]._oBreak, v3 != 1)) )
      {
        if ( plr[myplr]._pwtype == 1 )
        {
          if ( shift )
          {
            NetSendCmdLoc(1u, CMD_RATTACKXY, cursmx, cursmy);
          }
          else if ( pcursmonst == -1 )
          {
            if ( pcursplr != -1 && !FriendlyMode )
              NetSendCmdParam1(1u, CMD_RATTACKPID, pcursplr);
          }
          else
          {
            NetSendCmdParam1(1u, CMD_RATTACKID, pcursmonst);
          }
        }
        else if ( shift )
        {
          NetSendCmdLoc(1u, CMD_SATTACKXY, cursmx, cursmy);
        }
        else if ( pcursmonst == -1 )
        {
          if ( pcursplr != -1 && !FriendlyMode )
            NetSendCmdParam1(1u, CMD_ATTACKPID, pcursplr);
        }
        else
        {
          NetSendCmdParam1(1u, CMD_ATTACKID, pcursmonst);
        }
      }
      else
      {
        LOWORD(v3) = pcursobj;
        NetSendCmdLocParam1(1u, ((unsigned int)(pcurs - 5) < 1) + CMD_OPOBJXY, cursmx, cursmy, v3);
      }
    }
    else
    {
      LOWORD(v2) = pcursitem;
      NetSendCmdLocParam1(1u, ((unsigned int)invflag < 1) + CMD_GOTOGETITEM, cursmx, cursmy, v2);
    }
    if ( !shift && pcursitem == -1 && pcursobj == -1 && pcursmonst == -1 && pcursplr == -1 )
      track_repeat_walk(1);
  }
  else
  {
    v1 = pcursitem;
    if ( pcursitem != -1 && pcurs == 1 )
    {
      LOWORD(v1) = pcursitem;
      NetSendCmdLocParam1(1u, ((unsigned int)invflag < 1) + CMD_GOTOGETITEM, cursmx, cursmy, v1);
    }
    if ( pcursmonst != -1 )
      NetSendCmdLocParam1(1u, CMD_TALKXY, cursmx, cursmy, pcursmonst);
    if ( pcursitem == -1 && pcursmonst == -1 && pcursplr == -1 )
      track_repeat_walk(1);
  }
}

//----- (00491B3A) --------------------------------------------------------
BOOL __cdecl TryIconCurs()
{
  BOOL result; // eax

  switch ( pcurs )
  {
    case 8:
      NetSendCmdParam1(1u, CMD_RESURRECT, pcursplr);
      result = 1;
      break;
    case 10:
      NetSendCmdParam1(1u, CMD_HEALOTHER, pcursplr);
      result = 1;
      break;
    case 7:
      DoTelekinesis();
      result = 1;
      break;
    case 2:
      if ( pcursinvitem == -1 )
        j_SetCursor(1);
      else
        CheckIdentify(myplr, pcursinvitem);
      result = 1;
      break;
    case 3:
      if ( pcursinvitem == -1 )
        j_SetCursor(1);
      else
        DoRepair(myplr, pcursinvitem);
      result = 1;
      break;
    case 4:
      if ( pcursinvitem == -1 )
        j_SetCursor(1);
      else
        DoRecharge(myplr, pcursinvitem);
      result = 1;
      break;
    case 6:
      if ( pcursinvitem == -1 )
        j_SetCursor(1);
      else
        DoOil(myplr, pcursinvitem);
      result = 1;
      break;
    case 9:
      if ( pcursmonst == -1 )
      {
        if ( pcursplr == -1 )
          NetSendCmdLocParam1(1u, CMD_TSPELLXY, cursmx, cursmy, plr[myplr]._pTSpell);
        else
          NetSendCmdParam2(1u, CMD_TSPELLPID, pcursplr, plr[myplr]._pTSpell);
      }
      else
      {
        NetSendCmdParam2(1u, CMD_TSPELLID, pcursmonst, plr[myplr]._pTSpell);
      }
      j_SetCursor(1);
      result = 1;
      break;
    default:
      if ( pcurs != 5 || pcursobj != -1 )
      {
        result = 0;
      }
      else
      {
        j_SetCursor(1);
        result = 1;
      }
      break;
  }
  return result;
}

//----- (00491E07) --------------------------------------------------------
void __cdecl LeftMouseUp()
{
  gmenu_left_mouse(0);
  track_repeat_walk(0);
  if ( panbtndown )
    CheckBtnUp();
  if ( chrbtnactive )
    ReleaseChrBtns();
  if ( lvlbtndown )
    ReleaseLvlBtn();
  if ( stextflag )
    ReleaseStoreBtn();
}

//----- (00491E6F) --------------------------------------------------------
void __cdecl RightMouseDown()
{
  if ( !gmenu_exception() && !sgnTimeoutCurs && PauseMode != 2 && !plr[myplr]._pInvincible && !stextflag )
  {
    if ( spselflag )
    {
      SetSpell();
      return;
    }
    if ( !sbookflag || !control_41A64E() )
    {
      if ( MouseY >= 352 )
        goto LABEL_26;
      if ( TryIconCurs() )
        return;
      if ( pcursinvitem != -1 && UseInvItem(myplr, pcursinvitem) )
      {
        inv_4571FD(myplr, pcursinvitem);
      }
      else
      {
LABEL_26:
        if ( pcurs == 1 )
        {
          if ( pcursinvitem != -1 && UseInvItem(myplr, pcursinvitem) )
            inv_4571FD(myplr, pcursinvitem);
          else
            CheckPlrSpell();
        }
        else if ( pcurs > 1 && pcurs < 12 )
        {
          j_SetCursor(1);
        }
      }
    }
  }
}

//----- (0049200C) --------------------------------------------------------
void __cdecl diablo_49200C()
{
  if ( !gmenu_on_mouse_move() && !sgnTimeoutCurs )
    track_process();
}

//----- (00492045) --------------------------------------------------------
BOOL __fastcall PressSysKey(int wParam)
{
  if ( gmenu_exception() )
    return 0;
  if ( wParam != VK_F10 )
    return 0;
  diablo_hotkey_msg(1);
  return 1;
}

//----- (0049208F) --------------------------------------------------------
void __fastcall diablo_hotkey_msg(int dwMsg)
{
  char *i; // [esp+10h] [ebp-15Ch]
  char ReturnedString[80]; // [esp+14h] [ebp-158h]
  char Filename[260]; // [esp+64h] [ebp-108h]
  char *v5; // [esp+168h] [ebp-4h]

  if ( gbMaxPlayers != 1 )
  {
    if ( !GetModuleFileNameA(ghInst, Filename, 0x104u) )
      TermMsg("Can't get program name");
    v5 = strrchr(Filename, 92);
    if ( v5 )
      *v5 = 0;
    strcat(Filename, "\\Diablo.ini");
    assert((unsigned int)dwMsg < 4, "DIABLO.CPP", 809);
    GetPrivateProfileStringA("NetMsg", spszMsgKeyTbl[dwMsg], spszMsgTbl[dwMsg], ReturnedString, 0x50u, Filename);
    for ( i = ReturnedString; *i; ++i )
    {
      if ( *i < 32 || *i > 127 )
        *i = 32;
    }
    NetSendCmdString(-1, ReturnedString);
  }
}

//----- (004921E7) --------------------------------------------------------
void __fastcall ReleaseKey(int vkey)
{
  if ( vkey == VK_SNAPSHOT )
    CaptureScreen();
}

//----- (0049220C) --------------------------------------------------------
void __fastcall PressKey(int vkey)
{
  if ( !gmenu_presskeys(vkey) && !sgnTimeoutCurs )
  {
    if ( !plr[myplr]._pInvincible || !deathflag )
      goto LABEL_143;
    if ( talkflag )
      control_press_enter(vkey);
    if ( vkey == VK_F9 )
      diablo_hotkey_msg(0);
    if ( vkey == VK_F10 )
      diablo_hotkey_msg(1);
    if ( vkey == VK_F11 )
      diablo_hotkey_msg(2);
    if ( vkey == VK_F12 )
      diablo_hotkey_msg(3);
    if ( vkey == VK_RETURN )
      control_reset_talk_msg();
    if ( vkey == VK_ESCAPE )
    {
LABEL_143:
      if ( !dropGoldFlag )
      {
        if ( vkey == VK_ESCAPE )
        {
          if ( helpflag )
          {
            helpflag = 0;
          }
          else if ( qtextflag )
          {
            qtextflag = 0;
            if ( !leveltype )
              sfx_stop();
          }
          else if ( stextflag )
          {
            STextESC();
          }
          else if ( questlog )
          {
            QuestlogOff();
          }
          else if ( msgflag )
          {
            msgdelay = 0;
          }
          else if ( talkflag )
          {
            control_reset_talk();
          }
          else
          {
            gamemenu_previous();
          }
        }
        else if ( vkey == 19 )
        {
          NetSendCmd(1u, VK_NEXT);
        }
        else if ( PauseMode != 2 )
        {
          switch ( vkey )
          {
            case VK_F1:
              if ( helpflag )
              {
                helpflag = 0;
              }
              else if ( stextflag )
              {
                ClearPanel();
                AddPanelString("No help available", 1);
                AddPanelString("while in stores", 1);
              }
              else
              {
                invflag = 0;
                chrflag = 0;
                sbookflag = 0;
                spselflag = 0;
                if ( qtextflag && !leveltype )
                {
                  qtextflag = 0;
                  sfx_stop();
                }
                questlog = 0;
                automapflag = 0;
                msgdelay = 0;
                gamemenu_off();
                DisplayHelp();
              }
              break;
            case VK_F5:
              if ( spselflag )
                SetSpeedSpell(0);
              else
                ToggleSpell(0);
              break;
            case VK_F6:
              if ( spselflag )
                SetSpeedSpell(1);
              else
                ToggleSpell(1);
              break;
            case VK_F7:
              if ( spselflag )
                SetSpeedSpell(2);
              else
                ToggleSpell(2);
              break;
            case VK_F8:
              if ( spselflag )
                SetSpeedSpell(3);
              else
                ToggleSpell(3);
              break;
            case VK_F9:
              diablo_hotkey_msg(0);
              break;
            case VK_F10:
              diablo_hotkey_msg(1);
              break;
            case VK_F11:
              diablo_hotkey_msg(2);
              break;
            case VK_F12:
              diablo_hotkey_msg(3);
              break;
            case VK_UP:
              if ( stextflag )
              {
                STextUp();
              }
              else if ( questlog )
              {
                QuestlogUp();
              }
              else if ( helpflag )
              {
                HelpScrollUp();
              }
              else if ( automapflag )
              {
                AutomapUp();
              }
              break;
            case VK_DOWN:
              if ( stextflag )
              {
                STextDown();
              }
              else if ( questlog )
              {
                QuestlogDown();
              }
              else if ( helpflag )
              {
                HelpScrollDown();
              }
              else if ( automapflag )
              {
                AutomapDown();
              }
              break;
            case VK_LEFT:
              if ( automapflag )
                AutomapLeft();
              break;
            case VK_RIGHT:
              if ( automapflag )
                AutomapRight();
              break;
            case VK_RETURN:
              if ( stextflag )
              {
                STextEnter();
              }
              else if ( questlog )
              {
                QuestlogEnter();
              }
              else
              {
                control_reset_talk_msg();
              }
              break;
            default:
              if ( talkflag )
              {
                control_press_enter(vkey);
              }
              else
              {
                switch ( vkey )
                {
                  case VK_TAB:
                    if ( currlevel )
                    {
                      if ( automapflag )
                        automapflag = 0;
                      else
                        StartAutomap();
                    }
                    else if ( msgflag )
                    {
                      ClrDiabloMsg();
                    }
                    else
                    {
                      InitDiabloMsg(1);
                    }
                    break;
                  case VK_CAPITAL:
                    FriendlyMode = FriendlyMode == 0;
                    drawbtnflag = 1;
                    break;
                  case VK_SPACE:
                    if ( !chrflag && invflag && MouseX < 480 )
                      SetCursorPos(MouseX + 160, MouseY);
                    if ( !invflag && chrflag && MouseX > 160 )
                      SetCursorPos(MouseX - 160, MouseY);
                    helpflag = 0;
                    invflag = 0;
                    chrflag = 0;
                    sbookflag = 0;
                    spselflag = 0;
                    if ( qtextflag && !leveltype )
                    {
                      qtextflag = 0;
                      sfx_stop();
                    }
                    questlog = 0;
                    automapflag = 0;
                    msgdelay = 0;
                    gamemenu_off();
                    if ( pcurs != 1 && pcurs < 12 )
                      j_SetCursor(1);
                    break;
                }
              }
              break;
          }
        }
      }
    }
  }
}

//----- (00492954) --------------------------------------------------------
void __fastcall PressChar(char vkey)
{
  int v1; // [esp+0h] [ebp-14h]

  if ( !gmenu_exception() && !sgnTimeoutCurs )
  {
    if ( talkflag )
    {
      control_presskeys(vkey);
    }
    else if ( !plr[myplr]._pInvincible || !deathflag )
    {
      if ( vkey != VK_F1 && vkey != 80 )
      {
        if ( PauseMode != 2 )
        {
          if ( dropGoldFlag )
          {
            control_drop_gold(v1);
          }
          else
          {
            switch ( vkey )
            {
              case VK_PRIOR:
              case VK_PRIOR|VK_SHIFT:
                if ( plr[myplr].SpdList[0]._itype != -1 && plr[myplr].SpdList[0]._itype != 11 )
                  inv_4571FD(myplr, 47);
                break;
              case VK_END:
              case VK_END|VK_SHIFT:
                if ( plr[myplr].SpdList[2]._itype != -1 && plr[myplr].SpdList[2]._itype != 11 )
                  inv_4571FD(myplr, 49);
                break;
              case VK_HOME:
              case VK_HOME|VK_SHIFT:
                if ( plr[myplr].SpdList[3]._itype != -1 && plr[myplr].SpdList[3]._itype != 11 )
                  inv_4571FD(myplr, 50);
                break;
              case VK_LEFT:
              case VK_LEFT|VK_SHIFT:
                if ( plr[myplr].SpdList[4]._itype != -1 && plr[myplr].SpdList[4]._itype != 11 )
                  inv_4571FD(myplr, 51);
                break;
              case VK_UP:
              case VK_RIGHT|VK_SHIFT:
                if ( plr[myplr].SpdList[6]._itype != -1 && plr[myplr].SpdList[6]._itype != 11 )
                  inv_4571FD(myplr, 53);
                break;
              case VK_PRINT:
              case VK_DOWN|VK_SHIFT:
                if ( plr[myplr].SpdList[7]._itype != -1 && plr[myplr].SpdList[7]._itype != 11 )
                  inv_4571FD(myplr, 54);
                break;
              case VK_EXECUTE:
              case VK_INSERT|VK_SHIFT:
                if ( automapflag )
                  AutomapZoomIn();
                break;
              case VK_INSERT:
              case VK_APPS|VK_RBUTTON:
                if ( automapflag )
                  AutomapZoomOut();
                break;
              case VK_NEXT|VK_SHIFT:
              case 0x40:
                if ( plr[myplr].SpdList[1]._itype != -1 && plr[myplr].SpdList[1]._itype != 11 )
                  inv_4571FD(myplr, 48);
                break;
              case VK_UP|VK_SHIFT:
              case VK_RWIN|VK_RBUTTON:
                if ( plr[myplr].SpdList[5]._itype != -1 && plr[myplr].SpdList[5]._itype != 11 )
                  inv_4571FD(myplr, 52);
                break;
              case 0x42:
              case VK_NUMPAD2:
                if ( !stextflag )
                {
                  invflag = 0;
                  sbookflag = sbookflag == 0;
                }
                break;
              case VK_CANCEL|0x40:
              case VK_NUMPAD3:
                if ( !stextflag )
                {
                  questlog = 0;
                  chrflag = chrflag == 0;
                  if ( !chrflag || invflag )
                  {
                    if ( MouseX > 160 )
                      SetCursorPos(MouseX - 160, MouseY);
                  }
                  else if ( MouseX < 480 )
                  {
                    SetCursorPos(MouseX + 160, MouseY);
                  }
                }
                break;
              case VK_MBUTTON|VK_RBUTTON|0x40:
              case VK_NUMPAD6:
                IncreaseGamma();
                break;
              case VK_MBUTTON|VK_CANCEL|0x40:
              case VK_NUMPAD7:
                DecreaseGamma();
                break;
              case VK_TAB|0x40:
              case VK_NUMPAD9:
                if ( !stextflag )
                {
                  sbookflag = 0;
                  invflag = invflag == 0;
                  if ( !invflag || chrflag )
                  {
                    if ( MouseX < 480 )
                      SetCursorPos(MouseX + 160, MouseY);
                  }
                  else if ( MouseX > 160 )
                  {
                    SetCursorPos(MouseX - 160, MouseY);
                  }
                }
                break;
              case VK_CONTROL|0x40:
              case VK_F2:
                if ( !stextflag )
                {
                  chrflag = 0;
                  if ( questlog )
                    questlog = 0;
                  else
                    StartQuestlog();
                }
                break;
              case VK_MENU|0x40:
              case VK_F3:
                ClearPanel();
                sprintf(tempstr, "seed0 = %i", glSeedTbl[0]);
                AddPanelString(tempstr, 0);
                sprintf(tempstr, "seed1 = %i", dword_649C0C);
                AddPanelString(tempstr, 0);
                sprintf(tempstr, "seed2 = %i", dword_649C10);
                AddPanelString(tempstr, 0);
                break;
              case VK_PAUSE|0x40:
              case VK_F4:
                if ( !stextflag )
                {
                  invflag = 0;
                  if ( spselflag )
                    spselflag = 0;
                  else
                    DoSpeedBook();
                }
                break;
              case VK_CAPITAL|VK_RBUTTON|0x40:
              case VK_F7:
                AddPanelString("version unknown", 1);
                break;
              case VK_FINAL|VK_RBUTTON|0x40:
              case VK_F11:
                zoomflag = zoomflag == 0;
                break;
              default:
                return;
            }
          }
        }
      }
      else
      {
        NetSendCmd(1u, 0x22u);
      }
    }
  }
}

//----- (004931A7) --------------------------------------------------------
void __cdecl LoadLvlGFX()
{
  assert(!pDungeonCels, "DIABLO.CPP", 1447);
  if ( leveltype )
  {
    if ( leveltype == 1 )
    {
      pDungeonCels = LoadFileInMem("Levels\\L1Data\\L1.CEL", 0, 1457, "DIABLO.CPP");
      pMegaTiles = (WORD *)LoadFileInMem("Levels\\L1Data\\L1.TIL", 0, 1458, "DIABLO.CPP");
      pLevelPieces = LoadFileInMem("Levels\\L1Data\\L1.MIN", 0, 1459, "DIABLO.CPP");
      level_special_cel = (char *)LoadFileInMem("Levels\\L1Data\\L1S.CEL", 0, 1460, "DIABLO.CPP");
    }
    else
    {
      if ( leveltype != 2 )
        TermMsg("LoadLvlGFX");
      pDungeonCels = LoadFileInMem("Levels\\L2Data\\L2.CEL", 0, 1465, "DIABLO.CPP");
      pMegaTiles = (WORD *)LoadFileInMem("Levels\\L2Data\\L2.TIL", 0, 1466, "DIABLO.CPP");
      pLevelPieces = LoadFileInMem("Levels\\L2Data\\L2.MIN", 0, 1467, "DIABLO.CPP");
      level_special_cel = (char *)LoadFileInMem("Levels\\L2Data\\L2S.CEL", 0, 1468, "DIABLO.CPP");
    }
  }
  else
  {
    pDungeonCels = LoadFileInMem("Levels\\TownData\\Town.CEL", 0, 1450, "DIABLO.CPP");
    pMegaTiles = (WORD *)LoadFileInMem("Levels\\TownData\\Town.TIL", 0, 1451, "DIABLO.CPP");
    pLevelPieces = LoadFileInMem("Levels\\TownData\\Town.MIN", 0, 1452, "DIABLO.CPP");
    level_special_cel = (char *)LoadFileInMem("Levels\\TownData\\TownS.CEL", 0, 1453, "DIABLO.CPP");
  }
}

//----- (00493377) --------------------------------------------------------
void __cdecl LoadAllGFX()
{
  assert(!pSpeedCels, "DIABLO.CPP", 1501);
  pSpeedCels = DiabloAllocPtr(0x100000, 1502, "DIABLO.CPP");
  IncProgress();
  IncProgress();
  InitObjectGFX();
  IncProgress();
  InitMissileGFX();
  IncProgress();
}

//----- (004933DF) --------------------------------------------------------
void __fastcall CreateLevel(int lvldir)
{
  if ( leveltype )
  {
    if ( leveltype == 1 )
    {
      CreateL5Dungeon(glSeedTbl[currlevel], lvldir);
      InitL1Triggers();
      LoadRndLvlPal(1);
    }
    else
    {
      if ( leveltype != 2 )
        TermMsg("CreateLevel");
      CreateL2Dungeon(glSeedTbl[currlevel], lvldir);
      InitL2Triggers();
      LoadRndLvlPal(2);
    }
  }
  else
  {
    CreateTown(lvldir);
    InitTownTriggers();
    LoadRndLvlPal(0);
  }
}

//----- (004934AB) --------------------------------------------------------
void __fastcall LoadGameLevel(BOOL firstflag, int lvldir)
{
  int v2; // eax
  int v3; // ecx
  BOOL v6; // [esp+14h] [ebp-8h]
  int pnum; // [esp+18h] [ebp-4h]
  int pnuma; // [esp+18h] [ebp-4h]
  signed int pnumb; // [esp+18h] [ebp-4h]
  int pnumc; // [esp+18h] [ebp-4h]
  signed int pnumd; // [esp+18h] [ebp-4h]

  if ( setseed )
    glSeedTbl[currlevel] = setseed;
  music_stop();
  SetCursor(1);
  SetRndSeed(glSeedTbl[currlevel]);
  IncProgress();
  LoadLvlGFX();
  IncProgress();
  if ( firstflag )
  {
    InitInv();
    InitItemGFX();
    InitQuestText();
    for ( pnum = 0; gbMaxPlayers > pnum; ++pnum )
      InitPlrGFXMem(pnum);
    InitStores();
    InitAutomapOnce();
    InitHelp();
  }
  SetRndSeed(glSeedTbl[currlevel]);
  if ( !leveltype )
    SetupTownStores();
  IncProgress();
  if ( leveltype )
    InitAutomap();
  if ( leveltype && lvldir != 4 )
  {
    InitLighting();
    InitVision();
  }
  InitLevelMonsters();
  IncProgress();
  if ( setlevel )
  {
    assert(!pSpeedCels, "DIABLO.CPP", 1700);
    pSpeedCels = DiabloAllocPtr(0x100000, 1701, "DIABLO.CPP");
    LoadSetMap();
    IncProgress();
    GetLevelMTypes();
    InitMissileGFX();
    FillSolidBlockTbls();
    IncProgress();
    for ( pnumc = 0; pnumc < 4; ++pnumc )
    {
      if ( plr[pnumc].plractive )
      {
        if ( plr[pnumc].plrlevel == currlevel )
        {
          InitPlayerGFX(pnumc);
          if ( lvldir != 4 )
            InitPlayer(pnumc, firstflag);
        }
      }
    }
    InitMultiView();
    IncProgress();
    if ( firstflag || lvldir == 4 || !plr[myplr]._pSLvlVisited[(unsigned __int8)setlvlnum] )
    {
      InitItems();
      SavePreLighting();
    }
    else
    {
      LoadLevel();
    }
    InitMissiles();
    InitDead();
    IncProgress();
  }
  else
  {
    CreateLevel(lvldir);
    IncProgress();
    FillSolidBlockTbls();
    SetRndSeed(glSeedTbl[currlevel]);
    if ( leveltype )
    {
      GetLevelMTypes();
      InitThemes();
      LoadAllGFX();
    }
    else
    {
      InitMissileGFX();
    }
    IncProgress();
    if ( lvldir == 3 || lvldir == 5 )
      GetPortalLvlPos();
    IncProgress();
    for ( pnuma = 0; pnuma < 4; ++pnuma )
    {
      if ( plr[pnuma].plractive && plr[pnuma].plrlevel == currlevel )
      {
        InitPlayerGFX(pnuma);
        if ( lvldir != 4 )
          InitPlayer(pnuma, firstflag);
      }
    }
    InitMultiView();
    IncProgress();
    v6 = 0;
    for ( pnumb = 0; gbMaxPlayers > pnumb; ++pnumb )
    {
      if ( plr[pnumb].plractive )
        v6 = v6 || plr[pnumb]._pLvlVisited[currlevel];
    }
    SetRndSeed(glSeedTbl[currlevel]);
    if ( leveltype )
    {
      if ( firstflag || lvldir == 4 || !plr[myplr]._pLvlVisited[currlevel] || gbMaxPlayers != 1 )
      {
        HoldThemeRooms();
        InitMonsters();
        v2 = GetRndSeed();
        v3 = currlevel;
        glMid1Seed[v3] = v2;
        InitObjects(v3);
        InitItems();
        CreateThemeRooms();
        glMid2Seed[currlevel] = GetRndSeed();
        InitMissiles();
        InitDead();
        glEndSeed[currlevel] = GetRndSeed();
        if ( gbMaxPlayers != 1 )
          DeltaLoadLevel();
        IncProgress();
        SavePreLighting();
      }
      else
      {
        InitMonsters();
        InitMissiles();
        InitDead();
        IncProgress();
        LoadLevel();
        IncProgress();
      }
    }
    else
    {
      InitTowners();
      InitItems();
      InitMissiles();
      IncProgress();
      if ( !firstflag && lvldir != 4 && plr[myplr]._pLvlVisited[currlevel] && gbMaxPlayers == 1 )
        LoadLevel();
      if ( gbMaxPlayers != 1 )
        DeltaLoadLevel();
      IncProgress();
    }
  }
  SyncPortals();
  for ( pnumd = 0; pnumd < 4; ++pnumd )
  {
    if ( plr[pnumd].plractive && plr[pnumd].plrlevel == currlevel )
      dPlayer[plr[pnumd].WorldX][plr[pnumd].WorldY] = pnumd + 1;
  }
  if ( leveltype )
    SetDungeonMicros();
  InitLightMax();
  IncProgress();
  IncProgress();
  if ( firstflag )
  {
    InitControlPan();
    IncProgress();
  }
  if ( leveltype )
  {
    ProcessLightList();
    ProcessVisionList();
  }
  music_start((unsigned __int8)leveltype);
  while ( !IncProgress() )
    ;
}

//----- (00493BDD) --------------------------------------------------------
void __cdecl diablo_493BDD()
{
  multi_process_network_packets();
  if ( nthread_has_500ms_passed() )
  {
    game_loop();
    diablo_color_cyc_logic();
  }
}

//----- (00493C0E) --------------------------------------------------------
void __fastcall game_loop()
{
  signed int v0; // ST0C_4
  signed int v1; // [esp+10h] [ebp-4h]

  v1 = 3;
  do
  {
    v0 = v1--;
    if ( !v0 )
      break;
    if ( !multi_handle_delta() )
    {
      timeout_cursor(1);
      return;
    }
    timeout_cursor(0);
    game_logic();
  }
  while ( gbRunGame && gbMaxPlayers != 1 && nthread_has_500ms_passed() );
}

//----- (00493CA1) --------------------------------------------------------
void __cdecl game_logic()
{
  if ( PauseMode != 2 )
  {
    if ( PauseMode == 1 )
      PauseMode = 2;
    if ( !gmenu_exception() )
    {
      track_process();
      CheckCursMove();
    }
    ProcessPlayers();
    if ( leveltype )
    {
      ProcessMonsters();
      ProcessObjects();
      ProcessMissiles();
      ProcessItems();
      ProcessLightList();
      ProcessVisionList();
    }
    else
    {
      ProcessTowners();
      ProcessItems();
      ProcessMissiles();
    }
    if ( Xhelpflag_2 )
      new_help_mode();
    sound_update();
    ClearPlrMsg();
    CheckTriggers();
    CheckQuests();
    drawpanflag |= 1u;
    pfile_update(0);
  }
}

//----- (00493D6B) --------------------------------------------------------
void __fastcall timeout_cursor(bool timeout)
{
  if ( timeout )
  {
    if ( sgnTimeoutCurs || sgbMouseDown )
    {
      if ( !PauseMode )
      {
        scrollrt_draw_cursor_back_buffer();
        scrollrt_draw_cursor_item();
        scrollrt_draw_game_screen(1);
      }
    }
    else
    {
      sgnTimeoutCurs = pcurs;
      ClearPanel();
      AddPanelString("Waiting for player(s)...", 0);
      AddPanelString("Shift-F1 drops remote players", 0);
      AddPanelString("Shift-F4 leaves game", 0);
      ClearCtrlPan();
      UpdateLifeFlask();
      UpdateManaFlask();
      DrawCtrlPan();
      DrawInvBelt();
      DrawTalkPan();
      j_SetCursor(11);
      drawpanflag = 255;
      scrollrt_draw_game_screen(1);
    }
    if ( (((unsigned __int16)GetAsyncKeyState(VK_SHIFT) >> 8) & 0x80u) != 0 )
    {
      if ( (((unsigned __int16)GetAsyncKeyState(VK_F1) >> 8) & 0x80u) == 0 )
      {
        if ( (((unsigned __int16)GetAsyncKeyState(VK_F4) >> 8) & 0x80u) != 0 )
          gbRunGame = 0;
      }
      else
      {
        sgbTimeout = 1;
      }
    }
  }
  else if ( sgnTimeoutCurs )
  {
    SetCursor(sgnTimeoutCurs);
    sgnTimeoutCurs = 0;
    ClearPanel();
    ClearCtrlPan();
    drawpanflag = 255;
  }
}

//----- (00493EC9) --------------------------------------------------------
void __cdecl diablo_color_cyc_logic()
{
  DrawAndBlit();
  if ( (signed int)(unsigned __int8)leveltype >= 3 && (signed int)(unsigned __int8)leveltype <= 4 )
  {
    if ( fullscreen )
      palette_update_caves();
  }
}

