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
	void add();//����˺�
	void search();//�鿴�˺�
	void showcomp();//�鿴������Ϣ
	void clean();//���ԤԼ��¼
	void newvector();//��ȡѧ������ʦ��Ϣ
	void newcomp();//��ȡ������Ϣ
	bool checkrepeat(int id,int type);
	vector<student>vstu;
	vector<Teacher>vtea;
	vector<computer>vcomp;
};