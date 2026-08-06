#include<iostream>
#include "resume.h"
#include "zutils.h"
#include "login.h"
using namespace std;



void options()
{
    cout<<"1.Resume / Curriculum Vitae(CV) \n2.Job Application Letter \n3.Leave Application \n4.Invoice \n5.Receipt";
    cout<<"\n6.Quotation \n7.Purchase Order \n8.Salary Slip \n9.Medical Certificate (Template) \n10.Certificate";
    cout<<"\n11.Recommendation Letter \n12.Complaint Letter \n13.Business Letter \n14.Notice \n15.Memo";
    cout<<"\n16.Meeting Minutes \n";
}

int main()
{


    string dchoice,dchoice3;// document choice
    string username = login();
    options();
    if(username[0]>'0')
    {
        cout<<"\nWhich service do you want ?\n"<<endl;
        while(true)
        {


            cin>>dchoice;
            cout<<endl;
            int dchoice2=checkDigit(dchoice);


            switch(dchoice2)
            {
            case 1:
                resume(username);
                break;
            case 2:
                cout<<"2";
                break;
            case 3:
                cout<<"3";
                break;
            case 4:
                cout<<"4";
                break;
            case 5:
                cout<<"5";
                break;
            case 6:
                cout<<"6";
                break;
            case 7:
                cout<<"7";
                break;
            case 8:
                cout<<"8";
                break;
            case 9:
                cout<<"9";
                break;
            case 10:
                cout<<"10";
                break;
            case 11:
                cout<<"11";
                break;
            case 12:
                cout<<"12";
                break;
            case 13:
                cout<<"13";
                break;
            case 14:
                cout<<"14";
                break;
            case 15:
                cout<<"15";
                break;
            case 16:
                cout<<"16";
                break;
            case 17:
                cout<<"17";
                break;
            case 18:
                cout<<"18";
                break;
            case 19:
                cout<<"19";
                break;

            default:
                cout<<"Invalid Choice";

            }
            cout<<"\nWant to continue(Y/N) : ";
            cin>>dchoice3;
            if(dchoice3=="Y" || dchoice3=="y")
            {
                continue;
            }
            else
            {
                break;
            }
        }
    }

}


