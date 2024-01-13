class Solution {
public:
vector<vector<int>> ans;
void solve(int idx,int k,int n,vector<int> &temp){
    if(n==0 && k==0){
        ans.push_back(temp);
        return;
    }
    if(n<=0 || k<=0){
        return;
    }
    for(int st=idx;st<=9;st++){
        temp.push_back(st);
        solve(st+1,k-1,n-st,temp);
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        solve(1,k,n,temp);
        return ans;
    }
};