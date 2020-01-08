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
    void(*ppri_func)(struct_pub_t *);

    int nn;
} struct_pri_t;

/* struct_pri_t::pri_func */
void pri_func(struct_pri_t *pPri)
{
    pPri->nn = 1;

    return;
}

/* struct_pub_t:: */
void pub_func(struct_pub_t *pPub)
{
    if (!pPub)
        return;

    pPub->mm = 1;

    struct_pri_t *ptmp = (struct_pri_t *)pPub;
    ptmp->ppri_func(ptmp);
}

void create_pub_struct(struct_pub_t **ppPub)
{
    if (!ppPub)
        return;

    struct_pri_t *ptmp = (struct_pri_t *)malloc(sizeof(struct_pri_t));
    //public init 
    ptmp->pub.ppub_func = pub_func;
    ptmp->pub.mm = 0;
    //private init
    ptmp->ppri_func = pri_func;
    ptmp->nn = 0;

    *ppPub = (struct_pub_t *)ptmp;
}

void detroy_pub_struct(struct_pub_t **ppPub)
{
    if (!ppPub || !*ppPub)
        return;

    struct_pri_t *ptmp = (struct_pri_t *)(*ppPub);
    free((void *)ptmp);

    *ppPub = nullptr;
}