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


//多态(单继承虚表实现): 
//    结构体第一个成员: 虚表指针
//    结构体存在继承关系时:
//        1. 父结构体不存在虚函数时，复用基结构体的虚表指针
//        2. 父结构体存在虚函数时，替换基结构体的虚表指针
//多继承 比较复杂, 理解多态原理、照样能实现
//虚继承 更复杂, 可参考反汇编


/* base virtual table */
typedef struct vptr_base_table_s
{
    /* virtual funcs */
    void(*pvfunc1)(void *);

} vptr_base_table_t;

/* derive virtual table */
typedef struct vptr_derive_table_s
{
    /* base table */
    vptr_base_table_t vptr_base_table;

    /* new virtual funcs */
    void(*pvfunc2)(void *);

} vptr_derive_table_t;


/* base struct */
typedef struct struct_base_s
{
    /* virtual table ptr */
    const void * const pvptr;

    /* member func */
    void(*pbase_func)(void *);

    /* member */
    int m;
} struct_base_t;

/* just base has virtual function */
typedef struct struct_derive_s
{
    /* vptr base struct */
    struct_base_t base;

    /* member */
    void(*pderive_func)(void *);

    int n;
} struct_derive_t;

/* derive has virtual function (base virtual function maybe override) */
typedef struct struct_derive2_s
{
    /* vptr derive table */
    struct_base_t base;

    /* member */
    void(*pvptr_derive_func)(void *);

    int n;
} struct_derive2_t;



/* derive: no self virtual function */
void create_derive_struct(struct_derive_t **);

void do_derive_struct(struct_derive_t *);

void destroy_derive_struct(struct_derive_t **);


/* derive: self virtual function */
void create_vptr_derive_struct(struct_derive2_t **);

void do_vptr_derive_struct(struct_derive2_t *);

void destroy_vptr_derive_struct(struct_derive2_t **);


/* derive: self virtual function and override base virtual function */
void create_vptr_derive_override_struct(struct_derive2_t **);

void do_vptr_derive_override_struct(struct_derive2_t *);

void destroy_vptr_derive_override_struct(struct_derive2_t **);


