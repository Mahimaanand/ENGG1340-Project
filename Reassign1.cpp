#include <iostream>
using namespace std;

int main()
{
	int ctr=0;
	double w[4], wi[4];
	double sum=0;
	for(int i=0;i<4;i++)
	{
		cin>>w[i];
		if(w[i]==0) ctr++;
		else sum+=1/w[i];
	}
	if(ctr!=0)
	{
		for(int i=0;i<4;i++)
		{
			if(w[i]==0) cout<<40.0/ctr<<" ";
			else cout<<0<<" ";
		}

	}
	else
	{
		for(int i=0; i<4; i++)
		{
			wi[i]=1/w[i];
			cout<<(wi[i]/sum)*40<<" ";//normalising inverse of average to find final weightage
		}
	}
	cout<<endl;
	return 0;
}
