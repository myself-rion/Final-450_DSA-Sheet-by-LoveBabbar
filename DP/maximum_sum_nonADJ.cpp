int memo(int arr[], int n, vector<int> &dp)
{
    if (n < 0) return 0;
    if (n == 0) return arr[0];

    if (dp[n] != -1) return dp[n];

    int include = memo(arr, n - 2, dp) + arr[n];
    int exclude = memo(arr, n - 1, dp);

    dp[n] = max(include, exclude);
    return dp[n];
} //TC: O(N), SC: O(N)+O(N)

int tabu(int arr[], int n){

    if(n<0) return 0;

    vector<int> dp(n);
    dp[0]= arr[0];

    for (int i = 1; i < n; i++)
    {
        int in= arr[i] + dp[i-2];
        int ex=  dp[i-1];

        dp[i]= max(in,ex);
    }

    return dp[n-1];
} //TC: O(N), SC: O(N)

int optimal(int arr[], int n){

    if(n<0) return 0;

    int prev2 =0; 
    int prev1= arr[0];

    for (int i = 1; i < n; i++)
    {
        int in= arr[i] +prev2;
        int ex=  prev1;

        int ans= max(in,ex);

        prev2= prev1;
        prev1= ans;
    }

    return prev1;
} //TC: O(N), SC: O(1)



int FindMaxSum(int arr[], int n)
{
    vector<int> dp(n + 1, -1);
    
    int memorization= memo(arr, n - 1, dp);

    int tabular= tabu(arr, n);

    int optimal= optimal(arr, n);

    return optimal;
}