#include<iostream>
#include<cstring>
using namespace std;
class STRING
{
	char *s;
	public:
		STRING()
		{
			cout<<"Constructor"<<endl;
			s=0;
		}
		~STRING()
		{
			cout<<"Destructor"<<endl;
			delete []s;
		}
		void set_data()
		{
			char a[30];
			s=new char[30];
			cout<<"Enter The String: "<<endl;
			cin.getline(a,30);
			strcpy(s,a);
		}
		void get_data()
		{
			cout<<s<<endl;
		}
		void delete_char()
		{
			int i,j,k;
			for(i=0;s[i];i++)
			{
				for(j=i+1;s[j];j++)
				{
					if(s[i]==s[j])
					{
						for(k=j;s[k];k++)
						s[k]=s[k+1];
						j--;
					}
				}
			}
		}
		friend void my_strrev(STRING &);
};

void my_strrev(STRING &m)
{
	int i,j,len=0;
	char temp;
	len=strlen(m.s);
	for(i=0,j=len-1;i<j;i++,j--)
	{
		temp=m.s[i];
		m.s[i]=m.s[j];
		m.s[j]=temp;
	}
}

int main()
{
	STRING s1;
	s1.set_data();
	s1.get_data();
	s1.delete_char();
	s1.get_data();
	s1.set_data();
	my_strrev(s1);
	s1.get_data();
}
