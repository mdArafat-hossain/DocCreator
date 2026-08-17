#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#include "zutils.h"
#include "login.h"
#include "Recommendation.h"

using namespace std;

void recommendation()
{
    cin.ignore();
    string filename,ppath,path2;
    string recommenderName, recommenderPosition, organization, organizationAddress, recommenderEmail, recommenderPhone;
    string candidateName, candidateField, relationship;
    string sector, purpose, strengths, achievements, recommendationStatement;
    string recipientName, recipientPosition, recipientOrganization;
    string date;

    cout << "\n===== Resume Generator (HTML) =====\n\n";

    cout << "Recommender Information\n";

    cout << "Recommender Full Name: ";
    getline(cin, recommenderName);

    cout << "Position / Title: ";
    getline(cin, recommenderPosition);

    cout << "Organization / Institution: ";
    getline(cin, organization);

    cout << "Organization Address: ";
    getline(cin, organizationAddress);

    cout << "Email Address: ";
    getline(cin, recommenderEmail);

    cout << "Phone Number: ";
    getline(cin, recommenderPhone);

    cout << "\nCandidate Information\n";
    cout << "Candidate Full Name: ";
    getline(cin, candidateName);

    cout << "Candidate Position / Field: ";
    getline(cin, candidateField);

    cout << "Relationship with Candidate: ";
    getline(cin, relationship);

    cout << "\nRecommendation Information\n";
    cout << "Recommendation Sector / Purpose: ";
    getline(cin, sector);

    cout << "Purpose of Recommendation: ";
    getline(cin, purpose);

    cout << "Candidate's Key Strengths: ";
    getline(cin, strengths);

    cout << "Achievements / Notable Qualities: ";
    getline(cin, achievements);

    cout << "Additional Recommendation Statement: ";
    getline(cin, recommendationStatement);

    cout << "Recipient Information\n";
    cout << "\nRecipient Name (optional): ";
    getline(cin, recipientName);

    cout << "Recipient Position / Title (optional): ";
    getline(cin, recipientPosition);

    cout << "Recipient Organization (optional): ";
    getline(cin, recipientOrganization);

    cout << "\nLetter Information\n";
    cout << "Date: ";
    getline(cin, date);

    if (recipientName.empty())
    {
        recipientName = "To Whom It May Concern";
    }

    if (relationship.empty())
    {
        relationship = "professional acquaintance";
    }

    if (sector.empty())
    {
        sector = "Professional / Academic Opportunity";
    }

    if (purpose.empty())
    {
        purpose = "the opportunity for which this recommendation is being submitted";
    }

    if (strengths.empty())
    {
        strengths = "professionalism, dedication, communication, responsibility, and willingness to learn";
    }

    if (achievements.empty())
    {
        achievements = "consistent commitment to responsibilities and professional development";
    }

    if (recommendationStatement.empty())
    {
        recommendationStatement =
            "I am confident that the candidate will continue to demonstrate "
            "professionalism, dedication, integrity, and a strong commitment "
            "to achieving positive results.";
    }

    if (date.empty())
    {
        date = "Date: __________________";
    }

    cout<<"\nEnter file location : ";
    getline(cin,ppath);

    stringstream ss(candidateName); // generate one word from multiple words (Arafat Hossain Rizve)== Arafat
    ss >> filename;

    string path = file_path(ppath);
    string time = Date_Time();
    int l = path.length();
    if(path[l-1]=='\\')
    {
        path2 = path + filename + "(Recommendation)" + time + ".html"; //E:\\arafat(Resume)_2026-07-28_1237.html
    }
    else
    {
        path2 = path + "\\\\" + filename + "(Recommendation)" + time + ".html"; //E:\\DocCreator\\arafat(Resume)_2026-07-28_1237.html
    }


    ofstream file(path2);

    file << "<!DOCTYPE html>\n";
    file << "<html lang=\"en\">\n";

    file << "<head>\n";

    file << "<meta charset=\"UTF-8\">\n";
    file << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";

    file << "<title>Recommendation Letter - "
         << candidateName
         << "</title>\n";

    file << "<style>\n";

    file << "* {\n";
    file << "    box-sizing: border-box;\n";
    file << "}\n";

    file << "body {\n";
    file << "    margin: 0;\n";
    file << "    padding: 40px 20px;\n";
    file << "    background: #e8edf3;\n";
    file << "    color: #202733;\n";
    file << "    font-family: Georgia, 'Times New Roman', serif;\n";
    file << "}\n";

    file << ".page {\n";
    file << "    max-width: 850px;\n";
    file << "    min-height: 1100px;\n";
    file << "    margin: auto;\n";
    file << "    background: #ffffff;\n";
    file << "    padding: 65px 70px;\n";
    file << "    box-shadow: 0 10px 35px rgba(0,0,0,0.12);\n";
    file << "}\n";

    file << ".letterhead {\n";
    file << "    border-bottom: 3px solid #243b53;\n";
    file << "    padding-bottom: 22px;\n";
    file << "    margin-bottom: 28px;\n";
    file << "}\n";

    file << ".name {\n";
    file << "    font-family: Arial, sans-serif;\n";
    file << "    font-size: 27px;\n";
    file << "    font-weight: bold;\n";
    file << "    color: #243b53;\n";
    file << "    letter-spacing: 0.4px;\n";
    file << "}\n";

    file << ".position {\n";
    file << "    margin-top: 6px;\n";
    file << "    font-family: Arial, sans-serif;\n";
    file << "    font-size: 14px;\n";
    file << "    color: #52606d;\n";
    file << "}\n";

    file << ".organization {\n";
    file << "    margin-top: 3px;\n";
    file << "    font-family: Arial, sans-serif;\n";
    file << "    font-size: 15px;\n";
    file << "    font-weight: bold;\n";
    file << "    color: #334e68;\n";
    file << "}\n";

    file << ".address {\n";
    file << "    margin-top: 4px;\n";
    file << "    font-family: Arial, sans-serif;\n";
    file << "    font-size: 13px;\n";
    file << "    color: #627d98;\n";
    file << "}\n";

    file << ".contact {\n";
    file << "    margin-top: 11px;\n";
    file << "    font-family: Arial, sans-serif;\n";
    file << "    font-size: 12px;\n";
    file << "    color: #486581;\n";
    file << "}\n";

    file << ".date {\n";
    file << "    text-align: right;\n";
    file << "    font-size: 15px;\n";
    file << "    margin: 30px 0;\n";
    file << "}\n";

    file << ".recipient {\n";
    file << "    font-size: 15px;\n";
    file << "    line-height: 1.6;\n";
    file << "    margin-bottom: 28px;\n";
    file << "}\n";

    file << ".subject {\n";
    file << "    padding: 13px 16px;\n";
    file << "    margin-bottom: 28px;\n";
    file << "    border-left: 4px solid #243b53;\n";
    file << "    background: #f0f4f8;\n";
    file << "    font-family: Arial, sans-serif;\n";
    file << "    font-size: 14px;\n";
    file << "    font-weight: bold;\n";
    file << "    color: #243b53;\n";
    file << "}\n";

    file << ".salutation {\n";
    file << "    font-size: 16px;\n";
    file << "    margin-bottom: 18px;\n";
    file << "}\n";

    file << ".letter p {\n";
    file << "    font-size: 15.5px;\n";
    file << "    line-height: 1.85;\n";
    file << "    text-align: justify;\n";
    file << "    margin: 0 0 18px 0;\n";
    file << "}\n";

    file << ".details {\n";
    file << "    margin: 25px 0;\n";
    file << "    border: 1px solid #d9e2ec;\n";
    file << "    background: #f8fafc;\n";
    file << "}\n";

    file << ".detail-row {\n";
    file << "    display: flex;\n";
    file << "    border-bottom: 1px solid #d9e2ec;\n";
    file << "}\n";

    file << ".detail-row:last-child {\n";
    file << "    border-bottom: none;\n";
    file << "}\n";

    file << ".detail-label {\n";
    file << "    width: 32%;\n";
    file << "    padding: 12px 15px;\n";
    file << "    font-family: Arial, sans-serif;\n";
    file << "    font-size: 12px;\n";
    file << "    font-weight: bold;\n";
    file << "    color: #486581;\n";
    file << "    text-transform: uppercase;\n";
    file << "}\n";

    file << ".detail-value {\n";
    file << "    width: 68%;\n";
    file << "    padding: 12px 15px;\n";
    file << "    font-size: 14px;\n";
    file << "    color: #243b53;\n";
    file << "}\n";

    file << ".signature {\n";
    file << "    margin-top: 42px;\n";
    file << "    font-size: 15px;\n";
    file << "    line-height: 1.65;\n";
    file << "}\n";

    file << ".signature-name {\n";
    file << "    margin-top: 25px;\n";
    file << "    font-family: Arial, sans-serif;\n";
    file << "    font-size: 17px;\n";
    file << "    font-weight: bold;\n";
    file << "    color: #243b53;\n";
    file << "}\n";

    file << ".footer {\n";
    file << "    margin-top: 55px;\n";
    file << "    padding-top: 15px;\n";
    file << "    border-top: 1px solid #d9e2ec;\n";
    file << "    text-align: center;\n";
    file << "    font-family: Arial, sans-serif;\n";
    file << "    font-size: 10px;\n";
    file << "    color: #829ab1;\n";
    file << "}\n";

    file << "@media print {\n";

    file << "    body {\n";
    file << "        background: white;\n";
    file << "        padding: 0;\n";
    file << "    }\n";

    file << "    .page {\n";
    file << "        width: 100%;\n";
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

    file << "<div class=\"letterhead\">\n";

    file << "<div class=\"name\">"
         << recommenderName
         << "</div>\n";

    file << "<div class=\"position\">"
         << recommenderPosition
         << "</div>\n";

    file << "<div class=\"organization\">"
         << organization
         << "</div>\n";

    file << "<div class=\"address\">"
         << organizationAddress
         << "</div>\n";

    file << "<div class=\"contact\">";

    if (!recommenderEmail.empty())
    {
        file << "Email: " << recommenderEmail;
    }

    if (!recommenderEmail.empty() && !recommenderPhone.empty())
    {
        file << " &nbsp; | &nbsp; ";
    }

    if (!recommenderPhone.empty())
    {
        file << "Phone: " << recommenderPhone;
    }

    file << "</div>\n";

    file << "</div>\n";

    file << "<div class=\"date\">"
         << date
         << "</div>\n";

    file << "<div class=\"recipient\">\n";

    file << "<strong>"
         << recipientName
         << "</strong><br>\n";

    if (!recipientPosition.empty())
    {
        file << recipientPosition << "<br>\n";
    }

    if (!recipientOrganization.empty())
    {
        file << recipientOrganization << "<br>\n";
    }

    file << "</div>\n";

    file << "<div class=\"subject\">\n";

    file << "RE: LETTER OF RECOMMENDATION FOR "
         << candidateName;

    file << "</div>\n";

    file << "<div class=\"salutation\">"
         << "Dear Sir/Madam,"
         << "</div>\n";

    file << "<div class=\"letter\">\n";

    file << "<p>\n";

    file << "I am pleased to provide this letter of recommendation for "
         << "<strong>" << candidateName << "</strong>"
         << ", whom I have known for "
         << "a considerable period"
         << " in my capacity as "
         << "<strong>" << relationship << "</strong>"
         << ". I am writing in support of the candidate's application for "
         << "<strong>" << purpose << "</strong>"
         << ".\n";

    file << "</p>\n";

    file << "<div class=\"details\">\n";


    file << "<div class=\"detail-row\">\n";

    file << "<div class=\"detail-label\">Candidate</div>\n";

    file << "<div class=\"detail-value\">"
         << candidateName
         << "</div>\n";

    file << "</div>\n";


    file << "<div class=\"detail-row\">\n";

    file << "<div class=\"detail-label\">Field / Position</div>\n";

    file << "<div class=\"detail-value\">"
         << candidateField
         << "</div>\n";

    file << "</div>\n";


    file << "<div class=\"detail-row\">\n";

    file << "<div class=\"detail-label\">Purpose</div>\n";

    file << "<div class=\"detail-value\">"
         << sector
         << "</div>\n";

    file << "</div>\n";


    file << "<div class=\"detail-row\">\n";

    file << "<div class=\"detail-label\">Relationship</div>\n";

    file << "<div class=\"detail-value\">"
         << relationship
         << "</div>\n";

    file << "</div>\n";


    file << "</div>\n";

    file << "<p>\n";

    file << "<strong>" << candidateName << "</strong>"
         << " has consistently demonstrated a strong sense of responsibility, "
         "professionalism, and commitment. During the period I have known "
         "the candidate, I have observed a willingness to learn, accept "
         "responsibility, and work constructively toward achieving goals.\n";

    file << "</p>\n";

    file << "<p>\n";

    file << "Among the candidate's most notable strengths are "
         << "<strong>" << strengths << "</strong>"
         << ". These qualities have contributed positively to the candidate's "
         "performance and ability to work effectively in professional or "
         "academic environments.\n";

    file << "</p>\n";

    file << "<p>\n";

    file << "The candidate has also demonstrated the following achievements "
         "and notable qualities: "
         << "<strong>" << achievements << "</strong>"
         << ". These qualities reflect the candidate's ability to approach "
         "responsibilities with maturity, consistency, and professionalism.\n";

    file << "</p>\n";

    file << "<p>\n";

    file << recommendationStatement;

    file << "</p>\n";

    file << "<p>\n";

    file << "Based on my experience with "
         << "<strong>" << candidateName << "</strong>"
         << ", I believe the candidate possesses the character, skills, "
         "and potential necessary to contribute positively to the "
         "organization or institution under consideration. I therefore "
         "recommend the candidate for this opportunity with confidence.\n";

    file << "</p>\n";

    file << "<p>\n";

    file << "Should you require any additional information regarding this "
         "recommendation, I would be pleased to provide further details "
         "through the contact information listed above.\n";

    file << "</p>\n";


    file << "</div>\n";

    file << "<div class=\"signature\">\n";

    file << "Sincerely,<br>\n";

    file << "<div class=\"signature-name\">"
         << recommenderName
         << "</div>\n";

    file << recommenderPosition << "<br>\n";

    file << organization << "<br>\n";

    if (!recommenderEmail.empty())
    {
        file << recommenderEmail << "<br>\n";
    }

    if (!recommenderPhone.empty())
    {
        file << recommenderPhone;
    }

    file << "</div>\n";

    file << "<div class=\"footer\">\n";

    file << "Recommendation Letter &nbsp; | &nbsp; "
         "Generated by DocCreator";

    file << "</div>\n";

    file << "</div>\n";
    file << "</body>\n";
    file << "</html>\n";

    file.close();


    cout << "\nRecommendation Letter generated successfully!\n";
        cout << "File Name : "<< filename<<endl;
        cout<<"File Location : "<< path2<<endl;
        cout << "Open it in Chrome, Edge, or Firefox.\n";

}
