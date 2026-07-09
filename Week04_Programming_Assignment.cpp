// Week 06: Programming Assignment
// Added arrays and enum features


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// Function prototypes
void changeConsoleTextColor();
void displayIntroductionBanner();
void FirstTwoIntro_Questions(string& favoriteTopic, string& historicalFigure);
int CalculateWeeklyStudy(int Array_hoursPerWeek[], int hoursPerWeek_size);
double MonthlyAndYearlyCost(double Array_yearlyBookCost[], int monthsInYear);
int calculateMonthlyHours(int totalWeeklyHours);
double calculateWeeklyAverageHours(int hoursPerMonth);
double calculateMonthlyAverageCost(double totalYearlyBookCost);
void displayMenuOptions(int menuOptions[], int menuSize);
void saveFormattedReportToFile(string favoriteTopic, string historicalFigure, double averageHoursWeekly, int hoursPerMonth, double averageMonthlyCost, double totalYearlyBookCost);

int main()
{
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


    // Define an enumeration for menu options
    enum menuOptions_names { VIEW_STUDY_REPORT = 1, VIEW_SPENDING_REPORT = 2, VIEW_RECOMMENDATION = 3, CHOICE_CONFIRMATION = 4}; 

    //Arrays
    const int menuSize = 4;                                                                                          // Define the size of the menu options
    int menuOptions[menuSize] = {VIEW_STUDY_REPORT, VIEW_SPENDING_REPORT, VIEW_RECOMMENDATION, CHOICE_CONFIRMATION}; // Declare an array to store menu options

    const int hoursPerWeek_size = 7;                  // Define the size of the array for hours per week (7 days)
    int Array_hoursPerWeek[hoursPerWeek_size] = {0};  // Declare the array to store hours per week for each day

    const int monthsInYear = 12;                      // Define the number of months in a year
    double Array_yearlyBookCost[monthsInYear]= {0};   // Declare an array to store yearly book costs for each month

    cout << fixed << showpoint << setprecision(2);

    // Call functions
    changeConsoleTextColor();
    displayIntroductionBanner();
    FirstTwoIntro_Questions(favoriteTopic, historicalFigure);
    // ARRAY 
    totalWeeklyHours = CalculateWeeklyStudy(Array_hoursPerWeek, hoursPerWeek_size); // Store total weekly hours using  ARRAY 
    hoursPerMonth = calculateMonthlyHours(totalWeeklyHours);                        // Store calculated monthly study hours
    averageHoursWeekly = calculateWeeklyAverageHours(hoursPerMonth);                // Store calculated average weekly hours
    // ARRAY 
    totalYearlyBookCost = MonthlyAndYearlyCost(Array_yearlyBookCost, monthsInYear); // Store total yearly cost using ARRAY
    averageMonthlyCost = calculateMonthlyAverageCost(totalYearlyBookCost);          // Store calculated average monthly cost



    // This do-while loop lets the user view more than one menu option
    do
    {
        // ARRAY 
        // Display menu options using the menu array
        displayMenuOptions(menuOptions, menuSize);     
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

    saveFormattedReportToFile(favoriteTopic, historicalFigure, averageHoursWeekly, hoursPerMonth, averageMonthlyCost, totalYearlyBookCost);

    return 0;
}



// Function definitions


// Change the console text color to purple
void changeConsoleTextColor()
{
    cout << "\033[35m";
}


// Display the program introduction banner
void displayIntroductionBanner()
{
    cout << "================================================================" << endl;
    cout << "             Orthodox Christian History Tracker                 " << endl;
    cout << "================================================================"  << endl;
    cout << " This program helps track study time and book/resource spending " << endl << endl;
}


// Function (Void): Display fist two question, take user input
void FirstTwoIntro_Questions(string& favoriteTopic, string& historicalFigure)
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


// Function (return int): Use array to collect input and calculate total weekly hours
int CalculateWeeklyStudy(int Array_hoursPerWeek[], int hoursPerWeek_size)
{

    // cout << "How many hours per week do you study this topic? ";
    // cin >> hoursPerWeek;

    int HoursPerDay = 24;
    int Min_ValidHours = 0;
    int totalWeeklyHours = 0;                                                                              // Initialize a variable to keep track of the total weekly study hours
    cout << "How many hours do you study this topic each day of the week (Sunday to Saturday)?" << endl;   // Prompt the user to enter study hours for each day of the week
    for (int i = 0; i < hoursPerWeek_size; i++)                                                            // Loop through each day of the week to collect study hours (For loop)
    {
        cout << "Day " << (i + 1) << ": ";                  
        cin >> Array_hoursPerWeek[i];                                                              // Store the input in the corresponding index of the array
        while (Array_hoursPerWeek[i] < Min_ValidHours || Array_hoursPerWeek[i] > HoursPerDay || cin.fail())     // Validate that the input is not negative and is a valid integer (While loop)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Study hours cannot be negative or exceed 24. \nEnter again for Day " << (i + 1) << ": ";
            cin >> Array_hoursPerWeek[i];
        }
        totalWeeklyHours += Array_hoursPerWeek[i];          // Add the study hours for the current day to the total weekly hours
    }
    cout << "Total study hours for the week: " << totalWeeklyHours << endl;
    cout << endl;

    return totalWeeklyHours;
}


// Function (return double): Use array to collect input and calculate total yearly cost
double MonthlyAndYearlyCost(double Array_yearlyBookCost[], int monthsInYear)
{
    int Min_ValidNumber = 0;
    double totalYearlyBookCost = 0;                                                      // Initialize a variable to keep track of the total monthly book/resource cost
    cout << "Enter the monthly book/resource cost for each month of the year: " << endl; // Prompt the user to enter monthly book/resource costs for each month of the year
    for (int i = 0; i < monthsInYear; i++)                                               // Loop through each month of the year
    {
        cout << "Month " << (i + 1) << ": $";
        cin >> Array_yearlyBookCost[i];                                 // Store the input in the corresponding index of the array
        while (Array_yearlyBookCost[i] < Min_ValidNumber || cin.fail()) // Validate that the input is not negative and is a valid number
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Monthly book/resource cost cannot be negative. \nEnter again for Month " << (i + 1) << ": $";
            cin >> Array_yearlyBookCost[i];
        }
        totalYearlyBookCost += Array_yearlyBookCost[i];         // Add the monthly book/resource cost for the current month to the total monthly book/resource cost
    }
    cout << "Total book/resource cost for the year: $" << totalYearlyBookCost << endl;
    cout << endl;

    return totalYearlyBookCost;
}


// Function (return int): Calculate monthly study hours 
int calculateMonthlyHours(int totalWeeklyHours)
{
    int weeksInMonth = 4;
    int hoursPerMonth = totalWeeklyHours * weeksInMonth;

    return hoursPerMonth;
}

// Function (return int): Calculate weekly average study hours 
double calculateWeeklyAverageHours(int hoursPerMonth)
{
    int weeksInMonth = 4;
    double averageHoursPerMonth = hoursPerMonth / weeksInMonth;

    return averageHoursPerMonth;
}


// Function (return double): Calculate monthly average cost 
double calculateMonthlyAverageCost(double totalYearlyBookCost)
{
    int totalMonthsInYear = 12;
    double averageMonthlyCost = totalYearlyBookCost / totalMonthsInYear;

    return averageMonthlyCost;
}


// Function (Void): Use array to display menu choices
void displayMenuOptions(int menuOptions[], int menuSize)
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
void saveFormattedReportToFile(string favoriteTopic, string historicalFigure, double averageHoursWeekly, int hoursPerMonth, double averageMonthlyCost, double totalYearlyBookCost)
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
        reportFile << left << setw(35) << "Study level:" <<  "Heavy weekly study" << endl;
    }
    else
    {
        reportFile << "Study level: Light or moderate weekly study" << endl;
    }

    cout << endl;
    cout << "Report saved to report.txt." << endl;

    reportFile.close();
}