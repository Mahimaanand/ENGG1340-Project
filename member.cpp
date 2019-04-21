#ifndef MEMBER_CPP
#define MEMBER_CPP
#include <fstream>
#include <iostream>
#include <sstream>
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
		points+=(weightages[i]*sportScore[i]);
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
		if(!(isalpha(name[i])) && name[i]!=' ' && name[i]!='.') {
			cout<<"Error with name"<<endl;
			return false;
		}
	}
	for(int i=0; i<reference.length();i++)
	{
		if(!(isalpha(reference[i])) && reference[i]!=' ' && reference[i]!='.'){
			cout<<"Error with reference"<<endl;
			return false;
		}
	}
	string dummy;
	istringstream iss;
	getline(fin,dummy);
	iss.str(dummy);
	iss>>age;
	iss.clear();
	if(age<18) {
		cout<<"Error with age"<<endl;
		return false;
	}
	getline(fin,dummy);
	iss.str(dummy);
	iss>>income;
	iss.clear();
	getline(fin, dummy);
	iss.str(dummy);
	for(int i=0; i<4; i++)
	{
		iss>>sportScore[i];
		if(sportScore[i]>10 || sportScore[i]<0) {
			cout<<"Error with sport scores"<<endl;
			return false;
		}
	}
	if(getline(fin,dummy)) {
		cout<<"Excess information provided"<<endl;
		return false;
	}
	return true;
}
#endif
//
//int main() {
//	return 0;
//}
