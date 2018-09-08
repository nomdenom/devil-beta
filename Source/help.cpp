#include "all.h"

//----- (0044E5C0) --------------------------------------------------------
void __cdecl InitHelp()
{
  helpflag = 0;
  Xhelpflag_2 = 0;
  help_62748C_num = 0;
  help_627900_num = 0;
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
  v7 = gszHelpText[0];
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
void __fastcall PrintHelpModeStr(int a1)
{
  signed int v2; // [esp+10h] [ebp-10h]
  signed int i; // [esp+14h] [ebp-Ch]
  int No; // [esp+18h] [ebp-8h]
  char v5; // [esp+1Ch] [ebp-4h]

  No = Xhelpstruct[a1].x + screen_y_times_768[Xhelpstruct[a1].y + 160] + 64;
  v2 = strlen(Xhelpstruct[a1].text);
  for ( i = 0; i < v2; ++i )
  {
    v5 = fontframe[Xhelpstruct[a1].text[i] & 0x7F];
    if ( v5 )
      CPrintString(No, v5, Xhelpstruct[a1].just);
    No += fontkern[v5] + 1;
  }
}

//----- (0044EA77) --------------------------------------------------------
void __fastcall help_44EA77_add(int x, int y, char *text, int just)
{
  if ( help_62748C_num < 8 )
  {
    Xhelpstruct[help_62748C_num].x = x;
    Xhelpstruct[help_62748C_num].y = y;
    strcpy(Xhelpstruct[help_62748C_num].text, text);
    Xhelpstruct[help_62748C_num++].just = just;
  }
}

//----- (0044EB1A) --------------------------------------------------------
void __fastcall help_44EB1A_add(int a1, int a2, int a3, int a4, char a5)
{
  if ( help_627900_num < 4 )
  {
    Xhelpstruct2[help_627900_num].x1 = a1;
    Xhelpstruct2[help_627900_num].y1 = a2;
    Xhelpstruct2[help_627900_num].x2 = a3;
    Xhelpstruct2[help_627900_num].y2 = a4;
    Xhelpstruct2[help_627900_num++].field_10 = a5;
  }
}

//----- (0044EBA7) --------------------------------------------------------
void __cdecl helpmode_draw2()
{
  int a1; // [esp+Ch] [ebp-4h]
  int a1a; // [esp+Ch] [ebp-4h]

  for ( a1 = 0; help_627900_num > a1; ++a1 )
    engine_draw_automap_pixels(
      Xhelpstruct2[a1].x1,
      Xhelpstruct2[a1].y1,
      Xhelpstruct2[a1].x2,
      Xhelpstruct2[a1].y2,
      Xhelpstruct2[a1].field_10);
  for ( a1a = 0; help_62748C_num > a1a; ++a1a )
    PrintHelpModeStr(a1a);
}

//----- (0044EC51) --------------------------------------------------------
void __fastcall help_44EC51(int x, int y)
{
  help_6278F8_x = 32 * (x - ViewX) - 32 * (y - ViewY) + 320;
  help_6278FC_y = 16 * (x - ViewX) + 16 * (y - ViewY) + 126;
}

//----- (0044ECB0) --------------------------------------------------------
void __cdecl new_help_mode()
{
  help_627900_num = 0;
  help_62748C_num = 0;
  help_44EA77_add(8, 20, "Help mode on", 3);
  if ( pcursmonst != -1 )
  {
    if ( currlevel )
    {
      help_44EC51(monster[pcursmonst]._mx, monster[pcursmonst]._my);
      help_44EB1A_add(help_6278F8_x, help_6278FC_y, 318, 35, 225);
      strcpy(tempstr, "Left click to attack with weapon");
      help_44EA77_add(320, 20, tempstr, 2);
      strcpy(tempstr, "Right click to attack with firebolt spell");
      help_44EA77_add(320, 33, tempstr, 2);
    }
    else
    {
      help_44EC51(cursmx, cursmy);
      help_44EB1A_add(help_6278F8_x, help_6278FC_y, help_6278F8_x + 30, help_6278FC_y - 14, 225);
      strcpy(tempstr, "Left click to talk to person");
      help_44EA77_add(help_6278F8_x + 32, help_6278FC_y - 16, tempstr, 2);
    }
  }
  if ( pcursobj != -1 )
  {
    help_44EC51(object[pcursobj]._ox, object[pcursobj]._oy);
    help_44EB1A_add(help_6278F8_x, help_6278FC_y, help_6278F8_x + 30, help_6278FC_y - 14, 241);
    strcpy(tempstr, "Left click to operate");
    help_44EA77_add(help_6278F8_x + 32, help_6278FC_y - 16, tempstr, 0);
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

