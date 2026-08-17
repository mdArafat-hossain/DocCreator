#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "zutils.h"
#include "login.h"
#include "memo.h"
using namespace std;

void memo(string sorganization_name)
{
    cin.ignore();
    string filename, path2, ppath;

    string recipient, sender, date, subject;
    string purpose, details, requiredAction, importantNote;
    string senderName, designation;
    string department, companyName;


    cout << "\n===== Memo Generator (HTML) =====\n\n";


    cout << "\nMemo Information\n";

    cout << "To: ";
    getline(cin, recipient);

    cout << "From: ";
    getline(cin, sender);

    cout << "Date: ";
    getline(cin, date);

    cout << "Subject: ";
    getline(cin, subject);


    cout << "\nMemo Content\n";
    cout << "Purpose / Main Topic: ";
    getline(cin, purpose);

    cout << "Details / Information: ";
    getline(cin, details);

    cout << "Required Action: ";
    getline(cin, requiredAction);

    cout << "Deadline / Important Note: ";
    getline(cin, importantNote);


    cout << "\nSender Information\n";
    cout << "Sender Name: ";
    getline(cin, senderName);

    cout << "Designation: ";
    getline(cin, designation);

    cout << "Department: ";
    getline(cin, department);

    companyName = sorganization_name;
    if(companyName.empty()){
    cout << "Company / Organization: ";
    getline(cin, companyName);
    }

    stringstream ss(sender);
    ss >> filename;

    cout<<"\nEnter file location : ";
    getline(cin,ppath);

    string path = file_path(ppath);
    string time = Date_Time();
    int l = path.length();
    if(path[l-1]=='\\')
    {
        path2 = path + filename + "(Invoice)" + time + ".html";
    }
    else
    {
        path2 = path + "\\\\" + filename + "(Invoice)" + time + ".html";
    }

    ofstream file(path2);

    file << "<!DOCTYPE html>\n";
    file << "<html lang=\"en\">\n";

    file << "<head>\n";

    file << "<meta charset=\"UTF-8\">\n";

    file << "<meta name=\"viewport\" "
         "content=\"width=device-width, initial-scale=1.0\">\n";

    file << "<title>Memo - "
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
    file << "    font-family: Arial, Helvetica, sans-serif;\n";
    file << "}\n";


    file << ".page {\n";
    file << "    width: 850px;\n";
    file << "    max-width: 100%;\n";
    file << "    min-height: 1000px;\n";
    file << "    margin: auto;\n";
    file << "    background: white;\n";
    file << "    padding: 55px 65px;\n";
    file << "    box-shadow: 0 8px 28px rgba(0,0,0,0.10);\n";
    file << "}\n";


    file << ".top-line {\n";
    file << "    height: 6px;\n";
    file << "    background: #37474f;\n";
    file << "    margin-bottom: 25px;\n";
    file << "}\n";


    file << ".memo-title {\n";
    file << "    text-align: center;\n";
    file << "    font-size: 34px;\n";
    file << "    font-weight: bold;\n";
    file << "    letter-spacing: 3px;\n";
    file << "    color: #263238;\n";
    file << "    margin-bottom: 35px;\n";
    file << "}\n";


    file << ".info-box {\n";
    file << "    border: 1px solid #cfd8dc;\n";
    file << "    margin-bottom: 30px;\n";
    file << "}\n";


    file << ".info-row {\n";
    file << "    display: flex;\n";
    file << "    border-bottom: 1px solid #e0e5e7;\n";
    file << "}\n";


    file << ".info-row:last-child {\n";
    file << "    border-bottom: none;\n";
    file << "}\n";


    file << ".info-label {\n";
    file << "    width: 18%;\n";
    file << "    padding: 14px 16px;\n";
    file << "    background: #f1f4f5;\n";
    file << "    font-size: 12px;\n";
    file << "    font-weight: bold;\n";
    file << "    text-transform: uppercase;\n";
    file << "    color: #546e7a;\n";
    file << "}\n";


    file << ".info-value {\n";
    file << "    width: 82%;\n";
    file << "    padding: 14px 16px;\n";
    file << "    font-size: 14px;\n";
    file << "    color: #263238;\n";
    file << "}\n";


    file << ".opening {\n";
    file << "    font-size: 15.5px;\n";
    file << "    line-height: 1.8;\n";
    file << "    margin-bottom: 25px;\n";
    file << "}\n";


    file << ".section {\n";
    file << "    margin: 25px 0;\n";
    file << "    padding: 20px;\n";
    file << "    border-left: 5px solid #37474f;\n";
    file << "    background: #f7f9fa;\n";
    file << "}\n";


    file << ".section-title {\n";
    file << "    margin-bottom: 10px;\n";
    file << "    font-size: 13px;\n";
    file << "    font-weight: bold;\n";
    file << "    text-transform: uppercase;\n";
    file << "    letter-spacing: 0.5px;\n";
    file << "    color: #455a64;\n";
    file << "}\n";


    file << ".section-text {\n";
    file << "    font-family: Georgia, 'Times New Roman', serif;\n";
    file << "    font-size: 15px;\n";
    file << "    line-height: 1.8;\n";
    file << "    color: #252525;\n";
    file << "}\n";


    file << ".action-box {\n";
    file << "    margin: 25px 0;\n";
    file << "    padding: 20px;\n";
    file << "    border: 1px solid #cfd8dc;\n";
    file << "    background: #ffffff;\n";
    file << "}\n";


    file << ".action-title {\n";
    file << "    font-size: 13px;\n";
    file << "    font-weight: bold;\n";
    file << "    color: #263238;\n";
    file << "    text-transform: uppercase;\n";
    file << "    margin-bottom: 10px;\n";
    file << "}\n";


    file << ".action-text {\n";
    file << "    font-size: 15px;\n";
    file << "    line-height: 1.8;\n";
    file << "}\n";


    file << ".closing {\n";
    file << "    margin-top: 30px;\n";
    file << "    font-family: Georgia, 'Times New Roman', serif;\n";
    file << "    font-size: 15px;\n";
    file << "    line-height: 1.8;\n";
    file << "}\n";


    file << ".signature {\n";
    file << "    margin-top: 45px;\n";
    file << "    line-height: 1.7;\n";
    file << "}\n";


    file << ".signature-name {\n";
    file << "    font-size: 17px;\n";
    file << "    font-weight: bold;\n";
    file << "    color: #263238;\n";
    file << "}\n";


    file << ".signature-details {\n";
    file << "    font-size: 13px;\n";
    file << "    color: #607078;\n";
    file << "}\n";


    file << ".footer {\n";
    file << "    margin-top: 55px;\n";
    file << "    padding-top: 15px;\n";
    file << "    border-top: 1px solid #d5dde0;\n";
    file << "    text-align: center;\n";
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

    file << "<div class=\"memo-title\">MEMORANDUM</div>\n";

    file << "<div class=\"info-box\">\n";

    file << "<div class=\"info-row\">\n";

    file << "<div class=\"info-label\">To</div>\n";

    file << "<div class=\"info-value\">"
         << recipient
         << "</div>\n";

    file << "</div>\n";

    file << "<div class=\"info-row\">\n";

    file << "<div class=\"info-label\">From</div>\n";

    file << "<div class=\"info-value\">"
         << sender
         << "</div>\n";

    file << "</div>\n";

    file << "<div class=\"info-row\">\n";

    file << "<div class=\"info-label\">Date</div>\n";

    file << "<div class=\"info-value\">"
         << date
         << "</div>\n";

    file << "</div>\n";

    file << "<div class=\"info-row\">\n";

    file << "<div class=\"info-label\">Subject</div>\n";

    file << "<div class=\"info-value\">"
         << subject
         << "</div>\n";

    file << "</div>\n";

    file << "</div>\n";

    file << "<div class=\"opening\">\n";

    file << "Dear "
         << recipient
         << ",\n";

    file << "<br><br>\n";

    file << "This memo is to inform you about <strong>"
         << purpose
         << "</strong>.";

    file << "</div>\n";

    file << "<div class=\"section\">\n";

    file << "<div class=\"section-title\">Details</div>\n";

    file << "<div class=\"section-text\">\n";

    file << details;

    file << "</div>\n";

    file << "</div>\n";

    if (!requiredAction.empty())
    {
        file << "<div class=\"action-box\">\n";

        file << "<div class=\"action-title\">Required Action</div>\n";

        file << "<div class=\"action-text\">\n";

        file << requiredAction;

        file << "</div>\n";

        file << "</div>\n";
    }


    if (!importantNote.empty())
    {
        file << "<div class=\"section\">\n";

        file << "<div class=\"section-title\">Important Note</div>\n";

        file << "<div class=\"section-text\">\n";

        file << importantNote;

        file << "</div>\n";

        file << "</div>\n";
    }

    file << "<div class=\"closing\">\n";

    file << "Please ensure that the above information and requirements "
         "are followed accordingly.";

    file << "<br><br>";

    file << "Thank you for your attention and cooperation.";

    file << "</div>\n";

    file << "<div class=\"signature\">\n";

    file << "<div class=\"signature-name\">"
         << senderName
         << "</div>\n";

    file << "<div class=\"signature-details\">\n";

    file << designation << "<br>\n";

    file << department << "<br>\n";

    file << companyName << "\n";

    file << "</div>\n";

    file << "</div>\n";

    file << "<div class=\"footer\">\n";
    file << "Memo &nbsp; | &nbsp; Generated by DocCreator";

    file << "</div>\n";

    file << "</div>\n";

    file << "</body>\n";

    file << "</html>\n";

    file.close();


    cout << "\nMemo generated successfully!\n";
    cout << "File Name : "<< filename<<endl;
    cout<<"File Location : "<< path2<<endl;
    cout << "Open it in Chrome, Edge, or Firefox.\n";

}
