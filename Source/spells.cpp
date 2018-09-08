#include "all.h"

//----- (0045B6D0) --------------------------------------------------------
int __fastcall GetManaAmount(int id, int sn)
{
  int v2; // ecx
  int v3; // eax
  int v6; // [esp+14h] [ebp-10h]
  int v7; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  int j; // [esp+1Ch] [ebp-8h]
  int k; // [esp+1Ch] [ebp-8h]
  int v11; // [esp+20h] [ebp-4h]
  int v12; // [esp+20h] [ebp-4h]

  v11 = 0;
  v6 = plr[id]._pISplLvlAdd + plr[id]._pSplLvl[sn];
  if ( v6 < 0 )
    v6 = 0;
  for ( i = v6; i > 0; --i )
    v11 += spelldata[sn].sManaAdj;
  if ( sn == 30 )
    v11 = -v11;
  if ( sn == 1 )
    v11 >>= 1;
  if ( sn == 32 && v6 > 0 )
  {
    v11 = 0;
    for ( j = v6; j > 0; --j )
      v11 += (signed int)spelldata[32].sManaCost >> 3;
  }
  if ( spelldata[sn].sManaCost == 255 )
    v2 = LOBYTE(plr[id]._pMaxManaBase) - v11;
  else
    v2 = spelldata[sn].sManaCost - v11;
  v7 = v2 << 6;
  if ( sn == 2 )
    v7 = (spelldata[2].sManaCost + 2 * plr[id]._pLevel - v11) << 6;
  if ( sn == 34 )
    v7 = (spelldata[2].sManaCost + 2 * plr[id]._pLevel - v11) << 6;
  if ( sn == 32 )
  {
    v12 = 0;
    for ( k = v6; k > 0; --k )
      v12 += spelldata[32].sManaCost;
  }
  v3 = plr[id]._pClass;
  if ( v3 == 1 )
    v7 -= v7 >> 2;
  if ( v7 <= 0 )
    v7 = 64;
  return v7 * (100 - plr[id]._pISplCost) / 100;
}

//----- (0045B99D) --------------------------------------------------------
void __fastcall UseMana(int id, int sn)
{
  int v2; // ST18_4

  if ( myplr == id )
  {
    switch ( plr[id]._pSplType )
    {
      case 0:
      case 4:
        return;
      case 1:
        v2 = GetManaAmount(id, sn);
        plr[id]._pMana -= v2;
        plr[id]._pManaBase -= v2;
        drawhpflag = 1;
        break;
      case 2:
        RemoveScroll(id);
        break;
      case 3:
        UseStaffCharge(id);
        break;
    }
  }
}

//----- (0045BAA1) --------------------------------------------------------
BOOL __fastcall CheckSpell(int id, int sn, char st, bool manaonly)
{
  if ( !manaonly && pcurs != 1 )
    return 0;
  if ( !st )
    return 1;
  if ( GetSpellLevel(id, sn) > 0 )
    return plr[id]._pMana >= GetManaAmount(id, sn);
  return 0;
}

//----- (0045BB4A) --------------------------------------------------------
void __fastcall CastSpell(int id, int spl, int sx, int sy, int dx, int dy, int caster)
{
  int midir; // [esp+18h] [ebp-8h]
  signed int i; // [esp+1Ch] [ebp-4h]
  int j; // [esp+1Ch] [ebp-4h]

  if ( caster )
  {
    if ( caster == 1 )
      midir = monster[id]._mdir;
  }
  else
  {
    midir = plr[id]._pdir;
    caster = 0;
  }
  for ( i = 0; spelldata[spl]._sMissiles[i] && i < 3; ++i )
    AddMissile(sx, sy, dx, dy, midir, (unsigned __int8)spelldata[spl]._sMissiles[i], caster, id, 0);
  if ( spelldata[spl]._sMissiles[0] == 10 )
    UseMana(id, 7);
  if ( spelldata[spl]._sMissiles[0] == 52 )
  {
    UseMana(id, 30);
    for ( j = GetSpellLevel(id, 30) + 2; j > 0; --j )
      AddMissile(sx, sy, dx, dy, midir, 52, caster, id, 0);
  }
}

//----- (0045BCDF) --------------------------------------------------------
void __fastcall DoResurrect(int pnum, int rid)
{
  if ( (char)rid != -1 )
    AddMissile(plr[rid].WorldX, plr[rid].WorldY, plr[rid].WorldX, plr[rid].WorldY, 0, 62, 0, pnum, 0);
  if ( myplr == pnum )
    j_SetCursor(1);
  if ( (char)rid != -1 && !plr[rid]._pHitPoints )
  {
    if ( rid == myplr )
    {
      deathflag = 0;
      gamemenu_off();
      drawmanaflag = 1;
      drawhpflag = 1;
    }
    plr[rid]._pInvincible = 0;
    SetPlayerHitPoints(rid, 64);
    if ( plr[rid].plrlevel == currlevel )
      StartStand(rid, plr[rid]._pdir);
    else
      plr[rid]._pmode = 0;
    plr[rid]._pHPBase = plr[rid]._pHitPoints - (plr[rid]._pMaxHP - plr[rid]._pMaxHPBase);
    plr[rid]._pMana = 0;
    plr[rid]._pManaBase = plr[rid]._pMana - (plr[rid]._pMaxMana - plr[rid]._pMaxManaBase);
    CalcPlrInv(rid, 0);
  }
}

//----- (0045BFC4) --------------------------------------------------------
void __fastcall DoHealOther(int pnum, int rid)
{
  int v4; // [esp+14h] [ebp-8h]
  signed int i; // [esp+18h] [ebp-4h]
  int j; // [esp+18h] [ebp-4h]

  if ( myplr == pnum )
    j_SetCursor(1);
  if ( (char)rid != -1 && (signed int)(plr[rid]._pHitPoints & 0xFFFFFFC0) > 0 )
  {
    v4 = (random(57, 10) + 1) << 6;
    for ( i = 0; plr[pnum]._pLevel > i; ++i )
      v4 += (random(57, 4) + 1) << 6;
    for ( j = 0; GetSpellLevel(pnum, 34) > j; ++j )
      v4 += (random(57, 6) + 1) << 6;
    if ( !plr[pnum]._pClass )
      v4 *= 2;
    if ( plr[pnum]._pClass == 1 )
      v4 += v4 >> 1;
    plr[rid]._pHitPoints += v4;
    if ( plr[rid]._pHitPoints > plr[rid]._pMaxHP )
      plr[rid]._pHitPoints = plr[rid]._pMaxHP;
    plr[rid]._pHPBase += v4;
    if ( plr[rid]._pMaxHPBase < plr[rid]._pHPBase )
      plr[rid]._pHPBase = plr[rid]._pMaxHPBase;
    drawmanaflag = 1;
  }
}

