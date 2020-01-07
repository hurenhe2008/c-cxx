#pragma once

/****************************************************
C编译器下 struct 如何实现继承、封装、多态
note:
继承: 内存布局基struct靠最前
封装: .h声明struct, .c定义struct (实现私有化)
多态:
auth:
renhehu  -2020.01.07
****************************************************/


//公共、私有化: 
//    .h: 公共结构体定义
//    .c: 私有结构体定义(公有结构体作为第一个成员)
//另外:
//    .h: 提供公有接口 (创建/销毁/其他)
//    .c: 实现公有接口


/* just public struct. */
typedef struct struct_pub_s
{
    /* member */
    int mm;
} struct_pub_t;


/* public interface to use struct */
void create_pub_struct(struct_pub_t **);

void do_pub_struct(struct_pub_t *);

void detroy_pub_struct(struct_pub_t **);
