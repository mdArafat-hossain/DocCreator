#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include "zutils.h"
#include "login.h"
#include "notice.h"
using namespace std;

void notice(string sorganization_name, string saddress)
{
    cin.ignore();
    string filename, path2, ppath;
    string organizationName, department, organizationAddress;
    string noticeNumber, noticeDate, subject, noticeBody;
    string authorityName, authorityDesignation;

    cout <<"\n===== Notice Generator (HTML) =====\n\n";

    organizationName = sorganization_name;
    organizationAddress = saddress;

    if(organizationAddress.empty() || organizationName.empty())
    {
        cout << "Enter Organization Address: ";
        getline(cin, organizationAddress);
        cout << "Enter Organization / University Name: ";
        getline(cin, organizationName);
    }

    cout << "Enter Department / Office Name: ";
    getline(cin, department);

    cout << "\nNotice Information\n";

    cout << "Enter Notice Number: ";
    getline(cin, noticeNumber);

    cout << "Enter Notice Date (DD/MM/YYYY): ";
    getline(cin, noticeDate);

    cout << "Enter Notice Subject: ";
    getline(cin, subject);

    cout << "Enter Notice Content:\n";
    getline(cin, noticeBody);

    cout << "\nAuthorized By\n";

    cout << "Enter Authority Name: ";
    getline(cin, authorityName);

    cout << "Enter Authority Designation: ";
    getline(cin, authorityDesignation);

    time_t now = time(0);
    tm *localTime = localtime(&now);

    int day = localTime->tm_mday;
    int month = localTime->tm_mon + 1;
    int year = localTime->tm_year + 1900;

    stringstream ss(organizationName); // generate one word from multiple words (Arafat Hossain Rizve)== Arafat
    ss >> filename;

    cout<<"\nEnter file location : ";
    getline(cin,ppath);

    string path = file_path(ppath);
    string time = Date_Time();
    int l = path.length();
    if(path[l-1]=='\\')
    {
        path2 = path + filename + "(Invoice)" + time + ".html"; //E:\\arafat(Resume)_2026-07-28_1237.html
    }
    else
    {
        path2 = path + "\\\\" + filename + "(Invoice)" + time + ".html"; //E:\\DocCreator\\arafat(Resume)_2026-07-28_1237.html
    }

    ofstream file(path2);

    file << "<!DOCTYPE html>\n";
    file << "<html>\n";
    file << "<head>\n";

    file << "<meta charset='UTF-8'>\n";
    file << "<meta name='viewport' content='width=device-width, initial-scale=1.0'>\n";

    file << "<title>Official Notice</title>\n";

    file << "<style>\n";

    file << "* {\n";
    file << "    box-sizing: border-box;\n";
    file << "}\n";

    file << "body {\n";
    file << "    margin: 0;\n";
    file << "    background: #edf1f5;\n";
    file << "    font-family: Arial, Helvetica, sans-serif;\n";
    file << "    color: #263238;\n";
    file << "}\n";

    file << ".notice-page {\n";
    file << "    width: 800px;\n";
    file << "    min-height: 1120px;\n";
    file << "    margin: 35px auto;\n";
    file << "    background: #ffffff;\n";
    file << "    padding: 55px 65px;\n";
    file << "    box-shadow: 0 5px 22px rgba(0,0,0,0.10);\n";
    file << "    position: relative;\n";
    file << "}\n";

    // Top bar
    file << ".top-bar {\n";
    file << "    position: absolute;\n";
    file << "    top: 0;\n";
    file << "    left: 0;\n";
    file << "    width: 100%;\n";
    file << "    height: 7px;\n";
    file << "    background: #123b63;\n";
    file << "}\n";

    // Header
    file << ".header {\n";
    file << "    text-align: center;\n";
    file << "    padding-bottom: 22px;\n";
    file << "    border-bottom: 1px solid #cfd8dc;\n";
    file << "}\n";

    file << ".organization {\n";
    file << "    font-size: 27px;\n";
    file << "    font-weight: bold;\n";
    file << "    color: #123b63;\n";
    file << "    text-transform: uppercase;\n";
    file << "    letter-spacing: 0.5px;\n";
    file << "}\n";

    file << ".department {\n";
    file << "    margin-top: 8px;\n";
    file << "    font-size: 15px;\n";
    file << "    font-weight: bold;\n";
    file << "    color: #455a64;\n";
    file << "}\n";

    file << ".address {\n";
    file << "    margin-top: 6px;\n";
    file << "    font-size: 12px;\n";
    file << "    color: #78909c;\n";
    file << "}\n";

    // Notice heading
    file << ".notice-heading {\n";
    file << "    text-align: center;\n";
    file << "    margin-top: 35px;\n";
    file << "}\n";

    file << ".notice-heading h1 {\n";
    file << "    display: inline-block;\n";
    file << "    margin: 0;\n";
    file << "    padding: 8px 35px;\n";
    file << "    border-top: 2px solid #123b63;\n";
    file << "    border-bottom: 2px solid #123b63;\n";
    file << "    color: #123b63;\n";
    file << "    font-size: 30px;\n";
    file << "    letter-spacing: 4px;\n";
    file << "}\n";

    // Meta information
    file << ".meta {\n";
    file << "    display: flex;\n";
    file << "    justify-content: space-between;\n";
    file << "    margin-top: 30px;\n";
    file << "    padding: 13px 16px;\n";
    file << "    background: #f4f7fa;\n";
    file << "    border: 1px solid #d9e1e7;\n";
    file << "    font-size: 13px;\n";
    file << "}\n";

    file << ".meta strong {\n";
    file << "    color: #37474f;\n";
    file << "}\n";

    // Subject
    file << ".subject {\n";
    file << "    margin-top: 35px;\n";
    file << "    padding-bottom: 13px;\n";
    file << "    border-bottom: 1px solid #e0e0e0;\n";
    file << "}\n";

    file << ".subject-label {\n";
    file << "    font-size: 12px;\n";
    file << "    text-transform: uppercase;\n";
    file << "    letter-spacing: 1.5px;\n";
    file << "    color: #78909c;\n";
    file << "    margin-bottom: 7px;\n";
    file << "}\n";

    file << ".subject-text {\n";
    file << "    font-size: 19px;\n";
    file << "    font-weight: bold;\n";
    file << "    color: #263238;\n";
    file << "}\n";

    // Body
    file << ".content {\n";
    file << "    margin-top: 30px;\n";
    file << "    font-size: 16px;\n";
    file << "    line-height: 1.9;\n";
    file << "    min-height: 420px;\n";
    file << "    white-space: pre-line;\n";
    file << "}\n";

    // Important notice box
    file << ".important {\n";
    file << "    margin-top: 25px;\n";
    file << "    padding: 15px 18px;\n";
    file << "    border-left: 4px solid #123b63;\n";
    file << "    background: #f4f7fa;\n";
    file << "    font-size: 13px;\n";
    file << "    color: #455a64;\n";
    file << "}\n";

    // Signature
    file << ".signature-area {\n";
    file << "    margin-top: 65px;\n";
    file << "    display: flex;\n";
    file << "    justify-content: flex-end;\n";
    file << "}\n";

    file << ".signature {\n";
    file << "    width: 230px;\n";
    file << "    text-align: center;\n";
    file << "}\n";

    file << ".signature-line {\n";
    file << "    border-top: 1px solid #263238;\n";
    file << "    margin-bottom: 8px;\n";
    file << "}\n";

    file << ".authority-name {\n";
    file << "    font-weight: bold;\n";
    file << "    font-size: 14px;\n";
    file << "}\n";

    file << ".authority-designation {\n";
    file << "    font-size: 13px;\n";
    file << "    color: #607d8b;\n";
    file << "    margin-top: 4px;\n";
    file << "}\n";

    // Footer
    file << ".footer {\n";
    file << "    position: absolute;\n";
    file << "    bottom: 32px;\n";
    file << "    left: 65px;\n";
    file << "    right: 65px;\n";
    file << "    padding-top: 12px;\n";
    file << "    border-top: 1px solid #d9e1e7;\n";
    file << "    text-align: center;\n";
    file << "    font-size: 10px;\n";
    file << "    color: #90a4ae;\n";
    file << "}\n";

    // Print style
    file << "@media print {\n";

    file << "    body {\n";
    file << "        background: white;\n";
    file << "    }\n";

    file << "    .notice-page {\n";
    file << "        margin: 0;\n";
    file << "        width: 100%;\n";
    file << "        min-height: 100vh;\n";
    file << "        box-shadow: none;\n";
    file << "    }\n";

    file << "}\n";

    file << "</style>\n";
    file << "</head>\n";

    file << "<body>\n";

    file << "<div class='notice-page'>\n";

    // Top bar
    file << "<div class='top-bar'></div>\n";

    // Header
    file << "<div class='header'>\n";

    file << "<div class='organization'>"
         << organizationName
         << "</div>\n";

    file << "<div class='department'>"
         << department
         << "</div>\n";

    file << "<div class='address'>"
         << organizationAddress
         << "</div>\n";

    file << "</div>\n";

    // Notice heading
    file << "<div class='notice-heading'>\n";
    file << "<h1>NOTICE</h1>\n";
    file << "</div>\n";

    // Notice metadata
    file << "<div class='meta'>\n";

    file << "<div><strong>Notice No:</strong> "
         << noticeNumber
         << "</div>\n";

    file << "<div><strong>Date:</strong> "
         << noticeDate
         << "</div>\n";

    file << "</div>\n";

    // Subject
    file << "<div class='subject'>\n";

    file << "<div class='subject-label'>Subject</div>\n";

    file << "<div class='subject-text'>"
         << subject
         << "</div>\n";

    file << "</div>\n";

    // Notice body
    file << "<div class='content'>\n";

    file << noticeBody;

    file << "</div>\n";

    // Important message
    file << "<div class='important'>\n";

    file << "<strong>Important:</strong> "
         "All concerned individuals are requested to take note of this notice "
         "and act accordingly."
         << "</div>\n";

    // Signature
    file << "<div class='signature-area'>\n";

    file << "<div class='signature'>\n";

    file << "<div class='signature-line'></div>\n";

    file << "<div class='authority-name'>"
         << authorityName
         << "</div>\n";

    file << "<div class='authority-designation'>"
         << authorityDesignation
         << "</div>\n";

    file << "</div>\n";

    file << "</div>\n";

    // Footer
    file << "<div class='footer'>\n";

    file << "Official Notice &nbsp; | &nbsp; "
         "Generated using DocCreator"
         << "</div>\n";

    file << "</div>\n";

    file << "</body>\n";
    file << "</html>\n";

    file.close();
    cout << "\nInvoice generated successfully!\n";
    cout << "File Name : "<< filename<<endl;
    cout<<"File Location : "<< path2<<endl;
    cout << "Open it in Chrome, Edge, or Firefox.\n";
}
