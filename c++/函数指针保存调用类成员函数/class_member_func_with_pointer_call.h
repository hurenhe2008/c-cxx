#ifndef _CLASS_MEMBER_FUNC_WITH_POINTER_CALL_H_
#define _CLASS_MEMBER_FUNC_WITH_POINTER_CALL_H_


//【 如何利用函数指针保存和引用“C++类成员函数”？ 】
// C++类成员函数分：(普通、虚成员函数保存、引用一致)
//     静态成员函数 (static)
//     普通成员函数 (normal)
//     常成员函数 (const)
//     虚成员函数 (virtual)

// how to use: 
//     Test a;
//     a.call1();
//     a.call2();


class Test;
typedef void(*smFunc1)(void);
typedef void(Test::*mFunc1)(void);
typedef void(Test::*cmFunc1)(void)const;

class Test
{
    typedef void(*smFunc2)(void);
    typedef void(Test::*mFunc2)(void);
    typedef void(Test::*cmFunc2)(void)const;

public:
    Test();
    void call1();
    void call2();

private:
    static void static_func(void) {}
    void member_func(void) {}
    virtual void virtual_func(void) {}
    void cmember_func(void) const {}

private:
    smFunc1  m_smfunc1;
    mFunc1   m_nmfunc1;
    mFunc1   m_vmfunc1;
    cmFunc1  m_cmfunc1;

    smFunc2  m_smfunc2;
    mFunc2   m_nmfunc2;
    mFunc2   m_vmfunc2;
    cmFunc2  m_cmfunc2;
};


Test::Test()
{
    m_smfunc1 = &Test::static_func;
    m_nmfunc1 = &Test::member_func;
    m_cmfunc1 = &Test::cmember_func;
    m_vmfunc1 = &Test::virtual_func;

    m_smfunc2 = &Test::static_func;
    m_nmfunc2 = &Test::member_func;
    m_cmfunc2 = &Test::cmember_func;
    m_vmfunc2 = &Test::virtual_func;
}

void Test::call1()
{
    (*m_smfunc1)();
    (this->*m_nmfunc1)();  (*this.*m_nmfunc1)();
    (this->*m_vmfunc1)();  (*this.*m_vmfunc1)();
    (this->*m_cmfunc1)();  (*this.*m_cmfunc1)();
 }

void Test::call2()
{
    (*m_smfunc2)();
    (this->*m_nmfunc2)();  (*this.*m_nmfunc2)();
    (this->*m_vmfunc2)();  (*this.*m_vmfunc2)();
    (this->*m_cmfunc2)();  (*this.*m_cmfunc2)();
}

#endif //_CLASS_MEMBER_FUNC_WITH_POINTER_CALL_H_
