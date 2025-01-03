class Solution
{
public:
    int myAtoi(char *s)
    {
        while (true)
        {
            if (*s == ' ')
            {
                s += 1;
            }
            else
            {
                break;
            }
        }
        bool negative = false;
        if (*s == '+' || *s == '-')
        {
            if (*s == '-')
            {
                negative = true;
            }
            s += 1;
        }

        int ans = 0;
        int size = strlen(s);

        for (int i = 0; i < size; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                int digit = s[i] - '0'; // int
                if (ans <= (INT_MAX - digit) / 10)
                {
                    ans = ans * 10 + digit;
                }
                else
                {
                    if (negative)
                    {
                        return INT_MIN;
                    }
                    return INT_MAX;
                }
            }
            else
            {
                break;
            }
        }
        return negative ? ans * -1 : ans;
    }
};