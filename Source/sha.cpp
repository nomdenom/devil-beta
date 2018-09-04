//----- (004846A0) --------------------------------------------------------
void __cdecl SHA1Clear()
{
  memset(sgSHA1, 0, 0x114u);
}

//----- (004846C4) --------------------------------------------------------
void __fastcall SHA1Result(int n, char *Message_Digest)
{
  char *v2; // [esp+14h] [ebp-8h]
  signed int v3; // [esp+18h] [ebp-4h]

  if ( Message_Digest )
  {
    v2 = Message_Digest;
    v3 = 0;
    while ( v3 < 5 )
    {
      *(_DWORD *)v2 = sgSHA1[n].state[v3++];
      v2 += 4;
    }
  }
}

//----- (00484729) --------------------------------------------------------
void __fastcall SHA1Calculate(int n, const char *data, char *Message_Digest)
{
  SHA1Input(&sgSHA1[n], data, 64);
  if ( Message_Digest )
    SHA1Result(n, Message_Digest);
}

//----- (00484777) --------------------------------------------------------
void __fastcall SHA1Input(SHA1Context *context, const char *message_array, int len)
{
  const char *v3; // [esp+Ch] [ebp-8h]

  v3 = message_array;
  if ( context->count[0] + 8 * len < context->count[0] )
    ++context->count[1];
  context->count[0] += 8 * len;
  context->count[1] += len >> 29;
  while ( len >= 64 )
  {
    memcpy(context->buffer, v3, 0x40u);
    SHA1ProcessMessageBlock(context);
    v3 += 64;
    len -= 64;
  }
}

//----- (004847FC) --------------------------------------------------------
void __fastcall SHA1ProcessMessageBlock(SHA1Context *context)
{
  int v1[2]; // [esp+0h] [ebp-198h]
  int v2[6]; // [esp+8h] [ebp-190h]
  int v3[5]; // [esp+20h] [ebp-178h]
  int v4; // [esp+34h] [ebp-164h]
  int temp; // [esp+3Ch] [ebp-15Ch]
  int W[80]; // [esp+40h] [ebp-158h]
  int i; // [esp+180h] [ebp-18h]
  int E; // [esp+184h] [ebp-14h]
  int D; // [esp+188h] [ebp-10h]
  int C; // [esp+18Ch] [ebp-Ch]
  int B; // [esp+190h] [ebp-8h]
  int A; // [esp+194h] [ebp-4h]

  for ( i = 0; i < 16; ++i )
    W[i] = *(_DWORD *)&context->buffer[4 * i];
  for ( i = 16; i < 80; ++i )
    W[i] = v1[i] ^ v3[i] ^ v2[i] ^ *(&v4 + i);
  A = context->state[0];
  B = context->state[1];
  C = context->state[2];
  D = context->state[3];
  E = context->state[4];
  for ( i = 0; i < 20; ++i )
  {
    temp = E + W[i] + ((A >> 27) | 32 * A) + (B & C | D & ~B) + 1518500249;
    E = D;
    D = C;
    C = (B >> 2) | (B << 30);
    B = A;
    A = temp;
  }
  for ( i = 20; i < 40; ++i )
  {
    temp = E + W[i] + (B ^ C ^ D) + ((A >> 27) | 32 * A) + 1859775393;
    E = D;
    D = C;
    C = (B >> 2) | (B << 30);
    B = A;
    A = temp;
  }
  for ( i = 40; i < 60; ++i )
  {
    temp = E + W[i] + ((A >> 27) | 32 * A) + (C & D | B & C | B & D) - 1894007588;
    E = D;
    D = C;
    C = (B >> 2) | (B << 30);
    B = A;
    A = temp;
  }
  for ( i = 60; i < 80; ++i )
  {
    temp = E + W[i] + (B ^ C ^ D) + ((A >> 27) | 32 * A) - 899497514;
    E = D;
    D = C;
    C = (B >> 2) | (B << 30);
    B = A;
    A = temp;
  }
  context->state[0] += A;
  context->state[1] += B;
  context->state[2] += C;
  context->state[3] += D;
  context->state[4] += E;
  for ( i = 0; i < 80; ++i )
    W[i] = 0;
}

//----- (00484B5E) --------------------------------------------------------
void __fastcall j_SHA1Reset(int n)
{
  SHA1Reset(&sgSHA1[n]);
}

//----- (00484B8D) --------------------------------------------------------
void __fastcall SHA1Reset(SHA1Context *ctx)
{
  ctx->state[0] = 1732584193;
  ctx->state[1] = -271733879;
  ctx->state[2] = -1732584194;
  ctx->state[3] = 271733878;
  ctx->state[4] = -1009589776;
  ctx->count[0] = 0;
  ctx->count[1] = 0;
}

