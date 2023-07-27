long long int findSqr(long long int num)
{
    long long int s = 0; //start to end is the search space
    long long int e = num;
    long long int mid = s + (e - s) / 2;
    long long ans = 0;
    while (s <= e)
    {
        if (mid * mid <= num) // reducing search space, eg: if 5*5= 25 <= 36 then we will search between 5-6
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1; //if 18*18> num then the num will lie between 0-17
        }

        mid = s + (e - s) / 2;
    }

    return ans;
}
long long int floorSqrt(long long int x)
{
    return findSqr(x);
}

// T.C : O(log n)