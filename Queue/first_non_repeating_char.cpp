// First non-repeating characters in a String

string FirstNonRepeating(string A)
{
    // map to keep the count of characters
    unordered_map<char, int> count;
    // queue to find the non repeating character
    queue<char> q;
    string s = "";
    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];
        count[ch]++;
        q.push(ch);

        while (!q.empty())
        {
            //  check if the character is repeating
            if (count[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                s.push_back(q.front());
                break;
            }
        }
        if (q.empty())
            s.push_back('#');
    }
    return s;
}