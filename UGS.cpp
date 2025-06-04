#include<iostream>
using namespace std;

class student
{
	protected:
		int roll,age;
		string name;
	public:
		student()
		{
			cout<<"constructor"<<endl;
		}
		virtual void set_data()
		{
			cout<<"Enter Name,Roll No & age"<<endl;
			cin>>name>>roll>>age;
		}
		virtual void get_data()
		{
			cout<<name<<" "<<roll<<" "<<age<<endl;
		}
};

class UGStudent:public student
{
	protected:
		int fees;
		string sem;
		int date;
	public:
		void set_data()
		{
			cout<<"Enter Name,Roll No,Age,Fees,Sem,Date"<<endl;
			cin>>name>>roll>>age>>fees>>sem>>date;
		}
		void get_data()
		{
			cout<<"UGStudent name: "<<name<<" "<<roll<<" "<<age<<" "<<fees<<" "<<sem<<" "<<date<<endl;
		}
};

class PGStudent:public student
{
	protected:
		int fees;
		string sem;
		int date;
	public:
		void set_data()
		{
			cout<<"Enter Name,Roll No,Age,Fees,Sem,Date"<<endl;
			cin>>name>>roll>>age>>fees>>sem>>date;
		}
		void get_data()
		{
			cout<<"PGStudent name: "<<name<<" "<<roll<<" "<<age<<" "<<fees<<" "<<sem<<" "<<date<<endl;
		}
};

int main()
{
	UGStudent obj1;
	PGStudent obj2;
	int n,op;
	cout<<"Enter Number Of Student"<<endl;
	cin>>n;
	student *obj[n];

	while(1)
	{
		cout<<"Enter Options"<<endl;
		cout<<"1)Enter Student Data 2)Display Data 3)Average Age 4)Exit"<<endl;
		cin>>op;

		try
		{
			switch(op)
			{
				case 1:int i,st_op;
					for(i=0;i<n; )
					{
					   cout<<"Please Select For1)UGStudent 2)PGStudent"<<endl;
					   cin>>st_op;
					   if(st_op==1)
					   {
					   	obj[i]=new UGStudent;
						obj[i]->set_data();
						i++;
					   }
					   else if(st_op==2)
					   {
					   	obj[i]=new PGStudent;
						obj[i]->set_data();
						i++;
					   }

					   else
					   	throw "Invalid Option";
					 }
					 break;
				case 2:int j;
					cout<<"Display Student Data"<<endl;
					for(j=0;j<n;j++)
						obj[j]->get_data();
					break;
				case 4:exit(0);
				default:throw "Invalid Option";

			}

		}
		catch(const char *p)
		{
			cout<<"Error: "<<p<<endl;
		}
	}
}
