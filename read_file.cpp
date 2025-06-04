#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream fin;
	fin.open("data");
	char s[20];
//	fin>>s;// one word from file read
	fin.getline(s,20);//one line from file read
	fin.close();
	cout<<s<<endl;
}
