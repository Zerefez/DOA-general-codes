#include <iostream>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

// Function to check if the current position is valid
bool isSafe(int row, int col, char maze[ROWS][COLS], bool visited[ROWS][COLS]) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] != 'X' && !visited[row][col]);
}

// Recursive function to find the path to 'E'
bool findPath(int row, int col, char maze[ROWS][COLS], bool visited[ROWS][COLS]) {
    // Base case: If the current position is 'E'
    if (maze[row][col] == 'E') {
        return true;
    }

    // Check if the current position is safe to proceed
    if (!isSafe(row, col, maze, visited)) {
        return false;
    }

    // Mark the cell as visited
    visited[row][col] = true;

    // Explore all four possible directions
    // Move Down
    if (findPath(row + 1, col, maze, visited)) {
        return true;
    }
    // Move Up
    if (findPath(row - 1, col, maze, visited)) {
        return true;
    }
    // Move Right
    if (findPath(row, col + 1, maze, visited)) {
        return true;
    }
    // Move Left
    if (findPath(row, col - 1, maze, visited)) {
        return true;
    }

    // Unmark the cell (backtrack)
    visited[row][col] = false;
    return false;
}

int main() {
    char maze[ROWS][COLS] = {
        {'X', 'X', 'X', 'X', 'X'},
        {'X', ' ', ' ', ' ', 'X'},
        {'X', ' ', 'X', ' ', 'X'},
        {'X', ' ', 'X', ' ', 'X'},
        {'X', 'E', 'X', 'X', 'X'}
    };

    bool visited[ROWS][COLS] = { false }; // Array to track visited positions

    // Start the search from (1, 1)
    if (findPath(1, 1, maze, visited)) {
        cout << "Path to 'E' exists!" << endl;
    }
    else {
        cout << "No path to 'E' exists." << endl;
    }

    // Start the search from (1, 4)
    if (findPath(1, 4, maze, visited)) {
        cout << "Path to 'E' exists!" << endl;
    }
    else {
        cout << "No path to 'E' exists." << endl;
    }

    // Start the search from (4, 4)
    if (findPath(4, 4, maze, visited)) {
        cout << "Path to 'E' exists!" << endl;
    }
    else {
        cout << "No path to 'E' exists." << endl;
    }

    // Start the search from (4, 1)
    if (findPath(4, 1, maze, visited)) {
        cout << "Path to 'E' exists!" << endl;
    }
    else {
        cout << "No path to 'E' exists." << endl;
    }

    return 0;
}
