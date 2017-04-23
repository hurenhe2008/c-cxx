
【C++类成员函数的函数指针获取 及 使用】

 C++成员函数分 静态成员函数、普通成员函数(包括常成员函数)、虚成员函数
 
 
 typedef void(*sFunc)();
 
 class A;
 typdef void(A::*Func)();
 
 class A 
 {
 public:
    static void staticMember() {}
    
    void commonMember(){}
 
    void constMember() const {}
    
    virtual void virtualMember() {}
    
 private：
    void callFuncPtr() 
    {
        sFunc sfunc = &A::staticMember;
        
        Func cmmfunc = &A::commonMember;
        Func cntfunc = &A::constMember;
        Func virfunc = &A::virtualMember;
        
        /*静态成员函数调用： static member call*/
        sfunc();
        (*sfunc)();
        
        /*普通、常、虚成员函数调用： common / const / virtual member*/
        (this->*cmmfunc)();
        (this->*cntfunc)();
        (this->*virfunc)();
    }
    
 };
 
 
 #include <stdio.h>
 
 int main()
 {
    A a;
    
    sFunc sfunc = &A::staticMember;
        
    Func cmmfunc = &A::commonMember;
    Func cntfunc = &A::constMember;
    Func virfunc = &A::virtualMember;
    
    /*静态成员函数调用： static member call*/
    sfunc();
    (*sfunc)();
    
    /*普通、常、虚成员函数调用： common / const / virtual member*/
    (a.*cmmfunc)();
    (a.*cntfunc)();
    (a.*virfunc)();
 
    return 0;
 }
 
 