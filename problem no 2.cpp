//Write a C++ program to accpet worker information Worker_Name, No_Of_Hours_Worked,
// Pay_Rate and Salary. Write necessary functions to calculate and display 
// the salary of Worker. (Use Default values for Pay_Rate Rs. 500 per hours)



#include<iostream>
#include<string>
using namespace std;
class sal
{
	private:
		string wname;
	    double payrt,noh;
	    double sal;
	public:
		
		void getdata(string name,double wh,double pr)
		{
		    wname=name;
		    noh=wh;
		    payrt=pr;
		}
		int process()
		{
			
			sal=(30*noh*payrt);
			return sal;
			
		}
		void display()
		{
			cout<<"\nName of worker= "<<wname;
			cout<<"\nWorking HRS of worker= "<<noh;
			cout<<"\nPay rate of worker= "<<payrt;
		}
};
int main()
{
	
	string str;
	double w,p=500,a;
	cout<<"\nEnter name of worker= ";
	cin>>str;
	cout<<"\nEnter number of working hrs= ";
	cin>>w;
	sal obj;
	obj.getdata(str,w,p);
	obj.display();
	a=obj.process();
	cout<<"\nSalary of worker= "<<"Rs "<<a;
	
	return 0;
}