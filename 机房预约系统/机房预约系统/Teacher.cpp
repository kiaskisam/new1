#include "Teacher.h"

Teacher::Teacher()
{
}

Teacher::Teacher(int id, string name, string pwd)
{
	m_tid = id;
	m_name = name;
	m_pwd = pwd;
	//初始化预约
	newty();

}

void Teacher::menu()
{
	cout << "1.查看所有预约" << endl;
	cout << "2.审核预约" << endl;
	cout << "0.退出登录" << endl;
}

void Teacher::showallapply()
{
	for (auto t = vto.begin(); t != vto.end(); t++) {
		cout << " 日期：" << t->day << " 时间：" << t->time << " 机房id：" << t->id << "  审核状态（0代表为审核中，1代表审核通过,2代表审核未通过) ：" << t->sta << endl;
}
}

void Teacher::valid()
{
	for (auto t = vto.begin(); t != vto.end(); t++) {
		if (t->sta == 0) {
			cout << " 日期：" << t->day << " 时间：" << t->time << " 机房id：" << t->id << endl;
			int ch;
			cout << "输入审核结构：1.通过 2.不通过" << endl;
			cin >> ch;
			t->sta = ch;
			system("pause");
		}
	}
	fstream oa;
	oa.open(f_order, ios::out);
	for (auto t = vto.begin(); t != vto.end(); t++) {
		oa << t->name << "  " << t->day << " " << t->time << " " << t->id << " " << t->sta << endl;
	}
}

void Teacher::newty()
{
	vto.clear();
	Order a;
	fstream o;
	o.open(f_order, ios::in);
	while (o >> a.name && o >> a.day && o >> a.time && o >> a.id && o >> a.sta) {
		vto.push_back(a);
	}
	o.close();
}
