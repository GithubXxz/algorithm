//岛屿问题
//岛屿问题
//岛屿问题

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

//感染过程 时间复杂度比较低
void infect(vector<vector<int>> &matrix, int i, int j, int N, int M)
{
    if (i < 0 || i >= N || j < 0 || j >= M || matrix[i][j] != 1)
    {
        return;
    } 
    // i j 没有越界并且当前的位置是1
    matrix[i][j] = 2;
    infect(matrix, i + 1, j, N, M);
    infect(matrix, i - 1, j, N, M);
    infect(matrix, i, j + 1, N, M);
    infect(matrix, i, j - 1, N, M);
}

int countIslands(vector<vector<int>> matrix)
{
    if (matrix.size() == 0 || matrix[0].size() == 0)
    {
        return 0;
    }
    int N = matrix.size();
    int M = matrix[0].size();
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (matrix[i][j] == 1)
            {
                res++;
                infect(matrix, i, j, N, M);
            }
        }
    }
    return res;
}

int main()
{
    system("chcp 65001");
    vector<vector<int>> matrix = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 1, 1, 1, 0},
        {0, 1, 1, 1, 0, 0, 0, 1, 0},
        {0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    cout << "岛屿的个数为 " << countIslands(matrix) << endl;
    system("pause");
    return 0;
}