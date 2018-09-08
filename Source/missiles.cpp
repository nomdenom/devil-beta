#include "all.h"

//----- (0043AE00) --------------------------------------------------------
int __fastcall FindClosest(int sx, int sy, int rad)
{
  int v3; // ST18_4
  int v5; // [esp+14h] [ebp-60h]
  int CrawlNum[19]; // [esp+1Ch] [ebp-58h]
  int j; // [esp+68h] [ebp-Ch]
  int i; // [esp+6Ch] [ebp-8h]
  int v9; // [esp+70h] [ebp-4h]

  CrawlNum[0] = 0;
  CrawlNum[1] = 3;
  CrawlNum[2] = 12;
  CrawlNum[3] = 45;
  CrawlNum[4] = 94;
  CrawlNum[5] = 159;
  CrawlNum[6] = 240;
  CrawlNum[7] = 337;
  CrawlNum[8] = 450;
  CrawlNum[9] = 579;
  CrawlNum[10] = 724;
  CrawlNum[11] = 885;
  CrawlNum[12] = 1062;
  CrawlNum[13] = 1255;
  CrawlNum[14] = 1464;
  CrawlNum[15] = 1689;
  CrawlNum[16] = 1930;
  CrawlNum[17] = 2187;
  CrawlNum[18] = 2460;
  if ( rad > 19 )
    rad = 19;
  for ( i = 1; i < rad; ++i )
  {
    v3 = CrawlNum[i];
    v5 = v3 + 1;
    for ( j = (unsigned __int8)CrawlTable[v3]; j > 0; --j )
    {
      v9 = dMonster[sx + CrawlTable[v5]][sy + CrawlTable[v5 + 1]];
      if ( v9 > 0 )
        return v9 - 1;
      v5 += 2;
    }
  }
  return -1;
}

//----- (0043AF51) --------------------------------------------------------
int __fastcall GetSpellLevel(int id, int sn)
{
  int v3; // [esp+14h] [ebp-4h]

  v3 = plr[id]._pISplLvlAdd + plr[id]._pSplLvl[sn];
  if ( v3 < 0 )
    v3 = 0;
  return v3;
}

//----- (0043AFC2) --------------------------------------------------------
void __fastcall missiles_43AFC2(int a1, int a2, int a3, int a4, int a5)
{
  ;
}

//----- (0043B031) --------------------------------------------------------
BOOL __fastcall CheckBlock(int fx, int fy, int tx, int ty)
{
  int v4; // ST1C_4
  int y1a; // [esp+Ch] [ebp-14h]
  int x1a; // [esp+10h] [ebp-10h]
  BOOL v8; // [esp+1Ch] [ebp-4h]

  y1a = fy;
  x1a = fx;
  v8 = 0;
  while ( tx != x1a || ty != y1a )
  {
    v4 = GetDirection(x1a, y1a, tx, ty);
    x1a += XDirAdd[v4];
    y1a += YDirAdd[v4];
    if ( nSolidTable[dPiece[x1a][y1a]] )
      v8 = 1;
  }
  return v8;
}

//----- (0043B0D7) --------------------------------------------------------
int __fastcall GetDirection8(int x1, int y1, int x2, int y2)
{
  int v5; // [esp+Ch] [ebp-124h]
  int v6; // [esp+10h] [ebp-120h]
  char v7; // [esp+14h] [ebp-11Ch]
  char v8; // [esp+15h] [ebp-11Bh]
  char v9; // [esp+16h] [ebp-11Ah]
  char v10; // [esp+17h] [ebp-119h]
  char v11; // [esp+18h] [ebp-118h]
  char v12; // [esp+19h] [ebp-117h]
  char v13; // [esp+1Ah] [ebp-116h]
  char v14; // [esp+1Bh] [ebp-115h]
  char v15; // [esp+1Ch] [ebp-114h]
  char v16; // [esp+1Dh] [ebp-113h]
  char v17; // [esp+1Eh] [ebp-112h]
  char v18; // [esp+1Fh] [ebp-111h]
  char v19; // [esp+20h] [ebp-110h]
  char v20; // [esp+21h] [ebp-10Fh]
  char v21; // [esp+22h] [ebp-10Eh]
  char v22; // [esp+23h] [ebp-10Dh]
  char v23; // [esp+24h] [ebp-10Ch]
  char v24; // [esp+25h] [ebp-10Bh]
  char v25; // [esp+26h] [ebp-10Ah]
  char v26; // [esp+27h] [ebp-109h]
  char v27; // [esp+28h] [ebp-108h]
  char v28; // [esp+29h] [ebp-107h]
  char v29; // [esp+2Ah] [ebp-106h]
  char v30; // [esp+2Bh] [ebp-105h]
  char v31; // [esp+2Ch] [ebp-104h]
  char v32; // [esp+2Dh] [ebp-103h]
  char v33; // [esp+2Eh] [ebp-102h]
  char v34; // [esp+2Fh] [ebp-101h]
  char v35; // [esp+30h] [ebp-100h]
  char v36; // [esp+31h] [ebp-FFh]
  char v37; // [esp+32h] [ebp-FEh]
  char v38; // [esp+33h] [ebp-FDh]
  char v39; // [esp+34h] [ebp-FCh]
  char v40; // [esp+35h] [ebp-FBh]
  char v41; // [esp+36h] [ebp-FAh]
  char v42; // [esp+37h] [ebp-F9h]
  char v43; // [esp+38h] [ebp-F8h]
  char v44; // [esp+39h] [ebp-F7h]
  char v45; // [esp+3Ah] [ebp-F6h]
  char v46; // [esp+3Bh] [ebp-F5h]
  char v47; // [esp+3Ch] [ebp-F4h]
  char v48; // [esp+3Dh] [ebp-F3h]
  char v49; // [esp+3Eh] [ebp-F2h]
  char v50; // [esp+3Fh] [ebp-F1h]
  char v51; // [esp+40h] [ebp-F0h]
  char v52; // [esp+41h] [ebp-EFh]
  char v53; // [esp+42h] [ebp-EEh]
  char v54; // [esp+43h] [ebp-EDh]
  char v55; // [esp+44h] [ebp-ECh]
  char v56; // [esp+45h] [ebp-EBh]
  char v57; // [esp+46h] [ebp-EAh]
  char v58; // [esp+47h] [ebp-E9h]
  char v59; // [esp+48h] [ebp-E8h]
  char v60; // [esp+49h] [ebp-E7h]
  char v61; // [esp+4Ah] [ebp-E6h]
  char v62; // [esp+4Bh] [ebp-E5h]
  char v63; // [esp+4Ch] [ebp-E4h]
  char v64; // [esp+4Dh] [ebp-E3h]
  char v65; // [esp+4Eh] [ebp-E2h]
  char v66; // [esp+4Fh] [ebp-E1h]
  char v67; // [esp+50h] [ebp-E0h]
  char v68; // [esp+51h] [ebp-DFh]
  char v69; // [esp+52h] [ebp-DEh]
  char v70; // [esp+53h] [ebp-DDh]
  char v71; // [esp+54h] [ebp-DCh]
  char v72; // [esp+55h] [ebp-DBh]
  char v73; // [esp+56h] [ebp-DAh]
  char v74; // [esp+57h] [ebp-D9h]
  char v75; // [esp+58h] [ebp-D8h]
  char v76; // [esp+59h] [ebp-D7h]
  char v77; // [esp+5Ah] [ebp-D6h]
  char v78; // [esp+5Bh] [ebp-D5h]
  char v79; // [esp+5Ch] [ebp-D4h]
  char v80; // [esp+5Dh] [ebp-D3h]
  char v81; // [esp+5Eh] [ebp-D2h]
  char v82; // [esp+5Fh] [ebp-D1h]
  char v83; // [esp+60h] [ebp-D0h]
  char v84; // [esp+61h] [ebp-CFh]
  char v85; // [esp+62h] [ebp-CEh]
  char v86; // [esp+63h] [ebp-CDh]
  char v87; // [esp+64h] [ebp-CCh]
  char v88; // [esp+65h] [ebp-CBh]
  char v89; // [esp+66h] [ebp-CAh]
  char v90; // [esp+67h] [ebp-C9h]
  char v91; // [esp+68h] [ebp-C8h]
  char v92; // [esp+69h] [ebp-C7h]
  char v93; // [esp+6Ah] [ebp-C6h]
  char v94; // [esp+6Bh] [ebp-C5h]
  char v95; // [esp+6Ch] [ebp-C4h]
  char v96; // [esp+6Dh] [ebp-C3h]
  char v97; // [esp+6Eh] [ebp-C2h]
  char v98; // [esp+6Fh] [ebp-C1h]
  char v99; // [esp+70h] [ebp-C0h]
  char v100; // [esp+71h] [ebp-BFh]
  char v101; // [esp+72h] [ebp-BEh]
  char v102; // [esp+73h] [ebp-BDh]
  char v103; // [esp+74h] [ebp-BCh]
  char v104; // [esp+75h] [ebp-BBh]
  char v105; // [esp+76h] [ebp-BAh]
  char v106; // [esp+77h] [ebp-B9h]
  char v107; // [esp+78h] [ebp-B8h]
  char v108; // [esp+79h] [ebp-B7h]
  char v109; // [esp+7Ah] [ebp-B6h]
  char v110; // [esp+7Bh] [ebp-B5h]
  char v111; // [esp+7Ch] [ebp-B4h]
  char v112; // [esp+7Dh] [ebp-B3h]
  char v113; // [esp+7Eh] [ebp-B2h]
  char v114; // [esp+7Fh] [ebp-B1h]
  char v115; // [esp+80h] [ebp-B0h]
  char v116; // [esp+81h] [ebp-AFh]
  char v117; // [esp+82h] [ebp-AEh]
  char v118; // [esp+83h] [ebp-ADh]
  char v119; // [esp+84h] [ebp-ACh]
  char v120; // [esp+85h] [ebp-ABh]
  char v121; // [esp+86h] [ebp-AAh]
  char v122; // [esp+87h] [ebp-A9h]
  char v123; // [esp+88h] [ebp-A8h]
  char v124; // [esp+89h] [ebp-A7h]
  char v125; // [esp+8Ah] [ebp-A6h]
  char v126; // [esp+8Bh] [ebp-A5h]
  char v127; // [esp+8Ch] [ebp-A4h]
  char v128; // [esp+8Dh] [ebp-A3h]
  char v129; // [esp+8Eh] [ebp-A2h]
  char v130; // [esp+8Fh] [ebp-A1h]
  char v131; // [esp+90h] [ebp-A0h]
  char v132; // [esp+91h] [ebp-9Fh]
  char v133; // [esp+92h] [ebp-9Eh]
  char v134; // [esp+93h] [ebp-9Dh]
  char v135; // [esp+94h] [ebp-9Ch]
  char v136; // [esp+95h] [ebp-9Bh]
  char v137; // [esp+96h] [ebp-9Ah]
  char v138; // [esp+97h] [ebp-99h]
  char v139; // [esp+98h] [ebp-98h]
  char v140; // [esp+99h] [ebp-97h]
  char v141; // [esp+9Ah] [ebp-96h]
  char v142; // [esp+9Bh] [ebp-95h]
  char v143; // [esp+9Ch] [ebp-94h]
  char v144; // [esp+9Dh] [ebp-93h]
  char v145; // [esp+9Eh] [ebp-92h]
  char v146; // [esp+9Fh] [ebp-91h]
  char v147; // [esp+A0h] [ebp-90h]
  char v148; // [esp+A1h] [ebp-8Fh]
  char v149; // [esp+A2h] [ebp-8Eh]
  char v150; // [esp+A3h] [ebp-8Dh]
  char v151; // [esp+A4h] [ebp-8Ch]
  char v152; // [esp+A5h] [ebp-8Bh]
  char v153; // [esp+A6h] [ebp-8Ah]
  char v154; // [esp+A7h] [ebp-89h]
  char v155; // [esp+A8h] [ebp-88h]
  char v156; // [esp+A9h] [ebp-87h]
  char v157; // [esp+AAh] [ebp-86h]
  char v158; // [esp+ABh] [ebp-85h]
  char v159; // [esp+ACh] [ebp-84h]
  char v160; // [esp+ADh] [ebp-83h]
  char v161; // [esp+AEh] [ebp-82h]
  char v162; // [esp+AFh] [ebp-81h]
  char v163; // [esp+B0h] [ebp-80h]
  char v164; // [esp+B1h] [ebp-7Fh]
  char v165; // [esp+B2h] [ebp-7Eh]
  char v166; // [esp+B3h] [ebp-7Dh]
  char v167; // [esp+B4h] [ebp-7Ch]
  char v168; // [esp+B5h] [ebp-7Bh]
  char v169; // [esp+B6h] [ebp-7Ah]
  char v170; // [esp+B7h] [ebp-79h]
  char v171; // [esp+B8h] [ebp-78h]
  char v172; // [esp+B9h] [ebp-77h]
  char v173; // [esp+BAh] [ebp-76h]
  char v174; // [esp+BBh] [ebp-75h]
  char v175; // [esp+BCh] [ebp-74h]
  char v176; // [esp+BDh] [ebp-73h]
  char v177; // [esp+BEh] [ebp-72h]
  char v178; // [esp+BFh] [ebp-71h]
  char v179; // [esp+C0h] [ebp-70h]
  char v180; // [esp+C1h] [ebp-6Fh]
  char v181; // [esp+C2h] [ebp-6Eh]
  char v182; // [esp+C3h] [ebp-6Dh]
  char v183; // [esp+C4h] [ebp-6Ch]
  char v184; // [esp+C5h] [ebp-6Bh]
  char v185; // [esp+C6h] [ebp-6Ah]
  char v186; // [esp+C7h] [ebp-69h]
  char v187; // [esp+C8h] [ebp-68h]
  char v188; // [esp+C9h] [ebp-67h]
  char v189; // [esp+CAh] [ebp-66h]
  char v190; // [esp+CBh] [ebp-65h]
  char v191; // [esp+CCh] [ebp-64h]
  char v192; // [esp+CDh] [ebp-63h]
  char v193; // [esp+CEh] [ebp-62h]
  char v194; // [esp+CFh] [ebp-61h]
  char v195; // [esp+D0h] [ebp-60h]
  char v196; // [esp+D1h] [ebp-5Fh]
  char v197; // [esp+D2h] [ebp-5Eh]
  char v198; // [esp+D3h] [ebp-5Dh]
  char v199; // [esp+D4h] [ebp-5Ch]
  char v200; // [esp+D5h] [ebp-5Bh]
  char v201; // [esp+D6h] [ebp-5Ah]
  char v202; // [esp+D7h] [ebp-59h]
  char v203; // [esp+D8h] [ebp-58h]
  char v204; // [esp+D9h] [ebp-57h]
  char v205; // [esp+DAh] [ebp-56h]
  char v206; // [esp+DBh] [ebp-55h]
  char v207; // [esp+DCh] [ebp-54h]
  char v208; // [esp+DDh] [ebp-53h]
  char v209; // [esp+DEh] [ebp-52h]
  char v210; // [esp+DFh] [ebp-51h]
  char v211; // [esp+E0h] [ebp-50h]
  char v212; // [esp+E1h] [ebp-4Fh]
  char v213; // [esp+E2h] [ebp-4Eh]
  char v214; // [esp+E3h] [ebp-4Dh]
  char v215; // [esp+E4h] [ebp-4Ch]
  char v216; // [esp+E5h] [ebp-4Bh]
  char v217; // [esp+E6h] [ebp-4Ah]
  char v218; // [esp+E7h] [ebp-49h]
  char v219; // [esp+E8h] [ebp-48h]
  char v220; // [esp+E9h] [ebp-47h]
  char v221; // [esp+EAh] [ebp-46h]
  char v222; // [esp+EBh] [ebp-45h]
  char v223; // [esp+ECh] [ebp-44h]
  char v224; // [esp+EDh] [ebp-43h]
  char v225; // [esp+EEh] [ebp-42h]
  char v226; // [esp+EFh] [ebp-41h]
  char v227; // [esp+F0h] [ebp-40h]
  char v228; // [esp+F1h] [ebp-3Fh]
  char v229; // [esp+F2h] [ebp-3Eh]
  char v230; // [esp+F3h] [ebp-3Dh]
  char v231; // [esp+F4h] [ebp-3Ch]
  char v232; // [esp+F5h] [ebp-3Bh]
  char v233; // [esp+F6h] [ebp-3Ah]
  char v234; // [esp+F7h] [ebp-39h]
  char v235; // [esp+F8h] [ebp-38h]
  char v236; // [esp+F9h] [ebp-37h]
  char v237; // [esp+FAh] [ebp-36h]
  char v238; // [esp+FBh] [ebp-35h]
  char v239; // [esp+FCh] [ebp-34h]
  char v240; // [esp+FDh] [ebp-33h]
  char v241; // [esp+FEh] [ebp-32h]
  char v242; // [esp+FFh] [ebp-31h]
  char v243; // [esp+100h] [ebp-30h]
  char v244; // [esp+101h] [ebp-2Fh]
  char v245; // [esp+102h] [ebp-2Eh]
  char v246; // [esp+103h] [ebp-2Dh]
  char v247; // [esp+104h] [ebp-2Ch]
  char v248; // [esp+105h] [ebp-2Bh]
  char v249; // [esp+106h] [ebp-2Ah]
  char v250; // [esp+107h] [ebp-29h]
  char v251; // [esp+108h] [ebp-28h]
  char v252; // [esp+109h] [ebp-27h]
  char v253; // [esp+10Ah] [ebp-26h]
  char v254; // [esp+10Bh] [ebp-25h]
  char v255; // [esp+10Ch] [ebp-24h]
  char v256; // [esp+10Dh] [ebp-23h]
  char v257; // [esp+10Eh] [ebp-22h]
  char v258; // [esp+10Fh] [ebp-21h]
  char v259; // [esp+110h] [ebp-20h]
  char v260; // [esp+111h] [ebp-1Fh]
  char v261; // [esp+112h] [ebp-1Eh]
  char v262; // [esp+113h] [ebp-1Dh]
  char v263; // [esp+114h] [ebp-1Ch]
  char v264; // [esp+115h] [ebp-1Bh]
  char v265; // [esp+116h] [ebp-1Ah]
  int v266; // [esp+118h] [ebp-18h]
  char v267; // [esp+11Ch] [ebp-14h]
  char v268; // [esp+11Dh] [ebp-13h]
  char v269; // [esp+11Eh] [ebp-12h]
  char v270; // [esp+120h] [ebp-10h]
  char v271; // [esp+121h] [ebp-Fh]
  char v272; // [esp+122h] [ebp-Eh]
  char v273; // [esp+124h] [ebp-Ch]
  char v274; // [esp+125h] [ebp-Bh]
  char v275; // [esp+126h] [ebp-Ah]
  int v276; // [esp+128h] [ebp-8h]
  int v277; // [esp+12Ch] [ebp-4h]

  v5 = y1;
  v6 = x1;
  v7 = 99;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 2;
  v24 = 1;
  v25 = 1;
  v26 = 1;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v33 = 0;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  v38 = 0;
  v39 = 2;
  v40 = 1;
  v41 = 1;
  v42 = 1;
  v43 = 1;
  v44 = 1;
  v45 = 1;
  v46 = 0;
  v47 = 0;
  v48 = 0;
  v49 = 0;
  v50 = 0;
  v51 = 0;
  v52 = 0;
  v53 = 0;
  v54 = 0;
  v55 = 2;
  v56 = 1;
  v57 = 1;
  v58 = 1;
  v59 = 1;
  v60 = 1;
  v61 = 1;
  v62 = 1;
  v63 = 1;
  v64 = 0;
  v65 = 0;
  v66 = 0;
  v67 = 0;
  v68 = 0;
  v69 = 0;
  v70 = 0;
  v71 = 2;
  v72 = 2;
  v73 = 1;
  v74 = 1;
  v75 = 1;
  v76 = 1;
  v77 = 1;
  v78 = 1;
  v79 = 1;
  v80 = 1;
  v81 = 1;
  v82 = 1;
  v83 = 0;
  v84 = 0;
  v85 = 0;
  v86 = 0;
  v87 = 2;
  v88 = 2;
  v89 = 1;
  v90 = 1;
  v91 = 1;
  v92 = 1;
  v93 = 1;
  v94 = 1;
  v95 = 1;
  v96 = 1;
  v97 = 1;
  v98 = 1;
  v99 = 1;
  v100 = 1;
  v101 = 0;
  v102 = 0;
  v103 = 2;
  v104 = 2;
  v105 = 1;
  v106 = 1;
  v107 = 1;
  v108 = 1;
  v109 = 1;
  v110 = 1;
  v111 = 1;
  v112 = 1;
  v113 = 1;
  v114 = 1;
  v115 = 1;
  v116 = 1;
  v117 = 1;
  v118 = 1;
  v119 = 2;
  v120 = 2;
  v121 = 2;
  v122 = 1;
  v123 = 1;
  v124 = 1;
  v125 = 1;
  v126 = 1;
  v127 = 1;
  v128 = 1;
  v129 = 1;
  v130 = 1;
  v131 = 1;
  v132 = 1;
  v133 = 1;
  v134 = 1;
  v135 = 2;
  v136 = 2;
  v137 = 2;
  v138 = 1;
  v139 = 1;
  v140 = 1;
  v141 = 1;
  v142 = 1;
  v143 = 1;
  v144 = 1;
  v145 = 1;
  v146 = 1;
  v147 = 1;
  v148 = 1;
  v149 = 1;
  v150 = 1;
  v151 = 2;
  v152 = 2;
  v153 = 2;
  v154 = 2;
  v155 = 1;
  v156 = 1;
  v157 = 1;
  v158 = 1;
  v159 = 1;
  v160 = 1;
  v161 = 1;
  v162 = 1;
  v163 = 1;
  v164 = 1;
  v165 = 1;
  v166 = 1;
  v167 = 2;
  v168 = 2;
  v169 = 2;
  v170 = 2;
  v171 = 1;
  v172 = 1;
  v173 = 1;
  v174 = 1;
  v175 = 1;
  v176 = 1;
  v177 = 1;
  v178 = 1;
  v179 = 1;
  v180 = 1;
  v181 = 1;
  v182 = 1;
  v183 = 2;
  v184 = 2;
  v185 = 2;
  v186 = 2;
  v187 = 1;
  v188 = 1;
  v189 = 1;
  v190 = 1;
  v191 = 1;
  v192 = 1;
  v193 = 1;
  v194 = 1;
  v195 = 1;
  v196 = 1;
  v197 = 1;
  v198 = 1;
  v199 = 2;
  v200 = 2;
  v201 = 2;
  v202 = 2;
  v203 = 2;
  v204 = 1;
  v205 = 1;
  v206 = 1;
  v207 = 1;
  v208 = 1;
  v209 = 1;
  v210 = 1;
  v211 = 1;
  v212 = 1;
  v213 = 1;
  v214 = 1;
  v215 = 2;
  v216 = 2;
  v217 = 2;
  v218 = 2;
  v219 = 2;
  v220 = 1;
  v221 = 1;
  v222 = 1;
  v223 = 1;
  v224 = 1;
  v225 = 1;
  v226 = 1;
  v227 = 1;
  v228 = 1;
  v229 = 1;
  v230 = 1;
  v231 = 2;
  v232 = 2;
  v233 = 2;
  v234 = 2;
  v235 = 2;
  v236 = 2;
  v237 = 1;
  v238 = 1;
  v239 = 1;
  v240 = 1;
  v241 = 1;
  v242 = 1;
  v243 = 1;
  v244 = 1;
  v245 = 1;
  v246 = 1;
  v247 = 2;
  v248 = 2;
  v249 = 2;
  v250 = 2;
  v251 = 2;
  v252 = 2;
  v253 = 1;
  v254 = 1;
  v255 = 1;
  v256 = 1;
  v257 = 1;
  v258 = 1;
  v259 = 1;
  v260 = 1;
  v261 = 1;
  v262 = 1;
  v273 = 3;
  v274 = 4;
  v275 = 5;
  v270 = 3;
  v271 = 2;
  v272 = 1;
  v263 = 7;
  v264 = 6;
  v265 = 5;
  v267 = 7;
  v268 = 0;
  v269 = 1;
  v277 = abs(x2 - x1);
  if ( v277 > 15 )
    v277 = 15;
  v276 = abs(y2 - v5);
  if ( v276 > 15 )
    v276 = 15;
  v266 = (unsigned __int8)*(&v7 + 16 * v276 + v277);
  if ( x2 >= v6 )
  {
    if ( v5 <= y2 )
      v266 = (unsigned __int8)*(&v267 + v266);
    else
      v266 = (unsigned __int8)*(&v263 + v266);
  }
  else if ( v5 <= y2 )
  {
    v266 = (unsigned __int8)*(&v270 + v266);
  }
  else
  {
    v266 = (unsigned __int8)*(&v273 + v266);
  }
  return v266;
}

//----- (0043B7CF) --------------------------------------------------------
int __fastcall GetDirection16(int x1, int y1, int x2, int y2)
{
  int v5; // [esp+Ch] [ebp-134h]
  int v6; // [esp+10h] [ebp-130h]
  char v7; // [esp+14h] [ebp-12Ch]
  char v8; // [esp+15h] [ebp-12Bh]
  char v9; // [esp+16h] [ebp-12Ah]
  char v10; // [esp+17h] [ebp-129h]
  char v11; // [esp+18h] [ebp-128h]
  char v12; // [esp+19h] [ebp-127h]
  char v13; // [esp+1Ah] [ebp-126h]
  char v14; // [esp+1Bh] [ebp-125h]
  char v15; // [esp+1Ch] [ebp-124h]
  char v16; // [esp+1Dh] [ebp-123h]
  char v17; // [esp+1Eh] [ebp-122h]
  char v18; // [esp+1Fh] [ebp-121h]
  char v19; // [esp+20h] [ebp-120h]
  char v20; // [esp+21h] [ebp-11Fh]
  char v21; // [esp+22h] [ebp-11Eh]
  char v22; // [esp+23h] [ebp-11Dh]
  char v23; // [esp+24h] [ebp-11Ch]
  char v24; // [esp+25h] [ebp-11Bh]
  char v25; // [esp+26h] [ebp-11Ah]
  char v26; // [esp+27h] [ebp-119h]
  char v27; // [esp+28h] [ebp-118h]
  char v28; // [esp+29h] [ebp-117h]
  char v29; // [esp+2Ah] [ebp-116h]
  char v30; // [esp+2Bh] [ebp-115h]
  char v31; // [esp+2Ch] [ebp-114h]
  char v32; // [esp+2Dh] [ebp-113h]
  char v33; // [esp+2Eh] [ebp-112h]
  char v34; // [esp+2Fh] [ebp-111h]
  char v35; // [esp+30h] [ebp-110h]
  char v36; // [esp+31h] [ebp-10Fh]
  char v37; // [esp+32h] [ebp-10Eh]
  char v38; // [esp+33h] [ebp-10Dh]
  char v39; // [esp+34h] [ebp-10Ch]
  char v40; // [esp+35h] [ebp-10Bh]
  char v41; // [esp+36h] [ebp-10Ah]
  char v42; // [esp+37h] [ebp-109h]
  char v43; // [esp+38h] [ebp-108h]
  char v44; // [esp+39h] [ebp-107h]
  char v45; // [esp+3Ah] [ebp-106h]
  char v46; // [esp+3Bh] [ebp-105h]
  char v47; // [esp+3Ch] [ebp-104h]
  char v48; // [esp+3Dh] [ebp-103h]
  char v49; // [esp+3Eh] [ebp-102h]
  char v50; // [esp+3Fh] [ebp-101h]
  char v51; // [esp+40h] [ebp-100h]
  char v52; // [esp+41h] [ebp-FFh]
  char v53; // [esp+42h] [ebp-FEh]
  char v54; // [esp+43h] [ebp-FDh]
  char v55; // [esp+44h] [ebp-FCh]
  char v56; // [esp+45h] [ebp-FBh]
  char v57; // [esp+46h] [ebp-FAh]
  char v58; // [esp+47h] [ebp-F9h]
  char v59; // [esp+48h] [ebp-F8h]
  char v60; // [esp+49h] [ebp-F7h]
  char v61; // [esp+4Ah] [ebp-F6h]
  char v62; // [esp+4Bh] [ebp-F5h]
  char v63; // [esp+4Ch] [ebp-F4h]
  char v64; // [esp+4Dh] [ebp-F3h]
  char v65; // [esp+4Eh] [ebp-F2h]
  char v66; // [esp+4Fh] [ebp-F1h]
  char v67; // [esp+50h] [ebp-F0h]
  char v68; // [esp+51h] [ebp-EFh]
  char v69; // [esp+52h] [ebp-EEh]
  char v70; // [esp+53h] [ebp-EDh]
  char v71; // [esp+54h] [ebp-ECh]
  char v72; // [esp+55h] [ebp-EBh]
  char v73; // [esp+56h] [ebp-EAh]
  char v74; // [esp+57h] [ebp-E9h]
  char v75; // [esp+58h] [ebp-E8h]
  char v76; // [esp+59h] [ebp-E7h]
  char v77; // [esp+5Ah] [ebp-E6h]
  char v78; // [esp+5Bh] [ebp-E5h]
  char v79; // [esp+5Ch] [ebp-E4h]
  char v80; // [esp+5Dh] [ebp-E3h]
  char v81; // [esp+5Eh] [ebp-E2h]
  char v82; // [esp+5Fh] [ebp-E1h]
  char v83; // [esp+60h] [ebp-E0h]
  char v84; // [esp+61h] [ebp-DFh]
  char v85; // [esp+62h] [ebp-DEh]
  char v86; // [esp+63h] [ebp-DDh]
  char v87; // [esp+64h] [ebp-DCh]
  char v88; // [esp+65h] [ebp-DBh]
  char v89; // [esp+66h] [ebp-DAh]
  char v90; // [esp+67h] [ebp-D9h]
  char v91; // [esp+68h] [ebp-D8h]
  char v92; // [esp+69h] [ebp-D7h]
  char v93; // [esp+6Ah] [ebp-D6h]
  char v94; // [esp+6Bh] [ebp-D5h]
  char v95; // [esp+6Ch] [ebp-D4h]
  char v96; // [esp+6Dh] [ebp-D3h]
  char v97; // [esp+6Eh] [ebp-D2h]
  char v98; // [esp+6Fh] [ebp-D1h]
  char v99; // [esp+70h] [ebp-D0h]
  char v100; // [esp+71h] [ebp-CFh]
  char v101; // [esp+72h] [ebp-CEh]
  char v102; // [esp+73h] [ebp-CDh]
  char v103; // [esp+74h] [ebp-CCh]
  char v104; // [esp+75h] [ebp-CBh]
  char v105; // [esp+76h] [ebp-CAh]
  char v106; // [esp+77h] [ebp-C9h]
  char v107; // [esp+78h] [ebp-C8h]
  char v108; // [esp+79h] [ebp-C7h]
  char v109; // [esp+7Ah] [ebp-C6h]
  char v110; // [esp+7Bh] [ebp-C5h]
  char v111; // [esp+7Ch] [ebp-C4h]
  char v112; // [esp+7Dh] [ebp-C3h]
  char v113; // [esp+7Eh] [ebp-C2h]
  char v114; // [esp+7Fh] [ebp-C1h]
  char v115; // [esp+80h] [ebp-C0h]
  char v116; // [esp+81h] [ebp-BFh]
  char v117; // [esp+82h] [ebp-BEh]
  char v118; // [esp+83h] [ebp-BDh]
  char v119; // [esp+84h] [ebp-BCh]
  char v120; // [esp+85h] [ebp-BBh]
  char v121; // [esp+86h] [ebp-BAh]
  char v122; // [esp+87h] [ebp-B9h]
  char v123; // [esp+88h] [ebp-B8h]
  char v124; // [esp+89h] [ebp-B7h]
  char v125; // [esp+8Ah] [ebp-B6h]
  char v126; // [esp+8Bh] [ebp-B5h]
  char v127; // [esp+8Ch] [ebp-B4h]
  char v128; // [esp+8Dh] [ebp-B3h]
  char v129; // [esp+8Eh] [ebp-B2h]
  char v130; // [esp+8Fh] [ebp-B1h]
  char v131; // [esp+90h] [ebp-B0h]
  char v132; // [esp+91h] [ebp-AFh]
  char v133; // [esp+92h] [ebp-AEh]
  char v134; // [esp+93h] [ebp-ADh]
  char v135; // [esp+94h] [ebp-ACh]
  char v136; // [esp+95h] [ebp-ABh]
  char v137; // [esp+96h] [ebp-AAh]
  char v138; // [esp+97h] [ebp-A9h]
  char v139; // [esp+98h] [ebp-A8h]
  char v140; // [esp+99h] [ebp-A7h]
  char v141; // [esp+9Ah] [ebp-A6h]
  char v142; // [esp+9Bh] [ebp-A5h]
  char v143; // [esp+9Ch] [ebp-A4h]
  char v144; // [esp+9Dh] [ebp-A3h]
  char v145; // [esp+9Eh] [ebp-A2h]
  char v146; // [esp+9Fh] [ebp-A1h]
  char v147; // [esp+A0h] [ebp-A0h]
  char v148; // [esp+A1h] [ebp-9Fh]
  char v149; // [esp+A2h] [ebp-9Eh]
  char v150; // [esp+A3h] [ebp-9Dh]
  char v151; // [esp+A4h] [ebp-9Ch]
  char v152; // [esp+A5h] [ebp-9Bh]
  char v153; // [esp+A6h] [ebp-9Ah]
  char v154; // [esp+A7h] [ebp-99h]
  char v155; // [esp+A8h] [ebp-98h]
  char v156; // [esp+A9h] [ebp-97h]
  char v157; // [esp+AAh] [ebp-96h]
  char v158; // [esp+ABh] [ebp-95h]
  char v159; // [esp+ACh] [ebp-94h]
  char v160; // [esp+ADh] [ebp-93h]
  char v161; // [esp+AEh] [ebp-92h]
  char v162; // [esp+AFh] [ebp-91h]
  char v163; // [esp+B0h] [ebp-90h]
  char v164; // [esp+B1h] [ebp-8Fh]
  char v165; // [esp+B2h] [ebp-8Eh]
  char v166; // [esp+B3h] [ebp-8Dh]
  char v167; // [esp+B4h] [ebp-8Ch]
  char v168; // [esp+B5h] [ebp-8Bh]
  char v169; // [esp+B6h] [ebp-8Ah]
  char v170; // [esp+B7h] [ebp-89h]
  char v171; // [esp+B8h] [ebp-88h]
  char v172; // [esp+B9h] [ebp-87h]
  char v173; // [esp+BAh] [ebp-86h]
  char v174; // [esp+BBh] [ebp-85h]
  char v175; // [esp+BCh] [ebp-84h]
  char v176; // [esp+BDh] [ebp-83h]
  char v177; // [esp+BEh] [ebp-82h]
  char v178; // [esp+BFh] [ebp-81h]
  char v179; // [esp+C0h] [ebp-80h]
  char v180; // [esp+C1h] [ebp-7Fh]
  char v181; // [esp+C2h] [ebp-7Eh]
  char v182; // [esp+C3h] [ebp-7Dh]
  char v183; // [esp+C4h] [ebp-7Ch]
  char v184; // [esp+C5h] [ebp-7Bh]
  char v185; // [esp+C6h] [ebp-7Ah]
  char v186; // [esp+C7h] [ebp-79h]
  char v187; // [esp+C8h] [ebp-78h]
  char v188; // [esp+C9h] [ebp-77h]
  char v189; // [esp+CAh] [ebp-76h]
  char v190; // [esp+CBh] [ebp-75h]
  char v191; // [esp+CCh] [ebp-74h]
  char v192; // [esp+CDh] [ebp-73h]
  char v193; // [esp+CEh] [ebp-72h]
  char v194; // [esp+CFh] [ebp-71h]
  char v195; // [esp+D0h] [ebp-70h]
  char v196; // [esp+D1h] [ebp-6Fh]
  char v197; // [esp+D2h] [ebp-6Eh]
  char v198; // [esp+D3h] [ebp-6Dh]
  char v199; // [esp+D4h] [ebp-6Ch]
  char v200; // [esp+D5h] [ebp-6Bh]
  char v201; // [esp+D6h] [ebp-6Ah]
  char v202; // [esp+D7h] [ebp-69h]
  char v203; // [esp+D8h] [ebp-68h]
  char v204; // [esp+D9h] [ebp-67h]
  char v205; // [esp+DAh] [ebp-66h]
  char v206; // [esp+DBh] [ebp-65h]
  char v207; // [esp+DCh] [ebp-64h]
  char v208; // [esp+DDh] [ebp-63h]
  char v209; // [esp+DEh] [ebp-62h]
  char v210; // [esp+DFh] [ebp-61h]
  char v211; // [esp+E0h] [ebp-60h]
  char v212; // [esp+E1h] [ebp-5Fh]
  char v213; // [esp+E2h] [ebp-5Eh]
  char v214; // [esp+E3h] [ebp-5Dh]
  char v215; // [esp+E4h] [ebp-5Ch]
  char v216; // [esp+E5h] [ebp-5Bh]
  char v217; // [esp+E6h] [ebp-5Ah]
  char v218; // [esp+E7h] [ebp-59h]
  char v219; // [esp+E8h] [ebp-58h]
  char v220; // [esp+E9h] [ebp-57h]
  char v221; // [esp+EAh] [ebp-56h]
  char v222; // [esp+EBh] [ebp-55h]
  char v223; // [esp+ECh] [ebp-54h]
  char v224; // [esp+EDh] [ebp-53h]
  char v225; // [esp+EEh] [ebp-52h]
  char v226; // [esp+EFh] [ebp-51h]
  char v227; // [esp+F0h] [ebp-50h]
  char v228; // [esp+F1h] [ebp-4Fh]
  char v229; // [esp+F2h] [ebp-4Eh]
  char v230; // [esp+F3h] [ebp-4Dh]
  char v231; // [esp+F4h] [ebp-4Ch]
  char v232; // [esp+F5h] [ebp-4Bh]
  char v233; // [esp+F6h] [ebp-4Ah]
  char v234; // [esp+F7h] [ebp-49h]
  char v235; // [esp+F8h] [ebp-48h]
  char v236; // [esp+F9h] [ebp-47h]
  char v237; // [esp+FAh] [ebp-46h]
  char v238; // [esp+FBh] [ebp-45h]
  char v239; // [esp+FCh] [ebp-44h]
  char v240; // [esp+FDh] [ebp-43h]
  char v241; // [esp+FEh] [ebp-42h]
  char v242; // [esp+FFh] [ebp-41h]
  char v243; // [esp+100h] [ebp-40h]
  char v244; // [esp+101h] [ebp-3Fh]
  char v245; // [esp+102h] [ebp-3Eh]
  char v246; // [esp+103h] [ebp-3Dh]
  char v247; // [esp+104h] [ebp-3Ch]
  char v248; // [esp+105h] [ebp-3Bh]
  char v249; // [esp+106h] [ebp-3Ah]
  char v250; // [esp+107h] [ebp-39h]
  char v251; // [esp+108h] [ebp-38h]
  char v252; // [esp+109h] [ebp-37h]
  char v253; // [esp+10Ah] [ebp-36h]
  char v254; // [esp+10Bh] [ebp-35h]
  char v255; // [esp+10Ch] [ebp-34h]
  char v256; // [esp+10Dh] [ebp-33h]
  char v257; // [esp+10Eh] [ebp-32h]
  char v258; // [esp+10Fh] [ebp-31h]
  char v259; // [esp+110h] [ebp-30h]
  char v260; // [esp+111h] [ebp-2Fh]
  char v261; // [esp+112h] [ebp-2Eh]
  char v262; // [esp+113h] [ebp-2Dh]
  char v263; // [esp+114h] [ebp-2Ch]
  char v264; // [esp+115h] [ebp-2Bh]
  char v265; // [esp+116h] [ebp-2Ah]
  char v266; // [esp+117h] [ebp-29h]
  char v267; // [esp+118h] [ebp-28h]
  int v268; // [esp+11Ch] [ebp-24h]
  char v269; // [esp+120h] [ebp-20h]
  char v270; // [esp+121h] [ebp-1Fh]
  char v271; // [esp+122h] [ebp-1Eh]
  char v272; // [esp+123h] [ebp-1Dh]
  char v273; // [esp+124h] [ebp-1Ch]
  char v274; // [esp+128h] [ebp-18h]
  char v275; // [esp+129h] [ebp-17h]
  char v276; // [esp+12Ah] [ebp-16h]
  char v277; // [esp+12Bh] [ebp-15h]
  char v278; // [esp+12Ch] [ebp-14h]
  char v279; // [esp+130h] [ebp-10h]
  char v280; // [esp+131h] [ebp-Fh]
  char v281; // [esp+132h] [ebp-Eh]
  char v282; // [esp+133h] [ebp-Dh]
  char v283; // [esp+134h] [ebp-Ch]
  int v284; // [esp+138h] [ebp-8h]
  int v285; // [esp+13Ch] [ebp-4h]

  v5 = y1;
  v6 = x1;
  v7 = 99;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 4;
  v24 = 2;
  v25 = 1;
  v26 = 1;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v33 = 0;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  v38 = 0;
  v39 = 4;
  v40 = 3;
  v41 = 2;
  v42 = 1;
  v43 = 1;
  v44 = 1;
  v45 = 1;
  v46 = 1;
  v47 = 0;
  v48 = 0;
  v49 = 0;
  v50 = 0;
  v51 = 0;
  v52 = 0;
  v53 = 0;
  v54 = 0;
  v55 = 4;
  v56 = 3;
  v57 = 3;
  v58 = 2;
  v59 = 2;
  v60 = 1;
  v61 = 1;
  v62 = 1;
  v63 = 1;
  v64 = 1;
  v65 = 1;
  v66 = 1;
  v67 = 0;
  v68 = 0;
  v69 = 0;
  v70 = 0;
  v71 = 4;
  v72 = 4;
  v73 = 3;
  v74 = 2;
  v75 = 2;
  v76 = 1;
  v77 = 1;
  v78 = 1;
  v79 = 1;
  v80 = 1;
  v81 = 1;
  v82 = 1;
  v83 = 1;
  v84 = 1;
  v85 = 1;
  v86 = 1;
  v87 = 4;
  v88 = 4;
  v89 = 3;
  v90 = 3;
  v91 = 2;
  v92 = 2;
  v93 = 2;
  v94 = 1;
  v95 = 1;
  v96 = 1;
  v97 = 1;
  v98 = 1;
  v99 = 1;
  v100 = 1;
  v101 = 1;
  v102 = 1;
  v103 = 4;
  v104 = 4;
  v105 = 3;
  v106 = 3;
  v107 = 2;
  v108 = 2;
  v109 = 2;
  v110 = 2;
  v111 = 2;
  v112 = 1;
  v113 = 1;
  v114 = 1;
  v115 = 1;
  v116 = 1;
  v117 = 1;
  v118 = 1;
  v119 = 4;
  v120 = 4;
  v121 = 3;
  v122 = 3;
  v123 = 3;
  v124 = 3;
  v125 = 2;
  v126 = 2;
  v127 = 2;
  v128 = 2;
  v129 = 1;
  v130 = 1;
  v131 = 1;
  v132 = 1;
  v133 = 1;
  v134 = 1;
  v135 = 4;
  v136 = 4;
  v137 = 4;
  v138 = 3;
  v139 = 3;
  v140 = 3;
  v141 = 2;
  v142 = 2;
  v143 = 2;
  v144 = 2;
  v145 = 2;
  v146 = 1;
  v147 = 1;
  v148 = 1;
  v149 = 1;
  v150 = 1;
  v151 = 4;
  v152 = 4;
  v153 = 4;
  v154 = 3;
  v155 = 3;
  v156 = 3;
  v157 = 3;
  v158 = 2;
  v159 = 2;
  v160 = 2;
  v161 = 2;
  v162 = 2;
  v163 = 1;
  v164 = 1;
  v165 = 1;
  v166 = 1;
  v167 = 4;
  v168 = 4;
  v169 = 4;
  v170 = 3;
  v171 = 3;
  v172 = 3;
  v173 = 3;
  v174 = 3;
  v175 = 2;
  v176 = 2;
  v177 = 2;
  v178 = 2;
  v179 = 2;
  v180 = 2;
  v181 = 1;
  v182 = 1;
  v183 = 4;
  v184 = 4;
  v185 = 4;
  v186 = 3;
  v187 = 3;
  v188 = 3;
  v189 = 3;
  v190 = 3;
  v191 = 3;
  v192 = 2;
  v193 = 2;
  v194 = 2;
  v195 = 2;
  v196 = 2;
  v197 = 2;
  v198 = 1;
  v199 = 4;
  v200 = 4;
  v201 = 4;
  v202 = 4;
  v203 = 3;
  v204 = 3;
  v205 = 3;
  v206 = 3;
  v207 = 3;
  v208 = 3;
  v209 = 2;
  v210 = 2;
  v211 = 2;
  v212 = 2;
  v213 = 2;
  v214 = 2;
  v215 = 4;
  v216 = 4;
  v217 = 4;
  v218 = 4;
  v219 = 3;
  v220 = 3;
  v221 = 3;
  v222 = 3;
  v223 = 3;
  v224 = 3;
  v225 = 2;
  v226 = 2;
  v227 = 2;
  v228 = 2;
  v229 = 2;
  v230 = 2;
  v231 = 4;
  v232 = 4;
  v233 = 4;
  v234 = 4;
  v235 = 3;
  v236 = 3;
  v237 = 3;
  v238 = 3;
  v239 = 3;
  v240 = 3;
  v241 = 3;
  v242 = 2;
  v243 = 2;
  v244 = 2;
  v245 = 2;
  v246 = 2;
  v247 = 4;
  v248 = 4;
  v249 = 4;
  v250 = 4;
  v251 = 3;
  v252 = 3;
  v253 = 3;
  v254 = 3;
  v255 = 3;
  v256 = 3;
  v257 = 3;
  v258 = 3;
  v259 = 2;
  v260 = 2;
  v261 = 2;
  v262 = 2;
  v279 = 6;
  v280 = 7;
  v281 = 8;
  v282 = 9;
  v283 = 10;
  v274 = 6;
  v275 = 5;
  v276 = 4;
  v277 = 3;
  v278 = 2;
  v263 = 14;
  v264 = 13;
  v265 = 12;
  v266 = 11;
  v267 = 10;
  v269 = 14;
  v270 = 15;
  v271 = 0;
  v272 = 1;
  v273 = 2;
  v285 = abs(x2 - x1);
  if ( v285 > 15 )
    v285 = 15;
  v284 = abs(y2 - v5);
  if ( v284 > 15 )
    v284 = 15;
  v268 = (unsigned __int8)*(&v7 + 16 * v284 + v285);
  if ( x2 >= v6 )
  {
    if ( y2 >= v5 )
      v268 = (unsigned __int8)*(&v269 + v268);
    else
      v268 = (unsigned __int8)*(&v263 + v268);
  }
  else if ( y2 >= v5 )
  {
    v268 = (unsigned __int8)*(&v274 + v268);
  }
  else
  {
    v268 = (unsigned __int8)*(&v279 + v268);
  }
  return v268;
}

//----- (0043BF17) --------------------------------------------------------
void __fastcall DeleteMissile(int mi, int i)
{
  missilevail[125 - nummissiles--] = mi;
  if ( nummissiles > 0 && i != nummissiles )
    missileactive[i] = missileactive[nummissiles];
}

//----- (0043BF7C) --------------------------------------------------------
void __fastcall GetMissileVel(int i, int sx, int sy, int dx, int dy, int v)
{
  int v6; // ST28_4
  double v7; // ST34_8
  double v8; // st7
  double v9; // ST2C_8
  double v10; // st7

  v6 = i;
  v7 = (double)((32 * (dx - sx) - 32 * (dy - sy)) << 16);
  v8 = (double)((32 * (dx - sx) + 32 * (dy - sy)) << 16);
  v9 = v8;
  v10 = v8 * v8 + v7 * v7;
  sub_4A7F40(v10);
  missile[v6]._mixvel = (signed __int64)((double)(v << 16) * v7 / v10);
  missile[v6]._miyvel = (signed __int64)((double)(v << 15) * v9 / v10);
}

//----- (0043C04B) --------------------------------------------------------
void __fastcall PutMissile(int i)
{
  int v1; // [esp+10h] [ebp-8h]
  int v2; // [esp+14h] [ebp-4h]

  if ( !missile[i]._miDelFlag )
  {
    v2 = missile[i]._mix;
    v1 = missile[i]._miy;
    dFlags[v2][v1] |= 1u;
    if ( dMissile[v2][v1] )
      dMissile[v2][v1] = -1;
    else
      dMissile[v2][v1] = i + 1;
    if ( missile[i]._miPreFlag )
      MissilePreFlag = 1;
  }
}

//----- (0043C1CF) --------------------------------------------------------
void __fastcall GetMissilePos(int i)
{
  int v1; // [esp+10h] [ebp-18h]
  int v2; // [esp+10h] [ebp-18h]
  int v3; // [esp+14h] [ebp-14h]
  int v4; // [esp+18h] [ebp-10h]
  int v5; // [esp+18h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-Ch]
  int v7; // [esp+20h] [ebp-8h]
  int v8; // [esp+24h] [ebp-4h]

  v8 = missile[i]._mitxoff >> 16;
  v7 = missile[i]._mityoff >> 16;
  v4 = v8 + 2 * v7;
  v1 = 2 * v7 - v8;
  if ( v4 >= 0 )
  {
    v6 = v4 >> 3;
    v5 = v4 >> 6;
  }
  else
  {
    v6 = -(-v4 >> 3);
    v5 = -(-v4 >> 6);
  }
  if ( v1 >= 0 )
  {
    v3 = v1 >> 3;
    v2 = v1 >> 6;
  }
  else
  {
    v3 = -((v8 - 2 * v7) >> 3);
    v2 = -((v8 - 2 * v7) >> 6);
  }
  missile[i]._mix = v5 + missile[i]._misx;
  missile[i]._miy = v2 + missile[i]._misy;
  missile[i]._mixoff = v8 - 32 * (v5 - v2);
  missile[i]._miyoff = v7 - 16 * (v5 + v2);
  ChangeLightOff(missile[i]._mlid, v6 - 8 * v5, v3 - 8 * v2);
}

//----- (0043C370) --------------------------------------------------------
void __fastcall MoveMissilePos(int i)
{
  int v1; // [esp+10h] [ebp-14h]
  signed int v2; // [esp+14h] [ebp-10h]
  signed int v3; // [esp+18h] [ebp-Ch]

  v1 = i;
  switch ( missile[i]._mimfnum )
  {
    case 0:
      v3 = 1;
      v2 = 1;
      break;
    case 1:
      v3 = 1;
      v2 = 1;
      break;
    case 2:
      v3 = 0;
      v2 = 1;
      break;
    case 3:
      v3 = 0;
      v2 = 0;
      break;
    case 4:
      v3 = 0;
      v2 = 0;
      break;
    case 5:
      v3 = 0;
      v2 = 0;
      break;
    case 6:
      v3 = 1;
      v2 = 0;
      break;
    case 7:
      v3 = 1;
      v2 = 1;
      break;
    default:
      break;
  }
  if ( PosOkMonst(missile[i]._misource, v3 + missile[i]._mix, v2 + missile[i]._miy) )
  {
    missile[v1]._mix += v3;
    missile[v1]._miy += v2;
    missile[v1]._mixoff -= 32 * (v3 - v2);
    missile[v1]._miyoff -= 16 * (v3 + v2);
  }
}

//----- (0043C54B) --------------------------------------------------------
BOOL __fastcall MonsterTrapHit(int m, int mindam, int maxdam, int dist, int t, int shift)
{
  BOOL result; // eax
  int dam; // [esp+14h] [ebp-18h]
  char v10; // [esp+18h] [ebp-14h]
  int v11; // [esp+1Ch] [ebp-10h]
  signed int v12; // [esp+20h] [ebp-Ch]
  int v13; // [esp+24h] [ebp-8h]
  int v14; // [esp+28h] [ebp-4h]

  v12 = 0;
  if ( monster[m].mtalkmsg )
    return 0;
  if ( (signed int)(monster[m]._mhitpoints & 0xFFFFFFC0) <= 0 )
    return 0;
  if ( monster[m].MType->mtype == 32 && monster[m]._mgoal == 2 )
    return 0;
  v14 = missiledata[t].mResist;
  v10 = monster[m].mMagicRes;
  if ( v10 & 8 && v14 == 3 || v10 & 0x10 && v14 == 1 || v10 & 0x20 && v14 == 2 )
    return 0;
  if ( v10 & 1 && v14 == 3 || v10 & 2 && v14 == 1 || v10 & 4 && v14 == 2 )
    v12 = 1;
  v13 = random(68, 100);
  v11 = 90 - monster[m].mArmorClass - dist;
  if ( v11 < 5 )
    v11 = 5;
  if ( v11 > 95 )
    v11 = 95;
  if ( monster[m]._mFlags & 4 )
  {
    monster[m]._mFlags &= 0xFFFFFFFB;
    monster[m]._mmode = MM_SATTACK;
    result = 1;
  }
  else if ( v11 <= v13 && monster[m]._mmode != MM_STONE )
  {
    result = 0;
  }
  else
  {
    dam = random(68, maxdam - mindam + 1) + mindam;
    if ( !(_BYTE)shift )
      dam <<= 6;
    if ( v12 )
      monster[m]._mhitpoints -= dam >> 2;
    else
      monster[m]._mhitpoints -= dam;
    if ( monster[m]._mmode == MM_STONE )
      monster[m]._mhitpoints = 0;
    if ( (signed int)(monster[m]._mhitpoints & 0xFFFFFFC0) > 0 )
    {
      if ( v12 )
      {
        PlayEffect(m, 1);
      }
      else
      {
        M_StartHit(m, -1, dam);
        missiles_43AFC2(monster[m]._mx, monster[m]._my, 17, dam >> 6, monster[m]._mmaxhp >> 6);
      }
    }
    else if ( monster[m]._mmode == MM_STONE )
    {
      M_StartKill(m, -1);
      monster[m]._mmode = MM_STONE;
    }
    else
    {
      M_StartKill(m, -1);
    }
    result = 1;
  }
  return result;
}

//----- (0043C93B) --------------------------------------------------------
BOOL __fastcall MonsterMHit(int pnum, int m, int mindam, int maxdam, int dist, int t, BYTE shift)
{
  BOOL result; // eax
  int dam; // [esp+14h] [ebp-18h]
  char v11; // [esp+18h] [ebp-14h]
  int v12; // [esp+1Ch] [ebp-10h]
  signed int v13; // [esp+20h] [ebp-Ch]
  int v14; // [esp+24h] [ebp-8h]
  int v15; // [esp+28h] [ebp-4h]

  v13 = 0;
  if ( monster[m].mtalkmsg )
    return 0;
  if ( (signed int)(monster[m]._mhitpoints & 0xFFFFFFC0) <= 0 )
    return 0;
  if ( t == 53 && monster[m].MData->mMonstClass )
    return 0;
  if ( monster[m].MType->mtype == 32 && monster[m]._mgoal == 2 )
    return 0;
  v15 = missiledata[t].mResist;
  v11 = monster[m].mMagicRes;
  if ( v11 & 8 && v15 == 3 || v11 & 0x10 && v15 == 1 || v11 & 0x20 && v15 == 2 || v11 < 0 && v15 == 4 )
    return 0;
  if ( v11 & 1 && v15 == 3 || v11 & 2 && v15 == 1 || v11 & 4 && v15 == 2 )
    v13 = 1;
  v14 = random(69, 100);
  if ( missiledata[t].mType )
  {
    v12 = plr[pnum]._pMagic + 50 - 2 * monster[m].mLevel - dist;
    if ( plr[pnum]._pClass == 2 )
      v12 += 20;
  }
  else
  {
    v12 = plr[pnum]._pIBonusToHit
        + (plr[pnum]._pDexterity >> 1)
        + plr[pnum]._pLevel
        + 50
        - monster[m].mArmorClass
        - plr[pnum]._pIEnAc
        - (dist * dist >> 1);
    if ( plr[pnum]._pClass == 1 )
      v12 += 20;
  }
  if ( v12 < 5 )
    v12 = 5;
  if ( v12 > 95 )
    v12 = 95;
  if ( monster[m]._mmode == MM_STONE )
    v14 = 0;
  if ( monster[m]._mFlags & 4 )
  {
    monster[m]._mFlags &= 0xFFFFFFFB;
    monster[m]._mmode = MM_SATTACK;
    result = 1;
  }
  else if ( v12 <= v14 )
  {
    result = 0;
  }
  else
  {
    dam = random(70, maxdam - mindam + 1) + mindam;
    if ( !missiledata[t].mType )
      dam += plr[pnum]._pDamageMod + plr[pnum]._pIBonusDamMod + dam * plr[pnum]._pIBonusDam / 100;
    if ( !shift )
      dam <<= 6;
    if ( v13 )
      dam >>= 2;
    if ( pnum == myplr )
      monster[m]._mhitpoints -= dam;
    if ( plr[pnum]._pIFlags & 8 )
      monster[m]._mFlags |= 8u;
    if ( pnum == myplr && monster[m]._mmode == MM_STONE )
      monster[m]._mhitpoints = 0;
    if ( (signed int)(monster[m]._mhitpoints & 0xFFFFFFC0) > 0 )
    {
      if ( v13 )
      {
        PlayEffect(m, 1);
      }
      else
      {
        M_StartHit(m, pnum, dam);
        missiles_43AFC2(monster[m]._mx, monster[m]._my, 17, dam >> 6, monster[m]._mmaxhp >> 6);
      }
    }
    else if ( monster[m]._mmode == MM_STONE )
    {
      M_StartKill(m, pnum);
      monster[m]._mmode = MM_STONE;
    }
    else
    {
      M_StartKill(m, pnum);
    }
    if ( !monster[m]._msquelch )
    {
      monster[m]._msquelch = -1;
      monster[m]._lastx = plr[pnum].WorldX;
      monster[m]._lasty = plr[pnum].WorldY;
    }
    result = 1;
  }
  return result;
}

//----- (0043CFFA) --------------------------------------------------------
BOOL __fastcall PlayerMHit(int pnum, int m, int dist, int mind, int maxd, int mtype, BYTE shift)
{
  BOOL result; // eax
  int v8; // eax
  int v9; // eax
  int dir; // ST24_4
  int v11; // [esp+Ch] [ebp-2Ch]
  int v14; // [esp+18h] [ebp-20h]
  int v; // [esp+20h] [ebp-18h]
  int va; // [esp+20h] [ebp-18h]
  int vb; // [esp+20h] [ebp-18h]
  int vc; // [esp+20h] [ebp-18h]
  signed int v19; // [esp+24h] [ebp-14h]
  int v20; // [esp+28h] [ebp-10h]
  int v21; // [esp+2Ch] [ebp-Ch]
  int v22; // [esp+30h] [ebp-8h]
  int v23; // [esp+34h] [ebp-4h]

  if ( (signed int)(plr[pnum]._pHitPoints & 0xFFFFFFC0) <= 0 )
    return 0;
  if ( plr[pnum]._pInvincible )
    return 0;
  v23 = random(72, 100);
  v21 = plr[pnum]._pIAC + plr[pnum]._pIBonusAC + plr[pnum]._pArmorClass;
  if ( m == -1 )
    v8 = 100 - (v21 >> 1);
  else
    v8 = monster[m].mHit + 30 + 2 * (monster[m].mLevel - plr[pnum]._pLevel) - v21;
  v20 = v8 - 2 * dist;
  if ( v20 < 10 )
    v20 = 10;
  if ( plr[pnum]._pmode && plr[pnum]._pmode != 4 || !plr[pnum]._pBlockFlag )
    v22 = 100;
  else
    v22 = random(73, 100);
  if ( m == -1 )
    v9 = plr[pnum]._pBaseToBlk + plr[pnum]._pDexterity;
  else
    v9 = plr[pnum]._pBaseToBlk + plr[pnum]._pDexterity - 2 * (monster[m].mLevel - plr[pnum]._pLevel);
  v19 = v9;
  if ( v9 < 0 )
    v19 = 0;
  if ( v19 > 100 )
    v19 = 100;
  v11 = missiledata[mtype].mResist;
  switch ( v11 )
  {
    case 1:
      v14 = plr[pnum]._pFireResist;
      break;
    case 2:
      v14 = plr[pnum]._pLghtResist;
      break;
    case 3:
      v14 = plr[pnum]._pMagResist;
      break;
    default:
      v14 = 0;
      break;
  }
  if ( v20 <= v23 )
    return 0;
  if ( shift )
  {
    vb = random(75, maxd - mind + 1) + mind;
    if ( plr[pnum]._pIFlags & 0x10000000 )
      vb >>= 1;
    va = plr[pnum]._pIGetHit + vb;
    if ( va < 0 )
      va = 0;
  }
  else
  {
    v = (mind << 6) + random(75, (maxd - mind + 1) << 6);
    if ( plr[pnum]._pIFlags & 0x10000000 )
      v >>= 1;
    va = (plr[pnum]._pIGetHit << 6) + v;
    if ( va < 0 )
      va = 0;
  }
  if ( v14 <= 0 )
  {
    if ( v19 <= v22 )
    {
      if ( pnum == myplr )
      {
        plr[pnum]._pHitPoints -= va;
        plr[pnum]._pHPBase -= va;
      }
      if ( plr[pnum]._pHitPoints > plr[pnum]._pMaxHP )
      {
        plr[pnum]._pHitPoints = plr[pnum]._pMaxHP;
        plr[pnum]._pHPBase = plr[pnum]._pMaxHPBase;
      }
      if ( (signed int)(plr[pnum]._pHitPoints & 0xFFFFFFC0) > 0 )
      {
        StartPlrHit(pnum, va);
      }
      else
      {
        plr[pnum]._pHitPoints = 0;
        SyncPlrKill(pnum);
      }
      result = 1;
    }
    else
    {
      if ( m == -1 )
      {
        StartPlrBlock(pnum, plr[pnum]._pdir);
      }
      else
      {
        dir = GetDirection(plr[pnum].WorldX, plr[pnum].WorldY, monster[m]._mx, monster[m]._my);
        StartPlrBlock(pnum, dir);
      }
      result = 1;
    }
  }
  else
  {
    vc = va - va * v14 / 100;
    if ( pnum == myplr )
    {
      plr[pnum]._pHitPoints -= vc;
      plr[pnum]._pHPBase -= vc;
    }
    if ( plr[pnum]._pHitPoints > plr[pnum]._pMaxHP )
    {
      plr[pnum]._pHitPoints = plr[pnum]._pMaxHP;
      plr[pnum]._pHPBase = plr[pnum]._pMaxHPBase;
    }
    if ( (signed int)(plr[pnum]._pHitPoints & 0xFFFFFFC0) > 0 )
    {
      PlaySfxLoc(48, plr[pnum].WorldX, plr[pnum].WorldY);
      drawmanaflag = 1;
    }
    else
    {
      plr[pnum]._pHitPoints = 0;
      SyncPlrKill(pnum);
    }
    result = 1;
  }
  return result;
}

//----- (0043D8E1) --------------------------------------------------------
BOOL __fastcall Plr2PlrMHit(int pnum, int p, int mindam, int maxdam, int dist, int mtype, BYTE shift)
{
  BOOL result; // eax
  int dir; // ST24_4
  int v9; // [esp+Ch] [ebp-2Ch]
  int v12; // [esp+18h] [ebp-20h]
  int dwDam; // [esp+20h] [ebp-18h]
  unsigned int dwDama; // [esp+20h] [ebp-18h]
  int v15; // [esp+24h] [ebp-14h]
  int v16; // [esp+28h] [ebp-10h]
  int v17; // [esp+30h] [ebp-8h]
  int v18; // [esp+34h] [ebp-4h]

  if ( plr[p]._pInvincible )
    return 0;
  if ( mtype == 53 )
    return 0;
  v9 = missiledata[mtype].mResist;
  switch ( v9 )
  {
    case 1:
      v12 = plr[p]._pFireResist;
      break;
    case 2:
      v12 = plr[p]._pLghtResist;
      break;
    case 3:
      v12 = plr[p]._pMagResist;
      break;
    default:
      v12 = 0;
      break;
  }
  v18 = random(69, 100);
  if ( missiledata[mtype].mType )
  {
    v16 = plr[pnum]._pMagic + 50 - 2 * plr[p]._pLevel - dist;
    if ( plr[pnum]._pClass == 2 )
      v16 += 20;
  }
  else
  {
    v16 = plr[pnum]._pIBonusToHit
        + (plr[pnum]._pDexterity >> 1)
        + plr[pnum]._pLevel
        + 50
        - (plr[p]._pIAC
         + plr[p]._pIBonusAC
         + plr[p]._pArmorClass)
        - (dist * dist >> 1);
    if ( plr[pnum]._pClass == 1 )
      v16 += 20;
  }
  if ( v16 < 5 )
    v16 = 5;
  if ( v16 > 95 )
    v16 = 95;
  if ( v16 <= v18 )
    return 0;
  if ( plr[p]._pmode && plr[p]._pmode != 4 || !plr[p]._pBlockFlag )
    v17 = 100;
  else
    v17 = random(73, 100);
  v15 = plr[p]._pDexterity + plr[p]._pBaseToBlk - 2 * (plr[pnum]._pLevel - plr[p]._pLevel);
  if ( v15 < 0 )
    v15 = 0;
  if ( v15 > 100 )
    v15 = 100;
  dwDam = random(70, maxdam - mindam + 1) + mindam;
  if ( !missiledata[mtype].mType )
    dwDam += plr[pnum]._pDamageMod + plr[pnum]._pIBonusDamMod + dwDam * plr[pnum]._pIBonusDam / 100;
  if ( !shift )
    dwDam <<= 6;
  if ( v12 <= 0 )
  {
    if ( v17 >= v15 )
    {
      if ( myplr == pnum )
        NetSendCmdDamage(1u, p, dwDam);
      StartPlrHit(p, dwDam);
      result = 1;
    }
    else
    {
      dir = GetDirection(plr[p].WorldX, plr[p].WorldY, plr[pnum].WorldX, plr[pnum].WorldY);
      StartPlrBlock(p, dir);
      result = 1;
    }
  }
  else
  {
    dwDama = dwDam - v12 * dwDam / 100;
    if ( myplr == pnum )
      NetSendCmdDamage(1u, p, dwDama);
    PlaySfxLoc(48, plr[p].WorldX, plr[p].WorldY);
    result = 1;
  }
  return result;
}

//----- (0043DF1C) --------------------------------------------------------
void __fastcall CheckMissileCol(int i, int mindam, int maxdam, bool shift, int mx, int my, BYTE nodel)
{
  int oi; // [esp+14h] [ebp-8h]

  if ( missile[i]._miAnimType != 4 && missile[i]._misource != -1 )
  {
    if ( missile[i]._micaster )
    {
      if ( monster[missile[i]._misource]._mFlags & 0x10
        && dMonster[mx][my] > 0
        && monster[dMonster[mx][my] - 1]._mFlags & 0x20
        && MonsterTrapHit(dMonster[mx][my] - 1, mindam, maxdam, missile[i]._midist, missile[i]._mitype, shift) )
      {
        if ( !nodel )
          missile[i]._mirange = 0;
        missile[i]._miHitFlag = 1;
      }
      if ( dPlayer[mx][my] > 0
        && PlayerMHit(
             dPlayer[mx][my] - 1,
             missile[i]._misource,
             missile[i]._midist,
             mindam,
             maxdam,
             missile[i]._mitype,
             shift) )
      {
        if ( !nodel )
          missile[i]._mirange = 0;
        missile[i]._miHitFlag = 1;
      }
    }
    else
    {
      if ( dMonster[mx][my] <= 0 )
      {
        if ( dMonster[mx][my] < 0
          && monster[-(dMonster[mx][my] + 1)]._mmode == 15
          && MonsterMHit(
               missile[i]._misource,
               -(dMonster[mx][my] + 1),
               mindam,
               maxdam,
               missile[i]._midist,
               missile[i]._mitype,
               shift) )
        {
          if ( !nodel )
            missile[i]._mirange = 0;
          missile[i]._miHitFlag = 1;
        }
      }
      else if ( MonsterMHit(
                  missile[i]._misource,
                  dMonster[mx][my] - 1,
                  mindam,
                  maxdam,
                  missile[i]._midist,
                  missile[i]._mitype,
                  shift) )
      {
        if ( !nodel )
          missile[i]._mirange = 0;
        missile[i]._miHitFlag = 1;
      }
      if ( dPlayer[mx][my] > 0
        && dPlayer[mx][my] - 1 != missile[i]._misource
        && Plr2PlrMHit(
             missile[i]._misource,
             dPlayer[mx][my] - 1,
             mindam,
             maxdam,
             missile[i]._midist,
             missile[i]._mitype,
             shift) )
      {
        if ( !nodel )
          missile[i]._mirange = 0;
        missile[i]._miHitFlag = 1;
      }
    }
  }
  else
  {
    if ( dMonster[mx][my] > 0 )
    {
      if ( missile[i]._miAnimType == 4 )
      {
        if ( MonsterMHit(
               missile[i]._misource,
               dMonster[mx][my] - 1,
               mindam,
               maxdam,
               missile[i]._midist,
               missile[i]._mitype,
               shift) )
        {
          if ( !nodel )
            missile[i]._mirange = 0;
          missile[i]._miHitFlag = 1;
        }
      }
      else if ( MonsterTrapHit(dMonster[mx][my] - 1, mindam, maxdam, missile[i]._midist, missile[i]._mitype, shift) )
      {
        if ( !nodel )
          missile[i]._mirange = 0;
        missile[i]._miHitFlag = 1;
      }
    }
    if ( dPlayer[mx][my] > 0
      && PlayerMHit(dPlayer[mx][my] - 1, -1, missile[i]._midist, mindam, maxdam, missile[i]._mitype, shift) )
    {
      if ( !nodel )
        missile[i]._mirange = 0;
      missile[i]._miHitFlag = 1;
    }
  }
  if ( dObject[mx][my] )
  {
    oi = dObject[mx][my] <= 0 ? -(dObject[mx][my] + 1) : dObject[mx][my] - 1;
    if ( !object[oi]._oMissFlag )
    {
      if ( object[oi]._oBreak == 1 )
        BreakObject(-1, oi);
      if ( !nodel )
        missile[i]._mirange = 0;
      missile[i]._miHitFlag = 0;
    }
  }
  if ( nMissileTable[dPiece[mx][my]] )
  {
    if ( !nodel )
      missile[i]._mirange = 0;
    missile[i]._miHitFlag = 0;
  }
  if ( !missile[i]._mirange && missiledata[missile[i]._mitype].miSFX != -1 )
    PlaySfxLoc(missiledata[missile[i]._mitype].miSFX, missile[i]._mix, missile[i]._miy);
}

//----- (0043E8BA) --------------------------------------------------------
void __fastcall SetMissAnim(int mi, int animtype)
{
  int v2; // ST14_4

  v2 = missile[mi]._mimfnum;
  missile[mi]._miAnimType = animtype;
  missile[mi]._miAnimFlags = misfiledata[animtype].mFlags;
  missile[mi]._miAnimData = misfiledata[animtype].mAnimData[v2];
  missile[mi]._miAnimDelay = misfiledata[animtype].mAnimDelay[v2];
  missile[mi]._miAnimLen = misfiledata[animtype].mAnimLen[v2];
  missile[mi]._miAnimWidth = misfiledata[animtype].mAnimWidth[v2];
  missile[mi]._miAnimWidth2 = misfiledata[animtype].mAnimWidth2[v2];
  missile[mi]._miAnimCnt = 0;
  missile[mi]._miAnimFrame = 1;
}

//----- (0043EA59) --------------------------------------------------------
void __fastcall SetMissDir(int mi, int dir)
{
  missile[mi]._mimfnum = dir;
  SetMissAnim(mi, missile[mi]._miAnimType);
}

//----- (0043EAA9) --------------------------------------------------------
void __fastcall LoadMissileGFX(BYTE mi)
{
  unsigned __int8 *v1; // eax
  char pszName[256]; // [esp+10h] [ebp-108h]
  int i; // [esp+110h] [ebp-8h]
  unsigned __int8 *v5; // [esp+114h] [ebp-4h]

  if ( misfiledata[mi].mFlags & 4 )
  {
    sprintf(pszName, "Missiles\\%s.CEL", misfiledata[mi].mName);
    v5 = LoadFileInMem(pszName, 0, 866, "MISSILES.CPP");
    for ( i = 0; misfiledata[mi].mAnimFAmt > i; ++i )
      misfiledata[mi].mAnimData[i] = &v5[*(_DWORD *)&v5[4 * i]];
  }
  else if ( misfiledata[mi].mAnimFAmt == 1 )
  {
    sprintf(pszName, "Missiles\\%s.CEL", misfiledata[mi].mName);
    if ( !misfiledata[mi].mAnimData[0] )
      misfiledata[mi].mAnimData[0] = LoadFileInMem(pszName, 0, 874, "MISSILES.CPP");
  }
  else
  {
    for ( i = 0; misfiledata[mi].mAnimFAmt > i; ++i )
    {
      sprintf(pszName, "Missiles\\%s%i.CEL", misfiledata[mi].mName, i + 1);
      if ( !misfiledata[mi].mAnimData[i] )
      {
        v1 = LoadFileInMem(pszName, 0, 879, "MISSILES.CPP");
        misfiledata[mi].mAnimData[i] = v1;
      }
    }
  }
}

//----- (0043ED27) --------------------------------------------------------
void __cdecl InitMissileGFX()
{
  int mi; // [esp+Ch] [ebp-4h]

  for ( mi = 0; misfiledata[mi].mAnimFAmt; ++mi )
  {
    if ( !(misfiledata[mi].mFlags & 1) )
      LoadMissileGFX(mi);
  }
}

//----- (0043ED95) --------------------------------------------------------
void __fastcall FreeMissileGFX(int mi)
{
  signed int i; // [esp+10h] [ebp-4h]

  if ( misfiledata[mi].mFlags & 4 )
  {
    if ( misfiledata[mi].mAnimData[0] )
    {
      mem_free_dbg(
        &misfiledata[mi].mAnimData[0][-4 * misfiledata[mi].mAnimFAmt],
        907,
        "MISSILES.CPP");
      misfiledata[mi].mAnimData[0] = 0;
    }
  }
  else
  {
    for ( i = 0; misfiledata[mi].mAnimFAmt > i; ++i )
    {
      if ( misfiledata[mi].mAnimData[i] )
      {
        mem_free_dbg(misfiledata[mi].mAnimData[i], 916, "MISSILES.CPP");
        misfiledata[mi].mAnimData[i] = 0;
      }
    }
  }
}

//----- (0043EEF8) --------------------------------------------------------
void __cdecl FreeMissiles()
{
  int mi; // [esp+Ch] [ebp-4h]

  for ( mi = 0; misfiledata[mi].mAnimFAmt; ++mi )
  {
    if ( !(misfiledata[mi].mFlags & 1) )
      FreeMissileGFX(mi);
  }
}

//----- (0043EF66) --------------------------------------------------------
void __cdecl FreeMissiles2()
{
  int mi; // [esp+Ch] [ebp-4h]

  for ( mi = 0; misfiledata[mi].mAnimFAmt; ++mi )
  {
    if ( misfiledata[mi].mFlags & 1 )
      FreeMissileGFX(mi);
  }
}

//----- (0043EFD4) --------------------------------------------------------
void __cdecl InitMissiles()
{
  int i; // [esp+Ch] [ebp-4h]
  signed int j; // [esp+Ch] [ebp-4h]

  nummissiles = 0;
  for ( i = 0; i < 125; ++i )
  {
    missilevail[i] = i;
    missileactive[i] = 0;
  }
  Xunusedmissileflag = 0;
  for ( j = 0; j < 125; ++j )
  {
    Xunusedmissiledata[j][0] = -1;
    Xunusedmissiledata[j][1] = 0;
    Xunusedmissiledata[j][2] = 0;
  }
}

//----- (0043F085) --------------------------------------------------------
void __fastcall AddLArrow(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v9; // eax

  if ( dx == sx && dy == sy )
  {
    dx += XDirAdd[midir];
    dy += YDirAdd[midir];
  }
  if ( (_BYTE)mienemy )
  {
    GetMissileVel(mi, sx, sy, dx, dy, 32);
  }
  else if ( plr[id]._pClass == 1 )
  {
    GetMissileVel(mi, sx, sy, dx, dy, plr[id]._pLevel + 31);
  }
  else
  {
    GetMissileVel(mi, sx, sy, dx, dy, 32);
  }
  v9 = GetDirection16(sx, sy, dx, dy);
  SetMissDir(mi, v9);
  missile[mi]._mirange = 256;
  missile[mi]._miVar1 = sx;
  missile[mi]._miVar2 = sy;
  missile[mi]._mlid = AddLight(sx, sy, 5);
  PutMissile(mi);
}

//----- (0043F20A) --------------------------------------------------------
void __fastcall AddArrow(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v; // [esp+14h] [ebp-4h]

  if ( dx == sx && dy == sy )
  {
    dx += XDirAdd[midir];
    dy += YDirAdd[midir];
  }
  if ( (_BYTE)mienemy )
  {
    GetMissileVel(mi, sx, sy, dx, dy, 32);
  }
  else
  {
    v = 32;
    if ( plr[id]._pIFlags & 4 )
      v = random(64, 32) + 16;
    if ( plr[id]._pClass == 1 )
      v += plr[id]._pLevel - 1;
    GetMissileVel(mi, sx, sy, dx, dy, v);
  }
  missile[mi]._miAnimFrame = GetDirection16(sx, sy, dx, dy) + 1;
  missile[mi]._mirange = 256;
  PutMissile(mi);
}

//----- (0043F36F) --------------------------------------------------------
void __fastcall AddRndTeleport(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v11; // [esp+18h] [ebp-8h]
  int v12; // [esp+1Ch] [ebp-4h]

  do
  {
    v12 = random(58, 3) + 4;
    v11 = random(58, 3) + 4;
    if ( random(58, 2) == 1 )
      v12 = -v12;
    if ( random(58, 2) == 1 )
      v11 = -v11;
  }
  while ( nSolidTable[dPiece[sx + v12][sy + v11]] || dObject[sx + v12][sy + v11] || dMonster[sx + v12][sy + v11] );
  missile[mi]._mix = sx + v12;
  missile[mi]._miy = sy + v11;
  missile[mi]._mirange = 2;
  missile[mi]._miVar1 = 0;
  UseMana(id, 10);
}

//----- (0043F4E6) --------------------------------------------------------
void __fastcall AddFirebolt(int mi, int sx, int sy, int dx, int dy, int midir, int micaster, int id, int dam)
{
  int v9; // eax
  int v; // [esp+14h] [ebp-4h]

  if ( dx == sx && dy == sy )
  {
    dx += XDirAdd[midir];
    dy += YDirAdd[midir];
  }
  UseMana(id, 1);
  if ( id == -1 )
  {
    v = 16;
  }
  else
  {
    v = 2 * GetSpellLevel(id, 1) + 16;
    if ( v >= 63 )
      v = 63;
  }
  GetMissileVel(mi, sx, sy, dx, dy, v);
  v9 = GetDirection16(sx, sy, dx, dy);
  SetMissDir(mi, v9);
  missile[mi]._mirange = 256;
  missile[mi]._miVar1 = sx;
  missile[mi]._miVar2 = sy;
  missile[mi]._mlid = AddLight(sx, sy, 8);
  PutMissile(mi);
}

//----- (0043F627) --------------------------------------------------------
void __fastcall AddMagmaball(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  GetMissileVel(mi, sx, sy, dx, dy, 16);
  missile[mi]._mitxoff += 3 * missile[mi]._mixvel;
  missile[mi]._mityoff += 3 * missile[mi]._miyvel;
  GetMissilePos(mi);
  missile[mi]._mirange = 256;
  missile[mi]._miVar1 = sx;
  missile[mi]._miVar2 = sy;
  missile[mi]._mlid = AddLight(sx, sy, 8);
  PutMissile(mi);
}

//----- (0043F730) --------------------------------------------------------
void __fastcall miss_null_33(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  GetMissileVel(mi, sx, sy, dx, dy, 16);
  missile[mi]._mirange = 256;
  missile[mi]._miVar1 = sx;
  missile[mi]._miVar2 = sy;
  PutMissile(mi);
}

//----- (0043F7B5) --------------------------------------------------------
void __fastcall AddTeleport(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int i; // [esp+14h] [ebp-Ch]
  int v11; // [esp+18h] [ebp-8h]
  int v12; // [esp+1Ch] [ebp-4h]

  missile[mi]._miVar1 = 1;
  if ( !nSolidTable[dPiece[dx][dy]] && !dObject[dx][dy] && !dMonster[dx][dy] )
    missile[mi]._miVar1 = 0;
  for ( i = 0; nummissiles > i; ++i )
  {
    v12 = missileactive[i];
    if ( missile[v12]._mitype == 26 && missile[v12]._misource == id )
      break;
  }
  if ( nummissiles == i )
  {
    v11 = 0;
    UseMana(id, 23);
  }
  else
  {
    v11 = missile[v12]._mirange;
    missile[v12]._mirange = 0;
  }
  missile[mi]._mix = dx;
  missile[mi]._miy = dy;
  if ( v11 )
  {
    missile[mi]._mirange = v11;
  }
  else
  {
    missile[mi]._mirange = 16 * plr[id]._pLevel;
    missile[mi]._mirange += plr[id]._pISplDur * missile[mi]._mirange >> 7;
  }
}

//----- (0043FA0D) --------------------------------------------------------
void __fastcall AddLightball(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  GetMissileVel(mi, sx, sy, dx, dy, 16);
  missile[mi]._midam = dam;
  missile[mi]._miAnimFrame = random(63, 8) + 1;
  missile[mi]._mirange = 255;
  PutMissile(mi);
}

//----- (0043FA9F) --------------------------------------------------------
void __fastcall AddFirewall(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v10; // ebx
  int v11; // ebx
  int j; // [esp+14h] [ebp-4h]

  v10 = plr[id]._pLevel;
  v11 = random(53, 10) + v10;
  missile[mi]._midam = 2 * (random(53, 10) + v11) + 4;
  GetMissileVel(mi, sx, sy, dx, dy, 16);
  missile[mi]._mirange = 80 * plr[id]._pLevel;
  for ( j = GetSpellLevel(id, 6); j > 0; --j )
    missile[mi]._mirange += missile[mi]._mirange >> 3;
  missile[mi]._mirange += plr[id]._pISplDur * missile[mi]._mirange >> 7;
  missile[mi]._miVar1 = missile[mi]._mirange - missile[mi]._miAnimLen;
  missile[mi]._miVar2 = 0;
  PutMissile(mi);
}

//----- (0043FC87) --------------------------------------------------------
void __fastcall AddFireball(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v9; // ebx
  int v10; // ebx
  int v11; // eax
  int v; // [esp+14h] [ebp-4h]
  int va; // [esp+14h] [ebp-4h]

  if ( dx == sx && dy == sy )
  {
    dx += XDirAdd[midir];
    dy += YDirAdd[midir];
  }
  v9 = plr[id]._pLevel;
  v10 = random(60, 10) + v9;
  missile[mi]._midam = random(60, 10) + v10 + 2;
  for ( v = GetSpellLevel(id, 12); v > 0; --v )
    missile[mi]._midam += missile[mi]._midam >> 3;
  va = 2 * GetSpellLevel(id, 12) + 16;
  if ( va > 50 )
    va = 50;
  GetMissileVel(mi, sx, sy, dx, dy, va);
  v11 = GetDirection16(sx, sy, dx, dy);
  SetMissDir(mi, v11);
  missile[mi]._mirange = 256;
  missile[mi]._miVar1 = sx;
  missile[mi]._miVar2 = sy;
  missile[mi]._miVar3 = 0;
  missile[mi]._mlid = AddLight(sx, sy, 8);
  UseMana(id, 12);
}

//----- (0043FE6F) --------------------------------------------------------
void __fastcall AddLightctrl(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  if ( !dam )
    UseMana(id, 3);
  missile[mi]._miVar1 = sx;
  missile[mi]._miVar2 = sy;
  GetMissileVel(mi, sx, sy, dx, dy, 32);
  missile[mi]._miAnimFrame = random(52, 8) + 1;
  missile[mi]._mirange = 256;
}

//----- (0043FF28) --------------------------------------------------------
void __fastcall AddLightning(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._misx = dx;
  missile[mi]._misy = dy;
  if ( midir >= 0 )
  {
    missile[mi]._mixoff = missile[midir]._mixoff;
    missile[mi]._miyoff = missile[midir]._miyoff;
    missile[mi]._mitxoff = missile[midir]._mitxoff;
    missile[mi]._mityoff = missile[midir]._mityoff;
  }
  missile[mi]._miAnimFrame = random(52, 8) + 1;
  if ( midir < 0 || (char)mienemy == 1 || id == -1 )
  {
    if ( midir < 0 || id == -1 )
      missile[mi]._mirange = 8;
    else
      missile[mi]._mirange = 10;
  }
  else
  {
    missile[mi]._mirange = GetSpellLevel(id, 3) + 6;
  }
  missile[mi]._mlid = AddLight(missile[mi]._mix, missile[mi]._miy, 4);
  PutMissile(mi);
}

//----- (0044012E) --------------------------------------------------------
void __fastcall AddMisexp(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._mix = missile[dx]._mix;
  missile[mi]._miy = missile[dx]._miy;
  missile[mi]._misx = missile[dx]._misx;
  missile[mi]._misy = missile[dx]._misy;
  missile[mi]._mixoff = missile[dx]._mixoff;
  missile[mi]._miyoff = missile[dx]._miyoff;
  missile[mi]._mitxoff = missile[dx]._mitxoff;
  missile[mi]._mityoff = missile[dx]._mityoff;
  missile[mi]._mixvel = 0;
  missile[mi]._miyvel = 0;
  missile[mi]._mirange = missile[mi]._miAnimLen;
  missile[mi]._miVar1 = 0;
  PutMissile(mi);
}

//----- (00440316) --------------------------------------------------------
void __fastcall AddWeapexp(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._mix = sx;
  missile[mi]._miy = sy;
  missile[mi]._misx = sx;
  missile[mi]._misy = sy;
  missile[mi]._mixvel = 0;
  missile[mi]._miyvel = 0;
  missile[mi]._miVar1 = 0;
  missile[mi]._mimfnum = 0;
  if ( dx == 1 )
    SetMissAnim(mi, 5);
  else
    SetMissAnim(mi, 27);
  missile[mi]._mirange = missile[mi]._miAnimLen - 1;
}

//----- (00440449) --------------------------------------------------------
void __fastcall AddTown(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v9; // eax
  int x; // [esp+14h] [ebp-1Ch]
  int v13; // [esp+18h] [ebp-18h]
  signed int v14; // [esp+1Ch] [ebp-14h]
  int j; // [esp+20h] [ebp-10h]
  int v16; // [esp+28h] [ebp-8h]
  int y; // [esp+2Ch] [ebp-4h]

  v14 = 1;
  x = dx;
  y = dy;
  if ( currlevel )
  {
    while ( v14 == 1 )
    {
      v14 = 0;
      if ( nSolidTable[dPiece[x][y]] )
        v14 = 1;
      if ( dMonster[x][y] )
        v14 = 1;
      if ( dObject[x][y] )
        v14 = 1;
      if ( dItem[x][y] )
        v14 = 1;
      if ( sx == x && sy == y )
        v14 = 1;
      v13 = random(54, 7);
      if ( v14 == 1 )
      {
        x += XDirAdd[v13];
        y += YDirAdd[v13];
      }
    }
  }
  missile[mi]._mix = x;
  missile[mi]._miy = y;
  missile[mi]._misx = x;
  missile[mi]._misy = y;
  missile[mi]._mirange = 100;
  missile[mi]._miVar1 = missile[mi]._mirange - missile[mi]._miAnimLen;
  missile[mi]._miVar2 = 0;
  for ( j = 0; j < nummissiles; ++j )
  {
    v16 = missileactive[j];
    if ( missile[v16]._mitype == 10 && v16 != mi && missile[v16]._misource == id )
      missile[v16]._mirange = 0;
  }
  PutMissile(mi);
  if ( id == myplr )
  {
    v9 = (unsigned __int8)setlevel;
    if ( setlevel )
    {
      LOBYTE(v9) = setlvlnum;
      NetSendCmdLocParam2(1u, 0x3Bu, x, y, v9 & 0xFFFF00FF, 1);
    }
    else
    {
      LOBYTE(v9) = currlevel;
      NetSendCmdLocParam2(1u, 0x3Bu, x, y, v9 & 0xFFFF00FF, 0);
    }
  }
}

//----- (00440779) --------------------------------------------------------
void __fastcall AddFlash(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  signed int j; // [esp+14h] [ebp-4h]
  int k; // [esp+14h] [ebp-4h]

  missile[mi]._midam = 0;
  for ( j = 0; plr[id]._pLevel >= j; ++j )
    missile[mi]._midam += random(55, 2) + 1;
  for ( k = GetSpellLevel(id, 4); k > 0; --k )
    missile[mi]._midam += missile[mi]._midam >> 3;
  missile[mi]._mirange = 19;
  UseMana(id, 4);
  PutMissile(mi);
}

//----- (0044088F) --------------------------------------------------------
void __fastcall AddFlash2(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  signed int j; // [esp+14h] [ebp-4h]
  int k; // [esp+14h] [ebp-4h]

  missile[mi]._midam = 0;
  for ( j = 0; plr[id]._pLevel >= j; ++j )
    missile[mi]._midam += random(56, 2) + 1;
  for ( k = GetSpellLevel(id, 4); k > 0; --k )
    missile[mi]._midam += missile[mi]._midam >> 3;
  missile[mi]._miPreFlag = 1;
  missile[mi]._mirange = 19;
  PutMissile(mi);
}

//----- (004409B1) --------------------------------------------------------
void __fastcall AddManashield(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._mirange = 255;
  missile[mi]._miVar1 = plr[id]._pHitPoints;
  missile[mi]._miVar2 = plr[id]._pHPBase;
  UseMana(id, 11);
  PutMissile(mi);
}

//----- (00440A5E) --------------------------------------------------------
void __fastcall AddFiremove(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v11; // ebx

  v11 = plr[id]._pLevel;
  missile[mi]._midam = random(59, 10) + v11 + 1;
  GetMissileVel(mi, sx, sy, dx, dy, 16);
  missile[mi]._mirange = 255;
  missile[mi]._miVar1 = 0;
  missile[mi]._miVar2 = 0;
  PutMissile(mi);
}

//----- (00440B2A) --------------------------------------------------------
void __fastcall AddGuardian(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miDelFlag = 1;
}

//----- (00440B5E) --------------------------------------------------------
void __fastcall AddChain(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miVar1 = dx;
  missile[mi]._miVar2 = dy;
  missile[mi]._mirange = 1;
  UseMana(id, 14);
}

//----- (00440BCF) --------------------------------------------------------
void __fastcall miss_null_11(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  SetMissDir(mi, dx);
  missile[mi]._midam = 0;
  missile[mi]._miLightFlag = 1;
  missile[mi]._mirange = 250;
  PutMissile(mi);
}

//----- (00440C48) --------------------------------------------------------
void __fastcall miss_null_12(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  if ( dx > 3 )
    dx = 2;
  SetMissDir(mi, dx);
  missile[mi]._midam = 0;
  missile[mi]._miLightFlag = 1;
  missile[mi]._mirange = 250;
  PutMissile(mi);
}

//----- (00440CD2) --------------------------------------------------------
void __fastcall miss_null_13(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  if ( dx > 3 )
    dx = 2;
  SetMissDir(mi, dx);
  missile[mi]._midam = 0;
  missile[mi]._miLightFlag = 1;
  missile[mi]._mirange = missile[mi]._miAnimLen;
  PutMissile(mi);
}

//----- (00440D6D) --------------------------------------------------------
void __fastcall AddRhino(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  AnimStruct *v10; // [esp+14h] [ebp-4h]

  if ( (signed int)monster[id].MType->mtype < 64 || (signed int)monster[id].MType->mtype > 67 )
    v10 = &monster[id].MType->Anims[1];
  else
    v10 = &monster[id].MType->Anims[5];
  GetMissileVel(mi, sx, sy, dx, dy, 16);
  missile[mi]._mimfnum = midir;
  missile[mi]._miAnimFlags = 0;
  missile[mi]._miAnimData = v10->Frames[midir];
  missile[mi]._miAnimDelay = v10->Delay;
  missile[mi]._miAnimLen = v10->Rate;
  missile[mi]._miAnimWidth = monster[id].MType->flags_1;
  missile[mi]._miAnimWidth2 = monster[id].MType->flags_2;
  missile[mi]._miAnimAdd = 1;
  missile[mi]._miVar1 = 0;
  missile[mi]._miVar2 = 0;
  missile[mi]._miLightFlag = 1;
  if ( monster[id]._uniqtype )
    missile[mi]._miUniqTrans = (unsigned __int8)monster[id]._uniqtrans + 1;
  missile[mi]._mirange = 256;
  PutMissile(mi);
}

//----- (00440FD1) --------------------------------------------------------
void __fastcall miss_null_32(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  AnimStruct *v9; // ST24_4

  v9 = &monster[id].MType->Anims[1];
  GetMissileVel(mi, sx, sy, dx, dy, 16);
  missile[mi]._mimfnum = midir;
  missile[mi]._miAnimFlags = 0;
  missile[mi]._miAnimData = v9->Frames[midir];
  missile[mi]._miAnimDelay = v9->Delay;
  missile[mi]._miAnimLen = v9->Rate;
  missile[mi]._miAnimWidth = monster[id].MType->flags_1;
  missile[mi]._miAnimWidth2 = monster[id].MType->flags_2;
  missile[mi]._miAnimAdd = 1;
  missile[mi]._miVar1 = 0;
  missile[mi]._miVar2 = 0;
  missile[mi]._miLightFlag = 1;
  if ( monster[id]._uniqtype )
    missile[mi]._miUniqTrans = (unsigned __int8)monster[id]._uniqtrans + 1;
  dMonster[monster[id]._mx][monster[id]._my] = 0;
  missile[mi]._mirange = 256;
  PutMissile(mi);
}

//----- (0044120F) --------------------------------------------------------
void __fastcall AddFlare(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int j; // [esp+14h] [ebp-8h]
  signed int v12; // [esp+18h] [ebp-4h]

  GetMissileVel(mi, sx, sy, dx, dy, 16);
  missile[mi]._mirange = 256;
  missile[mi]._miVar1 = sx;
  missile[mi]._miVar2 = sy;
  missile[mi]._mlid = AddLight(sx, sy, 8);
  if ( !(_BYTE)mienemy )
  {
    UseMana(id, 35);
    v12 = 25;
    for ( j = GetSpellLevel(id, 35); j < 0; ++j )
      v12 -= 4;
    if ( v12 <= 0 )
      v12 = 1;
    plr[id]._pHitPoints -= v12 << 6;
    plr[id]._pHPBase -= v12 << 6;
    drawmanaflag = 1;
    if ( plr[id]._pHitPoints <= 0 )
    {
      plr[id]._pHitPoints = 0;
      SyncPlrKill(id);
    }
  }
  PutMissile(mi);
}

//----- (004413BB) --------------------------------------------------------
void __fastcall AddAcid(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v11; // eax

  GetMissileVel(mi, sx, sy, dx, dy, 16);
  v11 = GetDirection16(sx, sy, dx, dy);
  SetMissDir(mi, v11);
  missile[mi]._mirange = 5 * monster[id]._mint + 20;
  missile[mi]._mlid = -1;
  missile[mi]._miVar1 = sx;
  missile[mi]._miVar2 = sy;
  PutMissile(mi);
}

//----- (0044148F) --------------------------------------------------------
void __fastcall miss_null_1D(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._midam = dam;
  missile[mi]._mixvel = 0;
  missile[mi]._miyvel = 0;
  missile[mi]._mirange = 50;
  missile[mi]._miVar1 = missile[mi]._mirange - missile[mi]._miAnimLen;
  missile[mi]._miVar2 = 0;
  PutMissile(mi);
}

//----- (0044156D) --------------------------------------------------------
void __fastcall AddAcidpud(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v10; // ebx

  missile[mi]._mixvel = 0;
  missile[mi]._miyvel = 0;
  missile[mi]._mixoff = 0;
  missile[mi]._miyoff = 0;
  missile[mi]._miLightFlag = 1;
  v10 = 5 * monster[missile[mi]._misource]._mint + 5;
  missile[mi]._mirange = random(50, 15) + 8 * v10;
  missile[mi]._miPreFlag = 1;
}

//----- (00441677) --------------------------------------------------------
void __fastcall AddStone(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v9; // ST14_4
  signed int i; // [esp+18h] [ebp-28h]
  int v12; // [esp+1Ch] [ebp-24h]
  int CrawlNum[6]; // [esp+20h] [ebp-20h]
  int j; // [esp+38h] [ebp-8h]
  int v15; // [esp+3Ch] [ebp-4h]

  CrawlNum[0] = 0;
  CrawlNum[1] = 3;
  CrawlNum[2] = 12;
  CrawlNum[3] = 45;
  CrawlNum[4] = 94;
  CrawlNum[5] = 159;
  missile[mi]._misource = id;
  for ( i = 0; i < 6; ++i )
  {
    v9 = CrawlNum[i];
    v12 = v9 + 1;
    for ( j = (unsigned __int8)CrawlTable[v9]; j > 0; --j )
    {
      v15 = dMonster[dx + CrawlTable[v12]][dy + CrawlTable[v12 + 1]];
      if ( v15 <= 0 )
        v15 = -(v15 + 1);
      else
        --v15;
      if ( v15 > 0 )
      {
        j = -99;
        i = 6;
        missile[mi]._miVar1 = monster[v15]._mmode;
        missile[mi]._miVar2 = v15;
        monster[v15]._mmode = 15;
        break;
      }
      v12 += 2;
    }
  }
  if ( j == -99 )
  {
    missile[mi]._mix = dx + CrawlTable[v12];
    missile[mi]._miy = dy + CrawlTable[v12 + 1];
    missile[mi]._misx = missile[mi]._mix;
    missile[mi]._misy = missile[mi]._miy;
    missile[mi]._mirange = 16 * plr[id]._pLevel;
    for ( j = GetSpellLevel(id, 8); j > 0; --j )
      missile[mi]._mirange += 16 * missile[mi]._mirange >> 3;
    missile[mi]._mirange += plr[id]._pISplDur * missile[mi]._mirange >> 7;
    UseMana(id, 8);
  }
  else
  {
    missile[mi]._miDelFlag = 1;
  }
}

//----- (00441990) --------------------------------------------------------
void __fastcall AddGolem(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int i; // [esp+14h] [ebp-8h]

  missile[mi]._mirange = 32 * plr[id]._pLevel;
  for ( i = GetSpellLevel(id, 21); i > 0; --i )
    missile[mi]._mirange += 16 * missile[mi]._mirange >> 3;
  missile[mi]._mirange += missile[mi]._mirange * plr[id]._pISplDur >> 7;
  if ( dFlags[dx][dy] & 0x40 && !((unsigned __int8)nSolidTable[dPiece[dx][dy]] | dMonster[dx][dy] | dObject[dx][dy]) )
  {
    SpawnGolum(dx, dy, missile[mi]._mirange);
    UseMana(id, 21);
  }
  missile[mi]._miDelFlag = 1;
}

//----- (00441B46) --------------------------------------------------------
void __fastcall AddEtherealize(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miDelFlag = 1;
}

//----- (00441B7A) --------------------------------------------------------
void __fastcall miss_null_1F(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miDelFlag = 1;
}

//----- (00441BAE) --------------------------------------------------------
void __fastcall miss_null_23(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._midam = dam;
  missile[mi]._mix = sx;
  missile[mi]._miy = sy;
  missile[mi]._misx = sx;
  missile[mi]._misy = sy;
  missile[mi]._misource = id;
  if ( dam == 1 )
    SetMissDir(mi, 0);
  else
    SetMissDir(mi, 1);
  missile[mi]._miLightFlag = 1;
  missile[mi]._mirange = missile[mi]._miAnimLen;
  PutMissile(mi);
}

//----- (00441CCA) --------------------------------------------------------
void __fastcall AddBoom(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._mix = sx;
  missile[mi]._miy = sy;
  missile[mi]._misx = sx;
  missile[mi]._misy = sy;
  missile[mi]._mixvel = 0;
  missile[mi]._miyvel = 0;
  missile[mi]._midam = dam;
  missile[mi]._mirange = missile[mi]._miAnimLen;
  missile[mi]._miVar1 = 0;
  PutMissile(mi);
}

//----- (00441DDA) --------------------------------------------------------
void __fastcall AddHeal(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v10; // [esp+14h] [ebp-8h]
  signed int j; // [esp+18h] [ebp-4h]
  int k; // [esp+18h] [ebp-4h]

  v10 = (random(57, 10) + 1) << 6;
  for ( j = 0; plr[id]._pLevel > j; ++j )
    v10 += (random(57, 4) + 1) << 6;
  for ( k = 0; GetSpellLevel(id, 2) > k; ++k )
    v10 += (random(57, 6) + 1) << 6;
  if ( !plr[id]._pClass )
    v10 *= 2;
  if ( plr[id]._pClass == 1 )
    v10 += v10 >> 1;
  plr[id]._pHitPoints += v10;
  if ( plr[id]._pHitPoints > plr[id]._pMaxHP )
    plr[id]._pHitPoints = plr[id]._pMaxHP;
  plr[id]._pHPBase += v10;
  if ( plr[id]._pMaxHPBase < plr[id]._pHPBase )
    plr[id]._pHPBase = plr[id]._pMaxHPBase;
  UseMana(id, 2);
  drawmanaflag = 1;
  missile[mi]._miDelFlag = 1;
  PutMissile(mi);
}

//----- (00442060) --------------------------------------------------------
void __fastcall AddHealOther(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miDelFlag = 1;
  UseMana(id, 34);
  if ( myplr == id )
    j_SetCursor(10);
}

//----- (004420BA) --------------------------------------------------------
void __fastcall AddElement(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v9; // ST28_4
  int v10; // eax
  signed int j; // [esp+14h] [ebp-8h]
  int k; // [esp+14h] [ebp-8h]
  int x2; // [esp+28h] [ebp+Ch]
  int dya; // [esp+2Ch] [ebp+10h]

  missile[mi]._midam = 0;
  for ( j = 0; plr[id]._pLevel > j; ++j )
    missile[mi]._midam += random(67, 6) + 1;
  for ( k = GetSpellLevel(id, 29); k > 0; --k )
    missile[mi]._midam += plr[id]._pLevel >> 1;
  v9 = FindClosest(sx, sy, 19);
  x2 = monster[v9]._mx;
  dya = monster[v9]._my;
  GetMissileVel(mi, sx, sy, monster[v9]._mx, monster[v9]._my, 16);
  v10 = GetDirection8(sx, sy, x2, dya);
  SetMissDir(mi, v10);
  missile[mi]._mirange = 256;
  missile[mi]._miVar1 = sx;
  missile[mi]._miVar2 = sy;
  missile[mi]._miVar3 = 0;
  missile[mi]._mlid = AddLight(sx, sy, 8);
  UseMana(id, 29);
  PutMissile(mi);
}

//----- (004422B7) --------------------------------------------------------
void __fastcall AddIdentify(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miDelFlag = 1;
  UseMana(id, 5);
  if ( id == myplr )
  {
    if ( sbookflag )
      sbookflag = 0;
    if ( !invflag )
      invflag = 1;
    j_SetCursor(2);
  }
}

//----- (0044233E) --------------------------------------------------------
void __fastcall AddFirewallC(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  char v9; // al

  if ( dFlags[dx][dy] & 0x40 )
  {
    missile[mi]._miVar1 = dx;
    missile[mi]._miVar2 = dy;
    missile[mi]._miVar5 = dx;
    missile[mi]._miVar6 = dy;
    missile[mi]._miVar7 = 0;
    missile[mi]._miVar8 = 0;
    v9 = GetDirection(sx, sy, missile[mi]._miVar1, missile[mi]._miVar2);
    missile[mi]._miVar3 = (v9 - 2) & 7;
    missile[mi]._miVar4 = (v9 + 2) & 7;
    missile[mi]._mirange = 20;
    UseMana(id, 6);
  }
  else
  {
    missile[mi]._miDelFlag = 1;
    PutMissile(mi);
  }
}

//----- (004424CD) --------------------------------------------------------
void __fastcall AddInfra(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._mirange = 255;
  missile[mi]._mirange += plr[id]._pISplDur * missile[mi]._mirange >> 7;
  UseMana(id, 9);
}

//----- (00442559) --------------------------------------------------------
void __fastcall AddWave(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miVar1 = dx;
  missile[mi]._miVar2 = dy;
  missile[mi]._mirange = 1;
  UseMana(id, 15);
}

//----- (004425CA) --------------------------------------------------------
void __fastcall AddNova(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int v9; // ebx
  int v10; // ebx
  int v11; // ebx
  int v12; // ebx
  int v13; // ebx
  int v14; // ebx
  int i; // [esp+14h] [ebp-4h]

  missile[mi]._miVar1 = dx;
  missile[mi]._miVar2 = dy;
  if ( id == -1 )
  {
    v13 = random(66, 3);
    v14 = random(66, 3) + v13;
    missile[mi]._midam = random(66, 3) + v14;
    missile[mi]._midam += (signed int)currlevel >> 1;
  }
  else
  {
    v9 = random(66, 6);
    v10 = random(66, 6) + v9;
    v11 = random(66, 6) + v10;
    v12 = random(66, 6) + v11;
    missile[mi]._midam = random(66, 6) + v12;
    missile[mi]._midam += plr[id]._pLevel + 5;
    for ( i = GetSpellLevel(id, 18); i > 0; --i )
      missile[mi]._midam += missile[mi]._midam >> 3;
    UseMana(id, 18);
  }
  missile[mi]._mirange = 1;
}

//----- (004427A4) --------------------------------------------------------
void __fastcall AddBlodboil(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miVar1 = dx;
  missile[mi]._miVar2 = dy;
  missile[mi]._mirange = 1;
}

//----- (00442808) --------------------------------------------------------
void __fastcall AddRepair(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miDelFlag = 1;
  UseMana(id, 26);
  if ( myplr == id )
  {
    if ( sbookflag )
      sbookflag = 0;
    if ( !invflag )
      invflag = 1;
    j_SetCursor(3);
  }
}

//----- (00442890) --------------------------------------------------------
void __fastcall AddRecharge(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miDelFlag = 1;
  UseMana(id, 27);
  if ( myplr == id )
  {
    if ( sbookflag )
      sbookflag = 0;
    if ( !invflag )
      invflag = 1;
    j_SetCursor(4);
  }
}

//----- (00442918) --------------------------------------------------------
void __fastcall AddDisarm(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miDelFlag = 1;
  UseMana(id, 28);
  if ( myplr == id )
    j_SetCursor(5);
}

//----- (00442972) --------------------------------------------------------
void __fastcall AddApoca(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miDelFlag = 1;
}

//----- (004429A6) --------------------------------------------------------
void __fastcall AddFlame(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  int i; // [esp+14h] [ebp-4h]
  int j; // [esp+14h] [ebp-4h]

  missile[mi]._mix = sx + XDirAdd[midir];
  missile[mi]._miy = sy + YDirAdd[midir];
  missile[mi]._misx = missile[mi]._mix;
  missile[mi]._misy = missile[mi]._miy;
  missile[mi]._mixvel = 0;
  missile[mi]._miyvel = 0;
  missile[mi]._midam = 4 * plr[id]._pLevel;
  for ( i = GetSpellLevel(id, 20); i > 0; --i )
    missile[mi]._midam += missile[mi]._midam >> 3;
  missile[mi]._midam *= 2;
  missile[mi]._mirange = 0;
  for ( j = 4 - dam; j > 0; --j )
    missile[mi]._mirange += 2 * misfiledata[20].mAnimLen[midir];
  missile[mi]._mirange += misfiledata[21].mAnimLen[midir];
  missile[mi]._miVar1 = missile[mi]._mirange - misfiledata[20].mAnimLen[midir];
  missile[mi]._miVar2 = misfiledata[20].mAnimLen[midir];
  missile[mi]._miVar3 = dam;
  missile[mi]._miVar4 = plr[id].WorldX;
  missile[mi]._miVar5 = plr[id].WorldY;
  missile[mi]._miDelFlag = 0;
}

//----- (00442C98) --------------------------------------------------------
void __fastcall AddFlamec(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._mirange = 1;
  missile[mi]._miVar1 = dx;
  missile[mi]._miVar2 = dy;
  missile[mi]._miDelFlag = 0;
  UseMana(id, 20);
}

//----- (00442D22) --------------------------------------------------------
void __fastcall AddCbolt(int mi, int sx, int sy, int dx, int dy, int midir, int micaster, int id, int dam)
{
  int j; // [esp+14h] [ebp-4h]

  missile[mi]._mirnd = random(63, 15) + 1;
  if ( dx == sx && dy == sy )
  {
    dx += XDirAdd[midir];
    dy += YDirAdd[midir];
  }
  missile[mi]._miAnimFrame = random(63, 8) + 1;
  missile[mi]._mlid = AddLight(sx, sy, 5);
  GetMissileVel(mi, sx, sy, dx, dy, 8);
  missile[mi]._miVar1 = 5;
  missile[mi]._miVar2 = midir;
  missile[mi]._miVar3 = 0;
  missile[mi]._mirange = 256;
  missile[mi]._midam = random(68, plr[id]._pMagic >> 2);
  for ( j = GetSpellLevel(id, 30); j > 0; --j )
    ++missile[mi]._midam;
  PutMissile(mi);
}

//----- (00442F15) --------------------------------------------------------
void __fastcall AddHbolt(int mi, int sx, int sy, int dx, int dy, int midir, int micaster, int id, int dam)
{
  int v9; // eax
  int v10; // ebx
  int v; // [esp+14h] [ebp-4h]

  if ( dx == sx && dy == sy )
  {
    dx += XDirAdd[midir];
    dy += YDirAdd[midir];
  }
  if ( id == -1 )
  {
    v = 16;
  }
  else
  {
    v = 2 * GetSpellLevel(id, 31) + 16;
    if ( v >= 63 )
      v = 63;
  }
  GetMissileVel(mi, sx, sy, dx, dy, v);
  v9 = GetDirection16(sx, sy, dx, dy);
  SetMissDir(mi, v9);
  missile[mi]._mirange = 256;
  missile[mi]._miVar1 = sx;
  missile[mi]._miVar2 = sy;
  missile[mi]._mlid = AddLight(sx, sy, 8);
  v10 = plr[id]._pLevel;
  missile[mi]._midam = random(69, 10) + v10 + 9;
  UseMana(id, 31);
  PutMissile(mi);
}

//----- (0044309D) --------------------------------------------------------
void __fastcall AddResurrect(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  UseMana(id, 32);
  if ( myplr == id )
    j_SetCursor(8);
  missile[mi]._miDelFlag = 1;
}

//----- (004430F7) --------------------------------------------------------
void __fastcall AddResurrectBeam(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._mix = dx;
  missile[mi]._miy = dy;
  missile[mi]._misx = missile[mi]._mix;
  missile[mi]._misy = missile[mi]._miy;
  missile[mi]._mixvel = 0;
  missile[mi]._miyvel = 0;
  missile[mi]._mirange = misfiledata[37].mAnimLen[0];
}

//----- (004431E4) --------------------------------------------------------
void __fastcall AddTelekinesis(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  missile[mi]._miDelFlag = 1;
  UseMana(id, 33);
  if ( myplr == id )
    j_SetCursor(7);
}

//----- (0044323E) --------------------------------------------------------
void __fastcall AddBoneSpirit(int mi, int sx, int sy, int dx, int dy, int midir, int mienemy, int id, int dam)
{
  GetMissileVel(mi, sx, sy, dx, dy, 16);
  missile[mi]._mirange = 256;
  missile[mi]._miVar1 = sx;
  missile[mi]._miVar2 = sy;
  missile[mi]._mlid = AddLight(sx, sy, 8);
  if ( !(_BYTE)mienemy )
  {
    UseMana(id, 36);
    plr[id]._pHitPoints -= 1536;
    plr[id]._pHPBase -= 1536;
    drawmanaflag = 1;
    if ( plr[id]._pHitPoints <= 0 )
    {
      plr[id]._pHitPoints = 0;
      SyncPlrKill(id);
    }
  }
  PutMissile(mi);
}

//----- (004433AE) --------------------------------------------------------
int __fastcall AddMissile(int sx, int sy, int v1, int v2, int midir, int mitype, int micaster, int id, int v3)
{
  int mi; // [esp+14h] [ebp-4h]

  if ( nummissiles < 125 )
  {
    mi = missilevail[0];
    missilevail[0] = missilevail[125 - nummissiles - 1];
    missileactive[nummissiles] = mi;
    missile[mi]._mitype = mitype;
    missile[mi]._micaster = (char)micaster;
    missile[mi]._misource = id;
    missile[mi]._miAnimType = missiledata[mitype].mFileNum;
    missile[mi]._miDrawFlag = missiledata[mitype].mDraw;
    missile[mi]._mimfnum = midir;
    if ( missile[mi]._miAnimType == 255 || (signed int)misfiledata[missile[mi]._miAnimType].mAnimFAmt < 8 )
      SetMissDir(mi, 0);
    else
      SetMissDir(mi, midir);
    missile[mi]._mix = sx;
    missile[mi]._miy = sy;
    missile[mi]._mixoff = 0;
    missile[mi]._miyoff = 0;
    missile[mi]._misx = sx;
    missile[mi]._misy = sy;
    missile[mi]._mitxoff = 0;
    missile[mi]._mityoff = 0;
    missile[mi]._miDelFlag = 0;
    missile[mi]._miAnimAdd = 1;
    missile[mi]._miLightFlag = 0;
    missile[mi]._miPreFlag = 0;
    missile[mi]._miUniqTrans = 0;
    missile[mi]._midam = v3;
    missile[mi]._miHitFlag = 0;
    missile[mi]._midist = 0;
    missile[mi]._mlid = -1;
    missile[mi]._mirnd = 0;
    if ( missiledata[mitype].mlSFX != -1 )
      PlaySfxLoc(missiledata[mitype].mlSFX, missile[mi]._mix, missile[mi]._miy);
    missiledata[mitype].mAddProc(mi, sx, sy, v1, v2, midir, micaster, id, v3);
    ++nummissiles;
  }
  return mi;
}

//----- (0044377B) --------------------------------------------------------
signed int __fastcall unused_sub_44377B(int a1, int a2, int ty)
{
  int midir; // ST30_4
  int tx; // [esp+Ch] [ebp-14h]
  int mi; // [esp+10h] [ebp-10h]
  signed int v7; // [esp+1Ch] [ebp-4h]

  tx = a2;
  mi = a1;
  v7 = 0;
  if ( !CheckBlock(missile[a1]._mix, missile[a1]._miy, a2, ty)
    && dMonster[tx][ty] > 0
    && (signed int)(monster[dMonster[tx][ty] - 1]._mhitpoints & 0xFFFFFFC0) > 0 )
  {
    midir = GetDirection(missile[mi]._mix, missile[mi]._miy, tx, ty);
    AddMissile(missile[mi]._mix, missile[mi]._miy, tx, ty, midir, 1, 0, myplr, missile[mi]._midam);
    v7 = -1;
  }
  if ( v7 == -1 )
  {
    SetMissDir(mi, 2);
    missile[mi]._miVar2 = 3;
  }
  return v7;
}

//----- (00443907) --------------------------------------------------------
void __fastcall MI_Dummy(int i)
{
  ;
}

//----- (0044391D) --------------------------------------------------------
void __fastcall MI_SetManashield(int i)
{
  ManashieldFlag = 1;
}

//----- (0044393D) --------------------------------------------------------
void __fastcall MI_LArrow(int i)
{
  int maxdam; // [esp+10h] [ebp-Ch]
  int mindam; // [esp+14h] [ebp-8h]
  int v4; // [esp+18h] [ebp-4h]

  --missile[i]._mirange;
  if ( missile[i]._miAnimType == 27 )
  {
    ChangeLight(missile[i]._mlid, missile[i]._mix, missile[i]._miy, missile[i]._miAnimFrame + 5);
  }
  else
  {
    ++missile[i]._midist;
    missile[i]._mitxoff += missile[i]._mixvel;
    missile[i]._mityoff += missile[i]._miyvel;
    GetMissilePos(i);
    v4 = missile[i]._misource;
    if ( v4 == -1 )
    {
      mindam = currlevel + random(68, 10) + 1;
      maxdam = random(68, 10) + 2 * currlevel + 1;
    }
    else if ( missile[i]._micaster )
    {
      mindam = monster[v4].mMinDamage;
      maxdam = monster[v4].mMaxDamage;
    }
    else
    {
      mindam = plr[v4]._pIMinDam;
      maxdam = plr[v4]._pIMaxDam;
    }
    if ( missile[i]._mix != missile[i]._misx || missile[i]._miy != missile[i]._misy )
      CheckMissileCol(i, mindam, maxdam, 0, missile[i]._mix, missile[i]._miy, 0);
    if ( missile[i]._mirange )
    {
      if ( missile[i]._mix != missile[i]._miVar1 || missile[i]._miy != missile[i]._miVar2 )
      {
        missile[i]._miVar1 = missile[i]._mix;
        missile[i]._miVar2 = missile[i]._miy;
        ChangeLight(missile[i]._mlid, missile[i]._miVar1, missile[i]._miVar2, 5);
      }
    }
    else
    {
      missile[i]._mimfnum = 0;
      if ( missile[i]._mitype == 56 )
      {
        SetMissAnim(i, 27);
        missile[i]._mirange = missile[i]._miAnimLen - 1;
      }
      else
      {
        AddMissile(
          missile[i]._mix,
          missile[i]._miy,
          i,
          0,
          missile[i]._mimfnum,
          9,
          missile[i]._micaster,
          missile[i]._misource,
          0);
        missile[i]._mirange = 0;
      }
    }
  }
  if ( !missile[i]._mirange )
  {
    missile[i]._miDelFlag = 1;
    AddUnLight(missile[i]._mlid);
  }
  PutMissile(i);
}

//----- (00443E69) --------------------------------------------------------
void __fastcall MI_Arrow(int i)
{
  int maxdam; // [esp+10h] [ebp-Ch]
  int mindam; // [esp+14h] [ebp-8h]
  int v4; // [esp+18h] [ebp-4h]

  --missile[i]._mirange;
  ++missile[i]._midist;
  missile[i]._mitxoff += missile[i]._mixvel;
  missile[i]._mityoff += missile[i]._miyvel;
  GetMissilePos(i);
  v4 = missile[i]._misource;
  if ( v4 == -1 )
  {
    mindam = currlevel;
    maxdam = 2 * currlevel;
  }
  else if ( missile[i]._micaster )
  {
    mindam = monster[v4].mMinDamage;
    maxdam = monster[v4].mMaxDamage;
  }
  else
  {
    mindam = plr[v4]._pIMinDam;
    maxdam = plr[v4]._pIMaxDam;
  }
  if ( missile[i]._mix != missile[i]._misx || missile[i]._miy != missile[i]._misy )
    CheckMissileCol(i, mindam, maxdam, 0, missile[i]._mix, missile[i]._miy, 0);
  if ( !missile[i]._mirange )
    missile[i]._miDelFlag = 1;
  PutMissile(i);
}

//----- (004440B1) --------------------------------------------------------
void __fastcall MI_Firebolt(int i)
{
  signed int j; // [esp+14h] [ebp-14h]
  int k; // [esp+14h] [ebp-14h]
  int v4; // [esp+18h] [ebp-10h]
  int v5; // [esp+1Ch] [ebp-Ch]
  int mindam; // [esp+20h] [ebp-8h]
  int id; // [esp+24h] [ebp-4h]

  v5 = missile[i]._mitxoff;
  v4 = missile[i]._mityoff;
  --missile[i]._mirange;
  missile[i]._mitxoff += missile[i]._mixvel;
  missile[i]._mityoff += missile[i]._miyvel;
  GetMissilePos(i);
  id = missile[i]._misource;
  if ( id == -1 )
  {
    mindam = currlevel + random(78, 2 * currlevel);
  }
  else if ( missile[i]._micaster )
  {
    mindam = (monster[id].mMinDamage + random(77, monster[id].mMaxDamage - monster[id].mMinDamage + 1)) >> 1;
  }
  else
  {
    mindam = 0;
    for ( j = 0; j < 4; ++j )
      mindam += random(75, 6) + 1;
    for ( k = GetSpellLevel(id, 35); k > 0; --k )
      mindam += 3;
  }
  if ( missile[i]._mix != missile[i]._misx || missile[i]._miy != missile[i]._misy )
    CheckMissileCol(i, mindam, mindam, 0, missile[i]._mix, missile[i]._miy, 0);
  if ( missile[i]._mirange )
  {
    if ( missile[i]._mix != missile[i]._miVar1 || missile[i]._miy != missile[i]._miVar2 )
    {
      missile[i]._miVar1 = missile[i]._mix;
      missile[i]._miVar2 = missile[i]._miy;
      if ( missile[i]._mlid >= 0 )
        ChangeLight(missile[i]._mlid, missile[i]._miVar1, missile[i]._miVar2, 8);
    }
  }
  else
  {
    missile[i]._miDelFlag = 1;
    missile[i]._mitxoff = v5;
    missile[i]._mityoff = v4;
    GetMissilePos(i);
    switch ( missile[i]._mitype )
    {
      case 1:
      case 0x15:
        AddMissile(
          missile[i]._mix,
          missile[i]._miy,
          i,
          0,
          missile[i]._mimfnum,
          9,
          missile[i]._micaster,
          missile[i]._misource,
          0);
        break;
      case 0x18:
        AddMissile(
          missile[i]._mix,
          missile[i]._miy,
          i,
          0,
          missile[i]._mimfnum,
          25,
          missile[i]._micaster,
          missile[i]._misource,
          0);
        break;
      case 0x39:
        AddMissile(
          missile[i]._mix,
          missile[i]._miy,
          i,
          0,
          missile[i]._mimfnum,
          58,
          missile[i]._micaster,
          missile[i]._misource,
          0);
        break;
      default:
        break;
    }
    if ( missile[i]._mlid >= 0 )
      AddUnLight(missile[i]._mlid);
  }
  PutMissile(i);
}

//----- (00444704) --------------------------------------------------------
void __fastcall MI_Lightball(int i)
{
  int v2; // [esp+10h] [ebp-4h]

  --missile[i]._mirange;
  missile[i]._mitxoff += missile[i]._mixvel;
  missile[i]._mityoff += missile[i]._miyvel;
  GetMissilePos(i);
  v2 = missile[i]._mirange;
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix, missile[i]._miy, 0);
  if ( missile[i]._miHitFlag == 1 )
    missile[i]._mirange = v2;
  if ( !missile[i]._mirange )
    missile[i]._miDelFlag = 1;
  PutMissile(i);
}

//----- (00444877) --------------------------------------------------------
void __fastcall mi_null_33(int i)
{
  --missile[i]._mirange;
  missile[i]._mitxoff += missile[i]._mixvel;
  missile[i]._mityoff += missile[i]._miyvel;
  GetMissilePos(i);
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix, missile[i]._miy, 0);
  if ( !missile[i]._mirange )
    missile[i]._miDelFlag = 1;
  PutMissile(i);
}

//----- (0044499E) --------------------------------------------------------
void __fastcall MI_Acidpud(int i)
{
  int v1; // ST24_4

  v1 = --missile[i]._mirange;
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 1, missile[i]._mix, missile[i]._miy, 0);
  missile[i]._mirange = v1;
  if ( !missile[i]._mirange )
  {
    if ( missile[i]._mimfnum )
    {
      missile[i]._miDelFlag = 1;
    }
    else
    {
      SetMissDir(i, 1);
      missile[i]._mirange = missile[i]._miAnimLen;
    }
  }
  PutMissile(i);
}

//----- (00444AF1) --------------------------------------------------------
void __fastcall MI_Firewall(int i)
{
  int v2[14]; // [esp+10h] [ebp-38h]

  v2[0] = 2;
  v2[1] = 3;
  v2[2] = 4;
  v2[3] = 5;
  v2[4] = 5;
  v2[5] = 6;
  v2[6] = 7;
  v2[7] = 8;
  v2[8] = 9;
  v2[9] = 10;
  v2[10] = 11;
  v2[11] = 12;
  v2[12] = 12;
  v2[13] = 0;
  if ( missile[i]._miVar1 == --missile[i]._mirange )
  {
    SetMissDir(i, 1);
    missile[i]._miAnimFrame = random(83, 11) + 1;
  }
  if ( missile[i]._miAnimLen - 1 == missile[i]._mirange )
  {
    SetMissDir(i, 0);
    missile[i]._miAnimFrame = 13;
    missile[i]._miAnimAdd = -1;
  }
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 1, missile[i]._mix, missile[i]._miy, 1u);
  if ( !missile[i]._mirange )
  {
    missile[i]._miDelFlag = 1;
    AddUnLight(missile[i]._mlid);
  }
  if ( missile[i]._mimfnum && missile[i]._mirange && missile[i]._miAnimAdd != -1 && missile[i]._miVar2 < 12 )
  {
    if ( !missile[i]._miVar2 )
      missile[i]._mlid = AddLight(missile[i]._mix, missile[i]._miy, v2[missile[i]._miVar2]);
    ChangeLight(missile[i]._mlid, missile[i]._mix, missile[i]._miy, v2[missile[i]._miVar2]);
    ++missile[i]._miVar2;
  }
  PutMissile(i);
}

//----- (00444E65) --------------------------------------------------------
void __fastcall MI_Fireball(int i)
{
  int x1; // [esp+10h] [ebp-18h]
  int v3; // [esp+14h] [ebp-14h]
  int y; // [esp+18h] [ebp-10h]
  int x; // [esp+1Ch] [ebp-Ch]
  int mindam; // [esp+20h] [ebp-8h]
  int y1; // [esp+24h] [ebp-4h]

  v3 = missile[i]._misource;
  mindam = missile[i]._midam;
  --missile[i]._mirange;
  if ( missile[i]._miAnimType == 19 )
  {
    x = missile[i]._mix;
    y = missile[i]._miy;
    x1 = plr[v3].WorldX;
    y1 = plr[v3].WorldY;
    ChangeLight(missile[i]._mlid, missile[i]._mix, missile[i]._miy, missile[i]._miAnimFrame);
    if ( !CheckBlock(x1, y1, x, y) )
      CheckMissileCol(i, mindam, mindam, 0, x, y, 1u);
    if ( !CheckBlock(x1, y1, x, y + 1) )
      CheckMissileCol(i, mindam, mindam, 0, x, y + 1, 1u);
    if ( !CheckBlock(x1, y1, x, y - 1) )
      CheckMissileCol(i, mindam, mindam, 0, x, y - 1, 1u);
    if ( !CheckBlock(x1, y1, x + 1, y) )
      CheckMissileCol(i, mindam, mindam, 0, x + 1, y, 1u);
    if ( !CheckBlock(x1, y1, x + 1, y - 1) )
      CheckMissileCol(i, mindam, mindam, 0, x + 1, y - 1, 1u);
    if ( !CheckBlock(x1, y1, x + 1, y + 1) )
      CheckMissileCol(i, mindam, mindam, 0, x + 1, y + 1, 1u);
    if ( !CheckBlock(x1, y1, x - 1, y) )
      CheckMissileCol(i, mindam, mindam, 0, x - 1, y, 1u);
    if ( !CheckBlock(x1, y1, x - 1, y + 1) )
      CheckMissileCol(i, mindam, mindam, 0, x - 1, y + 1, 1u);
    if ( !CheckBlock(x1, y1, x - 1, y - 1) )
      CheckMissileCol(i, mindam, mindam, 0, x - 1, y - 1, 1u);
    if ( !missile[i]._mirange )
    {
      missile[i]._miDelFlag = 1;
      AddUnLight(missile[i]._mlid);
    }
    PutMissile(i);
  }
  else
  {
    missile[i]._mitxoff += missile[i]._mixvel;
    missile[i]._mityoff += missile[i]._miyvel;
    GetMissilePos(i);
    if ( missile[i]._mix != missile[i]._misx || missile[i]._miy != missile[i]._misy )
      CheckMissileCol(i, mindam, mindam, 0, missile[i]._mix, missile[i]._miy, 0);
    if ( missile[i]._mirange )
    {
      if ( missile[i]._mix != missile[i]._miVar1 || missile[i]._miy != missile[i]._miVar2 )
      {
        missile[i]._miVar1 = missile[i]._mix;
        missile[i]._miVar2 = missile[i]._miy;
        ChangeLight(missile[i]._mlid, missile[i]._miVar1, missile[i]._miVar2, 8);
      }
    }
    else
    {
      missile[i]._mimfnum = 0;
      SetMissAnim(i, 19);
      missile[i]._mirange = missile[i]._miAnimLen - 1;
    }
    PutMissile(i);
  }
}

//----- (00445451) --------------------------------------------------------
void __fastcall MI_Lightctrl(int i)
{
  int v1; // ebx
  int v3; // [esp+10h] [ebp-Ch]
  int v4; // [esp+14h] [ebp-8h]
  int v5; // [esp+18h] [ebp-4h]

  --missile[i]._mirange;
  v5 = missile[i]._misource;
  if ( v5 == -1 )
  {
    v3 = random(81, currlevel) + 2 * currlevel;
  }
  else if ( missile[i]._micaster )
  {
    v3 = 2 * (monster[v5].mMinDamage + random(80, monster[v5].mMaxDamage - monster[v5].mMinDamage + 1));
  }
  else
  {
    v1 = random(79, plr[v5]._pLevel);
    v3 = (random(79, 2) + v1 + 2) << 6;
  }
  missile[i]._mitxoff += missile[i]._mixvel;
  missile[i]._mityoff += missile[i]._miyvel;
  GetMissilePos(i);
  v4 = dPiece[missile[i]._mix][missile[i]._miy];
  if ( missile[i]._misource == -1 )
  {
    if ( (missile[i]._mix != missile[i]._misx || missile[i]._miy != missile[i]._misy) && nMissileTable[v4] )
      missile[i]._mirange = 0;
  }
  else if ( nMissileTable[v4] )
  {
    missile[i]._mirange = 0;
  }
  if ( !nMissileTable[v4] && (missile[i]._mix != missile[i]._miVar1 || missile[i]._miy != missile[i]._miVar2) )
  {
    if ( missile[i]._micaster && missile[i]._misource != -1 )
      AddMissile(
        missile[i]._mix,
        missile[i]._miy,
        missile[i]._misx,
        missile[i]._misy,
        i,
        23,
        missile[i]._micaster,
        missile[i]._misource,
        v3);
    else
      AddMissile(
        missile[i]._mix,
        missile[i]._miy,
        missile[i]._misx,
        missile[i]._misy,
        i,
        8,
        missile[i]._micaster,
        missile[i]._misource,
        v3);
    missile[i]._miVar1 = missile[i]._mix;
    missile[i]._miVar2 = missile[i]._miy;
  }
  if ( !missile[i]._mirange )
    missile[i]._miDelFlag = 1;
}

//----- (00445957) --------------------------------------------------------
void __fastcall MI_Lightning(int i)
{
  int v2; // [esp+10h] [ebp-4h]

  v2 = --missile[i]._mirange;
  if ( missile[i]._mix != missile[i]._misx || missile[i]._miy != missile[i]._misy )
    CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 1, missile[i]._mix, missile[i]._miy, 0);
  if ( missile[i]._miHitFlag == 1 )
    missile[i]._mirange = v2;
  if ( !missile[i]._mirange )
  {
    missile[i]._miDelFlag = 1;
    AddUnLight(missile[i]._mlid);
  }
  PutMissile(i);
}

//----- (00445AE8) --------------------------------------------------------
void __fastcall MI_Town(int i)
{
  int v2[17]; // [esp+10h] [ebp-48h]
  int pnum; // [esp+54h] [ebp-4h]

  v2[0] = 1;
  v2[1] = 2;
  v2[2] = 3;
  v2[3] = 4;
  v2[4] = 5;
  v2[5] = 6;
  v2[6] = 7;
  v2[7] = 8;
  v2[8] = 9;
  v2[9] = 10;
  v2[10] = 11;
  v2[11] = 12;
  v2[12] = 13;
  v2[13] = 14;
  v2[14] = 15;
  v2[15] = 15;
  v2[16] = 15;
  if ( missile[i]._mirange > 1 )
    --missile[i]._mirange;
  if ( missile[i]._miVar1 == missile[i]._mirange )
    SetMissDir(i, 1);
  if ( currlevel && missile[i]._mimfnum != 1 && missile[i]._mirange )
  {
    if ( !missile[i]._miVar2 )
      missile[i]._mlid = AddLight(missile[i]._mix, missile[i]._miy, v2[missile[i]._miVar2]);
    ChangeLight(missile[i]._mlid, missile[i]._mix, missile[i]._miy, v2[missile[i]._miVar2]);
    ++missile[i]._miVar2;
  }
  for ( pnum = 0; pnum < 4; ++pnum )
  {
    if ( plr[pnum].plractive
      && plr[pnum].plrlevel == currlevel
      && !plr[pnum]._pLvlChanging
      && !plr[pnum]._pmode
      && missile[i]._mix == plr[pnum].WorldX
      && missile[i]._miy == plr[pnum].WorldY )
    {
      ClrPlrPath(pnum);
      if ( myplr == pnum )
      {
        NetSendCmdParam1(1u, CMD_WARP, missile[i]._misource);
        plr[pnum]._pmode = 10;
      }
    }
  }
  if ( !missile[i]._mirange )
  {
    missile[i]._miDelFlag = 1;
    AddUnLight(missile[i]._mlid);
  }
  PutMissile(i);
}

//----- (00445F15) --------------------------------------------------------
void __fastcall MI_Flash(int i)
{
  plr[missile[i]._misource]._pInvincible = 1;
  --missile[i]._mirange;
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix - 1, missile[i]._miy, 1u);
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix, missile[i]._miy, 1u);
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix + 1, missile[i]._miy, 1u);
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix - 1, missile[i]._miy + 1, 1u);
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix, missile[i]._miy + 1, 1u);
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix + 1, missile[i]._miy + 1, 1u);
  if ( !missile[i]._mirange )
  {
    missile[i]._miDelFlag = 1;
    plr[missile[i]._misource]._pInvincible = 0;
  }
  PutMissile(i);
}

//----- (00446236) --------------------------------------------------------
void __fastcall MI_Flash2(int i)
{
  plr[missile[i]._misource]._pInvincible = 1;
  --missile[i]._mirange;
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix - 1, missile[i]._miy - 1, 1u);
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix, missile[i]._miy - 1, 1u);
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix + 1, missile[i]._miy - 1, 1u);
  if ( !missile[i]._mirange )
  {
    missile[i]._miDelFlag = 1;
    plr[missile[i]._misource]._pInvincible = 0;
  }
  PutMissile(i);
}

//----- (0044642C) --------------------------------------------------------
void __fastcall MI_Manashield(int i)
{
  int v1; // eax
  int id; // [esp+10h] [ebp-Ch]
  int j; // [esp+14h] [ebp-8h]
  int v5; // [esp+18h] [ebp-4h]

  id = missile[i]._misource;
  missile[i]._mitxoff = plr[id]._pxoff << 16;
  missile[i]._mityoff = plr[id]._pyoff << 16;
  if ( plr[id]._pmode == 3 )
  {
    missile[i]._misx = plr[id]._px;
    v1 = plr[id]._py;
  }
  else
  {
    missile[i]._misx = plr[id].WorldX;
    v1 = plr[id].WorldY;
  }
  missile[i]._misy = v1;
  GetMissilePos(i);
  if ( plr[id]._pmode == 3 )
  {
    if ( plr[id]._pdir == 2 )
      ++missile[i]._mix;
    else
      ++missile[i]._miy;
  }
  if ( missile[i]._miVar1 > plr[id]._pHitPoints )
  {
    v5 = missile[i]._miVar1 - plr[id]._pHitPoints;
    for ( j = GetSpellLevel(id, 11); j > 0; --j )
      v5 -= v5 >> 3;
    if ( v5 < 0 )
      v5 = 0;
    drawhpflag = 1;
    drawmanaflag = 1;
    if ( plr[id]._pMana < v5 )
    {
      plr[id]._pHitPoints -= v5 - plr[id]._pMana;
      plr[id]._pHPBase -= v5 - plr[id]._pMana;
      plr[id]._pMana = 0;
      plr[id]._pManaBase = 0;
      missile[i]._mirange = 0;
    }
    else
    {
      plr[id]._pHitPoints = missile[i]._miVar1;
      plr[id]._pHPBase = missile[i]._miVar2;
      plr[id]._pMana -= v5;
      plr[id]._pManaBase -= v5;
    }
  }
  missile[i]._miVar1 = plr[id]._pHitPoints;
  missile[i]._miVar2 = plr[id]._pHPBase;
  if ( !missile[i]._mirange )
    missile[i]._miDelFlag = 1;
  PutMissile(i);
}

//----- (00446955) --------------------------------------------------------
void __fastcall MI_Etherealize(int i)
{
  ;
}

//----- (0044696B) --------------------------------------------------------
void __fastcall MI_Firemove(int i)
{
  int v2[14]; // [esp+10h] [ebp-3Ch]
  int v3; // [esp+48h] [ebp-4h]

  v2[0] = 2;
  v2[1] = 3;
  v2[2] = 4;
  v2[3] = 5;
  v2[4] = 5;
  v2[5] = 6;
  v2[6] = 7;
  v2[7] = 8;
  v2[8] = 9;
  v2[9] = 10;
  v2[10] = 11;
  v2[11] = 12;
  v2[12] = 12;
  v2[13] = 0;
  if ( ++missile[i]._miVar1 == missile[i]._miAnimLen )
  {
    SetMissDir(i, 1);
    missile[i]._miAnimFrame = random(82, 11) + 1;
  }
  missile[i]._mitxoff += missile[i]._mixvel;
  missile[i]._mityoff += missile[i]._miyvel;
  GetMissilePos(i);
  v3 = missile[i]._mirange;
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 1, missile[i]._mix, missile[i]._miy, 0);
  if ( missile[i]._miHitFlag == 1 )
    missile[i]._mirange = v3;
  if ( !missile[i]._mirange )
  {
    missile[i]._miDelFlag = 1;
    AddUnLight(missile[i]._mlid);
  }
  if ( !missile[i]._mimfnum && missile[i]._mirange )
  {
    if ( !missile[i]._miVar2 )
      missile[i]._mlid = AddLight(missile[i]._mix, missile[i]._miy, v2[missile[i]._miVar2]);
    ChangeLight(missile[i]._mlid, missile[i]._mix, missile[i]._miy, v2[missile[i]._miVar2]);
    ++missile[i]._miVar2;
  }
  PutMissile(i);
}

//----- (00446CE2) --------------------------------------------------------
void __fastcall MI_Guardian(int i)
{
  ;
}

//----- (00446CF8) --------------------------------------------------------
void __fastcall MI_Chain(int i)
{
  int midir; // ST34_4
  int v2; // ST30_4
  int v3; // ST34_4
  int id; // [esp+10h] [ebp-70h]
  signed int j; // [esp+1Ch] [ebp-64h]
  int y1; // [esp+20h] [ebp-60h]
  int v8; // [esp+24h] [ebp-5Ch]
  int x1; // [esp+28h] [ebp-58h]
  int k; // [esp+2Ch] [ebp-54h]
  int v11[19]; // [esp+30h] [ebp-50h]
  int v12; // [esp+7Ch] [ebp-4h]

  v11[0] = 0;
  v11[1] = 3;
  v11[2] = 12;
  v11[3] = 45;
  v11[4] = 94;
  v11[5] = 159;
  v11[6] = 240;
  v11[7] = 337;
  v11[8] = 450;
  v11[9] = 579;
  v11[10] = 724;
  v11[11] = 885;
  v11[12] = 1062;
  v11[13] = 1255;
  v11[14] = 1464;
  v11[15] = 1689;
  v11[16] = 1930;
  v11[17] = 2187;
  v11[18] = 2460;
  id = missile[i]._misource;
  x1 = missile[i]._mix;
  y1 = missile[i]._miy;
  midir = GetDirection(missile[i]._mix, missile[i]._miy, missile[i]._miVar1, missile[i]._miVar2);
  AddMissile(x1, y1, missile[i]._miVar1, missile[i]._miVar2, midir, 7, 0, id, 1);
  v12 = GetSpellLevel(id, 14) + 3;
  if ( v12 > 19 )
    v12 = 19;
  for ( j = 1; v12 > j; ++j )
  {
    v2 = v11[j];
    v8 = v2 + 1;
    for ( k = (unsigned __int8)CrawlTable[v2]; k > 0; --k )
    {
      if ( dMonster[x1 + CrawlTable[v8]][y1 + CrawlTable[v8 + 1]] > 0 )
      {
        v3 = GetDirection(x1, y1, x1 + CrawlTable[v8], y1 + CrawlTable[v8 + 1]);
        AddMissile(x1, y1, x1 + CrawlTable[v8], y1 + CrawlTable[v8 + 1], v3, 7, 0, id, 1);
      }
      v8 += 2;
    }
  }
  if ( !--missile[i]._mirange )
    missile[i]._miDelFlag = 1;
}

//----- (00446FB3) --------------------------------------------------------
void __fastcall mi_null_11(int i)
{
  if ( !--missile[i]._mirange )
    missile[i]._miDelFlag = 1;
  if ( missile[i]._miAnimFrame == missile[i]._miAnimLen )
    missile[i]._miPreFlag = 1;
  PutMissile(i);
}

//----- (00447064) --------------------------------------------------------
void __fastcall MI_Weapexp(int i)
{
  int v2[10]; // [esp+10h] [ebp-34h]
  int v3; // [esp+38h] [ebp-Ch]
  int maxdam; // [esp+3Ch] [ebp-8h]
  int mindam; // [esp+40h] [ebp-4h]

  v2[0] = 9;
  v2[1] = 10;
  v2[2] = 11;
  v2[3] = 12;
  v2[4] = 11;
  v2[5] = 10;
  v2[6] = 8;
  v2[7] = 6;
  v2[8] = 4;
  v2[9] = 2;
  --missile[i]._mirange;
  v3 = missile[i]._misource;
  mindam = plr[v3]._pIMinDam;
  maxdam = plr[v3]._pIMaxDam;
  CheckMissileCol(i, mindam, maxdam, 0, missile[i]._mix, missile[i]._miy, 0);
  if ( missile[i]._miVar1 )
  {
    if ( missile[i]._mirange )
      ChangeLight(missile[i]._mlid, missile[i]._mix, missile[i]._miy, v2[missile[i]._miVar1]);
  }
  else
  {
    missile[i]._mlid = AddLight(missile[i]._mix, missile[i]._miy, v2[missile[i]._miVar1]);
  }
  ++missile[i]._miVar1;
  if ( missile[i]._mirange )
  {
    PutMissile(i);
  }
  else
  {
    missile[i]._miDelFlag = 1;
    AddUnLight(missile[i]._mlid);
  }
}

//----- (004472D7) --------------------------------------------------------
void __fastcall MI_Misexp(int i)
{
  int v2[10]; // [esp+10h] [ebp-28h]

  v2[0] = 9;
  v2[1] = 10;
  v2[2] = 11;
  v2[3] = 12;
  v2[4] = 11;
  v2[5] = 10;
  v2[6] = 8;
  v2[7] = 6;
  v2[8] = 4;
  v2[9] = 2;
  if ( --missile[i]._mirange )
  {
    if ( missile[i]._miVar1 )
    {
      if ( missile[i]._mirange )
        ChangeLight(missile[i]._mlid, missile[i]._mix, missile[i]._miy, v2[missile[i]._miVar1]);
    }
    else
    {
      missile[i]._mlid = AddLight(missile[i]._mix, missile[i]._miy, v2[missile[i]._miVar1]);
    }
    ++missile[i]._miVar1;
    PutMissile(i);
  }
  else
  {
    missile[i]._miDelFlag = 1;
    AddUnLight(missile[i]._mlid);
  }
}

//----- (004474B3) --------------------------------------------------------
void __fastcall MI_Acidsplat(int i)
{
  if ( --missile[i]._mirange )
  {
    PutMissile(i);
  }
  else
  {
    missile[i]._miDelFlag = 1;
    AddMissile(
      missile[i]._mix,
      missile[i]._miy,
      i,
      0,
      missile[i]._mimfnum,
      59,
      1,
      missile[i]._misource,
      monster[missile[i]._misource].MData->mLevel + 1);
  }
}

//----- (004475BD) --------------------------------------------------------
void __fastcall MI_Teleport(int i)
{
  int v2; // [esp+10h] [ebp-4h]

  v2 = missile[i]._misource;
  if ( --missile[i]._mirange > 0 )
  {
    if ( !missile[i]._miVar1 )
    {
      dPlayer[plr[v2].WorldX][plr[v2].WorldY] = 0;
      PlrClrTrans(plr[v2].WorldX, plr[v2].WorldY);
      plr[v2].WorldX = missile[i]._mix;
      plr[v2].WorldY = missile[i]._miy;
      plr[v2]._px = plr[v2].WorldX;
      plr[v2]._py = plr[v2].WorldY;
      PlrDoTrans(plr[v2].WorldX, plr[v2].WorldY);
      missile[i]._miVar1 = 1;
      dPlayer[plr[v2].WorldX][plr[v2].WorldY] = v2 + 1;
      if ( leveltype )
      {
        ChangeLightXY(plr[v2]._plid, plr[v2].WorldX, plr[v2].WorldY);
        ChangeVisionXY(plr[v2]._pvid, plr[v2].WorldX, plr[v2].WorldY);
      }
      if ( myplr == v2 )
      {
        ViewX = plr[v2].WorldX - Scrollinfo._sdx;
        ViewY = plr[v2].WorldY - Scrollinfo._sdy;
      }
    }
  }
  else
  {
    missile[i]._miDelFlag = 1;
  }
}

//----- (00447989) --------------------------------------------------------
void __fastcall MI_Stone(int i)
{
  int v2; // [esp+10h] [ebp-4h]

  --missile[i]._mirange;
  v2 = missile[i]._miVar2;
  if ( !monster[v2]._mhitpoints && missile[i]._miAnimType != 18 )
  {
    SetMissAnim(i, 18);
    missile[i]._mirange = 11;
  }
  if ( monster[v2]._mmode != 15 )
    missile[i]._miDelFlag = 1;
  if ( !missile[i]._mirange )
  {
    missile[i]._miDelFlag = 1;
    if ( monster[v2]._mhitpoints <= 0 )
      AddDead(monster[v2]._mx, monster[v2]._my, stonendx, monster[v2]._mdir);
    else
      monster[v2]._mmode = missile[i]._miVar1;
  }
  if ( missile[i]._miAnimType == 18 )
    PutMissile(i);
}

//----- (00447B4F) --------------------------------------------------------
void __fastcall MI_Boom(int i)
{
  --missile[i]._mirange;
  if ( !missile[i]._miVar1 )
    CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix, missile[i]._miy, 1u);
  if ( missile[i]._miHitFlag == 1 )
    missile[i]._miVar1 = 1;
  if ( !missile[i]._mirange )
    missile[i]._miDelFlag = 1;
  PutMissile(i);
}

//----- (00447C6B) --------------------------------------------------------
void __fastcall MI_Rhino(int i)
{
  int v1; // ST24_4
  int v2; // ST1C_4
  int v4; // [esp+10h] [ebp-18h]
  int y; // [esp+1Ch] [ebp-Ch]
  int x; // [esp+24h] [ebp-4h]

  GetMissilePos(i);
  x = missile[i]._mix;
  y = missile[i]._miy;
  dMonster[x][y] = 0;
  missile[i]._mitxoff += missile[i]._mixvel;
  missile[i]._mityoff += missile[i]._miyvel;
  GetMissilePos(i);
  v4 = missile[i]._misource;
  v1 = missile[i]._mix;
  v2 = missile[i]._miy;
  if ( PosOkMonst(missile[i]._misource, missile[i]._mix, missile[i]._miy) )
  {
    dMonster[missile[i]._mix][missile[i]._miy] = -(v4 + 1);
    if ( monster[v4]._uniqtype )
      ChangeLightXY(monster[v4].mlid, monster[v4]._mx, monster[v4]._my);
    MoveMissilePos(i);
    PutMissile(i);
  }
  else
  {
    MissToMonst(i, x, y);
    missile[i]._miDelFlag = 1;
  }
}

//----- (00447EAE) --------------------------------------------------------
void __fastcall mi_null_32(int i)
{
  int v2; // [esp+10h] [ebp-28h]
  int v3; // [esp+14h] [ebp-24h]
  int v4; // [esp+18h] [ebp-20h]
  int v5; // [esp+20h] [ebp-18h]
  int y; // [esp+24h] [ebp-14h]
  int v7; // [esp+28h] [ebp-10h]
  int x; // [esp+2Ch] [ebp-Ch]
  int v9; // [esp+30h] [ebp-8h]
  int v10; // [esp+34h] [ebp-4h]

  GetMissilePos(i);
  x = missile[i]._mix;
  y = missile[i]._miy;
  missile[i]._mitxoff += missile[i]._mixvel;
  missile[i]._mityoff += missile[i]._miyvel;
  GetMissilePos(i);
  v4 = missile[i]._misource;
  v7 = missile[i]._mix;
  v5 = missile[i]._miy;
  v10 = monster[v4]._menemy;
  if ( monster[v4]._mFlags & 0x10 )
  {
    v2 = monster[v10]._mx;
    v9 = monster[v10]._my;
  }
  else
  {
    v2 = plr[v10].WorldX;
    v9 = plr[v10].WorldY;
  }
  if ( (x != v7 || y != v5)
    && (missile[i]._miVar1 & 1 && (abs(x - v2) >= 4 || abs(y - v9) >= 4) || missile[i]._miVar2 > 1)
    && PosOkMonst(missile[i]._misource, x, y) )
  {
    MissToMonst(i, x, y);
    missile[i]._miDelFlag = 1;
  }
  else if ( monster[v4]._mFlags & 0x10 )
  {
    v3 = dMonster[v7][v5];
  }
  else
  {
    v3 = dPlayer[v7][v5];
  }
  if ( !PosOkMissile(v7, v5) || v3 > 0 && !(missile[i]._miVar1 & 1) )
  {
    missile[i]._mixvel = -missile[i]._mixvel;
    missile[i]._miyvel = -missile[i]._miyvel;
    missile[i]._mimfnum = opposite[missile[i]._mimfnum];
    missile[i]._miAnimData = monster[v4].MType->Anims[1].Frames[missile[i]._mimfnum];
    ++missile[i]._miVar2;
    if ( v3 > 0 )
      missile[i]._miVar1 |= 1u;
  }
  MoveMissilePos(i);
  PutMissile(i);
}

//----- (004482DD) --------------------------------------------------------
void __fastcall MI_FirewallC(int i)
{
  int v2; // [esp+10h] [ebp-8h]
  int v3; // [esp+10h] [ebp-8h]
  int v4; // [esp+14h] [ebp-4h]
  int v5; // [esp+14h] [ebp-4h]

  if ( --missile[i]._mirange )
  {
    v2 = missile[i]._miVar1 + XDirAdd[missile[i]._miVar3];
    v4 = missile[i]._miVar2 + YDirAdd[missile[i]._miVar3];
    if ( !(dFlags[v2][v4] & 0x40) || missile[i]._miVar8 )
    {
      missile[i]._miVar8 = 1;
    }
    else
    {
      AddMissile(
        missile[i]._miVar1,
        missile[i]._miVar2,
        missile[i]._miVar1,
        missile[i]._miVar2,
        plr[myplr]._pdir,
        5,
        0,
        myplr,
        0);
      missile[i]._miVar1 = v2;
      missile[i]._miVar2 = v4;
    }
    v3 = missile[i]._miVar5 + XDirAdd[missile[i]._miVar4];
    v5 = missile[i]._miVar6 + YDirAdd[missile[i]._miVar4];
    if ( !(dFlags[v3][v5] & 0x40) || missile[i]._miVar7 )
    {
      missile[i]._miVar7 = 1;
    }
    else
    {
      AddMissile(
        missile[i]._miVar5,
        missile[i]._miVar6,
        missile[i]._miVar5,
        missile[i]._miVar6,
        plr[myplr]._pdir,
        5,
        0,
        myplr,
        0);
      missile[i]._miVar5 = v3;
      missile[i]._miVar6 = v5;
    }
  }
  else
  {
    missile[i]._miDelFlag = 1;
  }
}

//----- (00448634) --------------------------------------------------------
void __fastcall MI_Infra(int i)
{
  --missile[i]._mirange;
  plr[missile[i]._misource]._pInfraFlag = 1;
  if ( !missile[i]._mirange )
  {
    missile[i]._miDelFlag = 1;
    CalcPlrItemVals(missile[i]._misource, 1);
  }
}

//----- (004486E6) --------------------------------------------------------
void __fastcall MI_Apoca(int i)
{
  ;
}

//----- (004486FC) --------------------------------------------------------
void __fastcall MI_Wave(int i)
{
  signed int v2; // [esp+10h] [ebp-40h]
  int v3; // [esp+18h] [ebp-38h]
  int id; // [esp+1Ch] [ebp-34h]
  int v5; // [esp+24h] [ebp-2Ch]
  int v6; // [esp+28h] [ebp-28h]
  int sx; // [esp+2Ch] [ebp-24h]
  int sxa; // [esp+2Ch] [ebp-24h]
  int y1; // [esp+30h] [ebp-20h]
  int x1; // [esp+34h] [ebp-1Ch]
  int j; // [esp+38h] [ebp-18h]
  int v12; // [esp+3Ch] [ebp-14h]
  int v13; // [esp+44h] [ebp-Ch]
  int sy; // [esp+48h] [ebp-8h]
  int sya; // [esp+48h] [ebp-8h]
  signed int v16; // [esp+4Ch] [ebp-4h]

  v2 = 0;
  v16 = 0;
  id = missile[i]._misource;
  x1 = missile[i]._mix;
  y1 = missile[i]._miy;
  v12 = GetDirection(missile[i]._mix, missile[i]._miy, missile[i]._miVar1, missile[i]._miVar2);
  v5 = ((_BYTE)v12 - 2) & 7;
  v3 = ((_BYTE)v12 + 2) & 7;
  sx = x1 + XDirAdd[v12];
  sy = y1 + YDirAdd[v12];
  if ( !nSolidTable[dPiece[sx][sy]] )
  {
    AddMissile(sx, sy, sx + XDirAdd[v12], sy + YDirAdd[v12], plr[id]._pdir, 14, 0, id, 0);
    sxa = XDirAdd[v5] + sx;
    sya = YDirAdd[v5] + sy;
    v6 = x1 + XDirAdd[v3] + XDirAdd[v12];
    v13 = y1 + YDirAdd[v3] + YDirAdd[v12];
    for ( j = 0; GetSpellLevel(id, 15) + 2 > j; ++j )
    {
      if ( nSolidTable[dPiece[sxa][sya]] || v2 )
      {
        v2 = 1;
      }
      else
      {
        AddMissile(sxa, sya, sxa + XDirAdd[v12], sya + YDirAdd[v12], plr[id]._pdir, 14, 0, id, 0);
        sxa += XDirAdd[v5];
        sya += YDirAdd[v5];
      }
      if ( nSolidTable[dPiece[v6][v13]] || v16 )
      {
        v16 = 1;
      }
      else
      {
        AddMissile(v6, v13, v6 + XDirAdd[v12], v13 + YDirAdd[v12], plr[id]._pdir, 14, 0, id, 0);
        v6 += XDirAdd[v3];
        v13 += YDirAdd[v3];
      }
    }
  }
  if ( !--missile[i]._mirange )
    missile[i]._miDelFlag = 1;
}

//----- (00448A7F) --------------------------------------------------------
void __fastcall MI_Nova(int i)
{
  int v1; // ST34_4
  int v2; // ST2C_4
  int id; // [esp+14h] [ebp-28h]
  int midir; // [esp+1Ch] [ebp-20h]
  int sy; // [esp+20h] [ebp-1Ch]
  signed int j; // [esp+24h] [ebp-18h]
  int sx; // [esp+28h] [ebp-14h]
  int micaster; // [esp+2Ch] [ebp-10h]
  int v3; // [esp+30h] [ebp-Ch]
  int v11; // [esp+34h] [ebp-8h]
  int v12; // [esp+38h] [ebp-4h]

  v11 = 0;
  v12 = 0;
  id = missile[i]._misource;
  v3 = missile[i]._midam;
  sx = missile[i]._mix;
  sy = missile[i]._miy;
  v1 = missile[i]._miVar1;
  v2 = missile[i]._miVar2;
  if ( id == -1 )
  {
    midir = 0;
    micaster = 1;
  }
  else
  {
    midir = plr[id]._pdir;
    micaster = 0;
  }
  for ( j = 0; j < 23; ++j )
  {
    if ( vCrawlTable[j][6] != v12 || vCrawlTable[j][7] != v11 )
    {
      AddMissile(sx, sy, sx + vCrawlTable[j][6], sy + vCrawlTable[j][7], midir, 4, micaster, id, v3);
      AddMissile(sx, sy, sx - vCrawlTable[j][6], sy - vCrawlTable[j][7], midir, 4, micaster, id, v3);
      AddMissile(sx, sy, sx - vCrawlTable[j][6], sy + vCrawlTable[j][7], midir, 4, micaster, id, v3);
      AddMissile(sx, sy, sx + vCrawlTable[j][6], sy - vCrawlTable[j][7], midir, 4, micaster, id, v3);
      v12 = vCrawlTable[j][6];
      v11 = vCrawlTable[j][7];
    }
  }
  if ( !--missile[i]._mirange )
    missile[i]._miDelFlag = 1;
}

//----- (00448D8E) --------------------------------------------------------
void __fastcall MI_Blodboil(int i)
{
  int v1; // eax
  int pnum; // [esp+14h] [ebp-10h]
  int j; // [esp+1Ch] [ebp-8h]
  int ia; // [esp+20h] [ebp-4h]
  int ib; // [esp+20h] [ebp-4h]

  pnum = missile[i]._misource;
  ia = dMonster[missile[i]._miVar1][missile[i]._miVar2];
  if ( ia <= 0 )
    ib = -(ia + 1);
  else
    ib = ia - 1;
  if ( ib > 0 )
  {
    monster[ib]._mhitpoints = 0;
    M_StartKill(ib, pnum);
    AddPlrExperience(pnum, monster[ib].mLevel, (unsigned __int16)monster[ib].mExp);
    dMonster[monster[ib]._mx][monster[ib]._my] = 0;
    monster[ib]._mDelFlag = 1;
    v1 = random(87, 2);
    AddMissile(monster[ib]._mx, monster[ib]._my, monster[ib]._mx, monster[ib]._my, plr[pnum]._pdir, 35, 0, pnum, v1 + 1);
    AddDead(monster[ib]._mx, monster[ib]._my, spurtndx, monster[ib]._mdir);
    plr[pnum]._pHitPoints -= monster[ib]._mmaxhp;
    plr[pnum]._pHPBase -= monster[ib]._mmaxhp;
    for ( j = GetSpellLevel(pnum, 22); j > 0; --j )
    {
      plr[pnum]._pHitPoints += monster[ib]._mmaxhp >> 3;
      plr[pnum]._pHPBase += monster[ib]._mmaxhp >> 3;
    }
    if ( plr[pnum]._pHitPoints > plr[pnum]._pMaxHP )
    {
      plr[pnum]._pHitPoints = plr[pnum]._pMaxHP;
      plr[pnum]._pHPBase = plr[pnum]._pMaxHPBase;
    }
    if ( plr[pnum]._pHitPoints > 0 )
    {
      StartPlrHit(pnum, monster[ib]._mmaxhp >> 3);
    }
    else
    {
      plr[pnum]._pHitPoints = 0;
      SyncPlrKill(pnum);
    }
    UseMana(pnum, 22);
  }
  if ( !--missile[i]._mirange )
    missile[i]._miDelFlag = 1;
}

//----- (00449225) --------------------------------------------------------
void __fastcall MI_Flame(int i)
{
  int id; // [esp+10h] [ebp-8h]
  int v3; // [esp+14h] [ebp-4h]

  id = missile[i]._misource;
  v3 = --missile[i]._mirange;
  CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 1, missile[i]._mix, missile[i]._miy, 0);
  if ( !missile[i]._mirange && missile[i]._miHitFlag == 1 )
    missile[i]._mirange = v3;
  if ( missile[i]._miVar1 == missile[i]._mirange )
  {
    SetMissAnim(i, 21);
    if ( missile[i]._miVar3 < 3 )
      AddMissile(
        missile[i]._mix,
        missile[i]._miy,
        plr[id].WorldX,
        plr[id].WorldY,
        missile[i]._mimfnum,
        48,
        0,
        id,
        ++missile[i]._miVar3);
  }
  if ( missile[i]._mirange == missile[i]._miVar2 )
  {
    SetMissAnim(i, 20);
    missile[i]._miAnimFrame = missile[i]._miAnimLen + 1;
    missile[i]._miAnimAdd = -1;
  }
  if ( !missile[i]._mirange )
    missile[i]._miDelFlag = 1;
  if ( missile[i]._miVar4 != plr[id].WorldX || missile[i]._miVar5 != plr[id].WorldY )
    missile[i]._miDelFlag = 1;
  PutMissile(i);
}

//----- (00449587) --------------------------------------------------------
void __fastcall MI_Flamec(int i)
{
  int id; // ST2C_4
  int midir; // ST30_4

  --missile[i]._mirange;
  id = missile[i]._misource;
  midir = GetDirection8(missile[i]._mix, missile[i]._miy, missile[i]._miVar1, missile[i]._miVar2);
  AddMissile(missile[i]._mix, missile[i]._miy, plr[id].WorldX, plr[id].WorldY, midir, 48, 0, id, 1);
  if ( !missile[i]._mirange )
    missile[i]._miDelFlag = 1;
}

//----- (004496D6) --------------------------------------------------------
void __fastcall MI_Cbolt(int i)
{
  int v1; // ST2C_4
  int v3[16]; // [esp+24h] [ebp-40h]

  v3[0] = -1;
  v3[1] = 0;
  v3[2] = 1;
  v3[3] = -1;
  v3[4] = 0;
  v3[5] = 1;
  v3[6] = -1;
  v3[7] = -1;
  v3[8] = 0;
  v3[9] = 0;
  v3[10] = 1;
  v3[11] = 1;
  v3[12] = 0;
  v3[13] = 1;
  v3[14] = -1;
  v3[15] = 0;
  --missile[i]._mirange;
  if ( missile[i]._miAnimType != 3 )
  {
    if ( missile[i]._miVar3 )
    {
      --missile[i]._miVar3;
    }
    else
    {
      v1 = (missile[i]._miVar2 + v3[missile[i]._mirnd]) & 7;
      missile[i]._mirnd = ((unsigned __int8)missile[i]._mirnd + 1) & 0xF;
      GetMissileVel(
        i,
        missile[i]._mix,
        missile[i]._miy,
        missile[i]._mix + XDirAdd[v1],
        missile[i]._miy + YDirAdd[v1],
        8);
      missile[i]._miVar3 = 16;
    }
    missile[i]._mitxoff += missile[i]._mixvel;
    missile[i]._mityoff += missile[i]._miyvel;
    GetMissilePos(i);
    CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix, missile[i]._miy, 0);
    if ( missile[i]._miHitFlag == 1 )
    {
      missile[i]._miVar1 = 8;
      missile[i]._mimfnum = 0;
      missile[i]._mixoff = 0;
      missile[i]._miyoff = 0;
      SetMissAnim(i, 3);
      missile[i]._mirange = missile[i]._miAnimLen;
      GetMissilePos(i);
    }
    ChangeLight(missile[i]._mlid, missile[i]._mix, missile[i]._miy, missile[i]._miVar1);
  }
  if ( !missile[i]._mirange )
  {
    missile[i]._miDelFlag = 1;
    AddUnLight(missile[i]._mlid);
  }
  PutMissile(i);
}

//----- (00449ADB) --------------------------------------------------------
void __fastcall MI_Hbolt(int i)
{
  int v1; // ebx
  int mindam; // [esp+10h] [ebp-4h]

  --missile[i]._mirange;
  if ( missile[i]._miAnimType == 29 )
  {
    ChangeLight(missile[i]._mlid, missile[i]._mix, missile[i]._miy, missile[i]._miAnimFrame + 7);
    if ( !missile[i]._mirange )
    {
      missile[i]._miDelFlag = 1;
      AddUnLight(missile[i]._mlid);
    }
  }
  else
  {
    missile[i]._mitxoff += missile[i]._mixvel;
    missile[i]._mityoff += missile[i]._miyvel;
    GetMissilePos(i);
    v1 = random(76, 10);
    mindam = random(76, 10) + v1 + 2;
    if ( missile[i]._mix != missile[i]._misx || missile[i]._miy != missile[i]._misy )
      CheckMissileCol(i, mindam, mindam, 0, missile[i]._mix, missile[i]._miy, 0);
    if ( missile[i]._mirange )
    {
      if ( missile[i]._mix != missile[i]._miVar1 || missile[i]._miy != missile[i]._miVar2 )
      {
        missile[i]._miVar1 = missile[i]._mix;
        missile[i]._miVar2 = missile[i]._miy;
        ChangeLight(missile[i]._mlid, missile[i]._miVar1, missile[i]._miVar2, 8);
      }
    }
    else
    {
      missile[i]._mitxoff -= missile[i]._mixvel;
      missile[i]._mityoff -= missile[i]._miyvel;
      GetMissilePos(i);
      missile[i]._mimfnum = 0;
      SetMissAnim(i, 29);
      missile[i]._mirange = missile[i]._miAnimLen - 1;
    }
  }
  PutMissile(i);
}

//----- (00449ED4) --------------------------------------------------------
void __fastcall MI_Element(int i)
{
  --missile[i]._mirange;
  missile[i]._mitxoff += missile[i]._mixvel;
  missile[i]._mityoff += missile[i]._miyvel;
  GetMissilePos(i);
  if ( missile[i]._mix != missile[i]._misx || missile[i]._miy != missile[i]._misy )
    CheckMissileCol(i, missile[i]._midam, missile[i]._midam, 0, missile[i]._mix, missile[i]._miy, 0);
  if ( missile[i]._mix != missile[i]._miVar1 || missile[i]._miy != missile[i]._miVar2 )
  {
    missile[i]._miVar1 = missile[i]._mix;
    missile[i]._miVar2 = missile[i]._miy;
    ChangeLight(missile[i]._mlid, missile[i]._miVar1, missile[i]._miVar2, 8);
  }
  if ( !missile[i]._mirange )
  {
    missile[i]._miDelFlag = 1;
    AddUnLight(missile[i]._mlid);
  }
  PutMissile(i);
}

//----- (0044A170) --------------------------------------------------------
void __fastcall MI_ResurrectBeam(int i)
{
  if ( !--missile[i]._mirange )
    missile[i]._miDelFlag = 1;
  PutMissile(i);
}

//----- (0044A1D8) --------------------------------------------------------
void __cdecl ProcessMissiles()
{
  int v0; // ebx
  int j; // [esp+Ch] [ebp-8h]
  int k; // [esp+Ch] [ebp-8h]
  int l; // [esp+Ch] [ebp-8h]
  int v4; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]
  int ia; // [esp+10h] [ebp-4h]
  int ib; // [esp+10h] [ebp-4h]

  for ( j = 0; nummissiles > j; ++j )
  {
    v0 = missileactive[j];
    dFlags[missile[v0]._mix][missile[v0]._miy] &= 0xFEu;
    dMissile[missile[v0]._mix][missile[v0]._miy] = 0;
  }
  MissilePreFlag = 0;
  ManashieldFlag = 0;
  for ( k = 0; nummissiles > k; ++k )
  {
    i = missileactive[k];
    missiledata[missile[i]._mitype].mProc(missileactive[k]);
    if ( !(missile[i]._miAnimFlags & 2) && ++missile[i]._miAnimCnt >= missile[i]._miAnimDelay )
    {
      missile[i]._miAnimCnt = 0;
      missile[i]._miAnimFrame += missile[i]._miAnimAdd;
      if ( missile[i]._miAnimLen < missile[i]._miAnimFrame )
        missile[i]._miAnimFrame = 1;
      if ( missile[i]._miAnimFrame < 1 )
        missile[i]._miAnimFrame = missile[i]._miAnimLen;
    }
  }
  if ( ManashieldFlag )
  {
    for ( l = 0; nummissiles > l; ++l )
    {
      ia = missileactive[l];
      if ( missile[ia]._mitype == 13 )
        MI_Manashield(ia);
    }
  }
  v4 = 0;
  while ( nummissiles > v4 )
  {
    ib = missileactive[v4];
    if ( missile[ib]._miDelFlag )
    {
      DeleteMissile(ib, v4);
      v4 = 0;
    }
    else
    {
      ++v4;
    }
  }
}

