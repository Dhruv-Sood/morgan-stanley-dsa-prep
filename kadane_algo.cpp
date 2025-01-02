class Solution
{
public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr)
    {
        // code here...
        int curr = arr[0];
        int maxi = arr[0];

        for (int i = 1; i < arr.size(); i++)
        {
            curr = max(arr[i] + curr, arr[i]);
            maxi = max(curr, maxi);
        }
        return maxi;
    }
};