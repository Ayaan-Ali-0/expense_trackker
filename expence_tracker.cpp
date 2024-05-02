#include <iostream>
#include <string> // Add this line for string usage
using namespace std;

int main() 
{
    const int MAX_WEEKS = 10; // Maximum number of weeks to track
    const int NUM_DAYS_IN_WEEK = 7;   // Number of days in a week

    // Ask the user for their budget
    int budget;
    cout << "Enter your budget for the week (in rupees): ";
    cin >> budget;

    // Validate input
    if (budget <= 0) {
        cout << "Invalid input. Budget must be greater than 0." << endl;
        return 1; // Exit with an error code
    }

    // Ask the user for the number of weeks to track
    int numWeeks;
    cout << "Enter the number of weeks you want to track: ";
    cin >> numWeeks;

    // Validate input
    if (numWeeks <= 0 || numWeeks > MAX_WEEKS) {
        cout << "Invalid input. Number of weeks must be between 1 and " << MAX_WEEKS << "." << endl;
        return 1; // Exit with an error code
    }

    // Array to store expenses for each week
    int expenses[MAX_WEEKS] = {0};

    cout << "\n**************\n";
    cout << "      Weekly Expense Tracker\n";
    cout << "************\n";

    cout << "Week    Total Expenses    Budget Status\n";
    cout << "----------------------------------------\n";

    // Use an array to store the days of the week
    string days[NUM_DAYS_IN_WEEK] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    // Input expenses for each week
    for (int week = 0; week < numWeeks; ++week) {
        cout << week + 1;

        int totalExpenses = 0; // Initialize totalExpenses here

        for (int day = 0; day < NUM_DAYS_IN_WEEK; ++day) {
            int expense;
            cout << "    " << days[day] << ": Rs.";
            cin >> expense;
            totalExpenses += expense;
        }

        // Check if total expenses exceed the budget
        int overspentAmount = totalExpenses - budget;
        cout << "    Total: Rs." << totalExpenses;

        // Output budget status
        if (overspentAmount > 0) {
            cout << "    Exceeded by Rs." << overspentAmount;
        } else {
            cout << "    Within budget";
        }

        cout << endl;

        // Store total expenses for the week
        expenses[week] = totalExpenses;
    }

    // Display total expenses for each week
    cout << "\nSummary:\n";
    cout << "Week    Total Expenses    Budget Status\n";
    cout << "----------------------------------------\n";

    for (int week = 0; week < numWeeks; ++week) {
        cout << week + 1;
        cout << "    Rs." << expenses[week];

        // Output budget status
        if (expenses[week] > budget) {
            cout << "    Exceeded by Rs." << (expenses[week] - budget);
        } else {
            cout << "    Within budget";
        }

        cout << endl;
    }

    return 0; // Exit successfully
}
