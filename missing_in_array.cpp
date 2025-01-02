class Solution
{
public:
    int missingNumber(vector<int> &arr)
    {
        // code here
        int n = arr.size() + 1;
        int xorArr = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            xorArr ^= arr[i];
        }
        int xorTotal = 0;
        for (int i = 1; i <= n; i++)
        {
            xorTotal ^= i;
        }

        return xorArr ^ xorTotal;
    }
};