#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool isKeyword(string str)
{
	vector<string> v = {"if", "then", "else", "main", "int", "float"};
	
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i] == str)
			return true;
	}
	return false;
}


int main()
{
	char opt;
	string input;
	
	do {
		cout << endl << "Enter the word you want to check : ";
		cin >> input;
		
		if(isKeyword(input))
			cout << input << " is a keyword\n";
		else
			cout << input << " is not a keyword\n";
		
		cout << endl << "Do you want to check again ? (y/n) :";
		cin >> opt;
		
	} while(opt == 'y' || opt == 'Y');
	
	return 0;
}
