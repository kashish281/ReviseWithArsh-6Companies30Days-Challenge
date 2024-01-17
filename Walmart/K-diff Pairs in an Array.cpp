class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i:nums)
            mp[i]++;
        int cnt=0;
        for(auto x:mp)
        {
            if(k==0)
            {    
                if(x.second>1)
                cnt++;
            }
             else if(mp.find(x.first+k)!=mp.end())
                cnt++;
        }
        return cnt;
    }
};