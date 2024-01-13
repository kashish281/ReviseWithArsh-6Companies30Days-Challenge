class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ans;
        map<string,vector<int>> mp;
        for(auto i:access_times){
            mp[i[0]].push_back(stoi(i[1]));
        }
        for(auto &[fir, sec] :mp){
            sort(sec.begin(),sec.end());
            int k=sec.size();
            bool flag=false;
            for(int j=0;j+3<=k;j++){
                flag=flag| sec[j+2]<sec[j]+100;
            }
            if(flag){
                ans.push_back(fir);
            }
        }
        return ans;
    }
};