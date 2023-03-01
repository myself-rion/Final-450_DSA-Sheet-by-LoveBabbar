void solve(stack<int> &mystack, int x)
{
    if (mystack.empty())
    {
        mystack.push(x);
        return;
    }
    int num = mystack.top();
    mystack.pop();
    solve(mystack, x);
    mystack.push(num);
}
stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    // Write your code here.
    solve(myStack, x);
    return myStack;
}