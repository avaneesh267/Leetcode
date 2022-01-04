class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int i=0, j, n=s.size(), dup=0;
        map<char,int> mp;
        for(j=0;j<n;j++)
        {
            mp[s[j]]++;
            dup += mp[s[j]]==2;
            if(dup>0)
            {
                dup-=mp[s[i]]==2;
                mp[s[i]]--;
                i++;
            }
        }
        return j-i;
    }
};