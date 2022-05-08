class Solution {
public:
    vector<int> nums;
    int n;
    vector<vector<long long>> dp;
    long long recurr(int i, int j)
    {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        long long mx=0;
        for(int k=i;k<=j;k++)
        {
            mx=max(mx, (long long)nums[k]*nums[i-1]*nums[j+1] + recurr(i, k-1) + recurr(k+1, j));
        }
        return dp[i][j]=mx;
    }
    int maxCoins(vector<int>& nums) 
    {
        dp.resize(502, vector<long long>(502,-1));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        this->nums=nums; this->n = nums.size();
        int i=1, j=n-2;
        return recurr(i,j);
    }
};