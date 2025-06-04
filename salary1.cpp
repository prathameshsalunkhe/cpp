#include<iostream>
using namespace std;
template<class type>
class wife;

template<class type>
class husband;

template<class type1,class type2>
void total_salary(wife<type1>&,husband<type2>&);

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
			cout<<"Enter wife Salary Amount: "<<typeid(salary).name()<<endl;
			cin>>salary;
		}
		void get_data()
		{
			cout<<"Individual wife Salary: "<<salary<<endl;
		}
	template<class type1,class type2>
	friend void total_salary(wife<type1>&,husband<type2>&);
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
			cout<<"Enter husband Salary Amount: "<<typeid(salary_1).name()<<endl;
			cin>>salary_1;
		}
		void get_data()
		{
			cout<<"Individual husband Salary: "<<salary_1<<endl;
		}
	template<class type1,class type2>
	friend void total_salary(wife<type1>&,husband<type2>&);
};


template<class type1,class type2>
void total_salary(wife<type1>&obj,husband<type2>&obj1)
{
	double total_salary;

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
	h_float.set_data();
	h_float.get_data();
	total_salary(w_int,h_float);
}
