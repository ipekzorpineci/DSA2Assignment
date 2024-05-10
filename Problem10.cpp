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

int kthElement(int arr1[], int arr2[], int n, int m, int k) {
    // Ensure arr1 is the smaller array to improve efficiency
    if (n > m) {
        return kthElement(arr2, arr1, m, n, k);
    }

    int low = max(0, k - m), high = min(k, n);

    while (low <= high) {
        int cut1 = (low + high) >> 1; // Cut on the first array
        int cut2 = k - cut1;          // Cut on the second array

        int left1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];

        int right1 = cut1 == n ? INT_MAX : arr1[cut1];
        int right2 = cut2 == m ? INT_MAX : arr2[cut2];

        // Correct partition
        if (left1 <= right2 && left2 <= right1) {
            return max(left1, left2);
        }
        else if (left1 > right2) {
            high = cut1 - 1;
        }
        else {
            low = cut1 + 1;
        }
    }
    return 1; // Return a default value (This line should never be executed)
}

int main() {
    // Example 1
    int arr1[] = { 2, 3, 6, 7, 9 };
    int arr2[] = { 1, 4, 8, 10 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k1 = 5;
    cout << "Example 1\nint arr1[] = { 2, 3, 6, 7, 9 }\nint arr2[] = { 1, 4, 8, 10 }" << endl;
    cout << "The " << k1 << "th element is " << kthElement(arr1, arr2, n1, n2, k1) << endl;

    // Example 2
    int arr3[] = { 100, 112, 256, 349, 770 };
    int arr4[] = { 72, 86, 113, 119, 265, 445, 892 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    int k2 = 7;
    cout << "\nExample 2\nint arr1[] = { 100, 112, 256, 349, 770 }\nint arr2[] = { 72, 86, 113, 119, 265, 445, 892 }" << endl;
    cout << "The " << k2 << "th element is " << kthElement(arr3, arr4, n3, n4, k2) << endl;

    return 0;
}
