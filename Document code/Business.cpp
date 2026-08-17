#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#include "zutils.h"
#include "login.h"
#include "business.h"

using namespace std;

void business(string sorganization_name, string saddress)
{
    cin.ignore();
    string filename,ppath,path2;

    string date;
    string recipientName, designation, companyName, companyAddress;
    string subject;
    string senderCompany, purpose, proposal, benefit, availability;
    string senderName, senderDesignation, senderPhone, senderEmail;

    cout << "\n===== Business Letter Generator (HTML) =====\n\n";

    cout << "Date: ";
    getline(cin, date);

    cout << "\nRecipient Information\n";

    cout << "Recipient Name: ";
    getline(cin, recipientName);

    cout << "Designation: ";
    getline(cin, designation);

    companyName = sorganization_name;
    companyAddress = saddress;

    if(companyAddress.empty() || companyName.empty())
    {
        cout << "Company Name: ";
        getline(cin, companyName);

        cout << "Company Address: ";
        getline(cin, companyAddress);
        }
        cout << "\nSubject: ";
        getline(cin, subject);



    cout << "\nLetter Content\n";

    cout << "Sender Company / Organization: ";
    getline(cin, senderCompany);

    cout << "Purpose of the Letter: ";
    getline(cin, purpose);

    cout << "Proposal / Request / Business Matter: ";
    getline(cin, proposal);

    cout << "Expected Benefit / Purpose: ";
    getline(cin, benefit);

    cout << "Availability / Additional Information: ";
    getline(cin, availability);


    cout << "\nSender Information\n";

    cout << "Sender Name: ";
    getline(cin, senderName);

    cout << "Sender Designation: ";
    getline(cin, senderDesignation);

    cout << "Sender Company: ";
    getline(cin, senderCompany);

    cout << "Phone Number: ";
    getline(cin, senderPhone);

    cout << "Email Address: ";
    getline(cin, senderEmail);

    cout<<"\nEnter file location : ";
    getline(cin,ppath);

    stringstream ss(companyName);
    ss >> filename;

    string path = file_path(ppath);
    string time = Date_Time();
    int l = path.length();
    if(path[l-1]=='\\')
    {
        path2 = path + filename + "(Business Letter)" + time + ".html";
    }
    else
    {
        path2 = path + "\\\\" + filename + "(Business Letter)" + time + ".html";
    }


    ofstream file(path2);

    file << "<!DOCTYPE html>\n";
    file << "<html lang=\"en\">\n";

    file << "<head>\n";

    file << "<meta charset=\"UTF-8\">\n";
    file << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";

    file << "<title>Business Letter - "
         << subject
         << "</title>\n";

    file << "<style>\n";

    file << "* {\n";
    file << "    box-sizing: border-box;\n";
    file << "}\n";

    file << "body {\n";
    file << "    margin: 0;\n";
    file << "    padding: 40px 20px;\n";
    file << "    background: #eef1f4;\n";
    file << "    color: #252525;\n";
    file << "    font-family: Georgia, 'Times New Roman', serif;\n";
    file << "}\n";

    file << ".page {\n";
    file << "    width: 850px;\n";
    file << "    max-width: 100%;\n";
    file << "    min-height: 1100px;\n";
    file << "    margin: auto;\n";
    file << "    background: white;\n";
    file << "    padding: 60px 70px;\n";
    file << "    box-shadow: 0 8px 28px rgba(0,0,0,0.10);\n";
    file << "}\n";

    file << ".top-line {\n";
    file << "    height: 5px;\n";
    file << "    background: #37474f;\n";
    file << "    margin-bottom: 30px;\n";
    file << "}\n";

    file << ".date {\n";
    file << "    text-align: right;\n";
    file << "    font-size: 15px;\n";
    file << "    margin-bottom: 35px;\n";
    file << "}\n";

    file << ".recipient {\n";
    file << "    font-size: 15px;\n";
    file << "    line-height: 1.7;\n";
    file << "    margin-bottom: 28px;\n";
    file << "}\n";

    file << ".subject {\n";
    file << "    font-family: Arial, sans-serif;\n";
    file << "    font-size: 15px;\n";
    file << "    font-weight: bold;\n";
    file << "    padding: 14px 18px;\n";
    file << "    margin-bottom: 28px;\n";
    file << "    background: #f1f4f5;\n";
    file << "    border-left: 5px solid #37474f;\n";
    file << "    color: #263238;\n";
    file << "}\n";

    file << ".salutation {\n";
    file << "    font-size: 16px;\n";
    file << "    margin-bottom: 22px;\n";
    file << "}\n";

    file << ".letter p {\n";
    file << "    font-size: 15.5px;\n";
    file << "    line-height: 1.85;\n";
    file << "    text-align: justify;\n";
    file << "    margin: 0 0 20px 0;\n";
    file << "}\n";

    file << ".signature {\n";
    file << "    margin-top: 40px;\n";
    file << "    font-size: 15px;\n";
    file << "    line-height: 1.7;\n";
    file << "}\n";

    file << ".signature-name {\n";
    file << "    margin-top: 18px;\n";
    file << "    font-family: Arial, sans-serif;\n";
    file << "    font-size: 17px;\n";
    file << "    font-weight: bold;\n";
    file << "    color: #263238;\n";
    file << "}\n";

    file << ".signature-details {\n";
    file << "    font-family: Arial, sans-serif;\n";
    file << "    font-size: 13px;\n";
    file << "    color: #607078;\n";
    file << "}\n";

    file << ".footer {\n";
    file << "    margin-top: 55px;\n";
    file << "    padding-top: 14px;\n";
    file << "    border-top: 1px solid #d5dde0;\n";
    file << "    text-align: center;\n";
    file << "    font-family: Arial, sans-serif;\n";
    file << "    font-size: 10px;\n";
    file << "    color: #78909c;\n";
    file << "}\n";

    file << "@media print {\n";

    file << "    body {\n";
    file << "        background: white;\n";
    file << "        padding: 0;\n";
    file << "    }\n";

    file << "    .page {\n";
    file << "        width: 100%;\n";
    file << "        min-height: auto;\n";
    file << "        box-shadow: none;\n";
    file << "        padding: 45px 55px;\n";
    file << "    }\n";

    file << "}\n";

    file << "</style>\n";

    file << "</head>\n";

    file << "<body>\n";
    file << "<div class=\"page\">\n";

    file << "<div class=\"top-line\"></div>\n";

    file << "<div class=\"date\">\n";
    file << date;
    file << "</div>\n";

    file << "<div class=\"recipient\">\n";

    file << "<strong>"
         << recipientName
         << "</strong><br>\n";

    file << designation << "<br>\n";

    file << companyName << "<br>\n";

    file << companyAddress << "\n";

    file << "</div>\n";

    file << "<div class=\"subject\">\n";

    file << "Subject: "
         << subject;

    file << "</div>\n";

    file << "<div class=\"salutation\">\n";

    file << "Dear "
         << recipientName
         << ",\n";

    file << "</div>\n";

    file << "<div class=\"letter\">\n";

    file << "<p>\n";

    file << "I am writing on behalf of <strong>"
         << senderCompany
         << "</strong> regarding "
         << purpose
         << ".";

    file << "</p>\n";

    file << "<p>\n";

    file << "We would like to "
         << proposal
         << ". We believe this can "
         << benefit
         << " and would be pleased to discuss the matter further.";

    file << "</p>\n";

    file << "<p>\n";

    file << availability
         << " We look forward to your response and the opportunity "
         "to work together.";

    file << "</p>\n";

    file << "<p>\n";

    file << "Thank you for your time and consideration.";

    file << "</p>\n";


    file << "</div>\n";

    file << "<div class=\"signature\">\n";

    file << "Sincerely,<br>\n";

    file << "<div class=\"signature-name\">"
         << senderName
         << "</div>\n";

    file << "<div class=\"signature-details\">\n";

    file << senderDesignation << "<br>\n";

    file << senderCompany << "<br>\n";

    file << senderPhone << "<br>\n";

    file << senderEmail << "\n";

    file << "</div>\n";

    file << "</div>\n";

    file << "<div class=\"footer\">\n";

    file << "Business Letter &nbsp; | &nbsp; Generated by DocCreator";

    file << "</div>\n";
    file << "</div>\n";
    file << "</body>\n";
    file << "</html>\n";


    file.close();


    cout << "\nBusiness Letter generated successfully!\n";
    cout << "File Name : "<< filename<<endl;
    cout<<"File Location : "<< path2<<endl;
    cout << "Open it in Chrome, Edge, or Firefox.\n";
}

