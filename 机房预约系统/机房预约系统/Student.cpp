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
	cout << "1.申请预约" << endl;
	cout << "2.查看我的预约" << endl;
	cout << "3.查看所有预约" << endl;
	cout << "4.取消预约" << endl;
	cout << "0.退出登录" << endl;
}

void student::apply()
{
	string day, time;
	int id;
	cout << "输入你的预约日期：" << endl;
	cin >> day;
	cout << "输入你的预约时间段（8：00-18：00）" << endl;
	cin >> time;
	cout << "以下为可预约机房信息" << endl;
	getcomp();
	cout << "输入你所要预约机房的id" << endl;
	cin >> id;
	//判断是否重复预约
	for (auto t = vorder.begin(); t != vorder.end(); t++) {
		if (t->name == this->m_name && t->day == day && t->time == time && t->id == id) {
			cout << "重复预约" << endl;
			return;
		}
	}
	//录入申请信息
	Order a(this->m_name,day, time, id);
	vorder.push_back(a);
	fstream ob;
	ob.open(f_order, ios::out );
	for (auto t = vorder.begin(); t != vorder.end(); t++) {
		ob <<t->name<<"  " << t->day << " " << t->time << " " << t->id <<" " <<t->sta<< endl;
	}
	ob.close();
	cout << "申请成功" << endl;




}

void student::showmyapply()
{
	for (auto t = vorder.begin(); t != vorder.end(); t++) {
		if (t->name == m_name) {
			cout << " 日期：" << t->day << " 时间：" << t->time << " 机房id：" << t->id<<"  审核状态（0代表为审核中，1代表审核通过，2代表审核未通过) ：" <<t->sta<< endl;
		}
}
}

void student::showallapply()
{
	for (auto t = vorder.begin(); t != vorder.end(); t++) {
		
			cout << " 日期：" << t->day << " 时间：" << t->time << " 机房id：" << t->id << "  审核状态（0代表为审核中，1代表审核通过，2代表审核未通过) ：" << t->sta << endl;
	}
}

void student::cancel()
{
	
	string day, time;
	int id;
	cout << "输入你所取消预约的日期：" << endl;
	cin >> day;
	cout << "输入你所取消预约的时间段（8：00-18：00）" << endl;
	cin >> time;
	cout << "输入你所取消预约的机房的id" << endl;
	cin >> id;
	for (auto t = vorder.begin(); t != vorder.end();t++) {
		if (t->name==this->m_name&&t->day == day && t->time == time && t->id == id) {
			t=vorder.erase(t);
		}
		cout << "已取消你的预约申请" << endl;
		
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
		cout << "id:" << t->id << "容纳人数：" << t->number << endl;
	}
}
//初始化申请容器
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
