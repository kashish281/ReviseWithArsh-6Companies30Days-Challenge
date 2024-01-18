class Solution {
public:
struct cmp{
    bool operator()(pair<int,string> &x,pair<int,string> &y){
        if(x.first==y.first){
            return x.second>y.second;
        }
        return x.first<y.first;
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto i:words){
            mp[i]++;
        }
        priority_queue<pair<int,string>, vector<pair<int, string>>,cmp> pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        vector<string> ans;
        while(k-- && !pq.empty()){
            auto top=pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        return ans;

    }
};