#include<iostream>
#include<fstream>
#include<iomanip>
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
        int i=1;
        string username, pass, email, company_name, address, number;
        ifstream file("Data.txt");
        cout<<endl;
        cout<<left<<setw(10)<<"Username"<<setw(40)<<"Email"<<setw(18)<<"Company"<<setw(20)<<"Address"<<setw(15)<<"Phone"<<endl;

        cout<<string(100, '-')<<endl;

        while(getline(file, username, '|') && getline(file, pass, '|') && getline(file, email, '|') && getline(file, company_name, '|') && getline(file, address, '|') && getline(file, number, '|'))
        {
            cout<<left<<setw(10)<<username<<setw(40)<<email<<setw(18)<<company_name<<setw(20)<<address<<setw(15)<<number<<endl;
            i++;
        }

        file.close();

    }
}
