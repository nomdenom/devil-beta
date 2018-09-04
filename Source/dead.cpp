//----- (00466F10) --------------------------------------------------------
void __cdecl InitDead()
{
  signed int k; // [esp+Ch] [ebp-330h]
  signed int l; // [esp+Ch] [ebp-330h]
  signed int m; // [esp+Ch] [ebp-330h]
  signed int ii; // [esp+Ch] [ebp-330h]
  signed int i; // [esp+10h] [ebp-32Ch]
  int j; // [esp+10h] [ebp-32Ch]
  int n; // [esp+10h] [ebp-32Ch]
  int mtypes[200]; // [esp+14h] [ebp-328h]
  int v8; // [esp+334h] [ebp-8h]
  int v9; // [esp+338h] [ebp-4h]

  for ( i = 0; i < 200; ++i )
    mtypes[i] = 0;
  v9 = 0;
  for ( j = 0; nummtypes > j; ++j )
  {
    if ( !mtypes[Monsters[j].mtype] )
    {
      for ( k = 0; k < 8; ++k )
        dead[v9]._deadData[k] = Monsters[j].Anims[4].Frames[k];
      dead[v9]._deadFrame = Monsters[j].Anims[4].Rate;
      dead[v9].flags_1 = Monsters[j].flags_1;
      dead[v9].flags_2 = Monsters[j].flags_2;
      dead[v9]._deadtrans = 0;
      Monsters[j].mdeadval = v9 + 1;
      mtypes[Monsters[j].mtype] = v9++ + 1;
    }
  }
  for ( l = 0; l < 8; ++l )
    dead[v9]._deadData[l] = misfiledata[16].mAnimData[0];
  dead[v9]._deadFrame = 8;
  dead[v9].flags_1 = 128;
  dead[v9].flags_2 = 32;
  dead[v9]._deadtrans = 0;
  spurtndx = v9++ + 1;
  for ( m = 0; m < 8; ++m )
    dead[v9]._deadData[m] = misfiledata[18].mAnimData[0];
  dead[v9]._deadFrame = 12;
  dead[v9].flags_1 = 128;
  dead[v9].flags_2 = 32;
  dead[v9]._deadtrans = 0;
  stonendx = v9++ + 1;
  for ( n = 0; n < nummonsters; ++n )
  {
    v8 = monstactive[n];
    if ( monster[v8]._uniqtype )
    {
      for ( ii = 0; ii < 8; ++ii )
        dead[v9]._deadData[ii] = monster[v8].MType->Anims[4].Frames[ii];
      dead[v9]._deadFrame = monster[v8].MType->Anims[4].Rate;
      dead[v9].flags_1 = monster[v8].MType->flags_1;
      dead[v9].flags_2 = monster[v8].MType->flags_2;
      dead[v9]._deadtrans = monster[v8]._uniqtrans + 4;
      monster[v8]._udeadval = v9++ + 1;
    }
  }
}

//----- (0046735F) --------------------------------------------------------
void __fastcall AddDead(int dx, int dy, char dv, int ddir)
{
  dDead[dx][dy] = 32 * (ddir & 7) + (dv & 0x1F);
}

