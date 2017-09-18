// ͷ�ļ� 
#pragma once

#include "config.h"

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
//#include "SDL_mixer.h"
//#include "smpeg.h"
#include "bass.h"
#include "bassmidi.h"
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h" 
#include "luafun.h"
#include "list.h" 

// ��������
#ifndef BOOL
#define BOOL unsigned char
#endif
#ifndef TRUE
#define TRUE (BOOL) 1
#endif
#ifndef FALSE
#define FALSE (BOOL) 0
#endif

static char *JY_CurrentPath = "./";

#ifdef ANDROID
*JY_CurrentPath = "/sdcard/JYLDCR/";
#endif

//��ȫfreeָ��ĺ�
#define swap16( x )  ( ((x & 0x00ffU) << 8) |  ((x & 0xff00U) >> 8) )

#define SafeFree(p) do {if(p) {free(p);p=NULL;}} while(0)

//ȫ�̱���

#define _(f) va("%s%s", JY_CurrentPath, f)

#define RMASK (0xff0000)
#define GMASK (0xff00)
#define BMASK (0xff)
#define AMASK (0xff000000)

// jymain.c

int Lua_Main(lua_State *pL_main);

int Lua_Config(lua_State *pL,const char *filename);

int getfield(lua_State *pL,const char *key);

int getfieldstr(lua_State *pL,const char *key,char *str);

// �����Ϣ���ļ�debug.txt��
int JY_Debug(const char * fmt,...);

// �����Ϣ���ļ�error.txt��
int JY_Error(const char * fmt,...);

//���� x�� xmin-xmax֮��
int limitX(int x, int xmin, int xmax);

//ȡ�ļ�����
int FileLength(const char *filename);

char *va(
   const char *format,
   ...
);

