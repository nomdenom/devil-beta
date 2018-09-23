#include "all.h"

//----- (0043AE00) --------------------------------------------------------
int __fastcall FindClosest(int sx, int sy, int rad)
{
  int v3; // ST18_4
  int v5; // [esp+14h] [ebp-60h]
  int CrawlNum[19]; // [esp+1Ch] [ebp-58h]
  int j; // [esp+68h] [ebp-Ch]
  int i; // [esp+6Ch] [ebp-8h]
  int v9; // [esp+70h] [ebp-4h]

  CrawlNum[0] = 0;
  CrawlNum[1] = 3;
  CrawlNum[2] = 12;
  CrawlNum[3] = 45;
  CrawlNum[4] = 94;
  CrawlNum[5] = 159;
  CrawlNum[6] = 240;
  CrawlNum[7] = 337;
  CrawlNum[8] = 450;
  CrawlNum[9] = 579;
  CrawlNum[10] = 724;
  CrawlNum[11] = 885;
  CrawlNum[12] = 1062;
  CrawlNum[13] = 1255;
  CrawlNum[14] = 1464;
  CrawlNum[15] = 1689;
  CrawlNum[16] = 1930;
  CrawlNum[17] = 2187;
  CrawlNum[18] = 2460;
  if ( rad > 19 )
    rad = 19;
  for ( i = 1; i < rad; ++i )
  {
    v3 = CrawlNum[i];
    v5 = v3 + 1;
    for ( j = (unsigned __int8)CrawlTable[v3]; j > 0; --j )
    {
      v9 = dMonster[sx + CrawlTable[v5]][sy + CrawlTable[v5 + 1]];
      if ( v9 > 0 )
        return v9 - 1;
      v5 += 2;
    }
  }
  return -1;
}

//----- (0043AF51) --------------------------------------------------------
int __fastcall GetSpellLevel(int id, int sn)
{
  int v3; // [esp+14h] [ebp-4h]

  v3 = plr[id]._pISplLvlAdd + plr[id]._pSplLvl[sn];
  if ( v3 < 0 )
    v3 = 0;
  return v3;
}

//----- (0043AFC2) --------------------------------------------------------
void __fastcall missiles_43AFC2(int a1, int a2, int a3, int a4, int a5)
{
  ;
}

//----- (0043B031) --------------------------------------------------------
BOOL __fastcall CheckBlock(int fx, int fy, int tx, int ty)
{
  int dir; // ST1C_4
  int y; // [esp+Ch] [ebp-14h]
  int x; // [esp+10h] [ebp-10h]
  BOOL result; // [esp+1Ch] [ebp-4h]

  y = fy;
  x = fx;
  result = 0;
  while ( tx != x || ty != y )
  {
    dir = GetDirection(x, y, tx, ty);
    x += XDirAdd[dir];
    y += YDirAdd[dir];
    if ( nSolidTable[dPiece[x][y]] )
      result = 1;
  }
  return result;
}

//----- (0043B0D7) --------------------------------------------------------
int __fastcall GetDirection8(int x1, int y1, int x2, int y2)
{
  unsigned __int8 Dirs[256]; // [esp+14h] [ebp-11Ch]
  unsigned __int8 ultolr[3]; // [esp+114h] [ebp-1Ch]
  int off; // [esp+118h] [ebp-18h]
  unsigned __int8 lltour[3]; // [esp+11Ch] [ebp-14h]
  unsigned __int8 urtoll[3]; // [esp+120h] [ebp-10h]
  unsigned __int8 lrtoul[3]; // [esp+124h] [ebp-Ch]
  int yd; // [esp+128h] [ebp-8h]
  int xd; // [esp+12Ch] [ebp-4h]

  Dirs[0] = 99;
  Dirs[1] = 0;
  Dirs[2] = 0;
  Dirs[3] = 0;
  Dirs[4] = 0;
  Dirs[5] = 0;
  Dirs[6] = 0;
  Dirs[7] = 0;
  Dirs[8] = 0;
  Dirs[9] = 0;
  Dirs[10] = 0;
  Dirs[11] = 0;
  Dirs[12] = 0;
  Dirs[13] = 0;
  Dirs[14] = 0;
  Dirs[15] = 0;
  Dirs[16] = 2;
  Dirs[17] = 1;
  Dirs[18] = 1;
  Dirs[19] = 1;
  Dirs[20] = 0;
  Dirs[21] = 0;
  Dirs[22] = 0;
  Dirs[23] = 0;
  Dirs[24] = 0;
  Dirs[25] = 0;
  Dirs[26] = 0;
  Dirs[27] = 0;
  Dirs[28] = 0;
  Dirs[29] = 0;
  Dirs[30] = 0;
  Dirs[31] = 0;
  Dirs[32] = 2;
  Dirs[33] = 1;
  Dirs[34] = 1;
  Dirs[35] = 1;
  Dirs[36] = 1;
  Dirs[37] = 1;
  Dirs[38] = 1;
  Dirs[39] = 0;
  Dirs[40] = 0;
  Dirs[41] = 0;
  Dirs[42] = 0;
  Dirs[43] = 0;
  Dirs[44] = 0;
  Dirs[45] = 0;
  Dirs[46] = 0;
  Dirs[47] = 0;
  Dirs[48] = 2;
  Dirs[49] = 1;
  Dirs[50] = 1;
  Dirs[51] = 1;
  Dirs[52] = 1;
  Dirs[53] = 1;
  Dirs[54] = 1;
  Dirs[55] = 1;
  Dirs[56] = 1;
  Dirs[57] = 0;
  Dirs[58] = 0;
  Dirs[59] = 0;
  Dirs[60] = 0;
  Dirs[61] = 0;
  Dirs[62] = 0;
  Dirs[63] = 0;
  Dirs[64] = 2;
  Dirs[65] = 2;
  Dirs[66] = 1;
  Dirs[67] = 1;
  Dirs[68] = 1;
  Dirs[69] = 1;
  Dirs[70] = 1;
  Dirs[71] = 1;
  Dirs[72] = 1;
  Dirs[73] = 1;
  Dirs[74] = 1;
  Dirs[75] = 1;
  Dirs[76] = 0;
  Dirs[77] = 0;
  Dirs[78] = 0;
  Dirs[79] = 0;
  Dirs[80] = 2;
  Dirs[81] = 2;
  Dirs[82] = 1;
  Dirs[83] = 1;
  Dirs[84] = 1;
  Dirs[85] = 1;
  Dirs[86] = 1;
  Dirs[87] = 1;
  Dirs[88] = 1;
  Dirs[89] = 1;
  Dirs[90] = 1;
  Dirs[91] = 1;
  Dirs[92] = 1;
  Dirs[93] = 1;
  Dirs[94] = 0;
  Dirs[95] = 0;
  Dirs[96] = 2;
  Dirs[97] = 2;
  Dirs[98] = 1;
  Dirs[99] = 1;
  Dirs[100] = 1;
  Dirs[101] = 1;
  Dirs[102] = 1;
  Dirs[103] = 1;
  Dirs[104] = 1;
  Dirs[105] = 1;
  Dirs[106] = 1;
  Dirs[107] = 1;
  Dirs[108] = 1;
  Dirs[109] = 1;
  Dirs[110] = 1;
  Dirs[111] = 1;
  Dirs[112] = 2;
  Dirs[113] = 2;
  Dirs[114] = 2;
  Dirs[115] = 1;
  Dirs[116] = 1;
  Dirs[117] = 1;
  Dirs[118] = 1;
  Dirs[119] = 1;
  Dirs[120] = 1;
  Dirs[121] = 1;
  Dirs[122] = 1;
  Dirs[123] = 1;
  Dirs[124] = 1;
  Dirs[125] = 1;
  Dirs[126] = 1;
  Dirs[127] = 1;
  Dirs[128] = 2;
  Dirs[129] = 2;
  Dirs[130] = 2;
  Dirs[131] = 1;
  Dirs[132] = 1;
  Dirs[133] = 1;
  Dirs[134] = 1;
  Dirs[135] = 1;
  Dirs[136] = 1;
  Dirs[137] = 1;
  Dirs[138] = 1;
  Dirs[139] = 1;
  Dirs[140] = 1;
  Dirs[141] = 1;
  Dirs[142] = 1;
  Dirs[143] = 1;
  Dirs[144] = 2;
  Dirs[145] = 2;
  Dirs[146] = 2;
  Dirs[147] = 2;
  Dirs[148] = 1;
  Dirs[149] = 1;
  Dirs[150] = 1;
  Dirs[151] = 1;
  Dirs[152] = 1;
  Dirs[153] = 1;
  Dirs[154] = 1;
  Dirs[155] = 1;
  Dirs[156] = 1;
  Dirs[157] = 1;
  Dirs[158] = 1;
  Dirs[159] = 1;
  Dirs[160] = 2;
  Dirs[161] = 2;
  Dirs[162] = 2;
  Dirs[163] = 2;
  Dirs[164] = 1;
  Dirs[165] = 1;
  Dirs[166] = 1;
  Dirs[167] = 1;
  Dirs[168] = 1;
  Dirs[169] = 1;
  Dirs[170] = 1;
  Dirs[171] = 1;
  Dirs[172] = 1;
  Dirs[173] = 1;
  Dirs[174] = 1;
  Dirs[175] = 1;
  Dirs[176] = 2;
  Dirs[177] = 2;
  Dirs[178] = 2;
  Dirs[179] = 2;
  Dirs[180] = 1;
  Dirs[181] = 1;
  Dirs[182] = 1;
  Dirs[183] = 1;
  Dirs[184] = 1;
  Dirs[185] = 1;
  Dirs[186] = 1;
  Dirs[187] = 1;
  Dirs[188] = 1;
  Dirs[189] = 1;
  Dirs[190] = 1;
  Dirs[191] = 1;
  Dirs[192] = 2;
  Dirs[193] = 2;
  Dirs[194] = 2;
  Dirs[195] = 2;
  Dirs[196] = 2;
  Dirs[197] = 1;
  Dirs[198] = 1;
  Dirs[199] = 1;
  Dirs[200] = 1;
  Dirs[201] = 1;
  Dirs[202] = 1;
  Dirs[203] = 1;
  Dirs[204] = 1;
  Dirs[205] = 1;
  Dirs[206] = 1;
  Dirs[207] = 1;
  Dirs[208] = 2;
  Dirs[209] = 2;
  Dirs[210] = 2;
  Dirs[211] = 2;
  Dirs[212] = 2;
  Dirs[213] = 1;
  Dirs[214] = 1;
  Dirs[215] = 1;
  Dirs[216] = 1;
  Dirs[217] = 1;
  Dirs[218] = 1;
  Dirs[219] = 1;
  Dirs[220] = 1;
  Dirs[221] = 1;
  Dirs[222] = 1;
  Dirs[223] = 1;
  Dirs[224] = 2;
  Dirs[225] = 2;
  Dirs[226] = 2;
  Dirs[227] = 2;
  Dirs[228] = 2;
  Dirs[229] = 2;
  Dirs[230] = 1;
  Dirs[231] = 1;
  Dirs[232] = 1;
  Dirs[233] = 1;
  Dirs[234] = 1;
  Dirs[235] = 1;
  Dirs[236] = 1;
  Dirs[237] = 1;
  Dirs[238] = 1;
  Dirs[239] = 1;
  Dirs[240] = 2;
  Dirs[241] = 2;
  Dirs[242] = 2;
  Dirs[243] = 2;
  Dirs[244] = 2;
  Dirs[245] = 2;
  Dirs[246] = 1;
  Dirs[247] = 1;
  Dirs[248] = 1;
  Dirs[249] = 1;
  Dirs[250] = 1;
  Dirs[251] = 1;
  Dirs[252] = 1;
  Dirs[253] = 1;
  Dirs[254] = 1;
  Dirs[255] = 1;
  lrtoul[0] = 3;
  lrtoul[1] = 4;
  lrtoul[2] = 5;
  urtoll[0] = 3;
  urtoll[1] = 2;
  urtoll[2] = 1;
  ultolr[0] = 7;
  ultolr[1] = 6;
  ultolr[2] = 5;
  lltour[0] = 7;
  lltour[1] = 0;
  lltour[2] = 1;
  xd = abs(x2 - x1);
  if ( xd > 15 )
    xd = 15;
  yd = abs(y2 - y1);
  if ( yd > 15 )
    yd = 15;
  off = Dirs[16 * yd + xd];
  if ( x2 >= x1 )
  {
    if ( y1 <= y2 )
      off = lltour[off];
    else
      off = ultolr[off];
  }
  else if ( y1 <= y2 )
  {
    off = urtoll[off];
  }
  else
  {
    off = lrtoul[off];
  }
  return off;
}

//----- (0043B7CF) --------------------------------------------------------
int __fastcall GetDirection16(int x1, int y1, int x2, int y2)
{
  BYTE Dirs[256]; // [esp+14h] [ebp-12Ch]
  BYTE lltour[5]; // [esp+114h] [ebp-2Ch]
  int off; // [esp+11Ch] [ebp-24h]
  BYTE lrtoul[5]; // [esp+120h] [ebp-20h]
  BYTE ultolr[5]; // [esp+128h] [ebp-18h]
  BYTE urtoll[5]; // [esp+130h] [ebp-10h]
  int yd; // [esp+138h] [ebp-8h]
  int xd; // [esp+13Ch] [ebp-4h]

  Dirs[0] = 99;
  Dirs[1] = 0;
  Dirs[2] = 0;
  Dirs[3] = 0;
  Dirs[4] = 0;
  Dirs[5] = 0;
  Dirs[6] = 0;
  Dirs[7] = 0;
  Dirs[8] = 0;
  Dirs[9] = 0;
  Dirs[10] = 0;
  Dirs[11] = 0;
  Dirs[12] = 0;
  Dirs[13] = 0;
  Dirs[14] = 0;
  Dirs[15] = 0;
  Dirs[16] = 4;
  Dirs[17] = 2;
  Dirs[18] = 1;
  Dirs[19] = 1;
  Dirs[20] = 0;
  Dirs[21] = 0;
  Dirs[22] = 0;
  Dirs[23] = 0;
  Dirs[24] = 0;
  Dirs[25] = 0;
  Dirs[26] = 0;
  Dirs[27] = 0;
  Dirs[28] = 0;
  Dirs[29] = 0;
  Dirs[30] = 0;
  Dirs[31] = 0;
  Dirs[32] = 4;
  Dirs[33] = 3;
  Dirs[34] = 2;
  Dirs[35] = 1;
  Dirs[36] = 1;
  Dirs[37] = 1;
  Dirs[38] = 1;
  Dirs[39] = 1;
  Dirs[40] = 0;
  Dirs[41] = 0;
  Dirs[42] = 0;
  Dirs[43] = 0;
  Dirs[44] = 0;
  Dirs[45] = 0;
  Dirs[46] = 0;
  Dirs[47] = 0;
  Dirs[48] = 4;
  Dirs[49] = 3;
  Dirs[50] = 3;
  Dirs[51] = 2;
  Dirs[52] = 2;
  Dirs[53] = 1;
  Dirs[54] = 1;
  Dirs[55] = 1;
  Dirs[56] = 1;
  Dirs[57] = 1;
  Dirs[58] = 1;
  Dirs[59] = 1;
  Dirs[60] = 0;
  Dirs[61] = 0;
  Dirs[62] = 0;
  Dirs[63] = 0;
  Dirs[64] = 4;
  Dirs[65] = 4;
  Dirs[66] = 3;
  Dirs[67] = 2;
  Dirs[68] = 2;
  Dirs[69] = 1;
  Dirs[70] = 1;
  Dirs[71] = 1;
  Dirs[72] = 1;
  Dirs[73] = 1;
  Dirs[74] = 1;
  Dirs[75] = 1;
  Dirs[76] = 1;
  Dirs[77] = 1;
  Dirs[78] = 1;
  Dirs[79] = 1;
  Dirs[80] = 4;
  Dirs[81] = 4;
  Dirs[82] = 3;
  Dirs[83] = 3;
  Dirs[84] = 2;
  Dirs[85] = 2;
  Dirs[86] = 2;
  Dirs[87] = 1;
  Dirs[88] = 1;
  Dirs[89] = 1;
  Dirs[90] = 1;
  Dirs[91] = 1;
  Dirs[92] = 1;
  Dirs[93] = 1;
  Dirs[94] = 1;
  Dirs[95] = 1;
  Dirs[96] = 4;
  Dirs[97] = 4;
  Dirs[98] = 3;
  Dirs[99] = 3;
  Dirs[100] = 2;
  Dirs[101] = 2;
  Dirs[102] = 2;
  Dirs[103] = 2;
  Dirs[104] = 2;
  Dirs[105] = 1;
  Dirs[106] = 1;
  Dirs[107] = 1;
  Dirs[108] = 1;
  Dirs[109] = 1;
  Dirs[110] = 1;
  Dirs[111] = 1;
  Dirs[112] = 4;
  Dirs[113] = 4;
  Dirs[114] = 3;
  Dirs[115] = 3;
  Dirs[116] = 3;
  Dirs[117] = 3;
  Dirs[118] = 2;
  Dirs[119] = 2;
  Dirs[120] = 2;
  Dirs[121] = 2;
  Dirs[122] = 1;
  Dirs[123] = 1;
  Dirs[124] = 1;
  Dirs[125] = 1;
  Dirs[126] = 1;
  Dirs[127] = 1;
  Dirs[128] = 4;
  Dirs[129] = 4;
  Dirs[130] = 4;
  Dirs[131] = 3;
  Dirs[132] = 3;
  Dirs[133] = 3;
  Dirs[134] = 2;
  Dirs[135] = 2;
  Dirs[136] = 2;
  Dirs[137] = 2;
  Dirs[138] = 2;
  Dirs[139] = 1;
  Dirs[140] = 1;
  Dirs[141] = 1;
  Dirs[142] = 1;
  Dirs[143] = 1;
  Dirs[144] = 4;
  Dirs[145] = 4;
  Dirs[146] = 4;
  Dirs[147] = 3;
  Dirs[148] = 3;
  Dirs[149] = 3;
  Dirs[150] = 3;
  Dirs[151] = 2;
  Dirs[152] = 2;
  Dirs[153] = 2;
  Dirs[154] = 2;
  Dirs[155] = 2;
  Dirs[156] = 1;
  Dirs[157] = 1;
  Dirs[158] = 1;
  Dirs[159] = 1;
  Dirs[160] = 4;
  Dirs[161] = 4;
  Dirs[162] = 4;
  Dirs[163] = 3;
  Dirs[164] = 3;
  Dirs[165] = 3;
  Dirs[166] = 3;
  Dirs[167] = 3;
  Dirs[168] = 2;
  Dirs[169] = 2;
  Dirs[170] = 2;
  Dirs[171] = 2;
  Dirs[172] = 2;
  Dirs[173] = 2;
  Dirs[174] = 1;
  Dirs[175] = 1;
  Dirs[176] = 4;
  Dirs[177] = 4;
  Dirs[178] = 4;
  Dirs[179] = 3;
  Dirs[180] = 3;
  Dirs[181] = 3;
  Dirs[182] = 3;
  Dirs[183] = 3;
  Dirs[184] = 3;
  Dirs[185] = 2;
  Dirs[186] = 2;
  Dirs[187] = 2;
  Dirs[188] = 2;
  Dirs[189] = 2;
  Dirs[190] = 2;
  Dirs[191] = 1;
  Dirs[192] = 4;
  Dirs[193] = 4;
  Dirs[194] = 4;
  Dirs[195] = 4;
  Dirs[196] = 3;
  Dirs[197] = 3;
  Dirs[198] = 3;
  Dirs[199] = 3;
  Dirs[200] = 3;
  Dirs[201] = 3;
  Dirs[202] = 2;
  Dirs[203] = 2;
  Dirs[204] = 2;
  Dirs[205] = 2;
  Dirs[206] = 2;
  Dirs[207] = 2;
  Dirs[208] = 4;
  Dirs[209] = 4;
  Dirs[210] = 4;
  Dirs[211] = 4;
  Dirs[212] = 3;
  Dirs[213] = 3;
  Dirs[214] = 3;
  Dirs[215] = 3;
  Dirs[216] = 3;
  Dirs[217] = 3;
  Dirs[218] = 2;
  Dirs[219] = 2;
  Dirs[220] = 2;
  Dirs[221] = 2;
  Dirs[222] = 2;
  Dirs[223] = 2;
  Dirs[224] = 4;
  Dirs[225] = 4;
  Dirs[226] = 4;
  Dirs[227] = 4;
  Dirs[228] = 3;
  Dirs[229] = 3;
  Dirs[230] = 3;
  Dirs[231] = 3;
  Dirs[232] = 3;
  Dirs[233] = 3;
  Dirs[234] = 3;
  Dirs[235] = 2;
  Dirs[236] = 2;
  Dirs[237] = 2;
  Dirs[238] = 2;
  Dirs[239] = 2;
  Dirs[240] = 4;
  Dirs[241] = 4;
  Dirs[242] = 4;
  Dirs[243] = 4;
  Dirs[244] = 3;
  Dirs[245] = 3;
  Dirs[246] = 3;
  Dirs[247] = 3;
  Dirs[248] = 3;
  Dirs[249] = 3;
  Dirs[250] = 3;
  Dirs[251] = 3;
  Dirs[252] = 2;
  Dirs[253] = 2;
  Dirs[254] = 2;
  Dirs[255] = 2;
  urtoll[0] = 6;
  urtoll[1] = 7;
  urtoll[2] = 8;
  urtoll[3] = 9;
  urtoll[4] = 10;
  ultolr[0] = 6;
  ultolr[1] = 5;
  ultolr[2] = 4;
  ultolr[3] = 3;
  ultolr[4] = 2;
  lltour[0] = 14;
  lltour[1] = 13;
  lltour[2] = 12;
  lltour[3] = 11;
  lltour[4] = 10;
  lrtoul[0] = 14;
  lrtoul[1] = 15;
  lrtoul[2] = 0;
  lrtoul[3] = 1;
  lrtoul[4] = 2;
  xd = abs(x2 - x1);
  if ( xd > 15 )
    xd = 15;
  yd = abs(y2 - y1);
  if ( yd > 15 )
    yd = 15;
  off = Dirs[16 * yd + xd];
  if ( x2 >= x1 )
  {
    if ( y2 >= y1 )
      off = lrtoul[off];
    else
      off = lltour[off];
  }
  else if ( y2 >= y1 )
  {
    off = ultolr[off];
  }
  else
  {
    off = urtoll[off];
  }
  return off;
}

//----- (0043BF17) --------------------------------------------------------
void __fastcall DeleteMissile(int mi, int i)
{
  missilevail[125 - nummissiles--] = mi;
  if ( nummissiles > 0 && i != nummissiles )
    missileactive[i] = missileactive[nummissiles];
}

//----- (0043BF7C) --------------------------------------------------------
void __fastcall GetMissileVel(int i, int sx, int sy, int dx, int dy, int v)
{
  double v7; // ST34_8
  double v8; // ST2C_8
  double v9; // ST3C_8

  v7 = (double)((32 * (dx - sx) - 32 * (dy - sy)) << 16);
  v8 = (double)((32 * (dx - sx) + 32 * (dy - sy)) << 16);
  v9 = sqrt(v8 * v8 + v7 * v7);
  missile[i]._mixvel = (signed __int64)((double)(v << 16) * v7 / v9);
  missile[i]._miyvel = (signed __int64)((double)(v << 15) * v8 / v9);
}

//----- (0043C04B) --------------------------------------------------------
void __fastcall PutMissile(int i)
{
  int y; // [esp+10h] [ebp-8h]
  int x; // [esp+14h] [ebp-4h]

  if ( !missile[i]._miDelFlag )
  {
    x = missile[i]._mix;
    y = missile[i]._miy;
    dFlags[x][y] |= 1u;
    if ( dMissile[x][y] )
      dMissile[x][y] = -1;
    else
      dMissile[x][y] = i + 1;
    if ( missile[i]._miPreFlag )
      MissilePreFlag = 1;
  }
}

//----- (0043C1CF) --------------------------------------------------------
void __fastcall GetMissilePos(int i)
{
  int v1; // [esp+10h] [ebp-18h]
  int v2; // [esp+10h] [ebp-18h]
  int v3; // [esp+14h] [ebp-14h]
  int v4; // [esp+18h] [ebp-10h]
  int v5; // [esp+18h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-Ch]
  int yoff; // [esp+20h] [ebp-8h]
  int xoff; // [esp+24h] [ebp-4h]

  xoff = missile[i]._mitxoff >> 16;
  yoff = missile[i]._mityoff >> 16;
  v4 = xoff + 2 * yoff;
  v1 = 2 * yoff - xoff;
  if ( v4 >= 0 )
  {
    v6 = v4 >> 3;
    v5 = v4 >> 6;
  }
  else
  {
    v6 = -(-v4 >> 3);
    v5 = -(-v4 >> 6);
  }
  if ( v1 >= 0 )
  {
    v3 = v1 >> 3;
    v2 = v1 >> 6;
  }
  else
  {
    v3 = -((xoff - 2 * yoff) >> 3);
    v2 = -((xoff - 2 * yoff) >> 6);
  }
  missile[i]._mix = v5 + missile[i]._misx;
  missile[i]._miy = v2 + missile[i]._misy;
  missile[i]._mixoff = xoff - 32 * (v5 - v2);
  missile[i]._miyoff = yoff - 16 * (v5 + v2);
  ChangeLightOff(missile[i]._mlid, v6 - 8 * v5, v3 - 8 * v2);
}

//----- (0043C370) --------------------------------------------------------
// PSX
void __fastcall MoveMissilePos(int i)
{
  signed int dy_; // [esp+14h] [ebp-10h]
  signed int dx_; // [esp+18h] [ebp-Ch]

  switch ( missile[i]._mimfnum )
  {
    case 0:
      dx_ = 1;
      dy_ = 1;
      break;
    case 1:
      dx_ = 1;
      dy_ = 1;
      break;
    case 2:
      dx_ = 0;
      dy_ = 1;
      break;
    case 3:
      dx_ = 0;
      dy_ = 0;
      break;
    case 4:
      dx_ = 0;
      dy_ = 0;
      break;
    case 5:
      dx_ = 0;
      dy_ = 0;
      break;
    case 6:
      dx_ = 1;
      dy_ = 0;
      break;
    case 7:
      dx_ = 1;
      dy_ = 1;
      break;
    default:
      break;
  }
  if ( PosOkMonst(missile[i]._misource, dx_ + missile[i]._mix, dy_ + missile[i]._miy) )
  {
    missile[i]._mix += dx_;
    missile[i]._miy += dy_;
    missile[i]._mixoff -= 32 * (dx_ - dy_);
    missile[i]._miyoff -= 16 * (dx_ + dy_);
  }
}

//----- (0043C54B) --------------------------------------------------------
BOOL __fastcall MonsterTrapHit(int m, int mindam, int maxdam, int dist, int t, int shift)
{
  BOOL result; // eax
  int dam; // [esp+14h] [ebp-18h]
  char v10; // [esp+18h] [ebp-14h]
  int v11; // [esp+1Ch] [ebp-10h]
  signed int v12; // [esp+20h] [ebp-Ch]
  int v13; // [esp+24h] [ebp-8h]
  int v14; // [esp+28h] [ebp-4h]

  v12 = 0;
  if ( monster[m].mtalkmsg )
    return 0;
  if ( (signed int)(monster[m]._mhitpoints & 0xFFFFFFC0) <= 0 )
    return 0;
  if ( monster[m].MType->mtype == 32 && monster[m]._mgoal == 2 )
    return 0;
  v14 = missiledata[t].mResist;
  v10 = monster[m].mMagicRes;
  if ( v10 & 8 && v14 == 3 || v10 & 0x10 && v14 == 1 || v10 & 0x20 && v14 == 2 )
    return 0;
  if ( v10 & 1 && v14 == 3 || v10 & 2 && v14 == 1 || v10 & 4 && v14 == 2 )
    v12 = 1;
  v13 = random(68, 100);
  v11 = 90 - monster[m].mArmorClass - dist;
  if ( v11 < 5 )
    v11 = 5;
  if ( v11 > 95 )
    v11 = 95;
  if ( monster[m]._mFlags & 4 )
  {
    monster[m]._mFlags &= 0xFFFFFFFB;
    monster[m]._mmode = MM_SATTACK;
    result = 1;
  }
  else if ( v11 <= v13 && monster[m]._mmode != MM_STONE )
  {
    result = 0;
  }
  else
  {
    dam = random(68, maxdam - mindam + 1) + mindam;
    if ( !(_BYTE)shift )
      dam <<= 6;
    if ( v12 )
      monster[m]._mhitpoints -= dam >> 2;
    else
      monster[m]._mhitpoints -= dam;
    if ( monster[m]._mmode == MM_STONE )
      monster[m]._mhitpoints = 0;
    if ( (signed int)(monster[m]._mhitpoints & 0xFFFFFFC0) > 0 )
    {
      if ( v12 )
      {
        PlayEffect(m, 1);
      }
      else
      {
        M_StartHit(m, -1, dam);
        missiles_43AFC2(monster[m]._mx, monster[m]._my, 17, dam >> 6, monster[m]._mmaxhp >> 6);
      }
    }
    else if ( monster[m]._mmode == MM_STONE )
    {
      M_StartKill(m, -1);
      monster[m]._mmode = MM_STONE;
    }
    else
    {
      M_StartKill(m, -1);
    }
    result = 1;
  }
  return result;
}

//----- (0043C93B) --------------------------------------------------------
BOOL __fastcall MonsterMHit(int pnum, int m, int mindam, int maxdam, int dist, int t, BYTE shift)
{
  BOOL result; // eax
  int dam; // [esp+14h] [ebp-18h]
  char v11; // [esp+18h] [ebp-14h]
  int v12; // [esp+1Ch] [ebp-10h]
  signed int v13; // [esp+20h] [ebp-Ch]
  int v14; // [esp+24h] [ebp-8h]
  int v15; // [esp+28h] [ebp-4h]

  v13 = 0;
  if ( monster[m].mtalkmsg )
    return 0;
  if ( (signed int)(monster[m]._mhitpoints & 0xFFFFFFC0) <= 0 )
    return 0;
  if ( t == 53 && monster[m].MData->mMonstClass )
    return 0;
  if ( monster[m].MType->mtype == 32 && monster[m]._mgoal == 2 )
    return 0;
  v15 = missiledata[t].mResist;
  v11 = monster[m].mMagicRes;
  if ( v11 & 8 && v15 == 3 || v11 & 0x10 && v15 == 1 || v11 & 0x20 && v15 == 2 || v11 < 0 && v15 == 4 )
    return 0;
  if ( v11 & 1 && v15 == 3 || v11 & 2 && v15 == 1 || v11 & 4 && v15 == 2 )
    v13 = 1;
  v14 = random(69, 100);
  if ( missiledata[t].mType )
  {
    v12 = plr[pnum]._pMagic + 50 - 2 * monster[m].mLevel - dist;
    if ( plr[pnum]._pClass == 2 )
      v12 += 20;
  }
  else
  {
    v12 = plr[pnum]._pIBonusToHit
        + (plr[pnum]._pDexterity >> 1)
        + plr[pnum]._pLevel
        + 50
        - monster[m].mArmorClass
        - plr[pnum]._pIEnAc
        - (dist * dist >> 1);
    if ( plr[pnum]._pClass == 1 )
      v12 += 20;
  }
  if ( v12 < 5 )
    v12 = 5;
  if ( v12 > 95 )
    v12 = 95;
  if ( monster[m]._mmode == MM_STONE )
    v14 = 0;
  if ( monster[m]._mFlags & 4 )
  {
    monster[m]._mFlags &= 0xFFFFFFFB;
    monster[m]._mmode = MM_SATTACK;
    result = 1;
  }
  else if ( v12 <= v14 )
  {
    result = 0;
  }
  else
  {
    dam = random(70, maxdam - mindam + 1) + mindam;
    if ( !missiledata[t].mType )
      dam += plr[pnum]._pDamageMod + plr[pnum]._pIBonusDamMod + dam * plr[pnum]._pIBonusDam / 100;
    if ( !shift )
      dam <<= 6;
    if ( v13 )
      dam >>= 2;
    if ( pnum == myplr )
      monster[m]._mhitpoints -= dam;
    if ( plr[pnum]._pIFlags & 8 )
      monster[m]._mFlags |= 8u;
    if ( pnum == myplr && monster[m]._mmode == MM_STONE )
      monster[m]._mhitpoints = 0;
    if ( (signed int)(monster[m]._mhitpoints & 0xFFFFFFC0) > 0 )
    {
      if ( v13 )
      {
        PlayEffect(m, 1);
      }
      else
      {
        M_StartHit(m, pnum, dam);
        missiles_43AFC2(monster[m]._mx, monster[m]._my, 17, dam >> 6, monster[m]._mmaxhp >> 6);
      }
    }
    else if ( monster[m]._mmode == MM_STONE )
    {
      M_StartKill(m, pnum);
      monster[m]._mmode = MM_STONE;
    }
    else
    {
      M_StartKill(m, pnum);
    }
    if ( !monster[m]._msquelch )
    {
      monster[m]._msquelch = -1;
      monster[m]._lastx = plr[pnum].WorldX;
      monster[m]._lasty = plr[pnum].WorldY;
    }
    result = 1;
  }
  return result;
}

//----- (0043CFFA) --------------------------------------------------------
BOOL __fastcall PlayerMHit(int pnum, int m, int dist, int mind, int maxd, int mtype, BYTE shift)
{
  BOOL result; // eax
  int v8; // eax
  int v9; // eax
  int dir; // ST24_4
  int v11; // [esp+Ch] [ebp-2Ch]
  int v14; // [esp+18h] [ebp-20h]
  int v; // [esp+20h] [ebp-18h]
  int va; // [esp+20h] [ebp-18h]
  int vb; // [esp+20h] [ebp-18h]
  int vc; // [esp+20h] [ebp-18h]
  signed int v19; // [esp+24h] [ebp-14h]
  int v20; // [esp+28h] [ebp-10h]
  int v21; // [esp+2Ch] [ebp-Ch]
  int v22; // [esp+30h] [ebp-8h]
  int v23; // [esp+34h] [ebp-4h]

  if ( (signed int)(plr[pnum]._pHitPoints & 0xFFFFFFC0) <= 0 )
    return 0;
  if ( plr[pnum]._pInvincible )
    return 0;
  v23 = random(72, 100);
  v21 = plr[pnum]._pIAC + plr[pnum]._pIBonusAC + plr[pnum]._pArmorClass;
  if ( m == -1 )
    v8 = 100 - (v21 >> 1);
  else
    v8 = monster[m].mHit + 30 + 2 * (monster[m].mLevel - plr[pnum]._pLevel) - v21;
  v20 = v8 - 2 * dist;
  if ( v20 < 10 )
    v20 = 10;
  if ( plr[pnum]._pmode && plr[pnum]._pmode != 4 || !plr[pnum]._pBlockFlag )
    v22 = 100;
  else
    v22 = random(73, 100);
  if ( m == -1 )
    v9 = plr[pnum]._pBaseToBlk + plr[pnum]._pDexterity;
  else
    v9 = plr[pnum]._pBaseToBlk + plr[pnum]._pDexterity - 2 * (monster[m].mLevel - plr[pnum]._pLevel);
  v19 = v9;
  if ( v9 < 0 )
    v19 = 0;
  if ( v19 > 100 )
    v19 = 100;
  v11 = missiledata[mtype].mResist;
  switch ( v11 )
  {
    case 1:
      v14 = plr[pnum]._pFireResist;
      break;
    case 2:
      v14 = plr[pnum]._pLghtResist;
      break;
    case 3:
      v14 = plr[pnum]._pMagResist;
      break;
    default:
      v14 = 0;
      break;
  }
  if ( v20 <= v23 )
    return 0;
  if ( shift )
  {
    vb = random(75, maxd - mind + 1) + mind;
    if ( plr[pnum]._pIFlags & 0x10000000 )
      vb >>= 1;
    va = plr[pnum]._pIGetHit + vb;
    if ( va < 0 )
      va = 0;
  }
  else
  {
    v = (mind << 6) + random(75, (maxd - mind + 1) << 6);
    if ( plr[pnum]._pIFlags & 0x10000000 )
      v >>= 1;
    va = (plr[pnum]._pIGetHit << 6) + v;
    if ( va < 0 )
      va = 0;
  }
  if ( v14 <= 0 )
  {
    if ( v19 <= v22 )
    {
      if ( pnum == myplr )
      {
        plr[pnum]._pHitPoints -= va;
        plr[pnum]._pHPBase -= va;
      }
      if ( plr[pnum]._pHitPoints > plr[pnum]._pMaxHP )
      {
        plr[pnum]._pHitPoints = plr[pnum]._pMaxHP;
        plr[pnum]._pHPBase = plr[pnum]._pMaxHPBase;
      }
      if ( (signed int)(plr[pnum]._pHitPoints & 0xFFFFFFC0) > 0 )
      {
        StartPlrHit(pnum, va);
      }
      else
      {
        plr[pnum]._pHitPoints = 0;
        SyncPlrKill(pnum);
      }
      result = 1;
    }
    else
    {
      if ( m == -1 )
      {
        StartPlrBlock(pnum, plr[pnum]._pdir);
      }
      else
      {
        dir = GetDirection(plr[pnum].WorldX, plr[pnum].WorldY, monster[m]._mx, monster[m]._my);
        StartPlrBlock(pnum, dir);
      }
      result = 1;
    }
  }
  else
  {
    vc = va - va * v14 / 100;
    if ( pnum == myplr )
    {
      plr[pnum]._pHitPoints -= vc;
      plr[pnum]._pHPBase -= vc;
    }
    if ( plr[pnum]._pHitPoints > plr[pnum]._pMaxHP )
    {
      plr[pnum]._pHitPoints = plr[pnum]._pMaxHP;
      plr[pnum]._pHPBase = plr[pnum]._pMaxHPBase;
    }
    if ( (signed int)(plr[pnum]._pHitPoints & 0xFFFFFFC0) > 0 )
    {
      PlaySfxLoc(48, plr[pnum].WorldX, plr[pnum].WorldY);
      drawhpflag = 1;
    }
    else
    {
      plr[pnum]._pHitPoints = 0;
      SyncPlrKill(pnum);
    }
    result = 1;
  }
  return result;
}

//----- (0043D8E1) --------------------------------------------------------
BOOL __fastcall Plr2PlrMHit(int pnum, int p, int mindam, int maxdam, int dist, int mtype, BYTE shift)
{
  BOOL result; // eax
  int dir; // ST24_4
  int v9; // [esp+Ch] [ebp-2Ch]
  int v12; // [esp+18h] [ebp-20h]
  int dwDam; // [esp+20h] [ebp-18h]
  unsigned int dwDama; // [esp+20h] [ebp-18h]
  int v15; // [esp+24h] [ebp-14h]
  int v16; // [esp+28h] [ebp-10h]
  int v17; // [esp+30h] [ebp-8h]
  int v18; // [esp+34h] [ebp-4h]

  if ( plr[p]._pInvincible )
    return 0;
  if ( mtype == 53 )
    return 0;
  v9 = missiledata[mtype].mResist;
  switch ( v9 )
  {
    case 1:
      v12 = plr[p]._pFireResist;
      break;
    case 2:
      v12 = plr[p]._pLghtResist;
      break;
    case 3:
      v12 = plr[p]._pMagResist;
      break;
    default:
      v12 = 0;
      break;
  }
  v18 = random(69, 100);
  if ( missiledata[mtype].mType )
  {
    v16 = plr[pnum]._pMagic + 50 - 2 * plr[p]._pLevel - dist;
    if ( plr[pnum]._pClass == 2 )
      v16 += 20;
  }
  else
  {
    v16 = plr[pnum]._pIBonusToHit
        + (plr[pnum]._pDexterity >> 1)
        + plr[pnum]._pLevel
        + 50
        - (plr[p]._pIAC
         + plr[p]._pIBonusAC
         + plr[p]._pArmorClass)
        - (dist * dist >> 1);
    if ( plr[pnum]._pClass == 1 )
      v16 += 20;
  }
  if ( v16 < 5 )
    v16 = 5;
  if ( v16 > 95 )
    v16 = 95;
  if ( v16 <= v18 )
    return 0;
  if ( plr[p]._pmode && plr[p]._pmode != 4 || !plr[p]._pBlockFlag )
    v17 = 100;
  else
    v17 = random(73, 100);
  v15 = plr[p]._pDexterity + plr[p]._pBaseToBlk - 2 * (plr[pnum]._pLevel - plr[p]._pLevel);
  if ( v15 < 0 )
    v15 = 0;
  if ( v15 > 100 )
    v15 = 100;
  dwDam = random(70, maxdam - mindam + 1) + mindam;
  if ( !missiledata[mtype].mType )
    dwDam += plr[pnum]._pDamageMod + plr[pnum]._pIBonusDamMod + dwDam * plr[pnum]._pIBonusDam / 100;
  if ( !shift )
    dwDam <<= 6;
  if ( v12 <= 0 )
  {
    if ( v17 >= v15 )
    {
      if ( myplr == pnum )
        NetSendCmdDamage(1u, p, dwDam);
      StartPlrHit(p, dwDam);
      result = 1;
    }
    else
    {
      dir = GetDirection(plr[p].WorldX, plr[p].WorldY, plr[pnum].WorldX, plr[pnum].WorldY);
      StartPlrBlock(p, dir);
      result = 1;
    }
  }
  else
  {
    dwDama = dwDam - v12 * dwDam / 100;
    if ( myplr == pnum )
      NetSendCmdDamage(1u, p, dwDama);
    PlaySfxLoc(48, plr[p].WorldX, plr[p].WorldY);
    result = 1;
  }
  return result;
}

//----- (0043DF1C) --------------------------------------------------------
void __fastcall CheckMissileCol(int i, int mindam, int maxdam, bool shift, int mx, int my, BYTE nodel)
{
  int oi; // [esp+14h] [ebp-8h]

  if ( missile[i]._miAnimType != 4 && missile[i]._misource != -1 )
  {
    if ( missile[i]._micaster )
    {
      if ( monster[missile[i]._misource]._mFlags & 0x10
        && dMonster[mx][my] > 0
        && monster[dMonster[mx][my] - 1]._mFlags & 0x20
        && MonsterTrapHit(dMonster[mx][my] - 1, mindam, maxdam, missile[i]._midist, missile[i]._mitype, shift) )
      {
        if ( !nodel )
          missile[i]._mirange = 0;
        missile[i]._miHitFlag = 1;
      }
      if ( dPlayer[mx][my] > 0
        && PlayerMHit(
             dPlayer[mx][my] - 1,
             missile[i]._misource,
             missile[i]._midist,
             mindam,
             maxdam,
             missile[i]._mitype,
             shift) )
      {
        if ( !nodel )
          missile[i]._mirange = 0;
        missile[i]._miHitFlag = 1;
      }
    }
    else
    {
      if ( dMonster[mx][my] <= 0 )
      {
        if ( dMonster[mx][my] < 0
          && monster[-(dMonster[mx][my] + 1)]._mmode == 15
          && MonsterMHit(
               missile[i]._misource,
               -(dMonster[mx][my] + 1),
               mindam,
               maxdam,
               missile[i]._midist,
               missile[i]._mitype,
               shift) )
        {
          if ( !nodel )
            missile[i]._mirange = 0;
          missile[i]._miHitFlag = 1;
        }
      }
      else if ( MonsterMHit(
                  missile[i]._misource,
                  dMonster[mx][my] - 1,
                  mindam,
                  maxdam,
                  missile[i]._midist,
                  missile[i]._mitype,
                  shift) )
      {
        if ( !nodel )
          missile[i]._mirange = 0;
        missile[i]._miHitFlag = 1;
      }
      if ( dPlayer[mx][my] > 0
        && dPlayer[mx][my] - 1 != missile[i]._misource
        && Plr2PlrMHit(
             missile[i]._misource,
             dPlayer[mx][my] - 1,
             mindam,
             maxdam,
             missile[i]._midist,
             missile[i]._mitype,
             shift) )
      {
        if ( !nodel )
          missile[i]._mirange = 0;
        missile[i]._miHitFlag = 1;
      }
    }
  }
  else
  {
    if ( dMonster[mx][my] > 0 )
    {
      if ( missile[i]._miAnimType == 4 )
      {
        if ( MonsterMHit(
               missile[i]._misource,
               dMonster[mx][my] - 1,
               mindam,
               maxdam,
               missile[i]._midist,
               missile[i]._mitype,
               shift) )
        {
          if ( !nodel )
            missile[i]._mirange = 0;
          missile[i]._miHitFlag = 1;
        }
      }
      else if ( MonsterTrapHit(dMonster[mx][my] - 1, mindam, maxdam, missile[i]._midist, missile[i]._mitype, shift) )
      {
        if ( !nodel )
          missile[i]._mirange = 0;
        missile[i]._miHitFlag = 1;
      }
    }
    if ( dPlayer[mx][my] > 0
      && PlayerMHit(dPlayer[mx][my] - 1, -1, missile[i]._midist, mindam, maxdam, missile[i]._mitype, shift) )
    {
      if ( !nodel )
        missile[i]._mirange = 0;
      missile[i]._miHitFlag = 1;
    }
  }
  if ( dObject[mx][my] )
  {
    oi = dObject[mx][my] <= 0 ? -(dObject[mx][my] + 1) : dObject[mx][my] - 1;
    if ( !object[oi]._oMissFlag )
    {
      if ( object[oi]._oBreak == 1 )
        BreakObject(-1, oi);
      if ( !nodel )
        missile[i]._mirange = 0;
      missile[i]._miHitFlag = 0;
    }
  }
  if ( nMissileTable[dPiece[mx][my]] )
  {
    if ( !nodel )
      missile[i]._mirange = 0;
    missile[i]._miHitFlag = 0;
  }
  if ( !missile[i]._mirange && missiledata[missile[i]._mitype].miSFX != -1 )
    PlaySfxLoc(missiledata[missile[i]._mitype].miSFX, missile[i]._mix, missile[i]._miy);
}

//----- (0043E8BA) --------------------------------------------------------
void __fastcall SetMissAnim(int mi, int animtype)
{
  int v2; // ST14_4

  v2 = missile[mi]._mimfnum;
  missile[mi]._miAnimType = animtype;
  missile[mi]._miAnimFlags = misfiledata[animtype].mFlags;
  missile[mi]._miAnimData = misfiledata[animtype].mAnimData[v2];
  missile[mi]._miAnimDelay = misfiledata[animtype].mAnimDelay[v2];
  missile[mi]._miAnimLen = misfiledata[animtype].mAnimLen[v2];
  missile[mi]._miAnimWidth = misfiledata[animtype].mAnimWidth[v2];
  missile[mi]._miAnimWidth2 = misfiledata[animtype].mAnimWidth2[v2];
  missile[mi]._miAnimCnt = 0;
  missile[mi]._miAnimFrame = 1;
}

//----- (0043EA59) --------------------------------------------------------
void __fastcall SetMissDir(int mi, int dir)
{
  missile[mi]._mimfnum = dir;
  SetMissAnim(mi, missile[mi]._miAnimType);
}

//----- (0043EAA9) --------------------------------------------------------
void __fastcall LoadMissileGFX(BYTE mi)
{
  unsigned __int8 *v1; // eax
  char pszName[256]; // [esp+10h] [ebp-108h]
  int i; // [esp+110h] [ebp-8h]
  unsigned __int8 *v5; // [esp+114h] [ebp-4h]

  if ( misfiledata[mi].mFlags & 4 )
  {
    sprintf(pszName, "Missiles\\%s.CEL", misfiledata[mi].mName);
    v5 = LoadFileInMem(pszName, 0, 866, "MISSILES.CPP");
    for ( i = 0; misfiledata[mi].mAnimFAmt > i; ++i )
      misfiledata[mi].mAnimData[i] = &v5[*(_DWORD *)&v5[4 * i]];
  }
  else if ( misfiledata[mi].mAnimFAmt == 1 )
  {
    sprintf(pszName, "Missiles\\%s.CEL", misfiledata[mi].mName);
    if ( !misfiledata[mi].mAnimData[0] )
      misfiledata[mi].mAnimData[0] = LoadFileInMem(pszName, 0, 874, "MISSILES.CPP");
  }
  else
  {
    for ( i = 0; misfiledata[mi].mAnimFAmt > i; ++i )
    {
      sprintf(pszName, "Missiles\\%s%i.CEL", misfiledata[mi].mName, i + 1);
      if ( !misfiledata[mi].mAnimData[i] )
      {
        v1 = LoadFileInMem(pszName, 0, 879, "MISSILES.CPP");
        misfiledata[mi].mAnimData[i] = v1;
      }
    }
  }
}

//----- (0043ED27) --------------------------------------------------------
void __cdecl InitMissileGFX()
{
  int mi; // [esp+Ch] [ebp-4h]

  for ( mi = 0; misfiledata[mi].mAnimFAmt; ++mi )
  {
    if ( !(misfiledata[mi].mFlags & 1) )
      LoadMissileGFX(mi);
  }
}

//----- (0043ED95) --------------------------------------------------------
void __fastcall FreeMissileGFX(int mi)
{
  signed int i; // [esp+10h] [ebp-4h]

  if ( misfiledata[mi].mFlags & 4 )
  {
    if ( misfiledata[mi].mAnimData[0] )
    {
      mem_free_dbg(
        &misfiledata[mi].mAnimData[0][-4 * misfiledata[mi].mAnimFAmt],
        907,
        "MISSILES.CPP");
      misfiledata[mi].mAnimData[0] = 0;
    }
  }
  else
  {
    for ( i = 0; misfiledata[mi].mAnimFAmt > i; ++i )
    {
      if ( misfiledata[mi].mAnimData[i] )
      {
        mem_free_dbg(misfiledata[mi].mAnimData[i], 916, "MISSILES.CPP");
        misfiledata[mi].mAnimData[i] = 0;
      }
    }
  }
}

//----- (0043EEF8) --------------------------------------------------------
void __cdecl FreeMissiles()
{
  int mi; // [esp+Ch] [ebp-4h]

  for ( mi = 0; misfiledata[mi].mAnimFAmt; ++mi )
  {
    if ( !(misfiledata[mi].mFlags & 1) )
      FreeMissileGFX(mi);
  }
}

//----- (0043EF66) --------------------------------------------------------
void __cdecl FreeMissiles2()
{
  int mi; // [esp+Ch] [ebp-4h]

  for ( mi = 0; misfiledata[mi].mAnimFAmt; ++mi )
  {
    if ( misfiledata[mi].mFlags & 1 )
      FreeMissileGFX(mi);
  }
}

//----- (0043EFD4) --------------------------------------------------------
void __cdecl InitMissiles()
{
  int i; // [esp+Ch] [ebp-4h]
  signed int j; // [esp+Ch] [ebp-4h]

  nummissiles = 0;
  for ( i = 0; i < 125; ++i )
  {
    missilevail[i] = i;
    missileactive[i] = 0;
  }
  Xunusedmissileflag = 0;
  for ( j = 0; j < 125; ++j )
  {
    Xunusedmissiledata[j][0] = -1;
    Xunusedmissiledata[j][1] = 0;
    Xunusedmissiledata[j][2] = 0;
  }
}

//----- (0043F085) --------------------------------------------------------
void __fastcall AddLArrow(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v9; // eax

  if ( dx == sx && dy == sy )
  {
    dx += XDirAdd[midir];
    dy += YDirAdd[midir];
  }
  if ( (_BYTE)mienemy )
  {
    GetMissileVel(mi, sx, sy, dx, dy, 32);
  }
  else if ( plr[id]._pClass == 1 )
  {
    GetMissileVel(mi, sx, sy, dx, dy, plr[id]._pLevel + 31);
  }
  else
  {
    GetMissileVel(mi, sx, sy, dx, dy, 32);
  }
  v9 = GetDirection16(sx, sy, dx, dy);
  SetMissDir(mi, v9);
  missile[mi]._mirange = 256;
  missile[mi]._miVar1 = sx;
  missile[mi]._miVar2 = sy;
  missile[mi]._mlid = AddLight(sx, sy, 5);
  PutMissile(mi);
}

//----- (0043F20A) --------------------------------------------------------
void __fastcall AddArrow(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v; // [esp+14h] [ebp-4h]

  if ( dx == sx && dy == sy )
  {
    dx += XDirAdd[midir];
    dy += YDirAdd[midir];
  }
  if ( (_BYTE)mienemy )
  {
    GetMissileVel(mi, sx, sy, dx, dy, 32);
  }
  else
  {
    v = 32;
    if ( plr[id]._pIFlags & 4 )
      v = random(64, 32) + 16;
    if ( plr[id]._pClass == 1 )
      v += plr[id]._pLevel - 1;
    GetMissileVel(mi, sx, sy, dx, dy, v);
  }
  missile[mi]._miAnimFrame = GetDirection16(sx, sy, dx, dy) + 1;
  missile[mi]._mirange = 256;
  PutMissile(mi);
}

//----- (0043F36F) --------------------------------------------------------
void __fastcall AddRndTeleport(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v11; // [esp+18h] [ebp-8h]
  int v12; // [esp+1Ch] [ebp-4h]

  do
  {
    v12 = random(58, 3) + 4;
    v11 = random(58, 3) + 4;
    if ( random(58, 2) == 1 )
      v12 = -v12;
    if ( random(58, 2) == 1 )
      v11 = -v11;
  }
  while ( nSolidTable[dPiece[sx + v12][sy + v11]] || dObject[sx + v12][sy + v11] || dMonster[sx + v12][sy + v11] );
  missile[mi]._mix = sx + v12;
  missile[mi]._miy = sy + v11;
  missile[mi]._mirange = 2;
  missile[mi]._miVar1 = 0;
  UseMana(id, 10);
}

//----- (0043F4E6) --------------------------------------------------------
void __fastcall AddFirebolt(int mi, int sx, int sy, int dx, int dy, int midir, int micaster, int id, int dam)
{
  int v9; // eax
  int v; // [esp+14h] [ebp-4h]

  if ( dx == sx && dy == sy )
  {
    dx += XDirAdd[midir];
    dy += YDirAdd[midir];
  }
  UseMana(id, 1);
  if ( id == -1 )
  {
    v = 16;
  }
  else
  {
    v = 2 * GetSpellLevel(id, 1) + 16;
    if ( v >= 63 )
      v = 63;
  }
  GetMissileVel(mi, sx, sy, dx, dy, v);
  v9 = GetDirection16(sx, sy, dx, dy);
  SetMissDir(mi, v9);
  missile[mi]._mirange = 256;
  missile[mi]._miVar1 = sx;
  missile[mi]._miVar2 = sy;
  missile[mi]._mlid = AddLight(sx, sy, 8);
  PutMissile(mi);
}

//----- (0043F627) --------------------------------------------------------
void __fastcall AddMagmaball(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  GetMissileVel(mi, sx, sy, dx, dy, 16);
  missile[mi]._mitxoff += 3 * missile[mi]._mixvel;
  missile[mi]._mityoff += 3 * missile[mi]._miyvel;
  GetMissilePos(mi);
  missile[mi]._mirange = 256;
  missile[mi]._miVar1 = sx;
  missile[mi]._miVar2 = sy;
  missile[mi]._mlid = AddLight(sx, sy, 8);
  PutMissile(mi);
}

//----- (0043F730) --------------------------------------------------------
void __fastcall miss_null_33(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  GetMissileVel(mi, sx, sy, dx, dy, 16);
  missile[mi]._mirange = 256;
  missile[mi]._miVar1 = sx;
  missile[mi]._miVar2 = sy;
  PutMissile(mi);
}

//----- (0043F7B5) --------------------------------------------------------
void __fastcall AddTeleport(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int i; // [esp+14h] [ebp-Ch]
  int v11; // [esp+18h] [ebp-8h]
  int v12; // [esp+1Ch] [ebp-4h]

  missile[mi]._miVar1 = 1;
  if ( !nSolidTable[dPiece[dx][dy]] && !dObject[dx][dy] && !dMonster[dx][dy] )
    missile[mi]._miVar1 = 0;
  for ( i = 0; nummissiles > i; ++i )
  {
    v12 = missileactive[i];
    if ( missile[v12]._mitype == 26 && missile[v12]._misource == id )
      break;
  }
  if ( nummissiles == i )
  {
    v11 = 0;
    UseMana(id, 23);
  }
  else
  {
    v11 = missile[v12]._mirange;
    missile[v12]._mirange = 0;
  }
  missile[mi]._mix = dx;
  missile[mi]._miy = dy;
  if ( v11 )
  {
    missile[mi]._mirange = v11;
  }
  else
  {
    missile[mi]._mirange = 16 * plr[id]._pLevel;
    missile[mi]._mirange += plr[id]._pISplDur * missile[mi]._mirange >> 7;
  }
}

//----- (0043FA0D) --------------------------------------------------------
void __fastcall AddLightball(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  GetMissileVel(mi, sx, sy, dx, dy, 16);
  missile[mi]._midam = dam;
  missile[mi]._miAnimFrame = random(63, 8) + 1;
  missile[mi]._mirange = 255;
  PutMissile(mi);
}

//----- (0043FA9F) --------------------------------------------------------
void __fastcall AddFirewall(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v10; // ebx
  int v11; // ebx
  int j; // [esp+14h] [ebp-4h]

  v10 = plr[id]._pLevel;
  v11 = random(53, 10) + v10;
  missile[mi]._midam = 2 * (random(53, 10) + v11) + 4;
  GetMissileVel(mi, sx, sy, dx, dy, 16);
  missile[mi]._mirange = 80 * plr[id]._pLevel;
  for ( j = GetSpellLevel(id, 6); j > 0; --j )
    missile[mi]._mirange += missile[mi]._mirange >> 3;
  missile[mi]._mirange += plr[id]._pISplDur * missile[mi]._mirange >> 7;
  missile[mi]._miVar1 = missile[mi]._mirange - missile[mi]._miAnimLen;
  missile[mi]._miVar2 = 0;
  PutMissile(mi);
}

//----- (0043FC87) --------------------------------------------------------
void __fastcall AddFireball(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v9; // ebx
  int v10; // ebx
  int v11; // eax
  int v; // [esp+14h] [ebp-4h]
  int va; // [esp+14h] [ebp-4h]

  if ( dx == sx && dy == sy )
  {
    dx += XDirAdd[midir];
    dy += YDirAdd[midir];
  }
  v9 = plr[id]._pLevel;
  v10 = random(60, 10) + v9;
  missile[mi]._midam = random(60, 10) + v10 + 2;
  for ( v = GetSpellLevel(id, 12); v > 0; --v )
    missile[mi]._midam += missile[mi]._midam >> 3;
  va = 2 * GetSpellLevel(id, 12) + 16;
  if ( va > 50 )
    va = 50;
  GetMissileVel(mi, sx, sy, dx, dy, va);
  v11 = GetDirection16(sx, sy, dx, dy);
  SetMissDir(mi, v11);
  missile[mi]._mirange = 256;
  missile[mi]._miVar1 = sx;
  missile[mi]._miVar2 = sy;
  missile[mi]._miVar3 = 0;
  missile[mi]._mlid = AddLight(sx, sy, 8);
  UseMana(id, 12);
}

//----- (0043FE6F) --------------------------------------------------------
void __fastcall AddLightctrl(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  if ( !dam )
    UseMana(id, 3);
  missile[mi]._miVar1 = sx;
  missile[mi]._miVar2 = sy;
  GetMissileVel(mi, sx, sy, dx, dy, 32);
  missile[mi]._miAnimFrame = random(52, 8) + 1;
  missile[mi]._mirange = 256;
}

//----- (0043FF28) --------------------------------------------------------
void __fastcall AddLightning(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._misx = dx;
  missile[mi]._misy = dy;
  if ( midir >= 0 )
  {
    missile[mi]._mixoff = missile[midir]._mixoff;
    missile[mi]._miyoff = missile[midir]._miyoff;
    missile[mi]._mitxoff = missile[midir]._mitxoff;
    missile[mi]._mityoff = missile[midir]._mityoff;
  }
  missile[mi]._miAnimFrame = random(52, 8) + 1;
  if ( midir < 0 || (char)mienemy == 1 || id == -1 )
  {
    if ( midir < 0 || id == -1 )
      missile[mi]._mirange = 8;
    else
      missile[mi]._mirange = 10;
  }
  else
  {
    missile[mi]._mirange = GetSpellLevel(id, 3) + 6;
  }
  missile[mi]._mlid = AddLight(missile[mi]._mix, missile[mi]._miy, 4);
  PutMissile(mi);
}

//----- (0044012E) --------------------------------------------------------
void __fastcall AddMisexp(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._mix = missile[dx]._mix;
  missile[mi]._miy = missile[dx]._miy;
  missile[mi]._misx = missile[dx]._misx;
  missile[mi]._misy = missile[dx]._misy;
  missile[mi]._mixoff = missile[dx]._mixoff;
  missile[mi]._miyoff = missile[dx]._miyoff;
  missile[mi]._mitxoff = missile[dx]._mitxoff;
  missile[mi]._mityoff = missile[dx]._mityoff;
  missile[mi]._mixvel = 0;
  missile[mi]._miyvel = 0;
  missile[mi]._mirange = missile[mi]._miAnimLen;
  missile[mi]._miVar1 = 0;
  PutMissile(mi);
}

//----- (00440316) --------------------------------------------------------
void __fastcall AddWeapexp(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._mix = sx;
  missile[mi]._miy = sy;
  missile[mi]._misx = sx;
  missile[mi]._misy = sy;
  missile[mi]._mixvel = 0;
  missile[mi]._miyvel = 0;
  missile[mi]._miVar1 = 0;
  missile[mi]._mimfnum = 0;
  if ( dx == 1 )
    SetMissAnim(mi, 5);
  else
    SetMissAnim(mi, 27);
  missile[mi]._mirange = missile[mi]._miAnimLen - 1;
}

//----- (00440449) --------------------------------------------------------
void __fastcall AddTown(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v9; // eax
  int x; // [esp+14h] [ebp-1Ch]
  int v13; // [esp+18h] [ebp-18h]
  signed int v14; // [esp+1Ch] [ebp-14h]
  int j; // [esp+20h] [ebp-10h]
  int v16; // [esp+28h] [ebp-8h]
  int y; // [esp+2Ch] [ebp-4h]

  v14 = 1;
  x = dx;
  y = dy;
  if ( currlevel )
  {
    while ( v14 == 1 )
    {
      v14 = 0;
      if ( nSolidTable[dPiece[x][y]] )
        v14 = 1;
      if ( dMonster[x][y] )
        v14 = 1;
      if ( dObject[x][y] )
        v14 = 1;
      if ( dItem[x][y] )
        v14 = 1;
      if ( sx == x && sy == y )
        v14 = 1;
      v13 = random(54, 7);
      if ( v14 == 1 )
      {
        x += XDirAdd[v13];
        y += YDirAdd[v13];
      }
    }
  }
  missile[mi]._mix = x;
  missile[mi]._miy = y;
  missile[mi]._misx = x;
  missile[mi]._misy = y;
  missile[mi]._mirange = 100;
  missile[mi]._miVar1 = missile[mi]._mirange - missile[mi]._miAnimLen;
  missile[mi]._miVar2 = 0;
  for ( j = 0; j < nummissiles; ++j )
  {
    v16 = missileactive[j];
    if ( missile[v16]._mitype == 10 && v16 != mi && missile[v16]._misource == id )
      missile[v16]._mirange = 0;
  }
  PutMissile(mi);
  if ( id == myplr )
  {
    v9 = (unsigned __int8)setlevel;
    if ( setlevel )
    {
      LOBYTE(v9) = setlvlnum;
      NetSendCmdLocParam2(1u, 0x3Bu, x, y, v9 & 0xFFFF00FF, 1);
    }
    else
    {
      LOBYTE(v9) = currlevel;
      NetSendCmdLocParam2(1u, 0x3Bu, x, y, v9 & 0xFFFF00FF, 0);
    }
  }
}

//----- (00440779) --------------------------------------------------------
void __fastcall AddFlash(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  signed int j; // [esp+14h] [ebp-4h]
  int k; // [esp+14h] [ebp-4h]

  missile[mi]._midam = 0;
  for ( j = 0; plr[id]._pLevel >= j; ++j )
    missile[mi]._midam += random(55, 2) + 1;
  for ( k = GetSpellLevel(id, 4); k > 0; --k )
    missile[mi]._midam += missile[mi]._midam >> 3;
  missile[mi]._mirange = 19;
  UseMana(id, 4);
  PutMissile(mi);
}

//----- (0044088F) --------------------------------------------------------
void __fastcall AddFlash2(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  signed int j; // [esp+14h] [ebp-4h]
  int k; // [esp+14h] [ebp-4h]

  missile[mi]._midam = 0;
  for ( j = 0; plr[id]._pLevel >= j; ++j )
    missile[mi]._midam += random(56, 2) + 1;
  for ( k = GetSpellLevel(id, 4); k > 0; --k )
    missile[mi]._midam += missile[mi]._midam >> 3;
  missile[mi]._miPreFlag = 1;
  missile[mi]._mirange = 19;
  PutMissile(mi);
}

//----- (004409B1) --------------------------------------------------------
void __fastcall AddManashield(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._mirange = 255;
  missile[mi]._miVar1 = plr[id]._pHitPoints;
  missile[mi]._miVar2 = plr[id]._pHPBase;
  UseMana(id, 11);
  PutMissile(mi);
}

//----- (00440A5E) --------------------------------------------------------
void __fastcall AddFiremove(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v11; // ebx

  v11 = plr[id]._pLevel;
  missile[mi]._midam = random(59, 10) + v11 + 1;
  GetMissileVel(mi, sx, sy, dx, dy, 16);
  missile[mi]._mirange = 255;
  missile[mi]._miVar1 = 0;
  missile[mi]._miVar2 = 0;
  PutMissile(mi);
}

//----- (00440B2A) --------------------------------------------------------
void __fastcall AddGuardian(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miDelFlag = 1;
}

//----- (00440B5E) --------------------------------------------------------
void __fastcall AddChain(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miVar1 = dx;
  missile[mi]._miVar2 = dy;
  missile[mi]._mirange = 1;
  UseMana(id, 14);
}

//----- (00440BCF) --------------------------------------------------------
void __fastcall miss_null_11(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  SetMissDir(mi, dx);
  missile[mi]._midam = 0;
  missile[mi]._miLightFlag = 1;
  missile[mi]._mirange = 250;
  PutMissile(mi);
}

//----- (00440C48) --------------------------------------------------------
void __fastcall miss_null_12(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  if ( dx > 3 )
    dx = 2;
  SetMissDir(mi, dx);
  missile[mi]._midam = 0;
  missile[mi]._miLightFlag = 1;
  missile[mi]._mirange = 250;
  PutMissile(mi);
}

//----- (00440CD2) --------------------------------------------------------
void __fastcall miss_null_13(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  if ( dx > 3 )
    dx = 2;
  SetMissDir(mi, dx);
  missile[mi]._midam = 0;
  missile[mi]._miLightFlag = 1;
  missile[mi]._mirange = missile[mi]._miAnimLen;
  PutMissile(mi);
}

//----- (00440D6D) --------------------------------------------------------
void __fastcall AddRhino(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  AnimStruct *v10; // [esp+14h] [ebp-4h]

  if ( (signed int)monster[id].MType->mtype < 64 || (signed int)monster[id].MType->mtype > 67 )
    v10 = &monster[id].MType->Anims[1];
  else
    v10 = &monster[id].MType->Anims[5];
  GetMissileVel(mi, sx, sy, dx, dy, 16);
  missile[mi]._mimfnum = midir;
  missile[mi]._miAnimFlags = 0;
  missile[mi]._miAnimData = v10->Frames[midir];
  missile[mi]._miAnimDelay = v10->Delay;
  missile[mi]._miAnimLen = v10->Rate;
  missile[mi]._miAnimWidth = monster[id].MType->flags_1;
  missile[mi]._miAnimWidth2 = monster[id].MType->flags_2;
  missile[mi]._miAnimAdd = 1;
  missile[mi]._miVar1 = 0;
  missile[mi]._miVar2 = 0;
  missile[mi]._miLightFlag = 1;
  if ( monster[id]._uniqtype )
    missile[mi]._miUniqTrans = (unsigned __int8)monster[id]._uniqtrans + 1;
  missile[mi]._mirange = 256;
  PutMissile(mi);
}

//----- (00440FD1) --------------------------------------------------------
void __fastcall miss_null_32(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  AnimStruct *v9; // ST24_4

  v9 = &monster[id].MType->Anims[1];
  GetMissileVel(mi, sx, sy, dx, dy, 16);
  missile[mi]._mimfnum = midir;
  missile[mi]._miAnimFlags = 0;
  missile[mi]._miAnimData = v9->Frames[midir];
  missile[mi]._miAnimDelay = v9->Delay;
  missile[mi]._miAnimLen = v9->Rate;
  missile[mi]._miAnimWidth = monster[id].MType->flags_1;
  missile[mi]._miAnimWidth2 = monster[id].MType->flags_2;
  missile[mi]._miAnimAdd = 1;
  missile[mi]._miVar1 = 0;
  missile[mi]._miVar2 = 0;
  missile[mi]._miLightFlag = 1;
  if ( monster[id]._uniqtype )
    missile[mi]._miUniqTrans = (unsigned __int8)monster[id]._uniqtrans + 1;
  dMonster[monster[id]._mx][monster[id]._my] = 0;
  missile[mi]._mirange = 256;
  PutMissile(mi);
}

//----- (0044120F) --------------------------------------------------------
void __fastcall AddFlare(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int j; // [esp+14h] [ebp-8h]
  signed int v12; // [esp+18h] [ebp-4h]

  GetMissileVel(mi, sx, sy, dx, dy, 16);
  missile[mi]._mirange = 256;
  missile[mi]._miVar1 = sx;
  missile[mi]._miVar2 = sy;
  missile[mi]._mlid = AddLight(sx, sy, 8);
  if ( !(_BYTE)mienemy )
  {
    UseMana(id, 35);
    v12 = 25;
    for ( j = GetSpellLevel(id, 35); j < 0; ++j )
      v12 -= 4;
    if ( v12 <= 0 )
      v12 = 1;
    plr[id]._pHitPoints -= v12 << 6;
    plr[id]._pHPBase -= v12 << 6;
    drawhpflag = 1;
    if ( plr[id]._pHitPoints <= 0 )
    {
      plr[id]._pHitPoints = 0;
      SyncPlrKill(id);
    }
  }
  PutMissile(mi);
}

//----- (004413BB) --------------------------------------------------------
void __fastcall AddAcid(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v11; // eax

  GetMissileVel(mi, sx, sy, dx, dy, 16);
  v11 = GetDirection16(sx, sy, dx, dy);
  SetMissDir(mi, v11);
  missile[mi]._mirange = 5 * monster[id]._mint + 20;
  missile[mi]._mlid = -1;
  missile[mi]._miVar1 = sx;
  missile[mi]._miVar2 = sy;
  PutMissile(mi);
}

//----- (0044148F) --------------------------------------------------------
void __fastcall miss_null_1D(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._midam = dam;
  missile[mi]._mixvel = 0;
  missile[mi]._miyvel = 0;
  missile[mi]._mirange = 50;
  missile[mi]._miVar1 = missile[mi]._mirange - missile[mi]._miAnimLen;
  missile[mi]._miVar2 = 0;
  PutMissile(mi);
}

//----- (0044156D) --------------------------------------------------------
void __fastcall AddAcidpud(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v10; // ebx

  missile[mi]._mixvel = 0;
  missile[mi]._miyvel = 0;
  missile[mi]._mixoff = 0;
  missile[mi]._miyoff = 0;
  missile[mi]._miLightFlag = 1;
  v10 = 5 * monster[missile[mi]._misource]._mint + 5;
  missile[mi]._mirange = random(50, 15) + 8 * v10;
  missile[mi]._miPreFlag = 1;
}

//----- (00441677) --------------------------------------------------------
void __fastcall AddStone(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v9; // ST14_4
  signed int i; // [esp+18h] [ebp-28h]
  int v12; // [esp+1Ch] [ebp-24h]
  int CrawlNum[6]; // [esp+20h] [ebp-20h]
  int j; // [esp+38h] [ebp-8h]
  int v15; // [esp+3Ch] [ebp-4h]

  CrawlNum[0] = 0;
  CrawlNum[1] = 3;
  CrawlNum[2] = 12;
  CrawlNum[3] = 45;
  CrawlNum[4] = 94;
  CrawlNum[5] = 159;
  missile[mi]._misource = id;
  for ( i = 0; i < 6; ++i )
  {
    v9 = CrawlNum[i];
    v12 = v9 + 1;
    for ( j = (unsigned __int8)CrawlTable[v9]; j > 0; --j )
    {
      v15 = dMonster[dx + CrawlTable[v12]][dy + CrawlTable[v12 + 1]];
      if ( v15 <= 0 )
        v15 = -(v15 + 1);
      else
        --v15;
      if ( v15 > 0 )
      {
        j = -99;
        i = 6;
        missile[mi]._miVar1 = monster[v15]._mmode;
        missile[mi]._miVar2 = v15;
        monster[v15]._mmode = 15;
        break;
      }
      v12 += 2;
    }
  }
  if ( j == -99 )
  {
    missile[mi]._mix = dx + CrawlTable[v12];
    missile[mi]._miy = dy + CrawlTable[v12 + 1];
    missile[mi]._misx = missile[mi]._mix;
    missile[mi]._misy = missile[mi]._miy;
    missile[mi]._mirange = 16 * plr[id]._pLevel;
    for ( j = GetSpellLevel(id, 8); j > 0; --j )
      missile[mi]._mirange += 16 * missile[mi]._mirange >> 3;
    missile[mi]._mirange += plr[id]._pISplDur * missile[mi]._mirange >> 7;
    UseMana(id, 8);
  }
  else
  {
    missile[mi]._miDelFlag = 1;
  }
}

//----- (00441990) --------------------------------------------------------
void __fastcall AddGolem(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int i; // [esp+14h] [ebp-8h]

  missile[mi]._mirange = 32 * plr[id]._pLevel;
  for ( i = GetSpellLevel(id, 21); i > 0; --i )
    missile[mi]._mirange += 16 * missile[mi]._mirange >> 3;
  missile[mi]._mirange += missile[mi]._mirange * plr[id]._pISplDur >> 7;
  if ( dFlags[dx][dy] & 0x40 && !((unsigned __int8)nSolidTable[dPiece[dx][dy]] | dMonster[dx][dy] | dObject[dx][dy]) )
  {
    SpawnGolum(dx, dy, missile[mi]._mirange);
    UseMana(id, 21);
  }
  missile[mi]._miDelFlag = 1;
}

//----- (00441B46) --------------------------------------------------------
void __fastcall AddEtherealize(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miDelFlag = 1;
}

//----- (00441B7A) --------------------------------------------------------
void __fastcall miss_null_1F(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miDelFlag = 1;
}

//----- (00441BAE) --------------------------------------------------------
void __fastcall miss_null_23(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._midam = dam;
  missile[mi]._mix = sx;
  missile[mi]._miy = sy;
  missile[mi]._misx = sx;
  missile[mi]._misy = sy;
  missile[mi]._misource = id;
  if ( dam == 1 )
    SetMissDir(mi, 0);
  else
    SetMissDir(mi, 1);
  missile[mi]._miLightFlag = 1;
  missile[mi]._mirange = missile[mi]._miAnimLen;
  PutMissile(mi);
}

//----- (00441CCA) --------------------------------------------------------
void __fastcall AddBoom(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._mix = sx;
  missile[mi]._miy = sy;
  missile[mi]._misx = sx;
  missile[mi]._misy = sy;
  missile[mi]._mixvel = 0;
  missile[mi]._miyvel = 0;
  missile[mi]._midam = dam;
  missile[mi]._mirange = missile[mi]._miAnimLen;
  missile[mi]._miVar1 = 0;
  PutMissile(mi);
}

//----- (00441DDA) --------------------------------------------------------
void __fastcall AddHeal(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v10; // [esp+14h] [ebp-8h]
  signed int j; // [esp+18h] [ebp-4h]
  int k; // [esp+18h] [ebp-4h]

  v10 = (random(57, 10) + 1) << 6;
  for ( j = 0; plr[id]._pLevel > j; ++j )
    v10 += (random(57, 4) + 1) << 6;
  for ( k = 0; GetSpellLevel(id, 2) > k; ++k )
    v10 += (random(57, 6) + 1) << 6;
  if ( !plr[id]._pClass )
    v10 *= 2;
  if ( plr[id]._pClass == 1 )
    v10 += v10 >> 1;
  plr[id]._pHitPoints += v10;
  if ( plr[id]._pHitPoints > plr[id]._pMaxHP )
    plr[id]._pHitPoints = plr[id]._pMaxHP;
  plr[id]._pHPBase += v10;
  if ( plr[id]._pMaxHPBase < plr[id]._pHPBase )
    plr[id]._pHPBase = plr[id]._pMaxHPBase;
  UseMana(id, 2);
  drawhpflag = 1;
  missile[mi]._miDelFlag = 1;
  PutMissile(mi);
}

//----- (00442060) --------------------------------------------------------
void __fastcall AddHealOther(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miDelFlag = 1;
  UseMana(id, 34);
  if ( myplr == id )
    j_SetCursor(10);
}

//----- (004420BA) --------------------------------------------------------
void __fastcall AddElement(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v9; // ST28_4
  int v10; // eax
  signed int j; // [esp+14h] [ebp-8h]
  int k; // [esp+14h] [ebp-8h]
  int x2; // [esp+28h] [ebp+Ch]
  int dya; // [esp+2Ch] [ebp+10h]

  missile[mi]._midam = 0;
  for ( j = 0; plr[id]._pLevel > j; ++j )
    missile[mi]._midam += random(67, 6) + 1;
  for ( k = GetSpellLevel(id, 29); k > 0; --k )
    missile[mi]._midam += plr[id]._pLevel >> 1;
  v9 = FindClosest(sx, sy, 19);
  x2 = monster[v9]._mx;
  dya = monster[v9]._my;
  GetMissileVel(mi, sx, sy, monster[v9]._mx, monster[v9]._my, 16);
  v10 = GetDirection8(sx, sy, x2, dya);
  SetMissDir(mi, v10);
  missile[mi]._mirange = 256;
  missile[mi]._miVar1 = sx;
  missile[mi]._miVar2 = sy;
  missile[mi]._miVar3 = 0;
  missile[mi]._mlid = AddLight(sx, sy, 8);
  UseMana(id, 29);
  PutMissile(mi);
}

//----- (004422B7) --------------------------------------------------------
void __fastcall AddIdentify(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miDelFlag = 1;
  UseMana(id, 5);
  if ( id == myplr )
  {
    if ( sbookflag )
      sbookflag = 0;
    if ( !invflag )
      invflag = 1;
    j_SetCursor(2);
  }
}

//----- (0044233E) --------------------------------------------------------
void __fastcall AddFirewallC(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  char v9; // al

  if ( dFlags[dx][dy] & 0x40 )
  {
    missile[mi]._miVar1 = dx;
    missile[mi]._miVar2 = dy;
    missile[mi]._miVar5 = dx;
    missile[mi]._miVar6 = dy;
    missile[mi]._miVar7 = 0;
    missile[mi]._miVar8 = 0;
    v9 = GetDirection(sx, sy, missile[mi]._miVar1, missile[mi]._miVar2);
    missile[mi]._miVar3 = (v9 - 2) & 7;
    missile[mi]._miVar4 = (v9 + 2) & 7;
    missile[mi]._mirange = 20;
    UseMana(id, 6);
  }
  else
  {
    missile[mi]._miDelFlag = 1;
    PutMissile(mi);
  }
}

//----- (004424CD) --------------------------------------------------------
void __fastcall AddInfra(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._mirange = 255;
  missile[mi]._mirange += plr[id]._pISplDur * missile[mi]._mirange >> 7;
  UseMana(id, 9);
}

//----- (00442559) --------------------------------------------------------
void __fastcall AddWave(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miVar1 = dx;
  missile[mi]._miVar2 = dy;
  missile[mi]._mirange = 1;
  UseMana(id, 15);
}

//----- (004425CA) --------------------------------------------------------
void __fastcall AddNova(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v9; // ebx
  int v10; // ebx
  int v11; // ebx
  int v12; // ebx
  int v13; // ebx
  int v14; // ebx
  int i; // [esp+14h] [ebp-4h]

  missile[mi]._miVar1 = dx;
  missile[mi]._miVar2 = dy;
  if ( id == -1 )
  {
    v13 = random(66, 3);
    v14 = random(66, 3) + v13;
    missile[mi]._midam = random(66, 3) + v14;
    missile[mi]._midam += (signed int)currlevel >> 1;
  }
  else
  {
    v9 = random(66, 6);
    v10 = random(66, 6) + v9;
    v11 = random(66, 6) + v10;
    v12 = random(66, 6) + v11;
    missile[mi]._midam = random(66, 6) + v12;
    missile[mi]._midam += plr[id]._pLevel + 5;
    for ( i = GetSpellLevel(id, 18); i > 0; --i )
      missile[mi]._midam += missile[mi]._midam >> 3;
    UseMana(id, 18);
  }
  missile[mi]._mirange = 1;
}

//----- (004427A4) --------------------------------------------------------
void __fastcall AddBlodboil(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miVar1 = dx;
  missile[mi]._miVar2 = dy;
  missile[mi]._mirange = 1;
}

//----- (00442808) --------------------------------------------------------
void __fastcall AddRepair(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miDelFlag = 1;
  UseMana(id, 26);
  if ( myplr == id )
  {
    if ( sbookflag )
      sbookflag = 0;
    if ( !invflag )
      invflag = 1;
    j_SetCursor(3);
  }
}

//----- (00442890) --------------------------------------------------------
void __fastcall AddRecharge(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miDelFlag = 1;
  UseMana(id, 27);
  if ( myplr == id )
  {
    if ( sbookflag )
      sbookflag = 0;
    if ( !invflag )
      invflag = 1;
    j_SetCursor(4);
  }
}

//----- (00442918) --------------------------------------------------------
void __fastcall AddDisarm(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miDelFlag = 1;
  UseMana(id, 28);
  if ( myplr == id )
    j_SetCursor(5);
}

//----- (00442972) --------------------------------------------------------
void __fastcall AddApoca(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miDelFlag = 1;
}

//----- (004429A6) --------------------------------------------------------
void __fastcall AddFlame(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int i; // [esp+14h] [ebp-4h]
  int j; // [esp+14h] [ebp-4h]

  missile[mi]._mix = sx + XDirAdd[midir];
  missile[mi]._miy = sy + YDirAdd[midir];
  missile[mi]._misx = missile[mi]._mix;
  missile[mi]._misy = missile[mi]._miy;
  missile[mi]._mixvel = 0;
  missile[mi]._miyvel = 0;
  missile[mi]._midam = 4 * plr[id]._pLevel;
  for ( i = GetSpellLevel(id, 20); i > 0; --i )
    missile[mi]._midam += missile[mi]._midam >> 3;
  missile[mi]._midam *= 2;
  missile[mi]._mirange = 0;
  for ( j = 4 - dam; j > 0; --j )
    missile[mi]._mirange += 2 * misfiledata[20].mAnimLen[midir];
  missile[mi]._mirange += misfiledata[21].mAnimLen[midir];
  missile[mi]._miVar1 = missile[mi]._mirange - misfiledata[20].mAnimLen[midir];
  missile[mi]._miVar2 = misfiledata[20].mAnimLen[midir];
  missile[mi]._miVar3 = dam;
  missile[mi]._miVar4 = plr[id].WorldX;
  missile[mi]._miVar5 = plr[id].WorldY;
  missile[mi]._miDelFlag = 0;
}

//----- (00442C98) --------------------------------------------------------
void __fastcall AddFlamec(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._mirange = 1;
  missile[mi]._miVar1 = dx;
  missile[mi]._miVar2 = dy;
  missile[mi]._miDelFlag = 0;
  UseMana(id, 20);
}

//----- (00442D22) --------------------------------------------------------
void __fastcall AddCbolt(int mi, int sx, int sy, int dx, int dy, int midir, int micaster, int id, int dam)
{
  int j; // [esp+14h] [ebp-4h]

  missile[mi]._mirnd = random(63, 15) + 1;
  if ( dx == sx && dy == sy )
  {
    dx += XDirAdd[midir];
    dy += YDirAdd[midir];
  }
  missile[mi]._miAnimFrame = random(63, 8) + 1;
  missile[mi]._mlid = AddLight(sx, sy, 5);
  GetMissileVel(mi, sx, sy, dx, dy, 8);
  missile[mi]._miVar1 = 5;
  missile[mi]._miVar2 = midir;
  missile[mi]._miVar3 = 0;
  missile[mi]._mirange = 256;
  missile[mi]._midam = random(68, plr[id]._pMagic >> 2);
  for ( j = GetSpellLevel(id, 30); j > 0; --j )
    ++missile[mi]._midam;
  PutMissile(mi);
}

//----- (00442F15) --------------------------------------------------------
void __fastcall AddHbolt(int mi, int sx, int sy, int dx, int dy, int midir, int micaster, int id, int dam)
{
  int v9; // eax
  int v10; // ebx
  int v; // [esp+14h] [ebp-4h]

  if ( dx == sx && dy == sy )
  {
    dx += XDirAdd[midir];
    dy += YDirAdd[midir];
  }
  if ( id == -1 )
  {
    v = 16;
  }
  else
  {
    v = 2 * GetSpellLevel(id, 31) + 16;
    if ( v >= 63 )
      v = 63;
  }
  GetMissileVel(mi, sx, sy, dx, dy, v);
  v9 = GetDirection16(sx, sy, dx, dy);
  SetMissDir(mi, v9);
  missile[mi]._mirange = 256;
  missile[mi]._miVar1 = sx;
  missile[mi]._miVar2 = sy;
  missile[mi]._mlid = AddLight(sx, sy, 8);
  v10 = plr[id]._pLevel;
  missile[mi]._midam = random(69, 10) + v10 + 9;
  UseMana(id, 31);
  PutMissile(mi);
}

//----- (0044309D) --------------------------------------------------------
void __fastcall AddResurrect(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  UseMana(id, 32);
  if ( myplr == id )
    j_SetCursor(8);
  missile[mi]._miDelFlag = 1;
}

//----- (004430F7) --------------------------------------------------------
void __fastcall AddResurrectBeam(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._mix = dx;
  missile[mi]._miy = dy;
  missile[mi]._misx = missile[mi]._mix;
  missile[mi]._misy = missile[mi]._miy;
  missile[mi]._mixvel = 0;
  missile[mi]._miyvel = 0;
  missile[mi]._mirange = misfiledata[37].mAnimLen[0];
}

//----- (004431E4) --------------------------------------------------------
void __fastcall AddTelekinesis(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miDelFlag = 1;
  UseMana(id, 33);
  if ( myplr == id )
    j_SetCursor(7);
}

//----- (0044323E) --------------------------------------------------------
void __fastcall AddBoneSpirit(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  GetMissileVel(mi, sx, sy, dx, dy, 16);
  missile[mi]._mirange = 256;
  missile[mi]._miVar1 = sx;
  missile[mi]._miVar2 = sy;
  missile[mi]._mlid = AddLight(sx, sy, 8);
  if ( !(_BYTE)mienemy )
  {
    UseMana(id, 36);
    plr[id]._pHitPoints -= 1536;
    plr[id]._pHPBase -= 1536;
    drawhpflag = 1;
    if ( plr[id]._pHitPoints <= 0 )
    {
      plr[id]._pHitPoints = 0;
      SyncPlrKill(id);
    }
  }
  PutMissile(mi);
}

//----- (004433AE) --------------------------------------------------------
int __fastcall AddMissile(int sx, int sy, int v1, int v2, int midir, int mitype, int micaster, int id, int v3)
{
  int mi; // [esp+14h] [ebp-4h]

  if ( nummissiles < 125 )
  {
    mi = missilevail[0];
    missilevail[0] = missilevail[125 - nummissiles - 1];
    missileactive[nummissiles] = mi;
    missile[mi]._mitype = mitype;
    missile[mi]._micaster = (char)micaster;
    missile[mi]._misource = id;
    missile[mi]._miAnimType = missiledata[mitype].mFileNum;
    missile[mi]._miDrawFlag = missiledata[mitype].mDraw;
    missile[mi]._mimfnum = midir;
    if ( missile[mi]._miAnimType == 255 || (signed int)misfiledata[missile[mi]._miAnimType].mAnimFAmt < 8 )
      SetMissDir(mi, 0);
    else
      SetMissDir(mi, midir);
    missile[mi]._mix = sx;
    missile[mi]._miy = sy;
    missile[mi]._mixoff = 0;
    missile[mi]._miyoff = 0;
    missile[mi]._misx = sx;
    missile[mi]._misy = sy;
    missile[mi]._mitxoff = 0;
    missile[mi]._mityoff = 0;
    missile[mi]._miDelFlag = 0;
    missile[mi]._miAnimAdd = 1;
    missile[mi]._miLightFlag = 0;
    missile[mi]._miPreFlag = 0;
    missile[mi]._miUniqTrans = 0;
    missile[mi]._midam = v3;
    missile[mi]._miHitFlag = 0;
    missile[mi]._midist = 0;
    missile[mi]._mlid = -1;
    missile[mi]._mirnd = 0;
    if ( missiledata[mitype].mlSFX != -1 )
      PlaySfxLoc(missiledata[mitype].mlSFX, missile[mi]._mix, missile[mi]._miy);
    missiledata[mitype].mAddProc(mi, sx, sy, v1, v2, midir, micaster, id, v3);
    ++nummissiles;
  }
  return mi;
}

//----- (0044377B) --------------------------------------------------------
signed int __fastcall unused_sub_44377B(int a1, int a2, int ty)
{
  int midir; // ST30_4
  int tx; // [esp+Ch] [ebp-14h]
  int mi; // [esp+10h] [ebp-10h]
  signed int v7; // [esp+1Ch] [ebp-4h]

  tx = a2;
  mi = a1;
  v7 = 0;
  if ( !CheckBlock(missile[a1]._mix, missile[a1]._miy, a2, ty)
    && dMonster[tx][ty] > 0
    && (signed int)(monster[dMonster[tx][ty] - 1]._mhitpoints & 0xFFFFFFC0) > 0 )
  {
    midir = GetDirection(missile[mi]._mix, missile[mi]._miy, tx, ty);
    AddMissile(missile[mi]._mix, missile[mi]._miy, tx, ty, midir, 1, 0, myplr, missile[mi]._midam);
    v7 = -1;
  }
  if ( v7 == -1 )
  {
    SetMissDir(mi, 2);
    missile[mi]._miVar2 = 3;
  }
  return v7;
}

//----- (00443907) --------------------------------------------------------
void __fastcall MI_Dummy(int i)
{
  ;
}

//----- (0044391D) --------------------------------------------------------
void __fastcall MI_SetManashield(int i)
{
  ManashieldFlag = 1;
}

//----- (0044393D) --------------------------------------------------------
void __fastcall MI_LArrow(int i)
{
  int maxdam; // [esp+10h] [ebp-Ch]
  int mindam; // [esp+14h] [ebp-8h]
  int v4; // [esp+18h] [ebp-4h]

  --missile[i]._mirange;
  if ( missile[i]._miAnimType == 27 )
  {
    ChangeLight(missile[i]._mlid, missile[i]._mix, missile[i]._miy, missile[i]._miAnimFrame + 5);
  }
  else
  {
    ++missile[i]._midist;
    missile[i]._mitxoff += missile[i]._mixvel;
    missile[i]._mityoff += missile[i]._miyvel;
    GetMissilePos(i);
    v4 = missile[i]._misource;
    if ( v4 == -1 )
    {
      mindam = currlevel + random(68, 10) + 1;
      maxdam = random(68, 10) + 2 * currlevel + 1;
    }
    else if ( missile[i]._micaster )
    {
      mindam = monster[v4].mMinDamage;
      maxdam = monster[v4].mMaxDamage;
    }
    else
    {
      mindam = plr[v4]._pIMinDam;
      maxdam = plr[v4]._pIMaxDam;
    }
    if ( missile[i]._mix != missile[i]._misx || missile[i]._miy != missile[i]._misy )
      CheckMissileCol(i, mindam, maxdam, 0, missile[i]._mix, missile[i]._miy, 0);
    if ( missile[i]._mirange )
    {
      if ( missile[i]._mix != missile[i]._miVar1 || missile[i]._miy != missile[i]._miVar2 )
      {
        missile[i]._miVar1 = missile[i]._mix;
        missile[i]._miVar2 = missile[i]._miy;
        ChangeLight(missile[i]._mlid, missile[i]._miVar1, missile[i]._miVar2, 5);
      }
    }
    else
    {
      missile[i]._mimfnum = 0;
      if ( missile[i]._mitype == 56 )
      {
        SetMissAnim(i, 27);
        missile[i]._mirange = missile[i]._miAnimLen - 1;
      }
      else
      {
        AddMissile(
          missile[i]._mix,
          missile[i]._miy,
          i,
          0,
          missile[i]._mimfnum,
          9,
          missile[i]._micaster,
          missile[i]._misource,
          0);
        missile[i]._mirange = 0;
      }
    }
  }
  if ( !missile[i]._mirange )
  {
    missile[i]._miDelFlag = 1;
    AddUnLight(missile[i]._mlid);
  }
  PutMissile(i);
}

//----- (00443E69) --------------------------------------------------------
void __fastcall MI_Arrow(int i)
{
  int maxdam; // [esp+10h] [ebp-Ch]
  int mindam; // [esp+14h] [ebp-8h]
  int v4; // [esp+18h] [ebp-4h]

  --missile[i]._mirange;
  ++missile[i]._midist;
  missile[i]._mitxoff += missile[i]._mixvel;
  missile[i]._mityoff += missile[i]._miyvel;
  GetMissilePos(i);
  v4 = missile[i]._misource;
  if ( v4 == -1 )
  {
    mindam = currlevel;
    maxdam = 2 * currlevel;
  }
  else if ( missile[i]._micaster )
  {
    mindam = monster[v4].mMinDamage;
    maxdam = monster[v4].mMaxDamage;
  }
  else
  {
    mindam = plr[v4]._pIMinDam;
    maxdam = plr[v4]._pIMaxDam;
  }
  if ( missile[i]._mix != missile[i]._misx || missile[i]._miy != missile[i]._misy )
    CheckMissileCol(i, mindam, maxdam, 0, missile[i]._mix, missile[i]._miy, 0);
  if ( !missile[i]._mirange )
    missile[i]._miDelFlag = 1;
  PutMissile(i);
}

//----- (004440B1) --------------------------------------------------------
void __fastcall MI_Firebolt(int i)
{
  signed int j; // [esp+14h] [ebp-14h]
  int k; // [esp+14h] [ebp-14h]
  int v4; // [esp+18h] [ebp-10h]
  int v5; // [esp+1Ch] [ebp-Ch]
  int mindam; // [esp+20h] [ebp-8h]
  int id; // [esp+24h] [ebp-4h]

  v5 = missile[i]._mitxoff;
  v4 = missile[i]._mityoff;
  --missile[i]._mirange;
  missile[i]._mitxoff += missile[i]._mixvel;
  missile[i]._mityoff += missile[i]._miyvel;
  GetMissilePos(i);
  id = missile[i]._misource;
  if ( id == -1 )
  {
    mindam = currlevel + random(78, 2 * currlevel);
  }
  else if ( missile[i]._micaster )
  {
    mindam = (monster[id].mMinDamage + random(77, monster[id].mMaxDamage - monster[id].mMinDamage + 1)) >> 1;
  }
  else
  {
    mindam = 0;
    for ( j = 0; j < 4; ++j )
      mindam += random(75, 6) + 1;
    for ( k = GetSpellLevel(id, 35); k > 0; --k )
      mindam += 3;
  }
  if ( missile[i]._mix != missile[i]._misx || missile[i]._miy != missile[i]._misy )
    CheckMissileCol(i, mindam, mindam, 0, missile[i]._mix, missile[i]._miy, 0);
  if ( missile[i]._mirange )
  {
    if ( missile[i]._mix != missile[i]._miVar1 || missile[i]._miy != missile[i]._miVar2 )
    {
      missile[i]._miVar1 = missile[i]._mix;
      missile[i]._miVar2 = missile[i]._miy;
      if ( missile[i]._mlid >= 0 )
        ChangeLight(missile[i]._mlid, missile[i]._miVar1, missile[i]._miVar2, 8);
    }
  }
  else
  {
    missile[i]._miDelFlag = 1;
    missile[i]._mitxoff = v5;
    missile[i]._mityoff = v4;
    GetMissilePos(i);
    switch ( missile[i]._mitype )
    {
      case 1:
      case 0x15:
        AddMissile(
          missile[i]._mix,
          missile[i]._miy,
          i,
          0,
          missile[i]._mimfnum,
          9,
          missile[i]._micaster,
          missile[i]._misource,
          0);
        break;
      case 0x18:
        AddMissile(
          missile[i]._mix,
          missile[i]._miy,
          i,
          0,
          missile[i]._mimfnum,
          25,
          missile[i]._micaster,
          missile[i]._misource,
          0);
        break;
      case 0x39:
        AddMissile(
          missile[i]._mix,
          missile[i]._miy,
          i,
          0,
          missile[i]._mimfnum,
          58,
          missile[i]._micaster,
          missile[i]._misource,
          0);
        break;
      default:
        break;
    }
    if ( missile[i]._mlid >= 0 )
      AddUnLight(missile[i]._mlid);
  }
  PutMissile(i);
}

//----- (00444704) --------------------------------------------------------
void __fastcall MI_Lightball(int i)
{
  int v2; // [esp+10h] [ebp-4h]

  --missile[i]._mirange;
  missile[i]._mitxoff += missile[i]._mixvel;
  missile[i]._mityoff += missile[i]._miyvel;
  GetMissilePos(i);
  v2 = missile[i]._mirange;
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix, missile[i]._miy, 0);
  if ( missile[i]._miHitFlag == 1 )
    missile[i]._mirange = v2;
  if ( !missile[i]._mirange )
    missile[i]._miDelFlag = 1;
  PutMissile(i);
}

//----- (00444877) --------------------------------------------------------
void __fastcall mi_null_33(int i)
{
  --missile[i]._mirange;
  missile[i]._mitxoff += missile[i]._mixvel;
  missile[i]._mityoff += missile[i]._miyvel;
  GetMissilePos(i);
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix, missile[i]._miy, 0);
  if ( !missile[i]._mirange )
    missile[i]._miDelFlag = 1;
  PutMissile(i);
}

//----- (0044499E) --------------------------------------------------------
void __fastcall MI_Acidpud(int i)
{
  int v1; // ST24_4

  v1 = --missile[i]._mirange;
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 1, missile[i]._mix, missile[i]._miy, 0);
  missile[i]._mirange = v1;
  if ( !missile[i]._mirange )
  {
    if ( missile[i]._mimfnum )
    {
      missile[i]._miDelFlag = 1;
    }
    else
    {
      SetMissDir(i, 1);
      missile[i]._mirange = missile[i]._miAnimLen;
    }
  }
  PutMissile(i);
}

//----- (00444AF1) --------------------------------------------------------
void __fastcall MI_Firewall(int i)
{
  int v2[14]; // [esp+10h] [ebp-38h]

  v2[0] = 2;
  v2[1] = 3;
  v2[2] = 4;
  v2[3] = 5;
  v2[4] = 5;
  v2[5] = 6;
  v2[6] = 7;
  v2[7] = 8;
  v2[8] = 9;
  v2[9] = 10;
  v2[10] = 11;
  v2[11] = 12;
  v2[12] = 12;
  v2[13] = 0;
  if ( missile[i]._miVar1 == --missile[i]._mirange )
  {
    SetMissDir(i, 1);
    missile[i]._miAnimFrame = random(83, 11) + 1;
  }
  if ( missile[i]._miAnimLen - 1 == missile[i]._mirange )
  {
    SetMissDir(i, 0);
    missile[i]._miAnimFrame = 13;
    missile[i]._miAnimAdd = -1;
  }
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 1, missile[i]._mix, missile[i]._miy, 1u);
  if ( !missile[i]._mirange )
  {
    missile[i]._miDelFlag = 1;
    AddUnLight(missile[i]._mlid);
  }
  if ( missile[i]._mimfnum && missile[i]._mirange && missile[i]._miAnimAdd != -1 && missile[i]._miVar2 < 12 )
  {
    if ( !missile[i]._miVar2 )
      missile[i]._mlid = AddLight(missile[i]._mix, missile[i]._miy, v2[missile[i]._miVar2]);
    ChangeLight(missile[i]._mlid, missile[i]._mix, missile[i]._miy, v2[missile[i]._miVar2]);
    ++missile[i]._miVar2;
  }
  PutMissile(i);
}

//----- (00444E65) --------------------------------------------------------
void __fastcall MI_Fireball(int i)
{
  int x1; // [esp+10h] [ebp-18h]
  int v3; // [esp+14h] [ebp-14h]
  int y; // [esp+18h] [ebp-10h]
  int x; // [esp+1Ch] [ebp-Ch]
  int mindam; // [esp+20h] [ebp-8h]
  int y1; // [esp+24h] [ebp-4h]

  v3 = missile[i]._misource;
  mindam = missile[i]._midam;
  --missile[i]._mirange;
  if ( missile[i]._miAnimType == 19 )
  {
    x = missile[i]._mix;
    y = missile[i]._miy;
    x1 = plr[v3].WorldX;
    y1 = plr[v3].WorldY;
    ChangeLight(missile[i]._mlid, missile[i]._mix, missile[i]._miy, missile[i]._miAnimFrame);
    if ( !CheckBlock(x1, y1, x, y) )
      CheckMissileCol(i, mindam, mindam, 0, x, y, 1u);
    if ( !CheckBlock(x1, y1, x, y + 1) )
      CheckMissileCol(i, mindam, mindam, 0, x, y + 1, 1u);
    if ( !CheckBlock(x1, y1, x, y - 1) )
      CheckMissileCol(i, mindam, mindam, 0, x, y - 1, 1u);
    if ( !CheckBlock(x1, y1, x + 1, y) )
      CheckMissileCol(i, mindam, mindam, 0, x + 1, y, 1u);
    if ( !CheckBlock(x1, y1, x + 1, y - 1) )
      CheckMissileCol(i, mindam, mindam, 0, x + 1, y - 1, 1u);
    if ( !CheckBlock(x1, y1, x + 1, y + 1) )
      CheckMissileCol(i, mindam, mindam, 0, x + 1, y + 1, 1u);
    if ( !CheckBlock(x1, y1, x - 1, y) )
      CheckMissileCol(i, mindam, mindam, 0, x - 1, y, 1u);
    if ( !CheckBlock(x1, y1, x - 1, y + 1) )
      CheckMissileCol(i, mindam, mindam, 0, x - 1, y + 1, 1u);
    if ( !CheckBlock(x1, y1, x - 1, y - 1) )
      CheckMissileCol(i, mindam, mindam, 0, x - 1, y - 1, 1u);
    if ( !missile[i]._mirange )
    {
      missile[i]._miDelFlag = 1;
      AddUnLight(missile[i]._mlid);
    }
    PutMissile(i);
  }
  else
  {
    missile[i]._mitxoff += missile[i]._mixvel;
    missile[i]._mityoff += missile[i]._miyvel;
    GetMissilePos(i);
    if ( missile[i]._mix != missile[i]._misx || missile[i]._miy != missile[i]._misy )
      CheckMissileCol(i, mindam, mindam, 0, missile[i]._mix, missile[i]._miy, 0);
    if ( missile[i]._mirange )
    {
      if ( missile[i]._mix != missile[i]._miVar1 || missile[i]._miy != missile[i]._miVar2 )
      {
        missile[i]._miVar1 = missile[i]._mix;
        missile[i]._miVar2 = missile[i]._miy;
        ChangeLight(missile[i]._mlid, missile[i]._miVar1, missile[i]._miVar2, 8);
      }
    }
    else
    {
      missile[i]._mimfnum = 0;
      SetMissAnim(i, 19);
      missile[i]._mirange = missile[i]._miAnimLen - 1;
    }
    PutMissile(i);
  }
}

//----- (00445451) --------------------------------------------------------
void __fastcall MI_Lightctrl(int i)
{
  int v1; // ebx
  int v3; // [esp+10h] [ebp-Ch]
  int v4; // [esp+14h] [ebp-8h]
  int v5; // [esp+18h] [ebp-4h]

  --missile[i]._mirange;
  v5 = missile[i]._misource;
  if ( v5 == -1 )
  {
    v3 = random(81, currlevel) + 2 * currlevel;
  }
  else if ( missile[i]._micaster )
  {
    v3 = 2 * (monster[v5].mMinDamage + random(80, monster[v5].mMaxDamage - monster[v5].mMinDamage + 1));
  }
  else
  {
    v1 = random(79, plr[v5]._pLevel);
    v3 = (random(79, 2) + v1 + 2) << 6;
  }
  missile[i]._mitxoff += missile[i]._mixvel;
  missile[i]._mityoff += missile[i]._miyvel;
  GetMissilePos(i);
  v4 = dPiece[missile[i]._mix][missile[i]._miy];
  if ( missile[i]._misource == -1 )
  {
    if ( (missile[i]._mix != missile[i]._misx || missile[i]._miy != missile[i]._misy) && nMissileTable[v4] )
      missile[i]._mirange = 0;
  }
  else if ( nMissileTable[v4] )
  {
    missile[i]._mirange = 0;
  }
  if ( !nMissileTable[v4] && (missile[i]._mix != missile[i]._miVar1 || missile[i]._miy != missile[i]._miVar2) )
  {
    if ( missile[i]._micaster && missile[i]._misource != -1 )
      AddMissile(
        missile[i]._mix,
        missile[i]._miy,
        missile[i]._misx,
        missile[i]._misy,
        i,
        23,
        missile[i]._micaster,
        missile[i]._misource,
        v3);
    else
      AddMissile(
        missile[i]._mix,
        missile[i]._miy,
        missile[i]._misx,
        missile[i]._misy,
        i,
        8,
        missile[i]._micaster,
        missile[i]._misource,
        v3);
    missile[i]._miVar1 = missile[i]._mix;
    missile[i]._miVar2 = missile[i]._miy;
  }
  if ( !missile[i]._mirange )
    missile[i]._miDelFlag = 1;
}

//----- (00445957) --------------------------------------------------------
void __fastcall MI_Lightning(int i)
{
  int v2; // [esp+10h] [ebp-4h]

  v2 = --missile[i]._mirange;
  if ( missile[i]._mix != missile[i]._misx || missile[i]._miy != missile[i]._misy )
    CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 1, missile[i]._mix, missile[i]._miy, 0);
  if ( missile[i]._miHitFlag == 1 )
    missile[i]._mirange = v2;
  if ( !missile[i]._mirange )
  {
    missile[i]._miDelFlag = 1;
    AddUnLight(missile[i]._mlid);
  }
  PutMissile(i);
}

//----- (00445AE8) --------------------------------------------------------
void __fastcall MI_Town(int i)
{
  int v2[17]; // [esp+10h] [ebp-48h]
  int pnum; // [esp+54h] [ebp-4h]

  v2[0] = 1;
  v2[1] = 2;
  v2[2] = 3;
  v2[3] = 4;
  v2[4] = 5;
  v2[5] = 6;
  v2[6] = 7;
  v2[7] = 8;
  v2[8] = 9;
  v2[9] = 10;
  v2[10] = 11;
  v2[11] = 12;
  v2[12] = 13;
  v2[13] = 14;
  v2[14] = 15;
  v2[15] = 15;
  v2[16] = 15;
  if ( missile[i]._mirange > 1 )
    --missile[i]._mirange;
  if ( missile[i]._miVar1 == missile[i]._mirange )
    SetMissDir(i, 1);
  if ( currlevel && missile[i]._mimfnum != 1 && missile[i]._mirange )
  {
    if ( !missile[i]._miVar2 )
      missile[i]._mlid = AddLight(missile[i]._mix, missile[i]._miy, v2[missile[i]._miVar2]);
    ChangeLight(missile[i]._mlid, missile[i]._mix, missile[i]._miy, v2[missile[i]._miVar2]);
    ++missile[i]._miVar2;
  }
  for ( pnum = 0; pnum < 4; ++pnum )
  {
    if ( plr[pnum].plractive
      && plr[pnum].plrlevel == currlevel
      && !plr[pnum]._pLvlChanging
      && !plr[pnum]._pmode
      && missile[i]._mix == plr[pnum].WorldX
      && missile[i]._miy == plr[pnum].WorldY )
    {
      ClrPlrPath(pnum);
      if ( myplr == pnum )
      {
        NetSendCmdParam1(1u, CMD_WARP, missile[i]._misource);
        plr[pnum]._pmode = 10;
      }
    }
  }
  if ( !missile[i]._mirange )
  {
    missile[i]._miDelFlag = 1;
    AddUnLight(missile[i]._mlid);
  }
  PutMissile(i);
}

//----- (00445F15) --------------------------------------------------------
void __fastcall MI_Flash(int i)
{
  plr[missile[i]._misource]._pInvincible = 1;
  --missile[i]._mirange;
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix - 1, missile[i]._miy, 1u);
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix, missile[i]._miy, 1u);
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix + 1, missile[i]._miy, 1u);
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix - 1, missile[i]._miy + 1, 1u);
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix, missile[i]._miy + 1, 1u);
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix + 1, missile[i]._miy + 1, 1u);
  if ( !missile[i]._mirange )
  {
    missile[i]._miDelFlag = 1;
    plr[missile[i]._misource]._pInvincible = 0;
  }
  PutMissile(i);
}

//----- (00446236) --------------------------------------------------------
void __fastcall MI_Flash2(int i)
{
  plr[missile[i]._misource]._pInvincible = 1;
  --missile[i]._mirange;
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix - 1, missile[i]._miy - 1, 1u);
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix, missile[i]._miy - 1, 1u);
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix + 1, missile[i]._miy - 1, 1u);
  if ( !missile[i]._mirange )
  {
    missile[i]._miDelFlag = 1;
    plr[missile[i]._misource]._pInvincible = 0;
  }
  PutMissile(i);
}

//----- (0044642C) --------------------------------------------------------
void __fastcall MI_Manashield(int i)
{
  int v1; // eax
  int id; // [esp+10h] [ebp-Ch]
  int j; // [esp+14h] [ebp-8h]
  int v5; // [esp+18h] [ebp-4h]

  id = missile[i]._misource;
  missile[i]._mitxoff = plr[id]._pxoff << 16;
  missile[i]._mityoff = plr[id]._pyoff << 16;
  if ( plr[id]._pmode == 3 )
  {
    missile[i]._misx = plr[id]._px;
    v1 = plr[id]._py;
  }
  else
  {
    missile[i]._misx = plr[id].WorldX;
    v1 = plr[id].WorldY;
  }
  missile[i]._misy = v1;
  GetMissilePos(i);
  if ( plr[id]._pmode == 3 )
  {
    if ( plr[id]._pdir == 2 )
      ++missile[i]._mix;
    else
      ++missile[i]._miy;
  }
  if ( missile[i]._miVar1 > plr[id]._pHitPoints )
  {
    v5 = missile[i]._miVar1 - plr[id]._pHitPoints;
    for ( j = GetSpellLevel(id, 11); j > 0; --j )
      v5 -= v5 >> 3;
    if ( v5 < 0 )
      v5 = 0;
    drawmanaflag = 1;
    drawhpflag = 1;
    if ( plr[id]._pMana < v5 )
    {
      plr[id]._pHitPoints -= v5 - plr[id]._pMana;
      plr[id]._pHPBase -= v5 - plr[id]._pMana;
      plr[id]._pMana = 0;
      plr[id]._pManaBase = 0;
      missile[i]._mirange = 0;
    }
    else
    {
      plr[id]._pHitPoints = missile[i]._miVar1;
      plr[id]._pHPBase = missile[i]._miVar2;
      plr[id]._pMana -= v5;
      plr[id]._pManaBase -= v5;
    }
  }
  missile[i]._miVar1 = plr[id]._pHitPoints;
  missile[i]._miVar2 = plr[id]._pHPBase;
  if ( !missile[i]._mirange )
    missile[i]._miDelFlag = 1;
  PutMissile(i);
}

//----- (00446955) --------------------------------------------------------
void __fastcall MI_Etherealize(int i)
{
  ;
}

//----- (0044696B) --------------------------------------------------------
void __fastcall MI_Firemove(int i)
{
  int v2[14]; // [esp+10h] [ebp-3Ch]
  int v3; // [esp+48h] [ebp-4h]

  v2[0] = 2;
  v2[1] = 3;
  v2[2] = 4;
  v2[3] = 5;
  v2[4] = 5;
  v2[5] = 6;
  v2[6] = 7;
  v2[7] = 8;
  v2[8] = 9;
  v2[9] = 10;
  v2[10] = 11;
  v2[11] = 12;
  v2[12] = 12;
  v2[13] = 0;
  if ( ++missile[i]._miVar1 == missile[i]._miAnimLen )
  {
    SetMissDir(i, 1);
    missile[i]._miAnimFrame = random(82, 11) + 1;
  }
  missile[i]._mitxoff += missile[i]._mixvel;
  missile[i]._mityoff += missile[i]._miyvel;
  GetMissilePos(i);
  v3 = missile[i]._mirange;
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 1, missile[i]._mix, missile[i]._miy, 0);
  if ( missile[i]._miHitFlag == 1 )
    missile[i]._mirange = v3;
  if ( !missile[i]._mirange )
  {
    missile[i]._miDelFlag = 1;
    AddUnLight(missile[i]._mlid);
  }
  if ( !missile[i]._mimfnum && missile[i]._mirange )
  {
    if ( !missile[i]._miVar2 )
      missile[i]._mlid = AddLight(missile[i]._mix, missile[i]._miy, v2[missile[i]._miVar2]);
    ChangeLight(missile[i]._mlid, missile[i]._mix, missile[i]._miy, v2[missile[i]._miVar2]);
    ++missile[i]._miVar2;
  }
  PutMissile(i);
}

//----- (00446CE2) --------------------------------------------------------
void __fastcall MI_Guardian(int i)
{
  ;
}

//----- (00446CF8) --------------------------------------------------------
void __fastcall MI_Chain(int i)
{
  int midir; // ST34_4
  int v2; // ST30_4
  int v3; // ST34_4
  int id; // [esp+10h] [ebp-70h]
  signed int j; // [esp+1Ch] [ebp-64h]
  int y1; // [esp+20h] [ebp-60h]
  int v8; // [esp+24h] [ebp-5Ch]
  int x1; // [esp+28h] [ebp-58h]
  int k; // [esp+2Ch] [ebp-54h]
  int v11[19]; // [esp+30h] [ebp-50h]
  int v12; // [esp+7Ch] [ebp-4h]

  v11[0] = 0;
  v11[1] = 3;
  v11[2] = 12;
  v11[3] = 45;
  v11[4] = 94;
  v11[5] = 159;
  v11[6] = 240;
  v11[7] = 337;
  v11[8] = 450;
  v11[9] = 579;
  v11[10] = 724;
  v11[11] = 885;
  v11[12] = 1062;
  v11[13] = 1255;
  v11[14] = 1464;
  v11[15] = 1689;
  v11[16] = 1930;
  v11[17] = 2187;
  v11[18] = 2460;
  id = missile[i]._misource;
  x1 = missile[i]._mix;
  y1 = missile[i]._miy;
  midir = GetDirection(missile[i]._mix, missile[i]._miy, missile[i]._miVar1, missile[i]._miVar2);
  AddMissile(x1, y1, missile[i]._miVar1, missile[i]._miVar2, midir, 7, 0, id, 1);
  v12 = GetSpellLevel(id, 14) + 3;
  if ( v12 > 19 )
    v12 = 19;
  for ( j = 1; v12 > j; ++j )
  {
    v2 = v11[j];
    v8 = v2 + 1;
    for ( k = (unsigned __int8)CrawlTable[v2]; k > 0; --k )
    {
      if ( dMonster[x1 + CrawlTable[v8]][y1 + CrawlTable[v8 + 1]] > 0 )
      {
        v3 = GetDirection(x1, y1, x1 + CrawlTable[v8], y1 + CrawlTable[v8 + 1]);
        AddMissile(x1, y1, x1 + CrawlTable[v8], y1 + CrawlTable[v8 + 1], v3, 7, 0, id, 1);
      }
      v8 += 2;
    }
  }
  if ( !--missile[i]._mirange )
    missile[i]._miDelFlag = 1;
}

//----- (00446FB3) --------------------------------------------------------
void __fastcall mi_null_11(int i)
{
  if ( !--missile[i]._mirange )
    missile[i]._miDelFlag = 1;
  if ( missile[i]._miAnimFrame == missile[i]._miAnimLen )
    missile[i]._miPreFlag = 1;
  PutMissile(i);
}

//----- (00447064) --------------------------------------------------------
void __fastcall MI_Weapexp(int i)
{
  int v2[10]; // [esp+10h] [ebp-34h]
  int v3; // [esp+38h] [ebp-Ch]
  int maxdam; // [esp+3Ch] [ebp-8h]
  int mindam; // [esp+40h] [ebp-4h]

  v2[0] = 9;
  v2[1] = 10;
  v2[2] = 11;
  v2[3] = 12;
  v2[4] = 11;
  v2[5] = 10;
  v2[6] = 8;
  v2[7] = 6;
  v2[8] = 4;
  v2[9] = 2;
  --missile[i]._mirange;
  v3 = missile[i]._misource;
  mindam = plr[v3]._pIMinDam;
  maxdam = plr[v3]._pIMaxDam;
  CheckMissileCol(i, mindam, maxdam, 0, missile[i]._mix, missile[i]._miy, 0);
  if ( missile[i]._miVar1 )
  {
    if ( missile[i]._mirange )
      ChangeLight(missile[i]._mlid, missile[i]._mix, missile[i]._miy, v2[missile[i]._miVar1]);
  }
  else
  {
    missile[i]._mlid = AddLight(missile[i]._mix, missile[i]._miy, v2[missile[i]._miVar1]);
  }
  ++missile[i]._miVar1;
  if ( missile[i]._mirange )
  {
    PutMissile(i);
  }
  else
  {
    missile[i]._miDelFlag = 1;
    AddUnLight(missile[i]._mlid);
  }
}

//----- (004472D7) --------------------------------------------------------
void __fastcall MI_Misexp(int i)
{
  int v2[10]; // [esp+10h] [ebp-28h]

  v2[0] = 9;
  v2[1] = 10;
  v2[2] = 11;
  v2[3] = 12;
  v2[4] = 11;
  v2[5] = 10;
  v2[6] = 8;
  v2[7] = 6;
  v2[8] = 4;
  v2[9] = 2;
  if ( --missile[i]._mirange )
  {
    if ( missile[i]._miVar1 )
    {
      if ( missile[i]._mirange )
        ChangeLight(missile[i]._mlid, missile[i]._mix, missile[i]._miy, v2[missile[i]._miVar1]);
    }
    else
    {
      missile[i]._mlid = AddLight(missile[i]._mix, missile[i]._miy, v2[missile[i]._miVar1]);
    }
    ++missile[i]._miVar1;
    PutMissile(i);
  }
  else
  {
    missile[i]._miDelFlag = 1;
    AddUnLight(missile[i]._mlid);
  }
}

//----- (004474B3) --------------------------------------------------------
void __fastcall MI_Acidsplat(int i)
{
  if ( --missile[i]._mirange )
  {
    PutMissile(i);
  }
  else
  {
    missile[i]._miDelFlag = 1;
    AddMissile(
      missile[i]._mix,
      missile[i]._miy,
      i,
      0,
      missile[i]._mimfnum,
      59,
      1,
      missile[i]._misource,
      monster[missile[i]._misource].MData->mLevel + 1);
  }
}

//----- (004475BD) --------------------------------------------------------
void __fastcall MI_Teleport(int i)
{
  int v2; // [esp+10h] [ebp-4h]

  v2 = missile[i]._misource;
  if ( --missile[i]._mirange > 0 )
  {
    if ( !missile[i]._miVar1 )
    {
      dPlayer[plr[v2].WorldX][plr[v2].WorldY] = 0;
      PlrClrTrans(plr[v2].WorldX, plr[v2].WorldY);
      plr[v2].WorldX = missile[i]._mix;
      plr[v2].WorldY = missile[i]._miy;
      plr[v2]._px = plr[v2].WorldX;
      plr[v2]._py = plr[v2].WorldY;
      PlrDoTrans(plr[v2].WorldX, plr[v2].WorldY);
      missile[i]._miVar1 = 1;
      dPlayer[plr[v2].WorldX][plr[v2].WorldY] = v2 + 1;
      if ( leveltype )
      {
        ChangeLightXY(plr[v2]._plid, plr[v2].WorldX, plr[v2].WorldY);
        ChangeVisionXY(plr[v2]._pvid, plr[v2].WorldX, plr[v2].WorldY);
      }
      if ( myplr == v2 )
      {
        ViewX = plr[v2].WorldX - ScrollInfo._sdx;
        ViewY = plr[v2].WorldY - ScrollInfo._sdy;
      }
    }
  }
  else
  {
    missile[i]._miDelFlag = 1;
  }
}

//----- (00447989) --------------------------------------------------------
void __fastcall MI_Stone(int i)
{
  int v2; // [esp+10h] [ebp-4h]

  --missile[i]._mirange;
  v2 = missile[i]._miVar2;
  if ( !monster[v2]._mhitpoints && missile[i]._miAnimType != 18 )
  {
    SetMissAnim(i, 18);
    missile[i]._mirange = 11;
  }
  if ( monster[v2]._mmode != 15 )
    missile[i]._miDelFlag = 1;
  if ( !missile[i]._mirange )
  {
    missile[i]._miDelFlag = 1;
    if ( monster[v2]._mhitpoints <= 0 )
      AddDead(monster[v2]._mx, monster[v2]._my, stonendx, monster[v2]._mdir);
    else
      monster[v2]._mmode = missile[i]._miVar1;
  }
  if ( missile[i]._miAnimType == 18 )
    PutMissile(i);
}

//----- (00447B4F) --------------------------------------------------------
void __fastcall MI_Boom(int i)
{
  --missile[i]._mirange;
  if ( !missile[i]._miVar1 )
    CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix, missile[i]._miy, 1u);
  if ( missile[i]._miHitFlag == 1 )
    missile[i]._miVar1 = 1;
  if ( !missile[i]._mirange )
    missile[i]._miDelFlag = 1;
  PutMissile(i);
}

//----- (00447C6B) --------------------------------------------------------
void __fastcall MI_Rhino(int i)
{
  int v1; // ST24_4
  int v2; // ST1C_4
  int v4; // [esp+10h] [ebp-18h]
  int y; // [esp+1Ch] [ebp-Ch]
  int x; // [esp+24h] [ebp-4h]

  GetMissilePos(i);
  x = missile[i]._mix;
  y = missile[i]._miy;
  dMonster[x][y] = 0;
  missile[i]._mitxoff += missile[i]._mixvel;
  missile[i]._mityoff += missile[i]._miyvel;
  GetMissilePos(i);
  v4 = missile[i]._misource;
  v1 = missile[i]._mix;
  v2 = missile[i]._miy;
  if ( PosOkMonst(missile[i]._misource, missile[i]._mix, missile[i]._miy) )
  {
    dMonster[missile[i]._mix][missile[i]._miy] = -(v4 + 1);
    if ( monster[v4]._uniqtype )
      ChangeLightXY(monster[v4].mlid, monster[v4]._mx, monster[v4]._my);
    MoveMissilePos(i);
    PutMissile(i);
  }
  else
  {
    MissToMonst(i, x, y);
    missile[i]._miDelFlag = 1;
  }
}

//----- (00447EAE) --------------------------------------------------------
void __fastcall mi_null_32(int i)
{
  int v2; // [esp+10h] [ebp-28h]
  int v3; // [esp+14h] [ebp-24h]
  int v4; // [esp+18h] [ebp-20h]
  int v5; // [esp+20h] [ebp-18h]
  int y; // [esp+24h] [ebp-14h]
  int v7; // [esp+28h] [ebp-10h]
  int x; // [esp+2Ch] [ebp-Ch]
  int v9; // [esp+30h] [ebp-8h]
  int v10; // [esp+34h] [ebp-4h]

  GetMissilePos(i);
  x = missile[i]._mix;
  y = missile[i]._miy;
  missile[i]._mitxoff += missile[i]._mixvel;
  missile[i]._mityoff += missile[i]._miyvel;
  GetMissilePos(i);
  v4 = missile[i]._misource;
  v7 = missile[i]._mix;
  v5 = missile[i]._miy;
  v10 = monster[v4]._menemy;
  if ( monster[v4]._mFlags & 0x10 )
  {
    v2 = monster[v10]._mx;
    v9 = monster[v10]._my;
  }
  else
  {
    v2 = plr[v10].WorldX;
    v9 = plr[v10].WorldY;
  }
  if ( (x != v7 || y != v5)
    && (missile[i]._miVar1 & 1 && (abs(x - v2) >= 4 || abs(y - v9) >= 4) || missile[i]._miVar2 > 1)
    && PosOkMonst(missile[i]._misource, x, y) )
  {
    MissToMonst(i, x, y);
    missile[i]._miDelFlag = 1;
  }
  else if ( monster[v4]._mFlags & 0x10 )
  {
    v3 = dMonster[v7][v5];
  }
  else
  {
    v3 = dPlayer[v7][v5];
  }
  if ( !PosOkMissile(v7, v5) || v3 > 0 && !(missile[i]._miVar1 & 1) )
  {
    missile[i]._mixvel = -missile[i]._mixvel;
    missile[i]._miyvel = -missile[i]._miyvel;
    missile[i]._mimfnum = opposite[missile[i]._mimfnum];
    missile[i]._miAnimData = monster[v4].MType->Anims[1].Frames[missile[i]._mimfnum];
    ++missile[i]._miVar2;
    if ( v3 > 0 )
      missile[i]._miVar1 |= 1u;
  }
  MoveMissilePos(i);
  PutMissile(i);
}

//----- (004482DD) --------------------------------------------------------
void __fastcall MI_FirewallC(int i)
{
  int v2; // [esp+10h] [ebp-8h]
  int v3; // [esp+10h] [ebp-8h]
  int v4; // [esp+14h] [ebp-4h]
  int v5; // [esp+14h] [ebp-4h]

  if ( --missile[i]._mirange )
  {
    v2 = missile[i]._miVar1 + XDirAdd[missile[i]._miVar3];
    v4 = missile[i]._miVar2 + YDirAdd[missile[i]._miVar3];
    if ( !(dFlags[v2][v4] & 0x40) || missile[i]._miVar8 )
    {
      missile[i]._miVar8 = 1;
    }
    else
    {
      AddMissile(
        missile[i]._miVar1,
        missile[i]._miVar2,
        missile[i]._miVar1,
        missile[i]._miVar2,
        plr[myplr]._pdir,
        5,
        0,
        myplr,
        0);
      missile[i]._miVar1 = v2;
      missile[i]._miVar2 = v4;
    }
    v3 = missile[i]._miVar5 + XDirAdd[missile[i]._miVar4];
    v5 = missile[i]._miVar6 + YDirAdd[missile[i]._miVar4];
    if ( !(dFlags[v3][v5] & 0x40) || missile[i]._miVar7 )
    {
      missile[i]._miVar7 = 1;
    }
    else
    {
      AddMissile(
        missile[i]._miVar5,
        missile[i]._miVar6,
        missile[i]._miVar5,
        missile[i]._miVar6,
        plr[myplr]._pdir,
        5,
        0,
        myplr,
        0);
      missile[i]._miVar5 = v3;
      missile[i]._miVar6 = v5;
    }
  }
  else
  {
    missile[i]._miDelFlag = 1;
  }
}

//----- (00448634) --------------------------------------------------------
void __fastcall MI_Infra(int i)
{
  --missile[i]._mirange;
  plr[missile[i]._misource]._pInfraFlag = 1;
  if ( !missile[i]._mirange )
  {
    missile[i]._miDelFlag = 1;
    CalcPlrItemVals(missile[i]._misource, 1);
  }
}

//----- (004486E6) --------------------------------------------------------
void __fastcall MI_Apoca(int i)
{
  ;
}

//----- (004486FC) --------------------------------------------------------
void __fastcall MI_Wave(int i)
{
  signed int v2; // [esp+10h] [ebp-40h]
  int v3; // [esp+18h] [ebp-38h]
  int id; // [esp+1Ch] [ebp-34h]
  int v5; // [esp+24h] [ebp-2Ch]
  int v6; // [esp+28h] [ebp-28h]
  int sx; // [esp+2Ch] [ebp-24h]
  int sxa; // [esp+2Ch] [ebp-24h]
  int y1; // [esp+30h] [ebp-20h]
  int x1; // [esp+34h] [ebp-1Ch]
  int j; // [esp+38h] [ebp-18h]
  int v12; // [esp+3Ch] [ebp-14h]
  int v13; // [esp+44h] [ebp-Ch]
  int sy; // [esp+48h] [ebp-8h]
  int sya; // [esp+48h] [ebp-8h]
  signed int v16; // [esp+4Ch] [ebp-4h]

  v2 = 0;
  v16 = 0;
  id = missile[i]._misource;
  x1 = missile[i]._mix;
  y1 = missile[i]._miy;
  v12 = GetDirection(missile[i]._mix, missile[i]._miy, missile[i]._miVar1, missile[i]._miVar2);
  v5 = ((_BYTE)v12 - 2) & 7;
  v3 = ((_BYTE)v12 + 2) & 7;
  sx = x1 + XDirAdd[v12];
  sy = y1 + YDirAdd[v12];
  if ( !nSolidTable[dPiece[sx][sy]] )
  {
    AddMissile(sx, sy, sx + XDirAdd[v12], sy + YDirAdd[v12], plr[id]._pdir, 14, 0, id, 0);
    sxa = XDirAdd[v5] + sx;
    sya = YDirAdd[v5] + sy;
    v6 = x1 + XDirAdd[v3] + XDirAdd[v12];
    v13 = y1 + YDirAdd[v3] + YDirAdd[v12];
    for ( j = 0; GetSpellLevel(id, 15) + 2 > j; ++j )
    {
      if ( nSolidTable[dPiece[sxa][sya]] || v2 )
      {
        v2 = 1;
      }
      else
      {
        AddMissile(sxa, sya, sxa + XDirAdd[v12], sya + YDirAdd[v12], plr[id]._pdir, 14, 0, id, 0);
        sxa += XDirAdd[v5];
        sya += YDirAdd[v5];
      }
      if ( nSolidTable[dPiece[v6][v13]] || v16 )
      {
        v16 = 1;
      }
      else
      {
        AddMissile(v6, v13, v6 + XDirAdd[v12], v13 + YDirAdd[v12], plr[id]._pdir, 14, 0, id, 0);
        v6 += XDirAdd[v3];
        v13 += YDirAdd[v3];
      }
    }
  }
  if ( !--missile[i]._mirange )
    missile[i]._miDelFlag = 1;
}

//----- (00448A7F) --------------------------------------------------------
void __fastcall MI_Nova(int i)
{
  int v1; // ST34_4
  int v2; // ST2C_4
  int id; // [esp+14h] [ebp-28h]
  int midir; // [esp+1Ch] [ebp-20h]
  int sy; // [esp+20h] [ebp-1Ch]
  signed int j; // [esp+24h] [ebp-18h]
  int sx; // [esp+28h] [ebp-14h]
  int micaster; // [esp+2Ch] [ebp-10h]
  int v3; // [esp+30h] [ebp-Ch]
  int v11; // [esp+34h] [ebp-8h]
  int v12; // [esp+38h] [ebp-4h]

  v11 = 0;
  v12 = 0;
  id = missile[i]._misource;
  v3 = missile[i]._midam;
  sx = missile[i]._mix;
  sy = missile[i]._miy;
  v1 = missile[i]._miVar1;
  v2 = missile[i]._miVar2;
  if ( id == -1 )
  {
    midir = 0;
    micaster = 1;
  }
  else
  {
    midir = plr[id]._pdir;
    micaster = 0;
  }
  for ( j = 0; j < 23; ++j )
  {
    if ( vCrawlTable[j][6] != v12 || vCrawlTable[j][7] != v11 )
    {
      AddMissile(sx, sy, sx + vCrawlTable[j][6], sy + vCrawlTable[j][7], midir, 4, micaster, id, v3);
      AddMissile(sx, sy, sx - vCrawlTable[j][6], sy - vCrawlTable[j][7], midir, 4, micaster, id, v3);
      AddMissile(sx, sy, sx - vCrawlTable[j][6], sy + vCrawlTable[j][7], midir, 4, micaster, id, v3);
      AddMissile(sx, sy, sx + vCrawlTable[j][6], sy - vCrawlTable[j][7], midir, 4, micaster, id, v3);
      v12 = vCrawlTable[j][6];
      v11 = vCrawlTable[j][7];
    }
  }
  if ( !--missile[i]._mirange )
    missile[i]._miDelFlag = 1;
}

//----- (00448D8E) --------------------------------------------------------
void __fastcall MI_Blodboil(int i)
{
  int v1; // eax
  int pnum; // [esp+14h] [ebp-10h]
  int j; // [esp+1Ch] [ebp-8h]
  int ia; // [esp+20h] [ebp-4h]
  int ib; // [esp+20h] [ebp-4h]

  pnum = missile[i]._misource;
  ia = dMonster[missile[i]._miVar1][missile[i]._miVar2];
  if ( ia <= 0 )
    ib = -(ia + 1);
  else
    ib = ia - 1;
  if ( ib > 0 )
  {
    monster[ib]._mhitpoints = 0;
    M_StartKill(ib, pnum);
    AddPlrExperience(pnum, monster[ib].mLevel, (unsigned __int16)monster[ib].mExp);
    dMonster[monster[ib]._mx][monster[ib]._my] = 0;
    monster[ib]._mDelFlag = 1;
    v1 = random(87, 2);
    AddMissile(monster[ib]._mx, monster[ib]._my, monster[ib]._mx, monster[ib]._my, plr[pnum]._pdir, 35, 0, pnum, v1 + 1);
    AddDead(monster[ib]._mx, monster[ib]._my, spurtndx, monster[ib]._mdir);
    plr[pnum]._pHitPoints -= monster[ib]._mmaxhp;
    plr[pnum]._pHPBase -= monster[ib]._mmaxhp;
    for ( j = GetSpellLevel(pnum, 22); j > 0; --j )
    {
      plr[pnum]._pHitPoints += monster[ib]._mmaxhp >> 3;
      plr[pnum]._pHPBase += monster[ib]._mmaxhp >> 3;
    }
    if ( plr[pnum]._pHitPoints > plr[pnum]._pMaxHP )
    {
      plr[pnum]._pHitPoints = plr[pnum]._pMaxHP;
      plr[pnum]._pHPBase = plr[pnum]._pMaxHPBase;
    }
    if ( plr[pnum]._pHitPoints > 0 )
    {
      StartPlrHit(pnum, monster[ib]._mmaxhp >> 3);
    }
    else
    {
      plr[pnum]._pHitPoints = 0;
      SyncPlrKill(pnum);
    }
    UseMana(pnum, 22);
  }
  if ( !--missile[i]._mirange )
    missile[i]._miDelFlag = 1;
}

//----- (00449225) --------------------------------------------------------
void __fastcall MI_Flame(int i)
{
  int id; // [esp+10h] [ebp-8h]
  int v3; // [esp+14h] [ebp-4h]

  id = missile[i]._misource;
  v3 = --missile[i]._mirange;
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 1, missile[i]._mix, missile[i]._miy, 0);
  if ( !missile[i]._mirange && missile[i]._miHitFlag == 1 )
    missile[i]._mirange = v3;
  if ( missile[i]._miVar1 == missile[i]._mirange )
  {
    SetMissAnim(i, 21);
    if ( missile[i]._miVar3 < 3 )
      AddMissile(
        missile[i]._mix,
        missile[i]._miy,
        plr[id].WorldX,
        plr[id].WorldY,
        missile[i]._mimfnum,
        48,
        0,
        id,
        ++missile[i]._miVar3);
  }
  if ( missile[i]._mirange == missile[i]._miVar2 )
  {
    SetMissAnim(i, 20);
    missile[i]._miAnimFrame = missile[i]._miAnimLen + 1;
    missile[i]._miAnimAdd = -1;
  }
  if ( !missile[i]._mirange )
    missile[i]._miDelFlag = 1;
  if ( missile[i]._miVar4 != plr[id].WorldX || missile[i]._miVar5 != plr[id].WorldY )
    missile[i]._miDelFlag = 1;
  PutMissile(i);
}

//----- (00449587) --------------------------------------------------------
void __fastcall MI_Flamec(int i)
{
  int id; // ST2C_4
  int midir; // ST30_4

  --missile[i]._mirange;
  id = missile[i]._misource;
  midir = GetDirection8(missile[i]._mix, missile[i]._miy, missile[i]._miVar1, missile[i]._miVar2);
  AddMissile(missile[i]._mix, missile[i]._miy, plr[id].WorldX, plr[id].WorldY, midir, 48, 0, id, 1);
  if ( !missile[i]._mirange )
    missile[i]._miDelFlag = 1;
}

//----- (004496D6) --------------------------------------------------------
void __fastcall MI_Cbolt(int i)
{
  int v1; // ST2C_4
  int v3[16]; // [esp+24h] [ebp-40h]

  v3[0] = -1;
  v3[1] = 0;
  v3[2] = 1;
  v3[3] = -1;
  v3[4] = 0;
  v3[5] = 1;
  v3[6] = -1;
  v3[7] = -1;
  v3[8] = 0;
  v3[9] = 0;
  v3[10] = 1;
  v3[11] = 1;
  v3[12] = 0;
  v3[13] = 1;
  v3[14] = -1;
  v3[15] = 0;
  --missile[i]._mirange;
  if ( missile[i]._miAnimType != 3 )
  {
    if ( missile[i]._miVar3 )
    {
      --missile[i]._miVar3;
    }
    else
    {
      v1 = (missile[i]._miVar2 + v3[missile[i]._mirnd]) & 7;
      missile[i]._mirnd = ((unsigned __int8)missile[i]._mirnd + 1) & 0xF;
      GetMissileVel(
        i,
        missile[i]._mix,
        missile[i]._miy,
        missile[i]._mix + XDirAdd[v1],
        missile[i]._miy + YDirAdd[v1],
        8);
      missile[i]._miVar3 = 16;
    }
    missile[i]._mitxoff += missile[i]._mixvel;
    missile[i]._mityoff += missile[i]._miyvel;
    GetMissilePos(i);
    CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix, missile[i]._miy, 0);
    if ( missile[i]._miHitFlag == 1 )
    {
      missile[i]._miVar1 = 8;
      missile[i]._mimfnum = 0;
      missile[i]._mixoff = 0;
      missile[i]._miyoff = 0;
      SetMissAnim(i, 3);
      missile[i]._mirange = missile[i]._miAnimLen;
      GetMissilePos(i);
    }
    ChangeLight(missile[i]._mlid, missile[i]._mix, missile[i]._miy, missile[i]._miVar1);
  }
  if ( !missile[i]._mirange )
  {
    missile[i]._miDelFlag = 1;
    AddUnLight(missile[i]._mlid);
  }
  PutMissile(i);
}

//----- (00449ADB) --------------------------------------------------------
void __fastcall MI_Hbolt(int i)
{
  int v1; // ebx
  int mindam; // [esp+10h] [ebp-4h]

  --missile[i]._mirange;
  if ( missile[i]._miAnimType == 29 )
  {
    ChangeLight(missile[i]._mlid, missile[i]._mix, missile[i]._miy, missile[i]._miAnimFrame + 7);
    if ( !missile[i]._mirange )
    {
      missile[i]._miDelFlag = 1;
      AddUnLight(missile[i]._mlid);
    }
  }
  else
  {
    missile[i]._mitxoff += missile[i]._mixvel;
    missile[i]._mityoff += missile[i]._miyvel;
    GetMissilePos(i);
    v1 = random(76, 10);
    mindam = random(76, 10) + v1 + 2;
    if ( missile[i]._mix != missile[i]._misx || missile[i]._miy != missile[i]._misy )
      CheckMissileCol(i, mindam, mindam, 0, missile[i]._mix, missile[i]._miy, 0);
    if ( missile[i]._mirange )
    {
      if ( missile[i]._mix != missile[i]._miVar1 || missile[i]._miy != missile[i]._miVar2 )
      {
        missile[i]._miVar1 = missile[i]._mix;
        missile[i]._miVar2 = missile[i]._miy;
        ChangeLight(missile[i]._mlid, missile[i]._miVar1, missile[i]._miVar2, 8);
      }
    }
    else
    {
      missile[i]._mitxoff -= missile[i]._mixvel;
      missile[i]._mityoff -= missile[i]._miyvel;
      GetMissilePos(i);
      missile[i]._mimfnum = 0;
      SetMissAnim(i, 29);
      missile[i]._mirange = missile[i]._miAnimLen - 1;
    }
  }
  PutMissile(i);
}

//----- (00449ED4) --------------------------------------------------------
void __fastcall MI_Element(int i)
{
  --missile[i]._mirange;
  missile[i]._mitxoff += missile[i]._mixvel;
  missile[i]._mityoff += missile[i]._miyvel;
  GetMissilePos(i);
  if ( missile[i]._mix != missile[i]._misx || missile[i]._miy != missile[i]._misy )
    CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix, missile[i]._miy, 0);
  if ( missile[i]._mix != missile[i]._miVar1 || missile[i]._miy != missile[i]._miVar2 )
  {
    missile[i]._miVar1 = missile[i]._mix;
    missile[i]._miVar2 = missile[i]._miy;
    ChangeLight(missile[i]._mlid, missile[i]._miVar1, missile[i]._miVar2, 8);
  }
  if ( !missile[i]._mirange )
  {
    missile[i]._miDelFlag = 1;
    AddUnLight(missile[i]._mlid);
  }
  PutMissile(i);
}

//----- (0044A170) --------------------------------------------------------
void __fastcall MI_ResurrectBeam(int i)
{
  if ( !--missile[i]._mirange )
    missile[i]._miDelFlag = 1;
  PutMissile(i);
}

//----- (0044A1D8) --------------------------------------------------------
void __cdecl ProcessMissiles()
{
  int v0; // ebx
  int j; // [esp+Ch] [ebp-8h]
  int k; // [esp+Ch] [ebp-8h]
  int l; // [esp+Ch] [ebp-8h]
  int v4; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]
  int ia; // [esp+10h] [ebp-4h]
  int ib; // [esp+10h] [ebp-4h]

  for ( j = 0; nummissiles > j; ++j )
  {
    v0 = missileactive[j];
    dFlags[missile[v0]._mix][missile[v0]._miy] &= 0xFEu;
    dMissile[missile[v0]._mix][missile[v0]._miy] = 0;
  }
  MissilePreFlag = 0;
  ManashieldFlag = 0;
  for ( k = 0; nummissiles > k; ++k )
  {
    i = missileactive[k];
    missiledata[missile[i]._mitype].mProc(missileactive[k]);
    if ( !(missile[i]._miAnimFlags & 2) && ++missile[i]._miAnimCnt >= missile[i]._miAnimDelay )
    {
      missile[i]._miAnimCnt = 0;
      missile[i]._miAnimFrame += missile[i]._miAnimAdd;
      if ( missile[i]._miAnimLen < missile[i]._miAnimFrame )
        missile[i]._miAnimFrame = 1;
      if ( missile[i]._miAnimFrame < 1 )
        missile[i]._miAnimFrame = missile[i]._miAnimLen;
    }
  }
  if ( ManashieldFlag )
  {
    for ( l = 0; nummissiles > l; ++l )
    {
      ia = missileactive[l];
      if ( missile[ia]._mitype == 13 )
        MI_Manashield(ia);
    }
  }
  v4 = 0;
  while ( nummissiles > v4 )
  {
    ib = missileactive[v4];
    if ( missile[ib]._miDelFlag )
    {
      DeleteMissile(ib, v4);
      v4 = 0;
    }
    else
    {
      ++v4;
    }
  }
}

