class Solution {
public:
int tabulation(vector<int>& S1, vector<int>& S2, int n, int m){
        int  maxi=0;
	    vector<vector<int>>dp(n+1,vector<int>(m+1,0)) ; 
	     
	     for(int i=1;i<=n;i++){
	         for(int j=1;j<=m;j++){
	             if(S1[i-1]==S2[j-1]){
	                 dp[i][j] = 1 + dp[i-1][j-1];
					 maxi=max(maxi,dp[i][j]);
	             }
	             else{
	                 dp[i][j] = 0;
	             }
	         }
	     }
	     return maxi;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        return tabulation(nums1,nums2,n,m);
    }
};