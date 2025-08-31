#ifndef _NEOS_RDST_CORE_H
#define _NEOS_RDST_CORE_H

/* 
* NEOR的基本抽号算法模块——头文件
*/

#include<stdlib.h>
#include<stdio.h>

#include"rdrules.h"
#include"../include/syscompile.h"

//结构体:_Seats
//功能：存放座位信息
struct _Seats
{
    int pernum;                 //总人数
    int numAvail;               //待抽人数
    int* stlist;                //座位列表，使用时需初始化
};

//函数: initSeat
//作用: 初始化座位表
//返回值:int整型, 0为正常,-1为错误
int 
initSeat(
    struct _Seats* seatlist ,   //传入的座位表指针
    int     pernum          ,   //人数
    int     arMode              //排号规则
);

//函数：gotoSeat
//作用：由座位表中的次序定位座位
//返回值：int整型，正数表示被抽到的座位号，-1表示超出范围，-2错误(未实现)
int
gotoSeat(
    struct _Seats* seatlist,    //传入的座位表指针
    int     stOrder             //座位在座位表中的次序
);

//函数：rmSeat
//作用：移去座位至座位表后端，但不删除
//返回值: int整型，正数为剩余人数，-1为座位表需重置，-2为出现错误(未实现)
int
rmSeat(
    struct _Seats* seatlist,    //传入的座位表指针
    int     stOrder             //待删除的座位在座位表中的次序
);

//函数：
//作用：
//返回值：
#endif