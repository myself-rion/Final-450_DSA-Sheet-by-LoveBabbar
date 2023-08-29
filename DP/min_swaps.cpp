class Solution
{
public:
    int solveMem(vector<int>& nums1, vector<int>& nums2, int index, int size, bool swapped){
        if(index>=size) return 0;

        if(dp[index][swapped]!=-1) return dp[index][swapped];

        int ans= INT_MAX;

        int prev1= nums1[index-1];
        int prev2= nums2[index-1];

        if(swapped) swap(prev1, prev2);

        if(nums1[index]> prev1 && nums2[index]> prev2){
            ans= solveMem(nums1, nums2, index+1,size,0);
        }
        if(nums1[index]> prev2 && nums2[index]> prev1){
            // gotta swap
            ans=min(ans,1+solveMem(nums1, nums2, index+1,size,1));
        }

        return dp[index][swapped]=ans;
    }

    int solveTab(vector<int> &nums1, vector<int> &nums2, int size)
    {
        vector<vector<int>> dp(size + 1, vector<int>(2, 0));

        for (int index = size - 1; index >= 1; index--)
        {
            for (int j = 1; j >= 0; j--)
            {

                int ans = INT_MAX;

                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                if (j) //if swapped in prev index
                    swap(prev1, prev2);

                if (nums1[index] > prev1 && nums2[index] > prev2)
                {
                    ans = dp[index + 1][0];
                }
                
                if (nums1[index] > prev2 && nums2[index] > prev1)
                {
                    // gotta swap
                    ans = min(ans, 1 + dp[index + 1][1]);
                }

                dp[index][j] = ans;
            }
        }

        return dp[1][0];
    }

    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        return solveTab(nums1, nums2, nums1.size());
    }
};