// using recursion

void solve(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int element = q.front();
    q.pop();
    solve(q);
    q.push(element);
}
queue<int> rev(queue<int> q)
{
    solve(q);
    return q;
}