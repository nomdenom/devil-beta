//----- (00493F10) --------------------------------------------------------
void __cdecl InitPortals()
{
  int portal_num; // [esp+Ch] [ebp-4h]

  for ( portal_num = 0; portal_num < 4; ++portal_num )
  {
    if ( delta_portal_inited(portal_num) )
      portal[portal_num].open = 0;
  }
}

//----- (00493F62) --------------------------------------------------------
void __fastcall SetPortalStats(int i, int o, int x, int y, int lvl, int lvltype)
{
  portal[i].open = o;
  portal[i].x = x;
  portal[i].y = y;
  portal[i].level = lvl;
  portal[i].setlvl = 0;
}

//----- (00493FCE) --------------------------------------------------------
void __fastcall AddWarpMissile(int i, int x, int y)
{
  int mi; // ST30_4

  missiledata[10].mlSFX = -1;
  mi = AddMissile(0, 0, x, y, 0, 10, 0, i, 0);
  SetMissDir(mi, 1);
  missiledata[10].mlSFX = 104;
}

//----- (0049402A) --------------------------------------------------------
void __cdecl SyncPortals()
{
  int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 4; ++i )
  {
    if ( portal[i].open )
    {
      if ( currlevel )
      {
        if ( portal[i].level == currlevel )
          AddWarpMissile(i, portal[i].x, portal[i].y);
      }
      else
      {
        AddWarpMissile(i, WarpDropX[i], WarpDropY[i]);
      }
    }
  }
}

//----- (004940DE) --------------------------------------------------------
void __fastcall AddInTownPortal(int i)
{
  AddWarpMissile(i, WarpDropX[i], WarpDropY[i]);
}

//----- (00494111) --------------------------------------------------------
void __fastcall ActivatePortal(int i, int x, int y, int lvl, int lvltype, int sp)
{
  portal[i].open = 1;
  if ( lvl )
  {
    portal[i].x = x;
    portal[i].y = y;
    portal[i].level = lvl;
    portal[i].setlvl = lvltype;
  }
}

//----- (00494187) --------------------------------------------------------
void __fastcall DeactivatePortal(int i)
{
  portal[i].open = 0;
}

//----- (004941AE) --------------------------------------------------------
BOOL __fastcall PortalOnLevel(int i)
{
  BOOL result; // eax

  if ( portal[i].level == currlevel )
    result = 1;
  else
    result = currlevel == 0;
  return result;
}

//----- (00494209) --------------------------------------------------------
void __fastcall RemovePortalMissile(int id)
{
  int i; // [esp+10h] [ebp-8h]
  int mi; // [esp+14h] [ebp-4h]

  for ( i = 0; i < nummissiles; ++i )
  {
    mi = missileactive[i];
    if ( missile[mi]._mitype == 10 && missile[mi]._misource == id )
    {
      dFlags[missile[mi]._mix][missile[mi]._miy] &= 0xFEu;
      dMissile[missile[mi]._mix][missile[mi]._miy] = 0;
      DeleteMissile(mi, i);
    }
  }
}

//----- (00494348) --------------------------------------------------------
void __fastcall SetCurrentPortal(int p)
{
  portalindex = p;
}

//----- (00494366) --------------------------------------------------------
void __cdecl GetPortalLevel()
{
  if ( currlevel )
  {
    setlevel = 0;
    currlevel = 0;
    plr[myplr].plrlevel = 0;
    leveltype = gnLevelTypeTbl[currlevel];
  }
  else
  {
    if ( portal[portalindex].setlvl )
    {
      setlevel = 1;
      setlvlnum = portal[portalindex].level;
      plr[myplr].plrlevel = (unsigned __int8)setlvlnum;
    }
    else
    {
      setlevel = 0;
      currlevel = portal[portalindex].level;
      plr[myplr].plrlevel = currlevel;
      leveltype = gnLevelTypeTbl[currlevel];
    }
    if ( myplr == portalindex )
    {
      NetSendCmd(1u, CMD_DEACTIVATEPORTAL);
      DeactivatePortal(portalindex);
    }
  }
}

//----- (004944AF) --------------------------------------------------------
void __cdecl GetPortalLvlPos()
{
  if ( currlevel )
  {
    ViewX = portal[portalindex].x;
    ViewY = portal[portalindex].y;
    if ( myplr != portalindex )
    {
      ++ViewX;
      ++ViewY;
    }
  }
  else
  {
    ViewX = WarpDropX[portalindex] + 1;
    ViewY = WarpDropY[portalindex] + 1;
  }
}

