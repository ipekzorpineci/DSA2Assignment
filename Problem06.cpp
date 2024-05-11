#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
* Name: ipek
* Surname: Zorpineci
* Date: 10.05.2024
* Student ID: 211504024
*/

void solve(int x, int y, vector<vector<int>>& m, int n, vector<string>& paths, string path, vector<vector<bool>>& visited) {
    // If reach the bottom-right corner, add the path to results
    if (x == n - 1 && y == n - 1) {
        paths.push_back(path);
        return;
    }

    // Mark the current cell as visited
    visited[x][y] = true;

    // Move Down
    if (x + 1 < n && !visited[x + 1][y] && m[x + 1][y] == 1) {
        solve(x + 1, y, m, n, paths, path + 'D', visited);
    }

    // Move Left
    if (y - 1 >= 0 && !visited[x][y - 1] && m[x][y - 1] == 1) {
        solve(x, y - 1, m, n, paths, path + 'L', visited);
    }

    // Move Right
    if (y + 1 < n && !visited[x][y + 1] && m[x][y + 1] == 1) {
        solve(x, y + 1, m, n, paths, path + 'R', visited);
    }

    // Move Up
    if (x - 1 >= 0 && !visited[x - 1][y] && m[x - 1][y] == 1) {
        solve(x - 1, y, m, n, paths, path + 'U', visited);
    }

    // Unmark the current cell as visited (backtrack)
    visited[x][y] = false;
}

vector<string> printPath(int n, vector<vector<int>> m) {
    vector<string> paths;
    if (m[0][0] == 0 || m[n - 1][n - 1] == 0) // If start or end is blocked
        return paths;

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string path = "";
    solve(0, 0, m, n, paths, path, visited);

    sort(paths.begin(), paths.end()); // Ensure the paths are in lexicographical order
    return paths;
}

int main() {
    // Example 1
    int N1 = 4;
    vector<vector<int>> m1 = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    // Example 2
    int N2 = 2;
    vector<vector<int>> m2 = {
        {1, 0},
        {1, 0}
    };

    auto paths1 = printPath(N1, m1);
    auto paths2 = printPath(N2, m2);

    cout << "Example 1\nInput: N = 4\nm[][] =\n{ 1, 0, 0, 0 }\n{ 1, 1, 0, 1 }\n{ 1, 1, 0, 0 }\n{ 0, 1, 1, 1 }" << endl;
    cout << "Paths Output : " ;
    if (paths1.empty()) cout << "-1" << endl;
    else {
        for (const auto& p : paths1) cout << p << " ";
        cout << endl;
    }

    cout << "\nExample 2\nInput: N = 2\nm[][] =\n{ 1, 0 }\n{ 1, 0 }" << endl;
    cout << "Paths Output: " ;
    if (paths2.empty()) cout << "-1" << endl;
    else {
        for (const auto& p : paths2) cout << p << " ";
        cout << endl;
    }

    return 0;
}
