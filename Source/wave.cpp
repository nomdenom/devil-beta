//----- (0043AB00) --------------------------------------------------------
BOOL __fastcall ReadWaveFile(int handle, WAVEFORMATEX *wf, int *len)
{
  WORD v6; // [esp+14h] [ebp-28h]
  WORD v7; // [esp+16h] [ebp-26h]
  DWORD v8; // [esp+18h] [ebp-24h]
  DWORD v9; // [esp+1Ch] [ebp-20h]
  WORD v10; // [esp+20h] [ebp-1Ch]
  WORD v11; // [esp+22h] [ebp-1Ah]
  int v12; // [esp+24h] [ebp-18h]
  int v13; // [esp+2Ch] [ebp-10h]
  int v14; // [esp+38h] [ebp-4h]

  if ( !handle )
    assertion_failed(52, "C:\\Diablo\\Direct\\wave.cpp");
  if ( !wf )
    assertion_failed(53, "C:\\Diablo\\Direct\\wave.cpp");
  if ( !len )
    assertion_failed(54, "C:\\Diablo\\Direct\\wave.cpp");
  if ( !SFileReadFile(handle, (int)&v12, 12, (int)&v14, 0) )
    return 0;
  if ( v14 != 12 )
    assertion_failed(60, "C:\\Diablo\\Direct\\wave.cpp");
  if ( v12 != 'FFIR' || v13 != 'EVAW' )
    return 0;
  if ( !WReadFile(handle, ' tmf', len) )
    return 0;
  if ( (unsigned int)*len < 0x10 )
    return 0;
  if ( !SFileReadFile(handle, (int)&v6, 16, (int)&v14, 0) )
    return 0;
  if ( v14 != 16 )
    assertion_failed(77, "C:\\Diablo\\Direct\\wave.cpp");
  if ( SFileSetFilePointer(handle, *len - 16, 0, 1) == -1 )
    return 0;
  wf->wFormatTag = v6;
  wf->nChannels = v7;
  wf->nSamplesPerSec = v8;
  wf->nAvgBytesPerSec = v9;
  wf->nBlockAlign = v10;
  wf->wBitsPerSample = v11;
  wf->cbSize = 0;
  return WReadFile(handle, 'atad', len) != 0;
}

//----- (0043ACDE) --------------------------------------------------------
BOOL __fastcall WReadFile(int hsFile, DWORD tag, void *a3)
{
  int v4; // eax
  int v7; // [esp+14h] [ebp-Ch]
  int v8; // [esp+18h] [ebp-8h]
  int v9; // [esp+1Ch] [ebp-4h]

  while ( 1 )
  {
    if ( !SFileReadFile(hsFile, (int)&v8, 8, (int)&v7, 0) )
      return 0;
    if ( v7 != 8 )
      assertion_failed(28, "C:\\Diablo\\Direct\\wave.cpp");
    if ( v8 == tag )
      break;
    v4 = SFileSetFilePointer(hsFile, v9, 0, 1);
    if ( v4 != v9 )
      return 0;
  }
  *(_DWORD *)a3 = v9;
  *((_DWORD *)a3 + 1) = SFileSetFilePointer(hsFile, 0, 0, 1);
  return *((_DWORD *)a3 + 1) != -1;
}

