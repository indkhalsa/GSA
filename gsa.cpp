#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
	int a[50], b[50];
	float fit_value[50], best, wrost, mgi[50];
	for(int i=0;i<50;i++)
	{
		int y, z;
		y=rand()%11 - 5;
		z=rand()%11 - 5;
		a[i] = y;
		b[i] = z;
		cout<<i<<" no "<<a[i]<<"    "<<b[i]<<"   "<<fit_value[i]<<endl;
	}
	for(int i=0;i<50;i++)
	{
		float x;
		x=4*a[i]*a[i]-2.1*a[i]*a[i]*a[i]*a[i]+1/3*a[i]*a[i]*a[i]*a[i]*a[i]*a[i]+a[i]*b[i]-4*b[i]*b[i]+4*b[i]*b[i]*b[i]*b[i];
		fit_value[i] = x;
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
	for(int i=0;i<50;i++)
	{
		float f_w, b_w;
		f_w=fit_value[i]-wrost;
		b_w=best-wrost;
		mgi[i]=f_w/b_w;
		cout<<i<<"    "<<mgi[i]<<endl;
	}
	return 0;
}
