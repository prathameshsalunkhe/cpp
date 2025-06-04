#include<iostream>
using namespace std;
int i;
class A
{
	int *a,ele;
	public:
		A()
		{
			cout<<"Enter The Number Of Elements: "<<endl;
			cin>>ele;
			a=new int[ele];
		}
		~A()
		{
			delete []a;
		}
		void set_data()
		{
			cout<<"Enter The Elements: "<<endl;
			for(i=0;i<ele;i++)
			cin>>a[i];
		}
		void get_data()
		{
			for(i=0;i<ele;i++)
			cout<<a[i]<<" ";
			cout<<endl;
		}
		int prime_sum()
		{
			int j,sum;
			for(i=0,sum=0;i<ele;i++)
			{
				for(j=2;j<a[i];j++)
				{
					if(a[i]%j==0)
					break;
				}
				if(a[i]==j)
					sum+=a[i];
			}
			return sum;
		}
		friend void arm(A &);
			

};

void arm(A &b)
{
	int temp,c,d,a,mul,sum;
	for(i=0;i<b.ele;i++)
	{
		for(temp=b.a[i],c=0;temp;temp/=10,c++);
		for(temp=b.a[i],sum=0;temp;temp/=10)
		{
			for(a=temp%10,d=0,mul=1;d<c;d++)
				mul*=a;
				sum+=mul;
		}
		if(sum==b.a[i])
			cout<<b.a[i]<<endl;
	}
}

int main()
{
	A obj1;
	int sum=0;
	obj1.set_data();
	obj1.get_data();
	sum=obj1.prime_sum();
	cout<<"Sum= "<<sum;
	cout<<endl;
	arm(obj1);

}

