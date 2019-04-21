#ifndef EXTRA_H
#define EXTRA_H
#include<vector>
#include<string>
#include "member.h"
using namespace std;

struct mList{
  Member m;
  mList * next;
};

void NameSearch(mList *, string);

void AgeSearch(mList *,int);

bool SearchReference(mList *, string);

int MakePosition(vector<Member> &waitlist, int numNewPos, mList * &head, long int &mID);

void ShowMList(mList *);

void ShowWList(const vector<Member>&);

void ReassignWaitlist(vector<Member>&);

#endif
