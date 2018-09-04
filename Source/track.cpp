//----- (004681A4) --------------------------------------------------------
void __cdecl track_process()
{
  signed int v0; // [esp+Ch] [ebp-24h]
  int v1; // [esp+10h] [ebp-20h]
  int v2; // [esp+10h] [ebp-20h]
  DWORD v3; // [esp+1Ch] [ebp-14h]
  int y; // [esp+20h] [ebp-10h]
  int x; // [esp+24h] [ebp-Ch]

  if ( sgbIsWalking )
  {
    v3 = GetTickCount();
    if ( (signed int)(v3 - sgdwLastWalk) >= 300 )
    {
      sgdwLastWalk = v3;
      if ( MouseY >= 352 )
        v0 = 351;
      else
        v0 = MouseY;
      if ( zoomflag )
      {
        v1 = v0 & 0x1F;
        x = ViewX + (MouseX >> 6) + (v0 >> 5) - 10;
        y = ViewY + (v0 >> 5) - (MouseX >> 6);
        if ( (MouseX & 0x3F) / 2 > v1 )
          --y;
        if ( 32 - (MouseX & 0x3F) / 2 <= v1 )
          ++x;
      }
      else
      {
        v2 = v0 & 0x3F;
        x = ViewX + (MouseX >> 7) + (v0 >> 6) - 5;
        y = ViewY + (v0 >> 6) - (MouseX >> 7);
        if ( (MouseX & 0x7F) / 2 > v2 )
          --y;
        if ( 64 - (MouseX & 0x7F) / 2 <= v2 )
          ++x;
      }
      if ( x < 0 )
        x = 0;
      if ( x >= 112 )
        x = 111;
      if ( y < 0 )
        y = 0;
      if ( y >= 112 )
        y = 111;
      if ( plr[myplr]._ptargx != x || plr[myplr]._ptargy != y )
        NetSendCmdLoc(1u, 1u, x, y);
    }
  }
}

//----- (004683C9) --------------------------------------------------------
void __fastcall track_repeat_walk(bool rep)
{
  sgbIsWalking = rep;
  if ( rep )
  {
    sgdwLastWalk = GetTickCount();
    NetSendCmdLoc(1u, 1u, cursmx, cursmy);
  }
}

