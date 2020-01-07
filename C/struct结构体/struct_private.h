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


//˽�л�: 
//    .h: �ṹ������
//    .c: �ṹ�嶨��
//����:
//    .h: �ṩ���нӿ� (����/����/����)
//    .c: ʵ�ֹ��нӿ�


/* just declare struct. */
typedef struct struct_pri_s struct_pri_t;


/* public interface to use struct */
void create_pri_struct(struct_pri_t **);

void get_pri_struct(struct_pri_t *, int *);

void set_pri_struct(struct_pri_t *, int);

void do_pri_struct(struct_pri_t *);

void detroy_pri_struct(struct_pri_t **);



  
