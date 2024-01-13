class Solution{
public:
     vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int> ans(2,-1);
        int i=0;
        while(i<n){
            if(arr[i]==i+1) i++;
            else{
                if(arr[i]==arr[arr[i]-1]) i++;
                else swap(arr[i],arr[arr[i]-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]-1!=i){
                ans[0]=arr[i];
                ans[1]=i+1;
                break;
            }
        }
        return ans;
        
    }
};