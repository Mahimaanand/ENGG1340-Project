#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include "member.h"
#include "member.cpp"
#include "extraFunctions.h"
#include "extraFunctions.cpp"
using namespace std;

//struct mList{
//  Member m;
//  mList * next;
//};

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
void SportsAvg(mList * head, double average[]){
  for(int i=0;i<4;i++) average[i]=0;
  mList * current = head;
  int ctr=1;
  while(current!=NULL){
    for (int i=0;i<4;i++){
      average[i]+=current->m.sportScore[i];
    }
    current=current->next;
    ctr++;
  }
  if(ctr!=1) ctr--;
  for (int i=0;i<4;i++){
    average[i]=average[i]/ctr;
  }
}


//double weightages[4] = {10,10,10,10};
int main(){

  mList * head = NULL;
  int numMembers;
  long int assignID;
  cout<<"Reading the member list...";
  ifstream fin;
  fin.open("CacheMemberList.txt");
  string tempVal;
  istringstream iss;
  getline(fin, tempVal);
  iss.str(tempVal);
  iss>>numMembers;
  iss>>assignID;
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
  int tempNum = numMembers;
  cout<<"Calculating sport score ratings..."<<endl;
  mList * current = head;
  double avg[4]={0,0,0,0};
  if(numMembers==0)
  {
  	for(int i=0;i<4;i++)
  	Member::weightages[i]=10.0;
  }
  else
  {
  	SportsAvg(head, avg);
  	Member::reassignWeightages(avg);
  }
  for(int i=0;i<4;i++) {
  	Member::weightages[i]=Member::weightages[i]/10.0;
  	cout<<Member::weightages[i]<<" ";
  }
  cout<<endl;
  cout<<"Program ready!"<<endl<<endl;
  //Waitlist defined
  vector<Member> waitlist;
  waitlist.reserve(40);


  //MENU
  int vacPositions = 0;
  char cmd=' ';
  cout<<"----------------------------------------------------------------------------"<<endl;
  cout<<"WELCOME TO FALCONKEEP SANCTUARY CLUB.\nChoose one of the following commands to continue:\n";
  cout<<"1. N: Create new membership positions.\n";
  cout<<"2. P: Add a person to the waitlist.\n";
  cout<<"3. R: Remove a person from the member list.\n";
  cout<<"4. S: Show the waitlist(W) or show the member list (M).\n";
  cout<<"5. F: Find all the members with a particular attribute.\n";
  cout<<"6. A: Display the average sports scores of the member list.\n";
  cout<<"7. E: Exit the database.\n";
  cout<<"----------------------------------------------------------------------------"<<endl;
  while(cmd!='E'){
  	cout<<"Your choice: ";
    cin>>cmd;
    if(cmd=='N'){
      int number;
      cout<<"Enter the number of new positions: ";
      cin>>number;
      cout<<"Members added:"<<endl;
      long int * temp = new long int;
      *temp=assignID;
      vacPositions+=MakePosition(waitlist, number, head, assignID);
      numMembers+=assignID-(*temp);
      delete temp;
      cout<<"Number of vacant positions = "<<vacPositions<<endl;
    }
    else if(cmd=='P'){
      string filename;
      cout<<"Enter filename of person's application form: ";
      cin>>filename;
      Member * p = new Member;
      if  ((*p).readInput(filename)){
        (*p).refExist=SearchReference(head, (*p).reference);
        (*p).computePoints();
        cout<<"Number of points: "<<(*p).points<<endl;
        cout<<"Current rank in Waitlist = ";
        if (waitlist.size()==0){
         waitlist.push_back(*p);
         cout<<"1"<<endl;
       }

        else {
          //vector<Member>::const_iterator i;
          int i;
          for (i=0; i<waitlist.size();i++){
            if ((*(waitlist.begin()+i)).points<(*p).points){
              break;
            }
          }
          if (i==waitlist.size()){
            waitlist.push_back(*p);
          }
          else{
            waitlist.insert(i+waitlist.begin(),*p);
          }
          cout<<i+1<<endl;
        }
        if(vacPositions>0) {
        	cout<<"Member added"<<endl;
        	vacPositions+=MakePosition(waitlist, 1, head, assignID);
        	vacPositions--;
        	numMembers++;
        	cout<<"Number of vacant positions = "<<vacPositions<<endl;
		}
      }
      else{
        cout<<"The data provided is invalid. Waitlist position not given.\n";
        delete p;
      }
      //search for person, calculate points, add to waitlist


    }
    else if(cmd=='R'){
      long int ID;
      cout<<"Enter ID of member to be removed: ";
      cin>>ID;
      if(numMembers==0)
      {
      	cout<<"Member list is empty. Nobody could be removed"<<endl;
      	continue;
	  }
      mList * current = head;
      if(current->m.memberID==ID) //member is 1st in member list
      {
      	cout<<"Removed "<<current->m.name<<endl;
        head=current->next;
        delete current;
      }
      else {
      	int flag=0;
        while(current->next!=NULL) { //general case
          mList * p = current->next;
          if(p->m.memberID==ID)
          {
            current->next=p->next;
            cout<<"Removed "<<p->m.name<<endl;
            delete p;
            flag=1;
            break;
          }
          current=current->next;
        }
        if(flag==0) //member is last in member list
        {
          if(current->m.memberID==ID) {
          	cout<<"Removed "<<current->m.name<<endl;
		  	delete current;
		  }
          else{
		  	cout<<"No such Member ID exists in our database"<<endl;
		  	continue;
		  }
        }
      }
      numMembers--;
      cout<<"Members added:"<<endl;
      long int * temp = new long int;
      *temp=assignID;
      vacPositions+=MakePosition(waitlist, 1, head, assignID);
      numMembers+=assignID-(*temp);
      delete temp;
      cout<<"Number of vacant positions = "<<vacPositions<<endl;
    }
    else if(cmd=='S'){
      char list;
      cout<<"Do you want to view the waitlist or the member list (W/M)? ";
      cin>>list;
      if(list=='M') ShowMList(head);
      else if(list=='W') ShowWList(waitlist);
      else cout<<"Invalid option"<<endl;
    }
    else if(cmd=='F'){
      string attribute;
      cout<<"Enter attribute to be searched (Name, Age): ";
      cin>>attribute;
      if(attribute=="Name"){
        string name_search;
        cout<<"Enter name: ";
        cin>>name_search;
        NameSearch(head, name_search);
      }
      else if (attribute=="Age"){
        int age_search;
        cout<<"Enter age: ";
        cin>>age_search;
        AgeSearch(head, age_search);
      }
      else{
        cout<<"The attribute is not valid."<<endl;
      }
    }
    else if (cmd=='A'){
      SportsAvg(head, avg);
      cout<<"Golf: "<<avg[0]<<endl;
      cout<<"Swimming: "<<avg[1]<<endl;
      cout<<"Squash: "<<avg[2]<<endl;
      cout<<"Snooker: "<<avg[3]<<endl;
    }

    else if(cmd!='E') cout<<"Invalid option entered"<<endl;
    if (numMembers-tempNum>=5){
      cout<<"Recalculating average...";
      SportsAvg(head, avg);
      cout<<"Adjusting weightages...";
      Member::reassignWeightages(avg);
      cout<<"Adjusting waitlist postions...";
      ReassignWaitlist(waitlist);
      cout<<"Changed!"<<endl;
      tempNum=numMembers;
    }
}//while loop ends

  cout<<"Writing member list to cache...";
  WriteCache(numMembers, assignID, head);
  cout<<"Program ended"<<endl;
  if(numMembers==0) return 0;
  while(head!=NULL) {
    mList * p = new mList;
	p=head;
    head = head->next;
    delete p;
  }
  return 0;
}
