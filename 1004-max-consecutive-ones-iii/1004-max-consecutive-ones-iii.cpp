class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(),ei = 0,si = 0,count = 0,len = 0;

        vector<int>freq(128,0);
        while(ei < n)
        {
            if(nums[ei++] == 0) count++;

            while(count > k)
            {
                if(nums[si++] == 0) count--;
            }

            len = max(len,ei - si);
        }

        return len; 
    }
};