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
    cout<<"\n09.Medical Certificate (Template) \n10.Meeting Minutes \n11.Assignment Cover Page \n12.Certificate \n13.Recommendation Letter \n14.Complaint Letter";
    cout<<"\n15.Business Letter \n16.Notice \n17.Memo\n";
}

void option2()
{
    cout<<"\n01.Invoice \n02.Receipt \n03.Quotation \n04.Purchase Order \n05.Salary Slip";
    cout<<"\n06.Meeting Minutes \n07.Certificate \n08.Business Letter \n9.Notice \n10.Memo";
}

int main()
{
    cout<<string(40,'-')<<" DocCreator "<<string(40,'-');

    string uchoice,rechoice,ct;// document choice, repeat choice

    while(true)
    {
        bool state = true;
        string username = login();
        if(username=="guest")//user
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
                        resume();
                        update_docCount("Resume Generated");
                        state=false;
                        break;
                    case 2:
                        cout<<"2";
                        update_docCount("Job Application Letter Generated");
                        state=false;
                        break;
                    case 3:
                        cout<<"3";
                        update_docCount("Leave Application Generated");
                        state=false;
                        break;
                    case 4:
                        cout<<"4";
                        update_docCount("Invoice Generated");
                        state=false;
                        break;
                    case 5:
                        cout<<"5";
                        update_docCount("Receipt Generated");
                        state=false;
                        break;
                    case 6:
                        cout<<"6";
                        update_docCount("Quotation Generated");
                        state=false;
                        break;
                    case 7:
                        cout<<"7";
                        update_docCount("Purchase Order Generated");
                        state=false;
                        break;
                    case 8:
                        cout<<"8";
                        update_docCount("Salary Slip Generated");
                        state=false;
                        break;
                    case 9:
                        cout<<"9";
                        update_docCount("Medical Certificate Generated");
                        state=false;
                        break;
                    case 10:
                        cout<<"10";
                        update_docCount("Meeting Minutes Generated");
                        state=false;
                        break;
                    case 11:
                        cout<<"11";
                        update_docCount("Assignment Cover Page Generated");
                        state=false;
                        break;
                    case 12:
                        cout<<"12";
                        ct="Certificate Generated";
                        update_docCount(ct);
                        state=false;
                        break;
                    case 13:
                        cout<<"13";
                        ct="Recommendation Letter Generated";
                        update_docCount(ct);
                        state=false;
                        break;
                    case 14:
                        cout<<"14";
                        update_docCount("Complaint Letter Generated");
                        state=false;
                        break;
                    case 15:
                        cout<<"15";
                        update_docCount("Business Letter Generated");
                        state=false;
                        break;
                    case 16:
                        cout<<"16";
                        update_docCount("Notice Generated");
                        state=false;
                        break;
                    case 17:
                        cout<<"17";
                        update_docCount("Memo Generated");
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
                        update_count(username);
                        update_docCount("Invoice Generated");
                        state=false;
                        break;
                    case 2:
                        cout<<"2";
                        update_count(username);
                        update_docCount("Receipt Generated");
                        state=false;
                        break;
                    case 3:
                        cout<<"3";
                        update_count(username);
                        update_docCount("Quotation Generated");
                        state=false;
                        break;
                    case 4:
                        cout<<"4";
                        update_count(username);
                        update_docCount("Purchase Order Generated");
                        state=false;
                        break;
                    case 5:
                        cout<<"5";
                        update_count(username);
                        update_docCount("Salary Slip Generated");
                        state=false;
                        break;
                    case 6:
                        cout<<"6";
                        update_count(username);
                        update_docCount("Meeting Minutes Generated");
                        state=false;
                        break;
                    case 7:
                        cout<<"7";
                        update_count(username);
                        update_docCount("Certificate Generated");
                        state=false;
                        break;
                    case 8:
                        cout<<"8";
                        update_count(username);
                        update_docCount("Business Letter Generated");
                        state=false;
                        break;
                    case 9:
                        cout<<"9";
                        update_count(username);
                        update_docCount("Notice Generated");
                        state=false;
                        break;
                    case 10:
                        cout<<"10";
                        update_count(username);
                        update_docCount("Memo Generated");
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
