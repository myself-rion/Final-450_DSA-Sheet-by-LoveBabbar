class SortedStack
{
public:
    stack<int> s;
    void sort();
};

void pushNum(stack<int> &s, int x)
{
    // base condition
    if (s.empty() || (s.top() < x))
    {
        s.push(x);
        return;
    }
    // pop & sort
    int num = s.top();
    s.pop();
    pushNum(s, x);
    s.push(num);
}
void SortedStack ::sort()
{
    //    check if stack is empty
    if (s.empty())
    {
        return;
    }
    //pop all elements by recursion
    int num = s.top();
    s.pop();
    sort();
    // push them in sorted manner
    pushNum(s, num);
}