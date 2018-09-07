//----- (0044E3D0) --------------------------------------------------------
void __cdecl LoadDebugGFX()
{
  assert(!pSquareCel, "DEBUG.CPP", 32);
}

//----- (0044E401) --------------------------------------------------------
void __cdecl FreeDebugGFX()
{
  pSquareCel = 0;
}

//----- (0044E41B) --------------------------------------------------------
signed int unused_sub_44E41B()
{
  signed int result; // eax
  signed int i; // [esp+Ch] [ebp-4h]
  signed int j; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 4096; ++i )
  {
    result = i;
    dword_623480[i] = -1;
  }
  dword_623430 = 0;
  for ( j = 0; j < 17; ++j )
  {
    result = j;
    dword_623438[j] = 0;
  }
  return result;
}

//----- (0044E493) --------------------------------------------------------
int unused_sub_44E493()
{
  int result; // eax

  result = currlevel;
  if ( currlevel )
  {
    result = dword_623438[currlevel];
    dword_623430 = dword_623438[currlevel];
    dword_4D0B78 = 1;
  }
  return result;
}

//----- (0044E4D4) --------------------------------------------------------
int unused_sub_44E4D4()
{
  int result; // eax

  result = currlevel;
  if ( currlevel )
  {
    result = dword_623430;
    dword_62343C[currlevel] = dword_623430;
    dword_4D0B78 = 0;
  }
  return result;
}

//----- (0044E516) --------------------------------------------------------
int __fastcall unused_sub_44E516(int a1)
{
  int result; // eax

  if ( dword_4D0B78 )
  {
    if ( dword_623430 != 4096 )
    {
      result = currlevel;
      if ( currlevel )
      {
        if ( dword_623480[dword_623430] == -1 )
        {
          result = a1;
          dword_623480[dword_623430] = a1;
        }
        else
        {
          result = dword_623430;
          if ( dword_623480[dword_623430] != a1 )
            TermMsg("Seeds desynced");
        }
        ++dword_623430;
      }
    }
  }
  return result;
}

