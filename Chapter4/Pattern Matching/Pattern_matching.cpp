#include <iostream>
#include <fstream>
#include "sorted.h"

using namespace std;


int main()
{
	
	string inquiry;
	string pattern;
	SortedType dict;

	ifstream fsIn("Words.txt"); 
	if (!fsIn)
	{
		cerr << "Input file open failure\a\n";
		exit(100);
	}

	//Words.txt(dictionary)에서 문자열을 한 줄씩 읽어와서 sorted list(dict)에 저장한다.  
	
	while (!fsIn.eof())
	{
		string str;
		getline(fsIn, str);

		ItemType temp;
		temp.Initialize(str);

		dict.InsertItem(temp);
	}

	int length = dict.LengthIs();
	/* Words.txt의 5줄이 각 한줄마다 sorted list의 item으로 들어갔는지 확인하는 코드
	dict.ResetList();
	for (int i = 0; i < 5; i++)
	{
		ItemType item;
		dict.GetNextItem(item);
		item.Print(cout);
		cout << endl;
	}*/
	fsIn.close();


	//inquiry의 pattern 부분을 sorted list의 string과 비교한다.
	
	while (inquiry != "STOP")
	{
		cout << "Example : STARTING <round>, STARTING <hard>" << endl; 
		cout << "Example : ENDING <skin>, ENDING <vegetable>" << endl; 
		cout << "Example : CONTAINING <round>, CONTAINING <salads>" << endl;
		cout << "\'STOP something\' when you wanna stop program" << endl;
		cin >> inquiry;  //STARTING 
		cin >> pattern;  //<pattern>
		
		int index_f=pattern.find("<",0);
		int index_l = pattern.find(">", 0);
		string temp;
		for (int i = index_f+1; i < index_l;i++)
		{
			
			temp += pattern[i]; //
		}
		pattern = temp; //<> 제거.

		if (inquiry == "STARTING")
		{
			dict.Start(pattern);

		}
		else if (inquiry == "ENDING")
		{
			dict.End(pattern);
		}
		else if (inquiry =="CONTAING")
		{
			dict.Contain(pattern);
		}
		else
		{

		}

	}

	return 0;
};



/* Words.txt
apple: a hard, round fruit with a green or red skin
banana: a long, white fruit with a yellow skin
melon: a large, round, sweet fruit with a thick, green or yellow skin
tomato: a soft, round, red fruit eaten in salads or as a vegetable
potato: a round, white vegetable that grows in the ground
*/




