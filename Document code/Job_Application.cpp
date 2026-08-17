#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "zutils.h"
#include "login.h"
#include "Job_Application.h"
using namespace std;

void Job_Application()
{
    string name, address, phone, email, date;
    string hiringManager, company, companyAddress, position;
    string skills, qualification;
    string experience, gender, letter;
    string filename,ppath,path2;
    cin.ignore();

    cout << "\n===== Job Application Generator (HTML) =====\n\n";

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

    cout << "Enter hiring manager's name (or press Enter for Sir/Madam): ";
    getline(cin, hiringManager);

    if (hiringManager.empty())
    {
        hiringManager = "Sir/Madam";
    }

    cout << "Enter company/organization name: ";
    getline(cin, company);

    cout << "Enter company address: ";
    getline(cin, companyAddress);

    cout << "Enter position you are applying for: ";
    getline(cin, position);

    cout << "Enter your relevant skills/field: ";
    getline(cin, skills);

    cout << "Enter your qualification/education: ";
    getline(cin, qualification);


    cout << "Enter your experience (or press enter for fresher): ";
    getline(cin, experience);

    if(experience.empty())
    {
        letter = "I ";
    }
    else
    {
        letter = "I have " + experience + " of experience working in this field and";
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
        path2 = path + filename + "(Job_Applica)" + time + ".html"; //E:\\arafat(Resume)_2026-07-28_1237.html
    }
    else
    {
        path2 = path + "\\\\" + filename + "(Job_Application)" + time + ".html"; //E:\\DocCreator\\arafat(Resume)_2026-07-28_1237.html
    }


    ofstream file(path2);

    file << "<!DOCTYPE html>\n";
    file << "<html>\n";

    file << "<head>\n";
    file << "<meta charset='UTF-8'>\n";
    file << "<title>Job Application</title>\n";

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


    // Body
    file << "<body>\n";


    // Applicant information
    file << "<p>";
    file << "<strong>" << name << "</strong><br>";
    file << address << "<br>";
    file << phone << "<br>";
    file << email << "<br>";
    file << date;
    file << "</p>\n";


    // Company information
    file << "<p>";
    if(hiringManager.empty())
    {
        file << "HR Department" << "<br>";
    }
    else
    {
        file<< hiringManager << "<br>";
    }
    file << company << "<br>";
    file << companyAddress;
    file << "</p>\n";


    // Subject
    file << "<p class='subject'>";
    file << "Subject: Application for the Position of "
         << position;
    file << "</p>\n";


    // Greeting
    file << "<p>Dear " << hiringManager << ",</p>\n";


    // Paragraph 1
    file << "<p>";
    file << "I am writing to apply for the position of "
         << "<strong>" << position << "</strong> at "
         << "<strong>" << company << "</strong>. ";

    file << "I am interested in this opportunity and believe that "
         "my skills, qualifications, and willingness to learn "
         "would allow me to contribute positively to your organization.";
    file << "</p>\n";


    // Paragraph 2
    file << "<p>";

    file << "I have experience and knowledge in "
         << "<strong>" << skills << "</strong> and have completed "
         << "<strong>" << qualification << "</strong>. ";

    file << "I am capable of working effectively both independently "
         "and as part of a team. ";

    file << "I am a responsible, hardworking, and adaptable individual "
         "who is always willing to learn new skills and take on "
         "new challenges.";

    file << "</p>\n";


    // Paragraph 3
    file << "<p>";

    file << letter << " believe that working with your organization would "
         "provide me with an opportunity to utilize my abilities "
         "while gaining valuable professional experience. ";

    file << "I am committed to performing my responsibilities sincerely "
         "and contributing to the success of the organization.";

    file << "</p>\n";


    // Paragraph 4
    file << "<p>";

    file << "I have attached my resume/CV for your consideration. "
         "I would appreciate the opportunity to discuss my "
         "qualifications further in an interview. Thank you for considering my application. "
         "I look forward to hearing from you.";

    file << "</p>\n";


    // Signature
    file << "<p class='signature'>";
    file << "Sincerely,<br>";
    file << "<strong>" << name << "</strong><br>";
    file << phone << "<br>";
    file << email;
    file << "</p>\n";


    // HTML ends
    file << "</body>\n";
    file << "</html>\n";

    file.close();


    cout << "\nJob Application generated successfully!\n";
    cout << "File Name : "<< filename<<endl;
    cout<<"File Location : "<< path2<<endl;
    cout << "Open it in Chrome, Edge, or Firefox.\n";
}
