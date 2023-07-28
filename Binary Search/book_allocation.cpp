bool isPossibleAnswer(int A[], int Number_of_Students, int Number_of_books, int mid)
{

    int studentCount = 1;
    int pageCount = 0;

    for (int i = 0; i < Number_of_Students; i++)
    {

        if (pageCount + A[i] <= mid)
        {
            pageCount += A[i];
        }
        else //book allocated to next student
        {
            studentCount++;
            if (studentCount > Number_of_books || A[i] > mid) //if next student exists || book pages < mid value
            {
                return false;
            }
            // pageCount=0; new page count for next student
            // pageCount+=A[i]; new book assigned
            pageCount = A[i];
        }
    }

    return true;
}
int findPages(int A[], int Number_of_Students, int Number_of_books)
{
    if (Number_of_books > Number_of_Students)
        return -1;

    int ans = -1;
    int s = 0;
    int e = 0;

    for (int i = 0; i < Number_of_Students; i++)
    {
        e += A[i];
    }

    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (isPossibleAnswer(A, Number_of_Students, Number_of_books, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}