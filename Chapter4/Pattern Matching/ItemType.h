// The following declarations and definitions go into file 
// ItemType.h. 
#pragma once
#include <fstream>
#include <string>

using namespace std;

const int MAX_ITEMS = 30;
enum RelationType  {LESS, GREATER, EQUAL};

class ItemType 
{ 
public:
  ItemType();
  RelationType ComparedTo(ItemType) const;
  void Print(std::ostream&) const;
  void Initialize(string number);
  int Find_start(string) const;
  int Find_end(string) const;
  int Find(string) const;
  void Printname(std::ostream& out) const; //print word name

private:
  string value;
};
 
