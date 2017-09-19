#pragma once

#include "SDL.h"
#include <stdio.h>
//PicCache.c

// ����ʹ�õ�����
struct CacheNode                         //��ͼcache����ڵ�
{
    CacheNode()
    {}
    ~CacheNode()
    {
        if (s) { SDL_FreeSurface(s); }
        if (t) { SDL_DestroyTexture(t); }
    }
    void toTexture();

    SDL_Surface* s;                      //����ͼ��Ӧ�ı���
    SDL_Texture* t;
    int w;                               //��ͼ���
    int h;                               //��ͼ�߶�
    int xoff;                            //��ͼƫ��
    int yoff;
    int id;                              //��ͼ���
    int fileid;                          //��ͼ�ļ����
    //struct list_head list;               //����ṹ��linux.h�е�list.h�ж���
};

struct PicFileCache                      //��ͼ�ļ�����ڵ�
{
    int num = 0;                         //�ļ���ͼ����
    int* idx = NULL;                     //idx������
    int filelength = 0;                  //grp�ļ�����
    FILE* fp = NULL;                     //grp�ļ����
    unsigned char* grp = NULL;           //grp������
    int width;                           //ָ�����
    int height;                          //ָ���߶�
    int percent;                         //ָ������
    struct CacheNode** pcache;           //�ļ������е���ͼ��Ӧ��cache�ڵ�ָ�룬Ϊ�����ʾû�С�
    char path[512];
    char suffix[12];                     //��׺��
};

#define PIC_FILE_NUM 100                 //�������ͼ�ļ�(idx/grp)����

int Init_Cache();
int JY_PicInit(char* PalletteFilename);
int JY_PicLoadFile(const char* idxfilename, const char* grpfilename, int id, int width, int height);
int JY_LoadPic(int fileid, int picid, int x, int y, int flag, int value);
int JY_LoadPicColor(int fileid, int picid, int x, int y, int flag, int value, int color);
int LoadPic(int fileid, int picid, struct CacheNode* cache);
int JY_LoadPNGPath(const char* path, int fileid, int num, int percent, const char* suffix);
int JY_LoadPNG(int fileid, int picid, int x, int y, int flag, int value);
int JY_GetPNGXY(int fileid, int picid, int* w, int* h, int* xoff, int* yoff);
int JY_GetPicXY(int fileid, int picid, int* w, int* h, int* xoff, int* yoff);
SDL_Texture* CreatePicSurface32(unsigned char* data, int w, int h, int datalong);
int LoadPallette(char* filename);
