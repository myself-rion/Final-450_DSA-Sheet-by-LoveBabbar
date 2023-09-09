int solveMem(int n, vector<int> &dp)
{
    if (n <= 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    int ans = 0;

    //root node
    for (int i = 1; i <= n; i++)
    {
        ans += solve(i - 1, dp) * solve(n - i, dp);
    }
    return dp[n] = ans;
}

int solveTab(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    
    //number of node
    for (int i = 2; i <= n; i++)
    {
        int ans = 0;
        //root node
        for (int j = 1; j <= i; j++)
        {
            ans += dp[i - j] * dp[j - 1];
        }
        dp[i] = ans;
    }

    return dp[n];
}
int numTrees(int n)
{
    // vector<int> dp(n+1,-1);
    return solveTab(n);
}
//can be calculated using catalan number formula : (2n)!/( (n+1)! * n)