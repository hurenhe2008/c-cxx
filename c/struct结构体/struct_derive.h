#pragma once

/****************************************************
C�������� struct ���ʵ�ּ̳С���װ����̬
note:
�̳�: �ڴ沼�ֻ�struct����ǰ
��װ: .h��������struct, .c����˽��struct
��̬: �ڴ沼���������ָ��, ģ��C++��̬ʵ��
auth:
renhehu  -2020.01.07
****************************************************/


//�̳�: �����ڴ沼��
//   ------------------                       ------------------ 
//   |    ��struct    |      -->  ��struct:   |   struct funs  |
//   |----------------|                       |----------------| 
//   |  ��struct funs |                       |   struct mems  |
//   |----------------|                       ------------------
//   |  ��struct mems |
//   ------------------


//����һ:
//   ����structʵ�ֻ�struct
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


//������:
//   ����structʵ�ֻ�struct����ָ������ǿת
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
