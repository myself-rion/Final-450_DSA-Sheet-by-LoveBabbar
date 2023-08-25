class Solution
{
private:
    long long solveMem(int faces, int dices, int target, vector<vector<long long>> &dp)
    {
        if (target < 0 || (dices <= 0 && target != 0) || (target <= 0 && dices != 0))
            return 0;

        if (dices == 0 && target == 0)
            return 1;

        if (dp[dices][target] != -1)
            return dp[dices][target];

        long long ans = 0;

        for (int i = 1; i <= faces; i++)
        {
            ans = ans + solveMem(faces, dices - 1, target - i, dp); // including possibilities & moving onto next dice
        }

        return dp[dices][target] = ans;
    }

    long long solveTab(int faces, int dices, int target)
    {

        vector<vector<long long>> dp(dices + 1, vector<long long>(target + 1, 0));

        dp[0][0] = 1;

        long long ans = 0;

        for (int j = 1; j <= dices; j++) //j--> dices
        {
            for (int k = 1; k <= target; k++) //k--> target
            {
                long long ans = 0;

                for (int i = 1; i <= faces; i++) //i--> faces
                {
                    if (k - i >= 0)
                        ans += dp[j - 1][k - i]; // including possibilities & moving onto next dice
                }
                dp[j][k] = ans;
            }
        }

        return dp[dices][target];
    }

public:
    long long noOfWays(int M, int N, int X)
    {

        return solveTab(M, N, X);
    }
};