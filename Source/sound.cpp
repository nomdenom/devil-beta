#include "all.h"

//----- (00413B70) --------------------------------------------------------
void __fastcall snd_stop_snd(TSnd *pSnd)
{
  assert(pSnd, "SOUND.CPP", 128);
  if ( pSnd->DSB )
    pSnd->DSB->lpVtbl->Stop(pSnd->DSB);
}

//----- (00413BC8) --------------------------------------------------------
BOOL __fastcall snd_playing(TSnd *pSnd)
{
  int v2; // [esp+10h] [ebp-8h]
  int error_code; // [esp+14h] [ebp-4h]

  assert(pSnd, "SOUND.CPP", 137);
  if ( !pSnd->DSB )
    return 0;
  error_code = pSnd->DSB->lpVtbl->GetStatus(pSnd->DSB, (LPDWORD)&v2);
  if ( error_code )
    DSErrDlg(error_code, 143, "SOUND.CPP");
  return v2 == 1;
}

//----- (00413C60) --------------------------------------------------------
void __fastcall snd_play_snd(TSnd *pSnd, int lVolume, int lPan)
{
  LONG v4; // [esp+Ch] [ebp-Ch]
  int error_code; // [esp+14h] [ebp-4h]
  int error_codea; // [esp+14h] [ebp-4h]
  int error_codeb; // [esp+14h] [ebp-4h]

  assert(pSnd, "SOUND.CPP", 154);
  if ( gbSoundOn && pSnd->DSB && !snd_playing(pSnd) )
  {
    v4 = value + lVolume;
    if ( v4 >= -1600 )
    {
      if ( v4 > 0 )
        v4 = 0;
    }
    else
    {
      v4 = -1600;
    }
    if ( v4 )
    {
      error_code = pSnd->DSB->lpVtbl->SetVolume(pSnd->DSB, v4);
      if ( error_code )
        DSErrDlg(error_code, 168, "SOUND.CPP");
    }
    if ( lPan )
    {
      error_codea = pSnd->DSB->lpVtbl->SetPan(pSnd->DSB, lPan);
      if ( error_codea )
        DSErrDlg(error_codea, 173, "SOUND.CPP");
    }
    error_codeb = pSnd->DSB->lpVtbl->Play(pSnd->DSB, 0, 0, 0);
    if ( error_codeb == -2005401450 )
    {
      sound_file_reload(pSnd, 0);
      error_codeb = pSnd->DSB->lpVtbl->Play(pSnd->DSB, 0, 0, 0);
    }
    if ( error_codeb )
      DSErrDlg(error_codeb, 180, "SOUND.CPP");
  }
}

//----- (00413DFC) --------------------------------------------------------
BOOL __fastcall sound_file_reload(TSnd *sound_file, IDirectSoundBuffer *DSB)
{
  BOOL result; // eax
  void *v5; // [esp+14h] [ebp-1Ch]
  IDirectSoundBuffer *v6; // [esp+18h] [ebp-18h]
  DWORD v7; // [esp+1Ch] [ebp-14h]
  int error_code; // [esp+20h] [ebp-10h]
  void *v9; // [esp+24h] [ebp-Ch]
  DWORD v10; // [esp+28h] [ebp-8h]
  int v11; // [esp+2Ch] [ebp-4h]

  assert(sound_file, "SOUND.CPP", 84);
  if ( DSB || (result = sound_file->DSB->lpVtbl->Restore(sound_file->DSB)) == 0 )
  {
    if ( DSB )
    {
      v6 = 0;
    }
    else
    {
      if ( !SFileOpenFile(sound_file->sound_path, &DSB) )
        TermMsg("Unable to load sound %s", sound_file->sound_path);
      v6 = DSB;
    }
    error_code = sound_file->DSB->lpVtbl->Lock(sound_file->DSB, 0, sound_file->len, &v9, &v10, &v5, &v7, 0);
    if ( error_code )
      DSErrDlg(error_code, 105, "SOUND.CPP");
    if ( SFileSetFilePointer(DSB, sound_file->offset, 0, 0) == -1 )
      TermMsg("Unable to seek in sound file %s", sound_file->sound_path);
    if ( !SFileReadFile((int)DSB, (int)v9, v10, (int)&v11, 0) )
      TermMsg("Unable to read sound file %s", sound_file->sound_path);
    assert(v10 == v11, "SOUND.CPP", 114);
    result = sound_file->DSB->lpVtbl->Unlock(sound_file->DSB, v9, v10, v5, v7);
    error_code = result;
    if ( result )
      DSErrDlg(error_code, 118, "SOUND.CPP");
    if ( v6 )
      result = SFileCloseFile(v6);
  }
  return result;
}

//----- (00413FD7) --------------------------------------------------------
TSnd *__fastcall sound_file_load(char *path)
{
  char *v2; // [esp+Ch] [ebp-Ch]
  TSnd *sound_file; // [esp+10h] [ebp-8h]
  IDirectSoundBuffer *DSB; // [esp+14h] [ebp-4h]

  v2 = path;
  if ( !sglpDS )
    return 0;
  sound_file = (TSnd *)DiabloAllocPtr(36, 207, "SOUND.CPP");
  memset(sound_file, 0, 0x24u);
  sound_file->sound_path = v2;
  if ( !SFileOpenFile(v2, &DSB) )
    TermMsg("Unable to load sound %s", sound_file->sound_path);
  if ( !ReadWaveFile((int)DSB, &sound_file->fmt, &sound_file->len) )
    TermMsg("Invalid sound format on file %s", sound_file->sound_path);
  sound_CreateSoundBuffer(sound_file);
  sound_file_reload(sound_file, DSB);
  SFileCloseFile(DSB);
  return sound_file;
}

//----- (004140A7) --------------------------------------------------------
void __fastcall sound_CreateSoundBuffer(TSnd *sound_file)
{
  int error_code; // [esp+10h] [ebp-18h]
  DSBUFFERDESC v3; // [esp+14h] [ebp-14h]

  assert(sglpDS, "SOUND.CPP", 187);
  memset(&v3, 0, 0x14u);
  v3.dwSize = 20;
  v3.dwFlags = 194;
  v3.dwBufferBytes = sound_file->len;
  v3.lpwfxFormat = &sound_file->fmt;
  error_code = sglpDS->lpVtbl->CreateSoundBuffer(sglpDS, &v3, &sound_file->DSB, 0);
  if ( error_code )
    DSErrDlg(error_code, 197, "SOUND.CPP");
}

//----- (0041414C) --------------------------------------------------------
void __fastcall sound_file_cleanup(TSnd *sound_file)
{
  TSnd *ptr; // [esp+Ch] [ebp-4h]

  ptr = sound_file;
  if ( sound_file )
  {
    if ( sound_file->DSB )
    {
      sound_file->DSB->lpVtbl->Stop(sound_file->DSB);
      ptr->DSB->lpVtbl->Release(ptr->DSB);
      ptr->DSB = 0;
    }
    mem_free_dbg(ptr, 242, "SOUND.CPP");
  }
}

//----- (004141B9) --------------------------------------------------------
void __fastcall snd_init(HWND hWnd)
{
  int v1; // eax
  int v3; // [esp+14h] [ebp-4h]

  sound_load_volume("Sound Volume", &value);
  sound_load_volume("Music Volume", &sglMusicVolume);
  assert(!sglpDS, "SOUND.CPP", 303);
  if ( DirectSoundCreate(0, &sglpDS, 0) )
    sglpDS = 0;
  if ( sglpDS && !sglpDS->lpVtbl->SetCooperativeLevel(sglpDS, hWnd, 3) )
    sound_create_primary_buffer(0);
  v3 = SVidInitialize(sglpDS);
  assert(!(sglpDS && !v3), "SOUND.CPP", 311);
  v1 = SFileDdaInitialize(sglpDS);
  assert(!(sglpDS && !v1), "SOUND.CPP", 314);
  gbSndInited = sglpDS != 0;
}

//----- (004142F7) --------------------------------------------------------
void __fastcall sound_load_volume(char *value_name, int *value)
{
  int v3; // [esp+14h] [ebp-4h]

  v3 = *value;
  if ( !SRegLoadValue("Diablo", value_name, 0, &v3) )
    v3 = 0;
  *value = v3;
  if ( *value >= -1600 )
  {
    if ( *value > 0 )
      *value = 0;
  }
  else
  {
    *value = -1600;
  }
  *value -= *value % 100;
}

//----- (0041438D) --------------------------------------------------------
void __fastcall sound_create_primary_buffer(int music_track)
{
  DSBUFFERDESC v2; // [esp+10h] [ebp-94h]
  int error_code; // [esp+24h] [ebp-80h]
  DSCAPS v4; // [esp+28h] [ebp-7Ch]
  int a3; // [esp+88h] [ebp-1Ch]
  WAVEFORMATEX wf; // [esp+90h] [ebp-14h]

  assert(sglpDS, "SOUND.CPP", 251);
  if ( !music_track )
  {
    memset(&v2, 0, 0x14u);
    v2.dwSize = 20;
    v2.dwFlags = 1;
    error_code = sglpDS->lpVtbl->CreateSoundBuffer(sglpDS, &v2, &sglpDSB, 0);
    if ( error_code )
      DSErrDlg(error_code, 264, "SOUND.CPP");
  }
  if ( sglpDSB )
  {
    v4.dwSize = 96;
    error_code = sglpDS->lpVtbl->GetCaps(sglpDS, &v4);
    if ( error_code )
      DSErrDlg(error_code, 272, "SOUND.CPP");
    if ( !music_track || !ReadWaveFile(music_track, &wf, &a3) )
    {
      memset(&wf, 0, 0x12u);
      wf.wFormatTag = 1;
      wf.nSamplesPerSec = 22050;
      wf.wBitsPerSample = 16;
      wf.nChannels = 1;
      wf.cbSize = 0;
    }
    wf.nBlockAlign = wf.wBitsPerSample * wf.nChannels / 8;
    wf.nAvgBytesPerSec = wf.nSamplesPerSec * wf.nBlockAlign;
    error_code = sglpDSB->lpVtbl->SetFormat(sglpDSB, &wf);
    if ( error_code && error_code != -2005401500 )
    {
      if ( error_code )
        DSErrDlg(error_code, 294, "SOUND.CPP");
    }
  }
}

//----- (00414561) --------------------------------------------------------
void __cdecl sound_414561()
{
  signed int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 4; ++i )
  {
    sound_file_cleanup(sound_file[i]);
    sound_file[i] = 0;
  }
}

//----- (004145AF) --------------------------------------------------------
void __cdecl sound_cleanup()
{
  sound_414561();
  if ( sglpDS )
  {
    sglpDS->lpVtbl->Release(sglpDS);
    sglpDS = 0;
  }
  if ( gbSndInited )
  {
    gbSndInited = 0;
    sound_store_volume("Sound Volume", value);
    sound_store_volume("Music Volume", sglMusicVolume);
  }
}

//----- (00414621) --------------------------------------------------------
void __fastcall sound_store_volume(char *key, int value)
{
  SRegSaveValue("Diablo", key, 0, value);
}

//----- (0041464E) --------------------------------------------------------
void __stdcall sound_41464E(char *path)
{
  signed int i; // [esp+Ch] [ebp-4h]
  signed int j; // [esp+Ch] [ebp-4h]

  if ( sglpDS && gbSoundOn )
  {
    for ( i = 0; i < 4; ++i )
    {
      if ( sound_file[i] && sound_file[i]->sound_path == path )
      {
        snd_play_snd(sound_file[i], 0, 0);
        return;
      }
    }
    for ( j = 0; j < 4; ++j )
    {
      if ( !sound_file[j] )
      {
        sound_file[j] = sound_file_load(path);
        if ( sound_file[j] )
          snd_play_snd(sound_file[j], 0, 0);
        return;
      }
    }
  }
}

//----- (0041475F) --------------------------------------------------------
void __cdecl music_stop()
{
  if ( sgpMusicTrack )
  {
    SFileDdaEnd(sgpMusicTrack);
    SFileCloseFile(sgpMusicTrack);
    sgpMusicTrack = 0;
  }
}

//----- (0041479C) --------------------------------------------------------
void __fastcall music_start(int nTrack)
{
  int v1; // ST1C_4

  assert((unsigned int)nTrack < 6, "SOUND.CPP", 389);
  music_stop();
  if ( sglpDS && gbMusicOn )
  {
    SFileEnableDirectAccess(0);
    v1 = SFileOpenFile(sgszMusicTracks[nTrack], &sgpMusicTrack);
    SFileEnableDirectAccess(1);
    sound_create_primary_buffer(sgpMusicTrack);
    if ( v1 )
    {
      SFileDdaBegin(sgpMusicTrack, 0x40000, 0x40000);
      SFileDdaSetVolume(sgpMusicTrack, sglMusicVolume, 0);
    }
    else
    {
      sgpMusicTrack = 0;
    }
  }
}

//----- (0041486D) --------------------------------------------------------
int __fastcall sound_get_or_set_music_volume(int volume)
{
  if ( volume == 1 )
    return sglMusicVolume;
  assert(volume >= -1600, "SOUND.CPP", 416);
  assert(volume <= 0, "SOUND.CPP", 417);
  sglMusicVolume = volume;
  if ( sgpMusicTrack )
    SFileDdaSetVolume(sgpMusicTrack, sglMusicVolume, 0);
  return sglMusicVolume;
}

//----- (00414903) --------------------------------------------------------
int __fastcall sound_get_or_set_sound_volume(int volume)
{
  if ( volume == 1 )
    return value;
  assert(volume >= -1600, "SOUND.CPP", 430);
  assert(volume <= 0, "SOUND.CPP", 431);
  value = volume;
  return volume;
}

