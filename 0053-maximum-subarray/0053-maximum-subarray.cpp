class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = 0,sum = -(int)1e9;

        for(int ele : nums)
        {
            currsum = max(ele,currsum + ele);
            sum = max(sum,currsum);
        }

        return sum;
    }
};