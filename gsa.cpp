#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
	int a[50], b[50];
	float fit_value[50], best, wrost;
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
	best = fit_value[0];
	wrost = fit_value[0];
	for (int i=1;i<50;i++)
	{
		if(best > fit_value[i])
		{
			best=fit_value[i];
		}
		if(wrost< fit_value[i])
		{
			wrost = fit_value[i];
		}
	}	
	cout<<"best="<<best<<"  wrost="<<wrost<<endl;
	return 0;
}
