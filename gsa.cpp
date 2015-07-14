#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cmath>

using namespace std;

int main()
{
	int a[50], b[50];
	double long fit_value[50], best, wrost, mg[50], mgi[50], mgall, G[50], mj, Fij[50], temp1, Fi[50], aj[50], vdi[50], xt[50];
	for(int i=0;i<50;i++)
	{
		int y, z;
		y=rand()%11 - 5;
		z=rand()%11 - 5;
		a[i] = y;
		b[i] = z;
		cout<<i<<" no "<<i<<" a "<<a[i]<<" b "<<b[i]<<endl;
	}
	for(int i=0;i<50;i++
	)
	{
		double x;
		x=4*a[i]*a[i]-2.1*a[i]*a[i]*a[i]*a[i]+1/3*a[i]*a[i]*a[i]*a[i]*a[i]*a[i]+a[i]*b[i]-4*b[i]*b[i]+4*b[i]*b[i]*b[i]*b[i];
		fit_value[i] = x;
		cout<<"fit value ["<<i<<"] "<<fit_value[i]<<endl;
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
		double f_w, b_w;
		f_w=fit_value[i]-wrost;
		b_w=best-wrost;
		mg[i]=f_w/b_w;
		cout<<i<<"    "<<mg[i]<<endl;
	}
	for(int i=0;i<50;i++)
	{
		mgall = mgall+mg[i];
	}
	for(int i=0;i<50;i++)
	{
		double mge = mgall-mg[i];
		mgi[i]=mg[i]/mge;
		cout<<mgi[i]<<endl;
	}
	for(int i=0;i<50;i++)
	{
		double temp, temp2, temp3;
		temp=i+1/50;
		temp2=temp*-20;
		temp3= exp (temp2);
		G[i]=100*temp3;
		cout<<"G["<<i<<"]= "<<G[i]<<endl;
	}
	for(int i=0;i<50;i++)
	{
		int temp=b[i]-a[i], temp2;
		if(temp<0)
		{
			temp2=temp*-1;
		}
		temp2=temp2+0.2; 
		mj=mg[i]*mg[i]/temp2;
		Fij[i]=G[i]*mj*temp;
		cout<<"Fij["<<i+1<<"]= "<<Fij[i]<<endl;
	}
	for(int i=0;i<50;i++)
	{
		float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		temp1=temp1+r;
		cout<<r<<endl;
	}
	for(int i=0;i<50;i++)
	{
		double temp;
		temp=temp1/50;
		Fi[i]=temp*Fij[i];
		cout<<"Fi" <<Fi[i]<<endl;
	}
	for(int i=0;i<50;i++)
	{
		aj[i]=Fi[i]/mgi[i];
		cout<<"aj"<<aj[i]<<endl;
	}
	vdi[0]=0;
	for(int i=0;i<50;i++)
	{
		float randv = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		vdi[i+1]=randv*vdi[i]+aj[i];
		cout<<"randm  "<<randv<<"  vdi "<<vdi[i]<<endl;
	}
	xt[0]=0;
	for(int i=0;i<50;i++)
	{
		xt[i+1]=xt[i]+vdi[i];
		cout<<"xt "<<xt<<endl;
	}
	return 0;
}
