/***********************************************************************************************************************
* Author : Zachary Pringle                                                                                             *
* Program : hw5                                                                                                        *
* Date Created : December 6, 2021                                                                                      *
* Date Last Modified : December 9, 2021                                                                                *
* Usage : No command line arguments                                                                                    *
*                                                                                                                      *
* Problem:                                                                                                             *
*-Write the csv file to the link list                                                                                  *
*- Create a link list that can add nodes to the head, display the list, search in the list, and delete the head pointer*
***********************************************************************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include "listtoolshb.h"
#include "listtoolshb.cpp"

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

int main() {
    Profile temp;
    string line;
    MyList<Profile> pMyList;

    ifstream file("C:\\Users\\zpringle\\CLionprojects\\HW_5\\presidentsWstates.txt");
    if (file.is_open())
    {
        while (getline(file, line))
        {
            stringstream ss(line);
            getline(ss, temp.fullname, '\t');
            getline(ss, temp.state, '\t');
            pMyList.insertHead( temp);
        }
    }
    pMyList.display();
    cout << "\n____________________________________________\n" << endl;
    Profile p1;
    p1.fullname = "John Tyler";
    Profile target=p1;
    pMyList.search(target);
    pMyList.deleteHead();
    pMyList.display();

return 0;
}