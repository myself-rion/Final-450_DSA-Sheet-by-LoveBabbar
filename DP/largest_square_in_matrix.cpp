int solveMem(int n, int m, vector<vector<int>> &ma, int &maximum, vector<vector<int>> &dp, int row, int col)
{
    if (row >= n || col >= m)
        return 0;

    if (dp[row][col] != -1)
        return dp[row][col];

    int horizontal = solveMem(n, m, ma, maximum, dp, row, col + 1);
    int vertical = solveMem(n, m, ma, maximum, dp, row + 1, col);
    int diagonal = solveMem(n, m, ma, maximum, dp, row + 1, col + 1);

    if (ma[row][col] == 1)
    {
        dp[row][col] = 1 + min(horizontal, min(vertical, diagonal));
        maximum = max(maximum, dp[row][col]);
        return dp[row][col];
    }
    else
    {
        return dp[row][col] = 0;
    }
}
int maxSquare(int n, int m, vector<vector<int>> mat)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maximum = 0;

    solveMem(n, m, mat, maximum, dp, 0, 0);

    return maximum;
}