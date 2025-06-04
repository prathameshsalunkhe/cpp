#include<iostream>
using namespace std;
int i;
class arr
{
	int *a,ele;
	public:
		arr()
		{
			cout<<"Enter The Number Of Elements"<<endl;
			cin>>ele;
			a=new int[ele];
		}
		~arr()
		{
			delete []a;
		}		
		void set_data()
		{
			cout<<"Enter The Elements"<<endl;
			for(i=0;i<ele;i++)
			cin>>a[i];
		}
		void get_data()
		{
			for(i=0;i<ele;i++)
			cout<<a[i]<<" ";
			cout<<endl;
		}
		int sum_prime()
		{	
			int sum,j;
			for(i=0,sum=0;i<ele;i++)
			{
				for(j=2;j<a[i];j++)
				{
					if(a[i]%j==0)
					break;
				}
				if(j==a[i])
					sum+=a[i];
			}
			return sum;
		}
		friend void arm_fun(arr &);
};

void arm_fun(arr &a)
{
	int c,temp,mul,sum,d,b;
	for(i=0;i<a.ele;i++)
	{
		for(c=0,temp=a.a[i];temp;temp/=10,c++);
		for(temp=a.a[i],sum=0;temp;temp/=10)
		{
			for(b=temp%10,d=0,mul=1;d<c;d++)
				mul*=b;
				sum+=mul;
		}
		if(sum==a.a[i])
			cout<<a.a[i]<<endl;
	}
}

int main()
{
	arr a;
	int sum;
	a.set_data();
	a.get_data();
	sum=a.sum_prime();
	cout<<"sum= "<<sum<<endl;
	cout<<"Armstrong number"<<endl;
	arm_fun(a);
}


