*****Right most bit = (num & 1)                           // this way to find the right most bit.
                      * ****Right shift bit = (num >>= 1) // this way to find the right shift.
    // Approach-1 (Visiting all bit one by one and compaing)
    class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int result = 0;

        while (a != 0 || b != 0 || c != 0)
        {

            if ((c & 1) == 1)
            { // right most bit 1 hai
                if ((a & 1) == 0 && (b & 1) == 0)
                {
                    result++;
                }
            }
            else
            { // right most bit 0 hai
                if (a & 1 == 1)
                    result++;
                if (b & 1 == 1)
                    result++;
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return result;
    }
};