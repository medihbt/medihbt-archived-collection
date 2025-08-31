/* 
* NEOR的基本抽号算法模块——源文件
*/

//系统库
#include<stdlib.h>
#include<unistd.h>
#include<stdint.h>

//自带库
#include"rdcore.h"
#include"../include/syscompile.h"

int initSeat(struct _Seats *seatlist, int pernum, int arMode)
{
    if(seatlist==0x0)return -1;
    seatlist->stlist=(int*)malloc(sizeof(int)*(pernum+2));
    //if arMode = 1
    for (int count = 0; count <= pernum; count++)
    {
        seatlist->stlist[count]=count+1;
    }
    seatlist->pernum  = pernum;
    seatlist->numAvail= pernum;
    return 0;
}

int gotoSeat(struct _Seats* seatlist, int stOrder)
{
    if (stOrder > seatlist->pernum)return -1;
    return seatlist->stlist[stOrder];
}

int rmSeat(struct _Seats* seatlist, int stOrder)
{
    if (seatlist->numAvail == 0)return -1;
    int* stLstTmp = seatlist->stlist;       //座位列表
    int  stLstAva = seatlist->numAvail - 1; //待抽的最后一个座位次序
    int  tmp=0;
    tmp = stLstTmp[stOrder];
    stLstTmp[stOrder] = stLstTmp[stLstAva];
    stLstTmp[stLstAva]= tmp;                //交换待抽的最后一个座位与被抽到的那个
    seatlist->numAvail --;                  //人数减一
    return seatlist->numAvail;
}
