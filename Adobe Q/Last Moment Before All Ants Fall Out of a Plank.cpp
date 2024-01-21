class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res=0;
        for(auto i:left){
            res=max(i,res);
        }
        for(auto j:right){
            res=max(n-j,res);
        }
        return res;

    }
};