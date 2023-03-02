class Solution
{
private:
    void insertAtBottom(stack<int> &s, int x)
    {
        if (s.empty())
        {
            s.push(x);
            return;
        }
        int num = s.top();
        s.pop();
        insertAtBottom(s, x);
        s.push(num);
    }

public:
    void Reverse(stack<int> &st)
    {
        if (st.empty())
        {
            return;
        }
        // store the top most value & remove it
        int num = st.top();
        st.pop();
        // recursive leap of faith will reverse rest of the stack
        Reverse(st);
        // after the stack is reversed, insert the num element at the bottom to complete reversing
        insertAtBottom(st, num);
    }
};