#define mod 1000000007
int dp[3005][1001];

class Solution {
public:

int solve(int st,int e,int k){
    if(st==e && k==0){
        return 1;
    }
    if(k<=0){
        return 0;
    }
    if(dp[st+1000][k]!=-1){
        return dp[st+1000][k] % mod;
    }
    int left=solve(st-1,e,k-1)%mod;
    int right=solve(st+1,e,k-1)%mod;
    return dp[st+1000][k]=(left+right)%mod;
    
}
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(startPos,endPos,k)%mod;
    }
};