//----- (0041B390) --------------------------------------------------------
int __fastcall nthread_send_and_recv_turn(int cur_turn, int turn_delta)
{
  char *v2; // eax
  int result; // eax
  unsigned int v4; // ST1C_4
  char *v5; // eax
  unsigned int v7; // [esp+10h] [ebp-10h]
  unsigned int v8; // [esp+18h] [ebp-8h]
  unsigned int v9; // [esp+1Ch] [ebp-4h]

  v7 = cur_turn;
  if ( SNetGetTurnsInTransit(&v9) )
  {
    assert(gdwTurnsInTransit, "nthread.cpp", 138);
    while ( 1 )
    {
      v4 = v9++;
      if ( gdwTurnsInTransit <= v4 )
        return v7;
      v8 = dword_5FE158 & 0xC0000000 | v7 & 0x3FFFFFFF;
      dword_5FE158 &= 0xBFFFFFFF;
      if ( !SNetSendTurn(&v8, 4) )
        break;
      v7 += turn_delta;
      if ( v7 >= 0x3FFFFFFF )
        v7 = (unsigned __int16)v7;
    }
    if ( GetLastError() != 553975813 )
    {
      v5 = GetLastErr();
      TermMsg("SNetSendTurn:\n%s", v5);
    }
    gbGameDestroyed = 1;
    result = 0;
  }
  else
  {
    if ( GetLastError() != 553975813 )
    {
      v2 = GetLastErr();
      TermMsg("SNetGetTurnsInTransit:\n%s", v2);
    }
    gbGameDestroyed = 1;
    result = 0;
  }
  return result;
}

//----- (0041B4AE) --------------------------------------------------------
int __fastcall nthread_recv_turns(int *pfSendAsync, int *a2)
{
  char *v3; // eax
  int error_code; // [esp+14h] [ebp-4h]

  assert(pfSendAsync, "nthread.cpp", 206);
  assert(a2, "nthread.cpp", 207);
  *pfSendAsync = 0;
  *a2 = 0;
  if ( byte_5FE0D0 )
    nthread_41B69A();
  assert(sgbPacketCountDown, "nthread.cpp", 216);
  if ( --sgbPacketCountDown )
  {
    dword_4C104C += 50;
    return 1;
  }
  sgbPacketCountDown = byte_5FE0E8;
  assert(sgbSyncCountDown, "nthread.cpp", 228);
  if ( --sgbSyncCountDown )
    goto LABEL_23;
  if ( SNetReceiveTurns(0, 4, dword_5FE120, dword_5FE0F0, dword_5FE0D8) )
  {
    if ( !byte_5FE144 )
    {
      byte_5FE144 = 1;
      dword_4C104C = GetTickCount() + 50;
    }
    sgbSyncCountDown = 8;
    *a2 = 1;
LABEL_23:
    *pfSendAsync = 1;
    dword_4C104C += 50;
    return 1;
  }
  error_code = GetLastError();
  if ( error_code == 553975813 )
  {
    gbGameDestroyed = 1;
  }
  else if ( error_code != 553975814 )
  {
    v3 = GetErr(error_code);
    TermMsg("SNetReceiveTurns:\n%s", v3);
  }
  sgbSyncCountDown = 1;
  sgbPacketCountDown = 1;
  memcpy(&dword_5FE130, dword_5FE0D8, 0x10u);
  byte_5FE144 = 0;
  return 0;
}

//----- (0041B69A) --------------------------------------------------------
void __cdecl nthread_41B69A()
{
  int v0; // eax
  char *v1[4]; // [esp+Ch] [ebp-58h]
  HDC hdc; // [esp+1Ch] [ebp-48h]
  HRESULT v3; // [esp+20h] [ebp-44h]
  char String; // [esp+24h] [ebp-40h]

  if ( gbActive )
  {
    assert((unsigned int)myplr < 4, "nthread.cpp", 176);
    v1[0] = "<%d> %d %d %d";
    v1[1] = "%d <%d> %d %d";
    v1[2] = "%d %d <%d> %d";
    v1[3] = "%d %d %d <%d>";
    sprintf(&String, v1[myplr], dword_5FE130, dword_5FE134, dword_5FE138, dword_5FE13C);
    v3 = lpDDSPrimary->lpVtbl->GetDC(lpDDSPrimary, &hdc);
    if ( !v3 )
    {
      v0 = strlen(&String);
      TextOutA(hdc, 30, 400, &String, v0);
      lpDDSPrimary->lpVtbl->ReleaseDC(lpDDSPrimary, hdc);
    }
  }
}

//----- (0041B786) --------------------------------------------------------
void __fastcall nthread_start(bool set_turn_upper_bit)
{
  char *v1; // eax
  unsigned int v2; // eax
  char *v3; // eax
  char ThreadId; // [esp+Ch] [ebp-28h]
  int v5; // [esp+10h] [ebp-24h]
  unsigned int v6; // [esp+18h] [ebp-1Ch]
  unsigned int v7; // [esp+20h] [ebp-14h]
  int v8; // [esp+24h] [ebp-10h]
  unsigned int v9; // [esp+2Ch] [ebp-8h]
  int v10; // [esp+30h] [ebp-4h]

  dword_4C104C = GetTickCount();
  sgbPacketCountDown = 1;
  sgbSyncCountDown = 1;
  byte_5FE144 = 1;
  v5 = 36;
  if ( !SNetGetProviderCaps(&v5) )
  {
    v1 = GetLastErr();
    TermMsg("SNetGetProviderCaps:\n%s", v1);
  }
  if ( v10 )
    gdwTurnsInTransit = v10;
  else
    gdwTurnsInTransit = 1;
  if ( v9 <= 0x14 && v9 )
    byte_5FE0E8 = 0x14 / v9;
  else
    byte_5FE0E8 = 1;
  v2 = v6;
  if ( v6 >= 0x200 )
    v2 = 512;
  gdwLargestMsgSize = v2;
  assert(v2 >= 0x80, "nthread.cpp", 349);
  gdwNormalMsgSize = v8 * (unsigned int)byte_5FE0E8 / 0x14;
  assert(v7, "nthread.cpp", 357);
  if ( v7 > 4 )
    v7 = 4;
  gdwNormalMsgSize /= v7;
  gdwNormalMsgSize *= 3;
  gdwNormalMsgSize = (unsigned int)gdwNormalMsgSize >> 2;
  while ( (unsigned int)gdwNormalMsgSize < 0x80 )
  {
    gdwNormalMsgSize *= 2;
    byte_5FE0E8 *= 2;
  }
  if ( gdwLargestMsgSize < (unsigned int)gdwNormalMsgSize )
    gdwNormalMsgSize = gdwLargestMsgSize;
  if ( (signed int)gbMaxPlayers > 1 )
  {
    sgbThreadIsRunning = 0;
    InitializeCriticalSection(&stru_5FE100);
    EnterCriticalSection(&stru_5FE100);
    byte_5FE118 = 1;
    assert(sghThread == (HANDLE)-1, "nthread.cpp", 386);
    sghThread = (HANDLE)_beginthreadex(0, 0x2000u, (int)nthread_handler, 0, 0, (LPDWORD)&ThreadId);
    if ( sghThread == (HANDLE)-1 )
    {
      v3 = GetLastErr();
      TermMsg("nthread2:\n%s", v3);
    }
  }
}

//----- (0041B9B5) --------------------------------------------------------
unsigned int __stdcall nthread_handler(void *a1)
{
  int v2; // ebx
  char pfSendAsync; // [esp+Ch] [ebp-Ch]
  int a2; // [esp+10h] [ebp-8h]
  int dwMilliseconds; // [esp+14h] [ebp-4h]

  while ( byte_5FE118 )
  {
    EnterCriticalSection(&stru_5FE100);
    if ( !byte_5FE118 )
    {
      LeaveCriticalSection(&stru_5FE100);
      return 0;
    }
    nthread_send_and_recv_turn(0, 0);
    if ( nthread_recv_turns((int *)&pfSendAsync, &a2) )
    {
      if ( a2 )
        multi_41C8BA(0);
      v2 = dword_4C104C;
      dwMilliseconds = v2 - GetTickCount();
    }
    else
    {
      dwMilliseconds = 50;
    }
    LeaveCriticalSection(&stru_5FE100);
    if ( dwMilliseconds > 0 )
      Sleep(dwMilliseconds);
  }
  return 0;
}

//----- (0041BA75) --------------------------------------------------------
void __cdecl nthread_cleanup()
{
  char *v0; // eax

  byte_5FE118 = 0;
  gdwTurnsInTransit = 0;
  gdwNormalMsgSize = 0;
  gdwLargestMsgSize = 0;
  if ( sghThread != (HANDLE)-1 )
  {
    if ( !sgbThreadIsRunning )
      LeaveCriticalSection(&stru_5FE100);
    if ( WaitForSingleObject(sghThread, 0xFFFFFFFF) == -1 )
    {
      v0 = GetLastErr();
      TermMsg("nthread3:\n(%s)", v0);
    }
    CloseHandle(sghThread);
    sghThread = (HANDLE)-1;
    DeleteCriticalSection(&stru_5FE100);
  }
}

//----- (0041BB1C) --------------------------------------------------------
void __fastcall nthread_ignore_mutex(bool bStart)
{
  if ( sghThread != (HANDLE)-1 )
  {
    assert(sgbThreadIsRunning != bStart, "nthread.cpp", 440);
    if ( bStart )
      LeaveCriticalSection(&stru_5FE100);
    else
      EnterCriticalSection(&stru_5FE100);
    sgbThreadIsRunning = bStart;
  }
}

//----- (0041BB95) --------------------------------------------------------
BOOL __cdecl nthread_has_500ms_passed()
{
  DWORD v1; // [esp+Ch] [ebp-8h]
  int v2; // [esp+10h] [ebp-4h]

  v1 = GetTickCount();
  v2 = v1 - dword_4C104C;
  if ( (signed int)(v1 - dword_4C104C) > 500 )
  {
    dword_4C104C = v1;
    v2 = 0;
  }
  return v2 >= 0;
}

