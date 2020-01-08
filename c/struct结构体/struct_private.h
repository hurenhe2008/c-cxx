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


//私有化: 
//    .h: 结构体声明
//    .c: 结构体定义
//另外:
//    .h: 提供公有接口 (创建/销毁/其他)
//    .c: 实现公有接口


/* declare private struct in .h */
typedef struct struct_pri_s struct_pri_t;


/* public interface */
void create_pri_struct(struct_pri_t **);

void get_pri_struct(struct_pri_t *, int *);

void set_pri_struct(struct_pri_t *, int);

void do_pri_struct(struct_pri_t *);

void detroy_pri_struct(struct_pri_t **);



  
