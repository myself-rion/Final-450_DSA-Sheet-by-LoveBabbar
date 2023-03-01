class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                // avoids poppping an empty stack
                if (st.empty())
                {
                    return false;
                }
                // checks characters
                else if (st.top() == '(' && s[i] == ')' || st.top() == '{' && s[i] == '}' || st.top() == '[' && s[i] == ']')
                {
                    st.pop();
                }
                // unmatched char
                else
                {
                    return false;
                }
            }
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};