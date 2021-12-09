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
    Profile p1;
    p1.fullname = "John Tyler";
    Profile target=p1;
    pMyList.search(target);
    pMyList.deleteHead();

return 0;
}