#pragma once
#include"Identity.h"
#include"order.h"
#include<fstream>
class Teacher :public identity {
public:
	Teacher();
	Teacher(int id,string name,string pwd);
	virtual void menu();
	void showallapply();//�鿴����ԤԼ
	void valid();//���ԤԼ
	int m_tid;
	void newty();
	vector<Order>vto;
};