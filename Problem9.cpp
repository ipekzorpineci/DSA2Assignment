#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
* Name: ipek
* Surname: Zorpineci
* Date: 10.05.2024
* Student ID: 211504024
*/

// Check if the current position is safe to explore
bool isSafe(int x, int y, vector<vector<bool>>& visited) {
    return x >= 0 && x < visited.size() && y >= 0 && y < visited[0].size() && !visited[x][y];
}

// DFS to search for words in the board
void dfs(vector<vector<char>>& board, int x, int y, vector<vector<bool>>& visited,
    set<string>& dictionary, string word, set<string>& result) {
    // Directions arrays for 8 possible moves
    static int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    static int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

    visited[x][y] = true;
    word += board[x][y];

    // If the current word is in the dictionary, add to result
    if (dictionary.find(word) != dictionary.end())
        result.insert(word);

    // Explore all 8 adjacent cells
    for (int dir = 0; dir < 8; ++dir) {
        int newX = x + dx[dir], newY = y + dy[dir];
        if (isSafe(newX, newY, visited)) {
            dfs(board, newX, newY, visited, dictionary, word, result);
        }
    }

    // Backtrack
    visited[x][y] = false;
}

vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& words) {
    set<string> dictionary(words.begin(), words.end()); // Using a set for fast lookup
    set<string> result; // Using a set to avoid duplicates and to maintain sorted order
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

    // Start from each cell
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            dfs(board, i, j, visited, dictionary, "", result);
        }
    }

    return vector<string>(result.begin(), result.end()); // Convert result set to vector
}

int main() {
    // Example 1
    vector<vector<char>> board1 = { {'C', 'A', 'P'}, {'A', 'N', 'D'}, {'T', 'I', 'E'} };
    vector<string> dictionary1 = { "CAT" };
    vector<string> result1 = wordBoggle(board1, dictionary1);
    cout << "Example 1\nN = 1\ndictionary = {CAT}\nR = 3, C = 3\nboard = {{C,A,P},{A,N,D},{T,I,E}}" << endl;
    cout << "Output: ";
    for (auto& word : result1) cout << word << " ";
    cout << endl;

    // Example 2
    vector<vector<char>> board2 = { {'G', 'I', 'Z'}, {'U', 'E', 'K'}, {'Q', 'S', 'E'} };
    vector<string> dictionary2 = { "GEEKS", "FOR", "QUIZ", "GO" };
    vector<string> result2 = wordBoggle(board2, dictionary2);
    cout << "\nExample 2\nN = 4\ndictionary = {GEEKS,FOR,QUIZ,GO}\nR = 3, C = 3\nboard = {G,I,Z},{U,E,K},{Q,S,E}}" << endl;
    cout << "Output: ";
    for (auto& word : result2) cout << word << " ";
    cout << endl;

    return 0;
}
