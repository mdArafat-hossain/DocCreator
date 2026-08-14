#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<limits>
#include "adbout.h"
#include "login.h"

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
        string username, pass, email, company_name, address, number;
        ifstream file("Data.txt");
        cout<<endl;
        cout<<left<<setw(10)<<"Username"<<setw(40)<<"Email"<<setw(18)<<"Company"<<setw(20)<<"Address"<<setw(15)<<"Phone"<<endl;

        cout<<string(100, '-')<<endl;

        while(getline(file, username, '|') && getline(file, pass, '|') && getline(file, email, '|') && getline(file, company_name, '|') && getline(file, address, '|') && getline(file, number, '|'))
        {
            cout<<left<<setw(10)<<username<<setw(40)<<email<<setw(18)<<company_name<<setw(20)<<address<<setw(15)<<number<<endl;

        }

        file.close();
    }
    else if(logchoice==2)
    {
        string user, username, password, email, company_name, address, number,status;
        cout<<"Enter username : ";
        cin>>user;
        ifstream file("Data.txt");
        string line;

        while (getline(file, line))
        {
            stringstream ss(line);



            getline(ss, username, '|');
            getline(ss, password, '|');
            getline(ss, email, '|');
            getline(ss, company_name, '|');
            getline(ss, address, '|');
            getline(ss, number, '|');
            getline(ss, status, '|');

            if (user == username)
            {
                cout << endl;
                cout << "Username          : " << username << endl;
                cout << "Email             : " << email << endl;
                cout << "Company Name      : " << company_name << endl;
                cout << "Address           : " << address << endl;
                cout << "Phone number      : " << number << endl;
                cout << "Total file generated : " << status << endl;

                break;
            }
        }
    }
    else if(logchoice==3)
    {
        registeruser();
    }
    else if(logchoice==4)
    {
        string user, username, password, email, company_name, address, number, status;
string line, ans;
bool dexist = false;

ifstream file("Data.txt");
ofstream temp("temp.txt");

while(true)
{
    cout << "Enter Username : ";
    cin >> username;

    dexist = false;

    while(getline(file, line))
    {
        stringstream check(line);
        string c_name;

        getline(check, c_name, '|');

        if(c_name == username)
        {
            dexist = true;
            break;
        }
    }

    if(!dexist)
    {
        cout << "Username doesn't exist\n" << endl;

        file.clear();
        file.seekg(0);
    }
    else
    {
        cout << "Delete " << username << " ? (Y/N) ";
        cin >> ans;

        if(ans == "y" || ans == "Y")
        {
            break;
        }

        file.clear();
        file.seekg(0);
    }
}

file.clear();
file.seekg(0);

while (getline(file, user, '|'))
{
    getline(file, password, '|');
    getline(file, email, '|');
    getline(file, company_name, '|');
    getline(file, address, '|');
    getline(file, number, '|');
    getline(file, status, '|');

    // Move file cursor to the next line
    file.ignore(numeric_limits<streamsize>::max(), '\n');

    if (user == username)
    {
        continue;
    }

    temp << user << "|" << password << "|" << email << "|"
         << company_name << "|" << address << "|" << number << "|"
         << status << "|" << endl;
}

file.close();
temp.close();

remove("Data.txt");
rename("temp.txt", "Data.txt");
    }
    else
    {
        cout<<endl;
        string line;
    ifstream file("statistics.txt");

    while(getline(file,line))
    {
        cout<<line<<endl;
    }
    file.close();
    }
}
