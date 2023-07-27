int findPivot(int A[], int l, int h)
{
    int mid = l + (h - l) / 2;

    while (l < h)
    {
        if (A[mid] >= A[0])
        {
            l = mid + 1;
        }
        else
        {
            h = mid;
        }

        mid = l + (h - l) / 2;
    }
    return l;
}

int BinarySearch(int A[], int l, int h, int key)
{
    int mid = l + (h - l) / 2;

    while (l <= h)
    {
        if (A[mid] == key)
        {
            return mid;
        }
        else if (A[mid] > key)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }

        mid = l + (h - l) / 2;
    }
    return -1;
}
int search(int A[], int l, int h, int key)
{
    int pivot = findPivot(A, l, h);

    if (A[pivot] <= key && key <= A[h])
    {
        return BinarySearch(A, pivot, h, key);
    }
    else
    {
        return BinarySearch(A, l, pivot - 1, key);
    }
}

// T.C: O(log n)