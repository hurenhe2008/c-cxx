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


//继承: 依赖内存布局
//   ------------------                       ------------------ 
//   |    基struct    |      -->  基struct:   |   struct funs  |
//   |----------------|                       |----------------| 
//   |  子struct funs |                       |   struct mems  |
//   |----------------|                       ------------------
//   |  子struct mems |
//   ------------------

//方法一:
//   匿名struct实现基struct
//方法二:
//   匿名struct实现基struct、并指针类型强转


typedef struct base_s
{
    /* member function */
    void(*pfunc)();

    /* member */
    int mm;
} base_t;

typedef struct derive_s
{
    /* inherit base */
    base_t base;

    /* member function */
    void(*pfunc)();

    /* member */
    int nn;
} derive_t;


typedef struct derive2_s
{
    /* annoymous struct */
    struct
    {
        void(*pfunc1)();
        int mm;
    };

    /* member function */
    void(*pfunc2)();

    /* member */
    int nn;
} derive2_t;


void test_struct()
{
    derive_t d;
    base_t *pb = (base_t *)&d;
    pb->mm;

    derive2_t d2;
    d2.mm;
    d2.nn;
}
