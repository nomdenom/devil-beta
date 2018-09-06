//----- (0047AAE0) --------------------------------------------------------
void __fastcall encrypt_decrypt_block(void *block, int size, int key)
{
  unsigned int v3; // ST14_4
  int v4; // ST1C_4
  _DWORD *v5; // [esp+10h] [ebp-10h]
  unsigned int v6; // [esp+18h] [ebp-8h]
  int v7; // [esp+1Ch] [ebp-4h]

  v5 = block;
  v7 = -286331154;
  v6 = (unsigned int)size >> 2;
  while ( 1 )
  {
    v3 = v6--;
    if ( !v3 )
      break;
    v4 = dword_643C30[(unsigned __int8)key] + v7;
    *v5 ^= key + v4;
    v7 = *v5 + 32 * v4 + 3 + v4;
    ++v5;
    key = ((unsigned int)key >> 11) | (((key << 21) ^ 0xFFE00000) + 286331153);
  }
}

//----- (0047AB70) --------------------------------------------------------
void __fastcall encrypt_encrypt_block(void *block, int size, int key)
{
  unsigned int v3; // ST14_4
  int v4; // ST18_4
  int v5; // ST20_4
  int *v6; // [esp+10h] [ebp-14h]
  unsigned int v7; // [esp+1Ch] [ebp-8h]
  int v8; // [esp+20h] [ebp-4h]

  v6 = (int *)block;
  v8 = -286331154;
  v7 = (unsigned int)size >> 2;
  while ( 1 )
  {
    v3 = v7--;
    if ( !v3 )
      break;
    v4 = *v6;
    v5 = dword_643C30[(unsigned __int8)key] + v8;
    *v6 ^= key + v5;
    ++v6;
    v8 = v4 + 32 * v5 + 3 + v5;
    key = ((unsigned int)key >> 11) | (((key << 21) ^ 0xFFE00000) + 286331153);
  }
}

//----- (0047AC09) --------------------------------------------------------
int __fastcall encrypt_hash(char *s, int type)
{
  char *v2; // ST18_4
  char v3; // ST1C_1
  char *v6; // [esp+10h] [ebp-14h]
  unsigned int v7; // [esp+1Ch] [ebp-8h]
  signed int v8; // [esp+20h] [ebp-4h]

  v6 = s;
  v8 = 0x7FED7FED;
  v7 = 0xEEEEEEEE;
  while ( v6 && *v6 )
  {
    v2 = v6++;
    v3 = toupper(*v2);
    v8 = (v8 + v7) ^ encrypt_table[256 * type + v3];
    v7 += v8 + 32 * v7 + v3 + 3;
  }
  return v8;
}

//----- (0047AC9C) --------------------------------------------------------
void __cdecl encrypt_init_lookup_table()
{
  unsigned int v0; // ST18_4
  int v1; // ST10_4
  signed int j; // [esp+14h] [ebp-Ch]
  unsigned int v3; // [esp+18h] [ebp-8h]
  signed int i; // [esp+1Ch] [ebp-4h]

  v3 = 1048577;
  for ( i = 0; i < 256; ++i )
  {
    for ( j = 0; j < 5; ++j )
    {
      v0 = (125 * v3 + 3) % 0x2AAAAB;
      v1 = (unsigned __int16)v0;
      v3 = (125 * v0 + 3) % 0x2AAAAB;
      encrypt_table[256 * j + i] = (unsigned __int16)v3 | (v1 << 16);
    }
  }
}

//----- (0047AD56) --------------------------------------------------------
int __fastcall encrypt_compress(void *buf, int size)
{
  int v2; // ecx
  unsigned __int8 *v4; // [esp+Ch] [ebp-2Ch]
  unsigned __int8 *v5; // [esp+10h] [ebp-28h]
  _DWORD *ptr; // [esp+14h] [ebp-24h]
  int v7; // [esp+18h] [ebp-20h]
  int v8; // [esp+1Ch] [ebp-1Ch]
  TDataInfo v9; // [esp+20h] [ebp-18h]
  void *v10; // [esp+34h] [ebp-4h]

  v4 = (unsigned __int8 *)size;
  v5 = (unsigned __int8 *)buf;
  ptr = DiabloAllocPtr(36312, 112, "encrypt.cpp");
  v2 = 2 * (_DWORD)v4;
  if ( (unsigned int)(2 * (_DWORD)v4) <= 0x2000 )
    v2 = 0x2000;
  v10 = DiabloAllocPtr(v2, 113, "encrypt.cpp");
  v9.pbInBuff = v5;
  v9.pbInBuffEnd = 0;
  v9.pbOutBuff = (unsigned __int8 *)v10;
  v9.pbOutBuffEnd = 0;
  v9.pbSize = v4;
  v8 = 0;
  v7 = 4096;
  implode((int)encrypt_pkware_read, (int)encrypt_pkware_write, ptr, (int)&v9, &v8, &v7);
  if ( v9.pbOutBuffEnd < v4 )
  {
    memcpy(v5, v10, (size_t)v9.pbOutBuffEnd);
    v4 = v9.pbOutBuffEnd;
  }
  mem_free_dbg(ptr, 135, "encrypt.cpp");
  mem_free_dbg(v10, 136, "encrypt.cpp");
  return (int)v4;
}

//----- (0047AE4D) --------------------------------------------------------
unsigned int __cdecl encrypt_pkware_read(char *buf, unsigned int *size, TDataInfo *param)
{
  unsigned int v3; // eax
  unsigned int v4; // ST18_4

  v3 = param->pbSize - param->pbInBuffEnd;
  if ( v3 >= *size )
    v3 = *size;
  v4 = v3;
  memcpy(buf, &param->pbInBuff[(unsigned int)param->pbInBuffEnd], v3);
  param->pbInBuffEnd += v4;
  return v4;
}

//----- (0047AEAC) --------------------------------------------------------
void __cdecl encrypt_pkware_write(char *buf, unsigned int *size, TDataInfo *param)
{
  memcpy(&param->pbOutBuff[(unsigned int)param->pbOutBuffEnd], buf, *size);
  param->pbOutBuffEnd += *size;
}

//----- (0047AEEF) --------------------------------------------------------
void __fastcall encrypt_decompress(void *param, int recv_size, int dwMaxBytes)
{
  unsigned __int8 *v3; // ST1C_4
  unsigned __int8 *v4; // [esp+10h] [ebp-20h]
  void *ptr; // [esp+14h] [ebp-1Ch]
  TDataInfo v6; // [esp+18h] [ebp-18h]
  void *v7; // [esp+2Ch] [ebp-4h]

  v3 = (unsigned __int8 *)recv_size;
  v4 = (unsigned __int8 *)param;
  ptr = DiabloAllocPtr(36312, 145, "encrypt.cpp");
  v7 = DiabloAllocPtr(dwMaxBytes, 146, "encrypt.cpp");
  v6.pbInBuff = v4;
  v6.pbInBuffEnd = 0;
  v6.pbOutBuff = (unsigned __int8 *)v7;
  v6.pbOutBuffEnd = 0;
  v6.pbSize = v3;
  explode((int)encrypt_pkware_read, (int)encrypt_pkware_write, (int)ptr, (int)&v6);
  assert(v6.pbOutBuffEnd <= (unsigned __int8 *)dwMaxBytes, 158, "encrypt.cpp");
  memcpy(v4, v7, (size_t)v6.pbOutBuffEnd);
  mem_free_dbg(ptr, 163, "encrypt.cpp");
  mem_free_dbg(v7, 164, "encrypt.cpp");
}

