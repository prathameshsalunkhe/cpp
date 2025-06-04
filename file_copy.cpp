#include<iostream>
#include<fstream>
using namespace std;
int main(int argc,char **argv)
{
	if(argc!=3)
	{
		cout<<"USAGE: ./a.out src_file dest_file"<<endl;
		return 0;
	}

	ifstream fin(argv[1]);
	if(fin.fail())
	{
		cout<<"File Is Not Present"<<endl;
		return 0;
	}
	ofstream fout(argv[2]);
	string s;

	while(getline(fin,s))
	fout<<s<<endl;

	fin.close();
	fout.close();
}
