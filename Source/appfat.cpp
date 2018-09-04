//----- (00410990) --------------------------------------------------------
char *__fastcall GetErr(int error_code)
{
  int uID; // [esp+Ch] [ebp-8h]

  uID = error_code;
  if ( (((unsigned int)error_code >> 16) & 0x1FFF) == 2168 )
  {
    GetDSErr(error_code, error_buf, 256);
  }
  else if ( (((unsigned int)error_code >> 16) & 0x1FFF) == 2166 )
  {
    GetDDErr(error_code, error_buf, 256);
  }
  else if ( error_code & 0x20000000 )
  {
    if ( (unsigned int)error_code >= 0x21050000 )
      uID = error_code - 553975808 + 30000;
    if ( !LoadStringA(ghInst, uID, error_buf, 256) )
      LoadStringA(ghInst, 1u, error_buf, 256);
  }
  else
  {
    FormatMessageA(0x1000u, 0, error_code, 0x400u, error_buf, 0x100u, 0);
  }
  return error_buf;
}

//----- (00410A92) --------------------------------------------------------
void __fastcall GetDDErr(int error_code, char *error_buf, int error_buf_len)
{
  int v3; // edx
  char v4; // al
  char v6[20]; // [esp+18h] [ebp-18h]
  char *v7; // [esp+2Ch] [ebp-4h]

  if ( error_code > DDERR_GENERIC )
  {
    if ( error_code > DDERR_INVALIDPARAMS )
    {
      if ( error_code > -2005532662 )
      {
        if ( error_code > -2005532632 )
        {
          if ( error_code > -2005532582 )
          {
            if ( error_code > -2005532572 )
            {
              if ( error_code > -2005532552 )
              {
                if ( error_code > -2005532527 )
                {
                  if ( error_code > -2005532512 )
                  {
                    if ( error_code > -2005532492 )
                    {
                      if ( error_code > -2005532462 )
                      {
                        if ( error_code > -2005532457 )
                        {
                          if ( error_code > -2005532447 )
                          {
                            if ( error_code > -2005532432 )
                            {
                              if ( error_code > -2005532417 )
                              {
                                if ( error_code > -2005532392 )
                                {
                                  if ( error_code > -2005532362 )
                                  {
                                    if ( error_code > -2005532342 )
                                    {
                                      if ( error_code > -2005532332 )
                                      {
                                        if ( error_code > -2005532312 )
                                        {
                                          if ( error_code > -2005532272 )
                                          {
                                            if ( error_code > -2005532252 )
                                            {
                                              if ( error_code > -2005532237 )
                                              {
                                                if ( error_code > -2005532222 )
                                                {
                                                  if ( error_code > -2005532202 )
                                                  {
                                                    if ( error_code > -2005532182 )
                                                    {
                                                      if ( error_code > -2005532152 )
                                                      {
                                                        if ( error_code > -2005532132 )
                                                        {
                                                          if ( error_code > -2005532032 )
                                                          {
                                                            if ( error_code == -2005532012 )
                                                            {
                                                              v7 = "DDERR_CANTPAGEUNLOCK";
                                                            }
                                                            else if ( error_code == -2005531992 )
                                                            {
                                                              v7 = "DDERR_NOTPAGELOCKED";
                                                            }
                                                            else
                                                            {
                                                              if ( error_code )
                                                                goto LABEL_100;
                                                              v7 = "DD_OK";
                                                            }
                                                          }
                                                          else
                                                          {
                                                            if ( error_code != -2005532032 )
                                                            {
                                                              switch ( error_code )
                                                              {
                                                                case -2005532112:
                                                                  v7 = "DDERR_XALIGN";
                                                                  goto LABEL_223;
                                                                case -2005532111:
                                                                  v7 = "DDERR_INVALIDDIRECTDRAWGUID";
                                                                  goto LABEL_223;
                                                                case -2005532110:
                                                                  v7 = "DDERR_DIRECTDRAWALREADYCREATED";
                                                                  goto LABEL_223;
                                                                case -2005532109:
                                                                  v7 = "DDERR_NODIRECTDRAWHW";
                                                                  goto LABEL_223;
                                                                case -2005532108:
                                                                  v7 = "DDERR_PRIMARYSURFACEALREADYEXISTS";
                                                                  goto LABEL_223;
                                                                case -2005532107:
                                                                  v7 = "DDERR_NOEMULATION";
                                                                  goto LABEL_223;
                                                                case -2005532106:
                                                                  v7 = "DDERR_REGIONTOOSMALL";
                                                                  goto LABEL_223;
                                                                case -2005532105:
                                                                  v7 = "DDERR_CLIPPERISUSINGHWND";
                                                                  goto LABEL_223;
                                                                case -2005532104:
                                                                  v7 = "DDERR_NOCLIPPERATTACHED";
                                                                  goto LABEL_223;
                                                                case -2005532103:
                                                                  v7 = "DDERR_NOHWND";
                                                                  goto LABEL_223;
                                                                case -2005532102:
                                                                  v7 = "DDERR_HWNDSUBCLASSED";
                                                                  goto LABEL_223;
                                                                case -2005532101:
                                                                  v7 = "DDERR_HWNDALREADYSET";
                                                                  goto LABEL_223;
                                                                case -2005532100:
                                                                  v7 = "DDERR_NOPALETTEATTACHED";
                                                                  goto LABEL_223;
                                                                case -2005532099:
                                                                  v7 = "DDERR_NOPALETTEHW";
                                                                  goto LABEL_223;
                                                                case -2005532098:
                                                                  v7 = "DDERR_BLTFASTCANTCLIP";
                                                                  goto LABEL_223;
                                                                case -2005532097:
                                                                  v7 = "DDERR_NOBLTHW";
                                                                  goto LABEL_223;
                                                                case -2005532096:
                                                                  v7 = "DDERR_NODDROPSHW";
                                                                  goto LABEL_223;
                                                                case -2005532095:
                                                                  v7 = "DDERR_OVERLAYNOTVISIBLE";
                                                                  goto LABEL_223;
                                                                case -2005532094:
                                                                  v7 = "DDERR_NOOVERLAYDEST";
                                                                  goto LABEL_223;
                                                                case -2005532093:
                                                                  v7 = "DDERR_INVALIDPOSITION";
                                                                  goto LABEL_223;
                                                                case -2005532092:
                                                                  v7 = "DDERR_NOTAOVERLAYSURFACE";
                                                                  goto LABEL_223;
                                                                case -2005532091:
                                                                  v7 = "DDERR_EXCLUSIVEMODEALREADYSET";
                                                                  goto LABEL_223;
                                                                case -2005532090:
                                                                  v7 = "DDERR_NOTFLIPPABLE";
                                                                  goto LABEL_223;
                                                                case -2005532089:
                                                                  v7 = "DDERR_CANTDUPLICATE";
                                                                  goto LABEL_223;
                                                                case -2005532088:
                                                                  v7 = "DDERR_NOTLOCKED";
                                                                  goto LABEL_223;
                                                                case -2005532087:
                                                                  v7 = "DDERR_CANTCREATEDC";
                                                                  goto LABEL_223;
                                                                case -2005532086:
                                                                  v7 = "DDERR_NODC";
                                                                  goto LABEL_223;
                                                                case -2005532085:
                                                                  v7 = "DDERR_WRONGMODE";
                                                                  goto LABEL_223;
                                                                case -2005532084:
                                                                  v7 = "DDERR_IMPLICITLYCREATED";
                                                                  goto LABEL_223;
                                                                case -2005532083:
                                                                  v7 = "DDERR_NOTPALETTIZED";
                                                                  goto LABEL_223;
                                                                case -2005532081:
                                                                  v7 = "DDERR_NOMIPMAPHW";
                                                                  goto LABEL_223;
                                                                case -2005532080:
                                                                  v7 = "DDERR_INVALIDSURFACETYPE";
                                                                  goto LABEL_223;
                                                                case -2005532052:
                                                                  v7 = "DDERR_DCALREADYCREATED";
                                                                  goto LABEL_223;
                                                                default:
                                                                  goto LABEL_100;
                                                              }
                                                              goto LABEL_100;
                                                            }
                                                            v7 = "DDERR_CANTPAGELOCK";
                                                          }
                                                        }
                                                        else if ( error_code == -2005532132 )
                                                        {
                                                          v7 = "DDERR_WASSTILLDRAWING";
                                                        }
                                                        else
                                                        {
                                                          if ( error_code != -2005532135 )
                                                            goto LABEL_100;
                                                          v7 = "DDERR_VERTICALBLANKINPROGRESS";
                                                        }
                                                      }
                                                      else if ( error_code == -2005532152 )
                                                      {
                                                        v7 = "DDERR_UNSUPPORTEDMASK";
                                                      }
                                                      else
                                                      {
                                                        if ( error_code != -2005532162 )
                                                          goto LABEL_100;
                                                        v7 = "DDERR_UNSUPPORTEDFORMAT";
                                                      }
                                                    }
                                                    else if ( error_code == -2005532182 )
                                                    {
                                                      v7 = "DDERR_TOOBIGWIDTH";
                                                    }
                                                    else
                                                    {
                                                      if ( error_code != -2005532192 )
                                                        goto LABEL_100;
                                                      v7 = "DDERR_TOOBIGSIZE";
                                                    }
                                                  }
                                                  else if ( error_code == -2005532202 )
                                                  {
                                                    v7 = "DDERR_TOOBIGHEIGHT";
                                                  }
                                                  else
                                                  {
                                                    if ( error_code != -2005532212 )
                                                      goto LABEL_100;
                                                    v7 = "DDERR_SURFACENOTATTACHED";
                                                  }
                                                }
                                                else if ( error_code == -2005532222 )
                                                {
                                                  v7 = "DDERR_SURFACELOST";
                                                }
                                                else
                                                {
                                                  if ( error_code != -2005532232 )
                                                    goto LABEL_100;
                                                  v7 = "DDERR_SURFACEISOBSCURED";
                                                }
                                              }
                                              else if ( error_code == -2005532237 )
                                              {
                                                v7 = "DDERR_CANTLOCKSURFACE";
                                              }
                                              else
                                              {
                                                if ( error_code != -2005532242 )
                                                  goto LABEL_100;
                                                v7 = "DDERR_SURFACEBUSY";
                                              }
                                            }
                                            else if ( error_code == -2005532252 )
                                            {
                                              v7 = "DDERR_SURFACEALREADYDEPENDENT";
                                            }
                                            else
                                            {
                                              if ( error_code != -2005532262 )
                                                goto LABEL_100;
                                              v7 = "DDERR_SURFACEALREADYATTACHED";
                                            }
                                          }
                                          else
                                          {
                                            if ( error_code != -2005532272 )
                                            {
                                              switch ( error_code )
                                              {
                                                case -2005532292:
                                                  v7 = "DDERR_OUTOFVIDEOMEMORY";
                                                  goto LABEL_223;
                                                case -2005532290:
                                                  v7 = "DDERR_OVERLAYCANTCLIP";
                                                  goto LABEL_223;
                                                case -2005532288:
                                                  v7 = "DDERR_OVERLAYCOLORKEYONLYONEACTIVE";
                                                  goto LABEL_223;
                                                case -2005532285:
                                                  v7 = "DDERR_PALETTEBUSY";
                                                  goto LABEL_223;
                                                default:
                                                  goto LABEL_100;
                                              }
                                              goto LABEL_100;
                                            }
                                            v7 = "DDERR_COLORKEYNOTSET";
                                          }
                                        }
                                        else if ( error_code == -2005532312 )
                                        {
                                          v7 = "DDERR_OUTOFCAPS";
                                        }
                                        else
                                        {
                                          if ( error_code != -2005532322 )
                                            goto LABEL_100;
                                          v7 = "DDERR_NOZOVERLAYHW";
                                        }
                                      }
                                      else if ( error_code == -2005532332 )
                                      {
                                        v7 = "DDERR_NOZBUFFERHW";
                                      }
                                      else
                                      {
                                        if ( error_code != -2005532337 )
                                          goto LABEL_100;
                                        v7 = "DDERR_NOVSYNCHW";
                                      }
                                    }
                                    else
                                    {
                                      switch ( error_code )
                                      {
                                        case -2005532342:
                                          v7 = "DDERR_NOTEXTUREHW";
                                          break;
                                        case -2005532356:
                                          v7 = "DDERR_NOT4BITCOLOR";
                                          break;
                                        case -2005532355:
                                          v7 = "DDERR_NOT4BITCOLORINDEX";
                                          break;
                                        case -2005532352:
                                          v7 = "DDERR_NOT8BITCOLOR";
                                          break;
                                        default:
                                          goto LABEL_100;
                                      }
                                    }
                                  }
                                  else if ( error_code == -2005532362 )
                                  {
                                    v7 = "DDERR_NOSTRETCHHW";
                                  }
                                  else
                                  {
                                    if ( error_code != -2005532382 )
                                      goto LABEL_100;
                                    v7 = "DDERR_NOROTATIONHW";
                                  }
                                }
                                else if ( error_code == -2005532392 )
                                {
                                  v7 = "DDERR_NORASTEROPHW";
                                }
                                else
                                {
                                  if ( error_code != -2005532412 )
                                    goto LABEL_100;
                                  v7 = "DDERR_NOOVERLAYHW";
                                }
                              }
                              else if ( error_code == -2005532417 )
                              {
                                v7 = "DDERR_NOTFOUND";
                              }
                              else
                              {
                                if ( error_code != -2005532422 )
                                  goto LABEL_100;
                                v7 = "DDERR_NOMIRRORHW";
                              }
                            }
                            else if ( error_code == -2005532432 )
                            {
                              v7 = "DDERR_NOGDI";
                            }
                            else
                            {
                              if ( error_code != -2005532442 )
                                goto LABEL_100;
                              v7 = "DDERR_NOFLIPHW";
                            }
                          }
                          else if ( error_code == -2005532447 )
                          {
                            v7 = "DDERR_NOEXCLUSIVEMODE";
                          }
                          else
                          {
                            if ( error_code != -2005532452 )
                              goto LABEL_100;
                            v7 = "DDERR_NOCOLORKEYHW";
                          }
                        }
                        else if ( error_code == -2005532457 )
                        {
                          v7 = "DDERR_NOCOLORKEY";
                        }
                        else
                        {
                          if ( error_code != -2005532460 )
                            goto LABEL_100;
                          v7 = "DDERR_NOCOOPERATIVELEVELSET";
                        }
                      }
                      else if ( error_code == -2005532462 )
                      {
                        v7 = "DDERR_NOCOLORCONVHW";
                      }
                      else
                      {
                        if ( error_code != -2005532467 )
                          goto LABEL_100;
                        v7 = "DDERR_NOCLIPLIST";
                      }
                    }
                    else if ( error_code == -2005532492 )
                    {
                      v7 = "DDERR_NOALPHAHW";
                    }
                    else
                    {
                      if ( error_code != -2005532502 )
                        goto LABEL_100;
                      v7 = "DDERR_NO3D";
                    }
                  }
                  else if ( error_code == -2005532512 )
                  {
                    v7 = "DDERR_LOCKEDSURFACES";
                  }
                  else
                  {
                    if ( error_code != -2005532522 )
                      goto LABEL_100;
                    v7 = "DDERR_INVALIDRECT";
                  }
                }
                else if ( error_code == -2005532527 )
                {
                  v7 = "DDERR_INVALIDPIXELFORMAT";
                }
                else
                {
                  if ( error_code != -2005532542 )
                    goto LABEL_100;
                  v7 = "DDERR_INVALIDOBJECT";
                }
              }
              else if ( error_code == -2005532552 )
              {
                v7 = "DDERR_INVALIDMODE";
              }
              else
              {
                if ( error_code != -2005532562 )
                  goto LABEL_100;
                v7 = "DDERR_INVALIDCLIPLIST";
              }
            }
            else if ( error_code == -2005532572 )
            {
              v7 = "DDERR_INVALIDCAPS";
            }
            else
            {
              if ( error_code != -2005532577 )
                goto LABEL_100;
              v7 = "DDERR_INCOMPATIBLEPRIMARY";
            }
          }
          else if ( error_code == -2005532582 )
          {
            v7 = "DDERR_HEIGHTALIGN";
          }
          else
          {
            if ( error_code != -2005532617 )
              goto LABEL_100;
            v7 = "DDERR_EXCEPTION";
          }
        }
        else if ( error_code == -2005532632 )
        {
          v7 = "DDERR_CURRENTLYNOTAVAIL";
        }
        else
        {
          if ( error_code != -2005532652 )
            goto LABEL_100;
          v7 = "DDERR_CANNOTDETACHSURFACE";
        }
      }
      else if ( error_code == -2005532662 )
      {
        v7 = "DDERR_CANNOTATTACHSURFACE";
      }
      else
      {
        if ( error_code != -2005532667 )
          goto LABEL_100;
        v7 = "DDERR_ALREADYINITIALIZED";
      }
    }
    else if ( error_code == DDERR_INVALIDPARAMS )
    {
      v7 = "DDERR_INVALIDPARAMS";
    }
    else
    {
      if ( error_code != DDERR_OUTOFMEMORY )
        goto LABEL_100;
      v7 = "DDERR_OUTOFMEMORY";
    }
LABEL_223:
    strncpy(error_buf, v7, error_buf_len);
    return;
  }
  if ( error_code == DDERR_GENERIC )
  {
    v7 = "DDERR_GENERIC";
    goto LABEL_223;
  }
  if ( error_code == DDERR_UNSUPPORTED )
  {
    v7 = "DDERR_UNSUPPORTED";
    goto LABEL_223;
  }
LABEL_100:
  strcpy(v6, "DDERR unknown 0x%x");
  v3 = *(_DWORD *)"n 0x%x";
  LOWORD(v3) = *(_WORD *)"%x";
  v4 = aDderrUnknown0x[18];
  if ( (unsigned int)error_buf_len < 0x1D )
    assertion_failed(329, "C:\\Diablo\\Direct\\appfat.cpp");
  sprintf(error_buf, v6, error_code);
}

//----- (00411543) --------------------------------------------------------
void __fastcall GetDSErr(int error_code, char *error_buf, int error_buf_len)
{
  int v3; // edx
  char v4; // al
  char v6[20]; // [esp+18h] [ebp-18h]
  char *v7; // [esp+2Ch] [ebp-4h]

  if ( error_code > -2147221232 )
  {
    if ( error_code > -2147024809 )
    {
      if ( error_code > -2005401570 )
      {
        if ( error_code > -2005401530 )
        {
          if ( error_code > -2005401480 )
          {
            if ( error_code == -2005401470 )
            {
              v7 = "DSERR_ALREADYINITIALIZED";
            }
            else if ( error_code == -2005401450 )
            {
              v7 = "DSERR_BUFFERLOST";
            }
            else
            {
              if ( error_code )
                goto LABEL_15;
              v7 = "DS_OK";
            }
          }
          else if ( error_code == -2005401480 )
          {
            v7 = "DSERR_NODRIVER";
          }
          else
          {
            if ( error_code != -2005401500 )
              goto LABEL_15;
            v7 = "DSERR_BADFORMAT";
          }
        }
        else if ( error_code == -2005401530 )
        {
          v7 = "DSERR_PRIOLEVELNEEDED";
        }
        else
        {
          if ( error_code != -2005401550 )
            goto LABEL_15;
          v7 = "DSERR_INVALIDCALL";
        }
      }
      else if ( error_code == -2005401570 )
      {
        v7 = "DSERR_CONTROLUNAVAIL";
      }
      else
      {
        if ( error_code != -2005401590 )
          goto LABEL_15;
        v7 = "DSERR_ALLOCATED";
      }
    }
    else if ( error_code == -2147024809 )
    {
      v7 = "DSERR_INVALIDPARAM";
    }
    else
    {
      if ( error_code != -2147024882 )
        goto LABEL_15;
      v7 = "DSERR_OUTOFMEMORY";
    }
LABEL_42:
    strncpy(error_buf, v7, error_buf_len);
    return;
  }
  if ( error_code == -2147221232 )
  {
    v7 = "DSERR_NOAGGREGATION";
    goto LABEL_42;
  }
  if ( error_code == -2147467262 )
  {
    v7 = "E_NOINTERFACE";
    goto LABEL_42;
  }
LABEL_15:
  strcpy(v6, "DSERR unknown 0x%x");
  v3 = *(_DWORD *)"n 0x%x";
  LOWORD(v3) = *(_WORD *)"%x";
  v4 = aDserrUnknown0x[18];
  if ( (unsigned int)error_buf_len < 0x1D )
    assertion_failed(391, "C:\\Diablo\\Direct\\appfat.cpp");
  sprintf(error_buf, v6, error_code);
}

//----- (00411763) --------------------------------------------------------
char *__cdecl GetLastErr()
{
  int v0; // eax

  v0 = GetLastError();
  return GetErr(v0);
}

//----- (00411780) --------------------------------------------------------
void __noreturn TermMsg(char *pszFmt, ...)
{
  va_list va; // [esp+1Ch] [ebp+Ch]

  va_start(va, pszFmt);
  if ( lpDDSPrimary )
  {
    lpDDSPrimary->lpVtbl->Release(lpDDSPrimary);
    lpDDSPrimary = 0;
  }
  if ( lpDDPalette )
  {
    lpDDPalette->lpVtbl->Release(lpDDPalette);
    lpDDPalette = 0;
  }
  if ( lpDD )
  {
    lpDD->lpVtbl->Release(lpDD);
    lpDD = 0;
  }
  if ( pszFmt )
    MsgBox(pszFmt, va);
  init_cleanup();
  exit(1);
}

//----- (00411841) --------------------------------------------------------
void __fastcall MsgBox(char *pszFmt, va_list va)
{
  char Text; // [esp+14h] [ebp-100h]

  wvsprintfA(&Text, pszFmt, va);
  MessageBoxA(ghMainWnd, &Text, "ERROR", 0x10u);
}

//----- (00411898) --------------------------------------------------------
void DrawDlg(char *pszFmt, ...)
{
  CHAR v1; // [esp+Ch] [ebp-104h]
  va_list arglist; // [esp+10Ch] [ebp-4h]
  va_list va; // [esp+11Ch] [ebp+Ch]

  va_start(va, pszFmt);
  if ( !pszFmt )
    assertion_failed(500, "C:\\Diablo\\Direct\\appfat.cpp");
  va_copy(arglist, va);
  wvsprintfA(&v1, pszFmt, va);
  arglist = 0;
  SDrawMessageBox(&v1, "Diablo", 8240);
}

//----- (00411904) --------------------------------------------------------
void __fastcall __noreturn assertion_failed(int line, char *file)
{
  TermMsg("assertion failed (%d:%s)", line, file);
}

//----- (00411932) --------------------------------------------------------
void __fastcall DDErrDlg(int error_code, int log_line_nr, char *log_file_path)
{
  char *v3; // eax

  if ( error_code )
  {
    v3 = GetErr(error_code);
    TermMsg("Direct draw error (%s:%d)\n%s", log_file_path, log_line_nr, v3);
  }
}

//----- (0041197A) --------------------------------------------------------
void __fastcall DSErrDlg(int error_code, int log_line_nr, char *log_file_path)
{
  char *v3; // eax

  if ( error_code )
  {
    v3 = GetErr(error_code);
    TermMsg("Direct sound error (%s:%d)\n%s", log_file_path, log_line_nr, v3);
  }
}

