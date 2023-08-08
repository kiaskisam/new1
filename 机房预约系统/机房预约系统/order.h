#pragma once
#include<iostream>
#include<string>
using namespace std;
class Order {
public:
	Order();
	Order(string name,string d,string t,int i);
	string day;
	string time;
	string name;
	int id;
	int sta;

};