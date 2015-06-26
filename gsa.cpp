#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
	int a[50], b[50];
	float fit_value[50];
	for(int i=0;i<50;i++)
	{
		int y, z;
		float x;
		y=rand()%11 - 5;
		z=rand()%11 - 5;
		a[i] = y;
		b[i] = z;
		x=4*y*y-2.1*y*y*y*y+1/3*y*y*y*y*y*y+y*z-4*z*z+4*z*z*z*z;
		fit_value[i] = x;
		cout<<i<<" no "<<a[i]<<"    "<<b[i]<<"   "<<fit_value[i]<<endl;
		
	}
	
	
	return 0;
}
