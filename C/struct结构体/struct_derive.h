#pragma once

/****************************************************
C�������� struct ���ʵ�ּ̳С���װ����̬
note:
�̳�: �ڴ沼�ֻ�struct����ǰ
��װ: .h����struct, .c����struct (ʵ��˽�л�)
��̬:
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
//������:
//   ����structʵ�ֻ�struct����ָ������ǿת


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
