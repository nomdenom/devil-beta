#include "all.h"

//----- (004A048C) --------------------------------------------------------
void __fastcall drawTopArchesUpperScreen(unsigned __int8 *pbDst)
{
  int v1; // edx
  unsigned __int8 *tmp_pbDst; // edi
  _BYTE *pdung_cels2; // esi
  BYTE *l_tbl; // ebx
  __int16 cel_type_16; // ax
  unsigned __int8 *pdung_cels; // esi
  __int16 v7; // ax
  unsigned int v8; // eax
  unsigned __int8 *v9; // esi
  unsigned int v10; // eax
  int v11; // eax
  signed int v12; // ebp
  signed int v13; // ecx
  unsigned int v14; // eax
  unsigned __int8 *v15; // edi
  signed int v16; // ecx
  int v17; // eax
  signed int v18; // ebp
  signed int v19; // edx
  unsigned int v20; // eax
  int v21; // edx
  unsigned int v22; // ecx
  unsigned __int8 v23; // cf
  unsigned int v24; // ecx
  unsigned int v25; // eax
  unsigned int v26; // ecx
  int v27; // eax
  unsigned int v28; // ecx
  unsigned int v29; // ecx
  int v30; // eax
  unsigned int v31; // ecx
  unsigned int v32; // eax
  signed int v33; // ebp
  unsigned __int8 *v34; // edi
  unsigned int v35; // ecx
  int v36; // edx
  unsigned int v37; // ecx
  unsigned int v38; // ecx
  unsigned int v39; // eax
  unsigned int v40; // ecx
  int v41; // eax
  int v42; // edx
  unsigned int v43; // ecx
  unsigned int v44; // ecx
  int v45; // eax
  unsigned int v46; // ecx
  unsigned int v47; // eax
  unsigned __int8 v48; // of
  signed int v49; // ebp
  unsigned __int8 *v50; // edi
  unsigned int v51; // ecx
  int v52; // edx
  unsigned int v53; // ecx
  unsigned int v54; // ecx
  unsigned int v55; // eax
  unsigned int v56; // ecx
  int v57; // eax
  int v58; // edx
  unsigned int v59; // ecx
  unsigned int v60; // ecx
  int v61; // eax
  unsigned int v62; // ecx
  unsigned int v63; // eax
  signed int v64; // ebp
  unsigned int v65; // ecx
  unsigned int v66; // ecx
  unsigned int v67; // ecx
  unsigned int v68; // eax
  unsigned int v69; // ecx
  int v70; // eax
  unsigned int v71; // ecx
  unsigned int v72; // ecx
  int v73; // eax
  unsigned int v74; // ecx
  unsigned int v75; // eax
  signed int v76; // ebp
  unsigned int v77; // ecx
  unsigned int v78; // ecx
  unsigned int v79; // ecx
  unsigned int v80; // eax
  unsigned int v81; // ecx
  int v82; // eax
  unsigned int v83; // ecx
  unsigned int v84; // ecx
  int v85; // eax
  unsigned int v86; // ecx
  unsigned int v87; // eax
  signed int v88; // ebp
  unsigned __int8 *v89; // edi
  unsigned int v90; // ecx
  int v91; // edx
  unsigned int v92; // ecx
  unsigned int v93; // ecx
  unsigned int v94; // eax
  unsigned int v95; // ecx
  int v96; // eax
  unsigned int v97; // ecx
  unsigned int v98; // ecx
  int v99; // eax
  unsigned int v100; // ecx
  unsigned int v101; // eax
  signed int v102; // ebp
  signed int v103; // ecx
  unsigned int v104; // eax
  unsigned __int8 *v105; // edi
  signed int v106; // ecx
  int v107; // eax
  signed int v108; // ebp
  unsigned int v109; // ecx
  unsigned int v110; // ecx
  unsigned int v111; // ecx
  unsigned int v112; // eax
  unsigned int v113; // ecx
  int v114; // eax
  unsigned int v115; // ecx
  unsigned int v116; // ecx
  int v117; // eax
  unsigned int v118; // ecx
  unsigned int v119; // eax
  signed int v120; // ebp
  signed int v121; // ecx
  unsigned int v122; // eax
  unsigned __int8 *v123; // edi
  signed int v124; // ecx
  int v125; // eax
  signed int v126; // edx
  signed int v127; // ecx
  int v128; // eax
  unsigned __int8 *v129; // edi
  unsigned __int8 *v130; // edi
  signed int v131; // ecx
  int v132; // eax
  _BYTE *v133; // edi
  signed int v134; // ebp
  signed int v135; // edx
  unsigned int v136; // eax
  unsigned int v137; // ecx
  unsigned int v138; // ecx
  unsigned __int8 *v139; // esi
  unsigned __int8 *v140; // edi
  unsigned __int8 v141; // al
  int v142; // eax
  unsigned __int8 *v143; // edi
  unsigned __int8 v144; // al
  unsigned int v145; // ecx
  unsigned __int8 v146; // al
  int v147; // eax
  unsigned __int8 *v148; // edi
  signed int v149; // edx
  unsigned __int8 *v150; // edi
  unsigned int v151; // ecx
  int v152; // eax
  unsigned int v153; // ecx
  _BYTE *v154; // edi
  int v155; // eax
  _BYTE *v156; // edi
  unsigned int v157; // ecx
  __int16 v158; // ax
  int v159; // eax
  _BYTE *v160; // edi
  signed int v161; // edx
  unsigned __int8 *v162; // edi
  unsigned int v163; // ecx
  int v164; // eax
  unsigned int v165; // ecx
  _BYTE *v166; // edi
  int v167; // eax
  _BYTE *v168; // edi
  unsigned int v169; // ecx
  __int16 v170; // ax
  int v171; // eax
  _BYTE *v172; // edi
  signed int v173; // edx
  unsigned int v174; // ecx
  int v175; // eax
  char v176; // bp
  unsigned int i; // ecx
  int v178; // eax
  unsigned __int8 *v179; // edi
  int v180; // ebp
  unsigned __int8 *v181; // edi
  unsigned int j; // ecx
  int v183; // eax
  unsigned __int8 *v184; // edi
  __int16 v185; // ax
  signed int v186; // edx
  unsigned int v187; // ecx
  int v188; // eax
  unsigned int k; // ecx
  int v190; // eax
  unsigned __int8 *v191; // edi
  unsigned __int8 *v192; // edi
  unsigned int l; // ecx
  int v194; // eax
  unsigned __int8 *v195; // edi
  __int16 v196; // ax
  signed int v197; // edx
  unsigned __int8 *v198; // edi
  unsigned int v199; // ecx
  int v200; // eax
  unsigned int v201; // ecx
  _BYTE *v202; // edi
  int v203; // eax
  _BYTE *v204; // edi
  unsigned int v205; // ecx
  __int16 v206; // ax
  int v207; // eax
  _BYTE *v208; // edi
  signed int v209; // edx
  signed int v210; // ecx
  int v211; // eax
  unsigned __int8 *v212; // edi
  unsigned __int8 *v213; // edi
  signed int v214; // ecx
  int v215; // eax
  _BYTE *v216; // edi
  signed int v217; // edx
  unsigned int v218; // ecx
  int v219; // eax
  unsigned int m; // ecx
  int v221; // eax
  unsigned __int8 *v222; // edi
  unsigned __int8 *v223; // edi
  unsigned int n; // ecx
  int v225; // eax
  unsigned __int8 *v226; // edi
  __int16 v227; // ax
  signed int v228; // edx
  signed int v229; // ecx
  int v230; // eax
  unsigned __int8 *v231; // edi
  unsigned __int8 *v232; // edi
  signed int v233; // ecx
  int v234; // eax
  _BYTE *v235; // edi
  signed int v236; // edx
  signed int v237; // ecx
  unsigned __int8 *v238; // edi
  signed int v239; // ecx
  signed int v240; // ebp
  signed int v241; // edx
  unsigned int v242; // eax
  unsigned int v243; // ecx
  unsigned int v244; // ecx
  unsigned __int8 *v245; // edi
  unsigned int v246; // ecx
  signed int ii; // edx
  unsigned __int8 *v248; // edi
  unsigned int v249; // ecx
  unsigned int v250; // ecx
  _BYTE *v251; // edi
  unsigned int v252; // ecx
  signed int v253; // edx
  unsigned __int8 *v254; // edi
  unsigned int v255; // ecx
  unsigned int v256; // ecx
  _BYTE *v257; // edi
  unsigned int v258; // ecx
  signed int jj; // edx
  unsigned int v260; // ecx
  unsigned int v261; // ecx
  unsigned __int8 *v262; // edi
  unsigned int v263; // ecx
  unsigned __int8 *v264; // edi
  signed int v265; // edx
  unsigned int v266; // ecx
  unsigned int v267; // ecx
  _BYTE *v268; // edi
  unsigned int v269; // ecx
  signed int kk; // edx
  unsigned __int8 *v271; // edi
  unsigned int v272; // ecx
  unsigned int v273; // ecx
  _BYTE *v274; // edi
  unsigned int v275; // ecx
  signed int v276; // edx
  signed int v277; // ecx
  unsigned __int8 *v278; // edi
  signed int v279; // ecx
  signed int ll; // edx
  unsigned int v281; // ecx
  unsigned int v282; // ecx
  unsigned __int8 *v283; // edi
  unsigned int v284; // ecx
  unsigned __int8 *v285; // edi
  signed int v286; // edx
  signed int v287; // ecx
  unsigned __int8 *v288; // edi
  signed int v289; // ecx
  int v290; // [esp-14h] [ebp-18h]
  int v291; // [esp-14h] [ebp-18h]

  gpCelFrame = (unsigned __int8 *)speed_cel_frame_num_from_light_index_frame_num;
  tmp_pbDst = pbDst;
  if ( !(_BYTE)light_table_index )
  {
    if ( level_cel_block & 0x8000 )
      level_cel_block = *(_DWORD *)&gpCelFrame[64 * (level_cel_block & 0xFFF)]
                      + (unsigned __int16)(level_cel_block & 0xF000);
    pdung_cels = (unsigned __int8 *)pDungeonCels + *((_DWORD *)pDungeonCels + (level_cel_block & 0xFFF));
    v8 = level_cel_block;
    LOBYTE(v8) = BYTE1(v8);
    v7 = ((v8 >> 4) & 7) + 8;
    goto LABEL_11;
  }
  if ( (_BYTE)light_table_index != lightmax )
  {
    if ( !(level_cel_block & 0x8000) )
    {
      pdung_cels2 = (char *)pDungeonCels + *((_DWORD *)pDungeonCels + (level_cel_block & 0xFFF));
      l_tbl = &pLightTbl[256 * light_table_index];
      cel_type_16 = (unsigned __int8)(BYTE1(level_cel_block) >> 4);
      if ( BYTE1(level_cel_block) >> 4 )
      {
        switch ( cel_type_16 )
        {
          case 1:
            WorldBoolFlag = (unsigned __int8)pbDst & 1;
            v18 = 32;
            do
            {
              v19 = 32;
              do
              {
                while ( 1 )
                {
                  v20 = (unsigned __int8)*pdung_cels2++;
                  if ( (v20 & 0x80u) == 0 )
                    break;
                  LOBYTE(v20) = -(char)v20;
                  tmp_pbDst += v20;
                  v19 -= v20;
                  if ( !v19 )
                    goto LABEL_67;
                }
                v21 = v19 - v20;
                if ( tmp_pbDst < gpBufEnd )
                  return;
                if ( ((unsigned __int8)tmp_pbDst & 1) == WorldBoolFlag )
                {
                  v290 = v21;
                  v22 = v20 >> 1;
                  if ( v20 & 1 )
                  {
                    ++pdung_cels2;
                    ++tmp_pbDst;
                    v23 = v22 & 1;
                    v26 = v20 >> 2;
                    if ( v23 )
                    {
                      LOBYTE(v21) = *pdung_cels2;
                      pdung_cels2 += 2;
                      *tmp_pbDst = l_tbl[v21];
                      tmp_pbDst += 2;
                    }
                    if ( (_BYTE)v26 )
                    {
                      do
                      {
                        v27 = *(_DWORD *)pdung_cels2;
                        pdung_cels2 += 4;
                        LOBYTE(v21) = v27;
                        *tmp_pbDst = l_tbl[v21];
                        LOBYTE(v21) = BYTE2(v27);
                        tmp_pbDst += 4;
                        --v26;
                        *(tmp_pbDst - 2) = l_tbl[v21];
                      }
                      while ( v26 );
                    }
                  }
                  else
                  {
                    v23 = v22 & 1;
                    v24 = v20 >> 2;
                    if ( v23 )
                    {
                      LOBYTE(v21) = pdung_cels2[1];
                      pdung_cels2 += 2;
                      tmp_pbDst[1] = l_tbl[v21];
                      tmp_pbDst += 2;
                    }
                    if ( (_BYTE)v24 )
                    {
                      do
                      {
                        v25 = *(_DWORD *)pdung_cels2;
                        pdung_cels2 += 4;
                        LOBYTE(v21) = BYTE1(v25);
                        v25 >>= 16;
                        tmp_pbDst[1] = l_tbl[v21];
                        LOBYTE(v21) = BYTE1(v25);
                        tmp_pbDst += 4;
                        --v24;
                        *(tmp_pbDst - 1) = l_tbl[v21];
                      }
                      while ( v24 );
                    }
                  }
                  v19 = v290;
                }
                else
                {
                  v291 = v21;
                  v28 = v20 >> 1;
                  if ( v20 & 1 )
                  {
                    LOBYTE(v21) = *pdung_cels2++;
                    *tmp_pbDst++ = l_tbl[v21];
                    v23 = v28 & 1;
                    v31 = v20 >> 2;
                    if ( v23 )
                    {
                      LOBYTE(v21) = pdung_cels2[1];
                      pdung_cels2 += 2;
                      tmp_pbDst[1] = l_tbl[v21];
                      tmp_pbDst += 2;
                    }
                    if ( (_BYTE)v31 )
                    {
                      do
                      {
                        v32 = *(_DWORD *)pdung_cels2;
                        pdung_cels2 += 4;
                        LOBYTE(v21) = BYTE1(v32);
                        v32 >>= 16;
                        tmp_pbDst[1] = l_tbl[v21];
                        LOBYTE(v21) = BYTE1(v32);
                        tmp_pbDst += 4;
                        --v31;
                        *(tmp_pbDst - 1) = l_tbl[v21];
                      }
                      while ( v31 );
                    }
                  }
                  else
                  {
                    v23 = v28 & 1;
                    v29 = v20 >> 2;
                    if ( v23 )
                    {
                      LOBYTE(v21) = *pdung_cels2;
                      pdung_cels2 += 2;
                      *tmp_pbDst = l_tbl[v21];
                      tmp_pbDst += 2;
                    }
                    if ( (_BYTE)v29 )
                    {
                      do
                      {
                        v30 = *(_DWORD *)pdung_cels2;
                        pdung_cels2 += 4;
                        LOBYTE(v21) = v30;
                        *tmp_pbDst = l_tbl[v21];
                        LOBYTE(v21) = BYTE2(v30);
                        tmp_pbDst += 4;
                        --v29;
                        *(tmp_pbDst - 2) = l_tbl[v21];
                      }
                      while ( v29 );
                    }
                  }
                  v19 = v291;
                }
              }
              while ( v19 );
LABEL_67:
              WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
              tmp_pbDst -= 800;
              --v18;
            }
            while ( v18 );
            break;
          case 2:
            WorldBoolFlag = 0;
            v33 = 30;
            while ( tmp_pbDst >= gpBufEnd )
            {
              v34 = &tmp_pbDst[v33];
              v35 = 32 - v33;
              WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
              if ( WorldBoolFlag )
              {
                v36 = v35 & 2;
                pdung_cels2 += v36;
                v23 = v35 & 1;
                v37 = v35 >> 1;
                if ( v23 )
                {
                  ++pdung_cels2;
                  ++v34;
                  v23 = v37 & 1;
                  v40 = v37 >> 1;
                  if ( v23 )
                  {
                    LOBYTE(v36) = *pdung_cels2;
                    pdung_cels2 += 2;
                    *v34 = l_tbl[v36];
                    v34 += 2;
                  }
                  if ( (_BYTE)v40 )
                  {
                    do
                    {
                      v41 = *(_DWORD *)pdung_cels2;
                      pdung_cels2 += 4;
                      LOBYTE(v36) = v41;
                      *v34 = l_tbl[v36];
                      LOBYTE(v36) = BYTE2(v41);
                      v34 += 4;
                      --v40;
                      *(v34 - 2) = l_tbl[v36];
                    }
                    while ( v40 );
                  }
                }
                else
                {
                  v23 = v37 & 1;
                  v38 = v37 >> 1;
                  if ( v23 )
                  {
                    LOBYTE(v36) = pdung_cels2[1];
                    pdung_cels2 += 2;
                    v34[1] = l_tbl[v36];
                    v34 += 2;
                  }
                  if ( (_BYTE)v38 )
                  {
                    do
                    {
                      v39 = *(_DWORD *)pdung_cels2;
                      pdung_cels2 += 4;
                      LOBYTE(v36) = BYTE1(v39);
                      v39 >>= 16;
                      v34[1] = l_tbl[v36];
                      LOBYTE(v36) = BYTE1(v39);
                      v34 += 4;
                      --v38;
                      *(v34 - 1) = l_tbl[v36];
                    }
                    while ( v38 );
                  }
                }
              }
              else
              {
                v42 = v35 & 2;
                pdung_cels2 += v42;
                v23 = v35 & 1;
                v43 = v35 >> 1;
                if ( v23 )
                {
                  LOBYTE(v42) = *pdung_cels2++;
                  *v34++ = l_tbl[v42];
                  v23 = v43 & 1;
                  v46 = v43 >> 1;
                  if ( v23 )
                  {
                    LOBYTE(v42) = pdung_cels2[1];
                    pdung_cels2 += 2;
                    v34[1] = l_tbl[v42];
                    v34 += 2;
                  }
                  if ( (_BYTE)v46 )
                  {
                    do
                    {
                      v47 = *(_DWORD *)pdung_cels2;
                      pdung_cels2 += 4;
                      LOBYTE(v42) = BYTE1(v47);
                      v47 >>= 16;
                      v34[1] = l_tbl[v42];
                      LOBYTE(v42) = BYTE1(v47);
                      v34 += 4;
                      --v46;
                      *(v34 - 1) = l_tbl[v42];
                    }
                    while ( v46 );
                  }
                }
                else
                {
                  v23 = v43 & 1;
                  v44 = v43 >> 1;
                  if ( v23 )
                  {
                    LOBYTE(v42) = *pdung_cels2;
                    pdung_cels2 += 2;
                    *v34 = l_tbl[v42];
                    v34 += 2;
                  }
                  if ( (_BYTE)v44 )
                  {
                    do
                    {
                      v45 = *(_DWORD *)pdung_cels2;
                      pdung_cels2 += 4;
                      LOBYTE(v42) = v45;
                      *v34 = l_tbl[v42];
                      LOBYTE(v42) = BYTE2(v45);
                      v34 += 4;
                      --v44;
                      *(v34 - 2) = l_tbl[v42];
                    }
                    while ( v44 );
                  }
                }
              }
              tmp_pbDst = v34 - 800;
              v48 = __OFSUB__(v33, 2);
              v33 -= 2;
              if ( (v33 < 0) ^ v48 )
              {
                v49 = 2;
                do
                {
                  if ( tmp_pbDst < gpBufEnd )
                    break;
                  v50 = &tmp_pbDst[v49];
                  v51 = 32 - v49;
                  WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
                  if ( WorldBoolFlag )
                  {
                    v52 = v51 & 2;
                    pdung_cels2 += v52;
                    v23 = v51 & 1;
                    v53 = v51 >> 1;
                    if ( v23 )
                    {
                      ++pdung_cels2;
                      ++v50;
                      v23 = v53 & 1;
                      v56 = v53 >> 1;
                      if ( v23 )
                      {
                        LOBYTE(v52) = *pdung_cels2;
                        pdung_cels2 += 2;
                        *v50 = l_tbl[v52];
                        v50 += 2;
                      }
                      if ( (_BYTE)v56 )
                      {
                        do
                        {
                          v57 = *(_DWORD *)pdung_cels2;
                          pdung_cels2 += 4;
                          LOBYTE(v52) = v57;
                          *v50 = l_tbl[v52];
                          LOBYTE(v52) = BYTE2(v57);
                          v50 += 4;
                          --v56;
                          *(v50 - 2) = l_tbl[v52];
                        }
                        while ( v56 );
                      }
                    }
                    else
                    {
                      v23 = v53 & 1;
                      v54 = v53 >> 1;
                      if ( v23 )
                      {
                        LOBYTE(v52) = pdung_cels2[1];
                        pdung_cels2 += 2;
                        v50[1] = l_tbl[v52];
                        v50 += 2;
                      }
                      if ( (_BYTE)v54 )
                      {
                        do
                        {
                          v55 = *(_DWORD *)pdung_cels2;
                          pdung_cels2 += 4;
                          LOBYTE(v52) = BYTE1(v55);
                          v55 >>= 16;
                          v50[1] = l_tbl[v52];
                          LOBYTE(v52) = BYTE1(v55);
                          v50 += 4;
                          --v54;
                          *(v50 - 1) = l_tbl[v52];
                        }
                        while ( v54 );
                      }
                    }
                  }
                  else
                  {
                    v58 = v51 & 2;
                    pdung_cels2 += v58;
                    v23 = v51 & 1;
                    v59 = v51 >> 1;
                    if ( v23 )
                    {
                      LOBYTE(v58) = *pdung_cels2++;
                      *v50++ = l_tbl[v58];
                      v23 = v59 & 1;
                      v62 = v59 >> 1;
                      if ( v23 )
                      {
                        LOBYTE(v58) = pdung_cels2[1];
                        pdung_cels2 += 2;
                        v50[1] = l_tbl[v58];
                        v50 += 2;
                      }
                      if ( (_BYTE)v62 )
                      {
                        do
                        {
                          v63 = *(_DWORD *)pdung_cels2;
                          pdung_cels2 += 4;
                          LOBYTE(v58) = BYTE1(v63);
                          v63 >>= 16;
                          v50[1] = l_tbl[v58];
                          LOBYTE(v58) = BYTE1(v63);
                          v50 += 4;
                          --v62;
                          *(v50 - 1) = l_tbl[v58];
                        }
                        while ( v62 );
                      }
                    }
                    else
                    {
                      v23 = v59 & 1;
                      v60 = v59 >> 1;
                      if ( v23 )
                      {
                        LOBYTE(v58) = *pdung_cels2;
                        pdung_cels2 += 2;
                        *v50 = l_tbl[v58];
                        v50 += 2;
                      }
                      if ( (_BYTE)v60 )
                      {
                        do
                        {
                          v61 = *(_DWORD *)pdung_cels2;
                          pdung_cels2 += 4;
                          LOBYTE(v58) = v61;
                          *v50 = l_tbl[v58];
                          LOBYTE(v58) = BYTE2(v61);
                          v50 += 4;
                          --v60;
                          *(v50 - 2) = l_tbl[v58];
                        }
                        while ( v60 );
                      }
                    }
                  }
                  tmp_pbDst = v50 - 800;
                  v49 += 2;
                }
                while ( v49 != 32 );
                return;
              }
            }
            break;
          case 3:
            WorldBoolFlag = 0;
            v64 = 30;
            while ( tmp_pbDst >= gpBufEnd )
            {
              v65 = 32 - v64;
              WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
              if ( WorldBoolFlag )
              {
                v23 = v65 & 1;
                v66 = v65 >> 1;
                if ( v23 )
                {
                  ++pdung_cels2;
                  ++tmp_pbDst;
                  v23 = v66 & 1;
                  v69 = v66 >> 1;
                  if ( v23 )
                  {
                    LOBYTE(v1) = *pdung_cels2;
                    pdung_cels2 += 2;
                    *tmp_pbDst = l_tbl[v1];
                    tmp_pbDst += 2;
                  }
                  if ( (_BYTE)v69 )
                  {
                    do
                    {
                      v70 = *(_DWORD *)pdung_cels2;
                      pdung_cels2 += 4;
                      LOBYTE(v1) = v70;
                      *tmp_pbDst = l_tbl[v1];
                      LOBYTE(v1) = BYTE2(v70);
                      tmp_pbDst += 4;
                      --v69;
                      *(tmp_pbDst - 2) = l_tbl[v1];
                    }
                    while ( v69 );
                  }
                }
                else
                {
                  v23 = v66 & 1;
                  v67 = v66 >> 1;
                  if ( v23 )
                  {
                    LOBYTE(v1) = pdung_cels2[1];
                    pdung_cels2 += 2;
                    tmp_pbDst[1] = l_tbl[v1];
                    tmp_pbDst += 2;
                  }
                  if ( (_BYTE)v67 )
                  {
                    do
                    {
                      v68 = *(_DWORD *)pdung_cels2;
                      pdung_cels2 += 4;
                      LOBYTE(v1) = BYTE1(v68);
                      v68 >>= 16;
                      tmp_pbDst[1] = l_tbl[v1];
                      LOBYTE(v1) = BYTE1(v68);
                      tmp_pbDst += 4;
                      --v67;
                      *(tmp_pbDst - 1) = l_tbl[v1];
                    }
                    while ( v67 );
                  }
                }
                v1 = (unsigned __int8)pdung_cels2 & 2;
                pdung_cels2 += v1;
              }
              else
              {
                v23 = v65 & 1;
                v71 = v65 >> 1;
                if ( v23 )
                {
                  LOBYTE(v1) = *pdung_cels2++;
                  *tmp_pbDst++ = l_tbl[v1];
                  v23 = v71 & 1;
                  v74 = v71 >> 1;
                  if ( v23 )
                  {
                    LOBYTE(v1) = pdung_cels2[1];
                    pdung_cels2 += 2;
                    tmp_pbDst[1] = l_tbl[v1];
                    tmp_pbDst += 2;
                  }
                  if ( (_BYTE)v74 )
                  {
                    do
                    {
                      v75 = *(_DWORD *)pdung_cels2;
                      pdung_cels2 += 4;
                      LOBYTE(v1) = BYTE1(v75);
                      v75 >>= 16;
                      tmp_pbDst[1] = l_tbl[v1];
                      LOBYTE(v1) = BYTE1(v75);
                      tmp_pbDst += 4;
                      --v74;
                      *(tmp_pbDst - 1) = l_tbl[v1];
                    }
                    while ( v74 );
                  }
                }
                else
                {
                  v23 = v71 & 1;
                  v72 = v71 >> 1;
                  if ( v23 )
                  {
                    LOBYTE(v1) = *pdung_cels2;
                    pdung_cels2 += 2;
                    *tmp_pbDst = l_tbl[v1];
                    tmp_pbDst += 2;
                  }
                  if ( (_BYTE)v72 )
                  {
                    do
                    {
                      v73 = *(_DWORD *)pdung_cels2;
                      pdung_cels2 += 4;
                      LOBYTE(v1) = v73;
                      *tmp_pbDst = l_tbl[v1];
                      LOBYTE(v1) = BYTE2(v73);
                      tmp_pbDst += 4;
                      --v72;
                      *(tmp_pbDst - 2) = l_tbl[v1];
                    }
                    while ( v72 );
                  }
                }
                v1 = (unsigned __int8)pdung_cels2 & 2;
                pdung_cels2 += v1;
              }
              tmp_pbDst = &tmp_pbDst[v64 - 800];
              v48 = __OFSUB__(v64, 2);
              v64 -= 2;
              if ( (v64 < 0) ^ v48 )
              {
                v76 = 2;
                do
                {
                  if ( tmp_pbDst < gpBufEnd )
                    break;
                  v77 = 32 - v76;
                  WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
                  if ( WorldBoolFlag )
                  {
                    v23 = v77 & 1;
                    v78 = v77 >> 1;
                    if ( v23 )
                    {
                      ++pdung_cels2;
                      ++tmp_pbDst;
                      v23 = v78 & 1;
                      v81 = v78 >> 1;
                      if ( v23 )
                      {
                        LOBYTE(v1) = *pdung_cels2;
                        pdung_cels2 += 2;
                        *tmp_pbDst = l_tbl[v1];
                        tmp_pbDst += 2;
                      }
                      if ( (_BYTE)v81 )
                      {
                        do
                        {
                          v82 = *(_DWORD *)pdung_cels2;
                          pdung_cels2 += 4;
                          LOBYTE(v1) = v82;
                          *tmp_pbDst = l_tbl[v1];
                          LOBYTE(v1) = BYTE2(v82);
                          tmp_pbDst += 4;
                          --v81;
                          *(tmp_pbDst - 2) = l_tbl[v1];
                        }
                        while ( v81 );
                      }
                    }
                    else
                    {
                      v23 = v78 & 1;
                      v79 = v78 >> 1;
                      if ( v23 )
                      {
                        LOBYTE(v1) = pdung_cels2[1];
                        pdung_cels2 += 2;
                        tmp_pbDst[1] = l_tbl[v1];
                        tmp_pbDst += 2;
                      }
                      if ( (_BYTE)v79 )
                      {
                        do
                        {
                          v80 = *(_DWORD *)pdung_cels2;
                          pdung_cels2 += 4;
                          LOBYTE(v1) = BYTE1(v80);
                          v80 >>= 16;
                          tmp_pbDst[1] = l_tbl[v1];
                          LOBYTE(v1) = BYTE1(v80);
                          tmp_pbDst += 4;
                          --v79;
                          *(tmp_pbDst - 1) = l_tbl[v1];
                        }
                        while ( v79 );
                      }
                    }
                    v1 = (unsigned __int8)pdung_cels2 & 2;
                    pdung_cels2 += v1;
                  }
                  else
                  {
                    v23 = v77 & 1;
                    v83 = v77 >> 1;
                    if ( v23 )
                    {
                      LOBYTE(v1) = *pdung_cels2++;
                      *tmp_pbDst++ = l_tbl[v1];
                      v23 = v83 & 1;
                      v86 = v83 >> 1;
                      if ( v23 )
                      {
                        LOBYTE(v1) = pdung_cels2[1];
                        pdung_cels2 += 2;
                        tmp_pbDst[1] = l_tbl[v1];
                        tmp_pbDst += 2;
                      }
                      if ( (_BYTE)v86 )
                      {
                        do
                        {
                          v87 = *(_DWORD *)pdung_cels2;
                          pdung_cels2 += 4;
                          LOBYTE(v1) = BYTE1(v87);
                          v87 >>= 16;
                          tmp_pbDst[1] = l_tbl[v1];
                          LOBYTE(v1) = BYTE1(v87);
                          tmp_pbDst += 4;
                          --v86;
                          *(tmp_pbDst - 1) = l_tbl[v1];
                        }
                        while ( v86 );
                      }
                    }
                    else
                    {
                      v23 = v83 & 1;
                      v84 = v83 >> 1;
                      if ( v23 )
                      {
                        LOBYTE(v1) = *pdung_cels2;
                        pdung_cels2 += 2;
                        *tmp_pbDst = l_tbl[v1];
                        tmp_pbDst += 2;
                      }
                      if ( (_BYTE)v84 )
                      {
                        do
                        {
                          v85 = *(_DWORD *)pdung_cels2;
                          pdung_cels2 += 4;
                          LOBYTE(v1) = v85;
                          *tmp_pbDst = l_tbl[v1];
                          LOBYTE(v1) = BYTE2(v85);
                          tmp_pbDst += 4;
                          --v84;
                          *(tmp_pbDst - 2) = l_tbl[v1];
                        }
                        while ( v84 );
                      }
                    }
                    v1 = (unsigned __int8)pdung_cels2 & 2;
                    pdung_cels2 += v1;
                  }
                  tmp_pbDst = &tmp_pbDst[v76 - 800];
                  v76 += 2;
                }
                while ( v76 != 32 );
                return;
              }
            }
            break;
          case 4:
            WorldBoolFlag = 0;
            v88 = 30;
            while ( tmp_pbDst >= gpBufEnd )
            {
              v89 = &tmp_pbDst[v88];
              v90 = 32 - v88;
              WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
              if ( WorldBoolFlag )
              {
                v91 = v90 & 2;
                pdung_cels2 += v91;
                v23 = v90 & 1;
                v92 = v90 >> 1;
                if ( v23 )
                {
                  ++pdung_cels2;
                  ++v89;
                  v23 = v92 & 1;
                  v95 = v92 >> 1;
                  if ( v23 )
                  {
                    LOBYTE(v91) = *pdung_cels2;
                    pdung_cels2 += 2;
                    *v89 = l_tbl[v91];
                    v89 += 2;
                  }
                  if ( (_BYTE)v95 )
                  {
                    do
                    {
                      v96 = *(_DWORD *)pdung_cels2;
                      pdung_cels2 += 4;
                      LOBYTE(v91) = v96;
                      *v89 = l_tbl[v91];
                      LOBYTE(v91) = BYTE2(v96);
                      v89 += 4;
                      --v95;
                      *(v89 - 2) = l_tbl[v91];
                    }
                    while ( v95 );
                  }
                }
                else
                {
                  v23 = v92 & 1;
                  v93 = v92 >> 1;
                  if ( v23 )
                  {
                    LOBYTE(v91) = pdung_cels2[1];
                    pdung_cels2 += 2;
                    v89[1] = l_tbl[v91];
                    v89 += 2;
                  }
                  if ( (_BYTE)v93 )
                  {
                    do
                    {
                      v94 = *(_DWORD *)pdung_cels2;
                      pdung_cels2 += 4;
                      LOBYTE(v91) = BYTE1(v94);
                      v94 >>= 16;
                      v89[1] = l_tbl[v91];
                      LOBYTE(v91) = BYTE1(v94);
                      v89 += 4;
                      --v93;
                      *(v89 - 1) = l_tbl[v91];
                    }
                    while ( v93 );
                  }
                }
              }
              else
              {
                v91 = v90 & 2;
                pdung_cels2 += v91;
                v23 = v90 & 1;
                v97 = v90 >> 1;
                if ( v23 )
                {
                  LOBYTE(v91) = *pdung_cels2++;
                  *v89++ = l_tbl[v91];
                  v23 = v97 & 1;
                  v100 = v97 >> 1;
                  if ( v23 )
                  {
                    LOBYTE(v91) = pdung_cels2[1];
                    pdung_cels2 += 2;
                    v89[1] = l_tbl[v91];
                    v89 += 2;
                  }
                  if ( (_BYTE)v100 )
                  {
                    do
                    {
                      v101 = *(_DWORD *)pdung_cels2;
                      pdung_cels2 += 4;
                      LOBYTE(v91) = BYTE1(v101);
                      v101 >>= 16;
                      v89[1] = l_tbl[v91];
                      LOBYTE(v91) = BYTE1(v101);
                      v89 += 4;
                      --v100;
                      *(v89 - 1) = l_tbl[v91];
                    }
                    while ( v100 );
                  }
                }
                else
                {
                  v23 = v97 & 1;
                  v98 = v97 >> 1;
                  if ( v23 )
                  {
                    LOBYTE(v91) = *pdung_cels2;
                    pdung_cels2 += 2;
                    *v89 = l_tbl[v91];
                    v89 += 2;
                  }
                  if ( (_BYTE)v98 )
                  {
                    do
                    {
                      v99 = *(_DWORD *)pdung_cels2;
                      pdung_cels2 += 4;
                      LOBYTE(v91) = v99;
                      *v89 = l_tbl[v91];
                      LOBYTE(v91) = BYTE2(v99);
                      v89 += 4;
                      --v98;
                      *(v89 - 2) = l_tbl[v91];
                    }
                    while ( v98 );
                  }
                }
              }
              tmp_pbDst = v89 - 800;
              v48 = __OFSUB__(v88, 2);
              v88 -= 2;
              if ( (v88 < 0) ^ v48 )
              {
                v102 = 8;
                do
                {
                  if ( tmp_pbDst < gpBufEnd )
                    break;
                  v103 = 8;
                  do
                  {
                    v104 = *(_DWORD *)pdung_cels2;
                    pdung_cels2 += 4;
                    LOBYTE(v91) = BYTE1(v104);
                    v104 >>= 16;
                    tmp_pbDst[1] = l_tbl[v91];
                    LOBYTE(v91) = BYTE1(v104);
                    tmp_pbDst += 4;
                    --v103;
                    *(tmp_pbDst - 1) = l_tbl[v91];
                  }
                  while ( v103 );
                  v105 = tmp_pbDst - 800;
                  if ( v105 < gpBufEnd )
                    break;
                  v106 = 8;
                  do
                  {
                    v107 = *(_DWORD *)pdung_cels2;
                    pdung_cels2 += 4;
                    LOBYTE(v91) = v107;
                    *v105 = l_tbl[v91];
                    LOBYTE(v91) = BYTE2(v107);
                    v105 += 4;
                    --v106;
                    *(v105 - 2) = l_tbl[v91];
                  }
                  while ( v106 );
                  tmp_pbDst = v105 - 800;
                  --v102;
                }
                while ( v102 );
                return;
              }
            }
            break;
          default:
            WorldBoolFlag = 0;
            v108 = 30;
            while ( tmp_pbDst >= gpBufEnd )
            {
              v109 = 32 - v108;
              WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
              if ( WorldBoolFlag )
              {
                v23 = v109 & 1;
                v110 = v109 >> 1;
                if ( v23 )
                {
                  ++pdung_cels2;
                  ++tmp_pbDst;
                  v23 = v110 & 1;
                  v113 = v110 >> 1;
                  if ( v23 )
                  {
                    LOBYTE(v1) = *pdung_cels2;
                    pdung_cels2 += 2;
                    *tmp_pbDst = l_tbl[v1];
                    tmp_pbDst += 2;
                  }
                  if ( (_BYTE)v113 )
                  {
                    do
                    {
                      v114 = *(_DWORD *)pdung_cels2;
                      pdung_cels2 += 4;
                      LOBYTE(v1) = v114;
                      *tmp_pbDst = l_tbl[v1];
                      LOBYTE(v1) = BYTE2(v114);
                      tmp_pbDst += 4;
                      --v113;
                      *(tmp_pbDst - 2) = l_tbl[v1];
                    }
                    while ( v113 );
                  }
                }
                else
                {
                  v23 = v110 & 1;
                  v111 = v110 >> 1;
                  if ( v23 )
                  {
                    LOBYTE(v1) = pdung_cels2[1];
                    pdung_cels2 += 2;
                    tmp_pbDst[1] = l_tbl[v1];
                    tmp_pbDst += 2;
                  }
                  if ( (_BYTE)v111 )
                  {
                    do
                    {
                      v112 = *(_DWORD *)pdung_cels2;
                      pdung_cels2 += 4;
                      LOBYTE(v1) = BYTE1(v112);
                      v112 >>= 16;
                      tmp_pbDst[1] = l_tbl[v1];
                      LOBYTE(v1) = BYTE1(v112);
                      tmp_pbDst += 4;
                      --v111;
                      *(tmp_pbDst - 1) = l_tbl[v1];
                    }
                    while ( v111 );
                  }
                }
                v1 = (unsigned __int8)pdung_cels2 & 2;
                pdung_cels2 += v1;
              }
              else
              {
                v23 = v109 & 1;
                v115 = v109 >> 1;
                if ( v23 )
                {
                  LOBYTE(v1) = *pdung_cels2++;
                  *tmp_pbDst++ = l_tbl[v1];
                  v23 = v115 & 1;
                  v118 = v115 >> 1;
                  if ( v23 )
                  {
                    LOBYTE(v1) = pdung_cels2[1];
                    pdung_cels2 += 2;
                    tmp_pbDst[1] = l_tbl[v1];
                    tmp_pbDst += 2;
                  }
                  if ( (_BYTE)v118 )
                  {
                    do
                    {
                      v119 = *(_DWORD *)pdung_cels2;
                      pdung_cels2 += 4;
                      LOBYTE(v1) = BYTE1(v119);
                      v119 >>= 16;
                      tmp_pbDst[1] = l_tbl[v1];
                      LOBYTE(v1) = BYTE1(v119);
                      tmp_pbDst += 4;
                      --v118;
                      *(tmp_pbDst - 1) = l_tbl[v1];
                    }
                    while ( v118 );
                  }
                }
                else
                {
                  v23 = v115 & 1;
                  v116 = v115 >> 1;
                  if ( v23 )
                  {
                    LOBYTE(v1) = *pdung_cels2;
                    pdung_cels2 += 2;
                    *tmp_pbDst = l_tbl[v1];
                    tmp_pbDst += 2;
                  }
                  if ( (_BYTE)v116 )
                  {
                    do
                    {
                      v117 = *(_DWORD *)pdung_cels2;
                      pdung_cels2 += 4;
                      LOBYTE(v1) = v117;
                      *tmp_pbDst = l_tbl[v1];
                      LOBYTE(v1) = BYTE2(v117);
                      tmp_pbDst += 4;
                      --v116;
                      *(tmp_pbDst - 2) = l_tbl[v1];
                    }
                    while ( v116 );
                  }
                }
                v1 = (unsigned __int8)pdung_cels2 & 2;
                pdung_cels2 += v1;
              }
              tmp_pbDst = &tmp_pbDst[v108 - 800];
              v48 = __OFSUB__(v108, 2);
              v108 -= 2;
              if ( (v108 < 0) ^ v48 )
              {
                v120 = 8;
                do
                {
                  if ( tmp_pbDst < gpBufEnd )
                    break;
                  v121 = 8;
                  do
                  {
                    v122 = *(_DWORD *)pdung_cels2;
                    pdung_cels2 += 4;
                    LOBYTE(v1) = BYTE1(v122);
                    v122 >>= 16;
                    tmp_pbDst[1] = l_tbl[v1];
                    LOBYTE(v1) = BYTE1(v122);
                    tmp_pbDst += 4;
                    --v121;
                    *(tmp_pbDst - 1) = l_tbl[v1];
                  }
                  while ( v121 );
                  v123 = tmp_pbDst - 800;
                  if ( v123 < gpBufEnd )
                    break;
                  v124 = 8;
                  do
                  {
                    v125 = *(_DWORD *)pdung_cels2;
                    pdung_cels2 += 4;
                    LOBYTE(v1) = v125;
                    *v123 = l_tbl[v1];
                    LOBYTE(v1) = BYTE2(v125);
                    v123 += 4;
                    --v124;
                    *(v123 - 2) = l_tbl[v1];
                  }
                  while ( v124 );
                  tmp_pbDst = v123 - 800;
                  --v120;
                }
                while ( v120 );
                return;
              }
            }
            break;
        }
      }
      else
      {
        v12 = 16;
        do
        {
          if ( tmp_pbDst < gpBufEnd )
            break;
          v13 = 8;
          do
          {
            v14 = *(_DWORD *)pdung_cels2;
            pdung_cels2 += 4;
            LOBYTE(v1) = BYTE1(v14);
            v14 >>= 16;
            tmp_pbDst[1] = l_tbl[v1];
            LOBYTE(v1) = BYTE1(v14);
            tmp_pbDst += 4;
            --v13;
            *(tmp_pbDst - 1) = l_tbl[v1];
          }
          while ( v13 );
          v15 = tmp_pbDst - 800;
          if ( v15 < gpBufEnd )
            break;
          v16 = 8;
          do
          {
            v17 = *(_DWORD *)pdung_cels2;
            pdung_cels2 += 4;
            LOBYTE(v1) = v17;
            *v15 = l_tbl[v1];
            LOBYTE(v1) = BYTE2(v17);
            v15 += 4;
            --v16;
            *(v15 - 2) = l_tbl[v1];
          }
          while ( v16 );
          tmp_pbDst = v15 - 800;
          --v12;
        }
        while ( v12 );
      }
      return;
    }
    pdung_cels = (unsigned __int8 *)pSpeedCels
               + *(_DWORD *)&gpCelFrame[4 * (light_table_index + 16 * (level_cel_block & 0xFFF))];
    v7 = (unsigned __int8)(BYTE1(level_cel_block) >> 4);
LABEL_11:
    if ( v7 == 8 )
    {
      v126 = 16;
      do
      {
        if ( tmp_pbDst < gpBufEnd )
          break;
        v127 = 8;
        do
        {
          v128 = *(_DWORD *)pdung_cels;
          pdung_cels += 4;
          v129 = tmp_pbDst + 1;
          v128 = __ROR4__(v128, 8);
          *v129 = v128;
          v129 += 2;
          *v129 = __ROR4__(v128, 16);
          tmp_pbDst = v129 + 1;
          --v127;
        }
        while ( v127 );
        v130 = tmp_pbDst - 800;
        if ( v130 < gpBufEnd )
          break;
        v131 = 8;
        do
        {
          v132 = *(_DWORD *)pdung_cels;
          pdung_cels += 4;
          *v130 = v132;
          v133 = v130 + 2;
          *v133 = __ROR4__(v132, 16);
          v130 = v133 + 2;
          --v131;
        }
        while ( v131 );
        tmp_pbDst = v130 - 800;
        --v126;
      }
      while ( v126 );
      return;
    }
    if ( v7 != 9 )
    {
      switch ( v7 )
      {
        case 10:
          WorldBoolFlag = 0;
          v149 = 30;
          while ( tmp_pbDst >= gpBufEnd )
          {
            v150 = &tmp_pbDst[v149];
            v151 = 32 - v149;
            v152 = ((_BYTE)WorldBoolFlag + 1) & 1;
            WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
            if ( WorldBoolFlag )
            {
              v23 = __CFSHR__(v151, 2);
              v153 = v151 >> 2;
              if ( !v23
                || (LOWORD(v152) = *((_WORD *)pdung_cels + 1),
                    pdung_cels += 4,
                    v154 = v150 + 1,
                    *v154 = __ROR4__(v152, 8),
                    v150 = v154 + 1,
                    v153) )
              {
                do
                {
                  v155 = *(_DWORD *)pdung_cels;
                  pdung_cels += 4;
                  v156 = v150 + 1;
                  v155 = __ROR4__(v155, 8);
                  *v156 = v155;
                  v156 += 2;
                  *v156 = __ROR4__(v155, 16);
                  v150 = v156 + 1;
                  --v153;
                }
                while ( v153 );
              }
            }
            else
            {
              v23 = __CFSHR__(v151, 2);
              v157 = v151 >> 2;
              if ( !v23 || (v158 = *((_WORD *)pdung_cels + 1), pdung_cels += 4, *v150 = v158, v150 += 2, v157) )
              {
                do
                {
                  v159 = *(_DWORD *)pdung_cels;
                  pdung_cels += 4;
                  *v150 = v159;
                  v160 = v150 + 2;
                  *v160 = __ROR4__(v159, 16);
                  v150 = v160 + 2;
                  --v157;
                }
                while ( v157 );
              }
            }
            tmp_pbDst = v150 - 800;
            v48 = __OFSUB__(v149, 2);
            v149 -= 2;
            if ( (v149 < 0) ^ v48 )
            {
              v161 = 2;
              do
              {
                if ( tmp_pbDst < gpBufEnd )
                  break;
                v162 = &tmp_pbDst[v161];
                v163 = 32 - v161;
                v164 = ((_BYTE)WorldBoolFlag + 1) & 1;
                WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
                if ( WorldBoolFlag )
                {
                  v23 = __CFSHR__(v163, 2);
                  v165 = v163 >> 2;
                  if ( !v23
                    || (LOWORD(v164) = *((_WORD *)pdung_cels + 1),
                        pdung_cels += 4,
                        v166 = v162 + 1,
                        *v166 = __ROR4__(v164, 8),
                        v162 = v166 + 1,
                        v165) )
                  {
                    do
                    {
                      v167 = *(_DWORD *)pdung_cels;
                      pdung_cels += 4;
                      v168 = v162 + 1;
                      v167 = __ROR4__(v167, 8);
                      *v168 = v167;
                      v168 += 2;
                      *v168 = __ROR4__(v167, 16);
                      v162 = v168 + 1;
                      --v165;
                    }
                    while ( v165 );
                  }
                }
                else
                {
                  v23 = __CFSHR__(v163, 2);
                  v169 = v163 >> 2;
                  if ( !v23 || (v170 = *((_WORD *)pdung_cels + 1), pdung_cels += 4, *v162 = v170, v162 += 2, v169) )
                  {
                    do
                    {
                      v171 = *(_DWORD *)pdung_cels;
                      pdung_cels += 4;
                      *v162 = v171;
                      v172 = v162 + 2;
                      *v172 = __ROR4__(v171, 16);
                      v162 = v172 + 2;
                      --v169;
                    }
                    while ( v169 );
                  }
                }
                tmp_pbDst = v162 - 800;
                v161 += 2;
              }
              while ( v161 != 32 );
              return;
            }
          }
          break;
        case 11:
          WorldBoolFlag = 0;
          v173 = 30;
          while ( tmp_pbDst >= gpBufEnd )
          {
            v174 = 32 - v173;
            v175 = ((_BYTE)WorldBoolFlag + 1) & 1;
            v176 = 32 - v173;
            WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
            if ( v175 )
            {
              for ( i = v174 >> 2; i; --i )
              {
                v178 = *(_DWORD *)pdung_cels;
                pdung_cels += 4;
                v179 = tmp_pbDst + 1;
                v178 = __ROR4__(v178, 8);
                *v179 = v178;
                v179 += 2;
                v175 = __ROR4__(v178, 16);
                *v179 = v175;
                tmp_pbDst = v179 + 1;
              }
              v180 = v176 & 2;
              if ( v180 )
              {
                LOWORD(v175) = *(_WORD *)pdung_cels;
                pdung_cels += 4;
                v181 = tmp_pbDst + 1;
                *v181 = __ROR4__(v175, 8);
                tmp_pbDst = v181 + 1;
              }
            }
            else
            {
              for ( j = v174 >> 2; j; --j )
              {
                v183 = *(_DWORD *)pdung_cels;
                pdung_cels += 4;
                *tmp_pbDst = v183;
                v184 = tmp_pbDst + 2;
                *v184 = __ROR4__(v183, 16);
                tmp_pbDst = v184 + 2;
              }
              v180 = v176 & 2;
              if ( v180 )
              {
                v185 = *(_WORD *)pdung_cels;
                pdung_cels += 4;
                *tmp_pbDst = v185;
                tmp_pbDst += 2;
              }
            }
            tmp_pbDst = &tmp_pbDst[v173 - 800];
            v48 = __OFSUB__(v173, 2);
            v173 -= 2;
            if ( (v173 < 0) ^ v48 )
            {
              v186 = 2;
              do
              {
                if ( tmp_pbDst < gpBufEnd )
                  break;
                v187 = 32 - v186;
                v188 = ((_BYTE)WorldBoolFlag + 1) & 1;
                WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
                if ( WorldBoolFlag )
                {
                  for ( k = v187 >> 2; k; --k )
                  {
                    v190 = *(_DWORD *)pdung_cels;
                    pdung_cels += 4;
                    v191 = tmp_pbDst + 1;
                    v190 = __ROR4__(v190, 8);
                    *v191 = v190;
                    v191 += 2;
                    v188 = __ROR4__(v190, 16);
                    *v191 = v188;
                    tmp_pbDst = v191 + 1;
                  }
                  v180 &= 2u;
                  if ( v180 )
                  {
                    LOWORD(v188) = *(_WORD *)pdung_cels;
                    pdung_cels += 4;
                    v192 = tmp_pbDst + 1;
                    *v192 = __ROR4__(v188, 8);
                    tmp_pbDst = v192 + 1;
                  }
                }
                else
                {
                  for ( l = v187 >> 2; l; --l )
                  {
                    v194 = *(_DWORD *)pdung_cels;
                    pdung_cels += 4;
                    *tmp_pbDst = v194;
                    v195 = tmp_pbDst + 2;
                    *v195 = __ROR4__(v194, 16);
                    tmp_pbDst = v195 + 2;
                  }
                  v180 &= 2u;
                  if ( v180 )
                  {
                    v196 = *(_WORD *)pdung_cels;
                    pdung_cels += 4;
                    *tmp_pbDst = v196;
                    tmp_pbDst += 2;
                  }
                }
                tmp_pbDst = &tmp_pbDst[v186 - 800];
                v186 += 2;
              }
              while ( v186 != 32 );
              return;
            }
          }
          break;
        case 12:
          WorldBoolFlag = 0;
          v197 = 30;
          while ( tmp_pbDst >= gpBufEnd )
          {
            v198 = &tmp_pbDst[v197];
            v199 = 32 - v197;
            v200 = ((_BYTE)WorldBoolFlag + 1) & 1;
            WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
            if ( WorldBoolFlag )
            {
              v23 = __CFSHR__(v199, 2);
              v201 = v199 >> 2;
              if ( !v23
                || (LOWORD(v200) = *((_WORD *)pdung_cels + 1),
                    pdung_cels += 4,
                    v202 = v198 + 1,
                    *v202 = __ROR4__(v200, 8),
                    v198 = v202 + 1,
                    v201) )
              {
                do
                {
                  v203 = *(_DWORD *)pdung_cels;
                  pdung_cels += 4;
                  v204 = v198 + 1;
                  v203 = __ROR4__(v203, 8);
                  *v204 = v203;
                  v204 += 2;
                  *v204 = __ROR4__(v203, 16);
                  v198 = v204 + 1;
                  --v201;
                }
                while ( v201 );
              }
            }
            else
            {
              v23 = __CFSHR__(v199, 2);
              v205 = v199 >> 2;
              if ( !v23 || (v206 = *((_WORD *)pdung_cels + 1), pdung_cels += 4, *v198 = v206, v198 += 2, v205) )
              {
                do
                {
                  v207 = *(_DWORD *)pdung_cels;
                  pdung_cels += 4;
                  *v198 = v207;
                  v208 = v198 + 2;
                  *v208 = __ROR4__(v207, 16);
                  v198 = v208 + 2;
                  --v205;
                }
                while ( v205 );
              }
            }
            tmp_pbDst = v198 - 800;
            v48 = __OFSUB__(v197, 2);
            v197 -= 2;
            if ( (v197 < 0) ^ v48 )
            {
              v209 = 8;
              do
              {
                if ( tmp_pbDst < gpBufEnd )
                  break;
                v210 = 8;
                do
                {
                  v211 = *(_DWORD *)pdung_cels;
                  pdung_cels += 4;
                  v212 = tmp_pbDst + 1;
                  v211 = __ROR4__(v211, 8);
                  *v212 = v211;
                  v212 += 2;
                  *v212 = __ROR4__(v211, 16);
                  tmp_pbDst = v212 + 1;
                  --v210;
                }
                while ( v210 );
                v213 = tmp_pbDst - 800;
                if ( v213 < gpBufEnd )
                  break;
                v214 = 8;
                do
                {
                  v215 = *(_DWORD *)pdung_cels;
                  pdung_cels += 4;
                  *v213 = v215;
                  v216 = v213 + 2;
                  *v216 = __ROR4__(v215, 16);
                  v213 = v216 + 2;
                  --v214;
                }
                while ( v214 );
                tmp_pbDst = v213 - 800;
                --v209;
              }
              while ( v209 );
              return;
            }
          }
          break;
        default:
          WorldBoolFlag = 0;
          v217 = 30;
          while ( tmp_pbDst >= gpBufEnd )
          {
            v218 = 32 - v217;
            v219 = ((_BYTE)WorldBoolFlag + 1) & 1;
            WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
            if ( WorldBoolFlag )
            {
              for ( m = v218 >> 2; m; --m )
              {
                v221 = *(_DWORD *)pdung_cels;
                pdung_cels += 4;
                v222 = tmp_pbDst + 1;
                v221 = __ROR4__(v221, 8);
                *v222 = v221;
                v222 += 2;
                v219 = __ROR4__(v221, 16);
                *v222 = v219;
                tmp_pbDst = v222 + 1;
              }
              if ( (32 - (_BYTE)v217) & 2 )
              {
                LOWORD(v219) = *(_WORD *)pdung_cels;
                pdung_cels += 4;
                v223 = tmp_pbDst + 1;
                *v223 = __ROR4__(v219, 8);
                tmp_pbDst = v223 + 1;
              }
            }
            else
            {
              for ( n = v218 >> 2; n; --n )
              {
                v225 = *(_DWORD *)pdung_cels;
                pdung_cels += 4;
                *tmp_pbDst = v225;
                v226 = tmp_pbDst + 2;
                *v226 = __ROR4__(v225, 16);
                tmp_pbDst = v226 + 2;
              }
              if ( (32 - (_BYTE)v217) & 2 )
              {
                v227 = *(_WORD *)pdung_cels;
                pdung_cels += 4;
                *tmp_pbDst = v227;
                tmp_pbDst += 2;
              }
            }
            tmp_pbDst = &tmp_pbDst[v217 - 800];
            v48 = __OFSUB__(v217, 2);
            v217 -= 2;
            if ( (v217 < 0) ^ v48 )
            {
              v228 = 8;
              do
              {
                if ( tmp_pbDst < gpBufEnd )
                  break;
                v229 = 8;
                do
                {
                  v230 = *(_DWORD *)pdung_cels;
                  pdung_cels += 4;
                  v231 = tmp_pbDst + 1;
                  v230 = __ROR4__(v230, 8);
                  *v231 = v230;
                  v231 += 2;
                  *v231 = __ROR4__(v230, 16);
                  tmp_pbDst = v231 + 1;
                  --v229;
                }
                while ( v229 );
                v232 = tmp_pbDst - 800;
                if ( v232 < gpBufEnd )
                  break;
                v233 = 8;
                do
                {
                  v234 = *(_DWORD *)pdung_cels;
                  pdung_cels += 4;
                  *v232 = v234;
                  v235 = v232 + 2;
                  *v235 = __ROR4__(v234, 16);
                  v232 = v235 + 2;
                  --v233;
                }
                while ( v233 );
                tmp_pbDst = v232 - 800;
                --v228;
              }
              while ( v228 );
              return;
            }
          }
          break;
      }
      return;
    }
    WorldBoolFlag = (unsigned __int8)pbDst & 1;
    v134 = 32;
LABEL_251:
    v135 = 32;
    while ( 1 )
    {
      while ( 1 )
      {
        v136 = *pdung_cels++;
        if ( (v136 & 0x80u) == 0 )
          break;
        LOBYTE(v136) = -(char)v136;
        tmp_pbDst += v136;
        v135 -= v136;
        if ( !v135 )
        {
LABEL_271:
          WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
          tmp_pbDst -= 800;
          if ( !--v134 )
            return;
          goto LABEL_251;
        }
      }
      v135 -= v136;
      if ( tmp_pbDst < gpBufEnd )
        return;
      if ( ((unsigned __int8)tmp_pbDst & 1) == WorldBoolFlag )
      {
        v137 = v136 >> 1;
        if ( !(v136 & 1) )
          goto LABEL_258;
        ++pdung_cels;
        ++tmp_pbDst;
        if ( v137 )
        {
LABEL_265:
          v23 = v137 & 1;
          v145 = v137 >> 1;
          if ( !v23 || (v146 = *pdung_cels, pdung_cels += 2, *tmp_pbDst = v146, tmp_pbDst += 2, v145) )
          {
            do
            {
              v147 = *(_DWORD *)pdung_cels;
              pdung_cels += 4;
              *tmp_pbDst = v147;
              v148 = tmp_pbDst + 2;
              *v148 = __ROR4__(v147, 16);
              tmp_pbDst = v148 + 2;
              --v145;
            }
            while ( v145 );
          }
          goto LABEL_268;
        }
      }
      else
      {
        v137 = v136 >> 1;
        if ( !(v136 & 1) )
          goto LABEL_265;
        v144 = *pdung_cels++;
        *tmp_pbDst++ = v144;
        if ( v137 )
        {
LABEL_258:
          v23 = v137 & 1;
          v138 = v137 >> 1;
          if ( !v23
            || (v139 = pdung_cels + 1,
                v140 = tmp_pbDst + 1,
                v141 = *v139,
                pdung_cels = v139 + 1,
                *v140 = v141,
                tmp_pbDst = v140 + 1,
                v138) )
          {
            do
            {
              v142 = *(_DWORD *)pdung_cels;
              pdung_cels += 4;
              v143 = tmp_pbDst + 1;
              v142 = __ROR4__(v142, 8);
              *v143 = v142;
              v143 += 2;
              *v143 = __ROR4__(v142, 16);
              tmp_pbDst = v143 + 1;
              --v138;
            }
            while ( v138 );
          }
          goto LABEL_268;
        }
      }
LABEL_268:
      if ( !v135 )
        goto LABEL_271;
    }
  }
  if ( level_cel_block & 0x8000 )
    level_cel_block = *(_DWORD *)&gpCelFrame[64 * (level_cel_block & 0xFFF)]
                    + (unsigned __int16)(level_cel_block & 0xF000);
  v9 = (unsigned __int8 *)pDungeonCels + *((_DWORD *)pDungeonCels + (level_cel_block & 0xFFF));
  v10 = level_cel_block;
  LOBYTE(v10) = BYTE1(v10);
  v11 = (v10 >> 4) & 7;
  if ( !v11 )
  {
    v236 = 16;
    do
    {
      if ( tmp_pbDst < gpBufEnd )
        break;
      v237 = 8;
      do
      {
        tmp_pbDst[1] = 0;
        tmp_pbDst[3] = 0;
        tmp_pbDst += 4;
        --v237;
      }
      while ( v237 );
      v238 = tmp_pbDst - 800;
      if ( v238 < gpBufEnd )
        break;
      v239 = 8;
      do
      {
        *v238 = 0;
        v238[2] = 0;
        v238 += 4;
        --v239;
      }
      while ( v239 );
      tmp_pbDst = v238 - 800;
      --v236;
    }
    while ( v236 );
    return;
  }
  switch ( (_WORD)v11 )
  {
    case 1:
      WorldBoolFlag = (unsigned __int8)pbDst & 1;
      v240 = 32;
      while ( 1 )
      {
        v241 = 32;
        do
        {
          while ( 1 )
          {
            v242 = *v9++;
            if ( (v242 & 0x80u) != 0 )
              break;
            v241 -= v242;
            if ( tmp_pbDst < gpBufEnd )
              return;
            v9 += v242;
            if ( ((unsigned __int8)tmp_pbDst & 1) == WorldBoolFlag )
            {
              v243 = v242 >> 1;
              if ( !(v242 & 1) )
                goto LABEL_378;
              ++tmp_pbDst;
              if ( v243 )
              {
LABEL_385:
                v23 = v243 & 1;
                v246 = v243 >> 1;
                if ( !v23 || (*tmp_pbDst = 0, tmp_pbDst += 2, v246) )
                {
                  do
                  {
                    *tmp_pbDst = 0;
                    tmp_pbDst[2] = 0;
                    tmp_pbDst += 4;
                    --v246;
                  }
                  while ( v246 );
                }
                goto LABEL_388;
              }
            }
            else
            {
              v243 = v242 >> 1;
              if ( !(v242 & 1) )
                goto LABEL_385;
              *tmp_pbDst++ = 0;
              if ( v243 )
              {
LABEL_378:
                v23 = v243 & 1;
                v244 = v243 >> 1;
                if ( !v23 || (v245 = tmp_pbDst + 1, *v245 = 0, tmp_pbDst = v245 + 1, v244) )
                {
                  do
                  {
                    tmp_pbDst[1] = 0;
                    tmp_pbDst[3] = 0;
                    tmp_pbDst += 4;
                    --v244;
                  }
                  while ( v244 );
                }
                goto LABEL_388;
              }
            }
LABEL_388:
            if ( !v241 )
              goto LABEL_391;
          }
          LOBYTE(v242) = -(char)v242;
          tmp_pbDst += v242;
          v241 -= v242;
        }
        while ( v241 );
LABEL_391:
        WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
        tmp_pbDst -= 800;
        if ( !--v240 )
          return;
      }
    case 2:
      WorldBoolFlag = 0;
      for ( ii = 30; ; ii -= 2 )
      {
        if ( tmp_pbDst < gpBufEnd )
          return;
        v248 = &tmp_pbDst[ii];
        v249 = 32 - ii;
        WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
        if ( WorldBoolFlag )
        {
          v23 = __CFSHR__(v249, 2);
          v250 = v249 >> 2;
          if ( !v23 || (v251 = v248 + 1, *v251 = 0, v248 = v251 + 1, v250) )
          {
            do
            {
              v248[1] = 0;
              v248[3] = 0;
              v248 += 4;
              --v250;
            }
            while ( v250 );
          }
        }
        else
        {
          v23 = __CFSHR__(v249, 2);
          v252 = v249 >> 2;
          if ( !v23 || (*v248 = 0, v248 += 2, v252) )
          {
            do
            {
              *v248 = 0;
              v248[2] = 0;
              v248 += 4;
              --v252;
            }
            while ( v252 );
          }
        }
        tmp_pbDst = v248 - 800;
        if ( !ii )
          break;
      }
      v253 = 2;
      do
      {
        if ( tmp_pbDst < gpBufEnd )
          break;
        v254 = &tmp_pbDst[v253];
        v255 = 32 - v253;
        WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
        if ( WorldBoolFlag )
        {
          v23 = __CFSHR__(v255, 2);
          v256 = v255 >> 2;
          if ( !v23 || (v257 = v254 + 1, *v257 = 0, v254 = v257 + 1, v256) )
          {
            do
            {
              v254[1] = 0;
              v254[3] = 0;
              v254 += 4;
              --v256;
            }
            while ( v256 );
          }
        }
        else
        {
          v23 = __CFSHR__(v255, 2);
          v258 = v255 >> 2;
          if ( !v23 || (*v254 = 0, v254 += 2, v258) )
          {
            do
            {
              *v254 = 0;
              v254[2] = 0;
              v254 += 4;
              --v258;
            }
            while ( v258 );
          }
        }
        tmp_pbDst = v254 - 800;
        v253 += 2;
      }
      while ( v253 != 32 );
      break;
    case 3:
      WorldBoolFlag = 0;
      for ( jj = 30; ; jj -= 2 )
      {
        if ( tmp_pbDst < gpBufEnd )
          return;
        v260 = 32 - jj;
        WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
        if ( WorldBoolFlag )
        {
          v23 = __CFSHR__(v260, 2);
          v261 = v260 >> 2;
          if ( !v23 || (v262 = tmp_pbDst + 1, *v262 = 0, tmp_pbDst = v262 + 1, v261) )
          {
            do
            {
              tmp_pbDst[1] = 0;
              tmp_pbDst[3] = 0;
              tmp_pbDst += 4;
              --v261;
            }
            while ( v261 );
          }
        }
        else
        {
          v23 = __CFSHR__(v260, 2);
          v263 = v260 >> 2;
          if ( !v23 || (*tmp_pbDst = 0, tmp_pbDst += 2, v263) )
          {
            do
            {
              *tmp_pbDst = 0;
              tmp_pbDst[2] = 0;
              tmp_pbDst += 4;
              --v263;
            }
            while ( v263 );
          }
        }
        v264 = tmp_pbDst - 800;
        if ( !jj )
          break;
        tmp_pbDst = &v264[jj];
      }
      v265 = 2;
      do
      {
        if ( v264 < gpBufEnd )
          break;
        v266 = 32 - v265;
        WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
        if ( WorldBoolFlag )
        {
          v23 = __CFSHR__(v266, 2);
          v267 = v266 >> 2;
          if ( !v23 || (v268 = v264 + 1, *v268 = 0, v264 = v268 + 1, v267) )
          {
            do
            {
              v264[1] = 0;
              v264[3] = 0;
              v264 += 4;
              --v267;
            }
            while ( v267 );
          }
        }
        else
        {
          v23 = __CFSHR__(v266, 2);
          v269 = v266 >> 2;
          if ( !v23 || (*v264 = 0, v264 += 2, v269) )
          {
            do
            {
              *v264 = 0;
              v264[2] = 0;
              v264 += 4;
              --v269;
            }
            while ( v269 );
          }
        }
        v264 = &v264[v265 - 800];
        v265 += 2;
      }
      while ( v265 != 32 );
      break;
    case 4:
      WorldBoolFlag = 0;
      for ( kk = 30; ; kk -= 2 )
      {
        if ( tmp_pbDst < gpBufEnd )
          return;
        v271 = &tmp_pbDst[kk];
        v272 = 32 - kk;
        WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
        if ( WorldBoolFlag )
        {
          v23 = __CFSHR__(v272, 2);
          v273 = v272 >> 2;
          if ( !v23 || (v274 = v271 + 1, *v274 = 0, v271 = v274 + 1, v273) )
          {
            do
            {
              v271[1] = 0;
              v271[3] = 0;
              v271 += 4;
              --v273;
            }
            while ( v273 );
          }
        }
        else
        {
          v23 = __CFSHR__(v272, 2);
          v275 = v272 >> 2;
          if ( !v23 || (*v271 = 0, v271 += 2, v275) )
          {
            do
            {
              *v271 = 0;
              v271[2] = 0;
              v271 += 4;
              --v275;
            }
            while ( v275 );
          }
        }
        tmp_pbDst = v271 - 800;
        if ( !kk )
          break;
      }
      v276 = 8;
      do
      {
        if ( tmp_pbDst < gpBufEnd )
          break;
        v277 = 8;
        do
        {
          tmp_pbDst[1] = 0;
          tmp_pbDst[3] = 0;
          tmp_pbDst += 4;
          --v277;
        }
        while ( v277 );
        v278 = tmp_pbDst - 800;
        if ( v278 < gpBufEnd )
          break;
        v279 = 8;
        do
        {
          *v278 = 0;
          v278[2] = 0;
          v278 += 4;
          --v279;
        }
        while ( v279 );
        tmp_pbDst = v278 - 800;
        --v276;
      }
      while ( v276 );
      break;
    default:
      WorldBoolFlag = 0;
      for ( ll = 30; ; ll -= 2 )
      {
        if ( tmp_pbDst < gpBufEnd )
          return;
        v281 = 32 - ll;
        WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
        if ( WorldBoolFlag )
        {
          v23 = __CFSHR__(v281, 2);
          v282 = v281 >> 2;
          if ( !v23 || (v283 = tmp_pbDst + 1, *v283 = 0, tmp_pbDst = v283 + 1, v282) )
          {
            do
            {
              tmp_pbDst[1] = 0;
              tmp_pbDst[3] = 0;
              tmp_pbDst += 4;
              --v282;
            }
            while ( v282 );
          }
        }
        else
        {
          v23 = __CFSHR__(v281, 2);
          v284 = v281 >> 2;
          if ( !v23 || (*tmp_pbDst = 0, tmp_pbDst += 2, v284) )
          {
            do
            {
              *tmp_pbDst = 0;
              tmp_pbDst[2] = 0;
              tmp_pbDst += 4;
              --v284;
            }
            while ( v284 );
          }
        }
        v285 = tmp_pbDst - 800;
        if ( !ll )
          break;
        tmp_pbDst = &v285[ll];
      }
      v286 = 8;
      do
      {
        if ( v285 < gpBufEnd )
          break;
        v287 = 8;
        do
        {
          v285[1] = 0;
          v285[3] = 0;
          v285 += 4;
          --v287;
        }
        while ( v287 );
        v288 = v285 - 800;
        if ( v288 < gpBufEnd )
          break;
        v289 = 8;
        do
        {
          *v288 = 0;
          v288[2] = 0;
          v288 += 4;
          --v289;
        }
        while ( v289 );
        v285 = v288 - 800;
        --v286;
      }
      while ( v286 );
      break;
  }
}

//----- (004A1AB9) --------------------------------------------------------
void __fastcall drawBottomArchesUpperScreen(unsigned __int8 *pbDst, unsigned int *pMask)
{
  unsigned __int8 *tmp_pbDst; // edi
  char *pdung_cels2; // esi
  __int16 v5; // ax
  unsigned __int8 *pdung_cels; // esi
  __int16 v7; // ax
  unsigned int v8; // eax
  unsigned __int8 *v9; // esi
  unsigned int v10; // eax
  int v11; // eax
  int v12; // edx
  unsigned int v13; // edx
  signed int v14; // ecx
  unsigned __int8 v16; // cf
  int v18; // ecx
  signed int v19; // edx
  int v20; // eax
  int v21; // edx
  int v22; // ecx
  int v23; // edx
  signed int v26; // edx
  unsigned __int8 *v27; // edi
  unsigned int v28; // ecx
  unsigned __int8 v31; // of
  signed int v32; // edx
  unsigned __int8 *v33; // edi
  unsigned int v34; // ecx
  signed int v37; // edx
  unsigned int l; // ecx
  signed int v41; // edx
  unsigned int m; // ecx
  signed int v45; // edx
  unsigned __int8 *v46; // edi
  unsigned int v47; // ecx
  int v50; // edx
  unsigned int v51; // edx
  signed int v52; // ecx
  signed int v55; // edx
  unsigned int n; // ecx
  int v59; // edx
  unsigned int v60; // edx
  signed int v61; // ecx
  int v64; // edx
  unsigned int v65; // edx
  signed int v66; // ecx
  unsigned __int8 v67; // al
  int v68; // ecx
  signed int v69; // edx
  int v70; // eax
  int v71; // edx
  int v72; // edx
  int v73; // ecx
  unsigned __int8 v74; // al
  signed int v75; // edx
  unsigned __int8 *v76; // edi
  unsigned int v77; // ecx
  __int16 v78; // ax
  int v79; // eax
  signed int v80; // edx
  unsigned __int8 *v81; // edi
  unsigned int v82; // ecx
  __int16 v83; // ax
  int v84; // eax
  signed int v85; // edx
  unsigned int i; // ecx
  int v87; // eax
  __int16 v88; // ax
  signed int v89; // edx
  unsigned int j; // ecx
  int v91; // eax
  __int16 v92; // ax
  signed int v93; // edx
  unsigned __int8 *v94; // edi
  unsigned int v95; // ecx
  __int16 v96; // ax
  int v97; // eax
  int v98; // edx
  unsigned int v99; // edx
  signed int v100; // ecx
  unsigned __int8 v101; // al
  signed int v102; // edx
  unsigned int k; // ecx
  int v104; // eax
  __int16 v105; // ax
  int v106; // edx
  unsigned int v107; // edx
  signed int v108; // ecx
  unsigned __int8 v109; // al
  int v110; // edx
  unsigned int v111; // edx
  signed int v112; // ecx
  int v113; // ecx
  signed int v114; // edx
  int v115; // eax
  int v116; // edx
  int v117; // edx
  int v118; // ecx
  signed int v119; // edx
  unsigned __int8 *v120; // edi
  unsigned int v121; // ecx
  signed int v122; // edx
  unsigned __int8 *v123; // edi
  unsigned int v124; // ecx
  signed int v125; // edx
  unsigned int v126; // ecx
  unsigned __int8 *v127; // edi
  signed int v128; // edx
  unsigned int v129; // ecx
  signed int v130; // edx
  unsigned __int8 *v131; // edi
  unsigned int v132; // ecx
  int v133; // edx
  unsigned int v134; // edx
  signed int v135; // ecx
  signed int v136; // edx
  unsigned int v137; // ecx
  unsigned __int8 *v138; // edi
  int v139; // edx
  unsigned int v140; // edx
  signed int v141; // ecx
  int v142; // [esp-8h] [ebp-14h]
  int v143; // [esp-8h] [ebp-14h]
  int v144; // [esp-8h] [ebp-14h]
  int v145; // [esp-8h] [ebp-14h]
  int v146; // [esp-8h] [ebp-14h]
  int v147; // [esp-4h] [ebp-10h]
  int v148; // [esp-4h] [ebp-10h]
  int v149; // [esp-4h] [ebp-10h]
  int v150; // [esp-4h] [ebp-10h]
  int v151; // [esp-4h] [ebp-10h]
  int v152; // [esp-4h] [ebp-10h]
  int v153; // [esp-4h] [ebp-10h]
  int v154; // [esp-4h] [ebp-10h]
  int v155; // [esp-4h] [ebp-10h]
  int v156; // [esp-4h] [ebp-10h]

  gpCelFrame = (unsigned __int8 *)speed_cel_frame_num_from_light_index_frame_num;
  tmp_pbDst = pbDst;
  gpDrawMask = pMask;
  if ( !(_BYTE)light_table_index )
  {
    if ( level_cel_block & 0x8000 )
      level_cel_block = *(_DWORD *)&gpCelFrame[64 * (level_cel_block & 0xFFF)]
                      + (unsigned __int16)(level_cel_block & 0xF000);
    pdung_cels = (unsigned __int8 *)pDungeonCels + *((_DWORD *)pDungeonCels + (level_cel_block & 0xFFF));
    v8 = level_cel_block;
    LOBYTE(v8) = BYTE1(v8);
    v7 = ((v8 >> 4) & 7) + 8;
LABEL_12:
    switch ( v7 )
    {
      case 8:
        v64 = 32;
        do
        {
          if ( tmp_pbDst < gpBufEnd )
            break;
          v150 = v64;
          v65 = *gpDrawMask;
          v66 = 32;
          do
          {
            v67 = *pdung_cels++;
            v16 = __CFSHL__(v65, 1);
            v65 *= 2;
            if ( v16 )
              *tmp_pbDst = v67;
            ++tmp_pbDst;
            --v66;
          }
          while ( v66 );
          tmp_pbDst -= 800;
          --gpDrawMask;
          v64 = v150 - 1;
        }
        while ( v150 != 1 );
        break;
      case 9:
        v68 = 32;
        do
        {
          v151 = v68;
          gdwCurrentMask = *gpDrawMask;
          v69 = 32;
          do
          {
            while ( 1 )
            {
              v70 = *pdung_cels++;
              if ( (v70 & 0x80u) == 0 )
                break;
              LOBYTE(v70) = -(char)v70;
              tmp_pbDst += v70;
              if ( v70 & 0x1F )
                gdwCurrentMask <<= v70 & 0x1F;
              v69 -= v70;
              if ( !v69 )
                goto LABEL_129;
            }
            v71 = v69 - v70;
            if ( tmp_pbDst < gpBufEnd )
              return;
            v144 = v71;
            v72 = gdwCurrentMask;
            v73 = v70;
            do
            {
              v74 = *pdung_cels++;
              v16 = __CFSHL__(v72, 1);
              v72 *= 2;
              if ( v16 )
                *tmp_pbDst = v74;
              ++tmp_pbDst;
              --v73;
            }
            while ( v73 );
            gdwCurrentMask = v72;
            v69 = v144;
          }
          while ( v144 );
LABEL_129:
          tmp_pbDst -= 800;
          --gpDrawMask;
          v68 = v151 - 1;
        }
        while ( v151 != 1 );
        break;
      case 10:
        v75 = 30;
        while ( tmp_pbDst >= gpBufEnd )
        {
          v76 = &tmp_pbDst[v75];
          v77 = (unsigned int)(32 - v75) >> 2;
          if ( !__CFSHR__(32 - v75, 2)
            || (v78 = *((_WORD *)pdung_cels + 1), pdung_cels += 4, *(_WORD *)v76 = v78, v76 += 2, v77) )
          {
            do
            {
              v79 = *(_DWORD *)pdung_cels;
              pdung_cels += 4;
              *(_DWORD *)v76 = v79;
              --v77;
              v76 += 4;
            }
            while ( v77 );
          }
          tmp_pbDst = v76 - 800;
          v31 = __OFSUB__(v75, 2);
          v75 -= 2;
          if ( (v75 < 0) ^ v31 )
          {
            v80 = 2;
            do
            {
              if ( tmp_pbDst < gpBufEnd )
                break;
              v81 = &tmp_pbDst[v80];
              v82 = (unsigned int)(32 - v80) >> 2;
              if ( __CFSHR__(32 - v80, 2) )
              {
                v83 = *((_WORD *)pdung_cels + 1);
                pdung_cels += 4;
                *(_WORD *)v81 = v83;
                v81 += 2;
                if ( !v82 )
                  continue;
              }
              do
              {
                v84 = *(_DWORD *)pdung_cels;
                pdung_cels += 4;
                *(_DWORD *)v81 = v84;
                v81 += 4;
                --v82;
              }
              while ( v82 );
              tmp_pbDst = v81 - 800;
              v80 += 2;
            }
            while ( v80 != 32 );
            return;
          }
        }
        break;
      case 11:
        v85 = 30;
        while ( tmp_pbDst >= gpBufEnd )
        {
          for ( i = (unsigned int)(32 - v85) >> 2; i; --i )
          {
            v87 = *(_DWORD *)pdung_cels;
            pdung_cels += 4;
            *(_DWORD *)tmp_pbDst = v87;
            tmp_pbDst += 4;
          }
          if ( (32 - (_BYTE)v85) & 2 )
          {
            v88 = *(_WORD *)pdung_cels;
            pdung_cels += 4;
            *(_WORD *)tmp_pbDst = v88;
            tmp_pbDst += 2;
          }
          tmp_pbDst = &tmp_pbDst[v85 - 800];
          v31 = __OFSUB__(v85, 2);
          v85 -= 2;
          if ( (v85 < 0) ^ v31 )
          {
            v89 = 2;
            do
            {
              if ( tmp_pbDst < gpBufEnd )
                break;
              for ( j = (unsigned int)(32 - v89) >> 2; j; --j )
              {
                v91 = *(_DWORD *)pdung_cels;
                pdung_cels += 4;
                *(_DWORD *)tmp_pbDst = v91;
                tmp_pbDst += 4;
              }
              if ( (32 - (_BYTE)v89) & 2 )
              {
                v92 = *(_WORD *)pdung_cels;
                pdung_cels += 4;
                *(_WORD *)tmp_pbDst = v92;
                tmp_pbDst += 2;
              }
              tmp_pbDst = &tmp_pbDst[v89 - 800];
              v89 += 2;
            }
            while ( v89 != 32 );
            return;
          }
        }
        break;
      case 12:
        v93 = 30;
        while ( tmp_pbDst >= gpBufEnd )
        {
          v94 = &tmp_pbDst[v93];
          v95 = (unsigned int)(32 - v93) >> 2;
          if ( !__CFSHR__(32 - v93, 2)
            || (v96 = *((_WORD *)pdung_cels + 1), pdung_cels += 4, *(_WORD *)v94 = v96, v94 += 2, v95) )
          {
            do
            {
              v97 = *(_DWORD *)pdung_cels;
              pdung_cels += 4;
              *(_DWORD *)v94 = v97;
              v94 += 4;
              --v95;
            }
            while ( v95 );
          }
          tmp_pbDst = v94 - 800;
          v31 = __OFSUB__(v93, 2);
          v93 -= 2;
          if ( (v93 < 0) ^ v31 )
          {
            gpDrawMask -= 16;
            v98 = 16;
            do
            {
              if ( tmp_pbDst < gpBufEnd )
                break;
              v152 = v98;
              v99 = *gpDrawMask;
              v100 = 32;
              do
              {
                v101 = *pdung_cels++;
                v16 = __CFSHL__(v99, 1);
                v99 *= 2;
                if ( v16 )
                  *tmp_pbDst = v101;
                ++tmp_pbDst;
                --v100;
              }
              while ( v100 );
              tmp_pbDst -= 800;
              --gpDrawMask;
              v98 = v152 - 1;
            }
            while ( v152 != 1 );
            return;
          }
        }
        break;
      default:
        v102 = 30;
        while ( tmp_pbDst >= gpBufEnd )
        {
          for ( k = (unsigned int)(32 - v102) >> 2; k; --k )
          {
            v104 = *(_DWORD *)pdung_cels;
            pdung_cels += 4;
            *(_DWORD *)tmp_pbDst = v104;
            tmp_pbDst += 4;
          }
          if ( (32 - (_BYTE)v102) & 2 )
          {
            v105 = *(_WORD *)pdung_cels;
            pdung_cels += 4;
            *(_WORD *)tmp_pbDst = v105;
            tmp_pbDst += 2;
          }
          tmp_pbDst = &tmp_pbDst[v102 - 800];
          v31 = __OFSUB__(v102, 2);
          v102 -= 2;
          if ( (v102 < 0) ^ v31 )
          {
            gpDrawMask -= 16;
            v106 = 16;
            do
            {
              if ( tmp_pbDst < gpBufEnd )
                break;
              v145 = v106;
              v107 = *gpDrawMask;
              v108 = 32;
              do
              {
                v109 = *pdung_cels++;
                v16 = __CFSHL__(v107, 1);
                v107 *= 2;
                if ( v16 )
                  *tmp_pbDst = v109;
                ++tmp_pbDst;
                --v108;
              }
              while ( v108 );
              pdung_cels += (unsigned __int8)pdung_cels & 2;
              tmp_pbDst -= 800;
              --gpDrawMask;
              v106 = v145 - 1;
            }
            while ( v145 != 1 );
            return;
          }
        }
        break;
    }
    return;
  }
  if ( (_BYTE)light_table_index != lightmax )
  {
    if ( !(level_cel_block & 0x8000) )
    {
      pdung_cels2 = (char *)pDungeonCels + *((_DWORD *)pDungeonCels + (level_cel_block & 0xFFF));
      _EBX = &pLightTbl[256 * light_table_index];
      v5 = (unsigned __int8)(BYTE1(level_cel_block) >> 4);
      if ( !(BYTE1(level_cel_block) >> 4) )
      {
        v12 = 32;
        do
        {
          if ( tmp_pbDst < gpBufEnd )
            break;
          v147 = v12;
          v13 = *gpDrawMask;
          v14 = 32;
          do
          {
            _AL = *pdung_cels2++;
            v16 = __CFSHL__(v13, 1);
            v13 *= 2;
            if ( v16 )
            {
              ASM_XLAT();
              *tmp_pbDst = _AL;
            }
            ++tmp_pbDst;
            --v14;
          }
          while ( v14 );
          tmp_pbDst -= 800;
          --gpDrawMask;
          v12 = v147 - 1;
        }
        while ( v147 != 1 );
        return;
      }
      if ( BYTE1(level_cel_block) >> 4 )
      {
        switch ( v5 )
        {
          case 1:
            v18 = 32;
            do
            {
              v148 = v18;
              gdwCurrentMask = *gpDrawMask;
              v19 = 32;
              do
              {
                while ( 1 )
                {
                  v20 = (unsigned __int8)*pdung_cels2++;
                  if ( (v20 & 0x80u) == 0 )
                    break;
                  LOBYTE(v20) = -(char)v20;
                  tmp_pbDst += v20;
                  if ( v20 & 0x1F )
                    gdwCurrentMask <<= v20 & 0x1F;
                  v19 -= v20;
                  if ( !v19 )
                    goto LABEL_50;
                }
                v21 = v19 - v20;
                if ( tmp_pbDst < gpBufEnd )
                  return;
                v22 = v20;
                v142 = v21;
                v23 = gdwCurrentMask;
                do
                {
                  _AL = *pdung_cels2++;
                  v16 = __CFSHL__(v23, 1);
                  v23 *= 2;
                  if ( v16 )
                  {
                    ASM_XLAT();
                    *tmp_pbDst = _AL;
                  }
                  ++tmp_pbDst;
                  --v22;
                }
                while ( v22 );
                gdwCurrentMask = v23;
                v19 = v142;
              }
              while ( v142 );
LABEL_50:
              tmp_pbDst -= 800;
              --gpDrawMask;
              v18 = v148 - 1;
            }
            while ( v148 != 1 );
            break;
          case 2:
            v26 = 30;
            while ( tmp_pbDst >= gpBufEnd )
            {
              v27 = &tmp_pbDst[v26];
              v28 = (unsigned int)(32 - v26) >> 2;
              if ( !__CFSHR__(32 - v26, 2) )
                goto LABEL_268;
              _AX = *((_WORD *)pdung_cels2 + 1);
              pdung_cels2 += 4;
              ASM_XLAT();
              _AX = __ROR2__(_AX, 8);
              ASM_XLAT();
              *(_WORD *)v27 = __ROR2__(_AX, 8);
              v27 += 2;
              if ( v28 )
              {
LABEL_268:
                do
                {
                  _EAX = *(_DWORD *)pdung_cels2;
                  pdung_cels2 += 4;
                  ASM_XLAT();
                  _EAX = __ROR4__(_EAX, 8);
                  ASM_XLAT();
                  _EAX = __ROR4__(_EAX, 8);
                  ASM_XLAT();
                  _EAX = __ROR4__(_EAX, 8);
                  ASM_XLAT();
                  *(_DWORD *)v27 = __ROR4__(_EAX, 8);
                  v27 += 4;
                  --v28;
                }
                while ( v28 );
              }
              tmp_pbDst = v27 - 800;
              v31 = __OFSUB__(v26, 2);
              v26 -= 2;
              if ( (v26 < 0) ^ v31 )
              {
                v32 = 2;
                do
                {
                  if ( tmp_pbDst < gpBufEnd )
                    break;
                  v33 = &tmp_pbDst[v32];
                  v34 = (unsigned int)(32 - v32) >> 2;
                  if ( !__CFSHR__(32 - v32, 2) )
                    goto LABEL_269;
                  _AX = *((_WORD *)pdung_cels2 + 1);
                  pdung_cels2 += 4;
                  ASM_XLAT();
                  _AX = __ROR2__(_AX, 8);
                  ASM_XLAT();
                  *(_WORD *)v33 = __ROR2__(_AX, 8);
                  v33 += 2;
                  if ( v34 )
                  {
LABEL_269:
                    do
                    {
                      _EAX = *(_DWORD *)pdung_cels2;
                      pdung_cels2 += 4;
                      ASM_XLAT();
                      _EAX = __ROR4__(_EAX, 8);
                      ASM_XLAT();
                      _EAX = __ROR4__(_EAX, 8);
                      ASM_XLAT();
                      _EAX = __ROR4__(_EAX, 8);
                      ASM_XLAT();
                      *(_DWORD *)v33 = __ROR4__(_EAX, 8);
                      v33 += 4;
                      --v34;
                    }
                    while ( v34 );
                  }
                  tmp_pbDst = v33 - 800;
                  v32 += 2;
                }
                while ( v32 != 32 );
                return;
              }
            }
            break;
          case 3:
            v37 = 30;
            while ( tmp_pbDst >= gpBufEnd )
            {
              for ( l = (unsigned int)(32 - v37) >> 2; l; --l )
              {
                _EAX = *(_DWORD *)pdung_cels2;
                pdung_cels2 += 4;
                ASM_XLAT();
                _EAX = __ROR4__(_EAX, 8);
                ASM_XLAT();
                _EAX = __ROR4__(_EAX, 8);
                ASM_XLAT();
                _EAX = __ROR4__(_EAX, 8);
                ASM_XLAT();
                *(_DWORD *)tmp_pbDst = __ROR4__(_EAX, 8);
                tmp_pbDst += 4;
              }
              if ( (32 - (_BYTE)v37) & 2 )
              {
                _AX = *(_WORD *)pdung_cels2;
                pdung_cels2 += 4;
                ASM_XLAT();
                _AX = __ROR2__(_AX, 8);
                ASM_XLAT();
                *(_WORD *)tmp_pbDst = __ROR2__(_AX, 8);
                tmp_pbDst += 2;
              }
              tmp_pbDst = &tmp_pbDst[v37 - 800];
              v31 = __OFSUB__(v37, 2);
              v37 -= 2;
              if ( (v37 < 0) ^ v31 )
              {
                v41 = 2;
                do
                {
                  if ( tmp_pbDst < gpBufEnd )
                    break;
                  for ( m = (unsigned int)(32 - v41) >> 2; m; --m )
                  {
                    _EAX = *(_DWORD *)pdung_cels2;
                    pdung_cels2 += 4;
                    ASM_XLAT();
                    _EAX = __ROR4__(_EAX, 8);
                    ASM_XLAT();
                    _EAX = __ROR4__(_EAX, 8);
                    ASM_XLAT();
                    _EAX = __ROR4__(_EAX, 8);
                    ASM_XLAT();
                    *(_DWORD *)tmp_pbDst = __ROR4__(_EAX, 8);
                    tmp_pbDst += 4;
                  }
                  if ( (32 - (_BYTE)v41) & 2 )
                  {
                    _AX = *(_WORD *)pdung_cels2;
                    pdung_cels2 += 4;
                    ASM_XLAT();
                    _AX = __ROR2__(_AX, 8);
                    ASM_XLAT();
                    *(_WORD *)tmp_pbDst = __ROR2__(_AX, 8);
                    tmp_pbDst += 2;
                  }
                  tmp_pbDst = &tmp_pbDst[v41 - 800];
                  v41 += 2;
                }
                while ( v41 != 32 );
                return;
              }
            }
            break;
          case 4:
            v45 = 30;
            while ( tmp_pbDst >= gpBufEnd )
            {
              v46 = &tmp_pbDst[v45];
              v47 = (unsigned int)(32 - v45) >> 2;
              if ( !__CFSHR__(32 - v45, 2) )
                goto LABEL_270;
              _AX = *((_WORD *)pdung_cels2 + 1);
              pdung_cels2 += 4;
              ASM_XLAT();
              _AX = __ROR2__(_AX, 8);
              ASM_XLAT();
              *(_WORD *)v46 = __ROR2__(_AX, 8);
              v46 += 2;
              if ( v47 )
              {
LABEL_270:
                do
                {
                  _EAX = *(_DWORD *)pdung_cels2;
                  pdung_cels2 += 4;
                  ASM_XLAT();
                  _EAX = __ROR4__(_EAX, 8);
                  ASM_XLAT();
                  _EAX = __ROR4__(_EAX, 8);
                  ASM_XLAT();
                  _EAX = __ROR4__(_EAX, 8);
                  ASM_XLAT();
                  *(_DWORD *)v46 = __ROR4__(_EAX, 8);
                  v46 += 4;
                  --v47;
                }
                while ( v47 );
              }
              tmp_pbDst = v46 - 800;
              v31 = __OFSUB__(v45, 2);
              v45 -= 2;
              if ( (v45 < 0) ^ v31 )
              {
                gpDrawMask -= 16;
                v50 = 16;
                do
                {
                  if ( tmp_pbDst < gpBufEnd )
                    break;
                  v149 = v50;
                  v51 = *gpDrawMask;
                  v52 = 32;
                  pdung_cels2 += (unsigned __int8)pdung_cels2 & 2;
                  do
                  {
                    _AL = *pdung_cels2++;
                    v16 = __CFSHL__(v51, 1);
                    v51 *= 2;
                    if ( v16 )
                    {
                      ASM_XLAT();
                      *tmp_pbDst = _AL;
                    }
                    ++tmp_pbDst;
                    --v52;
                  }
                  while ( v52 );
                  tmp_pbDst -= 800;
                  --gpDrawMask;
                  v50 = v149 - 1;
                }
                while ( v149 != 1 );
                return;
              }
            }
            break;
          default:
            v55 = 30;
            while ( tmp_pbDst >= gpBufEnd )
            {
              for ( n = (unsigned int)(32 - v55) >> 2; n; --n )
              {
                _EAX = *(_DWORD *)pdung_cels2;
                pdung_cels2 += 4;
                ASM_XLAT();
                _EAX = __ROR4__(_EAX, 8);
                ASM_XLAT();
                _EAX = __ROR4__(_EAX, 8);
                ASM_XLAT();
                _EAX = __ROR4__(_EAX, 8);
                ASM_XLAT();
                *(_DWORD *)tmp_pbDst = __ROR4__(_EAX, 8);
                tmp_pbDst += 4;
              }
              if ( (32 - (_BYTE)v55) & 2 )
              {
                _AX = *(_WORD *)pdung_cels2;
                pdung_cels2 += 4;
                ASM_XLAT();
                _AX = __ROR2__(_AX, 8);
                ASM_XLAT();
                *(_WORD *)tmp_pbDst = __ROR2__(_AX, 8);
                tmp_pbDst += 2;
              }
              tmp_pbDst = &tmp_pbDst[v55 - 800];
              v31 = __OFSUB__(v55, 2);
              v55 -= 2;
              if ( (v55 < 0) ^ v31 )
              {
                gpDrawMask -= 16;
                v59 = 16;
                do
                {
                  if ( tmp_pbDst < gpBufEnd )
                    break;
                  v143 = v59;
                  v60 = *gpDrawMask;
                  v61 = 32;
                  do
                  {
                    _AL = *pdung_cels2++;
                    v16 = __CFSHL__(v60, 1);
                    v60 *= 2;
                    if ( v16 )
                    {
                      ASM_XLAT();
                      *tmp_pbDst = _AL;
                    }
                    ++tmp_pbDst;
                    --v61;
                  }
                  while ( v61 );
                  pdung_cels2 += (unsigned __int8)pdung_cels2 & 2;
                  tmp_pbDst -= 800;
                  --gpDrawMask;
                  v59 = v143 - 1;
                }
                while ( v143 != 1 );
                return;
              }
            }
            break;
        }
        return;
      }
LABEL_187:
      v110 = 32;
      do
      {
        if ( tmp_pbDst < gpBufEnd )
          break;
        v153 = v110;
        v111 = *gpDrawMask;
        v112 = 32;
        do
        {
          v16 = __CFSHL__(v111, 1);
          v111 *= 2;
          if ( v16 )
            *tmp_pbDst = 0;
          ++tmp_pbDst;
          --v112;
        }
        while ( v112 );
        tmp_pbDst -= 800;
        --gpDrawMask;
        v110 = v153 - 1;
      }
      while ( v153 != 1 );
      return;
    }
    pdung_cels = (unsigned __int8 *)pSpeedCels
               + *(_DWORD *)&gpCelFrame[4 * (light_table_index + 16 * (level_cel_block & 0xFFF))];
    v7 = (unsigned __int8)(BYTE1(level_cel_block) >> 4);
    goto LABEL_12;
  }
  if ( level_cel_block & 0x8000 )
    level_cel_block = *(_DWORD *)&gpCelFrame[64 * (level_cel_block & 0xFFF)]
                    + (unsigned __int16)(level_cel_block & 0xF000);
  v9 = (unsigned __int8 *)pDungeonCels + *((_DWORD *)pDungeonCels + (level_cel_block & 0xFFF));
  v10 = level_cel_block;
  LOBYTE(v10) = BYTE1(v10);
  v11 = (v10 >> 4) & 7;
  if ( !v11 )
    goto LABEL_187;
  switch ( (_WORD)v11 )
  {
    case 1:
      v113 = 32;
      do
      {
        v154 = v113;
        gdwCurrentMask = *gpDrawMask;
        v114 = 32;
        do
        {
          while ( 1 )
          {
            v115 = *v9++;
            if ( (v115 & 0x80u) == 0 )
              break;
            LOBYTE(v115) = -(char)v115;
            tmp_pbDst += v115;
            if ( v115 & 0x1F )
              gdwCurrentMask <<= v115 & 0x1F;
            v114 -= v115;
            if ( !v114 )
              goto LABEL_208;
          }
          v116 = v114 - v115;
          if ( tmp_pbDst < gpBufEnd )
            return;
          v146 = v116;
          v117 = gdwCurrentMask;
          v118 = v115;
          v9 += v115;
          do
          {
            v16 = __CFSHL__(v117, 1);
            v117 *= 2;
            if ( v16 )
              *tmp_pbDst = 0;
            ++tmp_pbDst;
            --v118;
          }
          while ( v118 );
          gdwCurrentMask = v117;
          v114 = v146;
        }
        while ( v146 );
LABEL_208:
        tmp_pbDst -= 800;
        --gpDrawMask;
        v113 = v154 - 1;
      }
      while ( v154 != 1 );
      break;
    case 2:
      v119 = 30;
      while ( tmp_pbDst >= gpBufEnd )
      {
        v120 = &tmp_pbDst[v119];
        v121 = (unsigned int)(32 - v119) >> 2;
        if ( !__CFSHR__(32 - v119, 2) || (*(_WORD *)v120 = 0, v120 += 2, v121) )
        {
          do
          {
            *(_DWORD *)v120 = 0;
            v120 += 4;
            --v121;
          }
          while ( v121 );
        }
        tmp_pbDst = v120 - 800;
        if ( !v119 )
        {
          v122 = 2;
          do
          {
            if ( tmp_pbDst < gpBufEnd )
              break;
            v123 = &tmp_pbDst[v122];
            v124 = (unsigned int)(32 - v122) >> 2;
            if ( __CFSHR__(32 - v122, 2) )
            {
              *(_WORD *)v123 = 0;
              v123 += 2;
              if ( !v124 )
                continue;
            }
            do
            {
              *(_DWORD *)v123 = 0;
              v123 += 4;
              --v124;
            }
            while ( v124 );
            tmp_pbDst = v123 - 800;
            v122 += 2;
          }
          while ( v122 != 32 );
          return;
        }
        v119 -= 2;
      }
      break;
    case 3:
      v125 = 30;
      while ( tmp_pbDst >= gpBufEnd )
      {
        v126 = (unsigned int)(32 - v125) >> 2;
        if ( !__CFSHR__(32 - v125, 2) || (*(_WORD *)tmp_pbDst = 0, tmp_pbDst += 2, v126) )
        {
          do
          {
            *(_DWORD *)tmp_pbDst = 0;
            tmp_pbDst += 4;
            --v126;
          }
          while ( v126 );
        }
        v127 = tmp_pbDst - 800;
        if ( !v125 )
        {
          v128 = 2;
          do
          {
            if ( v127 < gpBufEnd )
              break;
            v129 = (unsigned int)(32 - v128) >> 2;
            if ( __CFSHR__(32 - v128, 2) )
            {
              *(_WORD *)v127 = 0;
              v127 += 2;
              if ( !v129 )
                continue;
            }
            do
            {
              *(_DWORD *)v127 = 0;
              v127 += 4;
              --v129;
            }
            while ( v129 );
            v127 = &v127[v128 - 800];
            v128 += 2;
          }
          while ( v128 != 32 );
          return;
        }
        tmp_pbDst = &v127[v125];
        v125 -= 2;
      }
      break;
    case 4:
      v130 = 30;
      while ( tmp_pbDst >= gpBufEnd )
      {
        v131 = &tmp_pbDst[v130];
        v132 = (unsigned int)(32 - v130) >> 2;
        if ( !__CFSHR__(32 - v130, 2) || (*(_WORD *)v131 = 0, v131 += 2, v132) )
        {
          do
          {
            *(_DWORD *)v131 = 0;
            v131 += 4;
            --v132;
          }
          while ( v132 );
        }
        tmp_pbDst = v131 - 800;
        if ( !v130 )
        {
          gpDrawMask -= 16;
          v133 = 16;
          do
          {
            if ( tmp_pbDst < gpBufEnd )
              break;
            v155 = v133;
            v134 = *gpDrawMask;
            v135 = 32;
            do
            {
              v16 = __CFSHL__(v134, 1);
              v134 *= 2;
              if ( v16 )
                *tmp_pbDst = 0;
              ++tmp_pbDst;
              --v135;
            }
            while ( v135 );
            tmp_pbDst -= 800;
            --gpDrawMask;
            v133 = v155 - 1;
          }
          while ( v155 != 1 );
          return;
        }
        v130 -= 2;
      }
      break;
    default:
      v136 = 30;
      while ( tmp_pbDst >= gpBufEnd )
      {
        v137 = (unsigned int)(32 - v136) >> 2;
        if ( !__CFSHR__(32 - v136, 2) || (*(_WORD *)tmp_pbDst = 0, tmp_pbDst += 2, v137) )
        {
          do
          {
            *(_DWORD *)tmp_pbDst = 0;
            tmp_pbDst += 4;
            --v137;
          }
          while ( v137 );
        }
        v138 = tmp_pbDst - 800;
        if ( !v136 )
        {
          gpDrawMask -= 16;
          v139 = 16;
          do
          {
            if ( v138 < gpBufEnd )
              break;
            v156 = v139;
            v140 = *gpDrawMask;
            v141 = 32;
            do
            {
              v16 = __CFSHL__(v140, 1);
              v140 *= 2;
              if ( v16 )
                *v138 = 0;
              ++v138;
              --v141;
            }
            while ( v141 );
            v138 -= 800;
            --gpDrawMask;
            v139 = v156 - 1;
          }
          while ( v156 != 1 );
          return;
        }
        tmp_pbDst = &v138[v136];
        v136 -= 2;
      }
      break;
  }
}

//----- (004A26F1) --------------------------------------------------------
void __fastcall drawUpperScreen(unsigned __int8 *pbDst)
{
  int v1; // edx
  char v2; // al
  char v3; // al
  unsigned __int8 *tmp_pbDst; // edi
  _BYTE *pdung_cels2; // esi
  BYTE *l_tbl; // ebx
  __int16 v7; // ax
  unsigned __int8 *pdung_cels; // esi
  __int16 v9; // ax
  unsigned int v10; // eax
  unsigned __int8 *pdung_cels3; // esi
  unsigned int v12; // eax
  int v13; // edx
  char v14; // cl
  int v15; // eax
  unsigned __int8 v16; // ch
  unsigned __int8 v17; // ch
  unsigned __int8 v18; // ch
  signed int v19; // ebp
  signed int v20; // edx
  int v21; // eax
  int v22; // edx
  char v23; // cl
  int v24; // eax
  unsigned __int8 v25; // ch
  unsigned __int8 v26; // ch
  unsigned __int8 v27; // ch
  signed int v28; // ebp
  unsigned __int8 *v29; // edi
  char v30; // cl
  int v31; // edx
  int v32; // eax
  BYTE v33; // ch
  BYTE v34; // ch
  BYTE v35; // ch
  unsigned __int8 v36; // of
  signed int v37; // ebp
  unsigned __int8 *v38; // edi
  char v39; // cl
  int v40; // edx
  int v41; // eax
  BYTE v42; // ch
  BYTE v43; // ch
  BYTE v44; // ch
  signed int v45; // ebp
  char m; // cl
  int v47; // eax
  unsigned __int8 v48; // ch
  unsigned __int8 v49; // ch
  unsigned __int8 v50; // ch
  signed int v51; // ebp
  char n; // cl
  int v53; // eax
  unsigned __int8 v54; // ch
  unsigned __int8 v55; // ch
  unsigned __int8 v56; // ch
  signed int v57; // ebp
  unsigned __int8 *v58; // edi
  char v59; // cl
  int v60; // edx
  int v61; // eax
  BYTE v62; // ch
  BYTE v63; // ch
  BYTE v64; // ch
  signed int v65; // ebp
  char v66; // cl
  int v67; // eax
  unsigned __int8 v68; // ch
  unsigned __int8 v69; // ch
  unsigned __int8 v70; // ch
  signed int v71; // ebp
  char ii; // cl
  int v73; // eax
  unsigned __int8 v74; // ch
  unsigned __int8 v75; // ch
  unsigned __int8 v76; // ch
  signed int v77; // ebp
  char v78; // cl
  int v79; // eax
  unsigned __int8 v80; // ch
  unsigned __int8 v81; // ch
  unsigned __int8 v82; // ch
  signed int v83; // edx
  signed int v84; // ecx
  int v85; // eax
  signed int v86; // ebp
  signed int v87; // edx
  unsigned int v88; // eax
  unsigned int v89; // ecx
  unsigned __int8 v90; // al
  char v91; // cf
  unsigned int v92; // ecx
  __int16 v93; // ax
  int v94; // eax
  signed int v95; // edx
  unsigned __int8 *v96; // edi
  unsigned int v97; // ecx
  __int16 v98; // ax
  int v99; // eax
  signed int v100; // edx
  unsigned __int8 *v101; // edi
  unsigned int v102; // ecx
  __int16 v103; // ax
  int v104; // eax
  signed int v105; // edx
  unsigned int i; // ecx
  int v107; // eax
  __int16 v108; // ax
  signed int v109; // edx
  unsigned int j; // ecx
  int v111; // eax
  __int16 v112; // ax
  signed int v113; // edx
  unsigned __int8 *v114; // edi
  unsigned int v115; // ecx
  __int16 v116; // ax
  int v117; // eax
  signed int v118; // edx
  signed int v119; // ecx
  int v120; // eax
  signed int v121; // edx
  unsigned int k; // ecx
  int v123; // eax
  __int16 v124; // ax
  signed int v125; // edx
  signed int v126; // ecx
  int v127; // eax
  signed int v128; // edx
  signed int v129; // ecx
  signed int v130; // ebp
  signed int v131; // edx
  unsigned int v132; // eax
  unsigned int v133; // ecx
  unsigned int v134; // ecx
  signed int v135; // edx
  unsigned __int8 *v136; // edi
  unsigned int v137; // ecx
  signed int v138; // edx
  unsigned __int8 *v139; // edi
  unsigned int v140; // ecx
  signed int v141; // edx
  unsigned int v142; // ecx
  unsigned __int8 *v143; // edi
  signed int v144; // edx
  unsigned int v145; // ecx
  signed int v146; // edx
  unsigned __int8 *v147; // edi
  unsigned int v148; // ecx
  signed int v149; // edx
  signed int v150; // ecx
  signed int v151; // edx
  unsigned int v152; // ecx
  unsigned __int8 *v153; // edi
  signed int v154; // edx
  signed int v155; // ecx
  int l; // [esp-14h] [ebp-18h]
  int v157; // [esp-10h] [ebp-14h]

  v1 = cel_transparency_active;
  if ( cel_transparency_active )
  {
    if ( !arch_draw_type )
    {
      drawTopArchesUpperScreen(pbDst);
      return;
    }
    if ( arch_draw_type == 1 )
    {
      v2 = block_lvid[level_piece_id];
      if ( v2 == 1 || v2 == 3 )
      {
        drawBottomArchesUpperScreen(pbDst, &LeftMask[31]);
        return;
      }
    }
    if ( arch_draw_type == 2 )
    {
      v3 = block_lvid[level_piece_id];
      if ( v3 == 2 || v3 == 3 )
      {
        drawBottomArchesUpperScreen(pbDst, &RightMask[31]);
        return;
      }
    }
  }
  gpCelFrame = (unsigned __int8 *)speed_cel_frame_num_from_light_index_frame_num;
  tmp_pbDst = pbDst;
  if ( !(_BYTE)light_table_index )
  {
    if ( level_cel_block & 0x8000 )
      level_cel_block = *(_DWORD *)&gpCelFrame[64 * (level_cel_block & 0xFFF)]
                      + (unsigned __int16)(level_cel_block & 0xF000);
    pdung_cels = (unsigned __int8 *)pDungeonCels + *((_DWORD *)pDungeonCels + (level_cel_block & 0xFFF));
    v10 = level_cel_block;
    LOBYTE(v10) = BYTE1(v10);
    v9 = ((v10 >> 4) & 7) + 8;
LABEL_22:
    switch ( v9 )
    {
      case 8:
        v83 = 32;
        do
        {
          if ( tmp_pbDst < gpBufEnd )
            break;
          v84 = 8;
          do
          {
            v85 = *(_DWORD *)pdung_cels;
            pdung_cels += 4;
            *(_DWORD *)tmp_pbDst = v85;
            tmp_pbDst += 4;
            --v84;
          }
          while ( v84 );
          tmp_pbDst -= 800;
          --v83;
        }
        while ( v83 );
        break;
      case 9:
        v86 = 32;
        do
        {
          v87 = 32;
          do
          {
            while ( 1 )
            {
              v88 = *pdung_cels++;
              if ( (v88 & 0x80u) == 0 )
                break;
              LOBYTE(v88) = -(char)v88;
              tmp_pbDst += v88;
              v87 -= v88;
              if ( !v87 )
                goto LABEL_133;
            }
            v87 -= v88;
            if ( tmp_pbDst < gpBufEnd )
              return;
            v89 = v88 >> 1;
            if ( v88 & 1 )
            {
              v90 = *pdung_cels++;
              *tmp_pbDst++ = v90;
              if ( !v89 )
                continue;
            }
            v91 = v89 & 1;
            v92 = v89 >> 1;
            if ( v91 )
            {
              v93 = *(_WORD *)pdung_cels;
              pdung_cels += 2;
              *(_WORD *)tmp_pbDst = v93;
              tmp_pbDst += 2;
              if ( !v92 )
                continue;
            }
            do
            {
              v94 = *(_DWORD *)pdung_cels;
              pdung_cels += 4;
              *(_DWORD *)tmp_pbDst = v94;
              tmp_pbDst += 4;
              --v92;
            }
            while ( v92 );
          }
          while ( v87 );
LABEL_133:
          tmp_pbDst -= 800;
          --v86;
        }
        while ( v86 );
        break;
      case 10:
        v95 = 30;
        while ( tmp_pbDst >= gpBufEnd )
        {
          v96 = &tmp_pbDst[v95];
          v97 = (unsigned int)(32 - v95) >> 2;
          if ( !__CFSHR__(32 - v95, 2)
            || (v98 = *((_WORD *)pdung_cels + 1), pdung_cels += 4, *(_WORD *)v96 = v98, v96 += 2, v97) )
          {
            do
            {
              v99 = *(_DWORD *)pdung_cels;
              pdung_cels += 4;
              *(_DWORD *)v96 = v99;
              v96 += 4;
              --v97;
            }
            while ( v97 );
          }
          tmp_pbDst = v96 - 800;
          v36 = __OFSUB__(v95, 2);
          v95 -= 2;
          if ( (v95 < 0) ^ v36 )
          {
            v100 = 2;
            do
            {
              if ( tmp_pbDst < gpBufEnd )
                break;
              v101 = &tmp_pbDst[v100];
              v102 = (unsigned int)(32 - v100) >> 2;
              if ( __CFSHR__(32 - v100, 2) )
              {
                v103 = *((_WORD *)pdung_cels + 1);
                pdung_cels += 4;
                *(_WORD *)v101 = v103;
                v101 += 2;
                if ( !v102 )
                  continue;
              }
              do
              {
                v104 = *(_DWORD *)pdung_cels;
                pdung_cels += 4;
                *(_DWORD *)v101 = v104;
                v101 += 4;
                --v102;
              }
              while ( v102 );
              tmp_pbDst = v101 - 800;
              v100 += 2;
            }
            while ( v100 != 32 );
            return;
          }
        }
        break;
      case 11:
        v105 = 30;
        while ( tmp_pbDst >= gpBufEnd )
        {
          for ( i = (unsigned int)(32 - v105) >> 2; i; --i )
          {
            v107 = *(_DWORD *)pdung_cels;
            pdung_cels += 4;
            *(_DWORD *)tmp_pbDst = v107;
            tmp_pbDst += 4;
          }
          if ( (32 - (_BYTE)v105) & 2 )
          {
            v108 = *(_WORD *)pdung_cels;
            pdung_cels += 4;
            *(_WORD *)tmp_pbDst = v108;
            tmp_pbDst += 2;
          }
          tmp_pbDst = &tmp_pbDst[v105 - 800];
          v36 = __OFSUB__(v105, 2);
          v105 -= 2;
          if ( (v105 < 0) ^ v36 )
          {
            v109 = 2;
            do
            {
              if ( tmp_pbDst < gpBufEnd )
                break;
              for ( j = (unsigned int)(32 - v109) >> 2; j; --j )
              {
                v111 = *(_DWORD *)pdung_cels;
                pdung_cels += 4;
                *(_DWORD *)tmp_pbDst = v111;
                tmp_pbDst += 4;
              }
              if ( (32 - (_BYTE)v109) & 2 )
              {
                v112 = *(_WORD *)pdung_cels;
                pdung_cels += 4;
                *(_WORD *)tmp_pbDst = v112;
                tmp_pbDst += 2;
              }
              tmp_pbDst = &tmp_pbDst[v109 - 800];
              v109 += 2;
            }
            while ( v109 != 32 );
            return;
          }
        }
        break;
      case 12:
        v113 = 30;
        while ( tmp_pbDst >= gpBufEnd )
        {
          v114 = &tmp_pbDst[v113];
          v115 = (unsigned int)(32 - v113) >> 2;
          if ( !__CFSHR__(32 - v113, 2)
            || (v116 = *((_WORD *)pdung_cels + 1), pdung_cels += 4, *(_WORD *)v114 = v116, v114 += 2, v115) )
          {
            do
            {
              v117 = *(_DWORD *)pdung_cels;
              pdung_cels += 4;
              *(_DWORD *)v114 = v117;
              v114 += 4;
              --v115;
            }
            while ( v115 );
          }
          tmp_pbDst = v114 - 800;
          v36 = __OFSUB__(v113, 2);
          v113 -= 2;
          if ( (v113 < 0) ^ v36 )
          {
            v118 = 16;
            do
            {
              if ( tmp_pbDst < gpBufEnd )
                break;
              v119 = 8;
              do
              {
                v120 = *(_DWORD *)pdung_cels;
                pdung_cels += 4;
                *(_DWORD *)tmp_pbDst = v120;
                tmp_pbDst += 4;
                --v119;
              }
              while ( v119 );
              tmp_pbDst -= 800;
              --v118;
            }
            while ( v118 );
            return;
          }
        }
        break;
      default:
        v121 = 30;
        while ( tmp_pbDst >= gpBufEnd )
        {
          for ( k = (unsigned int)(32 - v121) >> 2; k; --k )
          {
            v123 = *(_DWORD *)pdung_cels;
            pdung_cels += 4;
            *(_DWORD *)tmp_pbDst = v123;
            tmp_pbDst += 4;
          }
          if ( (32 - (_BYTE)v121) & 2 )
          {
            v124 = *(_WORD *)pdung_cels;
            pdung_cels += 4;
            *(_WORD *)tmp_pbDst = v124;
            tmp_pbDst += 2;
          }
          tmp_pbDst = &tmp_pbDst[v121 - 800];
          v36 = __OFSUB__(v121, 2);
          v121 -= 2;
          if ( (v121 < 0) ^ v36 )
          {
            v125 = 16;
            do
            {
              if ( tmp_pbDst < gpBufEnd )
                break;
              v126 = 8;
              do
              {
                v127 = *(_DWORD *)pdung_cels;
                pdung_cels += 4;
                *(_DWORD *)tmp_pbDst = v127;
                tmp_pbDst += 4;
                --v126;
              }
              while ( v126 );
              tmp_pbDst -= 800;
              --v125;
            }
            while ( v125 );
            return;
          }
        }
        break;
    }
    return;
  }
  if ( (_BYTE)light_table_index != lightmax )
  {
    if ( !(level_cel_block & 0x8000) )
    {
      pdung_cels2 = (char *)pDungeonCels + *((_DWORD *)pDungeonCels + (level_cel_block & 0xFFF));
      l_tbl = &pLightTbl[256 * light_table_index];
      v7 = (unsigned __int16)level_cel_block >> 12;
      if ( (unsigned __int16)level_cel_block >> 12 )
      {
        switch ( v7 )
        {
          case 1:
            v19 = 32;
            do
            {
              v20 = 32;
              do
              {
                while ( 1 )
                {
                  v21 = (unsigned __int8)*pdung_cels2++;
                  if ( (v21 & 0x80u) == 0 )
                    break;
                  LOBYTE(v21) = -(char)v21;
                  tmp_pbDst += v21;
                  v20 -= v21;
                  if ( !v20 )
                    goto LABEL_58;
                }
                v22 = v20 - v21;
                if ( tmp_pbDst < gpBufEnd )
                  return;
                v23 = v21;
                for ( l = v22; v23 >= 4; v23 -= 4 )
                {
                  v24 = *(_DWORD *)pdung_cels2;
                  pdung_cels2 += 4;
                  LOBYTE(v22) = v24;
                  v25 = l_tbl[v22];
                  LOBYTE(v22) = BYTE1(v24);
                  v24 = __ROR4__(v24, 16);
                  *tmp_pbDst = v25;
                  v26 = l_tbl[v22];
                  LOBYTE(v22) = v24;
                  tmp_pbDst[1] = v26;
                  v27 = l_tbl[v22];
                  LOBYTE(v22) = BYTE1(v24);
                  tmp_pbDst[2] = v27;
                  tmp_pbDst[3] = l_tbl[v22];
                  tmp_pbDst += 4;
                }
                if ( v23 >= 2 )
                {
                  LOBYTE(v22) = *pdung_cels2;
                  *tmp_pbDst = l_tbl[v22];
                  LOBYTE(v22) = pdung_cels2[1];
                  tmp_pbDst[1] = l_tbl[v22];
                  pdung_cels2 += 2;
                  tmp_pbDst += 2;
                }
                if ( v23 & 1 )
                {
                  LOBYTE(v22) = *pdung_cels2++;
                  *tmp_pbDst++ = l_tbl[v22];
                }
                v20 = l;
              }
              while ( l );
LABEL_58:
              tmp_pbDst -= 800;
              --v19;
            }
            while ( v19 );
            break;
          case 2:
            v28 = 30;
            while ( tmp_pbDst >= gpBufEnd )
            {
              v29 = &tmp_pbDst[v28];
              v30 = 32 - v28;
              v31 = (32 - (_BYTE)v28) & 2;
              pdung_cels2 += v31;
              if ( (char)(32 - v28) >= 4 )
              {
                do
                {
                  v32 = *(_DWORD *)pdung_cels2;
                  pdung_cels2 += 4;
                  LOBYTE(v31) = v32;
                  v33 = l_tbl[v31];
                  LOBYTE(v31) = BYTE1(v32);
                  v32 = __ROR4__(v32, 16);
                  *v29 = v33;
                  v34 = l_tbl[v31];
                  LOBYTE(v31) = v32;
                  v29[1] = v34;
                  v35 = l_tbl[v31];
                  LOBYTE(v31) = BYTE1(v32);
                  v29[2] = v35;
                  v29[3] = l_tbl[v31];
                  v29 += 4;
                  v30 -= 4;
                }
                while ( v30 >= 4 );
              }
              if ( v30 >= 2 )
              {
                LOBYTE(v31) = *pdung_cels2;
                *v29 = l_tbl[v31];
                LOBYTE(v31) = pdung_cels2[1];
                v29[1] = l_tbl[v31];
                pdung_cels2 += 2;
                v29 += 2;
              }
              tmp_pbDst = v29 - 800;
              v36 = __OFSUB__(v28, 2);
              v28 -= 2;
              if ( (v28 < 0) ^ v36 )
              {
                v37 = 2;
                do
                {
                  if ( tmp_pbDst < gpBufEnd )
                    break;
                  v38 = &tmp_pbDst[v37];
                  v39 = 32 - v37;
                  v40 = (32 - (_BYTE)v37) & 2;
                  pdung_cels2 += v40;
                  if ( (char)(32 - v37) >= 4 )
                  {
                    do
                    {
                      v41 = *(_DWORD *)pdung_cels2;
                      pdung_cels2 += 4;
                      LOBYTE(v40) = v41;
                      v42 = l_tbl[v40];
                      LOBYTE(v40) = BYTE1(v41);
                      v41 = __ROR4__(v41, 16);
                      *v38 = v42;
                      v43 = l_tbl[v40];
                      LOBYTE(v40) = v41;
                      v38[1] = v43;
                      v44 = l_tbl[v40];
                      LOBYTE(v40) = BYTE1(v41);
                      v38[2] = v44;
                      v38[3] = l_tbl[v40];
                      v38 += 4;
                      v39 -= 4;
                    }
                    while ( v39 >= 4 );
                  }
                  if ( v39 >= 2 )
                  {
                    LOBYTE(v40) = *pdung_cels2;
                    *v38 = l_tbl[v40];
                    LOBYTE(v40) = pdung_cels2[1];
                    v38[1] = l_tbl[v40];
                    pdung_cels2 += 2;
                    v38 += 2;
                  }
                  tmp_pbDst = v38 - 800;
                  v37 += 2;
                }
                while ( v37 != 32 );
                return;
              }
            }
            break;
          case 3:
            v45 = 30;
            while ( tmp_pbDst >= gpBufEnd )
            {
              for ( m = 32 - v45; m >= 4; m -= 4 )
              {
                v47 = *(_DWORD *)pdung_cels2;
                pdung_cels2 += 4;
                LOBYTE(v1) = v47;
                v48 = l_tbl[v1];
                LOBYTE(v1) = BYTE1(v47);
                v47 = __ROR4__(v47, 16);
                *tmp_pbDst = v48;
                v49 = l_tbl[v1];
                LOBYTE(v1) = v47;
                tmp_pbDst[1] = v49;
                v50 = l_tbl[v1];
                LOBYTE(v1) = BYTE1(v47);
                tmp_pbDst[2] = v50;
                tmp_pbDst[3] = l_tbl[v1];
                tmp_pbDst += 4;
              }
              if ( m >= 2 )
              {
                LOBYTE(v1) = *pdung_cels2;
                *tmp_pbDst = l_tbl[v1];
                LOBYTE(v1) = pdung_cels2[1];
                tmp_pbDst[1] = l_tbl[v1];
                pdung_cels2 += 2;
                tmp_pbDst += 2;
              }
              v1 = (unsigned __int8)pdung_cels2 & 2;
              pdung_cels2 += v1;
              tmp_pbDst = &tmp_pbDst[v45 - 800];
              v36 = __OFSUB__(v45, 2);
              v45 -= 2;
              if ( (v45 < 0) ^ v36 )
              {
                v51 = 2;
                do
                {
                  if ( tmp_pbDst < gpBufEnd )
                    break;
                  for ( n = 32 - v51; n >= 4; n -= 4 )
                  {
                    v53 = *(_DWORD *)pdung_cels2;
                    pdung_cels2 += 4;
                    LOBYTE(v1) = v53;
                    v54 = l_tbl[v1];
                    LOBYTE(v1) = BYTE1(v53);
                    v53 = __ROR4__(v53, 16);
                    *tmp_pbDst = v54;
                    v55 = l_tbl[v1];
                    LOBYTE(v1) = v53;
                    tmp_pbDst[1] = v55;
                    v56 = l_tbl[v1];
                    LOBYTE(v1) = BYTE1(v53);
                    tmp_pbDst[2] = v56;
                    tmp_pbDst[3] = l_tbl[v1];
                    tmp_pbDst += 4;
                  }
                  if ( n >= 2 )
                  {
                    LOBYTE(v1) = *pdung_cels2;
                    *tmp_pbDst = l_tbl[v1];
                    LOBYTE(v1) = pdung_cels2[1];
                    tmp_pbDst[1] = l_tbl[v1];
                    pdung_cels2 += 2;
                    tmp_pbDst += 2;
                  }
                  v1 = (unsigned __int8)pdung_cels2 & 2;
                  pdung_cels2 += v1;
                  tmp_pbDst = &tmp_pbDst[v51 - 800];
                  v51 += 2;
                }
                while ( v51 != 32 );
                return;
              }
            }
            break;
          case 4:
            v57 = 30;
            while ( tmp_pbDst >= gpBufEnd )
            {
              v58 = &tmp_pbDst[v57];
              v59 = 32 - v57;
              v60 = (32 - (_BYTE)v57) & 2;
              pdung_cels2 += v60;
              if ( (char)(32 - v57) >= 4 )
              {
                do
                {
                  v61 = *(_DWORD *)pdung_cels2;
                  pdung_cels2 += 4;
                  LOBYTE(v60) = v61;
                  v62 = l_tbl[v60];
                  LOBYTE(v60) = BYTE1(v61);
                  v61 = __ROR4__(v61, 16);
                  *v58 = v62;
                  v63 = l_tbl[v60];
                  LOBYTE(v60) = v61;
                  v58[1] = v63;
                  v64 = l_tbl[v60];
                  LOBYTE(v60) = BYTE1(v61);
                  v58[2] = v64;
                  v58[3] = l_tbl[v60];
                  v58 += 4;
                  v59 -= 4;
                }
                while ( v59 >= 4 );
              }
              if ( v59 >= 2 )
              {
                LOBYTE(v60) = *pdung_cels2;
                *v58 = l_tbl[v60];
                LOBYTE(v60) = pdung_cels2[1];
                v58[1] = l_tbl[v60];
                pdung_cels2 += 2;
                v58 += 2;
              }
              tmp_pbDst = v58 - 800;
              v36 = __OFSUB__(v57, 2);
              v57 -= 2;
              if ( (v57 < 0) ^ v36 )
              {
                v65 = 16;
                do
                {
                  if ( tmp_pbDst < gpBufEnd )
                    break;
                  v66 = 32;
                  do
                  {
                    v67 = *(_DWORD *)pdung_cels2;
                    pdung_cels2 += 4;
                    LOBYTE(v60) = v67;
                    v68 = l_tbl[v60];
                    LOBYTE(v60) = BYTE1(v67);
                    v67 = __ROR4__(v67, 16);
                    *tmp_pbDst = v68;
                    v69 = l_tbl[v60];
                    LOBYTE(v60) = v67;
                    tmp_pbDst[1] = v69;
                    v70 = l_tbl[v60];
                    LOBYTE(v60) = BYTE1(v67);
                    tmp_pbDst[2] = v70;
                    tmp_pbDst[3] = l_tbl[v60];
                    tmp_pbDst += 4;
                    v66 -= 4;
                  }
                  while ( v66 >= 4 );
                  tmp_pbDst -= 800;
                  --v65;
                }
                while ( v65 );
                return;
              }
            }
            break;
          default:
            v71 = 30;
            while ( tmp_pbDst >= gpBufEnd )
            {
              for ( ii = 32 - v71; ii >= 4; ii -= 4 )
              {
                v73 = *(_DWORD *)pdung_cels2;
                pdung_cels2 += 4;
                LOBYTE(v1) = v73;
                v74 = l_tbl[v1];
                LOBYTE(v1) = BYTE1(v73);
                v73 = __ROR4__(v73, 16);
                *tmp_pbDst = v74;
                v75 = l_tbl[v1];
                LOBYTE(v1) = v73;
                tmp_pbDst[1] = v75;
                v76 = l_tbl[v1];
                LOBYTE(v1) = BYTE1(v73);
                tmp_pbDst[2] = v76;
                tmp_pbDst[3] = l_tbl[v1];
                tmp_pbDst += 4;
              }
              if ( ii >= 2 )
              {
                LOBYTE(v1) = *pdung_cels2;
                *tmp_pbDst = l_tbl[v1];
                LOBYTE(v1) = pdung_cels2[1];
                tmp_pbDst[1] = l_tbl[v1];
                pdung_cels2 += 2;
                tmp_pbDst += 2;
              }
              v1 = (unsigned __int8)pdung_cels2 & 2;
              pdung_cels2 += v1;
              tmp_pbDst = &tmp_pbDst[v71 - 800];
              v36 = __OFSUB__(v71, 2);
              v71 -= 2;
              if ( (v71 < 0) ^ v36 )
              {
                v77 = 16;
                do
                {
                  if ( tmp_pbDst < gpBufEnd )
                    break;
                  v78 = 32;
                  do
                  {
                    v79 = *(_DWORD *)pdung_cels2;
                    pdung_cels2 += 4;
                    LOBYTE(v1) = v79;
                    v80 = l_tbl[v1];
                    LOBYTE(v1) = BYTE1(v79);
                    v79 = __ROR4__(v79, 16);
                    *tmp_pbDst = v80;
                    v81 = l_tbl[v1];
                    LOBYTE(v1) = v79;
                    tmp_pbDst[1] = v81;
                    v82 = l_tbl[v1];
                    LOBYTE(v1) = BYTE1(v79);
                    tmp_pbDst[2] = v82;
                    tmp_pbDst[3] = l_tbl[v1];
                    tmp_pbDst += 4;
                    v78 -= 4;
                  }
                  while ( v78 >= 4 );
                  tmp_pbDst -= 800;
                  --v77;
                }
                while ( v77 );
                return;
              }
            }
            break;
        }
      }
      else
      {
        v13 = 32;
        do
        {
          if ( tmp_pbDst < gpBufEnd )
            break;
          v14 = 32;
          v157 = v13;
          do
          {
            v15 = *(_DWORD *)pdung_cels2;
            pdung_cels2 += 4;
            LOBYTE(v13) = v15;
            v16 = l_tbl[v13];
            LOBYTE(v13) = BYTE1(v15);
            v15 = __ROR4__(v15, 16);
            *tmp_pbDst = v16;
            v17 = l_tbl[v13];
            LOBYTE(v13) = v15;
            tmp_pbDst[1] = v17;
            v18 = l_tbl[v13];
            LOBYTE(v13) = BYTE1(v15);
            tmp_pbDst[2] = v18;
            tmp_pbDst[3] = l_tbl[v13];
            tmp_pbDst += 4;
            v14 -= 4;
          }
          while ( v14 >= 4 );
          tmp_pbDst -= 800;
          v13 = v157 - 1;
        }
        while ( v157 != 1 );
      }
      return;
    }
    pdung_cels = (unsigned __int8 *)pSpeedCels
               + *(_DWORD *)&gpCelFrame[4 * (light_table_index + 16 * (level_cel_block & 0xFFF))];
    v9 = (unsigned __int16)level_cel_block >> 12;
    goto LABEL_22;
  }
  if ( level_cel_block & 0x8000 )
    level_cel_block = *(_DWORD *)&gpCelFrame[64 * (level_cel_block & 0xFFF)]
                    + (unsigned __int16)(level_cel_block & 0xF000);
  pdung_cels3 = (unsigned __int8 *)pDungeonCels + *((_DWORD *)pDungeonCels + (level_cel_block & 0xFFF));
  v12 = ((unsigned int)level_cel_block >> 12) & 7;
  if ( v12 )
  {
    switch ( (_WORD)v12 )
    {
      case 1:
        v130 = 32;
        do
        {
          v131 = 32;
          do
          {
            while ( 1 )
            {
              v132 = *pdung_cels3++;
              if ( (v132 & 0x80u) == 0 )
                break;
              LOBYTE(v132) = -(char)v132;
              tmp_pbDst += v132;
              v131 -= v132;
              if ( !v131 )
                goto LABEL_205;
            }
            v131 -= v132;
            if ( tmp_pbDst < gpBufEnd )
              return;
            pdung_cels3 += v132;
            v133 = v132 >> 1;
            if ( v132 & 1 )
            {
              *tmp_pbDst++ = 0;
              if ( !v133 )
                continue;
            }
            v91 = v133 & 1;
            v134 = v132 >> 2;
            if ( v91 )
            {
              *(_WORD *)tmp_pbDst = 0;
              tmp_pbDst += 2;
              if ( !v134 )
                continue;
            }
            do
            {
              *(_DWORD *)tmp_pbDst = 0;
              tmp_pbDst += 4;
              --v134;
            }
            while ( v134 );
          }
          while ( v131 );
LABEL_205:
          tmp_pbDst -= 800;
          --v130;
        }
        while ( v130 );
        break;
      case 2:
        v135 = 30;
        while ( tmp_pbDst >= gpBufEnd )
        {
          v136 = &tmp_pbDst[v135];
          v137 = (unsigned int)(32 - v135) >> 2;
          if ( !__CFSHR__(32 - v135, 2) || (*(_WORD *)v136 = 0, v136 += 2, v137) )
          {
            do
            {
              *(_DWORD *)v136 = 0;
              v136 += 4;
              --v137;
            }
            while ( v137 );
          }
          tmp_pbDst = v136 - 800;
          if ( !v135 )
          {
            v138 = 2;
            do
            {
              if ( tmp_pbDst < gpBufEnd )
                break;
              v139 = &tmp_pbDst[v138];
              v140 = (unsigned int)(32 - v138) >> 2;
              if ( __CFSHR__(32 - v138, 2) )
              {
                *(_WORD *)v139 = 0;
                v139 += 2;
                if ( !v140 )
                  continue;
              }
              do
              {
                *(_DWORD *)v139 = 0;
                v139 += 4;
                --v140;
              }
              while ( v140 );
              tmp_pbDst = v139 - 800;
              v138 += 2;
            }
            while ( v138 != 32 );
            return;
          }
          v135 -= 2;
        }
        break;
      case 3:
        v141 = 30;
        while ( tmp_pbDst >= gpBufEnd )
        {
          v142 = (unsigned int)(32 - v141) >> 2;
          if ( !__CFSHR__(32 - v141, 2) || (*(_WORD *)tmp_pbDst = 0, tmp_pbDst += 2, v142) )
          {
            do
            {
              *(_DWORD *)tmp_pbDst = 0;
              tmp_pbDst += 4;
              --v142;
            }
            while ( v142 );
          }
          v143 = tmp_pbDst - 800;
          if ( !v141 )
          {
            v144 = 2;
            do
            {
              if ( v143 < gpBufEnd )
                break;
              v145 = (unsigned int)(32 - v144) >> 2;
              if ( __CFSHR__(32 - v144, 2) )
              {
                *(_WORD *)v143 = 0;
                v143 += 2;
                if ( !v145 )
                  continue;
              }
              do
              {
                *(_DWORD *)v143 = 0;
                v143 += 4;
                --v145;
              }
              while ( v145 );
              v143 = &v143[v144 - 800];
              v144 += 2;
            }
            while ( v144 != 32 );
            return;
          }
          tmp_pbDst = &v143[v141];
          v141 -= 2;
        }
        break;
      case 4:
        v146 = 30;
        while ( tmp_pbDst >= gpBufEnd )
        {
          v147 = &tmp_pbDst[v146];
          v148 = (unsigned int)(32 - v146) >> 2;
          if ( !__CFSHR__(32 - v146, 2) || (*(_WORD *)v147 = 0, v147 += 2, v148) )
          {
            do
            {
              *(_DWORD *)v147 = 0;
              v147 += 4;
              --v148;
            }
            while ( v148 );
          }
          tmp_pbDst = v147 - 800;
          if ( !v146 )
          {
            v149 = 16;
            do
            {
              if ( tmp_pbDst < gpBufEnd )
                break;
              v150 = 8;
              do
              {
                *(_DWORD *)tmp_pbDst = 0;
                tmp_pbDst += 4;
                --v150;
              }
              while ( v150 );
              tmp_pbDst -= 800;
              --v149;
            }
            while ( v149 );
            return;
          }
          v146 -= 2;
        }
        break;
      default:
        v151 = 30;
        while ( tmp_pbDst >= gpBufEnd )
        {
          v152 = (unsigned int)(32 - v151) >> 2;
          if ( !__CFSHR__(32 - v151, 2) || (*(_WORD *)tmp_pbDst = 0, tmp_pbDst += 2, v152) )
          {
            do
            {
              *(_DWORD *)tmp_pbDst = 0;
              tmp_pbDst += 4;
              --v152;
            }
            while ( v152 );
          }
          v153 = tmp_pbDst - 800;
          if ( !v151 )
          {
            v154 = 16;
            do
            {
              if ( v153 < gpBufEnd )
                break;
              v155 = 8;
              do
              {
                *(_DWORD *)v153 = 0;
                v153 += 4;
                --v155;
              }
              while ( v155 );
              v153 -= 800;
              --v154;
            }
            while ( v154 );
            return;
          }
          tmp_pbDst = &v153[v151];
          v151 -= 2;
        }
        break;
    }
  }
  else
  {
    v128 = 32;
    do
    {
      if ( tmp_pbDst < gpBufEnd )
        break;
      v129 = 8;
      do
      {
        *(_DWORD *)tmp_pbDst = 0;
        tmp_pbDst += 4;
        --v129;
      }
      while ( v129 );
      tmp_pbDst -= 800;
      --v128;
    }
    while ( v128 );
  }
}

//----- (004A3364) --------------------------------------------------------
void __fastcall drawTopArchesLowerScreen(unsigned __int8 *pbDst)
{
  int v1; // edx
  unsigned int tmp_pbDst; // edi
  _BYTE *pdung_cels3; // esi
  BYTE *l_tbl; // ebx
  __int16 v5; // ax
  char *pdung_cels; // esi
  __int16 v7; // ax
  unsigned int v8; // eax
  char *pdung_cels2; // esi
  unsigned int v10; // eax
  int v11; // eax
  signed int v12; // ebp
  signed int v13; // ecx
  unsigned int v14; // eax
  unsigned __int8 *v15; // edi
  signed int v16; // ecx
  int v17; // eax
  int v18; // ecx
  signed int v19; // ebp
  unsigned int v20; // eax
  unsigned int v21; // ecx
  unsigned __int8 v22; // cf
  unsigned int v23; // ecx
  unsigned int v24; // eax
  unsigned int v25; // ecx
  int v26; // eax
  unsigned int v27; // ecx
  unsigned int v28; // ecx
  int v29; // eax
  unsigned int v30; // ecx
  unsigned int v31; // eax
  int v32; // ebp
  signed int v33; // eax
  unsigned int v34; // ecx
  int v35; // eax
  _BYTE *v36; // edi
  unsigned int v37; // ecx
  int v38; // edx
  unsigned int v39; // ecx
  unsigned int v40; // ecx
  unsigned int v41; // eax
  unsigned int v42; // ecx
  int v43; // eax
  int v44; // edx
  unsigned int v45; // ecx
  unsigned int v46; // ecx
  int v47; // eax
  unsigned int v48; // ecx
  unsigned int v49; // eax
  unsigned __int8 v50; // of
  int v51; // ebp
  signed int v52; // eax
  unsigned int v53; // ecx
  int v54; // eax
  _BYTE *v55; // edi
  unsigned int v56; // ecx
  int v57; // edx
  unsigned int v58; // ecx
  unsigned int v59; // ecx
  unsigned int v60; // eax
  unsigned int v61; // ecx
  int v62; // eax
  int v63; // edx
  unsigned int v64; // ecx
  unsigned int v65; // ecx
  int v66; // eax
  unsigned int v67; // ecx
  unsigned int v68; // eax
  int v69; // ebp
  signed int v70; // eax
  unsigned int v71; // ecx
  int v72; // eax
  unsigned int v73; // ecx
  unsigned int v74; // ecx
  unsigned int v75; // ecx
  unsigned int v76; // eax
  unsigned int v77; // ecx
  int v78; // eax
  unsigned int v79; // ecx
  unsigned int v80; // ecx
  int v81; // eax
  unsigned int v82; // ecx
  unsigned int v83; // eax
  int v84; // ebp
  signed int v85; // eax
  unsigned int v86; // ecx
  int v87; // eax
  unsigned int v88; // ecx
  unsigned int v89; // ecx
  unsigned int v90; // ecx
  unsigned int v91; // eax
  unsigned int v92; // ecx
  int v93; // eax
  unsigned int v94; // ecx
  unsigned int v95; // ecx
  int v96; // eax
  unsigned int v97; // ecx
  unsigned int v98; // eax
  int v99; // ebp
  signed int v100; // eax
  unsigned int v101; // ecx
  int v102; // eax
  _BYTE *v103; // edi
  unsigned int v104; // ecx
  unsigned int v105; // ecx
  unsigned int v106; // ecx
  unsigned int v107; // eax
  unsigned int v108; // ecx
  int v109; // eax
  unsigned int v110; // ecx
  unsigned int v111; // ecx
  int v112; // eax
  unsigned int v113; // ecx
  unsigned int v114; // eax
  signed int v115; // ebp
  signed int v116; // ecx
  unsigned int v117; // eax
  unsigned __int8 *v118; // edi
  signed int v119; // ecx
  int v120; // eax
  int v121; // ebp
  signed int v122; // eax
  unsigned int v123; // ecx
  int v124; // eax
  unsigned int v125; // ecx
  unsigned int v126; // ecx
  unsigned int v127; // ecx
  unsigned int v128; // eax
  unsigned int v129; // ecx
  int v130; // eax
  unsigned int v131; // ecx
  unsigned int v132; // ecx
  int v133; // eax
  unsigned int v134; // ecx
  unsigned int v135; // eax
  signed int v136; // ebp
  signed int v137; // ecx
  unsigned int v138; // eax
  unsigned __int8 *v139; // edi
  signed int v140; // ecx
  int v141; // eax
  signed int v142; // edx
  signed int v143; // ecx
  int v144; // eax
  _BYTE *v145; // edi
  unsigned __int8 *v146; // edi
  signed int v147; // ecx
  int v148; // eax
  _BYTE *v149; // edi
  int v150; // ecx
  signed int v151; // edx
  unsigned int v152; // eax
  unsigned int v153; // ecx
  unsigned int v154; // ecx
  char *v155; // esi
  _BYTE *v156; // edi
  char v157; // al
  int v158; // eax
  _BYTE *v159; // edi
  char v160; // al
  unsigned int v161; // ecx
  char v162; // al
  int v163; // eax
  _BYTE *v164; // edi
  int v165; // edx
  signed int v166; // eax
  unsigned int v167; // ecx
  int v168; // eax
  _BYTE *v169; // edi
  unsigned int v170; // ecx
  int v171; // eax
  unsigned int v172; // ecx
  _BYTE *v173; // edi
  int v174; // eax
  _BYTE *v175; // edi
  unsigned int v176; // ecx
  __int16 v177; // ax
  int v178; // eax
  _BYTE *v179; // edi
  int v180; // edx
  signed int v181; // eax
  unsigned int v182; // ecx
  int v183; // eax
  _BYTE *v184; // edi
  unsigned int v185; // ecx
  int v186; // eax
  unsigned int v187; // ecx
  _BYTE *v188; // edi
  int v189; // eax
  _BYTE *v190; // edi
  unsigned int v191; // ecx
  __int16 v192; // ax
  int v193; // eax
  _BYTE *v194; // edi
  int v195; // edx
  signed int v196; // eax
  unsigned int v197; // ecx
  int v198; // eax
  unsigned int v199; // ecx
  int v200; // eax
  unsigned int ii; // ecx
  int v202; // eax
  _BYTE *v203; // edi
  _BYTE *v204; // edi
  unsigned int jj; // ecx
  int v206; // eax
  _BYTE *v207; // edi
  __int16 v208; // ax
  int v209; // edx
  signed int v210; // eax
  unsigned int v211; // ecx
  int v212; // eax
  unsigned int v213; // ecx
  int v214; // eax
  unsigned int kk; // ecx
  int v216; // eax
  _BYTE *v217; // edi
  _BYTE *v218; // edi
  unsigned int ll; // ecx
  int v220; // eax
  _BYTE *v221; // edi
  __int16 v222; // ax
  int v223; // edx
  signed int v224; // eax
  unsigned int v225; // ecx
  int v226; // eax
  _BYTE *v227; // edi
  unsigned int v228; // ecx
  int v229; // eax
  unsigned int v230; // ecx
  _BYTE *v231; // edi
  int v232; // eax
  _BYTE *v233; // edi
  unsigned int v234; // ecx
  __int16 v235; // ax
  int v236; // eax
  _BYTE *v237; // edi
  signed int v238; // edx
  signed int v239; // ecx
  int v240; // eax
  _BYTE *v241; // edi
  unsigned __int8 *v242; // edi
  signed int v243; // ecx
  int v244; // eax
  _BYTE *v245; // edi
  int v246; // edx
  signed int v247; // eax
  unsigned int v248; // ecx
  int v249; // eax
  unsigned int v250; // ecx
  int v251; // eax
  unsigned int m; // ecx
  int v253; // eax
  _BYTE *v254; // edi
  _BYTE *v255; // edi
  unsigned int n; // ecx
  int v257; // eax
  _BYTE *v258; // edi
  __int16 v259; // ax
  signed int v260; // edx
  signed int v261; // ecx
  int v262; // eax
  _BYTE *v263; // edi
  unsigned __int8 *v264; // edi
  signed int v265; // ecx
  int v266; // eax
  _BYTE *v267; // edi
  signed int v268; // edx
  signed int v269; // ecx
  unsigned __int8 *v270; // edi
  signed int v271; // ecx
  int v272; // ecx
  signed int v273; // edx
  unsigned int v274; // eax
  unsigned int v275; // ecx
  unsigned int v276; // ecx
  _BYTE *v277; // edi
  unsigned int v278; // ecx
  signed int i; // edx
  _BYTE *v280; // edi
  unsigned int v281; // ecx
  unsigned int v282; // ecx
  _BYTE *v283; // edi
  unsigned int v284; // ecx
  signed int v285; // edx
  _BYTE *v286; // edi
  unsigned int v287; // ecx
  unsigned int v288; // ecx
  _BYTE *v289; // edi
  unsigned int v290; // ecx
  signed int j; // edx
  unsigned int v292; // ecx
  unsigned int v293; // ecx
  _BYTE *v294; // edi
  unsigned int v295; // ecx
  unsigned __int8 *v296; // edi
  signed int v297; // edx
  unsigned int v298; // ecx
  unsigned int v299; // ecx
  _BYTE *v300; // edi
  unsigned int v301; // ecx
  signed int k; // edx
  _BYTE *v303; // edi
  unsigned int v304; // ecx
  unsigned int v305; // ecx
  _BYTE *v306; // edi
  unsigned int v307; // ecx
  signed int v308; // edx
  signed int v309; // ecx
  unsigned __int8 *v310; // edi
  signed int v311; // ecx
  signed int l; // edx
  unsigned int v313; // ecx
  unsigned int v314; // ecx
  _BYTE *v315; // edi
  unsigned int v316; // ecx
  unsigned int v317; // edi
  signed int v318; // edx
  signed int v319; // ecx
  unsigned __int8 *v320; // edi
  signed int v321; // ecx
  int v322; // [esp-14h] [ebp-18h]
  int v323; // [esp-10h] [ebp-14h]
  int v324; // [esp-10h] [ebp-14h]

  gpCelFrame = (unsigned __int8 *)speed_cel_frame_num_from_light_index_frame_num;
  tmp_pbDst = (unsigned int)pbDst;
  if ( !(_BYTE)light_table_index )
  {
    if ( level_cel_block & 0x8000 )
      level_cel_block = *(_DWORD *)&gpCelFrame[64 * (level_cel_block & 0xFFF)]
                      + (unsigned __int16)(level_cel_block & 0xF000);
    pdung_cels = (char *)pDungeonCels + *((_DWORD *)pDungeonCels + (level_cel_block & 0xFFF));
    v8 = level_cel_block;
    LOBYTE(v8) = BYTE1(v8);
    v7 = ((v8 >> 4) & 7) + 8;
    goto LABEL_11;
  }
  if ( (_BYTE)light_table_index == lightmax )
  {
    if ( level_cel_block & 0x8000 )
      level_cel_block = *(_DWORD *)&gpCelFrame[64 * (level_cel_block & 0xFFF)]
                      + (unsigned __int16)(level_cel_block & 0xF000);
    pdung_cels2 = (char *)pDungeonCels + *((_DWORD *)pDungeonCels + (level_cel_block & 0xFFF));
    v10 = level_cel_block;
    LOBYTE(v10) = BYTE1(v10);
    v11 = (v10 >> 4) & 7;
    if ( !v11 )
    {
      v268 = 16;
      do
      {
        if ( tmp_pbDst < (unsigned int)gpBufEnd )
        {
          v269 = 8;
          do
          {
            *(_BYTE *)(tmp_pbDst + 1) = 0;
            *(_BYTE *)(tmp_pbDst + 3) = 0;
            tmp_pbDst += 4;
            --v269;
          }
          while ( v269 );
        }
        else
        {
          pdung_cels2 += 32;
          tmp_pbDst += 32;
        }
        v270 = (unsigned __int8 *)(tmp_pbDst - 800);
        if ( v270 < gpBufEnd )
        {
          v271 = 8;
          do
          {
            *v270 = 0;
            v270[2] = 0;
            v270 += 4;
            --v271;
          }
          while ( v271 );
        }
        else
        {
          pdung_cels2 += 32;
          v270 += 32;
        }
        tmp_pbDst = (unsigned int)(v270 - 800);
        --v268;
      }
      while ( v268 );
      return;
    }
    if ( (_WORD)v11 != 1 )
    {
      switch ( (_WORD)v11 )
      {
        case 2:
          WorldBoolFlag = 0;
          for ( i = 30; ; i -= 2 )
          {
            if ( tmp_pbDst < (unsigned int)gpBufEnd )
            {
              v280 = (_BYTE *)(i + tmp_pbDst);
              v281 = 32 - i;
              WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
              if ( WorldBoolFlag )
              {
                v22 = __CFSHR__(v281, 2);
                v282 = v281 >> 2;
                if ( !v22 || (v283 = v280 + 1, *v283 = 0, v280 = v283 + 1, v282) )
                {
                  do
                  {
                    v280[1] = 0;
                    v280[3] = 0;
                    v280 += 4;
                    --v282;
                  }
                  while ( v282 );
                }
              }
              else
              {
                v22 = __CFSHR__(v281, 2);
                v284 = v281 >> 2;
                if ( !v22 || (*v280 = 0, v280 += 2, v284) )
                {
                  do
                  {
                    *v280 = 0;
                    v280[2] = 0;
                    v280 += 4;
                    --v284;
                  }
                  while ( v284 );
                }
              }
            }
            else
            {
              pdung_cels2 = &pdung_cels2[-i + 32];
              v280 = (_BYTE *)(tmp_pbDst + 32);
            }
            tmp_pbDst = (unsigned int)(v280 - 800);
            if ( !i )
              break;
          }
          v285 = 2;
          do
          {
            if ( tmp_pbDst < (unsigned int)gpBufEnd )
            {
              v286 = (_BYTE *)(v285 + tmp_pbDst);
              v287 = 32 - v285;
              WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
              if ( WorldBoolFlag )
              {
                v22 = __CFSHR__(v287, 2);
                v288 = v287 >> 2;
                if ( !v22 || (v289 = v286 + 1, *v289 = 0, v286 = v289 + 1, v288) )
                {
                  do
                  {
                    v286[1] = 0;
                    v286[3] = 0;
                    v286 += 4;
                    --v288;
                  }
                  while ( v288 );
                }
              }
              else
              {
                v22 = __CFSHR__(v287, 2);
                v290 = v287 >> 2;
                if ( !v22 || (*v286 = 0, v286 += 2, v290) )
                {
                  do
                  {
                    *v286 = 0;
                    v286[2] = 0;
                    v286 += 4;
                    --v290;
                  }
                  while ( v290 );
                }
              }
            }
            else
            {
              pdung_cels2 = &pdung_cels2[-v285 + 32];
              v286 = (_BYTE *)(tmp_pbDst + 32);
            }
            tmp_pbDst = (unsigned int)(v286 - 800);
            v285 += 2;
          }
          while ( v285 != 32 );
          break;
        case 3:
          WorldBoolFlag = 0;
          for ( j = 30; ; j -= 2 )
          {
            if ( tmp_pbDst < (unsigned int)gpBufEnd )
            {
              v292 = 32 - j;
              WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
              if ( WorldBoolFlag )
              {
                v22 = __CFSHR__(v292, 2);
                v293 = v292 >> 2;
                if ( !v22 || (v294 = (_BYTE *)(tmp_pbDst + 1), *v294 = 0, tmp_pbDst = (unsigned int)(v294 + 1), v293) )
                {
                  do
                  {
                    *(_BYTE *)(tmp_pbDst + 1) = 0;
                    *(_BYTE *)(tmp_pbDst + 3) = 0;
                    tmp_pbDst += 4;
                    --v293;
                  }
                  while ( v293 );
                }
              }
              else
              {
                v22 = __CFSHR__(v292, 2);
                v295 = v292 >> 2;
                if ( !v22 || (*(_BYTE *)tmp_pbDst = 0, tmp_pbDst += 2, v295) )
                {
                  do
                  {
                    *(_BYTE *)tmp_pbDst = 0;
                    *(_BYTE *)(tmp_pbDst + 2) = 0;
                    tmp_pbDst += 4;
                    --v295;
                  }
                  while ( v295 );
                }
              }
            }
            else
            {
              pdung_cels2 = &pdung_cels2[-j + 32];
              tmp_pbDst = tmp_pbDst + 32 - j;
            }
            v296 = (unsigned __int8 *)(tmp_pbDst - 800);
            if ( !j )
              break;
            tmp_pbDst = (unsigned int)&v296[j];
          }
          v297 = 2;
          do
          {
            if ( v296 < gpBufEnd )
            {
              v298 = 32 - v297;
              WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
              if ( WorldBoolFlag )
              {
                v22 = __CFSHR__(v298, 2);
                v299 = v298 >> 2;
                if ( !v22 || (v300 = v296 + 1, *v300 = 0, v296 = v300 + 1, v299) )
                {
                  do
                  {
                    v296[1] = 0;
                    v296[3] = 0;
                    v296 += 4;
                    --v299;
                  }
                  while ( v299 );
                }
              }
              else
              {
                v22 = __CFSHR__(v298, 2);
                v301 = v298 >> 2;
                if ( !v22 || (*v296 = 0, v296 += 2, v301) )
                {
                  do
                  {
                    *v296 = 0;
                    v296[2] = 0;
                    v296 += 4;
                    --v301;
                  }
                  while ( v301 );
                }
              }
            }
            else
            {
              pdung_cels2 = &pdung_cels2[-v297 + 32];
              v296 = &v296[-v297 + 32];
            }
            v296 = &v296[v297 - 800];
            v297 += 2;
          }
          while ( v297 != 32 );
          break;
        case 4:
          WorldBoolFlag = 0;
          for ( k = 30; ; k -= 2 )
          {
            if ( tmp_pbDst < (unsigned int)gpBufEnd )
            {
              v303 = (_BYTE *)(k + tmp_pbDst);
              v304 = 32 - k;
              WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
              if ( WorldBoolFlag )
              {
                v22 = __CFSHR__(v304, 2);
                v305 = v304 >> 2;
                if ( !v22 || (v306 = v303 + 1, *v306 = 0, v303 = v306 + 1, v305) )
                {
                  do
                  {
                    v303[1] = 0;
                    v303[3] = 0;
                    v303 += 4;
                    --v305;
                  }
                  while ( v305 );
                }
              }
              else
              {
                v22 = __CFSHR__(v304, 2);
                v307 = v304 >> 2;
                if ( !v22 || (*v303 = 0, v303 += 2, v307) )
                {
                  do
                  {
                    *v303 = 0;
                    v303[2] = 0;
                    v303 += 4;
                    --v307;
                  }
                  while ( v307 );
                }
              }
            }
            else
            {
              pdung_cels2 = &pdung_cels2[-k + 32];
              v303 = (_BYTE *)(tmp_pbDst + 32);
            }
            tmp_pbDst = (unsigned int)(v303 - 800);
            if ( !k )
              break;
          }
          v308 = 8;
          do
          {
            if ( tmp_pbDst < (unsigned int)gpBufEnd )
            {
              v309 = 8;
              do
              {
                *(_BYTE *)(tmp_pbDst + 1) = 0;
                *(_BYTE *)(tmp_pbDst + 3) = 0;
                tmp_pbDst += 4;
                --v309;
              }
              while ( v309 );
            }
            else
            {
              pdung_cels2 += 32;
              tmp_pbDst += 32;
            }
            v310 = (unsigned __int8 *)(tmp_pbDst - 800);
            if ( v310 < gpBufEnd )
            {
              v311 = 8;
              do
              {
                *v310 = 0;
                v310[2] = 0;
                v310 += 4;
                --v311;
              }
              while ( v311 );
            }
            else
            {
              pdung_cels2 += 32;
              v310 += 32;
            }
            tmp_pbDst = (unsigned int)(v310 - 800);
            --v308;
          }
          while ( v308 );
          break;
        default:
          WorldBoolFlag = 0;
          for ( l = 30; ; l -= 2 )
          {
            if ( tmp_pbDst < (unsigned int)gpBufEnd )
            {
              v313 = 32 - l;
              WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
              if ( WorldBoolFlag )
              {
                v22 = __CFSHR__(v313, 2);
                v314 = v313 >> 2;
                if ( !v22 || (v315 = (_BYTE *)(tmp_pbDst + 1), *v315 = 0, tmp_pbDst = (unsigned int)(v315 + 1), v314) )
                {
                  do
                  {
                    *(_BYTE *)(tmp_pbDst + 1) = 0;
                    *(_BYTE *)(tmp_pbDst + 3) = 0;
                    tmp_pbDst += 4;
                    --v314;
                  }
                  while ( v314 );
                }
              }
              else
              {
                v22 = __CFSHR__(v313, 2);
                v316 = v313 >> 2;
                if ( !v22 || (*(_BYTE *)tmp_pbDst = 0, tmp_pbDst += 2, v316) )
                {
                  do
                  {
                    *(_BYTE *)tmp_pbDst = 0;
                    *(_BYTE *)(tmp_pbDst + 2) = 0;
                    tmp_pbDst += 4;
                    --v316;
                  }
                  while ( v316 );
                }
              }
            }
            else
            {
              pdung_cels2 = &pdung_cels2[-l + 32];
              tmp_pbDst = tmp_pbDst + 32 - l;
            }
            v317 = tmp_pbDst - 800;
            if ( !l )
              break;
            tmp_pbDst = l + v317;
          }
          v318 = 8;
          do
          {
            if ( v317 < (unsigned int)gpBufEnd )
            {
              v319 = 8;
              do
              {
                *(_BYTE *)(v317 + 1) = 0;
                *(_BYTE *)(v317 + 3) = 0;
                v317 += 4;
                --v319;
              }
              while ( v319 );
            }
            else
            {
              pdung_cels2 += 32;
              v317 += 32;
            }
            v320 = (unsigned __int8 *)(v317 - 800);
            if ( v320 < gpBufEnd )
            {
              v321 = 8;
              do
              {
                *v320 = 0;
                v320[2] = 0;
                v320 += 4;
                --v321;
              }
              while ( v321 );
            }
            else
            {
              pdung_cels2 += 32;
              v320 += 32;
            }
            v317 = (unsigned int)(v320 - 800);
            --v318;
          }
          while ( v318 );
          break;
      }
      return;
    }
    WorldBoolFlag = (unsigned __int8)pbDst & 1;
    v272 = 32;
LABEL_412:
    v324 = v272;
    v273 = 32;
    while ( 1 )
    {
      while ( 1 )
      {
        v274 = (unsigned __int8)*pdung_cels2++;
        if ( (v274 & 0x80u) == 0 )
          break;
        LOBYTE(v274) = -(char)v274;
        tmp_pbDst += v274;
        v273 -= v274;
        if ( !v273 )
        {
LABEL_433:
          WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
          tmp_pbDst -= 800;
          v272 = v324 - 1;
          if ( v324 == 1 )
            return;
          goto LABEL_412;
        }
      }
      v273 -= v274;
      if ( tmp_pbDst < (unsigned int)gpBufEnd )
      {
        pdung_cels2 += v274;
        if ( (tmp_pbDst & 1) == WorldBoolFlag )
        {
          v275 = v274 >> 1;
          if ( !(v274 & 1) )
            goto LABEL_420;
          ++tmp_pbDst;
          if ( v275 )
          {
LABEL_427:
            v22 = v275 & 1;
            v278 = v275 >> 1;
            if ( !v22 || (*(_BYTE *)tmp_pbDst = 0, tmp_pbDst += 2, v278) )
            {
              do
              {
                *(_BYTE *)tmp_pbDst = 0;
                *(_BYTE *)(tmp_pbDst + 2) = 0;
                tmp_pbDst += 4;
                --v278;
              }
              while ( v278 );
            }
            goto LABEL_430;
          }
        }
        else
        {
          v275 = v274 >> 1;
          if ( !(v274 & 1) )
            goto LABEL_427;
          *(_BYTE *)tmp_pbDst++ = 0;
          if ( v275 )
          {
LABEL_420:
            v22 = v275 & 1;
            v276 = v275 >> 1;
            if ( !v22 || (v277 = (_BYTE *)(tmp_pbDst + 1), *v277 = 0, tmp_pbDst = (unsigned int)(v277 + 1), v276) )
            {
              do
              {
                *(_BYTE *)(tmp_pbDst + 1) = 0;
                *(_BYTE *)(tmp_pbDst + 3) = 0;
                tmp_pbDst += 4;
                --v276;
              }
              while ( v276 );
            }
            goto LABEL_430;
          }
        }
      }
      else
      {
        pdung_cels2 += v274;
        tmp_pbDst += v274;
      }
LABEL_430:
      if ( !v273 )
        goto LABEL_433;
    }
  }
  if ( !(level_cel_block & 0x8000) )
  {
    pdung_cels3 = (char *)pDungeonCels + *((_DWORD *)pDungeonCels + (level_cel_block & 0xFFF));
    l_tbl = &pLightTbl[256 * light_table_index];
    v5 = (unsigned __int8)(BYTE1(level_cel_block) >> 4);
    if ( !(BYTE1(level_cel_block) >> 4) )
    {
      v12 = 16;
      do
      {
        if ( tmp_pbDst < (unsigned int)gpBufEnd )
        {
          v13 = 8;
          do
          {
            v14 = *(_DWORD *)pdung_cels3;
            pdung_cels3 += 4;
            LOBYTE(v1) = BYTE1(v14);
            v14 >>= 16;
            *(_BYTE *)(tmp_pbDst + 1) = l_tbl[v1];
            LOBYTE(v1) = BYTE1(v14);
            tmp_pbDst += 4;
            --v13;
            *(_BYTE *)(tmp_pbDst - 1) = l_tbl[v1];
          }
          while ( v13 );
        }
        else
        {
          pdung_cels3 += 32;
          tmp_pbDst += 32;
        }
        v15 = (unsigned __int8 *)(tmp_pbDst - 800);
        if ( v15 < gpBufEnd )
        {
          v16 = 8;
          do
          {
            v17 = *(_DWORD *)pdung_cels3;
            pdung_cels3 += 4;
            LOBYTE(v1) = v17;
            *v15 = l_tbl[v1];
            LOBYTE(v1) = BYTE2(v17);
            v15 += 4;
            --v16;
            *(v15 - 2) = l_tbl[v1];
          }
          while ( v16 );
        }
        else
        {
          pdung_cels3 += 32;
          v15 += 32;
        }
        tmp_pbDst = (unsigned int)(v15 - 800);
        --v12;
      }
      while ( v12 );
      return;
    }
    if ( v5 == 1 )
    {
      WorldBoolFlag = (unsigned __int8)pbDst & 1;
      v18 = 32;
      do
      {
        v322 = v18;
        v19 = 32;
        do
        {
          while ( 1 )
          {
            v20 = (unsigned __int8)*pdung_cels3++;
            if ( (v20 & 0x80u) == 0 )
              break;
            LOBYTE(v20) = -(char)v20;
            tmp_pbDst += v20;
            v19 -= v20;
            if ( !v19 )
              goto LABEL_69;
          }
          v19 -= v20;
          if ( tmp_pbDst < (unsigned int)gpBufEnd )
          {
            if ( (tmp_pbDst & 1) == WorldBoolFlag )
            {
              v21 = v20 >> 1;
              if ( v20 & 1 )
              {
                ++pdung_cels3;
                ++tmp_pbDst;
                v22 = v21 & 1;
                v25 = v20 >> 2;
                if ( v22 )
                {
                  LOBYTE(v1) = *pdung_cels3;
                  pdung_cels3 += 2;
                  *(_BYTE *)tmp_pbDst = l_tbl[v1];
                  tmp_pbDst += 2;
                }
                if ( (_BYTE)v25 )
                {
                  do
                  {
                    v26 = *(_DWORD *)pdung_cels3;
                    pdung_cels3 += 4;
                    LOBYTE(v1) = v26;
                    *(_BYTE *)tmp_pbDst = l_tbl[v1];
                    LOBYTE(v1) = BYTE2(v26);
                    tmp_pbDst += 4;
                    --v25;
                    *(_BYTE *)(tmp_pbDst - 2) = l_tbl[v1];
                  }
                  while ( v25 );
                }
              }
              else
              {
                v22 = v21 & 1;
                v23 = v20 >> 2;
                if ( v22 )
                {
                  LOBYTE(v1) = pdung_cels3[1];
                  pdung_cels3 += 2;
                  *(_BYTE *)(tmp_pbDst + 1) = l_tbl[v1];
                  tmp_pbDst += 2;
                }
                if ( (_BYTE)v23 )
                {
                  do
                  {
                    v24 = *(_DWORD *)pdung_cels3;
                    pdung_cels3 += 4;
                    LOBYTE(v1) = BYTE1(v24);
                    v24 >>= 16;
                    *(_BYTE *)(tmp_pbDst + 1) = l_tbl[v1];
                    LOBYTE(v1) = BYTE1(v24);
                    tmp_pbDst += 4;
                    --v23;
                    *(_BYTE *)(tmp_pbDst - 1) = l_tbl[v1];
                  }
                  while ( v23 );
                }
              }
            }
            else
            {
              v27 = v20 >> 1;
              if ( v20 & 1 )
              {
                LOBYTE(v1) = *pdung_cels3++;
                *(_BYTE *)tmp_pbDst++ = l_tbl[v1];
                v22 = v27 & 1;
                v30 = v20 >> 2;
                if ( v22 )
                {
                  LOBYTE(v1) = pdung_cels3[1];
                  pdung_cels3 += 2;
                  *(_BYTE *)(tmp_pbDst + 1) = l_tbl[v1];
                  tmp_pbDst += 2;
                }
                if ( (_BYTE)v30 )
                {
                  do
                  {
                    v31 = *(_DWORD *)pdung_cels3;
                    pdung_cels3 += 4;
                    LOBYTE(v1) = BYTE1(v31);
                    v31 >>= 16;
                    *(_BYTE *)(tmp_pbDst + 1) = l_tbl[v1];
                    LOBYTE(v1) = BYTE1(v31);
                    tmp_pbDst += 4;
                    --v30;
                    *(_BYTE *)(tmp_pbDst - 1) = l_tbl[v1];
                  }
                  while ( v30 );
                }
              }
              else
              {
                v22 = v27 & 1;
                v28 = v20 >> 2;
                if ( v22 )
                {
                  LOBYTE(v1) = *pdung_cels3;
                  pdung_cels3 += 2;
                  *(_BYTE *)tmp_pbDst = l_tbl[v1];
                  tmp_pbDst += 2;
                }
                if ( (_BYTE)v28 )
                {
                  do
                  {
                    v29 = *(_DWORD *)pdung_cels3;
                    pdung_cels3 += 4;
                    LOBYTE(v1) = v29;
                    *(_BYTE *)tmp_pbDst = l_tbl[v1];
                    LOBYTE(v1) = BYTE2(v29);
                    tmp_pbDst += 4;
                    --v28;
                    *(_BYTE *)(tmp_pbDst - 2) = l_tbl[v1];
                  }
                  while ( v28 );
                }
              }
            }
          }
          else
          {
            pdung_cels3 += v20;
            tmp_pbDst += v20;
          }
        }
        while ( v19 );
LABEL_69:
        WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
        tmp_pbDst -= 800;
        v18 = v322 - 1;
      }
      while ( v322 != 1 );
      return;
    }
    if ( v5 != 2 )
    {
      if ( v5 != 3 )
      {
        if ( v5 != 4 )
        {
          WorldBoolFlag = 0;
          v121 = 30;
          if ( pbDst >= gpBufEnd )
          {
            v122 = (unsigned int)(pbDst - gpBufEnd + 1023) >> 8;
            if ( v122 > 45 )
            {
              tmp_pbDst = (unsigned int)(pbDst - 12288);
              pdung_cels3 += 288;
LABEL_249:
              v136 = 8;
              do
              {
                if ( tmp_pbDst < (unsigned int)gpBufEnd )
                {
                  v137 = 8;
                  do
                  {
                    v138 = *(_DWORD *)pdung_cels3;
                    pdung_cels3 += 4;
                    LOBYTE(v1) = BYTE1(v138);
                    v138 >>= 16;
                    *(_BYTE *)(tmp_pbDst + 1) = l_tbl[v1];
                    LOBYTE(v1) = BYTE1(v138);
                    tmp_pbDst += 4;
                    --v137;
                    *(_BYTE *)(tmp_pbDst - 1) = l_tbl[v1];
                  }
                  while ( v137 );
                }
                else
                {
                  pdung_cels3 += 32;
                  tmp_pbDst += 32;
                }
                v139 = (unsigned __int8 *)(tmp_pbDst - 800);
                if ( v139 < gpBufEnd )
                {
                  v140 = 8;
                  do
                  {
                    v141 = *(_DWORD *)pdung_cels3;
                    pdung_cels3 += 4;
                    LOBYTE(v1) = v141;
                    *v139 = l_tbl[v1];
                    LOBYTE(v1) = BYTE2(v141);
                    v139 += 4;
                    --v140;
                    *(v139 - 2) = l_tbl[v1];
                  }
                  while ( v140 );
                }
                else
                {
                  pdung_cels3 += 32;
                  v139 += 32;
                }
                tmp_pbDst = (unsigned int)(v139 - 800);
                --v136;
              }
              while ( v136 );
              return;
            }
            v123 = WorldTbl3x16[v122];
            pdung_cels3 += *(int *)((char *)WorldTbl17_1 + v123);
            v124 = 192 * v123;
            v123 >>= 1;
            tmp_pbDst -= v124;
            v121 = 30 - v123;
            WorldBoolFlag += v123 >> 1;
          }
          do
          {
            v125 = 32 - v121;
            WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
            if ( WorldBoolFlag )
            {
              v22 = v125 & 1;
              v126 = v125 >> 1;
              if ( v22 )
              {
                ++pdung_cels3;
                ++tmp_pbDst;
                v22 = v126 & 1;
                v129 = v126 >> 1;
                if ( v22 )
                {
                  LOBYTE(v1) = *pdung_cels3;
                  pdung_cels3 += 2;
                  *(_BYTE *)tmp_pbDst = l_tbl[v1];
                  tmp_pbDst += 2;
                }
                if ( (_BYTE)v129 )
                {
                  do
                  {
                    v130 = *(_DWORD *)pdung_cels3;
                    pdung_cels3 += 4;
                    LOBYTE(v1) = v130;
                    *(_BYTE *)tmp_pbDst = l_tbl[v1];
                    LOBYTE(v1) = BYTE2(v130);
                    tmp_pbDst += 4;
                    --v129;
                    *(_BYTE *)(tmp_pbDst - 2) = l_tbl[v1];
                  }
                  while ( v129 );
                }
              }
              else
              {
                v22 = v126 & 1;
                v127 = v126 >> 1;
                if ( v22 )
                {
                  LOBYTE(v1) = pdung_cels3[1];
                  pdung_cels3 += 2;
                  *(_BYTE *)(tmp_pbDst + 1) = l_tbl[v1];
                  tmp_pbDst += 2;
                }
                if ( (_BYTE)v127 )
                {
                  do
                  {
                    v128 = *(_DWORD *)pdung_cels3;
                    pdung_cels3 += 4;
                    LOBYTE(v1) = BYTE1(v128);
                    v128 >>= 16;
                    *(_BYTE *)(tmp_pbDst + 1) = l_tbl[v1];
                    LOBYTE(v1) = BYTE1(v128);
                    tmp_pbDst += 4;
                    --v127;
                    *(_BYTE *)(tmp_pbDst - 1) = l_tbl[v1];
                  }
                  while ( v127 );
                }
              }
              v1 = (unsigned __int8)pdung_cels3 & 2;
              pdung_cels3 += v1;
            }
            else
            {
              v22 = v125 & 1;
              v131 = v125 >> 1;
              if ( v22 )
              {
                LOBYTE(v1) = *pdung_cels3++;
                *(_BYTE *)tmp_pbDst++ = l_tbl[v1];
                v22 = v131 & 1;
                v134 = v131 >> 1;
                if ( v22 )
                {
                  LOBYTE(v1) = pdung_cels3[1];
                  pdung_cels3 += 2;
                  *(_BYTE *)(tmp_pbDst + 1) = l_tbl[v1];
                  tmp_pbDst += 2;
                }
                if ( (_BYTE)v134 )
                {
                  do
                  {
                    v135 = *(_DWORD *)pdung_cels3;
                    pdung_cels3 += 4;
                    LOBYTE(v1) = BYTE1(v135);
                    v135 >>= 16;
                    *(_BYTE *)(tmp_pbDst + 1) = l_tbl[v1];
                    LOBYTE(v1) = BYTE1(v135);
                    tmp_pbDst += 4;
                    --v134;
                    *(_BYTE *)(tmp_pbDst - 1) = l_tbl[v1];
                  }
                  while ( v134 );
                }
              }
              else
              {
                v22 = v131 & 1;
                v132 = v131 >> 1;
                if ( v22 )
                {
                  LOBYTE(v1) = *pdung_cels3;
                  pdung_cels3 += 2;
                  *(_BYTE *)tmp_pbDst = l_tbl[v1];
                  tmp_pbDst += 2;
                }
                if ( (_BYTE)v132 )
                {
                  do
                  {
                    v133 = *(_DWORD *)pdung_cels3;
                    pdung_cels3 += 4;
                    LOBYTE(v1) = v133;
                    *(_BYTE *)tmp_pbDst = l_tbl[v1];
                    LOBYTE(v1) = BYTE2(v133);
                    tmp_pbDst += 4;
                    --v132;
                    *(_BYTE *)(tmp_pbDst - 2) = l_tbl[v1];
                  }
                  while ( v132 );
                }
              }
              v1 = (unsigned __int8)pdung_cels3 & 2;
              pdung_cels3 += v1;
            }
            tmp_pbDst = v121 + tmp_pbDst - 800;
            v50 = __OFSUB__(v121, 2);
            v121 -= 2;
          }
          while ( !((v121 < 0) ^ v50) );
          goto LABEL_249;
        }
        WorldBoolFlag = 0;
        v99 = 30;
        if ( pbDst >= gpBufEnd )
        {
          v100 = (unsigned int)(pbDst - gpBufEnd + 1023) >> 8;
          if ( v100 > 45 )
          {
            tmp_pbDst = (unsigned int)(pbDst - 12288);
            pdung_cels3 += 288;
LABEL_210:
            v115 = 8;
            do
            {
              if ( tmp_pbDst < (unsigned int)gpBufEnd )
              {
                v116 = 8;
                do
                {
                  v117 = *(_DWORD *)pdung_cels3;
                  pdung_cels3 += 4;
                  LOBYTE(v1) = BYTE1(v117);
                  v117 >>= 16;
                  *(_BYTE *)(tmp_pbDst + 1) = l_tbl[v1];
                  LOBYTE(v1) = BYTE1(v117);
                  tmp_pbDst += 4;
                  --v116;
                  *(_BYTE *)(tmp_pbDst - 1) = l_tbl[v1];
                }
                while ( v116 );
              }
              else
              {
                pdung_cels3 += 32;
                tmp_pbDst += 32;
              }
              v118 = (unsigned __int8 *)(tmp_pbDst - 800);
              if ( v118 < gpBufEnd )
              {
                v119 = 8;
                do
                {
                  v120 = *(_DWORD *)pdung_cels3;
                  pdung_cels3 += 4;
                  LOBYTE(v1) = v120;
                  *v118 = l_tbl[v1];
                  LOBYTE(v1) = BYTE2(v120);
                  v118 += 4;
                  --v119;
                  *(v118 - 2) = l_tbl[v1];
                }
                while ( v119 );
              }
              else
              {
                pdung_cels3 += 32;
                v118 += 32;
              }
              tmp_pbDst = (unsigned int)(v118 - 800);
              --v115;
            }
            while ( v115 );
            return;
          }
          v101 = WorldTbl3x16[v100];
          pdung_cels3 += *(int *)((char *)WorldTbl17_1 + v101);
          v102 = 192 * v101;
          v101 >>= 1;
          tmp_pbDst -= v102;
          v99 = 30 - v101;
          WorldBoolFlag += v101 >> 1;
        }
        do
        {
          v103 = (_BYTE *)(v99 + tmp_pbDst);
          v104 = 32 - v99;
          WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
          if ( WorldBoolFlag )
          {
            v1 = v104 & 2;
            pdung_cels3 += v1;
            v22 = v104 & 1;
            v105 = v104 >> 1;
            if ( v22 )
            {
              ++pdung_cels3;
              ++v103;
              v22 = v105 & 1;
              v108 = v105 >> 1;
              if ( v22 )
              {
                LOBYTE(v1) = *pdung_cels3;
                pdung_cels3 += 2;
                *v103 = l_tbl[v1];
                v103 += 2;
              }
              if ( (_BYTE)v108 )
              {
                do
                {
                  v109 = *(_DWORD *)pdung_cels3;
                  pdung_cels3 += 4;
                  LOBYTE(v1) = v109;
                  *v103 = l_tbl[v1];
                  LOBYTE(v1) = BYTE2(v109);
                  v103 += 4;
                  --v108;
                  *(v103 - 2) = l_tbl[v1];
                }
                while ( v108 );
              }
            }
            else
            {
              v22 = v105 & 1;
              v106 = v105 >> 1;
              if ( v22 )
              {
                LOBYTE(v1) = pdung_cels3[1];
                pdung_cels3 += 2;
                v103[1] = l_tbl[v1];
                v103 += 2;
              }
              if ( (_BYTE)v106 )
              {
                do
                {
                  v107 = *(_DWORD *)pdung_cels3;
                  pdung_cels3 += 4;
                  LOBYTE(v1) = BYTE1(v107);
                  v107 >>= 16;
                  v103[1] = l_tbl[v1];
                  LOBYTE(v1) = BYTE1(v107);
                  v103 += 4;
                  --v106;
                  *(v103 - 1) = l_tbl[v1];
                }
                while ( v106 );
              }
            }
          }
          else
          {
            v1 = v104 & 2;
            pdung_cels3 += v1;
            v22 = v104 & 1;
            v110 = v104 >> 1;
            if ( v22 )
            {
              LOBYTE(v1) = *pdung_cels3++;
              *v103++ = l_tbl[v1];
              v22 = v110 & 1;
              v113 = v110 >> 1;
              if ( v22 )
              {
                LOBYTE(v1) = pdung_cels3[1];
                pdung_cels3 += 2;
                v103[1] = l_tbl[v1];
                v103 += 2;
              }
              if ( (_BYTE)v113 )
              {
                do
                {
                  v114 = *(_DWORD *)pdung_cels3;
                  pdung_cels3 += 4;
                  LOBYTE(v1) = BYTE1(v114);
                  v114 >>= 16;
                  v103[1] = l_tbl[v1];
                  LOBYTE(v1) = BYTE1(v114);
                  v103 += 4;
                  --v113;
                  *(v103 - 1) = l_tbl[v1];
                }
                while ( v113 );
              }
            }
            else
            {
              v22 = v110 & 1;
              v111 = v110 >> 1;
              if ( v22 )
              {
                LOBYTE(v1) = *pdung_cels3;
                pdung_cels3 += 2;
                *v103 = l_tbl[v1];
                v103 += 2;
              }
              if ( (_BYTE)v111 )
              {
                do
                {
                  v112 = *(_DWORD *)pdung_cels3;
                  pdung_cels3 += 4;
                  LOBYTE(v1) = v112;
                  *v103 = l_tbl[v1];
                  LOBYTE(v1) = BYTE2(v112);
                  v103 += 4;
                  --v111;
                  *(v103 - 2) = l_tbl[v1];
                }
                while ( v111 );
              }
            }
          }
          tmp_pbDst = (unsigned int)(v103 - 800);
          v50 = __OFSUB__(v99, 2);
          v99 -= 2;
        }
        while ( !((v99 < 0) ^ v50) );
        goto LABEL_210;
      }
      WorldBoolFlag = 0;
      v69 = 30;
      if ( pbDst >= gpBufEnd )
      {
        v70 = (unsigned int)(pbDst - gpBufEnd + 1023) >> 8;
        if ( v70 > 45 )
        {
          tmp_pbDst = (unsigned int)(pbDst - 12288);
          pdung_cels3 += 288;
LABEL_154:
          v84 = 2;
          if ( tmp_pbDst >= (unsigned int)gpBufEnd )
          {
            v85 = (tmp_pbDst - (unsigned int)gpBufEnd + 1023) >> 8;
            if ( v85 > 42 )
              return;
            v86 = WorldTbl3x16[v85];
            pdung_cels3 += *(int *)((char *)WorldTbl17_2 + v86);
            v87 = 192 * v86;
            v86 >>= 1;
            tmp_pbDst -= v87;
            v84 = v86 + 2;
            WorldBoolFlag += v86 >> 1;
          }
          do
          {
            v88 = 32 - v84;
            WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
            if ( WorldBoolFlag )
            {
              v22 = v88 & 1;
              v89 = v88 >> 1;
              if ( v22 )
              {
                ++pdung_cels3;
                ++tmp_pbDst;
                v22 = v89 & 1;
                v92 = v89 >> 1;
                if ( v22 )
                {
                  LOBYTE(v1) = *pdung_cels3;
                  pdung_cels3 += 2;
                  *(_BYTE *)tmp_pbDst = l_tbl[v1];
                  tmp_pbDst += 2;
                }
                if ( (_BYTE)v92 )
                {
                  do
                  {
                    v93 = *(_DWORD *)pdung_cels3;
                    pdung_cels3 += 4;
                    LOBYTE(v1) = v93;
                    *(_BYTE *)tmp_pbDst = l_tbl[v1];
                    LOBYTE(v1) = BYTE2(v93);
                    tmp_pbDst += 4;
                    --v92;
                    *(_BYTE *)(tmp_pbDst - 2) = l_tbl[v1];
                  }
                  while ( v92 );
                }
              }
              else
              {
                v22 = v89 & 1;
                v90 = v89 >> 1;
                if ( v22 )
                {
                  LOBYTE(v1) = pdung_cels3[1];
                  pdung_cels3 += 2;
                  *(_BYTE *)(tmp_pbDst + 1) = l_tbl[v1];
                  tmp_pbDst += 2;
                }
                if ( (_BYTE)v90 )
                {
                  do
                  {
                    v91 = *(_DWORD *)pdung_cels3;
                    pdung_cels3 += 4;
                    LOBYTE(v1) = BYTE1(v91);
                    v91 >>= 16;
                    *(_BYTE *)(tmp_pbDst + 1) = l_tbl[v1];
                    LOBYTE(v1) = BYTE1(v91);
                    tmp_pbDst += 4;
                    --v90;
                    *(_BYTE *)(tmp_pbDst - 1) = l_tbl[v1];
                  }
                  while ( v90 );
                }
              }
              v1 = (unsigned __int8)pdung_cels3 & 2;
              pdung_cels3 += v1;
            }
            else
            {
              v22 = v88 & 1;
              v94 = v88 >> 1;
              if ( v22 )
              {
                LOBYTE(v1) = *pdung_cels3++;
                *(_BYTE *)tmp_pbDst++ = l_tbl[v1];
                v22 = v94 & 1;
                v97 = v94 >> 1;
                if ( v22 )
                {
                  LOBYTE(v1) = pdung_cels3[1];
                  pdung_cels3 += 2;
                  *(_BYTE *)(tmp_pbDst + 1) = l_tbl[v1];
                  tmp_pbDst += 2;
                }
                if ( (_BYTE)v97 )
                {
                  do
                  {
                    v98 = *(_DWORD *)pdung_cels3;
                    pdung_cels3 += 4;
                    LOBYTE(v1) = BYTE1(v98);
                    v98 >>= 16;
                    *(_BYTE *)(tmp_pbDst + 1) = l_tbl[v1];
                    LOBYTE(v1) = BYTE1(v98);
                    tmp_pbDst += 4;
                    --v97;
                    *(_BYTE *)(tmp_pbDst - 1) = l_tbl[v1];
                  }
                  while ( v97 );
                }
              }
              else
              {
                v22 = v94 & 1;
                v95 = v94 >> 1;
                if ( v22 )
                {
                  LOBYTE(v1) = *pdung_cels3;
                  pdung_cels3 += 2;
                  *(_BYTE *)tmp_pbDst = l_tbl[v1];
                  tmp_pbDst += 2;
                }
                if ( (_BYTE)v95 )
                {
                  do
                  {
                    v96 = *(_DWORD *)pdung_cels3;
                    pdung_cels3 += 4;
                    LOBYTE(v1) = v96;
                    *(_BYTE *)tmp_pbDst = l_tbl[v1];
                    LOBYTE(v1) = BYTE2(v96);
                    tmp_pbDst += 4;
                    --v95;
                    *(_BYTE *)(tmp_pbDst - 2) = l_tbl[v1];
                  }
                  while ( v95 );
                }
              }
              v1 = (unsigned __int8)pdung_cels3 & 2;
              pdung_cels3 += v1;
            }
            tmp_pbDst = v84 + tmp_pbDst - 800;
            v84 += 2;
          }
          while ( v84 != 32 );
          return;
        }
        v71 = WorldTbl3x16[v70];
        pdung_cels3 += *(int *)((char *)WorldTbl17_1 + v71);
        v72 = 192 * v71;
        v71 >>= 1;
        tmp_pbDst -= v72;
        v69 = 30 - v71;
        WorldBoolFlag += v71 >> 1;
      }
      do
      {
        v73 = 32 - v69;
        WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
        if ( WorldBoolFlag )
        {
          v22 = v73 & 1;
          v74 = v73 >> 1;
          if ( v22 )
          {
            ++pdung_cels3;
            ++tmp_pbDst;
            v22 = v74 & 1;
            v77 = v74 >> 1;
            if ( v22 )
            {
              LOBYTE(v1) = *pdung_cels3;
              pdung_cels3 += 2;
              *(_BYTE *)tmp_pbDst = l_tbl[v1];
              tmp_pbDst += 2;
            }
            if ( (_BYTE)v77 )
            {
              do
              {
                v78 = *(_DWORD *)pdung_cels3;
                pdung_cels3 += 4;
                LOBYTE(v1) = v78;
                *(_BYTE *)tmp_pbDst = l_tbl[v1];
                LOBYTE(v1) = BYTE2(v78);
                tmp_pbDst += 4;
                --v77;
                *(_BYTE *)(tmp_pbDst - 2) = l_tbl[v1];
              }
              while ( v77 );
            }
          }
          else
          {
            v22 = v74 & 1;
            v75 = v74 >> 1;
            if ( v22 )
            {
              LOBYTE(v1) = pdung_cels3[1];
              pdung_cels3 += 2;
              *(_BYTE *)(tmp_pbDst + 1) = l_tbl[v1];
              tmp_pbDst += 2;
            }
            if ( (_BYTE)v75 )
            {
              do
              {
                v76 = *(_DWORD *)pdung_cels3;
                pdung_cels3 += 4;
                LOBYTE(v1) = BYTE1(v76);
                v76 >>= 16;
                *(_BYTE *)(tmp_pbDst + 1) = l_tbl[v1];
                LOBYTE(v1) = BYTE1(v76);
                tmp_pbDst += 4;
                --v75;
                *(_BYTE *)(tmp_pbDst - 1) = l_tbl[v1];
              }
              while ( v75 );
            }
          }
          v1 = (unsigned __int8)pdung_cels3 & 2;
          pdung_cels3 += v1;
        }
        else
        {
          v22 = v73 & 1;
          v79 = v73 >> 1;
          if ( v22 )
          {
            LOBYTE(v1) = *pdung_cels3++;
            *(_BYTE *)tmp_pbDst++ = l_tbl[v1];
            v22 = v79 & 1;
            v82 = v79 >> 1;
            if ( v22 )
            {
              LOBYTE(v1) = pdung_cels3[1];
              pdung_cels3 += 2;
              *(_BYTE *)(tmp_pbDst + 1) = l_tbl[v1];
              tmp_pbDst += 2;
            }
            if ( (_BYTE)v82 )
            {
              do
              {
                v83 = *(_DWORD *)pdung_cels3;
                pdung_cels3 += 4;
                LOBYTE(v1) = BYTE1(v83);
                v83 >>= 16;
                *(_BYTE *)(tmp_pbDst + 1) = l_tbl[v1];
                LOBYTE(v1) = BYTE1(v83);
                tmp_pbDst += 4;
                --v82;
                *(_BYTE *)(tmp_pbDst - 1) = l_tbl[v1];
              }
              while ( v82 );
            }
          }
          else
          {
            v22 = v79 & 1;
            v80 = v79 >> 1;
            if ( v22 )
            {
              LOBYTE(v1) = *pdung_cels3;
              pdung_cels3 += 2;
              *(_BYTE *)tmp_pbDst = l_tbl[v1];
              tmp_pbDst += 2;
            }
            if ( (_BYTE)v80 )
            {
              do
              {
                v81 = *(_DWORD *)pdung_cels3;
                pdung_cels3 += 4;
                LOBYTE(v1) = v81;
                *(_BYTE *)tmp_pbDst = l_tbl[v1];
                LOBYTE(v1) = BYTE2(v81);
                tmp_pbDst += 4;
                --v80;
                *(_BYTE *)(tmp_pbDst - 2) = l_tbl[v1];
              }
              while ( v80 );
            }
          }
          v1 = (unsigned __int8)pdung_cels3 & 2;
          pdung_cels3 += v1;
        }
        tmp_pbDst = v69 + tmp_pbDst - 800;
        v50 = __OFSUB__(v69, 2);
        v69 -= 2;
      }
      while ( !((v69 < 0) ^ v50) );
      goto LABEL_154;
    }
    WorldBoolFlag = 0;
    v32 = 30;
    if ( pbDst >= gpBufEnd )
    {
      v33 = (unsigned int)(pbDst - gpBufEnd + 1023) >> 8;
      if ( v33 > 45 )
      {
        tmp_pbDst = (unsigned int)(pbDst - 12288);
        pdung_cels3 += 288;
LABEL_98:
        v51 = 2;
        if ( tmp_pbDst >= (unsigned int)gpBufEnd )
        {
          v52 = (tmp_pbDst - (unsigned int)gpBufEnd + 1023) >> 8;
          if ( v52 > 42 )
            return;
          v53 = WorldTbl3x16[v52];
          pdung_cels3 += *(int *)((char *)WorldTbl17_2 + v53);
          v54 = 192 * v53;
          v53 >>= 1;
          tmp_pbDst -= v54;
          v51 = v53 + 2;
          WorldBoolFlag += v53 >> 1;
        }
        do
        {
          v55 = (_BYTE *)(v51 + tmp_pbDst);
          v56 = 32 - v51;
          WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
          if ( WorldBoolFlag )
          {
            v57 = v56 & 2;
            pdung_cels3 += v57;
            v22 = v56 & 1;
            v58 = v56 >> 1;
            if ( v22 )
            {
              ++pdung_cels3;
              ++v55;
              v22 = v58 & 1;
              v61 = v58 >> 1;
              if ( v22 )
              {
                LOBYTE(v57) = *pdung_cels3;
                pdung_cels3 += 2;
                *v55 = l_tbl[v57];
                v55 += 2;
              }
              if ( (_BYTE)v61 )
              {
                do
                {
                  v62 = *(_DWORD *)pdung_cels3;
                  pdung_cels3 += 4;
                  LOBYTE(v57) = v62;
                  *v55 = l_tbl[v57];
                  LOBYTE(v57) = BYTE2(v62);
                  v55 += 4;
                  --v61;
                  *(v55 - 2) = l_tbl[v57];
                }
                while ( v61 );
              }
            }
            else
            {
              v22 = v58 & 1;
              v59 = v58 >> 1;
              if ( v22 )
              {
                LOBYTE(v57) = pdung_cels3[1];
                pdung_cels3 += 2;
                v55[1] = l_tbl[v57];
                v55 += 2;
              }
              if ( (_BYTE)v59 )
              {
                do
                {
                  v60 = *(_DWORD *)pdung_cels3;
                  pdung_cels3 += 4;
                  LOBYTE(v57) = BYTE1(v60);
                  v60 >>= 16;
                  v55[1] = l_tbl[v57];
                  LOBYTE(v57) = BYTE1(v60);
                  v55 += 4;
                  --v59;
                  *(v55 - 1) = l_tbl[v57];
                }
                while ( v59 );
              }
            }
          }
          else
          {
            v63 = v56 & 2;
            pdung_cels3 += v63;
            v22 = v56 & 1;
            v64 = v56 >> 1;
            if ( v22 )
            {
              LOBYTE(v63) = *pdung_cels3++;
              *v55++ = l_tbl[v63];
              v22 = v64 & 1;
              v67 = v64 >> 1;
              if ( v22 )
              {
                LOBYTE(v63) = pdung_cels3[1];
                pdung_cels3 += 2;
                v55[1] = l_tbl[v63];
                v55 += 2;
              }
              if ( (_BYTE)v67 )
              {
                do
                {
                  v68 = *(_DWORD *)pdung_cels3;
                  pdung_cels3 += 4;
                  LOBYTE(v63) = BYTE1(v68);
                  v68 >>= 16;
                  v55[1] = l_tbl[v63];
                  LOBYTE(v63) = BYTE1(v68);
                  v55 += 4;
                  --v67;
                  *(v55 - 1) = l_tbl[v63];
                }
                while ( v67 );
              }
            }
            else
            {
              v22 = v64 & 1;
              v65 = v64 >> 1;
              if ( v22 )
              {
                LOBYTE(v63) = *pdung_cels3;
                pdung_cels3 += 2;
                *v55 = l_tbl[v63];
                v55 += 2;
              }
              if ( (_BYTE)v65 )
              {
                do
                {
                  v66 = *(_DWORD *)pdung_cels3;
                  pdung_cels3 += 4;
                  LOBYTE(v63) = v66;
                  *v55 = l_tbl[v63];
                  LOBYTE(v63) = BYTE2(v66);
                  v55 += 4;
                  --v65;
                  *(v55 - 2) = l_tbl[v63];
                }
                while ( v65 );
              }
            }
          }
          tmp_pbDst = (unsigned int)(v55 - 800);
          v51 += 2;
        }
        while ( v51 != 32 );
        return;
      }
      v34 = WorldTbl3x16[v33];
      pdung_cels3 += *(int *)((char *)WorldTbl17_1 + v34);
      v35 = 192 * v34;
      v34 >>= 1;
      tmp_pbDst -= v35;
      v32 = 30 - v34;
      WorldBoolFlag += v34 >> 1;
    }
    do
    {
      v36 = (_BYTE *)(v32 + tmp_pbDst);
      v37 = 32 - v32;
      WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
      if ( WorldBoolFlag )
      {
        v38 = v37 & 2;
        pdung_cels3 += v38;
        v22 = v37 & 1;
        v39 = v37 >> 1;
        if ( v22 )
        {
          ++pdung_cels3;
          ++v36;
          v22 = v39 & 1;
          v42 = v39 >> 1;
          if ( v22 )
          {
            LOBYTE(v38) = *pdung_cels3;
            pdung_cels3 += 2;
            *v36 = l_tbl[v38];
            v36 += 2;
          }
          if ( (_BYTE)v42 )
          {
            do
            {
              v43 = *(_DWORD *)pdung_cels3;
              pdung_cels3 += 4;
              LOBYTE(v38) = v43;
              *v36 = l_tbl[v38];
              LOBYTE(v38) = BYTE2(v43);
              v36 += 4;
              --v42;
              *(v36 - 2) = l_tbl[v38];
            }
            while ( v42 );
          }
        }
        else
        {
          v22 = v39 & 1;
          v40 = v39 >> 1;
          if ( v22 )
          {
            LOBYTE(v38) = pdung_cels3[1];
            pdung_cels3 += 2;
            v36[1] = l_tbl[v38];
            v36 += 2;
          }
          if ( (_BYTE)v40 )
          {
            do
            {
              v41 = *(_DWORD *)pdung_cels3;
              pdung_cels3 += 4;
              LOBYTE(v38) = BYTE1(v41);
              v41 >>= 16;
              v36[1] = l_tbl[v38];
              LOBYTE(v38) = BYTE1(v41);
              v36 += 4;
              --v40;
              *(v36 - 1) = l_tbl[v38];
            }
            while ( v40 );
          }
        }
      }
      else
      {
        v44 = v37 & 2;
        pdung_cels3 += v44;
        v22 = v37 & 1;
        v45 = v37 >> 1;
        if ( v22 )
        {
          LOBYTE(v44) = *pdung_cels3++;
          *v36++ = l_tbl[v44];
          v22 = v45 & 1;
          v48 = v45 >> 1;
          if ( v22 )
          {
            LOBYTE(v44) = pdung_cels3[1];
            pdung_cels3 += 2;
            v36[1] = l_tbl[v44];
            v36 += 2;
          }
          if ( (_BYTE)v48 )
          {
            do
            {
              v49 = *(_DWORD *)pdung_cels3;
              pdung_cels3 += 4;
              LOBYTE(v44) = BYTE1(v49);
              v49 >>= 16;
              v36[1] = l_tbl[v44];
              LOBYTE(v44) = BYTE1(v49);
              v36 += 4;
              --v48;
              *(v36 - 1) = l_tbl[v44];
            }
            while ( v48 );
          }
        }
        else
        {
          v22 = v45 & 1;
          v46 = v45 >> 1;
          if ( v22 )
          {
            LOBYTE(v44) = *pdung_cels3;
            pdung_cels3 += 2;
            *v36 = l_tbl[v44];
            v36 += 2;
          }
          if ( (_BYTE)v46 )
          {
            do
            {
              v47 = *(_DWORD *)pdung_cels3;
              pdung_cels3 += 4;
              LOBYTE(v44) = v47;
              *v36 = l_tbl[v44];
              LOBYTE(v44) = BYTE2(v47);
              v36 += 4;
              --v46;
              *(v36 - 2) = l_tbl[v44];
            }
            while ( v46 );
          }
        }
      }
      tmp_pbDst = (unsigned int)(v36 - 800);
      v50 = __OFSUB__(v32, 2);
      v32 -= 2;
    }
    while ( !((v32 < 0) ^ v50) );
    goto LABEL_98;
  }
  pdung_cels = (char *)pSpeedCels + *(_DWORD *)&gpCelFrame[4 * (light_table_index + 16 * (level_cel_block & 0xFFF))];
  v7 = (unsigned __int8)(BYTE1(level_cel_block) >> 4);
LABEL_11:
  switch ( v7 )
  {
    case 8:
      v142 = 16;
      do
      {
        if ( tmp_pbDst < (unsigned int)gpBufEnd )
        {
          v143 = 8;
          do
          {
            v144 = *(_DWORD *)pdung_cels;
            pdung_cels += 4;
            v145 = (_BYTE *)(tmp_pbDst + 1);
            v144 = __ROR4__(v144, 8);
            *v145 = v144;
            v145 += 2;
            *v145 = __ROR4__(v144, 16);
            tmp_pbDst = (unsigned int)(v145 + 1);
            --v143;
          }
          while ( v143 );
        }
        else
        {
          pdung_cels += 32;
          tmp_pbDst += 32;
        }
        v146 = (unsigned __int8 *)(tmp_pbDst - 800);
        if ( v146 < gpBufEnd )
        {
          v147 = 8;
          do
          {
            v148 = *(_DWORD *)pdung_cels;
            pdung_cels += 4;
            *v146 = v148;
            v149 = v146 + 2;
            *v149 = __ROR4__(v148, 16);
            v146 = v149 + 2;
            --v147;
          }
          while ( v147 );
        }
        else
        {
          pdung_cels += 32;
          v146 += 32;
        }
        tmp_pbDst = (unsigned int)(v146 - 800);
        --v142;
      }
      while ( v142 );
      return;
    case 9:
      WorldBoolFlag = (unsigned __int8)pbDst & 1;
      v150 = 32;
      while ( 1 )
      {
        v323 = v150;
        v151 = 32;
        do
        {
          while ( 1 )
          {
            v152 = (unsigned __int8)*pdung_cels++;
            if ( (v152 & 0x80u) != 0 )
              break;
            v151 -= v152;
            if ( tmp_pbDst < (unsigned int)gpBufEnd )
            {
              if ( (tmp_pbDst & 1) == WorldBoolFlag )
              {
                v153 = v152 >> 1;
                if ( !(v152 & 1) )
                  goto LABEL_280;
                ++pdung_cels;
                ++tmp_pbDst;
                if ( v153 )
                {
LABEL_287:
                  v22 = v153 & 1;
                  v161 = v153 >> 1;
                  if ( !v22 || (v162 = *pdung_cels, pdung_cels += 2, *(_BYTE *)tmp_pbDst = v162, tmp_pbDst += 2, v161) )
                  {
                    do
                    {
                      v163 = *(_DWORD *)pdung_cels;
                      pdung_cels += 4;
                      *(_BYTE *)tmp_pbDst = v163;
                      v164 = (_BYTE *)(tmp_pbDst + 2);
                      *v164 = __ROR4__(v163, 16);
                      tmp_pbDst = (unsigned int)(v164 + 2);
                      --v161;
                    }
                    while ( v161 );
                  }
                  goto LABEL_290;
                }
              }
              else
              {
                v153 = v152 >> 1;
                if ( !(v152 & 1) )
                  goto LABEL_287;
                v160 = *pdung_cels++;
                *(_BYTE *)tmp_pbDst++ = v160;
                if ( v153 )
                {
LABEL_280:
                  v22 = v153 & 1;
                  v154 = v153 >> 1;
                  if ( !v22
                    || (v155 = pdung_cels + 1,
                        v156 = (_BYTE *)(tmp_pbDst + 1),
                        v157 = *v155,
                        pdung_cels = v155 + 1,
                        *v156 = v157,
                        tmp_pbDst = (unsigned int)(v156 + 1),
                        v154) )
                  {
                    do
                    {
                      v158 = *(_DWORD *)pdung_cels;
                      pdung_cels += 4;
                      v159 = (_BYTE *)(tmp_pbDst + 1);
                      v158 = __ROR4__(v158, 8);
                      *v159 = v158;
                      v159 += 2;
                      *v159 = __ROR4__(v158, 16);
                      tmp_pbDst = (unsigned int)(v159 + 1);
                      --v154;
                    }
                    while ( v154 );
                  }
                  goto LABEL_290;
                }
              }
            }
            else
            {
              pdung_cels += v152;
              tmp_pbDst += v152;
            }
LABEL_290:
            if ( !v151 )
              goto LABEL_293;
          }
          LOBYTE(v152) = -(char)v152;
          tmp_pbDst += v152;
          v151 -= v152;
        }
        while ( v151 );
LABEL_293:
        WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
        tmp_pbDst -= 800;
        v150 = v323 - 1;
        if ( v323 == 1 )
          return;
      }
    case 10:
      WorldBoolFlag = 0;
      v165 = 30;
      if ( pbDst >= gpBufEnd )
      {
        v166 = (unsigned int)(pbDst - gpBufEnd + 1023) >> 8;
        if ( v166 > 45 )
        {
          tmp_pbDst = (unsigned int)(pbDst - 12288);
          pdung_cels += 288;
LABEL_308:
          v180 = 2;
          if ( tmp_pbDst >= (unsigned int)gpBufEnd )
          {
            v181 = (tmp_pbDst - (unsigned int)gpBufEnd + 1023) >> 8;
            if ( v181 > 42 )
              return;
            v182 = WorldTbl3x16[v181];
            pdung_cels += *(int *)((char *)WorldTbl17_2 + v182);
            v183 = 192 * v182;
            v182 >>= 1;
            tmp_pbDst -= v183;
            v180 = v182 + 2;
            WorldBoolFlag += v182 >> 1;
          }
          do
          {
            v184 = (_BYTE *)(v180 + tmp_pbDst);
            v185 = 32 - v180;
            v186 = ((_BYTE)WorldBoolFlag + 1) & 1;
            WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
            if ( WorldBoolFlag )
            {
              v22 = __CFSHR__(v185, 2);
              v187 = v185 >> 2;
              if ( !v22
                || (LOWORD(v186) = *((_WORD *)pdung_cels + 1),
                    pdung_cels += 4,
                    v188 = v184 + 1,
                    *v188 = __ROR4__(v186, 8),
                    v184 = v188 + 1,
                    v187) )
              {
                do
                {
                  v189 = *(_DWORD *)pdung_cels;
                  pdung_cels += 4;
                  v190 = v184 + 1;
                  v189 = __ROR4__(v189, 8);
                  *v190 = v189;
                  v190 += 2;
                  *v190 = __ROR4__(v189, 16);
                  v184 = v190 + 1;
                  --v187;
                }
                while ( v187 );
              }
            }
            else
            {
              v22 = __CFSHR__(v185, 2);
              v191 = v185 >> 2;
              if ( !v22 || (v192 = *((_WORD *)pdung_cels + 1), pdung_cels += 4, *v184 = v192, v184 += 2, --v191, v191) )
              {
                do
                {
                  v193 = *(_DWORD *)pdung_cels;
                  pdung_cels += 4;
                  *v184 = v193;
                  v194 = v184 + 2;
                  *v194 = __ROR4__(v193, 16);
                  v184 = v194 + 2;
                  --v191;
                }
                while ( v191 );
              }
            }
            tmp_pbDst = (unsigned int)(v184 - 800);
            v180 += 2;
          }
          while ( v180 != 32 );
          return;
        }
        v167 = WorldTbl3x16[v166];
        pdung_cels += *(int *)((char *)WorldTbl17_1 + v167);
        v168 = 192 * v167;
        v167 >>= 1;
        tmp_pbDst -= v168;
        v165 = 30 - v167;
        WorldBoolFlag += v167 >> 1;
      }
      do
      {
        v169 = (_BYTE *)(v165 + tmp_pbDst);
        v170 = 32 - v165;
        v171 = ((_BYTE)WorldBoolFlag + 1) & 1;
        WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
        if ( WorldBoolFlag )
        {
          v22 = __CFSHR__(v170, 2);
          v172 = v170 >> 2;
          if ( !v22
            || (LOWORD(v171) = *((_WORD *)pdung_cels + 1),
                pdung_cels += 4,
                v173 = v169 + 1,
                *v173 = __ROR4__(v171, 8),
                v169 = v173 + 1,
                v172) )
          {
            do
            {
              v174 = *(_DWORD *)pdung_cels;
              pdung_cels += 4;
              v175 = v169 + 1;
              v174 = __ROR4__(v174, 8);
              *v175 = v174;
              v175 += 2;
              *v175 = __ROR4__(v174, 16);
              v169 = v175 + 1;
              --v172;
            }
            while ( v172 );
          }
        }
        else
        {
          v22 = __CFSHR__(v170, 2);
          v176 = v170 >> 2;
          if ( !v22 || (v177 = *((_WORD *)pdung_cels + 1), pdung_cels += 4, *v169 = v177, v169 += 2, v176) )
          {
            do
            {
              v178 = *(_DWORD *)pdung_cels;
              pdung_cels += 4;
              *v169 = v178;
              v179 = v169 + 2;
              *v179 = __ROR4__(v178, 16);
              v169 = v179 + 2;
              --v176;
            }
            while ( v176 );
          }
        }
        tmp_pbDst = (unsigned int)(v169 - 800);
        v50 = __OFSUB__(v165, 2);
        v165 -= 2;
      }
      while ( !((v165 < 0) ^ v50) );
      goto LABEL_308;
  }
  if ( v7 != 11 )
  {
    if ( v7 != 12 )
    {
      WorldBoolFlag = 0;
      v246 = 30;
      if ( pbDst >= gpBufEnd )
      {
        v247 = (unsigned int)(pbDst - gpBufEnd + 1023) >> 8;
        if ( v247 > 45 )
        {
          tmp_pbDst = (unsigned int)(pbDst - 12288);
          pdung_cels += 288;
LABEL_389:
          v260 = 8;
          do
          {
            if ( tmp_pbDst < (unsigned int)gpBufEnd )
            {
              v261 = 8;
              do
              {
                v262 = *(_DWORD *)pdung_cels;
                pdung_cels += 4;
                v263 = (_BYTE *)(tmp_pbDst + 1);
                v262 = __ROR4__(v262, 8);
                *v263 = v262;
                v263 += 2;
                *v263 = __ROR4__(v262, 16);
                tmp_pbDst = (unsigned int)(v263 + 1);
                --v261;
              }
              while ( v261 );
            }
            else
            {
              pdung_cels += 32;
              tmp_pbDst += 32;
            }
            v264 = (unsigned __int8 *)(tmp_pbDst - 800);
            if ( v264 < gpBufEnd )
            {
              v265 = 8;
              do
              {
                v266 = *(_DWORD *)pdung_cels;
                pdung_cels += 4;
                *v264 = v266;
                v267 = v264 + 2;
                *v267 = __ROR4__(v266, 16);
                v264 = v267 + 2;
                --v265;
              }
              while ( v265 );
            }
            else
            {
              pdung_cels += 32;
              v264 += 32;
            }
            tmp_pbDst = (unsigned int)(v264 - 800);
            --v260;
          }
          while ( v260 );
          return;
        }
        v248 = WorldTbl3x16[v247];
        pdung_cels += *(int *)((char *)WorldTbl17_1 + v248);
        v249 = 192 * v248;
        v248 >>= 1;
        tmp_pbDst -= v249;
        v246 = 30 - v248;
        WorldBoolFlag += v248 >> 1;
      }
      do
      {
        v250 = 32 - v246;
        v251 = ((_BYTE)WorldBoolFlag + 1) & 1;
        WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
        if ( WorldBoolFlag )
        {
          for ( m = v250 >> 2; m; --m )
          {
            v253 = *(_DWORD *)pdung_cels;
            pdung_cels += 4;
            v254 = (_BYTE *)(tmp_pbDst + 1);
            v253 = __ROR4__(v253, 8);
            *v254 = v253;
            v254 += 2;
            v251 = __ROR4__(v253, 16);
            *v254 = v251;
            tmp_pbDst = (unsigned int)(v254 + 1);
          }
          if ( (32 - (_BYTE)v246) & 2 )
          {
            LOWORD(v251) = *(_WORD *)pdung_cels;
            pdung_cels += 4;
            v255 = (_BYTE *)(tmp_pbDst + 1);
            *v255 = __ROR4__(v251, 8);
            tmp_pbDst = (unsigned int)(v255 + 1);
          }
        }
        else
        {
          for ( n = v250 >> 2; n; --n )
          {
            v257 = *(_DWORD *)pdung_cels;
            pdung_cels += 4;
            *(_BYTE *)tmp_pbDst = v257;
            v258 = (_BYTE *)(tmp_pbDst + 2);
            *v258 = __ROR4__(v257, 16);
            tmp_pbDst = (unsigned int)(v258 + 2);
          }
          if ( (32 - (_BYTE)v246) & 2 )
          {
            v259 = *(_WORD *)pdung_cels;
            pdung_cels += 4;
            *(_BYTE *)tmp_pbDst = v259;
            tmp_pbDst += 2;
          }
        }
        tmp_pbDst = v246 + tmp_pbDst - 800;
        v50 = __OFSUB__(v246, 2);
        v246 -= 2;
      }
      while ( !((v246 < 0) ^ v50) );
      goto LABEL_389;
    }
    WorldBoolFlag = 0;
    v223 = 30;
    if ( pbDst >= gpBufEnd )
    {
      v224 = (unsigned int)(pbDst - gpBufEnd + 1023) >> 8;
      if ( v224 > 45 )
      {
        tmp_pbDst = (unsigned int)(pbDst - 12288);
        pdung_cels += 288;
LABEL_364:
        v238 = 8;
        do
        {
          if ( tmp_pbDst < (unsigned int)gpBufEnd )
          {
            v239 = 8;
            do
            {
              v240 = *(_DWORD *)pdung_cels;
              pdung_cels += 4;
              v241 = (_BYTE *)(tmp_pbDst + 1);
              v240 = __ROR4__(v240, 8);
              *v241 = v240;
              v241 += 2;
              *v241 = __ROR4__(v240, 16);
              tmp_pbDst = (unsigned int)(v241 + 1);
              --v239;
            }
            while ( v239 );
          }
          else
          {
            pdung_cels += 32;
            tmp_pbDst += 32;
          }
          v242 = (unsigned __int8 *)(tmp_pbDst - 800);
          if ( v242 < gpBufEnd )
          {
            v243 = 8;
            do
            {
              v244 = *(_DWORD *)pdung_cels;
              pdung_cels += 4;
              *v242 = v244;
              v245 = v242 + 2;
              *v245 = __ROR4__(v244, 16);
              v242 = v245 + 2;
              --v243;
            }
            while ( v243 );
          }
          else
          {
            pdung_cels += 32;
            v242 += 32;
          }
          tmp_pbDst = (unsigned int)(v242 - 800);
          --v238;
        }
        while ( v238 );
        return;
      }
      v225 = WorldTbl3x16[v224];
      pdung_cels += *(int *)((char *)WorldTbl17_1 + v225);
      v226 = 192 * v225;
      v225 >>= 1;
      tmp_pbDst -= v226;
      v223 = 30 - v225;
      WorldBoolFlag += v225 >> 1;
    }
    do
    {
      v227 = (_BYTE *)(v223 + tmp_pbDst);
      v228 = 32 - v223;
      v229 = ((_BYTE)WorldBoolFlag + 1) & 1;
      WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
      if ( WorldBoolFlag )
      {
        v22 = __CFSHR__(v228, 2);
        v230 = v228 >> 2;
        if ( !v22
          || (LOWORD(v229) = *((_WORD *)pdung_cels + 1),
              pdung_cels += 4,
              v231 = v227 + 1,
              *v231 = __ROR4__(v229, 8),
              v227 = v231 + 1,
              v230) )
        {
          do
          {
            v232 = *(_DWORD *)pdung_cels;
            pdung_cels += 4;
            v233 = v227 + 1;
            v232 = __ROR4__(v232, 8);
            *v233 = v232;
            v233 += 2;
            *v233 = __ROR4__(v232, 16);
            v227 = v233 + 1;
            --v230;
          }
          while ( v230 );
        }
      }
      else
      {
        v22 = __CFSHR__(v228, 2);
        v234 = v228 >> 2;
        if ( !v22 || (v235 = *((_WORD *)pdung_cels + 1), pdung_cels += 4, *v227 = v235, v227 += 2, v234) )
        {
          do
          {
            v236 = *(_DWORD *)pdung_cels;
            pdung_cels += 4;
            *v227 = v236;
            v237 = v227 + 2;
            *v237 = __ROR4__(v236, 16);
            --v234;
            v227 = v237 + 2;
          }
          while ( v234 );
        }
      }
      tmp_pbDst = (unsigned int)(v227 - 800);
      v50 = __OFSUB__(v223, 2);
      v223 -= 2;
    }
    while ( !((v223 < 0) ^ v50) );
    goto LABEL_364;
  }
  WorldBoolFlag = 0;
  v195 = 30;
  if ( pbDst < gpBufEnd )
    goto LABEL_326;
  v196 = (unsigned int)(pbDst - gpBufEnd + 1023) >> 8;
  if ( v196 <= 45 )
  {
    v197 = WorldTbl3x16[v196];
    pdung_cels += *(int *)((char *)WorldTbl17_1 + v197);
    v198 = 192 * v197;
    v197 >>= 1;
    tmp_pbDst -= v198;
    v195 = 30 - v197;
    WorldBoolFlag += v197 >> 1;
    do
    {
LABEL_326:
      v199 = 32 - v195;
      v200 = ((_BYTE)WorldBoolFlag + 1) & 1;
      WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
      if ( WorldBoolFlag )
      {
        for ( ii = v199 >> 2; ii; --ii )
        {
          v202 = *(_DWORD *)pdung_cels;
          pdung_cels += 4;
          v203 = (_BYTE *)(tmp_pbDst + 1);
          v202 = __ROR4__(v202, 8);
          *v203 = v202;
          v203 += 2;
          v200 = __ROR4__(v202, 16);
          *v203 = v200;
          tmp_pbDst = (unsigned int)(v203 + 1);
        }
        if ( (32 - (_BYTE)v195) & 2 )
        {
          LOWORD(v200) = *(_WORD *)pdung_cels;
          pdung_cels += 4;
          v204 = (_BYTE *)(tmp_pbDst + 1);
          *v204 = __ROR4__(v200, 8);
          tmp_pbDst = (unsigned int)(v204 + 1);
        }
      }
      else
      {
        for ( jj = v199 >> 2; jj; --jj )
        {
          v206 = *(_DWORD *)pdung_cels;
          pdung_cels += 4;
          *(_BYTE *)tmp_pbDst = v206;
          v207 = (_BYTE *)(tmp_pbDst + 2);
          *v207 = __ROR4__(v206, 16);
          tmp_pbDst = (unsigned int)(v207 + 2);
        }
        if ( (32 - (_BYTE)v195) & 2 )
        {
          v208 = *(_WORD *)pdung_cels;
          pdung_cels += 4;
          *(_BYTE *)tmp_pbDst = v208;
          tmp_pbDst += 2;
        }
      }
      tmp_pbDst = v195 + tmp_pbDst - 800;
      v50 = __OFSUB__(v195, 2);
      v195 -= 2;
    }
    while ( !((v195 < 0) ^ v50) );
    goto LABEL_336;
  }
  tmp_pbDst = (unsigned int)(pbDst - 12288);
  pdung_cels += 288;
LABEL_336:
  v209 = 2;
  if ( tmp_pbDst >= (unsigned int)gpBufEnd )
  {
    v210 = (tmp_pbDst - (unsigned int)gpBufEnd + 1023) >> 8;
    if ( v210 > 42 )
      return;
    v211 = WorldTbl3x16[v210];
    pdung_cels += *(int *)((char *)WorldTbl17_2 + v211);
    v212 = 192 * v211;
    v211 >>= 1;
    tmp_pbDst -= v212;
    v209 = v211 + 2;
    WorldBoolFlag += v211 >> 1;
  }
  do
  {
    v213 = 32 - v209;
    v214 = ((_BYTE)WorldBoolFlag + 1) & 1;
    WorldBoolFlag = ((_BYTE)WorldBoolFlag + 1) & 1;
    if ( WorldBoolFlag )
    {
      for ( kk = v213 >> 2; kk; --kk )
      {
        v216 = *(_DWORD *)pdung_cels;
        pdung_cels += 4;
        v217 = (_BYTE *)(tmp_pbDst + 1);
        v216 = __ROR4__(v216, 8);
        *v217 = v216;
        v217 += 2;
        v214 = __ROR4__(v216, 16);
        *v217 = v214;
        tmp_pbDst = (unsigned int)(v217 + 1);
      }
      if ( (32 - (_BYTE)v209) & 2 )
      {
        LOWORD(v214) = *(_WORD *)pdung_cels;
        pdung_cels += 4;
        v218 = (_BYTE *)(tmp_pbDst + 1);
        *v218 = __ROR4__(v214, 8);
        tmp_pbDst = (unsigned int)(v218 + 1);
      }
    }
    else
    {
      for ( ll = v213 >> 2; ll; --ll )
      {
        v220 = *(_DWORD *)pdung_cels;
        pdung_cels += 4;
        *(_BYTE *)tmp_pbDst = v220;
        v221 = (_BYTE *)(tmp_pbDst + 2);
        *v221 = __ROR4__(v220, 16);
        tmp_pbDst = (unsigned int)(v221 + 2);
      }
      if ( (32 - (_BYTE)v209) & 2 )
      {
        v222 = *(_WORD *)pdung_cels;
        pdung_cels += 4;
        *(_BYTE *)tmp_pbDst = v222;
        tmp_pbDst += 2;
      }
    }
    tmp_pbDst = v209 + tmp_pbDst - 800;
    v209 += 2;
  }
  while ( v209 != 32 );
}

//----- (004A4D75) --------------------------------------------------------
void __fastcall drawBottomArchesLowerScreen(unsigned __int8 *pbDst, unsigned int *pMask)
{
  unsigned __int8 *tmp_pbDst; // edi
  char *pdung_cels2; // esi
  __int16 v5; // ax
  unsigned __int8 *pdung_cels3; // esi
  __int16 v7; // ax
  unsigned int v8; // eax
  char *pdung_cels; // esi
  unsigned int v10; // eax
  int v11; // eax
  signed int v12; // ebp
  unsigned int v13; // edx
  signed int v14; // ecx
  unsigned __int8 v16; // cf
  int v18; // ecx
  signed int v19; // edx
  int v20; // eax
  int v21; // ecx
  int v22; // edx
  int v25; // edx
  signed int v26; // eax
  unsigned int v27; // ecx
  unsigned __int8 *v28; // edi
  unsigned int v29; // ecx
  unsigned __int8 v32; // of
  int v33; // edx
  signed int v34; // eax
  unsigned int v35; // ecx
  unsigned __int8 *v36; // edi
  unsigned int v37; // ecx
  int v40; // edx
  signed int v41; // eax
  unsigned int v42; // ecx
  unsigned int ii; // ecx
  int v46; // edx
  signed int v47; // eax
  unsigned int v48; // ecx
  unsigned int n; // ecx
  int v52; // edx
  signed int v53; // eax
  unsigned int v54; // ecx
  unsigned __int8 *v55; // edi
  unsigned int v56; // ecx
  signed int v59; // edx
  unsigned int v60; // edx
  signed int v61; // ecx
  int v64; // edx
  signed int v65; // eax
  unsigned int v66; // ecx
  unsigned int m; // ecx
  signed int v70; // edx
  unsigned int v71; // edx
  signed int v72; // ecx
  signed int v75; // edx
  unsigned int v76; // edx
  signed int v77; // ecx
  unsigned __int8 v78; // al
  int v79; // ecx
  signed int v80; // edx
  int v81; // eax
  int v82; // ecx
  int v83; // edx
  unsigned __int8 v84; // al
  int v85; // edx
  signed int v86; // eax
  unsigned int v87; // ecx
  unsigned __int8 *v88; // edi
  unsigned int v89; // ecx
  __int16 v90; // ax
  int v91; // eax
  int v92; // edx
  signed int v93; // eax
  unsigned int v94; // ecx
  unsigned __int8 *v95; // edi
  unsigned int v96; // ecx
  __int16 v97; // ax
  int v98; // eax
  int v99; // edx
  signed int v100; // eax
  unsigned int v101; // ecx
  unsigned int kk; // ecx
  int v103; // eax
  __int16 v104; // ax
  int v105; // edx
  signed int v106; // eax
  unsigned int v107; // ecx
  unsigned int ll; // ecx
  int v109; // eax
  __int16 v110; // ax
  int v111; // edx
  signed int v112; // eax
  unsigned int v113; // ecx
  unsigned __int8 *v114; // edi
  unsigned int v115; // ecx
  __int16 v116; // ax
  int v117; // eax
  signed int v118; // edx
  unsigned int v119; // edx
  signed int v120; // ecx
  unsigned __int8 v121; // al
  int v122; // edx
  signed int v123; // eax
  unsigned int v124; // ecx
  unsigned int jj; // ecx
  int v126; // eax
  __int16 v127; // ax
  signed int v128; // edx
  unsigned int v129; // edx
  signed int v130; // ecx
  unsigned __int8 v131; // al
  signed int v132; // edx
  unsigned int v133; // edx
  signed int v134; // ecx
  int v135; // ecx
  signed int v136; // edx
  int v137; // eax
  int v138; // ecx
  int v139; // edx
  signed int i; // edx
  unsigned __int8 *v141; // edi
  unsigned int v142; // ecx
  signed int v143; // edx
  unsigned __int8 *v144; // edi
  unsigned int v145; // ecx
  signed int j; // edx
  unsigned int v147; // ecx
  unsigned __int8 *v148; // edi
  signed int v149; // edx
  unsigned int v150; // ecx
  signed int k; // edx
  unsigned __int8 *v152; // edi
  unsigned int v153; // ecx
  signed int v154; // edx
  unsigned int v155; // edx
  signed int v156; // ecx
  signed int l; // edx
  unsigned int v158; // ecx
  unsigned __int8 *v159; // edi
  signed int v160; // edx
  unsigned int v161; // edx
  signed int v162; // ecx
  signed int v163; // [esp-8h] [ebp-14h]
  signed int v164; // [esp-8h] [ebp-14h]
  signed int v165; // [esp-8h] [ebp-14h]
  signed int v166; // [esp-8h] [ebp-14h]
  signed int v167; // [esp-8h] [ebp-14h]
  int v168; // [esp-4h] [ebp-10h]
  signed int v169; // [esp-4h] [ebp-10h]
  signed int v170; // [esp-4h] [ebp-10h]
  int v171; // [esp-4h] [ebp-10h]
  signed int v172; // [esp-4h] [ebp-10h]
  signed int v173; // [esp-4h] [ebp-10h]
  int v174; // [esp-4h] [ebp-10h]
  signed int v175; // [esp-4h] [ebp-10h]
  signed int v176; // [esp-4h] [ebp-10h]

  gpCelFrame = (unsigned __int8 *)speed_cel_frame_num_from_light_index_frame_num;
  tmp_pbDst = pbDst;
  gpDrawMask = pMask;
  if ( (_BYTE)light_table_index )
  {
    if ( (_BYTE)light_table_index == lightmax )
    {
      if ( level_cel_block & 0x8000 )
        level_cel_block = *(_DWORD *)&gpCelFrame[64 * (level_cel_block & 0xFFF)]
                        + (unsigned __int16)(level_cel_block & 0xF000);
      pdung_cels = (char *)pDungeonCels + *((_DWORD *)pDungeonCels + (level_cel_block & 0xFFF));
      v10 = level_cel_block;
      LOBYTE(v10) = BYTE1(v10);
      v11 = (v10 >> 4) & 7;
      if ( v11 )
      {
        switch ( (_WORD)v11 )
        {
          case 1:
            v135 = 32;
            do
            {
              v174 = v135;
              gdwCurrentMask = *gpDrawMask;
              v136 = 32;
              do
              {
                while ( 1 )
                {
                  v137 = (unsigned __int8)*pdung_cels++;
                  if ( (v137 & 0x80u) != 0 )
                    break;
                  v136 -= v137;
                  if ( tmp_pbDst < gpBufEnd )
                  {
                    v138 = v137;
                    pdung_cels += v137;
                    v167 = v136;
                    v139 = gdwCurrentMask;
                    do
                    {
                      v16 = __CFSHL__(v139, 1);
                      v139 *= 2;
                      if ( v16 )
                        *tmp_pbDst = 0;
                      ++tmp_pbDst;
                      --v138;
                    }
                    while ( v138 );
                    gdwCurrentMask = v139;
                    v136 = v167;
                  }
                  else
                  {
                    pdung_cels += v137;
                    tmp_pbDst += v137;
                  }
                  if ( !v136 )
                    goto LABEL_252;
                }
                LOBYTE(v137) = -(char)v137;
                tmp_pbDst += v137;
                if ( v137 & 0x1F )
                  gdwCurrentMask <<= v137 & 0x1F;
                v136 -= v137;
              }
              while ( v136 );
LABEL_252:
              tmp_pbDst -= 800;
              --gpDrawMask;
              v135 = v174 - 1;
            }
            while ( v174 != 1 );
            break;
          case 2:
            for ( i = 30; ; i -= 2 )
            {
              if ( tmp_pbDst < gpBufEnd )
              {
                v141 = &tmp_pbDst[i];
                v142 = (unsigned int)(32 - i) >> 2;
                if ( !__CFSHR__(32 - i, 2) || (*(_WORD *)v141 = 0, v141 += 2, v142) )
                {
                  do
                  {
                    *(_DWORD *)v141 = 0;
                    v141 += 4;
                    --v142;
                  }
                  while ( v142 );
                }
              }
              else
              {
                pdung_cels = &pdung_cels[-i + 32];
                v141 = tmp_pbDst + 32;
              }
              tmp_pbDst = v141 - 800;
              if ( !i )
                break;
            }
            v143 = 2;
            do
            {
              if ( tmp_pbDst < gpBufEnd )
              {
                v144 = &tmp_pbDst[v143];
                v145 = (unsigned int)(32 - v143) >> 2;
                if ( !__CFSHR__(32 - v143, 2) || (*(_WORD *)v144 = 0, v144 += 2, v145) )
                {
                  do
                  {
                    *(_DWORD *)v144 = 0;
                    v144 += 4;
                    --v145;
                  }
                  while ( v145 );
                }
              }
              else
              {
                pdung_cels = &pdung_cels[-v143 + 32];
                v144 = tmp_pbDst + 32;
              }
              tmp_pbDst = v144 - 800;
              v143 += 2;
            }
            while ( v143 != 32 );
            break;
          case 3:
            for ( j = 30; ; j -= 2 )
            {
              if ( tmp_pbDst < gpBufEnd )
              {
                v147 = (unsigned int)(32 - j) >> 2;
                if ( !__CFSHR__(32 - j, 2) || (*(_WORD *)tmp_pbDst = 0, tmp_pbDst += 2, v147) )
                {
                  do
                  {
                    *(_DWORD *)tmp_pbDst = 0;
                    tmp_pbDst += 4;
                    --v147;
                  }
                  while ( v147 );
                }
              }
              else
              {
                pdung_cels = &pdung_cels[-j + 32];
                tmp_pbDst = &tmp_pbDst[-j + 32];
              }
              v148 = tmp_pbDst - 800;
              if ( !j )
                break;
              tmp_pbDst = &v148[j];
            }
            v149 = 2;
            do
            {
              if ( v148 < gpBufEnd )
              {
                v150 = (unsigned int)(32 - v149) >> 2;
                if ( !__CFSHR__(32 - v149, 2) || (*(_WORD *)v148 = 0, v148 += 2, v150) )
                {
                  do
                  {
                    *(_DWORD *)v148 = 0;
                    v148 += 4;
                    --v150;
                  }
                  while ( v150 );
                }
              }
              else
              {
                pdung_cels = &pdung_cels[-v149 + 32];
                v148 = &v148[-v149 + 32];
              }
              v148 = &v148[v149 - 800];
              v149 += 2;
            }
            while ( v149 != 32 );
            break;
          case 4:
            for ( k = 30; ; k -= 2 )
            {
              if ( tmp_pbDst < gpBufEnd )
              {
                v152 = &tmp_pbDst[k];
                v153 = (unsigned int)(32 - k) >> 2;
                if ( !__CFSHR__(32 - k, 2) || (*(_WORD *)v152 = 0, v152 += 2, v153) )
                {
                  do
                  {
                    *(_DWORD *)v152 = 0;
                    v152 += 4;
                    --v153;
                  }
                  while ( v153 );
                }
              }
              else
              {
                pdung_cels = &pdung_cels[-k + 32];
                v152 = tmp_pbDst + 32;
              }
              tmp_pbDst = v152 - 800;
              if ( !k )
                break;
            }
            gpDrawMask -= 16;
            v154 = 16;
            do
            {
              if ( tmp_pbDst < gpBufEnd )
              {
                v175 = v154;
                v155 = *gpDrawMask;
                v156 = 32;
                do
                {
                  v16 = __CFSHL__(v155, 1);
                  v155 *= 2;
                  if ( v16 )
                    *tmp_pbDst = 0;
                  ++tmp_pbDst;
                  --v156;
                }
                while ( v156 );
                v154 = v175;
              }
              else
              {
                pdung_cels += 32;
                tmp_pbDst += 32;
              }
              tmp_pbDst -= 800;
              --gpDrawMask;
              --v154;
            }
            while ( v154 );
            break;
          default:
            for ( l = 30; ; l -= 2 )
            {
              if ( tmp_pbDst < gpBufEnd )
              {
                v158 = (unsigned int)(32 - l) >> 2;
                if ( !__CFSHR__(32 - l, 2) || (*(_WORD *)tmp_pbDst = 0, tmp_pbDst += 2, v158) )
                {
                  do
                  {
                    *(_DWORD *)tmp_pbDst = 0;
                    tmp_pbDst += 4;
                    --v158;
                  }
                  while ( v158 );
                }
              }
              else
              {
                pdung_cels = &pdung_cels[-l + 32];
                tmp_pbDst = &tmp_pbDst[-l + 32];
              }
              v159 = tmp_pbDst - 800;
              if ( !l )
                break;
              tmp_pbDst = &v159[l];
            }
            gpDrawMask -= 16;
            v160 = 16;
            do
            {
              if ( v159 < gpBufEnd )
              {
                v176 = v160;
                v161 = *gpDrawMask;
                v162 = 32;
                do
                {
                  v16 = __CFSHL__(v161, 1);
                  v161 *= 2;
                  if ( v16 )
                    *v159 = 0;
                  ++v159;
                  --v162;
                }
                while ( v162 );
                v160 = v176;
              }
              else
              {
                pdung_cels += 32;
                v159 += 32;
              }
              v159 -= 800;
              --gpDrawMask;
              --v160;
            }
            while ( v160 );
            break;
        }
      }
      else
      {
        v132 = 32;
        do
        {
          if ( tmp_pbDst < gpBufEnd )
          {
            v173 = v132;
            v133 = *gpDrawMask;
            v134 = 32;
            do
            {
              v16 = __CFSHL__(v133, 1);
              v133 *= 2;
              if ( v16 )
                *tmp_pbDst = 0;
              ++tmp_pbDst;
              --v134;
            }
            while ( v134 );
            v132 = v173;
          }
          else
          {
            pdung_cels += 32;
            tmp_pbDst += 32;
          }
          tmp_pbDst -= 800;
          --gpDrawMask;
          --v132;
        }
        while ( v132 );
      }
      return;
    }
    if ( !(level_cel_block & 0x8000) )
    {
      pdung_cels2 = (char *)pDungeonCels + *((_DWORD *)pDungeonCels + (level_cel_block & 0xFFF));
      _EBX = &pLightTbl[256 * light_table_index];
      v5 = (unsigned __int8)(BYTE1(level_cel_block) >> 4);
      if ( !(BYTE1(level_cel_block) >> 4) )
      {
        v12 = 32;
        do
        {
          if ( tmp_pbDst < gpBufEnd )
          {
            v13 = *gpDrawMask;
            v14 = 32;
            do
            {
              _AL = *pdung_cels2++;
              v16 = __CFSHL__(v13, 1);
              v13 *= 2;
              if ( v16 )
              {
                ASM_XLAT();
                *tmp_pbDst = _AL;
              }
              ++tmp_pbDst;
              --v14;
            }
            while ( v14 );
          }
          else
          {
            pdung_cels2 += 32;
            tmp_pbDst += 32;
          }
          tmp_pbDst -= 800;
          --gpDrawMask;
          --v12;
        }
        while ( v12 );
        return;
      }
      if ( v5 == 1 )
      {
        v18 = 32;
        do
        {
          v168 = v18;
          gdwCurrentMask = *gpDrawMask;
          v19 = 32;
          do
          {
            while ( 1 )
            {
              v20 = (unsigned __int8)*pdung_cels2++;
              if ( (v20 & 0x80u) != 0 )
                break;
              v19 -= v20;
              if ( tmp_pbDst < gpBufEnd )
              {
                v21 = v20;
                v163 = v19;
                v22 = gdwCurrentMask;
                do
                {
                  _AL = *pdung_cels2++;
                  v16 = __CFSHL__(v22, 1);
                  v22 *= 2;
                  if ( v16 )
                  {
                    ASM_XLAT();
                    *tmp_pbDst = _AL;
                  }
                  ++tmp_pbDst;
                  --v21;
                }
                while ( v21 );
                gdwCurrentMask = v22;
                v19 = v163;
              }
              else
              {
                pdung_cels2 += v20;
                tmp_pbDst += v20;
              }
              if ( !v19 )
                goto LABEL_52;
            }
            LOBYTE(v20) = -(char)v20;
            tmp_pbDst += v20;
            if ( v20 & 0x1F )
              gdwCurrentMask <<= v20 & 0x1F;
            v19 -= v20;
          }
          while ( v19 );
LABEL_52:
          tmp_pbDst -= 800;
          --gpDrawMask;
          v18 = v168 - 1;
        }
        while ( v168 != 1 );
        return;
      }
      if ( v5 != 2 )
      {
        if ( v5 != 3 )
        {
          if ( v5 != 4 )
          {
            v64 = 30;
            if ( pbDst >= gpBufEnd )
            {
              v65 = (unsigned int)(pbDst - gpBufEnd + 1023) >> 8;
              if ( v65 > 45 )
              {
                tmp_pbDst = pbDst - 12288;
                pdung_cels2 += 288;
LABEL_117:
                gpDrawMask -= 16;
                v70 = 16;
                do
                {
                  if ( tmp_pbDst < gpBufEnd )
                  {
                    v164 = v70;
                    v71 = *gpDrawMask;
                    v72 = 32;
                    do
                    {
                      _AL = *pdung_cels2++;
                      v16 = __CFSHL__(v71, 1);
                      v71 *= 2;
                      if ( v16 )
                      {
                        ASM_XLAT();
                        *tmp_pbDst = _AL;
                      }
                      ++tmp_pbDst;
                      --v72;
                    }
                    while ( v72 );
                    pdung_cels2 += (unsigned __int8)pdung_cels2 & 2;
                    v70 = v164;
                  }
                  else
                  {
                    pdung_cels2 += 32;
                    tmp_pbDst += 32;
                  }
                  tmp_pbDst -= 800;
                  --gpDrawMask;
                  --v70;
                }
                while ( v70 );
                return;
              }
              v66 = WorldTbl3x16[v65];
              pdung_cels2 += *(int *)((char *)WorldTbl17_1 + v66);
              tmp_pbDst -= 192 * v66;
              v64 = 30 - (v66 >> 1);
            }
            do
            {
              for ( m = (unsigned int)(32 - v64) >> 2; m; --m )
              {
                _EAX = *(_DWORD *)pdung_cels2;
                pdung_cels2 += 4;
                ASM_XLAT();
                _EAX = __ROR4__(_EAX, 8);
                ASM_XLAT();
                _EAX = __ROR4__(_EAX, 8);
                ASM_XLAT();
                _EAX = __ROR4__(_EAX, 8);
                ASM_XLAT();
                *(_DWORD *)tmp_pbDst = __ROR4__(_EAX, 8);
                tmp_pbDst += 4;
              }
              if ( (32 - (_BYTE)v64) & 2 )
              {
                _AX = *(_WORD *)pdung_cels2;
                pdung_cels2 += 4;
                ASM_XLAT();
                _AX = __ROR2__(_AX, 8);
                ASM_XLAT();
                *(_WORD *)tmp_pbDst = __ROR2__(_AX, 8);
                tmp_pbDst += 2;
              }
              tmp_pbDst = &tmp_pbDst[v64 - 800];
              v32 = __OFSUB__(v64, 2);
              v64 -= 2;
            }
            while ( !((v64 < 0) ^ v32) );
            goto LABEL_117;
          }
          v52 = 30;
          if ( pbDst >= gpBufEnd )
          {
            v53 = (unsigned int)(pbDst - gpBufEnd + 1023) >> 8;
            if ( v53 > 45 )
            {
              tmp_pbDst = pbDst - 12288;
              pdung_cels2 += 288;
LABEL_98:
              gpDrawMask -= 16;
              v59 = 16;
              do
              {
                if ( tmp_pbDst < gpBufEnd )
                {
                  v169 = v59;
                  v60 = *gpDrawMask;
                  v61 = 32;
                  do
                  {
                    _AL = *pdung_cels2++;
                    v16 = __CFSHL__(v60, 1);
                    v60 *= 2;
                    if ( v16 )
                    {
                      ASM_XLAT();
                      *tmp_pbDst = _AL;
                    }
                    ++tmp_pbDst;
                    --v61;
                  }
                  while ( v61 );
                  v59 = v169;
                }
                else
                {
                  pdung_cels2 += 32;
                  tmp_pbDst += 32;
                }
                tmp_pbDst -= 800;
                --gpDrawMask;
                --v59;
              }
              while ( v59 );
              return;
            }
            v54 = WorldTbl3x16[v53];
            pdung_cels2 += *(int *)((char *)WorldTbl17_1 + v54);
            tmp_pbDst -= 192 * v54;
            v52 = 30 - (v54 >> 1);
          }
          do
          {
            v55 = &tmp_pbDst[v52];
            v56 = (unsigned int)(32 - v52) >> 2;
            if ( !__CFSHR__(32 - v52, 2) )
              goto LABEL_322;
            _AX = *((_WORD *)pdung_cels2 + 1);
            pdung_cels2 += 4;
            ASM_XLAT();
            _AX = __ROR2__(_AX, 8);
            ASM_XLAT();
            *(_WORD *)v55 = __ROR2__(_AX, 8);
            v55 += 2;
            if ( v56 )
            {
LABEL_322:
              do
              {
                _EAX = *(_DWORD *)pdung_cels2;
                pdung_cels2 += 4;
                ASM_XLAT();
                _EAX = __ROR4__(_EAX, 8);
                ASM_XLAT();
                _EAX = __ROR4__(_EAX, 8);
                ASM_XLAT();
                _EAX = __ROR4__(_EAX, 8);
                ASM_XLAT();
                *(_DWORD *)v55 = __ROR4__(_EAX, 8);
                v55 += 4;
                --v56;
              }
              while ( v56 );
            }
            tmp_pbDst = v55 - 800;
            v32 = __OFSUB__(v52, 2);
            v52 -= 2;
          }
          while ( !((v52 < 0) ^ v32) );
          goto LABEL_98;
        }
        v40 = 30;
        if ( pbDst >= gpBufEnd )
        {
          v41 = (unsigned int)(pbDst - gpBufEnd + 1023) >> 8;
          if ( v41 > 45 )
          {
            tmp_pbDst = pbDst - 12288;
            pdung_cels2 += 288;
LABEL_80:
            v46 = 2;
            if ( tmp_pbDst >= gpBufEnd )
            {
              v47 = (unsigned int)(tmp_pbDst - gpBufEnd + 1023) >> 8;
              if ( v47 > 42 )
                return;
              v48 = WorldTbl3x16[v47];
              pdung_cels2 += *(int *)((char *)WorldTbl17_2 + v48);
              tmp_pbDst -= 192 * v48;
              v46 = (v48 >> 1) + 2;
            }
            do
            {
              for ( n = (unsigned int)(32 - v46) >> 2; n; --n )
              {
                _EAX = *(_DWORD *)pdung_cels2;
                pdung_cels2 += 4;
                ASM_XLAT();
                _EAX = __ROR4__(_EAX, 8);
                ASM_XLAT();
                _EAX = __ROR4__(_EAX, 8);
                ASM_XLAT();
                _EAX = __ROR4__(_EAX, 8);
                ASM_XLAT();
                *(_DWORD *)tmp_pbDst = __ROR4__(_EAX, 8);
                tmp_pbDst += 4;
              }
              if ( (32 - (_BYTE)v46) & 2 )
              {
                _AX = *(_WORD *)pdung_cels2;
                pdung_cels2 += 2;
                ASM_XLAT();
                _AX = __ROR2__(_AX, 8);
                ASM_XLAT();
                *(_WORD *)tmp_pbDst = __ROR2__(_AX, 8);
                tmp_pbDst += 2;
              }
              tmp_pbDst = &tmp_pbDst[v46 - 800];
              v46 += 2;
            }
            while ( v46 != 32 );
            return;
          }
          v42 = WorldTbl3x16[v41];
          pdung_cels2 += *(int *)((char *)WorldTbl17_1 + v42);
          tmp_pbDst -= 192 * v42;
          v40 = 30 - (v42 >> 1);
        }
        do
        {
          for ( ii = (unsigned int)(32 - v40) >> 2; ii; --ii )
          {
            _EAX = *(_DWORD *)pdung_cels2;
            pdung_cels2 += 4;
            ASM_XLAT();
            _EAX = __ROR4__(_EAX, 8);
            ASM_XLAT();
            _EAX = __ROR4__(_EAX, 8);
            ASM_XLAT();
            _EAX = __ROR4__(_EAX, 8);
            ASM_XLAT();
            *(_DWORD *)tmp_pbDst = __ROR4__(_EAX, 8);
            tmp_pbDst += 4;
          }
          if ( (32 - (_BYTE)v40) & 2 )
          {
            _AX = *(_WORD *)pdung_cels2;
            pdung_cels2 += 4;
            ASM_XLAT();
            _AX = __ROR2__(_AX, 8);
            ASM_XLAT();
            *(_WORD *)tmp_pbDst = __ROR2__(_AX, 8);
            tmp_pbDst += 2;
          }
          tmp_pbDst = &tmp_pbDst[v40 - 800];
          v32 = __OFSUB__(v40, 2);
          v40 -= 2;
        }
        while ( !((v40 < 0) ^ v32) );
        goto LABEL_80;
      }
      v25 = 30;
      if ( pbDst >= gpBufEnd )
      {
        v26 = (unsigned int)(pbDst - gpBufEnd + 1023) >> 8;
        if ( v26 > 45 )
        {
          tmp_pbDst = pbDst - 12288;
          pdung_cels2 += 288;
LABEL_62:
          v33 = 2;
          if ( tmp_pbDst >= gpBufEnd )
          {
            v34 = (unsigned int)(tmp_pbDst - gpBufEnd + 1023) >> 8;
            if ( v34 > 42 )
              return;
            v35 = WorldTbl3x16[v34];
            pdung_cels2 += *(int *)((char *)WorldTbl17_2 + v35);
            tmp_pbDst -= 192 * v35;
            v33 = (v35 >> 1) + 2;
          }
          do
          {
            v36 = &tmp_pbDst[v33];
            v37 = (unsigned int)(32 - v33) >> 2;
            if ( !__CFSHR__(32 - v33, 2) )
              goto LABEL_323;
            _AX = *((_WORD *)pdung_cels2 + 1);
            pdung_cels2 += 4;
            ASM_XLAT();
            _AX = __ROR2__(_AX, 8);
            ASM_XLAT();
            *(_WORD *)v36 = __ROR2__(_AX, 8);
            v36 += 2;
            if ( v37 )
            {
LABEL_323:
              do
              {
                _EAX = *(_DWORD *)pdung_cels2;
                pdung_cels2 += 4;
                ASM_XLAT();
                _EAX = __ROR4__(_EAX, 8);
                ASM_XLAT();
                _EAX = __ROR4__(_EAX, 8);
                ASM_XLAT();
                _EAX = __ROR4__(_EAX, 8);
                ASM_XLAT();
                *(_DWORD *)v36 = __ROR4__(_EAX, 8);
                v36 += 4;
                --v37;
              }
              while ( v37 );
            }
            tmp_pbDst = v36 - 800;
            v33 += 2;
          }
          while ( v33 != 32 );
          return;
        }
        v27 = WorldTbl3x16[v26];
        pdung_cels2 += *(int *)((char *)WorldTbl17_1 + v27);
        tmp_pbDst -= 192 * v27;
        v25 = 30 - (v27 >> 1);
      }
      do
      {
        v28 = &tmp_pbDst[v25];
        v29 = (unsigned int)(32 - v25) >> 2;
        if ( !__CFSHR__(32 - v25, 2) )
          goto LABEL_324;
        _AX = *((_WORD *)pdung_cels2 + 1);
        pdung_cels2 += 4;
        ASM_XLAT();
        _AX = __ROR2__(_AX, 8);
        ASM_XLAT();
        *(_WORD *)v28 = __ROR2__(_AX, 8);
        v28 += 2;
        if ( v29 )
        {
LABEL_324:
          do
          {
            _EAX = *(_DWORD *)pdung_cels2;
            pdung_cels2 += 4;
            ASM_XLAT();
            _EAX = __ROR4__(_EAX, 8);
            ASM_XLAT();
            _EAX = __ROR4__(_EAX, 8);
            ASM_XLAT();
            _EAX = __ROR4__(_EAX, 8);
            ASM_XLAT();
            *(_DWORD *)v28 = __ROR4__(_EAX, 8);
            v28 += 4;
            --v29;
          }
          while ( v29 );
        }
        tmp_pbDst = v28 - 800;
        v32 = __OFSUB__(v25, 2);
        v25 -= 2;
      }
      while ( !((v25 < 0) ^ v32) );
      goto LABEL_62;
    }
    pdung_cels3 = (unsigned __int8 *)pSpeedCels
                + *(_DWORD *)&gpCelFrame[4 * (light_table_index + 16 * (level_cel_block & 0xFFF))];
    v7 = (unsigned __int8)(BYTE1(level_cel_block) >> 4);
  }
  else
  {
    if ( level_cel_block & 0x8000 )
      level_cel_block = *(_DWORD *)&gpCelFrame[64 * (level_cel_block & 0xFFF)]
                      + (unsigned __int16)(level_cel_block & 0xF000);
    pdung_cels3 = (unsigned __int8 *)pDungeonCels + *((_DWORD *)pDungeonCels + (level_cel_block & 0xFFF));
    v8 = level_cel_block;
    LOBYTE(v8) = BYTE1(v8);
    v7 = ((v8 >> 4) & 7) + 8;
  }
  switch ( v7 )
  {
    case 8:
      v75 = 32;
      do
      {
        if ( tmp_pbDst < gpBufEnd )
        {
          v170 = v75;
          v76 = *gpDrawMask;
          v77 = 32;
          do
          {
            v78 = *pdung_cels3++;
            v16 = __CFSHL__(v76, 1);
            v76 *= 2;
            if ( v16 )
              *tmp_pbDst = v78;
            ++tmp_pbDst;
            --v77;
          }
          while ( v77 );
          v75 = v170;
        }
        else
        {
          pdung_cels3 += 32;
          tmp_pbDst += 32;
        }
        tmp_pbDst -= 800;
        --gpDrawMask;
        --v75;
      }
      while ( v75 );
      return;
    case 9:
      v79 = 32;
      do
      {
        v171 = v79;
        gdwCurrentMask = *gpDrawMask;
        v80 = 32;
        do
        {
          while ( 1 )
          {
            v81 = *pdung_cels3++;
            if ( (v81 & 0x80u) != 0 )
              break;
            v80 -= v81;
            if ( tmp_pbDst < gpBufEnd )
            {
              v82 = v81;
              v165 = v80;
              v83 = gdwCurrentMask;
              do
              {
                v84 = *pdung_cels3++;
                v16 = __CFSHL__(v83, 1);
                v83 *= 2;
                if ( v16 )
                  *tmp_pbDst = v84;
                ++tmp_pbDst;
                --v82;
              }
              while ( v82 );
              gdwCurrentMask = v83;
              v80 = v165;
            }
            else
            {
              pdung_cels3 += v81;
              tmp_pbDst += v81;
            }
            if ( !v80 )
              goto LABEL_152;
          }
          LOBYTE(v81) = -(char)v81;
          tmp_pbDst += v81;
          if ( v81 & 0x1F )
            gdwCurrentMask <<= v81 & 0x1F;
          v80 -= v81;
        }
        while ( v80 );
LABEL_152:
        tmp_pbDst -= 800;
        --gpDrawMask;
        v79 = v171 - 1;
      }
      while ( v171 != 1 );
      return;
    case 10:
      v85 = 30;
      if ( pbDst >= gpBufEnd )
      {
        v86 = (unsigned int)(pbDst - gpBufEnd + 1023) >> 8;
        if ( v86 > 45 )
        {
          tmp_pbDst = pbDst - 12288;
          pdung_cels3 += 288;
LABEL_162:
          v92 = 2;
          if ( tmp_pbDst >= gpBufEnd )
          {
            v93 = (unsigned int)(tmp_pbDst - gpBufEnd + 1023) >> 8;
            if ( v93 > 42 )
              return;
            v94 = WorldTbl3x16[v93];
            pdung_cels3 += *(int *)((char *)WorldTbl17_2 + v94);
            tmp_pbDst -= 192 * v94;
            v92 = (v94 >> 1) + 2;
          }
          do
          {
            v95 = &tmp_pbDst[v92];
            v96 = (unsigned int)(32 - v92) >> 2;
            if ( !__CFSHR__(32 - v92, 2)
              || (v97 = *((_WORD *)pdung_cels3 + 1), pdung_cels3 += 4, *(_WORD *)v95 = v97, v95 += 2, v96) )
            {
              do
              {
                v98 = *(_DWORD *)pdung_cels3;
                pdung_cels3 += 4;
                *(_DWORD *)v95 = v98;
                v95 += 4;
                --v96;
              }
              while ( v96 );
            }
            tmp_pbDst = v95 - 800;
            v92 += 2;
          }
          while ( v92 != 32 );
          return;
        }
        v87 = WorldTbl3x16[v86];
        pdung_cels3 += *(int *)((char *)WorldTbl17_1 + v87);
        tmp_pbDst -= 192 * v87;
        v85 = 30 - (v87 >> 1);
      }
      do
      {
        v88 = &tmp_pbDst[v85];
        v89 = (unsigned int)(32 - v85) >> 2;
        if ( !__CFSHR__(32 - v85, 2)
          || (v90 = *((_WORD *)pdung_cels3 + 1), pdung_cels3 += 4, *(_WORD *)v88 = v90, v88 += 2, v89) )
        {
          do
          {
            v91 = *(_DWORD *)pdung_cels3;
            pdung_cels3 += 4;
            *(_DWORD *)v88 = v91;
            v88 += 4;
            --v89;
          }
          while ( v89 );
        }
        tmp_pbDst = v88 - 800;
        v32 = __OFSUB__(v85, 2);
        v85 -= 2;
      }
      while ( !((v85 < 0) ^ v32) );
      goto LABEL_162;
  }
  if ( v7 != 11 )
  {
    if ( v7 != 12 )
    {
      v122 = 30;
      if ( pbDst >= gpBufEnd )
      {
        v123 = (unsigned int)(pbDst - gpBufEnd + 1023) >> 8;
        if ( v123 > 45 )
        {
          tmp_pbDst = pbDst - 12288;
          pdung_cels3 += 288;
LABEL_217:
          gpDrawMask -= 16;
          v128 = 16;
          do
          {
            if ( tmp_pbDst < gpBufEnd )
            {
              v166 = v128;
              v129 = *gpDrawMask;
              v130 = 32;
              do
              {
                v131 = *pdung_cels3++;
                v16 = __CFSHL__(v129, 1);
                v129 *= 2;
                if ( v16 )
                  *tmp_pbDst = v131;
                ++tmp_pbDst;
                --v130;
              }
              while ( v130 );
              pdung_cels3 += (unsigned __int8)pdung_cels3 & 2;
              v128 = v166;
            }
            else
            {
              pdung_cels3 += 32;
              tmp_pbDst += 32;
            }
            tmp_pbDst -= 800;
            --gpDrawMask;
            --v128;
          }
          while ( v128 );
          return;
        }
        v124 = WorldTbl3x16[v123];
        pdung_cels3 += *(int *)((char *)WorldTbl17_1 + v124);
        tmp_pbDst -= 192 * v124;
        v122 = 30 - (v124 >> 1);
      }
      do
      {
        for ( jj = (unsigned int)(32 - v122) >> 2; jj; --jj )
        {
          v126 = *(_DWORD *)pdung_cels3;
          pdung_cels3 += 4;
          *(_DWORD *)tmp_pbDst = v126;
          tmp_pbDst += 4;
        }
        if ( (32 - (_BYTE)v122) & 2 )
        {
          v127 = *(_WORD *)pdung_cels3;
          pdung_cels3 += 4;
          *(_WORD *)tmp_pbDst = v127;
          tmp_pbDst += 2;
        }
        tmp_pbDst = &tmp_pbDst[v122 - 800];
        v32 = __OFSUB__(v122, 2);
        v122 -= 2;
      }
      while ( !((v122 < 0) ^ v32) );
      goto LABEL_217;
    }
    v111 = 30;
    if ( pbDst >= gpBufEnd )
    {
      v112 = (unsigned int)(pbDst - gpBufEnd + 1023) >> 8;
      if ( v112 > 45 )
      {
        tmp_pbDst = pbDst - 12288;
        pdung_cels3 += 288;
LABEL_198:
        gpDrawMask -= 16;
        v118 = 16;
        do
        {
          if ( tmp_pbDst < gpBufEnd )
          {
            v172 = v118;
            v119 = *gpDrawMask;
            v120 = 32;
            do
            {
              v121 = *pdung_cels3++;
              v16 = __CFSHL__(v119, 1);
              v119 *= 2;
              if ( v16 )
                *tmp_pbDst = v121;
              ++tmp_pbDst;
              --v120;
            }
            while ( v120 );
            v118 = v172;
          }
          else
          {
            pdung_cels3 += 32;
            tmp_pbDst += 32;
          }
          tmp_pbDst -= 800;
          --gpDrawMask;
          --v118;
        }
        while ( v118 );
        return;
      }
      v113 = WorldTbl3x16[v112];
      pdung_cels3 += *(int *)((char *)WorldTbl17_1 + v113);
      tmp_pbDst -= 192 * v113;
      v111 = 30 - (v113 >> 1);
    }
    do
    {
      v114 = &tmp_pbDst[v111];
      v115 = (unsigned int)(32 - v111) >> 2;
      if ( !__CFSHR__(32 - v111, 2)
        || (v116 = *((_WORD *)pdung_cels3 + 1), pdung_cels3 += 4, *(_WORD *)v114 = v116, v114 += 2, v115) )
      {
        do
        {
          v117 = *(_DWORD *)pdung_cels3;
          pdung_cels3 += 4;
          *(_DWORD *)v114 = v117;
          v114 += 4;
          --v115;
        }
        while ( v115 );
      }
      tmp_pbDst = v114 - 800;
      v32 = __OFSUB__(v111, 2);
      v111 -= 2;
    }
    while ( !((v111 < 0) ^ v32) );
    goto LABEL_198;
  }
  v99 = 30;
  if ( pbDst < gpBufEnd )
    goto LABEL_175;
  v100 = (unsigned int)(pbDst - gpBufEnd + 1023) >> 8;
  if ( v100 <= 45 )
  {
    v101 = WorldTbl3x16[v100];
    pdung_cels3 += *(int *)((char *)WorldTbl17_1 + v101);
    tmp_pbDst -= 192 * v101;
    v99 = 30 - (v101 >> 1);
    do
    {
LABEL_175:
      for ( kk = (unsigned int)(32 - v99) >> 2; kk; --kk )
      {
        v103 = *(_DWORD *)pdung_cels3;
        pdung_cels3 += 4;
        *(_DWORD *)tmp_pbDst = v103;
        tmp_pbDst += 4;
      }
      if ( (32 - (_BYTE)v99) & 2 )
      {
        v104 = *(_WORD *)pdung_cels3;
        pdung_cels3 += 4;
        *(_WORD *)tmp_pbDst = v104;
        tmp_pbDst += 2;
      }
      tmp_pbDst = &tmp_pbDst[v99 - 800];
      v32 = __OFSUB__(v99, 2);
      v99 -= 2;
    }
    while ( !((v99 < 0) ^ v32) );
    goto LABEL_180;
  }
  tmp_pbDst = pbDst - 12288;
  pdung_cels3 += 288;
LABEL_180:
  v105 = 2;
  if ( tmp_pbDst >= gpBufEnd )
  {
    v106 = (unsigned int)(tmp_pbDst - gpBufEnd + 1023) >> 8;
    if ( v106 > 42 )
      return;
    v107 = WorldTbl3x16[v106];
    pdung_cels3 += *(int *)((char *)WorldTbl17_2 + v107);
    tmp_pbDst -= 192 * v107;
    v105 = (v107 >> 1) + 2;
  }
  do
  {
    for ( ll = (unsigned int)(32 - v105) >> 2; ll; --ll )
    {
      v109 = *(_DWORD *)pdung_cels3;
      pdung_cels3 += 4;
      *(_DWORD *)tmp_pbDst = v109;
      tmp_pbDst += 4;
    }
    if ( (32 - (_BYTE)v105) & 2 )
    {
      v110 = *(_WORD *)pdung_cels3;
      pdung_cels3 += 4;
      *(_WORD *)tmp_pbDst = v110;
      tmp_pbDst += 2;
    }
    tmp_pbDst = &tmp_pbDst[v105 - 800];
    v105 += 2;
  }
  while ( v105 != 32 );
}

//----- (004A5C97) --------------------------------------------------------
void __fastcall drawLowerScreen(unsigned __int8 *pbDst)
{
  int v1; // edx
  char v2; // al
  char v3; // al
  unsigned __int8 *tmp_pbDst; // edi
  _BYTE *pdung_cels2; // esi
  BYTE *l_tbl; // ebx
  __int16 v7; // ax
  unsigned __int8 *v8; // esi
  __int16 v9; // ax
  char *pdung_cels; // esi
  unsigned int v11; // eax
  int v12; // eax
  int v13; // edx
  int v14; // edx
  signed int v15; // ebp
  int v16; // eax
  int v17; // ecx
  signed int v18; // ebp
  int v19; // eax
  char m; // cl
  int v21; // eax
  unsigned __int8 v22; // ch
  unsigned __int8 v23; // ch
  unsigned __int8 v24; // ch
  int v25; // ebp
  signed int v26; // eax
  unsigned int v27; // ecx
  unsigned __int8 *v28; // edi
  int v29; // ecx
  int v30; // edx
  unsigned __int8 v31; // of
  int v32; // ebp
  signed int v33; // eax
  unsigned int v34; // ecx
  unsigned __int8 *v35; // edi
  int v36; // ecx
  int v37; // edx
  int v38; // ebp
  signed int v39; // eax
  unsigned int v40; // ecx
  int v41; // ecx
  int v42; // ebp
  signed int v43; // eax
  unsigned int v44; // ecx
  int v45; // ecx
  int v46; // ebp
  signed int v47; // eax
  unsigned int v48; // ecx
  unsigned __int8 *v49; // edi
  char v50; // cl
  int v51; // eax
  BYTE v52; // ch
  BYTE v53; // ch
  BYTE v54; // ch
  signed int v55; // ebp
  char v56; // cl
  int v57; // eax
  unsigned __int8 v58; // ch
  unsigned __int8 v59; // ch
  unsigned __int8 v60; // ch
  int v61; // ebp
  signed int v62; // eax
  unsigned int v63; // ecx
  char n; // cl
  int v65; // eax
  unsigned __int8 v66; // ch
  unsigned __int8 v67; // ch
  unsigned __int8 v68; // ch
  signed int v69; // ebp
  char v70; // cl
  int v71; // eax
  unsigned __int8 v72; // ch
  unsigned __int8 v73; // ch
  unsigned __int8 v74; // ch
  signed int v75; // edx
  signed int v76; // ecx
  int v77; // eax
  int v78; // ecx
  signed int v79; // edx
  unsigned int v80; // eax
  unsigned int v81; // ecx
  unsigned __int8 v82; // al
  char v83; // cf
  unsigned int v84; // ecx
  __int16 v85; // ax
  int v86; // eax
  int v87; // edx
  signed int v88; // eax
  unsigned int v89; // ecx
  unsigned __int8 *v90; // edi
  unsigned int v91; // ecx
  __int16 v92; // ax
  int v93; // eax
  int v94; // edx
  signed int v95; // eax
  unsigned int v96; // ecx
  unsigned __int8 *v97; // edi
  unsigned int v98; // ecx
  __int16 v99; // ax
  int v100; // eax
  int v101; // edx
  signed int v102; // eax
  unsigned int v103; // ecx
  unsigned int jj; // ecx
  int v105; // eax
  __int16 v106; // ax
  int v107; // edx
  signed int v108; // eax
  unsigned int v109; // ecx
  unsigned int kk; // ecx
  int v111; // eax
  __int16 v112; // ax
  int v113; // edi
  int v114; // edx
  signed int v115; // eax
  unsigned int v116; // ecx
  unsigned __int8 *v117; // edi
  unsigned int v118; // ecx
  __int16 v119; // ax
  int v120; // eax
  signed int v121; // edx
  signed int v122; // ecx
  int v123; // eax
  int v124; // edx
  signed int v125; // eax
  unsigned int v126; // ecx
  unsigned int ii; // ecx
  int v128; // eax
  __int16 v129; // ax
  signed int v130; // edx
  signed int v131; // ecx
  int v132; // eax
  signed int v133; // edx
  signed int v134; // ecx
  int v135; // ecx
  signed int v136; // edx
  unsigned int v137; // eax
  unsigned int v138; // ecx
  unsigned int v139; // ecx
  signed int i; // edx
  unsigned __int8 *v141; // edi
  unsigned int v142; // ecx
  signed int v143; // edx
  unsigned __int8 *v144; // edi
  unsigned int v145; // ecx
  signed int j; // edx
  unsigned int v147; // ecx
  unsigned __int8 *v148; // edi
  signed int v149; // edx
  unsigned int v150; // ecx
  signed int k; // edx
  unsigned __int8 *v152; // edi
  unsigned int v153; // ecx
  signed int v154; // edx
  signed int v155; // ecx
  signed int l; // edx
  unsigned int v157; // ecx
  unsigned __int8 *v158; // edi
  signed int v159; // edx
  signed int v160; // ecx
  int v161; // [esp-14h] [ebp-18h]
  int v162; // [esp-14h] [ebp-18h]
  int v163; // [esp-10h] [ebp-14h]
  int v164; // [esp-10h] [ebp-14h]

  v1 = cel_transparency_active;
  if ( cel_transparency_active )
  {
    if ( !arch_draw_type )
    {
      drawTopArchesLowerScreen(pbDst);
      return;
    }
    if ( arch_draw_type == 1 )
    {
      v2 = block_lvid[level_piece_id];
      if ( v2 == 1 || v2 == 3 )
      {
        drawBottomArchesLowerScreen(pbDst, &LeftMask[31]);
        return;
      }
    }
    if ( arch_draw_type == 2 )
    {
      v3 = block_lvid[level_piece_id];
      if ( v3 == 2 || v3 == 3 )
      {
        drawBottomArchesLowerScreen(pbDst, &RightMask[31]);
        return;
      }
    }
  }
  gpCelFrame = (unsigned __int8 *)speed_cel_frame_num_from_light_index_frame_num;
  tmp_pbDst = pbDst;
  if ( (_BYTE)light_table_index )
  {
    if ( (_BYTE)light_table_index == lightmax )
    {
      if ( level_cel_block & 0x8000 )
        level_cel_block = *(_DWORD *)&gpCelFrame[64 * (level_cel_block & 0xFFF)]
                        + (unsigned __int16)(level_cel_block & 0xF000);
      pdung_cels = (char *)pDungeonCels + *((_DWORD *)pDungeonCels + (level_cel_block & 0xFFF));
      v11 = level_cel_block;
      LOBYTE(v11) = BYTE1(v11);
      v12 = (v11 >> 4) & 7;
      if ( v12 )
      {
        switch ( (_WORD)v12 )
        {
          case 1:
            v135 = 32;
            do
            {
              v164 = v135;
              v136 = 32;
              do
              {
                while ( 1 )
                {
                  v137 = (unsigned __int8)*pdung_cels++;
                  if ( (v137 & 0x80u) == 0 )
                    break;
                  LOBYTE(v137) = -(char)v137;
                  tmp_pbDst += v137;
                  v136 -= v137;
                  if ( !v136 )
                    goto LABEL_232;
                }
                v136 -= v137;
                if ( tmp_pbDst < gpBufEnd )
                {
                  pdung_cels += v137;
                  v138 = v137 >> 1;
                  if ( !(v137 & 1) || (*tmp_pbDst = 0, ++tmp_pbDst, v138) )
                  {
                    v83 = v138 & 1;
                    v139 = v137 >> 2;
                    if ( !v83 || (*(_WORD *)tmp_pbDst = 0, tmp_pbDst += 2, v139) )
                    {
                      do
                      {
                        *(_DWORD *)tmp_pbDst = 0;
                        tmp_pbDst += 4;
                        --v139;
                      }
                      while ( v139 );
                    }
                  }
                }
                else
                {
                  pdung_cels += v137;
                  tmp_pbDst += v137;
                }
              }
              while ( v136 );
LABEL_232:
              tmp_pbDst -= 800;
              v135 = v164 - 1;
            }
            while ( v164 != 1 );
            break;
          case 2:
            for ( i = 30; ; i -= 2 )
            {
              if ( tmp_pbDst < gpBufEnd )
              {
                v141 = &tmp_pbDst[i];
                v142 = (unsigned int)(32 - i) >> 2;
                if ( !__CFSHR__(32 - i, 2) || (*(_WORD *)v141 = 0, v141 += 2, v142) )
                {
                  do
                  {
                    *(_DWORD *)v141 = 0;
                    v141 += 4;
                    --v142;
                  }
                  while ( v142 );
                }
              }
              else
              {
                pdung_cels = &pdung_cels[-i + 32];
                v141 = tmp_pbDst + 32;
              }
              tmp_pbDst = v141 - 800;
              if ( !i )
                break;
            }
            v143 = 2;
            do
            {
              if ( tmp_pbDst < gpBufEnd )
              {
                v144 = &tmp_pbDst[v143];
                v145 = (unsigned int)(32 - v143) >> 2;
                if ( !__CFSHR__(32 - v143, 2) || (*(_WORD *)v144 = 0, v144 += 2, v145) )
                {
                  do
                  {
                    *(_DWORD *)v144 = 0;
                    v144 += 4;
                    --v145;
                  }
                  while ( v145 );
                }
              }
              else
              {
                pdung_cels = &pdung_cels[-v143 + 32];
                v144 = tmp_pbDst + 32;
              }
              tmp_pbDst = v144 - 800;
              v143 += 2;
            }
            while ( v143 != 32 );
            break;
          case 3:
            for ( j = 30; ; j -= 2 )
            {
              if ( tmp_pbDst < gpBufEnd )
              {
                v147 = (unsigned int)(32 - j) >> 2;
                if ( !__CFSHR__(32 - j, 2) || (*(_WORD *)tmp_pbDst = 0, tmp_pbDst += 2, v147) )
                {
                  do
                  {
                    *(_DWORD *)tmp_pbDst = 0;
                    tmp_pbDst += 4;
                    --v147;
                  }
                  while ( v147 );
                }
              }
              else
              {
                pdung_cels = &pdung_cels[-j + 32];
                tmp_pbDst = &tmp_pbDst[-j + 32];
              }
              v148 = tmp_pbDst - 800;
              if ( !j )
                break;
              tmp_pbDst = &v148[j];
            }
            v149 = 2;
            do
            {
              if ( v148 < gpBufEnd )
              {
                v150 = (unsigned int)(32 - v149) >> 2;
                if ( !__CFSHR__(32 - v149, 2) || (*(_WORD *)v148 = 0, v148 += 2, v150) )
                {
                  do
                  {
                    *(_DWORD *)v148 = 0;
                    v148 += 4;
                    --v150;
                  }
                  while ( v150 );
                }
              }
              else
              {
                pdung_cels = &pdung_cels[-v149 + 32];
                v148 = &v148[-v149 + 32];
              }
              v148 = &v148[v149 - 800];
              v149 += 2;
            }
            while ( v149 != 32 );
            break;
          case 4:
            for ( k = 30; ; k -= 2 )
            {
              if ( tmp_pbDst < gpBufEnd )
              {
                v152 = &tmp_pbDst[k];
                v153 = (unsigned int)(32 - k) >> 2;
                if ( !__CFSHR__(32 - k, 2) || (*(_WORD *)v152 = 0, v152 += 2, v153) )
                {
                  do
                  {
                    *(_DWORD *)v152 = 0;
                    v152 += 4;
                    --v153;
                  }
                  while ( v153 );
                }
              }
              else
              {
                pdung_cels = &pdung_cels[-k + 32];
                v152 = tmp_pbDst + 32;
              }
              tmp_pbDst = v152 - 800;
              if ( !k )
                break;
            }
            v154 = 16;
            do
            {
              if ( tmp_pbDst < gpBufEnd )
              {
                v155 = 8;
                do
                {
                  *(_DWORD *)tmp_pbDst = 0;
                  tmp_pbDst += 4;
                  --v155;
                }
                while ( v155 );
              }
              else
              {
                pdung_cels += 32;
                tmp_pbDst += 32;
              }
              tmp_pbDst -= 800;
              --v154;
            }
            while ( v154 );
            break;
          default:
            for ( l = 30; ; l -= 2 )
            {
              if ( tmp_pbDst < gpBufEnd )
              {
                v157 = (unsigned int)(32 - l) >> 2;
                if ( !__CFSHR__(32 - l, 2) || (*(_WORD *)tmp_pbDst = 0, tmp_pbDst += 2, v157) )
                {
                  do
                  {
                    *(_DWORD *)tmp_pbDst = 0;
                    tmp_pbDst += 4;
                    --v157;
                  }
                  while ( v157 );
                }
              }
              else
              {
                pdung_cels = &pdung_cels[-l + 32];
                tmp_pbDst = &tmp_pbDst[-l + 32];
              }
              v158 = tmp_pbDst - 800;
              if ( !l )
                break;
              tmp_pbDst = &v158[l];
            }
            v159 = 16;
            do
            {
              if ( v158 < gpBufEnd )
              {
                v160 = 8;
                do
                {
                  *(_DWORD *)v158 = 0;
                  v158 += 4;
                  --v160;
                }
                while ( v160 );
              }
              else
              {
                pdung_cels += 32;
                v158 += 32;
              }
              v158 -= 800;
              --v159;
            }
            while ( v159 );
            break;
        }
      }
      else
      {
        v133 = 32;
        do
        {
          if ( tmp_pbDst < gpBufEnd )
          {
            v134 = 8;
            do
            {
              *(_DWORD *)tmp_pbDst = 0;
              tmp_pbDst += 4;
              --v134;
            }
            while ( v134 );
          }
          else
          {
            pdung_cels += 32;
            tmp_pbDst += 32;
          }
          tmp_pbDst -= 800;
          --v133;
        }
        while ( v133 );
      }
      return;
    }
    if ( !(level_cel_block & 0x8000) )
    {
      pdung_cels2 = (char *)pDungeonCels + *((_DWORD *)pDungeonCels + (level_cel_block & 0xFFF));
      l_tbl = &pLightTbl[256 * light_table_index];
      v7 = (unsigned __int16)level_cel_block >> 12;
      if ( !((unsigned __int16)level_cel_block >> 12) )
      {
        v13 = 32;
        do
        {
          v161 = v13;
          if ( tmp_pbDst < gpBufEnd )
          {
            v14 = 0;
            v15 = 8;
            do
            {
              v16 = *(_DWORD *)pdung_cels2;
              pdung_cels2 += 4;
              v16 = __ROR4__(v16, 16);
              LOBYTE(v14) = v16;
              LOBYTE(pbDst) = l_tbl[v14];
              LOBYTE(v14) = BYTE1(v16);
              BYTE1(pbDst) = l_tbl[v14];
              v16 = __ROR4__(v16, 16);
              pbDst = (unsigned __int8 *)((_DWORD)pbDst << 16);
              LOBYTE(v14) = v16;
              LOBYTE(pbDst) = l_tbl[v14];
              LOBYTE(v14) = BYTE1(v16);
              BYTE1(pbDst) = l_tbl[v14];
              *(_DWORD *)tmp_pbDst = pbDst;
              tmp_pbDst += 4;
              --v15;
            }
            while ( v15 );
          }
          else
          {
            pdung_cels2 += 32;
            tmp_pbDst += 32;
          }
          tmp_pbDst -= 800;
          v13 = v161 - 1;
        }
        while ( v161 != 1 );
        return;
      }
      if ( v7 == 1 )
      {
        v17 = 32;
        do
        {
          v162 = v17;
          v18 = 32;
          do
          {
            v19 = (unsigned __int8)*pdung_cels2++;
            if ( (v19 & 0x80u) == 0 )
            {
              v18 -= v19;
              if ( tmp_pbDst < gpBufEnd )
              {
                for ( m = v19; m >= 4; m -= 4 )
                {
                  v21 = *(_DWORD *)pdung_cels2;
                  pdung_cels2 += 4;
                  LOBYTE(v1) = v21;
                  v22 = l_tbl[v1];
                  LOBYTE(v1) = BYTE1(v21);
                  v21 = __ROR4__(v21, 16);
                  *tmp_pbDst = v22;
                  v23 = l_tbl[v1];
                  LOBYTE(v1) = v21;
                  tmp_pbDst[1] = v23;
                  v24 = l_tbl[v1];
                  LOBYTE(v1) = BYTE1(v21);
                  tmp_pbDst[2] = v24;
                  tmp_pbDst[3] = l_tbl[v1];
                  tmp_pbDst += 4;
                }
                if ( m >= 2 )
                {
                  LOBYTE(v1) = *pdung_cels2;
                  *tmp_pbDst = l_tbl[v1];
                  LOBYTE(v1) = pdung_cels2[1];
                  tmp_pbDst[1] = l_tbl[v1];
                  pdung_cels2 += 2;
                  tmp_pbDst += 2;
                }
                if ( m & 1 )
                {
                  LOBYTE(v1) = *pdung_cels2++;
                  *tmp_pbDst++ = l_tbl[v1];
                }
              }
              else
              {
                pdung_cels2 += v19;
                tmp_pbDst += v19;
              }
            }
            else
            {
              LOBYTE(v19) = -(char)v19;
              tmp_pbDst += v19;
              v18 -= v19;
            }
          }
          while ( v18 );
          tmp_pbDst -= 800;
          v17 = v162 - 1;
        }
        while ( v162 != 1 );
        return;
      }
      if ( v7 != 2 )
      {
        if ( v7 != 3 )
        {
          if ( v7 != 4 )
          {
            v61 = 30;
            if ( pbDst >= gpBufEnd )
            {
              v62 = (unsigned int)(pbDst - gpBufEnd + 1023) >> 8;
              if ( v62 > 45 )
              {
                tmp_pbDst = pbDst - 12288;
                pdung_cels2 += 288;
LABEL_116:
                v69 = 16;
                do
                {
                  if ( tmp_pbDst < gpBufEnd )
                  {
                    v70 = 32;
                    do
                    {
                      v71 = *(_DWORD *)pdung_cels2;
                      pdung_cels2 += 4;
                      LOBYTE(v1) = v71;
                      v72 = l_tbl[v1];
                      LOBYTE(v1) = BYTE1(v71);
                      v71 = __ROR4__(v71, 16);
                      *tmp_pbDst = v72;
                      v73 = l_tbl[v1];
                      LOBYTE(v1) = v71;
                      tmp_pbDst[1] = v73;
                      v74 = l_tbl[v1];
                      LOBYTE(v1) = BYTE1(v71);
                      tmp_pbDst[2] = v74;
                      tmp_pbDst[3] = l_tbl[v1];
                      tmp_pbDst += 4;
                      v70 -= 4;
                    }
                    while ( v70 >= 4 );
                  }
                  else
                  {
                    pdung_cels2 += 32;
                    tmp_pbDst += 32;
                  }
                  tmp_pbDst -= 800;
                  --v69;
                }
                while ( v69 );
                return;
              }
              v63 = WorldTbl3x16[v62];
              pdung_cels2 += *(int *)((char *)WorldTbl17_1 + v63);
              tmp_pbDst -= 192 * v63;
              v61 = 30 - (v63 >> 1);
            }
            do
            {
              for ( n = 32 - v61; n >= 4; n -= 4 )
              {
                v65 = *(_DWORD *)pdung_cels2;
                pdung_cels2 += 4;
                LOBYTE(v1) = v65;
                v66 = l_tbl[v1];
                LOBYTE(v1) = BYTE1(v65);
                v65 = __ROR4__(v65, 16);
                *tmp_pbDst = v66;
                v67 = l_tbl[v1];
                LOBYTE(v1) = v65;
                tmp_pbDst[1] = v67;
                v68 = l_tbl[v1];
                LOBYTE(v1) = BYTE1(v65);
                tmp_pbDst[2] = v68;
                tmp_pbDst[3] = l_tbl[v1];
                tmp_pbDst += 4;
              }
              if ( n >= 2 )
              {
                LOBYTE(v1) = *pdung_cels2;
                *tmp_pbDst = l_tbl[v1];
                LOBYTE(v1) = pdung_cels2[1];
                tmp_pbDst[1] = l_tbl[v1];
                pdung_cels2 += 2;
                tmp_pbDst += 2;
              }
              v1 = (unsigned __int8)pdung_cels2 & 2;
              pdung_cels2 += v1;
              tmp_pbDst = &tmp_pbDst[v61 - 800];
              v31 = __OFSUB__(v61, 2);
              v61 -= 2;
            }
            while ( !((v61 < 0) ^ v31) );
            goto LABEL_116;
          }
          v46 = 30;
          if ( pbDst >= gpBufEnd )
          {
            v47 = (unsigned int)(pbDst - gpBufEnd + 1023) >> 8;
            if ( v47 > 45 )
            {
              tmp_pbDst = pbDst - 12288;
              pdung_cels2 += 288;
LABEL_100:
              v55 = 16;
              do
              {
                if ( tmp_pbDst < gpBufEnd )
                {
                  v56 = 32;
                  do
                  {
                    v57 = *(_DWORD *)pdung_cels2;
                    pdung_cels2 += 4;
                    LOBYTE(v1) = v57;
                    v58 = l_tbl[v1];
                    LOBYTE(v1) = BYTE1(v57);
                    v57 = __ROR4__(v57, 16);
                    *tmp_pbDst = v58;
                    v59 = l_tbl[v1];
                    LOBYTE(v1) = v57;
                    tmp_pbDst[1] = v59;
                    v60 = l_tbl[v1];
                    LOBYTE(v1) = BYTE1(v57);
                    tmp_pbDst[2] = v60;
                    tmp_pbDst[3] = l_tbl[v1];
                    tmp_pbDst += 4;
                    v56 -= 4;
                  }
                  while ( v56 >= 4 );
                }
                else
                {
                  pdung_cels2 += 32;
                  tmp_pbDst += 32;
                }
                tmp_pbDst -= 800;
                --v55;
              }
              while ( v55 );
              return;
            }
            v48 = WorldTbl3x16[v47];
            pdung_cels2 += *(int *)((char *)WorldTbl17_1 + v48);
            tmp_pbDst -= 192 * v48;
            v46 = 30 - (v48 >> 1);
          }
          do
          {
            v49 = &tmp_pbDst[v46];
            v50 = 32 - v46;
            v1 = (32 - (_BYTE)v46) & 2;
            pdung_cels2 += v1;
            if ( (char)(32 - v46) >= 4 )
            {
              do
              {
                v51 = *(_DWORD *)pdung_cels2;
                pdung_cels2 += 4;
                LOBYTE(v1) = v51;
                v52 = l_tbl[v1];
                LOBYTE(v1) = BYTE1(v51);
                v51 = __ROR4__(v51, 16);
                *v49 = v52;
                v53 = l_tbl[v1];
                LOBYTE(v1) = v51;
                v49[1] = v53;
                v54 = l_tbl[v1];
                LOBYTE(v1) = BYTE1(v51);
                v49[2] = v54;
                v49[3] = l_tbl[v1];
                v49 += 4;
                v50 -= 4;
              }
              while ( v50 >= 4 );
            }
            if ( v50 >= 2 )
            {
              LOBYTE(v1) = *pdung_cels2;
              *v49 = l_tbl[v1];
              LOBYTE(v1) = pdung_cels2[1];
              v49[1] = l_tbl[v1];
              pdung_cels2 += 2;
              v49 += 2;
            }
            tmp_pbDst = v49 - 800;
            v31 = __OFSUB__(v46, 2);
            v46 -= 2;
          }
          while ( !((v46 < 0) ^ v31) );
          goto LABEL_100;
        }
        v38 = 30;
        if ( pbDst >= gpBufEnd )
        {
          v39 = (unsigned int)(pbDst - gpBufEnd + 1023) >> 8;
          if ( v39 > 45 )
          {
            tmp_pbDst = pbDst - 12288;
            pdung_cels2 += 288;
LABEL_83:
            v42 = 2;
            if ( tmp_pbDst >= gpBufEnd )
            {
              v43 = (unsigned int)(tmp_pbDst - gpBufEnd + 1023) >> 8;
              if ( v43 > 42 )
                return;
              v44 = WorldTbl3x16[v43];
              pdung_cels2 += *(int *)((char *)WorldTbl17_2 + v44);
              tmp_pbDst -= 192 * v44;
              v42 = (v44 >> 1) + 2;
            }
            do
            {
              v45 = 32 - v42;
              do
              {
                LOBYTE(v1) = *pdung_cels2++;
                *tmp_pbDst++ = l_tbl[v1];
                --v45;
              }
              while ( v45 );
              v1 = (unsigned __int8)pdung_cels2 & 2;
              pdung_cels2 += v1;
              tmp_pbDst = &tmp_pbDst[v42 - 800];
              v42 += 2;
            }
            while ( v42 != 32 );
            return;
          }
          v40 = WorldTbl3x16[v39];
          pdung_cels2 += *(int *)((char *)WorldTbl17_1 + v40);
          tmp_pbDst -= 192 * v40;
          v38 = 30 - (v40 >> 1);
        }
        do
        {
          v41 = 32 - v38;
          do
          {
            LOBYTE(v1) = *pdung_cels2++;
            *tmp_pbDst++ = l_tbl[v1];
            --v41;
          }
          while ( v41 );
          v1 = (unsigned __int8)pdung_cels2 & 2;
          pdung_cels2 += v1;
          tmp_pbDst = &tmp_pbDst[v38 - 800];
          v31 = __OFSUB__(v38, 2);
          v38 -= 2;
        }
        while ( !((v38 < 0) ^ v31) );
        goto LABEL_83;
      }
      v25 = 30;
      if ( pbDst >= gpBufEnd )
      {
        v26 = (unsigned int)(pbDst - gpBufEnd + 1023) >> 8;
        if ( v26 > 45 )
        {
          tmp_pbDst = pbDst - 12288;
          pdung_cels2 += 288;
LABEL_68:
          v32 = 2;
          if ( tmp_pbDst >= gpBufEnd )
          {
            v33 = (unsigned int)(tmp_pbDst - gpBufEnd + 1023) >> 8;
            if ( v33 > 42 )
              return;
            v34 = WorldTbl3x16[v33];
            pdung_cels2 += *(int *)((char *)WorldTbl17_2 + v34);
            tmp_pbDst -= 192 * v34;
            v32 = (v34 >> 1) + 2;
          }
          do
          {
            v35 = &tmp_pbDst[v32];
            v36 = 32 - v32;
            v37 = (32 - (_BYTE)v32) & 2;
            pdung_cels2 += v37;
            do
            {
              LOBYTE(v37) = *pdung_cels2++;
              *v35++ = l_tbl[v37];
              --v36;
            }
            while ( v36 );
            v32 += 2;
            tmp_pbDst = v35 - 800;
          }
          while ( v32 != 32 );
          return;
        }
        v27 = WorldTbl3x16[v26];
        pdung_cels2 += *(int *)((char *)WorldTbl17_1 + v27);
        tmp_pbDst -= 192 * v27;
        v25 = 30 - (v27 >> 1);
      }
      do
      {
        v28 = &tmp_pbDst[v25];
        v29 = 32 - v25;
        v30 = (32 - (_BYTE)v25) & 2;
        pdung_cels2 += v30;
        do
        {
          LOBYTE(v30) = *pdung_cels2++;
          *v28++ = l_tbl[v30];
          --v29;
        }
        while ( v29 );
        tmp_pbDst = v28 - 800;
        v31 = __OFSUB__(v25, 2);
        v25 -= 2;
      }
      while ( !((v25 < 0) ^ v31) );
      goto LABEL_68;
    }
    v8 = (unsigned __int8 *)pSpeedCels
       + *(_DWORD *)&gpCelFrame[4 * (light_table_index + 16 * (level_cel_block & 0xFFF))];
    v9 = (unsigned __int16)level_cel_block >> 12;
  }
  else
  {
    if ( level_cel_block & 0x8000 )
      level_cel_block = *(_DWORD *)&gpCelFrame[64 * (level_cel_block & 0xFFF)]
                      + (unsigned __int16)(level_cel_block & 0xF000);
    v8 = (unsigned __int8 *)pDungeonCels + *((_DWORD *)pDungeonCels + (level_cel_block & 0xFFF));
    v9 = (((unsigned int)level_cel_block >> 12) & 7) + 8;
  }
  switch ( v9 )
  {
    case 8:
      v75 = 32;
      do
      {
        if ( tmp_pbDst < gpBufEnd )
        {
          v76 = 8;
          do
          {
            v77 = *(_DWORD *)v8;
            v8 += 4;
            *(_DWORD *)tmp_pbDst = v77;
            tmp_pbDst += 4;
            --v76;
          }
          while ( v76 );
        }
        else
        {
          v8 += 32;
          tmp_pbDst += 32;
        }
        tmp_pbDst -= 800;
        --v75;
      }
      while ( v75 );
      return;
    case 9:
      v78 = 32;
      do
      {
        v163 = v78;
        v79 = 32;
        do
        {
          while ( 1 )
          {
            v80 = *v8++;
            if ( (v80 & 0x80u) == 0 )
              break;
            LOBYTE(v80) = -(char)v80;
            tmp_pbDst += v80;
            v79 -= v80;
            if ( !v79 )
              goto LABEL_143;
          }
          v79 -= v80;
          if ( tmp_pbDst < gpBufEnd )
          {
            v81 = v80 >> 1;
            if ( !(v80 & 1) || (v82 = *v8, ++v8, *tmp_pbDst = v82, ++tmp_pbDst, v81) )
            {
              v83 = v81 & 1;
              v84 = v81 >> 1;
              if ( !v83 || (v85 = *(_WORD *)v8, v8 += 2, *(_WORD *)tmp_pbDst = v85, tmp_pbDst += 2, v84) )
              {
                do
                {
                  v86 = *(_DWORD *)v8;
                  v8 += 4;
                  *(_DWORD *)tmp_pbDst = v86;
                  tmp_pbDst += 4;
                  --v84;
                }
                while ( v84 );
              }
            }
          }
          else
          {
            v8 += v80;
            tmp_pbDst += v80;
          }
        }
        while ( v79 );
LABEL_143:
        tmp_pbDst -= 800;
        v78 = v163 - 1;
      }
      while ( v163 != 1 );
      return;
    case 10:
      v87 = 30;
      if ( pbDst >= gpBufEnd )
      {
        v88 = (unsigned int)(pbDst - gpBufEnd + 1023) >> 8;
        if ( v88 > 45 )
        {
          tmp_pbDst = pbDst - 12288;
          v8 += 288;
LABEL_153:
          v94 = 2;
          if ( tmp_pbDst >= gpBufEnd )
          {
            v95 = (unsigned int)(tmp_pbDst - gpBufEnd + 1023) >> 8;
            if ( v95 > 42 )
              return;
            v96 = WorldTbl3x16[v95];
            v8 += *(int *)((char *)WorldTbl17_2 + v96);
            tmp_pbDst -= 192 * v96;
            v94 = (v96 >> 1) + 2;
          }
          do
          {
            v97 = &tmp_pbDst[v94];
            v98 = (unsigned int)(32 - v94) >> 2;
            if ( !__CFSHR__(32 - v94, 2) || (v99 = *((_WORD *)v8 + 1), v8 += 4, *(_WORD *)v97 = v99, v97 += 2, v98) )
            {
              do
              {
                v100 = *(_DWORD *)v8;
                v8 += 4;
                *(_DWORD *)v97 = v100;
                v97 += 4;
                --v98;
              }
              while ( v98 );
            }
            v94 += 2;
            tmp_pbDst = v97 - 800;
          }
          while ( v94 < 32 );
          return;
        }
        v89 = WorldTbl3x16[v88];
        v8 += *(int *)((char *)WorldTbl17_1 + v89);
        tmp_pbDst -= 192 * v89;
        v87 = 30 - (v89 >> 1);
      }
      do
      {
        v90 = &tmp_pbDst[v87];
        v91 = (unsigned int)(32 - v87) >> 2;
        if ( !__CFSHR__(32 - v87, 2) || (v92 = *((_WORD *)v8 + 1), v8 += 4, *(_WORD *)v90 = v92, v90 += 2, v91) )
        {
          do
          {
            v93 = *(_DWORD *)v8;
            v8 += 4;
            *(_DWORD *)v90 = v93;
            v90 += 4;
            --v91;
          }
          while ( v91 );
        }
        tmp_pbDst = v90 - 800;
        v31 = __OFSUB__(v87, 2);
        v87 -= 2;
      }
      while ( !((v87 < 0) ^ v31) );
      goto LABEL_153;
  }
  if ( v9 != 11 )
  {
    if ( v9 != 12 )
    {
      v124 = 30;
      if ( pbDst >= gpBufEnd )
      {
        v125 = (unsigned int)(pbDst - gpBufEnd + 1023) >> 8;
        if ( v125 > 45 )
        {
          tmp_pbDst = pbDst - 12288;
          v8 += 288;
LABEL_205:
          v130 = 16;
          do
          {
            if ( tmp_pbDst < gpBufEnd )
            {
              v131 = 8;
              do
              {
                v132 = *(_DWORD *)v8;
                v8 += 4;
                *(_DWORD *)tmp_pbDst = v132;
                tmp_pbDst += 4;
                --v131;
              }
              while ( v131 );
            }
            else
            {
              v8 += 32;
              tmp_pbDst += 32;
            }
            tmp_pbDst -= 800;
            --v130;
          }
          while ( v130 );
          return;
        }
        v126 = WorldTbl3x16[v125];
        v8 += *(int *)((char *)WorldTbl17_1 + v126);
        tmp_pbDst -= 192 * v126;
        v124 = 30 - (v126 >> 1);
      }
      do
      {
        for ( ii = (unsigned int)(32 - v124) >> 2; ii; --ii )
        {
          v128 = *(_DWORD *)v8;
          v8 += 4;
          *(_DWORD *)tmp_pbDst = v128;
          tmp_pbDst += 4;
        }
        if ( (32 - (_BYTE)v124) & 2 )
        {
          v129 = *(_WORD *)v8;
          v8 += 4;
          *(_WORD *)tmp_pbDst = v129;
          tmp_pbDst += 2;
        }
        tmp_pbDst = &tmp_pbDst[v124 - 800];
        v31 = __OFSUB__(v124, 2);
        v124 -= 2;
      }
      while ( !((v124 < 0) ^ v31) );
      goto LABEL_205;
    }
    v114 = 30;
    if ( pbDst >= gpBufEnd )
    {
      v115 = (unsigned int)(pbDst - gpBufEnd + 1023) >> 8;
      if ( v115 > 45 )
      {
        tmp_pbDst = pbDst - 12288;
        v8 += 288;
LABEL_189:
        v121 = 16;
        do
        {
          if ( tmp_pbDst < gpBufEnd )
          {
            v122 = 8;
            do
            {
              v123 = *(_DWORD *)v8;
              v8 += 4;
              *(_DWORD *)tmp_pbDst = v123;
              tmp_pbDst += 4;
              --v122;
            }
            while ( v122 );
          }
          else
          {
            v8 += 32;
            tmp_pbDst += 32;
          }
          tmp_pbDst -= 800;
          --v121;
        }
        while ( v121 );
        return;
      }
      v116 = WorldTbl3x16[v115];
      v8 += *(int *)((char *)WorldTbl17_1 + v116);
      tmp_pbDst -= 192 * v116;
      v114 = 30 - (v116 >> 1);
    }
    do
    {
      v117 = &tmp_pbDst[v114];
      v118 = (unsigned int)(32 - v114) >> 2;
      if ( !__CFSHR__(32 - v114, 2) || (v119 = *((_WORD *)v8 + 1), v8 += 4, *(_WORD *)v117 = v119, v117 += 2, v118) )
      {
        do
        {
          v120 = *(_DWORD *)v8;
          v8 += 4;
          *(_DWORD *)v117 = v120;
          v117 += 4;
          --v118;
        }
        while ( v118 );
      }
      tmp_pbDst = v117 - 800;
      v31 = __OFSUB__(v114, 2);
      v114 -= 2;
    }
    while ( !((v114 < 0) ^ v31) );
    goto LABEL_189;
  }
  v101 = 30;
  if ( pbDst < gpBufEnd )
    goto LABEL_166;
  v102 = (unsigned int)(pbDst - gpBufEnd + 1023) >> 8;
  if ( v102 <= 45 )
  {
    v103 = WorldTbl3x16[v102];
    v8 += *(int *)((char *)WorldTbl17_1 + v103);
    tmp_pbDst -= 192 * v103;
    v101 = 30 - (v103 >> 1);
    do
    {
LABEL_166:
      for ( jj = (unsigned int)(32 - v101) >> 2; jj; --jj )
      {
        v105 = *(_DWORD *)v8;
        v8 += 4;
        *(_DWORD *)tmp_pbDst = v105;
        tmp_pbDst += 4;
      }
      if ( (32 - (_BYTE)v101) & 2 )
      {
        v106 = *(_WORD *)v8;
        v8 += 4;
        *(_WORD *)tmp_pbDst = v106;
        tmp_pbDst += 2;
      }
      tmp_pbDst = &tmp_pbDst[v101 - 800];
      v31 = __OFSUB__(v101, 2);
      v101 -= 2;
    }
    while ( !((v101 < 0) ^ v31) );
    goto LABEL_171;
  }
  tmp_pbDst = pbDst - 12288;
  v8 += 288;
LABEL_171:
  v107 = 2;
  if ( tmp_pbDst >= gpBufEnd )
  {
    v108 = (unsigned int)(tmp_pbDst - gpBufEnd + 1023) >> 8;
    if ( v108 > 42 )
      return;
    v109 = WorldTbl3x16[v108];
    v8 += *(int *)((char *)WorldTbl17_2 + v109);
    tmp_pbDst -= 192 * v109;
    v107 = (v109 >> 1) + 2;
  }
  do
  {
    for ( kk = (unsigned int)(32 - v107) >> 2; kk; --kk )
    {
      v111 = *(_DWORD *)v8;
      v8 += 4;
      *(_DWORD *)tmp_pbDst = v111;
      tmp_pbDst += 4;
    }
    if ( (32 - (_BYTE)v107) & 2 )
    {
      v112 = *(_WORD *)v8;
      v8 += 4;
      *(_WORD *)tmp_pbDst = v112;
      tmp_pbDst += 2;
    }
    v113 = (int)&tmp_pbDst[v107];
    v107 += 2;
    tmp_pbDst = (unsigned __int8 *)(v113 - 800);
  }
  while ( v107 < 32 );
}

//----- (004A6AEA) --------------------------------------------------------
void __fastcall world_draw_black_tile(char *dst_buf)
{
  char *v1; // edi
  signed int v2; // edx
  signed int i; // ebx
  char *v4; // edi
  signed int v5; // ecx
  signed int v6; // edx
  signed int v7; // ebx
  char *v8; // edi
  signed int v9; // ecx

  v1 = dst_buf;
  v2 = 30;
  for ( i = 1; ; ++i )
  {
    v4 = &v1[v2];
    v5 = i;
    do
    {
      *(_DWORD *)v4 = 0;
      v4 += 4;
      --v5;
    }
    while ( v5 );
    v1 = &v4[v2 - 832];
    if ( !v2 )
      break;
    v2 -= 2;
  }
  v6 = 2;
  v7 = 15;
  do
  {
    v8 = &v1[v6];
    v9 = v7;
    do
    {
      *(_DWORD *)v8 = 0;
      v8 += 4;
      --v9;
    }
    while ( v9 );
    v1 = &v8[v6 - 832];
    --v7;
    v6 += 2;
  }
  while ( v6 != 32 );
}

