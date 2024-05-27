#include <iostream>
#include <vector>
using namespace std;

bool is_valid(int x, int y, int N, int M)
{
    return (x >= 0 && x < N && y >= 0 && y < M);
}

bool dfs(vector<vector<char>> &matrix, string word, int x, int y, vector<vector<bool>> &visited)
{
    if (word.empty())
    {
        return true;
    }

    if (!is_valid(x, y, matrix.size(), matrix[0].size()) || visited[x][y] || matrix[x][y] != word[0])
    {
        return false;
    }

    visited[x][y] = true;

    // Check all possible neighbors
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < 8; i++)
    {
        if (dfs(matrix, word.substr(1), x + dx[i], y + dy[i], visited))
        {
            return true;
        }
    }

    visited[x][y] = false; // Backtrack
    return false;
}

bool find_path(vector<vector<char>> &matrix)
{
    string word = "CODINGNINJA";
    int N = matrix.size();
    int M = matrix[0].size();
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (matrix[i][j] == 'C' && dfs(matrix, word.substr(1), i, j, visited))
            {
                return true;
            }
        }
    }

    return false;
}
bool valid(int i, int j, vector<vector<int>> matrix)
{
    return (i < matrix.size() && i >= 0 && j < matrix[0].size() && j >= 0);
}
bool valid2(int i, int j, vector<vector<char>> matrix)
{
    return (i < matrix.size() && i >= 0 && j < matrix[0].size() && j >= 0);
}
int count_ones(vector<vector<int>> matrix, int i, int j, vector<vector<bool>> visited)
{
    visited[i][j] = true;
    int a = 0, b = 0, c = 0, d = 0;
    if (valid(i - 1, j, matrix) && matrix[i - 1][j] && !visited[i - 1][j])
        a = count_ones(matrix, i - 1, j, visited);
    if (valid(i, j - 1, matrix) && matrix[i][j - 1] && !visited[i][j - 1])
        b = count_ones(matrix, i, j - 1, visited);
    if (valid(i + 1, j, matrix) && matrix[i + 1][j] && !visited[i + 1][j])
        c = count_ones(matrix, i + 1, j, visited);
    if (valid(i, j + 1, matrix) && matrix[i][j + 1] && !visited[i][j + 1])
        d = count_ones(matrix, i, j + 1, visited);
    return a + b + c + d + 1;
}
int size(vector<vector<int>> matrix, int N)
{
    vector<vector<bool>> visited(N, vector<bool>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = false;
        }
    }
    int maxi = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (matrix[i][j] && !visited[i][j])
                maxi = max(maxi, count_ones(matrix, i, j, visited));
    return maxi;
}
bool check_cycle(vector<vector<char>> matrix, vector<vector<bool>> visited, int i, int j, vector<vector<bool>> start, int n)
{
    visited[i][j] = true;
    for (int p = -1; p < 2; p++)
        for (int q = -1; q < 2; q++)
            if (p != q && valid2(i - p, j - q, matrix) && matrix[i][j] == matrix[i - p][j - q] && start[i - p][j - q] && n > 3)
                return true;
    for (int p = -1; p < 2; p++)
        for (int q = -1; q < 2; q++)
            if (p != q && valid2(i - p, j - q, matrix) && matrix[i][j] == matrix[i - p][j - q] && !visited[i - p][j - q])
                if (check_cycle(matrix, visited, i - p, j - q, start, n + 1))
                    return true;
    return false;
}
bool cycle(vector<vector<char>> matrix)
{
    int N = matrix.size(), M = matrix[0].size();
    vector<vector<bool>> visited(N, vector<bool>(M));
    vector<vector<bool>> starting(N, vector<bool>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = false;
            starting[i][j] = false;
        }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (!visited[i][j])
            {
                starting[i][j] = true;
                if (check_cycle(matrix, visited, i, j, starting, 1))
                    return true;
            }
    return false;
}
bool exist(vector<vector<char>> matrix, vector<vector<bool>> visited, int i, int j, string s)
{
    if (s.size() == 0)
        return true;
    visited[i][j] = true;
    for (int p = -1; p < 2; p++)
        for (int q = -1; q < 2; q++)
            if (p || q)
                if (valid2(i + p, j + q, matrix) && matrix[i + p][j + q] == s[0])
                    if (exist(matrix, visited, i + p, j + q, s.substr(1)))
                        return true;
    return false;
}
bool coding_ninjas(vector<vector<char>> matrix)
{
    int N = matrix.size(), M = matrix[0].size();
    vector<vector<bool>> visited(N, vector<bool>(M));
    // vector<vector<bool>> starting(N, vector<bool>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = false;
            // starting[i][j]=false;
        }
    }
    string s = "CODINGNINJA";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (matrix[i][j] == s[0])
            {
                // starting[i][j]=true;
                if (exist(matrix, visited, i, j, s.substr(1)))
                    return true;
            }
    return false;
}
int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<char>> matrix(N, vector<char>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << coding_ninjas(matrix);
}
