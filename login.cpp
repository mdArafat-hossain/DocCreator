#include<iostream>
#include<cctype>
#include<ctime>
#include<fstream>
#include<filesystem>
#include "zutils.h"
#include "login.h"
using namespace std;
string login() //log in
    {
        string logchoice,logchoice2; //log in choice
        string username,password,email,line,pin;

        cout<<"1.User 2.Admin\n";
        cin>>logchoice;
        int l2choice=checkDigit(log2choice);

        if(l2choice==1)
        {

        cout<<"1.Register \n2.Log in\n"<<endl;

        while(true)
        {
            cin>>logchoice;
            int lchoice=checkDigit(logchoice);


            if(lchoice>2 || lchoice<1)
            {
                cout<<"Invalid Choice\n"<<endl;

            }
            else if(lchoice==1) //register
            {

                while(true)
                {
                    bool exist = false;
                    cout<<"\nEnter Username : ";
                    cin>>username;
                    ifstream file("Data.txt");
                    while(getline(file,line))
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
                        cout<<"\nUsername Already Exist. Try a different one\n"<<endl;
                    }
                    else
                    {
                        break;
                    }


                }
                while(true)
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
                        cout<<"\nInvalid Email\n"<<endl;
                    }
                }
                while(true)
                {
                    cout<<"Password : ";
                    cin>>password;
                    try
                    {
                        strnth(password);

                        ofstream file("Data.txt",ios::app);

                        file<<username<<"|"<<password<<"|"<<email<<"|\n";
                        file.close();


                        cout<<"Account Created"<<endl<<endl;

                        cout<<string(25, '-')<<"Welcome "<<username<<string(25, '-')<<endl;

                        return username;
                    }
                    catch(const char* msg)
                    {
                        cout<<"Error : "<<msg<<endl;
                    }

                }

            }
            else //log in
            {

                int chance=3;
                while(chance)
                {
                    bool found=false;
                    cout<<endl<<"\nEnter Username : ";
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
                                cout<<string(35, '-')<<"Welcome "<<username<<string(35, '-')<<endl;
                                return username;
                            }
                            cout<<endl<<"Wrong Password. Try Again"<<endl<<endl;
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
        else if(logchoice2==2)
        {
            cout<<"Enter Pin Number : ";
            cin>>pin;
            if(pin=="AdminPanel$5.23.6.11.28")
            {
                cout<<"Welcome Admin";
                co
            }
        }
    }
