#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
* Name: ipek
* Surname: Zorpineci
* Date: 10.05.2024
* Student ID: 211504024
*/

// Helper function to check if a string segment is a valid IP address part
bool isValid(const string& s) {
    if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0')) return false;
    int num = stoi(s);
    return num >= 0 && num <= 255;
}

// Recursive function to generate all valid IP addresses
void backtrack(const string& s, vector<string>& result, string current, int start, int partNum) {
    if (partNum == 4 && start == s.length()) {
        result.push_back(current.substr(0, current.length() - 1));  // Remove the last dot and add to results
        return;
    }

    if (partNum == 4 || start >= s.length()) return;  // Exceeds part limit or length of string, back out

    for (int len = 1; len <= 3 && start + len <= s.length(); ++len) {
        string part = s.substr(start, len);
        if (isValid(part)) {
            backtrack(s, result, current + part + '.', start + len, partNum + 1);
        }
    }
}

// Function to generate all valid IP addresses from a string
vector<string> genIp(string S) {
    vector<string> result;
    if (S.length() < 4 || S.length() > 12) {
        return { "-1" };  // Return "-1" when it's not possible to generate any IP address
    }
    backtrack(S, result, "", 0, 0);
    return result.empty() ? vector<string>{"-1"} : result;
}

int main() {
    // Example 1
    string S1 = "1111";
    vector<string> result1 = genIp(S1);
    cout << "Valid IPs from '" << S1 << "':" << endl;
    for (const auto& ip : result1) {
        cout << ip << endl;
    }

    // Example 2
    string S2 = "55";
    vector<string> result2 = genIp(S2);
    cout << "\nValid IPs from '" << S2 << "':" << endl;
    if (result2.front() == "-1") {
        cout << "-1" << endl;  // No valid IP addresses
    }
    else {
        for (const auto& ip : result2) {
            cout << ip << endl;
        }
    }

    return 0;
}

