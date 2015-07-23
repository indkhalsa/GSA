#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

int main()
{
	int dm=2, in, it;
	cout<<"\nEnter no of 'Particles' :- ";
	cin>>in;
	cout<<"\nEnter no of 'Iterations' :- ";
	cin>>it;
	double long X[it][dm][in], fit[it][in], G[it], best[it], wrost[it], mg[it][in], mgall[it], Mg[it][in], Fij[it][dm][in][in-1], Fi[it][dm][in], A[it][dm][in], V[it][dm][in];
	
	for(int d=1;d<=2;d++)
	{
		for(int i=1;i<=in;i++)
		{
			double long tmp = rand() / (double)RAND_MAX;
			double long x = tmp * (5 + 5);
			x = x - 5;
			X[1][d][i]=x;
			cout<<"X[1]["<<d<<"]["<<i<<"]= "<<X[1][d][i]<<endl;
		}
	}
	
	for(int t=1;t<=it;t++)
	{
		
		for(int i=1;i<=in;i++)
		{
			double long tempfit=4*X[t][1][i]*X[t][1][i]-2.1*X[t][1][i]*X[t][1][i]*X[t][1][i]*X[t][1][i]+1/3*X[t][1][i]*X[t][1][i]*X[t][1][i]*X[t][1][i]*X[t][1][i]*X[t][1][i]+X[t][1][i]*X[t][2][i]-4*X[t][2][i]*X[t][2][i]+4*X[t][2][i]*X[t][2][i]*X[t][2][i]*X[t][2][i];
			fit[t][i] = tempfit;
			cout<<"fit value ["<<t<<"]["<<i<<"]= "<<fit[t][i]<<endl;
		}
		
		best[t] = fit[t][1];
		wrost[t] = fit[t][1];
		for (int i=1;i<=in;i++)
		{
			if(best[t] > fit[t][i])
			{
				best[t]=fit[t][i];  
			}
			if(wrost[t]< fit[t][i])
			{
				wrost[t] = fit[t][i];
			}
		}	
		cout<<t<<"best= "<<best[t]<<"  wrost= "<<wrost[t]<<endl;
		
		double long tempg, tempg2, tempg3;
		tempg=t/50;
		tempg2=tempg*-20;
		tempg3= exp (tempg2);
		G[t]=100*tempg3;
		cout<<"G["<<t<<"]= "<<G[t]<<endl;
		
		double b_w=best[t]-wrost[t];
		for(int i=1;i<=in;i++)
		{
			double long f_w;
			f_w=fit[t][i]-wrost[t];
			mg[t][i]=f_w/b_w;
			cout<<"fit-worst"<<f_w<<"  best-worst"<<b_w<<endl;
			cout<<"mg["<<t<<"]["<<i<<"]= "<<mg[t][i]<<endl;
		}
		
		mgall[t]=0;
		for(int i=1;i<=in;i++)
		{
			mgall[t] = mgall[t]+mg[t][i];
			cout<<"mgall"<<mgall[t]<<endl;
		}
		for(int i=1;i<=in;i++)
		{
			double long mge = mgall[t]-mg[t][i];
			if(mge != 0)
			{
				Mg[t][i]=mg[t][i]/mge;
				cout<<"mge"<<mge<<endl;
				cout<<"Mg ["<<t<<"]["<<i<<"]= "<<Mg[t][i]<<endl;
			}
			else
			{
				Mg[t][i]=mg[t][i];
			}
		}
		
		for(int i=1;i<=in;i++)
		{
			for(int j=1;j<=in;j++)
			{
				if(j!=i)
				{
					double long temp1, temp2, temp3,temp4;
					temp1=X[t][2][j]-X[t][1][i];
					temp2= abs(X[t][1][i]-X[t][2][j]);
					temp2=temp2+0.2;
					temp3=X[t][1][i]*X[t][2][j];
					temp4=temp3/temp2;
					float randFi = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
					Fij[t][1][i][j]=G[t]*temp1*temp4*randFi;
					cout<<"Fij ["<<t<<"][1]["<<i<<"]["<<j<<"]= "<<Fij[t][1][i][j]<<endl;
				}
			}
		}
		
		for(int j=1;j<=in;j++)
		{
			for(int i=1;i<=in;i++)
			{
				if(i!=j)
				{
					double long temp1, temp2, temp3,temp4;
					temp1=X[t][1][i]-X[t][2][j];
					temp2= abs(X[t][2][j]-X[t][1][i]);
					temp2=temp2+0.2;
					temp3=X[t][2][j]*X[t][1][i];
					temp4=temp3/temp2;
					float randFi = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
					Fij[t][2][j][i]=G[t]*temp1*temp4*randFi;
					cout<<"Fij ["<<t<<"][2]["<<j<<"]["<<i<<"]= "<<Fij[t][2][j][i]<<endl;
				}
			}
		}
		
		for(int d=1;d<=2;d++)
		{
			for(int i=1;i<=in;i++)
			{
				double long tempf=0;
				for(int j=1;j<in;j++)
				{
					tempf=tempf+Fij[t][d][i][j];
				}
				Fi[t][d][i]=tempf;
				cout<<"Fi ["<<t<<"]["<<d<<"]["<<i<<"]= "<<Fi[t][d][i]<<endl;
			}
		}

		for(int d=1;d<=2;d++)
		{
			for(int i=1;i<=in;i++)
			{
				A[t][d][i]=(Fi[t][d][i])/(Mg[t][i]);
			}
		}
		
		
		for(int d=1;d<=2;d++)
		{
			for(int i=1;i<=in;i++)
			{
				if(t==1)
				{
					V[t+1][d][i]=A[t][d][i];
					cout<<"V["<<t+1<<"]["<<d<<"]["<<i<<"]= "<<V[t+1][d][i]<<endl;
				}
				if(t>1)
				{
					float randv = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); 
					V[t+1][d][i]=randv*V[t][d][i]+A[t][d][i];
					cout<<"V["<<t+1<<"]["<<d<<"]["<<i<<"]= "<<V[t+1][d][i]<<endl;
				}
			}
		}
		
		for(int d=1;d<=2;d++)
		{
			for(int i=1;i<=in;i++)
			{
				X[t+1][d][i]=X[t][d][i]+V[t+1][d][i];
				cout<<"X["<<t+1<<"]["<<d<<"]["<<i<<"]= "<<X[t+1][d][i]<<endl;
			}
		}
		
	}	
	return 0;
}
