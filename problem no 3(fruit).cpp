//Q.No 3
//Create a class named Fruit with a data member to calculate the number of fruits in a basket.
//Create two other class named Apples and Mangoes to calculate the number of apples and mangoes in the basket. 
//Print the number of fruits of each type and the total number of fruits in the basket.(Inheritance)

#include<iostream>
using namespace std;
class apples
{
	private:
		double apple;
	public:
		void geta(double a)
		{
			apple=a;
		}
		void displaya()
		{
			cout<<"\nThe number of apples are "<<apple;
		}	
};
class mangoes
{
	private:
		double mango;
	public:
		void getb(double b)
		{
			mango=b;
		}
		void displayb()
		{
			cout<<"\nThe number of mangoes are "<<mango;
		}	
};
class fruit:public apples,public mangoes
{
	protected:
		double totalf;
	public:
		fruit()
		{
			totalf=0;
		}
	friend void sum(double a,double b);
};
void sum(double a,double b)
{
	cout<<"\nTotal number of fruits in basket are "<<(a+b);
}
int main()
{
	double c=20,d=20;
	fruit obj;
	obj.geta(c);
	obj.displaya();
	obj.getb(d);
	obj.displayb();
	sum(c,d);
}
