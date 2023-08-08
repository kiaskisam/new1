#include "Manager.h"

void Mangager::menu()
{
	cout << "1.添加账号" << endl;
	cout << "2.查看账号" << endl;
	cout << "3.显示机房状态" << endl;
	cout << "4.清除预约记录" << endl;
	cout << "0.退出账号" << endl;
}

Mangager::Mangager()
{
}

Mangager::Mangager(string name, string pwd)
{
	m_name = name;
	m_pwd = pwd;
	newvector();
	newcomp();
}

void Mangager::add()
{
	string filename,tip;
	int s;
	cout << "--------------" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;
	cin >> s;
	if (s == 1) {
		tip = "输入学生学号";
		filename = f_student;
	}
	else if(s==2) {
		tip = "输入教师工号";
		filename = f_teacher;
	}
	else {
		cout << "输入有误" << endl;
		system("cls");
	}
	string name, pwd;
	int id;
	fstream o;
	o.open(filename, ios::in | ios::app);
	cout << tip << endl;
	cin >> id;
	if (checkrepeat(id,s) ){
		cout << "对象已存在,请查对后输入" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "输入姓名：" << endl;
	cin >> name;
	cout << "输入密码：" << endl;
	cin >> pwd;
	o << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;
	newvector();//更新容器
	system("pause");
	system("cls");

	o.close();
}

void Mangager::search()
{
	int s;
	cout << "1.显示所有账号信息" << endl;
	cout << "2.查找账号" << endl;
	cin >> s;
	switch (s) {
	case(1):
		cout << "学生信息：" << endl;
		cout << "学生人数：" << vstu.size()<<endl;
		for (auto t = vstu.begin(); t != vstu.end(); t++) {
			cout << t->m_id << " " << t->m_name << endl;
		}
		
		cout << "-----------------" << endl;
		cout << "教师信息" << endl;
		cout << "教师人数：" << vtea.size() << endl;
		for (auto t = vtea.begin(); t != vtea.end(); t++) {
			cout << t->m_tid << " " << t->m_name << endl;
		}
		system("pause");
		system("cls");
		break;
	case(2):
		int d;
		cout << "1.姓名查找" << endl;
		cout << "2.工号或学号查找" << endl;
		cin >> d;
		if (d == 1) {
			string name;
			int cha;
			cout << "输入查找人身份(学生/教师)"<<endl;
			cin>>cha;
			cout << "输入查找对象姓名" << endl;
			cin >> name;
			if (cha == 1) {
				for (auto t = vstu.begin(); t != vstu.end(); t++) {
					if (t->m_name == name) {
						cout << "查找成功，查找对象为学生，信息如下" << endl;
						cout << t->m_id << " " << t->m_name << endl;
						return;
					}
				}
			}
			if (cha == 2) {
				for (auto t = vtea.begin(); t != vtea.end(); t++) {
					if (t->m_name == name) {
						cout << "查找成功，查找对象为教师，信息如下" << endl;
						cout << t->m_tid << " " << t->m_name << endl;
						return;
					}
				}
			}
			cout << "查找对象不存在" << endl;
		}
		if (d == 2) {
			int id;
			int ch;
			cout << "输入查找对象身份(1.学生/2.教师)" << endl;
			cin >> ch;
			cout << "输入查找对象工号或学号" << endl;
			cin >> id;
			if (ch == 1) {
				for (auto t = vstu.begin(); t != vstu.end(); t++) {
					if (t->m_id == id) {
						cout << "查找成功，查找对象为学生，信息如下" << endl;
						cout << t->m_id << " " << t->m_name << endl;
						return;
					}
				}
			}
			if (ch == 2) {
				for (auto t = vtea.begin(); t != vtea.end(); t++) {
					if (t->m_tid == id) {
						cout << "查找成功，查找对象为教师，信息如下" << endl;
						cout << t->m_tid << " " << t->m_name << endl;
						return;
					}
				}
			}
			cout << "查找对象不存在" << endl;
		}
	}
	

}
void Mangager::showcomp()
{
	cout << "机房数量：" << vcomp.size()<<endl;
	for (auto t = vcomp.begin(); t != vcomp.end(); t++) {
		cout << "机房id：" << t->id << "机房可使用人数：" << t->number << endl;
	}
}

void Mangager::clean()
{
	fstream o;
	o.open(f_order, ios::trunc);//如果文件存在则清空文件重新创建
	o.close();
	cout << "清除成功" << endl;
	system("pause");
	system("cls");
}

void Mangager::newvector()
{
	fstream os;
	os.open(f_student, ios::in);
	if (!os.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}
	vstu.clear();
	vtea.clear();
	//读取学生信息
	student a;
	while (os >> a.m_id && os >> a.m_name && os >> a.m_pwd) {
		vstu.push_back(a);
	}
	//cout << "学生数量为：" << vstu.size() << endl;
	os.close();
	//读取学生信息
	os.open(f_teacher, ios::in);

	Teacher b;
	while (os >> b.m_tid && os >> b.m_name && os >> b.m_pwd) {
		vtea.push_back(b);
	}
	//cout << "教师数量为：" << vtea.size() << endl;
	os.close();
	
}

void Mangager::newcomp()
{//读取机房信息
	fstream os;
	os.open(f_comp, ios::in);
	computer c;
	while (os >> c.id && os >> c.number) {
		vcomp.push_back(c);
	}
	//cout << "机房数量" << vcomp.size() << endl;
	os.close();
}

bool Mangager::checkrepeat(int id,int type)
{
	if (type == 1) {
		for (auto t = vstu.begin(); t != vstu.end(); t++) {
			if (id == t->m_id) {
				return true;
			}
		}
}   
	if (type == 2) {
		for (auto t = vtea.begin(); t != vtea.end(); t++) {
			if (id == t->m_tid) {
				return true;
			}
		}
	}
	return false;
}
