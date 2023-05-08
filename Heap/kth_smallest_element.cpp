int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int> pq; // max heap

    // step 1 : creating a heap with first k elements of an Array
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // step 2 : comparing if there's any element smaller than root of max heap

    for (int i = k; i <= r; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // root of max heap is the kth samllest element
    return pq.top();
}

// use min heap for kth largest element