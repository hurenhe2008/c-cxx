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


//������˽�л�: 
//    .h: �����ṹ�嶨��
//    .c: ˽�нṹ�嶨��(���нṹ����Ϊ��һ����Ա)
//����:
//    .h: �ṩ���нӿ� (����/����/����)
//    .c: ʵ�ֹ��нӿ�


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
