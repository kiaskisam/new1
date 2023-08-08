#pragma once
#include"globafile.h"
#include<string>
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;
class identity {
public:
	virtual void menu() = 0;
	string m_name;
	string m_pwd;

};