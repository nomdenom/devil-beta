//----- (0045C280) --------------------------------------------------------
void __fastcall InitDiabloMsg(char e)
{
  signed int i; // [esp+10h] [ebp-4h]

  for ( i = 0; msgcnt > i; ++i )
  {
    if ( msgtable[i] == e )
      return;
  }
  msgtable[msgcnt] = e;
  if ( msgcnt < 80 )
    ++msgcnt;
  msgflag = msgtable[0];
  msgdelay = 50;
}

//----- (0045C30C) --------------------------------------------------------
void __cdecl ClrDiabloMsg()
{
  signed int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 80; ++i )
    msgtable[i] = 0;
  msgflag = 0;
  msgcnt = 0;
}

//----- (0045C355) --------------------------------------------------------
void __cdecl DrawDiabloMsg()
{
  char *v0; // edi
  signed int v1; // edx
  signed int v2; // ecx
  int v3; // edi
  signed int v4; // ecx
  _BYTE *v5; // edi
  signed int v6; // [esp+10h] [ebp-1Ch]
  signed int v7; // [esp+14h] [ebp-18h]
  signed int i; // [esp+18h] [ebp-14h]
  signed int j; // [esp+18h] [ebp-14h]
  signed int k; // [esp+18h] [ebp-14h]
  signed int l; // [esp+18h] [ebp-14h]
  int screen_y; // [esp+1Ch] [ebp-10h]
  int screen_x; // [esp+20h] [ebp-Ch]
  int No; // [esp+24h] [ebp-8h]
  char v15; // [esp+28h] [ebp-4h]

  CelDecodeOnly(192, 318, pSTextSlidCels, 1, 12);
  CelDecodeOnly(564, 318, pSTextSlidCels, 4, 12);
  CelDecodeOnly(192, 366, pSTextSlidCels, 2, 12);
  CelDecodeOnly(564, 366, pSTextSlidCels, 3, 12);
  screen_x = 204;
  for ( i = 0; i < 30; ++i )
  {
    CelDecodeOnly(screen_x, 318, pSTextSlidCels, 5, 12);
    CelDecodeOnly(screen_x, 366, pSTextSlidCels, 7, 12);
    screen_x += 12;
  }
  screen_y = 330;
  for ( j = 0; j < 3; ++j )
  {
    CelDecodeOnly(192, screen_y, pSTextSlidCels, 6, 12);
    CelDecodeOnly(564, screen_y, pSTextSlidCels, 8, 12);
    screen_y += 12;
  }
  v0 = gpBuffer + 278979;
  for (v1 = 27; v1; --v1)
  {
    for (v2 = 189; v2; --v2)
    {
      *v0 = 0;
      v0 += 2;
    }
    v3 = (int)(v0 - 1146);
    for (v4 = 189; v4; --v4)
    {
      v5 = (_BYTE *)(v3 + 1);
      *v5 = 0;
      v3 = (int)(v5 + 1);
    }
    v0 = (char *)(v3 - 1146);
  }
  switch ( msgflag )
  {
    case 1:
      strcpy(tempstr, "No automap available in town");
      break;
    case 2:
      strcpy(tempstr, "No multiplayer functions in demo");
      break;
    case 3:
      strcpy(tempstr, "Direct Sound Creation Failed");
      break;
    case 4:
      strcpy(tempstr, "Temp directory availability error");
      break;
    case 5:
      strcpy(tempstr, "Not enough space to save");
      break;
    case 6:
      strcpy(tempstr, "No Pause in town");
      break;
    case 7:
      strcpy(tempstr, "Copying to a hard disk is recommended");
      break;
    case 8:
      strcpy(tempstr, "Odd sensations...");
      break;
    case 9:
      strcpy(tempstr, "A surge of blood interrupts your thoughts");
      break;
    case 10:
      strcpy(tempstr, "Energy passes through your equipment...");
      break;
    case 11:
      strcpy(tempstr, "Growling is heard throughout the dungeon");
      break;
    case 12:
      strcpy(tempstr, "Your skills increase, but at a price...");
      break;
    case 13:
      strcpy(tempstr, "Did you forget something?");
      break;
    case 14:
      strcpy(tempstr, "You hear a series of creaks and thumps...");
      break;
    case 15:
      strcpy(tempstr, "You are the powerless master of fire!");
      break;
    case 16:
      strcpy(tempstr, "Power comes from your disorientation...");
      break;
    case 17:
      strcpy(tempstr, "You hear a strange cry from the distance");
      break;
    case 18:
      strcpy(tempstr, "You forget who you are!");
      break;
    case 19:
      strcpy(tempstr, "Untold Wealth!");
      break;
    case 20:
      strcpy(tempstr, "Multiplayer sync problem");
      break;
    case 21:
      strcpy(tempstr, "No pause in multiplayer");
      break;
    case 22:
      strcpy(tempstr, "Loading...");
      break;
    case 23:
      strcpy(tempstr, "Saving...");
      break;
    default:
      break;
  }
  No = screen_y_times_768[342] + 192;
  v6 = strlen(tempstr);
  v7 = 0;
  for ( k = 0; v6 > k; ++k )
    v7 += fontkern[fontframe[tempstr[k] & 0x7F]] + 1;
  if ( v7 < 384 )
    No += (384 - v7) >> 1;
  for ( l = 0; v6 > l; ++l )
  {
    v15 = fontframe[tempstr[l] & 0x7F];
    if ( v15 )
      CPrintString(No, v15, 0);
    No += fontkern[v15] + 1;
  }
  if ( msgdelay > 0 )
    --msgdelay;
  if ( !msgdelay )
  {
    --msgcnt;
    msgdelay = 50;
    if ( msgcnt )
      msgflag = msgtable[msgcnt];
    else
      msgflag = 0;
  }
}

