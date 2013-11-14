#include <iostream>
#include <sstream>

using std::string;
using std::endl;
using std::cout;

string escape(string str){
	string result = "";
	for(string::iterator it = str.begin(); it != str.end(); it++){
		char c = *it;
		switch(c){
			case '\n':
				result += "\\n";
				break;
			case '\t':
				result += "\\t";
				break;
			case '\\':
				result += "\\\\";
				break;
			default:
				result += c;
				break;
		}
	}
	return result;
}


int main(){
	string source = "one\ttwo\nthree\\four";
	cout << escape(source) << endl;
	return 0;
}