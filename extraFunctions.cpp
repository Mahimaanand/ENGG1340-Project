#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<iomanip>
#include "member.h"
#include "extraFunctions.h"
using namespace std;

void ShowMList(mList * head)
{
  mList * current = head;
  ofstream fout;
  fout.open("Show_Member_List.txt");
  if(current==NULL) {
    fout<<"Memberlist is empty";
    return;
  }
  fout<<left;
  fout<<setw(30)<<"NAME"<<" MEMBER ID"<<endl;
  while(current!=NULL)
  {
    fout<<setw(30)<<current->m.name<<" "<<current->m.memberID<<endl;
    current=current->next;
  }
  fout.close();
  return;
}

void ShowWList(const vector<Member> &waitlist)
{
  ofstream fout;
  fout.open("Show_Waiting_List");
  vector<Member>::const_iterator i;
  int rank=1;
  fout<<left;
  fout<<"Rank "<<setw(30)<<"Name"<<" Points"<<endl;
  for(i=waitlist.begin();i!=waitlist.end();i++,rank++)
  {
    fout<<setw(4)<<rank<<setw(30)<<(*i).name<<" "<<(*i).points<<endl;
  }
  fout.close();
  return;
}

bool SearchReference(mList *head, string name)
{
  mList *current=head;
  while(current!=NULL)
  {
    if(current->m.name==name) return true;
    current=current->next;
  }
  return false;
}

void AgeSearch(mList *head, int age)
{
  mList *current=head;
  ofstream fout;
  fout.open("Age_Output.txt");
  fout<<"Age="<<age<<endl;
  int ctr=0;
  fout<<left;
  while(current!=NULL)
  {
    if(current->m.age==age) {
      ctr++;
      fout<<setw(2)<<ctr<<" "<<setw(30)<<current->m.name<<" "<<current->m.memberID<<endl;
    }
    current=current->next;
  }
  if(ctr==0) fout<<"No members found"<<endl;
  cout<<ctr<<" members found"<<endl;
  return;
}

void NameSearch(mList *head, string name)
{
  mList *current=head;
  ofstream fout;
  fout.open("Name_Output.txt");
  fout<<"Name="<<name<<endl;
  int ctr=0;
  fout<<left;
  while(current!=NULL)
  {
    if(current->m.name==name) {
      ctr++;
      fout<<setw(2)<<ctr<<" "<<setw(30)<<current->m.name<<" "<<current->m.memberID<<endl;
    }
    current=current->next;
  }
  if(ctr==0) fout<<"No members found"<<endl;
  cout<<ctr<<" members found"<<endl;
  return;
}
//
//int main() {
//	return 0;
//}
