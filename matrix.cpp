#include<iostream>
#include<cstring>
using namespace std;
class matrix
{
	int **p1,**p2,**p3;
	int r,c,r1,c1;
	public:
		matrix()
		{
			int i;
			cout<<"Enter 1 array a Row & col : "<<endl;
			cin>>r>>c;
			cout<<"Enter 2 array a Row & Col : "<<endl;
			cin>>r1>>c1;

			p1=new int*[r];
			for(i=0;i<r;i++)
				p1[i]=new int[c];

			p2=new int*[r1];
			for(i=0;i<r;i++)
				p2[i]=new int[c1];
	
			p3=new int*[r];
			for(i=0;i<r;i++)
				p3[i]=new int[c1];
		}
		void set_data()
		{
			int i,j;
			cout<<"Enter Array1 Elements: "<<endl;
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
					cin>>p1[i][j];
			}

			cout<<"Enter Array2 Elements: "<<endl;
			for(i=0;i<r1;i++)
			{
				for(j=0;j<c1;j++)
					cin>>p2[i][j];
			}
		}
		void get_data()
		{
			int i,j;
			cout<<"Array1 Elements: "<<endl;
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
					cout<<p1[i][j]<<" ";
					cout<<endl;
			}
			cout<<endl;

			cout<<"Array2 Elements: "<<endl;
			for(i=0;i<r1;i++)
			{
				for(j=0;j<c1;j++)
					cout<<p2[i][j]<<" ";
					cout<<endl;
			}
			cout<<endl;
			
			cout<<"Array3 Elements: "<<endl;
			for(i=0;i<r;i++)
			{
				for(j=0;j<c1;j++)
					cout<<p3[i][j]<<" ";
					cout<<endl;
			}
			cout<<endl;
		}
		void add()
		{
			int i,j;
			//cout<<"ADD :Array3 Elements: "<<endl;
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					p3[i][j]=p1[i][j]+p2[i][j];
					//cout<<p3[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
		}
		/*void mul()
		{
			int i,j;
			cout<<"MUL :Array3 Elements: "<<endl;
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					p3[i][j]=p1[i][j]*p2[i][j];
					cout<<p3[i][j]<<" ";
				}		
			}
			cout<<endl;
		}*/

		~matrix()
		{
			int i;
			cout<<"Destructor"<<endl;
			for(i=0;i<r;i++)
			{
				delete []p1[i];
				delete []p3[i];
			}
			for(i=0;i<r1;i++)
				delete []p2[i];
			delete p1;
			delete p2;
			delete p3;
		}
		friend void mul(matrix &);
};

		void mul(matrix &a)
		{
			int i,j,k,sum;
			//cout<<"MUL :Array3 Elements: "<<endl;
			for(i=0;i<a.r;i++)
			{
				for(j=0;j<a.c1;j++)
				{	
					for(k=0,sum=0;k<a.c;k++)
						sum=sum+(a.p1[i][k]*a.p2[k][j]);
						a.p3[i][j]=sum;
					
				}		
		
			}
		}
	

int main()
{
	matrix ma;
	ma.set_data();
	ma.get_data();
	//ma.add();
	//ma.mul();
	mul(ma);
	ma.get_data();
	
}

