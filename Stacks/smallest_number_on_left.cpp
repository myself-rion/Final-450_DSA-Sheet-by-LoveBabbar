class Solution
{
public:
    vector<int> leftSmaller(int n, int arr[])
    {
        // vector for  storing answers
        vector<int> ans;
        stack<int> s;
        // initializing the stack with -1 because there's no smaller element on the left side of starting index
        s.push(-1);
        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            curr = arr[i];
            // if a smaller element found in stack then push it in answer vector
            if (curr > s.top())
            {
                ans.push_back(s.top());
                s.push(curr);
            }
            // search for the smaller element by removing greater elements out of the stack
            else
            {
                while (curr <= s.top() && !s.empty())
                {
                    s.pop();
                }
                // there were no smaller elements inside the stack
                if (s.empty())
                {
                    ans.push_back(-1);
                    s.push(curr);
                }
                // smaller element found
                else
                {
                    ans.push_back(s.top());
                    s.push(curr);
                }
            }
        }
        return ans;
    }
};