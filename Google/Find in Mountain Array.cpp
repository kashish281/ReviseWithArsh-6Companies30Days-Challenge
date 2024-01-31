
class Solution {
    const static int Max = 1e9;
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int top = getTopIdx(mountainArr);

        int ans = min(//                       lambda functoin
            bs(0,top , target , mountainArr , [] (int a, int b){ return a>=b; }  ) ,

            bs(top , mountainArr.length()-1 , target , mountainArr 
            , [](int a , int b){ return a<=b; } 
    ));

        return ans == Max ? -1 : ans;
    }
    int bs(int l , int r ,int target, MountainArray &mountainArr , bool (*cmp)(int,int) ){
        int ans = Max;
        while(l<=r){
            int  md = (l+r)/2;

            if(cmp( mountainArr.get(md) , target ) )
                r = md-1 , ans = md;
            else
                l = md+1;
        }

        if(ans != Max && mountainArr.get(ans) != target)
            ans = Max;

        return ans;
    }

    int getTopIdx(MountainArray &mountainArr){
        int l = 0 , r = mountainArr.length() -1 , md ,ans =-1;
        while(l<=r){
            md = (l+r)/2;
            if(mountainArr.get(md) < mountainArr.get(md+1)){
                l = md+1;
                ans = md+1;
            }
            else 
                r = md-1;
        }

        return ans;
    }
};