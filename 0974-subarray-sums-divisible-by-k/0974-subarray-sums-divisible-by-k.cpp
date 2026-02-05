class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
         int n = nums.size();
        int count = 0;
        int sum = 0;
        int ei = 0;
        unordered_map<int,int>map;
        map[0] = 1;
        while(ei < n)
        {
            sum += nums[ei++];
            int rem = (sum % k + k) % k;
            count += map[rem];
            map[rem]++;
        }
        return count;
    }
};