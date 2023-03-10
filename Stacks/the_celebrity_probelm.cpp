class Solution
{
private:
    bool knows(vector<vector<int>> &M, int a, int b)
    {
        if (M[a][b] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> s;
        // pushing all the party members inside the stack
        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }
        // looking for potential celebrity cadidate
        while (s.size() > 1)
        {
            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();
            // if a knows b then a is not a celebrity
            if (knows(M, a, b))
            {
                // pushing b in stack again because it can be a celebrity
                s.push(b);
            }
            // if a doesn't know b then a might be a celebrity
            else
            {
                s.push(a);
            }
        }
        // getting out of the loop means we have only 1 element in stack which can be a celebrity
        int potentialCandidate = s.top();
        // if the entire row is 0 for the element then rowCheck is successful
        bool rowCheck = false;
        int zeroCount_Row = 0;
        for (int i = 0; i < n; i++)
        {
            if (M[potentialCandidate][i] == 0)
            {
                zeroCount_Row++;
            }
        }
        if (zeroCount_Row == n)
        {
            rowCheck = true;
        }

        // if the entire column is 1 for the element except diagonal one then columnCheck is successful
        bool columnCheck = false;
        int zeroCount_Column = 0;
        for (int i = 0; i < n; i++)
        {
            if (M[i][potentialCandidate] == 1)
            {
                zeroCount_Column++;
            }
        }
        if (zeroCount_Column == n - 1)
        {
            columnCheck = true;
        }

        // if both rowCheck & ColumnCheck is successful then it's a celebrity element

        if (rowCheck == true && columnCheck == true)
        {
            return potentialCandidate;
        }
        else
        {
            return -1;
        }
    }
};
/*
Time Complexity: O(n)
Space Comeplexity: O(n)
*/