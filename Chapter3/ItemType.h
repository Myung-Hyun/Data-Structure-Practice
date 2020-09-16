// The following declarations and definitions go into file 
// ItemType.h. 

#include <fstream>
#include <iostream>
using namespace std;
const int MAX_ITEMS = 20;
enum RelationType  {LESS, GREATER, EQUAL};

class ItemType 
{ 
public:
  ItemType();
  RelationType ComparedTo(ItemType) const;
  void Print(std::ostream&) const;
  void Initialize(int number);
  int Value() const;


  /*friend istream& operator >>(istream& in, ItemType& n)
  {
	  in >> n.value;
	  return in;
  }

  friend ostream& operator <<(ostream& out, ItemType& n)
  {
	  out << n.value;
	  return out;
  }*/



  ItemType operator +(ItemType a)
  {
	  ItemType result;
	  result.value = this->value + a.value;
	  return result;
  }


private:
  int value;
};
 
