#include "Student.h"

student::student()
{
}

student::student(int id, string name, string pwd)
{
	this->m_id = id;
	this->m_name = name;
	this->m_pwd = pwd;
	neworder();
}

void student::menu()
{
	cout << "1.����ԤԼ" << endl;
	cout << "2.�鿴�ҵ�ԤԼ" << endl;
	cout << "3.�鿴����ԤԼ" << endl;
	cout << "4.ȡ��ԤԼ" << endl;
	cout << "0.�˳���¼" << endl;
}

void student::apply()
{
	string day, time;
	int id;
	cout << "�������ԤԼ���ڣ�" << endl;
	cin >> day;
	cout << "�������ԤԼʱ��Σ�8��00-18��00��" << endl;
	cin >> time;
	cout << "����Ϊ��ԤԼ������Ϣ" << endl;
	getcomp();
	cout << "��������ҪԤԼ������id" << endl;
	cin >> id;
	//�ж��Ƿ��ظ�ԤԼ
	for (auto t = vorder.begin(); t != vorder.end(); t++) {
		if (t->name == this->m_name && t->day == day && t->time == time && t->id == id) {
			cout << "�ظ�ԤԼ" << endl;
			return;
		}
	}
	//¼��������Ϣ
	Order a(this->m_name,day, time, id);
	vorder.push_back(a);
	fstream ob;
	ob.open(f_order, ios::out );
	for (auto t = vorder.begin(); t != vorder.end(); t++) {
		ob <<t->name<<"  " << t->day << " " << t->time << " " << t->id <<" " <<t->sta<< endl;
	}
	ob.close();
	cout << "����ɹ�" << endl;




}

void student::showmyapply()
{
	for (auto t = vorder.begin(); t != vorder.end(); t++) {
		if (t->name == m_name) {
			cout << " ���ڣ�" << t->day << " ʱ�䣺" << t->time << " ����id��" << t->id<<"  ���״̬��0����Ϊ����У�1�������ͨ����2�������δͨ��) ��" <<t->sta<< endl;
		}
}
}

void student::showallapply()
{
	for (auto t = vorder.begin(); t != vorder.end(); t++) {
		
			cout << " ���ڣ�" << t->day << " ʱ�䣺" << t->time << " ����id��" << t->id << "  ���״̬��0����Ϊ����У�1�������ͨ����2�������δͨ��) ��" << t->sta << endl;
	}
}

void student::cancel()
{
	
	string day, time;
	int id;
	cout << "��������ȡ��ԤԼ�����ڣ�" << endl;
	cin >> day;
	cout << "��������ȡ��ԤԼ��ʱ��Σ�8��00-18��00��" << endl;
	cin >> time;
	cout << "��������ȡ��ԤԼ�Ļ�����id" << endl;
	cin >> id;
	for (auto t = vorder.begin(); t != vorder.end();t++) {
		if (t->name==this->m_name&&t->day == day && t->time == time && t->id == id) {
			t=vorder.erase(t);
		}
		cout << "��ȡ�����ԤԼ����" << endl;
		
	}

	fstream ob;
	ob.open(f_order, ios::out);
	for (auto t = vorder.begin(); t != vorder.end(); t++) {
		ob << t->name << "  " << t->day << " " << t->time << " " << t->id << " " << t->sta << endl;
	}
	ob.close();
	
}

void student::getcomp()
{
	int id, num;
	vector<computer>a;
	computer v;
	fstream o;
	o.open(f_comp, ios::in);
	while (o>>v.id&&o>>v.number)
	{
		a.push_back(v);
	}
	o.close();
	for (auto t = a.begin(); t != a.end(); t++) {
		cout << "id:" << t->id << "����������" << t->number << endl;
	}
}
//��ʼ����������
void student::neworder()
{
	vorder.clear();
	fstream oa;
	Order a;
	oa.open(f_order, ios::in);
	while (oa>>a.name&&oa >> a.day && oa >> a.time && oa >> a.id&&oa>>a.sta) {
		vorder.push_back(a);
	}
	oa.close();
}
