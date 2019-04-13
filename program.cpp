#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include "member.h"
using namespace std;

struct mList{
  Member m;
  mList * next;
};

void WriteCache(int num, long int lastID, mList *h){
  ofstream fout;
  fout.open("CacheMemberList.txt");
  fout<<num<<" "<<lastID<<endl;
  mList * current = h;
  while(current!=NULL){
    fout<<current->m.name<<endl;
    fout<<current->m.memberID<<endl;
    fout<<current->m.age<<" "<<current->m.income<<endl;
    for (int i=0;i<4;i++){
      fout<<current->m.sportScore[i];
      if (i!=3){
        fout<<" ";
      }
      else{
        fout<<endl;
      }
    }
    current=current->next;
  }
  fout.close();
}

//double weightages[4] = {10,10,10,10};
int main(){
  mList * head = NULL;
  int numMembers;
  long int assignID;
  ifstream fin;
  fin.open("CacheMemberList.txt");
  string tempVal;
  istringstream iss;
  getline(fin, tempVal);
  iss.str(tempVal);
  iss>>numMembers;
  iss>>assignID;
  //assignID++;  ADD BASED ON HOW WE'RE ASSIGNING THE MEMBER ID TO MEMBERS (ADDITION BEFORE/AFTER ASSIGNNING)
  iss.clear();
  for(int i=1;i<=numMembers;i++){ //READING CACHE
    mList * p = new mList;
    getline(fin,p->m.name);
    getline(fin,tempVal);
    iss.str(tempVal);
    iss>>p->m.memberID;
    iss.clear();
    getline(fin, tempVal);
    iss.str(tempVal);
    iss>>p->m.age;
    iss>>p->m.income;
    getline(fin, tempVal);
    iss.clear();
    iss.str(tempVal);
    for(int i=0;i<4;i++){
      iss>>p->m.sportScore[i];
    }
    p->next=head;
    head=p;
    iss.clear();
  }
  fin.close();
  mList * current = head;
  double avg[4];
  if(numMembers==0)
  {
  	for(int i=0;i<4;i++)
  	Member::weightages[i]=10.0;
  }
  else
  {
  	while(current!=NULL)
  	{
  		for(int i=0; i<4; i++)
  	 	 avg[i]+=current->m.sportScore[i]/numMembers;
  		current=current->next;
  	}
  	Member::reassignWeightages(avg);
  }
  char cmd=' ';
  while(cmd!='E'){
    cout<<"WELCOME TO FALCONKEEP SANCTUARY CLUB.\nChoose one of the following commands to continue:\n";
    cout<<"1. N: Create new membership positions.\n";
    cout<<"2. P: Add person to waitlist.\n";
    cout<<"3. R: Remove person from member list.\n ";
    cout<<"4. S: Show waitlist(W) or show member list (M).\n";
    cout<<"5. F: Find all members with a particular attribute.\n";
    cout<<"6. E: Exit the database.\n";
    cout<<"Your choice: ";
    cin>>cmd;
    if(cmd=='N'){
      int number;
      cout<<"Enter number of new positions: ";
      cin>>number;

    }
    else if(cmd=='P'){
      string person_name;
      //search for person, calculate points, add to waitlist


    }
    else if(cmd=='R'){
      long int ID;
      cout<<"Enter ID of member to be removed: ";
      cin>>ID;
      //search for member ID and remove from member list

    }
    else if(cmd=='S'){
      char list;
      cout<<"Do you want to view waitlist or member list (W/M)?";
      cin>>list;

    }
    else if(cmd=='F'){
      string attribute;
      int value;

    }
}










  WriteCache(numMembers, assignID, head);
  if(numMembers==0) return 0;
  while(head!=NULL) {
    mList * p = head;
    head = head->next;
    delete p;
  }
  return 0;

}
