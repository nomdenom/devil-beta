#include "defs.h"
// Forward declarations
enum MON_MODE;
struct MonsterStruct;
struct AnimStruct;
struct CMonster;
struct MonsterData;
enum _object_id;
struct ObjectStruct;
struct ObjDataStruct;
struct QuestStruct;
struct QuestData;
struct TownerStruct;
struct TSnd;
struct UniqMonstStruct;
struct TriggerStruct;
struct ItemStruct;
struct PlayerStruct;
struct MissileStruct;
struct MissileData;
struct MisFileData;
struct PATHNODE;
struct SpellData;
enum item_effect_type;
struct ItemDataStruct;
struct PLStruct;
struct UItemStruct;
struct TCmdPlrInfoHdr;
struct STextStruct;
struct Coord;
struct _plrmsg;
struct TMPQHeader;
struct TMPQHeader_buffer;
struct _uiheroinfo;
struct _uidefaultstats;
struct PkItemStruct;
struct PkPlayerStruct;
struct LightListStruct;
struct InvXY;
struct DeadStruct;
struct TSFX;
struct ScrollStruct;
enum PLR_MODE;
enum _cmd_id;
enum enum_1;
struct TMenuItem;
struct ROOMNODE;
struct HALLNODE;
struct ThemeStruct;
struct THEME_LOC;
struct SHA1Context;
struct TSyncHeader;
struct TSyncMonster;
struct PortalStruct;
struct TMegaPkt;
struct DMonsterStr;
struct TCmdPItem;
struct DObjectStr;
struct DLevel;
struct DPortal;
struct DJunk;
struct TCmdGItem;
enum missile_id;
struct XHelpStruct;
struct XHelpStruct2;
// Types
struct MonsterStruct
{
  int _mMTidx;
  MON_MODE _mmode;
  char _mgoal;
  int _mgoalvar1;
  int _mgoalvar2;
  int _mgoalvar3;
  _BYTE gap18[4];
  int _mx;
  int _my;
  int _mfutx;
  int _mfuty;
  int _moldx;
  int _moldy;
  int _mxoff;
  int _myoff;
  int _mxvel;
  int _myvel;
  int _mdir;
  int _menemy;
  BYTE *_mAnimData;
  int _mAnimDelay;
  int _mAnimCnt;
  int _mAnimLen;
  int _mAnimFrame;
  int _meflag;
  int _mDelFlag;
  int _mVar1;
  int _mVar2;
  int _mVar3;
  int _mVar4;
  int _mVar5;
  int _mVar6;
  int _mVar7;
  int _mVar8;
  int _mmaxhp;
  int _mhitpoints;
  BYTE mAi;
  BYTE _mint;
  int _mFlags;
  BYTE _msquelch;
  _BYTE gap99[7];
  int _lastx;
  int _lasty;
  int _mRndSeed;
  int _mAISeed;
  _BYTE gapB0[4];
  BYTE _uniqtype;
  char _uniqtrans;
  char _udeadval;
  char mWhoHit;
  char mLevel;
  __int16 mExp;
  BYTE mHit;
  BYTE mMinDamage;
  BYTE mMaxDamage;
  BYTE mHit2;
  BYTE mMinDamage2;
  BYTE mMaxDamage2;
  char mArmorClass;
  __int16 mMagicRes;
  char field_C6;
  int mtalkmsg;
  BYTE leader;
  char leaderflag;
  BYTE packsize;
  BYTE mlid;
  char *mName;
  CMonster *MType;
  MonsterData *MData;
};

struct ObjectStruct
{
  _object_id _otype;
  int _ox;
  int _oy;
  int _oLight;
  int _oAnimFlag;
  void *_oAnimData;
  int _oAnimDelay;
  int _oAnimCnt;
  int _oAnimLen;
  int _oAnimFrame;
  int _oAnimWidth;
  int _oAnimWidth2;
  int _oDelFlag;
  char _oBreak;
  int _oSolidFlag;
  int _oMissFlag;
  char _oSelFlag;
  char field_41;
  char field_42;
  char field_43;
  int _oPreFlag;
  int _oTrapFlag;
  int _oDoorFlag;
  int _olid;
  int _oRndSeed;
  int _oVar1;
  int _oVar2;
  int _oVar3;
  int _oVar4;
  int _oVar5;
  int _oVar6;
  int _oVar7;
  int _oVar8;
};

struct ObjDataStruct
{
  char oload;
  char ofindex;
  char ominlvl;
  char omaxlvl;
  char olvltype;
  char otheme;
  char oquest;
  int oAnimFlag;
  int oAnimDelay;
  int oAnimLen;
  int oAnimWidth;
  int oSolidFlag;
  int oMissFlag;
  int oLightFlag;
  char oBreak;
  char oSelFlag;
  int oTrapFlag;
};

struct QuestStruct
{
  BYTE _qlevel;
  char _qtype;
  char _qactive;
  BYTE _qlvltype;
  int _qtx;
  int _qty;
  BYTE _qslvl;
  BYTE _qidx;
  char _qvar1;
  char _qvar2;
};

struct QuestData
{
  char _qdlvl;
  char X_qdlvl_max;
  char _qlvlt;
  char _qdtype;
  BYTE _qdrnd;
  char _qslvl;
  int _qflags;
  char *_qlstr;
};

struct TownerStruct
{
  _BYTE gap0[4];
  int _ttype;
  int _tx;
  int _ty;
  _BYTE gap10[20];
  void *_tAnimData;
  int _tAnimDelay;
  int _tAnimCnt;
  int _tAnimLen;
  int _tAnimFrame;
  int _tAnimFrameCnt;
  char _tAnimOrder;
  int _tAnimWidth;
  int _tAnimWidth2;
  int _tTenPer;
  _BYTE gap4C[4];
  int _tbtcnt;
  int _tSelFlag;
  int _tMsgSaid;
  int _tVar1;
  int _tVar2;
  _BYTE gap64[8];
  char _tName[32];
  BYTE *_tNAnim[8];
  int _tNFrames;
  _BYTE gapB0[36];
  BYTE *_tNData;
  _BYTE gapD8[3];
  char field_end;
};

struct AnimStruct
{
  BYTE *CMem;
  unsigned __int8 *Frames[8];
  int Rate;
  int Delay;
};

struct CMonster
{
  unsigned __int8 mtype;
  unsigned __int8 mPlaceFlags;
  AnimStruct Anims[6];
  _BYTE gap10C[12];
  LPVOID Snds[2][5];
  _BYTE gap140[28];
  int flags_1;
  int flags_2;
  BYTE mMinHP;
  BYTE mMaxHP;
  int has_special;
  char mAFNum;
  char mdeadval;
  MonsterData *MData;
  char *trans_file;
};

struct TSnd
{
  WAVEFORMATEX fmt;
  int len;
  int offset;
  char *sound_path;
  IDirectSoundBuffer *DSB;
  int start_tc;
};

struct MonsterData
{
  int flags;
  int mType;
  char *GraphicType;
  int has_special;
  char *sndfile;
  int snd_special;
  int has_trans;
  char *TransFile;
  int Frames[6];
  int Rate[6];
  char *mName;
  char mMinDLvl;
  char mMaxDLvl;
  char mLevel;
  int mMinHP;
  int mMaxHP;
  char mAi;
  char mInt;
  unsigned __int8 mHit;
  unsigned __int8 mAFNum;
  unsigned __int8 mMinDamage;
  unsigned __int8 mMaxDamage;
  unsigned __int8 mHit2;
  unsigned __int8 mAFNum2;
  unsigned __int8 mMinDamage2;
  unsigned __int8 mMaxDamage2;
  char mArmorClass;
  char mMonstClass;
  unsigned __int16 mMagicRes;
  unsigned __int16 mMagicRes2;
  unsigned __int16 mSelFlag;
  unsigned __int16 mExp;
};

struct UniqMonstStruct
{
  char mtype;
  char *mName;
  char *mMode;
  unsigned __int8 mlevel;
  unsigned __int16 mmaxhp;
  unsigned __int8 mAi;
  unsigned __int8 mint;
  unsigned __int8 mMinDamage;
  unsigned __int8 mMaxDamage;
  unsigned __int16 mMagicRes;
  unsigned __int16 mUnqAttr;
  unsigned __int8 mUnqVar1;
  unsigned __int8 mUnqVar2;
  int mtalkmsg;
};

struct TriggerStruct
{
  int _tx;
  int _ty;
  int _tmsg;
  int _tlvl;
};

struct ItemStruct
{
  int _iSeed;
  unsigned __int16 _iCreateInfo;
  int _itype;
  int _ix;
  int _iy;
  int _iAnimFlag;
  unsigned __int8 *_iAnimData;
  int _iAnimLen;
  int _iAnimFrame;
  int _iAnimWidth;
  int _iAnimWidth2;
  int _isin;
  char _iSelFlag;
  int _iPostDraw;
  int _iIdentified;
  char _iMagical;
  char _iName[64];
  char _iIName[64];
  char _iLoc;
  char _iClass;
  int _iCurs;
  int _ivalue;
  int _iIvalue;
  int _iMinDam;
  int _iMaxDam;
  int _iAC;
  int _iFlags;
  int _iMiscId;
  int _iSpell;
  int _iCharges;
  int _iMaxCharges;
  int _iDurability;
  int _iMaxDur;
  int _iPLDam;
  int _iPLToHit;
  int _iPLAC;
  int _iPLStr;
  int _iPLMag;
  int _iPLDex;
  int _iPLVit;
  int _iPLFR;
  int _iPLLR;
  int _iPLMR;
  int _iPLMana;
  int _iPLHP;
  int _iPLDamMod;
  int _iPLGetHit;
  int _iPLLight;
  char _iSplLvlAdd;
  char _pISplCost;
  int _pISplDur;
  int _iFMinDam;
  int _iFMaxDam;
  int _iLMinDam;
  int _iLMaxDam;
  int _iPLEnAc;
  char _iPrePower;
  char _iSufPower;
  int _iVAdd1;
  int _iVMult1;
  int _iVAdd2;
  int _iVMult2;
  char _iMinStr;
  unsigned __int8 _iMinMag;
  char _iMinDex;
  int _iStatFlag;
  int IDidx;
  int Xgold_unused;
};

struct PlayerStruct
{
  int _pmode;
  char walkpath[25];
  unsigned __int8 plractive;
  int destAction;
  int destParam1;
  int destParam2;
  int plrlevel;
  int WorldX;
  int WorldY;
  int _px;
  int _py;
  int _ptargx;
  int _ptargy;
  int _pownerx;
  int _pownery;
  int _poldx;
  int _poldy;
  int _pxoff;
  int _pyoff;
  int _pxvel;
  int _pyvel;
  int _pdir;
  int _nextdir;
  int _pgfxnum;
  int _pAnimData;
  int _pAnimDelay;
  int _pAnimCnt;
  int _pAnimLen;
  int _pAnimFrame;
  int _pAnimWidth;
  int _pAnimWidth2;
  int _peflag;
  int _plid;
  int _pvid;
  int _pSpell;
  char _pSplType;
  char _pSplFrom;
  int _pTSpell;
  char _pTSplType;
  char field_A9;
  int _pRSpell;
  BYTE _pRSplType;
  int _pSBkSpell;
  char _pSBkSplType;
  char _pSplLvl[64];
  int remove_1;
  QWORD _pMemSpells;
  QWORD _pAblSpells;
  QWORD _pScrlSpells;
  char _pSpellFlags;
  int _pSplHotKey[4];
  char _pSplTHotKey[4];
  int _pwtype;
  unsigned __int8 _pBlockFlag;
  unsigned __int8 _pInvincible;
  char _pLightRad;
  unsigned __int8 _pLvlChanging;
  char _pName[32];
  char _pClass;
  int _pStrength;
  int _pBaseStr;
  int _pMagic;
  int _pBaseMag;
  int _pDexterity;
  int _pBaseDex;
  int _pVitality;
  int _pBaseVit;
  int _pStatPts;
  int _pDamageMod;
  int _pBaseToBlk;
  int _pHPBase;
  int _pMaxHPBase;
  int _pHitPoints;
  int _pMaxHP;
  int _pHPPer;
  int _pManaBase;
  int _pMaxManaBase;
  int _pMana;
  int _pMaxMana;
  int _pManaPer;
  char _pLevel;
  char _pMaxLvl;
  int _pExperience;
  int _pMaxExp;
  int _pNextExper;
  char _pArmorClass;
  char _pMagResist;
  char _pFireResist;
  char _pLghtResist;
  int _pGold;
  int _pInfraFlag;
  int _pVar1;
  int _pVar2;
  int _pVar3;
  int _pVar4;
  int _pVar5;
  int _pVar6;
  int _pVar7;
  int _pVar8;
  unsigned __int8 _pLvlVisited[17];
  unsigned __int8 _pSLvlVisited[10];
  char gap20F[9];
  int _pGFXLoad;
  int _pNAnim[8];
  int _pNFrames;
  int _pNWidth;
  int _pWAnim[8];
  int _pWFrames;
  int _pWWidth;
  int _pAAnim[8];
  int _pAFrames;
  int _pAWidth;
  int _pAFNum;
  int _pLAnim[8];
  int _pFAnim[8];
  int _pTAnim[8];
  int _pSFrames;
  int _pSWidth;
  int _pSFNum;
  int _pHAnim[8];
  int _pHFrames;
  int _pHWidth;
  int _pDAnim[8];
  int _pDFrames;
  int _pDWidth;
  int _pBAnim[8];
  int _pBFrames;
  int _pBWidth;
  ItemStruct InvBody[7];
  ItemStruct InvList[40];
  int _pNumInv;
  char InvGrid[40];
  ItemStruct SpdList[8];
  ItemStruct HoldItem;
  int _pIMinDam;
  int _pIMaxDam;
  int _pIAC;
  int _pIBonusDam;
  int _pIBonusToHit;
  int _pIBonusAC;
  int _pIBonusDamMod;
  int remove_2;
  QWORD _pISpells;
  int _pIFlags;
  int _pIGetHit;
  char _pISplLvlAdd;
  char _pISplCost;
  int _pISplDur;
  int _pIEnAc;
  int _pIFMinDam;
  int _pIFMaxDam;
  int _pILMinDam;
  int _pILMaxDam;
  int _pOilType;
  void *_pNData;
  void *_pWData;
  void *_pAData;
  void *_pLData;
  void *_pFData;
  void *_pTData;
  void *_pHData;
  void *_pDData;
  void *_pBData;
  int unused_54D4;
};

struct MissileStruct
{
  int _mitype;
  int _mix;
  int _miy;
  int _mixoff;
  int _miyoff;
  int _mixvel;
  int _miyvel;
  int _misx;
  int _misy;
  int _mitxoff;
  int _mityoff;
  int _mimfnum;
  int _miDelFlag;
  BYTE _miAnimType;
  int _miAnimFlags;
  unsigned __int8 *_miAnimData;
  int _miAnimDelay;
  int _miAnimLen;
  int _miAnimWidth;
  int _miAnimWidth2;
  int _miAnimCnt;
  int _miAnimAdd;
  int _miAnimFrame;
  int _miDrawFlag;
  int _miLightFlag;
  int _miPreFlag;
  int _miUniqTrans;
  int _mirange;
  int _misource;
  int _micaster;
  int _midam;
  int _miHitFlag;
  int _midist;
  int _mlid;
  int _mirnd;
  int _miVar1;
  int _miVar2;
  int _miVar3;
  int _miVar4;
  int _miVar5;
  int _miVar6;
  int _miVar7;
  int _miVar8;
};

struct MissileData
{
  unsigned __int8 mName;
  void (__fastcall *mAddProc)(int, int, int, int, int, int, int, int, int);
  void (__fastcall *mProc)(int);
  int mDraw;
  unsigned __int8 mType;
  unsigned __int8 mResist;
  unsigned __int8 mFileNum;
  int mlSFX;
  int miSFX;
};

struct MisFileData
{
  unsigned __int8 mAnimName;
  unsigned __int8 mAnimFAmt;
  char *mName;
  int mFlags;
  unsigned __int8 *mAnimData[16];
  unsigned __int8 mAnimDelay[16];
  unsigned __int8 mAnimLen[16];
  int mAnimWidth[16];
  int mAnimWidth2[16];
};

struct PATHNODE
{
  char f;
  char h;
  char g;
  int x;
  int y;
  struct PATHNODE *Parent;
  struct PATHNODE *Child[8];
  PATHNODE *NextNode;
};

struct SpellData
{
  unsigned __int8 sName;
  unsigned __int8 sManaCost;
  unsigned __int8 sType;
  char *sNameText;
  char *sSkillText;
  int sBookLvl;
  int sStaffLvl;
  int sTargeted;
  unsigned __int8 sTownSpell;
  char _sSFX;
  char _sMissiles[3];
  unsigned __int8 sManaAdj;
};

enum item_effect_type
{
  IPL_TOHIT = 0x0,
  IPL_TOHIT_CURSE = 0x1,
  IPL_DAMP = 0x2,
  IPL_DAMP_CURSE = 0x3,
  IPL_TOHIT_DAMP = 0x4,
  IPL_TOHIT_DAMP_CURSE = 0x5,
  IPL_ACP = 0x6,
  IPL_ACP_CURSE = 0x7,
  IPL_FIRERES = 0x8,
  IPL_LIGHTRES = 0x9,
  IPL_MAGICRES = 0xA,
  IPL_ALLRES = 0xB,
  IPL_SPLLVLADD = 0xE,
  IPL_CHARGES = 0xF,
  IPL_FIREDAM = 0x10,
  IPL_LIGHTDAM = 0x11,
  IPL_STR = 0x13,
  IPL_STR_CURSE = 0x14,
  IPL_MAG = 0x15,
  IPL_MAG_CURSE = 0x16,
  IPL_DEX = 0x17,
  IPL_DEX_CURSE = 0x18,
  IPL_VIT = 0x19,
  IPL_VIT_CURSE = 0x1A,
  IPL_ATTRIBS = 0x1B,
  IPL_ATTRIBS_CURSE = 0x1C,
  IPL_GETHIT_CURSE = 0x1D,
  IPL_GETHIT = 0x1E,
  IPL_LIFE = 0x1F,
  IPL_LIFE_CURSE = 0x20,
  IPL_MANA = 0x21,
  IPL_MANA_CURSE = 0x22,
  IPL_DUR = 0x23,
  IPL_DUR_CURSE = 0x24,
  IPL_INDESTRUCTIBLE = 0x25,
  IPL_LIGHT = 0x26,
  IPL_LIGHT_CURSE = 0x27,
  IPL_MULT_ARROWS = 0x29,
  IPL_FIRE_ARROWS = 0x2A,
  IPL_LIGHT_ARROWS = 0x2B,
  IPL_INVCURS = 0x2C,
  IPL_THORNS = 0x2D,
  IPL_NOMANA = 0x2E,
  IPL_NOHEALPLR = 0x2F,
  IPL_ABSHALFTRAP = 0x34,
  IPL_KNOCKBACK = 0x35,
  IPL_NOHEALMON = 0x36,
  IPL_STEALMANA = 0x37,
  IPL_STEALLIFE = 0x38,
  IPL_TARGAC = 0x39,
  IPL_FASTATTACK = 0x3A,
  IPL_FASTRECOVER = 0x3B,
  IPL_FASTBLOCK = 0x3C,
  IPL_DAMMOD = 0x3D,
  IPL_RNDARROWVEL = 0x3E,
  IPL_SETDAM = 0x3F,
  IPL_SETDUR = 0x40,
  IPL_NOMINSTR = 0x41,
  IPL_SPELL = 0x42,
  IPL_FASTSWING = 0x43,
  IPL_ONEHAND = 0x44,
  IPL_3XDAMVDEM = 0x45,
  IPL_ALLRESZERO = 0x46,
  IPL_DRAINLIFE = 0x48,
  IPL_RNDSTEALLIFE = 0x49,
  IPL_INFRAVISION = 0x4A,
  IPL_SETAC = 0x4B,
  IPL_ADDACLIFE = 0x4C,
  IPL_ADDMANAAC = 0x4D,
  IPL_FIRERESCLVL = 0x4E,
  IPL_AC_CURSE = 0x4F,
  IPL_INVALID = 0xFFFFFFFF,
};

struct ItemDataStruct
{
  int iRnd;
  char iClass;
  char iLoc;
  int iCurs;
  char itype;
  char iItemId;
  char *iName;
  char *iSName;
  char iMinMLvl;
  int iDurability;
  int iMinDam;
  int iMaxDam;
  int iMinAC;
  int iMaxAC;
  char iMinStr;
  char iMinMag;
  char iMinDex;
  int iFlags;
  int iMiscId;
  int iSpell;
  int iUsable;
  int iValue;
  int iMaxValue;
};

struct PLStruct
{
  const char *PLName;
  int PLPower;
  int PLParam1;
  int PLParam2;
  BYTE PLMinLvl;
  int PLIType;
  int PLGOE;
  int PLDouble;
  int PLOk;
  signed int PLMinVal;
  signed int PLMaxVal;
  signed int PLMultVal;
};

struct UItemStruct
{
  char *UIName;
  char UIItemId;
  char UIMinLvl;
  char UINumPL;
  int UIValue;
  char UIPower1;
  int UIParam1;
  int UIParam2;
  char UIPower2;
  int UIParam3;
  int UIParam4;
  char UIPower3;
  int UIParam5;
  int UIParam6;
  char UIPower4;
  int UIParam7;
  int UIParam8;
  char UIPower5;
  int UIParam9;
  int UIParam10;
  char UIPower6;
  int UIParam11;
  int UIParam12;
};

struct TCmdPlrInfoHdr
{
  unsigned __int8 bCmd;
  unsigned __int16 wOffset;
  unsigned __int16 wBytes;
};

struct STextStruct
{
  int _sx;
  int _syoff;
  char _sstr[128];
  int _sjust;
  BYTE _sclr;
  int _sline;
  int _ssel;
  int _sval;
};

struct Coord
{
  char x;
  char y;
};

struct _plrmsg
{
  int time;
  char player;
  char str[119];
};

struct TMPQHeader
{
  int dwID;
  int dwHeaderSize;
  int dwArchiveSize;
  __int16 wFormatVersion;
  __int16 wSectorSize;
  int dwHashTablePos;
  int dwBlockTablePos;
  int dwHashTableSize;
  int dwBlockTableSize;
};

struct TMPQHeader_buffer
{
  TMPQHeader header;
  char data[64];
};

struct _uiheroinfo
{
  _uiheroinfo *next;
  char name[16];
  unsigned __int16 level;
  unsigned __int8 heroclass;
  unsigned __int8 herorank;
  char magic;
  char dexterity;
  BYTE vitality;
  int gold;
};

struct _uidefaultstats
{
  BYTE strength;
  BYTE magic;
  BYTE dexterity;
  BYTE vitality;
};

struct PkPlayerStruct
{
  char destAction;
  char destParam1;
  char destParam2;
  char plrlevel;
  char px;
  char py;
  char targx;
  char targy;
  char pName[32];
  char pClass;
  char pBaseStr;
  char pBaseMag;
  char pBaseDex;
  char pBaseVit;
  char pLevel;
  char pStatPts;
  int pExperience;
  int pGold;
  int pHPBase;
  int pMaxHPBase;
  int pManaBase;
  int pMaxManaBase;
  char pSplLvl[37];
  int pMemSpells;
  int pMemSpells2;
  PkItemStruct InvBody[7];
  PkItemStruct InvList[40];
  char InvGrid[40];
  char _pNumInv;
  PkItemStruct SpdList[8];
};

struct PkItemStruct
{
  int iSeed;
  __int16 iCreateInfo;
  __int16 idx;
  char bId;
  char bDur;
  char bMDur;
  char bCh;
  char bMCh;
  __int16 wValue;
};

struct LightListStruct
{
  int _lx;
  int _ly;
  int _lradius;
  int _lid;
  int _ldel;
  int _lunflag;
  int field_18;
  int _lunx;
  int _luny;
  int _lunr;
  int _xoff;
  int _yoff;
  int _lflags;
};

enum MON_MODE
{
  MM_STAND = 0x0,
  MM_WALK = 0x1,
  MM_WALK2 = 0x2,
  MM_WALK3 = 0x3,
  MM_ATTACK = 0x4,
  MM_GOTHIT = 0x5,
  MM_DEATH = 0x6,
  MM_SATTACK = 0x7,
  MM_FADEIN = 0x8,
  MM_FADEOUT = 0x9,
  MM_RATTACK = 0xA,
  MM_SPSTAND = 0xB,
  MM_RSPATTACK = 0xC,
  MM_DELAY = 0xD,
  MM_CHARGE = 0xE,
  MM_STONE = 0xF,
  MM_HEAL = 0x10,
  MM_TALK = 0x11,
};

struct InvXY
{
  int X;
  int Y;
};

enum _object_id
{
  OBJ_L1LIGHT = 0x0,
  OBJ_L1LDOOR = 0x1,
  OBJ_L1RDOOR = 0x2,
  OBJ_SKFIRE = 0x3,
  OBJ_LEVER = 0x4,
  OBJ_CHEST1 = 0x5,
  OBJ_CHEST2 = 0x6,
  OBJ_CHEST3 = 0x7,
  OBJ_CANDLE1 = 0x8,
  OBJ_CANDLE2 = 0x9,
  OBJ_CANDLEO = 0xA,
  OBJ_BANNERL = 0xB,
  OBJ_BANNERM = 0xC,
  OBJ_BANNERR = 0xD,
  OBJ_SKPILE = 0xE,
  OBJ_SKSTICK1 = 0xF,
  OBJ_SKSTICK2 = 0x10,
  OBJ_SKSTICK3 = 0x11,
  OBJ_SKSTICK4 = 0x12,
  OBJ_SKSTICK5 = 0x13,
  OBJ_CRUX1 = 0x14,
  OBJ_CRUX2 = 0x15,
  OBJ_CRUX3 = 0x16,
  OBJ_STAND = 0x17,
  OBJ_ANGEL = 0x18,
  OBJ_BOOK2L = 0x19,
  OBJ_BCROSS = 0x1A,
  OBJ_NUDEW2R = 0x1B,
  OBJ_SWITCHSKL = 0x1C,
  OBJ_TNUDEM1 = 0x1D,
  OBJ_TNUDEM2 = 0x1E,
  OBJ_TNUDEM3 = 0x1F,
  OBJ_TNUDEM4 = 0x20,
  OBJ_TNUDEW1 = 0x21,
  OBJ_TNUDEW2 = 0x22,
  OBJ_TNUDEW3 = 0x23,
  OBJ_TORTURE1 = 0x24,
  OBJ_TORTURE2 = 0x25,
  OBJ_TORTURE3 = 0x26,
  OBJ_TORTURE4 = 0x27,
  OBJ_TORTURE5 = 0x28,
  OBJ_BOOK2R = 0x29,
  OBJ_L2LDOOR = 0x2A,
  OBJ_L2RDOOR = 0x2B,
  OBJ_TORCHL = 0x2C,
  OBJ_TORCHR = 0x2D,
  OBJ_TORCHL2 = 0x2E,
  OBJ_TORCHR2 = 0x2F,
  OBJ_SARC = 0x30,
  OBJ_FLAMEHOLE = 0x31,
  OBJ_FLAMELVR = 0x32,
  OBJ_WATER = 0x33,
  OBJ_BOOKLVR = 0x34,
  OBJ_TRAPL = 0x35,
  OBJ_TRAPR = 0x36,
  OBJ_BOOKSHELF = 0x37,
  OBJ_WEAPRACK = 0x38,
  OBJ_BARREL = 0x39,
  OBJ_BARRELEX = 0x3A,
  OBJ_SHRINEL = 0x3B,
  OBJ_SHRINER = 0x3C,
  OBJ_SKELBOOK = 0x3D,
  OBJ_BOOKCASEL = 0x3E,
  OBJ_BOOKCASER = 0x3F,
  OBJ_BOOKSTAND = 0x40,
  OBJ_BOOKCANDLE = 0x41,
  OBJ_BLOODFTN = 0x42,
  OBJ_DECAP = 0x43,
  OBJ_TCHEST1 = 0x44,
  OBJ_TCHEST2 = 0x45,
  OBJ_TCHEST3 = 0x46,
  OBJ_BLINDBOOK = 0x47,
  OBJ_BLOODBOOK = 0x48,
  OBJ_PEDISTAL = 0x49,
  OBJ_L3LDOOR = 0x4A,
  OBJ_SOME_SHRINE_XXX = 0x4B,
  OBJ_PURIFYINGFTN = 0x4C,
  OBJ_ARMORSTAND = 0x4D,
  OBJ_ARMORSTANDN = 0x4E,
  OBJ_GOATSHRINE = 0x4F,
  OBJ_CAULDRON = 0x50,
  OBJ_MURKYFTN = 0x51,
  OBJ_TEARFTN = 0x52,
  OBJ_ALTBOY = 0x53,
  OBJ_MCIRCLE1 = 0x54,
  OBJ_MCIRCLE2 = 0x55,
  OBJ_STORYBOOK = 0x56,
  OBJ_STORYCANDLE = 0x57,
  OBJ_STEELTOME = 0x58,
  OBJ_WARARMOR = 0x59,
  OBJ_WARWEAP = 0x5A,
  OBJ_TBCROSS = 0x5B,
  OBJ_WEAPONRACK = 0x5C,
  OBJ_WEAPONRACKN = 0x5D,
  OBJ_MUSHPATCH = 0x5E,
  OBJ_LAZSTAND = 0x5F,
  OBJ_SLAINHERO = 0x60,
  OBJ_SIGNCHEST = 0x61,
  OBJ_NULL_98 = 0x62,
};

struct DeadStruct
{
  unsigned __int8 *_deadData[8];
  int _deadFrame;
  int _deadWidth;
  int _deadWidth2;
  char _deadtrans;
};

struct TSFX
{
  unsigned __int8 bFlags;
  char *pszName;
  TSnd *pSnd;
};

struct ScrollStruct
{
  int _sxoff;
  int _syoff;
  int _sdx;
  int _sdy;
  int _sdir;
};

enum PLR_MODE
{
  PM_STAND = 0x0,
  PM_WALK = 0x1,
  PM_WALK2 = 0x2,
  PM_WALK3 = 0x3,
  PM_ATTACK = 0x4,
  PM_RATTACK = 0x5,
  PM_BLOCK = 0x6,
  PM_GOTHIT = 0x7,
  PM_DEATH = 0x8,
  PM_SPELL = 0x9,
  PM_NEWLVL = 0xA,
  PM_QUIT = 0xB,
};

enum _cmd_id
{
  CMD_STAND = 0x0,
  CMD_WALKXY = 0x1,
  CMD_ACK_PLRINFO = 0x2,
  CMD_XXX_1 = 0x3,
  CMD_XXX_2 = 0x4,
  CMD_ADDSTR = 0x5,
  CMD_ADDMAG = 0x6,
  CMD_ADDDEX = 0x7,
  CMD_ADDVIT = 0x8,
  CMD_SBSPELL = 0x9,
  CMD_GETITEM = 0xA,
  CMD_AGETITEM = 0xB,
  CMD_PUTITEM = 0xC,
  CMD_RESPAWNITEM = 0xD,
  CMD_ATTACKXY = 0xE,
  CMD_RATTACKXY = 0xF,
  CMD_SPELLXY = 0x10,
  CMD_TSPELLXY = 0x11,
  CMD_OPOBJXY = 0x12,
  CMD_DISARMXY = 0x13,
  CMD_ATTACKID = 0x14,
  CMD_ATTACKPID = 0x15,
  CMD_RATTACKID = 0x16,
  CMD_RATTACKPID = 0x17,
  CMD_SPELLID = 0x18,
  CMD_SPELLPID = 0x19,
  CMD_TSPELLID = 0x1A,
  CMD_TSPELLPID = 0x1B,
  CMD_RESURRECT = 0x1C,
  CMD_OPOBJT = 0x1D,
  CMD_KNOCKBACK = 0x1E,
  CMD_TALKXY = 0x1F,
  CMD_NEWLVL = 0x20,
  CMD_WARP = 0x21,
  CMD_CHEAT_EXPERIENCE = 0x22,
  CMD_CHEAT_SPELL_LEVEL = 0x23,
  CMD_XXX_4 = 0x24,
  CMD_DEBUG = 0x25,
  CMD_SYNCDATA = 0x26,
  CMD_MONSTDEATH = 0x27,
  CMD_MONSTDAMAGE = 0x28,
  CMD_PLRDEAD = 0x29,
  CMD_REQUESTGITEM = 0x2A,
  CMD_REQUESTAGITEM = 0x2B,
  CMD_GOTOGETITEM = 0x2C,
  CMD_GOTOAGETITEM = 0x2D,
  CMD_OPENDOOR = 0x2E,
  CMD_CLOSEDOOR = 0x2F,
  CMD_OPERATEOBJ = 0x30,
  CMD_PLROPOBJ = 0x31,
  CMD_BREAKOBJ = 0x32,
  CMD_CHANGEPLRITEMS = 0x33,
  CMD_DELPLRITEMS = 0x34,
  CMD_PLRDAMAGE = 0x35,
  CMD_PLRLEVEL = 0x36,
  CMD_DROPITEM = 0x37,
  CMD_PLAYER_JOINLEVEL = 0x38,
  CMD_SEND_PLRINFO = 0x39,
  CMD_SATTACKXY = 0x3A,
  CMD_ACTIVATEPORTAL = 0x3B,
  CMD_DEACTIVATEPORTAL = 0x3C,
  CMD_DLEVEL_0 = 0x3D,
  CMD_DLEVEL_1 = 0x3E,
  CMD_DLEVEL_2 = 0x3F,
  CMD_DLEVEL_3 = 0x40,
  CMD_DLEVEL_4 = 0x41,
  CMD_DLEVEL_5 = 0x42,
  CMD_DLEVEL_6 = 0x43,
  CMD_DLEVEL_7 = 0x44,
  CMD_DLEVEL_8 = 0x45,
  CMD_DLEVEL_9 = 0x46,
  CMD_DLEVEL_10 = 0x47,
  CMD_DLEVEL_11 = 0x48,
  CMD_DLEVEL_12 = 0x49,
  CMD_DLEVEL_13 = 0x4A,
  CMD_DLEVEL_14 = 0x4B,
  CMD_DLEVEL_15 = 0x4C,
  CMD_DLEVEL_16 = 0x4D,
  CMD_DLEVEL_JUNK = 0x4E,
  CMD_DLEVEL_END = 0x4F,
  CMD_HEALOTHER = 0x50,
  CMD_STRING = 0x51,
  CMD_SETSTR = 0x52,
  CMD_SETMAG = 0x53,
  CMD_SETDEX = 0x54,
  CMD_SETVIT = 0x55,
  CMD_RETOWN = 0x56,
  CMD_SPELLXYD = 0x57,
  CMD_ITEMEXTRA = 0x58,
  CMD_SYNCPUTITEM = 0x59,
  CMD_KILLGOLEM = 0x5A,
  CMD_SYNCQUEST = 0x5B,
  CMD_ENDSHIELD = 0x5C,
  CMD_AWAKEGOLEM = 0x5D,
  CMD_NOVA = 0x5E,
  CMD_SETSHIELD = 0x5F,
  CMD_REMSHIELD = 0x60,
  FAKE_CMD_SETID = 0x61,
  FAKE_CMD_DROPID = 0x62,
  NUM_CMDS = 0x63,
  X_CMD_LAST = 0xFF,
};

enum enum_1
{
};

struct TMenuItem
{
  unsigned int dwFlags;
  char *pszStr;
  void (__fastcall *fnMenu)(signed int);
};

struct ROOMNODE
{
  int nRoomx1;
  int nRoomy1;
  int nRoomx2;
  int nRoomy2;
  int nRoomDest;
};

struct HALLNODE
{
  int nHallx1;
  int nHally1;
  int nHallx2;
  int nHally2;
  int nHalldir;
  HALLNODE *pNext;
};

struct ThemeStruct
{
  char ttype;
  int ttval;
};

struct THEME_LOC
{
  int x;
  int y;
  int ttval;
  int width;
  int height;
};

struct SHA1Context
{
  int state[5];
  int count[2];
  char buffer[64];
};

struct TSyncHeader
{
  unsigned __int8 bCmd;
  unsigned __int8 bLevel;
  unsigned __int16 wLen;
  unsigned __int8 bObjId;
  unsigned __int8 bObjCmd;
  unsigned __int8 bItemI;
  unsigned __int8 bItemX;
  unsigned __int8 bItemY;
  __int16 wItemIndx;
  unsigned __int16 wItemCI;
  int seed;
  unsigned __int8 bItemId;
  unsigned __int8 bItemDur;
  unsigned __int8 bItemMDur;
  unsigned __int8 bItemCh;
  unsigned __int8 bItemMCh;
  unsigned __int16 wItemVal;
  char dwItemBuff;
  unsigned __int16 wPInvIndx;
  unsigned __int16 wPInvCI;
  int dwPInvSeed;
  unsigned __int8 bPInvId;
};

struct TSyncMonster
{
  unsigned __int8 _mndx;
  unsigned __int8 _mx;
  unsigned __int8 _my;
  unsigned __int8 _menemy;
  unsigned __int8 _mdelta;
};

struct PortalStruct
{
  int open;
  int x;
  int y;
  int level;
  int setlvl;
};

struct TMegaPkt
{
  TMegaPkt *pNext;
  int dwSpaceLeft;
  unsigned __int8 data[32000];
};

struct DMonsterStr
{
  BYTE _mx;
  BYTE _my;
  char _mdir;
  BYTE _menemy;
  char _mactive;
  int _mhitpoints;
};

struct TCmdPItem
{
  char bCmd;
  unsigned __int8 x;
  unsigned __int8 y;
  unsigned __int16 wIndx;
  unsigned __int16 wCI;
  int dwSeed;
  unsigned __int8 bId;
  unsigned __int8 bDur;
  unsigned __int8 bMDur;
  unsigned __int8 bCh;
  unsigned __int8 bMCh;
  unsigned __int16 wValue;
};

struct DObjectStr
{
  unsigned __int8 bCmd;
};

struct DLevel
{
  TCmdPItem item[127];
  DObjectStr object[127];
  DMonsterStr monster[200];
  char automap[40][40];
};

struct DPortal
{
  unsigned __int8 x;
  unsigned __int8 y;
  unsigned __int8 level;
  unsigned __int8 ltype;
};

struct DJunk
{
  DPortal portal[4];
};

struct TCmdGItem
{
  unsigned __int8 bCmd;
  _BYTE gap1[1];
  unsigned __int8 bPnum;
  _BYTE gap3[1];
  unsigned __int8 x;
  unsigned __int8 y;
  __int16 wIndx;
  __int16 wCI;
  int dwSeed;
  unsigned __int8 bId;
  unsigned __int8 bDur;
  unsigned __int8 bMDur;
  unsigned __int8 bCh;
  unsigned __int8 bMCh;
  unsigned __int16 wValue;
};

enum missile_id
{
  MIS_ARROW = 0x0,
  MIS_FIREBOLT = 0x1,
  MIS_GUARDIAN = 0x2,
  MIS_RNDTELEPORT = 0x3,
  MIS_LIGHTBALL = 0x4,
  MIS_FIREWALL = 0x5,
  MIS_FIREBALL = 0x6,
  MIS_LIGHTCTRL = 0x7,
  MIS_LIGHTNING = 0x8,
  MIS_MISEXP = 0x9,
  MIS_TOWN = 0xA,
  MIS_FLASH = 0xB,
  MIS_FLASH2 = 0xC,
  MIS_MANASHIELD = 0xD,
  MIS_FIREMOVE = 0xE,
  MIS_CHAIN = 0xF,
  MIS_NULL_10 = 0x10,
  MIS_NULL_11 = 0x11,
  MIS_NULL_12 = 0x12,
  MIS_NULL_13 = 0x13,
  MIS_RHINO = 0x14,
  MIS_MAGMABALL = 0x15,
  MIS_LIGHTCTRL2 = 0x16,
  MIS_LIGHTNING2 = 0x17,
  MIS_FLARE = 0x18,
  MIS_MISEXP2 = 0x19,
  MIS_TELEPORT = 0x1A,
  MIS_FARROW = 0x1B,
  MIS_DOOMSERP = 0x1C,
  MIS_NULL_1D = 0x1D,
  MIS_STONE = 0x1E,
  MIS_NULL_1F = 0x1F,
  MIS_INVISIBL = 0x20,
  MIS_GOLEM = 0x21,
  MIS_ETHEREALIZE = 0x22,
  MIS_NULL_23 = 0x23,
  MIS_BOOM = 0x24,
  MIS_HEAL = 0x25,
  MIS_FIREWALLC = 0x26,
  MIS_INFRA = 0x27,
  MIS_IDENTIFY = 0x28,
  MIS_WAVE = 0x29,
  MIS_NOVA = 0x2A,
  MIS_BLODBOIL = 0x2B,
  MIS_APOCA = 0x2C,
  MIS_REPAIR = 0x2D,
  MIS_RECHARGE = 0x2E,
  MIS_DISARM = 0x2F,
  MIS_FLAME = 0x30,
  MIS_FLAMEC = 0x31,
  MIS_NULL_32 = 0x32,
  MIS_NULL_33 = 0x33,
  MIS_CBOLT = 0x34,
  MIS_HBOLT = 0x35,
  MIS_RESURRECT = 0x36,
  MIS_TELEKINESIS = 0x37,
  MIS_LARROW = 0x38,
  MIS_ACID = 0x39,
  MIS_MISEXP3 = 0x3A,
  MIS_ACIDPUD = 0x3B,
  MIS_HEALOTHER = 0x3C,
  MIS_ELEMENT = 0x3D,
  MIS_RESURRECTBEAM = 0x3E,
  MIS_BONESPIRIT = 0x3F,
  MIS_WEAPEXP = 0x40,
  MIS_RPORTAL = 0x41,
  MIS_BOOM2 = 0x42,
  MIS_DIABAPOCA = 0x43,
};

struct XHelpStruct
{
  int x;
  int y;
  char text[128];
  char just;
};

struct XHelpStruct2
{
  int x1;
  int y1;
  int x2;
  int y2;
  char field_10;
};

