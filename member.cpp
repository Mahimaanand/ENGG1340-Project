#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include "member.h"
using namespace std;

void Member::computePoints()
{
	points=0;
	if(refExist) points+=10; //REFERENCE

	if(age<25) points+=15;//AGE
	else if(age<40) points+=20;
	else if(age<50) points+=10;

	if(income>1000000) points+=30;//INCOME
	else if(income>750000) points+=20;
	else if(income>500000) points+=15;
	else if(income>400000) points+=10;

	for(int i=0; i<=3; i++)
	{
		points+=weightages[i]*sportScore[i];
	}
	return;
}

bool Member::readInput(string filename)
{
	ifstream fin;
	fin.open(filename.c_str());
	if(fin.fail()) {
		cout<<"Failed to open "<<filename<<endl;
		return false;
	}
	getline(fin, name);
	getline(fin, reference);
	for(int i=0; i<name.length();i++)
	{
		if(!(isalpha(name[i])) && name[i]!=' ' && name[i]!='.') return false;
	}
	for(int i=0; i<reference.length();i++)
	{
		if(!(isalpha(reference[i])) && reference[i]!=' ' && reference[i]!='.') return false;
	}
	fin>>age;
	if(age<18) return false;
	fin>>income;
	for(int i=0; i<4; i++)
	{
		fin>>sportScore[i];
		if(sportScore[i]>10 || sportScore[i]<0) return false;
	}
	string dummy;
	if(getline(fin,dummy)) {
		cout<<"Excess information provided"<<endl;
		return false;
	}
	return true;
}

int main() {
	return 0;
}
