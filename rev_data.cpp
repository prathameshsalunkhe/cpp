#include<iostream>
using namespace std;
template<class type,size_t n>
void sort_data(type (&p)[n]);

template<class type,size_t n>
void rev_data(type (&p)[n]);

int main()
{
	int a[5]={10,5,7,12,4};
	char s[5]={'A','G','X','B','E'};
	float f[5]={12.3,0.5,4.5,2.6,40.7};

	sort_data(a);
	sort_data(s);
	sort_data(f);

	rev_data(a);
	rev_data(s);
	rev_data(f);
}

template<class type,size_t n>
void sort_data(type (&p)[n])
{
	type t;
	int ele,i,j;
	//ele=sizeof(p)/sizeof(p[0]);
	ele=n;
	cout<<ele<<endl;
	
	for(i=0;i<ele-1;i++)
	{
		for(j=0;j<ele-1-i;j++)
		{
			if(p[j]>p[j+1])
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
		}
	}
	for(i=0;i<ele;i++)
		cout<<p[i]<<" ";
		cout<<endl;

}

template<class type,size_t n>
void rev_data(type (&p)[n])
{
	int ele,i,j;
	type t;
	ele=n;

	for(i=0,j=ele-1;i<j;i++,j--)
		p[i]=p[i]+p[j]-(p[j]=p[i]);
/*	{
		t=p[i];
		p[i]=p[j];
		p[j]=t;
	}
*/
	for(i=0;i<ele;i++)
		cout<<p[i]<<" ";
		cout<<endl;
}
