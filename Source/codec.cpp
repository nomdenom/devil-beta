#include "all.h"

//----- (0047AFD0) --------------------------------------------------------
int __fastcall codec_decode(void *pbSrcDst, int size, char *pszPassword)
{
  int v4; // ST18_4
  int v6; // [esp+Ch] [ebp-BCh]
  unsigned __int8 *pbSrcDst_; // [esp+10h] [ebp-B8h] MAPDST
  char Message_Digest[20]; // [esp+14h] [ebp-B4h]
  char v9[20]; // [esp+28h] [ebp-A0h]
  int j; // [esp+3Ch] [ebp-8Ch]
  char v11[128]; // [esp+40h] [ebp-88h]
  int i; // [esp+C0h] [ebp-8h]

  pbSrcDst_ = (unsigned __int8 *)pbSrcDst;
  assert(pbSrcDst, "CODEC.CPP", 130);
  assert(pszPassword, "CODEC.CPP", 131);
  codec_init_key(0, pszPassword);
  if ( (unsigned int)size <= 8 )
    return 0;
  v6 = size - 8;
  if ( v6 & 0x3F )
    return 0;
  for ( i = v6; i; i -= 64 )
  {
    memcpy(v11, pbSrcDst_, 0x40u);
    SHA1Result(0, v9);
    for ( j = 0; j < 64; ++j )
      v11[j] ^= v9[j % 20];
    SHA1Calculate(0, v11, 0);
    memset(v9, 0, 0x14u);
    memcpy(pbSrcDst_, v11, 0x40u);
    pbSrcDst_ += 64;
  }
  memset(v11, 0, 128u);
  if ( (signed int)pbSrcDst_[4] <= 0 )
  {
    SHA1Result(0, Message_Digest);
    if ( *(_DWORD *)pbSrcDst_ == *(_DWORD *)Message_Digest )
    {
      v4 = v6 - (64 - pbSrcDst_[5]);
      j_SHA1Clear();
      return v4;
    }
    memset(Message_Digest, 0, 20u);
  }
  j_SHA1Clear();
  return 0;
}

//----- (0047B1F6) --------------------------------------------------------
void j_SHA1Clear()
{
  SHA1Clear();
}

//----- (0047B20B) --------------------------------------------------------
void __fastcall codec_init_key(int unused, char *pszPassword)
{
  int v2; // ST20_4
  char v3; // al
  unsigned int j; // [esp+1Ch] [ebp-F4h]
  int v6; // [esp+20h] [ebp-F0h]
  signed int i; // [esp+24h] [ebp-ECh]
  char v8[20]; // [esp+28h] [ebp-E8h]
  char v9[64]; // [esp+3Ch] [ebp-D4h]
  char v10[136]; // [esp+7Ch] [ebp-94h]
  char *v11; // [esp+104h] [ebp-Ch]
  int v12; // [esp+108h] [ebp-8h]
  int n; // [esp+10Ch] [ebp-4h]

  srand(0x7088u);
  v11 = v10;
  v12 = 136;
  while ( 1 )
  {
    v2 = v12--;
    if ( !v2 )
      break;
    v3 = rand();
    *v11++ = v3;
  }
  v6 = 0;
  for ( i = 0; i < 64; ++i )
  {
    if ( !pszPassword[v6] )
      v6 = 0;
    v9[i] = pszPassword[v6++];
  }
  j_SHA1Reset(0);
  SHA1Calculate(0, v9, v8);
  SHA1Clear();
  for ( j = 0; j < 136; ++j )
    v10[j] ^= v8[(signed int)j % 20];
  memset(v9, 0, 64u);
  memset(v8, 0, 20u);
  for ( n = 0; n < 3; ++n )
  {
    j_SHA1Reset(n);
    SHA1Calculate(n, &v10[72], 0);
  }
  memset(v10, 0, 136u);
}

//----- (0047B3E4) --------------------------------------------------------
int __fastcall codec_get_encoded_len(int dwSrcBytes)
{
  int v2; // [esp+Ch] [ebp-4h]

  v2 = dwSrcBytes;
  assert(dwSrcBytes, "CODEC.CPP", 230);
  if ( dwSrcBytes & 0x3F )
    v2 = 64 - (dwSrcBytes & 0x3F) + dwSrcBytes;
  return v2 + 8;
}

//----- (0047B439) --------------------------------------------------------
void __fastcall codec_encode(void *pbSrcDst, int size, int size_64, char *pszPassword)
{
  size_t v4; // eax
  unsigned int dwSrcBytes; // [esp+Ch] [ebp-C0h]
  _DWORD *v6; // [esp+10h] [ebp-BCh] MAPDST
  char v7[20]; // [esp+14h] [ebp-B8h]
  int i; // [esp+28h] [ebp-A4h]
  size_t v9; // [esp+2Ch] [ebp-A0h]
  size_t v10; // [esp+30h] [ebp-9Ch]
  char Message_Digest[20]; // [esp+34h] [ebp-98h]
  char v12[128]; // [esp+48h] [ebp-84h]

  dwSrcBytes = size;
  v6 = pbSrcDst;
  assert(pbSrcDst, "CODEC.CPP", 241);
  assert(pszPassword, "CODEC.CPP", 242);
  if ( codec_get_encoded_len(size) != size_64 )
    TermMsg("Invalid encode parameters");
  codec_init_key(1, pszPassword);
  v10 = 0;
  while ( dwSrcBytes )
  {
    v4 = dwSrcBytes;
    if ( dwSrcBytes >= 0x40 )
      v4 = 64;
    v9 = v4;
    memcpy(v12, v6, v4);
    if ( v9 < 64 )
      memset(&v12[v9], 0, 64 - v9);
    SHA1Result(0, v7);
    SHA1Calculate(0, v12, 0);
    for ( i = 0; i < 64; ++i )
      v12[i] ^= v7[i % 20];
    memset(v7, 0, 20u);
    memcpy(v6, v12, 64u);
    v6 += 16;
    dwSrcBytes -= v9;
    v10 = v9;
  }
  memset(v12, 0, 0x80u);
  SHA1Result(0, Message_Digest);
  *v6 = *(_DWORD *)Message_Digest;
  *((_BYTE *)v6 + 4) = 0;
  *((_BYTE *)v6 + 5) = v10;
  *((_WORD *)v6 + 3) = 0;
  j_SHA1Clear();
}

