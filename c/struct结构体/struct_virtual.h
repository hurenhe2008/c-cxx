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


//��̬(���̳����ʵ��): 
//    �ṹ���һ����Ա: ���ָ��
//    �ṹ����ڼ̳й�ϵʱ:
//        1. ���ṹ�岻�����麯��ʱ�����û��ṹ������ָ��
//        2. ���ṹ������麯��ʱ���滻���ṹ������ָ��
//��̳� �Ƚϸ���, ����̬ԭ��������ʵ��
//��̳� ������, �ɲο������


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


