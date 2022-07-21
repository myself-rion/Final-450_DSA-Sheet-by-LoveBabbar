class Solution
{
    public:
    void sort012(int arr[], int n)
    {
        int low, mid, high;
        low = mid = 0;
        high = n - 1;
        while (mid <= high)
        {
            if (arr[mid] < arr[low])
            {
                swap(arr[mid], arr[low]);
                mid++;
                low++;
            }
            else if (arr[mid] > arr[high])
            {
                
                swap(arr[mid], arr[high]);
                mid++;
                high--;
            }
            else
            {
                mid++;
            }
        }
    }
    
};