//----- (0041BBF0) --------------------------------------------------------
size_t EventPlrMsg(char *pszFmt, ...)
{
  _plrmsg *v1; // ST18_4
  size_t result; // eax
  va_list va; // [esp+20h] [ebp+Ch]

  va_start(va, pszFmt);
  assert(pszFmt, "plrmsg.cpp", 45);
  v1 = &plr_msgs[plr_msg_slot++];
  plr_msg_slot &= 7u;
  v1->player = 4;
  v1->time = GetTickCount();
  vsprintf(v1->str, pszFmt, va);
  result = strlen(v1->str);
  assert(result < 0x77, "plrmsg.cpp", 56);
  return result;
}

//----- (0041BCAF) --------------------------------------------------------
void __fastcall SendPlrMsg(int pnum, const char *pszStr)
{
  _plrmsg *v4; // [esp+14h] [ebp-4h]

  assert((unsigned int)pnum < 4, "plrmsg.cpp", 63);
  assert(pszStr, "plrmsg.cpp", 64);
  v4 = &plr_msgs[plr_msg_slot++];
  plr_msg_slot &= 7u;
  v4->player = pnum;
  v4->time = GetTickCount();
  assert(strlen(plr[pnum]._pName) < 0x20, "plrmsg.cpp", 72);
  assert(strlen(pszStr) < 0x50, "plrmsg.cpp", 73);
  sprintf(v4->str, "%s: %s", plr[pnum]._pName, pszStr);
}

//----- (0041BDF0) --------------------------------------------------------
void __cdecl ClearPlrMsg()
{
  signed int v0; // ST0C_4
  signed int v1; // [esp+10h] [ebp-Ch]
  _plrmsg *v2; // [esp+14h] [ebp-8h]
  DWORD v3; // [esp+18h] [ebp-4h]

  v2 = plr_msgs;
  v3 = GetTickCount();
  v1 = 8;
  while ( 1 )
  {
    v0 = v1--;
    if ( !v0 )
      break;
    if ( (signed int)(v3 - v2->time) > 6000 )
      v2->str[0] = 0;
    ++v2;
  }
}

//----- (0041BE55) --------------------------------------------------------
void __cdecl InitPlrMsg()
{
  memset(plr_msgs, 0, 0x3E0u);
  plr_msg_slot = 0;
}

//----- (0041BE80) --------------------------------------------------------
void __cdecl DrawPlrMsg()
{
  signed int v0; // ST18_4
  int v1; // eax
  int x; // [esp+10h] [ebp-14h]
  signed int v3; // [esp+14h] [ebp-10h]
  int no; // [esp+18h] [ebp-Ch]
  _plrmsg *v5; // [esp+1Ch] [ebp-8h]
  int y; // [esp+20h] [ebp-4h]

  no = 74;
  x = 180;
  y = 620;
  if ( chrflag || questlog )
  {
    if ( invflag || sbookflag )
      return;
    no = 394;
    y = 300;
  }
  else if ( invflag || sbookflag )
  {
    y = 300;
  }
  v5 = plr_msgs;
  v3 = 8;
  while ( 1 )
  {
    v0 = v3--;
    if ( !v0 )
      break;
    if ( v5->str[0] )
    {
      v1 = (int)v5;
      LOBYTE(v1) = byte_4B4030[(unsigned __int8)v5->player];
      PrintPlrMsg(no, x, y, v5->str, v1);
    }
    ++v5;
    x += 41;
  }
}

//----- (0041BF81) --------------------------------------------------------
void __fastcall PrintPlrMsg(int no, int x, int y, char *str, int just)
{
  char v5; // ST1C_1
  int v6; // [esp+Ch] [ebp-24h]
  int v7; // [esp+10h] [ebp-20h]
  char v8; // [esp+14h] [ebp-1Ch]
  char *v9; // [esp+1Ch] [ebp-14h]
  int No; // [esp+20h] [ebp-10h]
  unsigned int v11; // [esp+24h] [ebp-Ch]
  char *v12; // [esp+28h] [ebp-8h]
  int v13; // [esp+2Ch] [ebp-4h]

  v6 = x;
  v7 = no;
  for (v13 = 0; v13 != 3; v13++)
  {
    if ( !*str )
      break;
    No = v7 + screen_y_times_768[v6];
    v11 = 0;
    v12 = str;
    v9 = str;
    while ( *v12 )
    {
      v5 = fontframe[*v12++];
      v11 += fontkern[v5] + 1;
      if ( v5 )
      {
        if ( v11 >= y )
          goto LABEL_10;
      }
      else
      {
        v9 = v12;
      }
    }
    v9 = v12;
LABEL_10:
    while ( v9 > str )
    {
      v8 = fontframe[*str++];
      if ( v8 )
        CPrintString(No, v8, just);
      No += fontkern[v8] + 1;
    }
    v6 += 10;
  }
}

