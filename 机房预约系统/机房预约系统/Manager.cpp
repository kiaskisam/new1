#include "Manager.h"

void Mangager::menu()
{
	cout << "1.����˺�" << endl;
	cout << "2.�鿴�˺�" << endl;
	cout << "3.��ʾ����״̬" << endl;
	cout << "4.���ԤԼ��¼" << endl;
	cout << "0.�˳��˺�" << endl;
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
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;
	cin >> s;
	if (s == 1) {
		tip = "����ѧ��ѧ��";
		filename = f_student;
	}
	else if(s==2) {
		tip = "�����ʦ����";
		filename = f_teacher;
	}
	else {
		cout << "��������" << endl;
		system("cls");
	}
	string name, pwd;
	int id;
	fstream o;
	o.open(filename, ios::in | ios::app);
	cout << tip << endl;
	cin >> id;
	if (checkrepeat(id,s) ){
		cout << "�����Ѵ���,���Ժ�����" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����������" << endl;
	cin >> name;
	cout << "�������룺" << endl;
	cin >> pwd;
	o << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;
	newvector();//��������
	system("pause");
	system("cls");

	o.close();
}

void Mangager::search()
{
	int s;
	cout << "1.��ʾ�����˺���Ϣ" << endl;
	cout << "2.�����˺�" << endl;
	cin >> s;
	switch (s) {
	case(1):
		cout << "ѧ����Ϣ��" << endl;
		cout << "ѧ��������" << vstu.size()<<endl;
		for (auto t = vstu.begin(); t != vstu.end(); t++) {
			cout << t->m_id << " " << t->m_name << endl;
		}
		
		cout << "-----------------" << endl;
		cout << "��ʦ��Ϣ" << endl;
		cout << "��ʦ������" << vtea.size() << endl;
		for (auto t = vtea.begin(); t != vtea.end(); t++) {
			cout << t->m_tid << " " << t->m_name << endl;
		}
		system("pause");
		system("cls");
		break;
	case(2):
		int d;
		cout << "1.��������" << endl;
		cout << "2.���Ż�ѧ�Ų���" << endl;
		cin >> d;
		if (d == 1) {
			string name;
			int cha;
			cout << "������������(ѧ��/��ʦ)"<<endl;
			cin>>cha;
			cout << "������Ҷ�������" << endl;
			cin >> name;
			if (cha == 1) {
				for (auto t = vstu.begin(); t != vstu.end(); t++) {
					if (t->m_name == name) {
						cout << "���ҳɹ������Ҷ���Ϊѧ������Ϣ����" << endl;
						cout << t->m_id << " " << t->m_name << endl;
						return;
					}
				}
			}
			if (cha == 2) {
				for (auto t = vtea.begin(); t != vtea.end(); t++) {
					if (t->m_name == name) {
						cout << "���ҳɹ������Ҷ���Ϊ��ʦ����Ϣ����" << endl;
						cout << t->m_tid << " " << t->m_name << endl;
						return;
					}
				}
			}
			cout << "���Ҷ��󲻴���" << endl;
		}
		if (d == 2) {
			int id;
			int ch;
			cout << "������Ҷ������(1.ѧ��/2.��ʦ)" << endl;
			cin >> ch;
			cout << "������Ҷ��󹤺Ż�ѧ��" << endl;
			cin >> id;
			if (ch == 1) {
				for (auto t = vstu.begin(); t != vstu.end(); t++) {
					if (t->m_id == id) {
						cout << "���ҳɹ������Ҷ���Ϊѧ������Ϣ����" << endl;
						cout << t->m_id << " " << t->m_name << endl;
						return;
					}
				}
			}
			if (ch == 2) {
				for (auto t = vtea.begin(); t != vtea.end(); t++) {
					if (t->m_tid == id) {
						cout << "���ҳɹ������Ҷ���Ϊ��ʦ����Ϣ����" << endl;
						cout << t->m_tid << " " << t->m_name << endl;
						return;
					}
				}
			}
			cout << "���Ҷ��󲻴���" << endl;
		}
	}
	

}
void Mangager::showcomp()
{
	cout << "����������" << vcomp.size()<<endl;
	for (auto t = vcomp.begin(); t != vcomp.end(); t++) {
		cout << "����id��" << t->id << "������ʹ��������" << t->number << endl;
	}
}

void Mangager::clean()
{
	fstream o;
	o.open(f_order, ios::trunc);//����ļ�����������ļ����´���
	o.close();
	cout << "����ɹ�" << endl;
	system("pause");
	system("cls");
}

void Mangager::newvector()
{
	fstream os;
	os.open(f_student, ios::in);
	if (!os.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	vstu.clear();
	vtea.clear();
	//��ȡѧ����Ϣ
	student a;
	while (os >> a.m_id && os >> a.m_name && os >> a.m_pwd) {
		vstu.push_back(a);
	}
	//cout << "ѧ������Ϊ��" << vstu.size() << endl;
	os.close();
	//��ȡѧ����Ϣ
	os.open(f_teacher, ios::in);

	Teacher b;
	while (os >> b.m_tid && os >> b.m_name && os >> b.m_pwd) {
		vtea.push_back(b);
	}
	//cout << "��ʦ����Ϊ��" << vtea.size() << endl;
	os.close();
	
}

void Mangager::newcomp()
{//��ȡ������Ϣ
	fstream os;
	os.open(f_comp, ios::in);
	computer c;
	while (os >> c.id && os >> c.number) {
		vcomp.push_back(c);
	}
	//cout << "��������" << vcomp.size() << endl;
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
