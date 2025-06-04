#include<iostream>
using namespace std;
template<class type>
class wife;

template<class type>
class husband;

template<class type>
void total_salary(wife<type>&,husband<type>&);

template<class type>
class wife
{
	   	type salary;
	public:
		wife()
		{
			salary=0;
		}
		void set_data()
		{
			cout<<"Enter A Salary Amount: "<<endl;
			cin>>salary;
		}
		void get_data()
		{
			cout<<"Individual Salary: "<<salary<<endl;
		}
		~wife()
		{
			cout<<"Destructor"<<endl;
		}
	friend void total_salary<type>(wife<type>&,husband<type>&);
};

template<class type>
class husband
{
		type salary_1;
	public:
		husband()
		{
			salary_1=0;
		}
		void set_data()
		{
			cout<<"Enter A Salary Amount: "<<endl;
			cin>>salary_1;
		}
		void get_data()
		{
			cout<<"Individual Salary: "<<salary_1<<endl;
		}
		~husband()
		{
			cout<<"Destructor"<<endl;
		}
	friend void total_salary<type>(wife<type>&,husband<type>&);
};

template<class type>
void total_salary(wife<type>&obj,husband<type>&obj1)
{
	type total_salary;

	total_salary=obj.salary+obj1.salary_1;
	cout<<"Total Salary= "<<total_salary<<endl;
}

int main()
{
	wife<int>w_int;
	wife<float>w_float;
	husband<int>h_int;
	husband<float>h_float;
	w_int.set_data();
	w_int.get_data();
	h_int.set_data();
	h_int.get_data();
	total_salary(w_int,h_int);
}
