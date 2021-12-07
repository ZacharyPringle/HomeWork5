#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <deque>
#include "MyList.h"

using namespace std;
struct Profile
{
    string fullname;
    string state;
    bool operator==( Profile rhs)
    {if (fullname==rhs.fullname) return true; return false; }
    bool operator!=(Profile rhs)
    {if (fullname!=rhs.fullname) return true; return false; }
};
ostream& operator<< (ostream &out, Profile &user)
{
    out << user.fullname<<"--" <<user.state;
    return out;
}
//define the function below to find a given Profile for which only name is provided. This function should return
//true or false. If it finds the given name, it should also change the value of the second parameter as it's
//passed by reference.
bool searchDeque(deque<Profile> &pq, Profile &president);
int main() {
    //create a Profile queue called pQueue;
    queue<Profile> pQueue;
    //create a Profile deque called pDeque;
    deque<Profile> pDeque;
    Profile temp;
    string line;
    //let's practice file I/O
    ifstream file("C:\\Users\\zpringle\\CLionprojects\\HW_5\\presidentsWstates.txt");
    if (file.is_open())
    {
        while (getline(file, line))
        {
            stringstream ss(line);
            getline(ss, temp.fullname, '\t');
            getline(ss, temp.state, '\t');
            //use push for your queue to insert president Profiles.
            pQueue.push(temp);
            //use push_front for your deque to insert president Profiles
            pDeque.push_front(temp);
        }
    }
    else{cout<<"Can't See File" << endl;}
    cout<<"Printing queue members by using pop and front***********************"<<endl;
//use a while loop by using front and pop function to both empty and print your President profiles.
while(!pQueue.empty()){
    cout << pQueue.front()<<endl;
    pQueue.pop();
}
            cout<<"Printing deque members with iterator***********************"<<endl;
//use an iterator print your President profiles.
    deque<Profile>::iterator dIter;
    for(dIter=pDeque.begin(); dIter!=pDeque.end(); dIter++){
        cout << *dIter << endl;
    }
    //use a for loop which works with indices to print your President profiles.
    cout<<"Printing deque members with indices***********************"<<endl;
//Uncomment below to when you have your search function ready
for(int i=0; i<pDeque.size(); i++){
    cout << pDeque[i] << endl;
}
temp.fullname = "Gerald R. Ford";
if(searchDeque(pDeque, temp))
  cout<<"found:"<<temp<<endl;
else
  cout<<"not found: "<<temp<<endl;

    MyList<Profile> pMylist;
    Node<Profile>* head=NULL;
   // ifstream file("presidentsWstates.txt");
    if (file.is_open())
    {
        while (getline(file, line))
        {
            stringstream ss(line);
            getline(ss, temp.fullname, '\t');
            getline(ss, temp.state, '\t');
            pMylist.insertHead(temp, head);
        }
    }


return 0;
}


bool searchDeque( deque<Profile> &pq,   Profile &president)
{
    for(int i=0; i<pq.size(); i++){
        if (president==pq[i])
            return true;
    }
    return false;
}