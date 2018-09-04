//----- (0044E5C0) --------------------------------------------------------
void __cdecl InitHelp()
{
  helpflag = 0;
  Xhelpflag_2 = 0;
  help_62748C = 0;
  help_627900 = 0;
}

//----- (0044E5F8) --------------------------------------------------------
int __stdcall DrawHelpLine(char *a1, int Just)
{
  int v2; // edx
  int v3; // ecx
  int result; // eax
  int v5; // [esp+14h] [ebp-18h]
  int i; // [esp+18h] [ebp-14h]
  signed int v7; // [esp+1Ch] [ebp-10h]
  int No; // [esp+20h] [ebp-Ch]
  char v9; // [esp+24h] [ebp-8h]

  No = v3 + screen_y_times_768[SStringY[v2] + 204] + 96;
  v5 = strlen(a1);
  v7 = 0;
  for ( i = 0; ; ++i )
  {
    result = v5;
    if ( i >= v5 )
      break;
    v9 = fontframe[a1[i] & 0x7F];
    v7 += fontkern[v9] + 1;
    if ( v9 )
    {
      if ( v7 <= 577 )
        CPrintString(No, v9, Just);
    }
    No += fontkern[v9] + 1;
  }
  return result;
}

//----- (0044E6C6) --------------------------------------------------------
void __cdecl DrawHelp()
{
  signed int j; // [esp+Ch] [ebp-1Ch]
  int i; // [esp+10h] [ebp-18h]
  int v2; // [esp+14h] [ebp-14h]
  signed int v3; // [esp+18h] [ebp-10h]
  signed int v4; // [esp+18h] [ebp-10h]
  int v5; // [esp+1Ch] [ebp-Ch]
  int v6; // [esp+1Ch] [ebp-Ch]
  char *v7; // [esp+24h] [ebp-4h]

  DrawSTextHelp();
  DrawQTextBack();
  PrintSString(0, 2, 1u, "Diablo Help", 3, 0);
  DrawSLine(5);
  v7 = gszHelpText;
  for ( i = 0; i < help_select_line; ++i )
  {
    v5 = 0;
    v3 = 0;
    while ( !*v7 )
      ++v7;
    if ( *v7 == '$' )
      ++v7;
    if ( *v7 != '&' )
    {
      while ( *v7 != ('|') && v3 < '\x02A' )
      {
        while ( !*v7 )
          ++v7;
        tempstr[v5] = *v7;
        v3 += fontkern[fontframe[tempstr[v5++] & 0x7F]] + 1;
        ++v7;
      }
      if ( v3 >= 577 )
      {
        while ( tempstr[--v5] != 32 )
          --v7;
      }
      if ( *v7 == ('|') )
        ++v7;
    }
  }
  for ( j = 7; j < 22; ++j )
  {
    v6 = 0;
    v4 = 0;
    while ( !*v7 )
      ++v7;
    if ( *v7 == '$' )
    {
      ++v7;
      LOBYTE(v2) = 2;
    }
    else
    {
      LOBYTE(v2) = 0;
    }
    if ( *v7 == '&' )
    {
      HelpTop = help_select_line;
    }
    else
    {
      while ( *v7 != ('|') && v4 < 577 )
      {
        while ( !*v7 )
          ++v7;
        tempstr[v6] = *v7;
        v4 += fontkern[fontframe[tempstr[v6++] & 0x7F]] + 1;
        ++v7;
      }
      if ( v4 >= 577 )
      {
        while ( tempstr[--v6] != 32 )
          --v7;
      }
      if ( v6 )
      {
        tempstr[v6] = 0;
        DrawHelpLine(tempstr, v2);
      }
      if ( *v7 == ('|') )
        ++v7;
    }
  }
  PrintSString(0, 23, 1u, "Press ESC to end or the arrow keys to scroll.", 3, 0);
}

//----- (0044E985) --------------------------------------------------------
signed int __fastcall PrintHelpModeStr(int a1)
{
  signed int result; // eax
  signed int v3; // [esp+10h] [ebp-10h]
  signed int i; // [esp+14h] [ebp-Ch]
  int No; // [esp+18h] [ebp-8h]
  char v6; // [esp+1Ch] [ebp-4h]

  No = dword_627498[35 * a1] + screen_y_times_768[dword_62749C[35 * a1] + 160] + 64;
  v3 = strlen((const char *)&dword_627498[35 * a1 + 2]);
  for ( i = 0; ; ++i )
  {
    result = v3;
    if ( i >= v3 )
      break;
    v6 = fontframe[byte_6274A0[140 * a1 + i] & 0x7F];
    if ( v6 )
      CPrintString(No, v6, byte_627520[140 * a1]);
    No += fontkern[v6] + 1;
  }
  return result;
}

//----- (0044EA77) --------------------------------------------------------
int __stdcall help_44EA77(char *a1, char a2)
{
  int v2; // edx
  int v3; // ecx
  int result; // eax

  if ( help_62748C < 8 )
  {
    dword_627498[35 * help_62748C] = v3;
    dword_62749C[35 * help_62748C] = v2;
    result = (int)strcpy((char *)&dword_627498[35 * help_62748C + 2], a1);
    LOBYTE(result) = a2;
    byte_627520[140 * help_62748C++] = a2;
  }
  return result;
}

//----- (0044EB1A) --------------------------------------------------------
char __fastcall help_44EB1A(int a1, int a2, int a3, int a4, char a5)
{
  char result; // al

  if ( help_627900 < 4 )
  {
    dword_627908[5 * help_627900] = a1;
    dword_62790C[5 * help_627900] = a2;
    dword_627910[5 * help_627900] = a3;
    dword_627914[5 * help_627900] = a4;
    result = a5;
    byte_627918[20 * help_627900++] = a5;
  }
  return result;
}

//----- (0044EBA7) --------------------------------------------------------
int helpmode_draw2()
{
  int result; // eax
  int i; // [esp+Ch] [ebp-4h]
  int j; // [esp+Ch] [ebp-4h]

  for ( i = 0; help_627900 > i; ++i )
    engine_draw_automap_pixels(
      dword_627908[5 * i],
      dword_62790C[5 * i],
      dword_627910[5 * i],
      dword_627914[5 * i],
      byte_627918[20 * i]);
  for ( j = 0; ; ++j )
  {
    result = j;
    if ( help_62748C <= j )
      break;
    PrintHelpModeStr(j);
  }
  return result;
}

//----- (0044EC51) --------------------------------------------------------
void __fastcall help_44EC51(int x, int y)
{
  dword_6278F8 = 32 * (x - ViewX) - 32 * (y - ViewY) + 320;
  dword_6278FC = 16 * (x - ViewX) + 16 * (y - ViewY) + 126;
}

//----- (0044ECB0) --------------------------------------------------------
void __cdecl new_help_mode()
{
  help_627900 = 0;
  help_62748C = 0;
  help_44EA77("Help mode on", 3);
  if ( pcursmonst != -1 )
  {
    if ( currlevel )
    {
      help_44EC51(monster[pcursmonst]._mx, monster[pcursmonst]._my);
      help_44EB1A(dword_6278F8, dword_6278FC, 318, 35, 225);
      strcpy(tempstr, "Left click to attack with weapon");
      help_44EA77(tempstr, 2);
      strcpy(tempstr, "Right click to attack with firebolt spell");
    }
    else
    {
      help_44EC51(cursmx, cursmy);
      help_44EB1A(dword_6278F8, dword_6278FC, dword_6278F8 + 30, dword_6278FC - 14, 225);
      strcpy(tempstr, "Left click to talk to person");
    }
    help_44EA77(tempstr, 2);
  }
  if ( pcursobj != -1 )
  {
    help_44EC51(object[pcursobj]._ox, object[pcursobj]._oy);
    help_44EB1A(dword_6278F8, dword_6278FC, dword_6278F8 + 30, dword_6278FC - 14, 241);
    strcpy(tempstr, "Left click to operate");
    help_44EA77(tempstr, 0);
  }
}

//----- (0044EEA8) --------------------------------------------------------
void __cdecl DisplayHelp()
{
  helpflag = 1;
  help_select_line = 0;
  HelpTop = 5000;
}

//----- (0044EED6) --------------------------------------------------------
void __cdecl HelpScrollUp()
{
  if ( help_select_line > 0 )
    --help_select_line;
}

//----- (0044EEF9) --------------------------------------------------------
void __cdecl HelpScrollDown()
{
  if ( HelpTop > help_select_line )
    ++help_select_line;
}

