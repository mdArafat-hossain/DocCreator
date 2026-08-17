#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include<sstream>
#include "zutils.h"
#include "login.h"
#include "Purchase_order.h"
using namespace std;

void purchase_order(string sname, string saddress)
{
    cin.ignore();
    string filename,ppath,path2;
    string poNumber, buyerName, buyerAddress, supplierName, supplierAddress;
    string deliveryDate, deliveryAddress, terms, authorizedPerson;

    string itemName[100], description[100];

    int quantity[100];
    double unitPrice[100], itemTotal[100];

    int itemCount;

    double subtotal = 0;
    double discount, taxRate, taxAmount, grandTotal;

    cout << "\n===== Purchase Order Generator (HTML) =====\n\n";

    // Basic information
    cout << "Enter Purchase Order Number: ";
    getline(cin, poNumber);

    if(sname.empty() || saddress.empty()){
    cout << "Enter Buyer / Company Name: ";
    getline(cin, buyerName);

    cout << "Enter Buyer Address: ";
    getline(cin, buyerAddress);
    }

    cout << "Enter Supplier / Vendor Name: ";
    getline(cin, supplierName);

    cout << "Enter Supplier Address: ";
    getline(cin, supplierAddress);

    // Delivery information
    cout << "\nEnter Requested Delivery Date: ";
    getline(cin, deliveryDate);

    cout << "Enter Delivery Address: ";
    getline(cin, deliveryAddress);

    // Number of items
    cout << "\nEnter Number of Items: ";
    cin >> itemCount;

    while (cin.fail() || itemCount <= 0 || itemCount > 100)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input! Enter number of items (1-100): ";
        cin >> itemCount;
    }

    cin.ignore(1000, '\n');

    // Item information
    for (int i = 0; i < itemCount; i++)
    {
        cout << "\n========== ITEM " << i + 1 << " ==========\n";

        cout << "Enter Item Name: ";
        getline(cin, itemName[i]);

        cout << "Enter Description: ";
        getline(cin, description[i]);

        cout << "Enter Quantity: ";
        cin >> quantity[i];

        while (cin.fail() || quantity[i] <= 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input! Enter a valid quantity: ";
            cin >> quantity[i];
        }

        cout << "Enter Unit Price: ";
        cin >> unitPrice[i];

        while (cin.fail() || unitPrice[i] < 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input! Enter a valid price: ";
            cin >> unitPrice[i];
        }

        itemTotal[i] = quantity[i] * unitPrice[i];

        subtotal += itemTotal[i];

        cin.ignore(1000, '\n');
    }

    // Discount
    cout << "\nEnter Discount Amount: ";
    cin >> discount;

    while (cin.fail() || discount < 0 || discount > subtotal)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input! Enter a valid discount: ";
        cin >> discount;
    }

    // Tax
    cout << "Enter Tax Rate (%): ";
    cin >> taxRate;

    while (cin.fail() || taxRate < 0 || taxRate > 100)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input! Enter a valid tax rate: ";
        cin >> taxRate;
    }

    cin.ignore(1000, '\n');

    // Terms and authorization
    cout << "\nEnter Terms / Notes (optional): ";
    getline(cin, terms);

    cout << "Enter Authorized Person: ";
    getline(cin, authorizedPerson);

    // Calculations
    double amountAfterDiscount = subtotal - discount;

    taxAmount = amountAfterDiscount * taxRate / 100;

    grandTotal = amountAfterDiscount + taxAmount;

    // Get current date
    time_t now = time(0);
    tm *localTime = localtime(&now);

    char currentDate[30];

    strftime(currentDate, sizeof(currentDate),
             "%d %B %Y", localTime);

    cout<<"\nEnter file location : ";
    getline(cin,ppath);

    stringstream ss(buyerName); // generate one word from multiple words (Arafat Hossain Rizve)== Arafat
    ss >> filename;

    string path = file_path(ppath);
    string time = Date_Time();
    int l = path.length();
    if(path[l-1]=='\\')
    {
        path2 = path + filename + "(Resume)" + time + ".html"; //E:\\arafat(Resume)_2026-07-28_1237.html
    }
    else
    {
        path2 = path + "\\\\" + filename + "(Resume)" + time + ".html"; //E:\\DocCreator\\arafat(Resume)_2026-07-28_1237.html
    }

    ofstream file(path2);

    file << "<!DOCTYPE html>\n";
    file << "<html>\n";
    file << "<head>\n";

    file << "<meta charset='UTF-8'>\n";
    file << "<meta name='viewport' content='width=device-width, initial-scale=1.0'>\n";

    file << "<title>Purchase Order - " << poNumber << "</title>\n";

    file << "<style>\n";

    file << "* { box-sizing: border-box; }\n";

    file << "body {\n";
    file << "    margin: 0;\n";
    file << "    padding: 40px 20px;\n";
    file << "    background: #eef1f4;\n";
    file << "    font-family: Arial, Helvetica, sans-serif;\n";
    file << "    color: #252525;\n";
    file << "}\n";

    file << ".page {\n";
    file << "    width: 850px;\n";
    file << "    max-width: 100%;\n";
    file << "    margin: auto;\n";
    file << "    background: white;\n";
    file << "    padding: 50px;\n";
    file << "    box-shadow: 0 5px 20px rgba(0,0,0,0.08);\n";
    file << "}\n";

    file << ".top {\n";
    file << "    display: flex;\n";
    file << "    justify-content: space-between;\n";
    file << "    align-items: flex-start;\n";
    file << "    padding-bottom: 25px;\n";
    file << "    border-bottom: 3px solid #222;\n";
    file << "}\n";

    file << ".company h1 {\n";
    file << "    margin: 0 0 8px 0;\n";
    file << "    font-size: 28px;\n";
    file << "}\n";

    file << ".company p {\n";
    file << "    margin: 4px 0;\n";
    file << "    color: #666;\n";
    file << "}\n";

    file << ".po-title {\n";
    file << "    text-align: right;\n";
    file << "}\n";

    file << ".po-title h2 {\n";
    file << "    margin: 0;\n";
    file << "    font-size: 32px;\n";
    file << "    letter-spacing: 2px;\n";
    file << "}\n";

    file << ".po-title p {\n";
    file << "    margin: 7px 0;\n";
    file << "    color: #666;\n";
    file << "}\n";

    file << ".parties {\n";
    file << "    display: grid;\n";
    file << "    grid-template-columns: 1fr 1fr;\n";
    file << "    gap: 25px;\n";
    file << "    margin: 30px 0;\n";
    file << "}\n";

    file << ".party {\n";
    file << "    border: 1px solid #d5d5d5;\n";
    file << "    padding: 20px;\n";
    file << "}\n";

    file << ".party-title {\n";
    file << "    font-size: 12px;\n";
    file << "    font-weight: bold;\n";
    file << "    color: #777;\n";
    file << "    text-transform: uppercase;\n";
    file << "    letter-spacing: 1px;\n";
    file << "    margin-bottom: 10px;\n";
    file << "}\n";

    file << ".party h3 {\n";
    file << "    margin: 0 0 7px 0;\n";
    file << "    font-size: 18px;\n";
    file << "}\n";

    file << ".party p {\n";
    file << "    margin: 4px 0;\n";
    file << "    color: #666;\n";
    file << "    line-height: 1.5;\n";
    file << "}\n";

    file << ".delivery {\n";
    file << "    display: grid;\n";
    file << "    grid-template-columns: 1fr 1fr;\n";
    file << "    gap: 20px;\n";
    file << "    margin-bottom: 30px;\n";
    file << "}\n";

    file << ".delivery-box {\n";
    file << "    background: #f5f6f7;\n";
    file << "    padding: 15px;\n";
    file << "}\n";

    file << ".delivery-box strong {\n";
    file << "    display: block;\n";
    file << "    font-size: 11px;\n";
    file << "    text-transform: uppercase;\n";
    file << "    color: #777;\n";
    file << "    margin-bottom: 6px;\n";
    file << "}\n";

    file << "table {\n";
    file << "    width: 100%;\n";
    file << "    border-collapse: collapse;\n";
    file << "    margin-top: 10px;\n";
    file << "}\n";

    file << "th {\n";
    file << "    background: #222;\n";
    file << "    color: white;\n";
    file << "    padding: 13px 10px;\n";
    file << "    text-align: left;\n";
    file << "    font-size: 13px;\n";
    file << "}\n";

    file << "td {\n";
    file << "    padding: 14px 10px;\n";
    file << "    border-bottom: 1px solid #ddd;\n";
    file << "    vertical-align: top;\n";
    file << "}\n";

    file << ".number {\n";
    file << "    width: 45px;\n";
    file << "}\n";

    file << ".right {\n";
    file << "    text-align: right;\n";
    file << "}\n";

    file << ".bottom {\n";
    file << "    display: flex;\n";
    file << "    justify-content: space-between;\n";
    file << "    margin-top: 30px;\n";
    file << "    gap: 50px;\n";
    file << "}\n";

    file << ".terms {\n";
    file << "    flex: 1;\n";
    file << "}\n";

    file << ".terms h4 {\n";
    file << "    margin: 0 0 10px 0;\n";
    file << "    font-size: 13px;\n";
    file << "    text-transform: uppercase;\n";
    file << "}\n";

    file << ".terms p {\n";
    file << "    color: #666;\n";
    file << "    line-height: 1.5;\n";
    file << "    font-size: 13px;\n";
    file << "}\n";

    file << ".totals {\n";
    file << "    width: 300px;\n";
    file << "}\n";

    file << ".total-row {\n";
    file << "    display: flex;\n";
    file << "    justify-content: space-between;\n";
    file << "    padding: 9px 0;\n";
    file << "    border-bottom: 1px solid #ddd;\n";
    file << "}\n";

    file << ".grand-total {\n";
    file << "    font-size: 20px;\n";
    file << "    font-weight: bold;\n";
    file << "    border-top: 2px solid #222;\n";
    file << "    border-bottom: none;\n";
    file << "    margin-top: 5px;\n";
    file << "    padding-top: 15px;\n";
    file << "}\n";

    file << ".signature {\n";
    file << "    margin-top: 60px;\n";
    file << "    width: 250px;\n";
    file << "    margin-left: auto;\n";
    file << "    text-align: center;\n";
    file << "}\n";

    file << ".signature-line {\n";
    file << "    border-top: 1px solid #333;\n";
    file << "    padding-top: 8px;\n";
    file << "    font-size: 13px;\n";
    file << "}\n";

    file << ".footer {\n";
    file << "    text-align: center;\n";
    file << "    margin-top: 45px;\n";
    file << "    padding-top: 20px;\n";
    file << "    border-top: 1px solid #ddd;\n";
    file << "    color: #888;\n";
    file << "    font-size: 12px;\n";
    file << "}\n";

    file << "@media print {\n";
    file << "    body { background: white; padding: 0; }\n";
    file << "    .page { width: 100%; box-shadow: none; }\n";
    file << "}\n";

    file << "</style>\n";
    file << "</head>\n";

    file << "<body>\n";
    file << "<div class='page'>\n";

// Header
    file << "<div class='top'>\n";

    file << "<div class='company'>\n";
    file << "<h1>" << buyerName << "</h1>\n";
    file << "<p>" << buyerAddress << "</p>\n";
    file << "</div>\n";

    file << "<div class='po-title'>\n";
    file << "<h2>PURCHASE ORDER</h2>\n";
    file << "<p><strong>PO No:</strong> " << poNumber << "</p>\n";
    file << "<p><strong>Date:</strong> " << currentDate << "</p>\n";
    file << "</div>\n";

    file << "</div>\n";

// Buyer and supplier
    file << "<div class='parties'>\n";

    file << "<div class='party'>\n";
    file << "<div class='party-title'>Buyer</div>\n";
    file << "<h3>" << buyerName << "</h3>\n";
    file << "<p>" << buyerAddress << "</p>\n";
    file << "</div>\n";

    file << "<div class='party'>\n";
    file << "<div class='party-title'>Supplier / Vendor</div>\n";
    file << "<h3>" << supplierName << "</h3>\n";
    file << "<p>" << supplierAddress << "</p>\n";
    file << "</div>\n";

    file << "</div>\n";

// Delivery
    file << "<div class='delivery'>\n";

    file << "<div class='delivery-box'>\n";
    file << "<strong>Requested Delivery Date</strong>\n";
    file << deliveryDate << "\n";
    file << "</div>\n";

    file << "<div class='delivery-box'>\n";
    file << "<strong>Delivery Address</strong>\n";
    file << deliveryAddress << "\n";
    file << "</div>\n";

    file << "</div>\n";

// Items table
    file << "<table>\n";

    file << "<tr>\n";
    file << "<th class='number'>#</th>\n";
    file << "<th>Item</th>\n";
    file << "<th class='right'>Qty</th>\n";
    file << "<th class='right'>Unit Price</th>\n";
    file << "<th class='right'>Total</th>\n";
    file << "</tr>\n";

    file << fixed << setprecision(2);

    for (int i = 0; i < itemCount; i++)
    {
        file << "<tr>\n";

        file << "<td>" << i + 1 << "</td>\n";

        file << "<td><strong>"
             << itemName[i]
             << "</strong></td>\n";

        file << "<td class='right'>"
             << quantity[i]
             << "</td>\n";

        file << "<td class='right'>"
             << unitPrice[i]
             << "</td>\n";

        file << "<td class='right'>"
             << itemTotal[i]
             << "</td>\n";

        file << "</tr>\n";
    }

    file << "</table>\n";

// Bottom section
    file << "<div class='bottom'>\n";

// Terms
    file << "<div class='terms'>\n";

    if (!terms.empty())
    {
        file << "<h4>Terms & Notes</h4>\n";
        file << "<p>" << terms << "</p>\n";
    }

    file << "</div>\n";

// Totals
    file << "<div class='totals'>\n";

    file << "<div class='total-row'>\n";
    file << "<span>Subtotal</span>\n";
    file << "<span>" << subtotal << "</span>\n";
    file << "</div>\n";

    file << "<div class='total-row'>\n";
    file << "<span>Discount</span>\n";
    file << "<span>-" << discount << "</span>\n";
    file << "</div>\n";

    file << "<div class='total-row'>\n";
    file << "<span>Tax (" << taxRate << "%)</span>\n";
    file << "<span>" << taxAmount << "</span>\n";
    file << "</div>\n";

    file << "<div class='total-row grand-total'>\n";
    file << "<span>Grand Total</span>\n";
    file << "<span>" << grandTotal << "</span>\n";
    file << "</div>\n";

    file << "</div>\n";

    file << "</div>\n";

// Signature
    file << "<div class='signature'>\n";

    file << "<div class='signature-line'>\n";
    file << authorizedPerson << "<br>";
    file << "Authorized By\n";
    file << "</div>\n";

    file << "</div>\n";

// Footer
    file << "<div class='footer'>\n";
    file << "This purchase order is generated by DocCreator.\n";
    file << "</div>\n";

    file << "</div>\n";
    file << "</body>\n";
    file << "</html>\n";

    file.close();

    cout << "\nPurchase Order Document generated successfully!\n";
    cout << "File Name : "<< filename<<endl;
    cout<<"File Location : "<< path2<<endl;
    cout << "Open it in Chrome, Edge, or Firefox.\n";
}


