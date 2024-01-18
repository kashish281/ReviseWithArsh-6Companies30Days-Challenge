class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto i:s){
            mp[i]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            for(int i=1;i<=top.first;i++){
                ans+=top.second;
            }
        }
        return ans;
    }
};