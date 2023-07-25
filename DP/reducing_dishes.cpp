int solveMem(vector<int> &s, int index, int time, vector<vector<int>> &dp)
{
    if (index >= s.size())
        return 0;

    if (dp[index][time] != -1)
        return dp[index][time];

    int include = s[index] * (time + 1) + solveMem(s, index + 1, time + 1, dp);
    int exclude = 0 + solveMem(s, index + 1, time, dp);

    dp[index][time] = max(include, exclude);

    return dp[index][time];
}

int solveTab(vector<int> &s, int size)
{
    vector<vector<int>> dp(size + 1, vector<int>(size + 1, 0));

    for (int index = size - 1; index >= 0; index--)
    {
        for (int time = index; time >= 0; time--)
        {

            int include = s[index] * (time + 1) + dp[index + 1][time + 1];
            int exclude = 0 + dp[index + 1][time];

            dp[index][time] = max(include, exclude);
        }
    }

    return dp[0][0];
}

int maxSatisfaction(vector<int> &satisfaction)
{
    // main step
    sort(satisfaction.begin(), satisfaction.end());

    int n = satisfaction.size();

    // vector<vector<int>> dp(n+1,vector<int> (n+1,-1));

    // return solveMem(satisfaction,0,0, dp);

    return solveTab(satisfaction, n);
}