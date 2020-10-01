// The following definitions go into file ItemType.cpp. 
#include <fstream>
#include <iostream>
#include "ItemType.h"


using namespace std;

ItemType::ItemType()
{ 
  value = "";
}

RelationType ItemType::ComparedTo(ItemType otherItem) const 
{
  if (value < otherItem.value)
    return LESS;
  else if (value > otherItem.value)
    return GREATER;
  else return EQUAL;
}

void ItemType::Initialize(string number) 
{
  value = number;
}

void ItemType::Print(std::ostream& out) const 
// pre:  out has been opened.
// post: value has been sent to the stream out.
{
  out << value;
}

int ItemType::Find_start(string str) const //,까지 재할당한 문자열에서 찾는다.
{
	int index = 0;
	int comma = 0;
	comma = (this->value).find(",",0);
	
	string temp =(this->value).substr(0, comma);
	index = (temp).find(str, 0);


	if (index == std::string::npos)
	{
		return -1;
	}
	return index;
}

int ItemType::Find_end(string str) const //\n을 제외하고 sorted list에 저장되므로 \n을 기준으로 할 수 없다. 문자열 크기를 기준으로 한다.
{
	int index = 0;
	int last = 0;
	last = this->value.length();

	string temp = (this->value).substr(last-10, last);

	index = (temp).find(str, 0);

	if (index == std::string::npos)
	{
		return -1;
	}
	return index;
}

//item이 문자열인데, 문자열에서 원하는 pattern을 찾고 있을 경우 시작위치 없을 경우 -1을 return한다.
int ItemType::Find(string str) const
{
	int index = 0;
	
	index=(this->value).find(str, 0);
	

	if (index == std::string::npos)
	{
		return -1;
	}
	return index;
}


void ItemType::Printname() const
{
	int colon = this->Find(":");
	for (int i = 0; i < colon; i++)
	{
		cout << (this->value)[i];
	}


}