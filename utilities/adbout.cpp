#include<iostream>
#include<fstream>
#include "adbout.h"

using namespace std;

void about()
{
    string line;
    ifstream file("about.txt");

    while(getline(file,line))
    {
        cout<<line<<endl;
    }
    file.close();

}

void admin(int logchoice)
{
    /*1.View all users
    2.Search users
    3.Add User
    4.Delete User
    5.View System Statistics*/
    if(logchoice==1)//View all users
    {

    }
}
