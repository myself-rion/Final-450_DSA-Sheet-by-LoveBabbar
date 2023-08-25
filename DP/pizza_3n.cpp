class Solution
{
public:
    int solveMem(int index, vector<int> &slices, int n, int size, vector<vector<int>> &dp)
    {
        if (n == 0 || index > size)
        {
            return 0;
        }

        if (dp[index][n] != -1)
            return dp[index][n];

        int take = slices[index] + solveMem(index + 2, slices, n - 1, size, dp);
        int ignore = solveMem(index + 1, slices, n, size, dp);

        return dp[index][n] = max(take, ignore);
    }

    int solveTab(vector<int> &slices)
    {
        int k = slices.size();

        vector<vector<int>> dp1(k + 2, vector<int>(k + 2, 0)); //k+2 because index+2 will point to k & will give runtime error
        vector<vector<int>> dp2(k + 2, vector<int>(k + 2, 0));

        for (int index = k - 2; index >= 0; index--)
        {
            for (int n = 1; n <= k / 3; n++)
            {
                int take = slices[index] + dp1[index + 2][n - 1];
                int ignore = dp1[index + 1][n];

                dp1[index][n] = max(take, ignore);
            }
        }

        int case1 = dp1[0][k / 3];

        for (int index = k - 1; index >= 1; index--)
        {
            for (int n = 1; n <= k / 3; n++)
            {
                int take = slices[index] + dp2[index + 2][n - 1];
                int ignore = dp2[index + 1][n];

                dp2[index][n] = max(take, ignore);
            }
        }
        int case2 = dp2[1][k / 3];

        return max(case1, case2);
    }


    int maxSizeSlices(vector<int> &slices)
    {
        /*Memorization
        int k= slices.size();
        vector<vector<int>> dp1(k, vector<int>(k, -1));
        vector<vector<int>> dp2(k, vector<int>(k, -1));

        int first_slice= solve(0, slices, k/3, k-2, dp1);
        int second_slice= solve(1, slices, k/3, k-1, dp2);
        return max(first_slice, second_slice);
        */

        // Tabulation

        return solveTab(slices);
    }
};