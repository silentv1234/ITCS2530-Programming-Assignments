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
    double bookCost;
    int hoursPerMonth;
    double yearlyBookCost;

    cout << "========================================" << endl;
    cout << "   Orthodox Christian History Tracker" << endl;
    cout << "========================================" << endl;

    cout << "What topic in Orthodox Christian history interests you most? ";
    getline(cin, favoriteTopic);

    cout << "What saint, council, or historical figure do you like learning about? ";
    getline(cin, historicalFigure);

    cout << "How many hours per week do you study this topic? ";
    cin >> hoursPerWeek;

    cout << "How much do you spend on books/resources each month? ";
    cin >> bookCost;

    if (hoursPerWeek < 0 || bookCost < 0)
    {
        cout << "Invalid input. Hours and cost cannot be negative." << endl;
        return 1;
    }

    hoursPerMonth = hoursPerWeek * 4;
    yearlyBookCost = bookCost * 12;

    cout << fixed << showpoint << setprecision(2);
    cout << endl;
    cout << left << setw(25) << "Topic:" << favoriteTopic << endl;
    cout << left << setw(25) << "Figure:" << historicalFigure << endl;
    cout << left << setw(25) << "Hours per week:" << hoursPerWeek << endl;
    cout << left << setw(25) << "Hours per month:" << hoursPerMonth << endl;
    cout << left << setw(25) << "Yearly resource cost:" << "$" << yearlyBookCost << endl;

    ofstream reportFile;
    reportFile.open("report.txt");

    reportFile << fixed << showpoint << setprecision(2);
    reportFile << "Orthodox Christian History Tracker Report" << endl;
    reportFile << "Topic: " << favoriteTopic << endl;
    reportFile << "Figure: " << historicalFigure << endl;
    reportFile << "Hours per week: " << hoursPerWeek << endl;
    reportFile << "Hours per month: " << hoursPerMonth << endl;
    reportFile << "Yearly resource cost: $" << yearlyBookCost << endl;

    reportFile.close();

    cout << endl << "Report saved to report.txt." << endl;

    return 0;
}