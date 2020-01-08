#include "struct_virtual.h"
#include <memory.h>

#ifdef NULL
#define nullptr NULL
#else
#define nullptr 0
#endif

/* virtual function */
void base_vfunc1(void *p) {
    struct_base_t *pp = (struct_base_t *)p;
}

void derive_vfunc1(void *p) {
    struct_derive_t *pp = (struct_derive_t *)p;
}
void derive_vfunc2(void *p) {
    struct_derive_t *pp = (struct_derive_t *)p;
}

/* virtual table */
vptr_base_table_t s_base_table = 
{
    &base_vfunc1,
};

vptr_derive_table_t s_derive_table = 
{ 
    {
        &base_vfunc1, /* base */
    }, 
    &derive_vfunc2,  
};

vptr_derive_table_t s_derive2_table =
{
    {
        &derive_vfunc1, /* override */
    },
    &derive_vfunc2,  
};

/* init global struct */
struct_derive_t s_derive_tt = { 
    { &s_base_table, nullptr, 0 }, nullptr, 0 
};
struct_derive2_t s_vptr_derive_tt = {
    { &s_derive_table, nullptr, 0 }, nullptr, 0 
};
struct_derive2_t s_vptr_derive2_tt = {
    { &s_derive2_table, nullptr, 0 }, nullptr, 0 
};


void create_derive_struct(struct_derive_t **ppderive)
{
    if (!ppderive)
        return;

    struct_derive_t *ptmp = (struct_derive_t *)malloc(sizeof(struct_derive_t));

    /* derive no self virtual function */
    memmove_s(ptmp, sizeof(s_derive_tt), &s_derive_tt, sizeof(s_derive_tt));

    *ppderive = ptmp;
}

void do_derive_struct(struct_derive_t *pderive)
{
    if (!pderive)
        return;

    /* virtual table */
    vptr_base_table_t *ptable = (vptr_base_table_t *)pderive->base.pvptr;

    /* call with base ptr */
    ptable->pvfunc1((void *)(struct_base_t *)pderive);
}

void destroy_derive_struct(struct_derive_t **ppderive)
{
    if (!ppderive || !*ppderive)
        return;

    free(*ppderive);

    *ppderive = nullptr;
}


void create_vptr_derive_struct(struct_derive2_t **ppvptr_derive)
{
    if (!ppvptr_derive)
        return;

    struct_derive2_t *ptmp = (struct_derive2_t *)malloc(sizeof(struct_derive2_t));
    
    /* derive with self virtual function */
    memmove_s(ptmp, sizeof(s_vptr_derive_tt), &s_vptr_derive_tt, sizeof(s_vptr_derive_tt));

    *ppvptr_derive = ptmp;
}

void do_vptr_derive_struct(struct_derive2_t *pvptr_derive)
{
    if (!pvptr_derive)
        return;

    /* virtual table */
    vptr_derive_table_t *ptable = (vptr_derive_table_t *)pvptr_derive->base.pvptr;

    /* call with base ptr */
    ptable->vptr_base_table.pvfunc1((void *)(struct_base_t *)pvptr_derive);
    
    /* call with derive ptr*/
    ptable->pvfunc2((void *)pvptr_derive);
}

void destroy_vptr_derive_struct(struct_derive2_t **ppvptr_derive)
{
    if (!ppvptr_derive || !*ppvptr_derive)
        return;

    free(*ppvptr_derive);

    *ppvptr_derive = nullptr;
}


void create_vptr_derive_override_struct(struct_derive2_t **ppvptr_derive)
{
    if (!ppvptr_derive)
        return;

    struct_derive2_t *ptmp = (struct_derive2_t *)malloc(sizeof(struct_derive2_t));

    /* derive with self virtual function and override base virrtual function */
    memmove_s(ptmp, sizeof(s_vptr_derive2_tt), &s_vptr_derive2_tt, sizeof(s_vptr_derive2_tt));

    *ppvptr_derive = ptmp;
}

void do_vptr_derive_override_struct(struct_derive2_t *pvptr_derive)
{
    if (!pvptr_derive)
        return;

    /* virtual table */
    vptr_derive_table_t *ptable = (vptr_derive_table_t *)pvptr_derive->base.pvptr;

    /* call with derive ptr */
    ptable->vptr_base_table.pvfunc1((void *)pvptr_derive);

    ptable->pvfunc2((void *)pvptr_derive);
}

void destroy_vptr_derive_override_struct(struct_derive2_t **ppvptr_derive)
{
    if (!ppvptr_derive || !*ppvptr_derive)
        return;

    free(*ppvptr_derive);

    *ppvptr_derive = nullptr;
}