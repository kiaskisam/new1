#pragma once
#include"Identity.h"
#include"order.h"
#include<fstream>
class Teacher :public identity {
public:
	Teacher();
	Teacher(int id,string name,string pwd);
	virtual void menu();
	void showallapply();//查看所有预约
	void valid();//审核预约
	int m_tid;
	void newty();
	vector<Order>vto;
};