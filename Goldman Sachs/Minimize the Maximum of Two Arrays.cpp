#define ll long long
class Solution {
public:
    bool checker(long long k, ll a, ll b, ll n1, ll n2){
        ll x= (k/a);//no. of +ve integers <=k, that are divisible by a
        ll y= k/b;//no. of +ve integers <=k, that are divisible by b
        ll z= k-(x+y-(k / (a * b /gcd(a, b))));//no. of +ve integers <=k, that are not divisible by a & b
        ll m=(k / (a * b / gcd(a, b)));
        x=k-x;//no. of +ve integers <=k, that are not divisible by a
        y=k-y;//no. of +ve integers <=k, that are not divisible by a
        x-=z;
        y-=z;
        if(x<n1){
            z-=(n1-x);
            x=n1;
        }
        if(y<n2){
            z-=(n2-y);
            y=n2;
        }
        return z>=0;  
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        ll a=divisor1, b=divisor2;
        ll l = min(a, b), r = INT_MAX;
        ll ans = INT_MAX; 
        while (l <= r)
        { 
            ll mid = (l + r) / 2;
            if (checker(mid, a, b,uniqueCnt1, uniqueCnt2 ))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;   
    }
};