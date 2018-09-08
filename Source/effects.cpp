//----- (004674C0) --------------------------------------------------------
void __cdecl sfx_stop()
{
  signed int v0; // ST10_4
  signed int v1; // [esp+10h] [ebp-8h]
  TSFX *v2; // [esp+14h] [ebp-4h]

  if ( sfx_stream )
  {
    SFileDdaEnd(sfx_stream);
    SFileCloseFile(sfx_stream);
    sfx_stream = 0;
  }
  v2 = sgSFX;
  v1 = 225;
  while ( 1 )
  {
    v0 = v1--;
    if ( !v0 )
      break;
    if ( (v2->bFlags & 0x80u) != 0 )
    {
      if ( v2->pSnd )
      {
        snd_stop_snd(v2->pSnd);
        v2->bFlags &= 0x7Fu;
      }
    }
    ++v2;
  }
}

//----- (00467570) --------------------------------------------------------
void __fastcall InitMonsterSND(int monst)
{
  size_t v1; // eax
  char *path; // ST24_4
  TSnd *v4; // [esp+10h] [ebp-118h]
  char v5[260]; // [esp+18h] [ebp-110h]
  int j; // [esp+11Ch] [ebp-Ch]
  int v7; // [esp+120h] [ebp-8h]
  int i; // [esp+124h] [ebp-4h]

  if ( gbSndInited )
  {
    v7 = Monsters[monst].mtype;
    for ( i = 0; i < 4; ++i )
    {
      if ( monster_action_sounds[i] != 115 || monsterdata[v7].snd_special )
      {
        for ( j = 0; j < 2; ++j )
        {
          sprintf(v5, monsterdata[v7].sndfile, monster_action_sounds[i], j + 1);
          v1 = strlen(v5);
          path = (char *)DiabloAllocPtr(v1 + 1, 223, "effects.cpp");
          strcpy(path, v5);
          v4 = sound_file_load(path);
          assert(v4, "effects.cpp", 229);
          Monsters[monst].Snds[i][j] = v4;
        }
      }
    }
  }
}

//----- (004676FA) --------------------------------------------------------
void __cdecl FreeEffects()
{
  int v0; // ST1C_4
  char *ptr; // ST14_4
  TSnd *sound_file; // [esp+Ch] [ebp-18h]
  signed int k; // [esp+14h] [ebp-10h]
  signed int j; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]

  for ( i = 0; i < nummtypes; ++i )
  {
    v0 = Monsters[i].mtype;
    for ( j = 0; j < 4; ++j )
    {
      for ( k = 0; k < 2; ++k )
      {
        sound_file = (TSnd *)Monsters[i].Snds[j][k];
        if ( sound_file )
        {
          Monsters[i].Snds[j][k] = 0;
          ptr = sound_file->sound_path;
          sound_file->sound_path = 0;
          sound_file_cleanup(sound_file);
          mem_free_dbg(ptr, 255, "effects.cpp");
        }
      }
    }
  }
}

//----- (0046780D) --------------------------------------------------------
void __fastcall PlayEffect(int i, int mode)
{
  int plPan; // [esp+14h] [ebp-10h]
  int plVolume; // [esp+18h] [ebp-Ch]
  int v6; // [esp+1Ch] [ebp-8h]
  int v7; // [esp+20h] [ebp-4h]

  v7 = random(164, 2);
  if ( gbSndInited )
  {
    plPan = 0;
    plVolume = 0;
    if ( calc_snd_position(monster[i]._mx, monster[i]._my, &plVolume, &plPan) )
    {
      v6 = monster[i]._mMTidx;
      if ( !Monsters[v6].Snds[mode][v7] )
        TermMsg("Monster sound problem\n:%s playing %i", Monsters[v6].MData->mName, mode);
      snd_play_snd((TSnd *)Monsters[v6].Snds[mode][v7], plVolume, plPan);
    }
  }
}

//----- (00467935) --------------------------------------------------------
int __fastcall calc_snd_position(int x, int y, int *plVolume, int *plPan)
{
  int v5; // ebx
  int v6; // [esp+Ch] [ebp-Ch]
  int v7; // [esp+10h] [ebp-8h]
  int v8; // [esp+14h] [ebp-4h]

  v7 = x - plr[myplr].WorldX;
  v6 = y - plr[myplr].WorldY;
  *plPan = (v7 - v6) << 8;
  if ( abs(*plPan) > 10000 )
    return 0;
  v5 = abs(v6);
  if ( v5 >= abs(v7) )
    v8 = abs(v6);
  else
    v8 = abs(v7);
  *plVolume = v8 << 6;
  if ( *plVolume >= 6400 )
    return 0;
  *plVolume = -*plVolume;
  return 1;
}

//----- (00467A43) --------------------------------------------------------
void __fastcall PlaySFX(int psfx)
{
  unsigned int psfxa; // [esp+Ch] [ebp-4h]

  psfxa = RndSFX(psfx);
  assert(psfxa < 0xE1, "effects.cpp", 367);
  PlaySFX_priv(&sgSFX[psfxa], 0, 0, 0);
}

//----- (00467A9A) --------------------------------------------------------
void __fastcall PlaySFX_priv(TSFX *pSFX, char loc, int x, int y)
{
  int plPan; // [esp+14h] [ebp-8h]
  int plVolume; // [esp+18h] [ebp-4h]

  if ( gbSndInited )
  {
    if ( !gbBufferMsgs )
    {
      plPan = 0;
      plVolume = 0;
      if ( !loc || calc_snd_position(x, y, &plVolume, &plPan) )
      {
        if ( pSFX->bFlags & 2 )
        {
          stream_play(pSFX, plVolume, plPan);
        }
        else
        {
          if ( !pSFX->pSnd )
          {
            pSFX->pSnd = sound_file_load(pSFX->pszName);
            if ( !(pSFX->bFlags & 1) )
              pSFX->bFlags |= 4u;
          }
          snd_play_snd(pSFX->pSnd, plVolume, plPan);
        }
      }
    }
  }
}

//----- (00467B88) --------------------------------------------------------
void __fastcall stream_play(TSFX *pSFX, int lVolume, int lPan)
{
  int v3; // ST20_4
  int lVolumeb; // [esp+Ch] [ebp-Ch]

  assert(pSFX, "effects.cpp", 115);
  assert((pSFX->bFlags & 2), "effects.cpp", 116);
  sfx_stop();
  lVolumeb = sound_get_or_set_sound_volume(1) + lVolume;
  if ( lVolumeb >= -1600 )
  {
    if ( lVolumeb > 0 )
      lVolumeb = 0;
  }
  else
  {
    lVolumeb = -1600;
  }
  SFileEnableDirectAccess(0);
  v3 = SFileOpenFile(pSFX->pszName, &sfx_stream);
  SFileEnableDirectAccess(1);
  if ( v3 )
  {
    if ( SFileDdaBegin(sfx_stream, 0x40000, 0) )
    {
      SFileDdaSetVolume(sfx_stream, lVolumeb, lPan);
    }
    else
    {
      sfx_stop();
      effects_467CB1(pSFX, lVolumeb, lPan);
    }
  }
  else
  {
    sfx_stream = 0;
    effects_467CB1(pSFX, lVolumeb, lPan);
  }
}

//----- (00467CB1) --------------------------------------------------------
void __fastcall effects_467CB1(TSFX *pSFX, int lVolume, int lPan)
{
  pSFX->pSnd = sound_file_load(pSFX->pszName);
  pSFX->bFlags |= 0x84u;
  snd_play_snd(pSFX->pSnd, lVolume, lPan);
}

//----- (00467CFE) --------------------------------------------------------
int __fastcall RndSFX(int psfx)
{
  int v1; // eax

  switch ( psfx )
  {
    case 48:
      v1 = random(165, 2);
      break;
    case 13:
      v1 = random(165, 2);
      break;
    case 36:
      v1 = random(165, 2);
      break;
    case 3:
      v1 = random(165, 2);
      break;
    case 52:
      v1 = random(165, 4);
      break;
    case 197:
      v1 = random(165, 3);
      break;
    default:
      return psfx;
  }
  return psfx + v1;
}

//----- (00467DB3) --------------------------------------------------------
void __fastcall PlaySfxLoc(int psfx, int x, int y)
{
  unsigned int psfxa; // [esp+10h] [ebp-4h]

  psfxa = RndSFX(psfx);
  assert(psfxa < 0xE1, "effects.cpp", 377);
  PlaySFX_priv(&sgSFX[psfxa], 1, x, y);
}

//----- (00467E16) --------------------------------------------------------
void __cdecl effects_467E16()
{
  sfx_stop();
  effects_467E30();
}

//----- (00467E30) --------------------------------------------------------
void __cdecl effects_467E30()
{
  signed int v0; // ST0C_4
  signed int v1; // [esp+10h] [ebp-8h]
  TSFX *v2; // [esp+14h] [ebp-4h]

  v2 = sgSFX;
  v1 = 225;
  while ( 1 )
  {
    v0 = v1--;
    if ( !v0 )
      break;
    if ( v2->pSnd )
      snd_stop_snd(v2->pSnd);
    ++v2;
  }
  effects_467E94();
}

//----- (00467E94) --------------------------------------------------------
void __cdecl effects_467E94()
{
  signed int v0; // ST0C_4
  signed int v1; // [esp+10h] [ebp-8h]
  TSFX *v2; // [esp+14h] [ebp-4h]

  if ( gbSndInited )
  {
    v2 = sgSFX;
    v1 = 225;
    while ( 1 )
    {
      v0 = v1--;
      if ( !v0 )
        break;
      if ( v2->bFlags & 4 && v2->pSnd && !snd_playing(v2->pSnd) )
      {
        sound_file_cleanup(v2->pSnd);
        v2->pSnd = 0;
        v2->bFlags &= 0xFBu;
        v2->bFlags &= 0x7Fu;
      }
      ++v2;
    }
  }
}

//----- (00467F5C) --------------------------------------------------------
void __cdecl sound_update()
{
  if ( gbSndInited )
  {
    snd_update();
    effects_467E94();
  }
}

//----- (00467F8A) --------------------------------------------------------
void __cdecl snd_update()
{
  unsigned int v0; // [esp+Ch] [ebp-8h]
  unsigned int v1; // [esp+10h] [ebp-4h]

  if ( sfx_stream && SFileDdaGetPos(sfx_stream, &v1, &v0) && v0 <= v1 )
    sfx_stop();
}

//----- (00467FE5) --------------------------------------------------------
void __cdecl effects_467FE5()
{
  unsigned int i; // [esp+Ch] [ebp-4h]

  if ( gbSndInited )
  {
    for ( i = 0; i < 0xE1; ++i )
    {
      if ( sgSFX[i].bFlags & 1 && !(sgSFX[i].bFlags & 2) && !sgSFX[i].pSnd )
        sgSFX[i].pSnd = sound_file_load(sgSFX[i].pszName);
    }
  }
}

//----- (00468090) --------------------------------------------------------
void __cdecl effects_cleanup_sfx()
{
  unsigned int i; // [esp+Ch] [ebp-4h]

  effects_467E16();
  for ( i = 0; i < 0xE1; ++i )
  {
    if ( sgSFX[i].pSnd )
    {
      sound_file_cleanup(sgSFX[i].pSnd);
      sgSFX[i].pSnd = 0;
      sgSFX[i].bFlags &= 0xFBu;
      sgSFX[i].bFlags &= 0x7Fu;
    }
  }
}

