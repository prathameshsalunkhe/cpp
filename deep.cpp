#include<iostream>
#include<cstring>
using namespace std;
class deep
{
	char *s;
	public:
		deep(const char *p)
		{
			cout<<"Paramiterized Constructor"<<endl;
			s=new char[strlen(p)+1];
			strcpy(s,p);
		}
		deep(deep &temp)
		{
			s=new char[strlen(temp.s)+1];
			strcpy(s,temp.s);
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
	deep a("Vector");
	deep b=a;
	a.modify();
	a.print();
	b.print();
}
