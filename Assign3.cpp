//============================================================================
// Name        : Assign3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<cstdlib>
#include <cmath>
#include <iostream>
using namespace std;


//Comment test
double func_1(double x, double intensity)
{
	
	for(int i=0; i<intensity; i++)
	{
		x=11; 
		x=x*x; 
	}
	return x;
}





double integral (double a, double b, int N, int intensity)
{

	double sum=0;

	 for(int i=0; i<N; i++)
			{
				const double h= (b-a)/N;
				sum+= func_1(( (a + i+.5) *(h))*(h),intensity);

			}
		return sum;
	}

int main(int argc, char *argv[])
{
	if(argc==5)
	{
	
	double a; 
	double b; 
	int N; 
	int intensity; 
	
	a= atof(argv[1]); 
	b=atof(argv[2]); 
	N=atoi(argv[3]); 
	intensity=atoi(argv[4]); 
	
		
	double x= integral(a,b,N,intensity);	
	cout << x << endl;
	}
	
	
	
	

}
