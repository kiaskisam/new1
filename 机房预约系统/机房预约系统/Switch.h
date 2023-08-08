#pragma once
#include<iostream>
#include"Manager.h";
#include"Student.h"
#include"Teacher.h"
#include"globafile.h"
#include<fstream>
using namespace std;
class Switch {
public:
	void mu();
	void loginln(string file,int type);
	void mangermenu(identity* & manager);
	//void mangermen(Mangager* & man);
	void stumenu(identity*& stu);
	void temenu(identity*& te);
};