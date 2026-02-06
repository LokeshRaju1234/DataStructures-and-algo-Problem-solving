class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
     int n = nums.size();
     unordered_map<int,int>map;
     for(int i = 0;i < n;i++)
     {
        int comp = target - nums[i];

        if(map.count(comp))
        {
            return {i,map[comp]};
        }

        map[nums[i]] = i;
     }
     return {};
    }
};