#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string favoriteTopic;
    string historicalFigure;
    int hoursPerWeek;
    double monthlyBookCost;
    int menuChoice;
    int hoursPerMonth;
    double yearlyBookCost;
    char runAgain;

    // Variables used in the for loop summary
    int studyWeek;

    cout << "========================================" << endl;
    cout << "   Orthodox Christian History Tracker" << endl;
    cout << "========================================" << endl;
    cout << "This program helps track study time and book/resource spending." << endl << endl;

    cout << "What topic in Orthodox Christian history interests you most? ";
    getline(cin, favoriteTopic);

    cout << "What saint, council, or historical figure do you like learning about? ";
    getline(cin, historicalFigure);

    cout << "How many hours per week do you study this topic? ";
    cin >> hoursPerWeek;

    cout << "How much do you spend on books/resources each month? ";
    cin >> monthlyBookCost;

    if (hoursPerWeek < 0)
    {
        cout << "Invalid input. Study hours cannot be negative." << endl;
        return 1;
    }

    if (monthlyBookCost < 0)
    {
        cout << "Invalid input. Monthly book cost cannot be negative." << endl;
        return 1;
    }

    hoursPerMonth = hoursPerWeek * 4;
    yearlyBookCost = monthlyBookCost * 12;

    cout << fixed << showpoint << setprecision(2);

    // This do-while loop lets the user view more than one menu option
    do
    {
        cout << endl;
        cout << "Choose an option:" << endl;
        cout << "1. View study report" << endl;
        cout << "2. View spending report" << endl;
        cout << "3. View recommendation" << endl;
        cout << "Enter your choice: ";
        cin >> menuChoice;

        // This while loop checks that the user entered a valid menu choice
        while (menuChoice < 1 || menuChoice > 3)
        {
            cout << "Invalid menu choice. Please choose 1, 2, or 3: ";
            cin >> menuChoice;
        }

        switch (menuChoice)
        {
        case 1:
            cout << endl;
            cout << "Study Report" << endl;
            cout << left << setw(25) << "Topic:" << favoriteTopic << endl;
            cout << left << setw(25) << "Figure:" << historicalFigure << endl;
            cout << left << setw(25) << "Hours per week:" << hoursPerWeek << endl;
            cout << left << setw(25) << "Hours per month:" << hoursPerMonth << endl;

            // This for loop prints a simple four week study plan
            cout << endl;
            cout << "Four Week Study Plan" << endl;
            for (studyWeek = 1; studyWeek <= 4; studyWeek++)
            {
                cout << "Week " << studyWeek << ": study " << hoursPerWeek << " hours" << endl;
            }
            break;

        case 2:
            cout << endl;
            cout << "Spending Report" << endl;
            cout << left << setw(25) << "Monthly resource cost:" << "$" << monthlyBookCost << endl;
            cout << left << setw(25) << "Yearly resource cost:" << "$" << yearlyBookCost << endl;
            break;

        case 3:
            cout << endl;
            cout << "Recommendation" << endl;

            if (hoursPerWeek >= 5 && monthlyBookCost >= 20)
            {
                cout << "You are putting serious time and money into this topic." << endl;
                cout << "You may want to make a reading schedule so you do not fall behind." << endl;
            }
            else if (hoursPerWeek >= 2)
            {
                cout << "You have a steady study pace." << endl;
                cout << "Try writing short notes after each reading session." << endl;
            }
            else
            {
                cout << "You may want to set aside more weekly study time." << endl;
            }
            break;
        }

        cout << endl;
        cout << "Would you like to view another option? Enter y or n: ";
        cin >> runAgain;

    } while (runAgain == 'y' || runAgain == 'Y');

    // Create and save a report file
    ofstream reportFile;
    reportFile.open("report.txt");

    reportFile << fixed << showpoint << setprecision(2);
    reportFile << "Orthodox Christian History Tracker Report" << endl;
    reportFile << "----------------------------------------" << endl;
    reportFile << left << setw(25) << "Topic:" << favoriteTopic << endl;
    reportFile << left << setw(25) << "Figure:" << historicalFigure << endl;
    reportFile << left << setw(25) << "Hours per week:" << hoursPerWeek << endl;
    reportFile << left << setw(25) << "Hours per month:" << hoursPerMonth << endl;
    reportFile << left << setw(25) << "Monthly resource cost:" << "$" << monthlyBookCost << endl;
    reportFile << left << setw(25) << "Yearly resource cost:" << "$" << yearlyBookCost << endl;

    if (hoursPerWeek >= 5)
    {
        reportFile << "Study level: Heavy weekly study" << endl;
    }
    else
    {
        reportFile << "Study level: Light or moderate weekly study" << endl;
    }

    reportFile.close();

    cout << endl;
    cout << "Report saved to report.txt." << endl;

    return 0;
}