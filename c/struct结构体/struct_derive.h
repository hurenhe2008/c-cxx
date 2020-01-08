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
typedef struct base_s
{
    /* member function */
    void(*pbase_func)(void *);

    /* member */
    int mm;
} base_t;

typedef struct derive_s
{
    /* inherit base */
    base_t base;

    /* member function */
    void(*pderive_func)(void *);

    /* member */
    int nn;
} derive_t;


//方法二:
//   匿名struct实现基struct、并指针类型强转
typedef struct derive2_s
{
    /* annoymous struct */
    struct
    {
        void(*pbase_func)(void *);
        int mm;
    };

    /* member function */
    void(*pderive_func)(void *);

    /* member */
    int nn;
} derive2_t;


void test_struct()
{
    derive_t d;
    d.pderive_func(&d);
    /* dynamic_cast<base_t> */
    base_t *pb = (base_t *)&d;
    pb->pbase_func(pb);
    
    derive2_t d2;
    d2.pbase_func(&d2);
    d2.pderive_func(&d2);
}
