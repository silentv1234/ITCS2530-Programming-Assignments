#include <iostream>
#include <string>

using namespace std;

int main()
// Week 01 programming assignment
{
    // Declare variables to store the user's answers
    string favoriteTopic;
    string historicalFigure;
    int hoursPerWeek;
    int hoursPerMonth;

    // Ask the user for three pieces of information
    cout << "What topic in Orthodox Christian history interests you most? ";
    getline(cin, favoriteTopic);

    cout << "What saint, council, or historical figure do you like learning about? ";
    getline(cin, historicalFigure);

    cout << "How many hours per week do you study this topic? ";
    cin >> hoursPerWeek;

    // Calculate monthly study time
    hoursPerMonth = hoursPerWeek * 4;

    // Display a paragraph using the user's information
    cout << endl;

    cout << "You enjoy studying " << favoriteTopic
        << " in Orthodox Christian history, especially learning about "
        << historicalFigure << ". If you study for "
        << hoursPerWeek << " hours each week, that means you study about "
        << hoursPerMonth << " hours each month. That is a great way to grow "
        << "in knowledge of Church history while also practicing research and discipline."
        << endl;

    return 0;
}