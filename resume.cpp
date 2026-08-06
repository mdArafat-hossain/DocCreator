#include<iostream>
#include<string>
#include<cctype>
#include<ctime>
#include<fstream>
#include<sstream>
#include<filesystem>
#include "resume.h"
#include "zutils.h"
#include "login.h"
using namespace std;
namespace fs = std::filesystem;

void resume(string username)
    {
        cin.ignore();
        string filename;
        string name, email, phone, address,pf;
        string objective,cchoice;

        string degree, university, year, cgpa;
        string college, year2, gpa;
        string school, year3, gpa2;

        string title,duration,position,work1,work2,work3;

        string skill1, skill2, skill3, skill4;
        bool exp = false;

        cout << "\n===== Resume Generator (HTML) =====\n\n";

        cout << "Full Name : ";
        getline(cin,name);

        stringstream ss(name); // generate one word from multiple words (Arafat Hossain Rizve)== Arafat
        ss >> filename;

        cout<<"\nProfessional Headline : ";
        getline(cin,pf);

        cout << "\nEmail : ";
        getline(cin,email);

        cout << "\nPhone : ";
        getline(cin,phone);

        cout << "\nAddress : ";
        getline(cin,address);

        cout << "\nCareer Objective : ";
        getline(cin,objective);

        cout << "\nEducation\n";
        cout << "Degree : ";
        getline(cin,degree);

        cout << "\nUniversity : ";
        getline(cin,university);

        cout << "\nYear : ";
        getline(cin,year);

        cout << "\nCGPA : ";
        getline(cin,cgpa);

        cout<<"\nCollege : ";
        getline(cin,college);

        cout<<"\nYear : ";
        getline(cin,year2);

        cout<<"\nGPA : ";
        getline(cin,gpa);

        cout<<"\nSchool : ";
        getline(cin,school);

        cout<<"\nYear : ";
        getline(cin,year3);

        cout<<"\nGPA : ";
        getline(cin,gpa2);

        cout<<"Do you have any Experience ?(Y/N) ";
        getline(cin,cchoice);
        if(cchoice == "Y" || cchoice=="y")
        {
            exp=true;
        }

        if(exp)
        {
            cout<<"\nEnter Job title : ";
            getline(cin,title);

            cout<<"\nJob Position : ";
            getline(cin,position);

            cout<<"\nJob Duration (Start year - End year)";
            getline(cin,duration);

            cout<<"\nEnter 3 Responsibilities"<<endl;

            cout<<"\n1.";
            getline(cin,work1);

            cout<<"\n2.";
            getline(cin,work2);

            cout<<"\n3.";
            getline(cin,work3);


        }

        cout << "\nEnter 4 Skills\n";
        cout << "\nSkill 1 : ";
        getline(cin, skill1);

        cout << "\nSkill 2 : ";
        getline(cin, skill2);

        cout << "\nSkill 3 : ";
        getline(cin, skill3);

        cout << "\nSkill 4 : ";
        getline(cin, skill4);

        string time = Date_Time();
        string path = "E:\\DocCreator\\html_files";
        string path2 = path + "\\" + username + "\\" + filename + "(Resume)" + time + ".html"; //E:\\DocCreator\\html_files\\Arafat\\arafat(Resume)_2026-07-28_1237.html

        ofstream file(path2);

        file << "<!DOCTYPE html>\n";
        file << "<html>\n";
        file << "<head>\n";
        file << "<meta charset='UTF-8'>\n";
        file << "<title>Resume</title>\n";

        file << "<style>\n";
        file << "body{font-family:Arial;margin:40px;background:white;}\n";
        file << ".resume{background:white;padding:40px;width:800px;margin:auto;""border-radius:10px;box-shadow:0 0 10px gray;}\n";
        file << "h1{color:#003366;}\n";
        file << "h2{color:#003366;border-bottom:2px solid #003366;}\n";
        file << "table{width:100%;border-collapse:collapse;}\n";
        file << "table,th,td{border:1px solid gray;}\n";
        file << "th,td{padding:8px;}\n";
        file << ".skill{display:inline-block;background:#ddeeff;"
             "padding:8px 15px;margin:5px;border-radius:5px;}\n";
        file << "</style>\n";

        file << "</head>\n";
        file << "<body>\n";

        file << "<div class='resume'>";

        file << "<h1>" << name << "</h1>";
        file << "<h2>" <<pf<<"</h2>";
        file << "<p><b>Email:</b> " << email << "</p>";
        file << "<p><b>Phone:</b> " << phone << "</p>";
        file << "<p><b>Address:</b> " << address << "</p>";

        file << "<h2>Career Objective</h2>";
        file << "<p>" << objective << "</p>";

        file << "<h2>Education</h2>";
        file << "<table>";
        file << "<tr><th>Degree</th><th>University</th><th>Year</th><th>Result</th></tr>";
        file << "<tr>";
        file << "<td>" << degree << "</td>";
        file << "<td>" << university << "</td>";
        file << "<td>" << year << "</td>";
        file << "<td>" << cgpa << "</td>";
        file << "</tr>";

        file << "<tr>";
        file << "<td>" << "HSC" << "</td>";
        file << "<td>" << college << "</td>";
        file << "<td>" << year2 << "</td>";
        file << "<td>" << gpa << "</td>";
        file << "</tr>";

        file << "<tr>";
        file << "<td>" << "SSC" << "</td>";
        file << "<td>" << school << "</td>";
        file << "<td>" << year3 << "</td>";
        file << "<td>" << gpa2 << "</td>";
        file << "</tr>";
        file << "</table>";

        file << "<h2>Skills</h2>";
        file << "<span class='skill'>" << skill1 << "</span>";
        file << "<span class='skill'>" << skill2 << "</span>";
        file << "<span class='skill'>" << skill3 << "</span>";
        file << "<span class='skill'>" << skill4 << "</span>";


        file << "<h2>Experience</h2>";
        if(!exp)
        {
            file << "<p>Fresher</p>";
        }
        else
        {
            file<<"</h1>" << title <<"</h1>";
            file<<" || " << position <<" || "<< duration;
            file<<"<p>"<<"1. " <<work1<<"</p>";
            file<<"<p>"<<"2. " <<work2<<"</p>";
            file<<"<p>"<<"3. " <<work3<<"</p>";

        }

        file << "</div>";

        file << "</body>";
        file << "</html>";

        file.close();

        cout << "\nResume generated successfully!\n";
        cout << "File Name : "<< filename<<endl;
        cout<<"File Location : "<< path2<<endl;
        cout << "Open it in Chrome, Edge, or Firefox.\n";

    }
