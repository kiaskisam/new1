#include "Switch.h"

void Switch::mu()
{
	int sw;
	while(true){
		cout << "��ӭʹ�û���ԤԼϵͳ" << endl;
		cout << "ѡ����Ĳ������" << endl;
		cout << "1.ѧ��" << endl;
		cout << "2.��ʦ" << endl;
		cout << "3.����Ա" << endl;
		cout << "4.�˳�" << endl;
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
			cout << "��ӭ�´�ʹ��" << endl;
			exit(0);
			break;
		default:
			cout << "��������" << endl;
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
		cout << "�ļ���ʧ��" << endl;
		os.close();
		return;
	}
	if (type == 1) {
		cout << "�������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "������Ĺ���" << endl;
		cin >> id;
	}
	if (type == 1) {
		cout << "�������������" << endl;
		cin >> name;
		cout << "����������룺" << endl;
		cin >> pwd;
		string fname, fpwd;
		int fid;
		while (os >> fid && os >> fname && os >> fpwd) {
			if (  id == fid&&name == fname && pwd == fpwd) {
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new student(id, name, pwd);
				stumenu(person);
				return;
			}
		}
	}
	else if (type == 2) {
		cout << "�������������" << endl;
		cin >> name;
		cout << "����������룺" << endl;
		cin >> pwd;
		string fname, fpwd;
		int fid;
		while (os >> fid && os >> fname && os >> fpwd) {
			if (id == fid && name == fname && pwd == fpwd) {
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				temenu(person);
				return;
			}
		}
	}
	else if (type == 3) {
		cout << "�������������" << endl;
		cin >> name;
		cout << "����������룺" << endl;
		cin >> pwd;
		string fname, fpwd;
		int fid;
		while (os >> fname && os >> fpwd) {
			if (name == fname&& pwd == fpwd) {
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Mangager(name, pwd);
				mangermenu(person);
				return;
			}
		}
	}
	cout << "��¼ʧ��" << endl;
}
//manger�˵�,��Ϊ��̬˼��(��ϰ)��Ҳ����ֱ����Ϊ��Ա����,���Կ�������һ�ֺ���������ģ�
void Switch::mangermenu(identity*& manager)//��(identity*) & manager,��identityָ�������,��person
{while(true){
	manager->menu();
	Mangager* man = (Mangager*)manager;//ʹ��ǿ��ת��Ϊ���࣬ʹ����Ե��������Ա
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
//personΪidentity�������޷�ʹ��һ�º���
//void Switch::mangermen(Mangager*& man)//��(identity*) & manager,��identityָ�������,��person
//{
//	while (true) {
//		man->menu();
//		//Mangager* man = (Mangager*)manager;//ʹ��ǿ��ת��Ϊ���࣬ʹ����Ե��������Ա
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

