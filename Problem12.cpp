#include <iostream>
#include <vector>
using namespace std;

/*
* Name: ipek
* Surname: Zorpineci
* Date: 10.05.2024
* Student ID: 211504024
*/

int numberSequence(int m, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize the sequences of length 1
    for (int j = 1; j <= m; j++) {
        dp[1][j] = 1; // There is exactly one sequence of length 1 ending with any j
    }

    // Fill the dp table
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k * 2 <= j; k++) { // seq[i] should be at least 2 * seq[i-1]
                dp[i][j] += dp[i - 1][k];
            }
        }
    }

    // Sum up all valid sequences of length n
    int sum = 0;
    for (int j = 1; j <= m; j++) {
        sum += dp[n][j];
    }

    return sum;
}

int main() {
    // Example 1
    int m1 = 10, n1 = 4;
    cout << "Example 1\nm = 10\nn = 4" << endl;
    cout << "Output: " << numberSequence(m1, n1) << endl;  

    // Example 2
    int m2 = 5, n2 = 2;
    cout << "\nExample 2\nm = 5\nn = 2" << endl;
    cout << "Output: " << numberSequence(m2, n2) << endl;  

    return 0;
}
