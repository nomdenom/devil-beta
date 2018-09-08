#include "all.h"

//----- (00413020) --------------------------------------------------------
int __fastcall FindPath(int pnum, int sx, int sy, int dx, int dy, char *path)
{
  PATHNODE *v7; // ST1C_4
  PATHNODE *v10; // [esp+14h] [ebp-10h]
  signed int v11; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  PATHNODE *a2; // [esp+20h] [ebp-4h]

  gdwCurNodes = 0;
  path_2_nodes = path_new_step();
  pnode_ptr = path_new_step();
  gdwCurPathStep = 0;
  v7 = path_new_step();
  v7->g = 0;
  v7->h = path_get_h_cost(sx, sy, dx, dy);
  v7->f = v7->h + v7->g;
  v7->x = sx;
  v7->y = sy;
  path_2_nodes->NextNode = v7;
  while ( 1 )
  {
    a2 = GetNextPath();
    if ( !a2 )
      return 0;
    if ( a2->x == dx && a2->y == dy )
      break;
    if ( !path_get_path(pnum, a2, dx, dy) )
      return 0;
  }
  v10 = a2;
  v11 = 0;
  while ( v10->Parent && v11 < 25 )
  {
    pnode_vals[v11++] = path_directions[3 * (v10->y - v10->Parent->y) + 3 - v10->Parent->x + 1 + v10->x];
    v10 = v10->Parent;
  }
  if ( v11 == 25 )
    return 0;
  for ( i = 0; i < v11; ++i )
    path[i] = pnode_vals[v11 - i - 1];
  return i;
}

//----- (004131D4) --------------------------------------------------------
int __fastcall path_get_h_cost(int sx, int sy, int dx, int dy)
{
  int v5; // eax
  int v6; // eax
  int v8; // [esp+14h] [ebp-10h]
  int v9; // [esp+18h] [ebp-Ch]
  int v10; // [esp+20h] [ebp-4h]

  v9 = abs(sx - dx);
  v5 = abs(sy - dy);
  v8 = v5;
  if ( v5 >= v9 )
    v5 = v9;
  v10 = v5;
  v6 = v8;
  if ( v8 <= v9 )
    v6 = v9;
  return 2 * (v10 + v6);
}

//----- (00413241) --------------------------------------------------------
signed int __fastcall path_check_equal(PATHNODE *pPath, int dx, int dy)
{
  signed int result; // eax

  if ( pPath->x != dx && pPath->y != dy )
    result = 3;
  else
    result = 2;
  return result;
}

//----- (0041328E) --------------------------------------------------------
PATHNODE *__cdecl GetNextPath()
{
  PATHNODE *v1; // ST0C_4

  if ( !path_2_nodes->NextNode )
    return 0;
  v1 = path_2_nodes->NextNode;
  path_2_nodes->NextNode = v1->NextNode;
  v1->NextNode = pnode_ptr->NextNode;
  pnode_ptr->NextNode = v1;
  return v1;
}

//----- (004132EE) --------------------------------------------------------
BOOL __fastcall path_solid_pieces(PATHNODE *pPath, int dx, int dy)
{
  BOOL v4; // [esp+18h] [ebp-4h]

  v4 = 1;
  switch ( path_directions[3 * (dy - pPath->y) + 3 - pPath->x + 1 + dx] )
  {
    case 5:
      v4 = !nSolidTable[dPiece[dx][dy + 1]] && !nSolidTable[dPiece[dx + 1][dy]];
      break;
    case 6:
      v4 = !nSolidTable[dPiece[dx][dy + 1]] && !nSolidTable[dPiece[dx - 1][dy]];
      break;
    case 7:
      v4 = !nSolidTable[dPiece[dx][dy - 1]] && !nSolidTable[dPiece[dx - 1][dy]];
      break;
    case 8:
      v4 = !nSolidTable[dPiece[dx + 1][dy]] && !nSolidTable[dPiece[dx][dy - 1]];
      break;
    default:
      return v4;
  }
  return v4;
}

//----- (00413502) --------------------------------------------------------
signed int __fastcall path_get_path(int pnum, PATHNODE *pPath, int x, int y)
{
  signed int j; // [esp+14h] [ebp-14h]
  BOOL v8; // [esp+18h] [ebp-10h]
  int py; // [esp+1Ch] [ebp-Ch]
  signed int i; // [esp+20h] [ebp-8h]
  int px; // [esp+24h] [ebp-4h]

  for ( i = -1; i <= 1; ++i )
  {
    for ( j = -1; j <= 1; ++j )
    {
      if ( i || j )
      {
        if ( (px = i + pPath->x, py = j + pPath->y, (v8 = PosOkPlayer(pnum, i + pPath->x, py)) != 0)
          && path_solid_pieces(pPath, px, py)
          || !v8 && px == x && py == y )
        {
          if ( !path_parent_path(pPath, px, py, x, y) )
            return 0;
        }
      }
    }
  }
  return 1;
}

//----- (00413605) --------------------------------------------------------
signed int __fastcall path_parent_path(PATHNODE *pPath, int dx, int dy, int sx, int sy)
{
  PATHNODE *pPatha; // [esp+10h] [ebp-14h]
  PATHNODE *v8; // [esp+14h] [ebp-10h]
  PATHNODE *v9; // [esp+14h] [ebp-10h]
  int v10; // [esp+18h] [ebp-Ch]
  signed int i; // [esp+1Ch] [ebp-8h]
  signed int j; // [esp+1Ch] [ebp-8h]
  signed int k; // [esp+1Ch] [ebp-8h]
  PATHNODE *v14; // [esp+20h] [ebp-4h]

  pPatha = pPath;
  v10 = pPath->g + path_check_equal(pPath, dx, dy);
  v8 = path_get_node1(dx, dy);
  if ( v8 )
  {
    for ( i = 0; i < 8 && pPatha->Child[i]; ++i )
      ;
    pPatha->Child[i] = v8;
    if ( v8->g > v10 )
    {
      if ( path_solid_pieces(pPatha, dx, dy) )
      {
        v8->Parent = pPatha;
        v8->g = v10;
        v8->f = v10 + v8->h;
      }
    }
  }
  else
  {
    v9 = path_get_node2(dx, dy);
    if ( v9 )
    {
      for ( j = 0; j < 8 && pPatha->Child[j]; ++j )
        ;
      pPatha->Child[j] = v9;
      if ( v9->g > v10 && path_solid_pieces(pPatha, dx, dy) )
      {
        v9->Parent = pPatha;
        v9->g = v10;
        v9->f = v10 + v9->h;
        path_set_coords(v9);
      }
    }
    else
    {
      v14 = path_new_step();
      if ( !v14 )
        return 0;
      v14->Parent = pPatha;
      v14->g = v10;
      v14->h = path_get_h_cost(dx, dy, sx, sy);
      v14->f = v10 + v14->h;
      v14->x = dx;
      v14->y = dy;
      path_next_node(v14);
      for ( k = 0; k < 8 && pPatha->Child[k]; ++k )
        ;
      pPatha->Child[k] = v14;
    }
  }
  return 1;
}

//----- (0041384E) --------------------------------------------------------
PATHNODE *__fastcall path_get_node1(int dx, int dy)
{
  PATHNODE *i; // [esp+14h] [ebp-4h]

  for ( i = path_2_nodes->NextNode; i; i = i->NextNode )
  {
    if ( i->x == dx && i->y == dy )
      return i;
  }
  return 0;
}

//----- (004138B7) --------------------------------------------------------
PATHNODE *__fastcall path_get_node2(int dx, int dy)
{
  PATHNODE *i; // [esp+14h] [ebp-4h]

  for ( i = pnode_ptr->NextNode; i; i = i->NextNode )
  {
    if ( i->x == dx && i->y == dy )
      return i;
  }
  return 0;
}

//----- (00413920) --------------------------------------------------------
void __fastcall path_next_node(PATHNODE *pPath)
{
  PATHNODE *i; // [esp+10h] [ebp-Ch]
  PATHNODE *v2; // [esp+14h] [ebp-8h]

  if ( path_2_nodes->NextNode )
  {
    v2 = path_2_nodes;
    for ( i = path_2_nodes->NextNode; i && i->f < pPath->f; i = i->NextNode )
      v2 = i;
    pPath->NextNode = i;
    v2->NextNode = pPath;
  }
  else
  {
    path_2_nodes->NextNode = pPath;
  }
}

//----- (004139B1) --------------------------------------------------------
void __fastcall path_set_coords(PATHNODE *pPath)
{
  PATHNODE *pPatha; // [esp+10h] [ebp-Ch]
  signed int i; // [esp+14h] [ebp-8h]
  PATHNODE *v3; // [esp+18h] [ebp-4h]

  path_push_active_step(pPath);
  while ( gdwCurPathStep )
  {
    pPatha = path_pop_active_step();
    for ( i = 0; i < 8; ++i )
    {
      v3 = pPatha->Child[i];
      if ( !v3 )
        break;
      if ( pPatha->g + path_check_equal(pPatha, v3->x, v3->y) < v3->g )
      {
        if ( path_solid_pieces(pPatha, v3->x, v3->y) )
        {
          v3->Parent = pPatha;
          v3->g = pPatha->g + path_check_equal(pPatha, v3->x, v3->y);
          v3->f = v3->h + v3->g;
          path_push_active_step(v3);
        }
      }
    }
  }
}

//----- (00413AB7) --------------------------------------------------------
void __fastcall path_push_active_step(PATHNODE *pPath)
{
  pnode_tblptr[gdwCurPathStep++] = pPath;
}

//----- (00413AE3) --------------------------------------------------------
PATHNODE *__cdecl path_pop_active_step()
{
  return pnode_tblptr[--gdwCurPathStep];
}

//----- (00413B05) --------------------------------------------------------
PATHNODE *__cdecl path_new_step()
{
  PATHNODE *v1; // ST18_4

  if ( gdwCurNodes == 300 )
    return 0;
  v1 = &path_nodes[gdwCurNodes++];
  memset(v1, 0, 0x34u);
  return v1;
}

