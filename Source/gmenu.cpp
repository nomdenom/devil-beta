#include "all.h"

//----- (00479D70) --------------------------------------------------------
void __cdecl gmenu_draw_pause()
{
  if ( currlevel )
    RedBack();
  if ( !gmenu_642C20_start )
  {
    light_table_index = 0;
    gmenu_print_text(316, 336, "Pause");
  }
}

//----- (00479DBF) --------------------------------------------------------
void __fastcall gmenu_print_text(int x, int y, char *pszStr)
{
  char v5; // [esp+14h] [ebp-4h]

  assert(pszStr, "gmenu.cpp", 90);
  while ( *pszStr )
  {
    v5 = lfontframe[*pszStr++];
    if ( v5 )
      CelDecodeLightOnly(x, y, BigTGold_cel, v5, 46);
    x += lfontkern[v5] + 2;
  }
}

//----- (00479E52) --------------------------------------------------------
void __cdecl FreeGMenu()
{
  mem_free_dbg(sgpLogo, 113, "gmenu.cpp");
  sgpLogo = 0;
  mem_free_dbg(BigTGold_cel, 115, "gmenu.cpp");
  BigTGold_cel = 0;
  mem_free_dbg(PentSpin_cel, 117, "gmenu.cpp");
  PentSpin_cel = 0;
  mem_free_dbg(option_cel, 119, "gmenu.cpp");
  option_cel = 0;
  mem_free_dbg(optbar_cel, 121, "gmenu.cpp");
  optbar_cel = 0;
}

//----- (00479EFD) --------------------------------------------------------
void __cdecl gmenu_init_menu()
{
  gmenu_byte_642C1C = 1;
  gmenu_642C20_start = 0;
  sgpCurrItem = 0;
  gmenu_642C2C = 0;
  gmenu_642C08 = 0;
  assert(!sgpLogo, "gmenu.cpp", 135);
  sgpLogo = LoadFileInMem("Data\\Diabsmal.CEL", 0, 136, "gmenu.cpp");
  BigTGold_cel = LoadFileInMem("Data\\BigTGold.CEL", 0, 137, "gmenu.cpp");
  PentSpin_cel = LoadFileInMem("Data\\PentSpin.CEL", 0, 138, "gmenu.cpp");
  option_cel = LoadFileInMem("Data\\option.CEL", 0, 139, "gmenu.cpp");
  optbar_cel = LoadFileInMem("Data\\optbar.CEL", 0, 140, "gmenu.cpp");
}

//----- (00479FE1) --------------------------------------------------------
BOOL __cdecl gmenu_exception()
{
  return gmenu_642C20_start != 0;
}

//----- (0047A00A) --------------------------------------------------------
void __fastcall gmenu_call_proc(TMenuItem *a1)
{
  TMenuItem *i; // [esp+10h] [ebp-4h]

  gmenu_642C20_start = a1;
  gmenu_642C08 = 0;
  gmenu_642C2C = 0;
  if ( a1 )
  {
    for ( i = gmenu_642C20_start; i->fnMenu; ++i )
      ++gmenu_642C2C;
  }
  sgpCurrItem = &gmenu_642C20_start[gmenu_642C2C - 1];
  gmenu_up_down(1);
}

//----- (0047A092) --------------------------------------------------------
void __fastcall gmenu_up_down(int a1)
{
  int v1; // ST10_4
  int v2; // [esp+14h] [ebp-4h]

  if ( sgpCurrItem )
  {
    gmenu_642C08 = 0;
    v2 = gmenu_642C2C;
    while ( 1 )
    {
      v1 = v2--;
      if ( !v1 )
        break;
      if ( a1 )
      {
        ++sgpCurrItem;
        if ( !sgpCurrItem->fnMenu )
          sgpCurrItem = gmenu_642C20_start;
      }
      else
      {
        if ( gmenu_642C20_start == sgpCurrItem )
          sgpCurrItem = &gmenu_642C20_start[gmenu_642C2C];
        --sgpCurrItem;
      }
      if ( (sgpCurrItem->dwFlags & 0x80000000) != 0 )
      {
        if ( v2 )
          PlaySFX(41);
        return;
      }
    }
  }
}

//----- (0047A166) --------------------------------------------------------
void __cdecl gmenu_draw()
{
  TMenuItem *a1; // [esp+Ch] [ebp-Ch]
  DWORD v1; // [esp+10h] [ebp-8h]
  signed int a2; // [esp+14h] [ebp-4h]

  if ( gmenu_642C20_start )
  {
    CelDecodeOnly(236, 262, sgpLogo, 1, 296);
    a2 = 320;
    for ( a1 = gmenu_642C20_start; a1->fnMenu; ++a1 )
    {
      gmenu_draw_menu_item(a1, a2);
      a2 += 45;
    }
    v1 = GetTickCount();
    if ( (signed int)(v1 - gmenu_642C18) > 25 )
    {
      if ( ++gmenu_byte_642C1C == 9 )
        gmenu_byte_642C1C = 1;
      gmenu_642C18 = v1;
    }
  }
}

//----- (0047A220) --------------------------------------------------------
void __fastcall gmenu_draw_menu_item(TMenuItem *a1, int y)
{
  unsigned int v2; // ST28_4
  int ya; // [esp+Ch] [ebp-1Ch]
  TMenuItem *v4; // [esp+10h] [ebp-18h]
  unsigned int v5; // [esp+18h] [ebp-10h]
  unsigned int v6; // [esp+20h] [ebp-8h]
  int x; // [esp+24h] [ebp-4h]

  ya = y;
  v4 = a1;
  v6 = gmenu_get_lfont(a1);
  if ( v4->dwFlags & 0x40000000 )
  {
    CelDecodeOnly((v6 >> 1) + 80, ya - 10, optbar_cel, 1, 287);
    v5 = (v4->dwFlags & 0xFFF000) >> 12;
    if ( v5 < 2 )
      v5 = 2;
    v2 = ((v4->dwFlags & 0xFFF) << 8) / v5;
    gmenu_clear_buffer((v6 >> 1) + 82, ya - 12, v2 + 13, 28);
    CelDecodeOnly((v6 >> 1) + 80 + v2 + 2, ya - 12, option_cel, 1, 27);
  }
  x = 320 - (v6 >> 1) + 64;
  if ( (v4->dwFlags & 0x80000000) == 0 )
    light_table_index = 15;
  else
    light_table_index = 0;
  gmenu_print_text(x, ya, v4->pszStr);
  if ( v4 == sgpCurrItem )
  {
    CelDecodeOnly(320 - (v6 >> 1) + 10, ya + 1, PentSpin_cel, (unsigned __int8)gmenu_byte_642C1C, 48);
    CelDecodeOnly(x + v6 + 4, ya + 1, PentSpin_cel, (unsigned __int8)gmenu_byte_642C1C, 48);
  }
}

//----- (0047A38D) --------------------------------------------------------
void __fastcall gmenu_clear_buffer(int x, int y, int width, int height)
{
  int v4; // ST20_4
  BYTE *i; // [esp+18h] [ebp-4h]

  assert(gpBuffer, "gmenu.cpp", 204);
  for ( i = &gpBuffer[x + screen_y_times_768[y]]; ; i -= 768 )
  {
    v4 = height--;
    if ( !v4 )
      break;
    memset(i, 205, width);
  }
}

//----- (0047A413) --------------------------------------------------------
int __fastcall gmenu_get_lfont(TMenuItem *a1)
{
  char *i; // [esp+10h] [ebp-8h]
  int v3; // [esp+14h] [ebp-4h]

  if ( a1->dwFlags & 0x40000000 )
    return 490;
  v3 = 0;
  for ( i = a1->pszStr; *i; ++i )
    v3 += lfontkern[lfontframe[*i]] + 2;
  return v3 - 2;
}

//----- (0047A487) --------------------------------------------------------
int __fastcall gmenu_presskeys(int a1)
{
  if ( !gmenu_642C20_start )
    return 0;
  assert(sgpCurrItem, "gmenu.cpp", 317);
  switch ( a1 )
  {
    case 13:
      PlaySFX(41);
      assert(sgpCurrItem, "gmenu.cpp", 342);
      ((void (__thiscall *)(signed int))sgpCurrItem->fnMenu)(1);
      return 1;
    case 27:
      PlaySFX(41);
      gmenu_call_proc(0);
      return 1;
    case 32:
      return 0;
    case 37:
      gmenu_left_right(0);
      break;
    case 38:
      gmenu_up_down(0);
      break;
    case 39:
      gmenu_left_right(1);
      break;
    case 40:
      gmenu_up_down(1);
      break;
    default:
      return 1;
  }
  return 1;
}

//----- (0047A5D3) --------------------------------------------------------
void __fastcall gmenu_left_right(int a1)
{
  unsigned int v1; // [esp+10h] [ebp-8h]
  int v2; // [esp+10h] [ebp-8h]

  if ( sgpCurrItem->dwFlags & 0x40000000 )
  {
    v1 = sgpCurrItem->dwFlags & 0xFFF;
    if ( a1 )
    {
      if ( (signed int)(sgpCurrItem->dwFlags & 0xFFF000) >> 12 == v1 )
        return;
      v2 = v1 + 1;
    }
    else
    {
      if ( !v1 )
        return;
      v2 = v1 - 1;
    }
    sgpCurrItem->dwFlags &= 0xFFFFF000;
    sgpCurrItem->dwFlags |= v2;
    ((void (__thiscall *)(_DWORD))sgpCurrItem->fnMenu)(0);
  }
}

//----- (0047A674) --------------------------------------------------------
int __fastcall gmenu_on_mouse_move()
{
  int plOffset; // [esp+Ch] [ebp-8h]
  int v2; // [esp+10h] [ebp-4h]

  if ( !gmenu_642C08 )
    return 0;
  assert(sgpCurrItem, "gmenu.cpp", 379);
  gmenu_valid_mouse_pos(&plOffset);
  v2 = sgpCurrItem->dwFlags & 0xFFF000;
  v2 >>= 12;
  plOffset *= v2;
  plOffset /= 256;
  sgpCurrItem->dwFlags &= 0xFFFFF000;
  sgpCurrItem->dwFlags |= plOffset;
  ((void (__thiscall *)(_DWORD))sgpCurrItem->fnMenu)(0);
  return 1;
}

//----- (0047A71A) --------------------------------------------------------
bool __fastcall gmenu_valid_mouse_pos(int *plOffset)
{
  bool result; // al

  assert(plOffset, "gmenu.cpp", 359);
  *plOffset = 282;
  if ( *plOffset <= MouseX )
  {
    if ( *plOffset + 256 >= MouseX )
    {
      *plOffset = MouseX - *plOffset;
      result = 1;
    }
    else
    {
      *plOffset = 256;
      result = 0;
    }
  }
  else
  {
    *plOffset = 0;
    result = 0;
  }
  return result;
}

//----- (0047A7B4) --------------------------------------------------------
int __fastcall gmenu_left_mouse(int a1)
{
  int result; // eax
  char plOffset; // [esp+10h] [ebp-10h]
  TMenuItem *v3; // [esp+14h] [ebp-Ch]
  int v4; // [esp+18h] [ebp-8h]
  unsigned int v5; // [esp+1Ch] [ebp-4h]

  if ( a1 )
  {
    if ( gmenu_642C20_start )
    {
      if ( MouseY < 352 )
      {
        v4 = MouseY - 117;
        if ( MouseY - 117 >= 0 )
        {
          v4 /= 45;
          if ( gmenu_642C2C > (unsigned int)v4 )
          {
            v3 = &gmenu_642C20_start[v4];
            if ( (gmenu_642C20_start[v4].dwFlags & 0x80000000) != 0 )
            {
              v5 = gmenu_get_lfont(v3);
              if ( 320 - (v5 >> 1) <= MouseX )
              {
                if ( (v5 >> 1) + 320 >= MouseX )
                {
                  sgpCurrItem = v3;
                  PlaySFX(41);
                  if ( v3->dwFlags & 0x40000000 )
                  {
                    gmenu_642C08 = gmenu_valid_mouse_pos((int *)&plOffset);
                    gmenu_on_mouse_move();
                  }
                  else
                  {
                    ((void (__thiscall *)(signed int))sgpCurrItem->fnMenu)(1);
                  }
                  result = 1;
                }
                else
                {
                  result = 1;
                }
              }
              else
              {
                result = 1;
              }
            }
            else
            {
              result = 1;
            }
          }
          else
          {
            result = 1;
          }
        }
        else
        {
          result = 1;
        }
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      result = 0;
    }
  }
  else if ( gmenu_642C08 )
  {
    gmenu_642C08 = 0;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0047A92A) --------------------------------------------------------
void __fastcall gmenu_slider_1(TMenuItem *pItem, int min, int max, int gamma)
{
  signed int v4; // [esp+14h] [ebp-4h]

  assert(pItem, "gmenu.cpp", 445);
  v4 = (signed int)(pItem->dwFlags & 0xFFF000) >> 12;
  if ( v4 < 2 )
    v4 = 2;
  pItem->dwFlags &= 0xFFFFF000;
  pItem->dwFlags |= ((max - min - 1) / 2 + (gamma - min) * v4) / (max - min);
}

//----- (0047A9C8) --------------------------------------------------------
int __fastcall gmenu_slider_get(TMenuItem *pItem, int min, int max)
{
  signed int v4; // [esp+18h] [ebp-4h]

  assert(pItem, "gmenu.cpp", 468);
  v4 = (signed int)(pItem->dwFlags & 0xFFF000) >> 12;
  if ( v4 < 2 )
    v4 = 2;
  return min + (signed int)((v4 - 1) / 2 + (pItem->dwFlags & 0xFFF) * (max - min)) / v4;
}

//----- (0047AA5C) --------------------------------------------------------
void __fastcall gmenu_slider_3(TMenuItem *pItem, int dwTicks)
{
  assert(pItem, "gmenu.cpp", 492);
  assert(!((unsigned int)dwTicks < 2 || (unsigned int)dwTicks > 0xFFF), "gmenu.cpp", 493);
  pItem->dwFlags &= 0xFF000FFF;
  pItem->dwFlags |= (dwTicks << 12) & 0xFFF000;
}

