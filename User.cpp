#include "pch.h"
#include "User.h"
#include <cstring>

//User::User()
User::User() {}
User::~User() {}
//Admin 类实现
Admin::Admin(CString a, CString p, CString i) 
{
	account = a;
	password = p;
	id = i;
}
Admin::~Admin() {}
//Pet 类实现
Pet::Pet(CString a, CString p, CString i, CString n, CString t, CString ag, CString w, CString v, CString c,
	CString ow, CString da, CString st, CString cu)
{
	account = a;
	password = p;
	id = i;
	name = n;
	type = t;
	age = ag;
	weight = w;
	value = v;
	character = c;
	owner = ow;
	date = da;
	state = st;
	customer = cu;
}
Pet::~Pet() {}
