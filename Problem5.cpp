#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* Name: ipek
* Surname: Zorpineci
* Date: 10.05.2024
* Student ID: 211504024
*/

struct Pair {
    int first;
    int second;
};

// Comparator to sort pairs based on the first element
bool compare(Pair a, Pair b) {
    return a.first < b.first;
}

// Function to find the longest chain of pairs using Dynamic Programming
int maxChainLen(Pair arr[], int n) {
    // Sort the pairs based on the first element using a custom comparator
    sort(arr, arr + n, compare);

    // Initialize the DP array
    vector<int> dp(n, 1); // Each pair can at least form a chain of itself, so start with 1

    // Build the DP table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j].second < arr[i].first && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;  // Update dp[i] if a longer chain ending at i is found
            }
        }
    }

    // The result is the maximum value in dp array
    return *max_element(dp.begin(), dp.end());
}

int main() {
    // Example 1
    Pair pairs1[] = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    int N1 = sizeof(pairs1) / sizeof(pairs1[0]);

    // Example 2
    Pair pairs2[] = { {5, 10}, {1, 11} };
    int N2 = sizeof(pairs2) / sizeof(pairs2[0]);

    int result1 = maxChainLen(pairs1, N1);
    int result2 = maxChainLen(pairs2, N2);

    cout << "Example 1\nInput: N = 5\nP[] = { (5, 24), (39, 60), (15, 28), (27, 40), (50, 90) }" << endl;
    cout << "Longest chain length: " << result1 << endl;
    cout << "\nExample 2\nInput: N = 2\nP[] = { (5, 10), (1, 11) }" << endl;
    cout << "Longest chain length: " << result2 << endl;

    return 0;
}
