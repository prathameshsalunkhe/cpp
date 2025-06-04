#include<iostream>
#include<cstring>
using namespace std;
class shallow
{
	char *s;
	public:
		shallow(const char *p)
		{
			cout<<"Parameter Constructot"<<endl;
			s=new char[strlen(p)+1];
			strcpy(s,p);
		}
		void modify()
		{
			s[0]='S';
		}
		void print()
		{
			cout<<"s="<<s<<endl;
		}
};

int main()
{
	shallow a("Vector");
	shallow b=a;
	a.modify();
	a.print();
	b.print();
}

