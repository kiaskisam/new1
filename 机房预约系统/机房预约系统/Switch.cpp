#include "Switch.h"

void Switch::mu()
{
	int sw;
	while(true){
		cout << "欢迎使用机房预约系统" << endl;
		cout << "选择你的操作身份" << endl;
		cout << "1.学生" << endl;
		cout << "2.教师" << endl;
		cout << "3.管理员" << endl;
		cout << "4.退出" << endl;
		cout << "---------------------" << endl;
		cin >> sw;
		switch (sw)
		{
		case(1):
			loginln(f_student, sw);
			break;
		case(2):
			loginln(f_teacher, sw);
			break;
		case(3):
			loginln(f_manger, sw);
			break;
		case(4):
			cout << "欢迎下次使用" << endl;
			exit(0);
			break;
		default:
			cout << "输入有误" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

}

void Switch::loginln(string filename, int type)
{
	string name,pwd;
	int id;
	identity* person = NULL;
	fstream os;
	os.open(filename, ios::in);
	if (!os.is_open()) {
		cout << "文件打开失败" << endl;
		os.close();
		return;
	}
	if (type == 1) {
		cout << "输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "输入你的工号" << endl;
		cin >> id;
	}
	if (type == 1) {
		cout << "输入你的姓名：" << endl;
		cin >> name;
		cout << "输入你的密码：" << endl;
		cin >> pwd;
		string fname, fpwd;
		int fid;
		while (os >> fid && os >> fname && os >> fpwd) {
			if (  id == fid&&name == fname && pwd == fpwd) {
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				person = new student(id, name, pwd);
				stumenu(person);
				return;
			}
		}
	}
	else if (type == 2) {
		cout << "输入你的姓名：" << endl;
		cin >> name;
		cout << "输入你的密码：" << endl;
		cin >> pwd;
		string fname, fpwd;
		int fid;
		while (os >> fid && os >> fname && os >> fpwd) {
			if (id == fid && name == fname && pwd == fpwd) {
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				temenu(person);
				return;
			}
		}
	}
	else if (type == 3) {
		cout << "输入你的姓名：" << endl;
		cin >> name;
		cout << "输入你的密码：" << endl;
		cin >> pwd;
		string fname, fpwd;
		int fid;
		while (os >> fname && os >> fpwd) {
			if (name == fname&& pwd == fpwd) {
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				person = new Mangager(name, pwd);
				mangermenu(person);
				return;
			}
		}
	}
	cout << "登录失败" << endl;
}
//manger菜单,此为多态思想(复习)，也可以直接作为成员函树,可以看看下面一种函数（错误的）
void Switch::mangermenu(identity*& manager)//对(identity*) & manager,对identity指针的引用,即person
{while(true){
	manager->menu();
	Mangager* man = (Mangager*)manager;//使其强制转换为子类，使其可以调用子类成员
	int selet;
	cin >> selet;
	switch (selet) {
	case(1):
		man->add();
		break;
	case(2):
		man->search();
		break;
	case(3):
		man->showcomp();
		break;
	case(4):
		man->clean();
		break;
		
	}
	if (selet == 0) {
		delete manager;
		system("pause");
		system("cls");

		return;
	}


}
}
//person为identity类所以无法使用一下函数
//void Switch::mangermen(Mangager*& man)//对(identity*) & manager,对identity指针的引用,即person
//{
//	while (true) {
//		man->menu();
//		//Mangager* man = (Mangager*)manager;//使其强制转换为子类，使其可以调用子类成员
//		int selet;
//		cin >> selet;
//		switch (selet) {
//		case(1):
//			man->add();
//			break;
//		case(2):
//			man->search();
//			break;
//		case(3):
//			man->showcomp();
//			break;
//		case(4):
//			man->clean();
//			break;
//
//		}
//		if (selet == 0) {
//			delete man;
//			system("pause");
//			system("cls");
//
//			return;
//		}
//
//
//	}
//}
void Switch::stumenu(identity*& stu)
{
	while (true) {
		student* man = (student*)stu;
		man->menu();
		int c;
		cin >> c;
		switch (c) {
		case(1):
			man->apply();
			break;
		case(2):
			man->showmyapply();
			break;
		case(3):
			man->showallapply();
			break;
		case(4):
			man->cancel();
			break;

		}
		if (c == 0) {
			delete stu;
			system("pause");
			system("cls");
			return;
		}
	}
}

void Switch::temenu(identity*& te)
{
	while (true) {
		Teacher* man = (Teacher*)te;
		man->menu();
		int s;
		cin >> s;
		switch (s) {
		case (1):
			man->showallapply();
			break;
		case(2):
			man->valid();
			break;
		}
		if (s == 0) {
			delete te;
			system("pause");
			system("cls");
			return;
		}

}
}

