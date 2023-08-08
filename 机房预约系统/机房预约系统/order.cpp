#include "order.h"

Order::Order()
{
}

Order::Order(string name,string d, string t, int i)
{
	this->name = name;
	this->day = d;
	this->time = t;
	this->id = i;
	sta = 0;
}
