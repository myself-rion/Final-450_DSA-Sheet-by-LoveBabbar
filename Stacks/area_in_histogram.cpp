class Solution
{
    vector<int> prevSmallerElement(vector<int> arr, int n)
    {
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> nextSmallerElement(vector<int> arr, int n)
    {
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        int curr = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> next(n);
        vector<int> prev(n);
        // array of smaller elements' indexes on right
        next = nextSmallerElement(heights, n);
        // array of smaller elements' indexes on left
        prev = prevSmallerElement(heights, n);
        int area = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int l = heights[i];
            if (next[i] == -1)
            {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newArea = l * b;
            area = max(area, newArea);
        }
        return area;
    }
};

/*
Time Complexity : O(n)
Space Complexity: O(n)
*/