class Solution
{
private:
// using methods of largest area in histogram
    vector<int> prevSmallerElement(int *arr, int n)
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
    vector<int> nextSmallerElement(int *arr, int n)
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

    int largestRectangleArea(int *heights, int n)
    {
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

public:
    int maxArea(int M[MAX][MAX], int n, int m)
    {
        // area of first row
        int area = largestRectangleArea(M[0], m);
        // merging rows to get the max area
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] != 0)
                {
                    M[i][j] = M[i][j] + M[i - 1][j];
                }
                else
                {
                    M[i][j] = 0;
                }
            }
            area = max(area, largestRectangleArea(M[i], m));
        }
        return area;
    }
};