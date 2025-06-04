#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
void rev_word(string,int,int);
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

	int start,end,len,temp_start,i,j,k,c,index=0,size;
	string s;
	fio.seekg(0,ios::end);
	size=fio.tellg();
	cout<<size<<endl;
	fio.seekg(0,ios::beg);
	char ch,ch2[size];
	while(getline(fio,s))
	{
		len=s.length();
		for(i=0;s[i];i++)
		{

			for(j=i,c=0;s[i]!=' '&&s[i]!='\0';i++)
			{
				k=i;
				if(((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')))
				{}
				else
				{
					c++;
				}
			}
			if(c>0)
			{
				for(;j<k;j++,k--)
				{
					s[j]=s[j]+s[k]-(s[k]=s[j]);
				}

			}
		}
		cout<<s<<endl;
		for(i=0;s[i];i++)
			ch2[index++]=s[i];
			ch2[index++]='\n';
		
	}
	ch2[index]=0;

	fio.close();
	ofstream fout(argv[1],ios::out);
	fout<<ch2;
	fout.close();

}

