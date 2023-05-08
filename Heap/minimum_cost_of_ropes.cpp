long long minCost(long long arr[], long long n)
{

    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    long long cost = 0;

    for (long long i = 0; i < n; i++)
    {
        minHeap.push(arr[i]);
    }

    while (minHeap.size() > 1)
    {
        long long a = minHeap.top();
        minHeap.pop();

        long long b = minHeap.top();
        minHeap.pop();

        cost += a + b;

        minHeap.push(a + b);
    }

    return cost;
}