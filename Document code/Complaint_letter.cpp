#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#include "zutils.h"
#include "login.h"
#include "Complaint_letter.h"
using namespace std;

void complaint()
{
    cin.ignore();
    string filename,ppath,path2;
    string complainantName, complainantAddress, complainantEmail, complainantPhone;
    string recipientName, recipientPosition, organization, organizationAddress;
    string complaintSubject, complaintDate, complaintLocation, complaintDetails, previousAction, requestedResolution;

    string date;

    cout << "\n===== Complaint Letter Generator (HTML) =====\n\n";

    cout << "Complainant Information\n";

    cout << "Full Name: ";
    getline(cin, complainantName);

    cout << "Address: ";
    getline(cin, complainantAddress);

    cout << "Email Address: ";
    getline(cin, complainantEmail);

    cout << "Phone Number: ";
    getline(cin, complainantPhone);

    cout << "\nRecipient Information\n";

    cout << "Recipient Name (optional): ";
    getline(cin, recipientName);

    cout << "Recipient Position / Title (optional): ";
    getline(cin, recipientPosition);

    cout << "Organization / Institution: ";
    getline(cin, organization);

    cout << "Organization Address: ";
    getline(cin, organizationAddress);

    cout << "\nComplaint Information\n";

    cout << "Complaint Subject: ";
    getline(cin, complaintSubject);

    cout << "Date of Incident: ";
    getline(cin, complaintDate);

    cout << "Location of Incident: ";
    getline(cin, complaintLocation);

    cout << "Detailed Description of Complaint: ";
    getline(cin, complaintDetails);

    cout << "Previous Action Taken (optional): ";
    getline(cin, previousAction);

    cout << "Requested Resolution / Action: ";
    getline(cin, requestedResolution);

    cout << "\nLetter Information\n";

    cout << "Letter Date: ";
    getline(cin, date);

    if (recipientName.empty())
    {
        recipientName = "The Concerned Authority";
    }

    if (recipientPosition.empty())
    {
        recipientPosition = "Concerned Officer";
    }

    if (previousAction.empty())
    {
        previousAction = "No previous formal action has been taken regarding this matter.";
    }

    if (requestedResolution.empty())
    {
        requestedResolution =
            "I respectfully request that the matter be reviewed and appropriate "
            "action be taken.";
    }

    if (date.empty())
    {
        date = "____________________";
    }

    cout<<"\nEnter file location : ";
        getline(cin,ppath);

        stringstream ss(complainantName); // generate one word from multiple words (Arafat Hossain Rizve)== Arafat
        ss >> filename;

        string path = file_path(ppath);
        string time = Date_Time();
        int l = path.length();
        if(path[l-1]=='\\')
        {
            path2 = path + filename + "(Complaint Letter)" + time + ".html"; //E:\\arafat(Resume)_2026-07-28_1237.html
        }
        else
        {
            path2 = path + "\\\\" + filename + "(Complaint Letter)" + time + ".html"; //E:\\DocCreator\\arafat(Resume)_2026-07-28_1237.html
        }


        ofstream file(path2);

    file << "<!DOCTYPE html>\n";
    file << "<html lang=\"en\">\n";

    file << "<head>\n";

    file << "<meta charset=\"UTF-8\">\n";
    file << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";

    file << "<title>Complaint Letter - "
         << complaintSubject
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
    file << "    max-width: 850px;\n";
    file << "    min-height: 1100px;\n";
    file << "    margin: auto;\n";
    file << "    background: #ffffff;\n";
    file << "    padding: 60px 70px;\n";
    file << "    box-shadow: 0 8px 28px rgba(0,0,0,0.10);\n";
    file << "}\n";

    file << ".top-line {\n";
    file << "    height: 5px;\n";
    file << "    background: #37474f;\n";
    file << "    margin-bottom: 28px;\n";
    file << "}\n";

    file << ".sender-name {\n";
    file << "    font-family: Arial, sans-serif;\n";
    file << "    font-size: 26px;\n";
    file << "    font-weight: bold;\n";
    file << "    color: #263238;\n";
    file << "}\n";

    file << ".sender-details {\n";
    file << "    margin-top: 7px;\n";
    file << "    font-family: Arial, sans-serif;\n";
    file << "    font-size: 13px;\n";
    file << "    line-height: 1.6;\n";
    file << "    color: #607078;\n";
    file << "}\n";

    file << ".header-divider {\n";
    file << "    border-bottom: 1px solid #cfd8dc;\n";
    file << "    margin: 22px 0 30px 0;\n";
    file << "}\n";

    file << ".date {\n";
    file << "    text-align: right;\n";
    file << "    font-size: 15px;\n";
    file << "    margin-bottom: 30px;\n";
    file << "}\n";

    file << ".recipient {\n";
    file << "    font-size: 15px;\n";
    file << "    line-height: 1.6;\n";
    file << "    margin-bottom: 28px;\n";
    file << "}\n";

    file << ".subject {\n";
    file << "    font-family: Arial, sans-serif;\n";
    file << "    font-size: 15px;\n";
    file << "    font-weight: bold;\n";
    file << "    color: #263238;\n";
    file << "    padding: 14px 18px;\n";
    file << "    margin-bottom: 28px;\n";
    file << "    background: #f1f4f5;\n";
    file << "    border-left: 5px solid #37474f;\n";
    file << "}\n";

    file << ".salutation {\n";
    file << "    font-size: 16px;\n";
    file << "    margin-bottom: 20px;\n";
    file << "}\n";

    file << ".letter p {\n";
    file << "    font-size: 15.5px;\n";
    file << "    line-height: 1.85;\n";
    file << "    text-align: justify;\n";
    file << "    margin: 0 0 18px 0;\n";
    file << "}\n";

    file << ".incident-box {\n";
    file << "    margin: 25px 0;\n";
    file << "    border: 1px solid #d5dde0;\n";
    file << "    background: #fafbfc;\n";
    file << "}\n";

    file << ".incident-title {\n";
    file << "    padding: 12px 16px;\n";
    file << "    background: #37474f;\n";
    file << "    color: white;\n";
    file << "    font-family: Arial, sans-serif;\n";
    file << "    font-size: 13px;\n";
    file << "    font-weight: bold;\n";
    file << "    text-transform: uppercase;\n";
    file << "    letter-spacing: 0.5px;\n";
    file << "}\n";

    file << ".incident-row {\n";
    file << "    display: flex;\n";
    file << "    border-bottom: 1px solid #e1e6e8;\n";
    file << "}\n";

    file << ".incident-row:last-child {\n";
    file << "    border-bottom: none;\n";
    file << "}\n";

    file << ".incident-label {\n";
    file << "    width: 30%;\n";
    file << "    padding: 12px 15px;\n";
    file << "    font-family: Arial, sans-serif;\n";
    file << "    font-size: 12px;\n";
    file << "    font-weight: bold;\n";
    file << "    color: #546e7a;\n";
    file << "}\n";

    file << ".incident-value {\n";
    file << "    width: 70%;\n";
    file << "    padding: 12px 15px;\n";
    file << "    font-size: 14px;\n";
    file << "    color: #263238;\n";
    file << "}\n";

    file << ".resolution {\n";
    file << "    margin: 25px 0;\n";
    file << "    padding: 18px 20px;\n";
    file << "    border: 1px solid #cfd8dc;\n";
    file << "    background: #f7f9fa;\n";
    file << "}\n";

    file << ".resolution-title {\n";
    file << "    margin-bottom: 9px;\n";
    file << "    font-family: Arial, sans-serif;\n";
    file << "    font-size: 12px;\n";
    file << "    font-weight: bold;\n";
    file << "    text-transform: uppercase;\n";
    file << "    color: #455a64;\n";
    file << "}\n";

    file << ".resolution-text {\n";
    file << "    font-size: 15px;\n";
    file << "    line-height: 1.7;\n";
    file << "}\n";

    file << ".signature {\n";
    file << "    margin-top: 40px;\n";
    file << "    font-size: 15px;\n";
    file << "    line-height: 1.7;\n";
    file << "}\n";

    file << ".signature-name {\n";
    file << "    margin-top: 22px;\n";
    file << "    font-family: Arial, sans-serif;\n";
    file << "    font-size: 17px;\n";
    file << "    font-weight: bold;\n";
    file << "    color: #263238;\n";
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
    file << "        max-width: none;\n";
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

    file << "<div class=\"sender-name\">"
         << complainantName
         << "</div>\n";

    file << "<div class=\"sender-details\">\n";

    file << complainantAddress << "<br>\n";

    if (!complainantEmail.empty())
    {
        file << "Email: " << complainantEmail << "<br>\n";
    }

    if (!complainantPhone.empty())
    {
        file << "Phone: " << complainantPhone << "\n";
    }

    file << "</div>\n";

    file << "<div class=\"header-divider\"></div>\n";

    file << "<div class=\"date\">"
         << date
         << "</div>\n";

    file << "<div class=\"recipient\">\n";

    file << "<strong>"
         << recipientName
         << "</strong><br>\n";

    file << recipientPosition << "<br>\n";

    file << organization << "<br>\n";

    file << organizationAddress << "\n";

    file << "</div>\n";

    file << "<div class=\"subject\">\n";

    file << "SUBJECT: FORMAL COMPLAINT REGARDING "
         << complaintSubject;

    file << "<div class=\"salutation\">"
         << "Dear Sir/Madam,"
         << "</div>\n";

    file << "<div class=\"letter\">\n";

    file << "<p>\n";

    file << "I am writing to formally bring to your attention an issue concerning "
         "<strong>"
         << complaintSubject
         << "</strong>. I respectfully request that the matter be reviewed "
         "and appropriate action be taken in accordance with the relevant "
         "policies and procedures.\n";

    file << "</p>\n";

    file << "<div class=\"incident-box\">\n";

    file << "<div class=\"incident-title\">Complaint Details</div>\n";
    file << "<div class=\"incident-row\">\n";

    file << "<div class=\"incident-label\">Subject</div>\n";

    file << "<div class=\"incident-value\">"
         << complaintSubject
         << "</div>\n";

    file << "</div>\n";

    file << "<div class=\"incident-row\">\n";

    file << "<div class=\"incident-label\">Date of Incident</div>\n";

    file << "<div class=\"incident-value\">"
         << complaintDate
         << "</div>\n";

    file << "</div>\n";
    file << "<div class=\"incident-row\">\n";

    file << "<div class=\"incident-label\">Location</div>\n";

    file << "<div class=\"incident-value\">"
         << complaintLocation
         << "</div>\n";

    file << "</div>\n";

    file << "</div>\n";

    file << "<p>\n";

    file << "The details of the matter are as follows: "
         << complaintDetails
         << "\n";

    file << "</p>\n";

    file << "<p>\n";

    file << "Regarding any previous efforts to address this matter, "
         << previousAction
         << "\n";

    file << "</p>\n";

    file << "<div class=\"resolution\">\n";

    file << "<div class=\"resolution-title\">Requested Resolution</div>\n";

    file << "<div class=\"resolution-text\">"
         << requestedResolution
         << "</div>\n";

    file << "</div>\n";

    file << "<p>\n";

    file << "I would appreciate your attention to this matter and request that "
         "the complaint be reviewed fairly and objectively. I hope that "
         "appropriate steps can be taken to resolve the issue and prevent "
         "similar situations from occurring in the future.\n";

    file << "</p>\n";

    file << "<p>\n";

    file << "I am willing to provide any additional information or supporting "
         "details that may be required during the review of this complaint. "
         "Thank you for your time and consideration.\n";

    file << "</p>\n";

    file << "</div>\n";

    file << "<div class=\"signature\">\n";

    file << "Yours faithfully,<br>\n";

    file << "<div class=\"signature-name\">"
         << complainantName
         << "</div>\n";

    file << complainantAddress << "<br>\n";

    if (!complainantEmail.empty())
    {
        file << complainantEmail << "<br>\n";
    }

    if (!complainantPhone.empty())
    {
        file << complainantPhone;
    }

    file << "</div>\n";
    file << "<div class=\"footer\">\n";

    file << "Formal Complaint Letter &nbsp; | &nbsp; "
         "Generated by DocCreator";

    file << "</div>\n";

    file << "</div>\n";
    file << "</body>\n";
    file << "</html>\n";

    file.close();


    // ==========================================
    // SUCCESS MESSAGE
    // ==========================================
 cout << "\nComplaint Letter generated successfully!\n";
        cout << "File Name : "<< filename<<endl;
        cout<<"File Location : "<< path2<<endl;
        cout << "Open it in Chrome, Edge, or Firefox.\n";
}

