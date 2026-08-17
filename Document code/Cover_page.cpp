#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include<sstream>
#include "zutils.h"
#include "login.h"
#include "Cover_page.h"

using namespace std;

void Cover_page()
{
    cin.ignore();
    string filename,ppath,path2;
    string studentName, studentID, batch, section;

    string courseTitle, courseCode, assignmentTitle, assignmentNo;
    string teacherName, teacherDesignation, department;
    string universityName, universityAddress;

    cout << "\n===== Assignment Cover Page Generator (HTML) =====\n\n";

    cout << "Enter University Name: ";
    getline(cin, universityName);

    cout << "Enter University Address: ";
    getline(cin, universityAddress);

    cout << "Enter Department: ";
    getline(cin, department);

    cout << "\nCourse Information\n";

    cout << "Enter Course Title: ";
    getline(cin, courseTitle);

    cout << "Enter Course Code: ";
    getline(cin, courseCode);

    cout << "Enter Assignment Title: ";
    getline(cin, assignmentTitle);

    cout << "Enter Assignment Number: ";
    getline(cin, assignmentNo);

    cout << "\nSubmitted To\n";

    cout << "Enter Teacher Name: ";
    getline(cin, teacherName);

    cout << "Enter Teacher Designation: ";
    getline(cin, teacherDesignation);

    cout << "\nSubmitted By\n";

    cout << "Enter Student Name: ";
    getline(cin, studentName);

    cout << "Enter Student ID: ";
    getline(cin, studentID);

    cout << "Enter Batch: ";
    getline(cin, batch);

    cout << "Enter Section: ";
    getline(cin, section);

    time_t now = time(0);
    tm *localTime = localtime(&now);

    int day = localTime->tm_mday;
    int month = localTime->tm_mon + 1;
    int year = localTime->tm_year + 1900;

    string submissionDate =
        to_string(day) + "/" +
        to_string(month) + "/" +
        to_string(year);


    cout<<"\nEnter file location : ";
    getline(cin,ppath);

    filename = "Assignment_Cover_Page";

    string path = file_path(ppath);
    string time = Date_Time();
    int l = path.length();

    if(path[l-1]=='\\')
    {
        path2 = path + filename + time + ".html"; //E:\\arafat(Resume)_2026-07-28_1237.html
    }
    else
    {
        path2 = path + "\\\\" + filename + time + ".html"; //E:\\DocCreator\\arafat(Resume)_2026-07-28_1237.html
    }
    ofstream file(path2);

    file << "<!DOCTYPE html>\n";
    file << "<html>\n";
    file << "<head>\n";

    file << "<meta charset='UTF-8'>\n";
    file << "<meta name='viewport' content='width=device-width, initial-scale=1.0'>\n";

    file << "<title>Assignment Cover Page</title>\n";

    // ==========================================
    // CSS
    // ==========================================
    file << "<style>\n";

    file << "* {\n";
    file << "    box-sizing: border-box;\n";
    file << "}\n";

    file << "body {\n";
    file << "    margin: 0;\n";
    file << "    padding: 0;\n";
    file << "    background: #e9eef5;\n";
    file << "    font-family: Arial, Helvetica, sans-serif;\n";
    file << "    color: #263238;\n";
    file << "}\n";

    file << ".page {\n";
    file << "    width: 794px;\n";
    file << "    min-height: 1123px;\n";
    file << "    margin: 30px auto;\n";
    file << "    background: white;\n";
    file << "    padding: 55px 65px;\n";
    file << "    position: relative;\n";
    file << "    box-shadow: 0 5px 20px rgba(0,0,0,0.10);\n";
    file << "}\n";

    file << ".top-line {\n";
    file << "    height: 6px;\n";
    file << "    background: #1565c0;\n";
    file << "    position: absolute;\n";
    file << "    top: 0;\n";
    file << "    left: 0;\n";
    file << "    right: 0;\n";
    file << "}\n";

    file << ".logo {\n";
    file << "    text-align: center;\n";
    file << "    margin-top: 10px;\n";
    file << "}\n";

    file << ".logo img {\n";
    file << "    width: 85px;\n";
    file << "    height: 85px;\n";
    file << "    object-fit: contain;\n";
    file << "}\n";

    file << ".university {\n";
    file << "    text-align: center;\n";
    file << "    margin-top: 18px;\n";
    file << "    font-size: 25px;\n";
    file << "    font-weight: bold;\n";
    file << "    color: #0d47a1;\n";
    file << "    text-transform: uppercase;\n";
    file << "}\n";

    file << ".address {\n";
    file << "    text-align: center;\n";
    file << "    margin-top: 7px;\n";
    file << "    font-size: 13px;\n";
    file << "    color: #607d8b;\n";
    file << "}\n";

    file << ".department {\n";
    file << "    text-align: center;\n";
    file << "    margin-top: 8px;\n";
    file << "    font-size: 15px;\n";
    file << "    font-weight: bold;\n";
    file << "    color: #37474f;\n";
    file << "}\n";

    file << ".divider {\n";
    file << "    width: 75%;\n";
    file << "    height: 1px;\n";
    file << "    background: #b0bec5;\n";
    file << "    margin: 28px auto;\n";
    file << "}\n";

    file << ".assignment-heading {\n";
    file << "    text-align: center;\n";
    file << "    font-size: 34px;\n";
    file << "    font-weight: bold;\n";
    file << "    letter-spacing: 3px;\n";
    file << "    color: #1565c0;\n";
    file << "    margin-top: 30px;\n";
    file << "}\n";

    file << ".assignment-number {\n";
    file << "    text-align: center;\n";
    file << "    margin-top: 10px;\n";
    file << "    font-size: 15px;\n";
    file << "    color: #607d8b;\n";
    file << "}\n";

    file << ".title-box {\n";
    file << "    margin: 55px auto 45px auto;\n";
    file << "    padding: 25px;\n";
    file << "    text-align: center;\n";
    file << "    border: 1px solid #cfd8dc;\n";
    file << "    border-left: 5px solid #1565c0;\n";
    file << "    background: #f7faff;\n";
    file << "}\n";

    file << ".title-label {\n";
    file << "    font-size: 12px;\n";
    file << "    text-transform: uppercase;\n";
    file << "    letter-spacing: 1px;\n";
    file << "    color: #78909c;\n";
    file << "    margin-bottom: 12px;\n";
    file << "}\n";

    file << ".title {\n";
    file << "    font-size: 23px;\n";
    file << "    font-weight: bold;\n";
    file << "    color: #263238;\n";
    file << "}\n";

    file << ".section-title {\n";
    file << "    font-size: 14px;\n";
    file << "    font-weight: bold;\n";
    file << "    color: #1565c0;\n";
    file << "    text-transform: uppercase;\n";
    file << "    letter-spacing: 1px;\n";
    file << "    margin-bottom: 14px;\n";
    file << "}\n";

    file << ".info-container {\n";
    file << "    display: flex;\n";
    file << "    gap: 35px;\n";
    file << "    margin-top: 25px;\n";
    file << "}\n";

    file << ".info-box {\n";
    file << "    flex: 1;\n";
    file << "    border-top: 2px solid #1565c0;\n";
    file << "    padding-top: 15px;\n";
    file << "}\n";

    file << ".info-row {\n";
    file << "    display: flex;\n";
    file << "    margin-bottom: 12px;\n";
    file << "    font-size: 14px;\n";
    file << "}\n";

    file << ".label {\n";
    file << "    width: 110px;\n";
    file << "    font-weight: bold;\n";
    file << "    color: #546e7a;\n";
    file << "}\n";

    file << ".value {\n";
    file << "    flex: 1;\n";
    file << "    color: #263238;\n";
    file << "}\n";

    file << ".date {\n";
    file << "    text-align: center;\n";
    file << "    margin-top: 65px;\n";
    file << "    font-size: 14px;\n";
    file << "    color: #546e7a;\n";
    file << "}\n";

    file << ".footer {\n";
    file << "    position: absolute;\n";
    file << "    bottom: 35px;\n";
    file << "    left: 65px;\n";
    file << "    right: 65px;\n";
    file << "    text-align: center;\n";
    file << "    border-top: 1px solid #cfd8dc;\n";
    file << "    padding-top: 12px;\n";
    file << "    font-size: 11px;\n";
    file << "    color: #90a4ae;\n";
    file << "}\n";

    file << "@media print {\n";

    file << "    body {\n";
    file << "        background: white;\n";
    file << "    }\n";

    file << "    .page {\n";
    file << "        margin: 0;\n";
    file << "        width: 100%;\n";
    file << "        min-height: 100vh;\n";
    file << "        box-shadow: none;\n";
    file << "    }\n";

    file << "}\n";

    file << "</style>\n";
    file << "</head>\n";

    file << "<body>\n";

    file << "<div class='page'>\n";

    // Top blue line
    file << "<div class='top-line'></div>\n";

    // Logo
    file << "<div class='logo'>\n";

    file << "<img src='" << "E:\\DocCreator\\photo\\logo.webp"
            << "' alt='University Logo'>\n";

    file << "</div>\n";

    // University
    file << "<div class='university'>"
         << universityName
         << "</div>\n";

    file << "<div class='address'>"
         << universityAddress
         << "</div>\n";

    file << "<div class='department'>"
         << department
         << "</div>\n";

    file << "<div class='divider'></div>\n";

    // Assignment heading
    file << "<div class='assignment-heading'>ASSIGNMENT</div>\n";

    file << "<div class='assignment-number'>"
         << "Assignment No. " << assignmentNo
         << "</div>\n";

    // Assignment title
    file << "<div class='title-box'>\n";

    file << "<div class='title-label'>Assignment Topic</div>\n";

    file << "<div class='title'>"
         << assignmentTitle
         << "</div>\n";

    file << "</div>\n";

    // Information containers
    file << "<div class='info-container'>\n";

    // Submitted To
    file << "<div class='info-box'>\n";

    file << "<div class='section-title'>Submitted To</div>\n";

    file << "<div class='info-row'>\n";
    file << "<div class='label'>Name:</div>\n";
    file << "<div class='value'>" << teacherName << "</div>\n";
    file << "</div>\n";

    file << "<div class='info-row'>\n";
    file << "<div class='label'>Designation:</div>\n";
    file << "<div class='value'>" << teacherDesignation << "</div>\n";
    file << "</div>\n";

    file << "<div class='info-row'>\n";
    file << "<div class='label'>Department:</div>\n";
    file << "<div class='value'>" << department << "</div>\n";
    file << "</div>\n";

    file << "</div>\n";

    // Submitted By
    file << "<div class='info-box'>\n";

    file << "<div class='section-title'>Submitted By</div>\n";

    file << "<div class='info-row'>\n";
    file << "<div class='label'>Name:</div>\n";
    file << "<div class='value'>" << studentName << "</div>\n";
    file << "</div>\n";

    file << "<div class='info-row'>\n";
    file << "<div class='label'>Student ID:</div>\n";
    file << "<div class='value'>" << studentID << "</div>\n";
    file << "</div>\n";

    file << "<div class='info-row'>\n";
    file << "<div class='label'>Batch:</div>\n";
    file << "<div class='value'>" << batch << "</div>\n";
    file << "</div>\n";

    file << "<div class='info-row'>\n";
    file << "<div class='label'>Section:</div>\n";
    file << "<div class='value'>" << section << "</div>\n";
    file << "</div>\n";

    file << "</div>\n";

    file << "</div>\n";

    file << "<div class='info-container'>\n";

    file << "<div class='info-box'>\n";

    file << "<div class='section-title'>Course Information</div>\n";

    file << "<div class='info-row'>\n";
    file << "<div class='label'>Course:</div>\n";
    file << "<div class='value'>" << courseTitle << "</div>\n";
    file << "</div>\n";

    file << "<div class='info-row'>\n";
    file << "<div class='label'>Code:</div>\n";
    file << "<div class='value'>" << courseCode << "</div>\n";
    file << "</div>\n";

    file << "</div>\n";

    file << "</div>\n";

    // Submission date
    file << "<div class='date'>\n";
    file << "Submission Date: <strong>"
         << submissionDate
         << "</strong>\n";
    file << "</div>\n";

    // Footer
    file << "<div class='footer'>\n";
    file << "Generated using DocCreator — Document Automation System\n";
    file << "</div>\n";

    file << "</div>\n";

    file << "</body>\n";
    file << "</html>\n";

    file.close();

        cout << "\nAssignment Cover Page generated successfully!\n";
        cout << "File Name : "<< filename<<endl;
        cout<<"File Location : "<< path2<<endl;
        cout << "Open it in Chrome, Edge, or Firefox.\n";


}
