// Using Recursion 
void solve(queue<int> &q, int k, int count)
{
    if (count == k)
    {
        return;
    }

    int element = q.front();
    q.pop();
    solve(q, k, count + 1);
    q.push(element);
}
queue<int> modifyQueue(queue<int> q, int k)
{
    // add code here.
    int count = 0;
    solve(q, k, count);
    // non reversed elements are on front that's why pop them & put them back
    for (int i = 0; i < q.size() - k; i++)
    {
        int element = q.front();
        q.pop();
        q.push(element);
    }
    return q;
}