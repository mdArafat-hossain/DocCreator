#include<iostream>
#include<cctype>
#include<fstream>
#include<sstream>

#include "resume.h"
#include "zutils.h"
#include "login.h"
#include "invoice.h"
#include "Job_Application.h"
#include "Leave_Application.h"
#include "Receipt.h"
#include "Quotation.h"
#include "Purchase_order.h"
#include "Salary_Slip.h"
#include "Medical_Certificate.h"
#include "Meeting_Minutes.h"
#include "Cover_page.h"
#include "Certificate.h"
#include "Recommendation.h"
#include "Complaint_letter.h"
#include "business.h"
#include "notice.h"
#include "memo.h"

using namespace std;

void options()
{
    cout<<"\n01.Resume / Curriculum Vitae(CV) \n02.Job Application Letter \n03.Leave Application \n04.Invoice";
    cout<<"\n05.Receipt \n06.Quotation \n07 Purchase Order \n08.Salary Slip ";
    cout<<"\n09.Medical Certificate (Template) \n10.Meeting Minutes \n11.Assignment Cover Page \n12.Certificate \n13.Recommendation Letter \n14.Complaint Letter";
    cout<<"\n15.Business Letter \n16.Notice \n17.Memo\n";
}

void option2()
{
    cout<<"\n01.Invoice \n02.Receipt \n03.Quotation \n04.Purchase Order \n05.Salary Slip";
    cout<<"\n06.Meeting Minutes \n07.Certificate \n08.Business Letter \n9.Notice \n10.Memo";
}
int main(){

    cout<<string(40,'-')<<" DocCreator "<<string(40,'-');

    string uchoice,rechoice,ct;
    string name, email, organization_name, address,phone,password, status;
    string sname, semail, sorganization_name, saddress,sphone;

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
                        Job_Application();
                        update_docCount("Job Application Letter Generated");
                        state=false;
                        break;
                    case 3:
                        leave_Application();
                        update_docCount("Leave Application Generated");
                        state=false;
                        break;
                    case 4:
                        invoice(sname, saddress, sphone, semail);
                        update_docCount("Invoice Generated");
                        state=false;
                        break;
                    case 5:
                        receipt(sname);
                        update_docCount("Receipt Generated");
                        state=false;
                        break;
                    case 6:
                        quotation(sname, saddress, sphone, semail);
                        update_docCount("Quotation Generated");
                        state=false;
                        break;
                    case 7:
                        purchase_order(sname, saddress);
                        update_docCount("Purchase Order Generated");
                        state=false;
                        break;
                    case 8:
                        salary_slip(sname,saddress,sphone);
                        update_docCount("Salary Slip Generated");
                        state=false;
                        break;
                    case 9:
                        medical_certificate();
                        update_docCount("Medical Certificate Generated");
                        state=false;
                        break;
                    case 10:
                        meeting_minutes(sname);
                        update_docCount("Meeting Minutes Generated");
                        state=false;
                        break;
                    case 11:
                        Cover_page();
                        update_docCount("Assignment Cover Page Generated");
                        state=false;
                        break;
                    case 12:
                        Certificate(sorganization_name);
                        ct="Certificate Generated";
                        update_docCount(ct);
                        state=false;
                        break;
                    case 13:
                        recommendation();
                        ct="Recommendation Letter Generated";
                        update_docCount(ct);
                        state=false;
                        break;
                    case 14:
                        complaint();
                        update_docCount("Complaint Letter Generated");
                        state=false;
                        break;
                    case 15:
                        business(sorganization_name, saddress);
                        update_docCount("Business Letter Generated");
                        state=false;
                        break;
                    case 16:
                        notice(sorganization_name,saddress);
                        update_docCount("Notice Generated");
                        state=false;
                        break;
                    case 17:
                        memo(sorganization_name);
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
        ifstream file("Data.txt");
        string line;

        while (getline(file, line))
        {
            stringstream ss(line);



            getline(ss, name, '|');
            getline(ss, password, '|');
            getline(ss, email, '|');
            getline(ss, organization_name, '|');
            getline(ss, address, '|');
            getline(ss, phone, '|');
            getline(ss, status, '|');

            if (name == username)
            {
                sname = name;
                semail = email;
                sorganization_name = organization_name;
                saddress = address ;
                sphone = phone;

                break;
            }
        }
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
                        invoice(sname, saddress, sphone, semail);
                        update_docCount("Invoice Generated");
                        state=false;
                        break;
                    case 2:
                        receipt(sname);
                        update_count(username);
                        update_docCount("Receipt Generated");
                        state=false;
                        break;
                    case 3:
                        quotation(sname, saddress,sphone,semail);
                        update_count(username);
                        update_docCount("Quotation Generated");
                        state=false;
                        break;
                    case 4:
                        purchase_order(sname, saddress);
                        update_count(username);
                        update_docCount("Purchase Order Generated");
                        state=false;
                        break;
                    case 5:
                        salary_slip(sname,saddress,sphone);
                        update_docCount("Salary Slip Generated");
                        state=false;
                        break;
                    case 6:
                        meeting_minutes(sname);
                        update_docCount("Meeting Minutes Generated");
                        state=false;
                        break;
                    case 7:
                        Certificate(sorganization_name);
                        update_count(username);
                        update_docCount("Certificate Generated");
                        state=false;
                        break;
                    case 8:
                        business(sorganization_name, saddress);
                        update_count(username);
                        update_docCount("Business Letter Generated");
                        state=false;
                        break;
                    case 9:
                        notice(sorganization_name,saddress);
                        update_count(username);
                        update_docCount("Notice Generated");
                        state=false;
                        break;
                    case 10:
                        memo(sorganization_name);
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
