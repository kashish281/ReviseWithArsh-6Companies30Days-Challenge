class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int i;
        int size1=hBars.size();
        int size2=vBars.size();
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int cons=1;
        int maxcons=1;
        int cons1=1;
        int maxcons1=1;
        int cons2=1;
        int maxcons2=1;
        
        for(i=0;i<size2-1;i++){
            if(vBars[i]+1==vBars[i+1])cons1++;
            else{
                maxcons1=max(cons1,maxcons1);
                cons1=1;
            }
        }
        maxcons1=max(maxcons1,cons1);
        for(i=0;i<size1-1;i++){
            if(hBars[i]+1==hBars[i+1])cons2++;
            else{
                maxcons2=max(cons2,maxcons2);
                cons2=1;
            }
        }
        maxcons2=max(maxcons2,cons2);
        maxcons=min(maxcons1,maxcons2);
        maxcons=maxcons+1;
        return maxcons*maxcons;
    }
};