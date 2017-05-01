#ifndef __CLASS_MEMBER_POINTER2_H__
#define __CLASS_MEMBER_POINTER2_H__


//【 如何利用函数指针保存和引用“C++类成员函数”？ 】
// C++类成员函数分：(普通、虚成员函数保存、引用一致)
//     静态成员函数 (static)
//     普通成员函数 (normal)
//     常成员函数 (const)
//     虚成员函数 (virtual)

// how to use: 
//     Test a;
//     a.call();

class Test
{
    typedef void(*smFunc)(void);
    typedef void(Test::*mFunc)(void);
    typedef void(Test::*cmFunc)(void)const;

public:
    Test();
    void call();

private:
    static void static_func(void) {}
    void member_func(void) {}
    virtual void virtual_func(void) {}
    void cmember_func(void) const {}

private:
    smFunc  m_smfunc;
    mFunc   m_nmfunc;
    mFunc   m_vmfunc;
    cmFunc  m_cmfunc;
};

Test::Test()
{
    m_smfunc = &Test::static_func;
    m_nmfunc = &Test::member_func;
    m_cmfunc = &Test::cmember_func;
    m_vmfunc = &Test::virtual_func;
}

void Test::call()
{
    (*m_smfunc)();
    (this->*m_nmfunc)();  (*this.*m_nmfunc)();
    (this->*m_vmfunc)();  (*this.*m_vmfunc)();
    (this->*m_cmfunc)();  (*this.*m_cmfunc)();
}

void use_4_member_func()
{
    Test a;
    
    a.call();
}

#endif //__CLASS_MEMBER_POINTER2_H__

