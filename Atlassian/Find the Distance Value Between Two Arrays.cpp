class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        for(auto var:arr1)
        {
            int start = 0;
            int end = arr2.size()-1;
            int mid = (start + end)/2;
            res++;
            while(start <= end)
            {
                mid = (start + end)/2;
                if((arr2[mid] <= (d+var))  and (arr2[mid] >= (var-d)))
                {
                    res--;
                    break;
                }
                else if(arr2[mid] > (d+var))                    end = mid-1;
                else                                          start = mid+1;
            }
        }
        return res;
        //Brute force approach
        // int res = 0;
        // for(auto var1:arr1)
        // {
        //     res++;
        //     for(auto var2:arr2)
        //     {
        //         if(abs(var1-var2) <= d)
        //         {
        //             res--;
        //             break;
        //         }
        //     }
        // }
        // return res;
    }
};