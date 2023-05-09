private:
void heapify(vector<int> &arr, int i, int size)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[largest] < arr[left])
    {
        largest = left;
    }
    
    if (right < size && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, largest, size);
    }
}

public:
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    vector<int> ans;

    for (auto i : a)
    {
        ans.push_back(i);
    }
    for (auto i : b)
    {
        ans.push_back(i);
    }

    int size = ans.size();

    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        heapify(ans, i, size);
    }

    return ans;
}
