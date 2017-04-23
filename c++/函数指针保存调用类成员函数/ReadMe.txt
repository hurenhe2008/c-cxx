
��C++���Ա�����ĺ���ָ���ȡ �� ʹ�á�

 C++��Ա������ ��̬��Ա��������ͨ��Ա����(��������Ա����)�����Ա����
 
 
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
    
 private��
    void callFuncPtr() 
    {
        sFunc sfunc = &A::staticMember;
        
        Func cmmfunc = &A::commonMember;
        Func cntfunc = &A::constMember;
        Func virfunc = &A::virtualMember;
        
        /*��̬��Ա�������ã� static member call*/
        sfunc();
        (*sfunc)();
        
        /*��ͨ���������Ա�������ã� common / const / virtual member*/
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
    
    /*��̬��Ա�������ã� static member call*/
    sfunc();
    (*sfunc)();
    
    /*��ͨ���������Ա�������ã� common / const / virtual member*/
    (a.*cmmfunc)();
    (a.*cntfunc)();
    (a.*virfunc)();
 
    return 0;
 }
 
 