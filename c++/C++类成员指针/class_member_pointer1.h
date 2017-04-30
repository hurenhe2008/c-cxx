#ifndef __CLASS_MEMBER_POINTER1_H__
#define __CLASS_MEMBER_POINTER1_H__


/*****************************************************************

@class member pointer include:
member function pointer,
member data pointer;

@define:
T C::*pmem = &C::member;

@use:
classobj.*pmem;
classptr->*pmem;

@dest:
save member function to array, and call with index.

******************************************************************/


class TestClass1
{
public:
    typedef void(TestClass1::*Func)();

    enum STEP{
        E_READY = 0,
        E_SHOW,
        E_HIDE,
        E_FINISH,
        E_TOTALS,  /* sentinel */
    };

    void ready() {}
    void show() {}
    void hide() {}
    void finish() {}

    void call(STEP step);

    TestClass1();

private:
    Func m_func_arr[E_TOTALS];
};

TestClass1::TestClass1()
    : m_func_arr{ 0 }
{
    m_func_arr[E_READY] = &TestClass1::ready;
    m_func_arr[E_SHOW] = &TestClass1::ready;
    m_func_arr[E_HIDE] = &TestClass1::ready;
    m_func_arr[E_FINISH] = &TestClass1::ready;

    m_func_arr[E_TOTALS] = nullptr;
}


void TestClass1::call(TestClass1::STEP step)
{
    if (step < 0 || step >= E_TOTALS) {
        //abort();
        return;
    }

    //classptr->*pmem
    (this->*m_func_arr[step])();

    //classobj.*pmem
    (*this.*m_func_arr[step])();
}

void use_member_func_array()
{
    TestClass1 test;

    TestClass1::STEP i = TestClass1::E_READY;
    for (; i < TestClass1::E_TOTALS; ) {
        test.call(i);
        i = (TestClass1::STEP)(i + 1);
    }
}


#endif //__CLASS_MEMBER_POINTER1_H__
