#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include<sstream>
#include "zutils.h"
#include "login.h"
#include "Salary_Slip.h"

using namespace std;

void salary_slip(string sname, string saddress, string sphone)
{
    cin.ignore();
    string filename,ppath,path2;
    string companyName, companyAddress, companyPhone;
    string employeeName, employeeID, designation, department, joiningDate;
    string salaryMonth, paymentDate;

    double basicSalary, houseAllowance, medicalAllowance, transportAllowance, otherAllowance;
    double tax, providentFund, loanDeduction, otherDeduction, grossSalary;
    double totalDeduction, netSalary;

    cout << "\n===== Salary Slip Generator (HTML) =====\n\n";

    cout << "COMPANY INFORMATION\n";

    if(sname.empty() || saddress.empty()){
    cout << "Company Name: ";
    getline(cin, companyName);

    cout << "Company Address: ";
    getline(cin, companyAddress);

    cout << "Company Phone: ";
    getline(cin, companyPhone);
}
    cout << "\nEMPLOYEE INFORMATION\n";
    cout << "Employee Name: ";
    getline(cin, employeeName);

    cout << "Employee ID: ";
    getline(cin, employeeID);

    cout << "Designation: ";
    getline(cin, designation);
    cout << "Department: ";
    getline(cin, department);

    cout << "Joining Date: ";
    getline(cin, joiningDate);

    cout << "\nSALARY SLIP INFORMATION\n";
    cout << "Salary Month: ";
    getline(cin, salaryMonth);

    cout << "Payment Date: ";
    getline(cin, paymentDate);

    cout << "\nEARNINGS\n";
    cout << "Basic Salary: ";
    cin >> basicSalary;

    while (cin.fail() || basicSalary < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid amount! Enter Basic Salary: ";
        cin >> basicSalary;
    }

    cout << "House Allowance: ";
    cin >> houseAllowance;

    while (cin.fail() || houseAllowance < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid amount! Enter House Allowance: ";
        cin >> houseAllowance;
    }

    cout << "Medical Allowance: ";
    cin >> medicalAllowance;

    while (cin.fail() || medicalAllowance < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid amount! Enter Medical Allowance: ";
        cin >> medicalAllowance;
    }

    cout << "Transport Allowance: ";
    cin >> transportAllowance;

    while (cin.fail() || transportAllowance < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid amount! Enter Transport Allowance: ";
        cin >> transportAllowance;
    }

    cout << "Other Allowance: ";
    cin >> otherAllowance;
    while (cin.fail() || otherAllowance < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid amount! Enter Other Allowance: ";
        cin >> otherAllowance;
    }

    cout << "\nDEDUCTIONS\n";
    cout << "Tax: ";
    cin >> tax;

    while (cin.fail() || tax < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid amount! Enter Tax: ";
        cin >> tax;
    }

    cout << "Provident Fund: ";
    cin >> providentFund;
    while (cin.fail() || providentFund < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid amount! Enter Provident Fund: ";
        cin >> providentFund;
    }

    cout << "Loan Deduction: ";
    cin >> loanDeduction;
    while (cin.fail() || loanDeduction < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid amount! Enter Loan Deduction: ";
        cin >> loanDeduction;
    }

    cout << "Other Deduction: ";
    cin >> otherDeduction;
    while (cin.fail() || otherDeduction < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid amount! Enter Other Deduction: ";
        cin >> otherDeduction;
    }

    grossSalary = basicSalary + houseAllowance + medicalAllowance + transportAllowance + otherAllowance;
    totalDeduction = tax + providentFund + loanDeduction + otherDeduction;
    netSalary = grossSalary - totalDeduction;

    cout<<"\nEnter file location : ";
    getline(cin,ppath);

    stringstream ss(employeeName); // generate one word from multiple words (Arafat Hossain Rizve)== Arafat
    ss >> filename;

    string path = file_path(ppath);
    string time = Date_Time();
    int l = path.length();
    if(path[l-1]=='\\')
    {
        path2 = path + filename + "(Salary Slip)" + time + ".html"; //E:\\arafat(Resume)_2026-07-28_1237.html
    }
    else
    {
        path2 = path + "\\\\" + filename + "(Salary Slip)" + time + ".html"; //E:\\DocCreator\\arafat(Resume)_2026-07-28_1237.html
    }


    ofstream file(path2);

    file << "<!DOCTYPE html>\n";
    file << "<html lang=\"en\">\n";
    file << "<head>\n";
    file << "<meta charset=\"UTF-8\">\n";
    file << "<meta name=\"viewport\" "
         << "content=\"width=device-width, initial-scale=1.0\">\n";

    file << "<title>Salary Slip - "
         << employeeName
         << "</title>\n";

    file << "<style>\n";

    file << "* {\n";
    file << "    box-sizing: border-box;\n";
    file << "}\n";

    file << "body {\n";
    file << "    margin: 0;\n";
    file << "    padding: 40px;\n";
    file << "    background: #edf1f5;\n";
    file << "    font-family: Arial, Helvetica, sans-serif;\n";
    file << "    color: #263238;\n";
    file << "}\n";

    /* Main Document */
    file << ".salary-slip {\n";
    file << "    max-width: 850px;\n";
    file << "    margin: auto;\n";
    file << "    background: white;\n";
    file << "    padding: 45px;\n";
    file << "    box-shadow: 0 8px 25px rgba(0,0,0,0.08);\n";
    file << "}\n";

    /* Company Header */
    file << ".company-header {\n";
    file << "    display: flex;\n";
    file << "    justify-content: space-between;\n";
    file << "    align-items: center;\n";
    file << "    padding-bottom: 25px;\n";
    file << "    border-bottom: 3px solid #263238;\n";
    file << "}\n";

    file << ".company-info h1 {\n";
    file << "    margin: 0;\n";
    file << "    font-size: 26px;\n";
    file << "}\n";

    file << ".company-info p {\n";
    file << "    margin: 5px 0;\n";
    file << "    color: #607d8b;\n";
    file << "    font-size: 13px;\n";
    file << "}\n";

    file << ".salary-title {\n";
    file << "    text-align: right;\n";
    file << "}\n";

    file << ".salary-title h2 {\n";
    file << "    margin: 0;\n";
    file << "    font-size: 28px;\n";
    file << "    letter-spacing: 2px;\n";
    file << "}\n";

    file << ".salary-title p {\n";
    file << "    margin: 6px 0 0;\n";
    file << "    color: #607d8b;\n";
    file << "}\n";

    /* Employee Section */
    file << ".employee-section {\n";
    file << "    margin-top: 30px;\n";
    file << "    padding: 20px;\n";
    file << "    background: #f5f7f9;\n";
    file << "    border: 1px solid #dce3e8;\n";
    file << "}\n";

    file << ".employee-grid {\n";
    file << "    display: grid;\n";
    file << "    grid-template-columns: 1fr 1fr;\n";
    file << "    gap: 18px 40px;\n";
    file << "}\n";

    file << ".employee-item label {\n";
    file << "    display: block;\n";
    file << "    font-size: 11px;\n";
    file << "    text-transform: uppercase;\n";
    file << "    color: #78909c;\n";
    file << "    margin-bottom: 5px;\n";
    file << "}\n";

    file << ".employee-item strong {\n";
    file << "    font-size: 14px;\n";
    file << "}\n";

    /* Salary Tables */
    file << ".salary-tables {\n";
    file << "    display: grid;\n";
    file << "    grid-template-columns: 1fr 1fr;\n";
    file << "    gap: 25px;\n";
    file << "    margin-top: 30px;\n";
    file << "}\n";

    file << ".salary-table h3 {\n";
    file << "    margin: 0;\n";
    file << "    padding: 12px 15px;\n";
    file << "    background: #263238;\n";
    file << "    color: white;\n";
    file << "    font-size: 14px;\n";
    file << "    text-transform: uppercase;\n";
    file << "    letter-spacing: 1px;\n";
    file << "}\n";

    file << "table {\n";
    file << "    width: 100%;\n";
    file << "    border-collapse: collapse;\n";
    file << "}\n";

    file << "td {\n";
    file << "    padding: 11px 12px;\n";
    file << "    border-bottom: 1px solid #e0e0e0;\n";
    file << "    font-size: 13px;\n";
    file << "}\n";

    file << "td:last-child {\n";
    file << "    text-align: right;\n";
    file << "    font-weight: 500;\n";
    file << "}\n";

    file << ".total-row td {\n";
    file << "    font-weight: bold;\n";
    file << "    background: #f1f4f6;\n";
    file << "    border-top: 2px solid #b0bec5;\n";
    file << "}\n";

    /* Net Salary */
    file << ".net-salary {\n";
    file << "    margin-top: 30px;\n";
    file << "    padding: 22px 25px;\n";
    file << "    border: 2px solid #263238;\n";
    file << "    display: flex;\n";
    file << "    justify-content: space-between;\n";
    file << "    align-items: center;\n";
    file << "}\n";

    file << ".net-salary span:first-child {\n";
    file << "    font-size: 15px;\n";
    file << "    font-weight: bold;\n";
    file << "    text-transform: uppercase;\n";
    file << "}\n";

    file << ".net-salary span:last-child {\n";
    file << "    font-size: 24px;\n";
    file << "    font-weight: bold;\n";
    file << "}\n";

    /* Payment Information */
    file << ".payment-info {\n";
    file << "    margin-top: 25px;\n";
    file << "    padding: 18px;\n";
    file << "    background: #f8fafb;\n";
    file << "    border-left: 4px solid #607d8b;\n";
    file << "}\n";

    file << ".payment-info h3 {\n";
    file << "    margin: 0 0 8px;\n";
    file << "    font-size: 14px;\n";
    file << "}\n";

    file << ".payment-info p {\n";
    file << "    margin: 4px 0;\n";
    file << "    font-size: 13px;\n";
    file << "}\n";

    /* Signatures */
    file << ".signatures {\n";
    file << "    display: flex;\n";
    file << "    justify-content: space-between;\n";
    file << "    margin-top: 65px;\n";
    file << "    gap: 80px;\n";
    file << "}\n";

    file << ".signature {\n";
    file << "    width: 220px;\n";
    file << "    text-align: center;\n";
    file << "}\n";

    /*
       Signature line
    */
    file << ".signature-line {\n";
    file << "    border-top: 1px solid #263238;\n";
    file << "    margin-top: 30px;\n";
    file << "    margin-bottom: 0;\n";
    file << "}\n";

    /*
       Move signature title upward onto the line
    */
    file << ".signature strong {\n";
    file << "    display: block;\n";
    file << "    position: relative;\n";
    file << "    margin-top: -22px;\n";
    file << "    background: white;\n";
    file << "    width: fit-content;\n";
    file << "    margin-left: auto;\n";
    file << "    margin-right: auto;\n";
    file << "    padding: 0 6px;\n";
    file << "    font-size: 14px;\n";
    file << "}\n";

    /*
       Employee / company name below
    */
    file << ".signature p {\n";
    file << "    margin: 8px 0 0;\n";
    file << "    font-size: 12px;\n";
    file << "    color: #607d8b;\n";
    file << "}\n";

    /* Footer */
    file << ".footer {\n";
    file << "    text-align: center;\n";
    file << "    margin-top: 40px;\n";
    file << "    padding-top: 15px;\n";
    file << "    border-top: 1px solid #cfd8dc;\n";
    file << "    color: #78909c;\n";
    file << "    font-size: 11px;\n";
    file << "}\n";

    /* Print */
    file << "@media print {\n";

    file << "    body {\n";
    file << "        padding: 0;\n";
    file << "        background: white;\n";
    file << "    }\n";

    file << "    .salary-slip {\n";
    file << "        max-width: none;\n";
    file << "        box-shadow: none;\n";
    file << "    }\n";

    file << "}\n";

    file << "</style>\n";
    file << "</head>\n";

    file << "<body>\n";
    file << "<div class=\"salary-slip\">\n";

    /* Company Header */
    file << "<div class=\"company-header\">\n";

    file << "<div class=\"company-info\">\n";

    file << "<h1>"
         << companyName
         << "</h1>\n";

    file << "<p>"
         << companyAddress
         << "</p>\n";

    file << "<p>"
         << companyPhone
         << "</p>\n";

    file << "</div>\n";

    file << "<div class=\"salary-title\">\n";

    file << "<h2>SALARY SLIP</h2>\n";

    file << "<p>"
         << salaryMonth
         << "</p>\n";

    file << "</div>\n";

    file << "</div>\n";

    /* Employee Information */
    file << "<div class=\"employee-section\">\n";
    file << "<div class=\"employee-grid\">\n";

    file << "<div class=\"employee-item\">\n";
    file << "<label>Employee Name</label>\n";
    file << "<strong>"
         << employeeName
         << "</strong>\n";
    file << "</div>\n";

    file << "<div class=\"employee-item\">\n";
    file << "<label>Employee ID</label>\n";
    file << "<strong>"
         << employeeID
         << "</strong>\n";
    file << "</div>\n";

    file << "<div class=\"employee-item\">\n";
    file << "<label>Designation</label>\n";
    file << "<strong>"
         << designation
         << "</strong>\n";
    file << "</div>\n";

    file << "<div class=\"employee-item\">\n";
    file << "<label>Department</label>\n";
    file << "<strong>"
         << department
         << "</strong>\n";
    file << "</div>\n";

    file << "<div class=\"employee-item\">\n";
    file << "<label>Joining Date</label>\n";
    file << "<strong>"
         << joiningDate
         << "</strong>\n";
    file << "</div>\n";

    file << "<div class=\"employee-item\">\n";
    file << "<label>Payment Date</label>\n";
    file << "<strong>"
         << paymentDate
         << "</strong>\n";
    file << "</div>\n";

    file << "</div>\n";
    file << "</div>\n";

    /* Salary Tables */
    file << "<div class=\"salary-tables\">\n";

    /* Earnings */
    file << "<div class=\"salary-table\">\n";

    file << "<h3>Earnings</h3>\n";

    file << "<table>\n";

    file << fixed << setprecision(2);

    file << "<tr>";
    file << "<td>Basic Salary</td>";
    file << "<td>" << basicSalary << "</td>";
    file << "</tr>\n";

    file << "<tr>";
    file << "<td>House Allowance</td>";
    file << "<td>" << houseAllowance << "</td>";
    file << "</tr>\n";

    file << "<tr>";
    file << "<td>Medical Allowance</td>";
    file << "<td>" << medicalAllowance << "</td>";
    file << "</tr>\n";

    file << "<tr>";
    file << "<td>Transport Allowance</td>";
    file << "<td>" << transportAllowance << "</td>";
    file << "</tr>\n";

    file << "<tr>";
    file << "<td>Other Allowance</td>";
    file << "<td>" << otherAllowance << "</td>";
    file << "</tr>\n";

    file << "<tr class=\"total-row\">";
    file << "<td>Gross Salary</td>";
    file << "<td>" << grossSalary << "</td>";
    file << "</tr>\n";

    file << "</table>\n";
    file << "</div>\n";

    /* Deductions */
    file << "<div class=\"salary-table\">\n";

    file << "<h3>Deductions</h3>\n";

    file << "<table>\n";

    file << "<tr>";
    file << "<td>Tax</td>";
    file << "<td>" << tax << "</td>";
    file << "</tr>\n";

    file << "<tr>";
    file << "<td>Provident Fund</td>";
    file << "<td>" << providentFund << "</td>";
    file << "</tr>\n";

    file << "<tr>";
    file << "<td>Loan Deduction</td>";
    file << "<td>" << loanDeduction << "</td>";
    file << "</tr>\n";

    file << "<tr>";
    file << "<td>Other Deduction</td>";
    file << "<td>" << otherDeduction << "</td>";
    file << "</tr>\n";

    file << "<tr class=\"total-row\">";
    file << "<td>Total Deduction</td>";
    file << "<td>" << totalDeduction << "</td>";
    file << "</tr>\n";

    file << "</table>\n";
    file << "</div>\n";

    file << "</div>\n";

    /* Net Salary */
    file << "<div class=\"net-salary\">\n";

    file << "<span>Net Salary Payable</span>";

    file << "<span>"
         << fixed << setprecision(2)
         << netSalary
         << "</span>\n";

    file << "</div>\n";

    /* Payment Information */
    file << "<div class=\"payment-info\">\n";

    file << "<h3>Payment Information</h3>\n";

    file << "<p><strong>Salary Month:</strong> "
         << salaryMonth
         << "</p>\n";

    file << "<p><strong>Payment Date:</strong> "
         << paymentDate
         << "</p>\n";

    file << "</div>\n";

    /* Signatures */
    file << "<div class=\"signatures\">\n";

    /* Employee Signature */
    file << "<div class=\"signature\">\n";

    file << "<div class=\"signature-line\"></div>\n";

    file << "<strong>Employee Signature</strong>\n";

    file << "<p>"
         << employeeName
         << "</p>\n";

    file << "</div>\n";

    /* Authorized Signature */
    file << "<div class=\"signature\">\n";

    file << "<div class=\"signature-line\"></div>\n";

    file << "<strong>Authorized Signature</strong>\n";

    file << "<p>"
         << companyName
         << "</p>\n";

    file << "</div>\n";

    file << "</div>\n";

    /* Footer */
    file << "<div class=\"footer\">\n";

    file << "This salary slip is generated electronically by DocCreator.";

    file << "</div>\n";

    file << "</div>\n";
    file << "</body>\n";
    file << "</html>\n";

    file.close();
    cout << "\nSalay Slip generated successfully!\n";
    cout << "File Name : "<< filename<<endl;
    cout<<"File Location : "<< path2<<endl;
    cout << "Open it in Chrome, Edge, or Firefox.\n";

}
