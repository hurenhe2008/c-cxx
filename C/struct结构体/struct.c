#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef NULL
#define nullptr NULL
#else
#define nullptr 0
#endif

/* private struct define */
typedef struct struct_pri_s
{
    /* public */
    struct_pub_t pub;

    /* private */
    void(*pfunc)();

    int nn;
} struct_pri_t;

/* struct_pri_t::pfunc */
void func()
{
    return;
}


void create_pub_struct(struct_pub_t **ppPub)
{
    if (!ppPub)
        return;

    struct_pri_t *ptmp = (struct_pri_t *)malloc(sizeof(struct_pri_t));
    ptmp->pub.mm = 0;
    ptmp->nn = 0;

    *ppPub = (struct_pub_t *)ptmp;
}

void do_pub_struct(struct_pub_t *pPub)
{
    if (!pPub)
        return;

    struct_pri_t *ptmp = (struct_pri_t *)pPub;

    ptmp->pfunc();
}

void detroy_pub_struct(struct_pub_t **ppPub)
{
    if (!ppPub || !*ppPub)
        return;

    free((void *)*ppPub);

    *ppPub = nullptr;
}