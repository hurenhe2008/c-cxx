#ifndef __CLASS_MEMBER_POINTER_H__
#define __CLASS_MEMBER_POINTER_H__


/*****************************************************************

@class member pointer include:
    member function pointer,
    member data pointer;

@define:
    T C::*pmem = &C::member;

@use:
    classobj.*pmem;
    classptr->*pmem;

******************************************************************/


class TestClass
{
public:
    typedef void(TestClass::*Func1)();
    typedef int(TestClass::*Func2)(int);
    typedef double(TestClass::*Func3)(int, float);
    TestClass(): m_data1(1), m_data2(2.0) {}

    void func1() {}

    int func2(int) { return 0; }

    double func3(int, float) { return 0.0; }

public://member must be public for outer call
    int    m_data1;

    double m_data2;
};


void use_member_function()
{
    TestClass::Func1 _func1 = &TestClass::func1;
    TestClass::Func2 _func2 = &TestClass::func2;
    TestClass::Func3 _func3 = &TestClass::func3;

    TestClass a;
    TestClass *p = &a;

    // classobj.*pmem;
    (a.*_func1)();
    (a.*_func2)(2);
    (a.*_func3)(2, 1.0);

    // classptr->*pmem;
    (p->*_func1)();
    (p->*_func2)(3);
    (p->*_func3)(3, 1.0);
}

void use_member_data()
{
    int TestClass::*_data1 = &TestClass::m_data1;

    double TestClass::*_data2 = &TestClass::m_data2;

    TestClass a;
    TestClass *p = &a;

    int _d1;
    double _d2;

    // classobj.*pmem;
    _d1 = a.*_data1;
    _d2 = a.*_data2;

    //classptr->*pmem;
    _d1 = p->*_data1;
    _d2 = p->*_data2;
}


#endif //__CLASS_MEMBER_POINTER_H__