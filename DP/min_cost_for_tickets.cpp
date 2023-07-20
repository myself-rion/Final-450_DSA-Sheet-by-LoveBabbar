int solveMem(vector<int> &days, vector<int> &costs, int n, int index, vector<int> &dp)
{
    if (index >= n)
        return 0;

    if (dp[index] != -1)
        return dp[index];
    // 1 day pass
    int op1 = costs[0] + solveMem(days, costs, n, index + 1, dp);

    // 7 days pass
    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;

    int op2 = costs[1] + solveMem(days, costs, n, i, dp);

    // 30 days pass
    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;

    int op3 = costs[2] + solveMem(days, costs, n, i, dp);

    dp[index] = min(op1, min(op2, op3));
    return dp[index];
}
int solveTab(vector<int> &days, vector<int> &costs, int n)
{

    vector<int> dp(n + 1, INT_MAX);

    dp[n] = 0;

    for (int k = n - 1; k >= 0; k--)
    {
        // 1 day pass
        int op1 = costs[0] + dp[k + 1];

        int i;
        // 7 days pass
        for (i = k; i < n && days[i] < days[k] + 7; i++)
            ;
        int op2 = costs[1] + dp[i];

        // 30 days pass
        for (i = k; i < n && days[i] < days[k] + 30; i++)
            ;
        int op3 = costs[2] + dp[i];

        dp[k] = min(op1, min(op2, op3));
    }

    return dp[0];
}
int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int n = days.size();
    // vector<int> dp(n+1, -1);
    // return solveMem(days, costs, n, 0, dp);
    return solveTab(days, costs, n);
}