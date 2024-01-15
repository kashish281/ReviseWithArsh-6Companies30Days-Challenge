class Solution {
public:
bool check(vector<int> tmp){
        for(int i=1;i<tmp.size();i++){
            if(tmp[i] <= tmp[i-1]) return false;
        }
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        int res = 0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                vector<int> tmp;
                for(int k=0;k<i;k++){
                    tmp.push_back(nums[k]);
                }
                for(int k=j+1;k<n;k++){
                    tmp.push_back(nums[k]);
                }
                if(check(tmp)){
                    res++;
                }
            }
        }
        return res;
    }
};