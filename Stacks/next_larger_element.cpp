class Solution
{
public:
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        if (n == 1)
            return {-1};

        vector<long long> ans(n, -1);
        stack<long long> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= arr[i]) //popping to find next greater element
            {
                st.pop();
            }

            ans[i] = (st.empty() ? -1 : st.top()); //if stack is empty then no greater element is available

            st.push(arr[i]);
        }
        return ans;
    }
};