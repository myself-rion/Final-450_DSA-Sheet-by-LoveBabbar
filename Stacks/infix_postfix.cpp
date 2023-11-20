class Solution
{
public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        unordered_map<char, int> mp;
        mp['+'] = 1;
        mp['-'] = 1;
        mp['*'] = 2;
        mp['/'] = 2;
        mp['^'] = 3;
        mp['('] = -1;
        stack<char> st;
        string ans;

        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' and s[i] <= '9'))
            {
                ans.push_back(s[i]);
            }
            else if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (st.top() != '(')
                {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else
            {

                while (!st.empty() && mp[st.top()] >= mp[s[i]])
                {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};