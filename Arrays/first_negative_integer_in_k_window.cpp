vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int n, long long int k)
{

    long long int firstNegativeIndex = 0;
    long long int firstNegativeNum;
    vector<long long int> ans;
    for (long long int i = k - 1; i < n; i++)
    {
        // condition to move the window
        while ((firstNegativeIndex < i) &&
               (firstNegativeIndex <= i - k || A[firstNegativeIndex] >= 0))
        {
            firstNegativeIndex++;
        }
        if (A[firstNegativeIndex] < 0)
        {
            ans.push_back(A[firstNegativeIndex]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}