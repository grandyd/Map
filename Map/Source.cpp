#include <iostream>
#include "Map.h"
#include "SortMap.h"
#include "TreeMap.h"
#include <string>
#include "HashMap.h"
#include "MyString.h"
using namespace std;


int main()
{
	HashMap<MyString, int> M;
	M.Add("bb", 123);
	M.Add("ba", 2);
	M.Add("da", 3);
	M.Add("bc", 4);
	cout << M["ba"];
	M.Delete("ba");
	cout << M["ba"];


	//TreeMap<char, int> M;
	//for (int i = 0; i < 10; i++)
	//{
	//	M.Add('a' + i, i);
	//}
	//cout << endl;
	//for (int i = 0; i < 10; i++)
	//{
	//	cout << M['a' + i]<<" ";
	//}
	//M.Delete('c');
	//M.Delete('e');
	//M.Delete('j');
	//cout << endl;
	//for (int i = 0; i < 9; i++)
	//{
	//	cout << M['a' + i]<<" ";
	//}
	//cout << endl;
	
	return 0;
}