#include "all.h"

//----- (0041F1A8) --------------------------------------------------------
BOOL __cdecl mpqapi_write_header()
{
  TMPQHeader_buffer Buffer; // [esp+Ch] [ebp-64h]
  int NumberOfBytesWritten; // [esp+6Ch] [ebp-4h]

  memset(&Buffer, 0, 0x60u);
  Buffer.header.dwID = '\x1AQPM';
  Buffer.header.dwHeaderSize = 32;
  Buffer.header.dwArchiveSize = GetFileSize(hFile, 0);
  Buffer.header.wFormatVersion = 0;
  Buffer.header.wSectorSize = 3;
  Buffer.header.dwHashTablePos = 32864;
  Buffer.header.dwBlockTablePos = 96;
  Buffer.header.dwHashTableSize = 2048;
  Buffer.header.dwBlockTableSize = 2048;
  if ( SetFilePointer(hFile, 0, 0, 0) == -1 )
    return 0;
  if ( WriteFile(hFile, &Buffer, 0x60u, (LPDWORD)&NumberOfBytesWritten, 0) )
    return NumberOfBytesWritten == 96;
  return 0;
}

//----- (0041F271) --------------------------------------------------------
BOOL __cdecl mpqapi_write_block_table()
{
  int v0; // eax
  int NumberOfBytesWritten; // [esp+Ch] [ebp-4h]

  v0 = encrypt_hash("(block table)", 3);
  encrypt_encrypt_block(sgpBlockTbl, 0x8000, v0);
  if ( SetFilePointer(hFile, 96, 0, 0) == -1 )
    return 0;
  if ( WriteFile(hFile, sgpBlockTbl, 0x8000u, (LPDWORD)&NumberOfBytesWritten, 0) )
    return NumberOfBytesWritten == 0x8000;
  return 0;
}

//----- (0041F30B) --------------------------------------------------------
BOOL __cdecl mpqapi_write_hash_table()
{
  int v0; // eax
  int NumberOfBytesWritten; // [esp+Ch] [ebp-4h]

  v0 = encrypt_hash("(hash table)", 3);
  encrypt_encrypt_block(sgpHashTbl, 0x8000, v0);
  if ( SetFilePointer(hFile, 32864, 0, 0) == -1 )
    return 0;
  if ( WriteFile(hFile, sgpHashTbl, 0x8000u, (LPDWORD)&NumberOfBytesWritten, 0) )
    return NumberOfBytesWritten == 0x8000;
  return 0;
}

//----- (0041F3A8) --------------------------------------------------------
BOOL __cdecl mpqapi_can_seek()
{
  BOOL result; // eax

  if ( SetFilePointer(hFile, lDistanceToMove, 0, 0) == -1 )
    result = 0;
  else
    result = SetEndOfFile(hFile);
  return result;
}

//----- (0041F3EA) --------------------------------------------------------
void __fastcall mpqapi_close_archive(char *pszArchive, bool bFree, int dwChar)
{
  if ( sgpBlockTbl )
  {
    mem_free_dbg(sgpBlockTbl, 314, "mpqapi.cpp");
    sgpBlockTbl = 0;
  }
  if ( sgpHashTbl )
  {
    mem_free_dbg(sgpHashTbl, 318, "mpqapi.cpp");
    sgpHashTbl = 0;
  }
  CloseHandle(hFile);
  hFile = (HANDLE)-1;
}

//----- (0041F468) --------------------------------------------------------
BOOL __fastcall mpqapi_open_archive(char *pszArchive, BOOL hidden)
{
  bool v3; // dl
  char *v4; // ecx
  int v5; // eax
  int v6; // eax
  int v7; // [esp+0h] [ebp-38h]
  TMPQHeader a1; // [esp+14h] [ebp-24h]
  int NumberOfBytesRead; // [esp+34h] [ebp-4h]

  assert(pszArchive, "mpqapi.cpp", 382);
  encrypt_init_lookup_table();
  hFile = CreateFileA(pszArchive, 0xC0000000, 0, 0, 3u, 0, 0);
  if ( hFile == (HANDLE)-1 )
  {
    if ( !hidden )
      return 0;
    hFile = CreateFileA(pszArchive, 0xC0000000, 0, 0, 2u, 0, 0);
    if ( hFile == (HANDLE)-1 )
      return 0;
  }
  memset(&a1, 0, 0x20u);
  if ( !mpqapi_parse_archive_header(&a1, &lDistanceToMove) )
    goto LABEL_30;
  sgpBlockTbl = (_BLOCKENTRY *)DiabloAllocPtr(0x8000, 417, "mpqapi.cpp");
  memset(sgpBlockTbl, 0, 0x8000u);
  if ( a1.dwBlockTableSize )
  {
    assert(a1.dwBlockTableSize == 2048, "mpqapi.cpp", 422);
    assert(a1.dwBlockTablePos == 96, "mpqapi.cpp", 423);
    if ( SetFilePointer(hFile, 96, 0, 0) == -1 || !ReadFile(hFile, sgpBlockTbl, 0x8000u, (LPDWORD)&NumberOfBytesRead, 0) )
      goto LABEL_30;
    assert(NumberOfBytesRead == 0x8000, "mpqapi.cpp", 428);
    v5 = encrypt_hash("(block table)", 3);
    encrypt_decrypt_block(sgpBlockTbl, 0x8000, v5);
  }
  sgpHashTbl = (_HASHENTRY *)DiabloAllocPtr(0x8000, 438, "mpqapi.cpp");
  memset(sgpHashTbl, 255, 0x8000u);
  if ( !a1.dwHashTableSize )
    return 1;
  assert(a1.dwHashTableSize == 2048, "mpqapi.cpp", 443);
  assert(a1.dwHashTablePos == 32864, "mpqapi.cpp", 444);
  if ( SetFilePointer(hFile, 32864, 0, 0) != -1 && ReadFile(hFile, sgpHashTbl, 0x8000u, (LPDWORD)&NumberOfBytesRead, 0) )
  {
    assert(NumberOfBytesRead == 0x8000, "mpqapi.cpp", 449);
    v6 = encrypt_hash("(hash table)", 3);
    encrypt_decrypt_block(sgpHashTbl, 0x8000, v6);
    return 1;
  }
LABEL_30:
  mpqapi_close_archive(v4, v3, v7);
  return 0;
}

//----- (0041F78C) --------------------------------------------------------
BOOL __fastcall mpqapi_parse_archive_header(TMPQHeader *pHdr, int *pdwNextFileStart)
{
  int NumberOfBytesRead; // [esp+14h] [ebp-Ch]
  int v6; // [esp+18h] [ebp-8h]
  unsigned int v7; // [esp+1Ch] [ebp-4h]

  assert(pHdr, "mpqapi.cpp", 330);
  v6 = 0;
  v7 = GetFileSize(hFile, 0);
  *pdwNextFileStart = v7;
  if ( v7 != -1 && v7 )
  {
    if ( v7 >= 0x20 )
    {
      if ( ReadFile(hFile, pHdr, 0x20u, (LPDWORD)&NumberOfBytesRead, 0) )
      {
        assert(NumberOfBytesRead == 32, "mpqapi.cpp", 345);
      }
      else
      {
        v6 = 1;
      }
    }
    else
    {
      v6 = 1;
    }
  }
  else
  {
    v6 = 1;
  }
  if ( !v6 )
  {
    if ( pHdr->dwID == 441536589 )
    {
      if ( pHdr->dwHeaderSize == 32 )
      {
        if ( (signed int)(unsigned __int16)pHdr->wFormatVersion <= 0 )
        {
          if ( pHdr->wSectorSize == 3 )
          {
            if ( pHdr->dwArchiveSize != v7 )
              v6 = 1;
          }
          else
          {
            v6 = 1;
          }
        }
        else
        {
          v6 = 1;
        }
      }
      else
      {
        v6 = 1;
      }
    }
    else
    {
      v6 = 1;
    }
  }
  if ( v6 )
  {
    if ( SetFilePointer(hFile, 0, 0, 0) == -1 )
      return 0;
    if ( !SetEndOfFile(hFile) )
      return 0;
    memset(pHdr, 0, 0x20u);
    pHdr->dwID = 441536589;
    pHdr->dwHeaderSize = 32;
    pHdr->wSectorSize = 3;
    pHdr->wFormatVersion = 0;
    *pdwNextFileStart = 65632;
  }
  return 1;
}

//----- (0041F97C) --------------------------------------------------------
void __fastcall mpqapi_remove_hash_entry(char *pszName)
{
  _BLOCKENTRY *v1; // ST2C_4
  int block_offset; // ST28_4
  int block_size; // ST20_4
  int v4; // [esp+18h] [ebp-Ch]

  v4 = mpqapi_get_hash_index_of_path(pszName);
  if ( v4 != -1 )
  {
    v1 = &sgpBlockTbl[sgpHashTbl[v4].block];
    sgpHashTbl[v4].block = -1;
    block_offset = v1->offset;
    block_size = v1->sizealloc;
    memset(v1, 0, 0x10u);
    mpqapi_alloc_block(block_offset, block_size);
  }
}

//----- (0041FA0A) --------------------------------------------------------
void __fastcall mpqapi_alloc_block(int block_offset, int block_size)
{
  signed int v2; // ST20_4
  _BLOCKENTRY *v3; // eax
  int block_sizeb; // [esp+Ch] [ebp-14h]
  signed int v7; // [esp+18h] [ebp-8h]
  _BLOCKENTRY *blockTbl; // [esp+1Ch] [ebp-4h]

  blockTbl = sgpBlockTbl;
  v7 = 2048;
  while ( 1 )
  {
    v2 = v7--;
    if ( !v2 )
      break;
    if ( blockTbl->offset && !blockTbl->flags && !blockTbl->sizefile )
    {
      if ( blockTbl->offset + blockTbl->sizealloc == block_offset )
      {
        block_offset = blockTbl->offset;
        block_sizeb = blockTbl->sizealloc + block_size;
LABEL_12:
        memset(blockTbl, 0, 0x10u);
        mpqapi_alloc_block(block_offset, block_sizeb);
        return;
      }
      if ( block_offset + block_size == blockTbl->offset )
      {
        block_sizeb = blockTbl->sizealloc + block_size;
        goto LABEL_12;
      }
    }
    ++blockTbl;
  }
  if ( block_offset + block_size > (unsigned int)lDistanceToMove )
    TermMsg("MPQ free list error");
  if ( block_offset + block_size == lDistanceToMove )
  {
    lDistanceToMove = block_offset;
  }
  else
  {
    v3 = mpqapi_new_block(0);
    v3->offset = block_offset;
    v3->sizealloc = block_size;
    v3->sizefile = 0;
    v3->flags = 0;
  }
}

//----- (0041FB63) --------------------------------------------------------
_BLOCKENTRY *__fastcall mpqapi_new_block(int *block_index)
{
  unsigned int v2; // [esp+10h] [ebp-8h]
  _BLOCKENTRY *v3; // [esp+14h] [ebp-4h]

  v3 = sgpBlockTbl;
  v2 = 0;
  while ( 1 )
  {
    if ( v2 >= 0x800 )
      TermMsg("Out of free block entries");
    if ( !v3->offset && !v3->sizealloc && !v3->flags && !v3->sizefile )
      break;
    ++v2;
    ++v3;
  }
  if ( block_index )
    *block_index = v2;
  return v3;
}

//----- (0041FC16) --------------------------------------------------------
int __fastcall mpqapi_get_hash_index_of_path(char *pszName)
{
  int v2; // ST00_4
  int v3; // ebx
  __int16 v4; // ax

  v2 = encrypt_hash(pszName, 2);
  v3 = encrypt_hash(pszName, 1);
  v4 = encrypt_hash(pszName, 0);
  return mpqapi_get_hash_index(v4, v3, v2, 0);
}

//----- (0041FC5E) --------------------------------------------------------
int __fastcall mpqapi_get_hash_index(__int16 index, int hash_a, int hash_b, int locale)
{
  int i; // [esp+14h] [ebp-4h]

  for ( i = index & 0x7FF; sgpHashTbl[i].block != -1; i = ((_WORD)i + 1) & 0x7FF )
  {
    if ( sgpHashTbl[i].hashcheck[0] == hash_a && sgpHashTbl[i].hashcheck[1] == hash_b && sgpHashTbl[i].lcid == locale )
      return i;
  }
  return -1;
}

//----- (0041FD17) --------------------------------------------------------
void __fastcall mpqapi_remove_hash_entries(bool (__stdcall *fnGetName)(int, char *))
{
  int dwChar; // ST14_4
  bool v2; // dl
  char *v3; // ecx
  int v4; // eax
  int v5; // [esp+0h] [ebp-120h]
  int v6; // [esp+10h] [ebp-110h]
  int i; // [esp+18h] [ebp-108h]
  char pszName; // [esp+1Ch] [ebp-104h]
  char *pszArchive; // [esp+128h] [ebp+8h]
  int (__stdcall *v10)(int, char *); // [esp+12Ch] [ebp+Ch]

  assert(pszArchive, "mpqapi.cpp", 529);
  assert(v10, "mpqapi.cpp", 530);
  if ( mpqapi_open_archive(pszArchive, 0) )
  {
    v6 = 0;
    for ( i = 0; ; i |= v4 )
    {
      dwChar = v6++;
      if ( !v10(dwChar, &pszName) )
        break;
      mpqapi_remove_hash_entry(&pszName);
    }
    if ( i && mpqapi_can_seek() && mpqapi_write_header() )
    {
      if ( mpqapi_write_block_table() )
        mpqapi_write_hash_table();
    }
    mpqapi_close_archive(v3, v2, v5);
  }
}

//----- (0041FE66) --------------------------------------------------------
BOOL __fastcall mpqapi_write_file(char *pszName, char *pbData, int dwLen)
{
  _BLOCKENTRY *v4; // ST04_4
  bool v5; // dl
  char *v6; // ecx
  int v7; // [esp+0h] [ebp-14h]
  BOOL v8; // [esp+Ch] [ebp-8h]
  char *pszNamea; // [esp+20h] [ebp+Ch]
  char *pbDataa; // [esp+24h] [ebp+10h]
  int v11; // [esp+28h] [ebp+14h]

  if ( !mpqapi_open_archive((char *)dwLen, 1) )
    return 0;
  v8 = 1;
  mpqapi_remove_hash_entry(pszNamea);
  v4 = mpqapi_add_file(pszNamea);
  if ( mpqapi_write_file_contents(pszNamea, pbDataa, v11, v4) )
  {
    if ( mpqapi_can_seek() )
    {
      if ( mpqapi_write_header() )
      {
        if ( mpqapi_write_block_table() )
        {
          if ( !mpqapi_write_hash_table() )
            v8 = 0;
        }
        else
        {
          v8 = 0;
        }
      }
      else
      {
        v8 = 0;
      }
    }
    else
    {
      v8 = 0;
    }
  }
  else
  {
    mpqapi_remove_hash_entry(pszNamea);
    v8 = 0;
  }
  mpqapi_close_archive(v6, v5, v7);
  return v8;
}

//----- (0041FF47) --------------------------------------------------------
_BLOCKENTRY *__fastcall mpqapi_add_file(char *pszName)
{
  int block_indexa; // [esp+10h] [ebp-18h]
  int index; // [esp+14h] [ebp-14h]
  int hash_b; // [esp+18h] [ebp-10h]
  int i; // [esp+1Ch] [ebp-Ch]
  int hash_a; // [esp+20h] [ebp-8h]
  _BLOCKENTRY *v8; // [esp+24h] [ebp-4h]

  index = encrypt_hash(pszName, 0);
  hash_a = encrypt_hash(pszName, 1);
  hash_b = encrypt_hash(pszName, 2);
  if ( mpqapi_get_hash_index(index, hash_a, hash_b, 0) != -1 )
    TermMsg("Hash collision between \"%s\" and existing file\n", pszName);
  for ( i = index & 0x7FF; sgpHashTbl[i].block != -1; i = ((_WORD)i + 1) & 0x7FF )
    ;
  v8 = mpqapi_new_block(&block_indexa);
  sgpHashTbl[i].hashcheck[0] = hash_a;
  sgpHashTbl[i].hashcheck[1] = hash_b;
  sgpHashTbl[i].lcid = 0;
  sgpHashTbl[i].block = block_indexa;
  return v8;
}

//----- (00420042) --------------------------------------------------------
BOOL __fastcall mpqapi_write_file_contents(char *pszName, char *pbData, int dwLen, _BLOCKENTRY *pBlk)
{
  char *i; // eax
  char *j; // eax
  int v7; // eax
  char *v8; // [esp+Ch] [ebp-34h]
  char *s; // [esp+10h] [ebp-30h]
  unsigned int block_size; // [esp+14h] [ebp-2Ch]
  int NumberOfBytesWritten; // [esp+18h] [ebp-28h]
  int k; // [esp+1Ch] [ebp-24h]
  int v13; // [esp+20h] [ebp-20h]
  void *lpBuffer; // [esp+24h] [ebp-1Ch]
  unsigned int v15; // [esp+28h] [ebp-18h]
  char *v16; // [esp+2Ch] [ebp-14h]
  unsigned int size; // [esp+30h] [ebp-10h]
  int v18; // [esp+34h] [ebp-Ch]
  unsigned int v19; // [esp+38h] [ebp-8h]
  unsigned int nNumberOfBytesToWrite; // [esp+3Ch] [ebp-4h]

  v8 = pbData;
  s = pszName;
  for ( i = strchr(pszName, ':'); ; i = strchr(v16 + 1, ':') )
  {
    v16 = i;
    if ( !i )
      break;
    s = v16 + 1;
  }
  for ( j = strchr(s, '\\'); ; j = strchr(v16 + 1, '\\') )
  {
    v16 = j;
    if ( !j )
      break;
    s = v16 + 1;
  }
  v18 = encrypt_hash(s, 3);
  v19 = (unsigned int)(dwLen + 4095) >> 12;
  nNumberOfBytesToWrite = 4 * v19 + 4;
  size = nNumberOfBytesToWrite + dwLen;
  pBlk->offset = mpqapi_find_free_block(nNumberOfBytesToWrite + dwLen, &pBlk->sizealloc);
  pBlk->sizefile = dwLen;
  pBlk->flags = 0x80010100;
  if ( SetFilePointer(hFile, pBlk->offset, 0, 0) == -1 )
    return 0;
  v13 = 0;
  v15 = 0;
  lpBuffer = 0;
  while ( dwLen )
  {
    for ( k = 0; k < 4096; ++k )
      mpq_buf[k] -= 86;
    v7 = dwLen;
    if ( (unsigned int)dwLen >= 0x1000 )
      v7 = 4096;
    NumberOfBytesWritten = v7;
    memcpy(mpq_buf, v8, v7);
    v8 += NumberOfBytesWritten;
    NumberOfBytesWritten = encrypt_compress(mpq_buf, NumberOfBytesWritten);
    if ( !v13 )
    {
      nNumberOfBytesToWrite = 4 * v19 + 4;
      lpBuffer = DiabloAllocPtr(nNumberOfBytesToWrite, 627, "mpqapi.cpp");
      memset(lpBuffer, 0, nNumberOfBytesToWrite);
      if ( !WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite, &nNumberOfBytesToWrite, 0) )
        goto LABEL_37;
      v15 += nNumberOfBytesToWrite;
    }
    assert(lpBuffer, "mpqapi.cpp", 635);
    *((_DWORD *)lpBuffer + v13) = v15;
    encrypt_encrypt_block(mpq_buf, NumberOfBytesWritten & 0xFFFFFFFC, v18 + v13);
    if ( !WriteFile(hFile, mpq_buf, NumberOfBytesWritten, (LPDWORD)&NumberOfBytesWritten, 0) )
      goto LABEL_37;
    ++v13;
    if ( (unsigned int)dwLen <= 0x1000 )
      dwLen = 0;
    else
      dwLen -= 4096;
    v15 += NumberOfBytesWritten;
  }
  assert(lpBuffer, "mpqapi.cpp", 653);
  *((_DWORD *)lpBuffer + v13) = v15;
  encrypt_encrypt_block(lpBuffer, nNumberOfBytesToWrite, v18 - 1);
  if ( SetFilePointer(hFile, -v15, 0, 1u) == -1
    || !WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite, &nNumberOfBytesToWrite, 0)
    || SetFilePointer(hFile, v15 - nNumberOfBytesToWrite, 0, 1u) == -1 )
  {
LABEL_37:
    if ( lpBuffer )
      mem_free_dbg(lpBuffer, 679, "mpqapi.cpp");
    return 0;
  }
  mem_free_dbg(lpBuffer, 662, "mpqapi.cpp");
  lpBuffer = 0;
  assert(pBlk->sizealloc >= v15, "mpqapi.cpp", 666);
  if ( pBlk->sizealloc > v15 )
  {
    block_size = pBlk->sizealloc - v15;
    if ( block_size >= 0x400 )
    {
      pBlk->sizealloc = v15;
      mpqapi_alloc_block(v15 + pBlk->offset, block_size);
    }
  }
  return 1;
}

//----- (0042044D) --------------------------------------------------------
int __fastcall mpqapi_find_free_block(int size, int *block_size)
{
  signed int v2; // ST20_4
  int v4; // ST28_4
  signed int v5; // [esp+18h] [ebp-Ch]
  int v6; // [esp+1Ch] [ebp-8h]
  _BLOCKENTRY *v7; // [esp+20h] [ebp-4h]

  v7 = sgpBlockTbl;
  v5 = 2048;
  while ( 1 )
  {
    v2 = v5--;
    if ( !v2 )
    {
      *block_size = size;
      v4 = lDistanceToMove;
      lDistanceToMove += size;
      return v4;
    }
    if ( v7->offset && !v7->flags && !v7->sizefile && v7->sizealloc >= (unsigned int)size )
      break;
    ++v7;
  }
  v6 = v7->offset;
  *block_size = size;
  v7->offset += size;
  v7->sizealloc -= size;
  if ( !v7->sizealloc )
    memset(v7, 0, 0x10u);
  return v6;
}

//----- (00420545) --------------------------------------------------------
signed int empty_fn_2()
{
  return 1;
}

//----- (00420560) --------------------------------------------------------
void empty_fn_4()
{
  ;
}

