#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include<sstream>
#include "zutils.h"
#include "login.h"
#include "Medical_Certificate.h"

using namespace std;

void medical_certificate()
{
    cin.ignore();
    string filename,ppath,path2;
    string patientName, gender, examinationDate, diagnosis, restPeriod;
    float age;

    string doctorName, qualification, registrationNo;
    string clinicName, clinicAddress, contactNumber;

    cout<<"\n===== Medical Certificate Generator (HTML) =====\n\n";

    cout << "Enter Patient Name: ";
    getline(cin, patientName);

    cout << "Enter Age: ";
    cin>> age;
    while (cin.fail() || age <= 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input! Enter a valid age: ";
        cin >> age;
    }

    cin.ignore();
    cout << "Enter Gender: ";
    getline(cin, gender);

    cout << "Enter Examination Date (DD/MM/YYYY): ";
    getline(cin, examinationDate);

    cout << "Enter Diagnosis / Medical Condition: ";
    getline(cin, diagnosis);

    cout << "Enter Recommended Rest Period: ";
    getline(cin, restPeriod);

    cout << "\nDoctor Information\n";

    cout << "Enter Doctor Name: ";
    getline(cin, doctorName);

    cout << "Enter Qualification: ";
    getline(cin, qualification);

    cout << "Enter Medical Registration Number: ";
    getline(cin, registrationNo);

    cout << "\nMedical Institution\n";

    cout << "Enter Clinic / Hospital Name: ";
    getline(cin, clinicName);

    cout << "Enter Clinic / Hospital Address: ";
    getline(cin, clinicAddress);

    cout << "Enter Contact Number: ";
    getline(cin, contactNumber);

    time_t now = time(0);
    tm *localTime = localtime(&now);

    int year = localTime->tm_year + 1900;
    int month = localTime->tm_mon + 1;
    int day = localTime->tm_mday;

    string certificateID = "MC-" + to_string(year) + to_string(month) + to_string(day);

    cout<<"\nEnter file location : ";
        getline(cin,ppath);

        stringstream ss(patientName); // generate one word from multiple words (Arafat Hossain Rizve)== Arafat
        ss >> filename;

        string path = file_path(ppath);
        string time = Date_Time();
        int l = path.length();
        if(path[l-1]=='\\')
        {
            path2 = path + filename + "(Medical Certificate)" + time + ".html";
        }
        else
        {
            path2 = path + "\\\\" + filename + "(Medical Certificate)" + time + ".html";
        }


        ofstream file(path2);

    file << "<!DOCTYPE html>\n";
    file << "<html>\n";
    file << "<head>\n";
    file << "<meta charset='UTF-8'>\n";
    file << "<title>Medical Certificate</title>\n";

    file << "<style>\n";

    file << "* {\n";
    file << "    box-sizing: border-box;\n";
    file << "}\n";

    file << "body {\n";
    file << "    margin: 0;\n";
    file << "    background: #eef2f5;\n";
    file << "    font-family: Arial, Helvetica, sans-serif;\n";
    file << "    color: #263238;\n";
    file << "}\n";

    file << ".certificate {\n";
    file << "    width: 850px;\n";
    file << "    margin: 40px auto;\n";
    file << "    background: white;\n";
    file << "    padding: 55px 65px;\n";
    file << "    border: 1px solid #cfd8dc;\n";
    file << "    box-shadow: 0 4px 18px rgba(0,0,0,0.08);\n";
    file << "    position: relative;\n";
    file << "}\n";

    file << ".sample {\n";
    file << "    position: absolute;\n";
    file << "    top: 46%;\n";
    file << "    left: 22%;\n";
    file << "    transform: rotate(-25deg);\n";
    file << "    font-size: 52px;\n";
    file << "    color: rgba(180, 0, 0, 0.10);\n";
    file << "    font-weight: bold;\n";
    file << "    pointer-events: none;\n";
    file << "}\n";

    file << ".header {\n";
    file << "    text-align: center;\n";
    file << "    border-bottom: 2px solid #37474f;\n";
    file << "    padding-bottom: 20px;\n";
    file << "}\n";

    file << ".clinic {\n";
    file << "    font-size: 25px;\n";
    file << "    font-weight: bold;\n";
    file << "    color: #263238;\n";
    file << "}\n";

    file << ".address {\n";
    file << "    margin-top: 7px;\n";
    file << "    font-size: 14px;\n";
    file << "    color: #607d8b;\n";
    file << "}\n";

    file << ".title {\n";
    file << "    margin-top: 32px;\n";
    file << "    text-align: center;\n";
    file << "    font-size: 28px;\n";
    file << "    letter-spacing: 2px;\n";
    file << "    font-weight: bold;\n";
    file << "}\n";

    file << ".certificate-id {\n";
    file << "    text-align: right;\n";
    file << "    margin-top: 12px;\n";
    file << "    font-size: 13px;\n";
    file << "    color: #607d8b;\n";
    file << "}\n";

    file << ".content {\n";
    file << "    margin-top: 35px;\n";
    file << "    font-size: 16px;\n";
    file << "    line-height: 1.8;\n";
    file << "}\n";

    file << ".patient-box {\n";
    file << "    margin-top: 22px;\n";
    file << "    border: 1px solid #cfd8dc;\n";
    file << "    padding: 20px;\n";
    file << "}\n";

    file << ".row {\n";
    file << "    display: flex;\n";
    file << "    margin-bottom: 12px;\n";
    file << "}\n";

    file << ".label {\n";
    file << "    width: 190px;\n";
    file << "    font-weight: bold;\n";
    file << "    color: #455a64;\n";
    file << "}\n";

    file << ".value {\n";
    file << "    flex: 1;\n";
    file << "}\n";

    file << ".statement {\n";
    file << "    margin-top: 30px;\n";
    file << "    padding: 18px;\n";
    file << "    background: #f5f7f8;\n";
    file << "    border-left: 4px solid #546e7a;\n";
    file << "}\n";

    file << ".footer {\n";
    file << "    margin-top: 70px;\n";
    file << "    display: flex;\n";
    file << "    justify-content: space-between;\n";
    file << "}\n";

    file << ".signature {\n";
    file << "    width: 230px;\n";
    file << "    text-align: center;\n";
    file << "    border-top: 1px solid #37474f;\n";
    file << "    padding-top: 8px;\n";
    file << "}\n";

    file << ".doctor {\n";
    file << "    font-weight: bold;\n";
    file << "}\n";

    file << ".disclaimer {\n";
    file << "    margin-top: 40px;\n";
    file << "    padding: 12px;\n";
    file << "    text-align: center;\n";
    file << "    font-size: 11px;\n";
    file << "    color: #8d0000;\n";
    file << "    border: 1px solid #e0b4b4;\n";
    file << "    background: #fff8f8;\n";
    file << "}\n";

    file << "@media print {\n";
    file << "    body {\n";
    file << "        background: white;\n";
    file << "    }\n";
    file << "    .certificate {\n";
    file << "        margin: 0;\n";
    file << "        width: 100%;\n";
    file << "        box-shadow: none;\n";
    file << "    }\n";
    file << "}\n";

    file << "</style>\n";
    file << "</head>\n";

    file << "<body>\n";

    file << "<div class='certificate'>\n";

    // Header
    file << "<div class='header'>\n";

    file << "<div class='clinic'>"
         << clinicName
         << "</div>\n";

    file << "<div class='address'>"
         << clinicAddress
         << "<br>Contact: "
         << contactNumber
         << "</div>\n";

    file << "</div>\n";

    // Title
    file << "<div class='title'>MEDICAL CERTIFICATE</div>\n";

    file << "<div class='certificate-id'>Certificate ID: "
         << certificateID
         << "</div>\n";

    // Main content
    file << "<div class='content'>\n";

    file << "This is to certify that the following patient was examined "
         "and the information below has been recorded for documentation purposes."
         << "</div>\n";

    // Patient information
    file << "<div class='patient-box'>\n";

    file << "<div class='row'>\n";
    file << "<div class='label'>Patient Name:</div>\n";
    file << "<div class='value'>" << patientName << "</div>\n";
    file << "</div>\n";

    file << "<div class='row'>\n";
    file << "<div class='label'>Age:</div>\n";
    file << "<div class='value'>" << age << "</div>\n";
    file << "</div>\n";

    file << "<div class='row'>\n";
    file << "<div class='label'>Gender:</div>\n";
    file << "<div class='value'>" << gender << "</div>\n";
    file << "</div>\n";

    file << "<div class='row'>\n";
    file << "<div class='label'>Examination Date:</div>\n";
    file << "<div class='value'>" << examinationDate << "</div>\n";
    file << "</div>\n";

    file << "<div class='row'>\n";
    file << "<div class='label'>Medical Condition:</div>\n";
    file << "<div class='value'>" << diagnosis << "</div>\n";
    file << "</div>\n";

    file << "<div class='row'>\n";
    file << "<div class='label'>Recommended Rest:</div>\n";
    file << "<div class='value'>" << restPeriod << "</div>\n";
    file << "</div>\n";

    file << "</div>\n";

    // Medical statement
    file << "<div class='statement'>\n";

    file << "Based on the information entered above, the patient is "
         "recommended to follow the stated medical advice and rest period."
         << "</div>\n";

    // Footer
    file << "<div class='footer'>\n";

    file << "<div>\n";
    file << "<div>Date: " << day << "/" << month << "/" << year << "</div>\n";
    file << "</div>\n";

    file << "<div class='signature'>\n";

    file << "<div class='doctor'>"
         << doctorName
         << "</div>\n";

    file << "<div>"
         << qualification
         << "</div>\n";

    file << "<div>Registration No: "
         << registrationNo
         << "</div>\n";

    file << "</div>\n";

    file << "</div>\n";

    // Disclaimer
    file << "<div class='disclaimer'>\n";

    file << "SAMPLE / NOT VALID FOR MEDICAL, LEGAL, EMPLOYMENT, "
         "INSURANCE OR OFFICIAL USE. Generated by DocCreator for "
         "educational demonstration purposes only."
         << "</div>\n";

    file << "</div>\n";

    file << "</body>\n";
    file << "</html>\n";

    file.close();

    cout << "\nMedical Certificate generated successfully!\n";
        cout << "File Name : "<< filename<<endl;
        cout<<"File Location : "<< path2<<endl;
        cout << "Open it in Chrome, Edge, or Firefox.\n";
}
