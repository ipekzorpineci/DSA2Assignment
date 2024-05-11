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

struct Job {
    int id;
    int deadline;
    int profit;
};

// Comparator to sort jobs based on deadline
bool compare(Job a, Job b) {
    if (a.deadline == b.deadline)
        return a.profit > b.profit; // If deadlines are the same, sort by profit descending
    return a.deadline < b.deadline;
}

// Function to schedule jobs to maximize profit using Dynamic Programming
pair<int, int> JobScheduling(vector<Job>& jobs, int N) {
    // Sort jobs based on deadlines
    sort(jobs.begin(), jobs.end(), compare);

    // Create a DP array to store maximum profit at each time point
    int maxDeadline = 0;
    for (const auto& job : jobs) {
        if (job.deadline > maxDeadline) {
            maxDeadline = job.deadline;
        }
    }
    vector<int> dp(maxDeadline + 1, 0);

    // Update the DP table
    for (const auto& job : jobs) {
        for (int j = job.deadline; j > 0; j--) {
            if (dp[j] < dp[j - 1] + job.profit) {
                dp[j] = max(dp[j], dp[j - 1] + job.profit);
            }
        }
    }

    // Calculate the maximum profit and number of jobs done
    int maxProfit = 0, lastNonZero = -1;
    for (int i = 1; i <= maxDeadline; i++) {
        if (dp[i] > maxProfit) {
            maxProfit = dp[i];
            lastNonZero = i;
        }
    }

    // Count the number of jobs included in the maximum profit schedule
    int countJobs = 0;
    int profitTrack = maxProfit;
    for (int i = lastNonZero; i > 0; i--) {
        if (dp[i] != dp[i - 1]) {
            countJobs++;
            profitTrack -= jobs[i - 1].profit;
            if (profitTrack <= 0) break;
        }
    }

    return { countJobs, maxProfit };
}

int main() {
    // Example 1
    vector<Job> jobs1 = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };
    int N1 = 4;

    // Example 2
    vector<Job> jobs2 = { {1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15} };
    int N2 = 5;

    auto result1 = JobScheduling(jobs1, N1);
    auto result2 = JobScheduling(jobs2, N2);

    cout << "Example 1\nInput: N = 4\nJobs = { (1, 4, 20), (2, 1, 10), (3, 1, 40), (4, 1, 30) }" << endl;
    cout << "Output: " << result1.first << " " << result1.second << endl;
    cout << "\nExample2\nInput: N = 5\nJobs = { (1, 2, 100), (2, 1, 19), (3, 2, 27), (4, 1, 25), (5, 1, 15) }" << endl;
    cout << "Output: " << result2.first << " " << result2.second << endl;

    return 0;
}
