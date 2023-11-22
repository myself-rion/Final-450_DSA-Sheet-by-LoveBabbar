class Solution
{
public:
    int isStackPermutation(int N, vector<int> &A, vector<int> &B)
    {
        stack<int> st;
        int j = 0; //pointing the indexes of output array

        // if all elements of A is present in B then B is  permutation of A
        for (int i = 0; i < N; i++)
        {
            st.push(A[i]);

            while (!st.empty() && st.top() == B[j])
            {
                st.pop();
                j++;
            }
        }

        return (st.empty()); //if stack is not empty then there is atleast element which is not present in B & it's not a permutation
    }
};