#pragma once

/****************************************************
C编译器下 struct 如何实现继承、封装、多态
note:
继承: 内存布局基struct靠最前
封装: .h声明公共struct, .c定义私有struct
多态: 内存布局增加虚标指针, 模拟C++多态实现
auth:
renhehu  -2020.01.07
****************************************************/


//公共、私有化: 
//    .h: 定义公共结构体 (即类的公有函数/公有成员)
//    .c: 定义私有结构体 (即类的私有函数/私有成员, 公有结构体为第一个成员)
//另:
//    .h: 提供公有接口 (创建/销毁)
//    .c: 实现公有接口


/* define public struct  */
typedef struct struct_pub_s
{
    /* member func */
    void(*ppub_func)(struct_pub_t *);

    /* member */
    int mm;
} struct_pub_t;


/* public interface to use struct */
void create_pub_struct(struct_pub_t **);

void detroy_pub_struct(struct_pub_t **);
