#include <string>
using namespace std;

class Member {
	public:
		int points;
		string name, reference, memberID;
		bool refExist;
		int age, income;
		int sportScore[4];
		bool readInput(string); //also determines if function is valid. (returns false = delete that file)
		void computePoints();
		static void reassignWeightages(double[]);
		static double weightages[4];

/*
index 0 is Golf score
index 1 is Swimming score
index 2 is Squash score
index 3 is Snooker score
*/
};

double Member::weightages[4];

void Member::reassignWeightages(double avg[])
{
	int ctr=0;
	double sum=0;
	for(int i=0;i<4;i++)
	{
		if(avg[i]==0) ctr++;
		else sum+=1/avg[i];
	}
	if(ctr!=0)
	{
		for(int i=0;i<4;i++)
		{
			if(avg[i]==0) weightages[i]=40.0/ctr;
			else weightages[i]=0;
		}
		return;
	}
	for(int i=0; i<4; i++)
	{
		weightages[i]=1/avg[i];
		weightages[i]=weightages[i]*40/sum;//normalising inverse of average to find final weightage
	}
	return;
}
