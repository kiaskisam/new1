#include "Teacher.h"

Teacher::Teacher()
{
}

Teacher::Teacher(int id, string name, string pwd)
{
	m_tid = id;
	m_name = name;
	m_pwd = pwd;
	//��ʼ��ԤԼ
	newty();

}

void Teacher::menu()
{
	cout << "1.�鿴����ԤԼ" << endl;
	cout << "2.���ԤԼ" << endl;
	cout << "0.�˳���¼" << endl;
}

void Teacher::showallapply()
{
	for (auto t = vto.begin(); t != vto.end(); t++) {
		cout << " ���ڣ�" << t->day << " ʱ�䣺" << t->time << " ����id��" << t->id << "  ���״̬��0����Ϊ����У�1�������ͨ��,2�������δͨ��) ��" << t->sta << endl;
}
}

void Teacher::valid()
{
	for (auto t = vto.begin(); t != vto.end(); t++) {
		if (t->sta == 0) {
			cout << " ���ڣ�" << t->day << " ʱ�䣺" << t->time << " ����id��" << t->id << endl;
			int ch;
			cout << "������˽ṹ��1.ͨ�� 2.��ͨ��" << endl;
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
