#include <string>
using namespace std;

class Member {
	public:
		int points;
		string name, reference;
		bool refExist;
		int age, income;
		int sportScore[4];
		bool readInput(string); //also determines if function is valid. (returns false = delete that file)
		void computePoints(int[]);
		void reassignWeightages(double[], double[]);
/*
index 0 is Golf score
index 1 is Swimming score
index 2 is Squash score
index 3 is Snooker score
*/
};
