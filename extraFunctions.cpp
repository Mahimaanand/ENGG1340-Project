#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<iomanip>
#include "member.h"
#include "member.cpp"
#include "extraFunctions.h"
using namespace std;

int MakePosition(vector<Member> &waitlist, int numNewPos, mList * &head, long int &mID)
{
	cout<<left;
	int numVacPosition=numNewPos;
	while(waitlist.begin()!=waitlist.end() && numVacPosition!=0)
	{
		mList *p = new mList;

		p->m.name=waitlist.at(0).name;
		p->m.memberID=mID++;
		p->m.age=waitlist.at(0).age;
		p->m.income=waitlist.at(0).income;
		for(int i=0;i<=3;i++) p->m.sportScore[i]=waitlist.at(0).sportScore[i];
		waitlist.erase(waitlist.begin());

		numVacPosition--;
		p->next=head;
		head=p;

		cout<<setw(30)<<p->m.name<<" "<<p->m.memberID<<endl;
	}
	if(numVacPosition==numNewPos) cout<<"No members have been added."<<endl;
	return numVacPosition;
}

void ShowMList(mList * head)
{
  mList * current = head;
  ofstream fout;
  fout.open("Show_Member_List.txt");
  if(current==NULL) {
    cout<<"The memberlist is empty"<<endl;
    fout<<"The memberlist is empty";
    return;
  }
  fout<<left;
  cout<<left;
  fout<<setw(30)<<"NAME"<<" MEMBER ID"<<endl;
  cout<<setw(30)<<"NAME"<<" MEMBER ID"<<endl;
  while(current!=NULL)
  {
    fout<<setw(30)<<current->m.name<<" "<<current->m.memberID<<endl;
    cout<<setw(30)<<current->m.name<<" "<<current->m.memberID<<endl;
    current=current->next;
  }
  fout.close();
  return;
}

void ShowWList(const vector<Member> &waitlist)
{
  //ofstream fout;
  //fout.open("Show_Waiting_List.txt");
  vector<Member>::const_iterator i;
  int rank=1;
  cout<<left;
  if(waitlist.begin()==waitlist.end())
  {
  	cout<<"The waitlist is empty";
  	//fout.close();
  	return;
  }
  cout<<"Rank "<<setw(30)<<"Name"<<" Points"<<endl;
  for(i=waitlist.begin();i!=waitlist.end();i++,rank++)
  {
    cout<<setw(4)<<rank<<" "<<setw(30)<<(*i).name<<" "<<(*i).points<<endl;
  }
  //fout.close();
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
  //ofstream fout;
  //fout.open("Age_Output.txt");
  //fout<<"Age="<<age<<endl;
  int ctr=0;
  cout<<left;
  while(current!=NULL)
  {
    if(current->m.age==age) {
      ctr++;
      cout<<setw(2)<<ctr<<" "<<setw(30)<<current->m.name<<" "<<current->m.memberID<<endl;
    }
    current=current->next;
  }
  if(ctr==0) cout<<"No members were found"<<endl<<endl;
  cout<<ctr<<" members found"<<endl;
  return;
}

void NameSearch(mList *head, string name)
{
  mList *current=head;
  //ofstream fout;
  //fout.open("Name_Output.txt");
  //fout<<"Name="<<name<<endl;
  int ctr=0;
  cout<<left;
  while(current!=NULL)
  {
    if(current->m.name==name) {
      ctr++;
      cout<<setw(2)<<ctr<<" "<<setw(30)<<current->m.name<<" "<<current->m.memberID<<endl;
    }
    current=current->next;
  }
  if(ctr==0) cout<<"No members found"<<endl<<endl;
  cout<<ctr<<" members found"<<endl;
  return;
}

void ReassignWaitlist(vector<Member>& v)
{
	for (int i=0;i<v.size();i++){
		v[i].computePoints();
	}
	bool flag = true;
	while(flag){
		flag=false;
		for (int i=1;i<v.size();i++){
			if (v[i-1].points<v[i].points){
				Member temp = v[i-1];
				v[i-1]=v[i];
				v[i]=temp;
				flag = true;
			}
		}
	}
}
//
//int main() {
//	return 0;
//}
