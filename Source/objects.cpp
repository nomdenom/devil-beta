//----- (0045C890) --------------------------------------------------------
void __cdecl InitObjectGFX()
{
  char pszName; // [esp+Ch] [ebp-54h]
  int j; // [esp+2Ch] [ebp-34h]
  int i; // [esp+30h] [ebp-30h]
  char fileload[44]; // [esp+34h] [ebp-2Ch]

  memset(fileload, 0, 0x2Cu);
  for ( i = 0; AllObjects[i].oload != -1; ++i )
  {
    if ( AllObjects[i].oload == 1
      && AllObjects[i].ominlvl <= (signed int)currlevel
      && AllObjects[i].omaxlvl >= (signed int)currlevel )
    {
      fileload[AllObjects[i].ofindex] = 1;
    }
    if ( AllObjects[i].otheme != -1 )
    {
      for ( j = 0; numthemes > j; ++j )
      {
        if ( AllObjects[i].otheme == themes[j].ttype )
          fileload[AllObjects[i].ofindex] = 1;
      }
    }
  }
  numobjfiles = 0;
  for ( i = 0; i < 44; ++i )
  {
    if ( fileload[i] )
    {
      ObjFileList[numobjfiles] = i;
      sprintf(&pszName, "Objects\\%s.CEL", ObjMasterLoadList[i]);
      if ( pObjCels[numobjfiles] )
        assertion_failed(123, "C:\\Diablo\\Direct\\OBJECTS.CPP");
      pObjCels[numobjfiles++] = LoadFileInMem(&pszName, 0, 124, "C:\\Diablo\\Direct\\OBJECTS.CPP");
    }
  }
}

//----- (0045CA91) --------------------------------------------------------
void __cdecl FreeObjectGFX()
{
  int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < numobjfiles; ++i )
  {
    mem_free_dbg(pObjCels[i], 134, "C:\\Diablo\\Direct\\OBJECTS.CPP");
    pObjCels[i] = 0;
  }
}

//----- (0045CAED) --------------------------------------------------------
BOOL __fastcall RndLocOk(int xp, int yp)
{
  if ( dMonster[xp][yp] )
    return 0;
  if ( dPlayer[xp][yp] )
    return 0;
  if ( dObject[xp][yp] )
    return 0;
  if ( dFlags[xp][yp] & 8 )
    return 0;
  if ( nSolidTable[dPiece[xp][yp]] )
    return 0;
  if ( leveltype != 1 || dPiece[xp][yp] <= 126 || dPiece[xp][yp] >= 144 )
    return 1;
  return 0;
}

//----- (0045CC29) --------------------------------------------------------
BOOL __fastcall objects_45CC29(int x, int y)
{
  BOOL result; // eax

  if ( dFlags[x][y] & 8 )
    result = 0;
  else
    result = nSolidTable[dPiece[x][y]] == 0;
  return result;
}

//----- (0045CD5D) --------------------------------------------------------
void __fastcall InitRndLocObj(int min, int max, _object_id objtype)
{
  int v3; // eax
  int yp; // [esp+14h] [ebp-10h]
  int i; // [esp+18h] [ebp-Ch]
  int xp; // [esp+1Ch] [ebp-8h]
  int v7; // [esp+20h] [ebp-4h]

  v7 = random(139, max - min) + min;
  for ( i = 0; i < v7; ++i )
  {
    do
    {
      do
      {
        xp = random(139, 80) + 16;
        v3 = random(139, 80);
        yp = v3 + 16;
      }
      while ( !RndLocOk(xp - 1, v3 + 15) );
    }
    while ( !RndLocOk(xp, yp - 1)
         || !RndLocOk(xp + 1, yp - 1)
         || !RndLocOk(xp - 1, yp)
         || !RndLocOk(xp, yp)
         || !RndLocOk(xp + 1, yp)
         || !RndLocOk(xp - 1, yp + 1)
         || !RndLocOk(xp, yp + 1)
         || !RndLocOk(xp + 1, yp + 1) );
    AddObject(objtype, xp, yp);
  }
}

//----- (0045CED9) --------------------------------------------------------
void __fastcall InitRndLocBigObj(int min, int max, _object_id objtype)
{
  int v3; // eax
  int yp; // [esp+14h] [ebp-10h]
  int i; // [esp+18h] [ebp-Ch]
  int xp; // [esp+1Ch] [ebp-8h]
  int v7; // [esp+20h] [ebp-4h]

  v7 = random(140, max - min) + min;
  for ( i = 0; i < v7; ++i )
  {
    do
    {
      do
      {
        xp = random(140, 80) + 16;
        v3 = random(140, 80);
        yp = v3 + 16;
      }
      while ( !RndLocOk(xp - 1, v3 + 14) );
    }
    while ( !RndLocOk(xp, yp - 2)
         || !RndLocOk(xp + 1, yp - 2)
         || !RndLocOk(xp - 1, yp - 1)
         || !RndLocOk(xp, yp - 1)
         || !RndLocOk(xp + 1, yp - 1)
         || !RndLocOk(xp - 1, yp)
         || !RndLocOk(xp, yp)
         || !RndLocOk(xp + 1, yp)
         || !RndLocOk(xp - 1, yp + 1)
         || !RndLocOk(xp, yp + 1)
         || !RndLocOk(xp + 1, yp + 1) );
    AddObject(objtype, xp, yp);
  }
}

//----- (0045D0A8) --------------------------------------------------------
void __cdecl ClrAllObjects()
{
  signed int i; // [esp+Ch] [ebp-4h]
  int j; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 127; ++i )
  {
    object[i]._ox = 0;
    object[i]._oy = 0;
    object[i]._oAnimData = 0;
    object[i]._oAnimDelay = 0;
    object[i]._oAnimCnt = 0;
    object[i]._oAnimLen = 0;
    object[i]._oAnimFrame = 0;
    object[i]._oDelFlag = 0;
    object[i]._oVar1 = 0;
    object[i]._oVar2 = 0;
    object[i]._oVar3 = 0;
    object[i]._oVar4 = 0;
  }
  nobjects = 0;
  for ( j = 0; j < 127; ++j )
  {
    objectavail[j] = j;
    objectactive[j] = 0;
  }
  trapid = 1;
  trapdir = 0;
  leverid = 1;
}

//----- (0045D22A) --------------------------------------------------------
void __cdecl AddTortures()
{
  int oy; // [esp+Ch] [ebp-8h]
  int ox; // [esp+10h] [ebp-4h]

  for ( oy = 0; oy < 112; ++oy )
  {
    for ( ox = 0; ox < 112; ++ox )
    {
      if ( dPiece[ox][oy] == 367 )
      {
        AddObject(OBJ_TORTURE1, ox, oy + 1);
        AddObject(OBJ_TORTURE3, ox + 2, oy - 1);
        AddObject(OBJ_TORTURE2, ox, oy + 3);
        AddObject(OBJ_TORTURE4, ox + 4, oy - 1);
        AddObject(OBJ_TORTURE5, ox, oy + 5);
        AddObject(OBJ_TNUDEM1, ox + 1, oy + 3);
        AddObject(OBJ_TNUDEM2, ox + 4, oy + 5);
        AddObject(OBJ_TNUDEM3, ox + 2, oy);
        AddObject(OBJ_TNUDEM4, ox + 3, oy + 2);
        AddObject(OBJ_TNUDEW1, ox + 2, oy + 4);
        AddObject(OBJ_TNUDEW2, ox + 2, oy + 1);
        AddObject(OBJ_TNUDEW3, ox + 4, oy + 2);
      }
    }
  }
}

//----- (0045D398) --------------------------------------------------------
int __fastcall unused_sub_45D398(int a1, int a2, int ot, int a4)
{
  int result; // eax
  int v5; // ST1C_4
  int v6; // ST1C_4
  int v7; // ST1C_4
  int v8; // ST1C_4
  int v9; // ST1C_4
  int v10; // ST1C_4
  int v11; // ST1C_4
  int v12; // ST1C_4
  int v13; // ST1C_4
  int v14; // ST1C_4
  int v15; // ST1C_4
  int v16; // ST1C_4
  int oy; // [esp+14h] [ebp-3Ch]
  int v18; // [esp+18h] [ebp-38h]
  int v19; // [esp+1Ch] [ebp-34h]
  signed int v20; // [esp+20h] [ebp-30h]
  int v21; // [esp+24h] [ebp-2Ch]
  int yp; // [esp+28h] [ebp-28h]
  int ypa; // [esp+28h] [ebp-28h]
  int v24; // [esp+2Ch] [ebp-24h]
  int ox; // [esp+30h] [ebp-20h]
  signed int j; // [esp+34h] [ebp-1Ch]
  int i; // [esp+38h] [ebp-18h]
  signed int v28; // [esp+3Ch] [ebp-14h]
  int x; // [esp+40h] [ebp-10h]
  int xa; // [esp+40h] [ebp-10h]
  signed int v31; // [esp+44h] [ebp-Ch]
  int v32; // [esp+48h] [ebp-8h]
  int v33; // [esp+4Ch] [ebp-4h]

  v32 = random(0, a2 - a1) + a1;
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( v32 <= i )
      break;
    v18 = 0;
    while ( !v18 )
    {
      v18 = 1;
      x = random(0, 80) + 16;
      yp = random(0, 80) + 16;
      if ( random(0, 2) )
      {
        while ( objects_45CC29(x, yp - 1) )
          --yp;
        v24 = x;
        v19 = yp;
        v28 = 0;
        v20 = 1;
        v31 = 0;
        while ( objects_45CC29(x, yp + 1) && v18 )
        {
          v5 = RndLocOk(x - 3, yp) & v18;
          v6 = RndLocOk(x - 2, yp) & v5;
          v7 = RndLocOk(x - 1, yp) & v6;
          v8 = RndLocOk(x, yp) & v7;
          v9 = RndLocOk(x + 1, yp) & v8;
          v10 = RndLocOk(x + 2, yp) & v9;
          v18 = RndLocOk(x + 3, yp++) & v10;
          ++v31;
        }
        ox = x - 2;
        oy = random(0, v31 - 1) + v19 + 1;
        v21 = x + 2;
        v33 = random(0, v31 - 1) + v19 + 1;
        trapdir = 2;
      }
      else
      {
        while ( objects_45CC29(x - 1, yp) )
          --x;
        v24 = x;
        v19 = yp;
        v28 = 1;
        v20 = 0;
        v31 = 0;
        while ( objects_45CC29(x + 1, yp) && v18 )
        {
          v11 = RndLocOk(x, yp - 3) & v18;
          v12 = RndLocOk(x, yp - 2) & v11;
          v13 = RndLocOk(x, yp - 1) & v12;
          v14 = RndLocOk(x, yp) & v13;
          v15 = RndLocOk(x, yp + 1) & v14;
          v16 = RndLocOk(x, yp + 2) & v15;
          v18 = RndLocOk(x++, yp + 3) & v16;
          ++v31;
        }
        ox = random(0, v31 - 1) + v24 + 1;
        oy = yp - 2;
        v21 = random(0, v31 - 1) + v24 + 1;
        v33 = yp + 2;
        trapdir = 1;
      }
      if ( v31 < 5 || v31 > 12 )
        v18 = 0;
    }
    xa = v24;
    ypa = v19;
    for ( j = 0; v31 >= j; ++j )
    {
      AddObject((_object_id)ot, xa, ypa);
      xa += v28;
      ypa += v20;
    }
    AddObject((_object_id)a4, ox, oy);
    AddObject((_object_id)a4, v21, v33);
    ++trapid;
  }
  return result;
}

//----- (0045D6FE) --------------------------------------------------------
void __fastcall unused_sub_45D6FE_lever(int a1, int a2, int a3, int a4, int x1, int y1, int x2, int y2)
{
  int v8; // [esp+Ch] [ebp-1Ch]
  int v9; // [esp+10h] [ebp-18h]
  int yp; // [esp+14h] [ebp-14h]
  int xp; // [esp+18h] [ebp-10h]
  int oy; // [esp+1Ch] [ebp-Ch]
  int ox; // [esp+24h] [ebp-4h]

  v8 = a2;
  v9 = a1;
  do
  {
    do
    {
      xp = random(141, a3 - v9 + 1) + v9;
      yp = random(141, a4 - v8 + 1) + v8;
    }
    while ( !RndLocOk(xp - 1, yp - 1) );
  }
  while ( !RndLocOk(xp, yp - 1)
       || !RndLocOk(xp + 1, yp - 1)
       || !RndLocOk(xp - 1, yp)
       || !RndLocOk(xp, yp)
       || !RndLocOk(xp + 1, yp)
       || !RndLocOk(xp - 1, yp + 1)
       || !RndLocOk(xp, yp + 1)
       || !RndLocOk(xp + 1, yp + 1) );
  AddObject(OBJ_LEVER, ox, oy);
  SetObjMapRange(dObject[ox][oy] - 1, x1, y1, x2, y2, leverid);
  ++leverid;
}

//----- (0045D88D) --------------------------------------------------------
void __fastcall objects_45D88D(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int msg)
{
  int i; // ST28_4
  int yp; // [esp+14h] [ebp-Ch]
  int xp; // [esp+1Ch] [ebp-4h]

  do
  {
    do
    {
      xp = random(142, x2 - x1 + 1) + x1;
      yp = random(142, y2 - y1 + 1) + y1;
    }
    while ( !RndLocOk(xp - 1, yp - 1) );
  }
  while ( !RndLocOk(xp, yp - 1)
       || !RndLocOk(xp + 1, yp - 1)
       || !RndLocOk(xp - 1, yp)
       || !RndLocOk(xp, yp)
       || !RndLocOk(xp + 1, yp)
       || !RndLocOk(xp - 1, yp + 1)
       || !RndLocOk(xp, yp + 1)
       || !RndLocOk(xp + 1, yp + 1) );
  if ( quests[4]._qlevel == currlevel )
    AddObject(OBJ_BOOKLVR, xp, yp);
  if ( quests[8]._qlevel == currlevel )
    AddObject(OBJ_BLINDBOOK, xp, yp);
  if ( quests[9]._qlevel == currlevel )
  {
    xp = 2 * setpc_x + 25;
    yp = 2 * setpc_y + 40;
    AddObject(OBJ_BLOODBOOK, xp, yp);
  }
  i = dObject[xp][yp] - 1;
  SetObjMapRange(i, x3, y3, x4, y4, leverid);
  SetBookMsg(i, msg);
  ++leverid;
}

//----- (0045DAA8) --------------------------------------------------------
void __cdecl InitRndBarrels()
{
  int v0; // ST24_4
  BOOL v1; // [esp+Ch] [ebp-24h]
  _object_id ot; // [esp+10h] [ebp-20h]
  _object_id ota; // [esp+10h] [ebp-20h]
  int yp; // [esp+14h] [ebp-1Ch]
  int i; // [esp+18h] [ebp-18h]
  int xp; // [esp+1Ch] [ebp-14h]
  signed int v7; // [esp+24h] [ebp-Ch]
  signed int v8; // [esp+28h] [ebp-8h]
  int v9; // [esp+2Ch] [ebp-4h]

  v9 = random(143, 5) + 3;
  for ( i = 0; i < v9; ++i )
  {
    do
    {
      xp = random(143, 80) + 16;
      yp = random(143, 80) + 16;
    }
    while ( !RndLocOk(xp, yp) );
    if ( random(143, 4) )
      ot = OBJ_BARREL;
    else
      ot = OBJ_BARRELEX;
    AddObject(ot, xp, yp);
    v8 = 1;
    v1 = 1;
    while ( !random(143, v8 >> 1) && v1 )
    {
      v7 = 0;
      v1 = 0;
      while ( !v1 && v7 < 3 )
      {
        v0 = random(143, 8);
        xp += bxadd[v0];
        yp += byadd[v0];
        v1 = RndLocOk(xp, yp);
        ++v7;
      }
      if ( v1 )
      {
        if ( random(143, 5) )
          ota = OBJ_BARREL;
        else
          ota = OBJ_BARRELEX;
        AddObject(ota, xp, yp);
        ++v8;
      }
    }
  }
}

//----- (0045DC55) --------------------------------------------------------
void __fastcall AddL1Objs(int x1, int y1, int x2, int y2)
{
  int oy; // [esp+14h] [ebp-Ch]
  int ox; // [esp+18h] [ebp-8h]
  int v7; // [esp+1Ch] [ebp-4h]

  for ( oy = y1; oy < y2; ++oy )
  {
    for ( ox = x1; ox < x2; ++ox )
    {
      v7 = dPiece[ox][oy];
      if ( v7 == 270 )
        AddObject(0, ox, oy);
      if ( v7 == 44 || v7 == 51 || v7 == 214 )
        AddObject(OBJ_L1LDOOR, ox, oy);
      if ( v7 == 46 || v7 == 56 )
        AddObject(OBJ_L1RDOOR, ox, oy);
    }
  }
}

//----- (0045DD3A) --------------------------------------------------------
void __fastcall AddL2Objs(int x1, int y1, int x2, int y2)
{
  int oy; // [esp+14h] [ebp-Ch]
  int ox; // [esp+18h] [ebp-8h]
  int v7; // [esp+1Ch] [ebp-4h]

  for ( oy = y1; oy < y2; ++oy )
  {
    for ( ox = x1; ox < x2; ++ox )
    {
      v7 = dPiece[ox][oy];
      if ( v7 == 13 )
        AddObject(OBJ_L2LDOOR, ox, oy);
      if ( v7 == 541 )
        AddObject(OBJ_L2LDOOR, ox, oy);
      if ( v7 == 17 )
        AddObject(OBJ_L2RDOOR, ox, oy);
      if ( v7 == 542 )
        AddObject(OBJ_L2RDOOR, ox, oy);
    }
  }
}

//----- (0045DE1F) --------------------------------------------------------
BOOL __fastcall WallTrapLocOk(int xp, int yp)
{
  return (dFlags[xp][yp] & 8) == 0;
}

//----- (0045DE64) --------------------------------------------------------
void __cdecl AddL2Torches()
{
  int yp; // [esp+Ch] [ebp-Ch]
  int xp; // [esp+10h] [ebp-8h]
  int v2; // [esp+14h] [ebp-4h]

  for ( yp = 0; yp < 112; ++yp )
  {
    for ( xp = 0; xp < 112; ++xp )
    {
      if ( WallTrapLocOk(xp, yp) )
      {
        v2 = dPiece[xp][yp];
        if ( v2 == 1 && !random(145, 3) )
          AddObject(OBJ_TORCHL2, xp, yp);
        if ( v2 == 5 && !random(145, 3) )
          AddObject(OBJ_TORCHR2, xp, yp);
        if ( v2 == 37 && !random(145, 10) && !dObject[xp - 1][yp] )
          AddObject(OBJ_TORCHL, xp - 1, yp);
        if ( v2 == 41 && !random(145, 10) && !dungeon[39][112 * xp + 39 + yp] )
          AddObject(OBJ_TORCHR, xp, yp - 1);
      }
    }
  }
}

//----- (0045DFEB) --------------------------------------------------------
BOOL __fastcall TorchLocOK(int xp, int yp)
{
  BOOL result; // eax

  if ( dFlags[xp][yp] & 8 )
    result = 0;
  else
    result = nTrapTable[dPiece[xp][yp]] != 0;
  return result;
}

//----- (0045E05E) --------------------------------------------------------
void __cdecl AddObjTraps()
{
  char v0; // ST28_1
  char v1; // ST28_1
  char v2; // [esp+Ch] [ebp-1Ch]
  int y; // [esp+10h] [ebp-18h]
  int x; // [esp+14h] [ebp-14h]
  int yp; // [esp+18h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-Ch]
  int xp; // [esp+20h] [ebp-8h]

  if ( currlevel == 1 )
    v6 = 10;
  if ( (signed int)currlevel >= 2 )
    v6 = 15;
  if ( (signed int)currlevel >= 5 )
    v6 = 20;
  if ( (signed int)currlevel >= 7 )
    v6 = 25;
  for ( y = 0; y < 112; ++y )
  {
    for ( x = 0; x < 112; ++x )
    {
      if ( dObject[x][y] > 0 && random(144, 100) < v6 )
      {
        v2 = dObject[x][y] - 1;
        if ( AllObjects[object[v2]._otype].oTrapFlag )
        {
          if ( random(144, 2) )
          {
            for ( yp = y - 1; !nSolidTable[dPiece[x][yp]]; --yp )
              ;
            if ( TorchLocOK(x, yp) && y - yp > 1 )
            {
              AddObject(OBJ_TRAPR, x, yp);
              v1 = dObject[x][yp] - 1;
              object[v1]._oVar1 = x;
              object[v1]._oVar2 = y;
              object[v2]._oTrapFlag = 1;
            }
          }
          else
          {
            for ( xp = x - 1; !nSolidTable[dPiece[xp][y]]; --xp )
              ;
            if ( TorchLocOK(xp, y) )
            {
              if ( x - xp > 1 )
              {
                AddObject(OBJ_TRAPL, xp, y);
                v0 = dObject[xp][y] - 1;
                object[v0]._oVar1 = x;
                object[v0]._oVar2 = y;
                object[v2]._oTrapFlag = 1;
              }
            }
          }
        }
      }
    }
  }
}

//----- (0045E329) --------------------------------------------------------
void __cdecl AddChestTraps()
{
  char v0; // [esp+Ch] [ebp-Ch]
  signed int i; // [esp+10h] [ebp-8h]
  signed int j; // [esp+14h] [ebp-4h]

  for ( i = 0; i < 112; ++i )
  {
    for ( j = 0; j < 112; ++j )
    {
      if ( dObject[j][i] > 0 )
      {
        v0 = dObject[j][i] - 1;
        if ( object[v0]._otype >= 5 && object[v0]._otype <= 7 && !object[v0]._oTrapFlag && random(0, 100) < 10 )
        {
          object[v0]._otype += 63;
          object[v0]._oTrapFlag = 1;
          object[v0]._oVar4 = random(0, 3);
        }
      }
    }
  }
}

//----- (0045E455) --------------------------------------------------------
void __fastcall InitObjects(int a1)
{
  ClrAllObjects();
  InitObjFlag = 1;
  GetRndSeed();
  if ( leveltype == 1 )
  {
    if ( quests[1]._qlevel == currlevel )
      AddTortures();
    InitRndLocBigObj(10, 15, OBJ_SARC);
    AddL1Objs(0, 0, 112, 112);
    if ( quests[4]._qlevel == currlevel )
      objects_45D88D(0, 0, 112, 112, setpc_x, setpc_y, setpc_x + setpc_w + 1, setpc_y + setpc_h + 1, 11);
    InitRndBarrels();
  }
  if ( leveltype == 2 )
  {
    AddL2Objs(0, 0, 112, 112);
    AddL2Torches();
    if ( quests[8]._qlevel == currlevel )
      objects_45D88D(0, 0, 112, 112, setpc_x, setpc_y, setpc_x + setpc_w + 1, setpc_y + setpc_h + 1, 23);
    if ( quests[9]._qlevel == currlevel )
      objects_45D88D(0, 0, 112, 112, setpc_x, setpc_y, setpc_x + setpc_w + 1, setpc_y + setpc_h + 1, 24);
    InitRndBarrels();
  }
  if ( quests[2]._qlevel == currlevel )
    InitRndLocObj(1, 1, OBJ_STAND);
  if ( quests[3]._qlevel - 1 == currlevel )
    InitRndLocObj(1, 1, OBJ_BOOK2R);
  InitRndLocObj(5, 10, OBJ_CHEST1);
  InitRndLocObj(3, 6, OBJ_CHEST2);
  InitRndLocObj(1, 5, OBJ_CHEST3);
  if ( leveltype != 4 )
    AddObjTraps();
  if ( (signed int)(unsigned __int8)leveltype > 1 )
    AddChestTraps();
  InitObjFlag = 0;
}

//----- (0045E691) --------------------------------------------------------
void __fastcall SetMapObjects(char *pMap, int startx, int starty)
{
  int v3; // ST38_4
  int v4; // ST34_4
  int v5; // ST44_4
  int k; // [esp+18h] [ebp-F4h]
  int n; // [esp+18h] [ebp-F4h]
  signed int i; // [esp+20h] [ebp-ECh]
  int j; // [esp+20h] [ebp-ECh]
  int l; // [esp+20h] [ebp-ECh]
  signed int m; // [esp+20h] [ebp-ECh]
  int ii; // [esp+20h] [ebp-ECh]
  int v15; // [esp+28h] [ebp-E4h]
  int v16; // [esp+2Ch] [ebp-E0h]
  char *v17; // [esp+34h] [ebp-D8h]
  char *v18; // [esp+34h] [ebp-D8h]
  int v19; // [esp+38h] [ebp-D4h]
  int fileload[44]; // [esp+3Ch] [ebp-D0h]
  char pszName[32]; // [esp+ECh] [ebp-20h]

  ClrAllObjects();
  InitObjFlag = 1;
  for ( i = 0; i < 44; ++i )
    fileload[i] = 0;
  for ( j = 0; AllObjects[j].oload != -1; ++j )
  {
    if ( AllObjects[j].oload == 1 && AllObjects[j].olvltype == (unsigned __int8)leveltype )
      fileload[AllObjects[j].ofindex] = 1;
  }
  v3 = (unsigned __int8)*pMap;
  v4 = (unsigned __int8)pMap[2];
  v5 = 2 * v3 * v4 + 2;
  v16 = 2 * v3;
  v15 = 2 * v4;
  v19 = 4 * v16 * v15 + v5;
  v17 = &pMap[v19 + 2];
  for ( k = 0; v15 > k; ++k )
  {
    for ( l = 0; v16 > l; ++l )
    {
      if ( *v17 )
        fileload[AllObjects[ObjTypeConv[(unsigned __int8)*v17]].ofindex] = 1;
      v17 += 2;
    }
  }
  numobjfiles = 0;
  for ( m = 0; m < 44; ++m )
  {
    if ( fileload[m] )
    {
      ObjFileList[numobjfiles] = m;
      sprintf(pszName, "Objects\\%s.CEL", ObjMasterLoadList[m]);
      if ( pObjCels[numobjfiles] )
        assertion_failed(715, "C:\\Diablo\\Direct\\OBJECTS.CPP");
      pObjCels[numobjfiles++] = LoadFileInMem(pszName, 0, 716, "C:\\Diablo\\Direct\\OBJECTS.CPP");
    }
  }
  v18 = &pMap[v19 + 2];
  for ( n = 0; v15 > n; ++n )
  {
    for ( ii = 0; v16 > ii; ++ii )
    {
      if ( *v18 )
        AddObject(ObjTypeConv[(unsigned __int8)*v18], startx + ii + 16, starty + n + 16);
      v18 += 2;
    }
  }
  InitObjFlag = 0;
}

//----- (0045EA7B) --------------------------------------------------------
void __fastcall DeleteObject(int oi, int i)
{
  dObject[object[oi]._ox][object[oi]._oy] = 0;
  objectavail[127 - nobjects--] = oi;
  if ( nobjects > 0 && nobjects != i )
    objectactive[i] = objectactive[nobjects];
}

//----- (0045EB1F) --------------------------------------------------------
void __fastcall SetupObject(int i, int x, int y, int ot)
{
  int j; // [esp+14h] [ebp-8h]

  object[i]._otype = ot;
  object[i]._ox = x;
  object[i]._oy = y;
  for ( j = 0; ObjFileList[j] != AllObjects[ot].ofindex; ++j )
    ;
  object[i]._oAnimData = pObjCels[j];
  object[i]._oAnimFlag = AllObjects[ot].oAnimFlag;
  if ( object[i]._oAnimFlag )
  {
    object[i]._oAnimDelay = AllObjects[ot].oAnimDelay;
    object[i]._oAnimCnt = random(146, AllObjects[ot].oAnimDelay);
    object[i]._oAnimLen = AllObjects[ot].oAnimLen;
    object[i]._oAnimFrame = random(146, AllObjects[ot].oAnimLen - 1) + 1;
  }
  else
  {
    object[i]._oAnimDelay = 1000;
    object[i]._oAnimCnt = 0;
    object[i]._oAnimLen = AllObjects[ot].oAnimLen;
    object[i]._oAnimFrame = AllObjects[ot].oAnimDelay;
  }
  object[i]._oAnimWidth = AllObjects[ot].oAnimWidth;
  object[i]._oSolidFlag = AllObjects[ot].oSolidFlag;
  object[i]._oMissFlag = AllObjects[ot].oMissFlag;
  object[i]._oLight = AllObjects[ot].oLightFlag;
  object[i]._oDelFlag = 0;
  object[i]._oBreak = AllObjects[ot].oBreak;
  object[i]._oSelFlag = AllObjects[ot].oSelFlag;
  object[i]._oPreFlag = 0;
  object[i]._oTrapFlag = 0;
  object[i]._oDoorFlag = 0;
}

//----- (0045EE3C) --------------------------------------------------------
void __fastcall SetObjMapRange(int i, int x1, int y1, int x2, int y2, int v)
{
  object[i]._oVar1 = x1;
  object[i]._oVar2 = y1;
  object[i]._oVar3 = x2;
  object[i]._oVar4 = y2;
  object[i]._oVar8 = v;
}

//----- (0045EEB6) --------------------------------------------------------
void __fastcall SetBookMsg(int i, int msg)
{
  object[i]._oVar7 = msg;
}

//----- (0045EEE2) --------------------------------------------------------
void __fastcall AddL1Door(int i, int x, int y, _object_id ot)
{
  int v4; // eax

  object[i]._oDoorFlag = 1;
  if ( ot == 1 )
  {
    object[i]._oVar1 = dPiece[x][y];
    v4 = dPiece[x][y - 1];
  }
  else
  {
    object[i]._oVar1 = dPiece[x][y];
    v4 = dPiece[x - 1][y];
  }
  object[i]._oVar2 = v4;
  object[i]._oVar4 = 0;
}

//----- (0045EFD1) --------------------------------------------------------
void __fastcall AddSCambBook(int i)
{
  if ( quests[3]._qactive != 1 )
  {
    object[i]._oSelFlag = 0;
    object[i]._oAnimFrame = 6;
  }
}

//----- (0045F01C) --------------------------------------------------------
void __fastcall AddChest(int i, int t)
{
  int v2; // [esp+10h] [ebp-8h]
  int v3; // [esp+14h] [ebp-4h]

  v2 = t;
  v3 = i;
  if ( !random(147, 2) )
    object[v3]._oAnimFrame += 3;
  object[v3]._oRndSeed = GetRndSeed();
  switch ( v2 )
  {
    case 5:
    case 68:
      object[v3]._oVar1 = random(147, 2);
      break;
    case 6:
    case 69:
      object[v3]._oVar1 = random(147, 3);
      break;
    case 7:
    case 70:
      object[v3]._oVar1 = random(147, 4);
      break;
    default:
      break;
  }
  object[v3]._oVar2 = random(147, 8);
}

//----- (0045F18B) --------------------------------------------------------
void __fastcall AddL2Door(int i, int x, int y, _object_id ot)
{
  int v4; // [esp+10h] [ebp-4h]

  v4 = i;
  object[i]._oDoorFlag = 1;
  if ( ot == 42 )
    ObjSetMicro(x, y, 538);
  else
    ObjSetMicro(x, y, 540);
  object[v4]._oVar4 = 0;
}

//----- (0045F1FD) --------------------------------------------------------
void __fastcall AddSarc(int i)
{
  int v1; // [esp+Ch] [ebp-Ch]

  v1 = i;
  dObject[object[i]._ox][object[i]._oy - 1] = -1 - i;
  object[i]._oVar1 = random(153, 10);
  object[v1]._oRndSeed = GetRndSeed();
  if ( object[v1]._oVar1 >= 8 )
    object[v1]._oVar2 = PreSpawnSkeleton();
}

//----- (0045F2BC) --------------------------------------------------------
void __fastcall AddFlameTrap(int i)
{
  object[i]._oVar1 = trapid;
  object[i]._oVar2 = 0;
  object[i]._oVar3 = trapdir;
  object[i]._oVar4 = 0;
}

//----- (0045F324) --------------------------------------------------------
void __fastcall AddFlameLvr(int i)
{
  object[i]._oVar1 = trapid;
  object[i]._oVar2 = 49;
}

//----- (0045F363) --------------------------------------------------------
void __fastcall AddTrap(int i)
{
  int v1; // [esp+10h] [ebp-Ch]
  int v2; // [esp+14h] [ebp-8h]

  v1 = i;
  v2 = random(148, currlevel / 3 + 1);
  if ( !v2 )
    object[v1]._oVar3 = 0;
  if ( v2 == 1 )
    object[v1]._oVar3 = 1;
  if ( v2 == 2 )
    object[v1]._oVar3 = 7;
  object[v1]._oVar4 = 0;
}

//----- (0045F40D) --------------------------------------------------------
void __fastcall AddObjLight(int i, int r)
{
  int v2; // [esp+10h] [ebp-4h]

  v2 = i;
  if ( InitObjFlag )
  {
    DoLighting(object[i]._ox, object[i]._oy, r, -1);
    object[v2]._oVar1 = -1;
  }
  else
  {
    object[i]._oVar1 = 0;
  }
}

//----- (0045F48B) --------------------------------------------------------
void __fastcall AddBarrel(int i)
{
  int v1; // [esp+10h] [ebp-4h]

  v1 = i;
  object[i]._oVar1 = random(149, 5) + 5;
  object[v1]._oRndSeed = GetRndSeed();
  object[v1]._oVar2 = random(149, 5);
  object[v1]._oVar3 = random(149, 3);
  if ( object[v1]._oVar2 == 4 )
    object[v1]._oVar4 = PreSpawnSkeleton();
}

//----- (0045F545) --------------------------------------------------------
int __fastcall objects_45F545(int a1)
{
  int result; // eax
  int v2; // [esp+Ch] [ebp-8h]

  v2 = a1;
  object[a1]._oPreFlag = 1;
  result = random(150, 13);
  object[v2]._oVar1 = result;
  if ( result == 3 || result == 7 || result == 9 )
  {
    object[v2]._oAnimFrame = 12;
    result = 24 * v2;
    object[v2]._oAnimLen = 22;
  }
  return result;
}

//----- (0045F5DA) --------------------------------------------------------
void __fastcall AddBookcase(int i)
{
  int v1; // ST0C_4

  v1 = i;
  object[i]._oRndSeed = GetRndSeed();
  object[v1]._oPreFlag = 1;
}

//----- (0045F619) --------------------------------------------------------
int __fastcall objects_45F619(int a1)
{
  int v1; // ST0C_4
  int result; // eax

  v1 = a1;
  result = GetRndSeed();
  object[v1]._oRndSeed = result;
  return result;
}

//----- (0045F644) --------------------------------------------------------
void __fastcall AddPurifyingFountain(int i)
{
  int v1; // ST10_4
  int v2; // ebx

  v1 = object[i]._oy;
  v2 = object[i]._ox;
  dungeon[39][112 * v2 + 39 + v1] = -1 - i;
  dObject[v2 - 1][v1] = -1 - i;
  dungeon[39][112 * (v2 - 1) + 39 + v1] = -1 - i;
}

//----- (0045F6E8) --------------------------------------------------------
void __fastcall AddDecap(int i)
{
  int v1; // ST0C_4

  v1 = i;
  object[i]._oRndSeed = GetRndSeed();
  object[v1]._oAnimFrame = random(151, 8) + 1;
  object[v1]._oPreFlag = 1;
}

//----- (0045F747) --------------------------------------------------------
void __fastcall AddObject(_object_id ot, int ox, int oy)
{
  int x; // [esp+10h] [ebp-Ch]
  int ota; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  x = ox;
  ota = ot;
  if ( nobjects < 127 )
  {
    i = objectavail[0];
    objectavail[0] = objectavail[127 - nobjects - 1];
    objectactive[nobjects] = i;
    dObject[ox][oy] = i + 1;
    SetupObject(i, ox, oy, ot);
    switch ( ota )
    {
      case OBJ_L1LIGHT:
      case OBJ_BCROSS:
        AddObjLight(i, 5);
        break;
      case OBJ_L1LDOOR:
      case OBJ_L1RDOOR:
        AddL1Door(i, x, oy, (_object_id)ota);
        break;
      case OBJ_SKFIRE:
      case OBJ_CANDLE2:
      case OBJ_BOOKCANDLE:
      case OBJ_L3LDOOR:
        AddObjLight(i, 5);
        break;
      case OBJ_CHEST1:
      case OBJ_CHEST2:
      case OBJ_CHEST3:
      case OBJ_TCHEST1:
      case OBJ_TCHEST2:
      case OBJ_TCHEST3:
        AddChest(i, ota);
        break;
      case OBJ_BOOK2R:
        AddSCambBook(i);
        break;
      case OBJ_L2LDOOR:
      case OBJ_L2RDOOR:
        AddL2Door(i, x, oy, (_object_id)ota);
        break;
      case OBJ_TORCHL:
      case OBJ_TORCHR:
      case OBJ_TORCHL2:
      case OBJ_TORCHR2:
        AddObjLight(i, 8);
        break;
      case OBJ_SARC:
        AddSarc(i);
        break;
      case OBJ_FLAMEHOLE:
        AddFlameTrap(i);
        break;
      case OBJ_FLAMELVR:
        AddFlameLvr(i);
        break;
      case OBJ_WATER:
        object[i]._oAnimFrame = 1;
        break;
      case OBJ_TRAPL:
      case OBJ_TRAPR:
        AddTrap(i);
        break;
      case OBJ_BARREL:
      case OBJ_BARRELEX:
        AddBarrel(i);
        break;
      case OBJ_SHRINEL:
      case OBJ_SHRINER:
      case OBJ_L3RDOOR:
      case OBJ_PURIFYINGFTN:
        objects_45F545(i);
        break;
      case OBJ_SKELBOOK:
      case OBJ_BOOKSTAND:
        objects_45F619(i);
        break;
      case OBJ_BOOKCASEL:
      case OBJ_BOOKCASER:
      case OBJ_ARMORSTAND:
      case OBJ_ARMORSTANDN:
        AddBookcase(i);
        break;
      case OBJ_BLOODFTN:
        AddPurifyingFountain(i);
        break;
      case OBJ_DECAP:
        AddDecap(i);
        break;
      default:
        break;
    }
    object[i]._oAnimWidth2 = (object[i]._oAnimWidth - 64) >> 1;
    ++nobjects;
  }
}

//----- (0045FA03) --------------------------------------------------------
void __fastcall Obj_Light(int i, int lr)
{
  int v2; // ST1C_4
  int v5; // [esp+14h] [ebp-1Ch]
  int y; // [esp+1Ch] [ebp-14h]
  signed int v7; // [esp+20h] [ebp-10h]
  int x; // [esp+24h] [ebp-Ch]
  int v9; // [esp+28h] [ebp-8h]
  signed int j; // [esp+2Ch] [ebp-4h]

  if ( object[i]._oVar1 != -1 )
  {
    x = object[i]._ox;
    y = object[i]._oy;
    v9 = lr + 10;
    v7 = 0;
    if ( !lightflag )
    {
      for ( j = 0; j < 4 && !v7; ++j )
      {
        if ( plr[j].plractive )
        {
          if ( plr[j].plrlevel == currlevel )
          {
            v2 = abs(plr[j].WorldX - x);
            v5 = abs(plr[j].WorldY - y);
            if ( v2 < v9 && v5 < v9 )
              v7 = 1;
          }
        }
      }
    }
    if ( v7 )
    {
      if ( !object[i]._oVar1 )
        object[i]._olid = AddLight(x, y, lr);
      object[i]._oVar1 = 1;
    }
    else
    {
      if ( object[i]._oVar1 == 1 )
        AddUnLight(object[i]._olid);
      object[i]._oVar1 = 0;
    }
  }
}

//----- (0045FC0F) --------------------------------------------------------
void __fastcall Obj_StopAnim(int i)
{
  if ( object[i]._oAnimFrame == object[i]._oAnimLen )
  {
    object[i]._oAnimCnt = 0;
    object[i]._oAnimDelay = 1000;
  }
}

//----- (0045FC73) --------------------------------------------------------
void __fastcall Obj_Door(int i)
{
  int v1; // [esp+10h] [ebp-Ch]
  bool v2; // [esp+14h] [ebp-8h]
  bool v3; // [esp+14h] [ebp-8h]
  int v4; // [esp+14h] [ebp-8h]
  int v5; // [esp+18h] [ebp-4h]

  if ( object[i]._oVar4 )
  {
    v5 = object[i]._ox;
    v1 = object[i]._oy;
    if ( dItem[v5][v1] )
      v2 = 0;
    else
      v2 = dMonster[v5][v1] == 0;
    if ( dDead[v5][v1] )
      v3 = 0;
    else
      v3 = v2;
    if ( dPlayer[v5][v1] )
      v4 = 0;
    else
      v4 = v3;
    object[i]._oSelFlag = 2;
    if ( v4 )
      object[i]._oVar4 = 1;
    else
      object[i]._oVar4 = 2;
    object[i]._oMissFlag = 1;
  }
  else
  {
    object[i]._oSelFlag = 3;
    object[i]._oMissFlag = 0;
  }
}

//----- (0045FE0D) --------------------------------------------------------
void __fastcall Obj_Sarc(int i)
{
  if ( object[i]._oAnimFrame == object[i]._oAnimLen )
    object[i]._oAnimFlag = 0;
}

//----- (0045FE5D) --------------------------------------------------------
void __fastcall ActivateTrapLine(_object_id ttype, int tid)
{
  int v4; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  for ( i = 0; nobjects > i; ++i )
  {
    v4 = objectactive[i];
    if ( object[v4]._otype == ttype && object[v4]._oVar1 == tid )
    {
      object[v4]._oVar4 = 1;
      object[v4]._oAnimFlag = 1;
      object[v4]._oAnimDelay = 1;
      object[v4]._olid = AddLight(object[v4]._ox, object[v4]._oy, 1);
    }
  }
}

//----- (0045FF4B) --------------------------------------------------------
void __fastcall Obj_FlameTrap(int i)
{
  int v1; // [esp+10h] [ebp-Ch]
  int v2; // [esp+10h] [ebp-Ch]
  signed int j; // [esp+14h] [ebp-8h]
  signed int k; // [esp+14h] [ebp-8h]
  int v5; // [esp+18h] [ebp-4h]
  int v6; // [esp+18h] [ebp-4h]

  if ( object[i]._oVar2 )
  {
    if ( object[i]._oVar4 )
    {
      if ( --object[i]._oAnimFrame == 1 )
      {
        object[i]._oVar4 = 0;
        AddUnLight(object[i]._olid);
      }
      else if ( object[i]._oAnimFrame <= 4 )
      {
        ChangeLightRadius(object[i]._olid, object[i]._oAnimFrame);
      }
    }
  }
  else if ( object[i]._oVar4 )
  {
    if ( object[i]._oAnimFrame == object[i]._oAnimLen )
      object[i]._oAnimFrame = 11;
    if ( object[i]._oAnimFrame <= 5 )
      ChangeLightRadius(object[i]._olid, object[i]._oAnimFrame);
  }
  else
  {
    if ( object[i]._oVar3 == 2 )
    {
      v5 = object[i]._ox - 2;
      v1 = object[i]._oy;
      for ( j = 0; j < 5; ++j )
      {
        if ( dPlayer[v5][v1] || dMonster[v5][v1] )
          object[i]._oVar4 = 1;
        ++v5;
      }
    }
    else
    {
      v6 = object[i]._ox;
      v2 = object[i]._oy - 2;
      for ( k = 0; k < 5; ++k )
      {
        if ( dPlayer[v6][v2] || dMonster[v6][v2] )
          object[i]._oVar4 = 1;
        ++v2;
      }
    }
    if ( object[i]._oVar4 )
      ActivateTrapLine(object[i]._otype, object[i]._oVar1);
  }
}

//----- (00460247) --------------------------------------------------------
void __fastcall Obj_Trap(int i)
{
  int v1; // ST08_4
  int v2; // [esp+10h] [ebp-30h]
  int y2; // [esp+14h] [ebp-2Ch]
  signed int v4; // [esp+18h] [ebp-28h]
  int x2; // [esp+1Ch] [ebp-24h]
  int y1; // [esp+20h] [ebp-20h]
  int x1; // [esp+24h] [ebp-1Ch]
  int j; // [esp+2Ch] [ebp-14h]
  int k; // [esp+30h] [ebp-10h]
  int v10; // [esp+34h] [ebp-Ch]
  int v11; // [esp+38h] [ebp-8h]
  int v12; // [esp+3Ch] [ebp-4h]

  v2 = i;
  v4 = 0;
  if ( !object[i]._oVar4 )
  {
    v10 = dObject[object[i]._oVar1][object[i]._oVar2] - 1;
    switch ( object[v10]._otype )
    {
      case 1:
      case 2:
      case 0x2A:
      case 0x2B:
        if ( object[v10]._oVar4 )
          v4 = 1;
        break;
      case 4:
      case 5:
      case 6:
      case 7:
      case 0x1C:
      case 0x30:
        if ( !object[v10]._oSelFlag )
          v4 = 1;
        break;
      default:
        break;
    }
    if ( v4 )
    {
      object[i]._oVar4 = 1;
      x1 = object[i]._ox;
      y1 = object[i]._oy;
      x2 = object[v10]._ox;
      y2 = object[v10]._oy;
      v12 = object[v10]._ox;
      v11 = y2;
      for ( j = y2 - 1; v11 + 1 >= j; ++j )
      {
        for ( k = v12 - 1; v12 + 1 >= k; ++k )
        {
          if ( dPlayer[k][j] )
          {
            x2 = k;
            y2 = j;
          }
        }
      }
      if ( !deltaload )
      {
        v1 = GetDirection(x1, y1, x2, y2);
        AddMissile(x1, y1, x2, y2, v1, object[v2]._oVar3, 1, -1, 0);
        PlaySfxLoc(43, object[v10]._ox, object[v10]._oy);
      }
      object[v10]._oTrapFlag = 0;
    }
  }
}

//----- (004604F1) --------------------------------------------------------
void __cdecl ProcessObjects()
{
  int i; // [esp+10h] [ebp-8h]
  int ia; // [esp+10h] [ebp-8h]
  int j; // [esp+14h] [ebp-4h]
  int v3; // [esp+14h] [ebp-4h]

  for ( j = 0; nobjects > j; ++j )
  {
    i = objectactive[j];
    switch ( object[i]._otype )
    {
      case OBJ_L1LIGHT:
        Obj_Light(i, 10);
        break;
      case OBJ_L1LDOOR:
      case OBJ_L1RDOOR:
      case OBJ_L2LDOOR:
      case OBJ_L2RDOOR:
        Obj_Door(i);
        break;
      case OBJ_SKFIRE:
      case OBJ_CANDLE2:
      case OBJ_BOOKCANDLE:
        Obj_Light(i, 5);
        break;
      case OBJ_CRUX1:
      case OBJ_CRUX2:
      case OBJ_CRUX3:
      case OBJ_BARREL:
      case OBJ_BARRELEX:
      case OBJ_SHRINEL:
      case OBJ_SHRINER:
      case OBJ_L3RDOOR:
      case OBJ_PURIFYINGFTN:
        Obj_StopAnim(i);
        break;
      case OBJ_BCROSS:
        Obj_Light(i, 10);
        break;
      case OBJ_TORCHL:
      case OBJ_TORCHR:
      case OBJ_TORCHL2:
      case OBJ_TORCHR2:
        Obj_Light(i, 8);
        break;
      case OBJ_SARC:
        Obj_Sarc(i);
        break;
      case OBJ_FLAMEHOLE:
        Obj_FlameTrap(i);
        break;
      case OBJ_TRAPL:
      case OBJ_TRAPR:
        Obj_Trap(i);
        break;
      default:
        break;
    }
    if ( object[i]._oAnimFlag )
    {
      if ( object[i]._oAnimDelay <= ++object[i]._oAnimCnt )
      {
        object[i]._oAnimCnt = 0;
        if ( ++object[i]._oAnimFrame > object[i]._oAnimLen )
          object[i]._oAnimFrame = 1;
      }
    }
  }
  v3 = 0;
  while ( nobjects > v3 )
  {
    ia = objectactive[v3];
    if ( object[ia]._oDelFlag )
    {
      DeleteObject(ia, v3);
      v3 = 0;
    }
    else
    {
      ++v3;
    }
  }
}

//----- (00460783) --------------------------------------------------------
void __fastcall ObjSetMicro(int dx, int dy, int pn)
{
  char *v3; // [esp+14h] [ebp-Ch]
  signed int i; // [esp+18h] [ebp-8h]
  char *v5; // [esp+1Ch] [ebp-4h]

  dPiece[dx][dy] = pn;
  v3 = (char *)dpiece_defs_map_1 + 32 * gendung_get_dpiece_num_from_coord(dx, dy);
  v5 = (char *)pLevelPieces + 20 * (pn - 1);
  for ( i = 0; i < 10; ++i )
    *(_WORD *)&v3[2 * i] = *(_WORD *)&v5[2 * ((i & 1) + 8 - (i & 0xE))];
}

//----- (00460827) --------------------------------------------------------
void __fastcall objects_set_door_piece(int x, int y)
{
  int v4; // ST24_4
  SHORT v5; // ST20_2
  SHORT v6; // ST1C_2

  v4 = dPiece[x][y] - 1;
  v5 = *((_WORD *)pLevelPieces + 10 * (unsigned __int16)v4 + 8);
  v6 = *((_WORD *)pLevelPieces + 10 * (unsigned __int16)v4 + 9);
  dpiece_defs_map_1[0][0][16 * gendung_get_dpiece_num_from_coord(x, y)] = v5;
  dpiece_defs_map_1[0][0][16 * gendung_get_dpiece_num_from_coord(x, y) + 1] = v6;
}

//----- (004608C7) --------------------------------------------------------
void __fastcall ObjSetMini(int x, int y, int v)
{
  WORD *v3; // esi
  WORD v4; // ax
  int v5; // eax
  int pn; // ST2C_4
  int v7; // ST28_4
  int v8; // ST24_4
  int v9; // ST20_4
  int v10; // ST18_4
  int dy; // ST1C_4

  v3 = &pMegaTiles[4 * ((unsigned __int16)v - 1)];
  v4 = *v3;
  ++v3;
  v5 = v4 + 1;
  pn = v5;
  LOWORD(v5) = *v3;
  ++v3;
  v7 = ++v5;
  LOWORD(v5) = *v3;
  v8 = ++v5;
  LOWORD(v5) = v3[1];
  v9 = v5 + 1;
  v10 = 2 * x + 16;
  dy = 2 * y + 16;
  ObjSetMicro(v10, dy, pn);
  ObjSetMicro(v10 + 1, dy, v7);
  ObjSetMicro(v10, dy + 1, v8);
  ObjSetMicro(v10 + 1, dy + 1, v9);
}

//----- (00460964) --------------------------------------------------------
void __fastcall ObjL1Special(int x1, int y1, int x2, int y2)
{
  int i; // [esp+14h] [ebp-8h]
  int j; // [esp+18h] [ebp-4h]

  for ( i = y1; i <= y2; ++i )
  {
    for ( j = x1; j <= x2; ++j )
    {
      dArch[j][i] = 0;
      if ( dPiece[j][i] == 12 )
        dArch[j][i] = 1;
      if ( dPiece[j][i] == 11 )
        dArch[j][i] = 2;
      if ( dPiece[j][i] == 71 )
        dArch[j][i] = 1;
      if ( dPiece[j][i] == 259 )
        dArch[j][i] = 5;
      if ( dPiece[j][i] == 249 )
        dArch[j][i] = 2;
      if ( dPiece[j][i] == 325 )
        dArch[j][i] = 2;
      if ( dPiece[j][i] == 321 )
        dArch[j][i] = 1;
      if ( dPiece[j][i] == 255 )
        dArch[j][i] = 4;
      if ( dPiece[j][i] == 211 )
        dArch[j][i] = 1;
      if ( dPiece[j][i] == 344 )
        dArch[j][i] = 2;
      if ( dPiece[j][i] == 341 )
        dArch[j][i] = 1;
      if ( dPiece[j][i] == 331 )
        dArch[j][i] = 2;
      if ( dPiece[j][i] == 418 )
        dArch[j][i] = 1;
      if ( dPiece[j][i] == 421 )
        dArch[j][i] = 2;
    }
  }
}

//----- (00460CEA) --------------------------------------------------------
void __fastcall ObjL2Special(int x1, int y1, int x2, int y2)
{
  int i; // [esp+14h] [ebp-8h]
  int k; // [esp+14h] [ebp-8h]
  int j; // [esp+18h] [ebp-4h]
  int l; // [esp+18h] [ebp-4h]

  for ( i = y1; i <= y2; ++i )
  {
    for ( j = x1; x2 >= j; ++j )
    {
      dArch[j][i] = 0;
      if ( dPiece[j][i] == 541 )
        dArch[j][i] = 5;
      if ( dPiece[j][i] == 178 )
        dArch[j][i] = 5;
      if ( dPiece[j][i] == 551 )
        dArch[j][i] = 5;
      if ( dPiece[j][i] == 542 )
        dArch[j][i] = 6;
      if ( dPiece[j][i] == 553 )
        dArch[j][i] = 6;
      if ( dPiece[j][i] == 13 )
        dArch[j][i] = 5;
      if ( dPiece[j][i] == 17 )
        dArch[j][i] = 6;
    }
  }
  for ( k = y1; k <= y2; ++k )
  {
    for ( l = x1; x2 >= l; ++l )
    {
      if ( dPiece[l][k] == 132 )
      {
        dArch[l][k + 1] = 2;
        dArch[l][k + 2] = 1;
      }
      if ( dPiece[l][k] == 135 || dPiece[l][k] == 139 )
      {
        dArch[l + 1][k] = 3;
        dArch[l + 2][k] = 4;
      }
    }
  }
}

//----- (00460FE9) --------------------------------------------------------
void __fastcall DoorSet(int oi, int dx, int dy)
{
  int v5; // [esp+14h] [ebp-4h]

  v5 = dPiece[dx][dy];
  if ( v5 == 43 )
    ObjSetMicro(dx, dy, 392);
  if ( v5 == 45 )
    ObjSetMicro(dx, dy, 394);
  if ( v5 == 50 && object[oi]._otype == 1 )
    ObjSetMicro(dx, dy, 411);
  if ( v5 == 50 && object[oi]._otype == 2 )
    ObjSetMicro(dx, dy, 412);
  if ( v5 == 54 )
    ObjSetMicro(dx, dy, 397);
  if ( v5 == 55 )
    ObjSetMicro(dx, dy, 398);
  if ( v5 == 61 )
    ObjSetMicro(dx, dy, 399);
  if ( v5 == 67 )
    ObjSetMicro(dx, dy, 400);
  if ( v5 == 68 )
    ObjSetMicro(dx, dy, 401);
  if ( v5 == 69 )
    ObjSetMicro(dx, dy, 403);
  if ( v5 == 70 )
    ObjSetMicro(dx, dy, 404);
  if ( v5 == 72 )
    ObjSetMicro(dx, dy, 406);
  if ( v5 == 212 )
    ObjSetMicro(dx, dy, 407);
  if ( v5 == 354 )
    ObjSetMicro(dx, dy, 409);
  if ( v5 == 355 )
    ObjSetMicro(dx, dy, 410);
  if ( v5 == 411 )
    ObjSetMicro(dx, dy, 396);
  if ( v5 == 412 )
    ObjSetMicro(dx, dy, 396);
}

//----- (00461215) --------------------------------------------------------
void __cdecl RedoPlayerVision()
{
  signed int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 4; ++i )
  {
    if ( plr[i].plractive )
    {
      if ( plr[i].plrlevel == currlevel )
        ChangeVisionXY(plr[i]._pvid, plr[i].WorldX, plr[i].WorldY);
    }
  }
}

//----- (004612FF) --------------------------------------------------------
void __fastcall OperateL1RDoor(int pnum, int oi, unsigned __int8 sendflag)
{
  int dy; // [esp+14h] [ebp-Ch]
  bool v6; // [esp+18h] [ebp-8h]
  int v7; // [esp+18h] [ebp-8h]
  int x; // [esp+1Ch] [ebp-4h]

  if ( object[oi]._oVar4 == 2 )
  {
    if ( !deltaload )
      PlaySfxLoc(6, object[oi]._ox, object[oi]._oy);
  }
  else
  {
    x = object[oi]._ox;
    dy = object[oi]._oy;
    if ( object[oi]._oVar4 )
    {
      if ( !deltaload )
        PlaySfxLoc(6, object[oi]._ox, object[oi]._oy);
      if ( dItem[x][dy] )
        v6 = 0;
      else
        v6 = dMonster[x][dy] == 0;
      if ( dDead[x][dy] )
        v7 = 0;
      else
        v7 = v6;
      if ( v7 )
      {
        if ( myplr == pnum && sendflag )
          NetSendCmdParam1(1u, CMD_CLOSEDOOR, oi);
        object[oi]._oVar4 = 0;
        object[oi]._oSelFlag = 3;
        ObjSetMicro(x, dy, object[oi]._oVar1);
        if ( object[oi]._oVar2 == 50 )
        {
          if ( dPiece[x - 1][dy] == 396 )
            ObjSetMicro(x - 1, dy, 411);
          else
            ObjSetMicro(x - 1, dy, object[oi]._oVar2);
        }
        else
        {
          ObjSetMicro(x - 1, dy, object[oi]._oVar2);
        }
        object[oi]._oAnimFrame -= 2;
        object[oi]._oPreFlag = 0;
        RedoPlayerVision();
      }
      else
      {
        object[oi]._oVar4 = 2;
      }
    }
    else
    {
      if ( myplr == pnum && sendflag )
        NetSendCmdParam1(1u, CMD_OPENDOOR, oi);
      if ( !deltaload )
        PlaySfxLoc(7, object[oi]._ox, object[oi]._oy);
      ObjSetMicro(x, dy, 395);
      dArch[x][dy] = 8;
      objects_set_door_piece(x, dy - 1);
      object[oi]._oAnimFrame += 2;
      object[oi]._oPreFlag = 1;
      DoorSet(oi, x - 1, dy);
      object[oi]._oVar4 = 1;
      object[oi]._oSelFlag = 2;
      RedoPlayerVision();
    }
  }
}

//----- (004616BA) --------------------------------------------------------
void __fastcall OperateL1LDoor(int pnum, int oi, unsigned __int8 sendflag)
{
  int dy; // [esp+14h] [ebp-Ch]
  bool v6; // [esp+18h] [ebp-8h]
  int v7; // [esp+18h] [ebp-8h]
  int v8; // [esp+1Ch] [ebp-4h]

  if ( object[oi]._oVar4 == 2 )
  {
    if ( !deltaload )
      PlaySfxLoc(6, object[oi]._ox, object[oi]._oy);
  }
  else
  {
    v8 = object[oi]._ox;
    dy = object[oi]._oy;
    if ( object[oi]._oVar4 )
    {
      if ( !deltaload )
        PlaySfxLoc(6, object[oi]._ox, object[oi]._oy);
      if ( dItem[v8][dy] )
        v6 = 0;
      else
        v6 = dMonster[v8][dy] == 0;
      if ( dDead[v8][dy] )
        v7 = 0;
      else
        v7 = v6;
      if ( v7 )
      {
        if ( myplr == pnum && sendflag )
          NetSendCmdParam1(1u, 0x2Fu, oi);
        object[oi]._oVar4 = 0;
        object[oi]._oSelFlag = 3;
        ObjSetMicro(v8, dy, object[oi]._oVar1);
        if ( object[oi]._oVar2 == 50 )
        {
          if ( dPiece[v8][dy - 1] == 396 )
            ObjSetMicro(v8, dy - 1, 412);
          else
            ObjSetMicro(v8, dy - 1, object[oi]._oVar2);
        }
        else
        {
          ObjSetMicro(v8, dy - 1, object[oi]._oVar2);
        }
        object[oi]._oAnimFrame -= 2;
        object[oi]._oPreFlag = 0;
        RedoPlayerVision();
      }
      else
      {
        object[oi]._oVar4 = 2;
      }
    }
    else
    {
      if ( myplr == pnum && sendflag )
        NetSendCmdParam1(1u, 0x2Eu, oi);
      if ( !deltaload )
        PlaySfxLoc(7, object[oi]._ox, object[oi]._oy);
      if ( object[oi]._oVar1 == 214 )
        ObjSetMicro(v8, dy, 408);
      else
        ObjSetMicro(v8, dy, 393);
      dArch[v8][dy] = 7;
      objects_set_door_piece(v8 - 1, dy);
      object[oi]._oAnimFrame += 2;
      object[oi]._oPreFlag = 1;
      DoorSet(oi, v8, dy - 1);
      object[oi]._oVar4 = 1;
      object[oi]._oSelFlag = 2;
      RedoPlayerVision();
    }
  }
}

//----- (00461AA3) --------------------------------------------------------
void __fastcall OperateL2RDoor(int pnum, int oi, unsigned __int8 sendflag)
{
  int dy; // [esp+14h] [ebp-Ch]
  bool v6; // [esp+18h] [ebp-8h]
  int v7; // [esp+18h] [ebp-8h]
  int v8; // [esp+1Ch] [ebp-4h]

  if ( object[oi]._oVar4 == 2 )
  {
    if ( !deltaload )
      PlaySfxLoc(6, object[oi]._ox, object[oi]._oy);
  }
  else
  {
    v8 = object[oi]._ox;
    dy = object[oi]._oy;
    if ( object[oi]._oVar4 )
    {
      if ( !deltaload )
        PlaySfxLoc(6, object[oi]._ox, object[oi]._oy);
      if ( dItem[v8][dy] )
        v6 = 0;
      else
        v6 = dMonster[v8][dy] == 0;
      if ( dDead[v8][dy] )
        v7 = 0;
      else
        v7 = v6;
      if ( v7 )
      {
        if ( myplr == pnum && sendflag )
          NetSendCmdParam1(1u, 0x2Fu, oi);
        object[oi]._oVar4 = 0;
        object[oi]._oSelFlag = 3;
        ObjSetMicro(v8, dy, 540);
        object[oi]._oAnimFrame -= 2;
        object[oi]._oPreFlag = 0;
        RedoPlayerVision();
      }
      else
      {
        object[oi]._oVar4 = 2;
      }
    }
    else
    {
      if ( myplr == pnum && sendflag )
        NetSendCmdParam1(1u, 0x2Eu, oi);
      if ( !deltaload )
        PlaySfxLoc(7, object[oi]._ox, object[oi]._oy);
      ObjSetMicro(v8, dy, 17);
      object[oi]._oAnimFrame += 2;
      object[oi]._oPreFlag = 1;
      object[oi]._oVar4 = 1;
      object[oi]._oSelFlag = 2;
      RedoPlayerVision();
    }
  }
}

//----- (00461D8B) --------------------------------------------------------
void __fastcall OperateL2LDoor(int pnum, int oi, unsigned __int8 sendflag)
{
  int dy; // [esp+14h] [ebp-Ch]
  bool v6; // [esp+18h] [ebp-8h]
  int v7; // [esp+18h] [ebp-8h]
  int v8; // [esp+1Ch] [ebp-4h]

  if ( object[oi]._oVar4 == 2 )
  {
    if ( !deltaload )
      PlaySfxLoc(6, object[oi]._ox, object[oi]._oy);
  }
  else
  {
    v8 = object[oi]._ox;
    dy = object[oi]._oy;
    if ( object[oi]._oVar4 )
    {
      if ( !deltaload )
        PlaySfxLoc(6, object[oi]._ox, object[oi]._oy);
      if ( dItem[v8][dy] )
        v6 = 0;
      else
        v6 = dMonster[v8][dy] == 0;
      if ( dDead[v8][dy] )
        v7 = 0;
      else
        v7 = v6;
      if ( v7 )
      {
        if ( myplr == pnum && sendflag )
          NetSendCmdParam1(1u, 0x2Fu, oi);
        object[oi]._oVar4 = 0;
        object[oi]._oSelFlag = 3;
        ObjSetMicro(v8, dy, 538);
        object[oi]._oAnimFrame -= 2;
        object[oi]._oPreFlag = 0;
        RedoPlayerVision();
      }
      else
      {
        object[oi]._oVar4 = 2;
      }
    }
    else
    {
      if ( myplr == pnum && sendflag )
        NetSendCmdParam1(1u, 0x2Eu, oi);
      if ( !deltaload )
        PlaySfxLoc(7, object[oi]._ox, object[oi]._oy);
      ObjSetMicro(v8, dy, 13);
      object[oi]._oAnimFrame += 2;
      object[oi]._oPreFlag = 1;
      object[oi]._oVar4 = 1;
      object[oi]._oSelFlag = 2;
      RedoPlayerVision();
    }
  }
}

//----- (00462073) --------------------------------------------------------
void __fastcall MonstCheckDoors(int m)
{
  signed int v1; // [esp+10h] [ebp-1Ch]
  int oi; // [esp+14h] [ebp-18h]
  int i; // [esp+18h] [ebp-14h]
  int v4; // [esp+1Ch] [ebp-10h]
  int v5; // [esp+20h] [ebp-Ch]
  int v6; // [esp+24h] [ebp-8h]
  int v7; // [esp+24h] [ebp-8h]
  int v8; // [esp+28h] [ebp-4h]
  int v9; // [esp+28h] [ebp-4h]

  v5 = monster[m]._mx;
  v4 = monster[m]._my;
  v1 = 0;
  if ( dungeon[39][112 * (v5 - 1) + 39 + v4] )
    v1 = 1;
  if ( !v1 && dungeon[39][112 * v5 + 39 + v4] )
    v1 = 1;
  if ( !v1 && dungeon[39][112 * (v5 + 1) + 39 + v4] )
    v1 = 1;
  if ( !v1 && dObject[v5 - 1][v4] )
    v1 = 1;
  if ( !v1 && dObject[v5 + 1][v4] )
    v1 = 1;
  if ( !v1 && dObject[v5 - 1][v4 + 1] )
    v1 = 1;
  if ( !v1 && dObject[v5][v4 + 1] )
    v1 = 1;
  if ( !v1 && dObject[v5 + 1][v4 + 1] )
    v1 = 1;
  if ( v1 )
  {
    for ( i = 0; i < nobjects; ++i )
    {
      oi = objectactive[i];
      if ( (object[oi]._otype == OBJ_L1LDOOR || object[oi]._otype == OBJ_L1RDOOR) && !object[oi]._oVar4 )
      {
        v8 = abs(object[oi]._ox - v5);
        v6 = abs(object[oi]._oy - v4);
        if ( v8 == 1 && v6 <= 1 && object[oi]._otype == OBJ_L1LDOOR )
          OperateL1LDoor(myplr, oi, 1u);
        if ( v8 <= 1 && v6 == 1 && object[oi]._otype == OBJ_L1RDOOR )
          OperateL1RDoor(myplr, oi, 1u);
      }
      if ( (object[oi]._otype == OBJ_L2LDOOR || object[oi]._otype == OBJ_L2RDOOR) && !object[oi]._oVar4 )
      {
        v9 = abs(object[oi]._ox - v5);
        v7 = abs(object[oi]._oy - v4);
        if ( v9 == 1 && v7 <= 1 && object[oi]._otype == OBJ_L2LDOOR )
          OperateL2LDoor(myplr, oi, 1u);
        if ( v9 <= 1 && v7 == 1 && object[oi]._otype == OBJ_L2RDOOR )
          OperateL2RDoor(myplr, oi, 1u);
      }
    }
  }
}

//----- (00462482) --------------------------------------------------------
void __fastcall ObjChangeMap(int x1, int y1, int x2, int y2)
{
  int y; // [esp+14h] [ebp-8h]
  int x; // [esp+18h] [ebp-4h]

  for ( y = y1; y <= y2; ++y )
  {
    for ( x = x1; x <= x2; ++x )
      ObjSetMini(x, y, (unsigned __int8)pdungeon[x][y]);
  }
  if ( leveltype == 1 )
  {
    ObjL1Special(2 * x1 + 16, 2 * y1 + 16, 2 * x2 + 17, 2 * y2 + 17);
    AddL1Objs(2 * x1 + 16, 2 * y1 + 16, 2 * x2 + 17, 2 * y2 + 17);
  }
  if ( leveltype == 2 )
  {
    ObjL2Special(2 * x1 + 16, 2 * y1 + 16, 2 * x2 + 17, 2 * y2 + 17);
    AddL2Objs(2 * x1 + 16, 2 * y1 + 16, 2 * x2 + 17, 2 * y2 + 17);
  }
}

//----- (004625C5) --------------------------------------------------------
void __fastcall OperateL1Door(int pnum, int i, unsigned __int8 sendflag)
{
  int v5; // [esp+14h] [ebp-8h]
  int v6; // [esp+18h] [ebp-4h]

  v6 = abs(object[i]._ox - plr[pnum].WorldX);
  v5 = abs(object[i]._oy - plr[pnum].WorldY);
  if ( v6 == 1 && v5 <= 1 && object[i]._otype == 1 )
    OperateL1LDoor(pnum, i, sendflag);
  if ( v6 <= 1 && v5 == 1 && object[i]._otype == 2 )
    OperateL1RDoor(pnum, i, sendflag);
}

//----- (004626C6) --------------------------------------------------------
void __fastcall OperateLever(int pnum, int i)
{
  if ( object[i]._oSelFlag )
  {
    if ( !deltaload )
      PlaySfxLoc(35, object[i]._ox, object[i]._oy);
    object[i]._oSelFlag = 0;
    ++object[i]._oAnimFrame;
    ObjChangeMap(object[i]._oVar1, object[i]._oVar2, object[i]._oVar3, object[i]._oVar4);
    if ( myplr == pnum )
      NetSendCmdParam1(0, 0x30u, i);
  }
}

//----- (004627BC) --------------------------------------------------------
void __fastcall OperateBook(int pnum, int i)
{
  QWORD *v2; // edx

  if ( object[i]._oSelFlag )
  {
    object[i]._oSelFlag = 0;
    ++object[i]._oAnimFrame;
    v2 = &plr[myplr]._pMemSpells;
    *(_DWORD *)v2 |= 0x20000u;
    *((_DWORD *)v2 + 1) = *((_DWORD *)v2 + 1);
    plr[myplr]._pSplLvl[18] = 1;
    quests[3]._qactive = 3;
    InitQTextMsg(10);
    object[i]._oVar1 = 150;
    object[i]._oVar2 = pnum;
  }
}

//----- (004628B2) --------------------------------------------------------
void __fastcall OperateBookLever(int pnum, int i)
{
  if ( object[i]._oSelFlag )
  {
    if ( object[i]._otype == OBJ_BLINDBOOK )
    {
      quests[8]._qactive = 2;
      quests[8]._qvar1 = 23;
      CreateItem(3, 2 * setpc_x + 21, 2 * setpc_y + 21);
    }
    if ( object[i]._otype == OBJ_BLOODBOOK )
    {
      quests[9]._qactive = 2;
      quests[9]._qvar1 = 24;
    }
    object[i]._oSelFlag = 0;
    ++object[i]._oAnimFrame;
    ObjChangeMap(object[i]._oVar1, object[i]._oVar2, object[i]._oVar3, object[i]._oVar4);
    InitQTextMsg(object[i]._oVar7);
    if ( myplr == pnum )
      NetSendCmdParam1(0, 0x30u, i);
  }
}

//----- (00462A00) --------------------------------------------------------
void __fastcall OperateSChambBk(int pnum, int i)
{
  if ( object[i]._oSelFlag )
  {
    object[i]._oSelFlag = 0;
    ++object[i]._oAnimFrame;
    quests[3]._qactive = 2;
    InitQTextMsg(9);
    object[i]._oVar1 = 150;
    object[i]._oVar2 = pnum;
  }
}

//----- (00462A90) --------------------------------------------------------
void __fastcall OperateChest(int pnum, int i, unsigned __int8 sendmsg)
{
  int v3; // [esp+Ch] [ebp-18h]
  int mitype; // [esp+18h] [ebp-Ch]
  int j; // [esp+1Ch] [ebp-8h]
  int midir; // [esp+20h] [ebp-4h]

  if ( object[i]._oSelFlag )
  {
    if ( !deltaload )
      PlaySfxLoc(5, object[i]._ox, object[i]._oy);
    object[i]._oSelFlag = 0;
    object[i]._oAnimFrame += 2;
    if ( !deltaload )
    {
      SetRndSeed(object[i]._oRndSeed);
      for ( j = 0; object[i]._oVar1 > j; ++j )
      {
        if ( object[i]._oVar2 )
          CreateRndItem(object[i]._ox, object[i]._oy, 0, sendmsg, 0);
        else
          CreateRndUseful(pnum, object[i]._ox, object[i]._oy, sendmsg);
      }
      if ( object[i]._oTrapFlag && object[i]._otype >= 68 && object[i]._otype <= 70 )
      {
        midir = GetDirection(object[i]._ox, object[i]._oy, plr[pnum].WorldX, plr[pnum].WorldY);
        v3 = object[i]._oVar4;
        if ( v3 )
        {
          if ( v3 == 1 )
          {
            AddMissile(object[i]._ox, object[i]._oy, plr[pnum].WorldX, plr[pnum].WorldY, midir, 27, 1, -1, 0);
          }
          else if ( v3 == 2 )
          {
            AddMissile(object[i]._ox, object[i]._oy, plr[pnum].WorldX, plr[pnum].WorldY, midir, 42, 1, -1, 0);
          }
          else
          {
            AddMissile(object[i]._ox, object[i]._oy, plr[pnum].WorldX, plr[pnum].WorldY, midir, mitype, 1, -1, 0);
          }
        }
        else
        {
          AddMissile(object[i]._ox, object[i]._oy, plr[pnum].WorldX, plr[pnum].WorldY, midir, 0, 1, -1, 0);
        }
        object[i]._oTrapFlag = 0;
      }
      if ( myplr == pnum )
        NetSendCmdParam2(0, 0x31u, pnum, i);
    }
  }
}

//----- (00462DA0) --------------------------------------------------------
void __fastcall OperateTrapLvr(int i)
{
  int v1; // [esp+10h] [ebp-8h]
  int v2; // [esp+10h] [ebp-8h]
  int j; // [esp+14h] [ebp-4h]
  int k; // [esp+14h] [ebp-4h]

  if ( object[i]._oAnimFrame == 1 )
  {
    ++object[i]._oAnimFrame;
    for ( j = 0; j < nobjects; ++j )
    {
      v1 = objectactive[j];
      if ( object[i]._oVar2 == object[v1]._otype && object[v1]._oVar1 == object[i]._oVar1 )
      {
        object[v1]._oVar2 = 1;
        object[v1]._oAnimFlag = 0;
      }
    }
  }
  else
  {
    --object[i]._oAnimFrame;
    for ( k = 0; k < nobjects; ++k )
    {
      v2 = objectactive[k];
      if ( object[i]._oVar2 == object[v2]._otype && object[v2]._oVar1 == object[i]._oVar1 )
      {
        object[v2]._oVar2 = 0;
        if ( object[v2]._oVar4 )
          object[v2]._oAnimFlag = 1;
      }
    }
  }
}

//----- (00462F4F) --------------------------------------------------------
void __fastcall OperateSarc(int pnum, int i, unsigned __int8 sendmsg)
{
  if ( object[i]._oSelFlag )
  {
    if ( !deltaload )
      PlaySfxLoc(38, object[i]._ox, object[i]._oy);
    if ( deltaload )
    {
      object[i]._oSelFlag = 0;
      object[i]._oAnimFrame = object[i]._oAnimLen;
    }
    else
    {
      object[i]._oSelFlag = 0;
      object[i]._oAnimFlag = 1;
      object[i]._oAnimDelay = 3;
      SetRndSeed(object[i]._oRndSeed);
      if ( object[i]._oVar1 <= 2 )
        CreateRndItem(object[i]._ox, object[i]._oy, 0, sendmsg, 0);
      if ( object[i]._oVar1 >= 8 )
        SpawnSkeleton(object[i]._oVar2, object[i]._ox, object[i]._oy);
      if ( myplr == pnum )
        NetSendCmdParam1(0, 0x30u, i);
    }
  }
}

//----- (00463106) --------------------------------------------------------
void __fastcall OperateL2Door(int pnum, int i, unsigned __int8 sendflag)
{
  int v5; // [esp+14h] [ebp-8h]
  int v6; // [esp+18h] [ebp-4h]

  v6 = abs(object[i]._ox - plr[pnum].WorldX);
  v5 = abs(object[i]._oy - plr[pnum].WorldY);
  if ( v6 == 1 && v5 <= 1 && object[i]._otype == 42 )
    OperateL2LDoor(pnum, i, sendflag);
  if ( v6 <= 1 && v5 == 1 && object[i]._otype == 43 )
    OperateL2RDoor(pnum, i, sendflag);
}

//----- (00463207) --------------------------------------------------------
void __fastcall TryDisarm(int pnum, int i)
{
  int v2; // ST1C_4
  int v5; // [esp+14h] [ebp-14h]
  int j; // [esp+18h] [ebp-10h]
  signed int v7; // [esp+20h] [ebp-8h]

  if ( myplr == pnum )
    j_SetCursor(1);
  if ( object[i]._oTrapFlag )
  {
    v2 = 2 * plr[pnum]._pDexterity - 5 * currlevel;
    if ( random(154, 100) <= v2 )
    {
      for ( j = 0; j < nobjects; ++j )
      {
        v5 = objectactive[j];
        v7 = 0;
        if ( object[v5]._otype == 53 )
          v7 = 1;
        if ( object[v5]._otype == 54 )
          v7 = 1;
        if ( v7 )
        {
          if ( dObject[object[v5]._oVar1][object[v5]._oVar2] - 1 == i )
          {
            object[v5]._oVar4 = 1;
            object[i]._oTrapFlag = 0;
          }
        }
      }
    }
  }
}

//----- (00463387) --------------------------------------------------------
void __fastcall OperateShrine(int pnum, int i, int sType)
{
  int v3; // ST5C_4
  int v4; // ST5C_4
  int v5; // ST5C_4
  QWORD *v6; // edx
  int v7; // ST5C_4
  int v8; // ST58_4
  int v9; // ST5C_4
  signed __int64 v12; // [esp+18h] [ebp-2Ch]
  signed __int64 v13; // [esp+18h] [ebp-2Ch]
  signed __int64 v14; // [esp+18h] [ebp-2Ch]
  int v15; // [esp+28h] [ebp-1Ch]
  signed int v16; // [esp+28h] [ebp-1Ch]
  signed __int64 v17; // [esp+2Ch] [ebp-18h]
  __int64 v18; // [esp+2Ch] [ebp-18h]
  int v19; // [esp+34h] [ebp-10h]
  int v20; // [esp+34h] [ebp-10h]
  int j; // [esp+34h] [ebp-10h]
  signed int k; // [esp+34h] [ebp-10h]
  signed int v23; // [esp+34h] [ebp-10h]
  signed int m; // [esp+34h] [ebp-10h]
  int n; // [esp+34h] [ebp-10h]
  int ii; // [esp+34h] [ebp-10h]
  int jj; // [esp+34h] [ebp-10h]
  int kk; // [esp+34h] [ebp-10h]
  signed int ll; // [esp+34h] [ebp-10h]
  int v30; // [esp+38h] [ebp-Ch]
  signed int v31; // [esp+38h] [ebp-Ch]
  int v2; // [esp+3Ch] [ebp-8h]
  int v2a; // [esp+3Ch] [ebp-8h]
  int v2b; // [esp+3Ch] [ebp-8h]
  int v2c; // [esp+3Ch] [ebp-8h]
  int l; // [esp+40h] [ebp-4h]
  int la; // [esp+40h] [ebp-4h]
  int lb; // [esp+40h] [ebp-4h]
  int lc; // [esp+40h] [ebp-4h]
  int ld; // [esp+40h] [ebp-4h]

  if ( object[i]._oSelFlag )
  {
    SetRndSeed(object[i]._oRndSeed);
    if ( !deltaload )
      PlaySfxLoc(36, object[i]._ox, object[i]._oy);
    object[i]._oSelFlag = 0;
    object[i]._oAnimFlag = 1;
    object[i]._oAnimDelay = 1;
    switch ( object[i]._oVar1 )
    {
      case 0:
        if ( !deltaload )
        {
          v19 = random(155, 4);
          if ( v19 )
            l = -1;
          else
            l = 5;
          if ( v19 == 1 )
            v2 = 5;
          else
            v2 = -1;
          if ( v19 == 2 )
            v31 = 5;
          else
            v31 = -1;
          if ( v19 == 3 )
            v16 = 5;
          else
            v16 = -1;
          ModifyPlrStr(pnum, l);
          ModifyPlrMag(pnum, v2);
          ModifyPlrDex(pnum, v31);
          ModifyPlrVit(pnum, v16);
          if ( myplr == pnum )
            InitDiabloMsg(8);
          goto LABEL_181;
        }
        break;
      case 1:
        if ( !deltaload )
        {
          v3 = plr[pnum]._pLevel << 7;
          plr[pnum]._pHitPoints += v3;
          plr[pnum]._pHPBase += v3;
          if ( plr[pnum]._pHitPoints > plr[pnum]._pMaxHP )
          {
            plr[pnum]._pHitPoints = plr[pnum]._pMaxHP;
            plr[pnum]._pHPBase = plr[pnum]._pMaxHPBase;
          }
          v4 = plr[pnum]._pLevel << 7;
          plr[pnum]._pMana -= v4;
          plr[pnum]._pManaBase -= v4;
          if ( plr[pnum]._pMana < 0 )
          {
            plr[pnum]._pManaBase -= plr[pnum]._pMana;
            plr[pnum]._pMana = 0;
          }
          if ( myplr == pnum )
          {
            drawpanflag = 255;
            InitDiabloMsg(9);
          }
          goto LABEL_181;
        }
        break;
      case 2:
        if ( !deltaload )
        {
          la = 0;
          if ( plr[pnum].InvBody[0]._itype != -1 )
            la = 1;
          if ( plr[pnum].InvBody[6]._itype != -1 )
            ++la;
          if ( plr[pnum].InvBody[4]._itype != -1 )
            ++la;
          if ( plr[pnum].InvBody[5]._itype != -1 )
            ++la;
          if ( la > 1 )
          {
            v20 = random(156, la) + 1;
            if ( plr[pnum].InvBody[0]._itype != -1 && !--v20 )
              plr[pnum].InvBody[0]._itype = -1;
            if ( plr[pnum].InvBody[6]._itype != -1 && !--v20 )
              plr[pnum].InvBody[6]._itype = -1;
            if ( plr[pnum].InvBody[4]._itype != -1 && !--v20 )
              plr[pnum].InvBody[4]._itype = -1;
            if ( plr[pnum].InvBody[5]._itype != -1 && v20 == 1 )
              plr[pnum].InvBody[5]._itype = -1;
            if ( plr[pnum].InvBody[0]._itype != -1 )
            {
              plr[pnum].InvBody[0]._iDurability += 10;
              plr[pnum].InvBody[0]._iMaxDur += 10;
            }
            if ( plr[pnum].InvBody[6]._itype != -1 )
            {
              plr[pnum].InvBody[6]._iDurability += 10;
              plr[pnum].InvBody[6]._iMaxDur += 10;
            }
            if ( plr[pnum].InvBody[4]._itype != -1 )
            {
              plr[pnum].InvBody[4]._iDurability += 10;
              plr[pnum].InvBody[4]._iMaxDur += 10;
            }
            if ( plr[pnum].InvBody[5]._itype != -1 )
            {
              plr[pnum].InvBody[5]._iDurability += 10;
              plr[pnum].InvBody[5]._iMaxDur += 10;
            }
            CalcPlrInv(pnum, 1);
          }
          if ( myplr == pnum )
            InitDiabloMsg(10);
          goto LABEL_181;
        }
        break;
      case 3:
        v2a = currlevel << 8;
        for ( j = 0; j < nummonsters; ++j )
        {
          v5 = monstactive[j];
          monster[v5]._mhitpoints += v2a;
          monster[v5]._mmaxhp += v2a;
          monster[v5].mArmorClass = 0;
        }
        if ( !deltaload )
        {
          if ( myplr == pnum )
            InitDiabloMsg(11);
          goto LABEL_181;
        }
        break;
      case 4:
        if ( !deltaload && myplr == pnum )
        {
          if ( plr[pnum]._pGold > 1 )
          {
            AddPlrExperience(pnum, currlevel, 1000 * currlevel * currlevel);
            TakePlrsMoney(plr[pnum]._pGold - 1);
          }
          InitDiabloMsg(12);
          goto LABEL_181;
        }
        break;
      case 5:
        if ( !deltaload && myplr == pnum )
        {
          v17 = 0i64;
          v12 = 1i64;
          for ( k = 1; k <= 37; ++k )
          {
            if ( v12 & plr[pnum]._pMemSpells )
              ++v17;
            v12 *= 2i64;
          }
          if ( v17 > 1 )
          {
            v18 = random(157, 74) + 1;
            v23 = 1;
            v13 = 1i64;
            while ( v18 >= 0 && (SHIDWORD(v18) > 0 || (_DWORD)v18) )
            {
              if ( v13 & plr[pnum]._pMemSpells )
                --v18;
              if ( v18 >= 0 && (SHIDWORD(v18) > 0 || (_DWORD)v18) )
              {
                if ( ++v23 <= 37 )
                {
                  v13 *= 2i64;
                }
                else
                {
                  v23 = 1;
                  v13 = 1i64;
                }
              }
            }
            if ( plr[pnum]._pRSplType == 1 && plr[pnum]._pRSpell == v23 )
            {
              plr[pnum]._pRSpell = -1;
              plr[pnum]._pRSplType = 4;
              drawpanflag = 255;
            }
            plr[pnum]._pMemSpells ^= v13;
            plr[pnum]._pSplLvl[v23] = 0;
            v14 = 1i64;
            for ( m = 1; m <= 37; ++m )
            {
              if ( v14 & plr[pnum]._pMemSpells )
                ++plr[pnum]._pSplLvl[m];
              v14 *= 2i64;
            }
          }
          InitDiabloMsg(13);
          goto LABEL_181;
        }
        break;
      case 6:
        for ( n = 0; n < nobjects; ++n )
        {
          lb = objectactive[n];
          if ( (object[lb]._otype == 5 || object[lb]._otype == 6 || object[lb]._otype == 7) && !object[lb]._oSelFlag )
          {
            object[lb]._oRndSeed = GetRndSeed();
            object[lb]._oSelFlag = 1;
            object[lb]._oAnimFrame -= 2;
          }
        }
        if ( !deltaload )
        {
          if ( myplr == pnum )
            InitDiabloMsg(14);
          goto LABEL_181;
        }
        break;
      case 7:
        for ( ii = 0; ii < nummonsters; ++ii )
          monster[monstactive[ii]].mMagicRes |= 0x10u;
        if ( !deltaload && myplr == pnum )
        {
          v6 = &plr[pnum]._pMemSpells;
          *(_DWORD *)v6 |= 1u;
          *((_DWORD *)v6 + 1) = *((_DWORD *)v6 + 1);
          plr[pnum]._pSplLvl[1] = 5;
          InitDiabloMsg(15);
          goto LABEL_181;
        }
        break;
      case 8:
        if ( !deltaload && myplr == pnum )
        {
          for ( jj = random(158, 4) + 4; jj > 0; --jj )
          {
            lc = random(158, 4);
            do
              v2b = random(158, 4);
            while ( lc == v2b );
            if ( !lc )
              v30 = plr[pnum]._pBaseStr;
            if ( lc == 1 )
              v30 = plr[pnum]._pBaseMag;
            if ( lc == 2 )
              v30 = plr[pnum]._pBaseDex;
            if ( lc == 3 )
              v30 = plr[pnum]._pBaseVit;
            if ( !v2b )
            {
              v15 = plr[pnum]._pBaseStr;
              ModifyPlrStr(pnum, v30 - v15);
            }
            if ( v2b == 1 )
            {
              v15 = plr[pnum]._pBaseMag;
              ModifyPlrMag(pnum, v30 - v15);
            }
            if ( v2b == 2 )
            {
              v15 = plr[pnum]._pBaseDex;
              ModifyPlrDex(pnum, v30 - v15);
            }
            if ( v2b == 3 )
            {
              v15 = plr[pnum]._pBaseVit;
              ModifyPlrVit(pnum, v30 - v15);
            }
            if ( !lc )
              ModifyPlrStr(pnum, v15 - v30);
            if ( lc == 1 )
              ModifyPlrMag(pnum, v15 - v30);
            if ( lc == 2 )
              ModifyPlrDex(pnum, v15 - v30);
            if ( lc == 3 )
              ModifyPlrVit(pnum, v15 - v30);
          }
          plr[pnum]._pMaxHP += 1280;
          plr[pnum]._pHitPoints += 1280;
          plr[pnum]._pMaxHPBase += 1280;
          plr[pnum]._pHPBase += 1280;
          if ( !(plr[pnum]._pIFlags & 0x8000000) )
          {
            plr[pnum]._pMaxMana += 1280;
            plr[pnum]._pMana += 1280;
            plr[pnum]._pMaxManaBase += 1280;
            plr[pnum]._pManaBase += 1280;
          }
          drawpanflag = 255;
          InitDiabloMsg(16);
          goto LABEL_181;
        }
        break;
      case 9:
        for ( kk = 0; kk < nummonsters; ++kk )
        {
          v7 = monstactive[kk];
          monster[v7].mHit = 100;
          monster[v7].mHit2 = 100;
          monster[v7].mMinDamage = (signed int)monster[v7].mMinDamage >> 1;
          monster[v7].mMaxDamage = (signed int)monster[v7].mMaxDamage >> 1;
          monster[v7].mMinDamage2 = (signed int)monster[v7].mMinDamage2 >> 1;
          monster[v7].mMaxDamage2 = (signed int)monster[v7].mMaxDamage2 >> 1;
        }
        if ( !deltaload && myplr == pnum )
        {
          InitDiabloMsg(17);
          goto LABEL_181;
        }
        break;
      case 0xA:
        if ( !deltaload )
        {
          pfile_436A75_reverse_name(pnum);
          ModifyPlrMag(pnum, 2);
          if ( myplr == pnum )
            InitDiabloMsg(18);
          goto LABEL_181;
        }
        break;
      case 0xB:
        if ( !deltaload )
        {
          do
          {
            do
            {
              ld = random(159, 112);
              v2c = random(159, 112);
            }
            while ( nSolidTable[dPiece[ld][v2c]] );
          }
          while ( dObject[ld][v2c] || dMonster[ld][v2c] );
          AddMissile(plr[pnum].WorldX, plr[pnum].WorldY, ld, v2c, plr[pnum]._pdir, 3, 0, pnum, 0);
          goto LABEL_181;
        }
        break;
      case 0xC:
        if ( !deltaload && myplr == pnum )
        {
          for ( ll = 0; ll < 40; ++ll )
          {
            if ( !plr[pnum].InvGrid[ll] )
            {
              v8 = 5 * currlevel + random(160, 10 * currlevel);
              v9 = plr[pnum]._pNumInv;
              qmemcpy(&plr[pnum].InvList[v9], &golditem, sizeof(plr[pnum].InvList[v9]));
              ++plr[pnum]._pNumInv;
              plr[pnum].InvGrid[ll] = plr[pnum]._pNumInv;
              plr[pnum].InvList[v9]._ivalue = v8;
              plr[pnum]._pGold += v8;
              SetGoldCurs(pnum, v9);
            }
          }
          InitDiabloMsg(19);
          goto LABEL_181;
        }
        break;
      default:
LABEL_181:
        if ( myplr == pnum )
          NetSendCmdParam2(0, 0x31u, pnum, i);
        break;
    }
  }
}

//----- (00464A21) --------------------------------------------------------
void __fastcall OperateSkelBook(int pnum, int i, unsigned __int8 sendmsg)
{
  if ( object[i]._oSelFlag )
  {
    if ( !deltaload )
      PlaySfxLoc(31, object[i]._ox, object[i]._oy);
    object[i]._oSelFlag = 0;
    object[i]._oAnimFrame += 2;
    if ( !deltaload )
    {
      SetRndSeed(object[i]._oRndSeed);
      if ( random(161, 5) )
        CreateTypeItem(object[i]._ox, object[i]._oy, 0, 0, 21, sendmsg, 0);
      else
        CreateTypeItem(object[i]._ox, object[i]._oy, 0, 0, 24, sendmsg, 0);
      if ( myplr == pnum )
        NetSendCmdParam1(0, 0x30u, i);
    }
  }
}

//----- (00464B78) --------------------------------------------------------
void __fastcall OperateBookCase(int pnum, int i, unsigned __int8 sendmsg)
{
  if ( object[i]._oSelFlag )
  {
    if ( !deltaload )
      PlaySfxLoc(31, object[i]._ox, object[i]._oy);
    object[i]._oSelFlag = 0;
    object[i]._oAnimFrame -= 2;
    if ( !deltaload )
    {
      SetRndSeed(object[i]._oRndSeed);
      CreateTypeItem(object[i]._ox, object[i]._oy, 0, 0, 24, sendmsg, 0);
      if ( myplr == pnum )
        NetSendCmdParam1(0, 0x30u, i);
    }
  }
}

//----- (00464C82) --------------------------------------------------------
void __fastcall objects_464C82_OperateBloodftn(int pnum, int i)
{
  if ( !deltaload )
  {
    if ( plr[pnum]._pMana <= 512 || plr[pnum]._pHitPoints == plr[pnum]._pMaxHP )
    {
      if ( !deltaload )
        PlaySfxLoc(29, object[i]._ox, object[i]._oy);
    }
    else
    {
      if ( !deltaload )
        PlaySfxLoc(36, object[i]._ox, object[i]._oy);
      plr[pnum]._pMana -= 512;
      plr[pnum]._pManaBase -= 512;
      plr[pnum]._pHitPoints += 512;
      plr[pnum]._pHPBase += 512;
      if ( plr[pnum]._pHitPoints > plr[pnum]._pMaxHP )
      {
        plr[pnum]._pHitPoints = plr[pnum]._pMaxHP;
        plr[pnum]._pHPBase = plr[pnum]._pMaxHPBase;
      }
      drawpanflag = 255;
    }
  }
}

//----- (00464ECB) --------------------------------------------------------
void __fastcall OperateDecap(int pnum, int i, unsigned __int8 sendmsg)
{
  if ( object[i]._oSelFlag )
  {
    object[i]._oSelFlag = 0;
    if ( !deltaload )
    {
      SetRndSeed(object[i]._oRndSeed);
      CreateRndItem(object[i]._ox, object[i]._oy, 0, sendmsg, 0);
      if ( myplr == pnum )
        NetSendCmdParam1(0, 0x30u, i);
    }
  }
}

//----- (00464F88) --------------------------------------------------------
void __fastcall OperateObject(int pnum, int i, unsigned __int8 TeleFlag)
{
  int v3; // [esp+0h] [ebp-1Ch]
  bool sendmsg; // [esp+18h] [ebp-4h]

  sendmsg = myplr == pnum;
  switch ( object[i]._otype )
  {
    case OBJ_L1LDOOR:
    case OBJ_L1RDOOR:
      if ( TeleFlag )
      {
        if ( object[i]._otype == 1 )
          OperateL1LDoor(pnum, i, 1u);
        if ( object[i]._otype == 2 )
          OperateL1RDoor(pnum, i, 1u);
      }
      else if ( myplr == pnum )
      {
        OperateL1Door(pnum, i, 1u);
      }
      break;
    case OBJ_LEVER:
    case OBJ_SWITCHSKL:
      OperateLever(pnum, i);
      break;
    case OBJ_CHEST1:
    case OBJ_CHEST2:
    case OBJ_CHEST3:
    case OBJ_TCHEST1:
    case OBJ_TCHEST2:
    case OBJ_TCHEST3:
      OperateChest(pnum, i, sendmsg);
      break;
    case OBJ_BOOK2L:
      OperateBook(pnum, i);
      break;
    case OBJ_BOOK2R:
      OperateSChambBk(pnum, i);
      break;
    case OBJ_L2LDOOR:
    case OBJ_L2RDOOR:
      if ( TeleFlag )
      {
        if ( object[i]._otype == 42 )
          OperateL2LDoor(pnum, i, 1u);
        if ( object[i]._otype == 43 )
          OperateL2RDoor(pnum, i, 1u);
      }
      else if ( myplr == pnum )
      {
        OperateL2Door(pnum, i, 1u);
      }
      break;
    case OBJ_SARC:
      OperateSarc(pnum, i, sendmsg);
      break;
    case OBJ_FLAMELVR:
      OperateTrapLvr(i);
      break;
    case OBJ_BOOKLVR:
    case OBJ_BLINDBOOK:
    case OBJ_BLOODBOOK:
      OperateBookLever(pnum, i);
      break;
    case OBJ_SHRINEL:
    case OBJ_SHRINER:
    case OBJ_L3RDOOR:
    case OBJ_PURIFYINGFTN:
      OperateShrine(pnum, i, v3);
      break;
    case OBJ_SKELBOOK:
    case OBJ_BOOKSTAND:
      OperateSkelBook(pnum, i, sendmsg);
      break;
    case OBJ_BOOKCASEL:
    case OBJ_BOOKCASER:
    case OBJ_ARMORSTAND:
    case OBJ_ARMORSTANDN:
      OperateBookCase(pnum, i, sendmsg);
      break;
    case OBJ_BLOODFTN:
      objects_464C82_OperateBloodftn(pnum, i);
      break;
    case OBJ_DECAP:
      OperateDecap(pnum, i, sendmsg);
      break;
    default:
      return;
  }
}

//----- (00465264) --------------------------------------------------------
void __fastcall SyncOpL1Door(int pnum, int cmd, int i)
{
  signed int v3; // [esp+14h] [ebp-4h]

  if ( myplr != pnum )
  {
    v3 = 0;
    if ( cmd == 46 && !object[i]._oVar4 )
      v3 = 1;
    if ( cmd == 47 && object[i]._oVar4 == 1 )
      v3 = 1;
    if ( v3 )
    {
      if ( object[i]._otype == 1 )
        OperateL1LDoor(-1, i, 0);
      if ( object[i]._otype == 2 )
        OperateL1RDoor(-1, i, 0);
    }
  }
}

//----- (00465340) --------------------------------------------------------
void __fastcall SyncOpL2Door(int pnum, int cmd, int i)
{
  signed int v3; // [esp+14h] [ebp-4h]

  if ( myplr != pnum )
  {
    v3 = 0;
    if ( cmd == 46 && !object[i]._oVar4 )
      v3 = 1;
    if ( cmd == 47 && object[i]._oVar4 == 1 )
      v3 = 1;
    if ( v3 )
    {
      if ( object[i]._otype == 42 )
        OperateL2LDoor(-1, i, 0);
      if ( object[i]._otype == 43 )
        OperateL2RDoor(-1, i, 0);
    }
  }
}

//----- (0046541C) --------------------------------------------------------
void __fastcall SyncOpObject(int pnum, int cmd, int i)
{
  int v3; // [esp+0h] [ebp-18h]

  switch ( object[i]._otype )
  {
    case OBJ_L1LDOOR:
    case OBJ_L1RDOOR:
      SyncOpL1Door(pnum, cmd, i);
      break;
    case OBJ_LEVER:
    case OBJ_SWITCHSKL:
      OperateLever(pnum, i);
      break;
    case OBJ_CHEST1:
    case OBJ_CHEST2:
    case OBJ_CHEST3:
    case OBJ_TCHEST1:
    case OBJ_TCHEST2:
    case OBJ_TCHEST3:
      OperateChest(pnum, i, 0);
      break;
    case OBJ_L2LDOOR:
    case OBJ_L2RDOOR:
      SyncOpL2Door(pnum, cmd, i);
      break;
    case OBJ_SARC:
      OperateSarc(pnum, i, 0);
      break;
    case OBJ_BOOKLVR:
    case OBJ_BLINDBOOK:
    case OBJ_BLOODBOOK:
      OperateBookLever(pnum, i);
      break;
    case OBJ_SHRINEL:
    case OBJ_SHRINER:
    case OBJ_L3RDOOR:
    case OBJ_PURIFYINGFTN:
      OperateShrine(pnum, i, v3);
      break;
    case OBJ_SKELBOOK:
    case OBJ_BOOKSTAND:
      OperateSkelBook(pnum, i, 0);
      break;
    case OBJ_BOOKCASEL:
    case OBJ_BOOKCASER:
    case OBJ_ARMORSTAND:
    case OBJ_ARMORSTANDN:
      OperateBookCase(pnum, i, 0);
      break;
    case OBJ_DECAP:
      OperateDecap(pnum, i, 0);
      break;
    default:
      return;
  }
}

//----- (004655B7) --------------------------------------------------------
void __fastcall BreakCrux(int i)
{
  int v1; // [esp+10h] [ebp-10h]
  signed int v2; // [esp+14h] [ebp-Ch]
  int j; // [esp+18h] [ebp-8h]
  _object_id v4; // [esp+1Ch] [ebp-4h]

  object[i]._oAnimFlag = 1;
  object[i]._oAnimFrame = 1;
  object[i]._oAnimDelay = 1;
  object[i]._oSolidFlag = 1;
  object[i]._oMissFlag = 1;
  object[i]._oBreak = -1;
  object[i]._oSelFlag = 0;
  v2 = 1;
  for ( j = 0; j < nobjects; ++j )
  {
    v1 = objectactive[j];
    v4 = object[v1]._otype;
    if ( (v4 == OBJ_CRUX1 || v4 == OBJ_CRUX2 || v4 == OBJ_CRUX3)
      && object[i]._oVar8 == object[v1]._oVar8
      && object[v1]._oBreak != -1 )
    {
      v2 = 0;
    }
  }
  if ( v2 )
    ObjChangeMap(object[i]._oVar1, object[i]._oVar2, object[i]._oVar3, object[i]._oVar4);
}

//----- (00465752) --------------------------------------------------------
void __fastcall BreakBarrel(int pnum, int i, int dam, unsigned __int8 forcebreak, int sendmsg)
{
  int ia; // [esp+14h] [ebp-Ch]
  int j; // [esp+18h] [ebp-8h]
  int k; // [esp+1Ch] [ebp-4h]

  if ( object[i]._oSelFlag )
  {
    if ( forcebreak )
    {
      object[i]._oVar1 = 0;
    }
    else
    {
      object[i]._oVar1 -= dam;
      if ( myplr != pnum && object[i]._oVar1 <= 0 )
        object[i]._oVar1 = 1;
    }
    if ( object[i]._oVar1 <= 0 )
    {
      object[i]._oAnimFlag = 1;
      object[i]._oAnimFrame = 1;
      object[i]._oAnimDelay = 1;
      object[i]._oSolidFlag = 0;
      object[i]._oMissFlag = 1;
      object[i]._oBreak = -1;
      object[i]._oSelFlag = 0;
      object[i]._oPreFlag = 1;
      if ( deltaload )
      {
        object[i]._oAnimFrame = object[i]._oAnimLen;
        object[i]._oAnimCnt = 0;
        object[i]._oAnimDelay = 1000;
      }
      else
      {
        if ( object[i]._otype == 58 )
        {
          PlaySfxLoc(2, object[i]._ox, object[i]._oy);
          for ( j = object[i]._oy - 1; object[i]._oy + 1 >= j; ++j )
          {
            for ( k = object[i]._ox - 1; object[i]._ox + 1 >= k; ++k )
            {
              if ( dMonster[k][j] > 0 )
                MonsterTrapHit(dMonster[k][j] - 1, 1, 4, 0, 1, 0);
              if ( dPlayer[k][j] > 0 )
                PlayerMHit(dPlayer[k][j] - 1, -1, 0, 8, 16, 1, 0);
              if ( dObject[k][j] > 0 )
              {
                ia = dObject[k][j] - 1;
                if ( object[ia]._otype == 58 && object[ia]._oBreak != -1 )
                  BreakBarrel(pnum, ia, dam, 1u, sendmsg);
              }
            }
          }
        }
        else
        {
          PlaySfxLoc(2, object[i]._ox, object[i]._oy);
          SetRndSeed(object[i]._oRndSeed);
          if ( object[i]._oVar2 <= 2 )
          {
            if ( object[i]._oVar3 )
              CreateRndItem(object[i]._ox, object[i]._oy, 0, sendmsg, 0);
            else
              CreateRndUseful(pnum, object[i]._ox, object[i]._oy, sendmsg);
          }
          if ( object[i]._oVar2 == 4 )
            SpawnSkeleton(object[i]._oVar4, object[i]._ox, object[i]._oy);
        }
        if ( myplr == pnum )
          NetSendCmdParam2(0, 0x32u, pnum, i);
      }
    }
    else if ( !deltaload )
    {
      PlaySfxLoc(24, object[i]._ox, object[i]._oy);
    }
  }
}

//----- (00465C5A) --------------------------------------------------------
void __fastcall BreakObject(int pnum, int oi)
{
  int v2; // ST2C_4
  int v3; // eax
  int dam; // [esp+18h] [ebp-Ch]

  if ( pnum == -1 )
  {
    dam = 10;
  }
  else
  {
    v2 = plr[pnum]._pIMinDam;
    v3 = random(163, plr[pnum]._pIMaxDam - v2 + 1);
    dam = plr[pnum]._pDamageMod + plr[pnum]._pIBonusDamMod + (v3 + v2) * plr[pnum]._pIBonusDam / 100 + v3 + v2;
  }
  switch ( object[oi]._otype )
  {
    case OBJ_CRUX1:
    case OBJ_CRUX2:
    case OBJ_CRUX3:
      BreakCrux(oi);
      break;
    case OBJ_BARREL:
    case OBJ_BARRELEX:
      BreakBarrel(pnum, oi, dam, 0, 1);
      break;
    default:
      return;
  }
}

//----- (00465DE2) --------------------------------------------------------
void __fastcall SyncBreakObj(int pnum, int oi)
{
  _object_id v2; // [esp+Ch] [ebp-Ch]

  v2 = object[oi]._otype;
  if ( (signed int)v2 >= 57 && (signed int)v2 <= 58 )
    BreakBarrel(pnum, oi, 0, 1u, 0);
}

//----- (00465E47) --------------------------------------------------------
void __fastcall SyncL1Doors(int i)
{
  int dy; // [esp+10h] [ebp-8h]
  int x; // [esp+14h] [ebp-4h]

  if ( object[i]._oVar4 )
  {
    object[i]._oMissFlag = 1;
    x = object[i]._ox;
    dy = object[i]._oy;
    object[i]._oSelFlag = 2;
    if ( object[i]._otype == 1 )
    {
      if ( object[i]._oVar1 == 214 )
        ObjSetMicro(x, dy, 408);
      else
        ObjSetMicro(x, dy, 393);
      dArch[x][dy] = 7;
      objects_set_door_piece(x - 1, dy--);
    }
    else
    {
      ObjSetMicro(x, dy, 395);
      dArch[x][dy] = 8;
      objects_set_door_piece(x--, dy - 1);
    }
    DoorSet(i, x, dy);
  }
  else
  {
    object[i]._oMissFlag = 0;
  }
}

//----- (00465FA5) --------------------------------------------------------
void __fastcall SyncCrux(int i)
{
  int v1; // [esp+10h] [ebp-10h]
  signed int v2; // [esp+14h] [ebp-Ch]
  int j; // [esp+18h] [ebp-8h]
  _object_id v4; // [esp+1Ch] [ebp-4h]

  v2 = 1;
  for ( j = 0; j < nobjects; ++j )
  {
    v1 = objectactive[j];
    v4 = object[v1]._otype;
    if ( (v4 == 20 || v4 == 21 || v4 == 22) && object[v1]._oVar8 == object[i]._oVar8 && object[v1]._oBreak != -1 )
      v2 = 0;
  }
  if ( v2 )
    ObjChangeMap(object[i]._oVar1, object[i]._oVar2, object[i]._oVar3, object[i]._oVar4);
}

//----- (004660BA) --------------------------------------------------------
void __fastcall SyncLever(int i)
{
  if ( !object[i]._oSelFlag )
    ObjChangeMap(object[i]._oVar1, object[i]._oVar2, object[i]._oVar3, object[i]._oVar4);
}

//----- (00466130) --------------------------------------------------------
void __fastcall SyncL2Doors(int i)
{
  int dy; // [esp+10h] [ebp-8h]
  int v2; // [esp+14h] [ebp-4h]

  if ( object[i]._oVar4 )
  {
    object[i]._oMissFlag = 1;
    v2 = object[i]._ox;
    dy = object[i]._oy;
    object[i]._oSelFlag = 2;
    if ( object[i]._otype == 1 )
      ObjSetMicro(v2, dy, 13);
    else
      ObjSetMicro(v2, dy, 17);
  }
  else
  {
    object[i]._oMissFlag = 0;
  }
}

//----- (00466355) --------------------------------------------------------
void __fastcall GetObjectStr(int i)
{
  switch ( object[i]._otype )
  {
    case OBJ_L1LDOOR:
    case OBJ_L1RDOOR:
    case OBJ_L2LDOOR:
    case OBJ_L2RDOOR:
      if ( object[i]._oVar4 == 1 )
        strcpy(infostr, "Open Door");
      if ( !object[i]._oVar4 )
        strcpy(infostr, "Closed Door");
      if ( object[i]._oVar4 == 2 )
        strcpy(infostr, "Blocked Door");
      break;
    case OBJ_LEVER:
    case OBJ_FLAMELVR:
      strcpy(infostr, "Lever");
      break;
    case OBJ_CHEST1:
    case OBJ_TCHEST1:
      strcpy(infostr, "Small Chest");
      break;
    case OBJ_CHEST2:
    case OBJ_TCHEST2:
      strcpy(infostr, "Chest");
      break;
    case OBJ_CHEST3:
    case OBJ_TCHEST3:
      strcpy(infostr, "Large Chest");
      break;
    case OBJ_CRUX1:
    case OBJ_CRUX2:
    case OBJ_CRUX3:
      strcpy(infostr, "Crusified Skeleton");
      break;
    case OBJ_BOOK2L:
      strcpy(infostr, "Book of Novaness");
      break;
    case OBJ_SWITCHSKL:
      strcpy(infostr, "Skull Lever");
      break;
    case OBJ_BOOK2R:
      strcpy(infostr, "Mythical Book");
      break;
    case OBJ_SARC:
      strcpy(infostr, "Sarcophagus");
      break;
    case OBJ_BOOKLVR:
      strcpy(infostr, "Tome");
      break;
    case OBJ_BOOKSHELF:
      strcpy(infostr, "Bookshelf");
      break;
    case OBJ_BARREL:
    case OBJ_BARRELEX:
      strcpy(infostr, "Barrel");
      break;
    case OBJ_SHRINEL:
    case OBJ_SHRINER:
    case OBJ_L3RDOOR:
    case OBJ_PURIFYINGFTN:
      sprintf(tempstr, "%s Shrine", off_4D60F8[object[i]._oVar1]);
      strcpy(infostr, tempstr);
      break;
    case OBJ_SKELBOOK:
      strcpy(infostr, "Skeleton Tome");
      break;
    case OBJ_BOOKCASEL:
    case OBJ_BOOKCASER:
    case OBJ_ARMORSTAND:
    case OBJ_ARMORSTANDN:
      strcpy(infostr, "Bookcase");
      break;
    case OBJ_BOOKSTAND:
      strcpy(infostr, "Library Book");
      break;
    case OBJ_BLOODFTN:
      strcpy(infostr, "Blood Fountain");
      break;
    case OBJ_DECAP:
      strcpy(infostr, "Decapitated Body");
      break;
    case OBJ_BLINDBOOK:
      strcpy(infostr, "Book of the Blind");
      break;
    case OBJ_BLOODBOOK:
      strcpy(infostr, "Book of Blood");
      break;
    default:
      break;
  }
  if ( plr[myplr]._pClass == 1 )
  {
    if ( object[i]._oTrapFlag )
    {
      sprintf(tempstr, "Trapped %s", infostr);
      strcpy(infostr, tempstr);
      infoclr = 2;
    }
  }
}

