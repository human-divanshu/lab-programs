#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	string a = "GeeksForGeeks";
 
    // Here b is an object of regex (regular expression)
    regex b("(Geek)"); // Geeks followed by any character
 
    // regex_match function matches string a against regex b
    if (regex_match(a, b))
        cout << "String 'a' matches regular expression 'b' \n";
    else
    	cout << "Does not match\n" << endl;
 
    // regex_match function for matching a range in string 
    // against regex b
    if (regex_match(a.begin(), a.end(), b))
        cout << "String 'a' matches with regular expression " << "'b' in the range from 0 to string end\n";	
	return 0;
}
