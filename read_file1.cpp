#include<iostream>
#include<fstream>
using namespace std;
int main(int argc,char **argv)
{
	if(argc!=2)
	{
		cout<<"USAGE: ./a.out filename"<<endl;
		return 0;
	}
	ifstream fin(argv[1]);
	string s;
	char ch;
	while((ch=fin.get())!=EOF)
		cout<<ch<<" ";
		cout<<endl;
	fin.clear();
	fin.seekg(0,ios::beg);
	
	while(fin>>s)
	cout<<s<<" ";
	cout<<endl;
	fin.clear();
	fin.seekg(0,ios::beg);

	while(getline(fin,s))
	cout<<s<<endl;
	fin.clear();
	fin.seekg(0,ios::beg);
}
	
