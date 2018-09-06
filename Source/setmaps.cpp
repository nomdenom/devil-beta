//----- (004364A0) --------------------------------------------------------
int __fastcall ObjIndex(int x, int y)
{
  int v3; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  for ( i = 0; nobjects > i; ++i )
  {
    v3 = objectactive[i];
    if ( object[v3]._ox == x && object[v3]._oy == y )
      return objectactive[i];
  }
  return -1;
}

//----- (00436528) --------------------------------------------------------
void __cdecl AddSKingObjs()
{
  int v0; // eax
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int i; // ST1C_4

  v0 = ObjIndex(64, 34);
  SetObjMapRange(v0, 20, 7, 23, 10, 1);
  v1 = ObjIndex(64, 59);
  SetObjMapRange(v1, 20, 14, 21, 16, 2);
  v2 = ObjIndex(27, 37);
  SetObjMapRange(v2, 8, 1, 15, 11, 3);
  v3 = ObjIndex(46, 35);
  SetObjMapRange(v3, 8, 1, 15, 11, 3);
  v4 = ObjIndex(49, 53);
  SetObjMapRange(v4, 8, 1, 15, 11, 3);
  i = ObjIndex(27, 53);
  SetObjMapRange(i, 8, 1, 15, 11, 3);
}

//----- (00436625) --------------------------------------------------------
void __cdecl AddSChamObjs()
{
  int v0; // eax
  int i; // ST1C_4

  v0 = ObjIndex(37, 30);
  SetObjMapRange(v0, 17, 1, 21, 5, 1);
  i = ObjIndex(37, 46);
  SetObjMapRange(i, 13, 1, 16, 5, 2);
}

//----- (00436686) --------------------------------------------------------
void __fastcall DRLG_SetMapTrans(char *sFileName)
{
  int v1; // ST24_4
  int v2; // ST20_4
  int v3; // ST30_4
  int i; // [esp+10h] [ebp-1Ch]
  int j; // [esp+14h] [ebp-18h]
  int v6; // [esp+18h] [ebp-14h]
  int v7; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *ptr; // [esp+20h] [ebp-Ch]
  char *v9; // [esp+24h] [ebp-8h]

  ptr = LoadFileInMem(sFileName, 0, 146, "SetMaps.cpp");
  v1 = *ptr;
  v2 = ptr[2];
  v3 = 2 * v1 * v2 + 2;
  v7 = 2 * v1;
  v6 = 2 * v2;
  v9 = (char *)&ptr[6 * v7 * v6 + 2 + v3];
  for ( i = 0; v6 > i; ++i )
  {
    for ( j = 0; v7 > j; ++j )
    {
      dung_map[j + 16][i + 16] = *v9;
      v9 += 2;
    }
  }
  mem_free_dbg(ptr, 168, "SetMaps.cpp");
}

//----- (00436770) --------------------------------------------------------
void __cdecl LoadSetMap()
{
  switch ( setlvlnum )
  {
    case 1:
      LoadPreL1Dungeon("Levels\\L1Data\\SklKng1.DUN", 84, 46);
      LoadL1Dungeon("Levels\\L1Data\\SklKng2.DUN", 84, 46);
      LoadPalette("Levels\\L1Data\\L1_2.pal");
      DRLG_AreaTrans(3, SkelKingTrans1);
      DRLG_ListTrans(2, SkelKingTrans2);
      DRLG_AreaTrans(5, SkelKingTrans3);
      DRLG_ListTrans(7, SkelKingTrans4);
      AddL1Objs(0, 0, 112, 112);
      AddSKingObjs();
      InitSKingTriggers();
      break;
    case 2:
      LoadPreL2Dungeon("Levels\\L2Data\\Bonecha2.DUN", 69, 39);
      LoadL2Dungeon("Levels\\L2Data\\Bonecha1.DUN", 69, 39);
      LoadPalette("Levels\\L2Data\\L2_2.pal");
      DRLG_ListTrans(5, SkelChamTrans1);
      DRLG_AreaTrans(2, SkelChamTrans2);
      DRLG_ListTrans(9, SkelChamTrans3);
      AddL2Objs(0, 0, 112, 112);
      AddSChamObjs();
      InitSChambTriggers();
      break;
    case 3:
      LoadPreL1Dungeon("Levels\\L1Data\\Lv1MazeA.DUN", 20, 50);
      LoadL1Dungeon("Levels\\L1Data\\Lv1MazeB.DUN", 20, 50);
      LoadPalette("Levels\\L1Data\\L1_5.pal");
      AddL1Objs(0, 0, 112, 112);
      DRLG_SetMapTrans("Levels\\L1Data\\Lv1MazeA.DUN");
      break;
    case 4:
      LoadPreL3Dungeon("Levels\\L3Data\\Foulwatr.DUN", 20, 50);
      LoadL3Dungeon("Levels\\L3Data\\Foulwatr.DUN", 20, 50);
      LoadPalette("Levels\\L3Data\\L3pfoul.pal");
      InitPWaterTriggers();
      break;
    default:
      return;
  }
}

