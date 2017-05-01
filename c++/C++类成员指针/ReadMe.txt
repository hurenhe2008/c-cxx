//////////////////////////////////////////////////////////////////////////////////////////
-- class_member_pointer.h

【C++类成员指针】
	C++类成员指针： 类成员函数指针、类数据成员指针
@define:
    T C::*pmem = &C::member;

@use:
    classobj.*pmem;
    classptr->*pmem;




//////////////////////////////////////////////////////////////////////////////////////////
-- class_member_pointer1.h

【C++类成员函数指针数组】
	C++类成员函数指针数组使用
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

【C++类成员函数的函数指针获取 及 使用】
	 C++成员函数分 静态成员函数、普通成员函数(包括常成员函数)、虚成员函数
 
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
 
 
 void use()
 {
    sFunc sfunc = &A::staticMember;
    Func cmmfunc = &A::commonMember;
    Func cntfunc = &A::constMember;
    Func virfunc = &A::virtualMember;
    
    /*静态成员函数调用： static member call*/
    sfunc();
    (*sfunc)();
    
	A a;
	A *p = &a;

    /*普通、常、虚成员函数调用： common / const / virtual member*/
    (a.*cmmfunc)();
    (a.*cntfunc)();
    (a.*virfunc)();

	/*普通、常、虚成员函数调用： common / const / virtual member*/
	(p->*cmmfunc)();
	(p->*cntfunc)();
	(p->*virfunc)();
 }