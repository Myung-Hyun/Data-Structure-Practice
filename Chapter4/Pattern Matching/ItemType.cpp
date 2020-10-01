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

int ItemType::Find_start(string str) const //,���� ���Ҵ��� ���ڿ����� ã�´�.
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

int ItemType::Find_end(string str) const //\n�� �����ϰ� sorted list�� ����ǹǷ� \n�� �������� �� �� ����. ���ڿ� ũ�⸦ �������� �Ѵ�.
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

//item�� ���ڿ��ε�, ���ڿ����� ���ϴ� pattern�� ã�� ���� ��� ������ġ ���� ��� -1�� return�Ѵ�.
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