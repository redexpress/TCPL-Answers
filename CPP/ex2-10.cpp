#include <iostream>

using std::cout;
using std::endl;
using std::string;

string lower(string str){
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

int main(){
	cout << lower("A") << endl;
	return 0;
}