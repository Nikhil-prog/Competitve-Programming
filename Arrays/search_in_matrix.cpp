/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
    Problem statement:
    Write an efficient algorithm that searches for a value target in
    an m x n integer matrix matrix. This matrix has the following properties:

    1.Integers in each row are sorted in ascending from left to right.
    2.Integers in each column are sorted in ascending from top to bottom.

    Problem Link: https://leetcode.com/problems/search-a-2d-matrix-ii/
*/

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();
    int i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        if (matrix[i][j] == target)
        {
            return true;
        }
        else if (matrix[i][j] > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix{
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};
    cout << "The target " << 21 << " existance is : " << searchMatrix(matrix, 21) << endl;
    cout << "The target " << 25 << " existance is : " << searchMatrix(matrix, 25) << endl;
    return 0;
}