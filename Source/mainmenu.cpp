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
    if ( !UiMainMenuDialog("version unknown", &v2, sound_41464E) )
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

//----- (0043A370) --------------------------------------------------------
void __fastcall LoadL3Dungeon(char *sFileName, int vx, int vy)
{
  int nYPos; // [esp+14h] [ebp-18h]
  signed int nYPosa; // [esp+14h] [ebp-18h]
  int nYPosb; // [esp+14h] [ebp-18h]
  int nXPos; // [esp+18h] [ebp-14h]
  signed int nXPosa; // [esp+18h] [ebp-14h]
  int nXPosb; // [esp+18h] [ebp-14h]
  int v10; // [esp+1Ch] [ebp-10h]
  int v11; // [esp+20h] [ebp-Ch]
  unsigned __int8 *pMap; // [esp+24h] [ebp-8h]
  BYTE *v13; // [esp+28h] [ebp-4h]

  InitL3Dungeon();
  dminx = 16;
  dminy = 16;
  dmaxx = 96;
  dmaxy = 96;
  DRLG_InitTrans();
  pMap = LoadFileInMem(sFileName, 0, 1520, "DRLG_L3.CPP");
  v11 = *pMap;
  v10 = pMap[2];
  v13 = pMap + 4;
  for ( nYPos = 0; v10 > nYPos; ++nYPos )
  {
    for ( nXPos = 0; v11 > nXPos; ++nXPos )
    {
      if ( *v13 )
        dungeon[nXPos][nYPos] = *v13;
      else
        dungeon[nXPos][nYPos] = 7;
      v13 += 2;
    }
  }
  for ( nYPosa = 0; nYPosa < 40; ++nYPosa )
  {
    for ( nXPosa = 0; nXPosa < 40; ++nXPosa )
    {
      if ( !dungeon[nXPosa][nYPosa] )
        dungeon[nXPosa][nYPosa] = 8;
    }
  }
  abyssx = 112;
  DRLG_L3Pass3();
  DRLG_Init_Globals();
  ViewX = 31;
  ViewY = 83;
  SetMapMonsters((char *)pMap, 0, 0);
  SetMapObjects((char *)pMap, 0, 0);
  for ( nYPosb = 0; nYPosb < 112; ++nYPosb )
  {
    for ( nXPosb = 0; nXPosb < 112; ++nXPosb )
    {
      if ( dPiece[nXPosb][nYPosb] < 56 || dPiece[nXPosb][nYPosb] > 147 )
      {
        if ( dPiece[nXPosb][nYPosb] < 154 || dPiece[nXPosb][nYPosb] > 161 )
        {
          if ( dPiece[nXPosb][nYPosb] == 150 )
          {
            DoLighting(nXPosb, nYPosb, 7, -1);
          }
          else if ( dPiece[nXPosb][nYPosb] == 152 )
          {
            DoLighting(nXPosb, nYPosb, 7, -1);
          }
        }
        else
        {
          DoLighting(nXPosb, nYPosb, 7, -1);
        }
      }
      else
      {
        DoLighting(nXPosb, nYPosb, 7, -1);
      }
    }
  }
  mem_free_dbg(pMap, 1563, "DRLG_L3.CPP");
}

