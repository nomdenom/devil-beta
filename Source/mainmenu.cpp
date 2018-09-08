#include "all.h"

//----- (0043A170) --------------------------------------------------------
void __cdecl mainmenu_refresh_music()
{
  music_start(nTrack);
  do
  {
    if ( ++nTrack == 6 )
      nTrack = 0;
  }
  while ( !nTrack || nTrack == 1 );
}

//----- (0043A1C2) --------------------------------------------------------
void __fastcall mainmenu_action(int option)
{
  bool v1; // dl
  int v2; // [esp+10h] [ebp-8h]
  int v3; // [esp+14h] [ebp-4h]

  mainmenu_refresh_music();
  v3 = 0;
LABEL_2:
  while ( !v3 )
  {
    v2 = 0;
    if ( !UiMainMenuDialog((int)"version unknown", (int)&v2, (int)sound_41464E) )
      TermMsg("Unable to display mainmenu");
    switch ( v2 )
    {
      case 1:
        DrawDlg("Not available in beta version");
        break;
      case 2:
        if ( !mainmenu_multi_player() )
          v3 = 1;
        break;
      case 3:
        music_stop();
        play_movie("gendata\\diablo.smk", v1);
        mainmenu_refresh_music();
        break;
      case 4:
        UiCreditsDialog(16);
        break;
      case 5:
        v3 = 1;
        break;
      default:
        goto LABEL_2;
    }
  }
  music_stop();
}

//----- (0043A2BB) --------------------------------------------------------
int __cdecl mainmenu_multi_player()
{
  int a1; // [esp+Ch] [ebp-4h]

  mainmenu_61D640_unused = 0;
  gbMaxPlayers = 4;
  a1 = 0;
  if ( !UiSelHeroMultDialog(
          pfile_ui_set_hero_infos,
          pfile_ui_save_create,
          pfile_delete_save,
          pfile_ui_set_class_stats,
          &a1,
          name) )
    TermMsg("Can't load multiplayer dialog");
  return mainmenu_init_menu(a1);
}

//----- (0043A325) --------------------------------------------------------
int __fastcall mainmenu_init_menu(int a1)
{
  int result; // eax

  if ( a1 == 4 )
    result = 1;
  else
    result = diablo_init_menu(a1 != 2, a1 != 3);
  return result;
}

