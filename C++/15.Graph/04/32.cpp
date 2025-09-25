// flyode warshell

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void flolydeWarshell(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int node = 0; node < n; node++)
    {
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (matrix[row][node] != 1e9 && matrix[node][col] != 1e9)
                {
                    matrix[row][col] = min(matrix[row][col], matrix[row][node] + matrix[node][col]);
                }
            }
        }
    }
}

int main() {}