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


//������˽�л�: 
//    .h: ���幫���ṹ�� (����Ĺ��к���/���г�Ա)
//    .c: ����˽�нṹ�� (�����˽�к���/˽�г�Ա, ���нṹ��Ϊ��һ����Ա)
//��:
//    .h: �ṩ���нӿ� (����/����)
//    .c: ʵ�ֹ��нӿ�


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
