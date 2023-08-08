#pragma once
#include"Identity.h"
#include"Student.h"
#include"Teacher.h"
#include"Computer.h"
class Mangager :public identity {
public:
	virtual void menu();
	Mangager();
	Mangager(string name, string pwd);
	void add();//添加账号
	void search();//查看账号
	void showcomp();//查看机房信息
	void clean();//清空预约记录
	void newvector();//读取学生和老师信息
	void newcomp();//读取机房信息
	bool checkrepeat(int id,int type);
	vector<student>vstu;
	vector<Teacher>vtea;
	vector<computer>vcomp;
};