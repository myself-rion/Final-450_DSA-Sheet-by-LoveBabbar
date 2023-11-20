// User function Template for C++

class Solution
{
public:
    int maxLength(string S)
    {
        if (S.length() == 1)
            return 0;
        stack<int> st;
        st.push(-1); //handling cases where first char is ), line 21 is the context
        int maxLength = 0;

        for (int i = 0; i < S.length(); i++)
        {
            char ch = S[i];
            if (ch == '(')
                st.push(i); //storing indexes
            else
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    maxLength = max(maxLength, i - st.top());
                }
            }
        }

        return maxLength;
    }
};