class Solution
{
   public:
    int findSum(int A[], int N)
    {
    	sort(A,A+N);
    	int sum_of_min_max = A[0]+A[N-1];
    	return sum_of_min_max;
    }

};