#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#include "zutils.h"
#include "login.h"
#include "Meeting_Minutes.h"
using namespace std;

void meeting_minutes(string sname)
{
    cin.ignore();
    string filename,ppath,path2;
    string meetingTitle, meetingDate, startTime, endTime;
    string location, chairperson, recorder;
    int attendeeCount, agendaCount, actionCount, decisionCount;
    string attendees[100], agenda[100], actionItem[100], responsiblePerson[100], deadline[100];

    string decisions[100], nextMeetingDate, nextMeetingTime, additionalNotes;

    cout << "\n===== Meeting Minutes Document Generator (HTML) =====\n\n";

    // Meeting Information
    cout << "Enter Meeting Title: ";
    getline(cin, meetingTitle);

    cout << "Enter Meeting Date: ";
    getline(cin, meetingDate);

    cout << "Enter Start Time: ";
    getline(cin, startTime);

    cout << "Enter End Time: ";
    getline(cin, endTime);

    cout << "Enter Location / Platform: ";
    getline(cin, location);

    chairperson = sname;
    if(sname.empty())
    {
        cout << "Enter Chairperson: ";
        getline(cin, chairperson);
    }

    cout << "Enter Meeting Recorder / Secretary: ";
    getline(cin, recorder);

    cout << "\nHow many attendees? ";
    cin >> attendeeCount;

    while (cin.fail() || attendeeCount <= 0 || attendeeCount > 100)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input! Enter number of attendees (1-100): ";
        cin >> attendeeCount;
    }

    cin.ignore();
    for (int i = 0; i < attendeeCount; i++)
    {
        cout << "Enter Attendee " << i + 1 << ": ";
        getline(cin, attendees[i]);
    }

    cout << "\nHow many agenda items? ";
    cin >> agendaCount;

    while (cin.fail() || agendaCount <= 0 || agendaCount > 100)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input! Enter number of agenda items (1-100): ";
        cin >> agendaCount;
    }
    cin.ignore();
    for (int i = 0; i < agendaCount; i++)
    {
        cout << "Enter Agenda Item " << i + 1 << ": ";
        getline(cin, agenda[i]);
    }
    cout << "\nHow many action items? ";
    cin >> actionCount;

    while (cin.fail() || actionCount < 0 || actionCount > 100)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input! Enter number of action items (0-100): ";
        cin >> actionCount;
    }

    cin.ignore();
    for (int i = 0; i < actionCount; i++)
    {
        cout << "\nAction Item " << i + 1 << endl;
        cout << "Description: ";
        getline(cin, actionItem[i]);
        cout << "Responsible Person: ";
        getline(cin, responsiblePerson[i]);
        cout << "Deadline: ";
        getline(cin, deadline[i]);
    }

    cout << "\nHow many decisions were made? ";
    cin >> decisionCount;

    while (cin.fail() || decisionCount < 0 || decisionCount > 100)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input! Enter number of decisions (0-100): ";
        cin >> decisionCount;
    }

    cin.ignore();

    for (int i = 0; i < decisionCount; i++)
    {
        cout << "Enter Decision " << i + 1 << ": ";
        getline(cin, decisions[i]);
    }
    // NEXT MEETING
    cout << "\nEnter Next Meeting Date (optional): ";
    getline(cin, nextMeetingDate);

    cout << "Enter Next Meeting Time (optional): ";
    getline(cin, nextMeetingTime);

    cout << "Enter Additional Notes (optional): ";
    getline(cin, additionalNotes);

    // Default values
    if (nextMeetingDate.empty())
    {
        nextMeetingDate = "Not scheduled";
    }
    if (nextMeetingTime.empty())
    {
        nextMeetingTime = "Not scheduled";
    }
    if (additionalNotes.empty())
    {
        additionalNotes = "No additional notes.";
    }

    cout<<"\nEnter file location : ";
    getline(cin,ppath);

    filename = "Meeting_Minutes";
    string path = file_path(ppath);
    string time = Date_Time();
    int l = path.length();
    if(path[l-1]=='\\')
    {
        path2 = path + filename  + time + ".html";
    }
    else
    {
        path2 = path + "\\\\" + filename  + time + ".html";
    }


    ofstream file(path2);

    file << "<!DOCTYPE html>\n";
    file << "<html lang=\"en\">\n";

    file << "<head>\n";
    file << "<meta charset=\"UTF-8\">\n";
    file << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
    file << "<title>Meeting Minutes</title>\n";
    file << "<style>\n";
    file << "* {\n";
    file << "    box-sizing: border-box;\n";
    file << "}\n";

    file << "body {\n";
    file << "    margin: 0;\n";
    file << "    padding: 40px;\n";
    file << "    background: #eef2f7;\n";
    file << "    font-family: Arial, Helvetica, sans-serif;\n";
    file << "    color: #263238;\n";
    file << "}\n";

    file << ".document {\n";
    file << "    max-width: 950px;\n";
    file << "    margin: auto;\n";
    file << "    background: white;\n";
    file << "    padding: 50px 60px;\n";
    file << "    box-shadow: 0 8px 25px rgba(0,0,0,0.08);\n";
    file << "    border-radius: 8px;\n";
    file << "}\n";

    file << ".header {\n";
    file << "    display: flex;\n";
    file << "    justify-content: space-between;\n";
    file << "    align-items: center;\n";
    file << "    padding-bottom: 25px;\n";
    file << "    border-bottom: 3px solid #263238;\n";
    file << "}\n";

    file << ".header h1 {\n";
    file << "    margin: 0;\n";
    file << "    font-size: 30px;\n";
    file << "    letter-spacing: 1px;\n";
    file << "}\n";

    file << ".header p {\n";
    file << "    margin: 6px 0 0;\n";
    file << "    color: #607d8b;\n";
    file << "}\n";

    file << ".meeting-badge {\n";
    file << "    padding: 10px 16px;\n";
    file << "    border: 1px solid #cfd8dc;\n";
    file << "    border-radius: 20px;\n";
    file << "    font-size: 13px;\n";
    file << "    color: #455a64;\n";
    file << "}\n";

    file << ".info-grid {\n";
    file << "    display: grid;\n";
    file << "    grid-template-columns: 1fr 1fr;\n";
    file << "    gap: 15px;\n";
    file << "    margin-top: 25px;\n";
    file << "}\n";

    file << ".info-box {\n";
    file << "    padding: 15px;\n";
    file << "    background: #f7f9fb;\n";
    file << "    border: 1px solid #e0e6eb;\n";
    file << "    border-radius: 6px;\n";
    file << "}\n";

    file << ".label {\n";
    file << "    font-size: 11px;\n";
    file << "    text-transform: uppercase;\n";
    file << "    letter-spacing: 1px;\n";
    file << "    color: #78909c;\n";
    file << "    margin-bottom: 5px;\n";
    file << "}\n";

    file << ".value {\n";
    file << "    font-weight: bold;\n";
    file << "    color: #263238;\n";
    file << "}\n";

    // Sections
    file << ".section {\n";
    file << "    margin-top: 35px;\n";
    file << "}\n";

    file << ".section-title {\n";
    file << "    font-size: 18px;\n";
    file << "    font-weight: bold;\n";
    file << "    padding-bottom: 10px;\n";
    file << "    margin-bottom: 15px;\n";
    file << "    border-bottom: 2px solid #eceff1;\n";
    file << "}\n";

    file << ".attendees {\n";
    file << "    display: grid;\n";
    file << "    grid-template-columns: 1fr 1fr;\n";
    file << "    gap: 10px;\n";
    file << "}\n";
    file << ".person {\n";
    file << "    padding: 10px 14px;\n";
    file << "    background: #fafafa;\n";
    file << "    border-left: 3px solid #607d8b;\n";
    file << "}\n";

    file << "ol {\n";
    file << "    margin: 0;\n";
    file << "    padding-left: 25px;\n";
    file << "}\n";

    file << "li {\n";
    file << "    padding: 7px 0;\n";
    file << "    line-height: 1.5;\n";
    file << "}\n";

    file << "table {\n";
    file << "    width: 100%;\n";
    file << "    border-collapse: collapse;\n";
    file << "}\n";

    file << "th {\n";
    file << "    background: #263238;\n";
    file << "    color: white;\n";
    file << "    padding: 12px;\n";
    file << "    text-align: left;\n";
    file << "    font-size: 13px;\n";
    file << "}\n";

    file << "td {\n";
    file << "    padding: 12px;\n";
    file << "    border-bottom: 1px solid #e0e0e0;\n";
    file << "    vertical-align: top;\n";
    file << "    line-height: 1.5;\n";
    file << "}\n";

    file << "tr:nth-child(even) {\n";
    file << "    background: #f8fafb;\n";
    file << "}\n";

    file << ".decision {\n";
    file << "    padding: 14px;\n";
    file << "    margin-bottom: 10px;\n";
    file << "    background: #f8fafb;\n";
    file << "    border-left: 4px solid #455a64;\n";
    file << "}\n";

    file << ".next-meeting {\n";
    file << "    display: flex;\n";
    file << "    gap: 30px;\n";
    file << "    padding: 18px;\n";
    file << "    background: #f5f7f8;\n";
    file << "    border: 1px solid #dce3e6;\n";
    file << "    border-radius: 6px;\n";
    file << "}\n";

    file << ".notes {\n";
    file << "    padding: 18px;\n";
    file << "    background: #fffdf5;\n";
    file << "    border: 1px solid #eee2b5;\n";
    file << "    line-height: 1.6;\n";
    file << "}\n";

    file << ".footer {\n";
    file << "    margin-top: 45px;\n";
    file << "    padding-top: 20px;\n";
    file << "    border-top: 1px solid #cfd8dc;\n";
    file << "    display: flex;\n";
    file << "    justify-content: space-between;\n";
    file << "    font-size: 13px;\n";
    file << "    color: #607d8b;\n";
    file << "}\n";

    // Print
    file << "@media print {\n";
    file << "    body {\n";
    file << "        padding: 0;\n";
    file << "        background: white;\n";
    file << "    }\n";

    file << "    .document {\n";
    file << "        box-shadow: none;\n";
    file << "        max-width: none;\n";
    file << "    }\n";
    file << "}\n";

    file << "</style>\n";
    file << "</head>\n";

    file << "<body>\n";
    file << "<div class=\"document\">\n";

    file << "<div class=\"header\">\n";

    file << "<div>\n";
    file << "<h1>MEETING MINUTES</h1>\n";
    file << "<p>" << meetingTitle << "</p>\n";
    file << "</div>\n";

    file << "<div class=\"meeting-badge\">OFFICIAL RECORD</div>\n";

    file << "</div>\n";

    // Meeting information
    file << "<div class=\"info-grid\">\n";

    file << "<div class=\"info-box\">";
    file << "<div class=\"label\">Date</div>";
    file << "<div class=\"value\">" << meetingDate << "</div>";
    file << "</div>\n";

    file << "<div class=\"info-box\">";
    file << "<div class=\"label\">Location / Platform</div>";
    file << "<div class=\"value\">" << location << "</div>";
    file << "</div>\n";

    file << "<div class=\"info-box\">";
    file << "<div class=\"label\">Time</div>";
    file << "<div class=\"value\">" << startTime
         << " - " << endTime << "</div>";
    file << "</div>\n";

    file << "<div class=\"info-box\">";
    file << "<div class=\"label\">Chairperson</div>";
    file << "<div class=\"value\">" << chairperson << "</div>";
    file << "</div>\n";

    file << "</div>\n";
    file << "<div class=\"section\">\n";
    file << "<div class=\"section-title\">ATTENDEES</div>\n";
    file << "<div class=\"attendees\">\n";

    for (int i = 0; i < attendeeCount; i++)
    {
        file << "<div class=\"person\">";
        file << attendees[i];
        file << "</div>\n";
    }

    file << "</div>\n";
    file << "</div>\n";
    file << "<div class=\"section\">\n";
    file << "<div class=\"section-title\">MEETING RECORDER</div>\n";

    file << "<p><strong>Recorded by:</strong> "
         << recorder << "</p>\n";

    file << "</div>\n";
    file << "<div class=\"section\">\n";
    file << "<div class=\"section-title\">AGENDA</div>\n";

    file << "<ol>\n";

    for (int i = 0; i < agendaCount; i++)
    {
        file << "<li>";
        file << agenda[i];
        file << "</li>\n";
    }

    file << "</ol>\n";
    file << "</div>\n";
    file << "<div class=\"section\">\n";
    file << "<div class=\"section-title\">ACTION ITEMS</div>\n";

    if (actionCount > 0)
    {
        file << "<table>\n";

        file << "<tr>";
        file << "<th>#</th>";
        file << "<th>Action Item</th>";
        file << "<th>Responsible Person</th>";
        file << "<th>Deadline</th>";
        file << "</tr>\n";
        for (int i = 0; i < actionCount; i++)
        {
            file << "<tr>";

            file << "<td>" << i + 1 << "</td>";

            file << "<td>"
                 << actionItem[i]
                 << "</td>";
            file << "<td>"
                 << responsiblePerson[i]
                 << "</td>";
            file << "<td>"
                 << deadline[i]
                 << "</td>";
            file << "</tr>\n";
        }

        file << "</table>\n";
    }
    else
    {
        file << "<p>No action items were recorded.</p>\n";
    }

    file << "</div>\n";
    file << "<div class=\"section\">\n";
    file << "<div class=\"section-title\">DECISIONS MADE</div>\n";

    if (decisionCount > 0)
    {
        for (int i = 0; i < decisionCount; i++)
        {
            file << "<div class=\"decision\">";
            file << "<strong>Decision " << i + 1 << ":</strong> ";
            file << decisions[i];
            file << "</div>\n";
        }
    }
    else
    {
        file << "<p>No formal decisions were recorded.</p>\n";
    }

    file << "</div>\n";

    file << "<div class=\"section\">\n";
    file << "<div class=\"section-title\">NEXT MEETING</div>\n";
    file << "<div class=\"next-meeting\">\n";
    file << "<div>";
    file << "<strong>Date:</strong><br>";
    file << nextMeetingDate;
    file << "</div>\n";

    file << "<div>";
    file << "<strong>Time:</strong><br>";
    file << nextMeetingTime;
    file << "</div>\n";
    file << "</div>\n";
    file << "</div>\n";

    file << "<div class=\"section\">\n";
    file << "<div class=\"section-title\">ADDITIONAL NOTES</div>\n";

    file << "<div class=\"notes\">";
    file << additionalNotes;
    file << "</div>\n";

    file << "</div>\n";


    file << "<div class=\"footer\">\n";

    file << "<div>";
    file << "<strong>Chairperson:</strong> "
         << chairperson;
    file << "</div>\n";

    file << "<div>";
    file << "<strong>Recorded by:</strong> "
         << recorder;
    file << "</div>\n";

    file << "</div>\n";

    file << "</div>\n";
    file << "</body>\n";
    file << "</html>\n";

    file.close();

    cout << "\nMeeting Minutes generated successfully!\n";
    cout << "File Name : "<< filename<<endl;
    cout<<"File Location : "<< path2<<endl;
    cout << "Open it in Chrome, Edge, or Firefox.\n";


}
