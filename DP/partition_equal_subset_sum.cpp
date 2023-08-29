int solveMem(int arr[], int index, int size, int target, vector<vector<int>> &dp)
{
    if (index >= size || target < 0)
        return 0;
    if (target == 0)
        return 1;

    if (dp[index][target] != -1)
        return dp[index][target];

    int include = solveMem(arr, index + 1, size, target - arr[index], dp);
    int exclude = solveMem(arr, index + 1, size, target, dp);

    return dp[index][target] = include or exclude;
}

int solveTab(int arr[], int size, int target)
{

    vector<vector<int>> dp(size + 1, vector<int>(target + 1, 0));

    for (int i = 0; i <= size; i++)
    {
        dp[i][0] = 1;
    }

    for (int index = size - 1; index >= 0; index--)
    {

        for (int j = 0; j <= target; j++)
        {

            int include = 0;

            if (j - arr[index] >= 0)
            {
                include = dp[index + 1][j - arr[index]];
            }

            int exclude = dp[index + 1][j];
            dp[index][j] = include or exclude;
        }
    }

    return dp[0][target];
}

int equalPartition(int N, int arr[])
{
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
    }

    if (sum & 1 == 1) //if it comes out odd then equal partition isn't possible
    {
        return 0;
    }

    int target = sum / 2;
    // vector<vector<int>> dp(N+1,vector<int>(target+1, -1));
    return solveTab(arr, N, target);
}