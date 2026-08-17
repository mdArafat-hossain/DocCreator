#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include "zutils.h"
#include "login.h"
#include "Receipt.h"
using namespace std;

void receipt(string sname)
{
    cin.ignore();
    string filename,ppath,path2;
    string businessName, tagline, receiptNo, cashier;
    string paymentMethod, approvalNumber;

    string itemCode[100];
    string itemName[100];

    int quantity[100];
    double price[100], itemTotal[100];

    int itemCount;

    double subtotal = 0;
    double discount;

    cout << "\n===== Receipt Generator (HTML) =====\n\n";

    businessName = sname;
    if(businessName.empty())
    {
        cout << "Enter Business Name: ";
    getline(cin, businessName);
    }


    cout << "Enter Business Tagline (Press Enter to skip): ";
    getline(cin, tagline);

    cout << "Enter Receipt Number: ";
    getline(cin, receiptNo);

    cout << "Enter Cashier Name / ID: ";
    getline(cin, cashier);

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

    // Item input
    for (int i = 0; i < itemCount; i++)
    {
        cout << "\n========== ITEM " << i + 1 << " ==========\n";

        cout << "Enter Item Code: ";
        getline(cin, itemCode[i]);

        cout << "Enter Item Name: ";
        getline(cin, itemName[i]);

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
        cin >> price[i];

        while (cin.fail() || price[i] < 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input! Enter a valid price: ";
            cin >> price[i];
        }

        itemTotal[i] = quantity[i] * price[i];

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

    cin.ignore(1000, '\n');

    // Payment information
    cout << "Enter Payment Method: ";
    getline(cin, paymentMethod);

    cout << "Enter Approval / Transaction Number: ";
    getline(cin, approvalNumber);

    double totalAmount = subtotal - discount;

    // Get current date and time
    time_t now = time(0);
    tm *localTime = localtime(&now);

    char dateTime[30];

    strftime(dateTime, sizeof(dateTime),
             "%d/%m/%Y - %I:%M %p", localTime);

    cout<<"\nEnter file location : ";
    getline(cin,ppath);
    stringstream ss(businessName); // generate one word from multiple words (Arafat Hossain Rizve)== Arafat
    ss >> filename;

    string path = file_path(ppath);
    string time = Date_Time();
    int l = path.length();
    if(path[l-1]=='\\')
    {
        path2 = path + filename + "(Receipt)" + time + ".html"; //E:\\arafat(Resume)_2026-07-28_1237.html
    }
    else
    {
        path2 = path + "\\\\" + filename + "(Receipt)" + time + ".html"; //E:\\DocCreator\\arafat(Resume)_2026-07-28_1237.html
    }


    ofstream file(path2);

    // HTML
    file << "<!DOCTYPE html>\n";
    file << "<html>\n";
    file << "<head>\n";

    file << "<meta charset='UTF-8'>\n";
    file << "<meta name='viewport' content='width=device-width, initial-scale=1.0'>\n";

    file << "<title>Receipt - " << receiptNo << "</title>\n";

    file << "<style>\n";

    file << "* {\n";
    file << "    box-sizing: border-box;\n";
    file << "}\n";

    file << "body {\n";
    file << "    margin: 0;\n";
    file << "    padding: 30px 10px;\n";
    file << "    background: #eeeeee;\n";
    file << "    font-family: 'Courier New', monospace;\n";
    file << "    color: #555555;\n";
    file << "}\n";

    file << ".receipt {\n";
    file << "    width: 520px;\n";
    file << "    max-width: 100%;\n";
    file << "    margin: auto;\n";
    file << "    background: #ffffff;\n";
    file << "    padding: 40px 30px;\n";
    file << "    box-shadow: 0 0 15px rgba(0,0,0,0.10);\n";
    file << "}\n";

    file << ".business {\n";
    file << "    text-align: center;\n";
    file << "    margin-bottom: 35px;\n";
    file << "}\n";

    file << ".business h1 {\n";
    file << "    margin: 0;\n";
    file << "    font-size: 32px;\n";
    file << "    font-weight: bold;\n";
    file << "    letter-spacing: 2px;\n";
    file << "    color: #555555;\n";
    file << "}\n";

    file << ".tagline {\n";
    file << "    margin-top: 8px;\n";
    file << "    font-size: 17px;\n";
    file << "    letter-spacing: 2px;\n";
    file << "}\n";

    file << ".receipt-title {\n";
    file << "    text-align: center;\n";
    file << "    font-size: 28px;\n";
    file << "    font-weight: bold;\n";
    file << "    margin-bottom: 35px;\n";
    file << "    letter-spacing: 2px;\n";
    file << "}\n";

    file << ".info {\n";
    file << "    display: flex;\n";
    file << "    justify-content: space-between;\n";
    file << "    font-size: 16px;\n";
    file << "    margin-bottom: 25px;\n";
    file << "}\n";

    file << ".separator {\n";
    file << "    border-top: 2px solid #999999;\n";
    file << "    margin: 15px 0;\n";
    file << "}\n";

    file << ".dashed {\n";
    file << "    border-top: 3px dashed #777777;\n";
    file << "    margin: 15px 0;\n";
    file << "}\n";

    file << ".items-header,\n";
    file << ".item {\n";
    file << "    display: grid;\n";
    file << "    grid-template-columns: 70px 45px 1fr 90px;\n";
    file << "    column-gap: 5px;\n";
    file << "    align-items: start;\n";
    file << "}\n";

    file << ".items-header {\n";
    file << "    font-size: 15px;\n";
    file << "    margin-bottom: 12px;\n";
    file << "}\n";

    file << ".item {\n";
    file << "    font-size: 15px;\n";
    file << "    line-height: 1.6;\n";
    file << "    margin: 5px 0;\n";
    file << "}\n";

    file << ".right {\n";
    file << "    text-align: right;\n";
    file << "}\n";

    file << ".summary-row {\n";
    file << "    display: flex;\n";
    file << "    justify-content: space-between;\n";
    file << "    font-size: 17px;\n";
    file << "    margin: 12px 0;\n";
    file << "}\n";

    file << ".total {\n";
    file << "    display: flex;\n";
    file << "    justify-content: space-between;\n";
    file << "    font-size: 21px;\n";
    file << "    font-weight: bold;\n";
    file << "    margin: 18px 0;\n";
    file << "}\n";

    file << ".payment {\n";
    file << "    margin-top: 35px;\n";
    file << "    font-size: 16px;\n";
    file << "}\n";

    file << ".payment-row {\n";
    file << "    display: flex;\n";
    file << "    justify-content: space-between;\n";
    file << "    margin: 12px 0;\n";
    file << "}\n";

    file << ".footer {\n";
    file << "    text-align: center;\n";
    file << "    border-top: 1px solid #888888;\n";
    file << "    margin-top: 40px;\n";
    file << "    padding-top: 35px;\n";
    file << "}\n";

    file << ".thank-you {\n";
    file << "    font-size: 19px;\n";
    file << "    font-weight: bold;\n";
    file << "    letter-spacing: 1px;\n";
    file << "    margin-bottom: 30px;\n";
    file << "}\n";

    // CSS barcode
    file << ".barcode {\n";
    file << "    height: 55px;\n";
    file << "    width: 280px;\n";
    file << "    margin: auto;\n";
    file << "    background: repeating-linear-gradient(\n";
    file << "        90deg,\n";
    file << "        #555555 0px,\n";
    file << "        #555555 4px,\n";
    file << "        white 4px,\n";
    file << "        white 7px,\n";
    file << "        #555555 7px,\n";
    file << "        #555555 9px,\n";
    file << "        white 9px,\n";
    file << "        white 13px\n";
    file << "    );\n";
    file << "}\n";

    file << ".receipt-number {\n";
    file << "    text-align: center;\n";
    file << "    margin-top: 10px;\n";
    file << "    font-size: 13px;\n";
    file << "}\n";

    file << "@media print {\n";
    file << "    body {\n";
    file << "        background: white;\n";
    file << "        padding: 0;\n";
    file << "    }\n";

    file << "    .receipt {\n";
    file << "        width: 100%;\n";
    file << "        box-shadow: none;\n";
    file << "    }\n";
    file << "}\n";

    file << "</style>\n";

    file << "</head>\n";

    file << "<body>\n";

    file << "<div class='receipt'>\n";

    // Business name
    file << "<div class='business'>\n";

    file << "<h1>" << businessName << "</h1>\n";

    if (!tagline.empty())
    {
        file << "<div class='tagline'>" << tagline << "</div>\n";
    }

    file << "</div>\n";

    // Receipt title
    file << "<div class='receipt-title'>\n";
    file << "*** RECEIPT ***\n";
    file << "</div>\n";

    // Cashier and date
    file << "<div class='info'>\n";

    file << "<span>CASHIER: " << cashier << "</span>\n";

    file << "<span>" << dateTime << "</span>\n";

    file << "</div>\n";

    file << "<div class='separator'></div>\n";

    // Table header
    file << "<div class='items-header'>\n";

    file << "<div>ITEM</div>\n";
    file << "<div>QTY</div>\n";
    file << "<div>DESCRIPTION</div>\n";
    file << "<div class='right'>COST</div>\n";

    file << "</div>\n";

    file << "<div class='separator'></div>\n";

    file << fixed << setprecision(2);

    // Items
    for (int i = 0; i < itemCount; i++)
    {
        file << "<div class='item'>\n";

        file << "<div>" << itemCode[i] << "</div>\n";

        file << "<div>" << quantity[i] << "</div>\n";

        file << "<div>" << itemName[i]
             << " @" << price[i] << "tk</div>\n";

        file << "<div class='right'>"
             << itemTotal[i] << "tk</div>\n";

        file << "</div>\n";
    }

    // Summary separator
    file << "<div class='dashed'></div>\n";

    // Subtotal
    file << "<div class='summary-row'>\n";

    file << "<span>SUBTOTAL</span>\n";

    file << "<span>" << subtotal << " tk</span>\n";

    file << "</div>\n";

    // Discount
    if (discount > 0)
    {
        file << "<div class='summary-row'>\n";

        file << "<span>DISCOUNT</span>\n";

        file << "<span>" << discount << " tk</span>\n";

        file << "</div>\n";
    }

    file << "<div class='dashed'></div>\n";

    // Total
    file << "<div class='total'>\n";

    file << "<span>TOTAL AMOUNT</span>\n";

    file << "<span>" << totalAmount << " tk</span>\n";

    file << "</div>\n";

    // Payment details
    file << "<div class='payment'>\n";

    file << "<div class='payment-row'>\n";
    file << "<span>PAYMENT METHOD</span>\n";
    file << "<span>" << paymentMethod << "</span>\n";
    file << "</div>\n";

    file << "<div class='payment-row'>\n";
    file << "<span>APPROVAL NUMBER</span>\n";
    file << "<span>#" << approvalNumber << "</span>\n";
    file << "</div>\n";

    file << "</div>\n";

    // Footer
    file << "<div class='footer'>\n";

    file << "<div class='thank-you'>\n";
    file << "THANK YOU FOR SHOPPING!\n";
    file << "</div>\n";

    file << "<div class='barcode'></div>\n";

    file << "<div class='receipt-number'>\n";
    file << "RECEIPT #" << receiptNo << "\n";
    file << "</div>\n";

    file << "</div>\n";

    file << "</div>\n";

    file << "</body>\n";
    file << "</html>\n";

    file.close();

    cout << "\nReceipt generated successfully!\n";
    cout << "File Name : "<< filename<<endl;
    cout<<"File Location : "<< path2<<endl;
    cout << "Open it in Chrome, Edge, or Firefox.\n";

}
