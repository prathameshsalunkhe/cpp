#include<iostream>
using namespace std;
class Student
{
	string name;
	int roll;
	public:
		void set_data()
		{
			cout<<"Enter The Name & Roll No"<<endl;
			cin>>name>>roll;
		}

		void get_data()
		{
			cout<<"Roll No: "<<roll<<" "<<"Name: "<<name<<endl;
		}
};

class exam:public Student
{
	int a[6];
	public:
		void set_data()
		{				
			int i;
			cout<<"Enter The Name & Roll no"<<endl;
			cin>>name>>roll;
			cout<<"Enter The Marks"<<endl;
			for(i=0;i<6;i++)
				cin>>a[i];
		}
		void get_data()
		{
			
