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
		void del_dup()
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
		friend void dig_rev(STRING &);
		friend void my_strrev(STRING &);
};

void dig_rev(STRING &t)
{
	int i,j,l,k;
	char temp;
	for(i=0;t.s[i];i=j+1)
	{	
		for(l=i;t.s[l]!=' '&&t.s[l]!='\0';l++);
		for(j=i;t.s[j]!=' '&&t.s[j]!='\0';j++)
		{
			if(!(t.s[j]>='0'&&t.s[j]<='9'||t.s[j]>='A'&&t.s[j]<='Z'||t.s[j]>='a'&&t.s[j]<='z'))
			{
				for(k=i,l=l-1;k<l;k++,l--)
				{
					temp=t.s[k];
					t.s[k]=t.s[l];
					t.s[l]=temp;
				}
			}
		}
	}
}

void my_strrev(STRING &t)
{
	int i,j,len;
	char temp;
	len=strlen(t.s);
	for(i=0,j=len-1;i<j;i++,j--)
	{
		temp=t.s[i];
		t.s[i]=t.s[j];
		t.s[j]=temp;
	}
}
					
int main()
{
	STRING s1,s2,s3;
	s1.set_data();
	s1.del_dup();
	s1.get_data();
	s2.set_data();
	dig_rev(s2);
	s2.get_data();
	s3.set_data();
	my_strrev(s3);
	s3.get_data();
}

