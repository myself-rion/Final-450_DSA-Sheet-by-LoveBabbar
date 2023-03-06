class Solution
{
public:
    int checkRedundancy(string s)
    {
        stack<char> st;
        // traversing the string
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            // checking the push condition
            if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                st.push(ch);
            }
            // if we are entering the ELSE block then either it's ')' or any operand
            else
            {

                if (ch == ')')
                {
                    int redundant = 1;
                    // finding the ')' in stack
                    while (st.top() != '(')
                    {
                        char top = st.top();
                        // if there is any operator between the ( & ) then it's not redundant 
                        if (top == '+' || top == '-' || top == '*' || top == '/')
                        {
                            redundant = 0;
                        }
                        st.pop();
                    }
                    // if no operators found between then those are redundant brackets
                    if (redundant == 1)
                    {
                        return 1;
                    }
                    // emptying the stack
                    st.pop();
                }
            }
        }
        return 0;
    }
};