class Solution {
public:
vector<int> ans;
int dp[1001];
void rec(int n,vector<int> &a,int curr,vector<int> &temp){
        if(curr==n){
            if(temp.size()>ans.size()){
                ans=temp;
            }
            return;
        }
        if(temp.size()==0){
            temp.push_back(a[curr]);
            rec(n,a,curr+1,temp);
            temp.pop_back();
        }
        else if((int)temp.size()>dp[curr] && a[curr]%temp.back()==0){
            dp[curr]=temp.size();
            temp.push_back(a[curr]);
            rec(n,a,curr+1,temp);
            temp.pop_back();
        }
        rec(n,a,curr+1,temp);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        vector<int> temp;
        sort(nums.begin(),nums.end());
        rec(n,nums,0,temp);
        return ans;
    }
};