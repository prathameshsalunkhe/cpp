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
			cout<<"Destructor"<<endl;
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
			cout<<"Array Elements: "<<endl;
			for(i=0;i<ele;i++)
				cout<<a[i]<<" ";
				cout<<endl;
		}
		int sum_perfect()
		{
			int j,sum,sum1;
			for(i=0,sum1=0;i<ele;i++)
			{
				for(j=1,sum=0;j<a[i];j++)
				{
					if(a[i]%j==0)
					sum+=j;
				}
				if(sum==a[i])
				sum1+=a[i];
			}
			return sum1;
		}
		friend void arms(A &);
};

void arms(A &t)
{
	int j,c,d,temp,sum,mul;
	for(i=0;i<t.ele;i++)
	{
		for(temp=t.a[i],c=0;temp;temp/=10,c++);
		for(temp=t.a[i],sum=0;temp;temp/=10)
		{
			for(j=temp%10,d=0,mul=1;d<c;d++)
				mul*=j;
				sum+=mul;
		}
		if(sum==t.a[i])
			cout<<t.a[i]<<endl;
	}
}

int main()
{
	A obj;
	int sum;
	obj.set_data();
	obj.get_data();
	sum=obj.sum_perfect();
	cout<<"Sum="<<sum<<endl;
	arms(obj);
}
	
