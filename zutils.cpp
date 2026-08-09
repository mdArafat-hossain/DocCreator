#include<iostream>
#include<string>
#include<ctime>
#include<cctype>
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

int checkDigit(string lochoice) // check if the password is digit
{
    for(char ch : lochoice)
    {
        if(!isdigit(ch))
        {
            return 0; //if the password is not fully digit it'll return 0
        }
    }
    int l2choice = stoi(lochoice); //converts string to int
    return l2choice; //return converted int value

}
string file_path(string path)
{
    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] == '\\')
        {
            path.insert(i, "\\");
            i++;
        }
    }


    return path;
}
