#pragma once
#include"Identity.h"
#include"Computer.h"
#include"order.h"
class student :public identity {
public:
	student();//Ĭ�Ϲ���
	student(int id,string name, string pwd);//�вι���
	virtual void menu();
	void apply();//����ԤԼ

	void showmyapply();//�鿴�ҵ�ԤԼ

	void showallapply();//�鿴����ԤԼ

	void cancel();//ȡ��ԤԼ

	int m_id;//ѧ��ѧ��
	void getcomp();
	vector<Order>vorder;
	void neworder();
};