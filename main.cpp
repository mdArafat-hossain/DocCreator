#include<iostream>
#include<cctype>
#include "resume.h"
#include "zutils.h"
#include "login.h"
using namespace std;

void options()
{
    cout<<"\n01.Resume / Curriculum Vitae(CV) \n02.Job Application Letter \n03.Leave Application \n4. Invoice";
    cout<<"\n05.Receipt \n06.Quotation \n07 Purchase Order \n08.Salary Slip ";
    cout<<"\n09.Medical Certificate (Template) \n10.Certificate \n11.Recommendation Letter \n12.Complaint Letter";
    cout<<"\n13.Business Letter \n14.Notice \n15.Memo \n16.Meeting Minutes\n";
}

void option2()
{
    cout<<"\n01.Invoice \n02.Receipt \n03.Quotation \n04.Purchase Order \n05.Salary Slip";
    cout<<"06.Certificate \n07.Recommendation Letter \n08.Complaint Letter";
    cout<<"\n09.Business Letter \n10.Notice \n12.Memo \n13.Meeting Minutes\n";
}

int main()
{
    cout<<string(40,'-')<<" DocCreator "<<string(40,'-');
    bool state = true;
    string uchoice,rechoice;// document choice, repeat choice

    while(true)
    {
        string username = login();
        if(username=="guest")
        {
            options();
            cout<<"\nWhat would you like to create today?"<<endl;
            while(state)
            {
                cout<<"Choice : ";
                cin>>uchoice;
                int fichoice=checkDigit(uchoice);//final choice

                if(fichoice==0)
                {
                    cout<<"Invalid Choice\n\n";
                    continue;
                }
                else
                {
                    switch(fichoice)
                    {
                    case 1:
                        resume(username);
                        state=false;
                        break;
                    case 2:
                        cout<<"2";
                        state=false;
                        break;
                    case 3:
                        cout<<"3";
                        state=false;
                        break;
                    case 4:
                        cout<<"4";
                        state=false;
                        break;
                    case 5:
                        cout<<"5";
                        state=false;
                        break;
                    case 6:
                        cout<<"6";
                        state=false;
                        break;
                    case 7:
                        cout<<"7";
                        state=false;
                        break;
                    case 8:
                        cout<<"8";
                        state=false;
                        break;
                    case 9:
                        cout<<"9";
                        state=false;
                        break;
                    case 10:
                        cout<<"10";
                        state=false;
                        break;
                    case 11:
                        cout<<"11";
                        state=false;
                        break;
                    case 12:
                        cout<<"12";
                        state=false;
                        break;
                    case 13:
                        cout<<"13";
                        state=false;
                        break;
                    case 14:
                        cout<<"14";
                        state=false;
                        break;
                    case 15:
                        cout<<"15";
                        state=false;
                        break;
                    case 16:
                        cout<<"16";
                        state=false;
                        break;

                    default:
                        cout<<"Invalid Choice\n\n";

                    }

                }
            }

        }
        else if(isalpha(username[0]))//company
        {
            option2();
            cout<<"\nWhat would you like to create today?\n"<<endl;
            while(state)
            {
                cout<<"Choice : ";
                cin>>uchoice;
                int fichoice=checkDigit(uchoice);//final choice

                if(fichoice==0)
                {
                    cout<<"Invalid Choice\n\n";
                }
                else
                {
                    switch(fichoice)
                    {
                    case 1:
                        cout<<"1";
                        state=false;
                        break;
                    case 2:
                        cout<<"2";
                        state=false;
                        break;
                    case 3:
                        cout<<"3";
                        state=false;
                        break;
                    case 4:
                        cout<<"4";
                        state=false;
                        break;
                    case 5:
                        cout<<"5";
                        state=false;
                        break;
                    case 6:
                        cout<<"6";
                        state=false;
                        break;
                    case 7:
                        cout<<"7";
                        state=false;
                        break;
                    case 8:
                        cout<<"8";
                        state=false;
                        break;
                    case 9:
                        cout<<"9";
                        state=false;
                        break;
                    case 10:
                        cout<<"10";
                        state=false;
                        break;
                    case 11:
                        cout<<"11";
                        state=false;
                        break;
                    case 12:
                        cout<<"12";
                        state=false;
                        break;
                    case 13:
                        cout<<"13";
                        state=false;
                        break;
                    default:
                        cout<<"Invalid Choice\n\n";

                    }

                }
            }
        }

        cout<<"\nWant to continue?(Y/N) : ";
        cin>>rechoice;
        if(rechoice=="Y" || rechoice=="y")
        {
            continue;
        }
        else
        {
            cout<<"\nThank You for using DocCreator\n";
            break;
        }
    }
}
