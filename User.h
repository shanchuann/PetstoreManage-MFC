#pragma once
class User
{
public:
	CString password;
	CString account;
	User();
	virtual ~User();
};
//Admin 类声明
class Admin :public User
{
public:
	CString id;//管理员编号
	Admin(CString a, CString p, CString i); \
	~Admin();
};
//Pet 类声明
class Pet :public User
{
	public:
	CString id;//宠物编号
	CString name;//宠物名
	CString type;//宠物种类
	CString age;//宠物年龄
	CString weight;//宠物体重
	CString value;//宠物价格
	CString character;//宠物性格
	CString owner;//宠物主人
	CString date;//交易日期
	CString state;//交易状态
	CString customer;//顾客
	Pet(CString a, CString p, CString i, CString n, CString t, CString ag, CString w,CString v,CString c,
		CString ow,CString da,CString st,CString cu);
	~Pet();
};




