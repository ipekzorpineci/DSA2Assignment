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

// Comparator to sort jobs based on profit in descending order
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

// Function to schedule jobs to maximize profit
pair<int, int> JobScheduling(vector<Job>& jobs, int N) {
    // Sort jobs based on decreasing order of profit
    sort(jobs.begin(), jobs.end(), compare);

    // Find the maximum deadline to size the vector
    int maxDeadline = 0;
    for (const auto& job : jobs) {
        if (job.deadline > maxDeadline) {
            maxDeadline = job.deadline;
        }
    }

    // Create a vector to track used time slots
    vector<bool> slot(maxDeadline + 1, false);

    int countJobs = 0, totalProfit = 0;

    // Iterate over sorted jobs
    for (const auto& job : jobs) {
        // Find a free slot for this job from its deadline to the start
        for (int j = min(job.deadline, maxDeadline); j > 0; j--) {
            if (!slot[j]) {
                // Slot found
                slot[j] = true;
                countJobs++;
                totalProfit += job.profit;
                break;
            }
        }
    }

    return { countJobs, totalProfit };
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
