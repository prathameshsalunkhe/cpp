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

	fstream fio(argv[1]);
	if(fio.fail())
	{
		cout<<"File Is Not Present"<<endl;
		return 0;
	}

}

