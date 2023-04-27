void heapify(vector<int> &arr, int i, int size)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[smallest] > arr[left])
    {
        smallest = left;
    }
    if (right < size && arr[smallest] > arr[right])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify(arr, smallest, size);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int size = arr.size();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, i, size);
    }

    return arr;
}