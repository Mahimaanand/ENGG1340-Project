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

int MakePosition(vector<Member>&, int numNewPos, mList *);

void ShowMList(mList *);

void ShowWList(const vector<Member>&);
