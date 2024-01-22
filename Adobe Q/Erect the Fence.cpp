class Solution {
public:
   static bool cmp(vector<int> &a,vector<int> &b){
       return a[0]<b[0] || ( a[0]==b[0]&&a[1]<b[1]);
   }
   bool check(vector<int> &a,vector<int> &b,vector<int> &c){
       return (b[0] - a[0]) * (c[1] - b[1]) - (b[1] - a[1]) * (c[0] - b[0])<0;
   }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(),trees.end(),cmp); // SORTING USING COMPARATOR
        vector<vector<int>> ans; int n=trees.size();
        for(int i=0;i<n;i++){
            while(ans.size()>1 && check(ans[ans.size()-2],ans[ans.size()-1],trees[i])){
                ans.pop_back();
            }
            ans.push_back(trees[i]);
        }
        if(ans.size()==n) return ans;
        for(int i=n-2;i>=0;i--){
            while(ans.size()>1 && check(ans[ans.size()-2],ans[ans.size()-1],trees[i])){
                ans.pop_back();
            }
            ans.push_back(trees[i]);
        }
        ans.pop_back(); // TO AVOID REPETITION OF THE FIRST COORDINATE 
        
        return ans;
    }
};