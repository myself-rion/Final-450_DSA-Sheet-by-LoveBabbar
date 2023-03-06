class Solution
{
public:
    int checkRedundancy(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                st.push(ch);
            }
            else
            {
                if (ch == ')')
                {
                    int redundant = 1;
                    while (st.top() != '(')
                    {
                        char top = st.top();
                        if (top == '+' || top == '-' || top == '*' || top == '/')
                        {
                            redundant = 0;
                        }
                        st.pop();
                    }
                    if (redundant == 1)
                    {
                        return 1;
                    }
                    st.pop();
                }
            }
        }
        return 0;
    }
};