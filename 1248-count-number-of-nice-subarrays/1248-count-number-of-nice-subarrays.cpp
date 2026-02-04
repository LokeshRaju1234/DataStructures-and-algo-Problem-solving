class Solution {
public:
int atmostkDistinct(vector<int> &arr,int k)
{
    
    int n = arr.size(),si = 0,ei = 0,count = 0,ans = 0;

    while(ei < n)
    {
        if((arr[ei++] & 1) != 0) count++;

        while(count > k)
        {
            if((arr[si++] & 1) != 0) count--; //& for working on odd numbers 
        }
        ans += ei - si;
    }
    return ans;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
         return atmostkDistinct(nums,k) - atmostkDistinct(nums,k - 1);
    }
};