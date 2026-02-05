class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>rem(k,0);
        int n = nums.size(),ei = 0,sum = 0,ans = 0;
        rem[0] = 1;
        while(ei < n)
        {
            sum += nums[ei++];
            int r = (sum % k + k) %k;

            ans += rem[r];
            rem[r]++;
        }

        return ans;
    }
};