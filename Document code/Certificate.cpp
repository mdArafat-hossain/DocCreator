#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#include "zutils.h"
#include "login.h"
#include "Certificate.h"

using namespace std;

void Certificate(string sorganization_name)
{
    cin.ignore();
    string filename,ppath,path2;
    string name, course, organization, date;

    cout << "\n===== Resume Generator (HTML) =====\n\n";

    cout << "Enter Recipient Name: ";
    getline(cin, name);

    cout << "Enter Course / Program Name: ";
    getline(cin, course);

    if(sorganization_name.empty())
    {
        cout << "Enter Organization / Institution Name: ";
        getline(cin, organization);
    }

    cout << "Enter Date: ";
    getline(cin, date);

    cout<<"\nEnter file location : ";
    getline(cin,ppath);

    stringstream ss(name);
    ss >> filename;

    string path = file_path(ppath);
    string time = Date_Time();
    int l = path.length();
    if(path[l-1]=='\\')
    {
        path2 = path + filename + "(Certificate)" + time + ".html";
    }
    else
    {
        path2 = path + "\\\\" + filename + "(Certificate)" + time + ".html";
    }

    ofstream file(path2);

    file << "<!DOCTYPE html>\n";
    file << "<html lang=\"en\">\n";

    file << "<head>\n";

    file << "<meta charset=\"UTF-8\">\n";

    file << "<meta name=\"viewport\" "
         << "content=\"width=device-width, initial-scale=1.0\">\n";

    file << "<title>Certificate of Achievement</title>\n";

    file << "<style>\n";
    file << "body {\n";
    file << "    margin: 0;\n";
    file << "    padding: 40px;\n";
    file << "    background: #eef5ff;\n";
    file << "    font-family: Arial, sans-serif;\n";
    file << "    text-align: center;\n";
    file << "}\n";

    file << ".certificate {\n";
    file << "    max-width: 850px;\n";
    file << "    margin: auto;\n";
    file << "    padding: 60px;\n";
    file << "    background: white;\n";
    file << "    border: 5px solid #1565c0;\n";
    file << "    box-shadow: 0 5px 20px rgba(0,0,0,0.10);\n";
    file << "}\n";

    file << "h1 {\n";
    file << "    color: #1565c0;\n";
    file << "    font-size: 36px;\n";
    file << "    letter-spacing: 2px;\n";
    file << "    margin-bottom: 35px;\n";
    file << "}\n";

    file << ".name {\n";
    file << "    display: inline-block;\n";
    file << "    margin: 20px 0;\n";
    file << "    padding: 8px 40px;\n";
    file << "    font-size: 32px;\n";
    file << "    font-weight: bold;\n";
    file << "    color: #1565c0;\n";
    file << "    border-bottom: 2px solid #1565c0;\n";
    file << "}\n";

    file << ".writing {\n";
    file << "    max-width: 700px;\n";
    file << "    margin: 25px auto;\n";
    file << "    font-size: 17px;\n";
    file << "    line-height: 1.7;\n";
    file << "    color: #444;\n";
    file << "}\n";

    file << ".details {\n";
    file << "    margin-top: 30px;\n";
    file << "    font-size: 15px;\n";
    file << "    color: #333;\n";
    file << "}\n";

    file << ".signatures {\n";
    file << "    display: flex;\n";
    file << "    justify-content: center;\n";
    file << "    margin-top: 70px;\n";
    file << "}\n";

    file << ".signature {\n";
    file << "    width: 250px;\n";
    file << "    text-align: center;\n";
    file << "}\n";

    file << ".line {\n";
    file << "    border-top: 1px solid #222;\n";
    file << "    margin-top: 20px;\n";
    file << "    margin-bottom: 8px;\n";
    file << "}\n";

    file << ".signature strong {\n";
    file << "    font-size: 13px;\n";
    file << "}\n";

    file << ".signature p {\n";
    file << "    margin-top: 5px;\n";
    file << "    font-size: 12px;\n";
    file << "    color: #607d8b;\n";
    file << "}\n";

    file << "@media print {\n";

    file << "    body {\n";
    file << "        padding: 0;\n";
    file << "        background: white;\n";
    file << "    }\n";

    file << "    .certificate {\n";
    file << "        box-shadow: none;\n";
    file << "    }\n";

    file << "}\n";

    file << "</style>\n";

    file << "</head>\n";

    file << "<body>\n";

    file << "<div class=\"certificate\">\n";

    // Certificate Title
    file << "<h1>CERTIFICATE OF ACHIEVEMENT</h1>\n";

    // Introduction
    file << "<p>This certificate is proudly presented to</p>\n";

    // Recipient Name
    file << "<div class=\"name\">";
    file << name;
    file << "</div>\n";

    // Main Writing
    file << "<p class=\"writing\">\n";

    file << "for successfully completing "
         << "<b>" << course << "</b>"
         << " and demonstrating dedication, commitment, "
         << "and excellence throughout the program.";

    file << "</p>\n";

    // Closing Writing
    file << "<p class=\"writing\">\n";

    file << "We appreciate this achievement and wish the recipient "
         << "continued success in future endeavors.";

    file << "</p>\n";

    // Details
    file << "<div class=\"details\">\n";

    file << "<p><b>Date:</b> "
         << date
         << "</p>\n";

    file << "<p><b>Certificate ID:</b> CERT-001</p>\n";

    file << "</div>\n";

    // Signature
    file << "<div class=\"signatures\">\n";

    file << "<div class=\"signature\">\n";

    file << "<div class=\"line\"></div>\n";

    file << "<strong>Authorized Signature</strong>\n";

    file << "<p>"
         << organization
         << "</p>\n";

    file << "</div>\n";

    file << "</div>\n";

    file << "</div>\n";

    file << "</body>\n";

    file << "</html>\n";

    file.close();

    cout << "\nCertificate generated successfully!\n";
    cout << "File Name : "<< filename<<endl;
    cout<<"File Location : "<< path2<<endl;
    cout << "Open it in Chrome, Edge, or Firefox.\n";
}
