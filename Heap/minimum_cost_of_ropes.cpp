long long minCost(long long arr[], long long n)
{

    priority_queue<long long, vector<long long>, greater<long long>> minHeap; //creating min Heap because top of min heap is the smallest element
    long long cost = 0;

    for (long long i = 0; i < n; i++)
    {
        minHeap.push(arr[i]);
    }

    while (minHeap.size() > 1)
    {
        //popping top 2 minimum elements
        long long a = minHeap.top();
        minHeap.pop();

        long long b = minHeap.top();
        minHeap.pop();

        cost += a + b;
        
        // pushing the sum in heap
        minHeap.push(a + b);
    }

    return cost;
}
