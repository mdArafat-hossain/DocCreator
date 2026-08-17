#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "invoice.h"
#include "zutils.h"
#include "login.h"

using namespace std;
void invoice(string sname, string saddress, string sphone, string semail)
{
    cin.ignore();
    string filename, path2, ppath;
    string sellerName, sellerAddress, sellerPhone, sellerEmail;
    string customerName, customerAddress, customerPhone, customerEmail;
    string invoiceNumber, invoiceDate;

    int itemCount;
    double subtotal = 0;
    double taxRate, discount;
    double taxAmount, grandTotal;

    cout << "\n===== Invoice Generator (HTML) =====\n\n";

    sellerName = sname;
    sellerAddress = saddress;
    sellerPhone = sphone;
    sellerEmail = semail;

    if(sellerName.empty() || sellerAddress.empty()){
    cout << "Enter seller/business name: ";
    getline(cin, sellerName);

    cout << "Enter seller address: ";
    getline(cin, sellerAddress);

    cout << "Enter seller phone: ";
    getline(cin, sellerPhone);

    cout << "Enter seller email: ";
    getline(cin, sellerEmail);
    }

    // Customer information
    cout << "\nEnter customer name: ";
    getline(cin, customerName);

    cout << "Enter customer address: ";
    getline(cin, customerAddress);

    cout << "Enter customer phone: ";
    getline(cin, customerPhone);

    cout << "Enter customer email: ";
    getline(cin, customerEmail);


    // Invoice information
    cout << "\nEnter invoice number: ";
    getline(cin, invoiceNumber);

    cout << "Enter invoice date: ";
    getline(cin, invoiceDate);


    // Items
    cout << "\nEnter number of items: ";
    cin >> itemCount;

    stringstream ss(sellerName); // generate one word from multiple words (Arafat Hossain Rizve)== Arafat
    ss >> filename;

    while (cin.fail() || itemCount <= 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input! Enter a valid number of items: ";
        cin >> itemCount;
    }



    string itemName[100];
    int quantity[100];
    double price[100];
    double itemTotal[100];

    cin.ignore();

    for (int i = 0; i < itemCount; i++)
    {
        cout << "\nItem " << i + 1 << endl;

        cout << "Enter item/service name: ";
        getline(cin, itemName[i]);

        cout << "Enter quantity: ";
        cin >> quantity[i];

        while (cin.fail() || quantity[i] <= 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input! Enter a valid quantity: ";
            cin >> quantity[i];
        }

        cout << "Enter unit price: ";
        cin >> price[i];

        while (cin.fail() || price[i] <= 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input! Enter a valid price : ";
            cin >> price[i];
        }

        itemTotal[i] = quantity[i] * price[i];

        subtotal += itemTotal[i];

        cin.ignore();
    }


    // Tax and discount
    cout << "\nEnter tax/VAT percentage(without %): ";
    cin >> taxRate;
    while (cin.fail() || taxRate < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input! Enter a valid tax/VAT percentage: ";
        cin >> taxRate;
    }

    cout << "Enter discount amount: ";
    cin >> discount;
    while (cin.fail() || discount <= 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input! Enter a valid discount: ";
        cin >> discount;
    }


    taxAmount = subtotal * taxRate / 100;

    grandTotal = subtotal + taxAmount - discount;
    cin.ignore();

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
    file << "<title>Invoice - " << invoiceNumber << "</title>\n";

    file << "<style>\n";

    file << "body {";
    file << "font-family: Arial, sans-serif;";
    file << "background: #f4f6f8;";
    file << "margin: 0;";
    file << "padding: 40px;";
    file << "color: #333;";
    file << "}\n";

    file << ".invoice {";
    file << "max-width: 900px;";
    file << "margin: auto;";
    file << "background: white;";
    file << "padding: 40px;";
    file << "box-shadow: 0 0 15px rgba(0,0,0,0.1);";
    file << "}\n";

    file << ".header {";
    file << "display: flex;";
    file << "justify-content: space-between;";
    file << "border-bottom: 3px solid #333;";
    file << "padding-bottom: 20px;";
    file << "}\n";

    file << ".company h1 {";
    file << "margin: 0;";
    file << "font-size: 28px;";
    file << "}\n";

    file << ".invoice-title {";
    file << "text-align: right;";
    file << "}\n";

    file << ".invoice-title h2 {";
    file << "margin: 0;";
    file << "font-size: 32px;";
    file << "}\n";

    file << ".info {";
    file << "display: flex;";
    file << "justify-content: space-between;";
    file << "margin-top: 30px;";
    file << "margin-bottom: 30px;";
    file << "}\n";

    file << ".box {";
    file << "width: 45%;";
    file << "}\n";

    file << ".box h3 {";
    file << "margin-bottom: 8px;";
    file << "}\n";

    file << "table {";
    file << "width: 100%;";
    file << "border-collapse: collapse;";
    file << "margin-top: 20px;";
    file << "}\n";

    file << "th {";
    file << "background: #333;";
    file << "color: white;";
    file << "padding: 12px;";
    file << "text-align: left;";
    file << "}\n";

    file << "td {";
    file << "padding: 12px;";
    file << "border-bottom: 1px solid #ddd;";
    file << "}\n";

    file << ".number {";
    file << "text-align: right;";
    file << "}\n";

    file << ".totals {";
    file << "width: 350px;";
    file << "margin-left: auto;";
    file << "margin-top: 30px;";
    file << "}\n";

    file << ".total-row {";
    file << "display: flex;";
    file << "justify-content: space-between;";
    file << "padding: 8px;";
    file << "}\n";

    file << ".grand-total {";
    file << "font-size: 20px;";
    file << "font-weight: bold;";
    file << "border-top: 2px solid #333;";
    file << "padding-top: 12px;";
    file << "}\n";

    file << ".footer {";
    file << "margin-top: 50px;";
    file << "text-align: center;";
    file << "border-top: 1px solid #ddd;";
    file << "padding-top: 20px;";
    file << "}\n";

    file << "</style>\n";

    file << "</head>\n";


    // ================= BODY =================

    file << "<body>\n";

    file << "<div class='invoice'>\n";


    // Header
    file << "<div class='header'>\n";

    file << "<div class='company'>\n";

    file << "<h1>" << sellerName << "</h1>\n";
    file << "<p>";
    file << sellerAddress << "<br>";
    file << sellerPhone << "<br>";
    file << sellerEmail;
    file << "</p>\n";

    file << "</div>\n";


    file << "<div class='invoice-title'>\n";

    file << "<h2>INVOICE</h2>\n";
    file << "<p>";
    file << "<strong>Invoice #:</strong> "
         << invoiceNumber << "<br>";

    file << "<strong>Date:</strong> "
         << invoiceDate;

    file << "</p>\n";

    file << "</div>\n";

    file << "</div>\n";


    // Customer information
    file << "<div class='info'>\n";

    file << "<div class='box'>\n";
    file << "<h3>Bill To:</h3>\n";

    file << customerName << "<br>";
    file << customerAddress << "<br>";
    file << customerPhone << "<br>";
    file << customerEmail;

    file << "</div>\n";

    file << "</div>\n";


    // Items table
    file << "<table>\n";

    file << "<tr>";
    file << "<th>#</th>";
    file << "<th>Item / Service</th>";
    file << "<th>Quantity</th>";
    file << "<th>Unit Price</th>";
    file << "<th>Total</th>";
    file << "</tr>\n";


    for (int i = 0; i < itemCount; i++)
    {
        file << "<tr>";

        file << "<td>" << i + 1 << "</td>";

        file << "<td>" << itemName[i] << "</td>";

        file << "<td>" << quantity[i] << "</td>";

        file << "<td>"
             << fixed << setprecision(2)
             << price[i] << " tk</td>";

        file << "<td>"
             << fixed << setprecision(2)
             << itemTotal[i] << " tk</td>";

        file << "</tr>\n";
    }

    file << "</table>\n";


    // Totals
    file << "<div class='totals'>\n";

    file << "<div class='total-row'>";
    file << "<span>Subtotal:</span>";
    file << "<span>" << fixed << setprecision(2)
         << subtotal << " tk</span>";
    file << "</div>\n";


    file << "<div class='total-row'>";
    file << "<span>Tax/VAT (" << taxRate << "%):</span>";
    file << "<span>" << fixed << setprecision(2)
         << taxAmount << " tk</span>";
    file << "</div>\n";


    file << "<div class='total-row'>";
    file << "<span>Discount:</span>";
    file << "<span>" << fixed << setprecision(2)
         << discount << " tk</span>";
    file << "</div>\n";


    file << "<div class='total-row grand-total'>";
    file << "<span>Grand Total:</span>";
    file << "<span>" << fixed << setprecision(2)
         << grandTotal << " tk</span>";
    file << "</div>\n";

    file << "</div>\n";


    // Footer
    file << "<div class='footer'>\n";

    file << "<p>Thank you for your business!</p>\n";

    file << "</div>\n";


    file << "</div>\n";

    file << "</body>\n";
    file << "</html>\n";


    file.close();


    cout << "\nInvoice generated successfully!\n";
    cout << "File Name : "<< filename<<endl;
    cout<<"File Location : "<< path2<<endl;
    cout << "Open it in Chrome, Edge, or Firefox.\n";
}
