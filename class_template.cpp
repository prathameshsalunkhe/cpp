#include<iostream>
using namespace std;
template<class type>
class Array
{
	type a[5];
	public:
		Array()
		{	
			int i;
			cout<<"Enter The Elements"<<typeid(a).name()<<endl;
			for(i=0;i<5;i++)
				cin>>a[i];
		}

		void get_data()
		{
			int i;
			for(i=0;i<5;i++)
				cout<<a[i]<<" ";
				cout<<endl;
		}

		void reverse()
		{
			int i,j;
			for(i=0,j=4;i<j;i++,j--)
				a[i]=a[i]+a[j]-(a[j]=a[i]);
		}
};

int main()
{
	Array<int> obj1;
	obj1.get_data();
	obj1.reverse();
	obj1.get_data();

	Array<char> obj2;
	obj2.get_data();
	obj2.reverse();
	obj2.get_data();
}
	
