#pragma once
#include"Identity.h"
#include"Computer.h"
#include"order.h"
class student :public identity {
public:
	student();//默认构造
	student(int id,string name, string pwd);//有参构造
	virtual void menu();
	void apply();//申请预约

	void showmyapply();//查看我的预约

	void showallapply();//查看所有预约

	void cancel();//取消预约

	int m_id;//学生学号
	void getcomp();
	vector<Order>vorder;
	void neworder();
};