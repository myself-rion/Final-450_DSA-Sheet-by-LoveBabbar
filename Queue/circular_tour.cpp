class Solution
{
public:
    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        int deficit = 0; // checks the amount of oil that falls short to cover distance
        int balance = 0; // the remaining amount of oil after covering a distance
        int start = 0;   // checks where to start the journey from

        for (int i = 0; i < n; i++)
        {
            balance += p[i].petrol - p[i].distance;
            if (balance < 0)
            {
                deficit += balance;
                start = i + 1;
                balance = 0;
            }
        }

        if (deficit + balance >= 0)
        {
            return start;
        }
        else
        {
            return -1;
        }
    }    
};