#pragma once
class User
{
public:
	CString password;
	CString account;
	User();
	virtual ~User();
};
//Admin ������
class Admin :public User
{
public:
	CString id;//����Ա���
	Admin(CString a, CString p, CString i); \
	~Admin();
};
//Pet ������
class Pet :public User
{
	public:
	CString id;//������
	CString name;//������
	CString type;//��������
	CString age;//��������
	CString weight;//��������
	CString value;//����۸�
	CString character;//�����Ը�
	CString owner;//��������
	CString date;//��������
	CString state;//����״̬
	CString customer;//�˿�
	Pet(CString a, CString p, CString i, CString n, CString t, CString ag, CString w,CString v,CString c,
		CString ow,CString da,CString st,CString cu);
	~Pet();
};




