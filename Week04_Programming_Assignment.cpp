// Week 08: Programming Assignment
// Added class features


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


class OrthodoxHistoryTracker
{
public:

    struct Day
    {
        int studyHours = 0;
    };

    struct totalWeeklyStudyHours
    {
        Day studyPerDay[7];
    };


    struct month
    {
        double cost = 0;
    };

    struct totalYearlyCost
    {
        month costPerMonth[12];
    };


    // Define an enumeration for menu options
    enum menuOptions_names
    {
        VIEW_STUDY_REPORT = 1,
        VIEW_SPENDING_REPORT = 2,
        VIEW_RECOMMENDATION = 3,
        CHOICE_CONFIRMATION = 4
    };


    // Constructor
    OrthodoxHistoryTracker()
    {
        favoriteTopic = "";
        historicalFigure = "";
        totalWeeklyHours = 0;
        averageMonthlyCost = 0.0;
        menuChoice = 0;
        hoursPerMonth = 0;
        averageHoursWeekly = 0.0;
        totalYearlyBookCost = 0.0;
        runAgain = ' ';
        studyWeek = 0;

        menuOptions[0] = VIEW_STUDY_REPORT;
        menuOptions[1] = VIEW_SPENDING_REPORT;
        menuOptions[2] = VIEW_RECOMMENDATION;
        menuOptions[3] = CHOICE_CONFIRMATION;
    }


    // Function prototypes
    void changeConsoleTextColor();
    void displayIntroductionBanner();
    void FirstTwoIntro_Questions();
    int CalculateWeeklyStudy();
    double MonthlyAndYearlyCost();
    int calculateMonthlyHours();
    double calculateWeeklyAverageHours();
    double calculateMonthlyAverageCost();
    void displayMenuOptions();
    void saveFormattedReportToFile();
    void runProgram();


private:

    // Declare variables
    string favoriteTopic;
    string historicalFigure;
    int totalWeeklyHours;
    double averageMonthlyCost;
    int menuChoice;
    int hoursPerMonth;
    double averageHoursWeekly;
    double totalYearlyBookCost;
    char runAgain;
    int studyWeek;


    // Arrays
    static const int menuSize = 4;
    int menuOptions[menuSize];

    totalWeeklyStudyHours weeklyStudyHourse;
    totalYearlyCost yearlyCost;
};



int main()
{
    // Create class object
    OrthodoxHistoryTracker tracker;

    // Run program
    tracker.runProgram();

    return 0;
}



// Function definitions


// Run the program
void OrthodoxHistoryTracker::runProgram()
{
    cout << fixed << showpoint << setprecision(2);

    // Call functions
    changeConsoleTextColor();
    displayIntroductionBanner();
    FirstTwoIntro_Questions();
    totalWeeklyHours = CalculateWeeklyStudy();                     // ARRAY // Store total weekly hours using ARRAY
    hoursPerMonth = calculateMonthlyHours();                       // Store calculated monthly study hours
    averageHoursWeekly = calculateWeeklyAverageHours();            // Store calculated average weekly hours
    totalYearlyBookCost = MonthlyAndYearlyCost();                  // ARRAY // Store total yearly cost using ARRAY
    averageMonthlyCost = calculateMonthlyAverageCost();            // Store calculated average monthly cost



    // This do-while loop lets the user view more than one menu option
    do
    {
        // ARRAY
        // Display menu options using the menu array
        displayMenuOptions();
        cin >> menuChoice;

        // This while loop checks that the user entered a valid menu choice
        while (cin.fail() || menuChoice < VIEW_STUDY_REPORT || menuChoice > VIEW_RECOMMENDATION)
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << endl;
            cout << "Invalid menu choice. Please choose 1, 2, or 3: ";
            cin >> menuChoice;
        }

        switch (menuChoice)
        {
        case VIEW_STUDY_REPORT:
            cout << endl;
            cout << "Study Report" << endl;
            cout << left << setw(25) << "Topic:" << favoriteTopic << endl;
            cout << left << setw(25) << "Figure:" << historicalFigure << endl;
            cout << left << setw(25) << "Average study hours per week:" << averageHoursWeekly << endl;
            cout << left << setw(25) << "Study hours per month:" << hoursPerMonth << endl;

            // This for loop prints a simple four week study plan
            cout << endl;
            cout << "Four Week Study Plan" << endl;
            for (studyWeek = 1; studyWeek <= 4; studyWeek++)
            {
                cout << "Week " << studyWeek << ": study " << totalWeeklyHours << " hours" << endl;
            }
            break;

        case VIEW_SPENDING_REPORT:
            cout << endl;
            cout << "Spending Report" << endl;
            cout << left << setw(25) << "Monthly average cost: " << "$" << averageMonthlyCost << endl;
            cout << left << setw(25) << "Yearly resource cost: " << "$" << totalYearlyBookCost << endl;
            break;

        case VIEW_RECOMMENDATION:
            cout << endl;
            cout << "Recommendation" << endl;

            if (totalWeeklyHours >= 5 && averageMonthlyCost >= 20)
            {
                cout << "You are putting serious time and money into this topic." << endl;
                cout << "You may want to make a reading schedule so you do not fall behind." << endl;
            }
            else if (totalWeeklyHours >= 2)
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
        cout << "Press Q to quit or press any other key to view other options: ";
        cin >> runAgain;

    } while (runAgain != 'q' && runAgain != 'Q');

    cout << endl;

    saveFormattedReportToFile();
}



// Change the console text color to purple
void OrthodoxHistoryTracker::changeConsoleTextColor()
{
    cout << "\033[35m";
}


// Display the program introduction banner
void OrthodoxHistoryTracker::displayIntroductionBanner()
{
    cout << "================================================================" << endl;
    cout << "             Orthodox Christian History Tracker                 " << endl;
    cout << "================================================================" << endl;
    cout << " This program helps track study time and book/resource spending " << endl << endl;
}


// Function (Void): Display fist two question, take user input
void OrthodoxHistoryTracker::FirstTwoIntro_Questions()
{
    cout << "What topic in Orthodox Christian history interests you most? ";
    getline(cin, favoriteTopic);

    while (favoriteTopic == "")     // Check if topic input is empty
    {
        cout << "Invalid input! \n\nWhat topic in Orthodox Christian history interests you most? ";
        getline(cin, favoriteTopic);
    }

    cout << "What saint, council, or historical figure do you like learning about? ";
    getline(cin, historicalFigure);

    while (historicalFigure == "")  // Check if historical figure input is empty
    {
        cout << "Invalid input! \n\nWhat saint, council, or historical figure do you like learning about? ";
        getline(cin, historicalFigure);
    }

    cout << endl;
}


// Function (return int): Use STRUCT and ARRAY to collect input and calculate total weekly hours
int OrthodoxHistoryTracker::CalculateWeeklyStudy()
{
    int HoursPerDay = 24;
    int Min_ValidHours = 0;
    int totalWeeklyHours = 0;
    int daysInWeek = 7;

    cout << "How many hours do you study this topic each day of the week (Sunday to Saturday)?" << endl;

    for (int i = 0; i < daysInWeek; i++)
    {
        cout << "Day " << (i + 1) << ": ";
        cin >> weeklyStudyHourse.studyPerDay[i].studyHours;

        while (cin.fail() ||
               weeklyStudyHourse.studyPerDay[i].studyHours < Min_ValidHours ||
               weeklyStudyHourse.studyPerDay[i].studyHours > HoursPerDay)
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input! Study hours cannot be negative or exceed 24."
                 << "\nEnter again for Day " << (i + 1) << ": ";

            cin >> weeklyStudyHourse.studyPerDay[i].studyHours;
        }

        totalWeeklyHours += weeklyStudyHourse.studyPerDay[i].studyHours;
    }

    cout << "Total study hours for the week: " << totalWeeklyHours << endl;
    cout << endl;

    return totalWeeklyHours;
}


// Function (return double): Use STRUCT and ARRAY to collect input and calculate total yearly cost
double OrthodoxHistoryTracker::MonthlyAndYearlyCost()
{
    double Min_ValidNumber = 0;
    double totalYearlyBookCost = 0;
    int monthsInYear = 12;

    cout << "Enter the monthly book/resource cost for each month of the year:" << endl;

    for (int i = 0; i < monthsInYear; i++)
    {
        cout << "Month " << (i + 1) << ": $";
        cin >> yearlyCost.costPerMonth[i].cost;

        while (cin.fail() ||
               yearlyCost.costPerMonth[i].cost < Min_ValidNumber)
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input. Monthly book/resource cost cannot be negative."
                 << "\nEnter again for Month " << (i + 1) << ": $";

            cin >> yearlyCost.costPerMonth[i].cost;
        }

        totalYearlyBookCost += yearlyCost.costPerMonth[i].cost;
    }

    cout << "Total book/resource cost for the year: $"
         << totalYearlyBookCost << endl;

    cout << endl;

    return totalYearlyBookCost;
}



// Function (return int): Calculate monthly study hours
int OrthodoxHistoryTracker::calculateMonthlyHours()
{
    int weeksInMonth = 4;
    int hoursPerMonth = totalWeeklyHours * weeksInMonth;

    return hoursPerMonth;
}


// Function (return int): Calculate weekly average study hours
double OrthodoxHistoryTracker::calculateWeeklyAverageHours()
{
    int weeksInMonth = 4;
    double averageHoursPerMonth = hoursPerMonth / weeksInMonth;

    return averageHoursPerMonth;
}


// Function (return double): Calculate monthly average cost
double OrthodoxHistoryTracker::calculateMonthlyAverageCost()
{
    int totalMonthsInYear = 12;
    double averageMonthlyCost = totalYearlyBookCost / totalMonthsInYear;

    return averageMonthlyCost;
}


// Function (Void): Use array to display menu choices
void OrthodoxHistoryTracker::displayMenuOptions()
{
    cout << endl;
    cout << "Choose an option:" << endl;

    for (int i = 0; i < menuSize; i++)
    {
        switch (menuOptions[i])
        {
        case 1:
            cout << "1. View study report" << endl;
            break;

        case 2:
            cout << "2. View spending report" << endl;
            break;

        case 3:
            cout << "3. View recommendation" << endl;
            break;

        case 4:
            cout << "Enter your choice: ";
            break;
        }
    }
}


// Save the formatted report to a text file
void OrthodoxHistoryTracker::saveFormattedReportToFile()
{
    ofstream reportFile;
    reportFile.open("report.txt");

    reportFile << fixed << showpoint << setprecision(2);
    reportFile << "   Orthodox Christian History Tracker Report    " << endl;
    reportFile << "------------------------------------------------" << endl;
    reportFile << left << setw(35) << "Topic:" << favoriteTopic << endl;
    reportFile << left << setw(35) << "Figure:" << historicalFigure << endl;
    reportFile << left << setw(35) << "Average hours per week:" << averageHoursWeekly << endl;
    reportFile << left << setw(35) << "Hours per month:" << hoursPerMonth << endl;
    reportFile << left << setw(35) << "Average monthly resource cost:" << "$" << averageMonthlyCost << endl;
    reportFile << left << setw(35) << "Yearly resource cost:" << "$" << totalYearlyBookCost << endl;

    if (averageHoursWeekly >= 5)
    {
        reportFile << left << setw(35) << "Study level:" << "Heavy weekly study" << endl;
    }
    else
    {
        reportFile << left << setw(35) << "Study level: Light or moderate weekly study" << endl;
    }

    cout << endl;
    cout << "Report saved to report.txt." << endl;

    reportFile.close();
}