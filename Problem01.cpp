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

struct Meeting {
    int start;
    int end;
};

// Comparator function to sort meetings by end time
bool compareMeeting(const Meeting& m1, const Meeting& m2) {
    return m1.end < m2.end;
}

// Function to find the maximum number of meetings
int maxMeetings(vector<int>& start, vector<int>& end, int N) {
    vector<Meeting> meetings(N);

    // Create a list of meetings
    for (int i = 0; i < N; ++i) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
    }

    // Sort the meetings by their end times
    sort(meetings.begin(), meetings.end(), compareMeeting);

    int count = 0; // To count the number of meetings
    int lastEndTime = -1; // To keep track of the end time of the last attended meeting

    // Iterate through the sorted meetings
    for (const auto& meeting : meetings) {
        // Check if the meeting can be attended
        if (meeting.start > lastEndTime) {
            lastEndTime = meeting.end; // Update the last end time
            count++; // Increment the count
        }
    }

    return count; // Return the maximum number of meetings
}

int main() {
    // Example 1
    vector<int> start1 = { 1, 3, 0, 5, 8, 5 };
    vector<int> end1 = { 2, 4, 6, 7, 9, 9 };
    int N1 = 6;

    // Example 2
    vector<int> start2 = { 10, 12, 20 };
    vector<int> end2 = { 20, 25, 30 };
    int N2 = 3;

    int result1 = maxMeetings(start1, end1, N1);
    int result2 = maxMeetings(start2, end2, N2);

    cout << "Example 1\nInput: N = 6\nstart[] = {1, 3, 0, 5, 8, 5}\nend[] = {2, 4, 6, 7, 9, 9}" << endl;
    cout << "Maximum number of meetings: " << result1 << endl;
    cout << "\nExample 2\nInput: N = 3\nstart[] = {10, 12, 20}\nend[] = {20, 25, 30}" << endl;
    cout << "Maximum number of meetings: " << result2 << endl;

    return 0;
}
