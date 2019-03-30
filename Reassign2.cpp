#include <iostream>
#include <string>
using namespace std;

struct sport
{
	string name;
	double avg;
};
int main()
{
	sport s[4];
	s[0].name="Golf";
	s[1].name="Swimming";
	s[2].name="Snooker";
	s[3].name="Squash";
	double sum=0;
	for(int i=0;i<4;i++)
	{
		cout<<s[i].name<<": ";
		cin>>s[i].avg;
		sum+=s[i].avg;
	}
	bool b=true;
	while(b)
	{
		b=false;
		for(int i=0;i<3;i++)
		{
			if(s[i].avg<s[i+1].avg)
			{
				sport temp=s[i];
				s[i]=s[i+1];
				s[i+1]=temp;
				b=true;
			}
		}
	}
	double temp=s[3].avg;
	s[3].avg=s[0].avg;
	s[0].avg=temp;
	temp=s[1].avg;
	s[1].avg=s[2].avg;
	s[2].avg=temp;
	for(int i=0; i<4; i++)
	cout<<s[i].name<<" "<<(s[i].avg/sum)*40<<endl;
	return 0;
}
