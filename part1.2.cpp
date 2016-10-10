

#include<cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;






	double val=0.0; 



double func_1(double x, double intensity)
{
	
	for(int i=0; i<intensity; i++)
	{
		x=11; 
		x=x*x; 
	}
	return 1.0;
}





double integral (double a, double b, int N, int intensity)
{

	double sum=0;

	 for(int i=0; i<N; i++)
			{
				const double h= (b-a)/N;
				sum+= func_1(( (a + i+.5) *(h))*(h),intensity);
				// 				mychunksum += func_1(a + (i+.5) *h ,intensity)  * h;


			}
		return sum;
	}
int startPtNxtChk =  0; 
int n=10000000; 
int chunkSize=100; 	
	bool done() {
	
		if(startPtNxtChk == n)
			return true;
		else return false;
	}
	
	void get_chunk_indices(int * a, int * b) {
		
		*a=startPtNxtChk; 
		*b=startPtNxtChk+chunkSize-1; 
		startPtNxtChk=startPtNxtChk+chunkSize; 
		
	}
int intensity= 10; 
double a=2.23; 
double b=12.24; 

	void* f1(void* p) 
	{   
		int begin, end;
		while(!done()) {
			get_chunk_indices(&begin, &end);
			// printf("I got [%d, %d] ", begin, end);
			// cout << pthread_self() << endl;
			double mychunksum = 0;
			double h= (b-a)/n;
			for(int i = begin; i <= end; i++) {
				mychunksum += func_1(a + (i+.5) *h ,intensity)  * h;
			}
			// cout << "chk: " << h << endl;
			val += mychunksum;
		}
		
	}

int main(int argc, char *argv[])
{
	if(argc==5)
	{
	
	double a; 
	double b; 
	int N, t = 16; 
	int intensity; 
	
	a= atof(argv[1]); 
	b=atof(argv[2]); 
	N=atoi(argv[3]); 
	intensity=atoi(argv[4]); 
		
	double x= integral(a,b,N,intensity);	
	cout << x << endl;
	}
	int t = 16;
	
		pthread_t th[t];
		
	for(int i=0; i<t; i++)	
	{
		pthread_create(&th[i], NULL, f1, NULL);
	}//Creates threads
		
	for (int i=0; i < t; ++i)    
	{
	pthread_join(th[i], NULL);
	
	} //Wait for threads to finish
	cout<<val<< endl; 
}
