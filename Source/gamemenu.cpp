//----- (00466750) --------------------------------------------------------
void __cdecl gamemenu_previous()
{
  if ( gbMaxPlayers == 1 )
  {
    if ( dword_6180EC )
    {
      dword_4D6420 |= 0x80000000;
      dword_4D63E4 |= 0x80000000;
    }
    else
    {
      dword_4D6420 &= 0x7FFFFFFFu;
      dword_4D63E4 &= 0x7FFFFFFFu;
    }
    gmenu_call_proc((char *)&unk_4D6408 + ((&unk_4D63C0 - &unk_4D6408) & ((deathflag != 0) - 1)));
  }
  else
  {
    gmenu_call_proc((char *)&unk_4D6478 + ((&unk_4D6448 - &unk_4D6478) & ((deathflag != 0) - 1)));
  }
}

//----- (004667F5) --------------------------------------------------------
void __cdecl gamemenu_off()
{
  if ( deathflag )
    gamemenu_previous();
  else
    gmenu_call_proc(0);
}

//----- (00466823) --------------------------------------------------------
void __cdecl gamemenu_handle_previous()
{
  if ( gmenu_exception() )
    gamemenu_off();
  else
    gamemenu_previous();
}

//----- (0046684F) --------------------------------------------------------
void __fastcall j_gamemenu_previous(int a1)
{
  assert(a1, 156, "GameMenu.cpp");
  gamemenu_previous();
}

//----- (00466888) --------------------------------------------------------
void __fastcall gamemenu_new_game(int a1)
{
  signed int i; // [esp+10h] [ebp-4h]

  assert(a1, 164, "GameMenu.cpp");
  for ( i = 0; i < 4; ++i )
  {
    plr[i]._pmode = 11;
    plr[i]._pInvincible = 1;
  }
  deathflag = 0;
  drawpanflag = 255;
  scrollrt_draw_game_screen(1);
  gbRunGame = 0;
  gamemenu_off();
}

//----- (00466946) --------------------------------------------------------
void __fastcall gamemenu_quit_game(int a1)
{
  assert(a1, 183, "GameMenu.cpp");
  gamemenu_new_game(a1);
  gbRunGameResult = 0;
}

//----- (0046698C) --------------------------------------------------------
void __fastcall gamemenu_load_game(int a1)
{
  assert(a1, 192, "GameMenu.cpp");
  if ( pcurs == 1 )
  {
    if ( (signed int)gbMaxPlayers <= 1 )
    {
      if ( dword_6180EC )
      {
        gamemenu_off();
        InitDiabloMsg(22);
        drawpanflag = 255;
        DrawAndBlit();
        LoadGame(0);
        ClrDiabloMsg();
        drawpanflag = 255;
        deathflag = 0;
      }
      else
      {
        MessageBeep(0);
      }
    }
    else
    {
      MessageBeep(0);
    }
  }
  else
  {
    MessageBeep(0);
  }
}

//----- (00466A4F) --------------------------------------------------------
void __fastcall gamemenu_save_game(int a1)
{
  assert(a1, 218, "GameMenu.cpp");
  if ( pcurs == 1 )
  {
    if ( (signed int)gbMaxPlayers <= 1 )
    {
      if ( plr[myplr]._pmode == 8 || deathflag )
      {
        MessageBeep(0);
      }
      else
      {
        gamemenu_off();
        InitDiabloMsg(23);
        drawpanflag = 255;
        DrawAndBlit();
        SaveGame();
        ClrDiabloMsg();
        drawpanflag = 255;
      }
    }
    else
    {
      MessageBeep(0);
    }
  }
  else
  {
    MessageBeep(0);
  }
}

//----- (00466B2C) --------------------------------------------------------
void __fastcall gamemenu_restart_town(int a1)
{
  assert(a1, 243, "GameMenu.cpp");
  NetSendCmd(1u, 0x56u);
}

//----- (00466B6F) --------------------------------------------------------
void __fastcall gamemenu_options(int a1)
{
  assert(a1, 312, "GameMenu.cpp");
  gamemenu_get_music();
  gamemenu_get_sound();
  gamemenu_get_gamma();
  gmenu_call_proc(&dword_4D64B8);
}

//----- (00466BBC) --------------------------------------------------------
void __cdecl gamemenu_get_music()
{
  sound_get_or_set_music_volume(1);
  gamemenu_sound_music_toggle(&music_toggle_names, gbMusicOn, &dword_4D64B8);
}

//----- (00466BED) --------------------------------------------------------
void __fastcall gamemenu_sound_music_toggle(_DWORD *a1, BYTE a2, DWORD *a3)
{
  int gamma; // [esp+20h] [ebp+Ch]

  if ( gbSndInited )
  {
    *a3 |= 0xC0000000;
    a3[1] = *a1;
    gmenu_slider_3((TMenuItem *)a3, 17);
    gmenu_slider_1((TMenuItem *)a3, -1600, 0, gamma);
  }
  else
  {
    *a3 &= 0x3FFFFFFFu;
    a3[1] = a1[1];
  }
}

//----- (00466C65) --------------------------------------------------------
void __cdecl gamemenu_get_sound()
{
  sound_get_or_set_sound_volume(1);
  gamemenu_sound_music_toggle(&off_4D6500, gbSoundOn, &dword_4D64B8 + 3);
}

//----- (00466C9A) --------------------------------------------------------
void __cdecl gamemenu_get_gamma()
{
  int v0; // eax

  gmenu_slider_3(&pItem, 15);
  v0 = UpdateGamma(0);
  gmenu_slider_1(&pItem, 30, 100, v0);
}

//----- (00466CD4) --------------------------------------------------------
void __fastcall gamemenu_music_volume(int a1)
{
  int volume; // ST10_4

  if ( a1 )
  {
    if ( gbMusicOn )
    {
      gbMusicOn = 0;
      music_stop();
      sound_get_or_set_music_volume(-1600);
    }
    else
    {
      gbMusicOn = 1;
      sound_get_or_set_music_volume(0);
      music_start((unsigned __int8)leveltype);
    }
  }
  else
  {
    volume = gamemenu_slider_music_sound(&dword_4D64B8);
    sound_get_or_set_music_volume(volume);
    if ( volume == -1600 )
    {
      if ( gbMusicOn )
      {
        gbMusicOn = 0;
        music_stop();
      }
    }
    else if ( !gbMusicOn )
    {
      gbMusicOn = 1;
      music_start((unsigned __int8)leveltype);
    }
  }
  gamemenu_get_music();
}

//----- (00466DAA) --------------------------------------------------------
int __fastcall gamemenu_slider_music_sound(_DWORD *a1)
{
  return gmenu_slider_get((TMenuItem *)a1, -1600, 0);
}

//----- (00466DCF) --------------------------------------------------------
void __fastcall gamemenu_sound_volume(int a1)
{
  int volume; // ST10_4

  if ( a1 )
  {
    if ( gbSoundOn )
    {
      gbSoundOn = 0;
      effects_467E16();
      sound_get_or_set_sound_volume(-1600);
    }
    else
    {
      gbSoundOn = 1;
      sound_get_or_set_sound_volume(0);
    }
  }
  else
  {
    volume = gamemenu_slider_music_sound(&dword_4D64C4);
    sound_get_or_set_sound_volume(volume);
    if ( volume == -1600 )
    {
      if ( gbSoundOn )
      {
        gbSoundOn = 0;
        effects_467E16();
      }
    }
    else if ( !gbSoundOn )
    {
      gbSoundOn = 1;
    }
  }
  gamemenu_get_sound();
}

//----- (00466E8A) --------------------------------------------------------
void __fastcall gamemenu_gamma(int a1)
{
  signed int gamma; // [esp+10h] [ebp-4h]

  if ( a1 )
  {
    if ( UpdateGamma(0) == 30 )
      gamma = 100;
    else
      gamma = 30;
  }
  else
  {
    gamma = gamemenu_slider_gamma();
  }
  UpdateGamma(gamma);
  gamemenu_get_gamma();
}

//----- (00466EEB) --------------------------------------------------------
int __cdecl gamemenu_slider_gamma()
{
  return gmenu_slider_get(&pItem, 30, 100);
}

