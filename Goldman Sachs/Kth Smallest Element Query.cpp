class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n=nums.size();
        for(auto i:queries){
            vector<pair<string,int>> temp;
            for(int j=0;j<n; j++) {
                temp.push_back({(nums[j].substr(nums[j].size()-i[1])), j});
            }
            sort(temp.begin(),temp.end());
            ans.push_back(temp[i[0]-1].second);
        }
        return ans;
    }
};  
