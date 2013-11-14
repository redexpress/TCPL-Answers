#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::string;

bool strend(string const &fullString, string const &ending){
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

int main(){
	string foo = "foo";
	string bar = "bar";
	string foobar = "foobar";
	cout << std::boolalpha << strend(foobar, foo) << endl;
	cout << std::boolalpha << strend(foobar, bar) << endl;

 	return 0;
}

