class Solution {
public:
    string minWindow(string s, string t) 
    {
        unordered_map<char,int>map;
        for(char st : t)
        {
            map[st]++;
        }
        int left = 0,right = 0,n = s.size(),req = t.size(),start = 0,len = INT_MAX;

        while(right < n)
        {
            if(map[s[right]] > 0)
            {
                req--;
            }

            map[s[right]]--;//to handle unique character
            right++;

            // valid window we got
            while(req == 0)
            {
                if(right - left < len)
                {
                    start = left;
                    len = right - left;
                }

                map[s[left]]++;
                if(map[s[left]] > 0)
                {
                    req++;
                }
                left++;
            } 
        }

        return len == INT_MAX ? "":s.substr(start,len);
    }
};