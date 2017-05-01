//////////////////////////////////////////////////////////////////////////////////////////
-- class_member_pointer.h

��C++���Աָ�롿
	C++���Աָ�룺 ���Ա����ָ�롢�����ݳ�Աָ��
@define:
    T C::*pmem = &C::member;

@use:
    classobj.*pmem;
    classptr->*pmem;




//////////////////////////////////////////////////////////////////////////////////////////
-- class_member_pointer1.h

��C++���Ա����ָ�����顿
	C++���Ա����ָ������ʹ��
@define:
	typedef void (Class::*Func)();

	enum EFUNC {
		E_FUNC0 = 0,
		E_FUNC1,
		...
		E_FUNCn
	}

	Func m_arr[n + 1];
	m_arr[0] = &Class::func_0;
	m_arr[1] = &Class::func_1;
	...
	m_arr[n] = &Class::func_n;

@use:
	EFUNC i = E_FUNC0;
	while (i <= E_FUNCn) {
		(this->*m_arr[i])();
		i = EFUNC(i + 1);
	}




//////////////////////////////////////////////////////////////////////////////////////////
-- class_member_pointer2.h

��C++���Ա�����ĺ���ָ���ȡ �� ʹ�á�
	 C++��Ա������ ��̬��Ա��������ͨ��Ա����(��������Ա����)�����Ա����
 
 typedef void(*sFunc)();
 
 class A;
 typdef void(A::*Func)();
 
 class A 
 {
 public:
    static void staticMember() {}     /*static member function*/
    void commonMember(){}             /*common member function*/
    void constMember() const {}       /*const member function*/
    virtual void virtualMember() {}   /*virtual member function*/
    
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
 
 
 void use()
 {
    sFunc sfunc = &A::staticMember;
    Func cmmfunc = &A::commonMember;
    Func cntfunc = &A::constMember;
    Func virfunc = &A::virtualMember;
    
    /*��̬��Ա�������ã� static member call*/
    sfunc();
    (*sfunc)();
    
	A a;
	A *p = &a;

    /*��ͨ���������Ա�������ã� common / const / virtual member*/
    (a.*cmmfunc)();
    (a.*cntfunc)();
    (a.*virfunc)();

	/*��ͨ���������Ա�������ã� common / const / virtual member*/
	(p->*cmmfunc)();
	(p->*cntfunc)();
	(p->*virfunc)();
 }