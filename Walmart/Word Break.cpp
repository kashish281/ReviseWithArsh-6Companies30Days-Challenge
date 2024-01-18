class Solution {
public:
int findit(int i,int n,string s, set<string> &wordDict,vector<int> &dp){
    if(i==n){
        return 1;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    string temp;
    for(int j=i;j<n;j++){
        temp+=s[j];
        if(wordDict.find(temp)!=wordDict.end()){
            if(findit(j+1,n,s,wordDict,dp)){
                return dp[i]=1;
            }
        }
    }
    return dp[i]=0;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto i:wordDict){
            st.insert(i);
        }
        int n=s.size();
        vector<int> dp(n,-1);
 
        return findit(0,n,s,st,dp);
    }
};