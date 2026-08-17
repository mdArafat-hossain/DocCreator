#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "resume.h"
#include "zutils.h"
#include "login.h"
#include "Leave_Application.h"
using namespace std;
void leave_Application()
{
    cin.ignore();
    string filename,ppath,path2;
    string name, address, phone, email, date;
    string recipient, organization, organizationAddress;
    string startDate, endDate, reason, joiningDate;
    string position,greetings;


    // Taking input
    cout << "========== LEAVE APPLICATION ==========\n\n";

    cout << "Enter your full name: ";
    getline(cin, name);

    cout << "Enter your address: ";
    getline(cin, address);

    cout << "Enter your phone number: ";
    getline(cin, phone);

    cout << "Enter your email: ";
    getline(cin, email);

    cout << "Enter date: ";
    getline(cin, date);

    cout << "Enter recipient name/department (press Enter to skip): ";
    getline(cin, recipient);

    while(recipient.empty())
    {
        cout << "Enter recipient gender (M/F) : ";
        getline(cin,greetings);
        if(greetings == "M" || greetings == "m")
        {
            greetings ="Sir";
            break;
        }
        else if(greetings == "F" || greetings == "f")
        {
            greetings = "Ma'am";
            break;

        }
        else
        {
            cout<<"Invalid choice\n";
        }
    }

    cout << "Enter organization name: ";
    getline(cin, organization);

    cout << "Enter organization address: ";
    getline(cin, organizationAddress);

    cout << "Enter start date of leave: ";
    getline(cin, startDate);

    cout << "Enter end date of leave: ";
    getline(cin, endDate);

    cout << "Enter reason for leave (Noun phrase) : ";
    getline(cin, reason);

    cout << "Enter joining/resuming date: ";
    getline(cin, joiningDate);

    cout << "Enter your position/class/department: ";
    getline(cin, position);


    // Default recipient
    if (recipient.empty())
    {
        recipient = "HR Department";
    }

    cout<<"\nEnter file location : ";
    getline(cin,ppath);

    stringstream ss(name); // generate one word from multiple words (Arafat Hossain Rizve)== Arafat
    ss >> filename;

    string path = file_path(ppath);
    string time = Date_Time();
    int l = path.length();
    if(path[l-1]=='\\')
    {
        path2 = path + filename + "(Job_Application)" + time + ".html"; //E:\\arafat(Resume)_2026-07-28_1237.html
    }
    else
    {
        path2 = path + "\\\\" + filename + "(Job_Application))" + time + ".html"; //E:\\DocCreator\\arafat(Resume)_2026-07-28_1237.html
    }


    ofstream file(path2);


    // HTML
    file << "<!DOCTYPE html>\n";
    file << "<html>\n";

    file << "<head>\n";
    file << "<meta charset='UTF-8'>\n";
    file << "<title>Leave Application</title>\n";

    file << "<style>\n";

    file << "body {";
    file << "font-family: Arial, sans-serif;";
    file << "margin: 60px;";
    file << "line-height: 1.6;";
    file << "color: #222;";
    file << "}\n";

    file << ".subject {";
    file << "font-weight: bold;";
    file << "margin-top: 25px;";
    file << "}\n";

    file << ".signature {";
    file << "margin-top: 30px;";
    file << "}\n";

    file << "</style>\n";
    file << "</head>\n";


    file << "<body>\n";


    // Applicant information
    file << "<p>";
    file << date <<"<br>";
    file << "<strong>" << name << "</strong><br>";
    file << address << "<br>";
    file << phone << "<br>";
    file << email << "<br>";

    file << "</p>\n";


    // Recipient information
    file << "<p>";
    file << recipient << "<br>";
    file << organization << "<br>";
    file << organizationAddress;
    file << "</p>\n";


    // Subject
    file << "<p class='subject'>";
    file << "Subject: Application for Leave";
    file << "</p>\n";


    // Greeting
    file << "<p>Dear " <<greetings<<" , "<<"</p>\n";


    // Paragraph 1
    file << "<p>";

    file << "I am writing to request leave from "
         << "<strong>" << startDate << "</strong> to "
         << "<strong>" << endDate << "</strong> "
         << "due to <strong>" << reason << "</strong>.";

    file << "I kindly request you to grant me leave for the "
         "mentioned period. I will make sure to complete any "
         "pending responsibilities or work and resume my regular "
         "activities on ";

    file << "<strong>" << joiningDate << "</strong>.";

    file << "</p>\n";


    // Paragraph 3
    file << "<p>";

    file << "I would be grateful for your kind consideration "
         "and approval of my leave request. Thank you for your understanding.";

    file << "</p>\n";


    // Signature
    file << "<p class='signature'>";
    file << "Sincerely,<br>";
    file << "<strong>" << name << "</strong><br>";
    file << position << "<br>";
    file << phone << "<br>";
    file << email;
    file << "</p>\n";


    // End HTML
    file << "</body>\n";
    file << "</html>\n";

    file.close();


    cout << "\nLeave Application generated successfully!\n";
    cout << "File Name : "<< filename<<endl;
    cout<<"File Location : "<< path2<<endl;
    cout << "Open it in Chrome, Edge, or Firefox.\n";

}
