class Solution
{
    private:
        void solve(stack<int>&s, int pos, int count){
            if(count==pos/2){
                s.pop();
                return;
            }
            int top= s.top();
            s.pop();
            solve(s,pos,count+1);
            s.push(top);
        }
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeofStack)
    {
        int count=0;
        solve(s,sizeofStack,count);
    }
};