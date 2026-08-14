#include<iostream>
#include<cctype>
#include<ctime>
#include<fstream>
#include<filesystem>
#include "zutils.h"
#include "login.h"
#include "adbout.h"
using namespace std;

string registeruser()
{
    string username,password,company_name,email,phone,address,line,status,pin;
    while(true)//username
    {
        bool exist = false;
        while(true)
        {
            cout<<"\nEnter Username : ";
            cin>>username;
            if(!isalpha(username[0])) //username first character cannot be digit
            {
                cout<<"Error : The first character must be a letter (A–Z or a–z)"<<endl;
            }
            else
            {
                break;
            }
        }
        ifstream file("Data.txt");
        while(getline(file,line))//check every line of Data.txt
        {
            stringstream check(line);
            string c_name;
            getline(check,c_name,'|');
            if(c_name==username)
            {
                exist = true;
                break;
            }
        }
        if(exist)
        {
            cout<<"Username Already Exist. Try a different one"<<endl;
        }
        else
        {
            break;
        }
        file.close();

    }
    while(true)//password
    {
        cout<<"Password : ";
        cin>>password;
        try
        {
            strnth(password); // check password strength
            break;
        }
        catch(const char* msg)
        {
            cout<<"Error : "<<msg<<endl;
        }

    }
    while(true)//email
    {
        bool dot=false;
        int index=0,cont2=0;//counts how many at the dots are there
        cout<<"Email Address  : ";
        cin>>email;

        for(int i=0; i<email.length(); i++)
        {
            if(email[i]=='@')
            {
                index=i;
                cont2++;
            }
        }

        if (cont2==1)
        {
            for(int j=index+1; j<email.length(); j++)
            {
                if(email[j]=='.')
                {
                    dot=true;
                    break;
                }
            }
        }

        if(cont2==1 && dot)
        {
            break;
        }
        else
        {
            cout<<"Invalid Email\n"<<endl;
        }
    }
    cin.ignore();
    cout<<"Company Name : ";
    getline(cin,company_name);
    cout<<"Address : ";
    getline(cin,address);
    cout<<"Phone Number : ";
    getline(cin,phone);
    status="0";
    ofstream file("Data.txt",ios::app);
    file<<username<<"|"<<password<<"|"<<email<<"|"<<company_name<<"|"<<address<<"|"<<phone<<"|"<<status<<"|"<<"\n";
    file.close();
    update_docCount("Total Users");
    cout<<"\nAccount Created"<<endl<<endl;
    return username;
}


string login() //log in
{
    string pri_choice,userlog,admin_choice; //log in choice
    string username,password,company_name,email,phone,address,line,status,pin;
    string c_password; //confirm password

    cout<<"\n\n1.User \n2.Company \n3.Admin \n4.About\n\n";
    while(true)
    {
        cin>>pri_choice;//primary choice

        int primary_choice=checkDigit(pri_choice);//int version

        if (primary_choice==1)// guest
        {
            cout<<"\nWelcome Guest,"<<endl;
            return "guest";
        }
        else if(primary_choice==2) //company
        {
            cout<<string(42,'-')<<" LOGIN "<<string(42,'-');
            cout<<"\n\n1.Register \n2.Sign in\n"<<endl;

            while(true)
            {
                cin>>userlog;
                int logchoice=checkDigit(userlog);


                if(logchoice>2 || logchoice<1)
                {
                    cout<<"Invalid Choice\n"<<endl;

                }
                else if(logchoice==1) //register
                {
                    string user=registeruser();
                    cout<<"Welcome "<<user<<","<<endl;
                    return user;
                }
                else //log in
                {

                    int chance=3;
                    while(chance)
                    {
                        bool found=false;
                        cout<<endl<<"Enter Username : ";
                        cin>>username;
                        cout<<"Enter Password : ";
                        cin>>password;
                        ifstream file("Data.txt");
                        while(getline(file,line))
                        {
                            stringstream check(line);
                            string c_name,c_pass;
                            getline(check,c_name,'|');
                            getline(check,c_pass,'|');

                            if(c_name==username)
                            {
                                found=true;
                                if(c_pass==password)
                                {
                                    cout<<"\nWelcome "<<username<<","<<endl;
                                    return username;
                                }
                                cout<<endl<<"Wrong Password."<<endl<<endl;
                                break;

                            }


                        }
                        if(!found)
                        {
                            cout<<endl<<"Account Not Found "<<endl;

                        }
                        chance--;
                    }
                    cout<<"Account Log in Failed"<<endl;
                    return "0";
                }
            }
        }
        else if(primary_choice==3)//admin
        {
            int i=3;
            while(i>0)
            {
                cout<<"Enter Pin Number : ";
                cin>>pin;
                if(pin!="123")
                {
                    i--;
                    cout<<"Wrong Pin.\n\n";

                }
                else
                {
                    i=0;
                    cout<<"Welcome Admin, ";
                    cout<<"What would you like to manage today? ";
                    cout<<"\n1.View all users \n2.Search users \n3.Add User \n4.Delete User \n5.View System Statistics";
                    while(true)
                    {
                        cout<<"\nChoice : ";
                        cin>>admin_choice;
                        int logchoice=checkDigit(admin_choice);
                        if(logchoice<6 && logchoice>0)
                        {
                            admin(logchoice);
                            return "0";
                        }
                        else
                        {
                            cout<<"Invalid Choice";
                        }
                    }

                }
            }
            cout<<"Admin Log in failed\n";
            return "0";
        }
        else if(primary_choice==4)//about
        {
            about();
            return "0";

        }
        else
        {
            cout<<"Invalid Choice\n";

        }
    }
}
