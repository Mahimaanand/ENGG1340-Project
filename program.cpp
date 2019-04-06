#include<iostream>
#include<fstream>
#include<string>
#include "member.h"
using namespace std;

struct mList{
  Member m;
  mList * next;
};

void WriteCache(int num, mList *h){
  ofstream fout;
  fout.open("CacheMemberList.txt");
  fout<<num<<endl;
  if (num==0){
  return;
  }
  mList * current = h;
  while(current->next!=NULL){
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

double weightages[4] = {10,10,10,10};
int main(){
  mList * head = NULL;
  int numMembers;
  ifstream fin;
  fin.open("CacheMemberList.txt");
  fin>>numMembers;
  for(int i=1;i<=numMembers;i++){ //READING CACHE
    mList * p = new mList;
    getline(fin,p->m.name);
    getline(fin,p->m.memberID);
    fin>>p->m.age;
    fin>>p->m.income;
    for(int i=0;i<4;i++){
      fin>>p->m.sportScore[i];
    }
    p->next=head;
    head=p;
  }
  fin.close();










  WriteCache(numMembers, head);
  if(numMembers==0) return 0;
  mList * p = head;
  head = head->next;
  delete p;
  return 0;

}
