#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/*
* Name: ipek
* Surname: Zorpineci
* Date: 10.05.2024
* Student ID: 211504024
*/

bool isFeasible(int mid, int M, vector<int>& pages, int N) {
    int count = 1;  // Start with one student
    int sum = 0;    // Sum of pages

    // Try to allocate pages to students keeping within the maximum 'mid' pages
    for (int i = 0; i < N; ++i) {
        // If adding this book exceeds 'mid', allocate to the next student
        if (sum + pages[i] > mid) {
            count++;        // One more student
            sum = pages[i]; // Reset sum for the new student
            if (count > M || pages[i] > mid) // Too many students or a single book too large
                return false;
        }
        else {
            sum += pages[i]; // Add pages to the current student
        }
    }
    return true;
}

int findPages(vector<int>& pages, int N, int M) {
    if (N < M) return -1; // Less books than students, not feasible

    int left = *max_element(pages.begin(), pages.end()); // At least one book needs to be assigned, pick the largest book
    int right = accumulate(pages.begin(), pages.end(), 0); // At most all books can be assigned to one student

    int result = right; // Start with the maximum possible value

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isFeasible(mid, M, pages, N)) {
            result = mid; // This 'mid' could be our answer
            right = mid - 1; // Try for a smaller maximum
        }
        else {
            left = mid + 1; // Increase 'mid' as we need more capacity
        }
    }
    return result;
}

int main() {
    // Example 1
    vector<int> pages1 = { 12, 34, 67, 90 };
    int N1 = 4, M1 = 2;
    cout << "Example 1\nN = 4\nA[] = {12,34,67,90}\nM = 2" << endl;
    cout << "Output: " << findPages(pages1, N1, M1) << endl;

    // Example 2
    vector<int> pages2 = { 15, 17, 20 };
    int N2 = 3, M2 = 2;
    cout << "\nExample 2\nN = 3\nA[] = {15,17,20}\nM = 2" << endl;
    cout << "Output: " << findPages(pages2, N2, M2) << endl;

    return 0;
}
