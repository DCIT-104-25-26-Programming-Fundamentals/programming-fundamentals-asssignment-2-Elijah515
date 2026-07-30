// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
using namespace std;

double calculate_sum(const vector<int>& numbers) {
    double total = 0;
    for (int num : numbers) {
        total = total + num;
    }
    return total;
}

double calculate_average(const vector<int>& numbers) {
    double total = calculate_sum(numbers);
    int count = numbers.size();
    double average = total / count;
    return average;
}

int calculate_max(const vector<int>& numbers) {
    int max_value = numbers[0];
    for (int num : numbers) {
        if (num > max_value) {
            max_value = num;
        }
    }
    return max_value;
}

int calculate_min(const vector<int>& numbers) {
    int min_value = numbers[0];
    for (int num : numbers) {
        if (num < min_value) {
            min_value = num;
        }
    }
    return min_value;
}

int main() {
    int n;
    cout << "How many numbers? ";
    cin >> n;

    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        int num;
        cout << "Enter number " << (i + 1) << ": ";
        cin >> num;
        numbers.push_back(num);
    }

    double total = calculate_sum(numbers);
    double avg = calculate_average(numbers);
    int max_val = calculate_max(numbers);
    int min_val = calculate_min(numbers);

    cout << "Results:" << endl;
    cout << "Sum: " << total << endl;
    cout << "Average: " << avg << endl;
    cout << "Maximum: " << max_val << endl;
    cout << "Minimum: " << min_val << endl;

    return 0;
}
