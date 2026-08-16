#include<iostream>
#include<string>
#include<ctime>
#include<cctype>
#include<fstream>
#include<limits>
#include "zutils.h"

using namespace std;
string Date_Time() //generate date and time
{
    time_t now=time(0);
    tm* local= localtime(&now);

    char dt[100];
    strftime(dt,sizeof(dt),"_%Y-%m-%d_%H%M",local);// year month date hour(24-format) Minute
    return dt;
}
void strnth(string password) //password strength check
{
    bool up=false,lp=false,dig=false,sp=false; //uppercase,lowercase,digit,special character
    if(password.length()<8)
        throw "Password must be at least 8 characters. ";
    for(char ch : password)//check all character of the string
    {
        if(isupper(ch))
            up=true;
        else if(islower(ch))
            lp=true;
        else if(isdigit(ch))
            dig=true;
        else
            sp=true;
    }
    if(!up)
        throw "Must contain an uppercase letter";
    if(!lp)
        throw "Must contain an lowercase letter";
    if(!dig)
        throw "Must contain a digit";
    if(!sp)
        throw "Must contain a special character";

}

int checkDigit(string choice) // check if the password is digit
{
    if(choice.empty())
    {
        return 0;
    }
    for(char ch : choice)
    {
        if(!isdigit(ch))
        {
            return 0; //if the password is not fully digit it'll return 0
        }
    }
    int digit = stoi(choice); //converts string to int
    return digit; //return converted int value

}
string file_path(string path)
{
    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] == '\\')
        {
            path.insert(i, "\\");// converts E:\DocCreator to E:\\DocCreator
            i++;
        }
    }


    return path;
}

void update_count(string user)
{
    ifstream file("Data.txt");
    ofstream temp("temp.txt");
    string username,password,email,company_name,address,phone,status;

    while(getline(file,username,'|') && getline(file,password,'|') && getline(file,email,'|') && getline(file,company_name,'|') && getline(file,address,'|') && getline(file,phone,'|') && getline(file,status,'|'))
    {
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        if(user==username)
        {
            int n=stoi(status);
            n++;
            status=to_string(n);
        }
        temp<<username<<"|"<<password<<"|"<<email<<"|"<<company_name<<"|"<<address<<"|"<<phone<<"|"<<status<<"|\n";
    }



    file.close();
    temp.close();

    remove("Data.txt");
    rename("temp.txt","Data.txt");

}

void update_docCount(string input)
{
    ifstream file("statistics.txt");
    ofstream temp("temp.txt");

    string line;

    while (getline(file, line))
    {
        if (line.find(input) != string::npos)
        {
            if(input=="Total Users")
            {
                int pos = line.find(':');
                int count = stoi(line.substr(pos + 1));

                count++;

                line = input + " : " + to_string(count);
            }
            else
            {
                int pos = line.find(':');
                int count = stoi(line.substr(pos + 1));

                count++;

                line = "** " + input + " : " + to_string(count);
            }
        }
        temp << line << endl;
    }

    file.close();
    temp.close();

    remove("statistics.txt");
    rename("temp.txt", "statistics.txt");
}
